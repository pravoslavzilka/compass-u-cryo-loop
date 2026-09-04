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

`fan2ndOrder`: `T_nominal`=116 K, `p_nominal`=2.5 MPa(a), sized from
`m_total` at suction density; `dp_nominal`=2 bar as a working estimate
covering header/heater/evaporator/coil/valve losses (ATEKO's own
channel-only table gives ~0.18 bar/channel, excluding those other losses).
Remaining circulator parameters (`n_nominal`, `eta_maxPhyd`, fan-curve
shape) carried from PFCircuit.mo's circulator.

## Status

Translates and simulates successfully (StopTime=1800s). This is a first
working version -- individual parameters (flow split, initial
temperatures, heat transfer coefficients, roughness/friction model) are
expected to be tuned in a later optimization pass rather than in this
sizing document.
