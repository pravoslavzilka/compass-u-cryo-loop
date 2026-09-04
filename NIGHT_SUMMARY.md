# CS coil cooling-loop model — summary

Branch: `night/cs-coil-loop-model`, off `development` (checked out fresh,
not stacked on the `night/tf-coil-loop-model` branch — TF's changes are not
present here and this branch's diff does not depend on them). Built live
in chat (not via `night.sh`), per the task brief at (session-local, not
part of this repo) `overNightClaude/examples/02-cs-coil-loop-model.md`.

## What was built

- `dymola-thermal-systems/CoilLoopCompassU/CS/CoilAssembly.mo` — 1-channel
  coil assembly (CS2U/CS2L), reusing PF's exact base-model structure.
- `dymola-thermal-systems/CoilLoopCompassU/CS/CoilAssembly2ch.mo` —
  2-channel coil assembly (CS1/CS3U/CS3L), reusing PF's exact 2-channel
  structure (including the `assemblyIndex` anti-degeneracy offset and
  `KvValue_in1` external control port).
- `dymola-thermal-systems/CoilLoopCompassU/CS/CSCircuit.mo` — full loop:
  fixed-speed circulator, heating-only PID-controlled electric heater,
  evaporator (ideal 77K boundary, same simplification PF uses), a 5-branch
  supply/return manifold (4 junctions each), relative-margin coil isolation
  on the 3 two-channel assemblies, and suction-pressure make-up/relief
  control (`RV07`/`RV08`) with PF's compliant-buffer fix carried over.
- `dymola-thermal-systems/CoilLoopCompassU/CS/CSTest.mo` — single-assembly
  smoke-test harness, analogous to PF's `Test.mo`.
- `dymola-thermal-systems/CoilLoopCompassU/CS/package.order` — registers
  the four new classes.
- `docs/design-basis/cs-circulator-sizing.md` — full parameter-by-parameter
  sourcing, FROM SOURCE/CALCULATED/ASSUMED tags throughout (PF's own
  FIRM/PROVISIONAL/MISMATCH convention doesn't apply — no compiled run
  exists to read FIRM values from).

`PF/`, `TF/`, and every other forbidden path are untouched — verified with
`git diff --stat` against every path the task brief listed (empty output)
and `git diff --name-only development..HEAD` (every changed path starts
with `CS/` or is the design-basis doc). The two pre-existing untracked
files (`docs/design-basis/pf-circulator-sizing.md`,
`pf_circulator_sizing.py`) were read for methodology only, never staged —
confirmed still untracked and byte-identical (checksummed before writing
this file).

## A real correction caught by cross-referencing sources

The CS PFD diagram (`22178-3-R0-S1 - PFD CS COILS.pdf`) labels the channel
cross-section "8x6.2mm" in small print. A first read of that diagram alone
could be misread as "8 channels of 6.2mm diameter" — which would have meant
CS needed a new 8-channel coil-assembly class PF doesn't have. Reading the
ATEKO study's own table (Tab.2) instead of trusting the diagram OCR showed
the real topology: 5 coil objects (CS1, CS2U, CS2L, CS3U, CS3L), each with
only 1–2 channels — "8x6.2mm" is the elliptical channel's cross-section
dimensions, not a channel count. This is why CS reuses PF's existing
`CoilAssembly`/`CoilAssembly2ch` classes directly instead of needing new
topology, and it's flagged here because it's exactly the kind of error an
unattended run reading only the diagram (not cross-checking the text table)
could have shipped silently.

## Key parameters and their sourcing

| Parameter | Value | Tag |
|---|---|---|
| Coil topology | 5 objects, 1–2 channels each | FROM SOURCE (ATEKO Tab.2) |
| Worst-case coil temp | 137.5 K | FROM SOURCE (ATEKO Tab.5, with a flagged "CS1U" naming inconsistency — see design-basis doc §2) |
| Total design flow | 0.17 kg/s | FROM SOURCE (ATEKO §6.5.2) |
| Nominal working (discharge) pressure | 81 barg | FROM SOURCE (ATEKO §6.5.2) |
| tempMargin (inlet-outlet dT) | 40 K | FROM SOURCE (ATEKO §3.4 — explicitly names the signal pair, more precisely sourced than PF's own flagged-UNVERIFIED 40K figure) |
| `dp_nominal` (circulator head) | 17.5 bar | CALCULATED, weakest number — channel-only loss is sourced (~13.7 bar interpolated from ATEKO Tab.9), the margin on top for header/valve/HX losses is an unsourced assumption |
| `p_nominal` | 64.5 bara | CALCULATED, declared directly at true suction — a deliberate improvement on PF's own flagged p_nominal mismatch |

Full table with reasoning: `docs/design-basis/cs-circulator-sizing.md` §3.

## Deliberate simplifications versus PF (documented, not hidden)

PF's `PFCircuit.mo` (1218 lines) has several control refinements added
iteratively after real simulated data existed to debug against —
overcool-prevention/recovery bypass, a circulator-shaft-power limiter, and
a low-temp-coolant-optimization overlay. None of that data exists for CS,
so `CSCircuit.mo` implements PF's core structure only (fixed-speed
circulator, heating-only control, relative-margin coil isolation, plain
PID-trim pressure control) and explicitly does not add refinements PF only
reached through iteration this build has no equivalent access to. Also:
coil isolation only covers CS1/CS3U/CS3L (the two-channel assemblies,
714 kg/16 MJ each) — CS2U/CS2L (349 kg/7.8 MJ, the lighter pair) reuse PF's
plain `CoilAssembly` class, which has no external Kv control port (matching
PF's own unused 1-channel base model), and always run fully open. Full
reasoning: design-basis doc §8.

## What I'm unsure about (uncertainty section)

- **`dp_nominal` = 17.5 bar is the weakest number in this build.** Only the
  channel-only pressure loss (~13.7 bar) is sourced from ATEKO's own
  table; the margin assumed on top for header/valve/heat-exchanger losses
  (28%, landing at a round 17.5 bar) has no basis. Everything downstream
  (`V_flow_nominal`, `p_nominal`, the §7 buildability check) inherits this
  uncertainty.
- **The thesis correction could not be checked.** PF's own worst-case
  temperature was corrected from ATEKO's 137 K to a thesis-sourced 160 K.
  Whether an analogous correction applies to CS's 137.5 K is genuinely
  unknown — `thesis_sis.pdf` exceeds this tool's 20 MB read limit, and the
  page-range PDF renderer (poppler-utils/`pdftoppm`) isn't installed in
  this environment, so no page of it could be read at all. This is an
  environment-level tooling gap, not a skipped step — flag it to whoever
  reviews this if the thesis correction turns out to matter.
- **ATEKO's own "CS1U" label doesn't match any real CS coil name** (the 5
  real objects are CS1/CS2U/CS2L/CS3U/CS3L). Read as a typo for one of
  CS1/CS3U/CS3L based on matching Tab.5's numbers (16 MJ, 714 kg) — not
  independently confirmed.
- **The evaporator (ideal 77K boundary, `nParallelTubes=25`) is unsourced**
  — ATEKO describes a real HE01/HE02+VE01 thermosiphon design (and flags
  that the last few K toward 80K need disproportionate heat-exchanger
  area), neither this model nor PF's attempts that detail.
- **The buildability check (375 m/s tip speed, 598mm diameter) stays under
  PF's cited ~450 m/s single-stage ceiling today**, but the margin (75 m/s)
  is smaller than PF's own margin (127 m/s) and is only as trustworthy as
  the weak `dp_nominal` above.
- **Nothing has been Dymola-verified.** No translate/simulate access exists
  in this environment (`dymola-thermal-systems/CLAUDE_en.md`). Structural
  self-checks pass (within-headers, package.order completeness, top-level
  model/end balance for every file, manual re-read of the full equation
  section for connect()/plain-equation consistency against verified PF
  precedent) but none of that substitutes for an actual compile.
