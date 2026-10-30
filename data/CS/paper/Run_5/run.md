# Run_5 — Reference without C-ISO

**Date:** 2026-10-29
**Model:** `CoilLoopCompassU.CS.CSCircuit`
**Git commit:** `a1ac967` (development). `CSCircuit.mo` at this commit is exactly what was translated and simulated for this run.

**Confirmed from `dsin.txt`** (the resolved set actually simulated): `enableCSPrep=1`, `enableCoilIsolation=0`, `shutWhenCold_CS[1..5]=0,0,0,0,0`, `rv01Goal=Flow` (enum index 1), `enablePressureControl=1`.

## Algorithm settings (on/off)

Per `docs/cs/run_simulation.md` Run_5 — Reference (Run_1) with C-ISO off. Only `enableCoilIsolation` differs from Run_1.

| Algorithm | State | Parameter |
|---|---|---|
| C-SPEED-b | on | structural |
| C-PRES-a | on | `enablePressureControl = true` |
| C-RV01 flow mode | on | structural |
| C-RV01 power mode | off | `rv01Goal = RV01Goal.Flow` |
| C-TEMP-SR | on | structural |
| C-TEMP-SP-b | on | structural (`wanted_temp`) |
| CS-PREP | on | `enableCSPrep = true` |
| CS-FLOW-SP | on | structural (`m_flow_set`) |
| **C-ISO** | **off** (changed from Run_1) | `enableCoilIsolation = false` |
| C-COLDSHUT | off | `shutWhenCold_CS = {false,false,false,false,false}` |
| C-OVERCOOL (archived) | off | `enableOverCoolPrevention = enableOverCoolRecovery = false` |

StopTime = 1800 s, solver = Dassl.

## Question (per run_simulation.md)

Is isolation needed to keep the coil-to-coil spread ≤ 40 K?

## Translation/simulation

`SUCCESSFUL simulation of CoilLoopCompassU.CS.CSCircuit`, `T = 1800` reached, CPU 155 s, 49201 accepted steps, 7 state events.

**Important correction to Run_4's `run.md`:** this run hit the identical recoverable Newton-solver failure at `T≈4.845855s` in `junction7`/`valve3`/`valve5` that Run_3/Run_4 showed — but Run_5 uses `rv01Goal=Flow`, the same as Run_1/Run_2, which never showed it. That falsifies the "power-mode-specific" hypothesis written into Run_4's `run.md`. The real dividing line is compiling before vs. after the `PID_power` gate fix (commit `13c9717`): Run_1/Run_2 predate it, Run_3/Run_4/Run_5 postdate it, regardless of `rv01Goal`. Logged as a new open item, FIX-27 in `docs/to-fix.md` — not yet root-caused, cost varies by run (this one recovered cheaply: 155 s vs. Run_1's 393 s baseline, vs. Run_3/4's 767-921 s).

## Result: C-ISO made no measurable difference, because spread never gets close to 40 K

Final state is essentially identical to Run_1:

| | Run_1 (C-ISO on) | Run_5 (C-ISO off) |
|---|---|---|
| Final `T_wallHotCooled` | 80.42 K | 80.42 K |
| Final loop flow `m_flow_loop` | 0.172 kg/s | 0.172 kg/s |
| Final `fan2ndOrder.P_shaft` | 18.96 kW | 18.96 kW |
| Circulator energy (∫P dt) | 8.639 kWh | 8.639 kWh |

The question this run actually targets — coil-to-coil spread — was computed directly from each coil's `T_wall_max` trajectory (`CS1`, `CS2U`, `CS2L`, `CS3U`, `CS3L`):

| | Run_1 (C-ISO on) | Run_5 (C-ISO off) |
|---|---|---|
| Max wall-temperature spread | 1.826 K at t=1051 s | 1.826 K at t=1051 s |
| Final wall-temperature spread | 0.612 K | 0.616 K |

**Answer: no — in this nominal, symmetric cooldown, the five coils never drift more than ~1.8 K apart from each other, nowhere near the 40 K margin `coilIsolationCloseMargin` is set to guard. C-ISO has nothing to do here**, so turning it off changes nothing measurable. This mirrors the C-COLDSHUT finding from Run_2/Run_4: none of CS's secondary algorithms show a benefit under these uniform, symmetric initial conditions — the coils are too similar to each other for isolation/shut-off/redistribution to matter. (A scenario with genuinely asymmetric coils — e.g. one coil starting warmer after an uneven plasma shot — would be a better test of what these algorithms are actually for; this run series uses uniform 137.5 K initial conditions for all five.)

## Files in this folder

- `Run_5.mat` — simulation result (renamed from `result.mat`)
- `dslog.txt` — solver log
- `dsin.txt` — resolved parameter/initial-condition set actually simulated
- `run.md` — this file

## Extract (remaining items, per run_simulation.md)

- Requirements: time for slowest coil ≤ 80 K (vs. 1800 s), max `T_object − T_coolant`, max coil inlet–outlet ΔT — not yet extracted (coil-to-coil spread extracted above)
- Cost: total LIN heat load, helium make-up/relief mass (RV07/RV08) — not yet extracted
- Numerics: CPU time 155 s, 49201 accepted steps, 7 state events (from `dslog.txt`)
