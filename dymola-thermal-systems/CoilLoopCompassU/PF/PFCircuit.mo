within CoilLoopCompassU.PF;
model  PFCircuit
  extends ThermalSystems.Internals.ClassTypes.ExampleModel;
  parameter Real m_wanted = 0.9
    "flow I want in the circuit, kg/s -- recalibrated 2026-07-28 from debugging/result.mat (sensor_m_flow.sensorValue averaged ~0.895 kg/s over t=1600-1815s, still rising ~0.03 kg/s/100s at end of run -- old value of 0.095 predated the coil-geometry/isolation changes and no longer matched the achieved flow by ~10x)";
  parameter Real m_total = 0.1 "total flow from the pump, kg/s";
  parameter Real u_dead = 1;
  parameter Real Kv_shut = 1e-4;
  parameter Real Kv_cool_max = 5000;
  parameter Real heater_gain = 100;
  parameter Real Kv_gain = 100;
  parameter Real bypass_limit = 10;
  parameter Real Kv_circuit = 5.0
    "Equivalent Kv (m3/h) of the circuit branch (junction5.portC -> ... -> junction4.portA), as seen in parallel with valve1's bypass branch across the shared junction5/junction4 dp -- measured 2026-07-28 from debugging/result.mat via two independent methods (flow-ratio: 5.49 m3/h; direct dp/mdot/rho: 4.99 m3/h), re-identify with debugging/identify_circuit_kv.py if the coil/header geometry changes again";
  parameter Real hysteresisHalfWidth = 0.3
    "Half-width of the ON/OFF gap around each PID.y switching threshold (heater/cooling/bypass), prevents state-event chattering when PID.y settles right on a threshold";
  parameter Modelica.Units.SI.TemperatureDifference tempMargin=40
    "Margin below the hottest coil-assembly gas outlet temperature";
  parameter Boolean enableOverCoolPrevention = true
    "Master switch for valve4's overcool-prevention trigger (the first when-branch below, gated on overCoolReopenMargin). When false, valve4 never opens in response to overcooling risk -- it stays permanently shut, and enableOverCoolRecovery's hold logic never has anything to act on.";
  parameter Boolean enableOverCoolRecovery = true
    "Master switch for valve4's stabilize-and-reclose logic (the three elsewhen-branches below, gated on overCoolShutMargin/overCoolStabilityBand/overCoolStabilizeDelay). When false, valve4 -- once opened by enableOverCoolPrevention -- never automatically recloses; the bypass stays open indefinitely. No effect if enableOverCoolPrevention is false.";
  parameter Modelica.Units.SI.TemperatureDifference overCoolShutMargin=40
    "Lower bound of valve4's settle band: T_ref - overCoolShutMargin (T_ref = T_gas_out_max snapshot recorded at the moment valve4 last reopened). sensor_T.sensorValue must sit at or above this (and at or below T_ref - overCoolShutMargin + overCoolStabilityBand, i.e. within the band) for overCoolStabilizeDelay seconds continuously before valve4 actually shuts.";
  parameter Modelica.Units.SI.TemperatureDifference overCoolReopenMargin=45
    "valve4 reopens (and re-records T_ref = current T_gas_out_max) once T_gas_out_max - sensor_T.sensorValue exceeds this, while shut";
  parameter Modelica.Units.SI.TemperatureDifference overCoolStabilityBand=20
    "Width of valve4's settle band above the lower bound (T_ref - overCoolShutMargin): sensor_T.sensorValue must stay within [T_ref - overCoolShutMargin, T_ref - overCoolShutMargin + overCoolStabilityBand] continuously -- e.g. cooling toward 120K with overCoolShutMargin=40/overCoolStabilityBand=20 means it needs to settle within [120,140]K, not just touch 120K once.";
  parameter Modelica.Units.SI.Time overCoolStabilizeDelay=30
    "sensor_T.sensorValue must stay continuously within valve4's settle band (see overCoolShutMargin/overCoolStabilityBand) for this long before valve4 actually closes -- lets the temperature genuinely settle before flow is pushed back through the coils. Any excursion out of the band (either side) before the delay elapses restarts the wait.";
  parameter Integer nPF = 8 "Number of PF coil assemblies";
  parameter Boolean enableCoilIsolation = true
    "Master switch for the per-assembly relative-margin isolation rule (coilIsolationCloseMargin/coilIsolationReopenMargin, in the combined when/elsewhen chain below). When false, this rule never closes or reopens coilOpen[i] -- only enableLowTempCoolantOptimization (if also true) can still act on the shared latch.";
  parameter Modelica.Units.SI.TemperatureDifference coilIsolationCloseMargin = 40
    "Per-coil isolation valve closes once T_gas_out is this much colder than T_gas_out_max";
  parameter Modelica.Units.SI.TemperatureDifference coilIsolationReopenMargin = 35
    "Per-coil isolation valve reopens once within this much of T_gas_out_max";
  parameter Boolean enableLowTempCoolantOptimization = false
    "Master switch for the absolute-threshold lowTempCoolantOptimization algorithm below. This flag only gates the when-clauses (coilOpen close/reopen, lowTempPending dwell) -- it does NOT gate lowTempOtherHotCount_PF's continuous comparison against lowTempCoolantOptimizationThreshold, which is evaluated every step regardless. Keep lowTempCoolantOptimizationThreshold at 0 (unreachable) while this is false, so that comparison never actually crosses and never generates a state event; only raise the threshold at the same time you set this true.";
  parameter Modelica.Units.SI.Temperature lowTempCoolantOptimizationThreshold = 0
    "Absolute T_gas_out threshold (K, independent of coilIsolationCloseMargin's relative-to-max logic) for the lowTempCoolantOptimization algorithm: an assembly colder than this can be shut once enough other assemblies are still hotter than it. Must be raised (e.g. to 80) together with enableLowTempCoolantOptimization=true to actually take effect -- see enableLowTempCoolantOptimization's docstring for why leaving it at 0 matters even while disabled.";
  parameter Integer lowTempCoolantOptimizationMinHotOthers = 2
    "Minimum number of OTHER assemblies that must have T_gas_out above lowTempCoolantOptimizationThreshold before a cold assembly is shut by lowTempCoolantOptimization";
  parameter Modelica.Units.SI.Time lowTempCoolantOptimizationMinDuration = 10
    "Assembly i's own T_gas_out must stay continuously below lowTempCoolantOptimizationThreshold (with lowTempOtherHotCount_PF[i] continuously >= lowTempCoolantOptimizationMinHotOthers) for this long before lowTempCoolantOptimization actually shuts it -- filters out a brief/noisy dip that shouldn't count as a real close decision. Any excursion out of that condition before the duration elapses cancels the pending close; the wait restarts on the next continuous entry.";
  parameter Modelica.Units.SI.Time controlActivationDelay = 5
    "Reopen logic (valve4 and per-coil isolation) stays disabled until this much simulated time has passed, so it isn't triggered by unsettled startup temperatures";
  parameter Real m_flow_startup = 0.2
    "Circuit flow target valve1 bypasses down to for the first controlActivationDelay seconds (same startup window as the reopen-logic delay above), so coil temperatures can be read before valve1 releases to the normal m_wanted trim control, kg/s";

  Real T_ref(start=0, fixed=true)
    "T_gas_out_max snapshot for valve4's own control logic only (PID/wanted_temp are unaffected) -- re-recorded every time valve4 reopens, held constant otherwise";
  Boolean valve4Open(start=false, fixed=true)
    "true -> valve4 Kv=5000 (open), false -> valve4 Kv=0.001 (shut)";
  Boolean overCoolRecovering(start=false, fixed=true)
    "True while sensor_T is inside valve4's settle band ([T_ref - overCoolShutMargin, T_ref - overCoolShutMargin + overCoolStabilityBand]) but hasn't stayed there continuously for overCoolStabilizeDelay yet -- valve4 stays open (bypass still flowing) during this hold. Reset to false the instant sensor_T leaves the band on either side, so the wait restarts on the next continuous stay.";
  Real overCoolRecoveredAt(start=0, fixed=true)
    "Time sensor_T most recently entered valve4's settle band during the current valve4-open episode -- gates the overCoolStabilizeDelay hold before valve4 actually closes.";
  Boolean coilOpen[nPF](start=fill(true, nPF), fixed=fill(true, nPF))
    "Per-assembly isolation valve latch, order: PF1U,PF1L,PF2U,PF2L,PF3U,PF3L,PF4U,PF4L -- closed by EITHER the relative-margin coilIsolation* rule or the absolute-threshold lowTempCoolantOptimization rule (see the combined when/elsewhen chain below); a single shared latch, not two separate ones, so it stays the same array Dymola already solves cleanly for this model.";
  Real T_gas_out_frozen[nPF](each start=0, each fixed=true)
    "Snapshot of T_gas_out_PF[i] taken the instant coilOpen[i] closes (by either rule) -- held constant while closed, re-recorded every closing edge";
  Boolean lowTempPending[nPF](start=fill(false, nPF), fixed=fill(false, nPF))
    "True while assembly i's T_gas_out is below lowTempCoolantOptimizationThreshold with enough hot others (lowTempOtherHotCount_PF[i] >= lowTempCoolantOptimizationMinHotOthers) but hasn't stayed there continuously for lowTempCoolantOptimizationMinDuration yet -- gates the dwell before lowTempCoolantOptimization actually closes coilOpen[i]. Reset to false the instant either condition breaks, so the wait restarts on the next continuous entry.";
  Real lowTempPendingSince[nPF](each start=0, each fixed=true)
    "Time assembly i most recently entered the lowTempCoolantOptimization pending state -- gates the lowTempCoolantOptimizationMinDuration hold.";

  output Modelica.Units.SI.Temperature T_gas_out_max = max(T_gas_out_compare_PF)
    "Hottest coil-assembly gas outlet temperature -- uses each coil's live reading while open, frozen closing-time snapshot while isolated, so a closed coil's post-isolation reheating can't distort this (or wanted_temp/other coils' close decisions)";
  output Modelica.Units.SI.Temperature wanted_temp = T_gas_out_max - tempMargin
    "PID setpoint: hottest coil outlet minus margin, revalued continuously";
  output Modelica.Units.SI.Temperature sensor_T_filtered = sensorTFiltered.y
    "Low-pass-filtered copy of sensor_T.sensorValue, reporting only";
  Real m_flowTarget = if time < controlActivationDelay then m_flow_startup else
      m_wanted
    "valve1's circuit-flow target: m_flow_startup for the first controlActivationDelay seconds (coil-temperature read window), m_wanted afterwards";

  Real T_gas_out_PF[nPF] = {PF1U.T_gas_out, PF1L.T_gas_out, PF2U.T_gas_out,
      PF2L.T_gas_out, PF3U.T_gas_out, PF3L.T_gas_out, PF4U.T_gas_out,
      PF4L.T_gas_out} "Same order as coilOpen";
  Real valveKvNominal_PF[nPF] = {PF1U.valveKvNominal, PF1L.valveKvNominal,
      PF2U.valveKvNominal, PF2L.valveKvNominal, PF3U.valveKvNominal,
      PF3L.valveKvNominal, PF4U.valveKvNominal, PF4L.valveKvNominal}
    "Each assembly's own fully-open Kv, same order as coilOpen";
  Real kvTarget_PF[nPF]
    "Commanded Kv per assembly before smoothing: valveKvNominal_PF when open, Kv_shut when closed";
  Real T_gas_out_compare_PF[nPF]
    "T_gas_out_PF[i] while open (live), T_gas_out_frozen[i] while closed -- what the close/reopen decision is evaluated against";
  Integer lowTempOtherHotCount_PF[nPF] = {sum(if (j <> i and T_gas_out_compare_PF[j] >
    lowTempCoolantOptimizationThreshold) then 1 else 0 for j in 1:nPF) for i in 1:nPF}
    "Per-assembly count of OTHER assemblies currently above lowTempCoolantOptimizationThreshold -- feeds the lowTempCoolantOptimization close condition (see lowTempCoolantOptimizationMinHotOthers)";

  inner ThermalSystems.SystemInformationManager sim(
      generateEventsAtFlowReversalGas=false,
      redeclare
      TSMedia.GasTypes.BaseGas gasType1(
      fixedMixingRatio=true,
      nc_propertyCalculation=1,
      gasNames={"VDIWA2006.Helium"},
      mixingRatio_propertyCalculation={1},
      condensingIndex=0)) annotation (Placement(transformation(extent={{180,160},
            {200,180}},
                      rotation=0)));

  ThermalSystems.GasComponents.Fans.Fan2ndOrder fan2ndOrder(
    orientation="symmetric",
    use_mechanicalPort=true,
    n_nominal=200,
    dp_nominal(displayUnit="bar") = 1500000,
    V_flow_nominal=0.031,
    V_flow0=0.05,
    T_nominal(displayUnit="K") = 80,
    p_nominal=4000000,
    dpInitial(displayUnit="bar") = 4000000,
    V_flow_Start=0.003)
    annotation (Placement(transformation(extent={{8,-8},{-8,8}},
        rotation=90,
        origin={-60,120})));
  ThermalSystems.OtherComponents.Sources.SmoothStep smoothStep(
    initialValue=200,
    endValue=200,
    startTime=1,
    stepPeriod=10)
    annotation (Placement(transformation(extent={{-6,-6},{6,6}},
        rotation=0,
        origin={-130,142})));
  ThermalSystems.OtherComponents.Mechanical.RotatoryBoundary rotatoryBoundary(
    phiInitial=0,
    boundaryType="n",
    use_nInput=true)
    annotation (Placement(transformation(extent={{-4,9},{4,-9}},
        rotation=270,
        origin={-60,131})));
  Modelica.Thermal.HeatTransfer.Sources.FixedTemperature coldSurface(T(
        displayUnit="K") = 77)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=270,
        origin={-50,-30})));
  ThermalSystems.GasComponents.Tubes.Tube tube1(
    tubeGeometry(
      innerDiameter=0.012,
      length=10,
      nParallelTubes=60,
      wallThickness=0.001,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    redeclare model WallMaterial =
        CoilLoopCompassU.Common.StainlessSteel304_Tdep,
    fixedTInitialWall=false,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=4000000,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-8,-2},{8,2}},
        rotation=0,
        origin={-50,-60})));
  ThermalSystems.GasComponents.Volumes.Volume volume(
    volume=0.5,
    m_flowStart=0,
    pInitial=4000000,
    TInitial(displayUnit="K") = 80,
    nPorts=1)
    annotation (Placement(transformation(extent={{-3,-7},{3,7}},
        rotation=0,
        origin={-107,-75})));
  ThermalSystems.GasComponents.Valves.Valve valve(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=3000)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=90,
        origin={-146,-77})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={60,60})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction3(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={140,80})));
  ThermalSystems.GasComponents.Valves.Valve valve1(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=0.0001)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=0,
        origin={-42,99})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction4(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=180,
        origin={-20,120})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction5(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=270,
        origin={-112,100})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction2(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,4},{4,-4}},
        rotation=270,
        origin={-112,68})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction8(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={80,80})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction9(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={140,40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction10(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={80,40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction11(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={160,60})));
  CoilAssembly2ch PF2U(lengths={80,83},
    dischargeLoads={0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=2)
    annotation (Placement(transformation(extent={{100,20},{120,40}})));
  CoilAssembly2ch PF2L(lengths={80,83},
    dischargeLoads={0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=1)
    annotation (Placement(transformation(extent={{100,40},{120,60}})));
  CoilAssembly4ch PF1L(
    lengths={61,64,70,74},
    dischargeLoads={0,0,0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=3)
    annotation (Placement(transformation(extent={{100,80},{120,100}})));
  CoilAssembly4ch PF1U(
    lengths={61,64,70,74},
    dischargeLoads={0,0,0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=4,
    nCellsPerTube=1)
    annotation (Placement(transformation(extent={{100,60},{120,80}})));
  CoilAssembly3ch PF3L(lengths={83,84,87},
    dischargeLoads={0,0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=5)
    annotation (Placement(transformation(extent={{100,0},{120,20}})));
  CoilAssembly3ch PF3U(lengths={83,84,87},
    dischargeLoads={0,0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=6)
    annotation (Placement(transformation(extent={{100,-20},{120,0}})));
  CoilAssembly4ch PF4L(lengths={90,90,90,75}, diameters_mm={9,9,9,9},
    wallThickness=0.0059,
    dischargeLoads={0,0,0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=7)
    annotation (Placement(transformation(extent={{100,-40},{120,-20}})));
  CoilAssembly4ch PF4U(lengths={90,90,90,75}, diameters_mm={9,9,9,9},
    wallThickness=0.0059,
    dischargeLoads={0,0,0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=8)
    annotation (Placement(transformation(extent={{100,-60},{120,-40}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction12(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={60,-20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction13(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={80,0})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction14(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={80,-40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction15(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={140,0})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction16(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={140,-40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction17(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={160,-20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction18(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={180,20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction19(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={40,20})));
  Modelica.Blocks.Sources.RealExpression valveRegulator(y=Kv_circuit*(
        sensor_m_flow.sensorValue - m_flowTarget)/m_flowTarget)
    annotation (Placement(transformation(extent={{-140,160},{-120,180}})));
  ThermalSystems.GasComponents.Sensors.Sensor_m_flow sensor_m_flow
    annotation (Placement(transformation(extent={{-72,116},{-80,124}})));
  Modelica.Blocks.Continuous.LimPID PID(
    controllerType=Modelica.Blocks.Types.SimpleController.PI,
    k=0.12,
    Ti=12,
    yMax=60,
    yMin=-60,
    initType=Modelica.Blocks.Types.Init.InitialOutput,
    y_start=5)
            annotation (Placement(transformation(extent={{-10,10},{10,-10}},
        rotation=-90,
        origin={-70,50})));
  Modelica.Blocks.Sources.RealExpression wantedTemp(y=wanted_temp)
    annotation (Placement(transformation(extent={{-156,70},{-136,90}})));
  ThermalSystems.GasComponents.Sensors.Sensor_T sensor_T
    annotation (Placement(transformation(extent={{-16,40},{-8,48}})));
  Modelica.Blocks.Continuous.FirstOrder sensorTFiltered(T=3,
      initType=Modelica.Blocks.Types.Init.SteadyState)
    "Reporting-only low-pass filter on sensor_T's raw reading -- does NOT
    feed PID.u_m (line 693) or the valve4Open algorithm block (lines
    525/529), both of which keep reading sensor_T.sensorValue directly.
    T=3s mirrors the 2026-07-27 firstOrderCoilKv precedent; raise toward
    5-10s if scatter persists, but not so high it visibly lags real
    transients (heater on/off, coil isolation events)."
    annotation (Placement(transformation(extent={{-16,18},{4,26}})));
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=500, uMin=0.001)
    annotation (Placement(transformation(extent={{-80,160},{-60,180}})));
  Modelica.Blocks.Sources.RealExpression valve1Command(y=if time <
        controlActivationDelay then limiter.y else Kv_shut)
    "valve1's final Kv command: the flow-trim proportional control (valveRegulator
    -> limiter), still targeting m_flow_startup, for the first controlActivationDelay
    seconds only; after that valve1 no longer trims flow toward m_wanted -- it's
    forced fully shut (Kv_shut) instead."
    annotation (Placement(transformation(extent={{-56,160},{-36,180}})));
  ThermalSystems.GasComponents.Valves.Valve valve3(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=4000)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=0,
        origin={-26,-59})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction20(
    volume=1e-1,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=180,
        origin={12,120})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction21(
    volume(displayUnit="l") = 0.2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=0,
        origin={12,20})));
  ThermalSystems.GasComponents.Valves.Valve valve4(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=0.0001)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=90,
        origin={12,65})));
  Modelica.Blocks.Logical.Hysteresis heaterHysteresis(uLow=u_dead -
        hysteresisHalfWidth, uHigh=u_dead + hysteresisHalfWidth)
    annotation (Placement(transformation(extent={{-330,54},{-310,74}})));
  Modelica.Blocks.Sources.RealExpression HeaterLimiter(y=if heaterHysteresis.y
         then PID.y*heater_gain else 0)
    annotation (Placement(transformation(extent={{-298,30},{-278,50}})));
  Modelica.Blocks.Logical.Hysteresis coolingHysteresis(uLow=-u_dead -
        hysteresisHalfWidth, uHigh=-u_dead + hysteresisHalfWidth)
    annotation (Placement(transformation(extent={{-258,-78},{-238,-58}})));
  Modelica.Blocks.Sources.RealExpression CoolingLimiter1(y=if
        coolingHysteresis.y then min(-PID.y*Kv_gain, Kv_cool_max) else
        Kv_shut)
    annotation (Placement(transformation(extent={{-226,-54},{-206,-34}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction7(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=270,
        origin={-112,-6})));
  ThermalSystems.GasComponents.Valves.Valve valve5(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=500)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=0,
        origin={-74,-5})));
  ThermalSystems.GasComponents.Valves.Valve valve6(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=5000)
    annotation (Placement(transformation(extent={{-6,3},{6,-3}},
        rotation=-90,
        origin={-112,-25})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction23(
    volume(displayUnit="l") = 0.1,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,4},{4,-4}},
        rotation=270,
        origin={-12,-6})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder(T=2)
    annotation (Placement(transformation(extent={{-192,-54},{-172,-34}})));
  ThermalSystems.GasComponents.Tubes.Tube Heater(
    tubeGeometry(
      innerDiameter=0.04,
      length=4,
      nParallelTubes=1,
      wallThickness=0.001,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    redeclare model WallMaterial =
        CoilLoopCompassU.Common.StainlessSteel304_Tdep,
    fixedTInitialWall=false,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=4000000,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = 80) annotation (Placement(transformation(
        extent={{8,-2},{-8,2}},
        rotation=90,
        origin={-114,40})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow1
    annotation (Placement(transformation(extent={{-200,30},{-180,50}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder1(T=1)
    annotation (Placement(transformation(extent={{-248,30},{-228,50}})));
  Modelica.Blocks.Logical.Hysteresis bypassHysteresis(uLow=bypass_limit -
        hysteresisHalfWidth, uHigh=bypass_limit + hysteresisHalfWidth)
    annotation (Placement(transformation(extent={{-274,-26},{-254,-6}})));
  Modelica.Blocks.Sources.RealExpression BypassLimiter(y=if bypassHysteresis.y
         then max(500 + (PID.y*10), Kv_shut) else 500)
    annotation (Placement(transformation(extent={{-242,-2},{-222,18}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder2(T=1)
    annotation (Placement(transformation(extent={{-192,-2},{-172,18}})));
  Modelica.Blocks.Sources.RealExpression bypassRegulatorOverCool(y=if
        valve4Open then 5000 else 0.001)
    annotation (Placement(transformation(extent={{-54,60},{-34,80}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder3(T=1)
    annotation (Placement(transformation(extent={{-20,60},{0,80}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderCoilKv[nPF](each T=3)
    "Smooths each per-coil Kv step to avoid solver state events -- T=3 (was 1) to soften the 6-decade Kv collapse that stalled the solver for ~73s of simulated time (t~95-168s) in the 2026-07-27 run"
    annotation (Placement(transformation(extent={{-20,-100},{0,-80}})));
equation
  heaterHysteresis.u = PID.y;
  coolingHysteresis.u = -PID.y;
  bypassHysteresis.u = -PID.y;

  for i in 1:nPF loop
    kvTarget_PF[i] = if coilOpen[i] then valveKvNominal_PF[i] else Kv_shut;
    firstOrderCoilKv[i].u = kvTarget_PF[i];
    T_gas_out_compare_PF[i] = if coilOpen[i] then T_gas_out_PF[i] else
      T_gas_out_frozen[i];
  end for;
  PF1U.KvValue_in1 = firstOrderCoilKv[1].y;
  PF1L.KvValue_in1 = firstOrderCoilKv[2].y;
  PF2U.KvValue_in1 = firstOrderCoilKv[3].y;
  PF2L.KvValue_in1 = firstOrderCoilKv[4].y;
  PF3U.KvValue_in1 = firstOrderCoilKv[5].y;
  PF3L.KvValue_in1 = firstOrderCoilKv[6].y;
  PF4U.KvValue_in1 = firstOrderCoilKv[7].y;
  PF4L.KvValue_in1 = firstOrderCoilKv[8].y;

algorithm
  when enableOverCoolPrevention and time >= controlActivationDelay and T_gas_out_max - sensor_T.sensorValue > overCoolReopenMargin
      and not pre(valve4Open) then
    T_ref := T_gas_out_max;
    valve4Open := true;
    overCoolRecovering := false;
  elsewhen enableOverCoolRecovery and pre(valve4Open) and not pre(overCoolRecovering)
      and sensor_T.sensorValue >= T_ref - overCoolShutMargin
      and sensor_T.sensorValue <= T_ref - overCoolShutMargin + overCoolStabilityBand then
    // sensor_T just entered the settle band -- don't close yet, start the
    // overCoolStabilizeDelay hold (valve4 keeps flowing through the bypass
    // branch).
    overCoolRecoveredAt := time;
    overCoolRecovering := true;
  elsewhen enableOverCoolRecovery and pre(valve4Open) and pre(overCoolRecovering)
      and (sensor_T.sensorValue < T_ref - overCoolShutMargin
        or sensor_T.sensorValue > T_ref - overCoolShutMargin + overCoolStabilityBand) then
    // sensor_T left the settle band (either side) before stabilizing --
    // cancel the hold; the branch above restarts it on the next continuous
    // entry into the band.
    overCoolRecovering := false;
  elsewhen enableOverCoolRecovery and pre(overCoolRecovering)
      and sensor_T.sensorValue >= T_ref - overCoolShutMargin
      and sensor_T.sensorValue <= T_ref - overCoolShutMargin + overCoolStabilityBand
      and time >= overCoolRecoveredAt + overCoolStabilizeDelay then
    valve4Open := false;
    overCoolRecovering := false;
  end when;

  for i in 1:nPF loop
    // lowTempCoolantOptimization dwell timer: track how long assembly i has
    // been continuously below the threshold with enough hot others, before
    // the close condition below is allowed to act on it. Any excursion out
    // of that condition (temp back up, or hot-others count drops) cancels
    // the pending close; the wait restarts on the next continuous entry --
    // same debounce pattern as valve4's overCoolRecovering/overCoolRecoveredAt.
    when enableLowTempCoolantOptimization and T_gas_out_PF[i] < lowTempCoolantOptimizationThreshold
        and lowTempOtherHotCount_PF[i] >= lowTempCoolantOptimizationMinHotOthers
        and not pre(lowTempPending[i]) and pre(coilOpen[i]) then
      lowTempPendingSince[i] := time;
      lowTempPending[i] := true;
    elsewhen (T_gas_out_PF[i] >= lowTempCoolantOptimizationThreshold
          or lowTempOtherHotCount_PF[i] < lowTempCoolantOptimizationMinHotOthers)
        and pre(lowTempPending[i]) then
      lowTempPending[i] := false;
    end when;

    // Reopen if EITHER the relative-margin rule says so (when enabled), OR
    // lowTempCoolantOptimization's global recovery has fired (when enabled,
    // T_gas_out_max dropped below its threshold) -- every assembly still
    // shut reopens together in that case, not just the ones this event's
    // condition names.
    when (enableCoilIsolation and time >= controlActivationDelay and (T_gas_out_max - T_gas_out_compare_PF[i]) < coilIsolationReopenMargin
          and not pre(coilOpen[i]))
        or (enableLowTempCoolantOptimization and T_gas_out_max < lowTempCoolantOptimizationThreshold and not pre(coilOpen[i])) then
      coilOpen[i] := true;
    // Close if EITHER the relative-margin rule says so (when enabled), OR
    // lowTempCoolantOptimization's dwell has actually elapsed (when enabled):
    // assembly i stayed continuously below lowTempCoolantOptimizationThreshold,
    // with at least lowTempCoolantOptimizationMinHotOthers other assemblies
    // still above it, for lowTempCoolantOptimizationMinDuration straight.
    elsewhen (enableCoilIsolation and (T_gas_out_max - T_gas_out_PF[i]) > coilIsolationCloseMargin
          and pre(coilOpen[i]))
        or (enableLowTempCoolantOptimization and pre(lowTempPending[i])
          and time >= lowTempPendingSince[i] + lowTempCoolantOptimizationMinDuration
          and pre(coilOpen[i])) then
      coilOpen[i] := false;
      T_gas_out_frozen[i] := T_gas_out_PF[i];
    end when;
  end for;

equation
  connect(smoothStep.y,rotatoryBoundary. n_in)
    annotation (Line(points={{-123.4,142},{-60,142},{-60,135}},
                                                     color={0,0,127}));
  connect(rotatoryBoundary.rotatoryFlange, fan2ndOrder.rotatoryFlange)
    annotation (Line(
      points={{-60,131},{-60,128}},
      color={135,135,135},
      thickness=0.5));
  connect(coldSurface.port, tube1.heatPort[1]) annotation (Line(points={{-50,-40},
          {-50,-58}},                           color={191,0,0}));
  connect(volume.portArray[1], valve.portA) annotation (Line(
      points={{-107,-81.825},{-106,-81.825},{-106,-96},{-146,-96},{-146,-83}},
      color={255,153,0},
      thickness=0.5));
  connect(fan2ndOrder.portA, junction4.portC) annotation (Line(
      points={{-52,120},{-24,120}},
      color={255,153,0},
      thickness=0.5));
  connect(junction4.portB, valve1.portB) annotation (Line(
      points={{-20,116},{-20,99},{-36,99}},
      color={255,153,0},
      thickness=0.5));
  connect(valve1.portA, junction5.portB) annotation (Line(
      points={{-48,99},{-50,100},{-108,100}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portC, junction8.portB) annotation (Line(
      points={{60,64},{60,80},{76,80}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portA, junction10.portB) annotation (Line(
      points={{60,56},{60,40},{76,40}},
      color={255,153,0},
      thickness=0.5));
  connect(junction3.portB, junction11.portA) annotation (Line(
      points={{144,80},{160,80},{160,64}},
      color={255,153,0},
      thickness=0.5));
  connect(junction9.portB, junction11.portC) annotation (Line(
      points={{144,40},{160,40},{160,56}},
      color={255,153,0},
      thickness=0.5));
  connect(junction10.portA, PF2U.portA1) annotation (Line(
      points={{80,36},{80,30},{97.2,30}},
      color={255,153,0},
      thickness=0.5));
  connect(PF2U.portB1, junction9.portC) annotation (Line(
      points={{120.4,29.8},{140,29.8},{140,36}},
      color={255,153,0},
      thickness=0.5));
  connect(junction10.portC, PF2L.portA1) annotation (Line(
      points={{80,44},{80,50},{97.2,50}},
      color={255,153,0},
      thickness=0.5));
  connect(PF2L.portB1, junction9.portA) annotation (Line(
      points={{120.4,49.8},{140,49.8},{140,44}},
      color={255,153,0},
      thickness=0.5));
  connect(junction8.portC, PF1L.portA1) annotation (Line(
      points={{80,84},{80,90},{97.2,90}},
      color={255,153,0},
      thickness=0.5));
  connect(junction8.portA, PF1U.portA1) annotation (Line(
      points={{80,76},{80,70},{97.2,70}},
      color={255,153,0},
      thickness=0.5));
  connect(PF1U.portB1, junction3.portC) annotation (Line(
      points={{120.4,69.8},{140,69.8},{140,76}},
      color={255,153,0},
      thickness=0.5));
  connect(PF1L.portB1, junction3.portA) annotation (Line(
      points={{120.4,89.8},{140,89.8},{140,84}},
      color={255,153,0},
      thickness=0.5));
  connect(junction12.portC, junction13.portB) annotation (Line(
      points={{60,-16},{60,0},{76,0}},
      color={255,153,0},
      thickness=0.5));
  connect(junction12.portA, junction14.portB) annotation (Line(
      points={{60,-24},{60,-40},{76,-40}},
      color={255,153,0},
      thickness=0.5));
  connect(junction15.portB, junction17.portA) annotation (Line(
      points={{144,0},{160,0},{160,-16}},
      color={255,153,0},
      thickness=0.5));
  connect(junction16.portB, junction17.portC) annotation (Line(
      points={{144,-40},{160,-40},{160,-24}},
      color={255,153,0},
      thickness=0.5));
  connect(junction17.portB, junction18.portC) annotation (Line(
      points={{164,-20},{180,-20},{180,16}},
      color={255,153,0},
      thickness=0.5));
  connect(junction11.portB, junction18.portA) annotation (Line(
      points={{164,60},{180,60},{180,24}},
      color={255,153,0},
      thickness=0.5));
  connect(junction13.portC, PF3L.portA1) annotation (Line(
      points={{80,4},{80,10},{97.2,10}},
      color={255,153,0},
      thickness=0.5));
  connect(junction13.portA, PF3U.portA1) annotation (Line(
      points={{80,-4},{80,-10},{97.2,-10}},
      color={255,153,0},
      thickness=0.5));
  connect(junction14.portC, PF4L.portA1) annotation (Line(
      points={{80,-36},{80,-30},{97.2,-30}},
      color={255,153,0},
      thickness=0.5));
  connect(junction14.portA, PF4U.portA1) annotation (Line(
      points={{80,-44},{80,-50},{97.2,-50}},
      color={255,153,0},
      thickness=0.5));
  connect(PF4U.portB1, junction16.portC) annotation (Line(
      points={{120.4,-50.2},{140,-50.2},{140,-44}},
      color={255,153,0},
      thickness=0.5));
  connect(PF4L.portB1, junction16.portA) annotation (Line(
      points={{120.4,-30.2},{140,-30.2},{140,-36}},
      color={255,153,0},
      thickness=0.5));
  connect(PF3U.portB1, junction15.portC) annotation (Line(
      points={{120.4,-10.2},{140,-10.2},{140,-4}},
      color={255,153,0},
      thickness=0.5));
  connect(PF3L.portB1, junction15.portA) annotation (Line(
      points={{120.4,9.8},{140,9.8},{140,4}},
      color={255,153,0},
      thickness=0.5));
  connect(junction19.portC, junction1.portB) annotation (Line(
      points={{40,24},{40,60},{56,60}},
      color={255,153,0},
      thickness=0.5));
  connect(junction19.portA, junction12.portB) annotation (Line(
      points={{40,16},{40,-20},{56,-20}},
      color={255,153,0},
      thickness=0.5));
  connect(fan2ndOrder.portB, sensor_m_flow.portA) annotation (Line(
      points={{-68,120},{-73,120}},
      color={255,153,0},
      thickness=0.5));
  connect(sensor_m_flow.portB, junction5.portA) annotation (Line(
      points={{-79,120},{-112,120},{-112,104}},
      color={255,153,0},
      thickness=0.5));
  connect(wantedTemp.y, PID.u_s) annotation (Line(points={{-135,80},{-70,80},{
          -70,62}},               color={0,0,127}));
  connect(sensor_T.sensorValue, PID.u_m)
    annotation (Line(points={{-12,46},{-12,52},{-50,52},{-50,50},{-58,50}},
                                                          color={0,0,127}));
  connect(sensor_T.sensorValue, sensorTFiltered.u)
    annotation (Line(points={{-12,46},{-12,22},{-18,22}}, color={0,0,127}));
  connect(valveRegulator.y, limiter.u) annotation (Line(points={{-119,170},{-82,
          170}},                            color={0,0,127}));
  connect(valve1Command.y, valve1.KvValue_in) annotation (Line(points={{-35,170},
          {-42,170},{-42,102.75}},                     color={0,0,127}));
  connect(tube1.portB, valve3.portA) annotation (Line(
      points={{-42,-60},{-42,-59},{-32,-59}},
      color={255,153,0},
      thickness=0.5));
  connect(junction21.portC, junction19.portB) annotation (Line(
      points={{16,20},{36,20}},
      color={255,153,0},
      thickness=0.5));
  connect(junction21.portB, valve4.portA) annotation (Line(
      points={{12,24},{12,59}},
      color={255,153,0},
      thickness=0.5));
  connect(valve4.portB, junction20.portB) annotation (Line(
      points={{12,71},{12,116}},
      color={255,153,0},
      thickness=0.5));
  connect(junction20.portC, junction4.portA) annotation (Line(
      points={{8,120},{-16,120}},
      color={255,153,0},
      thickness=0.5));
  connect(junction20.portA, junction18.portB) annotation (Line(
      points={{16,120},{200,120},{200,20},{184,20}},
      color={255,153,0},
      thickness=0.5));
  connect(valve.portB, junction2.portB) annotation (Line(
      points={{-146,-71},{-146,68},{-116,68}},
      color={255,153,0},
      thickness=0.5));
  connect(junction7.portC, valve6.portA) annotation (Line(
      points={{-112,-10},{-112,-19}},
      color={255,153,0},
      thickness=0.5));
  connect(valve6.portB, tube1.portA) annotation (Line(
      points={{-112,-31},{-112,-60},{-58,-60}},
      color={255,153,0},
      thickness=0.5));
  connect(junction7.portB, valve5.portA) annotation (Line(
      points={{-108,-6},{-106,-5},{-80,-5}},
      color={255,153,0},
      thickness=0.5));
  connect(valve3.portB, junction23.portC) annotation (Line(
      points={{-20,-59},{-12,-59},{-12,-10}},
      color={255,153,0},
      thickness=0.5));
  connect(valve5.portB, junction23.portB) annotation (Line(
      points={{-68,-5},{-20,-5},{-20,-6},{-16,-6}},
      color={255,153,0},
      thickness=0.5));
  connect(junction5.portC, junction2.portA) annotation (Line(
      points={{-112,96},{-112,72}},
      color={255,153,0},
      thickness=0.5));
  connect(CoolingLimiter1.y, firstOrder.u)
    annotation (Line(points={{-205,-44},{-194,-44}}, color={0,0,127}));
  connect(firstOrder.y, valve6.KvValue_in) annotation (Line(points={{-171,-44},{
          -120,-44},{-120,-25},{-115.75,-25}}, color={0,0,127}));
  connect(HeaterLimiter.y, firstOrder1.u)
    annotation (Line(points={{-277,40},{-250,40}}, color={0,0,127}));
  connect(firstOrder1.y, prescribedHeatFlow1.Q_flow)
    annotation (Line(points={{-227,40},{-200,40}},color={0,0,127}));
  connect(junction2.portC, Heater.portA) annotation (Line(
      points={{-112,64},{-112,52},{-114,52},{-114,48}},
      color={255,153,0},
      thickness=0.5));
  connect(Heater.portB, junction7.portA) annotation (Line(
      points={{-114,32},{-114,2},{-112,2},{-112,-2}},
      color={255,153,0},
      thickness=0.5));
  connect(junction23.portA, junction21.portA) annotation (Line(
      points={{-12,-2},{-12,20},{8,20}},
      color={255,153,0},
      thickness=0.5));
  connect(junction23.portA, sensor_T.port) annotation (Line(
      points={{-12,-2},{-12,40}},
      color={255,153,0},
      thickness=0.5));
  connect(prescribedHeatFlow1.port, Heater.heatPort[1])
    annotation (Line(points={{-180,40},{-116,40}}, color={191,0,0}));
  connect(BypassLimiter.y, firstOrder2.u)
    annotation (Line(points={{-221,8},{-194,8}}, color={0,0,127}));
  connect(firstOrder2.y, valve5.KvValue_in)
    annotation (Line(points={{-171,8},{-74,8},{-74,-1.25}}, color={0,0,127}));
  connect(firstOrder3.y, valve4.KvValue_in) annotation (Line(points={{1,70},{4,
          70},{4,65},{8.25,65}}, color={0,0,127}));
  connect(bypassRegulatorOverCool.y, firstOrder3.u)
    annotation (Line(points={{-33,70},{-22,70}}, color={0,0,127}));
  annotation (Diagram(coordinateSystem(preserveAspectRatio=false, extent={{-100,
            -100},{100,100}})),
    experiment(
      StopTime=1815,
      __Dymola_NumberOfIntervals=50,
      __Dymola_Algorithm="Dassl"),
    __Dymola_experimentSetupOutput,
    uses(
      ThermalSystems(version="1.13.0"),
      TSMedia(version="1.13.0"),
      Modelica(version="4.0.0")),
    version="1",
    conversion(noneFromVersion=""));
end PFCircuit;
