# PF-Coil Cooling-Loop Circulator — Design Basis

| | |
|---|---|
| **Title** | PF-coil cooling-loop circulator sizing — design basis |
| **Date** | 2026-09-03 |
| **Author** | _(placeholder — fill in)_ |
| **Model file** | `dymola-thermal-systems/CoilLoopCompassU/PF/PFCircuit.mo`, component `fan2ndOrder` (`ThermalSystems.GasComponents.Fans.Fan2ndOrder`) |
| **Applies to git commit** | `f9c46c4` — "Circulator maxDeltaT increased to 20" |
| **Real-data source** | `dymola-thermal-systems/CoilLoopCompassU/PF/debugging/result.mat`, re-run 2026-09-03 16:59 (`dslog_simulate.txt`: `SUCCESSFUL simulation`, 1815 s, 52 state events, no solver failures) |

**Tagging convention:** every number below is marked **[FIRM]** (read directly
from the model or the cited real run), **[PROVISIONAL]** (an assumption, a
TIL library default not yet replaced with vendor data, or a hand calculation
built on a FIRM number), or **[MISMATCH]** (the model/real-run value
disagrees with the reasoning that was used to arrive at it, or with an
external claim — see the specific note). Where a number could not be
verified from this repository's data, it is not stated — see **Open Items**.

**A note on method:** every number under "actual model values" and "actual
simulated result" in this document was read directly from
`fan2ndOrder`'s compiled parameters in `result.mat` and from the trajectory
data of the 2026-09-03 16:59 run, not transcribed from the reasoning that
motivated the original sizing. Several of them disagree with that reasoning
— those disagreements are called out explicitly rather than smoothed over,
per the instructions this document was written against.

---

## 1. Context

Closed-loop helium circulator for the COMPASS-U tokamak PF-coil cooling
loop, modeled in Dymola/TIL (`CoilLoopCompassU.PF.PFCircuit`). Loop
topology: cold compressor (`fan2ndOrder`) → electric heater (`Heater`, off
in normal operation) → helium/LIN evaporator (`tube1`, cooled by an ideal
77 K `coldSurface` boundary — see the caveat in §9) → coil header → 8 PF
coil assemblies (`PF1U/PF1L/PF2U/PF2L/PF3U/PF3L/PF4U/PF4L`) → return header
→ circulator. A helium inventory/stabilizer (`makeupReservoir`/
`reliefReservoir` via `RV07`/`RV08`/`PF_RV01`) holds the **discharge**
pressure; suction floats to discharge minus loop head. A bypass branch
(`valve4`/`valve5`) exists for turndown. No filter component is present in
this model (see Open Items).

## 2. Requirement

Source: ATEKO study 22172-Z-R1 §3.4/3.5/6.5.1; PF thesis §6.1.

- Cool PF coils to ≤ 80 K within 30 minutes (1800 s).
- Worst thermal case = hot restart: coils return at **~160 K** (corrected
  worst case — not the 137 K used in the ATEKO study).
- Max temperature difference 40 K (coolant-to-coil and inlet-to-outlet).
  **[UNVERIFIED — see Open Items]**: this document could not confirm which
  specific signal pair the 40 K figure is meant to bound (see §5).

## 3. `fan2ndOrder` — actual compiled parameter values (Step 2)

Read directly from `result.mat` (all confirmed identical between the
`.mo` source declaration and the compiled value logged in the `.mat` —
no stale-translation risk here, unlike some earlier entries in
`docs/migration-notes.md`).

