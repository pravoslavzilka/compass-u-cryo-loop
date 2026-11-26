# Run_1 — Reference (requirement-only control)

**Date:** 2026-11-04 (translate 11:34, simulation finished 11:48)
**Model:** `CoilLoopCompassU.PF.PFCircuit`
**Git commit:** `df928b2` — "PF: tag algorithm IDs, header comment, correct stale docstrings (FIX-18)" (last commit touching `PFCircuit.mo`; working tree clean for the model, HEAD at the time `b3cc45d`). Includes the 2026-11-04 changes: loop gas 120 K, `PID.y_start` = 0, valve6 Kv floor, FIX-01/11/03.

**Settings changed against model defaults:** none (this is the default configuration).

**Translation/simulation:** `OK: translation successful` → `SUCCESSFUL simulation of CoilLoopCompassU.PF.PFCircuit`, `T = 1815` reached, CPU 779 s, 1062 accepted steps, 60 state events, 1 model time event, no "Failed to solve nonlinear system" lines in `dslog.txt`. Run by `PF/auto_translate_log.mos`: Dassl, **tolerance 1e-4**, StopTime 1815 s (all runs use the same).

## Algorithm settings (confirmed from `dsin.txt`)

| Algorithm | State | Parameter |
|---|---|---|
| C-SPEED-a (constant 200 Hz) | on | structural |
| C-PRES-b | **on** | `enablePressureControl = 1` |
| C-TEMP-SR (split range) | on | structural |
| C-TEMP-SP-a (`T_gas_out_max` − 40 K) | on | structural (`tempMargin` = 40) |
| C-ISO | **on** | `enableCoilIsolation = 1` (close 40 K / reopen 35 K) |
| C-RV01 power-cap | **off** | `enableCirculatorPowerOptimization = 0` (`P_shaftLimit` = 50000 W) |
| PF-LOWTEMP | **off** | `enableLowTempCoolantOptimization = 0`, threshold 0 |
| C-OVERCOOL (archived) | **off** | `enableOverCoolPrevention = enableOverCoolRecovery = 0` |

Start: assemblies 160 K, loop gas 120 K.

## Files in this folder

- `Run_1.mat` — simulation result (renamed from `result.mat`)
- `dslog.txt` — solver log (from `dslog_simulate.txt`)
- `dsin.txt` — resolved parameter/initial-condition set actually simulated
- `run.md` — this file

## Extract (fill in from `Run_1.mat`)

Not yet extracted. List in `docs/pf/run_simulation.md` §Extract, including the mandatory "Outlet vs wall" section. Smoke-test items (valve6 Kv never negative, first-60 s heater power, first-contact ΔT) are also still to be read from the result.

Numerics (from `dslog.txt`): CPU 779 s, 1062 accepted steps, 60 state events.

Known open items to note when interpreting: FIX-12, FIX-13, FIX-25, FIX-02, FIX-09, FIX-24, FIX-23.
