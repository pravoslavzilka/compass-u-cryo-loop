# Run_4 — Reference + C-COLDSHUT + power mode (interaction)

**Date:** 2026-10-29
**Model:** `CoilLoopCompassU.CS.CSCircuit`
**Git commit:** `f9a7c70` (development). `CSCircuit.mo` at this commit is exactly what was translated and simulated for this run.

**Confirmed from `dsin.txt`** (the resolved set actually simulated): `enableCSPrep=1`, `enableCoilIsolation=1`, `shutWhenCold_CS[1..5]=1,1,1,1,1`, `rv01Goal=Power` (enum index 2), `enablePressureControl=1`.

## Algorithm settings (on/off)

Per `docs/cs/run_simulation.md` Run_4 — Reference (Run_1) with both C-COLDSHUT and RV01 power mode on together. Differs from Run_1 in both `shutWhenCold_CS` and `rv01Goal`.

| Algorithm | State | Parameter |
|---|---|---|
| C-SPEED-b (fixed speed, soft start) | on | structural |
| C-PRES-a (RV07/RV08 pressure PI) | on | `enablePressureControl = true` |
| C-RV01 flow mode | on (flow floor) | structural |
| **C-RV01 power mode** | **on** | `rv01Goal = RV01Goal.Power` |
| C-TEMP-SR | on | structural |
| C-TEMP-SP-b | on | structural (`wanted_temp`) |
| CS-PREP | on | `enableCSPrep = true` |
| CS-FLOW-SP | on | structural (`m_flow_set`) |
| C-ISO | on | `enableCoilIsolation = true` |
| **C-COLDSHUT** | **on** | `shutWhenCold_CS = {true,true,true,true,true}` |
| C-OVERCOOL (archived) | off | `enableOverCoolPrevention = enableOverCoolRecovery = false` |

StopTime = 1800 s, solver = Dassl.

## Question (per run_simulation.md)

Do the two secondary algorithms interact? Compare with Run_2 and Run_3.

## Translation/simulation

Same two-stage startup pattern seen in Run_3 — gated `PID_power` passes `T≈3.6s` cleanly, then the same recoverable nonlinear-solver failure at `T≈4.845855s` in `junction7`/`valve3`/`valve5` (`"Failed to solve nonlinear system using Newton solver... Solver will attempt to handle this problem"`), which the solver pushed through. Seeing the identical failure signature in both power-mode runs (Run_3 and Run_4) and in neither flow-mode run (Run_1, Run_2) supports the earlier hypothesis that it's specific to the power-mode code path, not a generic recompile artifact.

`SUCCESSFUL simulation of CoilLoopCompassU.CS.CSCircuit`, `T = 1800` reached, CPU 767 s, 76162 accepted steps, **28 state events** (vs. Run_3's 11, Run_2's 9, Run_1's 6 — C-COLDSHUT's extra per-coil latching adds events on top of power mode's).

## Result: no meaningful interaction — power mode dominates

| | Run_1 (ref) | Run_2 (+COLDSHUT) | Run_3 (+Power) | Run_4 (+COLDSHUT+Power) |
|---|---|---|---|---|
| Final `T_wallHotCooled` | 80.42 K | 80.43 K | 78.09 K | **78.09 K** |
| Final loop flow `m_flow_loop` | 0.172 kg/s | 0.156 kg/s | 0.187 kg/s | **0.189 kg/s** |
| Final `fan2ndOrder.P_shaft` | 18.96 kW | 18.13 kW | 20.18 kW | **20.36 kW** |
| Peak `P_shaft` | 18.96 kW | 18.94 kW | 22.88 kW | **22.88 kW** |
| Circulator energy (∫P dt) | 8.64 kWh | 8.64 kWh | 9.30 kWh | **9.29 kWh** |
| State events | 6 | 9 | 11 | **28** |

Run_4 is within noise of Run_3 on every thermal/energy metric (ΔT = 0.01 K, Δflow ≈ +1%, Δenergy ≈ −0.1%) — adding C-COLDSHUT on top of power mode changes essentially nothing about the outcome. This mirrors Run_2 vs. Run_1: C-COLDSHUT alone also made no meaningful difference there (80.43 K vs. 80.42 K). So across both flow and power mode, **C-COLDSHUT's redistribution strategy doesn't measurably shorten cooldown or lower the final temperature** — its only visible effect is structural: 28 state events vs. 11, from the extra per-coil cold-shut/release latching. (`T_wallHotLive` reads 0 at t=1800 in this run because every individual coil had already latched `coldShut` before the global `allReleased` — expected with `shutWhenCold_CS` all true, not a fault; `T_wallHotCooled` is the metric that matters here since it folds `allReleased` back in.)

## Files in this folder

- `Run_4.mat` — simulation result (renamed from `result.mat`)
- `dslog.txt` — solver log
- `dsin.txt` — resolved parameter/initial-condition set actually simulated
- `run.md` — this file

## Extract (remaining items, per run_simulation.md)

- Requirements: time for slowest coil ≤ 80 K (vs. 1800 s), max `T_object − T_coolant`, max coil inlet–outlet ΔT, max coil-to-coil spread — not yet extracted
- Cost: total LIN heat load, helium make-up/relief mass (RV07/RV08) — not yet extracted
- Numerics: CPU time 767 s, 76162 accepted steps, 28 state events (from `dslog.txt`)
