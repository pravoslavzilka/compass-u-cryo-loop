# Algorithms

Detailed explanations of non-trivial control algorithms in this codebase —
one entry per algorithm, most recent first. This is a design/behavior
reference (what the algorithm does and why), distinct from
`docs/migration-notes.md` (a troubleshooting log of bugs/root causes hit
along the way). An algorithm entry here should stay accurate to the
current `.mo` source; if the design changes, update the entry rather than
appending a new one, and note what changed and why in a short "revision
history" line at the top of the entry.

---

## CirculatorPowerLimiter (PF_RV01): temperature-gated PID shaft-power cap

**Name:** `CirculatorPowerLimiter` informally (no single Modelica instance
carries this name) — the mechanism is `PID_circulatorPower` +
`PF_RV01Command` + `firstOrderPF_RV01`, keyed off
`enableCirculatorPowerOptimization`.

**Where:** `dymola-thermal-systems/CoilLoopCompassU/PF/PFCircuit.mo`,
parameters `enableCirculatorPowerOptimization`/`P_shaftLimit`/
`valve1PowerLimitTriggerTemp`/`kPowerLimitPID`/`TiPowerLimitPID`/
`KvGainPowerLimit`/`KvPowerLimitMax` (all declared together, right after
`controlActivationDelay`), the `PID_circulatorPower`/`PF_RV01Command`/
`firstOrderPF_RV01` block trio, and the two equations wiring
`PID_circulatorPower.u_s`/`u_m` in the equation section.

**Can it be fully turned off?** Yes — `enableCirculatorPowerOptimization`
(default `true`), same `parameter Boolean enable*` convention as every
other optional algorithm in this file. Setting it `false` forces
`PF_RV01Command` to `Kv_shut` unconditionally — the outermost condition in
its expression — regardless of `fan2ndOrder.P_shaft` or `T_gas_out_max`.

**Revision history:** 2026-09-03, replacing an earlier undocumented
flow-trim algorithm on the same valve (`valveRegulator`/`limiter`/
`valve1Command`, never written up in this file) that only ran for the
first `controlActivationDelay` seconds targeting `m_flow_startup`/
`m_wanted`, then forced the valve shut (`Kv_shut`) for the rest of every
run. That algorithm played no role in steady-state or end-of-cooldown
behavior at all; this one replaces it with something that's actually
active during the expensive part of the run.

### What problem this solves

`fan2ndOrder` (the circulator) runs at a fixed speed (`n=200`, held
constant by `rotatoryBoundary`/`smoothStep` for the entire simulation —
there is no speed control available on this hardware). At fixed speed,
`fan2ndOrder.volumeFlowRate` stays roughly flat (~32–35 L/s) through most
of a cooldown, but as the helium densifies while cooling, the pressure
rise (`fan2ndOrder.dp`) needed to push that same volumetric flow through
the coil circuit climbs steeply — from ~5.9 bar (`T_gas_out_max`≈160K) to
~10.8 bar (`T_gas_out_max`≈80K) in the 2026-09-02 baseline run
(`debugging/result.mat`). Since `fan2ndOrder.eta` stays essentially flat
(~0.63–0.665) across that whole range — confirmed from the same run by
checking `fan2ndOrder.P_loss_impact` against `fan2ndOrder.P_loss_blade`:
impact (flow-mismatch) loss stays under ~2% of total loss the entire
cooldown, so the fan is not poorly matched to this circuit — shaft power
tracks `dp` almost 1:1: `fan2ndOrder.P_shaft` rises from ~28 kW to ~58.6
kW over the run, with the **final third of the cooldown alone consuming
43.7% of the run's total circulator energy** (30.9 of 70.8 MJ). Circulator
speed can't be reduced to fix this (see above), so the only lever
available is cutting the circuit resistance the fixed-speed fan has to
push against — which is exactly what opening `PF_RV01` (a bypass valve in
parallel with the coil branch, `junction5`→`PF_RV01`→`junction4`) does:
diverting some flow around the coils lowers the `dp` the fan needs to
produce, at the cost of some coil flow.

### The mechanism

**1. Temperature gate.** The whole thing is forced to `Kv_shut` — doing
nothing — until two conditions both hold:

```
time >= controlActivationDelay
and T_gas_out_max <= valve1PowerLimitTriggerTemp   -- default 140 K
```

