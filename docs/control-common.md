# Common control algorithms

Algorithms used by more than one circuit (or designed to be). Each entry
defines **what** the algorithm does, its signals, parameters and
variants. **Which tier** it has and **what differs** in a given circuit
live in that circuit's file: [CS](cs/control-logic.md),
[PF](pf/control-logic.md), [TF](tf/control-logic.md). Rules and the tier
definitions: [README](README.md).

Sign convention used throughout: every `LimPID` computes
`y = k·(u_s − u_m) + I`, so `y > 0` means the measurement is *below*
the setpoint.

---

<a id="c-speed"></a>
## C-SPEED — Fixed circulator speed

**Components:** `rotatoryBoundary.n_in` → `fan2ndOrder` (CC01).

The circulator has no speed control (fixed-speed drive in all three
circuits). The speed signal is open-loop:

| Variant | Signal | Used by |
|---|---|---|
| **a** — constant | `smoothStep` 200 → 200 Hz (start and end value equal, so effectively constant) | PF, TF |
| **b** — soft start | `speedSetpoint` (`n_fixed_Hz`) → `firstOrderSpeed` (T = `T_softStart`), starting at `n_start_Hz` | CS |

Variant b exists because starting a cold, dense loop at full speed gave a
pressure spike that opened RV07 and RV08 together (CS 2026-10-08 run).

**Revision history:** 2026-10-22 entry created.

---

<a id="c-pres"></a>
## C-PRES — Loop pressure control (RV07 make-up / RV08 relief)

**Components:** `sensor_p_suction` → `PID_pressure` → `RV07Limiter` /
`RV08Limiter` → `firstOrderRV07` / `firstOrderRV08` → `RV07`, `RV08`.
Reservoirs: `makeupReservoir` → `makeupBuffer` → RV07 → `junction22`;
`junction22` → RV08 → `reliefBuffer` → `reliefReservoir`.
**Switch:** `enablePressureControl` (forces both valves to
`Kv_shut_pressureValves`).

ATEKO S6.1: the circuits are operated at constant pressure; helium is
filled from storage while cooling and returned while heating (RV07/RV08,
"helium management").

One PI on the pressure at `junction22`, split range: `y > 0` (pressure
low) opens RV07, `y < 0` (pressure high) opens RV08. The two never act
together.

```
RV07 Kv = min(max( PID_pressure.y, 0)·KvGainMakeup, KvMakeupMax)
RV08 Kv = min(max(−PID_pressure.y, 0)·KvGainRelief, KvReliefMax)
```

`PID_pressure.yMax/yMin` is set so that the PI saturates exactly where
the downstream Kv clamp does (`R-WINDUP`).

