# CS-Coil Cooling-Loop Circulator — Design Basis

| | |
|---|---|
| **Title** | CS-coil cooling-loop circulator sizing — design basis |
| **Date** | 2026-09-04 |
| **Author** | _(placeholder — fill in)_ |
| **Model file** | `dymola-thermal-systems/CoilLoopCompassU/CS/CSCircuit.mo`, component `fan2ndOrder` (`ThermalSystems.GasComponents.Fans.Fan2ndOrder`) |
| **Applies to git commit** | `f48942d` — "CS: add CSTest.mo run harness and register classes in package.order" |
| **Real-data source** | None — no Dymola access (see "Cannot run Dymola" below), no compiled `result.mat` exists for CS. |

**Tagging convention (adapted from PF's design-basis doc for a model with no
compiled run to read from):** every number below is marked **[FROM
SOURCE]** (read directly off a cited ATEKO 22172-Z-R1 page/table/section),
**[CALCULATED]** (derived here from a stated formula and at least one FROM
SOURCE input), or **[ASSUMED]** (no CS-specific source or derivation —
carried from PF's validated choice, or a bare estimate). Nothing here is
**[FIRM]** in PF's sense of that word — PF's design-basis doc reads FIRM
numbers from a real, successfully-simulated `result.mat`; this model has
never been translated, let alone simulated (see "Cannot run Dymola"). Do
not read a CALCULATED number here as verified — it is exactly as good as
its formula and its FROM SOURCE inputs, no better.

---

## 1. Context

Closed-loop helium circulator for the COMPASS-U tokamak CS (central
solenoid) cooling loop, modeled in Dymola/TIL
(`CoilLoopCompassU.CS.CSCircuit`). Loop topology: circulator (`fan2ndOrder`)
→ electric heater (`Heater`, off in normal cooldown operation, per ATEKO
S6.1) → helium/LIN evaporator (`tube1`, cooled by an ideal 77 K
`coldSurface` boundary — same simplification PF's own model makes; see §9)
→ supply manifold (`junctionS1`–`junctionS4`) → 5 CS coil assemblies (`CS1`,
`CS2U`, `CS2L`, `CS3U`, `CS3L`) → return manifold (`junctionR1`–`junctionR4`)
→ suction tee (`junction22`) → circulator. Suction-node pressure is held by
a make-up/relief valve pair (`RV07`/`RV08`) against two ideal storage-
reservoir boundaries, discharge floats to suction plus loop head — same
architecture as PF's stabilizer, simplified (see §8).

**Topology note, corrected during this build (see NIGHT_SUMMARY.md):** the
CS PFD (`22178-3-R0-S1 - PFD CS COILS.pdf`) shows 5 valve branches, and a
first read of that diagram (small print, elliptical channel cross-section
labeled "8x6.2mm") could be misread as "8 channels per coil." **[FROM
SOURCE, ATEKO Tab.2]** corrects this: "8x6.2mm" is the elliptical channel's
cross-section dimensions, not a channel count — each of the 5 CS coil
objects has only 1–2 real channels, matching PF's own per-object channel
pattern exactly. This is why CS reuses PF's existing `CoilAssembly`
(1-channel) and `CoilAssembly2ch` (2-channel) classes directly rather than
needing a new topology.

## 2. Requirement

Source: ATEKO study 22172-Z-R1, §3.3.2, §3.4, §3.5, §5.1.2, §5.2.2, §6.5.2.

- Cool CS coils to ≤ 80 K from RT (target 80 K, system projected to a
  minimum of 77 K but not required to reach it — §3.4). **[FROM SOURCE]**
- Worst thermal case (hot restart): coils return at **137.5 K** (ATEKO
  Tab.5, "the worst condition is for CS1U" — this label doesn't match any
  of the 5 actual CS coil object names (`CS1`/`CS2U`/`CS2L`/`CS3U`/`CS3L`);
  Tab.5's own numbers — 16 MJ, 714 kg — match CS1/CS3U/CS3L exactly (the
  three heavier coils, vs. 349 kg/7.8 MJ for CS2U/CS2L), so "CS1U" is read
  here as a typo in the source document for one of those three, not a
  sixth coil. **[FROM SOURCE, with a flagged naming inconsistency]** — cf.
  PF's own design basis, which found and corrected an analogous ATEKO
  labeling issue (its worst-case coil PF3U vs. the document's own numbers).
- Max temperature difference 40 K, **explicitly named as (T inlet − T
  outlet)** — ATEKO §3.4. **[FROM SOURCE]** — notably more precise than
  what PF's own design-basis doc could confirm for the same figure (PF's
  doc marks its 40 K requirement **[UNVERIFIED]** because it couldn't
  confirm which signal pair it bounds; ATEKO states the CS pair directly).
- Cooldown window: 30 min design (15 min leads to critical/choked flow per
  ATEKO Tab.10 — same finding pattern as PF's own Tab.8). **[FROM SOURCE]**

**Unread source, flagged honestly:** PF's design basis cites its own coil's
worst-case temperature as a document-corrected 160 K, not the 137 K ATEKO
gives — a correction sourced from "PF thesis §6.1" (`thesis_sis.pdf`). This
document could **not** check whether an analogous correction applies to
CS's 137.5 K: `thesis_sis.pdf` exceeds this tool's 20 MB read limit, and
the page-range PDF renderer (`pdftoppm`/poppler-utils) is not installed in
this environment, so no page of it could be read at all this pass. See
Open Items — this is a real, environment-level gap, not a skipped step.

## 3. `fan2ndOrder` — parameter derivation

No compiled model exists, so nothing here is read from a `result.mat` —
every value is either **[FROM SOURCE]** (ATEKO) or **[CALCULATED]**/
**[ASSUMED]** from it, shown with its formula.

| Parameter | Value | Tag | Derivation |
|---|---|---|---|
| `n_nominal` | 200 Hz (12,000 rpm) | **[ASSUMED]** | Carried from PF's own validated choice (PF's design-basis doc confirms 200 Hz as realistic for a helium cryo-circulator, buildability-checked). No CS-specific vendor curve exists to size this independently — see §7 for the buildability recheck at CS's own dp/flow. |
| `dp_nominal` | 1,750,000 Pa = 17.5 bar | **[CALCULATED, weakest number in this document]** | ATEKO Tab.9 (CS1U pressure-loss table) gives channel-only loss at 137 K: 13.89 bar at 80 barg inlet, 13.00 bar at 85 barg. Linear interpolation to the proposed 81 barg working pressure (ATEKO §5.3.2) gives **13.71 bar, channel-only**. ATEKO's own table explicitly excludes header/valve/heat-exchanger losses (same caveat PF's design basis flags for its own `dp_nominal` provenance, §11). A flat +28% margin is assumed for those — chosen only to land dp_nominal at a round 17.5 bar, not derived from any header/valve loss estimate. **Treat this as an order-of-magnitude placeholder, not a sized value** — same weakness TF's build flagged for its own `dp_nominal`. |
| `V_flow_nominal` | 0.0075 m³/s | **[CALCULATED]** | `mdot_design / rho_suction`. `mdot_design` = 0.17 kg/s **[FROM SOURCE, ATEKO §6.5.2]**. `rho_suction`: ideal-gas He at 64.5 bara (= 82 bara discharge − 17.5 bar `dp_nominal`), 137.5 K → ρ = pM/(RT) = (6.45e6 × 0.004003)/(8.314 × 137.5) = **22.59 kg/m³**. 0.17/22.59 = 0.00753 m³/s, rounded to 0.0075. Real-gas (CoolProp) correction not applied — PF's own doc found this a ~3% effect at similar conditions, immaterial at this precision. |
| `V_flow0` | 0.00908 m³/s | **[CALCULATED]** | = 1.21 × `V_flow_nominal`, using PF's *actual compiled* ratio (1.21×), not PF's original reasoning's assumed 1.5× — PF's own design-basis doc explicitly recommends the compiled ratio over the reasoning's assumption (§6: "the reasoning's own worked example... is why it only matched order of magnitude"). |
| `T_nominal` | 137.5 K | **[FROM SOURCE]** | ATEKO Tab.5 worst-case coil temperature (see §2's naming-inconsistency note). Same caveat as PF's `T_nominal`: this is the *declared design point*, not necessarily what the circulator sees at any instant once the manifold mixes flows from 5 coils at different temperatures — not checked here (no simulation available to check it, unlike PF where a real run confirmed a materially different true suction temperature, 136.5 K vs. declared 160 K). |
| `p_nominal` | 6,450,000 Pa = 64.5 bara | **[CALCULATED]** | Declared **directly at the calculated true-suction estimate** (discharge 82 bara − `dp_nominal` 17.5 bar), rather than at an ambiguous intermediate value — PF's own design-basis doc flags PF's `p_nominal` as a **[MISMATCH]** for sitting between suction and discharge without a clear reason, and recommends "reconcile intent before trusting it as the suction reference pressure." This CS value is built to avoid that specific problem from the start, at the cost of depending on the weak `dp_nominal` above. |
| `eta_maxPhyd` | 0.6 | **[ASSUMED]** | Carried from PF's validated choice (60–70% band, cryogenic cold-compressor references PF's doc cites: a low-flow 2 K machine at 64.4%, LHC-class at 50–70%). No CS-specific vendor quote. |
| `maxDeltaT` | 20 K | **[ASSUMED]** | Carried from PF's current value — added to PF for an unrelated fix (per PF's own migration notes), not derived from any CS- or PF-specific physics either. |
| `dpInitial` | 8,200,000 Pa | **[ASSUMED]** | Initial-condition helper only (matches discharge-pressure region), not a sizing parameter — same role as PF's own `dpInitial`. |
| `V_flow_Start` | 0.003 m³/s | **[ASSUMED]** | Carried from PF, initial-condition helper only. |