`controlActivationDelay` (default 5s, shared with the reopen-logic gates
elsewhere in this file) exists because `T_gas_out_max` briefly reads the
junctions' 80K initial condition for about the first 1.2s of every run,
before the coils' true ~160K start temperature propagates through — an
ungated temperature check would spuriously trigger right at `t=0`.
`valve1PowerLimitTriggerTemp` (140K) is set with margin above the ~127K
point where `fan2ndOrder.P_shaft` naturally crosses `P_shaftLimit` in the
baseline run, so the PID has room to start trimming gently before the cap
would otherwise be exceeded, rather than starting from zero right at the
limit.

**2. PID relief control (only active past the gate).** `PID_circulatorPower`
is a PI `LimPID`, wired in the same direct-acting/relief convention as
`PID_pressure`/`RV08Limiter` above (see the PressureStabilizer entry):

```
PID_circulatorPower.u_s = P_shaftLimit            -- 40000 W
PID_circulatorPower.u_m = fan2ndOrder.P_shaft

PF_RV01Command.y = if not enableCirculatorPowerOptimization then Kv_shut
                   elseif not (time >= controlActivationDelay
                       and T_gas_out_max <= valve1PowerLimitTriggerTemp) then Kv_shut
                   else max(-PID_circulatorPower.y, 0) * KvGainPowerLimit
```

Because of `max(-PID_circulatorPower.y, 0)`, the valve only ever opens
when `fan2ndOrder.P_shaft` is *above* `P_shaftLimit` (error negative) —
whenever `P_shaft` is comfortably under the limit, `PID_circulatorPower.y`
sits saturated at `yMax=2` (an idle saturation with anti-windup, not a
knife-edge boundary at 0, so it doesn't chatter), and
`max(-y, 0) = 0`. `KvGainPowerLimit=50` is sized so `yMin=-10` maps to
exactly `KvPowerLimitMax=500`, keeping the LimPID's own anti-windup bound
sitting exactly at the downstream Kv clamp — the same
no-windup-headroom-beyond-what's-usable invariant `PID_pressure`/
`KvGainMakeup`/`KvGainRelief` already use.

**3. Deliberately gentle tuning.** `kPowerLimitPID=0.0005` is sized so the
~20kW worst-case overshoot above `P_shaftLimit` seen in the baseline run
(`P_shaft` up to ~58.6kW) maps across the PID's full output swing rather
than saturating early; `TiPowerLimitPID=60s` is slower than
`TiPressurePID=30s` because the driver here is a slow, monotonic
cooldown, not a fast transient. Both choices exist specifically so
`PF_RV01` eases open rather than snapping open and dragging `P_shaft`
well below `P_shaftLimit` — per the design brief, overshooting *down* on
power is exactly as undesirable as exceeding the cap, since it means
giving up coil flow for no power benefit.

**4. Anti-chatter smoothing.** `firstOrderPF_RV01` (`T=valveRampTime`)
sits between `PF_RV01Command` and `PF_RV01.KvValue_in`, same role as
`firstOrderRV07`/`firstOrderRV08` on the pressure valves.

### Known placeholders / not yet tuned

- `P_shaftLimit=40000`, `valve1PowerLimitTriggerTemp=140` — both derived
  from a single baseline run (`debugging/result.mat`, 2026-09-02); not
  re-validated with the power-limiter itself active (which will change
  the cooldown trajectory that produced these numbers in the first
  place).
- `kPowerLimitPID=0.0005`, `TiPowerLimitPID=60` — first-guess gentle
  tuning, sized off the same single baseline run's worst-case overshoot;
  needs a real closed-loop run to confirm `P_shaft` actually settles near
  `P_shaftLimit` without excessive undershoot or slow drift.
- `KvGainPowerLimit=50`/`KvPowerLimitMax=500` — carried over in spirit
  from the old flow-trim limiter's `uMax=500` and RV07/RV08's Kv range,
  not re-derived for this specific duty.

All of the above needs a real VM run to confirm before treating this
design as validated rather than "structurally sound, not yet proven at
these exact numbers."

---

## PressureStabilizer (RV07/RV08 suction-pressure control): split-range continuous trim + feedforward pulse

**Name:** `PressureStabilizer` in commit messages (e.g. `c9934d5
PressureStabilizer algorithm set to Pulse+Trim configuration`) — there is
no single Modelica component/instance actually named `PressureStabilizer`
in `PFCircuit.mo`; the name refers to the whole RV07/RV08 make-up/relief
mechanism described below, keyed off `enablePressureControl`. Also
referred to informally as the RV07/RV08 split-range pressure control.

**Where:** `dymola-thermal-systems/CoilLoopCompassU/PF/PFCircuit.mo`,
parameters around `pMakeupOpen`/`KvMakeupPulse`/etc., state variables
around `makeupActive`, `RV07Limiter`/`RV08Limiter`, and the `when` blocks
in the algorithm section (RV07/RV08 make-up/relief comment block).

**Can it be fully turned off?** Yes — `enablePressureControl` (default
`true`) is PressureStabilizer's on/off switch, using the same
`parameter Boolean enable*` convention as every other optional algorithm
in this file (`enableOverCoolPrevention`, `enableOverCoolRecovery`,
`enableCoilIsolation`, `enableLowTempCoolantOptimization`). Setting it
`false` forces both `RV07Limiter` and `RV08Limiter` to
`Kv_shut_pressureValves` unconditionally — this check is the outermost
condition in both Limiter expressions, so it overrides the continuous
trim and the pulse alike; neither valve does anything at all while it's
off, regardless of `sensor_p_suction`. The pulse-arming `when` blocks
also gate on `enablePressureControl`, so no pulse can be armed or left
mid-flight when it's toggled off between runs either (it's a `parameter`,
not changeable mid-run).

