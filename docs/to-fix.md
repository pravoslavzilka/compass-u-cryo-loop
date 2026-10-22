# To fix

Open problems in the three circuit models, found in reviews. Algorithm and
robustness IDs (`C-…`, `R-…`) refer to [control-common.md](control-common.md).
When an item is fixed, set its status to **done** with the commit and the date,
and update the circuit's `control-logic.md`; don't delete the entry.

Priority: **P1** a requirement is violated or the run is at risk; **P2** a
behaviour or robustness gap with a known fix; **P3** documentation, naming,
structure.

## Summary

| ID | Circuit | Problem | Prio | Status |
|---|---|---|---|---|
| [FIX-01](#fix-01) | TF, PF | Coils meet 80 K gas at 137 K (TF) / 160 K (PF): 40 K rule broken at startup | P1 | open |
| [FIX-02](#fix-02) | TF | Pressure PI saturates at 150 Pa error (CS found ringing with the same gain) | P1 | open |
| [FIX-03](#fix-03) | TF, PF | valve6 Kv negative for 0 < PID.y < 0.7 (no R-KVFLOOR) | P2 | open |
| [FIX-04](#fix-04) | TF, CS | Cold shut-off overwrites a frozen temperature with the raw stagnant one | P2 | open |
| [FIX-05](#fix-05) | TF, PF | Isolation close not gated by the activation delay | P3 | open |
| [FIX-06](#fix-06) | TF | PID_pressure limits don't match the Kv clamp (no R-WINDUP) | P3 | open |
| [FIX-07](#fix-07) | TF | No flow control: coil flow is whatever the fixed-speed fan gives | P2 | open, check PFD |
| [FIX-08](#fix-08) | TF, PF | No LIN supply cap on the evaporator (CS has one) | P3 | open |
| [FIX-09](#fix-09) | TF, PF | C-SPEED-a has no soft start | P3 | open |
| [FIX-10](#fix-10) | TF, PF, CS | C-OVERCOOL archived everywhere but still in all three `.mo` | P3 | open |
| [FIX-11](#fix-11) | PF | `PID.y_start` = 5 switches the heater on at startup | P2 | open |
| [FIX-12](#fix-12) | PF | Setpoint is C-TEMP-SP-a (gas outlet, no floor) | P2 | open, decision |
| [FIX-13](#fix-13) | PF | valve5 throttles only below PID.y = −10.3 | P2 | open |
| [FIX-14](#fix-14) | CS | C-RV01 power mode never run, all four parameters guessed | P2 | open |
| [FIX-15](#fix-15) | CS | RV01 flow PI reads a loop-side flow the plant doesn't measure | P2 | open, plant |
| [FIX-16](#fix-16) | all | C-ISO 40 K coil-to-coil: source unknown; outlet vs wall undecided | P2 | open, decision |
| [FIX-17](#fix-17) | all | `sensor_p_suction` measures the discharge side | P3 | open, ask first |
| [FIX-18](#fix-18) | PF | `.mo` not tagged with algorithm IDs; stale docstrings (thresholds, suction, line numbers) | P3 | open |
| [FIX-19](#fix-19) | PF | `pressureSetpoint` docstring says 35.5 barg for 36.5 bara | P3 | open |
| [FIX-20](#fix-20) | all | Coil-sequencing rules share latches but are separate algorithms | P3 | proposal |
| [FIX-21](#fix-21) | TF | Four branch masks only special-case the Structure | P3 | proposal |
| [FIX-22](#fix-22) | TF | Stale header and docstrings, no ID tags | P3 | **done** 2026-10-22 |
| [FIX-23](#fix-23) | PF | PF-LOWTEMP and C-ISO fight over the same latch (close/reopen loop) | P2 | open |
| [FIX-24](#fix-24) | PF | Coil valves at the inlet only (no R-BOTHENDS) | P3 | open |
| [FIX-25](#fix-25) | PF | Evaporator modelled as one well-mixed cell, likely oversized | P2 | open |
| [FIX-26](#fix-26) | PF | Power-cap PI integrates while its gate is shut | P3 | open |

---

## TF

<a id="fix-01"></a>
### FIX-01 — 40 K rule broken at startup (P1)

**Where:** `TFCircuit.mo`, `TInitial` of all junctions, `tube1` and
`Heater` = 80 K; `TFCL1/TFUL1/TFUL2.TInitial` = 137 K; coils open at t = 0.
**Problem:** first contact is 137 K wall vs 80 K gas, i.e. 57 K, against
ATEKO S3.2 (`T_object − T_coolant ≤ 40 K`) and S3.4 (40 K inlet → outlet).
`wanted_temp` starts at 97 K but the loop holds 80 K gas. CS had the same
problem (2026-10-07 run: 31 s over the limit) and solved it with CS-PREP.
**Fix:** quick: start the loop gas at `T_loopInitial` = 137 − 40 = 97 K, as
CS does. Full: adopt CS-PREP (coils shut, circulate through valve4 until
the supply sits at `T_wall_max − 40 K`), which then moves to
`control-common.md` as `C-PREP` and gives TF's valve4 a use again (see
FIX-10). Check the first ~60 s of a run for inlet–outlet ΔT either way.
**PF:** same, worse: assemblies at 160 K, loop gas (junctions, `tube1`,
`Heater`) at 80 K, i.e. an 80 K step, with `PID.y_start` = 5 also
switching the heater on (FIX-11). PF's valve4 has no other use either,
so the same C-PREP decision applies.

<a id="fix-02"></a>
### FIX-02 — Pressure PI saturates at 150 Pa (P1)

**Where:** `kPressurePID` = 0.05 /Pa, `PID_pressure` y ∈ ±7.5.
**Problem:** 150 Pa of error saturates the PI, so RV07/RV08 behave
bang-bang. CS used the same gain and found the discharge pressure ringing
at several Hz, costing ~125 solver steps per simulated second
(2026-10-08); CS now runs 1.5e-6 /Pa. TF's RV07/RV08 gains are tagged
PLACEHOLDER.
**Fix:** check a TF result for RV07/RV08 Kv chatter; retune on CS's
pattern (k ~1e-6 /Pa, Ti 30 s), then fix FIX-06 at the same time.
PF uses the same 0.05 /Pa inside C-PRES-b; its runs since the 2026-09-01
rewrite were reported stable, so look at its RV07/RV08 Kv traces before
deciding whether it needs the same change.

<a id="fix-03"></a>
### FIX-03 — valve6 Kv negative, no R-KVFLOOR (P2, also PF)

**Where:** `CoolingLimiter1`: `min(-PID.y*Kv_gain, Kv_cool_max)`.
**Problem:** the cooling gate opens at `PID.y` < 0.7, so for 0 < y < 0.7 the
command is negative: reverse evaporator flow (16k Newton failures in CS).
**Fix:** `max(min(-PID.y*Kv_gain, Kv_cool_max), Kv_shut)`, as CS. Same
one-token fix in `PFCircuit.mo`.

<a id="fix-04"></a>
### FIX-04 — Cold shut-off overwrites the frozen temperature (P2, also CS)

**Where:** algorithm section, `[C-COLDSHUT]` when-block:
`T_gas_out_frozen[i] := T_gas_out_TF[i]`.
**Problem:** if an upper-limb bus is first isolated by C-ISO with a frozen
value ≤ 80 K (upper limb at 80 K while the core is still above 120 K), the
cold-shut test fires on that frozen value and overwrites it with the raw
outlet temperature of a stagnant bus, exactly what R-FROZEN exists to
avoid. Rare, but reachable.
**Fix:** only re-freeze if the bus is still flowing
(`if pre(coilOpen[i]) then T_gas_out_frozen[i] := …`), or fold both rules
into one state machine (FIX-20). `CSCircuit.mo` has the identical
when-block (`[C-COLDSHUT]`, all five coils opted in), so fix both.

<a id="fix-05"></a>
### FIX-05 — Isolation close not gated by the activation delay (P3, also PF)

**Where:** `[C-ISO]` close branch (`elsewhen … > coilIsolationCloseMargin`).
**Problem:** reopen, cold shut-off and release-all wait for
`controlActivationDelay`; close does not. CS gates all of them through
`controlsActive`. Harmless today (all coil busses start at 137 K, the
Structure is excluded), but it would bite with uneven initial temperatures.
**Fix:** add `time >= controlActivationDelay` to the close condition.

<a id="fix-06"></a>
### FIX-06 — Pressure PI limits don't match the Kv clamp (P3)

**Where:** `PID_pressure` y ±7.5, `KvGainMakeup/Relief` = 5,
`KvMakeupMax/ReliefMax` = 30.
**Problem:** 7.5 × 5 = 37.5 > 30, so the integrator can wind up past what
the valve can use (R-WINDUP is not satisfied; PF and CS match exactly).
**Fix:** y ±6 (= 30/5), or settle it with the retune in FIX-02.

<a id="fix-07"></a>
### FIX-07 — No flow control (P2, check PFD 22179)

**Problem:** no circulator bypass RV01, no flow setpoint. `m_total` =
1.3 kg/s (ATEKO S6.5.3) is documentation only; the coil flow is set by the
fixed-speed fan and the static Kv values (`KvUpperLimb` = 45,
`Structure.valveKvNominal` = 12).
**Fix:** check whether PFD 22179 shows a TF_RV01 (the PFD has no text
layer; render it). If it does, port CS's C-RV01 flow mode and a
per-channel setpoint (5.17 g/s per channel, ATEKO Tab.6).

<a id="fix-08"></a>
### FIX-08 — No LIN supply cap (P3, plant model)

**Where:** `tube1` wall held at a fixed 77 K (`coldSurface`).
**Problem:** no LIN-side boiling resistance and no cap at the LIN supply;
the `tube1` docstring itself calls the evaporator optimistic. CS models
both (`G_LINcell`, `Q_LINmax`).
**Fix:** port CS's capped LIN model with TF's numbers (ATEKO S6.2, S7.2).
PF: same gap, plus FIX-25.

<a id="fix-09"></a>
### FIX-09 — No soft start (P3)

**Where:** `smoothStep` 200 → 200 Hz.
**Problem:** CS starting at full speed gave a pressure spike that opened
RV07 and RV08 together; CS moved to C-SPEED-b. TF hasn't been checked for
the same spike.
**Fix:** look at RV07/RV08 in the first 10 s of a TF run; if both open,
switch to C-SPEED-b. PF has the same constant `smoothStep` 200 → 200 Hz.

---

## Several circuits

<a id="fix-10"></a>
### FIX-10 — C-OVERCOOL still in the code everywhere (P3)

**Problem:** archived in all three circuits, but valve4, the four state
variables, six parameters and the when-block remain in each `.mo`. In CS
valve4 is also used by CS-PREP; in TF and PF it has no other use.
**Fix:** decide together with FIX-01. If TF adopts C-PREP, keep valve4
and drop only the state machine; otherwise remove it from TF/PF and record
the last commit containing it in the Archived row.

<a id="fix-16"></a>
### FIX-16 — C-ISO requirement and measured quantity (P2, decision)

**Problem:** C-ISO is tiered Primary on "hottest and coldest coil may not
differ by more than 40 K", cited as an IPP requirement; ATEKO doesn't state
it (only S3.2 "temperature homogeneity", S6.1 ON/OFF valves). The source
document is still missing. Second: all three circuits compare gas
**outlet** temperatures; if the requirement is on the coil, the test should
use `T_wall_max`.
**Fix:** get the source; settle outlet vs wall.

<a id="fix-17"></a>
### FIX-17 — `sensor_p_suction` measures the discharge side (P3, ask first)

**Problem:** in CS, PF and TF it reads `junction22`, which hangs off the
evaporator inlet tee after the heater, i.e. the circulator discharge. The
TF docstrings now say so.
**Fix:** rename (e.g. `sensor_p_discharge`). This changes result-file
variable names used by scripts and plots, so agree on it first.

<a id="fix-20"></a>
### FIX-20 — One coil-sequencing state machine (P3, proposal)

**Problem:** C-ISO, C-COLDSHUT and PF-LOWTEMP share `coilOpen[]` and
`T_gas_out_frozen[]` and all feed one "flows / doesn't flow" signal
(`coilFlowing` in CS, `kvTarget_TF` in TF), but they're written and
documented as separate algorithms. Two writers of the frozen temperature
caused FIX-04.
**Fix:** one per-coil state machine `Open / Isolated / ColdShut /
Released` (`C-COILSEQ`), with the existing rules as transitions. Fold
PF-LOWTEMP into C-COLDSHUT as variant b (reversible, `minHotOthers`).
Do it in all three circuits together.

---

## TF only, structure

<a id="fix-21"></a>
### FIX-21 — Branch masks (P3, proposal)

**Where:** `isolationAllowed_TF`, `isCoil_TF`, `inGasOutMax_TF`,
`shutWhenCold_TF`.
**Problem:** four Boolean arrays whose only job is to special-case index 2
(Structure). Easy to get one out of step.
**Fix:** one `branchRole = {Coil, Structure, Coil, Coil}` (enumeration),
masks derived from it; document `KvUpperLimb` and the Structure Kv as
plant configuration, not control.

<a id="fix-22"></a>
### FIX-22 — Stale header and docstrings, no ID tags (P3) — done

**Done** 2026-10-22: header rewritten (flow path, algorithm list,
robustness measures); "speed ramp", "suction node", "proportional trim",
"2 + 2 busses", "CLASS NAME ASSUMED" and the wrong 3.4× flow ratio
removed; `controlActivationDelay` docstring lists everything it gates;
`[C-…]`/`[R-…]` tags on parameters, blocks and when-blocks, as in
`CSCircuit.mo`. Comments and docstrings only; code checked identical.

---

## PF

<a id="fix-11"></a>
### FIX-11 — `PID.y_start` = 5 (P2)

**Problem:** starts with the heater gate on. TF moved to 0 after the heater
pushed the supply to ~117 K for the first ~40 s.
**Fix:** `y_start` = 0.

<a id="fix-12"></a>
### FIX-12 — Setpoint variant a (P2, decision)

**Problem:** `wanted_temp = T_gas_out_max − 40 K`, no floor. The gas
outlet runs a few K below the hottest wall cell, so the wall-to-supply
difference can exceed 40 K (TF measured 45 K, 917 s above 40 K, before it
switched); without a floor the setpoint falls below what the 77 K
evaporator can deliver.
**Fix:** decide whether PF moves to C-TEMP-SP-b, as CS and TF did.

<a id="fix-13"></a>
### FIX-13 — Late valve5 throttling (P2)

**Problem:** `bypass_limit` = 10 and gain 10 (literals in `BypassLimiter`):
valve5 throttles only below PID.y = −10.3 and shuts at −50. In TF this kept
valve5 fully open while the supply sat 7–14 K above setpoint.
**Fix:** 2 / 50 as TF, with the gain as a parameter.

<a id="fix-18"></a>
### FIX-18 — No ID tags, stale docstrings (P3)

**What is stale in `PFCircuit.mo`:**
- `RV07` docstring: opens at "32 bar", closes at "35 bar" — actual
  `pMakeupOpen` 34 bar, and the valve trims continuously, not open/shut.
- `RV08` docstring: "37 bar" / "35 bar" — actual `pReliefOpen` 39 bar,
  `pReliefClose` 37.5 bar.
- `junction22` docstring: "suction node … unchanged coil-return
  topology" — it hangs off `junction6`, the evaporator inlet tee
  (discharge side). Same "suction" wording in `enablePressureControl`,
  `pressureSetpoint`, `PID_pressure`, `V_loopEffective`.
- `sensor_p_suction`: "CLASS NAME ASSUMED … verify at translate-check".
- `sensorTFiltered`: cites "line 693", "lines 525/529" — no longer match.
- `valve1PowerLimitTriggerTemp`: reasons from `P_shaftLimit=40000`; the
  value is now 50 kW. The name says `valve1`, the valve is `PF_RV01`.
- `PF_RV01Command`: history of the replaced flow trim (`m_wanted`).
- `m_total` "total flow from the pump": not used by any controller.
- No header comment (CS and TF have one).

**Fix:** same pass as FIX-22: header with flow path and algorithm list,
`[C-…]`/`[PF-…]`/`[R-…]` tags, section comments in the order C-SPEED-a,
C-PRES-b, C-RV01 power-cap, C-TEMP-SR + C-TEMP-SP-a, C-ISO + PF-LOWTEMP,
C-OVERCOOL (archived) last. The long dated histories in the RV07/RV08,
`valveRampTime`, `PID_pressure` and pulse-latch docstrings could move to
`migration-notes.md`, leaving one line each. Comments and docstrings
only; check the code is unchanged afterwards.

<a id="fix-19"></a>
### FIX-19 — `pressureSetpoint` docstring (P3)

**Problem:** says "35.5 barg abs" for 3,650,000 Pa (= 36.5 bara).

<a id="fix-23"></a>
### FIX-23 — PF-LOWTEMP and C-ISO fight over `coilOpen` (P2)

**Where:** the `coilOpen[i]` `when/elsewhen` chain and the
`lowTempPending[i]` block.
**Problem:** PF-LOWTEMP closes a coil that is below an absolute
threshold, typically only a few K below the hottest. With C-ISO on, the
reopen test `T_gas_out_max − T_gas_out_frozen[i] < 35 K` is then true at
the next event iteration, so the coil reopens; `lowTempPending[i]` is not
reset on closing and its dwell has already elapsed, so the close fires
again: a close/reopen loop at one instant (event iteration may not
converge) or rapid chatter. PF-LOWTEMP can only hold a coil shut that is
≥ 35 K below the hottest, which C-ISO already handles at 40 K. Not seen
because PF-LOWTEMP is off and its threshold is 0 K.
**Fix:** reset `lowTempPending[i]` when the coil closes; remember why a
coil was closed (C-ISO vs PF-LOWTEMP) and let each rule reopen only what
it closed, which is what the state machine in FIX-20 gives. Fold
PF-LOWTEMP into C-COLDSHUT as variant b at the same time.

<a id="fix-24"></a>
### FIX-24 — Coil valves at the inlet only (P3)

**Where:** `CoilAssembly2ch/3ch/4ch`: `KvValue_in1` drives the inlet
valve only.
**Problem:** a shut assembly stays open to the return header, so its gas
breathes with near-zero, sign-changing flow. R-FROZEN hides the
temperature flicker, but TF's Structure branch (valve-only isolation)
broke `nonlinear[8]` with exactly this reversing outlet flow; CS and TF
now close both ends (R-BOTHENDS).
**Fix:** add an outlet valve driven by `KvValue_in1 · outletKvRatio`, as
in `TFCoilBusUpper`, if PF shows solver trouble during isolation.

<a id="fix-25"></a>
### FIX-25 — Evaporator one well-mixed cell, likely oversized (P2)

**Where:** `tube1` (60 × 12 mm × 10 m), `nCells` not set; only
`heatPort[1]` is connected to `coldSurface`.
**Problem:** TF started from this PF tube and found that a single
well-mixed cell capped the effectiveness and hid a ~4× UA oversizing
versus ATEKO (TF resized it 2026-10-06 to 4.5 m with 5 cells). PF's
supply may reach its setpoint only because of this.
**Fix:** `nCells` = 5 with one 77 K port per cell, sized against ATEKO's
PF duty, as TF did; then FIX-08.

<a id="fix-26"></a>
### FIX-26 — Power-cap PI integrates while gated shut (P3)

**Where:** `PID_circulatorPower`, `PF_RV01Command`.
**Problem:** the PI always runs; the gate (`T_gas_out_max` ≤ 140 K, time
≥ 5 s) only forces the valve command to `Kv_shut`. If `P_shaft` exceeds
`P_shaftLimit` before the gate opens, the integrator winds toward
y = −10 and PF_RV01 steps toward Kv 500 (over `valveRampTime`) the moment
the gate opens. Off by default, and in the 2026-09-02 baseline `P_shaft`
crossed the old 40 kW limit only at ~127 K, so not seen yet.
**Fix:** hold or re-initialise the integrator while gated, or move to
the common power mode with a flow floor.

---

## CS

<a id="fix-14"></a>
### FIX-14 — C-RV01 power mode unvalidated (P2)

**Problem:** `rv01Goal = Power` added 2026-10-22, never run.
`P_shaftLimit` 20 kW, `dm_flowPowerMax` 0.1 kg/s, `k_powerPID` 6e-6,
`Ti_powerPID` 60 s are all ASSUMED.
**Fix:** run power mode; check `P_shaft` settles near the limit and loop
flow stays ≥ `m_flow_set`; retune.

<a id="fix-15"></a>
### FIX-15 — Loop-side flow not measured on the plant (P2, plant)

**Problem:** `PID_RV01` reads `m_flow_loop = Heater.portA.m_flow`,
downstream of the RV01 tee. FM01 (`sensor_m_flow`) sits upstream on PFD
22178 and reads loop + bypass.
**Fix:** a meter on the loop side, or FM01 minus an RV01 flow estimate.
Raise it with the PFD owner.