## 4. Pressure architecture

**[CALCULATED]**, since no run exists to read FIRM values from:

| | Design point |
|---|---|
| Discharge pressure | 82 bara (= 81 barg nominal working pressure **[FROM SOURCE, ATEKO §6.5.2]** + 1 bar, barg→bara convention matching PF's own doc's usage) |
| Suction pressure | 64.5 bara (= discharge − `dp_nominal`) |
| Head (discharge − suction) | 17.5 bar |

Unlike PF's real run (head nearly doubling from hot start to cold end, 6.75
→ 10.78 bar, as loop resistance grows with cold-end mass flow), **no
hot-start/cold-end trajectory exists here at all** — there is nothing to
simulate. Whether CS's head grows similarly through a cooldown is unknown
and unstated as a finding.

## 5. Mass flow & cooldown — design intent, not a simulated result

**[FROM SOURCE, ATEKO Tab.5]**: 30-minute cooldown design flow per channel
0.0214 kg/s at the worst-case coil (CS1/CS3U/CS3L, 16 MJ, 714 kg,
137.5 K → 80 K). 15-minute cooldown leads to critical (choked) flow per
ATEKO Tab.10, the same reason PF and TF both settled on 30-minute design.
**No cooldown trajectory, margin, or asymptotic-approach behavior can be
stated here** — PF's own design basis reports these (§5) only because a
real simulated run exists to read them from; this document has no
equivalent to offer. This is a real gap versus PF's document, not an
oversight — flagged explicitly rather than fabricating a plausible-looking
number.

