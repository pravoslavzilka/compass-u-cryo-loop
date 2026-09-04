within CoilLoopCompassU.TF;
model TFCircuit
  extends ThermalSystems.Internals.ClassTypes.ExampleModel;
  // ===========================================================================
  // TF coil cooling loop -- structural analog of PF/PFCircuit.mo, sized from
  // ATEKO study 22172-Z-R1 (S3.3.3, S5.1.3, S5.2.3, S6.5.3, S7.3) instead of
  // PF's own numbers. See docs/design-basis/tf-circulator-sizing.md for the
  // full parameter-by-parameter sourcing (FROM SOURCE / CALCULATED /
  // ASSUMED tags) and for what has been deliberately simplified relative to
  // PFCircuit.mo -- summary here, detail there:
  //
  // KEPT (same structure as PF): circulator (fan2ndOrder) with speed ramp,
  // electric heater with hysteresis-gated PID temperature control, LIN-side
  // evaporator (tube1 vs a fixed 77K coldSurface), 4 parallel coil-bus
  // branches each behind its own isolation valve with a relative-margin
  // close/reopen rule (coilOpen[nTF]), a basic bypass valve pair, RV07/RV08
  // make-up/relief valves to storage reservoirs holding suction pressure.
  //
  // SIMPLIFIED (deliberately, not carried over from PF): PF's RV07/RV08
  // "pulse-then-trim" mass-integral rewrite is replaced here with a plain
  // continuous proportional trim -- the pulse rewrite was itself a fix for
  // limit-cycling PF only discovered after real simulation runs (see
  // PFCircuit.mo's own RV07/RV08 docstrings and docs/migration-notes.md);
  // TF has had no such run, so porting the fix pre-emptively would be
  // copying a solution without the problem that motivated it. PF's
  // valve4/overCoolRecovering bypass state machine and its
  // PID_circulatorPower/PF_RV01 shaft-power limiter are omitted entirely,
  // same reasoning -- both were added to PF after specific solver failures
  // TF has not encountered. If TF is ever actually simulated and shows the
  // same failure modes, port the corresponding PF fix in at that point
  // rather than before.
  // ===========================================================================

  parameter Real m_total = 1.3 "Total design flow from the circulator, kg/s -- FROM SOURCE, ATEKO 22172-Z-R1 S6.5.3 (minimal design flow 1.3 kg/s at coil temperature 116 K)";
  parameter Real u_dead = 1;
  parameter Real Kv_shut = 1e-4;
  parameter Real Kv_cool_max = 5000;
  parameter Real heater_gain = 100;
  parameter Real Kv_gain = 100;
  parameter Real hysteresisHalfWidth = 0.3
    "Half-width of the ON/OFF gap around each PID.y switching threshold -- same anti-chatter role as PFCircuit.mo's identical parameter.";
  parameter Modelica.Units.SI.TemperatureDifference tempMargin=40
    "Margin below the hottest coil-bus gas outlet temperature -- FROM SOURCE, ATEKO 22172-Z-R1 S3.2 (\"Limit (T_object-T_coolant)<=40K\", cooldown-after-discharge mode) and S6.4 (\"maximal temperature difference 40K (T inlet-T outlet)\") -- both directly state 40K for the whole cooling system, TF included, so this is a stronger sourcing than PF's own tempMargin=40 (which is a PF-model default, not independently cited in PF's own design-basis doc).";
  parameter Integer nTF = 4 "Number of TF coil-bus branches -- CALCULATED: ATEKO 22172-Z-R1 S3.3.3 states 224 channels 'connected in parallel to 4 busses' (text, not the PFD image's visual branch count -- see tf-circulator-sizing.md S1 for the reconciliation). Modeled as 2 TFCoilBusCoreLower + 2 TFCoilBusUpper instances, an ASSUMED even split of each 112-channel group across 2 busses (not stated in the source) -- see Open Items.";
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
    "Suction-node pressure setpoint, Pa (~24 barg abs) -- CALCULATED from ATEKO 22172-Z-R1 S6.5.3's stated nominal working pressure (24 barg at the outlet of CC), barg->Pa(a) via +1 atm. Held by RV07/RV08's plain continuous PID trim (see RV07Limiter/RV08Limiter) -- no separate open/close hysteresis thresholds, unlike PFCircuit.mo's pulse-then-trim scheme (see the top-of-file note on why that rewrite was not ported over); PID_pressure's own yMax/yMin plus KvMakeupMax/KvReliefMax bound the correction instead.";
  parameter Real kPressurePID=0.05;
  parameter Modelica.Units.SI.Time TiPressurePID=30;
  parameter Real KvGainMakeup = 5 "PLACEHOLDER, same status as PF's KvGainMakeup -- not sized against any TF-specific flow data, see Open Items.";
  parameter Real KvMakeupMax = 30 "PLACEHOLDER -- scaled up from PF's KvMakeupMax=15 in rough proportion to TF's ~3.4x larger total design flow (1.3 vs 0.1 kg/s referenced by PFCircuit.mo's own m_total); not independently sized.";
  parameter Real KvGainRelief = 5 "PLACEHOLDER, mirror of KvGainMakeup.";
  parameter Real KvReliefMax = 30 "PLACEHOLDER, mirror of KvMakeupMax.";
  parameter Modelica.Units.SI.AbsolutePressure pMakeupReservoir=2700000
    "Make-up storage reservoir pressure, Pa -- CALCULATED, above pressureSetpoint by roughly the same margin PF uses proportionally.";
  parameter Modelica.Units.SI.AbsolutePressure pReliefReservoir=2300000
    "Relief storage reservoir pressure, Pa -- CALCULATED, below pressureSetpoint, mirror of pMakeupReservoir.";
  parameter Modelica.Units.SI.Temperature TStorageReservoirs=80;
  parameter Modelica.Units.SI.Time valveRampTime=3;
  parameter Real Kv_shut_pressureValves = 1e-2;

  Real T_gas_out_TF[nTF] = {TFCL1.T_gas_out, TFCL2.T_gas_out, TFUL1.T_gas_out, TFUL2.T_gas_out}
    "Same order as coilOpen: TFCL1, TFCL2, TFUL1, TFUL2";
  Real valveKvNominal_TF[nTF] = {TFCL1.valveKvNominal, TFCL2.valveKvNominal, TFUL1.valveKvNominal, TFUL2.valveKvNominal};
  Real kvTarget_TF[nTF] "Commanded Kv per bus before smoothing: valveKvNominal_TF when open, Kv_shut when closed";
  Real T_gas_out_compare_TF[nTF] "T_gas_out_TF[i] while open (live), T_gas_out_frozen[i] while closed";
  Boolean coilOpen[nTF](start=fill(true, nTF), fixed=fill(true, nTF))
    "Per-bus isolation valve latch, order: TFCL1,TFCL2,TFUL1,TFUL2";
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
    n_nominal=200,
    dp_nominal(displayUnit="bar") = 200000,
    V_flow_nominal=0.125,
    V_flow0=0.151,
    T_nominal(displayUnit="K") = 116,
    p_nominal=2500000,
    eta_maxPhyd=0.6,
    dpInitial(displayUnit="bar") = 2500000,
    V_flow_Start=0.01)
    "Sizing FROM SOURCE / CALCULATED / ASSUMED, see tf-circulator-sizing.md S2-S3: T_nominal/p_nominal FROM SOURCE (ATEKO worst-case coil temp 116K, nominal working pressure 24barg->~2.5MPa(a)); V_flow_nominal/V_flow0 CALCULATED (m_total/rho_suction via ideal-gas estimate, V_flow0 carrying PF's own 1.21x ratio); dp_nominal CALCULATED, a rough order-of-magnitude estimate -- ATEKO's own channel-only pressure-loss table (Tab.11) gives ~0.18 bar per channel at these conditions, but that excludes header/heater/evaporator/valve losses which ATEKO explicitly leaves to 'the cryogenic system supplier' to evaluate; 2 bar used here as a placeholder allowing headroom for those unmodeled losses, not a real hydraulic calculation -- see Open Items; n_nominal/eta_maxPhyd/V_flow0 ratio/deltaV_flow/bladeLossExponent/impactLossCoefficient ASSUMED, carried from PF (no TF-specific circulator data exists)."
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
    "LIN-side evaporator boundary -- FROM SOURCE, ATEKO 22172-Z-R1 S6.2 (LIN evaporates at 77K, shared design across all 3 cooling circuits, same as PFCircuit.mo's coldSurface)."
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
    m_flowStart=0.01,
    pInitial=2500000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = 80)
    "Evaporator geometry ASSUMED, carried from PFCircuit.mo's tube1 unchanged -- not TF-specific, sized only to plausibly pass m_total without excessive pressure drop; see Open Items."
    annotation (Placement(transformation(extent={{-8,-2},{8,2}},
        rotation=0,
        origin={-50,-60})));
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
    "Electric heater -- FROM SOURCE that TF requires one (ATEKO S6.1: 'electric heater for TF coils and support structure has to be used, because support structure has huge weight... design case based on 40C temperature difference'), unlike PF/CS where compression heat alone may suffice. Geometry itself ASSUMED (widened bore vs PF's Heater to pass TF's larger m_total without excessive dp -- not a real sizing calc)."
    annotation (Placement(transformation(
        extent={{8,-2},{-8,2}},
        rotation=90,
        origin={-112,40})));

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
  Modelica.Blocks.Continuous.FirstOrder firstOrder(T=2)
    annotation (Placement(transformation(extent={{-192,-54},{-172,-34}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder1(T=1)
    annotation (Placement(transformation(extent={{-248,30},{-228,50}})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow1
    annotation (Placement(transformation(extent={{-200,30},{-180,50}})));

  ThermalSystems.GasComponents.Valves.Valve valve5(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=500)
    "Cooling/bypass trim valve, carried directly from PF's valve5 -- same role, not TF-specific."
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
        origin={-112,-43})));

  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-2, m_flowStart=1e-5, pInitial=2500000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90, origin={60,60})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction6(
    volume=1e-2, m_flowStart=1e-5, pInitial=2500000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90, origin={-112,-24})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction7(
    volume=1e-2, m_flowStart=1e-5, pInitial=2500000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=270, origin={-112,-6})));
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
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90, origin={40,40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionReturnCL(
    volume=1e-2, m_flowStart=1e-5, pInitial=2500000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=-90, origin={140,80})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionReturnUL(
    volume=1e-2, m_flowStart=1e-5, pInitial=2500000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=-90, origin={140,0})));
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

  TFCoilBusCoreLower TFCL1(TInitial(displayUnit="K") = 116)
    annotation (Placement(transformation(extent={{100,60},{120,80}})));
  TFCoilBusCoreLower TFCL2(TInitial(displayUnit="K") = 116)
    annotation (Placement(transformation(extent={{100,80},{120,100}})));
  TFCoilBusUpper TFUL1(TInitial(displayUnit="K") = 116)
    annotation (Placement(transformation(extent={{100,-20},{120,0}})));
  TFCoilBusUpper TFUL2(TInitial(displayUnit="K") = 116)
    annotation (Placement(transformation(extent={{100,0},{120,20}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderCoilKv[nTF](each T=3)
    "Smooths each per-bus Kv step -- same anti-chatter role as PFCircuit.mo's identical block."
    annotation (Placement(transformation(extent={{-20,-100},{0,-80}})));

  ThermalSystems.GasComponents.Sensors.Sensor_p sensor_p_suction
    "CLASS NAME ASSUMED by analogy with PFCircuit.mo's identical sensor and its own docstring caveat -- ThermalSystems isn't vendored in this repo, verify at translate-check."
    annotation (Placement(transformation(extent={{58,134},{66,142}})));
  Modelica.Blocks.Continuous.LimPID PID_pressure(
    controllerType=Modelica.Blocks.Types.SimpleController.PI,
    k=kPressurePID, Ti=TiPressurePID, yMax=7.5, yMin=-7.5,
    initType=Modelica.Blocks.Types.Init.InitialOutput, y_start=0)
    annotation (Placement(transformation(extent={{120,160},{140,180}})));
  ThermalSystems.GasComponents.Boundaries.Boundary makeupReservoir(
    TFixed(displayUnit="K") = TStorageReservoirs, boundaryType="p", pFixed=pMakeupReservoir)
    annotation (Placement(transformation(extent={{34,194},{42,214}})));
  ThermalSystems.GasComponents.Boundaries.Boundary reliefReservoir(
    TFixed(displayUnit="K") = TStorageReservoirs, boundaryType="p", pFixed=pReliefReservoir)
    annotation (Placement(transformation(extent={{-24,168},{-16,188}})));
  ThermalSystems.GasComponents.Volumes.Volume makeupBuffer(
    volume=1e-2, enableHeatPort=false, m_flowStart=0, pInitial=pMakeupReservoir,
    fixedInitialPressure=false, TInitial(displayUnit="K") = TStorageReservoirs, nPorts=2)
    "Compliant buffer between the ideal makeupReservoir boundary and RV07 -- same structural fix PF applies (see PFCircuit.mo's makeupBuffer docstring: a valve bridging a compliant network node directly to a rigid ideal boundary is a known solver-stiffness risk)."
    annotation (Placement(transformation(extent={{52,194},{60,202}})));
  ThermalSystems.GasComponents.Volumes.Volume reliefBuffer(
    volume=1e-2, enableHeatPort=false, m_flowStart=0, pInitial=pReliefReservoir,
    fixedInitialPressure=false, TInitial(displayUnit="K") = TStorageReservoirs, nPorts=2)
    annotation (Placement(transformation(extent={{-36,182},{-28,190}})));
  ThermalSystems.GasComponents.Valves.Valve RV07(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false, use_KvValueInput=true,
    KvValueFixed=Kv_shut_pressureValves)
    annotation (Placement(transformation(extent={{6,-3},{-6,3}}, rotation=0, origin={16,180})));
  ThermalSystems.GasComponents.Valves.Valve RV08(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false, use_KvValueInput=true,
    KvValueFixed=Kv_shut_pressureValves)
    annotation (Placement(transformation(extent={{6,-3},{-6,3}}, rotation=0, origin={-8,204})));
  Modelica.Blocks.Sources.RealExpression RV07Limiter(y=if not enablePressureControl
         then Kv_shut_pressureValves else min(max(PID_pressure.y, 0)*KvGainMakeup, KvMakeupMax))
    "Plain continuous proportional trim -- SIMPLIFIED vs PFCircuit.mo's RV07Limiter, see the top-of-file note on why the pulse-then-trim rewrite was not ported over."
    annotation (Placement(transformation(extent={{-40,258},{-20,278}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderRV07(T=valveRampTime)
    annotation (Placement(transformation(extent={{0,260},{20,280}})));
  Modelica.Blocks.Sources.RealExpression RV08Limiter(y=if not enablePressureControl
         then Kv_shut_pressureValves else min(max(-PID_pressure.y, 0)*KvGainRelief, KvReliefMax))
    annotation (Placement(transformation(extent={{-80,220},{-60,240}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderRV08(T=valveRampTime)
    annotation (Placement(transformation(extent={{-40,220},{-20,240}})));

equation
  heaterHysteresis.u = PID.y;
  coolingHysteresis.u = -PID.y;
  wantedTemp.y = PID.u_s;
  PID.u_m = sensor_T.sensorValue;
  firstOrder1.u = HeaterLimiter.y;
  prescribedHeatFlow1.Q_flow = firstOrder1.y;
  firstOrder.u = CoolingLimiter1.y;
  valve6.KvValue_in = firstOrder.y;
  PID_pressure.u_s = pressureSetpoint;
  PID_pressure.u_m = sensor_p_suction.sensorValue;
  firstOrderRV07.u = RV07Limiter.y;
  RV07.KvValue_in = firstOrderRV07.y;
  firstOrderRV08.u = RV08Limiter.y;
  RV08.KvValue_in = firstOrderRV08.y;

  for i in 1:nTF loop
    kvTarget_TF[i] = if coilOpen[i] then valveKvNominal_TF[i] else Kv_shut;
    firstOrderCoilKv[i].u = kvTarget_TF[i];
    T_gas_out_compare_TF[i] = if coilOpen[i] then T_gas_out_TF[i] else T_gas_out_frozen[i];
  end for;
  TFCL1.KvValue_in1 = firstOrderCoilKv[1].y;
  TFCL2.KvValue_in1 = firstOrderCoilKv[2].y;
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
  connect(fan2ndOrder.portA, junction1.portB) annotation (Line(points={{-60,112},{-60,60},{56,60}}, color={255,153,0}, thickness=0.5));
  connect(smoothStep.y, rotatoryBoundary.n_in)
    annotation (Line(points={{-179.4,156},{-70,156},{-70,140}}, color={0,0,127}));
  connect(rotatoryBoundary.rotatoryFlange, fan2ndOrder.rotatoryFlange)
    annotation (Line(points={{-60,127},{-60,128}}, color={135,135,135}, thickness=0.5));
  connect(coldSurface.port, tube1.heatPort[1]) annotation (Line(points={{-50,-40},{-50,-58}}, color={191,0,0}));
  connect(prescribedHeatFlow1.port, Heater.heatPort[1]) annotation (Line(points={{-180,40},{-112,40}}, color={191,0,0}));

  connect(fan2ndOrder.portB, Heater.portA) annotation (Line(points={{-60,128},{-60,140},{-160,140},{-160,40},{-120,40}}, color={255,153,0}, thickness=0.5));
  connect(Heater.portB, junction6.portA) annotation (Line(points={{-112,32},{-112,-20}}, color={255,153,0}, thickness=0.5));
  connect(sensor_T.port, junction6.portA) annotation (Line(points={{-12,44},{-112,44},{-112,-20}}, color={255,153,0}, thickness=0.5));
  connect(junction6.portB, junction7.portC) annotation (Line(points={{-108,-24},{-100,-24},{-100,-6},{-108,-6}}, color={255,153,0}, thickness=0.5));
  connect(junction7.portA, valve5.portA) annotation (Line(points={{-112,-10},{-112,-5},{-80,-5}}, color={255,153,0}, thickness=0.5));
  connect(valve5.portB, valve6.portA) annotation (Line(points={{-68,-5},{-60,-5},{-60,-30},{-112,-30},{-112,-39}}, color={255,153,0}, thickness=0.5));
  connect(valve6.portB, tube1.portA) annotation (Line(points={{-112,-47},{-112,-60},{-58,-60}}, color={255,153,0}, thickness=0.5));
  connect(tube1.portB, junctionSupply.portA) annotation (Line(points={{-42,-60},{40,-60},{40,36}}, color={255,153,0}, thickness=0.5));

  connect(junctionSupply.portB, junctionCL.portA) annotation (Line(points={{36,40},{20,40},{20,76}}, color={255,153,0}, thickness=0.5));
  connect(junctionSupply.portC, junctionUL.portA) annotation (Line(points={{44,40},{20,40},{20,4}}, color={255,153,0}, thickness=0.5));
  connect(junctionCL.portB, TFCL1.portA1) annotation (Line(points={{20,84},{60,84},{60,90},{100,90}}, color={255,153,0}, thickness=0.5));
  connect(junctionCL.portC, TFCL2.portA1) annotation (Line(points={{24,80},{60,80},{60,70},{100,70}}, color={255,153,0}, thickness=0.5));
  connect(junctionUL.portB, TFUL1.portA1) annotation (Line(points={{20,4},{60,4},{60,10},{100,10}}, color={255,153,0}, thickness=0.5));
  connect(junctionUL.portC, TFUL2.portA1) annotation (Line(points={{24,0},{60,0},{60,-10},{100,-10}}, color={255,153,0}, thickness=0.5));

  connect(TFCL1.portB1, junctionReturnCL.portA) annotation (Line(points={{120,90},{140,90},{140,84}}, color={255,153,0}, thickness=0.5));
  connect(TFCL2.portB1, junctionReturnCL.portC) annotation (Line(points={{120,70},{140,70},{140,76}}, color={255,153,0}, thickness=0.5));
  connect(TFUL1.portB1, junctionReturnUL.portA) annotation (Line(points={{120,10},{140,10},{140,4}}, color={255,153,0}, thickness=0.5));
  connect(TFUL2.portB1, junctionReturnUL.portC) annotation (Line(points={{120,-10},{140,-10},{140,-4}}, color={255,153,0}, thickness=0.5));
  connect(junctionReturnCL.portB, junctionReturn.portA) annotation (Line(points={{144,80},{160,80},{160,44}}, color={255,153,0}, thickness=0.5));
  connect(junctionReturnUL.portB, junctionReturn.portC) annotation (Line(points={{144,0},{160,0},{160,36}}, color={255,153,0}, thickness=0.5));

  connect(junctionReturn.portB, junction1.portC) annotation (Line(points={{160,40},{60,40},{60,64}}, color={255,153,0}, thickness=0.5));
  connect(junction1.portA, junction22.portA) annotation (Line(points={{60,56},{60,20},{-2,20},{-2,152}}, color={255,153,0}, thickness=0.5));
  connect(junction22.portB, RV07.portA) annotation (Line(points={{2,158},{10,158},{10,180}}, color={255,153,0}, thickness=0.5));
  connect(RV07.portB, makeupBuffer.portArray[1]) annotation (Line(points={{22,180},{56,180},{56,194}}, color={255,153,0}, thickness=0.5));
  connect(makeupBuffer.portArray[2], makeupReservoir.port) annotation (Line(points={{56,200},{38,200},{38,194}}, color={255,153,0}, thickness=0.5));
  connect(junction22.portC, RV08.portA) annotation (Line(points={{-2,160},{-2,204}}, color={255,153,0}, thickness=0.5));
  connect(RV08.portB, reliefBuffer.portArray[1]) annotation (Line(points={{-14,204},{-32,204},{-32,190}}, color={255,153,0}, thickness=0.5));
  connect(reliefBuffer.portArray[2], reliefReservoir.port) annotation (Line(points={{-32,184},{-20,184},{-20,178}}, color={255,153,0}, thickness=0.5));
  connect(sensor_p_suction.port, junction1.portB) annotation (Line(points={{62,134},{62,60},{64,60}}, color={255,153,0}, thickness=0.5));

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
