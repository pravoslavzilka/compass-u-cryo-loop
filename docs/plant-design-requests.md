# Requests for the real cooling-plant design

Things the simulations and control algorithms need that the current PFDs
(22171 PF, 22178 CS, 22179 TF, ATEKO study 22172-Z-R1) do not provide. Each
entry says what is missing, why the control needs it, and what the
alternative is. These are requests to the PFD owner, not model bugs.

Add an entry when a control algorithm depends on a signal or component the
plant doesn't have. Don't delete entries; mark them **agreed**, **rejected**
or **done** with the date and the PFD revision.

## Summary

| ID | Circuits | Request | Linked | Status |
|---|---|---|---|---|
| [PLANT-01](#plant-01) | CS (PF, TF if flow control is added) | Flow meter on the loop side of the RV01 tee | FIX-15, FIX-07 | open, not yet raised |

---

<a id="plant-01"></a>
## PLANT-01 — Flow meter on the coil-loop side of the RV01 tee

**Missing:** each PFD has one circulator flow meter, `X_FM01` (with FT), on
the circulator discharge line **upstream** of the RV01 bypass take-off. It
reads the total circulator flow, loop plus bypass. There is no meter that
reads only the flow to the coils.

**Why it is needed:** the CS flow control (C-RV01 flow mode, and the flow
floor of power mode) regulates the flow *into the coil loop* by opening or
closing RV01. That quantity is `m_flow_loop` in the model, taken at the
heater inlet downstream of the tee. FM01 cannot give it: as RV01 opens, FM01
stays high while the coil flow drops, so a controller reading FM01 would
regulate the wrong quantity. The same applies to CS-FLOW-SP (0.0214 kg/s per
open channel, ATEKO Tab.5) and to the startup preparation check (design flow
circulating). PF and TF have the identical circulator block (`PF_FM01`,
`TF_FM01`, `X_RV01`); if flow control is added there (FIX-07 for TF), they
need the same meter.

**Request:** add a flow meter (FT) on the line from the RV01 tee to the heater
/ supply side, in each circuit that gets flow control (CS first).

**Alternative if no meter can be added:** estimate the loop flow as FM01 minus
the RV01 bypass flow, with the bypass flow computed from RV01's Kv at its
commanded position and the pressure drop across it. That needs pressure
measurements on both sides of RV01 and an accurate Kv curve, and the error
adds directly to the controlled flow. Simulate the estimation error before
accepting this option.

**Status:** open. Not yet raised with the PFD owner.
**References:** FIX-15 and FIX-07 in [to-fix.md](to-fix.md); C-RV01 in
[control-common.md](control-common.md); `m_flow_loop` in `CSCircuit.mo`;
[reading-simulations.md](reading-simulations.md) §2 (signals the plant has).