| Variant | Description | Used by |
|---|---|---|
| **a** — continuous split-range PI | Only the trim above. | CS, TF |
| **b** — PressureStabilizer | Trim above **plus** a feedforward pulse: when the pressure crosses an outer threshold (`pMakeupOpen` / `pReliefOpen`), the valve opens at a large fixed Kv until an ideal-gas estimate of the missing/excess mass has been delivered, then hands back to the trim. [Details](#c-pres-b-details). | PF |

In all three circuits `junction22` hangs off the evaporator inlet tee
after the heater, so the controlled pressure is the **circulator
discharge** side, not the suction. The sensor is still called
`sensor_p_suction`, and PF/TF docstrings (and the moved PressureStabilizer
text below) still say "suction node": the names are historical.

**Revision history:** 2026-10-22 entry created; variant b text moved
from the former `docs/algorithms.md` (PressureStabilizer entry, last
revised 2026-09-01).

---

<a id="c-rv01"></a>
## C-RV01 — Circulator bypass control (CS_RV01 / PF_RV01)

**Components:** valve RV01 between the circulator discharge tee
`junction5` and the suction tee `junction4` (ATEKO S6.1: "RV01 — on the
cold-compressor bypass").

With a fixed-speed circulator (C-SPEED), RV01 is the only lever on the
coil-loop flow and on shaft power: opening it returns discharge gas to
suction, which lowers the coil flow, the loop pressure drop and the
shaft power.

One algorithm, **one setting** that selects the goal:

| Mode | Goal | Status |
|---|---|---|
| **Flow** | Hold the coil-loop flow `m_flow_loop` at a setpoint | Implemented (CS) |
| **Power** | Use the shaft-power budget `P_shaftLimit` for extra coil flow, never below the flow setpoint | Implemented (CS), off by default |
| **Power-cap (a)** | Older, PF-only form: cap the shaft power, no flow floor | Implemented (PF), off by default |

### Flow mode

```
m_flow_target = m_flow_set                      (setpoint from the circuit, e.g. CS-FLOW-SP)
PID_RV01:  u_s = firstOrder(m_flow_target), u_m = m_flow_loop
RV01 Kv  = Kv_shut + max(−PID_RV01.y, 0)        → first-order actuator lag → RV01
```

Too much loop flow → `y < 0` → RV01 opens. `PID_RV01.yMin = −Kv_RV01Max`,
`yMax = 0` (R-WINDUP). `m_flow_loop` is measured downstream of the RV01
tee (flow to the heater/loop), not at FM01, which reads loop + bypass.

### Power mode (with flow floor)

A cascade on top of flow mode, so the valve is still driven by the same
flow PI and the minimum flow can never be undercut:

```
PID_power:  u_s = P_shaftLimit, u_m = fan2ndOrder.P_shaft
            yMin = 0, yMax = Δm_max                (extra flow allowed above the setpoint)
m_flow_target = m_flow_set + PID_power.y            (instead of m_flow_set)
```

- Power below the limit → `PID_power.y` rises toward `Δm_max` → the flow
  target rises → RV01 closes → more coil flow, using the power budget.
- Power above the limit → `PID_power.y` falls toward 0 → the target falls
  back to `m_flow_set` → RV01 opens → less power.
- At `PID_power.y = 0` the target is exactly `m_flow_set`: if the power
  is still above the limit there, the **flow floor wins** (the
  requirement beats the optimization).

Both PIs keep their own fixed limits, so there is no min/max-selector and
no integrator wind-up between them. Flow mode is power mode with
`PID_power.y ≡ 0`, which is how the setting switches between them
(CS: `rv01Goal = RV01Goal.Flow | RV01Goal.Power`).

### Power-cap (a) — PF's current form

`PID_circulatorPower` (`u_s = P_shaftLimit`, `u_m = fan2ndOrder.P_shaft`)
drives `PF_RV01` directly: `Kv = max(−y, 0)·KvGainPowerLimit`, only once
`T_gas_out_max ≤ valve1PowerLimitTriggerTemp` (140 K). It only ever
opens RV01 (power above the limit), and has no flow floor. Switch:
`enableCirculatorPowerOptimization` (default **false**). [Details](#c-rv01-power-cap-details).
To be replaced by the power mode above if PF adopts a flow setpoint.

**Revision history:** 2026-10-22 entry created: CS flow mode documented,
power mode (with flow floor) designed and implemented in CS; PF power-cap text moved from the
former `docs/algorithms.md` (CirculatorPowerLimiter entry, 2026-09-03).

---

<a id="c-temp-sr"></a>
## C-TEMP-SR — Split-range supply temperature control

**Components:** `sensor_T` (supply, after the evaporator/bypass mixing
node) and the setpoint from C-TEMP-SP → `PID` → three branches:

| Branch | Gate on `PID.y` (hysteresis, half-width `hysteresisHalfWidth`) | Command | Smoothing | Actuator |
|---|---|---|---|---|
| Heat | `heaterHysteresis`: on above `u_dead + 0.3`, off below `u_dead − 0.3` | `Q = PID.y · heater_gain` | `firstOrder1` | `prescribedHeatFlow1` → heater EH01 |
| Cool | `coolingHysteresis` on `−PID.y`: on when `PID.y < 0.7`, off when `PID.y > 1.3` | `Kv = min(−PID.y · Kv_gain, Kv_cool_max)` | `firstOrder` | `valve6`, evaporator HE01 inlet |
| Force more through HE01 | `bypassHysteresis` on `−PID.y`: on when `PID.y < −(bypass_limit + 0.3)`, off when `PID.y > −(bypass_limit − 0.3)` | `Kv = max(Kv_bypassOpen + PID.y · bypassKvGain, Kv_shut)`, otherwise `Kv_bypassOpen` | `firstOrder2` | `valve5`, evaporator bypass (RV02 on the PFDs) |

(`u_dead = 1` in all circuits, so the thresholds above are 0.7 / 1.3.)

As the loop gets hotter relative to the setpoint, the actions come in
order: heater off → valve6 opens → valve5 throttles, sending a growing
share of the flow through the evaporator. A fixed `valve3` sits between
the evaporator outlet and the mixing node (R-EVAPDECOUPLE).

ATEKO S6.1: RV02 is the temperature-control valve; EH01 is off in normal
cooldown and only needed for warm-up.

Per-circuit parameters (`bypass_limit`, `bypassKvGain`, Kv scaling,
`PID.y_start`) and whether the valve6 command is floored at `Kv_shut`
(R-KVFLOOR) are listed in the circuit files.

**Revision history:** 2026-10-22 entry created.

---

<a id="c-temp-sp"></a>
## C-TEMP-SP — Supply temperature setpoint (40 K rule)

**Output:** `wanted_temp` → `wantedTemp` → `PID.u_s` (C-TEMP-SR).

ATEKO S3.2 (cooldown after discharge): `T_object − T_coolant ≤ 40 K`;
S3.4: cooling loops operated with at most 40 K between inlet and outlet;
S3.4: 77 K is the minimum design target (LIN evaporation).

| Variant | Setpoint | Used by |
|---|---|---|
| **a** — gas outlet | `wanted_temp = T_gas_out_max − tempMargin` (hottest coil **gas outlet**, frozen values for shut coils), no floor | PF |
| **b** — wall, floored | `wanted_temp = max(T_wallHotCooled − tempMargin, T_supplyFloor)` — hottest **wall cell** over the coils currently receiving coolant (or all coils once released, C-COLDSHUT), floored at 77 K | CS, TF |

`tempMargin = 40 K` everywhere. Variant b is the stricter reading of
"T_object": the gas outlet runs a few K below the hottest wall cell, so
variant a lets the supply sit slightly more than 40 K below the coil.
Shut coils are excluded in b because they receive no coolant; including
them would hold the supply up for coils it never reaches.

**Revision history:** 2026-10-22 entry created.

---

<a id="c-iso"></a>
## C-ISO — Per-coil isolation (relative margin)

**Components:** per coil `i`: `coilOpen[i]` latch → `kvTarget[i]`
(`valveKvNominal` or `Kv_shut`) → `firstOrderCoilKv[i]` → the coil
assembly's `KvValue_in1` (its ON/OFF valve(s)).
**Switch:** `enableCoilIsolation` (default true in all circuits).

ATEKO S6.1: "ON/OFF valve switch ON/OFF flow rate through coils according
to their temperature"; S3.2: focus on temperature homogeneity. IPP
requirement: the spread between the hottest and the coldest coil must
not exceed 40 K.

```
close coil i   when  T_gas_out_max − T_cmp[i] > coilIsolationCloseMargin   (40 K)
               and freeze T_gas_out_frozen[i] := T_gas_out[i]
reopen coil i  when  T_gas_out_max − T_cmp[i] < coilIsolationReopenMargin  (35 K)
               and time past the activation delay (R-ACTDELAY)
```

`T_cmp[i]` is the live outlet temperature while the coil flows and the
frozen value while it is shut (R-FROZEN). A coil that is far colder
than the hottest one is taken out, so its flow goes to the hot coils;
it comes back once the others have caught up to within 35 K.

**Revision history:** 2026-10-22 entry created.

---

<a id="c-coldshut"></a>
## C-COLDSHUT — Shut-off at target temperature + release-all

**Components:** `coldShut[i]`, `allReleased` → the coil's commanded Kv.
**Switch:** per coil, `shutWhenCold_<circuit>[i]`.

```
coldShut[i]  := true   when shutWhenCold[i] and T_cmp[i] ≤ T_coldShut (80 K), freeze T_gas_out_frozen[i]
allReleased  := true   when T_wallHotLive < T_releaseAll (80 K)
coil i flows  ⇔  allReleased or (coilOpen[i] and not coldShut[i])
```

`T_wallHotLive` is the hottest wall cell among the coils still being
cooled. A coil that has reached the 80 K target (ATEKO S3.4) stops
taking flow, which then goes to the coils still warm; once the last of
them is below 80 K every shut-off is lifted and all coils run again.
Both latches are permanent for the run.

**Optimizes:** cooldown time of the slowest coil (flow redistribution).
The requirements are met without it.

**Revision history:** 2026-10-22 entry created.

---

<a id="c-overcool"></a>
## C-OVERCOOL — valve4 overcool state machine

**Components:** `valve4Open`, `overCoolRecovering`, `T_ref` →
`bypassRegulatorOverCool` → `firstOrder3` → `valve4` (coil bypass:
supply tee `junction21` → valve4 → return tee `junction20`, around all
coils).
**Switches:** `enableOverCoolPrevention`, `enableOverCoolRecovery` —
both **false** in all circuits.

```
open:      T_gas_out_max − T_supply > overCoolReopenMargin (45 K)  → valve4Open, T_ref := T_gas_out_max
settling:  T_supply inside [T_ref − 40 K, T_ref − 40 K + 20 K]     → start the 30 s timer
           leaving the band cancels the timer
close:     30 s continuously inside the band                       → valve4 shut
```

While open, most of the flow bypasses the coils (valve4 Kv is much
larger than the coil branches), so the coils are not hit by supply gas
far colder than they are.

Archived everywhere: C-TEMP-SP keeps the supply within 40 K of the
hottest coil by construction, so the 45 K trigger has nothing left to
catch, and the CS startup case is handled by CS-PREP. The code is kept
(flags off) in all three `.mo` files.

**Revision history:** 2026-10-22 entry created.

---

# Robustness measures (not tiered)

These exist for numerical stability (event chattering, Newton failures,
stiff valve steps), not for control intent. Changing them changes how
well the model solves, not what the plant is asked to do.

| ID | Measure | Where |
|---|---|---|
| <a id="r-hyst"></a>**R-HYST** | Hysteresis gates (± `hysteresisHalfWidth` = 0.3) on every `PID.y` switching threshold, so a PI output resting on a threshold doesn't fire events. | C-TEMP-SR, all circuits |
| <a id="r-smooth"></a>**R-SMOOTH** | First-order lag on every Kv / heat command (1–8 s), with `InitialOutput` at the command's own start value, so no valve steps by decades in one instant. | All valves, all circuits |
| <a id="r-frozen"></a>**R-FROZEN** | A shut coil's outlet temperature is replaced by its value at the closing instant. The raw value flips with the near-zero, sign-changing flow and fired ~1500 events per 7 ms in TF. | C-ISO, C-COLDSHUT |
| <a id="r-bothends"></a>**R-BOTHENDS** | A shut coil is closed at inlet **and** outlet (one Kv command, outlet scaled by `outletKvRatio`), so its gas is trapped instead of breathing through an open outlet. | CS (all coils), TF upper limb; PF inlet only |
| <a id="r-evapdecouple"></a>**R-EVAPDECOUPLE** | Fixed `valve3` between the evaporator outlet and the mixing node decouples the near-zero-flow evaporator tube from the supply junctions. | All circuits |
| <a id="r-actdelay"></a>**R-ACTDELAY** | `controlActivationDelay`: event logic waits until the startup transient has settled (junction initial temperatures briefly read wrong). | All circuits (CS: counted from coil opening) |
| <a id="r-kvfloor"></a>**R-KVFLOOR** | valve6 command floored at `Kv_shut`: the cooling gate opens at `PID.y < 0.7`, so `−PID.y·Kv_gain` is negative for 0 < y < 0.7 (negative Kv, reverse evaporator flow, 16k Newton failures in CS). | CS only — **PF and TF still lack it** |
| <a id="r-windup"></a>**R-WINDUP** | PI output limits set exactly at the downstream Kv clamp, so the integrator can't wind up past what the valve can use. | C-PRES, C-RV01 |

---

# Details

<a id="c-pres-b-details"></a>
## C-PRES-b details — PressureStabilizer (PF)

Moved from the former `docs/algorithms.md`. Written for
`PFCircuit.mo`; parameter names below are PF's.

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

---

<a id="c-rv01-power-cap-details"></a>
## C-RV01 power-cap (a) details — CirculatorPowerLimiter (PF)

Moved from the former `docs/algorithms.md`. Written for `PFCircuit.mo`;
parameter names below are PF's. **Current values differ from the
original write-up:** `enableCirculatorPowerOptimization` now defaults to
`false` and `P_shaftLimit` is 50 kW (was 40 kW); the reasoning below is
unchanged.

Original revision note (2026-09-03): replaced an earlier undocumented
flow-trim algorithm on the same valve (`valveRegulator`/`limiter`/
`valve1Command`) that only ran for the first `controlActivationDelay`
seconds, targeting `m_flow_startup`/`m_wanted`, then forced the valve
shut for the rest of every run.

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
