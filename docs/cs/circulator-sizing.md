# CS-Coil Cooling-Loop Circulator — Design Basis

| | |
|---|---|
| **Title** | CS-coil cooling-loop circulator sizing — design basis |
| **Date** | 2026-09-04, updated 2026-09-06 (§8, §10, §11 — robustness pass), 2026-10-07 (§10a — rebuilt on TF's structure after the first real run), 2026-10-08 (§10b — speed control, LIN limit, startup preparation, friction) |
| **Author** | _(placeholder — fill in)_ |
| **Model file** | `dymola-thermal-systems/CoilLoopCompassU/CS/CSCircuit.mo`, component `fan2ndOrder` (`ThermalSystems.GasComponents.Fans.Fan2ndOrder`); coil-channel changes in `CoilAssembly.mo`/`CoilAssembly2ch.mo` |
| **Applies to git commit** | `f48942d` — "CS: add CSTest.mo run harness and register classes in package.order"; later revisions §10a–§10c merged to `development` via PR #24 |
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

**Topology note, corrected during the original CS build:** the
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
  not a hidden gap. `CoilAssembly` **did**, however, share a real structural
  risk with TF's original `TFUL1`/`TFUL2` bug: CS2U and CS2L are two
  parameter-identical `CoilAssembly` instances connected via a chain of
  zero-resistance `VolumeJunction`s (`junctionS1`→`junctionS4` on the supply
  side, `junctionR1`→`junctionR4` on the return side), the same
  symmetric-parallel-branch degeneracy class TF's `acba24f` commit fixed
  for `TFUL1`/`TFUL2` (a "22890 unknowns/22889 equations" structural
  singularity). `CoilAssembly2ch` already carried PF's `assemblyIndex`/
  `lengthAdjusted` anti-degeneracy fix (used for `CS1`/`CS3U`/`CS3L`); plain
  `CoilAssembly` had no such mechanism at all. **[FIXED, this build]** —
  `CoilAssembly.mo` now has the same `assemblyIndex`/`lengthAdjusted`
  parameters, with `CS2U`/`CS2L` given distinct indices (4, 5) in
  `CSCircuit.mo`. See also `CLAUDE_en.md`, "Modelling lessons".
- Suction pressure control (`RV07`/`RV08`) as a **plain PID-proportional
  trim**, not PF's 2026-09-01 pulse-then-trim rewrite. **Re-examined this
  build, decision: kept as-is.** The wiring
  initially thought to be the relevant TF/PF "more robust" precedent
  (`bypassHysteresis`/`BypassLimiter`/`firstOrder2` in `TFCircuit.mo`,
  wired up by TF's `acba24f` commit) turns out to govern a *different*
  subsystem — TF's heater/cooling/bypass split-range triad (`valve5`/
  `valve6`), not TF's own suction-pressure `RV07`/`RV08`. TF's actual
  `RV07`/`RV08` (the real structural analog to CS's) use this identical
  plain-proportional-trim architecture, per `TFCircuit.mo`'s own header
  comment ("RV07/RV08 use a plain continuous proportional trim, simpler
  than PF's pulse-then-trim scheme") — TF made the same simplification
  versus PF that CS did. TF's suction-node compliance
  (`junction22`+`makeupBuffer`+`reliefBuffer`, each 1e-2 m³) is also
  numerically identical to CS's, and TF's model "translates and simulates
  successfully" on that architecture (`docs/tf/circulator-sizing.md` Status).
  This is concrete, matched-parameter precedent, not blind analogy, that
  the plain trim is workable at this loop scale — so the specific
  limit-cycle PF observed and fixed for its own (much smaller) loop volume
  is treated as unconfirmed-but-unlikely for CS, not ported speculatively.
  Whether CS's loop has the same failure mode remains genuinely unknown
  (nothing here can be simulated) — flagged in Open Items, not silently
  closed. The compliant-buffer fix PF found necessary
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

## 10. Coil-channel geometry, thermal mass, and heat transfer — brought to TF's level (this build)

Both gaps below were present in the CS build inherited at the start of this
task and are fixed here in `CoilAssembly.mo`/`CoilAssembly2ch.mo`, using
TF's `acba24f` commit (see `git show acba24f`) as the worked example, but
recomputed from CS's own numbers throughout — none of TF's actual figures
(6x10mm ellipse, 13900kg, alpha=1090, etc.) are reused directly.

**Elliptical channel geometry.** The old `CoilAssembly`/`CoilAssembly2ch`
used `crossSectionType=Circular` with ATEKO Tab.2's "equivalent diameter"
(6.96025mm) — an approximation, like TF's pre-`acba24f` state. **[FIXED,
this build]** — both classes now use `crossSectionType=NonCircular` with
`crossSectionArea`/`wettedPerimeter` computed directly from the real
8x6.2mm ellipse (semi-axes 4mm x 3.1mm) ATEKO Tab.2 actually describes:
- `crossSectionArea` **[CALCULATED]** = π·a·b = π·4mm·3.1mm = **38.956
  mm²**.
- `wettedPerimeter` **[CALCULATED]** = Ramanujan's ellipse-perimeter
  approximation, π·[3(a+b) − √((3a+b)(a+3b))] = **22.396 mm**.
- Method cross-checked against TF's own documented 6x10mm-ellipse numbers
  before use: the same formulas, with TF's a=5mm/b=3mm, reproduce TF's
  documented 47.12 mm² area and 25.53 mm wetted perimeter exactly.
- Resulting hydraulic diameter (4·A/P) = 6.9584mm, consistent with ATEKO
  Tab.2's 6.96025mm "equivalent diameter" to ~0.03mm — a sanity check that
  8x6.2mm is the right ellipse, not an independent confirmation of it.

**Copper thermal mass.** The old `CoilAssembly` had no `wallThickness` set
at all (library default, ~0.5mm) and `CoilAssembly2ch` used a guessed
0.00488m — neither traced to ATEKO's real coil weights. Reconstructing the
old `CoilAssembly2ch` mass from its 0.00488m circular wall: ~286kg total
for both channels of a coil, versus the real 714kg (CS1/CS3U/CS3L) — about
2.5x too little, the same class of thermal-mass shortfall (if smaller in
magnitude) that caused TF's solver blow-up before `acba24f`. **[FIXED,
this build]** — `outerCrossSectionalArea` on both classes is now sized so
modeled copper mass matches ATEKO Tab.5's real coil weights (**[FROM
SOURCE]** 349kg for CS2U/CS2L, 714kg total / 357kg per channel for
CS1/CS3U/CS3L), using copper density 8960 kg/m³ (`Common/CopperOFHC_Tdep.mo`):
copperArea = mass/(density·length); outerCrossSectionalArea =
crossSectionArea + copperArea. **[CALCULATED]**, method verified by
reproducing TF's own `TFCoilBusCoreLower`/`TFCoilBusUpper`
`outerCrossSectionalArea` values from their documented masses/geometry to
within rounding before applying it to CS.

