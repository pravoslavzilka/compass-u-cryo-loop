# TF circuit — control logic

Model: `dymola-thermal-systems/CoilLoopCompassU/TF/TFCircuit.mo`.
Requirements from the sources: [requirements.md](requirements.md).
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

## Flow path

```
fan2ndOrder (CC01) → Heater (EH01) → junction6 → junction1 ─┬─► junction22 → RV07 / RV08            pressure tee (discharge side)
                                                            ├─► valve5 (RV02) ───────────────────┐   evaporator bypass
                                                            └─► valve6 → tube1 (HE01) → valve3 ──┤
      junction7 (mixing node, sensor_T) ◄──────────────────────────────────────────────────────────┘
          → junction21 ─┬─► valve4 ─► junction20                                                      coil bypass (archived)
                        └─► junctionSupply ─┬─► junctionCL → TFCL1 (+ Structure if connected)
                                            └─► junctionUL → TFUL1, TFUL2
      → junctionReturnCL / junctionReturnUL → junctionReturn → junction20 → junction4 → fan2ndOrder
```

Structure sits between `junctionCL` and `junctionReturnCL` and is connected
at both ends only when `connectStructure` = true. valve5 is RV02 on the
PFDs; the other valves are not mapped to PFD numbers here (the PFD has no
text layer; see FIX-07).

## How the pieces connect

```
coil outlet temps ──► T_gas_out_max (frozen for shut busses) ──► coilOpen[i], coldShut[i]   (C-ISO, C-COLDSHUT)
                                                                        │
                                                                        └──► kvTarget_TF[i] ──► bus inlet valve (+ outlet valve, upper limb: R-BOTHENDS)
wall temps (coil busses only) ──► T_wallHotCooled ──► wanted_temp (C-TEMP-SP-b) ──► PID ──► heater / valve6 / valve5   (C-TEMP-SR)
wall temps ──► T_wallHotLive ──► allReleased (C-COLDSHUT release-all)
discharge pressure ──► PID_pressure ──► RV07 / RV08                                          (C-PRES-a, independent)
```

The bus valves are commanded by one expression per branch:

```
kvTarget_TF[i] = flowing[i] ? valveKvNominal_TF[i] : Kv_shut  → first-order lag (3 s) → bus valve
flowing[i]     = allReleased or (coilOpen[i] and not coldShut[i])      (the structure is never isolated, never cold shut)
T_gas_out_compare_TF[i] = flowing ? T_gas_out_TF[i] : T_gas_out_frozen[i]      (R-FROZEN)
```

---

## Common algorithms — what differs in TF

### C-SPEED-a
`smoothStep` 200 → 200 Hz: constant speed from t = 0.

### C-PRES-a
`pressureSetpoint` = 2.5 MPa (24 barg at the CC outlet, ATEKO S6.5.3);
reservoirs 27 / 23 bar. `kPressurePID` = 0.05, `TiPressurePID` = 30 s,
`KvGain` 5 / `KvMax` 30 (placeholders, scaled from PF), y ±7.5,
`valveRampTime` = 3 s. Node: discharge side (`junction22` off the
evaporator inlet tee `junction1`); the sensor is `sensor_p_discharge` (renamed from
`sensor_p_suction`, FIX-17).

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

Since 2026-11-03 the cold shut-off re-freezes `T_gas_out_frozen[i]` only while
the branch flows (`(pre(allReleased) and isCoil_TF[i]) or pre(coilOpen[i])`),
so a bus already isolated by C-ISO keeps its R-FROZEN value (FIX-04, not yet
simulated).

### C-OVERCOOL (archived)
Copied unchanged from PF: valve4 Kv 5000 when open, gated by `time ≥
controlActivationDelay`.

---

## Robustness measures used

R-HYST, R-SMOOTH, R-FROZEN, R-BOTHENDS (upper-limb busses only,
`TFCoilBusUpper.outletKvRatio`), R-EVAPDECOUPLE, R-ACTDELAY (5 s; also
gates C-COLDSHUT because the gas starts at 80 K = `T_coldShut`).
Not used: R-KVFLOOR.

## Plant-model assumptions (not control)

* **Evaporator:** `tube1` 60 × 12 mm × 4.5 m, `nCells` = 5, wall held at
  77 K on every cell. Resized 2026-10-06 to about 1.5 × the UA implied by
  ATEKO S6.5.3/S7.2 (138.8 kW, 1.3 kg/s, 100.6 → 80 K against 77 K LIN);
  PF's copy of this tube was one cell and about 4× oversized (FIX-25).
  No LIN-side boiling resistance and no cap at the LIN supply (1.3 kg/s,
  ATEKO S7.2), unlike CS (FIX-08).
* **Startup:** coil busses at 137 K, Structure and loop gas at 80 K, busses
  open at t = 0: a 57 K step at first contact (FIX-01).
* **Static flow split:** with no flow control, `KvUpperLimb` = 45 and
  `Structure.valveKvNominal` = 12 are tuning values, not plant data; see
  their docstrings in `TFCircuit.mo` and FIX-07.
* **Heater:** `Heater` is the EH01 stand-in; ATEKO S6.1 requires it for TF.


**Revision history:** 2026-11-04 flow path, signal map and plant-model assumptions
added; FIX-04 noted (no code change).
2026-10-22 created from `TFCircuit.mo` at commit
2ecd589.
2026-10-22: `TFCircuit.mo` tagged with algorithm IDs, stale comments
fixed (no code change). Open problems: [to-fix.md](../to-fix.md).