**Revision history:** 2026-09-01, replacing an earlier pure-hysteresis
design (`pMakeupOpen`/`pMakeupClose` band, full trim authority for the
whole time a valve was "active") that still limit-cycled. See
`docs/migration-notes.md`'s 2026-09-01 entries for the bugs hit getting
here, in particular the `when/elsewhen` branch-collision bug that
initially made this design look like it worked before it actually did.

### What problem this solves

RV07 (make-up, admits helium from a higher-pressure reservoir) and RV08
(relief, vents helium to a lower-pressure reservoir) hold the suction-node
pressure (`sensor_p_suction`) near `pressureSetpoint` (3,650,000 Pa /
36.5 bar). Earlier designs made each valve a pure on/off (or
dwell-debounced on/off) relay: fully shut, or open at close to full
authority. A relay controller structurally cannot rest at a point — it
can only approach the setpoint, overshoot, and re-trigger the opposite
valve, forever. That produced a sustained ~10–17s bang-bang oscillation
across several tuning attempts (narrow deadband, dwell timers, wider
hysteresis bands — see migration notes).

The fix changes what kind of controller each valve *is*: instead of a
relay, each valve now runs a small **continuous PID trim at all times**,
and reserves a **large fixed-Kv feedforward pulse** purely for excursions
large enough that the trim alone can't be trusted to catch up fast
enough.

### The two mechanisms

**1. Continuous trim (runs essentially always).** `RV07Limiter`/
`RV08Limiter` compute Kv directly from `PID_pressure.y` — the live PI
error between `pressureSetpoint` and `sensor_p_suction` — with a small
gain and cap:

```
RV07Limiter.y = if not enablePressureControl then Kv_shut_pressureValves
                elseif makeupPulsing then KvMakeupPulse
                else min(max(PID_pressure.y, 0) * KvGainMakeup, KvMakeupMax)

RV08Limiter.y = if not enablePressureControl then Kv_shut_pressureValves
                elseif reliefPulsing then KvReliefPulse
                else min(max(-PID_pressure.y, 0) * KvGainRelief, KvReliefMax)
```

`KvGainMakeup`/`KvGainRelief` = 2, `KvMakeupMax`/`KvReliefMax` = 15 (both
placeholders, deliberately conservative — this loop has very little gas
compliance, so a large Kv here has historically been numerically stiff
enough to collapse the solver). Because of `max(PID_pressure.y, 0)` /
`max(-PID_pressure.y, 0)`, RV07 only ever contributes when pressure is
below setpoint and RV08 only when above — a classic split-range pair,
never fighting each other, each fading to ~0 as its side of the error
goes to zero. This is the **only** thing driving the valves whenever no
pulse is in progress, regardless of whether `makeupActive`/`reliefActive`
is true or false — that gating was deliberately removed (see "Why
`Active` no longer gates the trim" below).

The only thing that ever overrides the trim entirely is
`enablePressureControl = false`, the model's master kill switch — that
still forces both valves to `Kv_shut_pressureValves` regardless of
pressure, preserving its documented contract.

**2. Feedforward pulse (fires only on a large excursion).** If pressure
drifts past the outer thresholds (`pMakeupOpen` = 34 bar / `pReliefOpen`
= 39 bar — well outside the setpoint, on purpose, so ordinary trim
activity never reaches them), a pulse fires:

```
when enablePressureControl and sensor_p_suction.sensorValue <= pMakeupOpen
    and not pre(makeupActive) then
  makeupActive := true;
  makeupPulsing := true;
  makeupPulseTargetMass := (pMakeupClose - sensor_p_suction.sensorValue)
                            * V_loopEffective / (R_specificHelium * T_loopEstimate);
end when;
```

`makeupPulseTargetMass` is an ideal-gas-law estimate: "how much helium
mass would need to be added to move the pressure from where it is right
now up to `pMakeupClose`?" (`V_loopEffective` and `T_loopEstimate` are
explicit placeholders — an inaccurate guess only mis-sizes the pulse, it
doesn't break correctness, because of how the pulse is cut off — see
next.) `makeupPulsing` switches `RV07Limiter` to a large **fixed** Kv
(`KvMakeupPulse` = 60) — not PID-moderated, a genuine feedforward burst.

