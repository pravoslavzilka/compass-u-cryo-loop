# PF circuit — control logic

Model: `dymola-thermal-systems/CoilLoopCompassU/PF/PFCircuit.mo`.
Sizing and sources: [circulator-sizing.md](circulator-sizing.md);
tuning study: [pid-sensitivity-report.md](pid-sensitivity-report.md).
Common algorithm definitions: [control-common.md](../control-common.md).
Tier rules: [README](../README.md#tiers). Open problems:
[to-fix.md](../to-fix.md).

Eight coil assemblies (PF1U … PF4L: PF1U/L 4 channels, PF2U/L 2, PF3U/L 3,
PF4U/L 4) start at 160 K; the loop gas outside the coils starts at 80 K.
Helium at 36.5 bara, default run 1815 s.

> `PFCircuit.mo` is **not** tagged with algorithm IDs yet (FIX-18); the
> component names below are how to find each algorithm in the code.

## Summary

| ID | Algorithm | Tier | Default | Requirement / optimizes |
|---|---|---|---|---|
| [C-SPEED-a](../control-common.md#c-speed) | Constant 200 Hz | Baseline | on | — |
| [C-PRES-b](../control-common.md#c-pres) | PressureStabilizer: PI trim + feedforward pulse | Baseline | on | — |
| [C-RV01](../control-common.md#c-rv01) power-cap (a) | PF_RV01 caps shaft power below 140 K | Secondary | **off** (`enableCirculatorPowerOptimization`) | Circulator energy in the cold end of the cooldown |
| [C-TEMP-SR](../control-common.md#c-temp-sr) | Split-range supply temperature | Baseline | on | — |
| [C-TEMP-SP-a](../control-common.md#c-temp-sp) | `wanted_temp` = `T_gas_out_max` − 40 K | Primary | on | ATEKO S3.2, S3.4 |
| [C-ISO](../control-common.md#c-iso) | Per-assembly isolation 40 K / 35 K | Primary | on | ATEKO S6.1, S3.2; IPP coil-to-coil ≤ 40 K |
| [PF-LOWTEMP](#pf-lowtemp) | Absolute-threshold coil shut-off | Secondary | **off** | Flow to the hot coils |
| [C-OVERCOOL](../control-common.md#c-overcool) | valve4 overcool state machine | Archived | off | Kept off by `enableOverCoolPrevention = enableOverCoolRecovery = false` |

Not used in PF: C-COLDSHUT, startup preparation, a loop-flow setpoint
(with RV01 shut, the coil flow is whatever the fixed-speed circulator
delivers; `m_total` = 0.1 kg/s is declared but not used by any
controller).

## Flow path

```
fan2ndOrder (CC01) → sensor_m_flow → junction5 ─┬─► PF_RV01 ─► junction4 (suction)        circulator bypass
                                                └─► Heater (EH01) → junction7 ─┬─► valve5 ──────────────────┐   evaporator bypass
                                                                               └─► junction6 ─┬─► valve6 → tube1 (HE01) → valve3 ─┤
                                                                                              └─► junction22 → RV07/RV08          │   pressure tee (discharge side)
      junction23 (mixing node, sensor_T) ◄──────────────────────────────────────────────────────────────────┘
          → junction21 ─┬─► valve4 ─► junction20                                                  coil bypass (archived)
                        └─► supply header → 8 assemblies (inlet ON/OFF valve each) → return header → junction20 → junction4 → fan
```

## How the pieces connect

```
coil outlet temps ──► T_gas_out_max (frozen for shut coils) ──► wanted_temp (C-TEMP-SP-a) ──► PID ──► heater / valve6 / valve5   (C-TEMP-SR)
        │
        └──► coilOpen[i]  ◄── C-ISO (relative 40 K / 35 K)
                          ◄── PF-LOWTEMP (absolute threshold, dwell, global reopen)       ──► kvTarget_PF[i] ──► coil inlet valve
discharge pressure ──► PID_pressure + pulse latches ──► RV07 / RV08                     (C-PRES-b, independent)
fan2ndOrder.P_shaft ──► PID_circulatorPower ──► PF_RV01  (only if enabled and T_gas_out_max ≤ 140 K)   (C-RV01 power-cap a)
```

The coil valves are commanded by a single latch per assembly; both
sequencing rules write it, in **one** `when/elsewhen` chain:

```
coilOpen[i] := true   when C-ISO reopen  or  PF-LOWTEMP global reopen
coilOpen[i] := false  when C-ISO close   or  PF-LOWTEMP dwell elapsed      (freeze T_gas_out_frozen[i])
kvTarget_PF[i]        = coilOpen[i] ? valveKvNominal_PF[i] : Kv_shut  → firstOrderCoilKv[i] (3 s) → KvValue_in1
T_gas_out_compare_PF[i] = coilOpen[i] ? T_gas_out_PF[i] : T_gas_out_frozen[i]
```

The valve sits at the assembly **inlet only**; a shut assembly stays open
to the return header (no R-BOTHENDS).

---

## PF-only algorithms

<a id="pf-lowtemp"></a>
### PF-LOWTEMP — Low-temperature coolant optimization

**Tier:** Secondary, off (`enableLowTempCoolantOptimization` = false).
**Optimizes:** stops spending flow on assemblies that are already cold
while enough others are still hot.
**Components:** `lowTempOtherHotCount_PF[]`, `lowTempPending[]`,
`lowTempPendingSince[]` → the shared `coilOpen[]` latch.

```
hotOthers[i] = number of OTHER assemblies with T_gas_out_compare > threshold
pending[i]  := true   when T_gas_out[i] < threshold and hotOthers[i] ≥ minHotOthers and coil open   (stamp time)
pending[i]  := false  when T_gas_out[i] ≥ threshold or hotOthers[i] < minHotOthers
close i              when pending[i] for lowTempCoolantOptimizationMinDuration (10 s)
reopen all           when T_gas_out_max < threshold
```

| Parameter | Value | Note |
|---|---|---|
| `lowTempCoolantOptimizationThreshold` | **0 K** | Inert even when enabled; raise (e.g. 80 K) together with the switch. The count is evaluated even while disabled, so a non-zero threshold with the switch off still generates events. |
| `lowTempCoolantOptimizationMinHotOthers` | 2 | |
| `lowTempCoolantOptimizationMinDuration` | 10 s | Debounce, same pattern as C-OVERCOOL's settle timer. |

**Interaction with C-ISO (known conflict, FIX-23).** PF-LOWTEMP closes a
coil that may be only a few K below the hottest one. C-ISO's reopen test
(`T_gas_out_max − frozen < 35 K`) is then immediately true, so C-ISO
reopens it, and the still-elapsed dwell closes it again. With both rules
on, PF-LOWTEMP can only hold a coil shut when it is ≥ 35 K below the
hottest — a band C-ISO already covers from 40 K. It has never been run
enabled.

---

## Common algorithms — what differs in PF

### C-SPEED-a
`smoothStep` 200 → 200 Hz: constant speed from t = 0, no soft start.

### C-PRES-b
Full description in
[control-common.md](../control-common.md#c-pres-b-details).

| Parameter | Value |
|---|---|
| `pressureSetpoint` | 3.65 MPa (36.5 bara) |
| Make-up pulse armed / disarmed | `pMakeupOpen` 34 bar / `pMakeupClose` 35 bar |
| Relief pulse armed / disarmed | `pReliefOpen` 39 bar / `pReliefClose` 37.5 bar |
| Reservoirs | 45 / 30 bar, 80 K, each behind a 10 l buffer volume |
| `PID_pressure` | k 0.05 /Pa, Ti 30 s, y ±7.5 |
| Trim | `KvGain` 2, `KvMax` 15 (7.5 × 2 = 15: R-WINDUP holds) |
| Pulse | Kv 60; mass target from `V_loopEffective` 0.5 m³, `T_loopEstimate` 80 K (placeholders) |
| `valveRampTime` | 3 s; `Kv_shut_pressureValves` 1e-2 |

Node: `junction22` off `junction6`, the evaporator inlet tee after the
heater — the circulator **discharge** side, despite the sensor name.
Several PF docstrings still quote old thresholds (FIX-18).

### C-RV01 power-cap (a)
`P_shaftLimit` = 50 kW, trigger `T_gas_out_max` ≤ 140 K
(`valve1PowerLimitTriggerTemp`) and `time` ≥ 5 s, `kPowerLimitPID`
= 0.0005 /W, `TiPowerLimitPID` = 60 s, y ∈ [−10, 2],
`KvGainPowerLimit` = 50, `KvPowerLimitMax` = 500 (R-WINDUP holds), lag
`valveRampTime`. Full description in
[control-common.md](../control-common.md#c-rv01-power-cap-details).

`PID_circulatorPower` integrates whether or not the gate is open; if
`P_shaft` exceeds the limit before the 140 K trigger, the valve steps
open by the accumulated amount when the gate opens (FIX-26). If PF gets
a flow setpoint, this should move to the common power mode with a flow
floor.

### C-TEMP-SR
| Parameter | PF |
|---|---|
| `Kv_cool_max` / `Kv_gain` (valve6) | 5000 / 100 |
| valve5 open Kv / gain | 500 / 10 (literals in `BypassLimiter`), shut at y = −50 |
| `bypass_limit` | 10 |
| valve3 (fixed) | 4000 |
| `heater_gain` | 100 W per unit |
| `PID` | k 0.12, Ti 12 s, y ±60, **`y_start` = 5** |

Differences from CS/TF worth knowing:
- `PID.y_start` = 5 starts with the heater gate on. TF changed this to 0
  after it heated the supply to ~117 K for the first ~40 s (FIX-11).
- No R-KVFLOOR on valve6: for 0 < `PID.y` < 0.7 the commanded Kv is
  negative (FIX-03).
- `bypass_limit` = 10 / gain 10: valve5 only starts throttling at
  `PID.y` < −10.3; TF lowered both because valve5 otherwise stayed fully
  open while the supply drifted (FIX-13).

`sensor_T` sits on the mixing node `junction23`; `sensorTFiltered` (3 s)
is for reporting only.

### C-TEMP-SP-a
`wanted_temp = T_gas_out_max − 40 K`, no floor. `T_gas_out_max` uses
frozen values for isolated assemblies. CS and TF moved to variant b
(hottest cooled wall, floored at 77 K) — open decision, FIX-12.

### C-ISO
All eight assemblies, 40 K close / 35 K reopen. Reopen gated by
`controlActivationDelay` = 5 s; close not gated (FIX-05). Shares the
`coilOpen` latch and the frozen temperature with PF-LOWTEMP, in one
`when/elsewhen` chain. The close test reads the live outlet (`T_gas_out_PF`,
guarded by `pre(coilOpen)`), the reopen test the frozen one.

### C-OVERCOOL (archived)
valve4 Kv 5000 when open (0.001 shut), gated by `time ≥
controlActivationDelay`. The branch, four state variables and six
parameters remain in the `.mo` (FIX-10).

---

## Robustness measures used

R-HYST, R-SMOOTH (valve6 2 s, heater/valve5 1 s, valve4/coil valves 3 s,
RV07/RV08/PF_RV01 `valveRampTime`), R-FROZEN, R-EVAPDECOUPLE (valve3),
R-ACTDELAY (5 s), R-WINDUP (PID_pressure, PID_circulatorPower).
Also PF-specific: buffer volumes between RV07/RV08 and their ideal
reservoirs, `Kv_shut_pressureValves` = 1e-2 instead of 1e-4.
Not used: R-BOTHENDS, R-KVFLOOR.

## Plant-model assumptions (not control)

* **Evaporator:** `tube1` 60 × 12 mm × 10 m, `nCells` not set (library
  default) and only `heatPort[1]` tied to the 77 K wall. TF found that a
  single well-mixed cell hid a ~4× UA oversizing of this same PF-copied
  tube (FIX-25). No LIN-side boiling resistance or LIN supply cap (FIX-08).
* **Startup:** coils at 160 K, loop gas at 80 K, coils open at t = 0 — an
  80 K step at first contact (FIX-01).

**Revision history:** 2026-10-22 created from `PFCircuit.mo` at commit
2ecd589; absorbs the former `docs/algorithms.md` (now in
`control-common.md` under C-PRES-b and C-RV01).
2026-10-22: flow path, signal map, PF-LOWTEMP/C-ISO conflict, full
C-PRES-b and C-RV01 parameter tables, plant-model notes added from a
review of `PFCircuit.mo` (no code change); problems moved to
[to-fix.md](../to-fix.md).