| Parameter | Model value **[FIRM]** | Reasoning expected | Verdict |
|---|---|---|---|
| `n_nominal` | 200 (Hz) = 12,000 rpm (confirmed via `summary.speed_rpm`) | ~200 Hz (12,000 rpm) | Match |
| `dp_nominal` | 560,000 Pa = **5.6 bar** | order 4–6 bar | Match (upper end of range — see §6 buildability recheck) |
| `V_flow_nominal` | 0.038 m³/s | order 0.03–0.04 m³/s | Match, see §6 for the recomputed design-point value |
| `V_flow0` | 0.046 m³/s | ~1.5× `V_flow_nominal` (≈0.057) | **[MISMATCH]** actual ratio is 1.21×, not 1.5× |
| `deltaV_flow` | 0.07 m³/s | TIL default (no specific value expected) | Not overridden in `PFCircuit.mo` — confirmed TIL library default |
| `eta_maxPhyd` | **0.6** | reasoning expects TIL default 0.30, recommends replacing with 0.6–0.7 | **[MISMATCH with the reasoning's premise, not with its conclusion]** — see §7. The model already has 0.6, not the 0.30 default the reasoning assumes is still in place |
| `bladeLossExponent` | 2.3 | TIL default (no specific value expected) | Not overridden — TIL default |
| `impactLossCoefficient` | 0.4 | TIL default (no specific value expected) | Not overridden — TIL default |
| `T_nominal` | 160 K | must be declared at true suction (~160 K), not 80 K | Matches the *declared design point*; note the *simulated* suction temperature at hot start is materially colder — see §5 |
| `p_nominal` | 3,340,000 Pa = **33.4 bar** | ~30 bar (suction) | **[MISMATCH]** actual simulated suction at hot start is 29.80 bar (close to "~30 bar"), but `p_nominal` itself is 33.4 bar — 3.6 bar / ~12% higher than the suction pressure it's implicitly meant to represent. `p_nominal` reads as sitting between suction and discharge rather than at suction — reconcile intent before trusting it as "the suction reference pressure" |
| `maxDeltaT` | 20 K | not part of the original sizing reasoning | Added 2026-09-03, unrelated fix (see `docs/migration-notes.md`, same date) — included here because it is now a real, current parameter of this component |
| `V_flow_Start` | 0.003 m³/s | initial-condition helper, not a sizing parameter | — |
| `dpInitial` | 4,000,000 Pa = 40 bar | initial-condition helper, not a sizing parameter | — |
| `orientation` | `"symmetric"` (string, read from `.mo` source; not fetchable from the compiled `.mat`) | — | — |
| `use_mechanicalPort` | `true` | — | — |

## 4. Pressure architecture — actual simulated values

**[FIRM]**, from the 2026-09-03 16:59 run:

| | Hot start (t≈5.8 s, `T_gas_out_max`≈160.0 K) | Cold end (t=1815 s, run end) |
|---|---|---|
| Discharge pressure (`fan2ndOrder.portB.p`) | 36.55 bar | 36.58 bar |
| Suction pressure (`fan2ndOrder.portA.p`) | 29.80 bar | 25.80 bar |
| Head (discharge − suction) | 6.75 bar | 10.78 bar |

Discharge is held essentially flat at ~36.5–36.6 bar for the entire run —
the stabilizer is doing its job; this matches the "~36 bar(a)" claim in
the design reasoning closely **[Match]**. Suction at hot start (29.80 bar)
matches the "~30 bar(a)" claim closely **[Match]**. The reasoning does not
state a cold-end suction figure; this document adds it (25.80 bar) as new
real data — the discharge-minus-suction spread nearly *doubles* from hot
start to cold end (6.75 → 10.78 bar) as loop resistance grows with the
higher cold-end mass flow (§5).

## 5. Mass flow & cooldown result — actual simulated data vs. the design reasoning

**[FIRM]**, from the same run. The "hot start" reference point below is
sampled at t≈5.8 s — after the fan's speed ramp completes (`smoothStep`
ramps 1→11 s) and after `T_gas_out_max`'s ~1.2 s junction-initial-condition
artifact clears (documented in `PFCircuit.mo`'s own `controlActivationDelay`
docstring), so it reflects genuine hot-start operation rather than t=0's
uniform-initial-condition instant.

| | Hot start (t≈5.8 s) | Cold end (t=1815 s) |
|---|---|---|
| `T_gas_out_max` | 160.0 K | 79.69 K |
| Mass flow (`fan2ndOrder.portB.m_flow`) | 0.383 kg/s | **0.650 kg/s** |
| Circulator shaft power `P_shaft` | 33.65 kW | **57.98 kW** |

**[MISMATCH vs. the reasoning's stated figures — flagged explicitly, per
Step 2 — but the underlying requirement is still met; see below]:**