**Ending the pulse — two conditions, not a computed time.** No duration
is ever calculated. Instead, the model's own simulated mass flow through
the valve is integrated live:

```
der(makeupDeliveredMass) = if makeupPulsing then abs(RV07.summary.m_flow_gas_B) else 0;
when enablePressureControl and sensor_p_suction.sensorValue <= pMakeupOpen
    and not pre(makeupActive) then
  reinit(makeupDeliveredMass, 0);
end when;
```

(reset to 0 on the same pulse-start event, in the equation section since
`reinit` isn't legal inside an algorithm-section `when`). A separate
`when` block ends the pulse the moment either stop condition is met:

```
when pre(makeupPulsing) and (makeupDeliveredMass >= makeupPulseTargetMass
    or sensor_p_suction.sensorValue >= pMakeupClose) then
  makeupPulsing := false;
end when;
```

- **Mass condition:** the integrated *actual* delivered mass has caught
  up to the estimate.
- **Pressure condition:** the sensor itself already reached
  `pMakeupClose`, regardless of what the mass integral says.

Using the real simulated flow (not a Kv/dp flow-rate assumption) makes
this self-correcting even if `V_loopEffective`/`T_loopEstimate`/
`KvMakeupPulse` are poorly guessed — an oversized pulse Kv just makes the
mass target arrive sooner, it doesn't cause overshoot, because delivery
is measured, not timed. Once `makeupPulsing` clears, `RV07Limiter`
automatically falls through to the same continuous trim used at every
other time — the pulse does the bulk correction fast, then hands off
smoothly.

RV08/relief mirrors all of this exactly: `pReliefOpen` = 39 bar,
`pReliefClose` = 37.5 bar, `KvReliefPulse` = 60, `reliefPulseTargetMass =
(sensor_p_suction - pReliefClose) * V_loopEffective / (R_specificHelium *
T_loopEstimate)`, integrating `abs(RV08.summary.m_flow_gas_A)` (RV08's
loop-side port — note it's port A for RV08 vs. port B for RV07, since the
two valves are wired with opposite port orientation relative to
`junction22`).

### `makeupActive`/`reliefActive`: a pulse-arming cooldown gate, nothing else

`makeupActive` is a separate, longer-lived flag from `makeupPulsing`. It
turns true on the exact same edge that arms a pulse (crossing
`pMakeupOpen`), but only turns back to `false` once pressure recovers all
the way to `pMakeupClose` — a third, independent `when` block:

```
when pre(makeupActive) and sensor_p_suction.sensorValue >= pMakeupClose then
  makeupActive := false;
  makeupPulsing := false;   -- safety net; normally already false by now
end when;
```

Its **only** remaining job is gating whether a *new* pulse can be armed —
the pulse-start condition requires `not pre(makeupActive)`. Without this
gate, if pressure wobbled back and forth across `pMakeupOpen` (e.g. the
trim nudges it back up a hair, then it dips again), a brand-new pulse
would get armed on every dip — recomputing the mass target and resetting
the mass integral each time — reproducing the exact retriggering-chatter
problem this design exists to avoid, just for the burst valve instead of
the old on/off valve. Requiring a full recovery to `pMakeupClose` before
`makeupActive` clears (and thus before a new pulse can arm) is a
deliberate hysteresis gap on the *pulse*, separate from the deadband the
trim itself doesn't need (the trim has no on/off state to chatter
between in the first place).

