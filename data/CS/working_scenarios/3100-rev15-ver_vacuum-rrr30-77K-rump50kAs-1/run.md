# 3100-rev15-ver_vacuum-rrr30-77K-rump50kAs-1 — CS, all algorithms on

**Date:** 2026-11-11
**Model:** `CoilLoopCompassU.CS.CSCircuit`, StopTime 1800 s, DASSL, tol 1e-4
**Git:** base `0ffbc68` (development) **plus uncommitted edits** — the exact model simulated is `CSCircuit.mo.snapshot` in this folder.
**Run script:** `cs_full.mos` (copy in this folder; run on the VM via `tools/vm/vm_watcher.ps1`, 4.7 min wall).

## Scenario

First scenario of `data/working_scenarios/model_coil_start.csv`. Coil start temperature = `T_start_energy_conserving_K`, applied to coil wall and trapped gas (`TInitialCoilCS`):

| CS1 | CS2U | CS2L | CS3U | CS3L |
|---|---|---|---|---|
| 78.682 K | 83.209 K | 83.209 K | 83.280 K | 80.470 K |

Loop gas starts at the idle 80 K (`T_loopIdle`, because CS-PREP is on).

## Algorithm settings (all on)

`enableCSPrep=true`, `enableCoilIsolation=true`, `shutWhenCold_CS={true x5}`, `rv01Goal=Power`, `enablePressureControl=true`, `enableOverCoolPrevention=true`, `enableOverCoolRecovery=true` (the last two are the TF/PF copies, never run on CS before this run). Confirmed in `dsin.txt` for CSPrep / isolation / rv01Goal / overcool; `shutWhenCold_CS` entries are listed there too.

## Key results (`summary.json`, plot `overview.png`)

**CS-PREP sequence**

| Event | Time |
|---|---|
| Probe ends, coils shut, `T_probe` latched | 15 s, T_probe = 83.21 K |
| Target supply = max(T_probe − 40, 77) | 77 K (floor) |
| Flush starts | 98.8 s |
| `coolantReady` (hand-over) | 158.8 s |
| `controlsActive` | 168.8 s |
| `allReleased` | 642.7 s |

**Cooldown**

| Coil | T0 | Cold-shut latched | Settled ≤ 80 K | End |
|---|---|---|---|---|
| CS1 | 78.68 K | 168.8 s | **900.0 s** | 77.44 K |
| CS2U | 83.21 K | 634.0 s | 637.2 s | 77.44 K |
| CS2L | 83.21 K | 630.0 s | 634.0 s | 77.44 K |
| CS3U | 83.28 K | 642.7 s | 648.0 s | 77.44 K |
| CS3L | 80.47 K | 598.7 s | 604.8 s | 77.44 K |

- Slowest coil ≤ 80 K at **900 s** (CS1); all coils 77.44 K at 1800 s. Hottest wall peak 84.27 K (CS2U, 133 s).
- Supply temperature (header): min 76.7 K, max 90.1 K (warm-up), 77.43 K at end.
- Hot wall − supply after hand-over: max 5.9 K. Max coil-to-coil spread after hand-over: 2.6 K.

**Flow / power / cost**

- Loop flow max 0.334 kg/s, 0.292 kg/s at end.
- Circulator shaft power: 4.2 kW at start, peak 27.1 kW, 26.5 kW at end; energy 11.84 kWh.
- Evaporator duty max 60 kW (cap), 26.3 kW at end; LIN energy 44.3 MJ.
- Discharge pressure 77.8–84.6 bar (setpoint 82), 82.0 at end.

**Numerics:** 3822 accepted steps, 4 time events, 23 state events, no solver failure. One "~500 steps" warning at T≈1.12 s in the first 3.6 s interval (start-up transient).

## Observation worth following up

**CS1 was cold-shut at t = 168.8 s because it started below 80 K (78.7 K), then reheated.** During prep the supply was warmed to ~88 K and the coil sat shut with warm gas; CS1's wall rose to 83 K at 160 s, but the cold-shut latch (T_coldShut = 80 K) had already fired at the moment controls activated, so CS1 stayed isolated at ~82.4 K until `allReleased` at 643 s and only settled at 900 s. The other coils started above 80 K, so they only latched once genuinely cooled. This makes CS1 the slowest coil with C-COLDSHUT on. Whether to latch on the instantaneous start value (vs. after the coil has actually been cooled) is a model-logic question, not fixed here.

## Files

- `3100-rev15-ver_vacuum-rrr30-77K-rump50kAs-1.mat` — result
- `dsin.txt`, `dslog.txt` — resolved parameters, solver log
- `CSCircuit.mo.snapshot` — model as simulated; `cs_full.mos` — run script
- `summary.json`, `overview.png` — extracted key variables (tools: `tools/scenarios/summarize_cs_run.py`, `matlib.py`)
