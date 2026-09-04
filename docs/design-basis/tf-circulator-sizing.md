# TF-Coil Cooling-Loop Circulator — Design Basis

| | |
|---|---|
| **Title** | TF-coil cooling-loop circulator sizing — design basis |
| **Date** | 2026-09-04 |
| **Author** | Claude (live chat session, not `night.sh`), reviewed against `docs/design-basis/pf-circulator-sizing.md`'s methodology |
| **Model file** | `dymola-thermal-systems/CoilLoopCompassU/TF/TFCircuit.mo`, component `fan2ndOrder` (`ThermalSystems.GasComponents.Fans.Fan2ndOrder`) |
| **Real-data source** | **None.** Unlike PF's design basis, there is no compiled `result.mat` for this model — it has never been translated or simulated (no Dymola access here; see `dymola-thermal-systems/CLAUDE_en.md`). Every number below is either read directly from a cited source document or derived by hand calculation. |

**Tagging convention (adapted from `pf-circulator-sizing.md`):** PF's design basis
tags numbers **[FIRM]** when read from a compiled model/simulation run — that
tag cannot be used here, since no run exists. Instead:

- **[FROM SOURCE]** — read directly off a cited page/section of a source
  document (the ATEKO cryogenic-system study or the TF PFD).
- **[CALCULATED]** — derived by a stated formula/method from FROM SOURCE
  numbers (unit conversions, scaling, the buildability check, etc.).
- **[ASSUMED]** — no source and no calculation basis; carried from PF's own
  model as a placeholder, or a bare engineering guess. Always says so
  explicitly and why.

Where a number could not be sourced or reasonably calculated, it is flagged
in **Open Items** rather than invented.

---

## 1. Context and topology

Closed-loop helium cooling for the COMPASS-U TF (toroidal-field) coil,
modeled in Dymola/TIL (`CoilLoopCompassU.TF.TFCircuit`), structurally
parallel to `CoilLoopCompassU.PF.PFCircuit`.

**Topology decision — 4 lumped coil-bus assemblies, not 8, not 16.** The TF
coil is physically "one huge coil (112 turns) made out of copper plates with
brazed-on pipe" **[FROM SOURCE, ATEKO 22172-Z-R1 S3.3.3, p.7]**, split into
two named parts — "TF core + lower limb" (112 channels, L=9.2m) and "TF
upper limb" (112 channels, L=7.7m) — for a total of 224 channels, explicitly
stated as **"connected in parallel to 4 busses"** **[FROM SOURCE, same
section]**.

This superseded an earlier read of the TF PFD image
(`material/22179-0-R0-S1 - PFD TF COILS, SUPPORT STR..pdf`), which visually
shows 6 valve/flow-transmitter branches feeding the coil torus. The
reconciliation: 2 of those 6 branches feed the separate "SUPPORT STRUCTURE
UPPER"/"SUPPORT STRUCTURE LOWER" boxes shown on the same drawing, not TF
coil channels — support structure is **out of scope for this model** (same
scope boundary PF's own model uses: PF's model covers PF coils only, not
the shared support-structure cooling circuit either, even though ATEKO
groups "TF coils and support structure" as one delivery circuit, S6.1).
That leaves 4 branches for the coils, matching the text exactly.

Each of the 4 busses is modeled as a `TFCoilBusCoreLower` or
`TFCoilBusUpper` instance — a **[CALCULATED, ASSUMED split]** even 2-and-2
division of the two 112-channel groups (56 channels per bus). The source
does not state how the 112 channels of each group are distributed across
the 4 busses; even-split-by-type was chosen as the simplest structural
assumption, by analogy with PF's own U/L (upper/lower) pairing pattern. See
Open Items.

