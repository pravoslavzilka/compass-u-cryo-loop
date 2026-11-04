# Run_6 — Reference without CS-PREP

**Date:** 2026-11-03
**Model:** `CoilLoopCompassU.CS.CSCircuit`
**Git commit:** `cee7fbe` (development; `CSCircuit.mo` is unchanged at `3d3ef5c`). Built after the FIX-04 guard (`09a9199`) and the `sensor_p_suction` → `sensor_p_discharge` rename (`cee7fbe`); `enableCSPrep = false` was set in `abc10ec`. The same configuration was simulated on 2026-10-30 (before those two commits) with identical step counts, so neither change affects this run.

**Confirmed from `dsin.txt`** (the resolved set actually simulated): `enableCSPrep=0`, `enableCoilIsolation=1`, `shutWhenCold_CS[1..5]=0,0,0,0,0`, `rv01Goal=Flow` (enum index 1), `enablePressureControl=1`.

## Algorithm settings (on/off)

Per `docs/cs/run_simulation.md` Run_6 — Reference (Run_1) with CS-PREP off. Only `enableCSPrep` differs from Run_1.

| Algorithm | State | Parameter |
|---|---|---|
| C-SPEED-b | on | structural |
| C-PRES-a | on | `enablePressureControl = true` |
| C-RV01 flow mode | on | structural |
| C-RV01 power mode | off | `rv01Goal = RV01Goal.Flow` |
| C-TEMP-SR | on | structural |
| C-TEMP-SP-b | on | structural (`wanted_temp`) |
| **CS-PREP** | **off** (changed from Run_1) | `enableCSPrep = false` |
| CS-FLOW-SP | on | structural (`m_flow_set`) |
| C-ISO | on | `enableCoilIsolation = true` |
| C-COLDSHUT | off | `shutWhenCold_CS = {false,false,false,false,false}` |
| C-OVERCOOL (archived) | off | `enableOverCoolPrevention = enableOverCoolRecovery = false` |

StopTime = 1800 s, solver = Dassl.

## Question (per run_simulation.md)

Is preparation needed to meet the 40 K rule at first coolant contact?

## Translation/simulation

`SUCCESSFUL simulation of CoilLoopCompassU.CS.CSCircuit`, `T = 1800` reached, CPU 1460 s, 26199 accepted steps, 6 state events, 1 model time event.
- **No Newton-solver failure** (FIX-27 does not appear): with CS-PREP off there is no shut-coil preparation phase, and the T≈4.85 s failure seen in Runs 3–5 is absent. Runs 3–5 all had CS-PREP on and were built after `13c9717`.
- One DASSL warning at `T≈2.2 s` ("about 500 steps… the system is stiff"), minimum step 3.4e-6 s. This stiff startup is the likely reason for the high cost (1460 s vs. Run_1's 393 s), but that was not measured.

## Result: the 40 K rule holds at first contact without CS-PREP — because the loop gas already starts at 97.5 K

Extracted from `Run_6.mat` (and Run_1.mat, Run_5.mat for comparison; same extraction script for all):

| | Run_1 (CS-PREP on) | Run_6 (CS-PREP off) |
|---|---|---|
| Coils open at | 91.1 s (`coolantReady`) | 0 s |
| Final `T_wallHotCooled` | 80.42 K | **79.21 K** |
| First time slowest wall ≤ 80 K | not reached by 1800 s | **1743 s** |
| Max `T_wall_max − T_supply` | 40.0 K (at t = 0) | 40.0 K (at t = 0) |
| Same, t ≥ 60 s | 39.99 K | 39.99 K |
| Time wall − supply > 40 K | 0 s | 0 s |
| Max coil gas inlet − outlet (`tube2` A/B) | 40.4 K at 93.6 s | 39.8 K at 327.6 s |
| Time inlet − outlet > 40 K | 57.6 s | **0 s** |
| Max wall-temperature spread, coil to coil | 1.83 K | 1.82 K |
| Final loop flow `m_flow_loop` | 0.172 kg/s | 0.171 kg/s |
| Final `P_shaft` / peak | 18.96 / 18.96 kW | 19.03 / 19.03 kW |
| Circulator energy (∫P dt) | 8.639 kWh | 8.665 kWh |

**Answer: in this series CS-PREP is not needed to meet the 40 K rule at first contact, and it costs time.** The loop gas is initialised at `T_loopInitial = 137.5 − 40 = 97.5 K` (see `docs/cs/circulator-sizing.md`), so the 40 K wall-to-supply margin holds at t = 0 by the initial condition itself (exactly 40.0 K), and the wall never gets more than 40 K above the supply afterwards. The ~91 s that CS-PREP spends with the coils shut also shows up at the end: Run_1 stops at 80.42 K, 0.4 K above the 80 K target, while Run_6 reaches 80 K at 1743 s. In Run_1 the inlet–outlet difference also exceeds 40 K for 57.6 s just after the coils open (peak 40.4 K, so only marginally); Run_6 never exceeds it.

**Caveat:** this does not show that CS-PREP is useless in general. It matters when the loop gas is *colder* than the coils minus 40 K when the coils open (the 2026-10-07 run started the loop at 80 K and violated the rule for 31 s). Run_6 only tests the case where the initial conditions already do the preparation. A run with the loop gas at 80 K and CS-PREP off would test what CS-PREP is actually for. The inlet–outlet figures use `tube2.summary.T_gas_A/T_gas_B`; ATEKO S3.4's exact definition of "inlet–outlet" has not been matched to this signal pair.

## Outlet vs wall check (docs/reading-simulations.md §5)

Wall-hottest-cell minus gas-outlet temperature, per coil, from `Run_6.mat` (Run_1 in brackets):

| | Run_6 | (Run_1) |
|---|---|---|
| Max, t ≥ 60 s | 0.57 K | (0.76 K) |
| Final value, per coil | 0.05–0.07 K | (0.09–0.11 K) |
| Hottest coil by outlet = hottest by wall (t ≥ 60 s) | 96.9 % of the time | (90.6 %) |
| Max coil-to-coil spread, wall vs outlet | 1.82 K vs 1.82 K | (1.83 K vs 1.83 K) |

The wall-minus-outlet offset is 20 K at t = 0 only (initial conditions: gas and wall start apart) and stays below 1 K afterwards, well inside the proposed 5 K acceptance. **In this symmetric, uniform-start scenario the outlet temperature is a good stand-in for the wall.** This says nothing yet about an asymmetric start, nor about the shut-coil case (frozen values), which these runs don't exercise.

## Files in this folder

- `Run_6.mat` — simulation result (renamed from `result.mat`); pressure signal is `sensor_p_discharge` (older runs use `sensor_p_suction`)
- `dslog.txt` — solver log (from `dslog_simulate.txt`)
- `dsin.txt` — resolved parameter/initial-condition set actually simulated
- `run.md` — this file

## Extract (remaining items, per run_simulation.md)

- Requirements: max `T_object − T_coolant`, max coil-to-coil spread, time to ≤ 80 K and inlet–outlet ΔT — extracted above (inlet–outlet definition to be confirmed)
- Cost: total LIN heat load, helium make-up/relief mass (RV07/RV08) — not yet extracted
- Numerics: CPU time 1460 s, 26199 accepted steps, 6 state events
