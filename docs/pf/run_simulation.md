# PF circuit — simulation plan

Model: `CoilLoopCompassU.PF.PFCircuit`. Every run uses the same StopTime
(1815 s, as in the model's `experiment`), solver (Dassl), tolerance and
initial conditions; only the settings listed under each run change. All
requirement numbers are taken at t = 1800 s, the 30 min design time
([requirements.md](requirements.md) §3); the last 15 s are margin.

Inputs to this plan: the requirements and their open points in
[requirements.md](requirements.md), the algorithms and their switches in
[control-logic.md](control-logic.md), the reading rules and the mandatory
outlet-vs-wall check in [../reading-simulations.md](../reading-simulations.md),
open problems in [../to-fix.md](../to-fix.md). Dymola runs only inside the VM,
so every run is started by the user; this plan does not assume Claude can
simulate or verify anything.

## Before the first run

PF has not been simulated since the 2026-11-04 changes (loop gas 120 K,
`PID.y_start` = 0, valve6 Kv floor, FIX-01/11/03). The old PF results
(2026-09-03: 80 K crossed at 1771 s, flow 0.38 → 0.65 kg/s, `P_shaft`
33.7 → 58 kW, discharge pressure flat at 36.5 bar) are **not** comparable.

1. **Smoke test.** Run the Reference (Run_1) with `StopTime` = 300 s from a
   clean translate. Check: translation without new warnings (the earlier
   isolation fix left an `h_min` warning, see to-fix/migration notes);
   `dslog.txt` has no "Failed to solve nonlinear system"; heater power in
   the first 60 s is not the 5-unit start of the old `y_start`; valve6 Kv
   never negative; coil inlet − outlet ΔT in the first 60 s (the 120 K gas
   meeting 160 K coils is a 40 K step, at the limit of ATEKO S3.4).
2. **Compile every run from the same commit.** Write the hash in each
   `run.md`. If the model changes between runs, repeat the affected ones.
3. **Do not change anything else** in `PFCircuit.mo` between runs; all
   switches below are parameter modifiers.
4. **Known open items that affect interpretation** (do not fix before the
   series, only note in each `run.md`): FIX-12 (setpoint has no floor),
   FIX-13 (valve5 throttles late), FIX-25 (evaporator is one oversized cell,
   so supply control is optimistic), FIX-02 (pressure PI gain 0.05 /Pa: look
   at RV07/RV08 Kv traces), FIX-09 (no soft start: look at RV07/RV08 in the
   first 10 s), FIX-24 (coil valves at inlet only: look for solver trouble
   during isolation), FIX-23 (never enable C-ISO and PF-LOWTEMP together).

## Reference and run matrix

Reference = Baseline + Primary tier on, Secondary tier off, Archived off.
Each run changes one thing against Run_1, except the asymmetric-start pair
(Runs 5 – 6), which change the initial state for both members.

| Run | Changes against Run_1 | Question |
|---|---|---|
| 1 | Reference | Does requirement-only control meet the requirements? |
| 2 | C-RV01 power-cap on | Does the power cap cut energy, and at what cost in cooldown time? |
| 3 | C-ISO off | Is isolation needed to keep the coil-to-coil spread ≤ 40 K? |
| 4 | PF-LOWTEMP on, C-ISO off | Does absolute-threshold shut-off shorten the slowest coil's cooldown? |
| 5 | Asymmetric start, C-ISO on | Does C-ISO act when the coils really differ? |
| 6 | Asymmetric start, C-ISO off | What happens to the same state without C-ISO? |
| 7 | All coils start at 137 K | Does the A-vs-T start temperature change the verdict? |
| 8 | C-PRES-b off | How much does the pressure stabilizer do? (diagnostic) |
| 9 | C-ISO and PF-LOWTEMP both on | Does the FIX-23 conflict appear? (diagnostic, expected to fail) |

Algorithm state per run (`●` on, `○` off; the structural ones are always on):

| Algorithm | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|
| C-SPEED-a (constant 200 Hz) | ● | ● | ● | ● | ● | ● | ● | ● | ● |
| C-PRES-b (`enablePressureControl`) | ● | ● | ● | ● | ● | ● | ● | ○ | ● |
| C-TEMP-SR (split range) | ● | ● | ● | ● | ● | ● | ● | ● | ● |
| C-TEMP-SP-a (`T_gas_out_max` − 40 K) | ● | ● | ● | ● | ● | ● | ● | ● | ● |
| C-ISO (`enableCoilIsolation`) | ● | ● | ○ | ○ | ● | ○ | ● | ● | ● |
| C-RV01 power-cap (`enableCirculatorPowerOptimization`) | ○ | ● | ○ | ○ | ○ | ○ | ○ | ○ | ○ |
| PF-LOWTEMP (`enableLowTempCoolantOptimization`) | ○ | ○ | ○ | ● | ○ | ○ | ○ | ○ | ● |
| C-OVERCOOL (archived) | ○ | ○ | ○ | ○ | ○ | ○ | ○ | ○ | ○ |

Not in PF, so not tested here: C-COLDSHUT, startup preparation, C-RV01 flow
mode, CS-FLOW-SP (see [Runs that need code first](#runs-that-need-code-first)).

## Run_1 — Reference (requirement-only control)

* Settings: model defaults, i.e. `enableCoilIsolation = true`,
  `enableLowTempCoolantOptimization = false`,
  `enableCirculatorPowerOptimization = false`, `enablePressureControl = true`,
  `enableOverCoolPrevention = enableOverCoolRecovery = false`.
* Start: assemblies 160 K, loop gas 120 K.

Look at: slowest coil ≤ 80 K before 1800 s; time with
`T_object − T_coolant` > 40 K at the start (the 160 K coils against a supply
that has to come down from 120 K); coil inlet − outlet ΔT; which coil is
slowest (expected PF4, 90 m / 13 g/s per segment, see requirements §10
item 3); `P_shaft` against 50 kW; discharge pressure against the 41 bara
design limit.

## Run_2 — Reference + C-RV01 power-cap

* **`enableCirculatorPowerOptimization = true`** (`P_shaftLimit` = 50 kW,
  trigger `T_gas_out_max` ≤ 140 K).

Question: the old run exceeded the cap by 16 % at the cold end (58 kW).
Does PF_RV01 hold `P_shaft` near 50 kW, how much cooldown margin is lost
(Run_1 reference), and what is the energy saved? Look for FIX-26: the PI
integrates while its gate is shut, so a step of PF_RV01 right at the 140 K
trigger is expected if `P_shaft` was above the limit before that; record the
size of the step and the `P_shaft` overshoot.

## Run_3 — Reference without C-ISO

* **`enableCoilIsolation = false`**.

Question: is isolation needed to keep the coil-to-coil spread ≤ 40 K? With
a symmetric start the assemblies differ only by length, mass and flow, so
the spread may stay below 40 K even without isolation (CS Run_5 saw 1.8 K).
If so, Run_5/6 are the real test. Compare cooldown time of the slowest coil
and the number of state events (isolation costs events).

## Run_4 — Reference + PF-LOWTEMP (C-ISO off)

* **`enableLowTempCoolantOptimization = true`**,
  **`lowTempCoolantOptimizationThreshold = 80`** (K),
  `lowTempCoolantOptimizationMinHotOthers = 2`,
  `lowTempCoolantOptimizationMinDuration = 10` (defaults),
  **`enableCoilIsolation = false`** (never together with C-ISO, FIX-23).

Question: does shutting an assembly that is below 80 K while at least two
others are hotter shorten the cooldown of the slowest assembly (flow goes
to the others), and does the shut assembly stay below the requirement
(it reheats while shut; the reopen rule is "hottest < threshold")? Compare
with Run_3 (same, without PF-LOWTEMP). The threshold must be non-zero
together with the switch (control-logic.md, PF-LOWTEMP).

## Run_5 — Asymmetric start, C-ISO on

* Initial temperatures (modifiers on `PF…TInitial`): PF1U/PF1L 160 K,
  **PF2U/PF2L 100 K**, **PF3U/PF3L 130 K**, PF4U/PF4L 160 K. Loop gas 120 K
  as in Run_1.
* C-ISO on, everything else as Run_1.

Reason: the sources expect coils to differ ("impossible to predict which coil
will experience the worst-case thermal load", coils up to 80 K apart,
[requirements.md](requirements.md) §2.2). PF2 is 60 K colder than PF1/PF4,
over the 40 K close margin, PF3 30 K colder (inside the 35 K reopen margin),
so C-ISO should isolate PF2 and not PF3.

Question: does C-ISO act as described (PF2 shut at once after the 5 s
delay, reopened when `T_gas_out_max − T_frozen` < 35 K), and does the
coil-to-coil spread stay ≤ 40 K after the first contact? Look at
`coilOpen[3..4]`, `T_gas_out_compare_PF`, and whether the isolated pair
reheats (R-FROZEN hides it; check the wall, see below).

## Run_6 — Asymmetric start, C-ISO off

* Same initial temperatures as Run_5.
* **`enableCoilIsolation = false`**.

Question: how large does the spread get without C-ISO, and does PF2 overcool
(`T_object − T_coolant`, supply below the coil by more than 40 K is the
overcooling case the rule prevents)? Compare with Run_5.

## Run_7 — Start at 137 K (ATEKO value)

* All assemblies **`TInitial` = 137 K** (ATEKO Tab.4); loop gas 97 K
  (137 − 40, same 40 K first-contact step as Run_1).
* Everything else as Run_1.

Question: requirements §10 item 1: the thesis allows 160 K, ATEKO's heat
balance gives 137 K. Is the 1800 s margin still met at 160 K and how much
does 137 K gain? Also gives the cooldown time for the design case of the
flow sizing (0.23 kg/s was sized for 137 K).

## Run_8 — Reference without C-PRES-b (diagnostic)

* **`enablePressureControl = false`** (RV07 and RV08 forced shut).

Question: how far does the loop pressure fall as the gas cools (no helium
admitted), and does the circulator or the cooldown suffer? This quantifies
what the stabilizer is worth and whether the pressure ever nears the 41 bara
design limit without it. Not for the paper; use it to judge Run_1's RV07/RV08
duty and the helium mass they moved.

## Run_9 — C-ISO and PF-LOWTEMP together (diagnostic, expected to fail)

* `enableCoilIsolation = true`, **`enableLowTempCoolantOptimization = true`**,
  `lowTempCoolantOptimizationThreshold = 80`. Use StopTime 600 s.

Question: FIX-23: does the close/reopen loop at one instant appear
(PF-LOWTEMP closes a coil a few K below the hottest, C-ISO reopens it,
the elapsed dwell closes it again)? A failure or a very high event count here
is the evidence needed to fix FIX-23 (reset `lowTempPending[i]` on closing,
remember which rule closed the coil). Run only after Runs 1 – 6; skip if the
build is needed for something else.

---

## Runs that need code first

These algorithms cannot be switched on from the current model.

| Candidate | Needs | Why it matters |
|---|---|---|
| C-TEMP-SP-b (hottest cooled wall − 40 K, floor 77 K) | code change, FIX-12 | PF's setpoint has no floor; TF measured 45 K wall-to-supply with variant a. Also depends on FIX-28 (wall signal not on the plant) |
| Startup preparation (probe, warm-up, flush: CS-PREP → C-PREP) | code change, FIX-01 full variant | the 120 K quick fix leaves a 40 K step; CS-PREP is the only complete answer to ATEKO S3.2 |
| C-RV01 flow mode / flow setpoint (CS-FLOW-SP) | code change, no PF flow setpoint exists | the PF circulator delivers 0.38 → 0.65 kg/s against a 0.23 kg/s design flow (requirements §10 item 6) |
| valve5 throttle 2 / 50 (FIX-13) | parameter + code, small | supply drifts above setpoint while valve5 stays open |
| C-COLDSHUT in PF | code change, FIX-20 | closest PF equivalent today is Run_4 |

Each becomes a new run `Run_10+` with the same extract list; add it to the
matrix when it exists.

## Priority

* For the abstract: Run_1, Run_2, Run_3, Run_5, Run_6.
* For the full paper: add Run_4, Run_7.
* Diagnostic only: Run_8, Run_9.

## Extract from every run

Names are in the result file; PF has no hottest-wall-cell signal, so the wall
is `PFxx.ChannelN.T_wall` (one heat port of the channel's tube; check it is
the hottest cell before using it, unlike CS/TF).

* **Requirements** (judged at t = 1800 s):
  * slowest coil: time to `T_gas_out_PF[i]` ≤ 80 K and **wall** ≤ 80 K
    (outlet alone is not enough, reading-simulations §5);
  * max `T_object − T_coolant`: wall of each assembly − `sensor_T.sensorValue`,
    and the time spent above 40 K;
  * max inlet − outlet ΔT per channel (`ChannelN.T_gas_in − T_gas_out`);
  * max coil-to-coil spread, from the outlets (what C-ISO sees) and from the
    walls (ground truth);
  * discharge pressure peak against 41 bara; `P_shaft` against 20 kW (ATEKO
    estimate, expected to be exceeded, see requirements §10 item 7) and
    50 kW (model cap).
* **Cost:** ∫ `fan2ndOrder.P_shaft` dt, peak `P_shaft`, total mass moved by
  RV07/RV08 (∫ |m_flow|), LIN heat load (heat flow into `coldSurface`).
* **Sequence:** `coilOpen[i]` events (time, count), `lowTempPending[i]`,
  `PF_RV01` Kv, `wanted_temp` against `sensor_T.sensorValue`.
* **Numerics:** CPU time, accepted steps, state events, number of
  "Failed to solve nonlinear system" lines. Compare numerics only between
  runs compiled from the same commit.
* **Outlet vs wall** (mandatory, reading-simulations §5): max wall − outlet
  offset while flowing, spread error, hottest-coil identity, any decision
  that would have differed. Record it in `run.md` under "Outlet vs wall".

### Pass / fail per run

| Item | Pass | Source |
|---|---|---|
| Slowest coil ≤ 80 K by 1800 s | yes | ATEKO S3.4, T §2.8 |
| `T_object − T_coolant` | ≤ 40 K from the first contact (record any exceedance and its time) | ATEKO S3.2 |
| Inlet − outlet ΔT | ≤ 40 K | ATEKO S3.4 |
| Coil-to-coil spread | ≤ 40 K | T §6.2 |
| Pressure | < 41 bara | ATEKO S6.5.1 |
| Simulation | `SUCCESSFUL`, no solver failures | — |

A run that misses a pass criterion is a finding, not a failed run; the Reference
is expected to violate the first-contact criteria for a few seconds (§Run_1).

## Saving

One folder per run, `data/PF/paper/Run_N/`: result `.mat` (renamed, not
`result.mat`), `dslog.txt`, `dsin.txt`, and `run.md` with git commit hash,
changed settings, the resolved switches confirmed from `dsin.txt`, and date.
`PF/save_run.mos` archives the result under `dymola-thermal-systems/data/PF/`;
copy the files into `data/PF/paper/Run_N/` afterwards. Save before the next
translate, which overwrites `PF/debugging/result.mat`.
