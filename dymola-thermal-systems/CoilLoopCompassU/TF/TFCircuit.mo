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
  // PID_circulatorPower/PF_RV01 shaft-power limiter is omitted entirely,
  // same reasoning. PF's valve4 overcool bypass branch (supply tee
  // junction21 -> valve4 -> return tee junction20 -> circulator suction)
  // and its overCoolRecovering state machine ARE ported, copied unchanged
  // from PFCircuit.mo including its defaults (enableOverCoolPrevention=
  // enableOverCoolRecovery=false, i.e. valve4 stays shut until enabled).
  // ===========================================================================

  parameter Real m_total = 1.3 "Total design flow from the circulator, kg/s -- FROM SOURCE, ATEKO 22172-Z-R1 S6.5.3 (minimal design flow 1.3 kg/s at coil temperature 116 K)";
  parameter Real u_dead = 1;
  parameter Real Kv_shut = 1e-4;
  parameter Real Kv_cool_max = 5000;
  parameter Real heater_gain = 100;
  parameter Real Kv_gain = 100;
  parameter Real bypass_limit = 2
    "Threshold (on -PID.y) above which valve5's bypass leg is throttled back. Lowered from PF's 10 to 2 (just past the cooling threshold u_dead+hysteresisHalfWidth=1.3): with 10, the 2026-10-02 run kept valve5 at its full Kv=500 for the first ~300s, sending 1.1-1.4 kg/s around the evaporator vs 0.2-0.5 kg/s through it, so the supply sat 7-14K above wanted_temp.";
  parameter Real bypassKvGain = 50
    "valve5 Kv reduction per unit of PID.y once bypassHysteresis is on (Kv = 500 + PID.y*bypassKvGain, floored at Kv_shut) -- raised from PF's literal 10 so the bypass is fully shut by PID.y=-10 instead of -50, for the same reason as bypass_limit.";
  parameter Real hysteresisHalfWidth = 0.3
    "Half-width of the ON/OFF gap around each PID.y switching threshold -- same anti-chatter role as PFCircuit.mo's identical parameter.";
  parameter Modelica.Units.SI.TemperatureDifference tempMargin=40
    "Margin below the hottest coil-bus gas outlet temperature -- FROM SOURCE, ATEKO 22172-Z-R1 S3.2 (\"Limit (T_object-T_coolant)<=40K\", cooldown-after-discharge mode) and S3.4 (\"maximal temperature difference 40K (T inlet-T outlet)\") -- both directly state 40K for the whole cooling system, TF included, so this is a stronger sourcing than PF's own tempMargin=40 (which is a PF-model default, not independently cited in PF's own design-basis doc).";
  parameter Boolean enableOverCoolPrevention=false
    "Master switch for valve4's overcool-prevention trigger (the first when-branch below, gated on overCoolReopenMargin). When false, valve4 never opens in response to overcooling risk -- it stays permanently shut, and enableOverCoolRecovery's hold logic never has anything to act on. Copied unchanged from PFCircuit.mo.";
  parameter Boolean enableOverCoolRecovery=false
    "Master switch for valve4's stabilize-and-reclose logic (the three elsewhen-branches below, gated on overCoolShutMargin/overCoolStabilityBand/overCoolStabilizeDelay). When false, valve4 -- once opened by enableOverCoolPrevention -- never automatically recloses; the bypass stays open indefinitely. No effect if enableOverCoolPrevention is false. Copied unchanged from PFCircuit.mo.";
  parameter Modelica.Units.SI.TemperatureDifference overCoolShutMargin=40
    "Lower bound of valve4's settle band: T_ref - overCoolShutMargin (T_ref = T_gas_out_max snapshot recorded at the moment valve4 last reopened). sensor_T.sensorValue must sit at or above this (and at or below T_ref - overCoolShutMargin + overCoolStabilityBand, i.e. within the band) for overCoolStabilizeDelay seconds continuously before valve4 actually shuts. Copied unchanged from PFCircuit.mo.";
  parameter Modelica.Units.SI.TemperatureDifference overCoolReopenMargin=45
    "valve4 reopens (and re-records T_ref = current T_gas_out_max) once T_gas_out_max - sensor_T.sensorValue exceeds this, while shut. Copied unchanged from PFCircuit.mo.";
  parameter Modelica.Units.SI.TemperatureDifference overCoolStabilityBand=20
    "Width of valve4's settle band above the lower bound (T_ref - overCoolShutMargin): sensor_T.sensorValue must stay within [T_ref - overCoolShutMargin, T_ref - overCoolShutMargin + overCoolStabilityBand] continuously. Copied unchanged from PFCircuit.mo.";
  parameter Modelica.Units.SI.Time overCoolStabilizeDelay=30
    "sensor_T.sensorValue must stay continuously within valve4's settle band (see overCoolShutMargin/overCoolStabilityBand) for this long before valve4 actually closes. Any excursion out of the band (either side) before the delay elapses restarts the wait. Copied unchanged from PFCircuit.mo.";
  parameter Integer nTF = 4 "Number of TF coil-bus branches -- CALCULATED: ATEKO 22172-Z-R1 S3.3.3 states 224 channels 'connected in parallel to 4 busses' (text, not the PFD image's visual branch count -- see tf-circulator-sizing.md S1 for the reconciliation). Modeled as 2 TFCoilBusCoreLower + 2 TFCoilBusUpper instances, an ASSUMED even split of each 112-channel group across 2 busses (not stated in the source) -- see Open Items.";
  parameter Boolean enableCoilIsolation = true
    "Master switch for the per-bus relative-margin isolation rule, same role as PFCircuit.mo's enableCoilIsolation.";
  parameter Boolean connectStructure = false
    "true: support-structure branch connected between junctionCL and junctionReturnCL (throttled by Structure.valveKvNominal=12, ~11% of circulator flow in the 2026-10-02 run). false: Structure is disconnected from both headers -- fully closed, zero flow, its gas trapped at its initial 80K -- so all circulator flow goes to the coil busses. Disconnecting both ends (rather than shutting only the inlet valve) avoids the reversing outlet flow that broke simulation.nonlinear[8] when Structure was isolated by valve alone.";
  parameter Modelica.Units.SI.Temperature T_supplyFloor(displayUnit="K") = 80
    "Lower bound on wanted_temp -- ATEKO 22172-Z-R1 S3.4 target temperature 80K. Without it wanted_temp = T_gas_out_max - 40 fell to ~46-49K late in the run, below what the 77K LIN evaporator can deliver: PID sat saturated at yMin=-60 from ~1350s on and the supply undershot to 78.5K.";
  parameter Real KvUpperLimb = 45
    "Fully-open Kv of the TFUL1/TFUL2 bus valves (TFCoilBusUpper default 100). Throttled so the faster-cooling upper limb (shorter 7.7m channels, 7.5 vs 5.9 g/s/channel at Kv=100 in the 2026-10-03 run, done at ~79K by 1800s) gives flow to the slower core + lower limb.";
  parameter Boolean shutWhenCold_TF[nTF] = {false, false, true, true}
    "Per-branch opt-in to the permanent 'cooled down' shut-off below, order TFCL1,Structure,TFUL1,TFUL2 -- upper limb only.";
  parameter Modelica.Units.SI.Temperature T_coldShut(displayUnit="K") = 80
    "A shutWhenCold_TF branch closes permanently (both ends, see TFCoilBusUpper.outletKvRatio) once its gas outlet temperature -- the hottest end of the bus -- reaches this. 80K = ATEKO 22172-Z-R1 S3.4 target temperature.";
  parameter Boolean isolationAllowed_TF[nTF] = {true, false, true, true}
    "Per-branch opt-in to the isolation rule, order TFCL1,Structure,TFUL1,TFUL2. Structure is excluded (always open): it starts at 80K vs the coils' 137K, so the close rule shut it at t~0.1s and it never reopened; the shut branch stayed open to the return header on its outlet side, and the resulting reversing outlet flow (-0.14..+0.05 kg/s) made simulation.nonlinear[8] fail repeatedly. ATEKO 22172-Z-R1 S5.2.3 also states the support structure is not heated by the shot, so there is no design reason to isolate it during post-shot cooldown.";
  parameter Modelica.Units.SI.TemperatureDifference coilIsolationCloseMargin = 40
    "Per-bus isolation valve closes once T_gas_out is this much colder than T_gas_out_max -- carried directly from PF (same class of relative-margin isolation rule, no TF-specific tuning data available).";
  parameter Modelica.Units.SI.TemperatureDifference coilIsolationReopenMargin = 35
    "Per-bus isolation valve reopens once within this much of T_gas_out_max -- carried from PF, see coilIsolationCloseMargin.";
  parameter Modelica.Units.SI.Time controlActivationDelay = 5
    "Reopen logic (valve4 and per-bus isolation) stays disabled until this much simulated time has passed, so it doesn't react to the unsettled startup transient -- same role as PFCircuit.mo's identical parameter.";

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

  Real T_ref(start=0, fixed=true)
    "T_gas_out_max snapshot for valve4's own control logic only (PID/wanted_temp are unaffected) -- re-recorded every time valve4 reopens, held constant otherwise";
  Boolean valve4Open(start=false, fixed=true)
    "true -> valve4 Kv=5000 (open), false -> valve4 Kv=0.001 (shut)";
  Boolean overCoolRecovering(start=false, fixed=true)
    "True while sensor_T is inside valve4's settle band ([T_ref - overCoolShutMargin, T_ref - overCoolShutMargin + overCoolStabilityBand]) but hasn't stayed there continuously for overCoolStabilizeDelay yet -- valve4 stays open (bypass still flowing) during this hold. Reset to false the instant sensor_T leaves the band on either side, so the wait restarts on the next continuous stay.";
  Real overCoolRecoveredAt(start=0, fixed=true)
    "Time sensor_T most recently entered valve4's settle band during the current valve4-open episode -- gates the overCoolStabilizeDelay hold before valve4 actually closes.";

  Real T_gas_out_TF[nTF] = {TFCL1.T_gas_out, Structure.T_gas_out, TFUL1.T_gas_out, TFUL2.T_gas_out}
    "Same order as coilOpen: TFCL1, Structure, TFUL1, TFUL2";
  Real valveKvNominal_TF[nTF] = {TFCL1.valveKvNominal, Structure.valveKvNominal, TFUL1.valveKvNominal, TFUL2.valveKvNominal};
  Real kvTarget_TF[nTF] "Commanded Kv per bus before smoothing: valveKvNominal_TF when open, Kv_shut when closed";
  Real T_gas_out_compare_TF[nTF] "T_gas_out_TF[i] while open (live), T_gas_out_frozen[i] while closed";
  Boolean coilOpen[nTF](start=fill(true, nTF), fixed=fill(true, nTF))
    "Per-bus isolation valve latch, order: TFCL1,Structure,TFUL1,TFUL2";
  Boolean coldShut[nTF](start=fill(false, nTF), fixed=fill(true, nTF))
    "Latched true (never reset) once a shutWhenCold_TF branch reaches T_coldShut -- that branch then stays at Kv_shut for the rest of the run, overriding coilOpen.";
  Real T_gas_out_frozen[nTF](each start=0, each fixed=true)
    "Snapshot of T_gas_out_TF[i] taken the instant coilOpen[i] closes -- held constant while closed.";

  output Modelica.Units.SI.Temperature T_gas_out_max = max(T_gas_out_compare_TF)
    "Hottest coil-bus gas outlet temperature.";
  output Modelica.Units.SI.Temperature wanted_temp = max(T_gas_out_max - tempMargin, T_supplyFloor)
    "PID setpoint: hottest bus outlet minus margin, floored at T_supplyFloor.";

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
    dp_nominal(displayUnit="bar") = 70000,
    V_flow_nominal=0.145,
    V_flow0=0.175,
    T_nominal(displayUnit="K") = 116,
    p_nominal=2500000,
    eta_maxPhyd=0.6,
    dpInitial(displayUnit="bar") = 2500000,
    V_flow_Start=0.01)
    "Re-sized 2026-10-05 to the loop's simulated operating point, same method as PF (design point placed where the machine actually runs): V_flow_nominal=0.145 m3/s = delivered volume flow in the 2026-10-04 run (m_flow/rho ~0.145 throughout); dp_nominal=0.7 bar = middle of the 0.47-0.94 bar the loop actually needed; V_flow0=1.21*V_flow_nominal (PF's ratio). The previous placeholder (dp_nominal=2 bar, V_flow_nominal=0.125, V_flow0=0.151) left the machine at ~96% of its zero-head flow, eta=0.25-0.30 vs PF's 0.63-0.66, P_shaft 28-55 kW for 7-14 kW hydraulic -- ~21 kW of loss dumped into the helium. Expected now: eta ~0.6, P_shaft ~17 kW (ATEKO S7.3 budget 25 kW electrical). T_nominal/p_nominal FROM SOURCE (ATEKO 116K, 24barg); n_nominal/eta_maxPhyd ASSUMED, carried from PF.";
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
    "Evaporator geometry ASSUMED, carried from PFCircuit.mo's tube1 unchanged -- not TF-specific, sized only to plausibly pass m_total without excessive pressure drop; see Open Items."
    annotation (Placement(transformation(extent={{-8,-2},{8,2}},
        rotation=0,
        origin={-90,-60})));
  ThermalSystems.GasComponents.Valves.Valve valve3(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=4000)
    "Fixed valve between the evaporator outlet and the mixing node junction7 -- copied unchanged from PFCircuit.mo's valve3 (tube1 -> valve3 -> junction23 there). Without it the near-zero-flow evaporator tube was coupled straight into the supply junctions, and that combined algebraic system (simulation.nonlinear[2]: tube1, junction7/21, junctionSupply/CL/UL) failed repeatedly at t~9.72s."
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=0,
        origin={-66,-59})));
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
        origin={-160,40})));

  Modelica.Blocks.Continuous.LimPID PID(
    controllerType=Modelica.Blocks.Types.SimpleController.PI,
    k=0.12,
    Ti=12,
    yMax=60,
    yMin=-60,
    initType=Modelica.Blocks.Types.Init.InitialOutput,
    y_start=0)
    "y_start=0 (was 5, carried from PF): a positive start value switched the heater on for the first ~40s of a cooldown run, heating the supply to ~117K before the PI integrator could swing negative."
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
    "Same role as PFCircuit.mo's identical block: a THIRD hysteresis gate on top of heaterHysteresis/coolingHysteresis, all keyed off the same PID.y (the split-range heater/cooling/bypass control triad) -- not to be confused with the separate valve4/overCoolRecovering state machine (valve4 bypasses the coils, valve5 bypasses the evaporator). Missing valve5 wiring was the root cause of the earlier 'structurally singular, 22890 unknowns/22889 equations' translate error."
    annotation (Placement(transformation(extent={{-340,-60},{-320,-40}})));
  Modelica.Blocks.Sources.RealExpression BypassLimiter(y=if bypassHysteresis.y
         then max(500 + (PID.y*bypassKvGain), Kv_shut) else 500)
    "Structure carried from PFCircuit.mo's identical block; gain and threshold re-tuned for TF, see bypass_limit/bypassKvGain."
    annotation (Placement(transformation(extent={{-272,0},{-252,20}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder2(T=1)
    annotation (Placement(transformation(extent={{-238,0},{-218,20}})));

  ThermalSystems.GasComponents.Valves.Valve valve5(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=500)
    "Cooling/bypass trim valve, carried directly from PF's valve5 -- same role, not TF-specific. Driven by BypassLimiter/bypassHysteresis/firstOrder2 (see their docstrings), same as PF; KvValueFixed=500 is only the unused fallback while use_KvValueInput=true."
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

  // --- valve4 overcool bypass branch, copied from PFCircuit.mo: supply tee
  // junction21 (after the heater/evaporator mixing node) -> valve4 ->
  // return tee junction20 -> circulator suction, bypassing all coil busses.
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction21(
    volume(displayUnit="l") = 0.2,
    m_flowStart=1e-5,
    pInitial=2500000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    "Supply tee: portA from junction7 (mixed heater/evaporator outlet), portC to the coil supply header (junctionSupply), portB to valve4 -- same role and volume as PFCircuit.mo's junction21."
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=0,
        origin={-20,20})));
  ThermalSystems.GasComponents.Valves.Valve valve4(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=0.0001)
    "Overcool bypass valve, supply -> return around all coil busses. Driven by bypassRegulatorOverCool/firstOrder3 (valve4Open state machine in the algorithm section) -- copied unchanged from PFCircuit.mo's valve4."
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=90,
        origin={-20,65})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction20(
    volume=1e-1,
    m_flowStart=1e-5,
    pInitial=2500000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    "Return tee: portA from the coil return header (junctionReturn), portB from valve4, portC to the circulator suction -- same role and volume as PFCircuit.mo's junction20."
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=180,
        origin={-20,120})));
  Modelica.Blocks.Sources.RealExpression bypassRegulatorOverCool(y=if
        valve4Open then 5000 else 0.001)
    annotation (Placement(transformation(extent={{-86,60},{-66,80}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder3(T=3)
    annotation (Placement(transformation(extent={{-56,60},{-36,80}})));

  TFCoilBusCoreLower TFCL1(TInitial(displayUnit="K") = 137, assemblyIndex=1)
    annotation (Placement(transformation(extent={{100,60},{120,80}})));
  TFCoilBusUpper TFUL1(TInitial(displayUnit="K") = 137, assemblyIndex=3,
    valveKvNominal=KvUpperLimb)
    annotation (Placement(transformation(extent={{100,-20},{120,0}})));
  TFCoilBusUpper TFUL2(TInitial(displayUnit="K") = 137, assemblyIndex=4,
    valveKvNominal=KvUpperLimb)
    annotation (Placement(transformation(extent={{100,0},{120,20}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderCoilKv[nTF](each T=3)
    "Smooths each per-bus Kv step -- same anti-chatter role as PFCircuit.mo's identical block."
    annotation (Placement(transformation(extent={{-220,-100},{-200,-80}})));

  ThermalSystems.GasComponents.Sensors.Sensor_p sensor_p_suction
    "CLASS NAME ASSUMED by analogy with PFCircuit.mo's identical sensor and its own docstring caveat -- ThermalSystems isn't vendored in this repo, verify at translate-check."
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
    "Compliant buffer between the ideal makeupReservoir boundary and RV07 -- same structural fix PF applies (see PFCircuit.mo's makeupBuffer docstring: a valve bridging a compliant network node directly to a rigid ideal boundary is a known solver-stiffness risk)."
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
    "Plain continuous proportional trim -- SIMPLIFIED vs PFCircuit.mo's RV07Limiter, see the top-of-file note on why the pulse-then-trim rewrite was not ported over."
    annotation (Placement(transformation(extent={{120,220},{100,240}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderRV07(T=valveRampTime)
    annotation (Placement(transformation(extent={{80,220},{60,240}})));
  Modelica.Blocks.Sources.RealExpression RV08Limiter(y=if not enablePressureControl
         then Kv_shut_pressureValves else min(max(-PID_pressure.y, 0)*KvGainRelief, KvReliefMax))
    annotation (Placement(transformation(extent={{-100,240},{-80,260}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderRV08(T=valveRampTime)
    annotation (Placement(transformation(extent={{-60,240},{-40,260}})));

  TFStructure Structure(TInitial(displayUnit="K") = 80,  assemblyIndex=2,
    valveKvNominal=12)
    "valveKvNominal=12 (default 100) throttles the always-open Structure branch to ~0.14 kg/s -- the share ATEKO's 1.3 kg/s total leaves after the 224 coil channels x 5.17 g/s (Tab.6). At Kv=100 it took 51% of circulator flow (0.86 kg/s), starving the coils to 3.4-4.2 g/s/channel. Sized from the 2026-10-02 run: the branch is valve-dominated (7.9 kPa valve vs 70 Pa tube), so flow ~ Kv*sqrt(dp); 100*(0.14/0.86)*sqrt(7.9/15) ~ 12 at the ~15 kPa header dp expected once the coils carry ~1.15 kg/s."
    annotation (Placement(transformation(extent={{100,80},{120,100}})));
equation
  heaterHysteresis.u = PID.y;
  coolingHysteresis.u = -PID.y;
  bypassHysteresis.u = -PID.y;
  PID_pressure.u_s = pressureSetpoint;
  PID_pressure.u_m = sensor_p_suction.sensorValue;

  for i in 1:nTF loop
    kvTarget_TF[i] = if coilOpen[i] and not coldShut[i] then valveKvNominal_TF[i] else Kv_shut;
    firstOrderCoilKv[i].u = kvTarget_TF[i];
    T_gas_out_compare_TF[i] = if coilOpen[i] and not coldShut[i] then T_gas_out_TF[i] else T_gas_out_frozen[i];
  end for;
  TFCL1.KvValue_in1 = firstOrderCoilKv[1].y;
  Structure.KvValue_in1 = firstOrderCoilKv[2].y;
  TFUL1.KvValue_in1 = firstOrderCoilKv[3].y;
  TFUL2.KvValue_in1 = firstOrderCoilKv[4].y;

algorithm
  // valve4 overcool bypass state machine -- copied unchanged from PFCircuit.mo.
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

  for i in 1:nTF loop
    when (enableCoilIsolation and isolationAllowed_TF[i] and time >= controlActivationDelay
          and (T_gas_out_max - T_gas_out_compare_TF[i]) < coilIsolationReopenMargin
          and not pre(coilOpen[i])) then
      coilOpen[i] := true;
    // Close test uses T_gas_out_compare_TF (live while open, frozen while
    // closed) rather than the raw T_gas_out_TF: once a branch is shut its
    // near-zero outlet flow keeps reversing sign, so the raw outlet
    // temperature flips between tube and junction values and kept crossing
    // this threshold, firing ~1500 state events per 7 ms (Structure, t~38.9s).
    elsewhen (enableCoilIsolation and isolationAllowed_TF[i] and (T_gas_out_max - T_gas_out_compare_TF[i]) > coilIsolationCloseMargin
          and pre(coilOpen[i])) then
      coilOpen[i] := false;
      T_gas_out_frozen[i] := T_gas_out_TF[i];
    end when;

    // Permanent "cooled down" shut-off (upper limb only, see shutWhenCold_TF).
    // Tested on T_gas_out_compare_TF, which freezes at the latch instant, so
    // the shut bus's stagnant outlet temperature can't re-cross the threshold
    // and fire events afterwards. Gated by controlActivationDelay because the
    // gas starts at 80K (= T_coldShut) before the 137K coils heat it.
    when shutWhenCold_TF[i] and time >= controlActivationDelay
        and T_gas_out_compare_TF[i] <= T_coldShut and not pre(coldShut[i]) then
      coldShut[i] := true;
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
  connect(tube1.portB, valve3.portA) annotation (Line(
      points={{-82,-60},{-82,-59},{-72,-59}},
      color={255,153,0},
      thickness=0.5));
  connect(valve3.portB, junction7.portB) annotation (Line(
      points={{-60,-59},{-50,-59},{-50,-4}},
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
  connect(junction7.portA, junction21.portA) annotation (Line(
      points={{-46,0},{-30,0},{-30,20},{-24,20}},
      color={255,153,0},
      thickness=0.5));
  connect(junction21.portC, junctionSupply.portB) annotation (Line(
      points={{-16,20},{-10,20},{-10,40},{-4,40}},
      color={255,153,0},
      thickness=0.5));
  connect(junction21.portB, valve4.portA) annotation (Line(
      points={{-20,24},{-20,59}},
      color={255,153,0},
      thickness=0.5));
  connect(valve4.portB, junction20.portB) annotation (Line(
      points={{-20,71},{-20,116}},
      color={255,153,0},
      thickness=0.5));
  connect(bypassRegulatorOverCool.y, firstOrder3.u)
    annotation (Line(points={{-65,70},{-58,70}}, color={0,0,127}));
  connect(firstOrder3.y, valve4.KvValue_in) annotation (Line(points={{-35,70},
          {-28,70},{-28,65},{-23.75,65}}, color={0,0,127}));
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
  if connectStructure then
    connect(junctionCL.portC, Structure.portA1) annotation (Line(
        points={{20,84},{20,90},{97.2,90}},
        color={255,153,0},
        thickness=0.5));
    connect(Structure.portB1, junctionReturnCL.portC) annotation (Line(
        points={{120.4,89.8},{140,89.8},{140,84}},
        color={255,153,0},
        thickness=0.5));
  end if;
  connect(junctionReturn.portB, junction20.portA) annotation (Line(
      points={{164,40},{180,40},{180,120},{-16,120}},
      color={255,153,0},
      thickness=0.5));
  connect(junction20.portC, fan2ndOrder.portA) annotation (Line(
      points={{-24,120},{-52,120}},
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