Each bus is modeled with `nParallelTubes` = 56 on a single `Tube`
(PF's single-channel `CoilAssembly.mo` pattern), not as 56 individually
branched channels (PF's `CoilAssemblyNch` pattern) — correct here because
every channel within one TF bus is geometrically identical, unlike PF's
per-coil channels of differing length.

## 2. Requirement

Source: ATEKO study 22172-Z-R1 S3.2, S3.3.3, S5.1.3, S6.4, S6.5.3.

- Cool TF coils to 80 K target (77 K minimum, 82 K fallback ceiling) within
  the same 30-minute cooldown window used for PF/CS **[FROM SOURCE, S3.4,
  S5.2.3 — "cooling down time 15 min leads to critical flow so cooling down
  time 30 min is used for design of flow. The worst condition for cold
  compressor design is at 116 K"]**.
- Worst-case coil temperature during cooldown: **116 K** **[FROM SOURCE,
  Tab.6/S5.1.3]** — this is the thermal-balance result, analogous to PF's
  own ATEKO-sourced 137 K figure. **Unlike PF**, this document does not
  apply an additional "corrected worst case" margin on top of the
  ATEKO figure — PF's design basis cites a thesis-derived correction
  (137 K → 160 K, "thesis S6.1") that could not be independently verified
  here (the thesis PDF was not read in this pass — see Open Items). 116 K
  is used as-is, FROM SOURCE, with that gap flagged rather than papered
  over with an invented analogous correction.
- Max temperature difference: **40 K** (coolant-to-coil / inlet-to-outlet)
  **[FROM SOURCE, ATEKO S3.2 — "Cooldown after tokamak discharge... Limit
  (T_object - T_coolant) <= 40K"; and S6.4 — "operate cooling loops with
  maximal temperature difference 40K (T inlet-T outlet)"]**. Unlike PF's own
  design basis (which flags this exact 40 K figure as **[UNVERIFIED]** for
  PF, unable to confirm which signal pair it bounds), the TF/whole-system
  source text states it plainly for the system as a whole — stronger
  sourcing here than PF has for its own `tempMargin` default.
- Total heat duty to extract: **138.8 kW** sustained **[FROM SOURCE, S6.5.3]**
  — internally consistent with the two coil-group energies from Tab.3
  (196 MJ core+lower-limb + 53.76 MJ upper-limb = 249.76 MJ) divided by the
  1800 s design cooldown window: 249.76e6 / 1800 = 138.76 kW, matching the
  stated 138.8 kW to within rounding **[CALCULATED cross-check, confirms
  internal consistency of the source document]**.
- Total design mass flow: **1.3 kg/s** at 116 K **[FROM SOURCE, S6.5.3]**.
  Cross-check against the per-channel figure (Tab.6: 0.00517 kg/s/channel
  × 224 channels = 1.158 kg/s) shows an ~11% gap **[FROM SOURCE discrepancy,
  present in ATEKO's own numbers, not introduced here]** — 1.3 kg/s (the
  circuit-level design figure) is used as the model's `m_total`.
- Design/working pressure: max 30 barg, nominal working 24 barg (at CC
  outlet) **[FROM SOURCE, S6.5.3]**.

## 3. `fan2ndOrder` — parameter derivation

| Parameter | Model value | Tag | Basis |
|---|---|---|---|
| `T_nominal` | 116 K | **[FROM SOURCE]** | ATEKO Tab.6/S5.1.3, worst-case coil temperature |
| `p_nominal` | 2,500,000 Pa (~24 bara) | **[CALCULATED]** | ATEKO S6.5.3 nominal working pressure 24 barg, +1 atm → bara, rounded |
| `m_total` | 1.3 kg/s | **[FROM SOURCE]** | ATEKO S6.5.3, minimal design flow |
| `V_flow_nominal` | 0.125 m³/s | **[CALCULATED]** | `m_total / rho_suction`; `rho_suction` via ideal-gas He at 116 K/2.5 MPa(a): `p*M/(R*T)` = 2,500,000×0.004003/(8.314×116) ≈ **10.38 kg/m³**; 1.3/10.38 ≈ 0.1253 m³/s. Ideal-gas only — PF's own design basis found real-gas He differs ~2–3% from ideal-gas at similar conditions (its S7); not re-derived with CoolProp here, no simulation to validate against anyway. |
| `V_flow0` | 0.151 m³/s | **[CALCULATED]** | Carries PF's actual model ratio `V_flow0/V_flow_nominal` = 0.046/0.038 ≈ 1.21× (not the 1.5× "typical centrifugal" figure PF's own reasoning cites, which PF's design basis already flags as a mismatch against PF's real model value) |
| `dp_nominal` | 200,000 Pa (2 bar) | **[CALCULATED, rough estimate]** | See S6 below — this is the least-confident number in this document |
| `n_nominal` | 200 Hz (12,000 rpm) | **[ASSUMED]** | Carried unchanged from PF — no TF-specific circulator speed data exists anywhere in the source material |
| `eta_maxPhyd` | 0.6 | **[ASSUMED]** | Carried unchanged from PF, same reasoning |
| `deltaV_flow`, `bladeLossExponent`, `impactLossCoefficient` | 0.07 m³/s, 2.3, 0.4 (TIL defaults, not overridden) | **[ASSUMED]** | Not TF-specific — same TIL library defaults PF's own design basis documents as unreplaced |

## 4. Pressure architecture

`pressureSetpoint` = 2,500,000 Pa **[CALCULATED, same basis as `p_nominal`
above]**. RV07 (make-up)/RV08 (relief) hold this at the suction node via a
**plain continuous PID trim**, not PF's later pulse-then-trim rewrite — see
`TFCircuit.mo`'s file header for why that PF refinement was not ported over
(it fixed a limit-cycling failure mode only found after PF was actually
simulated; TF has had no such run). `pMakeupReservoir`/`pReliefReservoir`
(2.7/2.3 MPa(a)) are **[CALCULATED]**, offset from `pressureSetpoint` by a
margin scaled down proportionally from PF's own reservoir-to-setpoint
spread, not independently sized.

## 5. Buildability check (impeller tip speed / diameter)

**[CALCULATED]**, using the model's own `dp_nominal` and the ideal-gas
density from S3 above, loading coefficient ψ=0.55 (same assumed value
PF's own check uses, carried here for consistency — not a model parameter
either place):

- ρ at nominal point: 10.38 kg/m³ (ideal-gas estimate, S3)
- u = √(dp_nominal / (ρ·ψ)) = √(200,000 / (10.38 × 0.55)) ≈ **187 m/s**
- D = u / (π·n_nominal) = 187 / (π×200) ≈ **0.30 m** (298 mm)

Both figures sit comfortably inside PF's own cited ~450 m/s single-stage
metal-impeller ceiling, and are smaller than PF's own actual model values
(323 m/s / 0.51 m) — consistent with TF's much lower `dp_nominal`. **This
check is only as good as the `dp_nominal` estimate it depends on** — see
Open Items.

## 6. `dp_nominal` — how the 2 bar estimate was reached, and why it's weak

ATEKO's own channel-only pressure-loss table (Tab.11, S5.2.3) gives, for one
TF channel at 30 min cooldown / 116 K / a 20–25 barg inlet range,
**0.17–0.21 bar** — far smaller than PF's own single-channel loss at its
design point (PF's design basis notes its `dp_nominal`=5.6 bar sits close to
PF's own channel-table value at its nominal inlet pressure, S6/S11 of
`pf-circulator-sizing.md`). That is physically plausible on its own — TF's
channels are much shorter (9.2/7.7 m vs PF's 60–90 m) and larger-bore
(7.38 mm vs 7 mm) — but a circulator's real head also has to cover header,
heater, evaporator, and valve losses that ATEKO's channel-only table
explicitly does **not** cover: *"the final pressure losses of circuit and
channels have to be evaluated by cryogenic system supplier"* **[FROM
SOURCE, S5.2.3, verbatim]**. TF's total flow (1.3 kg/s) and channel count
(224) are both far higher than PF's (~0.1 kg/s referenced by PF's own
`m_total`, ~24 channels total) — pointing toward header/manifold losses
being proportionally larger for TF, not smaller, than for PF.

`dp_nominal` = 200,000 Pa (2 bar) was chosen as a round placeholder,
roughly an order of magnitude above the bare channel figure, as headroom
for those unmodeled losses — **not a real hydraulic calculation**. A rough
sanity check: shaft power at this point works out to
`dp_nominal × V_flow_nominal / eta_maxPhyd` = 200,000×0.125/0.6 ≈ **42 kW**,
compared to ATEKO's own TF circulator estimate of 25 kW (S7.3) — a ~1.7×
gap. That is *smaller* than the gap PF's own real (simulated) shaft power
turned out to have against its ATEKO estimate (58 kW actual vs 20 kW
estimate, ~3×) — so 2 bar is not obviously unreasonable, but this is a
plausibility check on an assumption, not independent validation. **Treat
`dp_nominal` as the single least-trustworthy number in this document.**

## 7. Assumptions

- Ideal-gas helium density used throughout (no CoolProp real-gas
  correction) — no simulation exists to check the error against, unlike PF.
- 4-bus split is 2 core+lower-limb + 2 upper-limb, each bus 56 channels —
  **[ASSUMED]**, not stated in the source (see S1).
- Evaporator (`tube1`) and electric heater geometry carried from/loosely
  scaled off PF's own components, not independently sized for TF's flow —
  **[ASSUMED]**.
- `n_nominal`, `eta_maxPhyd`, and the TIL fan-curve shape parameters carried
  unchanged from PF — **[ASSUMED]**, no TF-specific circulator vendor data
  exists in the source material.
- Fixed-speed machine, same as PF.

## 8. Open Items

- **`dp_nominal` (2 bar)** — the single weakest number here, see S6. Needs
  either a real header/valve/HX pressure-drop calculation or, eventually, a
  Dymola translate/simulate pass (impossible from this session — no VM
  access) to check whether the model even reaches its design flow at this
  head.
- **4-bus channel split (56/56 core+lower-limb, 56/56 upper-limb)** — an
  assumption, not sourced. If the real bus wiring differs (e.g. uneven
  split, or busses mixing both channel types), the per-bus heat load and
  flow used here would need revising.
- **116 K worst-case temperature, no thesis-derived correction** — PF's own
  design basis applies a +23 K correction on top of its ATEKO figure
  (137 K → 160 K), sourced to "thesis S6.1". The thesis
  (`material/thesis_sis.pdf`) was not read in this pass to check whether an
  analogous TF-specific correction exists. If one does, `T_nominal` and the
  per-bus `TInitial` (currently 116 K) should be revised upward and this
  design basis re-derived from the corrected value, the same way PF's is.
- **Support structure cooling** — explicitly out of scope here (see S1),
  matching PF's own coils-only scope, but ATEKO treats "TF coils and
  support structure" as one delivery circuit/cold box (S6.1) — if a full
  system model is ever wanted, the support-structure branches (the other 2
  of the PFD's 6 visible branches) would need their own model, not folded
  into this one.
- **Electric heater and evaporator sizing** — both geometries are carried
  over from PF with only cosmetic changes (wider heater bore), not
  independently sized for TF's ~3.4× larger design flow. Revisit once real
  pressure-drop numbers exist.
- **No Dymola verification of any kind.** Every structural claim in this
  document (that the model would even translate, let alone reach its
  design point) is unverified. This is expected — see the model file's own
  "Cannot run Dymola" note — but worth restating plainly here too.

## 9. Reproducibility

No equivalent of `pf_circulator_sizing.py` exists for TF, and none is
proposed here — that script reads a compiled `result.mat`, which requires
an actual Dymola translate/simulate run this session cannot perform. Once
this model has been run inside the VM at least once, a TF-specific version
of that script (reading `TF/debugging/result.mat` instead) would let the
FROM SOURCE / CALCULATED numbers above be checked against real simulated
values, the same way `pf_circulator_sizing.py` checks PF's.