## 6. Circulator parameter rationale

Same structure as PF's design-basis doc §6, but every entry here is
CALCULATED/ASSUMED rather than reconciled against a real run:

- **`n_nominal` = 200 Hz.** [ASSUMED] — see §3. Buildability rechecked
  below at CS's own `dp_nominal`/flow, since a fixed speed carried from a
  very differently-sized loop (PF: 5.6 bar/0.038 m³/s vs. CS: 17.5 bar/
  0.0075 m³/s) is not automatically still appropriate.
- **`dp_nominal` = 17.5 bar.** [CALCULATED, weak] — see §3's full caveat.
  This is the single number in this document most likely to be wrong by a
  large factor; everything downstream of it (`V_flow_nominal`, `p_nominal`,
  the buildability check in §7) inherits that uncertainty.
- **`V_flow0`.** [CALCULATED] — see §3, uses PF's compiled ratio not its
  original reasoning's assumption, per PF's own documented recommendation.
- **Nominal gas conditions.** [FROM SOURCE + CALCULATED] — `T_nominal`
  sourced from ATEKO Tab.5 (with the naming-inconsistency caveat in §2);
  `p_nominal` calculated directly at the estimated true suction condition,
  a deliberate improvement on PF's own flagged mismatch (see §3).

## 7. Buildability check (impeller tip speed / diameter)

**[CALCULATED]**, same method as PF's design-basis doc §7 (loading
coefficient ψ = 0.55, assumed per PF's own reasoning, not a model
parameter), using this document's own `dp_nominal`/density rather than
PF's:

- ρ at nominal point (ideal-gas): 22.59 kg/m³ (see §3 derivation).
- u = √(dp_nominal / (ρ·ψ)) = √(1,750,000 / (22.59 × 0.55)) = √(140,910)
  = **375 m/s**.
- D = u / (π·n_nominal) = 375 / (π × 200) = **0.598 m** (598 mm).

**Comparison to PF:** PF's own (real-data-corrected) figures are 323 m/s /
0.51 m. CS's calculated 375 m/s / 598 mm is larger on both counts —
plausible in direction (CS's `dp_nominal` is roughly 3× PF's 5.6 bar at a
much lower flow, and a higher-head/lower-flow duty at fixed speed pushes
tip speed and diameter up, all else equal), but **this is not a
confirmation** — it depends entirely on the weak `dp_nominal` estimate in
§3. 375 m/s stays under PF's cited ~450 m/s single-stage metal-impeller
ceiling, so nothing here rules out single-stage construction, but the
margin (75 m/s) is smaller than PF's own margin to that ceiling (127 m/s)
and would close further if `dp_nominal` needs revising upward once real
header/valve loss data exists.

## 8. Simplifications versus PF, made deliberately

