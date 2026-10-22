# TF circuit — control logic

Model: `dymola-thermal-systems/CoilLoopCompassU/TF/TFCircuit.mo`.
Sizing and sources: [circulator-sizing.md](circulator-sizing.md).
Common algorithm definitions: [control-common.md](../control-common.md).
Tier rules: [README](../README.md#tiers).

Four branches, order `TFCL1, Structure, TFUL1, TFUL2`: one core/lower
coil bus, the support structure, and two upper-limb coil busses (224
channels on 4 busses, ATEKO S3.3.3). Coil busses start at 137 K, the
structure and loop gas at 80 K. The structure branch is disconnected by
default (`connectStructure` = false).

## Summary

| ID | Algorithm | Tier | Default | Requirement / optimizes |
|---|---|---|---|---|
| [C-SPEED-a](../control-common.md#c-speed) | Constant 200 Hz | Baseline | on | — |
| [C-PRES-a](../control-common.md#c-pres) | RV07/RV08 pressure PI | Baseline | on | — |
| [C-TEMP-SR](../control-common.md#c-temp-sr) | Split-range supply temperature | Baseline | on | — |
| [C-TEMP-SP-b](../control-common.md#c-temp-sp) | `wanted_temp` = hottest cooled wall − 40 K, ≥ 77 K | Primary | on | ATEKO S3.2, S3.4 |
| [C-ISO](../control-common.md#c-iso) | Per-bus isolation 40 K / 35 K | Primary | on | ATEKO S6.1, S3.2; IPP coil-to-coil ≤ 40 K |
| [C-COLDSHUT](../control-common.md#c-coldshut) | Shut-off at 80 K (upper limb) + release-all | Secondary | on | Cooldown time of the core/lower bus |
| [C-OVERCOOL](../control-common.md#c-overcool) | valve4 overcool state machine | Archived | off | Kept off by `enableOverCoolPrevention = enableOverCoolRecovery = false` |

Not used in TF: C-RV01 (no circulator bypass in the model), a loop-flow
setpoint (`m_total` = 1.3 kg/s, ATEKO S6.5.3, is documentation only),
startup preparation.

---

## Common algorithms — what differs in TF

### C-SPEED-a
`smoothStep` 200 → 200 Hz: constant speed from t = 0.

### C-PRES-a
`pressureSetpoint` = 2.5 MPa (24 barg at the CC outlet, ATEKO S6.5.3);
reservoirs 27 / 23 bar. `kPressurePID` = 0.05, `TiPressurePID` = 30 s,
`KvGain` 5 / `KvMax` 30 (placeholders, scaled from PF), y ±7.5,
`valveRampTime` = 3 s. Node: discharge side (`junction22` off the
evaporator inlet tee `junction1`); the `junction22` docstring still
calls it the suction node.

### C-TEMP-SR
| Parameter | TF |
|---|---|
| `Kv_cool_max` / `Kv_gain` (valve6) | 5000 / 100 |
| valve5 open Kv / `bypassKvGain` | 500 / 50, shut at y = −10 |
| `bypass_limit` | 2 (PF: 10) |
| `PID` | k 0.12, Ti 12 s, y ±60, `y_start` 0 |

The heater is required in TF (ATEKO S6.1: the support structure is too
heavy for compression heat alone). No R-KVFLOOR on valve6 (same gap as
PF).

### C-TEMP-SP-b
`T_wallHotCooled` counts branches in `inGasOutMax_TF` (Structure only
when connected) that are released coils or open and not cold-shut.
`T_supplyFloor` = 77 K; at the end of the cooldown the floor is what
holds the supply.

### C-ISO
`isolationAllowed_TF` = {true, false, true, true}: the structure is never
isolated (at 80 K vs the coils' 137 K the rule shut it at t ≈ 0.1 s and
it never reopened). Margins 40 K / 35 K; reopen gated by
`controlActivationDelay` = 5 s. `T_gas_out_max` counts only
`inGasOutMax_TF` branches.

### C-COLDSHUT
`shutWhenCold_TF` = {false, false, true, true}: upper limb only — its
shorter 7.7 m channels finish first, and shutting them hands their flow
to TFCL1. `T_coldShut` = `T_releaseAll` = 80 K. `isCoil_TF` excludes the
structure from `T_wallHotLive` and from the release (its wall sits at
~80 K by itself and would block the release). The upper-limb bus valves
are also throttled to `KvUpperLimb` = 45 (default 100) to slow that limb
down.

### C-OVERCOOL (archived)
Copied unchanged from PF: valve4 Kv 5000 when open, gated by `time ≥
controlActivationDelay`.

---

## Robustness measures used

R-HYST, R-SMOOTH, R-FROZEN, R-BOTHENDS (upper-limb busses only,
`TFCoilBusUpper.outletKvRatio`), R-EVAPDECOUPLE, R-ACTDELAY (5 s; also
gates C-COLDSHUT because the gas starts at 80 K = `T_coldShut`).
Not used: R-KVFLOOR.

**Revision history:** 2026-10-22 created from `TFCircuit.mo` at commit
2ecd589.
