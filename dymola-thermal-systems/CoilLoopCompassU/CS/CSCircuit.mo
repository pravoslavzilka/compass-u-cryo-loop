within CoilLoopCompassU.CS;
model CSCircuit
  extends ThermalSystems.Internals.ClassTypes.ExampleModel;
  // ===========================================================================
  // CS coil cooling loop -- same structure as TF/TFCircuit.mo and
  // PF/PFCircuit.mo (diagram laid out on PF's coordinates), sized from ATEKO
  // study 22172-Z-R1 (S3.3.2, S5.1.2, S5.2.2, S5.3.2, S6.5.2, S7) and PFD
  // 22178-3-R0. Full sourcing in docs/cs/circulator-sizing.md.
  //
  // Flow path: circulator CC01 (fan2ndOrder, fixed speed) -> flow meter FM01
  // -> junction5 (circulator bypass CS_RV01 back to suction, sets the loop flow) ->
  // heater EH01 -> split: cooling valve valve6 -> evaporator tube1 (HE01, LIN
  // side with boiling resistance and a 0.27 kg/s supply cap) -> valve3 |
  // evaporator bypass valve5 (CS_RV02) -> mixing node junction7 -> coil
  // bypass tee junction21 (valve4 -> junction20, around all coils) -> supply
  // header -> 5 coils, each with ON/OFF valves at both ends (CS_V01..V05) ->
  // return header -> junction20 -> junction4 -> circulator.
  //
  // Startup: the coils start shut, at 137.5K wall and gas (ATEKO Tab.5, no
  // heat pulse). The loop first circulates through the coil bypass valve4
  // (throttled to the coils' own resistance) while the temperature control
  // brings the supply to T_wall_max - 40K; once it has held there for
  // prepHoldTime, the coils open and valve4 closes (coolantReady).
  //
  // Anti-chatter measures carried from TF/PF: valve3 decouples the near-zero-
  // flow evaporator from the supply junctions; heater/cooling/bypass split
  // range uses hysteresis gates + first-order smoothing; coil isolation and
  // cold shut-off test frozen outlet temperatures (T_gas_out_compare_CS) and
  // close each coil at both ends; all Kv commands are smoothed and start
  // from their own initial value.
  // ===========================================================================

  parameter Integer nCS = 5 "Number of CS coils, order CS1, CS2U, CS2L, CS3U, CS3L (ATEKO Tab.2).";
  parameter Integer nChannels_CS[nCS] = {2, 1, 1, 2, 2} "Channels per coil (ATEKO Tab.2), 8 in total.";
  parameter Real kvScale = 0.05
    "Scale applied to TF's heater/cooling/bypass valve Kv values: CS circulates ~0.0075 m3/s vs TF's 0.145 m3/s (~1/19), so the same valve pressure drops -- and TF's tuned split-range behaviour -- are kept at CS flow.";
  parameter Real u_dead = 1;
  parameter Real Kv_shut = 1e-4;
  parameter Real Kv_cool_max = 5000*kvScale "Cooling valve6 max Kv (TF 5000, scaled).";
  parameter Real Kv_gain = 100*kvScale "Cooling valve6 Kv per unit -PID.y (TF 100, scaled).";
  parameter Real Kv_bypassOpen = 500*kvScale "Evaporator bypass valve5 Kv when not throttled (TF 500, scaled).";
  parameter Real heater_gain = 100
    "W per unit PID.y -> 6 kW max (yMax=60), same as TF. ATEKO S6.1: a CS heater may not be needed at all (compression heat warms the loop ~30C/h); it only matters for warm-up, not cooldown.";
  parameter Real bypass_limit = 2 "Same as TF -- valve5 starts throttling just past the cooling threshold.";
  parameter Real bypassKvGain = 50*kvScale "valve5 Kv reduction per unit PID.y once bypassHysteresis is on (TF 50, scaled) -- fully shut by PID.y=-10.";
  parameter Real hysteresisHalfWidth = 0.3 "Anti-chatter gap around each PID.y switching threshold, same as TF/PF.";
  parameter Modelica.Units.SI.TemperatureDifference tempMargin = 40
    "ATEKO S3.2 'Limit (T_object - T_coolant) <= 40K' and S3.4 '40K (T inlet - T outlet)'.";
  parameter Modelica.Units.SI.Temperature T_supplyFloor(displayUnit="K") = 77
    "Lower bound on wanted_temp -- 77K LIN evaporation temperature (ATEKO S3.4 minimum target), same as TF.";

  // --- startup coolant preparation through the coil bypass valve4 [CS-PREP] ---
  parameter Real Kv_prepBypass = 1
    "valve4 Kv during preparation: ~10 bar at 0.17 kg/s of 97.5K/82 bar helium, about the coils' own loss, so the circulator runs near its design point and RV01 hardly moves at the hand-over.";
  parameter Modelica.Units.SI.TemperatureDifference prepTempBand = 2
    "Preparation is done once the supply temperature is within this band of wanted_temp (T_wall_max - 40K) ...";
  parameter Real prepFlowFraction = 0.9 "... with at least this fraction of m_flow_design circulating ...";
  parameter Modelica.Units.SI.Time prepHoldTime = 10 "... continuously for this long.";
  parameter Modelica.Units.SI.Time prepMaxTime = 300 "Fallback: the coils open at this time even if the supply never settled.";
  parameter Modelica.Units.SI.Temperature T_loopInitial(displayUnit="K") = TInitialCoil - tempMargin
    "Initial gas temperature in the loop outside the coils and the evaporator -- the prepared supply temperature, so the first gas the coils see already meets the 40K rule (the 2026-10-07 run started it at 80K and broke S3.4's inlet-outlet limit for 31s).";

  parameter Boolean enableOverCoolPrevention = false "valve4 coil-bypass trigger after startup -- copied from TF/PF, off by default.";
  parameter Boolean enableOverCoolRecovery = false "valve4 stabilize-and-reclose logic -- copied from TF/PF, off by default.";
  parameter Modelica.Units.SI.TemperatureDifference overCoolShutMargin = 40 "Copied from TF/PF.";
  parameter Modelica.Units.SI.TemperatureDifference overCoolReopenMargin = 45 "Copied from TF/PF.";
  parameter Modelica.Units.SI.TemperatureDifference overCoolStabilityBand = 20 "Copied from TF/PF.";
  parameter Modelica.Units.SI.Time overCoolStabilizeDelay = 30 "Copied from TF/PF.";
  parameter Real Kv_coilBypassOpen = 5000*kvScale "valve4 Kv when opened by the overcool logic (TF 5000, scaled).";

  parameter Boolean enableCoilIsolation = true
    "Per-coil relative-margin isolation (ATEKO S6.1: 'ON/OFF valve switch ON/OFF flow rate through coils according to their temperature') -- all 5 coils, CS_V01..V05.";
  parameter Modelica.Units.SI.TemperatureDifference coilIsolationCloseMargin = 40 "Same as TF/PF.";
  parameter Modelica.Units.SI.TemperatureDifference coilIsolationReopenMargin = 35 "Same as TF/PF.";
  parameter Boolean shutWhenCold_CS[nCS] = fill(true, nCS)
    "Per-coil opt-in to the permanent 'cooled down' shut-off, same rule as TF's upper limb -- a coil that reaches T_coldShut gives its flow to the others.";
  parameter Modelica.Units.SI.Temperature T_coldShut(displayUnit="K") = 80 "ATEKO S3.4 target temperature.";
  parameter Modelica.Units.SI.Temperature T_releaseAll(displayUnit="K") = 80
    "Once the hottest wall cell of every coil still being cooled is below this, all shut-offs are lifted (allReleased), same as TF.";
  parameter Modelica.Units.SI.Time controlActivationDelay = 10
    "Preparation, isolation and shut-off logic stay off this long after start / after the coils open: the 88m CS channels hold ~5s of gas at design flow.";
  parameter Modelica.Units.SI.Temperature TInitialCoil(displayUnit="K") = 137.5
    "Coil wall and trapped gas initial temperature -- ATEKO Tab.5: 137.5K coil temperature after a shot (energy balance, 16 MJ into 714 kg).";

  // --- circulator CC01: fixed speed, coil flow set by the bypass CS_RV01 -- design-basis doc S10d ---
  // Sized 2026-10-16 for fixed-speed duty (design-basis doc S10e): the design point is the
  // hardest duty point at n_fixed_Hz. The 2026-10-16 run (11.5 bar/0.0074 m3/s machine at
  // 220 Hz) ran at 86-96% of zero-head flow, eta 0.27-0.53 and 22-28 kW shaft power.
  parameter Modelica.Units.SI.Frequency n_nominal_Hz = 200 "ASSUMED, carried from PF (12,000 rpm); also the fixed running speed.";
  parameter Modelica.Units.SI.PressureDifference dp_nominal_Pa = 1375000
    "Hardest duty point: 13.8 bar loop loss at 0.17 kg/s and 25.4 kg/m3 suction (t~300s, 2026-10-16 run), at the reference density of p/T_nominal (24.7 kg/m3). Fan2ndOrder losses scale with density x speed^3 and (V/V_maxPhyd)^2.3, so a machine sized exactly for this point at its own nominal speed gives the lowest fixed-speed power: ~16-18 kW over the cooldown (Python replica of Fan2ndOrder validated against the run to 0.1%).";
  parameter Modelica.Units.SI.VolumeFlowRate V_flow_nominal_val = 0.0070
    "Hardest duty point: 0.17 kg/s / 25.4 kg/m3 = 0.0067 m3/s, +5% so RV01 still passes ~0.013 kg/s there.";
  parameter Real V_flow0_ratio = 1.10
    "Zero-head flow / V_flow_nominal_val (was 1.21, PF's ratio). Steep curve: as the gas densifies the fan's flow rises only ~7% (0.0071 -> 0.0076 m3/s) while RV01 takes the surplus mass. Peak shaft power vs this ratio: 1.05 -> 16.8, 1.10 -> 18.0, 1.21 -> 20.1, 1.5 -> 24.6 kW.";
  parameter Modelica.Units.SI.AbsolutePressure p_nominal_Pa = 7050000
    "Reference state for the fan's density scaling (with T_nominal 137.5K: 24.7 kg/m3 real gas). Kept at 70.5 bara so dp_nominal_Pa above stays referred to that density.";
  parameter Modelica.Units.SI.MassFlowRate m_flow_design = 0.17
    "ATEKO S6.5.2 total minimal flow, 8 channels x 0.0214 kg/s (Tab.5).";
  parameter Modelica.Units.SI.Frequency n_fixed_Hz = n_nominal_Hz
    "Fixed circulator speed (no speed control, as PF/TF) -- the machine's own nominal speed. As the gas densifies the fan pushes more mass at almost the same volume flow and RV01 returns the surplus to suction (~0.12 kg/s at the cold end).";
  parameter Modelica.Units.SI.Time T_softStart = 10
    "Motor soft start (first order) from n_start_Hz to n_fixed_Hz -- a start-up ramp only, no feedback.";
  parameter Modelica.Units.SI.Frequency n_start_Hz = 155
    "Speed at t=0: the 2026-10-08 run settled at 152-157 Hz for 0.17 kg/s through valve4 at 97.5K. Starting at n_nominal_Hz (200) gave 21 bar, 26 kW and 0.34 kg/s at t=0, a pressure spike that opened RV07 and RV08 together.";
  parameter Modelica.Units.SI.VolumeFlowRate V_flow_start = 0.0045
    "Circulator volume flow at t=0: 0.17 kg/s / ~38 kg/m3 (97.5K, 82 bar). V_flow_nominal_val is at 137.5K (23 kg/m3) and doubled the initial mass flow.";

  // --- circulator bypass CS_RV01: coil-loop flow control (replaces the speed control) [C-RV01] ---
  parameter Real k_RV01PID = 3
    "Kv per kg/s of loop-flow error. Plant gain d(m_flow_loop)/d(Kv) ~ -0.1 (cold end, RV01 passing ~0.15 kg/s at 8 bar) to -0.17 kg/s (RV01 nearly shut at 14 bar) -> loop gain 0.3-0.5.";
  parameter Modelica.Units.SI.Time Ti_RV01PID = 10;
  parameter Real Kv_RV01Max = 5
    "RV01 full-open Kv: 0.3 kg/s at 8 bar/47 kg/m3 (one coil channel left open at the cold end) needs Kv ~1.8.";
  parameter Real Kv_RV01Start = 0.5
    "RV01 Kv at t=0: ~0.1 kg/s of the circulator's ~0.28 kg/s (97.5K gas) back to suction during preparation.";
  parameter Modelica.Units.SI.Time T_RV01 = 2 "RV01 actuator lag (first order).";

  // --- C-RV01 goal: flow (m_flow_set) or power (P_shaftLimit with m_flow_set as floor) -- docs/control-common.md ---
  type RV01Goal = enumeration(
      Flow "Hold the coil-loop flow at m_flow_set",
      Power "Spend the shaft-power budget P_shaftLimit on extra coil flow, never below m_flow_set")
    "C-RV01 control goal.";
  parameter RV01Goal rv01Goal = RV01Goal.Flow
    "Flow: RV01 holds m_flow_set. Power: PID_power adds 0..dm_flowPowerMax to the flow target while P_shaft is below P_shaftLimit, and takes it back above; the flow PI and the m_flow_set floor are the same in both modes.";
  parameter Modelica.Units.SI.Power P_shaftLimit = 20000
    "ASSUMED placeholder: shaft-power budget in power mode. Flow mode runs at ~16-18 kW over the cooldown (2026-10-16 sizing), so 20 kW leaves a few kW for extra flow.";
  parameter Modelica.Units.SI.MassFlowRate dm_flowPowerMax = 0.1
    "ASSUMED placeholder: most extra coil-loop flow power mode may add above m_flow_set (the circulator delivers ~0.29 kg/s at the cold end).";
  parameter Real k_powerPID = 6e-6
    "kg/s of extra flow per W of power error. ASSUMED: ~5 kW per 0.1 kg/s of loop flow at fixed speed -> outer loop gain ~0.3; to be checked against a power-mode run.";
  parameter Modelica.Units.SI.Time Ti_powerPID = 60
    "Slow outer loop: 6x the flow PI's Ti_RV01PID, so the cascade doesn't fight the inner flow loop.";

  // --- evaporator HE01, LIN side ---
  parameter Modelica.Units.SI.Temperature T_LIN(displayUnit="K") = 77 "LIN evaporation at ~1 bar (ATEKO S6.2).";
  parameter Integer evapTubes = 25;
  parameter Modelica.Units.SI.Length evapLength = 8.0
    "Enlarged HE01 (2026-10-09), was 5 m = the study's UA ~2.35 kW/K. At 5 m the 2026-10-08 run left the He outlet 4.5K above the 77K LIN at full duty (NTU ~2.8, effective UA ~2.0 kW/K at 0.13 kg/s), the evaporator bypass shut by ~900s and the supply could not follow wanted_temp (1.7-2.6K above it), which stretched the tail to 80K. 8 m: area and both film conductances x1.6 -> NTU ~4.5, approach ~1K. Length rather than more tubes: more tubes lower the He velocity and gain only ~n^0.2.";
  parameter Integer nEvapCells = 8 "One per metre, so per-cell NTU stays ~0.6 (5 cells at 8 m would understate the approach).";
  parameter Modelica.Units.SI.CoefficientOfHeatTransfer alpha_LIN = 3000
    "LIN nucleate boiling on the tube outside at ~7 kW/m2 (35 kW / 5.5 m2) -- ASSUMED, typical 2000-5000 W/m2K. At 5 m: He side ~2.8 kW/K + LIN side 16.5 kW/K in series -> UA ~2.4 kW/K at 0.17 kg/s; x1.6 at 8 m.";
  final parameter Modelica.Units.SI.ThermalConductance G_LINcell =
    alpha_LIN*evapTubes*Modelica.Constants.pi*0.014*evapLength/nEvapCells
    "LIN-side conductance per evaporator cell (14 mm tube OD).";
  parameter Modelica.Units.SI.HeatFlowRate Q_LINmax = 60000
    "ATEKO S7.2: 0.27 kg/s LIN supply -> 53.7 kW latent + vapour superheat -> ~55-60 kW. The evaporator can never remove more.";

  // --- pressure control (RV07 make-up / RV08 relief), same node as TF [C-PRES-a] ---
  parameter Boolean enablePressureControl = true "Master switch for RV07/RV08.";
  parameter Modelica.Units.SI.AbsolutePressure pressureSetpoint = 8200000
    "81 barg nominal working pressure at the CC outlet (ATEKO S6.5.2), +1 bar to absolute. Held at junction1 after the heater, i.e. at circulator discharge pressure -- same node as TF.";
  parameter Modelica.Units.SI.AbsolutePressure pMakeupReservoir = 8850000
    "Make-up reservoir, setpoint x1.08 (TF's ratio) -- below the 95 barg design pressure.";
  parameter Modelica.Units.SI.AbsolutePressure pReliefReservoir = 7550000 "Relief reservoir, setpoint x0.92 (TF's ratio).";
  parameter Modelica.Units.SI.Temperature TStorageReservoirs = 80;
  parameter Real kPressurePID = 1.5e-6
    "Per Pa. Was 0.05 (TF/PF value): 150 Pa of error already saturated PID_pressure, i.e. ~0.016 kg/s of make-up per Pa against a loop capacitance of ~1e-6 kg/Pa. Behind the 8s valve lag that left the discharge pressure ringing at several Hz (std 0.5 Pa, der(p) +-300 Pa/s at junctions 1/5/6/22), which DASSL had to resolve: ~125 steps per simulated second in the 2026-10-08 runs. 1.5e-6: 1 bar error -> Kv 0.3 -> ~0.05 kg/s, loop gain ~0.5/s, damping ~0.5 with pressureValveRampTime.";
  parameter Modelica.Units.SI.Time TiPressurePID = 30;
  parameter Real KvGainMakeup = 2 "Carried from the earlier CS model (held suction within 0.1 bar in the 2026-09-16 run).";
  parameter Real KvMakeupMax = 15;
  parameter Real KvGainRelief = 2;
  parameter Real KvReliefMax = 15;
  parameter Real Kv_shut_pressureValves = 1e-2;
  parameter Modelica.Units.SI.Time valveRampTime = 8;
  parameter Modelica.Units.SI.Time pressureValveRampTime = 2
    "RV07/RV08 command lag (was valveRampTime=8); with kPressurePID it sets the pressure loop damping.";

  Boolean coolantReady(start=false, fixed=true)
    "False during startup preparation (coils shut, flow through valve4); latched true once the supply has settled.";
  Real coolantReadySince(start=0, fixed=true) "Time the coils were opened.";
  Real prepBandEnteredAt(start=0, fixed=true) "Time the supply last entered the preparation band.";
  Modelica.Units.SI.Temperature T_prepTarget = max(max(T_wall_max_CS) - tempMargin, T_supplyFloor)
    "Supply target during preparation = wanted_temp with all coils counted, but without reading the isolation latches (that formed a Boolean algebraic loop with the algorithm).";
  Boolean prepInBand = time >= controlActivationDelay
    and abs(sensor_T.sensorValue - T_prepTarget) < prepTempBand
    and m_flow_loop > prepFlowFraction*m_flow_design
    "Supply prepared: at the target temperature and with design flow circulating.";
  Boolean controlsActive = pre(coolantReady) and time >= pre(coolantReadySince) + controlActivationDelay
    "Isolation, shut-off, release and valve4 logic run only after the coils have been open for controlActivationDelay. pre(): read by the algorithm that sets coolantReady.";

  Real T_ref(start=0, fixed=true) "T_gas_out_max snapshot for valve4's logic, copied from TF/PF.";
  Boolean valve4Open(start=false, fixed=true);
  Boolean overCoolRecovering(start=false, fixed=true);
  Real overCoolRecoveredAt(start=0, fixed=true);

  Real T_gas_out_CS[nCS] = {CS1.T_gas_out, CS2U.T_gas_out, CS2L.T_gas_out, CS3U.T_gas_out, CS3L.T_gas_out}
    "Live gas outlet temperature, order CS1, CS2U, CS2L, CS3U, CS3L.";
  Real T_wall_max_CS[nCS] = {CS1.T_wall_max, CS2U.T_wall_max, CS2L.T_wall_max, CS3U.T_wall_max, CS3L.T_wall_max}
    "Hottest wall cell per coil.";
  Real valveKvNominal_CS[nCS] = {CS1.valveKvNominal, CS2U.valveKvNominal, CS2L.valveKvNominal, CS3U.valveKvNominal, CS3L.valveKvNominal};
  Boolean coilFlowing[nCS] = {pre(coolantReady) and (pre(allReleased) or (pre(coilOpen[i]) and not pre(coldShut[i]))) for i in 1:nCS}
    "Coil i is commanded open. pre(): the latches are set by the algorithm that reads this; event iteration settles it at the same instant.";
  Real kvTarget_CS[nCS] "Commanded Kv per coil before smoothing.";
  Real T_gas_out_compare_CS[nCS]
    "T_wall_max_CS[i] during preparation (shut coil, no meaningful outlet), T_gas_out_CS[i] while flowing, T_gas_out_frozen[i] while shut.";
  Boolean coilOpen[nCS](start=fill(true, nCS), fixed=fill(true, nCS)) "Per-coil isolation latch.";
  Boolean coldShut[nCS](start=fill(false, nCS), fixed=fill(true, nCS))
    "Latched once a shutWhenCold_CS coil reaches T_coldShut; overrides coilOpen until allReleased.";
  Real T_gas_out_frozen[nCS](each start=0, each fixed=true)
    "Snapshot of T_gas_out_CS[i] taken when coil i is shut.";
  Boolean allReleased(start=false, fixed=true) "Latched once T_wallHotLive < T_releaseAll: all coils reopen.";

  Modelica.Units.SI.Temperature T_wallHotLive = max({if coilOpen[i] and not coldShut[i]
      then T_wall_max_CS[i] else 0 for i in 1:nCS})
    "Hottest wall cell among the coils still being cooled; 0 if none.";
  output Modelica.Units.SI.Temperature T_gas_out_max = max(T_gas_out_compare_CS)
    "Hottest coil gas outlet temperature (frozen values for shut coils).";
  Modelica.Units.SI.Temperature T_wallHotCooled = max({if allReleased or (coilOpen[i] and not coldShut[i])
      then T_wall_max_CS[i] else 0 for i in 1:nCS})
    "Hottest wall cell over the coils receiving coolant -- T_object of ATEKO's 40K rule.";
  output Modelica.Units.SI.Temperature wanted_temp = max(T_wallHotCooled - tempMargin, T_supplyFloor)
    "[C-TEMP-SP-b] Supply temperature setpoint: hottest cooled wall cell - 40K, floored at 77K (same as TF).";

  Real openChannelFraction = sum({if coilFlowing[i] then nChannels_CS[i] else 0 for i in 1:nCS})/sum(nChannels_CS)
    "Share of the 8 channels commanded open.";
  output Modelica.Units.SI.MassFlowRate m_flow_set = m_flow_design*(if coolantReady
      then max(openChannelFraction, 1/sum(nChannels_CS)) else 1)
    "[CS-FLOW-SP] Coil-loop flow setpoint: 0.0214 kg/s per open channel (ATEKO Tab.5), full design flow through valve4 during preparation.";
  Modelica.Units.SI.MassFlowRate m_flow_loop = Heater.portA.m_flow
    "Flow to the loop, downstream of the CS_RV01 tee -- what RV01 controls. FM01 sits upstream of the tee (PFD) and reads the circulator flow, loop + bypass; the plant needs a meter here or FM01 minus an RV01 flow estimate.";

  Modelica.Units.SI.HeatFlowRate Q_LIN_uncapped = sum(G_LINcell*(tube1.heatPort[i].T - T_LIN) for i in 1:nEvapCells)
    "Heat the LIN bath would take from the evaporator wall without a supply limit.";
  Real LINcapFactor = noEvent(if Q_LIN_uncapped > Q_LINmax then Q_LINmax/Q_LIN_uncapped else 1)
    "<1 while the LIN supply limits the duty.";
  output Modelica.Units.SI.HeatFlowRate Q_evaporator = LINcapFactor*Q_LIN_uncapped "Evaporator duty.";

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

  // --- circulator CC01, fixed speed [C-SPEED-b] ---
  ThermalSystems.GasComponents.Fans.Fan2ndOrder fan2ndOrder(
    orientation="symmetric",
    use_mechanicalPort=true,
    maxDeltaT=20,
    n_nominal=n_nominal_Hz,
    dp_nominal(displayUnit="bar") = dp_nominal_Pa,
    V_flow_nominal=V_flow_nominal_val,
    V_flow0=V_flow0_ratio*V_flow_nominal_val,
    T_nominal(displayUnit="K") = 137.5,
    p_nominal=p_nominal_Pa,
    eta_maxPhyd=0.6,
    dpInitial(displayUnit="bar") = 1000000,
    V_flow_Start=V_flow_start)
    annotation (Placement(transformation(extent={{8,-8},{-8,8}}, rotation=90,
        origin={-60,120})));
  ThermalSystems.OtherComponents.Mechanical.RotatoryBoundary rotatoryBoundary(
    phiInitial=0,
    boundaryType="n",
    use_nInput=true)
    annotation (Placement(transformation(extent={{-4,9},{4,-9}}, rotation=270,
        origin={-60,131})));
  ThermalSystems.GasComponents.Sensors.Sensor_m_flow sensor_m_flow
    "Circulator mass flow (FM01 on PFD 22178-3-R0), same place as PF -- loop + RV01 bypass, monitoring only."
    annotation (Placement(transformation(extent={{-72,116},{-80,124}})));
  Modelica.Blocks.Sources.RealExpression speedSetpoint(y=n_fixed_Hz) "Fixed circulator speed."
    annotation (Placement(transformation(extent={{-144,126},{-124,146}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderSpeed(T=T_softStart,
    initType=Modelica.Blocks.Types.Init.InitialOutput, y_start=n_start_Hz)
    "Motor soft start, see T_softStart."
    annotation (Placement(transformation(extent={{-112,126},{-92,146}})));

  // --- circulator bypass CS_RV01 (PFD 22178-3-R0), as PF_RV01 ---
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction5(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = T_loopInitial)
    "Circulator discharge tee: portA from the flow meter, portC to the heater, portB to CS_RV01."
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=270, origin={-112,100})));
  ThermalSystems.GasComponents.Valves.Valve CS_RV01(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=0.0001)
    "Circulator bypass, discharge -> suction. Sets the coil-loop flow: the fixed-speed circulator's surplus goes back to suction."
    annotation (Placement(transformation(extent={{-6,-3},{6,3}}, rotation=0, origin={-42,99})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction4(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = T_loopInitial)
    "Circulator suction tee: portA from junction20, portC to the circulator, portB from CS_RV01."
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=180, origin={-20,120})));
  Modelica.Blocks.Sources.RealExpression massFlowSetpoint(y=m_flow_set +
        (if rv01Goal == RV01Goal.Power then PID_power.y else 0))
    "Flow target for PID_RV01: m_flow_set, plus the power-mode surplus (>= 0, so m_flow_set stays the floor)."
    annotation (Placement(transformation(extent={{-230,174},{-210,194}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderMflowSet(T=5,
    initType=Modelica.Blocks.Types.Init.InitialOutput, y_start=m_flow_design)
    "Smooths the setpoint steps when coils shut or reopen."
    annotation (Placement(transformation(extent={{-204,174},{-184,194}})));
  Modelica.Blocks.Continuous.LimPID PID_RV01(
    controllerType=Modelica.Blocks.Types.SimpleController.PI,
    k=k_RV01PID,
    Ti=Ti_RV01PID,
    yMax=0,
    yMin=-Kv_RV01Max,
    initType=Modelica.Blocks.Types.Init.InitialOutput,
    y_start=-Kv_RV01Start)
    "Coil-loop flow on CS_RV01: u_s=m_flow_set, u_m=m_flow_loop. Too much loop flow -> negative y -> RV01 opens (PF's max(-y,0) convention)."
    annotation (Placement(transformation(extent={{-178,174},{-158,194}})));
  Modelica.Blocks.Sources.RealExpression CS_RV01Command(y=Kv_shut + max(-PID_RV01.y, 0))
    "RV01 Kv from the loop-flow PI."
    annotation (Placement(transformation(extent={{-154,174},{-134,194}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderRV01(T=T_RV01,
    initType=Modelica.Blocks.Types.Init.InitialOutput, y_start=Kv_shut + Kv_RV01Start)
    annotation (Placement(transformation(extent={{-118,174},{-98,194}})));
  Modelica.Blocks.Continuous.LimPID PID_power(
    controllerType=Modelica.Blocks.Types.SimpleController.PI,
    k=k_powerPID,
    Ti=Ti_powerPID,
    yMax=dm_flowPowerMax,
    yMin=0,
    initType=Modelica.Blocks.Types.Init.InitialOutput,
    y_start=0)
    "C-RV01 power mode: u_s=P_shaftLimit, u_m=fan2ndOrder.P_shaft. Power below the limit -> y>0 -> extra flow target -> RV01 closes. Only read when rv01Goal=Power; yMin=0 keeps m_flow_set as the floor."
    annotation (Placement(transformation(extent={{-230,206},{-210,226}})));

  // --- heater EH01 ---
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
    m_flowStart=0.17,
    pInitial=8200000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = T_loopInitial,
    TInitialWall(displayUnit="K") = T_loopInitial)
    "Electric heater EH01, off during normal cooldown (ATEKO S6.1)."
    annotation (Placement(transformation(extent={{8,-2},{-8,2}}, rotation=90,
        origin={-112,40})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow1
    annotation (Placement(transformation(extent={{-200,30},{-180,50}})));

  // --- evaporator HE01 and its bypass ---
  ThermalSystems.GasComponents.Tubes.Tube tube1(
    tubeGeometry(
      innerDiameter=0.012,
      length=evapLength,
      nParallelTubes=evapTubes,
      wallThickness=0.001,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    nCells=nEvapCells,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    redeclare model WallMaterial =
        CoilLoopCompassU.Common.StainlessSteel304_Tdep,
    fixedTInitialWall=false,
    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.17,
    pInitial=8200000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = 80)
    "Evaporator HE01, 25 x 12mm x evapLength (8 m; 5 m in the study). ATEKO S6.5.2: 35.3 kW, 0.17 kg/s, He 120 -> 80K vs 77K LIN -> UA ~2.35 kW/K. He side (Dittus-Boelter) ~2.8 kW/K in series with the LIN side (alpha_LIN) ~16.5 kW/K -> ~2.4 kW/K. Duty capped at Q_LINmax (S7.2)."
    annotation (Placement(transformation(extent={{-8,-2},{8,2}}, rotation=0,
        origin={-50,-60})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow linHeatFlow[nEvapCells]
    "LIN bath, one per evaporator cell."
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=270, origin={-50,-30})));
  Modelica.Blocks.Sources.RealExpression LINDuty[nEvapCells](y={-LINcapFactor*
        G_LINcell*(tube1.heatPort[i].T - T_LIN) for i in 1:nEvapCells})
    "Boiling-side heat flow per cell, G_LINcell*(T_wall - 77K), scaled down together once the total exceeds Q_LINmax."
    annotation (Placement(transformation(extent={{-86,-30},{-66,-10}})));
  ThermalSystems.GasComponents.Valves.Valve valve3(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=4000*kvScale)
    "Fixed valve between the evaporator outlet and the mixing node, from TF/PF: decouples the evaporator tube from the supply junctions when its flow is near zero (TF's simulation.nonlinear[2] failures)."
    annotation (Placement(transformation(extent={{-6,-3},{6,3}}, rotation=0,
        origin={-26,-59})));
  ThermalSystems.GasComponents.Valves.Valve valve5(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=Kv_bypassOpen)
    "Evaporator bypass -- CS_RV02 on PFD 22178-3-R0 (temperature control)."
    annotation (Placement(transformation(extent={{-6,-3},{6,3}}, rotation=0,
        origin={-74,-5})));
  ThermalSystems.GasComponents.Valves.Valve valve6(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=Kv_cool_max)
    "Cooling valve at the evaporator inlet, from TF/PF."
    annotation (Placement(transformation(extent={{-6,3},{6,-3}}, rotation=-90,
        origin={-112,-43})));

  // --- heater/cooling/bypass split-range temperature control, from TF [C-TEMP-SR] ---
  Modelica.Blocks.Continuous.LimPID PID(
    controllerType=Modelica.Blocks.Types.SimpleController.PI,
    k=0.12,
    Ti=12,
    yMax=60,
    yMin=-60,
    initType=Modelica.Blocks.Types.Init.InitialOutput,
    y_start=0)
    "Same as TF (y_start=0 so the heater doesn't switch on at startup)."
    annotation (Placement(transformation(extent={{-10,10},{10,-10}},
        rotation=-90, origin={-70,50})));
  Modelica.Blocks.Sources.RealExpression wantedTemp(y=wanted_temp)
    annotation (Placement(transformation(extent={{-156,70},{-136,90}})));
  ThermalSystems.GasComponents.Sensors.Sensor_T sensor_T
    "Supply temperature after the heater/evaporator mixing node."
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
        coolingHysteresis.y then max(min(-PID.y*Kv_gain, Kv_cool_max), Kv_shut) else
        Kv_shut)
    "max(..., Kv_shut): the cooling gate opens at PID.y < 0.7, so -PID.y*Kv_gain was negative for 0 < PID.y < 0.7 (valve6 Kv -0.88 and reverse evaporator flow at t=4-9s in the 2026-10-08 run, 16k Newton failures in tube1). TF/PF have the same expression."
    annotation (Placement(transformation(extent={{-226,-54},{-206,-34}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder(T=2,
    initType=Modelica.Blocks.Types.Init.InitialOutput, y_start=Kv_shut)
    annotation (Placement(transformation(extent={{-192,-54},{-172,-34}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder1(T=1,
    initType=Modelica.Blocks.Types.Init.InitialOutput, y_start=0)
    annotation (Placement(transformation(extent={{-248,30},{-228,50}})));
  Modelica.Blocks.Logical.Hysteresis bypassHysteresis(uLow=bypass_limit -
        hysteresisHalfWidth, uHigh=bypass_limit + hysteresisHalfWidth)
    annotation (Placement(transformation(extent={{-274,-26},{-254,-6}})));
  Modelica.Blocks.Sources.RealExpression BypassLimiter(y=if bypassHysteresis.y
         then max(Kv_bypassOpen + (PID.y*bypassKvGain), Kv_shut) else Kv_bypassOpen)
    annotation (Placement(transformation(extent={{-242,-2},{-222,18}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder2(T=1,
    initType=Modelica.Blocks.Types.Init.InitialOutput, y_start=Kv_bypassOpen)
    annotation (Placement(transformation(extent={{-192,-2},{-172,18}})));

  // --- junctions around the evaporator ---
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction6(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = T_loopInitial)
    "Heater outlet: to the evaporator (portC) and its bypass valve5 (portB)."
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=270, origin={-112,-6})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = T_loopInitial)
    "Evaporator inlet tee; portB to the pressure-control node junction22 (same as TF)."
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90, origin={-112,-24})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction7(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = T_loopInitial)
    "Mixing node: evaporator outlet (via valve3, portC) + bypass valve5 (portB)."
    annotation (Placement(transformation(extent={{-4,4},{4,-4}}, rotation=270, origin={-12,-6})));

  // --- coil bypass: startup preparation and overcool protection ---
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction21(
    volume(displayUnit="l") = 0.2, m_flowStart=1e-5, pInitial=8200000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = T_loopInitial)
    "Supply tee: portA from junction7, portC to the coil supply header, portB to the coil bypass valve4 -- from TF/PF."
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=0, origin={12,20})));
  ThermalSystems.GasComponents.Valves.Valve valve4(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=0.0001)
    "Coil bypass (supply -> circulator suction around all 5 coils): carries the whole flow during startup preparation, then the TF/PF overcool state machine."
    annotation (Placement(transformation(extent={{-6,-3},{6,3}}, rotation=90, origin={12,65})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction20(
    volume=1e-1, m_flowStart=1e-5, pInitial=8200000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = T_loopInitial)
    "Return tee: portA from the coil return header, portB from valve4, portC to junction4 -- from TF/PF."
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=180, origin={12,120})));
  Modelica.Blocks.Sources.RealExpression bypassRegulatorOverCool(y=if not
        coolantReady then Kv_prepBypass else if valve4Open then Kv_coilBypassOpen
         else 0.001)
    annotation (Placement(transformation(extent={{-54,60},{-34,80}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder3(T=3,
    initType=Modelica.Blocks.Types.Init.InitialOutput, y_start=Kv_prepBypass)
    annotation (Placement(transformation(extent={{-20,60},{0,80}})));

  // --- supply header (CS1, CS2U, CS2L, CS3U, CS3L) ---
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionS2(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = T_loopInitial)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90,
        origin={40,20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionS3(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = T_loopInitial)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90,
        origin={60,50})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionS4(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = T_loopInitial)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90,
        origin={60,-58})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionS5(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = T_loopInitial)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=90,
        origin={74,-26})));

  CoilAssembly2ch CS1(TInitial(displayUnit="K") = TInitialCoil,
    TInitialGas(displayUnit="K") = TInitialCoil, assemblyIndex=1)
    "714 kg, 2 x 88 m (ATEKO Tab.2)."
    annotation (Placement(transformation(extent={{100,60},{120,80}})));
  CoilAssembly CS2U(length=86, TInitial(displayUnit="K") = TInitialCoil,
    TInitialGas(displayUnit="K") = TInitialCoil, assemblyIndex=4)
    "349 kg, 1 x 86 m."
    annotation (Placement(transformation(extent={{100,20},{120,40}})));
  CoilAssembly CS2L(length=86, TInitial(displayUnit="K") = TInitialCoil,
    TInitialGas(displayUnit="K") = TInitialCoil, assemblyIndex=5)
    "349 kg, 1 x 86 m."
    annotation (Placement(transformation(extent={{100,-20},{120,0}})));
  CoilAssembly2ch CS3U(TInitial(displayUnit="K") = TInitialCoil,
    TInitialGas(displayUnit="K") = TInitialCoil, assemblyIndex=2)
    "714 kg, 2 x 88 m (Tab.2; PFD draws 2 x 86 m)."
    annotation (Placement(transformation(extent={{100,-60},{120,-40}})));
  CoilAssembly2ch CS3L(TInitial(displayUnit="K") = TInitialCoil,
    TInitialGas(displayUnit="K") = TInitialCoil, assemblyIndex=3)
    "714 kg, 2 x 88 m (Tab.2; PFD draws 2 x 86 m)."
    annotation (Placement(transformation(extent={{100,-100},{120,-80}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderCoilKv[nCS](each T=3,
    each initType=Modelica.Blocks.Types.Init.InitialOutput, each y_start=Kv_shut)
    "Smooths each coil's Kv step -- same anti-chatter role as TF/PF. Starts shut (startup preparation)."
    annotation (Placement(transformation(extent={{-20,-140},{0,-120}})));

  // --- return header ---
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionR1(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = T_loopInitial)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}}, rotation=270,
        origin={140,-76})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionR2(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = T_loopInitial)
    annotation (Placement(transformation(extent={{-4,4},{4,-4}}, rotation=90,
        origin={170,-4})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionR3(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = T_loopInitial)
    annotation (Placement(transformation(extent={{-4,4},{4,-4}}, rotation=90,
        origin={146,52})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junctionR5(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000, fixedInitialPressure=false,
    TInitial(displayUnit="K") = T_loopInitial)
    annotation (Placement(transformation(extent={{-4,4},{4,-4}}, rotation=90,
        origin={152,-44})));

  // --- pressure control RV07/RV08, same node as TF, PF's layout ---
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction22(
    volume=1e-2, m_flowStart=1e-5, pInitial=8200000,
    fixedInitialPressure=false, TInitial(displayUnit="K") = T_loopInitial)
    "Pressure-control node: portA from junction1, portB to RV07 (make-up), portC to RV08 (relief)."
    annotation (Placement(transformation(extent={{-4,4},{4,-4}}, rotation=90, origin={-2,156})));
  ThermalSystems.GasComponents.Sensors.Sensor_p sensor_p_suction
    "Name kept from PF/TF; measures the controlled node junction22 (circulator discharge side), not the suction."
    annotation (Placement(transformation(extent={{58,134},{66,142}})));
  Modelica.Blocks.Sources.RealExpression pressureSetpointSource(y=pressureSetpoint)
    annotation (Placement(transformation(extent={{80,160},{100,180}})));
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
    "Compliant buffer between the ideal reservoir and RV07 -- same as TF/PF."
    annotation (Placement(transformation(extent={{52,194},{60,202}})));
  ThermalSystems.GasComponents.Volumes.Volume reliefBuffer(
    volume=1e-2, enableHeatPort=false, m_flowStart=0, pInitial=pReliefReservoir,
    fixedInitialPressure=false, TInitial(displayUnit="K") = TStorageReservoirs, nPorts=2)
    annotation (Placement(transformation(extent={{-36,182},{-28,190}})));
  ThermalSystems.GasComponents.Valves.Valve RV07(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false, use_KvValueInput=true,
    KvValueFixed=Kv_shut_pressureValves)
    "Make-up valve: makeupBuffer -> junction22."
    annotation (Placement(transformation(extent={{6,-3},{-6,3}}, rotation=0, origin={16,180})));
  ThermalSystems.GasComponents.Valves.Valve RV08(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false, use_KvValueInput=true,
    KvValueFixed=Kv_shut_pressureValves)
    "Relief valve: junction22 -> reliefBuffer."
    annotation (Placement(transformation(extent={{6,-3},{-6,3}}, rotation=0, origin={-8,204})));
  Modelica.Blocks.Sources.RealExpression RV07Limiter(y=if not enablePressureControl
         then Kv_shut_pressureValves else min(max(PID_pressure.y, 0)*KvGainMakeup, KvMakeupMax))
    "Plain continuous proportional trim, same as TF."
    annotation (Placement(transformation(extent={{-40,258},{-20,278}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderRV07(T=pressureValveRampTime)
    annotation (Placement(transformation(extent={{0,260},{20,280}})));
  Modelica.Blocks.Sources.RealExpression RV08Limiter(y=if not enablePressureControl
         then Kv_shut_pressureValves else min(max(-PID_pressure.y, 0)*KvGainRelief, KvReliefMax))
    annotation (Placement(transformation(extent={{-80,220},{-60,240}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderRV08(T=pressureValveRampTime)
    annotation (Placement(transformation(extent={{-40,220},{-20,240}})));
equation
  heaterHysteresis.u = PID.y;
  coolingHysteresis.u = -PID.y;
  bypassHysteresis.u = -PID.y;
  PID_RV01.u_m = m_flow_loop;
  PID_power.u_s = P_shaftLimit;
  PID_power.u_m = fan2ndOrder.P_shaft;

  for i in 1:nCS loop
    kvTarget_CS[i] = if coilFlowing[i] then valveKvNominal_CS[i] else Kv_shut;
    firstOrderCoilKv[i].u = kvTarget_CS[i];
    T_gas_out_compare_CS[i] = if not pre(coolantReady) then T_wall_max_CS[i]
      elseif coilFlowing[i] then T_gas_out_CS[i] else pre(T_gas_out_frozen[i]);
  end for;

algorithm
  // [CS-PREP] Startup coolant preparation: the coils stay shut and the whole flow runs
  // through valve4 until the supply has held within prepTempBand of
  // wanted_temp for prepHoldTime (or prepMaxTime has passed).
  when prepInBand and not pre(coolantReady) then
    prepBandEnteredAt := time;
  end when;
  when not pre(coolantReady) and ((prepInBand and time >= prepBandEnteredAt + prepHoldTime)
      or time >= prepMaxTime) then
    coolantReady := true;
    coolantReadySince := time;
  end when;

  // [C-OVERCOOL, archived] valve4 overcool state machine -- copied unchanged from TF/PF, active
  // only after the startup preparation.
  when enableOverCoolPrevention and controlsActive and T_gas_out_max - sensor_T.sensorValue > overCoolReopenMargin
      and not pre(valve4Open) then
    T_ref := T_gas_out_max;
    valve4Open := true;
    overCoolRecovering := false;
  elsewhen enableOverCoolRecovery and pre(valve4Open) and not pre(overCoolRecovering)
      and sensor_T.sensorValue >= T_ref - overCoolShutMargin
      and sensor_T.sensorValue <= T_ref - overCoolShutMargin + overCoolStabilityBand then
    overCoolRecoveredAt := time;
    overCoolRecovering := true;
  elsewhen enableOverCoolRecovery and pre(valve4Open) and pre(overCoolRecovering)
      and (sensor_T.sensorValue < T_ref - overCoolShutMargin
        or sensor_T.sensorValue > T_ref - overCoolShutMargin + overCoolStabilityBand) then
    overCoolRecovering := false;
  elsewhen enableOverCoolRecovery and pre(overCoolRecovering)
      and sensor_T.sensorValue >= T_ref - overCoolShutMargin
      and sensor_T.sensorValue <= T_ref - overCoolShutMargin + overCoolStabilityBand
      and time >= overCoolRecoveredAt + overCoolStabilizeDelay then
    valve4Open := false;
    overCoolRecovering := false;
  end when;

  for i in 1:nCS loop
    // [C-ISO] Both tests use T_gas_out_compare_CS (live while flowing, frozen while
    // shut): a shut coil's raw outlet temperature flips with its near-zero,
    // sign-changing flow and fired ~1500 events per 7 ms in TF.
    when enableCoilIsolation and controlsActive
        and (T_gas_out_max - T_gas_out_compare_CS[i]) < coilIsolationReopenMargin
        and not pre(coilOpen[i]) then
      coilOpen[i] := true;
    elsewhen enableCoilIsolation and controlsActive
        and (T_gas_out_max - T_gas_out_compare_CS[i]) > coilIsolationCloseMargin
        and pre(coilOpen[i]) then
      coilOpen[i] := false;
      T_gas_out_frozen[i] := T_gas_out_CS[i];
    end when;

    // [C-COLDSHUT] Permanent "cooled down" shut-off, same as TF's upper limb.
    when shutWhenCold_CS[i] and controlsActive
        and T_gas_out_compare_CS[i] <= T_coldShut and not pre(coldShut[i]) then
      coldShut[i] := true;
      T_gas_out_frozen[i] := T_gas_out_CS[i];
    end when;
  end for;

  // [C-COLDSHUT] Release-all once the last coil still being cooled is below T_releaseAll.
  when controlsActive and T_wallHotLive < T_releaseAll
      and not pre(allReleased) then
    allReleased := true;
  end when;

equation
  // --- circulator, fixed speed with soft start ---
  connect(rotatoryBoundary.rotatoryFlange, fan2ndOrder.rotatoryFlange)
    annotation (Line(points={{-60,131},{-60,128}}, color={135,135,135}, thickness=0.5));
  connect(speedSetpoint.y, firstOrderSpeed.u)
    annotation (Line(points={{-123,136},{-114,136}}, color={0,0,127}));
  connect(firstOrderSpeed.y, rotatoryBoundary.n_in)
    annotation (Line(points={{-91,136},{-90,136},{-90,142},{-60,142},{-60,135}}, color={0,0,127}));
  connect(fan2ndOrder.portB, sensor_m_flow.portA)
    annotation (Line(points={{-68,120},{-73,120}}, color={255,153,0}, thickness=0.5));
  connect(sensor_m_flow.portB, junction5.portA)
    annotation (Line(points={{-79,120},{-112,120},{-112,104}}, color={255,153,0}, thickness=0.5));

  // --- circulator bypass CS_RV01 and the coil-loop flow control ---
  connect(massFlowSetpoint.y, firstOrderMflowSet.u)
    annotation (Line(points={{-209,184},{-206,184}}, color={0,0,127}));
  connect(firstOrderMflowSet.y, PID_RV01.u_s)
    annotation (Line(points={{-183,184},{-180,184}}, color={0,0,127}));
  connect(junction5.portB, CS_RV01.portA)
    annotation (Line(points={{-108,100},{-50,100},{-50,99},{-48,99}}, color={255,153,0}, thickness=0.5));
  connect(CS_RV01.portB, junction4.portB)
    annotation (Line(points={{-36,99},{-20,99},{-20,116}}, color={255,153,0}, thickness=0.5));
  connect(junction4.portC, fan2ndOrder.portA)
    annotation (Line(points={{-24,120},{-52,120}}, color={255,153,0}, thickness=0.5));
  connect(CS_RV01Command.y, firstOrderRV01.u)
    annotation (Line(points={{-133,184},{-120,184}}, color={0,0,127}));
  connect(firstOrderRV01.y, CS_RV01.KvValue_in)
    annotation (Line(points={{-97,184},{-42,184},{-42,102.75}}, color={0,0,127}));

  // --- heater and its controls ---
  connect(junction5.portC, Heater.portA)
    annotation (Line(points={{-112,96},{-112,48}}, color={255,153,0}, thickness=0.5));
  connect(prescribedHeatFlow1.port, Heater.heatPort[1])
    annotation (Line(points={{-180,40},{-114,40}}, color={191,0,0}));
  connect(HeaterLimiter.y, firstOrder1.u)
    annotation (Line(points={{-277,40},{-250,40}}, color={0,0,127}));
  connect(firstOrder1.y, prescribedHeatFlow1.Q_flow)
    annotation (Line(points={{-227,40},{-200,40}}, color={0,0,127}));
  connect(wantedTemp.y, PID.u_s)
    annotation (Line(points={{-135,80},{-70,80},{-70,62}}, color={0,0,127}));
  connect(sensor_T.sensorValue, PID.u_m)
    annotation (Line(points={{-12,46},{-12,52},{-50,52},{-50,50},{-58,50}}, color={0,0,127}));

  // --- heater outlet -> evaporator branch (valve6 -> tube1 -> valve3) and bypass valve5 ---
  connect(Heater.portB, junction6.portA)
    annotation (Line(points={{-112,32},{-112,-2}}, color={255,153,0}, thickness=0.5));
  connect(junction6.portC, junction1.portC)
    annotation (Line(points={{-112,-10},{-112,-20}}, color={255,153,0}, thickness=0.5));
  connect(junction1.portA, valve6.portA)
    annotation (Line(points={{-112,-28},{-112,-37}}, color={255,153,0}, thickness=0.5));
  connect(valve6.portB, tube1.portA)
    annotation (Line(points={{-112,-49},{-112,-60},{-58,-60}}, color={255,153,0}, thickness=0.5));
  for i in 1:nEvapCells loop
    connect(linHeatFlow[i].port, tube1.heatPort[i])
      annotation (Line(points={{-50,-40},{-50,-58}}, color={191,0,0}));
    connect(LINDuty[i].y, linHeatFlow[i].Q_flow)
      annotation (Line(points={{-65,-20},{-50,-20}}, color={0,0,127}));
  end for;
  connect(tube1.portB, valve3.portA)
    annotation (Line(points={{-42,-60},{-42,-59},{-32,-59}}, color={255,153,0}, thickness=0.5));
  connect(valve3.portB, junction7.portC)
    annotation (Line(points={{-20,-59},{-12,-59},{-12,-10}}, color={255,153,0}, thickness=0.5));
  connect(junction6.portB, valve5.portA)
    annotation (Line(points={{-108,-6},{-106,-5},{-80,-5}}, color={255,153,0}, thickness=0.5));
  connect(valve5.portB, junction7.portB)
    annotation (Line(points={{-68,-5},{-20,-5},{-20,-6},{-16,-6}}, color={255,153,0}, thickness=0.5));
  connect(CoolingLimiter1.y, firstOrder.u)
    annotation (Line(points={{-205,-44},{-194,-44}}, color={0,0,127}));
  connect(firstOrder.y, valve6.KvValue_in)
    annotation (Line(points={{-171,-44},{-170,-43},{-115.75,-43}}, color={0,0,127}));
  connect(BypassLimiter.y, firstOrder2.u)
    annotation (Line(points={{-221,8},{-194,8}}, color={0,0,127}));
  connect(firstOrder2.y, valve5.KvValue_in)
    annotation (Line(points={{-171,8},{-74,8},{-74,-1.25}}, color={0,0,127}));
  connect(junction7.portA, sensor_T.port)
    annotation (Line(points={{-12,-2},{-12,40}}, color={255,153,0}, thickness=0.5));

  // --- mixing node -> coil bypass tee -> supply header ---
  connect(junction7.portA, junction21.portA)
    annotation (Line(points={{-12,-2},{-12,20},{8,20}}, color={255,153,0}, thickness=0.5));
  connect(junction21.portB, valve4.portA)
    annotation (Line(points={{12,24},{12,59}}, color={255,153,0}, thickness=0.5));
  connect(valve4.portB, junction20.portB)
    annotation (Line(points={{12,71},{12,116}}, color={255,153,0}, thickness=0.5));
  connect(bypassRegulatorOverCool.y, firstOrder3.u)
    annotation (Line(points={{-33,70},{-22,70}}, color={0,0,127}));
  connect(firstOrder3.y, valve4.KvValue_in)
    annotation (Line(points={{1,70},{4,70},{4,65},{8.25,65}}, color={0,0,127}));
  connect(junction21.portC, junctionS2.portB)
    annotation (Line(points={{16,20},{36,20}}, color={255,153,0}, thickness=0.5));

  // --- supply header: S2 -> S3 (CS1, CS2U), S2 -> S4 -> S5 (CS2L, CS3U), S4 -> CS3L ---
  connect(junctionS2.portC, junctionS3.portB)
    annotation (Line(points={{40,24},{40,50},{56,50}}, color={255,153,0}, thickness=0.5));
  connect(junctionS3.portC, CS1.portA1)
    annotation (Line(points={{60,54},{60,70},{97.2,70}}, color={255,153,0}, thickness=0.5));
  connect(junctionS3.portA, CS2U.portA1)
    annotation (Line(points={{60,46},{60,30},{97.2,30}}, color={255,153,0}, thickness=0.5));
  connect(junctionS2.portA, junctionS4.portB)
    annotation (Line(points={{40,16},{40,-58},{56,-58}}, color={255,153,0}, thickness=0.5));
  connect(junctionS4.portC, junctionS5.portB)
    annotation (Line(points={{60,-54},{60,-26},{70,-26}}, color={255,153,0}, thickness=0.5));
  connect(junctionS5.portC, CS2L.portA1)
    annotation (Line(points={{74,-22},{74,-10},{97.2,-10}}, color={255,153,0}, thickness=0.5));
  connect(junctionS5.portA, CS3U.portA1)
    annotation (Line(points={{74,-30},{74,-50},{97.2,-50}}, color={255,153,0}, thickness=0.5));
  connect(junctionS4.portA, CS3L.portA1)
    annotation (Line(points={{60,-62},{60,-90},{97.2,-90}}, color={255,153,0}, thickness=0.5));

  // --- coil ON/OFF valve commands ---
  connect(firstOrderCoilKv[1].y, CS1.KvValue_in1)
    annotation (Line(points={{1,-130},{132,-130},{132,63.4},{120.4,63.4}}, color={0,0,127}));
  connect(firstOrderCoilKv[2].y, CS2U.KvValue_in1)
    annotation (Line(points={{1,-130},{130,-130},{130,23.4},{120.4,23.4}}, color={0,0,127}));
  connect(firstOrderCoilKv[3].y, CS2L.KvValue_in1)
    annotation (Line(points={{1,-130},{128,-130},{128,-16.6},{120.4,-16.6}}, color={0,0,127}));
  connect(firstOrderCoilKv[4].y, CS3U.KvValue_in1)
    annotation (Line(points={{1,-130},{126,-130},{126,-56.6},{120.4,-56.6}}, color={0,0,127}));
  connect(firstOrderCoilKv[5].y, CS3L.KvValue_in1)
    annotation (Line(points={{1,-130},{124,-130},{124,-96.6},{120.4,-96.6}}, color={0,0,127}));

  // --- return header: R1 (CS3U, CS3L) -> R5 (+CS2L) -> R2; R3 (CS1, CS2U) -> R2 -> junction20 ---
  connect(CS3U.portB1, junctionR1.portA)
    annotation (Line(points={{120.4,-50.2},{140,-50.2},{140,-72}}, color={255,153,0}, thickness=0.5));
  connect(CS3L.portB1, junctionR1.portC)
    annotation (Line(points={{120.4,-90.2},{140,-90.2},{140,-80}}, color={255,153,0}, thickness=0.5));
  connect(junctionR1.portB, junctionR5.portA)
    annotation (Line(points={{144,-76},{152,-76},{152,-48}}, color={255,153,0}, thickness=0.5));
  connect(CS2L.portB1, junctionR5.portC)
    annotation (Line(points={{120.4,-10.2},{152,-10.2},{152,-40}}, color={255,153,0}, thickness=0.5));
  connect(junctionR5.portB, junctionR2.portA)
    annotation (Line(points={{156,-44},{170,-44},{170,-8}}, color={255,153,0}, thickness=0.5));
  connect(CS2U.portB1, junctionR3.portA)
    annotation (Line(points={{120.4,29.8},{146,29.8},{146,48}}, color={255,153,0}, thickness=0.5));
  connect(CS1.portB1, junctionR3.portC)
    annotation (Line(points={{120.4,69.8},{146,69.8},{146,56}}, color={255,153,0}, thickness=0.5));
  connect(junctionR3.portB, junctionR2.portC)
    annotation (Line(points={{150,52},{170,52},{170,0}}, color={255,153,0}, thickness=0.5));
  connect(junctionR2.portB, junction20.portA)
    annotation (Line(points={{174,-4},{200,-4},{200,120},{16,120}}, color={255,153,0}, thickness=0.5));
  connect(junction20.portC, junction4.portA)
    annotation (Line(points={{8,120},{-16,120}}, color={255,153,0}, thickness=0.5));

  // --- pressure control at junction1 (circulator discharge side), same as TF ---
  connect(junction1.portB, junction22.portA)
    annotation (Line(points={{-116,-24},{-120,-24},{-120,158},{-12,158},{-12,148},{-2,148},{-2,152}},
      color={255,153,0}, thickness=0.5));
  connect(sensor_p_suction.port, junction22.portA)
    annotation (Line(points={{62,134},{62,130},{-2,130},{-2,152}}, color={255,153,0}, thickness=0.5));
  connect(RV07.portB, junction22.portB)
    annotation (Line(points={{10,180},{4,180},{4,164},{6,164},{6,156},{2,156}}, color={255,153,0}, thickness=0.5));
  connect(junction22.portC, RV08.portA)
    annotation (Line(points={{-2,160},{-2,198},{2,198},{2,204},{-2,204}}, color={255,153,0}, thickness=0.5));
  connect(makeupReservoir.port, makeupBuffer.portArray[1])
    annotation (Line(points={{38,204},{48,204},{48,190},{56,190},{56,193.975}}, color={255,153,0}, thickness=0.5));
  connect(makeupBuffer.portArray[2], RV07.portA)
    annotation (Line(points={{56,194.225},{56,180},{22,180}}, color={255,153,0}, thickness=0.5));
  connect(RV08.portB, reliefBuffer.portArray[1])
    annotation (Line(points={{-14,204},{-40,204},{-40,178},{-32,178},{-32,181.975}}, color={255,153,0}, thickness=0.5));
  connect(reliefBuffer.portArray[2], reliefReservoir.port)
    annotation (Line(points={{-32,182.225},{-32,178},{-20,178}}, color={255,153,0}, thickness=0.5));
  connect(pressureSetpointSource.y, PID_pressure.u_s)
    annotation (Line(points={{101,170},{118,170}}, color={0,0,127}));
  connect(sensor_p_suction.sensorValue, PID_pressure.u_m)
    annotation (Line(points={{62,140},{62,148},{130,148},{130,158}}, color={0,0,127}));
  connect(RV07Limiter.y, firstOrderRV07.u)
    annotation (Line(points={{-19,268},{-10,268},{-10,270},{-2,270}}, color={0,0,127}));
  connect(firstOrderRV07.y, RV07.KvValue_in)
    annotation (Line(points={{21,270},{26,270},{26,188},{16,188},{16,183.75}}, color={0,0,127}));
  connect(RV08Limiter.y, firstOrderRV08.u)
    annotation (Line(points={{-59,230},{-42,230}}, color={0,0,127}));
  connect(firstOrderRV08.y, RV08.KvValue_in)
    annotation (Line(points={{-19,230},{-8,230},{-8,207.75}}, color={0,0,127}));
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
