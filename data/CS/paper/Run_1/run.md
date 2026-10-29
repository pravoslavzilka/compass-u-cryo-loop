# Run_1 — Reference (requirement-only control)

**Date:** 2026-10-29
**Model:** `CoilLoopCompassU.CS.CSCircuit`
**Git commit (HEAD):** `c0bf7686b154cde6d2ed0ac1aad09c056177f3a7` (2026-10-22) — **working tree was dirty**, see below. Commit before the next run if an exact-reproduction hash is needed.

**Uncommitted changes present at simulation time** (`dymola-thermal-systems/CoilLoopCompassU/CS/CSCircuit.mo`):
- Added `enableCSPrep` (new master switch for CS-PREP, default `true`).
- `shutWhenCold_CS` default changed from `fill(true, nCS)` to `fill(false, nCS)`.
- `coolantReady` start value and `firstOrder3.y_start` updated to respect `enableCSPrep`.
- Also uncommitted: `docs/cs/control-logic.md` (documents `enableCSPrep`), new `docs/cs/run_simulation.md`.

**Translation/simulation:** `OK: translation successful` → `SUCCESSFUL simulation of CoilLoopCompassU.CS.CSCircuit`, `T = 1800` reached (`dslog.txt`), CPU 393 s, 6551 accepted steps, 6 state events, 3 model time events.

## Algorithm settings (on/off)

Per `docs/cs/run_simulation.md` Run_1 — the reference configuration all other runs are compared against.

| Algorithm | State | Parameter |
|---|---|---|
| C-SPEED-b (fixed speed, soft start) | on | structural (`n_fixed_Hz`, `T_softStart`) |
| C-PRES-a (RV07/RV08 pressure PI) | **on** | `enablePressureControl = true` |
| C-RV01 flow mode | on | structural (always active) |
| C-RV01 power mode | **off** | `rv01Goal = RV01Goal.Flow` |
| C-TEMP-SR (split-range supply temperature) | on | structural |
| C-TEMP-SP-b (40 K setpoint rule) | on | structural (`wanted_temp`) |
| CS-PREP (startup coolant preparation) | **on** | `enableCSPrep = true` |
| CS-FLOW-SP (flow setpoint per open channel) | on | structural (`m_flow_set`) |
| C-ISO (coil isolation) | **on** | `enableCoilIsolation = true` |
| C-COLDSHUT (shut-off at 80 K) | **off** | `shutWhenCold_CS = {false,false,false,false,false}` |
| C-OVERCOOL (archived) | **off** | `enableOverCoolPrevention = enableOverCoolRecovery = false` |

StopTime = 1800 s, solver = Dassl (common to every run, per `run_simulation.md`).

## Files in this folder

- `Run_1.mat` — simulation result (renamed from `result.mat`)
- `dslog.txt` — solver log (steps, events, CPU time)
- `dsin.txt` — resolved parameter/initial-condition set actually simulated
- `run.md` — this file

## Extract (fill in from `Run_1.mat`)

Not yet extracted — pending a pass over the result file:

- Requirements: time for slowest coil ≤ 80 K (vs. 1800 s), max `T_object − T_coolant`, max coil inlet–outlet ΔT, max coil-to-coil spread
- Cost: total circulator energy, peak `fan2ndOrder.P_shaft`, total LIN heat load, helium make-up/relief mass (RV07/RV08)
- Numerics: CPU time 393 s, 6551 accepted steps, 6 state events (from `dslog.txt`)