PF's `PFCircuit.mo` (1218 lines) includes several optional control
refinements added iteratively after real simulated data existed to debug
against: an overcool-prevention/recovery bypass with hysteresis and a dwell
timer, a circulator-shaft-power limiter PID, and a low-temperature-
coolant-optimization overlay on top of the basic coil-isolation rule. None
of that data exists for CS. `CSCircuit.mo` implements PF's **core**
structure only:

- Fixed-speed circulator (matches PF's actual implementation — PF's own
  temperature PID modulates the heater/cooling/bypass valves, not
  circulator speed; this document does not add a refinement PF itself
  doesn't have).
- A heating-only PID-modulated electric heater (PF's cooling-valve/bypass-
  overcool subsystem is not replicated — CS's primary cooldown mechanism
  is the passive evaporator, and no ATEKO or PF data motivates a
  CS-specific need for the extra bypass branch).
- Relative-margin coil isolation (`coilOpen`), **CS1/CS3U/CS3L only** — the
  two-channel assemblies. CS2U/CS2L reuse PF's plain `CoilAssembly` class,
  which (matching PF's own unused 1-channel base model) has no external Kv
  input port, so they always run fully open. This is the lighter pair
  (349 kg/7.8 MJ vs. 714 kg/16 MJ) — a defensible but real scope reduction,
  not a hidden gap.
- Suction pressure control (`RV07`/`RV08`) as a **plain PID-proportional
  trim**, not PF's 2026-09-01 pulse-then-trim rewrite. That rewrite fixed a
  specific limit-cycle PF observed in its own (much smaller) loop volume;
  whether CS's loop has the same failure mode is unknown, since nothing
  here can be simulated. The compliant-buffer fix PF found necessary
  (`makeupBuffer`/`reliefBuffer` between the ideal reservoir boundary and
  the valve) is still included, since it is cheap and PF's own reasoning
  for it (a valve bridging directly to a zero-compliance boundary) applies
  structurally regardless of loop size.

## 9. Evaporator — same simplification as PF, unresolved either place

Both this model and PF's use an ideal fixed-temperature 77 K `coldSurface`
boundary in place of ATEKO's actual described evaporator: a helium/LIN
thermosiphon through `HE01`+`HE02`+a separation vessel `VE01` (ATEKO §6.1,
§6.2 — which also flags that the last few K of cooling toward 80 K requires
disproportionate heat-exchanger area/height, "beyond the standard design
parameters of evaporators"). Neither model attempts that detail. The
evaporator tube's `nParallelTubes=25` in `CSCircuit.mo` is **[ASSUMED]**,
sized to no particular target — ATEKO gives no evaporator geometry, and
PF's own model has the same gap (its design-basis doc's Open Items §11
notes no filter/evaporator-sizing detail was checked either).

## 10. Open Items

- **`dp_nominal` provenance (weakest number in this document, §3/§6).**
  Only channel-only pressure loss is sourced; header/valve/HX loss is an
  assumed 28% margin with no basis. Revisit once real component-level
  pressure-drop data exists — same status as PF's own `dp_nominal`
  provenance item, which PF's doc also left open.
- **Thesis correction, unchecked (§2).** `thesis_sis.pdf` could not be read
  in this environment (exceeds the 20 MB single-read limit; page-range
  rendering needs `pdftoppm`/poppler-utils, not installed here). PF's own
  worst-case temperature was corrected from ATEKO's 137 K to a
  thesis-sourced 160 K — whether an analogous correction exists for CS's
  137.5 K is genuinely unknown, not just unstated.
- **ATEKO's "CS1U" label (§2).** Read here as a typo for one of
  CS1/CS3U/CS3L based on matching Tab.5's own numbers — not independently
  confirmed against any other source.
- **`Sensor_p` class name (CSCircuit.mo).** Carried directly from PF's own
  `PFCircuit.mo`, where it is itself flagged "ASSUMED by analogy... verify
  at translate-check" — same unverified status here, not newly introduced.
- **No cooldown trajectory, margin, or mass-flow drift exists (§5)** — PF's
  document reports these from a real run; this one cannot, for the reasons
  above.
- **Buildability margin is real-data-dependent (§7)** — 375 m/s / 598 mm
  stays under PF's cited ceiling today, but is only as trustworthy as
  `dp_nominal`.
- **Simplifications versus PF (§8)** are deliberate and documented, not
  oversights — but they are real reductions in control-loop fidelity
  relative to PF's most mature version, which itself only reached that
  maturity through iterative real-data debugging this document had no
  access to.
- **Nothing in this file has been translated or simulated.** No Dymola
  access exists in this environment (see `dymola-thermal-systems/
  CLAUDE_en.md`). Every number above should be re-checked once a real
  translate/simulate run exists, the same way PF's own numbers were
  reconciled against its first real `result.mat`.
