# Run_3 — Reference without C-ISO

**Date:** 2026-11-04 (translate 12:41, simulation finished 12:53)
**Model:** `CoilLoopCompassU.PF.PFCircuit`
**Git commit:** `df928b2` (last commit touching `PFCircuit.mo`; HEAD `b3cc45d`). Same model as Run_1/2.

**Settings changed against Run_1:** `enableCoilIsolation = false` (modifier in `auto_translate_log.mos`, model file untouched).

**Translation/simulation:** `OK: translation successful` → `SUCCESSFUL simulation of CoilLoopCompassU.PF.PFCircuit`, `T = 1815` reached, CPU 734 s, 935 accepted steps, 54 state events, 0 model time events (Run_1: 779 s, 1062 steps, 60 events). Dassl, tolerance 1e-4. Script saved here as `auto_translate_log.mos`.

## Algorithm settings (confirmed from `dsin.txt`)

| Algorithm | State | Parameter |
|---|---|---|
| C-SPEED-a | on | structural |
| C-PRES-b | on | `enablePressureControl = 1` |
| C-TEMP-SR / C-TEMP-SP-a | on | structural |
| C-ISO | **off** | `enableCoilIsolation = 0` |
| C-RV01 power-cap | off | `enableCirculatorPowerOptimization = 0` |
| PF-LOWTEMP | off | `enableLowTempCoolantOptimization = 0`, threshold 0 |
| C-OVERCOOL (archived) | off | both 0 |

## Files in this folder

- `Run_3.mat`, `dslog.txt`, `dsin.txt`, `auto_translate_log.mos`, `run.md`

## Extract (fill in from `Run_3.mat`)

Not yet extracted. Per `docs/pf/run_simulation.md` Run_3: is the coil-to-coil spread ≤ 40 K without isolation (outlet and wall spread); cooldown time of the slowest coil vs Run_1; state-event count (54 vs 60 in Run_1). Plus the common extract list and "Outlet vs wall".
