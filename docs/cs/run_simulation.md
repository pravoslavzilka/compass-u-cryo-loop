# CS circuit — simulation runs 

Model: `CoilLoopCompassU.CS.CSCircuit`. Every run uses the same StopTime, solver,
tolerance and initial conditions; only the settings below change.

Reference = Baseline + Primary tier on, Secondary tier off, Archived off.
Each run changes one thing against Run\_1, except Run\_4, which turns on both
secondary algorithms.

## Run\_1 — Reference (requirement-only control)

* C-SPEED-b (fixed speed, soft start): on
* C-PRES-a (RV07/RV08 pressure PI): on (`enablePressureControl = true`)
* C-RV01 flow mode: on
* C-RV01 power mode: off (`rv01Goal = RV01Goal.Flow`)
* C-TEMP-SR (split-range supply temperature): on
* C-TEMP-SP-b (40 K setpoint rule): on
* CS-PREP (startup coolant preparation): on
* CS-FLOW-SP (flow setpoint per open channel): on
* C-ISO (coil isolation): on (`enableCoilIsolation = true`)
* C-COLDSHUT (shut-off at 80 K): off (`shutWhenCold\_CS = {false,false,false,false,false}`)
* C-OVERCOOL: off (`enableOverCoolPrevention = enableOverCoolRecovery = false`)

## Run\_2 — Reference + C-COLDSHUT

* C-SPEED-b: on
* C-PRES-a: on
* C-RV01 flow mode: on
* C-RV01 power mode: off
* C-TEMP-SR: on
* C-TEMP-SP-b: on
* CS-PREP: on
* CS-FLOW-SP: on
* C-ISO: on
* **C-COLDSHUT: on** (`shutWhenCold\_CS = {true,true,true,true,true}`)
* C-OVERCOOL: off

Question: does redistributing flow shorten the cooldown of the slowest coil?

## Run\_3 — Reference + RV01 power mode

* C-SPEED-b: on
* C-PRES-a: on
* C-RV01 flow mode: on (stays active as the flow floor)
* **C-RV01 power mode: on** (`rv01Goal = RV01Goal.Power`)
* C-TEMP-SR: on
* C-TEMP-SP-b: on
* CS-PREP: on
* CS-FLOW-SP: on
* C-ISO: on
* C-COLDSHUT: off
* C-OVERCOOL: off

Question: does extra flow within the 20 kW budget shorten cooldown, and at what energy cost?

## Run\_4 — Reference + C-COLDSHUT + power mode (interaction)

* C-SPEED-b: on
* C-PRES-a: on
* C-RV01 flow mode: on
* **C-RV01 power mode: on**
* C-TEMP-SR: on
* C-TEMP-SP-b: on
* CS-PREP: on
* CS-FLOW-SP: on
* C-ISO: on
* **C-COLDSHUT: on**
* C-OVERCOOL: off

Question: do the two secondary algorithms interact? Compare with Run\_2 and Run\_3.

## Run\_5 — Reference without C-ISO

* C-SPEED-b: on
* C-PRES-a: on
* C-RV01 flow mode: on
* C-RV01 power mode: off
* C-TEMP-SR: on
* C-TEMP-SP-b: on
* CS-PREP: on
* CS-FLOW-SP: on
* **C-ISO: off** (`enableCoilIsolation = false`)
* C-COLDSHUT: off
* C-OVERCOOL: off

Question: is isolation needed to keep the coil-to-coil spread ≤ 40 K?

## Run\_6 — Reference without CS-PREP

* C-SPEED-b: on
* C-PRES-a: on
* C-RV01 flow mode: on
* C-RV01 power mode: off
* C-TEMP-SR: on
* C-TEMP-SP-b: on
* **CS-PREP: off** (`enableCSPrep = false`)
* CS-FLOW-SP: on
* C-ISO: on
* C-COLDSHUT: off
* C-OVERCOOL: off

Question: is preparation needed to meet the 40 K rule at first coolant contact?

\---

## Priority

* For the abstract: Run\_1, Run\_2, Run\_3, Run\_5
* For the full paper: add Run\_4, Run\_6

## Extract from every run

* Requirements: time for the slowest coil to reach ≤ 80 K (vs. 1800 s), max T\_object − T\_coolant,
max coil inlet–outlet ΔT, max coil-to-coil spread
* Cost: total circulator energy, peak `fan2ndOrder.P\_shaft`, total LIN heat load,
helium make-up/relief mass (RV07/RV08)
* Numerics: CPU time, number of state events

## Saving

One folder per run, `data/CS/paper/Run\_N/`: result `.mat` (renamed, not `result.mat`),
`dslog.txt`, `dsin.txt`, and `run.md` with git commit hash, changed settings and date.

