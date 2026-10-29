# Run_2 — Reference + C-COLDSHUT

**Date:** 2026-10-29
**Model:** `CoilLoopCompassU.CS.CSCircuit`
**Git commit:** `4cd3dc7` — "CS: set shutWhenCold_CS for Run_2, add Run_2 result" (development). `CSCircuit.mo` at this commit is exactly what was translated and simulated for this run.

**Translation/simulation:** `OK: translation successful` → `SUCCESSFUL simulation of CoilLoopCompassU.CS.CSCircuit`, `T = 1800` reached (`dslog.txt`), CPU 393 s, 6598 accepted steps, 9 state events, 3 model time events.

**Confirmed from `dsin.txt`** (the resolved set actually simulated): `enableCSPrep=1`, `enableCoilIsolation=1`, `shutWhenCold_CS[1..5]=1,1,1,1,1`, `rv01Goal=Flow`, `enablePressureControl=1`.

## Algorithm settings (on/off)

Per `docs/cs/run_simulation.md` Run_2 — Reference (Run_1) with C-COLDSHUT turned on. Only `shutWhenCold_CS` differs from Run_1.

| Algorithm | State | Parameter |
|---|---|---|
| C-SPEED-b (fixed speed, soft start) | on | structural (`n_fixed_Hz`, `T_softStart`) |
| C-PRES-a (RV07/RV08 pressure PI) | on | `enablePressureControl = true` |
| C-RV01 flow mode | on | structural (always active) |
| C-RV01 power mode | off | `rv01Goal = RV01Goal.Flow` |
| C-TEMP-SR (split-range supply temperature) | on | structural |
| C-TEMP-SP-b (40 K setpoint rule) | on | structural (`wanted_temp`) |
| CS-PREP (startup coolant preparation) | on | `enableCSPrep = true` |
| CS-FLOW-SP (flow setpoint per open channel) | on | structural (`m_flow_set`) |
| C-ISO (coil isolation) | on | `enableCoilIsolation = true` |
| C-COLDSHUT (shut-off at 80 K) | **on** (changed from Run_1) | `shutWhenCold_CS = {true,true,true,true,true}` |
| C-OVERCOOL (archived) | off | `enableOverCoolPrevention = enableOverCoolRecovery = false` |

StopTime = 1800 s, solver = Dassl (common to every run, per `run_simulation.md`).

## Question (per run_simulation.md)

Does redistributing flow shorten the cooldown of the slowest coil?

## Files in this folder

- `Run_2.mat` — simulation result (renamed from `result.mat`)
- `dslog.txt` — solver log (steps, events, CPU time)
- `dsin.txt` — resolved parameter/initial-condition set actually simulated
- `run.md` — this file

## Extract (fill in from `Run_2.mat`, compare against Run_1)

Not yet extracted — pending a pass over the result file:

- Requirements: time for slowest coil ≤ 80 K (vs. 1800 s), max `T_object − T_coolant`, max coil inlet–outlet ΔT, max coil-to-coil spread
- Cost: total circulator energy, peak `fan2ndOrder.P_shaft`, total LIN heat load, helium make-up/relief mass (RV07/RV08)
- Numerics: CPU time 393 s, 6598 accepted steps, 9 state events (vs. Run_1's 6 state events — from `dslog.txt`)
