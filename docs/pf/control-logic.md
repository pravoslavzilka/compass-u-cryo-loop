# PF circuit — control logic

Model: `dymola-thermal-systems/CoilLoopCompassU/PF/PFCircuit.mo`.
Sizing and sources: [circulator-sizing.md](circulator-sizing.md);
tuning study: [pid-sensitivity-report.md](pid-sensitivity-report.md).
Common algorithm definitions: [control-common.md](../control-common.md).
Tier rules: [README](../README.md#tiers).

Eight coil assemblies (PF1U … PF4L, 2–4 channels each) start at 160 K;
the loop gas outside the coils starts at 80 K.

## Summary

| ID | Algorithm | Tier | Default | Requirement / optimizes |
|---|---|---|---|---|
| [C-SPEED-a](../control-common.md#c-speed) | Constant 200 Hz | Baseline | on | — |
| [C-PRES-b](../control-common.md#c-pres) | PressureStabilizer: PI trim + feedforward pulse | Baseline | on | — |
| [C-RV01](../control-common.md#c-rv01) power-cap (a) | PF_RV01 caps shaft power below 140 K | Secondary | **off** (`enableCirculatorPowerOptimization`) | Circulator energy in the cold end of the cooldown |
| [C-TEMP-SR](../control-common.md#c-temp-sr) | Split-range supply temperature | Baseline | on | — |
| [C-TEMP-SP-a](../control-common.md#c-temp-sp) | `wanted_temp` = `T_gas_out_max` − 40 K | Primary | on | ATEKO S3.2, S3.4 |
| [C-ISO](../control-common.md#c-iso) | Per-coil isolation 40 K / 35 K | Primary | on | ATEKO S6.1, S3.2; IPP coil-to-coil ≤ 40 K |
| [PF-LOWTEMP](#pf-lowtemp) | Absolute-threshold coil shut-off | Secondary | **off** | Flow to the hot coils |
| [C-OVERCOOL](../control-common.md#c-overcool) | valve4 overcool state machine | Archived | off | Kept off by `enableOverCoolPrevention = enableOverCoolRecovery = false` |

Not used in PF: C-COLDSHUT, a loop-flow setpoint (with RV01 shut, the
coil flow is whatever the fixed-speed circulator delivers; `m_total` =
0.1 kg/s is declared but not used by any controller).

---

## PF-only algorithms

<a id="pf-lowtemp"></a>
### PF-LOWTEMP — Low-temperature coolant optimization

**Tier:** Secondary, off (`enableLowTempCoolantOptimization` = false).
**Optimizes:** stops spending flow on assemblies that are already cold
while enough others are still hot.

```
pending[i]  when T_gas_out[i] < threshold and ≥ minHotOthers other assemblies above it
            (cancelled if either stops holding)
close i     when pending[i] for lowTempCoolantOptimizationMinDuration (10 s)
reopen all  when T_gas_out_max < threshold
```

Shares the `coilOpen[i]` latch and the frozen temperature with C-ISO:
either rule can close a coil, and a coil reopens if either rule says so.
`lowTempCoolantOptimizationThreshold` defaults to **0 K**, so it is
inert even when enabled until a real threshold is set.
`lowTempCoolantOptimizationMinHotOthers` = 2.

---

## Common algorithms — what differs in PF

### C-SPEED-a
`smoothStep` 200 → 200 Hz: constant speed from t = 0.

### C-PRES-b
Full description in
[control-common.md](../control-common.md#c-pres-b-details).
`pressureSetpoint` = 3.65 MPa; make-up pulse armed at 34 bar, ended at
35 bar; relief armed at 39 bar, ended at 37.5 bar; reservoirs 45 / 30 bar.
`kPressurePID` = 0.05, `TiPressurePID` = 30 s, trim `KvGain` 2 / `KvMax`
15, pulse Kv 60, `valveRampTime` = 3 s. Node: discharge side (`junction22`
off the evaporator inlet tee `junction6`), despite the sensor name.

### C-RV01 power-cap (a)
`P_shaftLimit` = 50 kW, trigger `T_gas_out_max` ≤ 140 K, `kPowerLimitPID`
= 0.0005 /W, `TiPowerLimitPID` = 60 s, `KvGainPowerLimit` = 50,
`KvPowerLimitMax` = 500, lag `valveRampTime`. Full description in
[control-common.md](../control-common.md#c-rv01-power-cap-details). If
PF gets a flow setpoint, this should move to the common power mode with
a flow floor.

### C-TEMP-SR
| Parameter | PF |
|---|---|
| `Kv_cool_max` / `Kv_gain` (valve6) | 5000 / 100 |
| valve5 open Kv / gain | 500 / 10 (literals in `BypassLimiter`), shut at y = −50 |
| `bypass_limit` | 10 |
| valve3 (fixed) | 4000 |
| `PID` | k 0.12, Ti 12 s, y ±60, **`y_start` = 5** |

Differences from CS/TF worth knowing:
- `PID.y_start` = 5 starts with the heater gate on. TF changed this to 0
  after it heated the supply to ~117 K for the first ~40 s.
- No R-KVFLOOR on valve6: for 0 < `PID.y` < 0.7 the commanded Kv is
  negative.
- `bypass_limit` = 10 / gain 10: valve5 only starts throttling at
  `PID.y` < −10.3; TF lowered both because valve5 otherwise stayed fully
  open while the supply drifted.

`sensor_T` sits on the mixing node `junction23`; `sensorTFiltered` (3 s)
is for reporting only.

### C-TEMP-SP-a
`wanted_temp = T_gas_out_max − 40 K`, no floor. `T_gas_out_max` uses
frozen values for isolated assemblies.

### C-ISO
All eight assemblies, 40 K close / 35 K reopen. Reopen gated by
`controlActivationDelay` = 5 s; close not gated. Shared latch with
PF-LOWTEMP. The coil valve is at the **inlet only** (no R-BOTHENDS).

### C-OVERCOOL (archived)
valve4 Kv 5000 when open, gated by `time ≥ controlActivationDelay`.

---

## Robustness measures used

R-HYST, R-SMOOTH, R-FROZEN, R-EVAPDECOUPLE (valve3), R-ACTDELAY (5 s),
R-WINDUP (PID_pressure, PID_circulatorPower). Not used: R-BOTHENDS,
R-KVFLOOR.

**Revision history:** 2026-10-22 created from `PFCircuit.mo` at commit
2ecd589; absorbs the former `docs/algorithms.md` (now in
`control-common.md` under C-PRES-b and C-RV01).
