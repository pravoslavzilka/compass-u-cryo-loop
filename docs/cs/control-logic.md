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
|[CS-PREP](#cs-prep)|Startup coolant preparation through valve4|Primary|on|ATEKO S3.2, S3.4 (40 K at first contact)|
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

### CS-PREP — Startup coolant preparation

**Tier:** Primary. **Requirement:** ATEKO S3.2 (`T\_object − T\_coolant ≤ 40 K`) and S3.4 (at most 40 K inlet → outlet) from the first moment the
coils see coolant.
**Components:** `coolantReady`, `prepBandEnteredAt`, `coolantReadySince`
→ `bypassRegulatorOverCool` (valve4), `coilFlowing\[]` (coil valves),
`m\_flow\_set`.

The coils start at 137.5 K. Opening them straight onto a cold supply
breaks the 40 K rule (the 2026-10-07 run started the loop at 80 K and was
over the inlet–outlet limit for 31 s). So the loop first circulates with
the coils shut:

1. **Preparation.** All coil valves at `Kv\_shut`; valve4 at
`Kv\_prepBypass` = 1, about the coils' own resistance (\~10 bar at
0.17 kg/s), so the circulator runs near its design point and RV01
hardly moves at the hand-over. C-TEMP-SR brings the supply to
`T\_prepTarget = max(max(T\_wall\_max\_CS) − 40 K, 77 K)`. This is the
C-TEMP-SP rule over all coils, without reading the isolation latches
(reading them formed a Boolean algebraic loop with the algorithm).
The loop gas outside the coils already starts at `T\_loopInitial` =
137.5 − 40 = 97.5 K.
2. **In band:** `prepInBand` = t ≥ 10 s **and** |T\_supply − T\_prepTarget|
< `prepTempBand` (2 K) **and** `m\_flow\_loop` > `prepFlowFraction` (0.9)
× 0.17 kg/s. Entering the band stamps `prepBandEnteredAt`.
3. **Hand-over:** `coolantReady` latches when the band has held for
`prepHoldTime` (10 s), or at `prepMaxTime` (300 s) as a fallback. The
coils open (3 s ramp), valve4 goes to 0.001, `m\_flow\_set` switches to
per-channel flow.
4. `controlsActive` = `coolantReady` and 10 s since the coils opened
(`controlActivationDelay`) — the 88 m channels hold \~5 s of gas at
design flow. C-ISO, C-COLDSHUT and C-OVERCOOL only run after that.

`coolantReady` never resets: preparation runs once per simulation.

**Switch:** `enableCSPrep` (default `true`). `false` starts `coolantReady`
latched true, so the coils open at t = 0 as if no preparation had run —
used for the Run\_6 ablation in `run_simulation.md` (is CS-PREP needed to
meet the 40 K rule at first contact?).

<a id="cs-flow-sp"></a>

### CS-FLOW-SP — Coil-loop flow setpoint

**Tier:** Primary. **Requirement:** ATEKO S5.1 heat balance / Tab.5:
0.0214 kg/s per channel cools a channel in 30 min (S3.5: 15–30 min);
S6.5.2: 0.17 kg/s total minimal flow (8 channels).
**Output:** `m\_flow\_set` → `firstOrderMflowSet` (5 s) → C-RV01.

```
m\_flow\_set = 0.17 kg/s × ( coolantReady ? max(openChannelFraction, 1/8) : 1 )
openChannelFraction = Σ nChannels\_CS\[i] over coilFlowing\[i] / 8
```

During preparation the full 0.17 kg/s circulates through valve4. After
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
(`Kv\_RV01Max` = 5), start −0.5 (`Kv\_RV01Start`: \~0.1 kg/s back to
suction during preparation).
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
switching is a parameter change only. It also acts during CS-PREP (the
extra flow goes through valve4).

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
`T\_releaseAll` = 80 K. Gated by `controlsActive`.

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

