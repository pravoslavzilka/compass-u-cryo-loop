# CS working scenarios — all algorithms on (2026-11-11)

Same model/settings for all five (see `3100-.../run.md`; `CSCircuit.mo.snapshot` in each folder). Only `TInitialCoilCS` differs (`T_start_energy_conserving_K`). Per run: `<scenario>.mat`, `dsin.txt`, `dslog.txt`, `summary.json`, `overview.png`, `cs_scen.mos` (3100: `cs_full.mos`). Driver: `tools/scenarios/run_cs_scenarios.py`.

| Scenario | CS T0 [K] (CS1, 2U, 2L, 3U, 3L) | T_probe | coolantReady | allReleased | Slowest coil ≤80 K (settled) | Hot-wall peak | Circ. energy | LIN energy | Steps / state events |
|---|---|---|---|---|---|---|---|---|---|
| 3100-rev15 | 78.7, 83.2, 83.2, 83.3, 80.5 | 83.2 K | 159 s | 643 s | CS1 900 s | 84.3 K | 11.8 kWh | 44 MJ | 3822 / 23 |
| 4300-rev18 | 78.8, 79.9, 79.9, 80.5, 80.1 | 80.4 K | 160 s | 603 s | CS2U 947 s | 83.2 K | 11.3 kWh | 41 MJ | 6017 / 31 |
| 5400-rev18 | 80.0, 85.4, 85.4, 83.9, 82.4 | 85.3 K | 156 s | 657 s | CS1 1012 s | 85.4 K | 11.8 kWh | 45 MJ | 2945 / 34 |
| 6400-rev17 | 79.9, 81.3, 81.3, 84.0, 80.5 | 83.9 K | 158 s | 650 s | CS1 997 s | 84.4 K | 11.8 kWh | 44 MJ | 4044 / 35 |
| 24300-rev28 | 79.1, 78.4, 78.4, 82.2, 79.7 | 82.1 K | 160 s | 636 s | CS3L 972 s | 83.7 K | 10.6 kWh | 39 MJ | 3610 / 30 |

All five end at 77.44 K for every coil at 1800 s, with supply min 76.2–76.8 K and peak shaft power 27.1–27.5 kW.

**Pattern:** the slowest coil is always one that started near or below 80 K and was cold-shut at `controlsActive` (~169 s) while the prep warm-up had reheated it (CS1 in 3100/5400/6400, CS2U/CS2L in 4300, CS3L in 24300): settle time 870–1012 s vs ~600–660 s for the coils that started above 80 K. See the CS1 note in `3100-.../run.md`.
