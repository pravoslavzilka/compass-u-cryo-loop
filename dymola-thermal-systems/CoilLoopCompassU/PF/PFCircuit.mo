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
  parameter Boolean enableOverCoolPrevention=false
    "Master switch for valve4's overcool-prevention trigger (the first when-branch below, gated on overCoolReopenMargin). When false, valve4 never opens in response to overcooling risk -- it stays permanently shut, and enableOverCoolRecovery's hold logic never has anything to act on.";
  parameter Boolean enableOverCoolRecovery=false
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
  parameter Modelica.Units.SI.Temperature lowTempCoolantOptimizationThreshold(
      displayUnit="K")=0
    "Absolute T_gas_out threshold (K, independent of coilIsolationCloseMargin's relative-to-max logic) for the lowTempCoolantOptimization algorithm: an assembly colder than this can be shut once enough other assemblies are still hotter than it. Must be raised (e.g. to 80) together with enableLowTempCoolantOptimization=true to actually take effect -- see enableLowTempCoolantOptimization's docstring for why leaving it at 0 matters even while disabled.";
  parameter Integer lowTempCoolantOptimizationMinHotOthers = 2
    "Minimum number of OTHER assemblies that must have T_gas_out above lowTempCoolantOptimizationThreshold before a cold assembly is shut by lowTempCoolantOptimization";
  parameter Modelica.Units.SI.Time lowTempCoolantOptimizationMinDuration = 10
    "Assembly i's own T_gas_out must stay continuously below lowTempCoolantOptimizationThreshold (with lowTempOtherHotCount_PF[i] continuously >= lowTempCoolantOptimizationMinHotOthers) for this long before lowTempCoolantOptimization actually shuts it -- filters out a brief/noisy dip that shouldn't count as a real close decision. Any excursion out of that condition before the duration elapses cancels the pending close; the wait restarts on the next continuous entry.";
  parameter Modelica.Units.SI.Time controlActivationDelay = 5
    "Reopen logic (valve4 and per-coil isolation) stays disabled until this much simulated time has passed, so it isn't triggered by unsettled startup temperatures";
  parameter Real m_flow_startup = 0.2
    "Circuit flow target valve1 bypasses down to for the first controlActivationDelay seconds (same startup window as the reopen-logic delay above), so coil temperatures can be read before valve1 releases to the normal m_wanted trim control, kg/s";

  parameter Boolean enablePressureControl = true
    "Master switch for the RV07 (make-up)/RV08 (relief) split-range pressure-control valve pair at the suction node. When false, both valves are forced to Kv_shut regardless of suction pressure.";
  parameter Modelica.Units.SI.AbsolutePressure pressureSetpoint=3650000
    "Suction-node pressure setpoint held by the RV07/RV08 pair, Pa (35.5 barg abs) -- matches the old ideal boundary's pFixed.";
  parameter Modelica.Units.SI.AbsolutePressure pMakeupOpen(displayUnit="bar")=
    3400000
    "RV07 (make-up) hysteresis ON threshold, Pa (34 bar abs). makeupActive turns true (and a feedforward pulse starts, see makeupPulsing) the instant sensor_p_suction drops to/below this.";
  parameter Modelica.Units.SI.AbsolutePressure pMakeupClose(displayUnit="bar")=
    3500000
    "RV07 (make-up) hysteresis OFF threshold, Pa (35 bar abs). makeupActive turns false once sensor_p_suction recovers to/above this -- must stay > pMakeupOpen so the band gives real chatter margin. 2026-09-01: this hysteresis band on its own still limit-cycled (bang-bang between pMakeupOpen/pMakeupClose, ~10s period observed) because RV07Limiter drove full trim authority (KvGainMakeup*PID_pressure.y, capped at KvMakeupMax) for the whole time makeupActive was true, so each opening still delivered far more mass than needed to just cross the band -- see the pulse-then-trim rewrite at makeupPulsing/KvMakeupPulse below, which fixes this by sizing the correction to the actual deviation instead of relying on the band width to absorb the overshoot.";
  parameter Modelica.Units.SI.AbsolutePressure pReliefOpen(displayUnit="bar")=
    3900000
    "RV08 (relief) hysteresis ON threshold, Pa (39 bar abs). reliefActive turns true (and a feedforward pulse starts, see reliefPulsing) the instant sensor_p_suction rises to/above this.";
  parameter Modelica.Units.SI.AbsolutePressure pReliefClose(displayUnit="bar")=
    3750000
    "RV08 (relief) hysteresis OFF threshold, Pa (37.5 bar abs). reliefActive turns false once sensor_p_suction falls to/below this.";
  parameter Real kPressurePID=0.05
    "PLACEHOLDER P gain for PID_pressure -- conservative starting value, tune after reviewing the baseline (ideal-boundary) run's pressure excursions.";
  parameter Modelica.Units.SI.Time TiPressurePID=30
    "PLACEHOLDER integral time for PID_pressure, s -- tune after baseline run.";
  parameter Modelica.Units.SI.Volume V_loopEffective = 0.5
    "PLACEHOLDER estimate of the compliant helium gas volume on the suction side that RV07/RV08 pressurize/vent (loop tubing + coil headers + junction22 -- NOT the reservoirs/buffers, which are on the other side of the valves). Used only for the feedforward pulse-mass estimate (ideal gas law, see makeupPulseTargetMass/reliefPulseTargetMass) added 2026-09-01. An inaccurate guess only makes the pulse over/undersized -- it does not affect correctness elsewhere, and the trim phase that follows every pulse (KvGainMakeup/KvGainRelief, now capped much lower than the pulse) absorbs whatever the pulse under/overshoots. REPLACE with the actual summed suction-side volume once known, to make the pulse land closer to pMakeupClose/pReliefClose in one shot.";
  parameter Modelica.Units.SI.Temperature T_loopEstimate = 80
    "PLACEHOLDER constant gas temperature for the feedforward pulse-mass estimate (ideal gas law) -- matches TStorageReservoirs/valve TInitial elsewhere in this model as a representative cold-loop value. Same caveat as V_loopEffective: only affects pulse sizing, not correctness.";
  parameter Real R_specificHelium = 2077.1
    "Specific gas constant for helium, J/(kg.K) (R_universal/M_He = 8314.46/4.0026) -- used only for the feedforward pulse-mass estimate.";
  parameter Real KvGainMakeup = 2
    "PLACEHOLDER: maps PID_pressure.y (>0 when pressure below setpoint) to RV07's Kv command during the POST-PULSE TRIM phase only (pre(makeupActive) and not makeupPulsing -- see RV07Limiter). Tune together with kPressurePID/KvMakeupMax. Cut from an initial 50 -> 2 after the 2026-08-10 debugging runs: even Kv~15 (well under the old KvMakeupMax=500 cap) was enough to drag this loop's small internal volume up to within ~13000 Pa of the full pMakeupReservoir within the ~15s open dwell -- this loop has very little gas compliance relative to a reservoir-scale dp, so both gain and cap needed to come down together, not just the cap.";
  parameter Real KvMakeupMax = 15
    "PLACEHOLDER Kv cap for RV07's POST-PULSE TRIM phase (see KvGainMakeup) -- REPLACE with a value sized to the peak make-up mass flow measured from the ideal-boundary baseline run (e.g. via sensor_m_flow during the largest cooldown/isolation transient). Cut from an initial 500 -> 5 for the same reason as KvGainMakeup above -- this is a deliberately weak trim valve until real sizing data is available, not yet sized to correct a real deficit quickly. Raised 5 -> 15 on 2026-09-01 as a first incremental step back up (see the 2026-09-01 migration-notes entry on RV07/RV08 capacity) paired with makeupBuffer's volume increase 1e-3 -> 1e-2 -- re-check dslog.txt for corrector-step collapse before raising further; the 2026-08-10 runs showed even Kv~15 alone (without the larger buffer) was enough to nearly equalize the loop with the reservoir in one dwell window. Since the 2026-09-01 pulse-then-trim rewrite this is no longer the value that does the bulk of the correction -- KvMakeupPulse is.";
  parameter Real KvMakeupPulse = 60
    "PLACEHOLDER fixed (non-PID) Kv commanded during RV07's feedforward pulse (makeupPulsing=true), added 2026-09-01. Deliberately much larger than KvMakeupMax's trim authority -- an oversized value here only shortens the pulse (it's cut off by makeupDeliveredMass reaching makeupPulseTargetMass, or by sensor_p_suction reaching pMakeupClose, whichever comes first), it does not cause overshoot the way running full trim authority for the whole open window did under the pure-hysteresis design (see pMakeupClose's docstring). REPLACE once real make-up flow requirements are known -- this is a first guess, not sized.";
  parameter Real KvGainRelief = 2
    "PLACEHOLDER: maps -PID_pressure.y (>0 when pressure above setpoint) to RV08's Kv command during the POST-PULSE TRIM phase only (pre(reliefActive) and not reliefPulsing -- see RV08Limiter). Tune together with kPressurePID/KvReliefMax. Cut from an initial 50 -> 2, same reasoning as KvGainMakeup. PID_pressure.yMax/yMin must stay at >= KvReliefMax/KvMakeupMax divided by this gain, or PID_pressure's own output saturation becomes the binding cap instead of KvReliefMax/KvMakeupMax -- see PID_pressure's yMax/yMin docstring.";
  parameter Real KvReliefMax = 15
    "PLACEHOLDER Kv cap for RV08's POST-PULSE TRIM phase (see KvGainRelief) -- REPLACE with a value sized to the peak relief mass flow measured from the ideal-boundary baseline run. Cut from an initial 500 -> 5, same reasoning as KvMakeupMax. Raised 5 -> 15 on 2026-09-01, same reasoning as KvMakeupMax. Since the 2026-09-01 pulse-then-trim rewrite this is no longer the value that does the bulk of the correction -- KvReliefPulse is.";
  parameter Real KvReliefPulse = 60
    "PLACEHOLDER fixed (non-PID) Kv commanded during RV08's feedforward pulse (reliefPulsing=true) -- mirror of KvMakeupPulse, see its docstring.";
  parameter Modelica.Units.SI.AbsolutePressure pMakeupReservoir=4500000
    "Make-up storage reservoir pressure (ideal p,T boundary feeding RV07), Pa. Above pressureSetpoint so RV07 can admit helium when the loop runs low.";
  parameter Modelica.Units.SI.AbsolutePressure pReliefReservoir=3000000
    "Relief storage reservoir pressure (ideal p,T boundary drained by RV08), Pa. Below pressureSetpoint so RV08 can bleed helium when the loop runs high.";
  parameter Modelica.Units.SI.Temperature TStorageReservoirs=80
    "Temperature of both storage reservoir boundaries, K.";
  parameter Modelica.Units.SI.Time valveRampTime=3
    "FirstOrder smoothing time constant on RV07/RV08's Kv command -- opening ramp, same anti-chatter role as firstOrder/firstOrder2 on valve6/valve5 (avoids instantaneous Kv steps). Raised from an initial 2s to 8s after the 2026-08-10 debugging run: RV08 crashed the solver (corrector step collapsed to ~6e-13 at t=24.6s, 'the corrector could not converge') while ramping open from Kv_shut_pressureValves, the same '6-decade Kv collapse' class of failure firstOrderCoilKv above documents -- worse here because RV07/RV08 ramp against a fixed, zero-compliance ideal-boundary dp (reservoir) rather than a compliant junction volume, so needs more margin than firstOrderCoilKv's T=3 precedent. Briefly lowered 8 -> 3 on 2026-09-01 to try to shrink the RV07/RV08 ramp-overlap window in the post-relocation oscillation; reverted the same day -- confirmed worse on every measure (state events 836->1007, CPU 743s->1190s, oscillation period 17.7s->a tighter 14.6s, and 3 genuine 'Failed to solve nonlinear system using Newton solver' warnings appeared that were not present at 8s). The ramp speed was never the actual driver -- it just let the same excess valve authority (KvReliefMax/KvMakeupMax) get applied faster, shortening the bang-bang cycle instead of damping it. Superseded by the 2026-09-01 hysteresis rewrite (see pMakeupOpen/pMakeupClose/pReliefOpen/pReliefClose) which addresses the cycle at its source instead of tuning around it.";
  parameter Real Kv_shut_pressureValves = 1e-2
    "RV07/RV08's shut-state Kv -- deliberately less extreme than the shared Kv_shut (1e-4) used elsewhere in this model. Same 2026-08-10 debugging fix as valveRampTime above: RV07/RV08 ramp against a fixed ideal-boundary dp (reservoir), so the full 1e-4-to-open span was numerically harsher than the coil case Kv_shut is tuned for; backing the shut value off by two decades shortens the stiff part of the ramp without meaningfully changing the 'closed' leak flow. Since the 2026-09-01 split-range rewrite (see RV07Limiter/RV08Limiter) this is no longer selected just because makeupActive/reliefActive is false -- RV07/RV08 now always run at least their small PID trim while enablePressureControl is true. It's still reachable, though: it's what both Limiters fall back to whenever the enablePressureControl master switch itself is false, preserving that switch's 'both valves forced shut' contract.";

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

  Boolean makeupActive(start=sensor_p_suction.sensorValue <= pMakeupOpen, fixed=true)
    "RV07's pulse-arming latch. As of the 2026-09-01 split-range rewrite this no longer gates RV07's Kv directly (RV07Limiter runs its small PID trim continuously regardless of makeupActive -- see RV07Limiter's docstring); makeupActive's only remaining job is to arm/cool down the large feedforward PULSE: turns true the instant sensor_p_suction drops to/below pMakeupOpen (arming a pulse, see makeupPulsing), turns false once it recovers to/above pMakeupClose, and a new pulse can't be armed again until that recovery happens -- this is what stops the pulse from re-firing repeatedly while pressure lingers just below pMakeupOpen. This design was arrived at by observing an actual bug: a 2026-09-01 run where makeupActive got stuck true (a when/elsewhen collision, since fixed -- see the git history right above the when-blocks below) accidentally left RV07 running this same always-on continuous trim for the whole run, and that run was dead stable/non-oscillating specifically because a continuously-modulated valve has no discrete state to hunt between, unlike the old hysteresis-gated on/off design. This rewrite makes that behavior deliberate. start is evaluated from the live sensor rather than hardcoded false, so a model that initializes already below pMakeupOpen still latches active instead of the when-clause's crossing edge being missed at t=0 -- see the 2026-09-01 migration-notes entry for why a hardcoded false previously silently disabled RV07/RV08 for an entire run.";
  Boolean makeupPulsing(start=false, fixed=true)
    "True for the first part of a makeupActive episode: RV07 commanded to a large fixed Kv (KvMakeupPulse, not PID-moderated) to deliver makeupPulseTargetMass quickly, added 2026-09-01 to replace running full trim authority for the whole open window (see pMakeupClose's docstring for why that limit-cycled). Set true on the same edge that sets makeupActive; cleared (see the when-clause below) once makeupDeliveredMass reaches makeupPulseTargetMass or sensor_p_suction already reached pMakeupClose, whichever comes first -- after that RV07Limiter drops back to its normal small PID-moderated trim (KvGainMakeup/KvMakeupMax), the same trim that's running continuously at all other times too (see RV07Limiter's docstring).";
  Real makeupPulseTargetMass(start=0, fixed=true)
    "Estimated helium mass, kg, to admit during the current pulse to bring sensor_p_suction from its value at the triggering instant up to pMakeupClose -- ideal gas law: (pMakeupClose - p_trigger)*V_loopEffective/(R_specificHelium*T_loopEstimate). Recomputed only on the makeupPulsing rising edge (frozen for the rest of the episode); an estimate, not exact -- see V_loopEffective's docstring for why that's fine (the trim phase that follows absorbs the error).";
  Real makeupDeliveredMass(start=0, fixed=true)
    "Integral of the actual RV07 loop-side mass flow (abs(RV07.summary.m_flow_gas_B)) since the current pulse started -- see the equation-section der()/reinit pair. Compared against makeupPulseTargetMass to decide when to end the pulse; using the model's own simulated flow (not the Kv/dp estimate that sized the pulse) makes the pulse cutoff self-correcting even if KvMakeupPulse or V_loopEffective/T_loopEstimate are inaccurate.";

  Boolean reliefActive(start=sensor_p_suction.sensorValue >= pReliefOpen, fixed=true)
    "RV08's pulse-arming latch -- mirror of makeupActive, see its docstring for the full 2026-09-01 split-range rationale. No longer gates RV08's Kv directly; only arms/cools down the feedforward pulse (reliefPulsing). Turns true the instant sensor_p_suction rises to/above pReliefOpen, turns false once it falls to/below pReliefClose.";
  Boolean reliefPulsing(start=false, fixed=true)
    "Mirror of makeupPulsing for RV08/reliefActive -- see its docstring.";
  Real reliefPulseTargetMass(start=0, fixed=true)
    "Estimated helium mass, kg, to vent during the current pulse to bring sensor_p_suction from its value at the triggering instant down to pReliefClose: (p_trigger - pReliefClose)*V_loopEffective/(R_specificHelium*T_loopEstimate). Mirror of makeupPulseTargetMass -- see its docstring.";
  Real reliefDeliveredMass(start=0, fixed=true)
    "Integral of the actual RV08 loop-side mass flow (abs(RV08.summary.m_flow_gas_A)) since the current pulse started. Mirror of makeupDeliveredMass -- see its docstring.";

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
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-8,-2},{8,2}},
        rotation=0,
        origin={-50,-60})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={60,60})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction3(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={140,80})));
  ThermalSystems.GasComponents.Valves.Valve PF_RV01(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=0.0001) annotation (Placement(transformation(
        extent={{-6,-3},{6,3}},
        rotation=0,
        origin={-42,99})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction4(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=180,
        origin={-20,120})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction5(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=270,
        origin={-112,100})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction8(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={80,80})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction9(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={140,40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction10(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={80,40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction11(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=3650000,
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
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={60,-20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction13(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={80,0})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction14(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={80,-40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction15(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={140,0})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction16(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={140,-40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction17(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={160,-20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction18(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={180,20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction19(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={40,20})));
  Modelica.Blocks.Sources.RealExpression valveRegulator(y=Kv_circuit*(
        sensor_m_flow.sensorValue - m_flowTarget)/m_flowTarget)
    annotation (Placement(transformation(extent={{-238,174},{-218,194}})));
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
    annotation (Placement(transformation(extent={{-46,10},{-30,26}})));
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=500, uMin=0.001)
    annotation (Placement(transformation(extent={{-178,174},{-158,194}})));
  Modelica.Blocks.Sources.RealExpression valve1Command(y=if time <
        controlActivationDelay then limiter.y else Kv_shut)
    "valve1's final Kv command: the flow-trim proportional control (valveRegulator
    -> limiter), still targeting m_flow_startup, for the first controlActivationDelay
    seconds only; after that valve1 no longer trims flow toward m_wanted -- it's
    forced fully shut (Kv_shut) instead."
    annotation (Placement(transformation(extent={{-154,174},{-134,194}})));
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
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=180,
        origin={12,120})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction21(
    volume(displayUnit="l") = 0.2,
    m_flowStart=1e-5,
    pInitial=3650000,
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
    pInitial=3650000,
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
        origin={-112,-43})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction23(
    volume(displayUnit="l") = 0.1,
    m_flowStart=1e-5,
    pInitial=3650000,
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
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = 80) annotation (Placement(transformation(
        extent={{8,-2},{-8,2}},
        rotation=90,
        origin={-112,40})));
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
  Modelica.Blocks.Continuous.FirstOrder firstOrder3(T=3)
    annotation (Placement(transformation(extent={{-20,60},{0,80}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderCoilKv[nPF](each T=3)
    "Smooths each per-coil Kv step to avoid solver state events -- T=3 (was 1) to soften the 6-decade Kv collapse that stalled the solver for ~73s of simulated time (t~95-168s) in the 2026-07-27 run"
    annotation (Placement(transformation(extent={{-20,-100},{0,-80}})));
  // --- RV07/RV08 make-up/relief pressure control (replaces the old ideal
  // p,T boundary) ---------------------------------------------------------
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction22(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    "Tee at the suction node occupying junction6's old boundary.port slot -- portA to junction6.portB (unchanged coil-return topology), portB to RV07 (make-up), portC to RV08 (relief)."
    annotation (Placement(transformation(extent={{-4,4},{4,-4}},
        rotation=90,
        origin={-2,156})));
  ThermalSystems.GasComponents.Boundaries.Boundary makeupReservoir(
    TFixed(displayUnit="K") = TStorageReservoirs,
    boundaryType="p",
    pFixed=pMakeupReservoir)
    "Infinite make-up storage reservoir, above pressureSetpoint. Fixed p,T (boundaryType=\"p\"), free mass flow -- one of the model's two remaining fixed-pressure points."
    annotation (Placement(transformation(extent={{34,194},{42,214}})));
  ThermalSystems.GasComponents.Boundaries.Boundary reliefReservoir(
    TFixed(displayUnit="K") = TStorageReservoirs,
    boundaryType="p",
    pFixed=pReliefReservoir)
    "Infinite relief storage reservoir, below pressureSetpoint. Fixed p,T (boundaryType=\"p\"), free mass flow -- the model's other remaining fixed-pressure point."
    annotation (Placement(transformation(extent={{-24,168},{-16,188}})));
  ThermalSystems.GasComponents.Volumes.Volume makeupBuffer(
    volume=1e-2,
    enableHeatPort=false,
    m_flowStart=0,
    pInitial=pMakeupReservoir,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = TStorageReservoirs,
    nPorts=2)
    "Small compliant buffer between makeupReservoir (ideal, zero-compliance p,T boundary) and RV07 -- added 2026-08-10 after repeated solver collapses ('corrector could not converge', stepsize -> ~1e-13) that persisted even after cutting KvGainMakeup/KvMakeupMax and lengthening valveRampTime; the last failure hit a SECOND, otherwise-unrelated nonlinear subsystem (junction8/10/1/13/23/14/12/19/21, nothing to do with RV07/junction22) at the same instant, pointing at a structural issue -- a valve bridging directly from a compliant network node to a rigid ideal boundary -- rather than just Kv magnitude. This gives the DAE a real pressure state to relax through instead of an algebraic jump against an infinitely stiff boundary. volume raised 1e-3 -> 1e-2 on 2026-09-01 alongside KvMakeupMax 5 -> 15, to buy back some of the compliance margin a bigger Kv spends -- still small enough not to meaningfully change the reservoir's effectively-infinite capacity."
    annotation (Placement(transformation(extent={{52,194},{60,202}})));
  ThermalSystems.GasComponents.Volumes.Volume reliefBuffer(
    volume=1e-2,
    enableHeatPort=false,
    m_flowStart=0,
    pInitial=pReliefReservoir,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = TStorageReservoirs,
    nPorts=2)
    "Same purpose as makeupBuffer, on RV08's reservoir side -- see makeupBuffer's docstring. volume raised 1e-3 -> 1e-2 on 2026-09-01, same reasoning as makeupBuffer."
    annotation (Placement(transformation(extent={{-36,182},{-28,190}})));
  ThermalSystems.GasComponents.Valves.Valve RV07(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=Kv_shut_pressureValves)
    "Make-up valve: makeupReservoir -> junction22. Opens proportionally (RV07Limiter/firstOrderRV07, PID-moderated) once suction pressure drops to/below pMakeupOpen (32 bar); stays open, still PID-moderated, until pressure recovers to/above pMakeupClose (35 bar) -- see makeupActive's hysteresis docstring."
    annotation (Placement(transformation(extent={{6,-3},{-6,3}},
        rotation=0,
        origin={16,180})));
  ThermalSystems.GasComponents.Valves.Valve RV08(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=Kv_shut_pressureValves)
    "Relief valve: junction22 -> reliefReservoir. Opens proportionally (RV08Limiter/firstOrderRV08, PID-moderated) once suction pressure rises to/above pReliefOpen (37 bar); stays open, still PID-moderated, until pressure falls to/below pReliefClose (35 bar) -- see reliefActive's hysteresis docstring."
    annotation (Placement(transformation(extent={{6,-3},{-6,3}},
        rotation=0,
        origin={-8,204})));
  ThermalSystems.GasComponents.Sensors.Sensor_p sensor_p_suction
    "Suction-node pressure sensor -- CLASS NAME ASSUMED by analogy with Sensor_T/Sensor_m_flow (no pressure sensor existed anywhere in this model before; the ThermalSystems library isn't vendored in this repo so this couldn't be confirmed against source -- verify at translate-check, fix the class path here if Dymola reports it unresolved)."
    annotation (Placement(transformation(extent={{58,134},{66,142}})));
  Modelica.Blocks.Sources.RealExpression pressureSetpointSource(y=
        pressureSetpoint)
    annotation (Placement(transformation(extent={{80,160},{100,180}})));
  Modelica.Blocks.Continuous.LimPID PID_pressure(
    controllerType=Modelica.Blocks.Types.SimpleController.PI,
    k=kPressurePID,
    Ti=TiPressurePID,
    yMax=7.5,
    yMin=-7.5,
    initType=Modelica.Blocks.Types.Init.InitialOutput,
    y_start=0)
    "u_s=pressureSetpoint, u_m=sensor_p_suction.sensorValue, e=u_s-u_m: y>0 when suction pressure is below setpoint (feeds RV07Limiter), y<0 when above (feeds RV08Limiter via -y). Same LimPID class/PI form as PID (temperature loop) above; k/Ti are still placeholders, tune together with KvGainMakeup/KvGainRelief. yMax/yMin tightened from a placeholder +-1e5 to +-2.5 (2026-08-31, diagnosing an enableOverCoolPrevention=true run that hard-failed at t=37.86s with 'corrector could not converge') -- 2.5 was exactly where RV07Limiter/RV08Limiter's own min(...,KvMakeupMax)/(KvGainMakeup) downstream clamp already saturated at the time, so anything y accumulated past that was pure integrator windup with no effect on the commanded Kv. End-state dump from that failed run showed PID_pressure.I.y=-199708, ~2x past even the old yMin -- this bound stops that windup at the DAE level instead of letting it grow unchecked until a valve4-triggered pressure transient (e.g. overcool-bypass opening) forces a slow unwind that compounds with the transient's own stiffness. Raised 2.5 -> 7.5 on 2026-09-01 in lockstep with KvMakeupMax/KvReliefMax 5 -> 15 (7.5*KvGainMakeup/KvGainRelief=2 = 15), preserving the same 'yMax sits exactly at the downstream Kv clamp, no windup headroom beyond what's usable' invariant the 2026-08-31 fix established -- do not raise KvMakeupMax/KvReliefMax again without moving this in the same proportion, or the 2026-08-31 windup failure mode is back in play."
    annotation (Placement(transformation(extent={{120,160},{140,180}})));
  Modelica.Blocks.Sources.RealExpression RV07Limiter(y=if not
        enablePressureControl then Kv_shut_pressureValves else if
        makeupPulsing then KvMakeupPulse else min(max(PID_pressure.y, 0)*
        KvGainMakeup, KvMakeupMax))
    "RV07 Kv command, 2026-09-01 split-range trim (made permanent/deliberate, see makeupActive's docstring): Kv_shut_pressureValves only while the enablePressureControl master switch is off (preserves its documented 'both valves forced shut' contract); otherwise fixed KvMakeupPulse (feedforward burst, not PID) while makeupPulsing, else PID-proportional trim (min(PID_pressure.y*KvGainMakeup, KvMakeupMax)) at ALL times whether or not makeupActive -- RV07 never fully closes just because makeupActive is false, it just trims toward ~0 on its own once PID_pressure.y<=0 (pressure at/above setpoint)."
    annotation (Placement(transformation(extent={{-40,258},{-20,278}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderRV07(T=valveRampTime)
    "Opening ramp for RV07 -- same anti-chatter role as firstOrder/firstOrder2 on valve6/valve5."
    annotation (Placement(transformation(extent={{0,260},{20,280}})));
  Modelica.Blocks.Sources.RealExpression RV08Limiter(y=if not
        enablePressureControl then Kv_shut_pressureValves else if
        reliefPulsing then KvReliefPulse else min(max(-PID_pressure.y, 0)*
        KvGainRelief, KvReliefMax))
    "RV08 Kv command, 2026-09-01 split-range trim (made permanent/deliberate, see reliefActive's docstring): Kv_shut_pressureValves only while the enablePressureControl master switch is off (preserves its documented 'both valves forced shut' contract); otherwise fixed KvReliefPulse (feedforward burst, not PID) while reliefPulsing, else PID-proportional trim (min(-PID_pressure.y*KvGainRelief, KvReliefMax)) at ALL times whether or not reliefActive -- RV08 never fully closes just because reliefActive is false, it just trims toward ~0 on its own once -PID_pressure.y<=0 (pressure at/below setpoint)."
    annotation (Placement(transformation(extent={{-80,220},{-60,240}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrderRV08(T=valveRampTime)
    "Opening ramp for RV08 -- same anti-chatter role as firstOrder/firstOrder2 on valve6/valve5."
    annotation (Placement(transformation(extent={{-40,220},{-20,240}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction6(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=3650000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={-112,-24})));
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

  // RV07/RV08 make-up/relief hysteresis + feedforward pulse/trim.
  // 2026-08-31: pressureDeadband+pressureDwellTime debounce FSM -- dwell
  // gated OPENING only with an immediate, narrow-band close, which let each
  // valve's own ramp-down/residual flow push the pressure straight through
  // to the opposite valve's threshold and re-trigger it, sustaining a
  // ~14.5s bang-bang limit cycle indefinitely instead of settling.
  // 2026-09-01 rewrite #1: replaced the debounce with a wide fixed
  // hysteresis band (pMakeupOpen/pMakeupClose, pReliefOpen/pReliefClose).
  // Still limit-cycled (~10s period observed) because RV07Limiter/
  // RV08Limiter ran full trim authority (PID*KvGain, capped at KvMax) for
  // the ENTIRE time the valve was active, so each opening still dumped far
  // more mass than the deviation actually needed -- the band width was
  // absorbing the same kind of overshoot the dwell used to, just less of it.
  // 2026-09-01 rewrite #2 (this one): estimate the mass needed to correct
  // the deviation (ideal gas law, makeupPulseTargetMass/reliefPulseTargetMass)
  // the instant the threshold is crossed, and deliver it with a large FIXED
  // Kv (KvMakeupPulse/KvReliefPulse, not PID-moderated) until the model's
  // own measured delivered mass (makeupDeliveredMass/reliefDeliveredMass,
  // integrated in the equation section below) reaches that estimate -- or
  // until the pressure already got there on its own, whichever is first.
  // Only after that does control hand off to the old, deliberately weak PID
  // trim (KvGainMakeup/KvMakeupMax etc.) for the rest of the episode, so the
  // trim is now correcting a small residual instead of doing the whole job.
  // Each valve's open/stop-pulse/close transitions are THREE INDEPENDENT
  // when-blocks, not one chained when/elsewhen -- deliberately, after a
  // 2026-09-01 bug where chaining them let one collision silently eat
  // another. A chained when/elsewhen behaves like an if-elseif: at any
  // instant where ANY branch's condition gets a fresh edge, the branches
  // are evaluated top-to-bottom and only the FIRST currently-true one
  // fires -- the rest are skipped even if their own condition is also true
  // at that same instant. The old chained version's "stop pulsing"
  // (pulse-mass reached OR pressure >= pMakeupClose) and "stop active"
  // (pressure >= pMakeupClose) branches shared that same pressure-crossing
  // trigger, so whenever the pulse was ended BY the pressure reaching
  // pMakeupClose (rather than by the mass integral), both conditions went
  // true simultaneously and "stop pulsing" (listed first) silently
  // swallowed "stop active" -- makeupActive got stuck true permanently
  // (confirmed via result.mat: makeupActive stayed 1 from t=126s to the
  // end of a 1815s run), leaving RV07 in its PID-trim branch forever
  // instead of shutting once pressure recovered. Trim then quietly
  // converged the whole loop to pressureSetpoint (its own target, not
  // pMakeupClose) with a tiny self-balancing Kv -- a real equilibrium, so
  // the run LOOKED perfectly settled/non-oscillating, but only because the
  // hysteresis close logic was dead, not because it was working. Splitting
  // into independent when-blocks means each fires on its own edge
  // regardless of what else is true at that instant, so this collision
  // can't happen again.
  when enablePressureControl and sensor_p_suction.sensorValue <= pMakeupOpen
      and not pre(makeupActive) then
    makeupActive := true;
    makeupPulsing := true;
    makeupPulseTargetMass := (pMakeupClose - sensor_p_suction.sensorValue)*
      V_loopEffective/(R_specificHelium*T_loopEstimate);
  end when;
  when pre(makeupPulsing) and (makeupDeliveredMass >= makeupPulseTargetMass
      or sensor_p_suction.sensorValue >= pMakeupClose) then
    makeupPulsing := false;
  end when;
  when pre(makeupActive) and sensor_p_suction.sensorValue >= pMakeupClose then
    makeupActive := false;
    makeupPulsing := false;
  end when;

  when enablePressureControl and sensor_p_suction.sensorValue >= pReliefOpen
      and not pre(reliefActive) then
    reliefActive := true;
    reliefPulsing := true;
    reliefPulseTargetMass := (sensor_p_suction.sensorValue - pReliefClose)*
      V_loopEffective/(R_specificHelium*T_loopEstimate);
  end when;
  when pre(reliefPulsing) and (reliefDeliveredMass >= reliefPulseTargetMass
      or sensor_p_suction.sensorValue <= pReliefClose) then
    reliefPulsing := false;
  end when;
  when pre(reliefActive) and sensor_p_suction.sensorValue <= pReliefClose then
    reliefActive := false;
    reliefPulsing := false;
  end when;

equation
  // RV07/RV08 pulse-mass integrators (see makeupPulsing/reliefPulsing above):
  // only accumulate while a pulse is running, and reinit to 0 right on the
  // pulse-start event so each episode's pulse is measured from zero.
  der(makeupDeliveredMass) = if makeupPulsing then abs(RV07.summary.m_flow_gas_B)
    else 0;
  when enablePressureControl and sensor_p_suction.sensorValue <= pMakeupOpen
      and not pre(makeupActive) then
    reinit(makeupDeliveredMass, 0);
  end when;

  der(reliefDeliveredMass) = if reliefPulsing then abs(RV08.summary.m_flow_gas_A)
    else 0;
  when enablePressureControl and sensor_p_suction.sensorValue >= pReliefOpen
      and not pre(reliefActive) then
    reinit(reliefDeliveredMass, 0);
  end when;

  connect(smoothStep.y,rotatoryBoundary. n_in)
    annotation (Line(points={{-179.4,156},{-60,156},{-60,135}},
                                                     color={0,0,127}));
  connect(rotatoryBoundary.rotatoryFlange, fan2ndOrder.rotatoryFlange)
    annotation (Line(
      points={{-60,131},{-60,128}},
      color={135,135,135},
      thickness=0.5));
  connect(coldSurface.port, tube1.heatPort[1]) annotation (Line(points={{-50,-40},
          {-50,-58}},                           color={191,0,0}));
  connect(fan2ndOrder.portA, junction4.portC) annotation (Line(
      points={{-52,120},{-24,120}},
      color={255,153,0},
      thickness=0.5));
  connect(junction4.portB, PF_RV01.portB) annotation (Line(
      points={{-20,116},{-20,99},{-36,99}},
      color={255,153,0},
      thickness=0.5));
  connect(PF_RV01.portA, junction5.portB) annotation (Line(
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
    annotation (Line(points={{-12,46},{-12,52},{-50,52},{-50,32},{-60,32},{-60,
          18},{-47.6,18}},                                color={0,0,127}));
  connect(valveRegulator.y, limiter.u) annotation (Line(points={{-217,184},{
          -180,184}},                       color={0,0,127}));
  connect(valve1Command.y, PF_RV01.KvValue_in) annotation (Line(points={{-133,
          184},{-42,184},{-42,102.75}}, color={0,0,127}));
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
  connect(junction20.portA, junction18.portB) annotation (Line(
      points={{16,120},{200,120},{200,20},{184,20}},
      color={255,153,0},
      thickness=0.5));
  connect(valve6.portB, tube1.portA) annotation (Line(
      points={{-112,-49},{-112,-60},{-58,-60}},
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
  connect(CoolingLimiter1.y, firstOrder.u)
    annotation (Line(points={{-205,-44},{-194,-44}}, color={0,0,127}));
  connect(firstOrder.y, valve6.KvValue_in) annotation (Line(points={{-171,-44},
          {-170,-43},{-115.75,-43}},           color={0,0,127}));
  connect(HeaterLimiter.y, firstOrder1.u)
    annotation (Line(points={{-277,40},{-250,40}}, color={0,0,127}));
  connect(firstOrder1.y, prescribedHeatFlow1.Q_flow)
    annotation (Line(points={{-227,40},{-200,40}},color={0,0,127}));
  connect(Heater.portB, junction7.portA) annotation (Line(
      points={{-112,32},{-112,-2}},
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
    annotation (Line(points={{-180,40},{-114,40}}, color={191,0,0}));
  connect(BypassLimiter.y, firstOrder2.u)
    annotation (Line(points={{-221,8},{-194,8}}, color={0,0,127}));
  connect(firstOrder2.y, valve5.KvValue_in)
    annotation (Line(points={{-171,8},{-74,8},{-74,-1.25}}, color={0,0,127}));
  connect(firstOrder3.y, valve4.KvValue_in) annotation (Line(points={{1,70},{4,
          70},{4,65},{8.25,65}}, color={0,0,127}));
  connect(bypassRegulatorOverCool.y, firstOrder3.u)
    annotation (Line(points={{-33,70},{-22,70}}, color={0,0,127}));
  connect(junction6.portB, junction22.portA) annotation (Line(
      points={{-116,-24},{-120,-24},{-120,158},{-12,158},{-12,148},{-2,148},{-2,
          152}},
      color={255,153,0},
      thickness=0.5));
  connect(RV07.portB, junction22.portB) annotation (Line(
      points={{10,180},{4,180},{4,164},{6,164},{6,156},{2,156}},
      color={255,153,0},
      thickness=0.5));
  connect(junction22.portC, RV08.portA) annotation (Line(
      points={{-2,160},{-2,198},{2,198},{2,204},{-2,204}},
      color={255,153,0},
      thickness=0.5));
  connect(makeupReservoir.port, makeupBuffer.portArray[1]) annotation (Line(
      points={{38,204},{48,204},{48,190},{56,190},{56,193.975}},
      color={255,153,0},
      thickness=0.5));
  connect(makeupBuffer.portArray[2], RV07.portA) annotation (Line(
      points={{56,194.225},{56,180},{22,180}},
      color={255,153,0},
      thickness=0.5));
  connect(RV08.portB, reliefBuffer.portArray[1]) annotation (Line(
      points={{-14,204},{-40,204},{-40,178},{-32,178},{-32,181.975}},
      color={255,153,0},
      thickness=0.5));
  connect(reliefBuffer.portArray[2], reliefReservoir.port) annotation (Line(
      points={{-32,182.225},{-32,178},{-20,178}},
      color={255,153,0},
      thickness=0.5));
  connect(sensor_p_suction.port, junction22.portA) annotation (Line(
      points={{62,134},{62,130},{-2,130},{-2,152}},
      color={255,153,0},
      thickness=0.5));
  connect(pressureSetpointSource.y, PID_pressure.u_s) annotation (Line(
      points={{101,170},{118,170}}, color={0,0,127}));
  connect(sensor_p_suction.sensorValue, PID_pressure.u_m) annotation (Line(
      points={{62,140},{62,148},{130,148},{130,158}},
                                            color={0,0,127}));
  connect(RV07Limiter.y, firstOrderRV07.u) annotation (Line(
      points={{-19,268},{-10,268},{-10,270},{-2,270}},
                                  color={0,0,127}));
  connect(firstOrderRV07.y, RV07.KvValue_in) annotation (Line(
      points={{21,270},{26,270},{26,188},{16,188},{16,183.75}},
                                                       color={0,0,127}));
  connect(RV08Limiter.y, firstOrderRV08.u) annotation (Line(
      points={{-59,230},{-42,230}},
                                  color={0,0,127}));
  connect(firstOrderRV08.y, RV08.KvValue_in) annotation (Line(
      points={{-19,230},{-8,230},{-8,207.75}},         color={0,0,127}));
  connect(junction5.portC, Heater.portA) annotation (Line(
      points={{-112,96},{-112,48}},
      color={255,153,0},
      thickness=0.5));
  connect(junction6.portC, junction7.portC) annotation (Line(
      points={{-112,-20},{-112,-10}},
      color={255,153,0},
      thickness=0.5));
  connect(junction6.portA, valve6.portA) annotation (Line(
      points={{-112,-28},{-112,-37}},
      color={255,153,0},
      thickness=0.5));
  connect(junction20.portC, junction4.portA) annotation (Line(
      points={{8,120},{-16,120}},
      color={255,153,0},
      thickness=0.5));
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