- **Cooldown margin.** The design reasoning states the loop cools the
  hottest coil to "~78 K within the 30-minute window, with ~100 s of
  margin." The actual latest run crosses `T_gas_out_max` ≤ 80 K
  permanently at **t = 1771.4 s**, giving a margin to the 1800 s target of
  **28.6 s**, not ~100 s — so the **requirement in §2 (≤80 K within 1800 s)
  is met**, just with a tighter margin than the reasoning implied. By
  t = 1800.5 s, `T_gas_out_max` = 79.77 K; by the end of the logged run
  (t = 1815 s) it is 79.69 K, still declining slowly (≈ −0.009 K/s, per
  the companion conservation-law audit of this same run).
  **This is expected, not a shortfall:** the coil is being cooled by the
  ~77–78 K `coldSurface` boundary, so `T_gas_out_max` approaches that
  supply temperature *asymptotically* — the heat-transfer rate scales
  with the coil-to-coolant temperature difference, which itself shrinks
  toward zero as the coil cools, so the coil physically never reaches
  (let alone crosses below) the coolant's own temperature in finite time.
  Reading "~78 K" in the reasoning as an approximate description of that
  asymptote — not a hard value the run should exactly hit — resolves the
  apparent gap; the ≤80 K/1800 s design requirement itself is the number
  that actually matters, and it is satisfied.
- **Cold-end mass flow.** The reasoning states mass flow drifts "UP to
  ~0.54 kg/s at the cold end." The actual latest run reaches **0.650
  kg/s** — 20% higher than stated, and still rising at the end of the
  logged window (not yet plateaued).
- **Cold-end shaft power vs. `P_shaftLimit`.** `P_shaft` reaches 57.98 kW
  at the cold end, above the model's own `P_shaftLimit=50000` (50 kW) —
  not a concern in itself; see §9 for the percentage and the mechanism
  that exists specifically to manage it.

**Why the "~78 K / ~100 s / 0.54 kg/s" figures don't match this run:**
almost certainly an earlier parameter set or an earlier run (plausibly
with `enableCirculatorPowerOptimization=true`, which trims cold-end flow
rather than letting it run up freely) — but the specific run that
produced those numbers could not be identified or re-checked:
`result.mat` at this path is overwritten on every run, and no earlier
copy of the exact trajectory that produced "~78 K / ~100 s" was found in
this repository. This discrepancy could not be resolved further within
this pass — see Open Items.

