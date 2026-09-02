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
