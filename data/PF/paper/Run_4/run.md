# Run_4 — Reference + PF-LOWTEMP (C-ISO off)

**Date:** 2026-11-04 (translate 13:11, simulation finished 13:36)
**Model:** `CoilLoopCompassU.PF.PFCircuit`
**Git commit:** `df928b2` (last commit touching `PFCircuit.mo`; HEAD `b3cc45d`). Same model as Runs 1–3.

**Settings changed against Run_1** (modifiers in `auto_translate_log.mos`, model file untouched): `enableLowTempCoolantOptimization = true`, `lowTempCoolantOptimizationThreshold = 80` K, `enableCoilIsolation = false` (never together, FIX-23). `lowTempCoolantOptimizationMinHotOthers` = 2 and `lowTempCoolantOptimizationMinDuration` = 10 s are the defaults.

**Translation/simulation:** `OK: translation successful` → `SUCCESSFUL simulation of CoilLoopCompassU.PF.PFCircuit`, `T = 1815` reached, CPU 1510 s, 1676 accepted steps, 103 state events, 6 model time events. Dassl, tolerance 1e-4.

**Solver warnings (a finding):** 27 × "Failed to solve nonlinear system using Newton solver" (`simulation.nonlinear[38]`), from t ≈ 1759.3 s to 1777.1 s; Dassl recovered and the run completed. Runs 1–3 had none. Look at what happens around t ≈ 1759 s (a PF-LOWTEMP close/reopen, `coilOpen[i]`, `lowTempPending[i]`).

## Algorithm settings (confirmed from `dsin.txt`)

| Algorithm | State | Parameter |
|---|---|---|
| C-SPEED-a | on | structural |
| C-PRES-b | on | `enablePressureControl = 1` |
| C-TEMP-SR / C-TEMP-SP-a | on | structural |
| C-ISO | **off** | `enableCoilIsolation = 0` |
| C-RV01 power-cap | off | `enableCirculatorPowerOptimization = 0` |
| PF-LOWTEMP | **on** | `enableLowTempCoolantOptimization = 1`, threshold 80, MinHotOthers 2, MinDuration 10 |
| C-OVERCOOL (archived) | off | both 0 |

## Files in this folder

- `Run_4.mat`, `dslog.txt`, `dsin.txt`, `auto_translate_log.mos`, `run.md`

## Extract (fill in from `Run_4.mat`)

Not yet extracted. Per `docs/pf/run_simulation.md` Run_4: does shutting an assembly below 80 K shorten the slowest assembly's cooldown (compare Run_3), does the shut assembly stay below the requirement while shut (check the wall), `coilOpen[i]` events and `lowTempPending[i]`. Plus the common extract list and "Outlet vs wall".