**Suction temperature at the fan is not the same as `T_gas_out_max`.**
Using the same CoolProp (P,h) inversion technique as the companion
conservation-law audit (datum-corrected for TSMedia's enthalpy reference),
the *true* simulated suction temperature at t≈5.8 s is **136.5 K**, not
160 K — the header mixes the hottest coil's return flow with cooler
coils' return flow before it reaches the circulator inlet, so the
circulator itself never actually sees the single hottest coil's own
outlet temperature. `T_nominal=160 K` is a reasonable, conservative
*design* point (it matches the worst-case single-coil requirement in
§2), but it is not literally what the fan processes at any instant in
this multi-coil topology — worth noting explicitly so `T_nominal` isn't
later mistaken for "the fan's real operating temperature."

## 6. Circulator parameter rationale, reconciled against real data

- **`n_nominal` = 200 Hz (12,000 rpm).** **[FIRM, Match]** — confirmed
  realistic for a helium cryo-circulator; buildability rechecked below.
- **`V_flow_nominal` = 0.038 m³/s.** **[FIRM, Match — but the "expected
  order" reasoning used the wrong temperature].** Recomputing
  `mdot_design / rho_suction` at the *true* simulated suction condition
  (136.5 K, 29.80 bar, via CoolProp real-gas Helium) gives **0.0376 m³/s**
  — within 1% of the model's `V_flow_nominal`. The reasoning's own
  worked example (using 160 K instead of the true 136.5 K suction
  temperature) gives 0.043 m³/s instead, which is why it only matched
  "order of magnitude." Recommend using the true simulated suction
  temperature, not the nominal 160 K design point, for any future
  refinement of this number.
- **`dp_nominal` = 5.6 bar.** **[FIRM, within the stated 4–6 bar range,
  toward the top of it]**. The 15-bar figure the reasoning warns against
  (a leftover TF-loop, 0.9 kg/s value mistakenly applied to PF) is
  confirmed **not** present anywhere in the current model — no
  `dp_nominal` value in `PFCircuit.mo` or the compiled `.mat` is anywhere
  near 15 bar. Confirmed resolved.
- **`V_flow0` = 0.046 m³/s.** **[MISMATCH]** — see the table in §3. The
  reasoning's "typical centrifugal free-delivery ratio" of ~1.5× gives
  ~0.057 m³/s; the model has 0.046 m³/s (1.21×). Not necessarily wrong
  (real machine curves vary), but the number in the model doesn't match
  the number in the reasoning that was supposed to justify it — flagged
  for reconciliation once a real vendor curve exists (see Open Items).
- **`deltaV_flow`, `bladeLossExponent`, `impactLossCoefficient`.**
  **[PROVISIONAL — confirmed TIL library defaults]**, not present in the
  `.mo` instance declaration, so not modeler-chosen. Values: 0.07 m³/s,
  2.3, 0.4 respectively. Replace with vendor curve data when available.
- **Nominal gas conditions (`T_nominal`/`p_nominal`).** **[FIRM values,
  one flagged mismatch]** — `T_nominal=160 K` is correctly declared at
  the true (worst-case design) suction temperature, not 80 K; the
  documented prior error (nominal conditions declared at 80 K/40 bar,
  mis-scaling delivered flow via the model's density correction) is
  confirmed **resolved** in the current model. `p_nominal=33.4 bar`,
  however, doesn't cleanly correspond to either the suction pressure
  (29.8 bar at hot start) or the discharge pressure (36.5 bar) — see the
  mismatch note in §3.

## 7. Buildability check (impeller tip speed / diameter)

**[PROVISIONAL — hand calculation, not read from the model]**, recomputed
using the model's *actual* `dp_nominal` and a real-gas (CoolProp) density
at the declared nominal point (`T_nominal=160 K`, `p_nominal=33.4 bar`),
loading coefficient ψ=0.55 (assumed, per the original reasoning, not a
model parameter):

- ρ at nominal point: 9.75 kg/m³ (real-gas, CoolProp) vs. 10.05 kg/m³
  (ideal-gas) — a 3.1% difference. The reasoning's claim of "~2%" is close
  but the actual figure runs slightly higher; not a material issue for
  this check either way.
- u = √(dp_nominal / (ρ·ψ)) = √(560,000 / (9.75 × 0.55)) = **323 m/s**
  (real-gas) / 318 m/s (ideal-gas).
- D = u / (π·n_nominal) = **0.51 m** (514 mm).

**[MISMATCH]** — the design reasoning states "~240–270 m/s, ~0.4 m" for
this same check. Recomputing with the model's own `dp_nominal=5.6 bar`
(not the reasoning's apparent ~4 bar reference point) gives materially
higher numbers: **323 m/s / 0.51 m**, not 240–270 m/s / 0.4 m. At `dp=4
bar` the formula does reproduce ~273 m/s, matching the low end of the
reasoning's stated range — the mismatch traces to which `dp` value was
used in the hand calculation, not to a different formula or a different ψ.

**Conclusion (still holds despite the mismatch):** 323 m/s and 0.51 m are
still comfortably inside the ~450 m/s single-stage metal-impeller ceiling
the reasoning cites, and nowhere near the retired 15-bar scenario's ~463
m/s / ~0.74 m (which the reasoning correctly identifies as not buildable
single-stage). **The buildability conclusion is unaffected — only the
specific tip-speed/diameter figures needed correcting.**

## 8. Efficiency

**[FIRM — the model's current value already differs from the reasoning's
premise]:** `eta_maxPhyd = 0.6` is the value actually compiled into
`fan2ndOrder` right now (`result.mat`, `fan.eta` reads ~0.66 at the hot-start
sample point — consistent with `eta_maxPhyd=0.6` as a *maximum*, not a flat
operating value). The design reasoning frames 0.30 (the TIL library
default) as the current state and recommends replacing it with a
realistic 60–70% figure, citing real cryogenic helium cold-compressor
references (a low-flow 2 K machine at 64.4%, LHC-class machines at
50–70%) and noting this loop's duty (pressure ratio ~1.2, higher flow) is
easier than those references. **That recommendation has already been
acted on** — 0.6 sits at the low end of the recommended 60–70% band, not
at the library default. No further action needed here beyond noting the
reasoning's framing is out of date relative to the current model, and
that 0.6 (rather than, say, 0.65–0.70) was chosen — no record of why that
specific value within the 60–70% band was picked; if there's a vendor
quote or reference machine behind it, cite it here.

Per the reasoning: efficiency scales power only, not flow or head, so
this does not change the cooldown-time result in §5.

## 9. Power finding

**[FIRM]** `P_shaft` reaches **57.98 kW** at the cold end of the current
run (t=1815 s, still rising — see §5), close to the design reasoning's
"~59 kW" figure. It peaks at the cold end (density-driven flow rise),
thermally the easy end, consistent with the reasoning's framing.

- **Electrical power (~65 kW claimed, "after motor losses"): [could not
  be verified — see Open Items].** `fan2ndOrder` outputs shaft power only;
  this model has no motor/VFD stage, so an electrical figure requires an
  assumed motor efficiency not present anywhere in this model. 58 kW
  shaft at ~90–95% assumed motor efficiency would land around 61–64 kW,
  in the neighborhood of the claimed ~65 kW, but this is a hand estimate
  layered on top of the FIRM shaft-power number, not a modeled value.
- **Comparison to ATEKO:** ~3× the ATEKO per-circulator *estimate* of
  20 kW for PF CC01 (§7.3), and roughly equal to the 65 kW ATEKO penciled
  in for all three compressors combined. The reasoning is explicit that
  20 kW is an estimate, not a hard limit, and that total electrical
  availability for the whole cryo system is ~200 kW (300 kW with a
  sub-atmospheric LIN blower, ATEKO §3.6/§7.3) — this document does not
  attempt to re-derive whether 58 kW for one PF circulator fits that
  budget alongside the other loops; that's outside this document's scope.
**`P_shaftLimit` headroom.** `PFCircuit.mo` declares
`parameter Modelica.Units.SI.Power P_shaftLimit=50000` (50 kW). At the
cold end of this run, `P_shaft` = 57.98 kW — **116.0% of `P_shaftLimit`**,
i.e. 16% over. This is not a concern on its own: it's exactly the
condition `P_shaftLimit` and its associated control loop exist to handle.
At hot start, by contrast, `P_shaft` = 33.58 kW is only 67.2% of the
limit — the limit only binds in the back-loaded cold-end stage, matching
`P_shaftLimit`'s own docstring ("`P_shaft` climbs from ~28 kW
(`T_gas_out_max`~160 K) to ~58.6 kW (`T_gas_out_max`~80 K) at fixed
circulator speed, because `dp` roughly doubles as the helium densifies
while volumetric flow stays ~flat").

The reason it's exceeded in *this particular run* is that
`enableCirculatorPowerOptimization` is `false` here — changed in the same
commit as the `maxDeltaT` fix (see `docs/migration-notes.md`, 2026-09-03
entry), as an incidental, bundled change rather than a deliberate
decision to accept the overshoot. The mechanism that exists specifically
to keep `P_shaft` at or below `P_shaftLimit` —
`enableCirculatorPowerOptimization` → `PID_circulatorPower` → `PF_RV01`,
which bleeds some flow around the coils once shaft power approaches the
cap — is present in the model and can be switched back on at any time;
it just hasn't been re-validated together with the `maxDeltaT=20` fix
yet (see Open Items). The reasoning's own conclusion — "further gains
come from a control schedule (bypass/speed turndown), not from tuning
the circulator parameters" — describes exactly this mechanism.

## 10. Assumptions

- Ideal-gas helium density is adequate for engineering-level sizing
  calculations (confirmed ~3% off real-gas at the relevant conditions —
  see §7 — close to, though somewhat above, the reasoning's claimed ~2%).
- Loop resistance dp ∝ ṁ² (not independently re-verified in this pass).
- Fixed-speed machine (`n_nominal=200` Hz, driven by a `smoothStep` to a
  constant setpoint in this model) with bypass valves for turndown.
- Choke limit and the 40 barg PF coil design pressure are monitored in
  the transient simulation rather than gated in this design-basis
  document.

## 11. Open Items

- **Mesh convergence:** confirm cooldown time / head / power are stable
  across `nCells = 5, 8, 10`. Not checked in this pass.
- **`dp_nominal` provenance:** confirm it was read off a resistance curve
  generated *at 160 K* (current value may be scaled from a different
  reference point); validate discharge minus `dp_nominal` against the
  measured ~30 bar hot-start suction — partially done here (§4: 36.55 −
  5.6 = 30.95 bar vs. measured 29.80 bar, a ~1.15 bar / ~4% gap, small but
  present).
- **`eta_maxPhyd`:** now 0.6, within the recommended 60–70% band, but no
  record found of why 0.6 specifically (vs. e.g. 0.65 or 0.70) was
  chosen — cite a vendor quote or reference machine if one exists.
- **Motor stage:** confirm whether the model includes (or should include)
  a motor/VFD stage separating shaft power from electrical power, and
  whether aerodynamic loss heat is credited to the helium — the companion
  conservation-law audit (`docs/migration-notes.md`, 2026-09-03 entry)
  found and fixed one related issue (`maxDeltaT` silently discarding loss
  heat); confirm no analogous gap remains between shaft and electrical
  power.
- **Re-validate with `enableCirculatorPowerOptimization=true`, medium
  priority:** the ≤80 K/1800 s requirement is met in this run (28.6 s
  margin — see §5), and the 116%-of-`P_shaftLimit` cold-end power is
  expected to be within the control loop's job to manage, not a design
  failure (§9) — but that loop is currently switched off, so neither
  figure has been checked *with* it on. Re-run with
  `enableCirculatorPowerOptimization=true` alongside the `maxDeltaT=20`
  fix and re-check both the margin and the peak shaft power.
- **`V_flow0` ratio:** model has 1.21× `V_flow_nominal`, reasoning assumed
  ~1.5×; reconcile once a real machine curve is available (§3, §6).
- **`p_nominal`:** doesn't cleanly match either suction or discharge
  pressure (§3); confirm what this parameter is meant to represent for
  `Fan2ndOrder` and whether 33.4 bar is the intended value.
- **40 K max-ΔT requirement (§2):** could not confirm which specific
  signal pair this bounds. A naive `T_gas_out_max − sensor_T` (coil
  outlet minus loop supply temperature) check on the current run shows a
  gap up to ~80 K — far above 40 K — but this is very likely the wrong
  pair of signals for what the ATEKO/thesis requirement actually
  constrains (it may refer to a coil-metal-vs-local-coolant criterion, or
  something evaluated only in steady state / only per-channel, not this
  loop-wide hot-transient gap). Needs the original requirement source
  re-read before this can be checked properly — do not treat the ~80 K
  figure above as a finding against the requirement.
- **No filter component** was found in this model's PF loop topology
  (`fan2ndOrder → Heater → tube1/HX → coil header → coils → return`) —
  the context in §1 mentions one per the original loop description; confirm
  whether a filter is out of scope for this model or missing.
- **Full model verification** (mass and energy conservation balances) —
  see the companion audit artifact (published this session) for the
  loop-wide version of this; this document only covers circulator sizing.

## 12. Reproducibility (Step 5)

`pf_circulator_sizing.py`, in this same folder
(`docs/design-basis/pf_circulator_sizing.py`), reproduces every number in
§3–§5, §7 and §9 of this document from a `result.mat` path: `fan2ndOrder`'s
compiled parameters, the hot-start/cold-end operating table, the
cooldown-vs-requirement check, the CoolProp-corrected true suction
condition, the tip-speed/diameter buildability check, and the cold-end
`P_shaft` vs. `P_shaftLimit` percentage. Run it after any change to
`fan2ndOrder`'s parameters or a fresh simulation, and diff the output
against this document to see what moved:

```
python docs/design-basis/pf_circulator_sizing.py \
    dymola-thermal-systems/CoilLoopCompassU/PF/debugging/result.mat
```

Requires `numpy`, `DyMat`, `CoolProp` (`pip install numpy DyMat CoolProp`).
It intentionally lives next to this document rather than inside
`CoilLoopCompassU/PF/` or `PF/debugging/` — it's a sizing-verification
tool for this write-up, not part of the Dymola model or its automation
scripts, and keeping it here avoids mixing analysis scripts into the
model/debugging-artifact folders.
