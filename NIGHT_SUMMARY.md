# TF coil cooling-loop model — summary

Branch: `night/tf-coil-loop-model`, off `development`. Built live in chat
(not via `night.sh`), per the task brief at (session-local, not part of
this repo) `overNightClaude/queue/01-tf-coil-loop-model.md`.

## What was built

- `dymola-thermal-systems/CoilLoopCompassU/TF/TFCoilBusCoreLower.mo` and
  `TFCoilBusUpper.mo` — the two coil-bus assembly models (56 lumped
  parallel channels each), analogous to PF's `CoilAssembly.mo`.
- `dymola-thermal-systems/CoilLoopCompassU/TF/TFCircuit.mo` — the full
  loop: circulator, electric heater, LIN-side evaporator, 4 coil-bus
  branches with isolation valves, RV07/RV08 make-up/relief pressure
  control at the suction node.
- `dymola-thermal-systems/CoilLoopCompassU/TF/TFTest.mo` — single-bus
  smoke-test harness, analogous to PF's `Test.mo`.
- `dymola-thermal-systems/CoilLoopCompassU/TF/package.order` — registers
  the four new classes.
- `docs/design-basis/tf-circulator-sizing.md` — full parameter-by-parameter
  sourcing, FROM SOURCE/CALCULATED/ASSUMED tags throughout.

`PF/`, `CS/`, and every other forbidden path are untouched — verified with
`git diff --stat` against every path the task brief listed (see the
commands run and their empty output, immediately before this file was
written). The whole diff is confined to the 6 files above.

## What was checked with the user instead of guessed

One real structural fork came up: the TF PDF's schematic shows 6
valve/flowmeter branches, but I wasn't sure whether to model 6 lumped
coil-groups or one instance per physical coil (~16 visible in the torus
drawing). Asked directly — the user chose lumped coil-groups (mirroring
PF's "one assembly per independently-isolated branch" invariant) over
one-instance-per-magnet. Partway through building, the ATEKO study's own
text turned up a more authoritative number for that same question — "4
busses," not 6 (2 of the 6 PFD branches turned out to be a separate,
out-of-scope support-structure circuit) — so the topology actually built
is 4 busses, applying the same principle the user approved with better
data, not a second unilateral change. Documented in
`tf-circulator-sizing.md` S1.

## Key parameters and their sourcing

| Parameter | Value | Tag |
|---|---|---|
| Coil-bus count | 4 (2 core+lower-limb, 2 upper-limb) | CALCULATED — see fork above |
| Worst-case coil temp | 116 K | FROM SOURCE (ATEKO Tab.6) |
| Total design flow | 1.3 kg/s | FROM SOURCE (ATEKO S6.5.3) |
| Nominal pressure | ~24 bara | CALCULATED (barg→bara) |
| `tempMargin` | 40 K | FROM SOURCE (stronger sourcing than PF's own default) |
| `dp_nominal` (circulator head) | 2 bar | CALCULATED, weak — see below |

Full table with reasoning: `docs/design-basis/tf-circulator-sizing.md` S3.

## What I'm unsure about (uncertainty section)

- **`dp_nominal` = 2 bar is a placeholder, not a real calculation.** ATEKO's
  own channel-only pressure-loss table gives ~0.18 bar per channel, but
  explicitly excludes header/heater/evaporator/valve losses ("have to be
  evaluated by cryogenic system supplier" — ATEKO's own words, not mine).
  I picked 2 bar as headroom above the channel figure and sanity-checked it
  against a shaft-power estimate (~42 kW vs ATEKO's own 25 kW TF circulator
  estimate — a smaller gap than PF's real-vs-estimate gap turned out to be,
  so not obviously unreasonable, but still a guess). This is the single
  weakest number in the whole model.
- **4-bus channel split (56/56/56/56) is assumed, not sourced.** ATEKO
  states 4 busses and 224 channels total but never says how the two
  112-channel groups map onto those 4 busses. I split evenly by type,
  mirroring PF's own U/L pairing convention, but this is a guess.
- **No thesis-derived temperature correction applied.** PF's own design
  basis adds +23 K on top of its ATEKO figure (137 K → 160 K), citing
  "thesis S6.1." I did not read the thesis PDF in this pass to check
  whether an analogous TF correction exists, so 116 K is used as-is,
  FROM SOURCE, unadjusted. If the thesis has a TF-specific correction,
  `T_nominal` and every coil-bus `TInitial` should be revised and this
  design basis re-derived.
- **Cannot verify any of this compiles.** No Dymola access from this
  session (network-isolated VM, per `CLAUDE_en.md`). Structural checks
  (brace/paren balance, `within` headers, `package.order` completeness)
  were run and pass, but that is not the same as a successful translate.
  First real test happens whenever this gets copied into the VM and
  translated there.
- **Heater and evaporator geometry are not independently sized for TF** —
  carried over from PF with only a cosmetic bore widening, not a real
  calculation against TF's ~3.4× larger design flow.

## What I did not do

- Did not read `material/thesis_sis.pdf` in this pass (see temperature
  correction item above).
- Did not model the support-structure cooling circuit (out of scope, same
  boundary PF's own model uses — see design-basis S1 for the reasoning).
- Did not attempt any real hydraulic (header/valve/HX) pressure-drop
  calculation for `dp_nominal` — flagged as the weakest number instead of
  faked.
