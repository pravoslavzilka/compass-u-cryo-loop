# Reading a simulation — overview and result checks

How to read a CS / PF / TF run, which signals mean what, and the check
that must be done after every run: **does the coil outlet temperature,
which the controllers use, track the coil wall temperature, which the
requirements are about?**

Applies to all three circuits. Circuit details are in
`docs/{cs,pf,tf}/control-logic.md`; algorithm definitions in
[control-common.md](control-common.md).

## 1. What the model is

One closed helium loop per coil system:

```
circulator → (RV01 bypass) → heater → evaporator (LIN, 77 K) + bypass valves
          → supply header → coils (one valve per coil/assembly) → return header → circulator
```

- The controllers set the **supply temperature** (heater / evaporator /
  bypass split-range, C-TEMP-SR), the **loop flow** (RV01), the **loop
  pressure** (RV07/RV08, makeup/relief) and which coils receive flow
  (C-ISO, C-COLDSHUT).
- The goal after a discharge is to cool every coil to ≤ 80 K within
  1800 s without violating the 40 K rules (see §3).
- Runs start at the hot-restart state (CS 137.5 K, TF 137 K, PF 160 K)
  and stop at StopTime (1800 s for the CS paper runs).

## 2. What the real machine can and cannot measure

The coils have **no internal temperature sensors** (insulation and
reliability; thesis §6.2). The only thermometers that see a coil are on
the **return (outlet) line after each coil**. So on the real plant:

