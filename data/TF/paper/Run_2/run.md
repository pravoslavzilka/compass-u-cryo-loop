# TF Run_2 — Reference, Structure connected

**Date:** 2026-11-04 (translate 13:43, simulation finished 13:43:58)
**Model:** `CoilLoopCompassU.TF.TFCircuit`
**Git commit:** `cee7fbe` (last commit touching `TF/`; HEAD `b3cc45d`). Same model as TF Run_1; FIX-01 and FIX-03 not applied.

**Settings changed against TF Run_1** (modifier in `auto_translate_log.mos`): `connectStructure = true` (`Structure.valveKvNominal` = 12). Everything else as Run_1: `shutWhenCold_TF = {false,false,false,false}`, `enableCoilIsolation = true`, `KvUpperLimb = 45`, `enablePressureControl = true`. Dassl, tolerance 1e-4, StopTime 2100 s.

**Translation/simulation:** `OK: translation successful` → `SUCCESSFUL simulation of CoilLoopCompassU.TF.TFCircuit`, `T = 2100` reached, CPU 37.6 s, 2590 accepted steps, 50 state events, 1 model time event (Run_1: 14.9 s, 1282 steps, 56 events).

**Solver warnings:** 6 × "Failed to solve nonlinear system" during integration: 5 × `nonlinear[10]` and 1 × `nonlinear[5]` at t ≈ 1.03 s; the rest between about 1.03 s and 2012 s. No initialization failures (Run_1: 4 at t = 0 plus 44 during integration).

## Confirmed from the result file

`connectStructure` = 1, `kvTarget_TF[2]` = 12 and `coilOpen[2]` = 1 for the whole run. `Structure.portA1.m_flow` 0.17 to 0.24 kg/s (about 12 % of the flow); `Structure.T_wall` stays 80.0 to 80.4 K (starts at 80 K, so it barely cools).

## First comparison with Run_1 (quick read, not the full extract)

| | Run_1 (isolated) | Run_2 (open) |
|---|---|---|
| TFCL1 wall at 1800 s | 84.5 K | 87.5 K |
| TFCL1 wall ≤ 80 K | about 2070 s | not reached (81.1 K at 2100 s) |
| TFUL1/TFUL2 wall ≤ 80 K | 1491 s | 1579 s |
| Circulator energy to 2100 s | 11.7 kWh | 11.6 kWh |
| Peak `P_shaft` | 25.5 kW | 25.1 kW |
| Peak discharge pressure | 29.4 bar | 28.8 bar |

The open Structure takes flow from the coils without cooling much itself, and delays the coil cooldown by about 90 s (upper limbs) and more than 30 s (TFCL1). Outlet vs wall not yet checked; the wall − supply time above 40 K was not computed reliably.

## Files in this folder

- `Run_2.mat`, `dslog.txt`, `dsin.txt`, `auto_translate_log.mos`, `run.md`
