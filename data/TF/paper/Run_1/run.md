# TF Run_1 — Reference, Structure isolated

**Date:** 2026-11-04 (13:40)
**Model:** `CoilLoopCompassU.TF.TFCircuit`
**Git commit:** `cee7fbe` (last commit touching `TF/`; HEAD `b3cc45d`, no uncommitted changes in the TF `.mo` files). TF has none of the 2026-11-04 PF fixes: loop gas still starts at 80 K (FIX-01 not applied), valve6 has no Kv floor (FIX-03 not applied).

**Settings** (modifiers in `auto_translate_log.mos`, model file untouched): `connectStructure = false`, `shutWhenCold_TF = {false,false,false,false}` (the model default is `{false,false,true,true}`; the Reference turns C-COLDSHUT off), `enableCoilIsolation = true`, `KvUpperLimb = 45`, `enablePressureControl = true`. Start: busses 137 K, Structure and loop gas 80 K. Dassl, tolerance 1e-4, StopTime 2100 s.

This is the first of two TF runs. The second differs only by `connectStructure = true`.

**Translation/simulation:** `OK: translation successful` → `SUCCESSFUL simulation of CoilLoopCompassU.TF.TFCircuit`, `T = 2100` reached, CPU 14.9 s, 1282 accepted steps, 56 state events, 1 model time event.

**Solver warnings (findings):** 48 × "Failed to solve nonlinear system using Newton solver":
- 4 during initialization at t = 0 (`simulation.nonlinear[22]`, homotopy used; initialization still succeeded);
- 44 during integration (`simulation.nonlinear[10]`), t ≈ 1808 s to 2091 s, i.e. around the time the last bus nears 80 K. Dassl recovered each time.

## Settings confirmed from `dsin.txt`

`connectStructure = 0`, `shutWhenCold_TF[1..4] = 0`, `enableCoilIsolation = 1`, `KvUpperLimb = 45`, `enablePressureControl = 1`, `enableOverCoolPrevention = 0`.

## Files in this folder

- `Run_1.mat`, `dslog.txt`, `dsin.txt`, `auto_translate_log.mos`, `run.md`

## Extract (fill in from `Run_1.mat`)

Not yet extracted. Per `docs/tf/run_simulation.md` §Extract and Run_1: slowest bus to ≤ 80 K (outlet and wall; TFCL1 expected), wall − supply above 40 K and for how long, inlet − outlet ΔT, bus-to-bus spread, `P_shaft`, discharge pressure vs 31 bara, RV07/RV08 Kv in the first 10 s and for chatter (FIX-09, FIX-02), `coilOpen[i]`, and the mandatory "Outlet vs wall" section.
