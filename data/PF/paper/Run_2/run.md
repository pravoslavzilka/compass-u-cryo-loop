# Run_2 — Reference + C-RV01 power-cap

**Date:** 2026-11-04 (translate 12:12, simulation finished 12:30)
**Model:** `CoilLoopCompassU.PF.PFCircuit`
**Git commit:** `df928b2` (last commit touching `PFCircuit.mo`; HEAD `b3cc45d`). Same model as Run_1.

**Settings changed against Run_1:** `enableCirculatorPowerOptimization = true` (set as a modifier in `auto_translate_log.mos`, model file untouched). `P_shaftLimit` = 50000 W, trigger `valve1PowerLimitTriggerTemp` = 140 K, defaults.

**Translation/simulation:** `OK: translation successful` → `SUCCESSFUL simulation of CoilLoopCompassU.PF.PFCircuit`, `T = 1815` reached, CPU 1080 s, 1305 accepted steps, 74 state events, 1 model time event (Run_1: 779 s, 1062 steps, 60 events). Dassl, tolerance 1e-4. The script used is saved here as `auto_translate_log.mos`.

## Algorithm settings (confirmed from `dsin.txt`)

| Algorithm | State | Parameter |
|---|---|---|
| C-SPEED-a | on | structural |
| C-PRES-b | on | `enablePressureControl = 1` |
| C-TEMP-SR / C-TEMP-SP-a | on | structural |
| C-ISO | on | `enableCoilIsolation = 1` |
| C-RV01 power-cap | **on** | `enableCirculatorPowerOptimization = 1` |
| PF-LOWTEMP | off | `enableLowTempCoolantOptimization = 0` |
| C-OVERCOOL (archived) | off | both 0 |

## Files in this folder

- `Run_2.mat` — result (renamed from `result.mat`)
- `dslog.txt` — solver log (from `dslog_simulate.txt`)
- `dsin.txt` — resolved parameters
- `auto_translate_log.mos` — the script as run
- `run.md` — this file

## Extract (fill in from `Run_2.mat`)

Not yet extracted. Per `docs/pf/run_simulation.md` Run_2: does PF_RV01 hold `P_shaft` near 50 kW; cooldown margin lost against Run_1; energy saved (∫ `P_shaft` dt); size of the PF_RV01 step at the 140 K trigger and the `P_shaft` overshoot (FIX-26). Plus the common extract list and the mandatory "Outlet vs wall" section.
