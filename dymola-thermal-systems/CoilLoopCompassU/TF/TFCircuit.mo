within CoilLoopCompassU.TF;
model TFCircuit
  extends ThermalSystems.Internals.ClassTypes.ExampleModel;
  // ===========================================================================
  // TF coil cooling loop, structural analog of PF/PFCircuit.mo, sized from
  // ATEKO study 22172-Z-R1. See docs/design-basis/tf-circulator-sizing.md
  // for parameter sourcing.
  //
  // Circulator (fan2ndOrder) with speed ramp, electric heater with
  // hysteresis-gated PID temperature control, LIN-side evaporator (tube1
  // vs a fixed 77K coldSurface), 4 parallel coil branches (TFCL1, Structure,
  // TFUL1, TFUL2) each behind its own isolation valve with a relative-margin
  // close/reopen rule (coilOpen[nTF]), a bypass valve pair, RV07/RV08
  // make-up/relief valves to storage reservoirs holding suction pressure.
  //
  // RV07/RV08 use a plain continuous proportional trim (simpler than PF's
  // pulse-then-trim scheme). PF's valve4/overCoolRecovering bypass state
  // machine and PID_circulatorPower/PF_RV01 shaft-power limiter are not
  // used here.
  // ===========================================================================

  parameter Real m_total = 1.3 "Total design flow from the circulator, kg/s (ATEKO 22172-Z-R1 S6.5.3, minimal design flow 1.3 kg/s at coil temperature 116 K)";
  parameter Real u_dead = 1;
  parameter Real Kv_shut = 1e-4;
  parameter Real Kv_cool_max = 5000;
  parameter Real heater_gain = 100;
  parameter Real Kv_gain = 100;
  parameter Real bypass_limit = 10
    "Threshold (on -PID.y) above which valve5's bypass leg is throttled back -- see BypassLimiter's docstring.";
  parameter Real hysteresisHalfWidth = 0.3
    "Half-width of the ON/OFF gap around each PID.y switching threshold, anti-chatter.";
  parameter Modelica.Units.SI.TemperatureDifference tempMargin=40
    "Margin below the hottest coil-bus gas outlet temperature (ATEKO 22172-Z-R1 S3.2/S6.4, 40K limit for the cooling system).";
  parameter Integer nTF = 4
    "Number of TF coil branches: TFCL1 (core+lower limb, 112 channels), Structure (coil case/support structure), TFUL1+TFUL2 (upper limb, 56 channels each).";
  parameter Boolean enableCoilIsolation = true
    "Master switch for the per-bus relative-margin isolation rule, same role as PFCircuit.mo's enableCoilIsolation.";
  parameter Modelica.Units.SI.TemperatureDifference coilIsolationCloseMargin = 40
    "Per-bus isolation valve closes once T_gas_out is this much colder than T_gas_out_max -- carried directly from PF (same class of relative-margin isolation rule, no TF-specific tuning data available).";
  parameter Modelica.Units.SI.TemperatureDifference coilIsolationReopenMargin = 35
    "Per-bus isolation valve reopens once within this much of T_gas_out_max -- carried from PF, see coilIsolationCloseMargin.";
  parameter Modelica.Units.SI.Time controlActivationDelay = 5
    "Reopen logic stays disabled until this much simulated time has passed, so it doesn't react to the unsettled startup transient -- same role as PFCircuit.mo's identical parameter.";

  parameter Boolean enablePressureControl = true
    "Master switch for the RV07 (make-up)/RV08 (relief) pressure-control valve pair at the suction node.";
  parameter Modelica.Units.SI.AbsolutePressure pressureSetpoint=2500000
    "Suction-node pressure setpoint, Pa (~24 barg abs, ATEKO 22172-Z-R1 S6.5.3). Held by RV07/RV08's continuous PID trim (see RV07Limiter/RV08Limiter); PID_pressure's own yMax/yMin plus KvMakeupMax/KvReliefMax bound the correction.";
  parameter Real kPressurePID=0.05;
  parameter Modelica.Units.SI.Time TiPressurePID=30;
  parameter Real KvGainMakeup = 5;
  parameter Real KvMakeupMax = 30;
  parameter Real KvGainRelief = 5;
  parameter Real KvReliefMax = 30;
  parameter Modelica.Units.SI.AbsolutePressure pMakeupReservoir=2700000 "Make-up storage reservoir pressure, above pressureSetpoint.";
  parameter Modelica.Units.SI.AbsolutePressure pReliefReservoir=2300000 "Relief storage reservoir pressure, below pressureSetpoint.";
  parameter Modelica.Units.SI.Temperature TStorageReservoirs=80;
  parameter Modelica.Units.SI.Time valveRampTime=3;
  parameter Real Kv_shut_pressureValves = 1e-2;

  Real T_gas_out_TF[nTF] = {TFCL1.T_gas_out, Structure.T_gas_out, TFUL1.T_gas_out, TFUL2.T_gas_out}
    "Same order as coilOpen: TFCL1, Structure, TFUL1, TFUL2";
  Real valveKvNominal_TF[nTF] = {TFCL1.valveKvNominal, Structure.valveKvNominal, TFUL1.valveKvNominal, TFUL2.valveKvNominal};
  Real kvTarget_TF[nTF] "Commanded Kv per bus before smoothing: valveKvNominal_TF when open, Kv_shut when closed";
  Real T_gas_out_compare_TF[nTF] "T_gas_out_TF[i] while open (live), T_gas_out_frozen[i] while closed";
  Boolean coilOpen[nTF](start=fill(true, nTF), fixed=fill(true, nTF))
    "Per-bus isolation valve latch, order: TFCL1,Structure,TFUL1,TFUL2";
  Real T_gas_out_frozen[nTF](each start=0, each fixed=true)
    "Snapshot of T_gas_out_TF[i] taken the instant coilOpen[i] closes -- held constant while closed.";

  output Modelica.Units.SI.Temperature T_gas_out_max = max(T_gas_out_compare_TF)
    "Hottest coil-bus gas outlet temperature.";
  output Modelica.Units.SI.Temperature wanted_temp = T_gas_out_max - tempMargin
    "PID setpoint: hottest bus outlet minus margin.";

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
    n_nominal=200,
    dp_nominal(displayUnit="bar") = 200000,
    V_flow_nominal=0.125,
    V_flow0=0.151,
    T_nominal(displayUnit="K") = 116,
    p_nominal=2500000,
    eta_maxPhyd=0.6,
    dpInitial(displayUnit="bar") = 2500000,
    V_flow_Start=0.01)
    "Circulator sizing: T_nominal/p_nominal from ATEKO worst-case coil temp (116K) and nominal working pressure (24barg); V_flow_nominal/V_flow0 from m_total at suction density; dp_nominal 2 bar working estimate covering header/heater/evaporator/coil/valve losses; remaining parameters carried from PFCircuit.mo's circulator."
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
        origin={-186,156})));
  ThermalSystems.OtherComponents.Mechanical.RotatoryBoundary rotatoryBoundary(
    phiInitial=0,
    boundaryType="n",
    use_nInput=true)
    annotation (Placement(transformation(extent={{-4,9},{4,-9}},
        rotation=270,
        origin={-60,131})));
  Modelica.Thermal.HeatTransfer.Sources.FixedTemperature coldSurface(T(
        displayUnit="K") = 77)
    "LIN-side evaporator boundary, ATEKO 22172-Z-R1 S6.2 (LIN evaporates at 77K)."
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=270,
        origin={-90,-30})));
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
    m_flowStart=0.01,
    pInitial=2500000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = 80)
    "Evaporator geometry carried from PFCircuit.mo's tube1, sized to pass m_total without excessive pressure drop."
    annotation (Placement(transformation(extent={{-8,-2},{8,2}},
        rotation=0,
        origin={-90,-60})));
  ThermalSystems.GasComponents.Tubes.Tube Heater(
    tubeGeometry(
      innerDiameter=0.05,
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
    m_flowStart=0.01,
    pInitial=2500000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = 80)
    "Electric heater, required per ATEKO S6.1 (support structure has huge weight, design case based on 40C temperature difference). Bore widened vs PF's Heater to pass TF's larger m_total."
    annotation (Placement(transformation(
        extent={{8,-2},{-8,2}},
        rotation=90,
        origin={-160,40})));

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
        origin={-90,70})));
  Modelica.Blocks.Sources.RealExpression wantedTemp(y=wanted_temp)
    annotation (Placement(transformation(extent={{-140,80},{-120,100}})));
  ThermalSystems.GasComponents.Sensors.Sensor_T sensor_T
    annotation (Placement(transformation(extent={{-50,30},{-42,38}})));
  Modelica.Blocks.Logical.Hysteresis heaterHysteresis(uLow=u_dead -
        hysteresisHalfWidth, uHigh=u_dead + hysteresisHalfWidth)
    annotation (Placement(transformation(extent={{-340,20},{-320,40}})));
  Modelica.Blocks.Sources.RealExpression HeaterLimiter(y=if heaterHysteresis.y
         then PID.y*heater_gain else 0)
    annotation (Placement(transformation(extent={{-298,30},{-278,50}})));
  Modelica.Blocks.Logical.Hysteresis coolingHysteresis(uLow=-u_dead -
        hysteresisHalfWidth, uHigh=-u_dead + hysteresisHalfWidth)
    annotation (Placement(transformation(extent={{-340,-20},{-320,0}})));
  Modelica.Blocks.Sources.RealExpression CoolingLimiter1(y=if
        coolingHysteresis.y then min(-PID.y*Kv_gain, Kv_cool_max) else
        Kv_shut)
    annotation (Placement(transformation(extent={{-302,-56},{-282,-36}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder(T=2)
    annotation (Placement(transformation(extent={{-268,-56},{-248,-36}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder1(T=1)
    annotation (Placement(transformation(extent={{-248,30},{-228,50}})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow1
    annotation (Placement(transformation(extent={{-200,30},{-180,50}})));
  Modelica.Blocks.Logical.Hysteresis bypassHysteresis(uLow=bypass_limit -
        hysteresisHalfWidth, uHigh=bypass_limit + hysteresisHalfWidth)
    "Third hysteresis gate (with heaterHysteresis/coolingHysteresis) on the split-range heater/cooling/bypass control triad, keyed off PID.y."
    annotation (Placement(transformation(extent={{-340,-60},{-320,-40}})));
  Modelica.Blocks.Sources.RealExpression BypassLimiter(y=if bypassHysteresis.y
         then max(500 + (PID.y*10), Kv_shut) else 500)
    "Drives valve5's bypass leg via bypassHysteresis/firstOrder2."
    annotation (Placement(transformation(extent={{-272,0},{-252,20}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder2(T=1)
    annotation (Placement(transformation(extent={{-238,0},{-218,20}})));

  ThermalSystems.GasComponents.Valves.Valve valve5(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=500)
    "Cooling/bypass trim valve, driven by BypassLimiter/bypassHysteresis/firstOrder2; KvValueFixed=500 is the unused fallback while use_KvValueInput=true."
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=0,
        origin={-92,1})));
  ThermalSystems.GasComponents.Valves.Valve valve6(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=5000)
    annotation (Placement(transformation(extent={{-6,3},{6,-3}},
        rotation=-90,
        origin={-160,-45})));

  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-2, m_flowStart=1e-5, pInitial=2500000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90, origin={-160,-20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction6(
    volume=1e-2, m_flowStart=1e-5, pInitial=2500000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{4,4},{-4,-4}}, rotation=90, origin={-160,0})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction7(
    volume=1e-2, m_flowStart=1e-5, pInitial=2500000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=180, origin={-50,0})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionCL(
    volume=1e-2, m_flowStart=1e-5, pInitial=2500000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = 80)
    "Header tee splitting supply into the two TFCoilBusCoreLower branches."
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90, origin={20,80})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionUL(
    volume=1e-2, m_flowStart=1e-5, pInitial=2500000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = 80)
    "Header tee splitting supply into the two TFCoilBusUpper branches."
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90, origin={20,0})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionSupply(
    volume=1e-2, m_flowStart=1e-5, pInitial=2500000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = 80)
    "Splits supply between the core+lower-limb header and the upper-limb header."
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90, origin={0,40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionReturnCL(
    volume=1e-2, m_flowStart=1e-5, pInitial=2500000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{4,-4},{-4,4}}, rotation=-90, origin={140,80})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionReturnUL(
    volume=1e-2, m_flowStart=1e-5, pInitial=2500000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{4,-4},{-4,4}}, rotation=-90, origin={140,0})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionReturn(
    volume=1e-2, m_flowStart=1e-5, pInitial=2500000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = 80)
    "Merges the two limb-group return headers before the suction node."
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=-90, origin={160,40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction22(
    volume=1e-2, m_flowStart=1e-5, pInitial=2500000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = 80)
    "Suction-node tee: portA to the return header, portB to RV07 (make-up), portC to RV08 (relief) -- same role as PFCircuit.mo's junction22."
    annotation (Placement(transformation(extent={{-4,4},{4,-4}}, rotation=90, origin={-2,156})));

  TFCoilBusCoreLower TFCL1(TInitial(displayUnit="K") = 137, assemblyIndex=1)
    annotation (Placement(transformation(extent={{100,60},{120,80}})));
  TFCoilBusUpper TFUL1(TInitial(displayUnit="K") = 137, assemblyIndex=3)
    annotation (Placement(transformation(extent={{100,-20},{120,0}})));
  TFCoilBusUpper TFUL2(TInitial(displayUnit="K") = 137, assemblyIndex=4)
    annotation (Placement(transformation(extent={{100,0},{120,20}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderCoilKv[nTF](each T=3)
    "Smooths each per-bus Kv step -- same anti-chatter role as PFCircuit.mo's identical block."
    annotation (Placement(transformation(extent={{-220,-100},{-200,-80}})));

  ThermalSystems.GasComponents.Sensors.Sensor_p sensor_p_suction
    annotation (Placement(transformation(extent={{64,160},{72,168}})));
  Modelica.Blocks.Continuous.LimPID PID_pressure(
    controllerType=Modelica.Blocks.Types.SimpleController.PI,
    k=kPressurePID, Ti=TiPressurePID, yMax=7.5, yMin=-7.5,
    initType=Modelica.Blocks.Types.Init.InitialOutput, y_start=0)
    annotation (Placement(transformation(extent={{120,160},{140,180}})));
  ThermalSystems.GasComponents.Boundaries.Boundary makeupReservoir(
    TFixed(displayUnit="K") = TStorageReservoirs, boundaryType="p", pFixed=pMakeupReservoir)
    annotation (Placement(transformation(extent={{88,176},{96,196}})));
  ThermalSystems.GasComponents.Boundaries.Boundary reliefReservoir(
    TFixed(displayUnit="K") = TStorageReservoirs, boundaryType="p", pFixed=pReliefReservoir)
    annotation (Placement(transformation(extent={{-76,194},{-68,214}})));
  ThermalSystems.GasComponents.Volumes.Volume makeupBuffer(
    volume=1e-2, enableHeatPort=false, m_flowStart=0, pInitial=pMakeupReservoir,
    fixedInitialPressure=false, TInitial(displayUnit="K") = TStorageReservoirs, nPorts=2)
    "Compliant buffer between the ideal makeupReservoir boundary and RV07."
    annotation (Placement(transformation(extent={{50,190},{58,198}})));
  ThermalSystems.GasComponents.Volumes.Volume reliefBuffer(
    volume=1e-2, enableHeatPort=false, m_flowStart=0, pInitial=pReliefReservoir,
    fixedInitialPressure=false, TInitial(displayUnit="K") = TStorageReservoirs, nPorts=2)
    annotation (Placement(transformation(extent={{-48,212},{-40,220}})));
  ThermalSystems.GasComponents.Valves.Valve RV07(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false, use_KvValueInput=true,
    KvValueFixed=Kv_shut_pressureValves)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}}, rotation=0, origin={16,156})));
  ThermalSystems.GasComponents.Valves.Valve RV08(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false, use_KvValueInput=true,
    KvValueFixed=Kv_shut_pressureValves)
    annotation (Placement(transformation(extent={{6,-3},{-6,3}}, rotation=0, origin={-8,204})));
  Modelica.Blocks.Sources.RealExpression RV07Limiter(y=if not enablePressureControl
         then Kv_shut_pressureValves else min(max(PID_pressure.y, 0)*KvGainMakeup, KvMakeupMax))
    "Continuous proportional trim for RV07 make-up valve."
    annotation (Placement(transformation(extent={{120,220},{100,240}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderRV07(T=valveRampTime)
    annotation (Placement(transformation(extent={{80,220},{60,240}})));
  Modelica.Blocks.Sources.RealExpression RV08Limiter(y=if not enablePressureControl
         then Kv_shut_pressureValves else min(max(-PID_pressure.y, 0)*KvGainRelief, KvReliefMax))
    annotation (Placement(transformation(extent={{-100,240},{-80,260}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderRV08(T=valveRampTime)
    annotation (Placement(transformation(extent={{-60,240},{-40,260}})));

  TFStructure Structure(TInitial(displayUnit="K") = 80,  assemblyIndex=2)
    annotation (Placement(transformation(extent={{100,80},{120,100}})));
equation
  heaterHysteresis.u = PID.y;
  coolingHysteresis.u = -PID.y;
  bypassHysteresis.u = -PID.y;
  PID_pressure.u_s = pressureSetpoint;
  PID_pressure.u_m = sensor_p_suction.sensorValue;

  for i in 1:nTF loop
    kvTarget_TF[i] = if coilOpen[i] then valveKvNominal_TF[i] else Kv_shut;
    firstOrderCoilKv[i].u = kvTarget_TF[i];
    T_gas_out_compare_TF[i] = if coilOpen[i] then T_gas_out_TF[i] else T_gas_out_frozen[i];
  end for;
  TFCL1.KvValue_in1 = firstOrderCoilKv[1].y;
  Structure.KvValue_in1 = firstOrderCoilKv[2].y;
  TFUL1.KvValue_in1 = firstOrderCoilKv[3].y;
  TFUL2.KvValue_in1 = firstOrderCoilKv[4].y;

algorithm
  for i in 1:nTF loop
    when (enableCoilIsolation and time >= controlActivationDelay
          and (T_gas_out_max - T_gas_out_compare_TF[i]) < coilIsolationReopenMargin
          and not pre(coilOpen[i])) then
      coilOpen[i] := true;
    elsewhen (enableCoilIsolation and (T_gas_out_max - T_gas_out_TF[i]) > coilIsolationCloseMargin
          and pre(coilOpen[i])) then
      coilOpen[i] := false;
      T_gas_out_frozen[i] := T_gas_out_TF[i];
    end when;
  end for;

equation
  connect(smoothStep.y, rotatoryBoundary.n_in)
    annotation (Line(points={{-179.4,156},{-60,156},{-60,135}}, color={0,0,127}));
  connect(rotatoryBoundary.rotatoryFlange, fan2ndOrder.rotatoryFlange)
    annotation (Line(points={{-60,131},{-60,128}}, color={135,135,135}, thickness=0.5));
  connect(coldSurface.port, tube1.heatPort[1]) annotation (Line(points={{-90,-40},
          {-90,-58}},                                                                         color={191,0,0}));
  connect(prescribedHeatFlow1.port, Heater.heatPort[1]) annotation (Line(points={{-180,40},
          {-162,40}},                                                                                  color={191,0,0}));

  connect(fan2ndOrder.portB, Heater.portA) annotation (Line(points={{-68,120},{
          -160,120},{-160,48}},                                                                                          color={255,153,0}, thickness=0.5));
  connect(Heater.portB, junction6.portA) annotation (Line(points={{-160,32},{
          -160,4}},                                                                      color={255,153,0}, thickness=0.5));
  connect(valve6.portB, tube1.portA) annotation (Line(points={{-160,-51},{-160,
          -60},{-98,-60}},                                                                      color={255,153,0}, thickness=0.5));

  connect(junctionUL.portC, TFUL2.portA1) annotation (Line(points={{20,4},{60,4},
          {60,10},{97.2,10}},                                                                         color={255,153,0}, thickness=0.5));

  connect(TFCL1.portB1, junctionReturnCL.portA) annotation (Line(points={{120.4,
          69.8},{140,69.8},{140,76}},                                                                 color={255,153,0}, thickness=0.5));
  connect(TFUL1.portB1, junctionReturnUL.portA) annotation (Line(points={{120.4,
          -10.2},{140,-10.2},{140,-4}},                                                              color={255,153,0}, thickness=0.5));
  connect(TFUL2.portB1, junctionReturnUL.portC) annotation (Line(points={{120.4,
          9.8},{140,9.8},{140,4}},                                                                      color={255,153,0}, thickness=0.5));
  connect(junctionReturnCL.portB, junctionReturn.portA) annotation (Line(points={{144,80},{160,80},{160,44}}, color={255,153,0}, thickness=0.5));
  connect(junctionReturnUL.portB, junctionReturn.portC) annotation (Line(points={{144,0},{160,0},{160,36}}, color={255,153,0}, thickness=0.5));

  connect(junction22.portB, RV07.portA) annotation (Line(points={{2,156},{10,
          156}},                                                                             color={255,153,0}, thickness=0.5));
  connect(RV07.portB, makeupBuffer.portArray[1]) annotation (Line(points={{22,156},
          {54,156},{54,189.975}},                                                                      color={255,153,0}, thickness=0.5));
  connect(makeupBuffer.portArray[2], makeupReservoir.port) annotation (Line(points={{54,
          190.225},{54,186},{92,186}},                                                                           color={255,153,0}, thickness=0.5));
  connect(junction22.portC, RV08.portA) annotation (Line(points={{-2,160},{-2,204}}, color={255,153,0}, thickness=0.5));
  connect(RV08.portB, reliefBuffer.portArray[1]) annotation (Line(points={{-14,204},
          {-44,204},{-44,211.975}},                                                                       color={255,153,0}, thickness=0.5));
  connect(reliefBuffer.portArray[2], reliefReservoir.port) annotation (Line(points={{-44,
          212.225},{-44,204},{-72,204}},                                                                            color={255,153,0}, thickness=0.5));

  connect(junction22.portA, junction1.portB) annotation (Line(
      points={{-2,152},{-2,136},{-170,136},{-170,-20},{-164,-20}},
      color={255,153,0},
      thickness=0.5));
  connect(RV07Limiter.y, firstOrderRV07.u)
    annotation (Line(points={{99,230},{82,230}}, color={0,0,127}));
  connect(RV08Limiter.y, firstOrderRV08.u)
    annotation (Line(points={{-79,250},{-62,250}}, color={0,0,127}));
  connect(firstOrderRV08.y, RV08.KvValue_in) annotation (Line(points={{-39,250},
          {-8,250},{-8,207.75}}, color={0,0,127}));
  connect(firstOrderRV07.y, RV07.KvValue_in)
    annotation (Line(points={{59,230},{16,230},{16,159.75}}, color={0,0,127}));
  connect(HeaterLimiter.y, firstOrder1.u)
    annotation (Line(points={{-277,40},{-250,40}}, color={0,0,127}));
  connect(firstOrder1.y, prescribedHeatFlow1.Q_flow)
    annotation (Line(points={{-227,40},{-200,40}}, color={0,0,127}));
  connect(CoolingLimiter1.y, firstOrder.u)
    annotation (Line(points={{-281,-46},{-270,-46}}, color={0,0,127}));
  connect(valve5.portA, junction6.portB) annotation (Line(
      points={{-98,1},{-152,1},{-152,0},{-156,0}},
      color={255,153,0},
      thickness=0.5));
  connect(tube1.portB, junction7.portB) annotation (Line(
      points={{-82,-60},{-50,-60},{-50,-4}},
      color={255,153,0},
      thickness=0.5));
  connect(valve5.portB, junction7.portC) annotation (Line(
      points={{-86,1},{-58,1},{-58,0},{-54,0}},
      color={255,153,0},
      thickness=0.5));
  connect(TFUL1.portA1, junctionUL.portA) annotation (Line(
      points={{97.2,-10},{60,-10},{60,-4},{20,-4}},
      color={255,153,0},
      thickness=0.5));
  connect(sensor_T.port, junction7.portA) annotation (Line(
      points={{-46,30},{-46,8},{-42,8},{-42,0},{-46,0}},
      color={255,153,0},
      thickness=0.5));
  connect(junction7.portA, junctionSupply.portB) annotation (Line(
      points={{-46,0},{-42,0},{-42,26},{-10,26},{-10,40},{-4,40}},
      color={255,153,0},
      thickness=0.5));
  connect(junctionSupply.portA, junctionUL.portB) annotation (Line(
      points={{0,36},{0,0},{16,0}},
      color={255,153,0},
      thickness=0.5));
  connect(junctionCL.portA, TFCL1.portA1) annotation (Line(
      points={{20,76},{20,70},{97.2,70}},
      color={255,153,0},
      thickness=0.5));
  connect(junctionCL.portB, junctionSupply.portC) annotation (Line(
      points={{16,80},{0,80},{0,44}},
      color={255,153,0},
      thickness=0.5));
  connect(firstOrder.y, valve6.KvValue_in) annotation (Line(points={{-247,-46},
          {-246,-45},{-163.75,-45}}, color={0,0,127}));
  connect(BypassLimiter.y, firstOrder2.u)
    annotation (Line(points={{-251,10},{-240,10}},   color={0,0,127}));
  connect(firstOrder2.y, valve5.KvValue_in) annotation (Line(points={{-217,10},
          {-92,10},{-92,4.75}},   color={0,0,127}));
  connect(wantedTemp.y, PID.u_s)
    annotation (Line(points={{-119,90},{-90,90},{-90,82}}, color={0,0,127}));
  connect(sensor_T.sensorValue, PID.u_m)
    annotation (Line(points={{-46,36},{-46,70},{-78,70}}, color={0,0,127}));
  connect(junctionCL.portC, Structure.portA1) annotation (Line(
      points={{20,84},{20,90},{97.2,90}},
      color={255,153,0},
      thickness=0.5));
  connect(Structure.portB1, junctionReturnCL.portC) annotation (Line(
      points={{120.4,89.8},{140,89.8},{140,84}},
      color={255,153,0},
      thickness=0.5));
  connect(junctionReturn.portB, fan2ndOrder.portA) annotation (Line(
      points={{164,40},{180,40},{180,120},{-52,120}},
      color={255,153,0},
      thickness=0.5));
  connect(sensor_p_suction.port, junction22.portA) annotation (Line(
      points={{68,160},{68,138},{-2,138},{-2,152}},
      color={255,153,0},
      thickness=0.5));
  connect(junction6.portC, junction1.portC) annotation (Line(
      points={{-160,-4},{-160,-16}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portA, valve6.portA) annotation (Line(
      points={{-160,-24},{-160,-39}},
      color={255,153,0},
      thickness=0.5));
  annotation (Diagram(coordinateSystem(preserveAspectRatio=false, extent={{-360,-100},{220,300}})),
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
end TFCircuit;
