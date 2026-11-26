# CS circuit — control logic

Model: `dymola-thermal-systems/CoilLoopCompassU/CS/CSCircuit.mo`.
Sizing and sources: [circulator-sizing.md](circulator-sizing.md).
Common algorithm definitions: [control-common.md](../control-common.md).
Tier rules: [README](../README.md#tiers).

Five coils (CS1, CS2U, CS2L, CS3U, CS3L; 8 channels in total, ATEKO
Tab.2) start at 137.5 K wall and gas after a shot (ATEKO Tab.5) and are
cooled to 80 K by helium at 82 bara.

## Summary

|ID|Algorithm|Tier|Default|Requirement / optimizes|
|-|-|-|-|-|
|[C-SPEED-b](../control-common.md#c-speed)|Fixed speed with soft start|Baseline|on|—|
|[C-PRES-a](../control-common.md#c-pres)|RV07/RV08 pressure PI|Baseline|on|—|
|[C-RV01](../control-common.md#c-rv01) flow mode|CS\_RV01 holds the coil-loop flow|Baseline|on|—|
|[C-RV01](../control-common.md#c-rv01) power mode|Power budget → extra flow, flow floor kept|Secondary|off (`rv01Goal = Flow`)|Circulator energy (ATEKO S3.2 idle: "circulation optimized to save power")|
|[C-TEMP-SR](../control-common.md#c-temp-sr)|Split-range supply temperature|Baseline|on|—|
|[C-TEMP-SP-b](../control-common.md#c-temp-sp)|`wanted\_temp` = hottest cooled wall − 40 K, ≥ 77 K|Primary|on|ATEKO S3.2, S3.4|
|[CS-PREP](#cs-prep)|Startup probe (small flow, read outlet), warm-up through valve4, flush|Primary|on|ATEKO S3.2, S3.4 (40 K once the coils see working coolant)|
|[CS-FLOW-SP](#cs-flow-sp)|Flow setpoint 0.0214 kg/s per open channel|Primary|on|ATEKO S5.1 / Tab.5, S6.5.2|
|[C-ISO](../control-common.md#c-iso)|Per-coil isolation 40 K / 35 K|Primary|on|ATEKO S6.1, S3.2; IPP coil-to-coil ≤ 40 K|
|[C-COLDSHUT](../control-common.md#c-coldshut)|Shut-off at 80 K + release-all|Secondary|on|Cooldown time of the slowest coil|
|[C-OVERCOOL](../control-common.md#c-overcool)|valve4 overcool state machine|Archived|off|Kept off by `enableOverCoolPrevention = enableOverCoolRecovery = false`; covered by C-TEMP-SP + CS-PREP|

## How the pieces connect

```
coil temperatures ──► wanted\_temp (C-TEMP-SP) ──► PID ──► heater / valve6 / valve5   (C-TEMP-SR)
        │
        ├──► coolantReady (CS-PREP) ─────────────┬──► valve4 (prep bypass)
        │                                        │
        └──► coilOpen, coldShut, allReleased ────┴──► coilFlowing\[] ──► CS\_V01..V05
             (C-ISO, C-COLDSHUT)                             │
                                                             └──► m\_flow\_set (CS-FLOW-SP) ──► PID\_RV01 ──► CS\_RV01 (C-RV01)
coilOpen / coldShut / allReleased ──► T\_wallHotCooled ──► wanted\_temp                       (feedback)
discharge pressure ──► PID\_pressure ──► RV07 / RV08 (C-PRES-a)                             (independent)
```

The coil valves are commanded by one expression that combines the
sequencing algorithms:

```
coilFlowing\[i] = coolantReady and (allReleased or (coilOpen\[i] and not coldShut\[i]))
Kv target      = valveKvNominal\[i] if coilFlowing\[i] else Kv\_shut  → firstOrderCoilKv\[i] (3 s) → KvValue\_in1
```

Inside each coil assembly that one signal drives the inlet ON/OFF valve
and, scaled by `outletKvRatio` in series with `KvFrictionTrim`, the
outlet valve (R-BOTHENDS).

Valve mapping (PFD 22178-3-R0): CS1 → CS\_V01, CS2U/CS2L → CS\_V02/V03,
CS3U/CS3L → CS\_V04/V05; valve5 = CS\_RV02; valve4 = coil bypass;
FM01 = `sensor\_m\_flow`.

\---

## CS-only algorithms

<a id="cs-prep"></a>

### CS-PREP — Startup coolant preparation (probe, warm-up, flush)

**Tier:** Primary. **Requirement:** ATEKO S3.2 (`T\_object − T\_coolant ≤ 40 K`) and S3.4 (at most 40 K inlet → outlet) once the
coils see the working coolant.
**Components:** `prepProbing`, `T\_probe`, `prepFlushing`, `sensor\_T\_header`, `coolantReady`, `prepBandEnteredAt`, `coolantReadySince`
→ `bypassRegulatorOverCool` (valve4), `coilFlowing\[]` (coil valves),
`m\_flow\_set`, `wanted\_temp`.

After a discharge the loop sits at 80 K (idle) and the coils at 137.5 K
(`T\_loopInitial` = 80 K since 2026-11-03; before that the loop started at
97.5 K, i.e. already prepared). The plant has no coil sensors, only the
outlet thermometers (thesis §6.2; `docs/reading-simulations.md` §2), so
the coil temperature is first *measured* with a small flow, then the
coolant is brought to a safe temperature:

1. **Probe** (`prepProbing`, 0 … `prepProbeTime` = 15 s). The coil valves open
(3 s valve lag) with a small flow: the flow setpoint is
`prepProbeFlowFraction` (0.1) × 0.17 kg/s, held by the normal flow regulator
(PID\_RV01), which starts at a **calculated** RV01 opening and only trims it:
`Kv\_RV01Probe = (m\_circStart − m\_probe) / (K\_valveRV01 · √(ρ · Δp))` =
(0.31 − 0.017) / (0.0086 · √(48 · 4.5)) ≈ 2.3 (RV01 passes the circulator
flow minus the probe flow; the valve law `m = K·Kv·√(ρ·Δp)` fits the
2026-11-03 run within 2 %; the circulator flow, density and Δp are assumed
from that run). The flow setpoint also starts at the probe value. The
PI alone had reached only Kv 1.75 after 15 s and left 0.14 kg/s through the
coils instead of 0.017. valve4 is shut.
The gas passing a coil takes the coil's temperature, so the outlet reads
the coil. At the end of the probe the hottest outlet is latched:
`T\_probe = max(T\_gas\_out\_CS)`, and the coils shut again. `wanted\_temp`
holds `T\_loopInitial` (80 K) meanwhile.
2. **Warm-up** (coils shut, valve4 at `Kv\_prepBypass` = 1, the full 0.17 kg/s
through valve4, so the circulator runs near its design point).
The supply is heated by the normal split-range control (C-TEMP-SR) to
`T\_prepAim = T\_prepTarget + prepAimOffset` (+5 K), with
`T\_prepTarget = max(T\_probe − 40 K, 77 K)`.
3. **Release band.** `prepInBand` = probe finished **and**
`T\_prepTarget ≤ T\_header ≤ T\_prepTarget + prepWarmBand` (+10 K) **and**
`m\_flow\_loop` > `prepFlowFraction` (0.9) × 0.17 kg/s. `T\_header` is
`sensor\_T\_header`, the gas entering the coil supply header (tee
`junction21`, coil side); the supply control itself still reads `sensor\_T`
(`junction7`). Not too cold (that would break the 40 K rule); a bit warmer
is fine and needs no precision. Entering the band stamps `prepBandEnteredAt`.
4. **Flush** (`prepFlushing`, `prepFlushTime` = 60 s). When the band has held
for `prepHoldTime` (10 s) the coils open with `prepFlushFlowFraction` (0.3) ×
0.17 kg/s, held by PID\_RV01, valve4 shut. The dead-end header (4 × 10 l) and
the coil feed lines still hold gas from the idle loop temperature, because
warm-up flows only through the tee and valve4; the flush pushes that gas
through the coils with warm supply gas behind it. (2026-11-03 run without a
flush: the coil inlet stayed at 81–94 K for 80–180 s after the release while
the supply sensor read 100–108 K.)
5. **Hand-over:** at the end of the flush, or at `prepMaxTime` (300 s) from any
phase as a fallback, `coolantReady` latches. The coils open fully (3 s ramp),
valve4 goes to 0.001, `m\_flow\_set` switches to per-channel flow, and
`wanted\_temp` becomes the normal C-TEMP-SP-b value (hottest cooled wall −
40 K, ≥ 77 K), so the PID takes the supply down to the 40 K difference as
before.
6. `controlsActive` = `coolantReady` and 10 s since the coils opened
(`controlActivationDelay`) — the 88 m channels hold \~5 s of gas at
design flow. C-ISO, C-COLDSHUT and C-OVERCOOL only run after that.

`coolantReady` never resets: preparation runs once per simulation.

**Known cost of the probe:** while the 80 K loop gas passes the 137.5 K
coils, the coil gas inlet–outlet difference is ~57 K for a few seconds
(over S3.4's 40 K), and the supply is 57 K below the wall. It is a
small flow for 15 s, the same measurement the real plant makes (thesis
§6.2), but check the result: time with inlet–outlet > 40 K during the
probe, and how far the walls cool in those seconds.

**Signals:** the probe uses the **outlet** temperature, as the real plant
must; the release target no longer reads the wall (this closes the
CS-PREP part of FIX-28). The setpoint after the hand-over (C-TEMP-SP-b)
still reads the wall.

**Switch:** `enableCSPrep` (default `true`). `false` starts `coolantReady`
latched true and `prepProbing` false, so the coils open at t = 0 with the
loop at `T\_loopInitial` as if no preparation had run — used for the
Run\_6 ablation in `run_simulation.md`.

**Revision history:** 2026-11-03 rewritten: probe + warm-up replaces
"warm the supply to wall − 40 K with the coils shut"; `T\_loopInitial`
97.5 K → 80 K; `prepTempBand` (2 K band) replaced by
`prepAimOffset`/`prepWarmBand`. Same day, after the first run: the probe
flow starts at a calculated RV01 opening instead of 0.5, release test
moved to the coil header (`sensor\_T\_header`), a 60 s flush phase added
before the hand-over, and the supply tee `junction21` reduced from 200 l to
10 l (it was a 10 kg mixing volume copied from TF/PF with no stated basis).
Not yet simulated.

<a id="cs-flow-sp"></a>

### CS-FLOW-SP — Coil-loop flow setpoint

**Tier:** Primary. **Requirement:** ATEKO S5.1 heat balance / Tab.5:
0.0214 kg/s per channel cools a channel in 30 min (S3.5: 15–30 min);
S6.5.2: 0.17 kg/s total minimal flow (8 channels).
**Output:** `m\_flow\_set` → `firstOrderMflowSet` (5 s) → C-RV01.

```
m\_flow\_set = 0.17 kg/s × ( prepProbing ? 0.1 : coolantReady ? max(openChannelFraction, 1/8) : 1 )
openChannelFraction = Σ nChannels\_CS\[i] over coilFlowing\[i] / 8
```

During the CS-PREP probe 10 % of it goes through the coils, then during warm-up the full 0.17 kg/s circulates through valve4. After
it, each open channel gets 0.0214 kg/s and the surplus of the
fixed-speed circulator goes back to suction through CS\_RV01. At least
one channel's worth always circulates.

\---

## Common algorithms — what differs in CS

### C-SPEED-b

`n\_start\_Hz` = 155 Hz → `n\_fixed\_Hz` = `n\_nominal\_Hz` = 200 Hz, first
order `T\_softStart` = 10 s. 155 Hz is where the 2026-10-08 run settled for
0.17 kg/s through valve4; starting at 200 Hz gave 21 bar, 26 kW and
0.34 kg/s at t = 0 and opened RV07 and RV08 together.

### C-PRES-a

* **Node:** `junction22` hangs off `junction1`, the evaporator inlet tee
after the heater — the **circulator discharge** pressure, same node as
PF and TF.
* `pressureSetpoint` = 82 bara (81 barg at the CC outlet, ATEKO S6.5.2);
reservoirs 88.5 / 75.5 bara (×1.08 / ×0.92); `TStorageReservoirs` 80 K.
* `kPressurePID` = 1.5e-6 /Pa (TF/PF: 0.05), `TiPressurePID` = 30 s,
`KvGainMakeup/Relief` = 2, `KvMakeupMax/ReliefMax` = 15, y ∈ ±7.5,
`pressureValveRampTime` = 2 s. The gain was cut from 0.05 because 150 Pa
of error saturated the PI and the discharge pressure rang at several
Hz, costing \~125 solver steps per simulated second (2026-10-08).

### C-RV01 — flow mode (implemented)

* `PID\_RV01`: PI, k = 3 Kv per kg/s, Ti = 10 s, y ∈ \[−5, 0]
(`Kv\_RV01Max` = 5), start −`Kv\_RV01Start`: the calculated probe opening
≈ 2.3 with CS-PREP (see CS-PREP step 1), −0.5 (\~0.1 kg/s back to suction)
without it.
* `firstOrderRV01`: 2 s actuator lag.
* `u\_m = m\_flow\_loop = Heater.portA.m\_flow`, downstream of the RV01 tee.
FM01 (`sensor\_m\_flow`) sits upstream and reads loop + bypass; it is
monitoring only. The real plant needs a meter at the loop side, or
FM01 minus an RV01 flow estimate.
* At the cold end RV01 returns \~0.12 kg/s.

### C-RV01 — power mode

Selected by `rv01Goal = RV01Goal.Power` (default `Flow`). `PID\_power`
(PI, `u\_s = P\_shaftLimit`, `u\_m = fan2ndOrder.P\_shaft`, y ∈ \[0,
`dm\_flowPowerMax`]) adds its output to the flow target in
`massFlowSetpoint`; `PID\_RV01` and the `m\_flow\_set` floor are unchanged.
PID\_power runs in both modes but is only read in power mode, so
switching is a parameter change only.

**Gated by `controlsActive`:** `PID\_power.u\_s` is held equal to `u\_m`
(zero error, output pinned near 0, no integrator wind-up) until
`controlsActive` -- i.e. not during CS-PREP, and not until
`controlActivationDelay` after the coils open. Added 2026-10-29 after
the first power-mode run (Run\_3) stalled DASSL at the T\~3.6 s startup
transient: with no gate, `PID\_power` saturated to `dm\_flowPowerMax`
within the first simulated second (circulator still on its soft-start
ramp, `P\_shaft` near zero vs `P\_shaftLimit` = 20 kW), demanding flow
the ramping circulator couldn't deliver. See FIX-14 in `to-fix.md`.

|Parameter|Value|Status|
|-|-|-|
|`P\_shaftLimit`|20 kW|ASSUMED: flow mode runs at \~16–18 kW|
|`dm\_flowPowerMax`|0.1 kg/s|ASSUMED: circulator gives \~0.29 kg/s at the cold end|
|`k\_powerPID`|6e-6 kg/s per W|ASSUMED: \~5 kW per 0.1 kg/s → outer loop gain \~0.3|
|`Ti\_powerPID`|60 s|6× the flow PI's Ti|

All four need a power-mode run to confirm.

### C-TEMP-SR

All valve Kv values are TF's × `kvScale` = 0.05 (CS flow is \~1/19 of
TF's), so the valve pressure drops and the tuned split-range behaviour
carry over:

|Parameter|CS|TF / PF|
|-|-|-|
|`Kv\_cool\_max` (valve6)|250|5000|
|`Kv\_gain` (valve6 per unit −y)|5|100|
|`Kv\_bypassOpen` (valve5)|25|500|
|`bypassKvGain`|2.5 (shut at y = −10)|TF 50, PF 10|
|`bypass\_limit`|2|TF 2, PF 10|
|valve3 (fixed)|200|4000|
|`heater\_gain`|100 W per unit (max 6 kW)|100|
|`PID`|k 0.12, Ti 12 s, y ±60, `y\_start` 0|same; PF `y\_start` 5|

valve6 is floored at `Kv\_shut` (R-KVFLOOR). ATEKO S6.1 notes the CS
heater may not be needed at all (compression heat warms the loop
\~30 °C/h); it matters for warm-up only.

### C-TEMP-SP-b

`T\_wallHotCooled` counts coils that are `allReleased or (coilOpen and not coldShut)`. `T\_supplyFloor` = 77 K. During preparation CS-PREP uses
its own `T\_prepTarget` (see above).

### C-ISO

All five coils. Margins 40 K close / 35 K reopen. Gated by
`controlsActive` (CS-PREP), not just by time. `T\_cmp\[i]` =
`T\_wall\_max\_CS\[i]` while not `coolantReady` (shut coils have no
meaningful outlet), the live outlet while flowing, the frozen value
while shut.

### C-COLDSHUT

All five coils opted in (`shutWhenCold\_CS` = true × 5). `T\_coldShut` =
`T\_releaseAll` = 80 K. Gated by `controlsActive`. Since 2026-11-03 the cold
shut-off re-freezes `T\_gas\_out\_frozen[i]` only while the coil flows
(`coilFlowing[i]`), so a coil already isolated by C-ISO keeps its R-FROZEN
value (FIX-04, not yet simulated).

### C-OVERCOOL (archived)

Code unchanged from TF/PF, gated by `controlsActive`; when open, valve4
goes to `Kv\_coilBypassOpen` = 250. The same valve4 is used by CS-PREP,
whose command takes priority (`not coolantReady` is checked first).

\---

## Robustness measures used

R-HYST, R-SMOOTH (all Kv commands start from their own initial value),
R-FROZEN, R-BOTHENDS (all five coils), R-EVAPDECOUPLE (valve3),
R-ACTDELAY (from coil opening), R-KVFLOOR, R-WINDUP (PID\_pressure,
PID\_RV01). See [control-common.md](../control-common.md#robustness-measures-not-tiered).

## Plant-model assumptions (not control)

* **LIN supply cap:** each evaporator cell takes `G\_LINcell·(T\_wall − 77 K)` (nucleate boiling, `alpha\_LIN` = 3000 W/m²K assumed); the total
is scaled down to `Q\_LINmax` = 60 kW (0.27 kg/s LIN, ATEKO S7.2).
* **Evaporator:** 25 × 12 mm × 8 m (study: 5 m), enlarged 2026-10-09 so
the supply can follow `wanted\_temp` at full duty.

