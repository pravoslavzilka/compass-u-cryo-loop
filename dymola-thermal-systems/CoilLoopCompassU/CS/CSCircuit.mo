within CoilLoopCompassU.CS;
model CSCircuit
  extends ThermalSystems.Internals.ClassTypes.ExampleModel;

  // ---------------------------------------------------------------------
  // Sourcing summary -- full reasoning in docs/design-basis/cs-circulator-sizing.md.
  // FROM SOURCE (ATEKO 22172-Z-R1): worst-case coil temp 137.5 K (Tab.5),
  // total design flow 0.17 kg/s at 137 K (S6.5.2), design pressure -1/95
  // barg (S6.5.2), nominal working (discharge) pressure 81 barg (S6.5.2),
  // tempMargin 40 K max inlet-outlet dT (S3.4), coil topology 5 objects /
  // 1-2 channels each (Tab.2, CS1/CS3U/CS3L=2ch@88m, CS2U/CS2L=1ch@86m),
  // channel equivalent diameter 6.96025 mm (Tab.2), channel-only pressure
  // loss ~13.7 bar interpolated at 81 barg/137K (Tab.9), real coil weights
  // 714 kg (CS1/CS3U/CS3L) / 349 kg (CS2U/CS2L) (Tab.5).
  // CALCULATED: fan2ndOrder dp_nominal/V_flow_nominal/p_nominal (channel
  // loss + assumed header/valve/HX margin -- see Open Items, this is the
  // weakest number in this file, same caveat TF's build flagged for its
  // own dp_nominal), pressure-control hysteresis bands (scaled from PF's
  // relative fractions around its own setpoint, not independently sized).
  // CoilAssembly.mo/CoilAssembly2ch.mo now also carry: real 8x6.2mm
  // elliptical channel geometry (crossSectionArea/wettedPerimeter, direct
  // computation, replacing the old circular equivalent-diameter
  // approximation -- see gap 1, same fix as TF's acba24f), copper wall
  // thickness sized to the real ATEKO coil weights above (gap 2, same
  // method as TF's acba24f), a Dittus-Boelter alphaConstant scaled from
  // TF's own reverse-engineered value (gap 1's ConstantAlpha/ConstantR
  // switch, needed because the library's geometry-based correlations only
  // support circular tubes -- see TF's own tf-circulator-sizing.md), and
  // an assemblyIndex/lengthAdjusted anti-degeneracy fix on CS2U/CS2L (gap
  // 4 -- CoilAssembly2ch already had this for CS1/CS3U/CS3L, carried from
  // PF; the plain CoilAssembly class did not, despite CS2U/CS2L being
  // structurally identical instances connected via a chain of
  // zero-resistance VolumeJunctions, the same class of risk TF's
  // TFUL1/TFUL2 hit).
  // ASSUMED (carried from PF's validated choices, no CS-specific vendor
  // data): n_nominal=200 Hz, eta_maxPhyd=0.6, maxDeltaT=20 K,
  // coilIsolationCloseMargin/ReopenMargin=40/35 K, PID gains, evaporator
  // tube sizing, discharge-pulse timing (5s window). RV07/RV08's plain PID
  // trim (gap 3) is kept as-is, reasoned rather than silently copied or
  // silently upgraded -- see RV07Command's docstring and
  // cs-circulator-sizing.md S8.
  // ---------------------------------------------------------------------

  parameter Real Kv_shut = 1e-4;
  parameter Modelica.Units.SI.TemperatureDifference tempMargin=40
    "Max coolant-to-coil / inlet-outlet dT -- FROM SOURCE, ATEKO S3.4: 'maximal temperature difference 40K (T inlet - T outlet)', named explicitly for this signal pair -- more precisely sourced than PF's own tempMargin, which its design-basis doc flags as [UNVERIFIED] for exactly this ambiguity.";
  parameter Boolean enableCoilIsolation = true
    "Master switch for the 3 two-channel assemblies' (CS1/CS3U/CS3L) relative-margin isolation valves. CS2U/CS2L are NOT covered by this -- see the deliberate scope note on nIso below.";
  parameter Modelica.Units.SI.TemperatureDifference coilIsolationCloseMargin = 40
    "ASSUMED, carried from PF's PFCircuit.mo default -- no CS-specific basis found in ATEKO or the (unread, see Open Items) thesis.";
  parameter Modelica.Units.SI.TemperatureDifference coilIsolationReopenMargin = 35
    "ASSUMED, carried from PF's PFCircuit.mo default -- see coilIsolationCloseMargin.";
  parameter Modelica.Units.SI.Time controlActivationDelay = 5
    "ASSUMED, carried from PF -- lets T_gas_out_max settle past its junction-initial-condition artifact before isolation/pressure control react, same rationale as PF's own docstring for this parameter.";
  parameter Integer nIso = 3
    "Number of isolation-controlled branches: CS1, CS3U, CS3L (the 2-channel assemblies, order matches coilOpen/kvTarget below). CS2U/CS2L use PF's plain CoilAssembly (no KvValue_in port, same as PF's own unused 1-channel base model in PFCircuit.mo) and always run fully open -- a deliberate scope simplification, not an oversight: see docs/design-basis/cs-circulator-sizing.md Open Items.";

  // --- fan2ndOrder sizing -- see design-basis doc S3 for the full derivation ---
  parameter Modelica.Units.SI.Frequency n_nominal_Hz = 200
    "ASSUMED, carried from PF's validated 200 Hz (12,000 rpm) choice -- no CS-specific vendor curve.";
  parameter Modelica.Units.SI.PressureDifference dp_nominal_Pa = 1750000
    "CALCULATED: ATEKO Tab.9 channel-only loss at 81 barg/137K interpolated to ~13.71 bar, +28% assumed margin for header/valves/HX (not in ATEKO's channel-only table) = 17.5 bar. Weakest number in this file -- see Open Items.";
  parameter Modelica.Units.SI.VolumeFlowRate V_flow_nominal_val = 0.0075
    "CALCULATED: 0.17 kg/s (FROM SOURCE, S6.5.2) / ideal-gas He density at true suction (64.5 bara, 137.5 K) = 22.59 kg/m3 -> 0.00753 m3/s, rounded.";
  parameter Modelica.Units.SI.AbsolutePressure p_nominal_Pa = 6450000
    "CALCULATED: declared directly at the true suction estimate (discharge 82 bara - dp_nominal 17.5 bar = 64.5 bara), improving on PF's own flagged p_nominal mismatch (PF's design-basis doc recommends declaring this at true suction, not a value that sits ambiguously between suction and discharge).";

  // --- suction pressure-control setpoint/bands, scaled from PF's relative fractions ---
  parameter Modelica.Units.SI.AbsolutePressure pressureSetpoint = 6450000
    "= p_nominal_Pa, suction-node target.";
  parameter Modelica.Units.SI.AbsolutePressure pMakeupOpen = 6000000
    "CALCULATED: pressureSetpoint * 0.93, scaled from PF's own (pMakeupOpen/pressureSetpoint) fraction -- not independently sized for CS.";
  parameter Modelica.Units.SI.AbsolutePressure pMakeupClose = 6200000
    "CALCULATED: pressureSetpoint * 0.96, same scaling basis as pMakeupOpen.";
  parameter Modelica.Units.SI.AbsolutePressure pReliefOpen = 6900000
    "CALCULATED: pressureSetpoint * 1.07, same scaling basis as pMakeupOpen.";
  parameter Modelica.Units.SI.AbsolutePressure pReliefClose = 6650000
    "CALCULATED: pressureSetpoint * 1.03, same scaling basis as pMakeupOpen.";
  parameter Modelica.Units.SI.AbsolutePressure pMakeupReservoir = 7900000
    "CALCULATED: pressureSetpoint * 1.23, same relative gap PF uses between its own pMakeupReservoir and pressureSetpoint.";
  parameter Modelica.Units.SI.AbsolutePressure pReliefReservoir = 5300000
    "CALCULATED: pressureSetpoint * 0.82, same relative gap PF uses between its own pReliefReservoir and pressureSetpoint.";
  parameter Modelica.Units.SI.Temperature TStorageReservoirs = 80
    "ASSUMED, carried from PF -- generic cold-storage boundary temperature, no CS-specific basis.";
  parameter Real kPressurePID = 0.05 "ASSUMED, carried from PF's own placeholder -- PF's doc itself calls this untuned.";
  parameter Modelica.Units.SI.Time TiPressurePID = 30 "ASSUMED, carried from PF's own placeholder.";
  parameter Real KvGainMakeup = 2 "ASSUMED, carried from PF's post-2026-09-01 trim gain.";
  parameter Real KvMakeupMax = 15 "ASSUMED, carried from PF.";
  parameter Real KvGainRelief = 2 "ASSUMED, carried from PF.";
  parameter Real KvReliefMax = 15 "ASSUMED, carried from PF.";
  parameter Real Kv_shut_pressureValves = 1e-2 "ASSUMED, carried from PF -- see PF's own docstring on why this differs from the shared Kv_shut.";
  parameter Modelica.Units.SI.Time valveRampTime = 8 "ASSUMED, carried from PF's post-2026-08-10 value (not the earlier 2-3s that PF found caused solver collapses).";

  output Modelica.Units.SI.Temperature T_gas_out_max = max({CS1.T_gas_out,
      CS2U.T_gas_out, CS2L.T_gas_out, CS3U.T_gas_out, CS3L.T_gas_out})
    "Hottest coil-assembly gas outlet temperature across all 5 CS coils.";
  output Modelica.Units.SI.Temperature wanted_temp = T_gas_out_max - tempMargin
    "Heater setpoint: hottest coil outlet minus tempMargin, mirrors PF's wanted_temp.";

  Real T_gas_out_iso[nIso] = {CS1.T_gas_out, CS3U.T_gas_out, CS3L.T_gas_out}
    "Live T_gas_out for the 3 isolation-controlled assemblies, order: CS1, CS3U, CS3L.";
  Real valveKvNominal_iso[nIso] = {CS1.valveKvNominal, CS3U.valveKvNominal,
      CS3L.valveKvNominal};
  Real T_gas_out_compare_iso[nIso]
    "T_gas_out_iso[i] while open (live), T_gas_out_frozen[i] while closed.";
  Real kvTarget_iso[nIso]
    "Commanded Kv per isolation-controlled assembly before smoothing.";
  Boolean coilOpen[nIso](start=fill(true, nIso), fixed=fill(true, nIso))
    "Per-assembly isolation latch for CS1/CS3U/CS3L, same relative-margin rule as PF's coilIsolation* (no lowTempCoolantOptimization overlay -- that PF refinement is out of scope here, see Open Items).";
  Real T_gas_out_frozen[nIso](each start=0, each fixed=true)
    "Snapshot of T_gas_out_iso[i] taken the instant coilOpen[i] closes, held constant while closed.";

  inner ThermalSystems.SystemInformationManager sim(
      generateEventsAtFlowReversalGas=false,
      redeclare
      TSMedia.GasTypes.BaseGas gasType1(
      fixedMixingRatio=true,
      nc_propertyCalculation=1,
      gasNames={"VDIWA2006.Helium"},
      mixingRatio_propertyCalculation={1},
      condensingIndex=0)) annotation (Placement(transformation(extent={{180,160},
            {200,180}}, rotation=0)));

  ThermalSystems.GasComponents.Fans.Fan2ndOrder fan2ndOrder(
    orientation="symmetric",
    use_mechanicalPort=true,
    maxDeltaT=20,
    n_nominal=n_nominal_Hz,
    dp_nominal(displayUnit="bar") = dp_nominal_Pa,
    V_flow_nominal=V_flow_nominal_val,
    V_flow0=1.21*V_flow_nominal_val,
    T_nominal(displayUnit="K") = 137.5,
    p_nominal=p_nominal_Pa,
    eta_maxPhyd=0.6,
    dpInitial(displayUnit="bar") = 8200000,
    V_flow_Start=0.003)
    annotation (Placement(transformation(extent={{8,-8},{-8,8}}, rotation=90,
        origin={-60,120})));
  ThermalSystems.OtherComponents.Sources.SmoothStep smoothStep(
    initialValue=n_nominal_Hz,
    endValue=n_nominal_Hz,
    startTime=1,
    stepPeriod=10)
    "Fixed-speed circulator, same as PF's actual implementation (fan2ndOrder runs open-loop at n_nominal, not dynamically PID-controlled -- PF's temperature PID modulates the heater/cooling/bypass valves instead, not circulator speed)."
    annotation (Placement(transformation(extent={{-6,-6},{6,6}}, rotation=0,
        origin={-186,156})));
  ThermalSystems.OtherComponents.Mechanical.RotatoryBoundary rotatoryBoundary(
    phiInitial=0,
    boundaryType="n",
    use_nInput=true)
    annotation (Placement(transformation(extent={{-4,9},{4,-9}}, rotation=270,
        origin={-60,131})));

  Modelica.Thermal.HeatTransfer.Sources.FixedTemperature coldSurface(T(
        displayUnit="K") = 77)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=270, origin={-50,-30})));
  ThermalSystems.GasComponents.Tubes.Tube tube1(
    tubeGeometry(
      innerDiameter=0.012,
      length=10,
      nParallelTubes=25,
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
    pInitial=8200000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = 80)
    "Evaporator: helium/LIN heat exchange, modeled as PF's is -- an ideal 77K coldSurface boundary rather than the real HE01/HE02+VE01 thermosiphon ATEKO describes (S6.1/S6.2). nParallelTubes=25 is ASSUMED, not sourced -- ATEKO gives no evaporator sizing, same gap PF's own model has (see PF's design-basis doc S1 caveat in S9)."
    annotation (Placement(transformation(extent={{-8,-2},{8,2}}, rotation=0,
        origin={-50,-60})));

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
    pInitial=8200000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = 80)
    "Electric heater EH01, off during normal cooldown (ATEKO S6.1: 'electric heater is switched off during normal operation'). Heating-only PID below -- PF's separate cooling-valve/bypass-overcool subsystem (valve3/4/5/6) is deliberately out of scope here, see Open Items."
    annotation (Placement(transformation(extent={{8,-2},{-8,2}}, rotation=90,
        origin={-112,40})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlowHeater
    annotation (Placement(transformation(extent={{-200,30},{-180,50}})));
  Modelica.Blocks.Continuous.LimPID PID_temp(
    controllerType=Modelica.Blocks.Types.SimpleController.PI,
    k=0.12,
    Ti=12,
    yMax=1,
    yMin=0,
    initType=Modelica.Blocks.Types.Init.InitialOutput,
    y_start=0)
    "Heating-only split-range: u_s=wanted_temp, u_m=sensor_T.sensorValue, y in [0,1] -> PrescribedHeatFlow via heater_gain. Simplified vs. PF's 3-way heater/cooling/bypass hysteresis switch -- see Heater's docstring."
    annotation (Placement(transformation(extent={{-10,10},{10,-10}}, rotation=
           -90, origin={-70,50})));
  parameter Real heater_gain = 100000 "ASSUMED: W per unit PID_temp.y -- no CS-specific heater sizing found in ATEKO.";

  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionS1(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90,
        origin={20,20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionS2(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90,
        origin={40,20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionS3(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90,
        origin={60,20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionS4(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90,
        origin={80,20})));

  CoilAssembly2ch CS1(
    TInitial(displayUnit="K") = 137.5, assemblyIndex=1, nCellsPerTube=8)
    annotation (Placement(transformation(extent={{100,60},{120,80}})));
  CoilAssembly CS2U(length=86, TInitial(displayUnit="K") = 137.5,
    dischargeLoad=1560000, assemblyIndex=4)
    annotation (Placement(transformation(extent={{100,20},{120,40}})));
  CoilAssembly CS2L(length=86, TInitial(displayUnit="K") = 137.5,
    dischargeLoad=1560000, assemblyIndex=5)
    annotation (Placement(transformation(extent={{100,-20},{120,0}})));
  CoilAssembly2ch CS3U(
    TInitial(displayUnit="K") = 137.5, assemblyIndex=2, nCellsPerTube=8)
    annotation (Placement(transformation(extent={{100,-60},{120,-40}})));
  CoilAssembly2ch CS3L(
    TInitial(displayUnit="K") = 137.5, assemblyIndex=3, nCellsPerTube=8)
    annotation (Placement(transformation(extent={{100,-100},{120,-80}})));

  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionR1(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    "Merges CS3U + CS3L (the last pair tapped from junctionS4)."
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90,
        origin={140,-70})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionR2(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90,
        origin={160,-10})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionR3(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90,
        origin={180,30})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionR4(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90,
        origin={200,70})));

  ThermalSystems.GasComponents.Sensors.Sensor_T sensor_T
    annotation (Placement(transformation(extent={{206,80},{214,88}})));

  Modelica.Blocks.Continuous.FirstOrder firstOrderCoilKv[nIso](each T=3)
    "Smooths each isolation-controlled coil's Kv step, same anti-chatter role as PF's firstOrderCoilKv."
    annotation (Placement(transformation(extent={{-20,-140},{0,-120}})));

  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction22(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    "Suction-node tee: portA from junctionR4/return header, portB to RV07, portC to RV08 -- same role as PF's junction22."
    annotation (Placement(transformation(extent={{-4,4},{4,-4}}, rotation=90,
        origin={-2,156})));
  ThermalSystems.GasComponents.Boundaries.Boundary makeupReservoir(
    TFixed(displayUnit="K") = TStorageReservoirs,
    boundaryType="p", pFixed=pMakeupReservoir)
    annotation (Placement(transformation(extent={{34,194},{42,214}})));
  ThermalSystems.GasComponents.Boundaries.Boundary reliefReservoir(
    TFixed(displayUnit="K") = TStorageReservoirs,
    boundaryType="p", pFixed=pReliefReservoir)
    annotation (Placement(transformation(extent={{-24,168},{-16,188}})));
  ThermalSystems.GasComponents.Volumes.Volume makeupBuffer(
    volume=1e-2, enableHeatPort=false, m_flowStart=0, pInitial=pMakeupReservoir,
    fixedInitialPressure=false, TInitial(displayUnit="K") = TStorageReservoirs,
    nPorts=2)
    "Compliant buffer between the ideal makeupReservoir boundary and RV07 -- carried from PF's 2026-08-10 fix (a valve bridging a compliant node directly to a rigid ideal boundary caused solver collapses in PF; untested here, but the fix is cheap to include preemptively)."
    annotation (Placement(transformation(extent={{52,194},{60,202}})));
  ThermalSystems.GasComponents.Volumes.Volume reliefBuffer(
    volume=1e-2, enableHeatPort=false, m_flowStart=0, pInitial=pReliefReservoir,
    fixedInitialPressure=false, TInitial(displayUnit="K") = TStorageReservoirs,
    nPorts=2)
    annotation (Placement(transformation(extent={{-36,182},{-28,190}})));
  ThermalSystems.GasComponents.Valves.Valve RV07(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false, use_KvValueInput=true,
    KvValueFixed=Kv_shut_pressureValves)
    annotation (Placement(transformation(extent={{6,-3},{-6,3}}, rotation=0,
        origin={16,180})));
  ThermalSystems.GasComponents.Valves.Valve RV08(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false, use_KvValueInput=true,
    KvValueFixed=Kv_shut_pressureValves)
    annotation (Placement(transformation(extent={{6,-3},{-6,3}}, rotation=0,
        origin={-8,204})));
  ThermalSystems.GasComponents.Sensors.Sensor_p sensor_p_suction
    "CLASS NAME carried from PF's own PFCircuit.mo, where it is itself flagged 'ASSUMED by analogy... verify at translate-check' -- same unverified status here, not newly invented."
    annotation (Placement(transformation(extent={{58,134},{66,142}})));
  Modelica.Blocks.Continuous.LimPID PID_pressure(
    controllerType=Modelica.Blocks.Types.SimpleController.PI,
    k=kPressurePID, Ti=TiPressurePID, yMax=7.5, yMin=-7.5,
    initType=Modelica.Blocks.Types.Init.InitialOutput, y_start=0)
    annotation (Placement(transformation(extent={{120,160},{140,180}})));
  Modelica.Blocks.Sources.RealExpression RV07Command(y=min(max(PID_pressure.y,
      0)*KvGainMakeup, KvMakeupMax))
    "Simplified vs. PF: plain PID-proportional trim, no pulse-then-trim feedforward. Deliberately left this way, not ported from PF -- reasoned decision, not a silent gap: TF's own RV07/RV08 (the real structural analog -- TF's bypassHysteresis/BypassLimiter wiring that acba24f fixed governs a different subsystem, the heater/cooling/bypass triad on valve5/valve6, not suction pressure) use this identical plain-trim architecture, and TF's suction-node compliance (junction22+makeupBuffer+reliefBuffer, each 1e-2 m3) is numerically identical to CS's here, with TF's model translating/simulating successfully on it. See cs-circulator-sizing.md S8 for the full comparison."
    annotation (Placement(transformation(extent={{-40,258},{-20,278}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderRV07(T=valveRampTime)
    annotation (Placement(transformation(extent={{0,260},{20,280}})));
  Modelica.Blocks.Sources.RealExpression RV08Command(y=min(max(-PID_pressure.y,
      0)*KvGainRelief, KvReliefMax))
    annotation (Placement(transformation(extent={{-80,220},{-60,240}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderRV08(T=valveRampTime)
    annotation (Placement(transformation(extent={{-40,220},{-20,240}})));

equation
  // circulator, fixed speed
  connect(smoothStep.y, rotatoryBoundary.n_in) annotation (Line(points={{-179.4,
          156},{-170,156},{-170,131},{-64,131}}, color={0,0,127}));
  connect(rotatoryBoundary.rotatoryFlange, fan2ndOrder.rotatoryFlange)
    annotation (Line(points={{-60,131},{-60,128}}, color={135,135,135},
      thickness=0.5));

  // heater
  PID_temp.u_s = wanted_temp;
  PID_temp.u_m = sensor_T.sensorValue;
  prescribedHeatFlowHeater.Q_flow = PID_temp.y*heater_gain;
  connect(prescribedHeatFlowHeater.port, Heater.heatPort[1]) annotation (Line(
      points={{-180,40},{-116,40}}, color={191,0,0}));

  // evaporator
  connect(coldSurface.port, tube1.heatPort[1]) annotation (Line(points={{-50,-40},
          {-50,-58}}, color={191,0,0}));

  // main flow path: fan -> Heater -> tube1(evaporator) -> supply manifold
  connect(fan2ndOrder.portB, Heater.portA) annotation (Line(points={{-60,128},
          {-60,140},{-112,140},{-112,48}}, color={255,153,0}, thickness=0.5));
  connect(Heater.portB, tube1.portA) annotation (Line(points={{-112,32},{-112,
          -60},{-58,-60}}, color={255,153,0}, thickness=0.5));
  connect(tube1.portB, junctionS1.portA) annotation (Line(points={{-42,-60},{20,
          -60},{20,16}}, color={255,153,0}, thickness=0.5));

  // supply manifold: junctionS1..S4 tap CS1/CS2U/CS2L/CS3U, S4 also feeds CS3L
  connect(junctionS1.portC, CS1.portA1) annotation (Line(points={{24,20},{60,20},
          {60,70},{99.6,70}}, color={255,153,0}, thickness=0.5));
  connect(junctionS1.portB, junctionS2.portA) annotation (Line(points={{20,24},
          {40,24},{40,16}}, color={255,153,0}, thickness=0.5));
  connect(junctionS2.portC, CS2U.portA1) annotation (Line(points={{44,20},{70,
          20},{70,30},{99.6,30}}, color={255,153,0}, thickness=0.5));
  connect(junctionS2.portB, junctionS3.portA) annotation (Line(points={{40,24},
          {60,24},{60,16}}, color={255,153,0}, thickness=0.5));
  connect(junctionS3.portC, CS2L.portA1) annotation (Line(points={{64,20},{80,
          20},{80,-10},{99.6,-10}}, color={255,153,0}, thickness=0.5));
  connect(junctionS3.portB, junctionS4.portA) annotation (Line(points={{60,24},
          {80,24},{80,16}}, color={255,153,0}, thickness=0.5));
  connect(junctionS4.portC, CS3U.portA1) annotation (Line(points={{84,20},{90,
          20},{90,-50},{99.6,-50}}, color={255,153,0}, thickness=0.5));
  connect(junctionS4.portB, CS3L.portA1) annotation (Line(points={{80,24},{95,
          24},{95,-90},{99.6,-90}}, color={255,153,0}, thickness=0.5));

  // return manifold: R1 merges CS3U+CS3L, chain outward through R2/R3/R4
  connect(CS3U.portB1, junctionR1.portA) annotation (Line(points={{120.4,-50},
          {140,-50},{140,-66}}, color={255,153,0}, thickness=0.5));
  connect(CS3L.portB1, junctionR1.portC) annotation (Line(points={{120.4,-90},
          {130,-90},{130,-70},{136,-70}}, color={255,153,0}, thickness=0.5));
  connect(junctionR1.portB, junctionR2.portA) annotation (Line(points={{140,-66},
          {160,-66},{160,-14}}, color={255,153,0}, thickness=0.5));
  connect(CS2L.portB1, junctionR2.portC) annotation (Line(points={{120.4,-10},
          {150,-10},{156,-10}}, color={255,153,0}, thickness=0.5));
  connect(junctionR2.portB, junctionR3.portA) annotation (Line(points={{160,-6},
          {180,-6},{180,26}}, color={255,153,0}, thickness=0.5));
  connect(CS2U.portB1, junctionR3.portC) annotation (Line(points={{120.4,30},
          {176,30}}, color={255,153,0}, thickness=0.5));
  connect(junctionR3.portB, junctionR4.portA) annotation (Line(points={{180,34},
          {200,34},{200,66}}, color={255,153,0}, thickness=0.5));
  connect(CS1.portB1, junctionR4.portC) annotation (Line(points={{120.4,70},
          {196,70}}, color={255,153,0}, thickness=0.5));
  connect(junctionR4.portB, sensor_T.port) annotation (Line(points={{200,74},
          {200,84},{206,84}}, color={255,153,0}, thickness=0.5));
  connect(junctionR4.portB, junction22.portA) annotation (Line(points={{200,74},
          {200,156},{2,156}}, color={255,153,0}, thickness=0.5));
  connect(junction22.portB, fan2ndOrder.portA) annotation (Line(points={{-2,152},
          {-2,110},{-60,110},{-60,112}}, color={255,153,0}, thickness=0.5));

  // isolation valve control, CS1/CS3U/CS3L only -- same for-loop/when idiom
  // as PF's PFCircuit.mo (algorithm section, pre() referencing previous value)
  for i in 1:nIso loop
    kvTarget_iso[i] = if coilOpen[i] then valveKvNominal_iso[i] else Kv_shut;
    firstOrderCoilKv[i].u = kvTarget_iso[i];
    T_gas_out_compare_iso[i] = if coilOpen[i] then T_gas_out_iso[i] else
      T_gas_out_frozen[i];
  end for;
  CS1.KvValue_in1 = firstOrderCoilKv[1].y;
  CS3U.KvValue_in1 = firstOrderCoilKv[2].y;
  CS3L.KvValue_in1 = firstOrderCoilKv[3].y;

  // suction pressure control
  connect(sensor_p_suction.port, junction22.portC);
  PID_pressure.u_s = pressureSetpoint;
  PID_pressure.u_m = sensor_p_suction.sensorValue;
  RV07.KvValue_in = firstOrderRV07.y;
  firstOrderRV07.u = RV07Command.y;
  RV08.KvValue_in = firstOrderRV08.y;
  firstOrderRV08.u = RV08Command.y;
  connect(makeupReservoir.port, makeupBuffer.portArray[1]) annotation (Line(
      points={{42,204},{52,204},{52,198}}, color={255,153,0}, thickness=0.5));
  connect(makeupBuffer.portArray[2], RV07.portA) annotation (Line(points={{52,
          198},{22,198},{22,180}}, color={255,153,0}, thickness=0.5));
  connect(RV07.portB, junction22.portB) annotation (Line(points={{10,180},{
          -2,180},{-2,160}}, color={255,153,0}, thickness=0.5));
  connect(reliefReservoir.port, reliefBuffer.portArray[1]) annotation (Line(
      points={{-16,178},{-32,178},{-32,186}}, color={255,153,0}, thickness=0.5));
  connect(reliefBuffer.portArray[2], RV08.portA) annotation (Line(points={{-32,
          186},{-14,186},{-14,204}}, color={255,153,0}, thickness=0.5));
  connect(RV08.portB, junction22.portC) annotation (Line(points={{-14,204},{
          -6,204},{-6,160}}, color={255,153,0}, thickness=0.5));

algorithm
  for i in 1:nIso loop
    when enableCoilIsolation and time >= controlActivationDelay and
        (T_gas_out_max - T_gas_out_compare_iso[i]) < coilIsolationReopenMargin
        and not pre(coilOpen[i]) then
      coilOpen[i] := true;
    elsewhen enableCoilIsolation and (T_gas_out_max - T_gas_out_iso[i]) >
        coilIsolationCloseMargin and pre(coilOpen[i]) then
      coilOpen[i] := false;
      T_gas_out_frozen[i] := T_gas_out_iso[i];
    end when;
  end for;

  annotation (Diagram(coordinateSystem(preserveAspectRatio=false, extent={{-360,
            -160},{260,300}})),
    experiment(
      StopTime=1800,
      __Dymola_NumberOfIntervals=50,
      __Dymola_Algorithm="Dassl"),
    __Dymola_experimentSetupOutput,
    uses(
      ThermalSystems(version="1.13.0"),
      TSMedia(version="1.13.0"),
      Modelica(version="4.0.0")),
    version="1",
    conversion(noneFromVersion=""));
end CSCircuit;
