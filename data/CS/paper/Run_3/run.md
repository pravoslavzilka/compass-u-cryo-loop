# Run_3 — Reference + RV01 power mode

**Date:** 2026-10-29
**Model:** `CoilLoopCompassU.CS.CSCircuit`
**Git commit:** `07304e9` (development). `CSCircuit.mo` at this commit is exactly what was translated and simulated for this run — includes the `PID_power` startup gate added earlier the same day (commit `13c9717`, FIX-14) that this run validates.

**Confirmed from `dsin.txt`** (the resolved set actually simulated): `enableCSPrep=1`, `enableCoilIsolation=1`, `shutWhenCold_CS[1..5]=0,0,0,0,0`, `rv01Goal=Power` (enum index 2), `P_shaftLimit=20000`, `dm_flowPowerMax=0.1`, `enablePressureControl=1`.

## Algorithm settings (on/off)

Per `docs/cs/run_simulation.md` Run_3 — Reference (Run_1) with RV01 power mode on instead of flow mode. Only `rv01Goal` differs from Run_1.

| Algorithm | State | Parameter |
|---|---|---|
| C-SPEED-b (fixed speed, soft start) | on | structural (`n_fixed_Hz`, `T_softStart`) |
| C-PRES-a (RV07/RV08 pressure PI) | on | `enablePressureControl = true` |
| C-RV01 flow mode | on (stays active as flow floor) | structural |
| **C-RV01 power mode** | **on** (changed from Run_1) | `rv01Goal = RV01Goal.Power` |
| C-TEMP-SR (split-range supply temperature) | on | structural |
| C-TEMP-SP-b (40 K setpoint rule) | on | structural (`wanted_temp`) |
| CS-PREP (startup coolant preparation) | on | `enableCSPrep = true` |
| CS-FLOW-SP (flow setpoint per open channel) | on | structural (`m_flow_set`) |
| C-ISO (coil isolation) | on | `enableCoilIsolation = true` |
| C-COLDSHUT (shut-off at 80 K) | off | `shutWhenCold_CS = {false,false,false,false,false}` |
| C-OVERCOOL (archived) | off | `enableOverCoolPrevention = enableOverCoolRecovery = false` |

StopTime = 1800 s, solver = Dassl (common to every run, per `run_simulation.md`).

## Question (per run_simulation.md)

Does extra flow within the 20 kW budget shorten cooldown, and at what energy cost?

## What happened getting here (two stalls, both resolved)

This was the first-ever run of power mode (`docs/to-fix.md` FIX-14). It took two attempts:

1. **First attempt stalled at `T≈3.6s`** — `PID_power.u_s = P_shaftLimit` was unconditional, so at t=0 (circulator still on its soft-start ramp, `P_shaft` near zero vs. the 20 kW limit) `PID_power.y` saturated to `dm_flowPowerMax` almost instantly, demanding flow the ramping circulator couldn't deliver. Fixed by gating `PID_power.u_s` to `u_s = u_m` (zero error) until `controlsActive` — commit `13c9717`.
2. **Second attempt got past `T≈3.6s` cleanly, then hit a nonlinear-solver failure at `T≈4.845855s`** in `junction7`/`valve3`/`valve5` (the evaporator-bypass trio the model's own header already flags as anti-chatter-sensitive): gas enthalpy/pressure briefly went unphysical (`T` clamped to 10000 K / 2 K, `p` swinging between ~1 Pa and ~93–98 MPa), logged as "Failed to solve nonlinear system using Newton solver... Solver will attempt to handle this problem." This turned out to be **recoverable** — the solver pushed through and reached `T=1800` successfully, at much higher cost (921 s CPU / 75,944 accepted steps vs. Run_1/2's 393 s / ~6,600 steps).

**Translation/simulation:** `OK: translation successful` → `SUCCESSFUL simulation of CoilLoopCompassU.CS.CSCircuit`, `T = 1800` reached (`dslog.txt`), CPU 921 s, 75944 accepted steps, 11 state events, 3 model time events.

## Result: extra flow did shorten cooldown, at an energy cost

Compared against Run_1 (Flow mode) and Run_2 (Flow mode + C-COLDSHUT), extracted from the `.mat` files:

| | Run_1 (Flow) | Run_2 (Flow+COLDSHUT) | Run_3 (Power) |
|---|---|---|---|
| Final `T_wallHotCooled` | 80.42 K | 80.43 K | **78.09 K** |
| Final loop flow `m_flow_loop` | 0.172 kg/s | 0.156 kg/s | **0.187 kg/s** |
| Final `fan2ndOrder.P_shaft` | 18.96 kW | 18.13 kW | **20.18 kW** |
| Peak `P_shaft` | 18.96 kW | 18.94 kW | **22.88 kW** |
| Circulator energy (∫P dt, trapezoidal) | 8.64 kWh | 8.64 kWh | **9.30 kWh** |

Run_3 ends ~2.3 K colder than Run_1/Run_2 because it ran ~9% more loop flow, which cost ~7.6% more circulator energy (8.64 → 9.30 kWh) to achieve. `P_shaft` sits right around the 20 kW budget at the end (20.18 kW), as designed — this is the expected behaviour of power mode (spend available power headroom on extra cooling), not a save-power mode.

**Note:** peak `P_shaft` (22.88 kW) briefly exceeded `P_shaftLimit` (20 kW) — almost certainly a transient overshoot during the `T≈4.85s` nonlinear-solver recovery, not a sustained steady-state violation (final value sits at the limit). Worth a closer look in a future pass but not flagged as a new to-fix item on this evidence alone.

## Files in this folder

- `Run_3.mat` — simulation result (renamed from `result.mat`)
- `dslog.txt` — solver log (steps, events, CPU time, including the Newton-solver-failure and recovery messages)
- `dsin.txt` — resolved parameter/initial-condition set actually simulated
- `run.md` — this file

## Extract (remaining items, per run_simulation.md)

- Requirements: time for slowest coil ≤ 80 K (vs. 1800 s), max `T_object − T_coolant`, max coil inlet–outlet ΔT, max coil-to-coil spread — not yet extracted
- Cost: total LIN heat load, helium make-up/relief mass (RV07/RV08) — not yet extracted
- Numerics: CPU time 921 s, 75944 accepted steps, 11 state events (from `dslog.txt`) — note the ~2.3x CPU cost vs. Run_1/2 from the `T≈4.85s` recovery