The reset is essential, not optional: if that third `when` block didn't
exist, `makeupActive` would stay stuck `true` forever after the *first*
low-pressure episode, permanently blocking any *future* pulse for the
rest of the run — exactly the bug documented in `docs/migration-notes.md`
(2026-09-01, "chained `when/elsewhen` branch collision"), which happened
because the reset was there but got silently skipped due to a branch
priority collision with the pulse-stop condition. It's now a fully
independent `when` block specifically so it can't be skipped that way
again.

**Important distinction:** `makeupActive` resets at `pMakeupClose` (35
bar), *not* at `pressureSetpoint` (36.5 bar). The two latches only need
to confirm pressure is back in a reasonable range before disarming the
pulse mechanism; getting the rest of the way to the exact setpoint is
left entirely to the continuous trim, which doesn't need a threshold to
tell it what to do — it's always just chasing `pressureSetpoint` via the
PID error, before, during, and after any pulse. The threshold ordering
is deliberately staggered:
`pMakeupOpen`(34) < `pMakeupClose`(35) < `pressureSetpoint`(36.5) <
`pReliefClose`(37.5) < `pReliefOpen`(39).

### Why `Active` no longer gates the trim (and why that's safe)

The earlier design used `makeupActive` to gate `RV07Limiter` directly —
`Kv_shut_pressureValves` while `not makeupActive`, trim only while
`makeupActive`. That was removed after observing (via the bug above) that
a run where `makeupActive` got accidentally stuck `true` — leaving RV07
running this same continuous trim unconditionally for the whole run — was
dead stable with no oscillation at all, specifically *because* a
continuously-modulated valve has no discrete state to hunt between. That
observation was deliberately turned into the design: both valves now
always run their trim whenever `enablePressureControl` is true, and
`Active` was narrowed to just the pulse-arming role described above.

### Worked timeline (make-up side; relief mirrors)

1. Pressure drifts down toward 34 bar under normal trim action (trim
   alone isn't enough to arrest a fast enough drift).
2. Pressure crosses `pMakeupOpen` (34 bar): `makeupActive` and
   `makeupPulsing` both turn true in the same event; `makeupPulseTargetMass`
   is computed once from the deviation and frozen; `makeupDeliveredMass`
   resets to 0.
3. `RV07Limiter` commands `KvMakeupPulse` (60) — a real burst, ramped
   through `firstOrderRV07` (`T=valveRampTime`) for numerical smoothing.
   `makeupDeliveredMass` integrates the actual flow.
4. The pulse ends the instant `makeupDeliveredMass >=
   makeupPulseTargetMass` OR pressure itself reaches `pMakeupClose` (35
   bar), whichever comes first. `makeupPulsing := false`.
5. `RV07Limiter` falls through to the small PID trim. If pressure hasn't
   quite reached `pMakeupClose` yet, the trim keeps nudging it up.
6. Once pressure reaches `pMakeupClose`, `makeupActive := false` — the
   pulse mechanism is re-armed for a future excursion. The trim keeps
   running regardless, and continues converging pressure the rest of the
   way to `pressureSetpoint` (36.5 bar) on its own, with no further
   discrete state changes, until the next real excursion.

### Known placeholders / not yet tuned

- `V_loopEffective` = 0.5 m³, `T_loopEstimate` = 80 K, `R_specificHelium`
  = 2077.1 J/(kg·K) — feed the pulse-mass estimate only; wrong values
  mis-size the pulse (over/under-shoots `pMakeupClose`/`pReliefClose`
  somewhat) but don't break correctness, since the trim absorbs whatever
  the pulse leaves behind.
- `KvMakeupPulse`/`KvReliefPulse` = 60 — first guess at pulse authority,
  not sized against real make-up/relief flow requirements yet.
- `KvGainMakeup`/`KvGainRelief` = 2, `KvMakeupMax`/`KvReliefMax` = 15 —
  carried over from the pre-pulse design, historically de-rated multiple
  times for this loop's low gas compliance; now doing double duty as the
  *permanent* trim authority rather than just a post-pulse remainder, not
  yet re-validated in that role.
- `valveRampTime` = 3s at time of writing (has been tuned between 2s/3s/8s
  across sessions — see its docstring in `PFCircuit.mo` for the full
  history) — smooths both the pulse and the trim's Kv commands.

All of the above needs a real VM run to confirm before treating this
design as validated rather than "structurally sound, not yet proven at
these exact numbers."
