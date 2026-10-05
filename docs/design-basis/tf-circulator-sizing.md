# TF Coil Cooling Loop — Design Basis

Closed-loop helium cooling for the COMPASS-U TF (toroidal-field) coil,
modeled in `CoilLoopCompassU.TF.TFCircuit`, structurally parallel to
`CoilLoopCompassU.PF.PFCircuit`. Source: ATEKO study 22172-Z-R1.

## Topology

Four coil branches, each behind its own isolation valve:

| Branch | Model | Channels | Length | Material | Wall mass |
|---|---|---|---|---|---|
| TF core + lower limb | `TFCL1` (`TFCoilBusCoreLower`) | 112 | 9.2 m | OFHC copper, RRR~30 | 13,900 kg |
| Coil case / support structure | `Structure` (`TFStructure`) | 120 | 3.5 m | 316LN stainless | 250,000 kg |
| TF upper limb | `TFUL1` + `TFUL2` (`TFCoilBusUpper`) | 56 each (112 total) | 7.7 m | OFHC copper, RRR~30 | 7,808 kg total |

Upper and lower support structure are modeled together as one lumped
`TFStructure` instance.

An overcool bypass branch (`junction21` -> `valve4` -> `junction20`) routes
supply gas straight from the heater/evaporator mixing node to the circulator
suction, around all coil branches. It is copied unchanged from
`PFCircuit.mo` (same volumes, Kv 5000 open / 0.001 shut, same
`valve4Open`/`overCoolRecovering` state machine and margins) and is disabled
by default (`enableOverCoolPrevention`/`enableOverCoolRecovery` = false).

Coil channels (core+lower and upper limb) are 6x10mm elliptical, flow area
47.12 mm², wetted perimeter 25.53 mm², hydraulic diameter 7.38 mm.
`TFStructure`'s channels are circular, 20 mm bore.

## Operating point

- Total design flow: `m_total` = 1.3 kg/s
- Suction pressure setpoint: 2.5 MPa(a) (~24 barg)
- Coolant (gas) initial temperature: 80 K, uniformly
- Wall (metal) initial temperature: 137 K for the coil branches (TFCL1,
  TFUL1, TFUL2), 80 K for Structure
- Discharge heat load: 0 for all branches -- coil thermal mass is
  represented via the elevated wall initial temperature rather than a
  discharge heat pulse
- Max coolant-to-coil temperature difference: 40 K (`tempMargin`)

## Heat transfer and pressure drop

`TFCL1`/`TFUL1`/`TFUL2` use `NonCircular` tube geometry (direct flow
area/perimeter, not derived from hydraulic diameter) with `ConstantAlpha`
(gas-side heat transfer) and `ConstantR` (wall conduction), since the
library's geometry-based correlations only support circular tubes.
`Structure` uses `GnielinskiDittusBoelter` directly (its geometry is
genuinely circular). All branches use the `Konakov` pressure-drop
correlation.

## Circulator

`fan2ndOrder`: `T_nominal`=116 K, `p_nominal`=2.5 MPa(a) (from ATEKO).
Re-sized on 2026-10-05 to the operating point the loop actually reaches in
simulation: `V_flow_nominal`=0.145 m³/s, `dp_nominal`=0.7 bar,
`V_flow0`=0.175 m³/s (1.21×, PF's ratio). The earlier placeholder
(`dp_nominal`=2 bar, `V_flow_nominal`=0.125 m³/s) left the circulator at
~96% of its zero-head flow with efficiency 0.25–0.30 (PF: 0.63–0.66) and
28–55 kW shaft power for 7–14 kW hydraulic. The loop itself only needs
0.47–0.94 bar at ~1.3–2 kg/s. Target after re-sizing: efficiency ~0.6 and
~17 kW shaft power, within ATEKO §7.3's 25 kW electrical budget.
`n_nominal`, `eta_maxPhyd` and the fan-curve shape are carried from
PFCircuit.mo's circulator.

## Status

Translates and simulates successfully (StopTime=1800s). This is a first
working version -- individual parameters (flow split, initial
temperatures, heat transfer coefficients, roughness/friction model) are
expected to be tuned in a later optimization pass rather than in this
sizing document.
