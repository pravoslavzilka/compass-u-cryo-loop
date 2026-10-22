# Documentation

## Layout

| Path | Content |
|---|---|
| `docs/control-common.md` | Control algorithms shared by more than one circuit, each with a stable ID (`C-…`), plus shared robustness measures (`R-…`). Definitions only: what the algorithm does, its parameters, its variants. |
| `docs/cs/control-logic.md` | CS circuit: which algorithms it uses (linked by ID), their tier and default state, what differs in CS, and the CS-only algorithms (`CS-…`). |
| `docs/pf/control-logic.md` | Same for PF (`PF-…`). |
| `docs/tf/control-logic.md` | Same for TF (`TF-…`). |
| `docs/{cs,pf,tf}/circulator-sizing.md` | Circulator sizing derivations (design basis), numbers tagged [FROM SOURCE] / [CALCULATED] / [ASSUMED]. |
| `docs/pf/pf_circulator_sizing.py` | Reproduces the PF sizing numbers from a result file. |
| `docs/pf/pid-sensitivity-report.md` | One-off PF investigation report (mass-flow/pressure sensitivity to PID and isolation tuning). |
| `docs/to-fix.md` | Open problems found in reviews, all circuits, with IDs (`FIX-…`) and status. Close an item by marking it done with the commit, not by deleting it. |
| `docs/migration-notes.md` | Chronological troubleshooting log (bugs, root causes), all circuits. |

Requirement references (`ATEKO S3.4`, `Tab.5`, …) point to the ATEKO study
22172-Z-R1 and the PFDs 22171/22178/22179, kept outside the repo in
`..\materials`.

## Rules for the control docs

- **Keep them in sync with the `.mo` source.** If an algorithm changes,
  update its entry in place and add one line to that entry's revision
  history (date, what changed, why). Don't append a second entry.
- **IDs are stable and never reused.** `C-` common, `CS-`/`PF-`/`TF-`
  circuit-only, `R-` robustness measure. An algorithm that starts in one
  circuit and is adopted by a second one moves to `control-common.md`
  under a `C-` ID; the old ID stays listed as an alias.
- **Variants:** when circuits run different versions of the same
  algorithm, the common entry defines them as `a`, `b`, … and each
  circuit file names the one it uses (e.g. `C-PRES-a`).
- **The code names the ID** in the comment next to the algorithm
  (`[C-ISO]`, `[CS-PREP]`, …), so code → doc lookup is a grep.

## Tiers

The tier is assigned **per circuit** (the same algorithm can be primary in
one circuit and archived in another), in the circuit file. It is separate
from the default state: a secondary algorithm can be on by default.

| Tier | Rule | Required field in the circuit file |
|---|---|---|
| **Baseline** | Without it the loop is not operable or stable. Never switched off. | — |
| **Primary** | Exists to meet a cited ATEKO / IPP requirement. | Requirement reference |
| **Secondary** | Optional optimization; the requirements are still met with it off. | What it optimizes |
| **Archived** | Removed from the `.mo`, or dead code we don't intend to use. | Last commit containing it, or the flag that keeps it off, and why |

Not tiered: **robustness measures** (`R-…`: hysteresis, smoothing,
frozen temperatures, …), which exist for numerical stability rather than
control intent, and **plant-model assumptions** (e.g. the LIN supply
cap), which belong to the model, not the controller.

## Overview matrix

`B` baseline, `P` primary, `S` secondary, `A` archived, `—` not present;
the variant letter follows where it matters; *off* = disabled by default.

| ID | Algorithm | CS | PF | TF |
|---|---|---|---|---|
| [C-SPEED](control-common.md#c-speed) | Fixed circulator speed | B (b) | B (a) | B (a) |
| [C-PRES](control-common.md#c-pres) | RV07/RV08 pressure control | B (a) | B (b) | B (a) |
| [C-RV01](control-common.md#c-rv01) | Circulator bypass RV01 | B flow; S power *off* | S power-cap (a), *off* | — |
| [C-TEMP-SR](control-common.md#c-temp-sr) | Split-range supply temperature | B | B | B |
| [C-TEMP-SP](control-common.md#c-temp-sp) | Supply temperature setpoint | P (b) | P (a) | P (b) |
| [C-ISO](control-common.md#c-iso) | Per-coil isolation | P | P | P |
| [C-COLDSHUT](control-common.md#c-coldshut) | Shut-off at 80 K + release-all | S | — | S |
| [C-OVERCOOL](control-common.md#c-overcool) | valve4 overcool state machine | A | A | A |
| [CS-PREP](cs/control-logic.md#cs-prep) | Startup coolant preparation | P | — | — |
| [CS-FLOW-SP](cs/control-logic.md#cs-flow-sp) | Loop-flow setpoint per open channel | P | — | — |
| [PF-LOWTEMP](pf/control-logic.md#pf-lowtemp) | Absolute-threshold coil shut-off | — | S *off* | — |
