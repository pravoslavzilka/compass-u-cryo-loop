# TF circuit — simulation plan

Model: `CoilLoopCompassU.TF.TFCircuit`. Every run uses the same StopTime
(2100 s, as in the model's `experiment`), solver (Dassl), tolerance and
initial conditions; only the settings listed under each run change. The
requirements are judged at t = 1800 s, the 30 min design time
([requirements.md](requirements.md) §3); the remaining 300 s show whether the
end state holds.

Inputs to this plan: the requirements and their open points in
[requirements.md](requirements.md), the algorithms and their switches in
[control-logic.md](control-logic.md), the reading rules and the mandatory
outlet-vs-wall check in [../reading-simulations.md](../reading-simulations.md),
open problems in [../to-fix.md](../to-fix.md). Dymola runs only inside the VM,
so every run is started by the user; this plan does not assume Claude can
simulate or verify anything.

## Before the first run

1. **Decide the start-up problem first (FIX-01).** The coil busses start at
   137 K and the loop gas at 80 K, a 57 K step at first contact against
   ATEKO S3.2 and S3.4. If it is left as it is, every run exceeds the 40 K
   rule at the start, and the requirement table cannot separate algorithm
   effects from this. Two ways, both documented in to-fix.md:
   * **quick fix** (as for PF, 2026-11-04): loop gas `TInitial` 97 K
     (137 − 40) in all loop components; or
   * keep it, and report the first-contact violation as a fixed offset in
     every run.
   Recommended: apply the quick fix before Run_1, since it costs one edit and
   the series then tests the algorithms, not the start state.
2. **FIX-03 (valve6 negative Kv, no R-KVFLOOR).** PF and CS floor valve6 at
   `Kv_shut`; TF does not (16k Newton failures in CS). Apply the one-token
   fix before the series, or the numerics comparison between runs is
   polluted.
3. **Smoke test.** Run the Reference (Run_1) with `StopTime` = 300 s. Check:
   translation without new warnings; no "Failed to solve nonlinear system";
   RV07/RV08 Kv in the first 10 s (FIX-09: both opening together would be the
   start-up spike CS had) and for chatter later (FIX-02: `kPressurePID` =
   0.05 /Pa saturates the PI at 150 Pa error; CS needed 1.5e-6 /Pa); supply
   temperature against `wanted_temp` (valve5 open while the supply is 7 – 14 K
   high is the FIX-13 pattern seen earlier in TF). If RV07/RV08 ring, retune
   (FIX-02/FIX-06 together) **before** the series and repeat the smoke test.
4. **Compile every run from the same commit**, write the hash in `run.md`.
   Change only the parameters listed below between runs.
5. **Note, do not fix, before the series:** FIX-07 (no flow control: the coil
   flow is whatever the fixed-speed circulator gives), FIX-08 (no LIN supply
   cap on the evaporator), FIX-28 (the setpoint and release-all read the
   wall, which the plant cannot measure), FIX-05 (isolation close not gated
   by the activation delay).

## Reference and run matrix

Reference = Baseline + Primary tier on, Secondary tier off, Archived off.
**This differs from the shipped defaults**: the model ships with C-COLDSHUT on
(`shutWhenCold_TF = {false, false, true, true}`); the Reference turns it off,
as in CS Run_1, so that C-COLDSHUT can be tested as a change. Each run
changes one thing against Run_1, except the asymmetric pair (Runs 7 – 8).

| Run | Changes against Run_1 | Question |
|---|---|---|
| 1 | Reference | Does requirement-only control meet the requirements? |
| 2 | C-COLDSHUT on (upper limb) | Does shutting the faster upper limb at 80 K shorten the core + lower cooldown? |
| 3 | C-ISO off | Is isolation needed to keep the bus-to-bus spread ≤ 40 K? |
| 4 | `KvUpperLimb` = 100 (no static throttle) | Is the static throttle of the upper limb needed, or is it a stand-in for C-COLDSHUT? |
| 5 | Support structure connected | What does the 250 t structure do to the flow split and the coils? |
| 6 | Start at 116 K (ATEKO) | Does the A-vs-model start temperature change the verdict? |
| 7 | Asymmetric start (upper limb colder), C-COLDSHUT off | Which rule acts when the limbs really differ? |
| 8 | Asymmetric start, C-COLDSHUT on | Does C-COLDSHUT do its job when the upper limb finishes first? |
| 9 | C-PRES-a off | How much does the pressure PI do? (diagnostic) |

Algorithm state per run (`●` on, `○` off):

| Algorithm | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|
| C-SPEED-a (constant 200 Hz) | ● | ● | ● | ● | ● | ● | ● | ● | ● |
| C-PRES-a (`enablePressureControl`) | ● | ● | ● | ● | ● | ● | ● | ● | ○ |
| C-TEMP-SR (split range) | ● | ● | ● | ● | ● | ● | ● | ● | ● |
| C-TEMP-SP-b (hottest cooled wall − 40 K, ≥ 77 K) | ● | ● | ● | ● | ● | ● | ● | ● | ● |
| C-ISO (`enableCoilIsolation`) | ● | ● | ○ | ● | ● | ● | ● | ● | ● |
| C-COLDSHUT (`shutWhenCold_TF`) | ○ | ● | ○ | ○ | ○ | ○ | ○ | ● | ○ |
| C-OVERCOOL (archived) | ○ | ○ | ○ | ○ | ○ | ○ | ○ | ○ | ○ |

Not in TF, so not tested here: C-RV01 (no circulator bypass), flow setpoint,
startup preparation, C-PRES-b (see
[Runs that need code first](#runs-that-need-code-first)).

## Run_1 — Reference (requirement-only control)

* Settings: `shutWhenCold_TF = {false, false, false, false}`,
  `enableCoilIsolation = true`, `connectStructure = false`,
  `KvUpperLimb = 45`, `enablePressureControl = true`,
  `enableOverCoolPrevention = enableOverCoolRecovery = false`.
* Start: coil busses 137 K (TFCL1, TFUL1, TFUL2), Structure and loop gas
  80 K (or 97 K loop gas after the FIX-01 quick fix).

Look at: slowest bus ≤ 80 K by 1800 s (TFCL1, 9.2 m, is expected to be the
slowest); time with wall − supply > 40 K (TF measured 45 K, 917 s above 40 K
earlier, [to-fix.md](../to-fix.md) FIX-12); inlet − outlet ΔT; per-channel
flow of the core + lower (A: 5.17 g/s) and of the upper limb (7.5 vs 5.9 g/s
at Kv = 100 seen before); `P_shaft` (target ≈ 17 kW after the re-sizing,
ATEKO estimate 25 kW); discharge pressure against the 31 bara design limit
(30 barg).

## Run_2 — Reference + C-COLDSHUT

* **`shutWhenCold_TF = {false, false, true, true}`** (the shipped default).
* `T_coldShut` = `T_releaseAll` = 80 K, `KvUpperLimb` = 45.

Question: the upper limb (7.7 m) cools first; shutting it at 80 K gives its
flow to TFCL1. Does TFCL1 finish earlier than in Run_1? How long does the
shut upper limb sit before the release-all, and does it reheat (wall vs
frozen outlet, FIX-04: the cold shut-off re-freezes only while the bus
flows; not yet simulated)? Look at `coldShut[3..4]`, `allReleased`, and
whether the release happens at the right moment given that it reads the wall
(FIX-28).

## Run_3 — Reference without C-ISO

* **`enableCoilIsolation = false`**.

Question: is isolation needed to keep the spread between busses ≤ 40 K?
With a symmetric 137 K start the busses differ only by channel length (9.2
vs 7.7 m), mass and Kv, so the spread may never reach 40 K (the Structure is
excluded from isolation anyway). If so, the real test is Runs 7 – 8. Compare
cooldown time and state events.

## Run_4 — Reference with the upper limb un-throttled

* **`KvUpperLimb = 100`** (the library default), everything else as Run_1.

Question: `KvUpperLimb` = 45 is a plant-configuration tuning, introduced to
slow the upper limb so that core + lower gets more flow. With C-COLDSHUT off,
how much does the throttle matter? If Run_2 (C-COLDSHUT) achieves the same
gain, the throttle is the same job done statically, and the paper must say
which one is the control algorithm and which is plant data
([control-logic.md](control-logic.md) C-COLDSHUT, FIX-21).

## Run_5 — Support structure connected

* **`connectStructure = true`**, `Structure.valveKvNominal = 12`; everything
  else as Run_1. C-ISO is not allowed for the Structure
  (`isolationAllowed_TF[2] = false`), and it is outside `T_gas_out_max` and
  `T_wallHotCooled` unless connected.

Question: the Structure must cool in about 7 days at about 2 K/h, not in
30 min (T §5.6.3), so it should **not** hold the coils back. Does it
take only about 0.14 kg/s (11 % of the flow, the share it was throttled to),
does it pull `T_gas_out_max` or `T_wallHotCooled` down and so change the
supply setpoint for the coils (it enters `inGasOutMax_TF` when connected),
and is the structure's 80 K start meaningful against the 137 K coils? A
failure to translate or a solver issue at the reconnected branch (the old
`nonlinear[8]` problem was with valve-only isolation, now disconnected at
both ends) is itself a result.

## Run_6 — Start at 116 K (ATEKO value)

* **`TInitial` of TFCL1, TFUL1, TFUL2 = 116 K**; loop gas stays at 80 K
  (or 97 K after the FIX-01 quick fix: then use 80 K here, the step is
  116 − 80 = 36 K); everything else as Run_1.

Question: requirements §10 item 1: ATEKO's thermal balance gives 116 K for
TF, the model uses 137 K (the PF/CS number). How much cooldown margin does
the lower start give, and is the 40 K first-contact step now fine without
a prep phase (116 K against 80 K gas is a 36 K step)? Optionally add a
160 K run (thesis limit, T §5.1) if the 137 K result is close to 1800 s.

## Run_7 — Asymmetric start, C-COLDSHUT off

* Start: **TFCL1 137 K, TFUL1 and TFUL2 110 K**, loop gas as Run_1, C-ISO on,
  C-COLDSHUT off.

Reason (derived, [ASSUMED] copper heat capacity ≈ 0.25 kJ/kg/K between 80 and
140 K): the discharge deposits about 53.8 MJ in 7 808 kg of upper limb
(6.9 kJ/kg) against 196 MJ in 13 900 kg of core + lower (14.1 kJ/kg), so
after one shot the upper limb is about half as far above 80 K as the core:
80 + 6.9/0.25 ≈ 108 K against 80 + 14.1/0.25 ≈ 136 K (requirements §3). The
137 K for the core agrees with this; the upper limb should start near 110 K.
Check the heat capacity against `CopperOFHC_RRR30_Tdep` before quoting it.

Question: with a realistic asymmetry (a 27 K spread, inside the 35 K reopen
margin) no isolation should fire; this is the baseline for Run_8. How much
earlier than in Run_1 does the upper limb reach 80 K, and does it then keep
taking flow it no longer needs?

## Run_8 — Asymmetric start + C-COLDSHUT

* Same start as Run_7, **`shutWhenCold_TF = {false, false, true, true}`**.

Question: this is the situation C-COLDSHUT was built for. Does shutting the
upper limb at 80 K (about 5 – 10 min earlier than the core) shorten TFCL1's
cooldown compared with Run_7, and does the release-all return the limbs to
service before the end? Check the interplay with C-ISO: after the limbs shut
the spread (frozen limb 80 K, core above 120 K) is over 40 K, so
the frozen value must not be taken for a reopen/close decision (FIX-04,
R-FROZEN, `T_gas_out_compare_TF`).

## Run_9 — Reference without C-PRES-a (diagnostic)

* **`enablePressureControl = false`**.

Question: how far does the pressure fall as the gas cools, and does the
circulator or the cooldown suffer? It shows what RV07/RV08 are worth and
whether the pressure ever nears the 31 bara design limit without them. Use it
to judge Run_1's RV07/RV08 Kv traces and mass moved. Not for the paper.

---

## Runs that need code first

| Candidate | Needs | Why it matters |
|---|---|---|
| Startup preparation (C-PREP: probe, warm-up, flush) | code change, FIX-01 full variant | the only complete answer to ATEKO S3.2 at first contact; CS-PREP exists for CS |
| C-RV01 flow mode with a flow setpoint (5.17 g/s per channel) | code change, FIX-07 (check PFD 22179 for a TF_RV01) | the coil flow is whatever the fan gives; the upper limb receives about 3.6× its heat-balance need (requirements §10 item 3) |
| C-PRES-b (pulse + trim) | port from PF | only if C-PRES-a still rings after the FIX-02 retune |
| C-SPEED-b (soft start) | parameter swap, FIX-09 | only if RV07/RV08 open together in the first 10 s |
| LIN supply cap on the evaporator | code change, FIX-08 | the evaporator can currently deliver any duty |
| Support structure on its own schedule (7 days, 2 K/h) | separate model/run length | out of scope for 1800 s runs, requirements §10 item 8 |

Each becomes a new run `Run_10+` with the same extract list.

## Priority

* For the abstract: Run_1, Run_2, Run_3, Run_8.
* For the full paper: add Run_4, Run_5, Run_6, Run_7.
* Diagnostic only: Run_9.

## Extract from every run

Signals: `TFCL1.T_wall_max`, `TFUL1.T_wall_max`, `TFUL2.T_wall_max`,
`Structure.T_wall`; `T_gas_out_TF[i]` (outlets, what the controllers use);
buses' `T_gas_in`, `m_flow` (lumped over the channels: divide by 112 or 56
for per-channel flow).

* **Requirements** (judged at t = 1800 s):
  * slowest bus: time to outlet ≤ 80 K and wall ≤ 80 K (outlet alone is not
    enough, reading-simulations §5);
  * max wall − `sensor_T.sensorValue` and the time above 40 K;
  * max inlet − outlet ΔT per bus;
  * max bus-to-bus spread, from the outlets and from the walls;
  * discharge pressure against 31 bara; `P_shaft` against 25 kW (ATEKO
    estimate) and the 17 kW re-sizing target.
* **Cost:** ∫ `fan2ndOrder.P_shaft` dt, peak `P_shaft`, mass moved by
  RV07/RV08, LIN heat load (heat flow into `coldSurface`; no cap in the
  model, FIX-08).
* **Sequence:** `coilOpen[i]`, `coldShut[i]`, `allReleased` (time of each
  event), `wanted_temp` against `sensor_T.sensorValue`, per-channel flows of
  the core + lower and of the upper limb.
* **Numerics:** CPU time, accepted steps, state events, "Failed to solve
  nonlinear system" lines. Compare numerics only between runs of the same
  commit.
* **Outlet vs wall** (mandatory, reading-simulations §5): max wall − outlet
  offset while flowing, spread error, hottest-bus identity, decisions that
  would have differed. Known data point: TF's outlet ran "a few K" below the
  hottest wall cell. FIX-28 depends on this result.

### Pass / fail per run

| Item | Pass | Source |
|---|---|---|
| Core + lower and upper limb ≤ 80 K by 1800 s | yes | ATEKO S3.4 |
| Wall − supply | ≤ 40 K from the first contact (record exceedances and their time) | ATEKO S3.2 |
| Inlet − outlet ΔT | ≤ 40 K | ATEKO S3.4 |
| Bus-to-bus spread | ≤ 40 K | T §6.2 |
| Pressure | < 31 bara | ATEKO S6.5.3 |
| Simulation | `SUCCESSFUL`, no solver failures | — |

The support structure is not judged against 80 K at 1800 s (its target is
7 days, requirements §3); only its flow share and its influence on the coils
are read in Run_5.

## Saving

One folder per run, `data/TF/paper/Run_N/`: result `.mat` (renamed, not
`result.mat`), `dslog.txt`, `dsin.txt`, and `run.md` with git commit hash,
changed settings, the resolved switches confirmed from `dsin.txt`
(`shutWhenCold_TF`, `connectStructure`, `KvUpperLimb`, `enableCoilIsolation`,
`enablePressureControl`) and date. `TF/save_run.mos` archives the result under
`dymola-thermal-systems/data/TF/`; copy the files into `data/TF/paper/Run_N/`
afterwards. Save before the next translate, which overwrites
`TF/debugging/result.mat`.