- A coil's temperature is *inferred* from the helium temperature leaving
  it. During a discharge a small flow is circulated through every coil
  just so this reading exists (ATEKO S3.2 mode 3: "read object
  temperature").
- The hottest coil is the one with the hottest return temperature.

**Decision (FIX-16, 2026-11-03): the controllers use the outlet
temperature (`T_gas_out`) as the coil temperature**, because that is the
only signal the plant has. The model also contains the coil wall
temperature (`T_wall_max`, hottest wall cell), which the real machine
cannot see. We therefore treat the wall temperature as **ground truth for
checking**, not as a controller input, and verify after every run that
the outlet is a good enough stand-in (§5).

| Signal | Meaning | Real sensor? | Use |
|---|---|---|---|
| `T_gas_out_CS[i]` / `T_gas_out` | Helium temperature leaving coil *i* | **Yes** (return line) | Controller input; C-ISO, C-COLDSHUT |
| `T_gas_out_compare_CS[i]` | Outlet while the coil flows, frozen value while shut (R-FROZEN) | Yes (derived) | C-ISO, C-COLDSHUT |
| `T_gas_out_max` | Hottest outlet over all coils | Yes (derived) | C-ISO reference |
| `sensor_T.sensorValue` | Supply temperature to the coils | Yes | C-TEMP-SR feedback |
| `T_wall_max_CS[i]` / `T_wall_max` | Hottest wall cell of coil *i* | **No** (model only) | Checking; see the caveat below |
| `T_wallHotCooled`, `T_wallHotLive` | Hottest wall cell over the coils being cooled | **No** | Checking; see the caveat below |

**Caveat (open, FIX-28):** in CS and TF the setpoint rule C-TEMP-SP-b
and the release-all rule of C-COLDSHUT still read the *wall* temperature,
which the plant cannot measure. (CS-PREP no longer does: since 2026-11-03 it
measures the coil with a small-flow probe and reads the outlet.) C-ISO already uses
outlets. Until FIX-28 is closed, those algorithms are an idealisation:
results that depend on them (supply setpoint, release time) assume
perfect knowledge of the wall.

## 3. The requirements the results are judged against

| Requirement | Source | Quantity |
|---|---|---|
| Coils ≤ 80 K within 30 min | ATEKO 22172-Z-R1 S3.4/Tab.10 | slowest coil's temperature vs 1800 s |
| `T_object − T_coolant ≤ 40 K` | ATEKO S3.2 (mode 4) | coil temperature minus **supply** temperature, from the first contact |
| Max 40 K between inlet and outlet | ATEKO S3.4 | coil gas inlet minus outlet |
| Hottest and coldest coil ≤ 40 K apart | Thesis §6.1–6.2 (isolation scheme); not stated in ATEKO | coil-to-coil spread, via return temperatures |
| Circulator within the power budget | ATEKO (CS 20 kW) | `fan2ndOrder.P_shaft` |

Thesis §6.2 is the source of the coil-to-coil rule: coils reconnect
gradually after a discharge; the coils are judged by their return
temperature; every coil more than 40 K cooler than the hottest is
temporarily isolated (to avoid overcooling), and it is opened again when
the hottest has come within the 40 K difference. This is what C-ISO
implements with its 40 K close / 35 K reopen margins. The thesis also
gives the physical reason for the 40 K limit on the support structure
(≈ 100 MPa thermal stress, about 10 % of the 316LN yield margin).

## 4. Reading a result file

Open the `.mat` (one folder per run, `data/<circuit>/…/Run_N/`, which also
holds `dslog.txt`, `dsin.txt` and `run.md`) and look at, in this order:

1. **Did it finish?** `dslog.txt` ends with `SUCCESSFUL simulation` and
   `T = StopTime`. Note CPU time, accepted steps, state events, and any
   "Failed to solve nonlinear system" lines (see FIX-27).
2. **What was actually simulated?** `dsin.txt` holds the resolved
   switches (`enableCSPrep`, `enableCoilIsolation`, `shutWhenCold_CS`,
   `rv01Goal`, …). `run.md` records the commit and the on/off table.
3. **Sequence flags (CS):** `coolantReady` (preparation done, coils
   open), `coilOpen[i]` (C-ISO), `coldShut[i]`, `allReleased`
   (C-COLDSHUT). They tell you *which rule acted when*.
4. **Temperatures:** `T_gas_out_CS[i]`, `T_wall_max_CS[i]`, supply
   `sensor_T.sensorValue` vs `wanted_temp`, `T_wallHotCooled`.
5. **Flow, pressure, power:** `m_flow_loop` vs `m_flow_set`,
   `fan2ndOrder.P_shaft`, RV07/RV08 Kv traces, pressure at
   `sensor_p_discharge` (renamed from `sensor_p_suction`, FIX-17; older result files still use the old name).

Standard numbers extracted from every run (from `docs/cs/run_simulation.md`):

- Requirements: time for the slowest coil to reach ≤ 80 K, max
  `T_object − T_coolant`, max coil inlet–outlet ΔT, max coil-to-coil spread.
- Cost: circulator energy (∫`P_shaft` dt), peak `P_shaft`, LIN heat load,
  helium make-up/relief mass.
- Numerics: CPU time, accepted steps, state events.

## 5. Mandatory check: outlet vs wall

The controllers see only outlets. After each run, compare them with the
wall temperature the plant could not see, per coil *i*, over the whole
run **while the coil flows** (a shut coil's outlet is a frozen value, so
compare only while it flows; for shut coils compare the frozen value with
the wall at the freezing instant and note how far the wall then drifts):

| Quantity | Definition |
|---|---|
| Lag/offset | `T_wall_max_CS[i] − T_gas_out_CS[i]`: max, and value at the end |
| Spread error | (max − min over coils of `T_wall_max`) − (max − min over coils of the outlet signal used by C-ISO) |
| Hottest-coil identity | Is the coil with the hottest outlet also the one with the hottest wall? For what fraction of time? |
| Decision error | Did C-ISO/C-COLDSHUT act on an outlet reading while the wall was on the other side of the threshold (e.g. outlet ≤ 80 K but wall > 80 K)? |

**Acceptance (proposed, [ASSUMED] — confirm with the requirement owner):**
the approximation is good enough when

- the max wall-minus-outlet offset stays within about **5 K** (about an
  eighth of the 40 K margin) during the controlled phase, and
- the spread error stays within about 5 K, and
- no rule decision (isolate, reopen, shut at 80 K, release) would have
  been different if the wall had been used.

If any condition fails, the outlet is not a sufficient proxy for that
scenario. Then refine it, in this order of effort: (1) add a fixed or
temperature-dependent offset to the outlet reading, (2) estimate the wall
from outlet and flow (a simple first-order observer using the coil's
thermal mass), (3) change the rule's margin to cover the offset. Record
the outcome in the run's `run.md` under a heading "Outlet vs wall".

Known data points so far: in TF the gas outlet ran "a few K" below the
hottest wall cell (control-common.md, C-TEMP-SP), and CS Run_5 showed the
wall-based coil-to-coil spread peaking at 1.8 K, so the 40 K isolation
margin was never approached in the symmetric nominal case. The outlet-vs-
wall check itself has **not yet been run** on any result; do it first on
CS Runs 1–5.

## 6. Limits of what the runs show

- The CS paper runs use uniform initial conditions (all coils 137.5 K), so
  coil-to-coil algorithms (C-ISO, C-COLDSHUT) have little to do. An
  asymmetric start is a stronger test of both the algorithms and of the
  outlet-as-proxy assumption.
- The outlet reading is a mixed-mean of the channel flow; while the coils
  are shut there is no meaningful outlet. CS-PREP therefore takes one
  reading at the end of a short small-flow probe (`T_probe`) and uses
  that.
- Open numerical issue FIX-27 changes cost (CPU, steps) between runs
  compiled before and after commit `13c9717`; compare numerics only
  between like runs.