**Heat-transfer model.** Switching to `NonCircular` geometry required also
switching off `GnielinskiDittusBoelter` (the previously-used heat-transfer
model) — per TF's own `docs/tf/circulator-sizing.md`, the library's
geometry-based correlations only support circular tubes. **[FIXED, this
build]**, mirroring TF's own resolution of the identical problem:
`ConstantAlpha`/`ConstantR` now supply gas-side heat transfer and wall
conduction.
- `alphaConstant` **[CALCULATED]**: a Dittus-Boelter estimate obtained by
  *scaling* TF's own reverse-engineered `TFCoilBusCoreLower` value
  (1090 W/m²K at Dh=7.38mm, A=47.12mm², 2.90e-3 kg/s/channel) via
  Nu=0.023·Re^0.8·Pr^0.4, using CS's own per-channel mass flow (0.17 kg/s
  total design flow split evenly across the 5 coil branches, then across
  each branch's channel count — 0.034 kg/s/channel for CS2U/CS2L, 0.017
  kg/s/channel for CS1/CS3U/CS3L — the same even-split convention TF uses
  for its own `m_flowStart=m_total/4`) and CS's own channel geometry.
  Helium gas properties (μ, k, cp) are held fixed between TF's ~116K and
  CS's ~137.5K design points — **[ASSUMED]**, the weakest link in this
  estimate; the net T-exponent on the property terms is small (~0.14) so
  this is a mild approximation, not independently checked against a real
  helium property table. The scaling method itself was validated first
  against TF's own two instances (`TFCoilBusCoreLower` vs
  `TFCoilBusUpper`, same T/geometry, different mdot/channel): predicted
  ratio 2.0^0.8=1.741 vs. TF's actual 1899/1090=1.742, a near-exact match,
  giving confidence in the scaling relationship even though the absolute
  CS values it produces (9197 W/m²K for CoilAssembly, 5284 W/m²K for
  CoilAssembly2ch) are noticeably higher than TF's — expected, since CS's
  design splits far less flow across far fewer, much longer channels than
  TF's heavily-paralleled bus design (mass flux per channel roughly 14x
  TF's), which is also independently consistent with CS's known high
  channel-only pressure loss (~13.7 bar vs. TF's ~0.18 bar/channel).
- `wallConductionR` **[CALCULATED, weaker than the numbers above]**:
  reverse-engineering TF's own `wallConductionR` values via an
  area-equivalent-circular-radii annular-conduction formula
  (R=ln(r2/r1)/(2π·k·L·n)) gave inconsistent implied copper conductivities
  between TF's two instances (142 vs. 116 W/(m·K)) — a ~20% spread,
  meaning this reverse-engineering does not exactly reproduce TF's
  internal method. k_Cu=130 W/(m·K) (the average) is used here for CS's
  own values via the same formula. Convection resistance dominates
  wall-gas coupling by roughly 20x over this conduction term in both TF's
  and CS's numbers, so the practical impact of this imprecision is small.

**Not changed:** `WallMaterial` stays `CopperOFHC_Tdep` (not TF's
`CopperOFHC_RRR30_Tdep`) — switching material models was not asked for and
is out of scope; `Common/CopperOFHC_Tdep.mo` itself is explicitly
off-limits this build. `nCells`/`nCellsPerTube` settings are unchanged
(see the nCells=10 lambda/NaN project history — not touched here, unrelated
to this fix).

## 10a. 2026-10-07 revision — aligned with TF and the ATEKO study

The first real run (`CS/debugging/result.mat`, 2026-09-16) showed the
model did not cool at all, so the circuit was rebuilt on `TFCircuit.mo`'s
structure. Where this section disagrees with §3–§10, this section wins.

| Change | Why |
|---|---|
| Removed the zero-resistance link `junctionS6 → junctionS1` around the evaporator; added TF's evaporator branch `valve6 → tube1 → valve3` with a controlled bypass `valve5` (CS_RV02 on PFD 22178-3-R0) | The link carried essentially all flow: `tube1` saw < 2 g/s, removed 0.06 MJ after t=5 s, and the coils warmed from 137.5 K to ~240 K |
| Added TF's heater/cooling/bypass split-range control (`PID`, three hysteresis gates, first-order smoothing) with Kv values scaled by `kvScale`=0.05 | Same control as TF/PF; CS moves ~1/19 of TF's volume flow, so scaled Kv keeps TF's valve pressure drops |
| Added the coil bypass `junction21 → valve4 → junction20` and its state machine (off by default, as in TF) | "Bypass on the whole cooled objects as in PF and TF" |
| No discharge heat pulse; coil walls start at 137.5 K, gas at 80 K | ATEKO Tab.5's 137.5 K is already the post-shot temperature. The pulse counted the shot twice and, applied to cell 1 only, pushed walls to 580–1097 K and discharge pressure to 113.9 bara (> 95 barg design) |
| `alphaConstant` = 6350 W/m²K for all coils (was 9197 single-channel / 5284 two-channel) | ATEKO's design is 0.0214 kg/s in every channel (8 × 0.0214 = 0.17 kg/s), and the run showed equal per-channel flow |
| Isolation valves on all 5 coils, closing both ends (`valve2` outlet valve, `outletKvRatio`=50); `T_wall_max` output | PFD shows CS_V01–V05 on every coil; both-end closure and frozen outlet temperatures are TF's anti-chatter fix |
| 40 K rule on the hottest cooled wall cell, floored at 77 K; cold shut-off at 80 K and release-all (`allReleased`) | Same as TF; ATEKO S3.2 limits T_object − T_coolant |
| Pressure control moved to `junction1` (circulator discharge side) at **82 bara = 81 barg** | ATEKO S6.5.2: 81 barg nominal working pressure *at the CC outlet*; same node as TF |
| Evaporator 25 × 12 mm × **4.5 m**, 5 cells, 77 K on every cell (was 10 m, 1 cell) | Study UA ≈ 2.35 kW/K (35.3 kW, 0.17 kg/s, He 120 → 80 K vs 77 K); now ~3.7 kW/K ≈ 1.6×, same margin policy as TF |
| 10 cells per coil channel (was 8 / 20), `fixedTInitialWall=false` everywhere, `controlActivationDelay`=10 s | Consistency with TF; 88 m channels hold ~5 s of gas at design flow |

Still open: no LIN supply cap (0.27 kg/s, ~55–60 kW, ATEKO S7.2); fixed
circulator speed (shaft power will rise as the gas densifies — check
against the 20 kW budget, S7.3); CS3U/CS3L length 88 m (Tab.2) vs 86 m
(PFD); HE02, VE01, filter, RV01 and FM01 not modeled.

## 10b. 2026-10-08 revision — circulator, LIN limit, startup, friction

The 2026-10-07 run cooled all coils to 80 K in ~20 min with the pressure on
target, but the fixed-speed circulator ran at 92% of its zero-head flow
(eta 0.47–0.51, 25–40 kW shaft vs the 20 kW budget, 0.22–0.36 kg/s vs
0.17), the evaporator duty peaked at 75 kW (LIN supply ~55–60 kW), and the
coil gas inlet–outlet difference exceeded 40 K for 31 s at startup. Where
this section disagrees with §3–§10a, this section wins.

| Change | Why |
|---|---|
| Circulator speed-controlled on mass flow (`PID_speed`, flow meter `sensor_m_flow` = FM01): 0.0214 kg/s per open channel, 0.17 kg/s with all 8 | ATEKO S6.1: CC "controllable at all regimes"; S6.5.2: 0.17 kg/s. Holds flow and shaft power down as the gas densifies |
| `dp_nominal` 17.5 → **11.5 bar**, `V_flow_nominal` 0.0075 → **0.0074 m³/s**, `p_nominal` **70.5 bara** | Loop loss at 0.17 kg/s just after the coils open (15.1 bar at 0.0274 kg/s in the 2026-10-07 run, ×1.22 friction, scaled by (0.0214/0.0274)^1.8 → 11.8 bar; 10.7 bar by t=300 s). Puts the design point where the machine runs, as for TF |
| Evaporator LIN side: boiling resistance `alpha_LIN` = 3000 W/m²K on the tube outside, duty capped at `Q_LINmax` = **60 kW**; tube 4.5 → **5 m** | S6.2, S7.2 (0.27 kg/s LIN). He side ~2.8 kW/K in series with ~16.5 kW/K → UA ≈ 2.4 kW/K, the study's 2.35 kW/K |
| Startup preparation through the coil bypass `valve4` (throttled to Kv 1 ≈ the coils' own loss): coils shut until the supply holds within 2 K of T_wall_max − 40 K for 10 s (fallback 300 s), then the coils open and `valve4` closes (`coolantReady`) | Prepare the coolant before it reaches the coils, using PF's coil-bypass branch |
| Loop gas starts at **97.5 K** (137.5 − 40), coil gas at the coil temperature (137.5 K) | S3.4: inlet–outlet ≤ 40 K from the first second |
| Channel friction ×1.22 via `KvFrictionTrim` (0.34 per channel), combined into each coil's outlet valve | Konakov (smooth tube) gave 0.77–0.88 of Tab. 9 (13.89 bar at 137 K, 7.89 bar at 80 K) |
| Circulator bypass `CS_RV01` (PFD) with PF_RV01's power-limit logic, shut by default | PF structure; the speed control already keeps power under 20 kW |
| All connections drawn on PF's diagram coordinates; every Kv command starts from its own initial value | Diagram readability; removes the 2 s reverse flow through `valve5`/`tube1` at t=0 |
| `StopTime` 2100 → 2700 s | At design flow the cooldown should take ~30 min (S5.2.2) instead of ~20 |

## 10c. 2026-10-09 — enlarged evaporator (trial)

The 2026-10-08 run (5 m HE01, the study's UA ~2.35 kW/K) cooled at 33.6 kW
in the 40K-limited phase against the 35.3 kW the rule allows, and spent
~940 s of a ~1900 s cooldown in the tail after the supply floor (77K) was
reached. Over that tail the evaporator was at full capacity (bypass shut)
with its outlet 1.4-4.5K above the LIN, so the supply sat 1.7-2.6K above
wanted_temp, and the walls had to close the last few kelvin to 80K with
less driving temperature difference.

Trial: `evapLength` 5 -> 8 m (`nEvapCells` 5 -> 8), i.e. UA x1.6, NTU
~2.8 -> ~4.5, approach ~4.5K -> ~1K. The LIN duty stays under `Q_LINmax`
(peak ~52 kW expected vs 60 kW). This departs from the study's HE01 size;
keep it only if the cooldown gain is worth a ~9 m2 instead of ~5.5 m2
exchanger.

## 10d. 2026-10-16 — circulator at fixed speed, coil flow set by CS_RV01

The speed control of §10b is removed; CC01 runs at a fixed speed like PF
and TF, and the circulator bypass `CS_RV01` (PFD 22178-3-R0) sets the coil
flow instead. Where this section disagrees with §10b, this section wins.

| Change | Why |
|---|---|
| `PID_speed` removed; CC01 at `n_fixed_Hz` = **220 Hz** after a 10 s soft start from 155 Hz | Speed-controlled run (2026-10-15) needed at most 213 Hz for 0.17 kg/s at the hardest point (t≈300 s, 14 bar, 26 kg/m³ suction) |
| `PID_RV01` (PI, k=3 Kv per kg/s, Ti=10 s, Kv 0–5, 2 s actuator lag) holds the flow to the loop at `m_flow_set` (0.0214 kg/s per open channel) | At fixed speed the circulator's volume flow stays roughly constant (PF, `docs/control-common.md` C-RV01), so its mass flow grows as the helium densifies; RV01 returns the surplus to suction at low resistance instead of forcing it through the coils, which lowers the pressure rise and the shaft power (PF_RV01's mechanism) |
| Loop flow measured at the heater inlet (`m_flow_loop`), downstream of the RV01 tee; FM01 keeps its PFD position and reads loop + bypass flow; `prepInBand` now uses `m_flow_loop` | FM01 upstream of the tee no longer equals the coil flow once RV01 is open |
| PF's power-limit logic on RV01 (`enableCirculatorPowerOptimization`, `PID_circulatorPower`) removed | It was off, and two controllers on one valve would fight |

Expected at the cold end (estimate, to be checked against the next run):
circulator ~0.32 kg/s, of which ~0.15 kg/s through RV01, ~8 bar head,
~8 kW shaft power — higher than the speed-controlled run's 2.3 kW, but
under the 20 kW budget (§7.3).

## 10e. 2026-10-16 — CC01 resized for fixed-speed duty

The first fixed-speed run (§10d: the §10b machine, 11.5 bar / 0.0074 m³/s
at 200 Hz, driven at 220 Hz) held the coil flow on target, but ran at
86–96 % of its zero-head flow with eta 0.27–0.53: 22–28 kW shaft power
(> 20 kW, §7.3), 25.6 MJ of losses into the helium, evaporator energy
86 MJ (60 MJ before), supply stuck 0.6–0.9 K above 77 K and the last coil
at 80 K only at ~1824 s.

**Fan model (read from the `Fan2ndOrder` source in `dsmodel.c`).** Curve:
quadratic through (`V_flow_nominal`, `dp_nominal`), zero head at `V_flow0`
and `V_flow0 + deltaV_flow`, scaled by r = n/n_nom (flow), r² (head) and
d = ρ/ρ_nom. Losses: `P_ref = d·r³·(1/eta_maxPhyd − 1)·P_hyd_max`,
blade `P_ref·(V/V_maxPhyd)^2.3`, impact `P_ref·0.4·(1 − V/V_maxPhyd)²`
(`V_maxPhyd` is not speed-scaled). A Python replica with ρ_nom = 24.7 kg/m³
reproduces the run's flow and shaft power to 0.1 %.

**Sizing.** Duty from the run (loop dp at the controlled flow, suction
density over time); fan dp = loop dp, RV01 takes the rest; minimise the
peak shaft power subject to ≥ 1.05 × the loop flow with RV01 shut.

| Parameter | Was | Now |
|---|---|---|
| Fixed speed | 220 Hz | **200 Hz** = `n_nominal_Hz` |
| `dp_nominal` | 11.5 bar | **13.75 bar** (hardest point: 13.8 bar at 0.17 kg/s, 25.4 kg/m³, t≈300 s) |
| `V_flow_nominal` | 0.0074 m³/s | **0.0070 m³/s** (0.0067 needed + 5 %) |
| `V_flow0` | 1.21 × nominal | **1.10 ×** (`V_flow0_ratio`) |

Peak shaft power vs. the zero-head ratio (each with its best dp/V):
1.05 → 16.8 kW, **1.10 → 18.0 kW**, 1.21 → 20.1 kW, 1.5 → 24.6 kW — a
steeper curve keeps the fan's volume flow nearly constant as the gas
densifies, so less of the surplus turns into blade loss.

Predicted (to be checked against the next run): 15–18 kW shaft power over
the whole cooldown, fan 0.18–0.29 kg/s, RV01 0.013 kg/s at t≈300 s rising
to 0.12 kg/s at the cold end (Kv 0.08–0.8), eta 0.59 → 0.34. That is
~7 kW less heat into the helium than §10d, but still more than the
speed-controlled machine (§10b, 2–14 kW): at fixed speed the losses scale
with gas density, so they grow while the duty falls. `eta_maxPhyd` = 0.6
remains [ASSUMED]; every +0.05 lowers the losses by ~12 %.

## 11. Open Items

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
- **RV07/RV08 limit-cycle risk, reasoned-not-simulated (§8, this build).**
  Kept CS's plain PID trim rather than porting a more elaborate scheme,
  backed by TF's matched-parameter precedent (identical suction-node
  buffer volumes, TF's own RV07/RV08 use the same plain-trim
  architecture) — but this is still an argument by analogy to a
  real-but-different model, not a CS-specific simulation result. If a
  real translate/simulate run later shows CS's suction pressure
  oscillating, revisit this decision and consider porting PF's actual
  2026-09-01 pulse-then-trim mechanism (hysteresis-gated feedforward
  pulse + trim, in `PFCircuit.mo`), not TF's bypassHysteresis wiring
  (confirmed this build to be an unrelated subsystem).
- **`alphaConstant`/`wallConductionR` (§10, this build) carry real,
  flagged uncertainty**, more than `crossSectionArea`/`wettedPerimeter`/
  `outerCrossSectionalArea` in the same section: the per-branch mass-flow
  split (0.17 kg/s ÷ 5 branches ÷ channel count) is a first-order,
  unweighted estimate (real flow would split by branch resistance, which
  differs with channel count/length); the Dittus-Boelter scaling holds
  helium gas properties fixed between TF's ~116K and CS's ~137.5K design
  points rather than computing them from a property table; and
  `wallConductionR`'s reverse-engineered k_Cu has a ~20% spread between
  TF's own two instances. None of these were checked against
  `thesis_sis.pdf` or any CoolProp/NIST property lookup this pass.
- **Nothing in this file has been translated or simulated.** No Dymola
  access exists in this environment (see `dymola-thermal-systems/
  CLAUDE_en.md`). Every number above should be re-checked once a real
  translate/simulate run exists, the same way PF's own numbers were
  reconciled against its first real `result.mat`.
