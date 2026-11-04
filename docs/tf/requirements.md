# TF circuit — requirements, conditions and limits from the sources

What the two source documents say about the toroidal-field (TF) coil and
support-structure cooling circuit: requirements, operating conditions, limits
and design parameters, each with a citation. This is the *input* side. How the
model uses these numbers is in [circulator-sizing.md](circulator-sizing.md)
(design basis) and [control-logic.md](control-logic.md) (algorithms); results
are read with [../reading-simulations.md](../reading-simulations.md).

Items that are the same for all three circuits (the 40 K rule in its several
forms, the operating modes and the staged cooldown, what the plant measures,
cold-box equipment, utilities) are **not repeated** here. They are in
[../cs/requirements.md](../cs/requirements.md) §2.3, §5, §6 and §7 and are
referred to as "CS §…". This page holds what is specific to TF and to the
support structure (SS), which shares the TF circuit.

## Sources and citation format

| Key | Document | File (in `..\material`) |
|---|---|---|
| **A** | ATEKO a.s., *Study of a cryogenic system for tokamak cooling – COMPASS-U*, report 22172-Z-R1, rev. 1, 7.10.2025, 25 pp. | `22172-Z-R1-S2 Study of a cryogenic system for tokamak_připomínky.pdf` |
| **T** | P. Barto, *Cryogenic design of tokamak COMPASS Upgrade*, doctoral thesis, Charles University, Prague 2025, 106 pp. | `thesis_sis.pdf` |

A citation is `[A §3.3.3, p.7]` or `[T §5.6.3, p.67]`: document, section (or
`Tab.`/`Fig.`/`Eq.`), page. Page numbers are the printed ones, which equal the
PDF page numbers in both files.

Tags used for each value:

- **verbatim** — a number or statement written in the source.
- **derived** — computed here from source values; the arithmetic is shown.
  Not in the source.
- **discrepancy** — the two sources, or two places in one source, disagree.
  Collected in [§10](#10-discrepancies-and-open-points).

The ATEKO text layer scrambles several tables (Tab.4 – 6, §6.5). They were
checked against the extracted text of the table rows and the stated results;
the TF numbers in Tab.3 and Tab.6 are consistent with the derivations below.

---

## 1. Cooled objects

**Two cooled objects: the TF coil (core + lower limb, and upper limb) and the
support structure.** The TF coil is one large coil of 112 turns made of copper
plates with brazed-on pipe; 16 × 7 × 2 = **224 short channels** of two types
are connected in parallel to **4 busses** [A §3.3.3, p.7].

| Object | Channels | Equivalent diameter | Length per channel | Copper mass | Energy to extract |
|---|---|---|---|---|---|
| TF core + lower limb | 112 | 0.007379796 m | 9.2 m | 13 900 kg | 196 MJ |
| TF upper limb | 112 | 0.007379796 m | 7.7 m | 7 808 kg | 53.76 MJ |

Source: [A Tab.3, p.8]. PFD number 22179-3-R0 (the list in §6.5.4 writes
22179-0-R0). Maximum deposited energy to the TF coil in a normal tokamak shot
about **250 MJ** in total [A §3.3.3, p.8].

- **Channel shape:** elliptical 6 × 10 mm, hydraulic diameter 7.379 mm
  [A §5.2.3, p.14]. Copper, Ra ≈ 2 µm. The thesis calls it an ellipse of
  6 × 10 mm "with a hydraulic diameter of approximately 7.8 mm"
  [T §5.1.2, p.51] (see §10, item 4). The tube is soldered to the surface of
  the turns; its size is bounded by the circumferential space per turn:
  1143 mm / 112 = 10.2 mm, less 2 × 1 mm wall and 1.05 mm insulation = 7.15 mm
  [T §5.1.2, p.51].
- **Material:** copper, two alloy candidates under consideration (OFHC
  silver-bearing C10700 or CuCr1Zr) [T §5.1, p.48]; the model's busses use
  OFHC copper with RRR ≈ 30 [T §7, p.83].
- **Construction:** 16 bundles of 7 turns; each bundle is split into a lower
  J-shaped segment and an upper almost straight limb, joined by a bolted joint
  (outer radius) and a sliding joint (inner radius). The channel is therefore
  two hydraulically independent channels: the upper limb and the core + lower
  limb [T §5.1, p.48; §5.1.2, p.49]. Masses: 70 kg per turn (upper limb),
  124 kg per turn (core + lower limb) [T §5.1.2, p.49], i.e. 7 840 kg and
  13 888 kg for 112 turns (**derived**; A has 7 808 and 13 900).
- **Busses:** the busses are doubled and the channels interleaved, so that
  one lost bus leaves partial cooling [T §5.3, p.57]. Inner diameters:
  **55 mm** for the core + lower-limb busses, **50 mm** for the upper-limb
  busses, 30 mm for the collector pipes that merge three or four channels
  [T §5.3, p.57]. Flow variation among the channels: below 6 % (core + lower)
  and below 15 % (upper limb); the busses take less than 10 % and less than
  20 % of the pressure drop respectively [T §5.3.2, p.58].
- **No internal coil sensors**, as for PF and CS [T §6.2, p.74].

### 1.1 Support structure

- **One cooled object, a large number of channels, 4 busses**
  [A §3.3.4, p.8]. Mass of stainless steel: "exceeds 200 t" overall
  [T §5.6, p.66]; the structure alone "roughly 200 t" [T §5.6.3, p.68].
  Material AISI 316LN, chosen because its yield strength rises at 80 K
  [T §5.6.2, p.67]; A uses SA 316 with roughness Ra ≈ 12.5 µm
  [A §5.2.3, p.14].
- **Functions:** hold all PF, CS and TF coils, carry the vacuum vessel, stiffen
  the TF coils, preload the TF bottom wedges [T §5.6, p.66].
- **Active cooling is mandatory.** A passively cooled structure would leave
  gaps above 9 mm vertically and 4 mm radially against the 80 K coils, and
  large thermal stresses [T §5.6.1, p.66–67].
- **Channels:** drilled holes with end caps, connected to the busses by
  10 mm inner-diameter pipes (the largest that still bends and takes the
  1/2" VCR fittings) [T §5.6.4, p.68–69; §5.6.5, p.70]. The channel network
  is a 1-D model with base pressure 20 bar and available pressure drop
  0.1 bar [T §5.6.5, p.70].
- **Not heated by the tokamak shot;** "cooling down of support structure will
  be evaluated later" [A §5.2.3, p.15] — A gives no balance, flow or pressure
  drop for the structure.

## 2. Temperature requirements

### 2.1 Target and range

Same as CS §2.1: target **80 K**, minimum 77 K, maximum 82 K, heating back to
room temperature [A §3.4, p.8]. The structure must reach "approximately the
same temperature as the TF and PF coils, i.e. 80 K"; any large deviation
would disturb the load transfer between coils and structure
[T §5.6.3, p.68].

### 2.2 Starting temperature after a discharge

- **116 K** for the TF coils "based on the thermal balance calculations"
  [A §5.1.3, Tab.6, p.13]; §6.5.3 states the design flow "at coil
  temperature 116 K" [A §6.5.3, p.19]. (The PF value is 137 K, CS 137.5 K.)
- The thesis models a TF core that rises by **80 K** in a 4.8 s discharge
  (200 kA) [T §5.2.4, p.54]: from the 80 K "ready for shot" state to about
  160 K, the same limit as for PF/CS. A 3-D model starts each cooldown from
  that state; 16 identical cycles of a 4.8 s discharge and 1800 s cooling,
  then a 12 h overnight cooldown [T §5.2.4, p.54].
- Dissipated energy: about 200 MJ in normal operation, up to **250 MJ** in
  an extreme case; the design uses 250 MJ [T §5.1.1, p.48]. Of the 250 MJ,
  about 54 MJ go to the upper limb, about 135 MJ to the core and 61 MJ to
  the lower limb [T §5.1.2, p.49]; 135 + 61 = 196 MJ ✔ matches A Tab.3.
- The model starts the coil busses at **137 K** (see §10, item 1) and the
  structure at 80 K.

### 2.3 The 40 K rule

Same forms and same ambiguity as CS §2.3. TF-specific points:

- A's TF tables use a helium temperature rise of **36.2 K**
  [A Tab.11, p.15], i.e. 116 K (coil) − 80 K (coolant inlet) = 36 K
  (**derived**). The thesis uses 20 K at the cold end and 40 K at the start
  of the cooldown [T Tab.5.1, p.51].
- For the electric heater (TF only), the design case is a **40 °C**
  difference [A §6.1, p.17].
- **Support structure:** its own homogeneity requirement, "within 40 K",
  because 40 K gives a thermal stress of about 100 MPa, which is about 10 %
  of the cryogenic yield strength (≈ 1000 MPa) of 316LN
  [T §5.6.3, p.68]. This is a requirement inside one object, not between
  coolant and coil.
- **Synchronisation of the structure and the coils:** if the SS cools too
  slowly, frictional slip occurs at the shims; if too quickly, tensile stress
  appears in the TF coils or their insulation [T §5.6.1, p.67]. The model's
  structure is disconnected by default (`connectStructure` = false), so this
  is not exercised.
- Cooling direction and the cooling-wave plateau (CS §2.3, §2.4) were studied
  by the thesis for CS2U only. For TF the thesis gives the optimal flow
  direction of the core/lower-limb channel from a 3-D model [T §5.2, p.52–57];
  the direction is not in the model.

## 3. Cooldown time and cooling capacity

| Item | Value | Source |
|---|---|---|
| Cooldown of the TF coils after a discharge | about 15 min (standard), at most **30 min** (high performance) | [T §2.8, p.30] |
| Design time of the TF loop | **30 min**; 15 min leads to critical flow | [A §5.2.3, p.15; §5.3.3, p.16] |
| Support structure cooldown | **7 days**, about 2 K/h on average; in principle about 35 h with the full 150 kW, rejected because of gradients | [T §5.6.3, p.68] |

Heat balance for the TF lower limb [A §5.1.3, Tab.6, p.13]:

| Time | Heat extracted | Coil mass | Coil temperature | Heat duty per channel | Flow per channel |
|---|---|---|---|---|---|
| 15 min | 196 MJ | 13 900 kg | 116 K | 1.94 kW | 0.0134 kg/s |
| 30 min | 196 MJ | 13 900 kg | 116 K | 0.97 kW | **0.00517 kg/s** |

Check (**derived**): 196 MJ / 112 channels = 1.75 MJ per channel;
1.75 MJ / 1800 s = 0.972 kW (thesis: 974 W [T Tab.5.1, p.51]);
0.97 kW / (5.2 kJ/kg/K × 36.2 K) = 0.00515 kg/s.

A gives no per-channel table for the upper limb. From its energy
(**derived**): 53.76 MJ / 112 / 1800 s = 0.267 kW per channel (thesis:
266 W); at 40 K rise this needs 1.28 g/s (thesis: 1.3 g/s at 120 K average,
ΔT 40 K [T Tab.5.1, p.51]).

**Total heat duty (derived).** 196 MJ / 1800 s + 53.76 MJ / 1800 s =
108.9 + 29.9 = **138.8 kW**, which matches A §6.5.3 "sum of heat duty to TF
coils: 138.8 kW" [A p.19]. The support structure is not in this number.
With the 150 kW the thesis assumes for the structure [T §5.6.3, p.68] the
whole circuit would have about 289 kW (**derived**).

## 4. Flow and pressure

### 4.1 Design point of the TF loop

| Item | Value | Source |
|---|---|---|
| Cooling medium | helium He-4 | [A §6.5.3, p.19] |
| Minimal design flow | **1.3 kg/s** of helium at coil temperature 116 K | [A §6.5.3, p.19] |
| Design temperature (min / max) | 77 K / 323 K (−196 / 50 °C) | [A §6.5.3, p.19] |
| Design pressure (min / max) | −1 barg / **30 barg** | [A §6.5.3, p.19] |
| Nominal working pressure | **24 barg, at the outlet of the CC** | [A §6.5.3, p.19] |
| Sum of heat duty to TF coils | 138.8 kW | [A §6.5.3, p.19] |
| Original (before study) | working 20 barg, design 30 barg, cooldown 15–30 min | [A §5.3.3, p.16] |
| Proposed (this study) | working 24 barg, design 30 barg, cooldown 30 min | [A §5.3.3, p.16] |
| Base pressure in the thesis | **20 bar** | [T §5.1.2, p.51; §5.3.1, p.57; §6.1, p.74] |
| Mass flow class of the loop | high, "≈ 1 kg/s" (TF coils and structure) | [T §6.1, p.74] |
| Support-structure minimum flow | about **750 g/s** (150 kW, 40 K rise); the 55 mm bus gives 920 g/s | [T §5.6.5, p.70] |

A does not split the 1.3 kg/s between the coil busses and the structure; see
§10, item 3.

### 4.2 Pressure drop in the TF channel

TF core + lower limb (D 7.38 mm, L 9.2 m, ΔT 36.2 K), 0.00517 kg/s, 30 min
case [A Tab.11, p.15]:

| Inlet pressure | 80 K | 116 K |
|---|---|---|
| 16 barg | 0.17 bar | 0.26 bar |
| 20 barg | 0.14 bar | 0.21 bar |
| 25 barg | 0.12 bar | 0.17 bar |
| 30 barg | 0.10 bar | 0.15 bar |

At the working pressure 24 barg (interpolating between 20 and 25 barg) the
drop is about **0.18 bar at 116 K** (**derived**). 15 min case, 0.0134 kg/s:
0.58 – 1.62 bar over the same range [A Tab.12, p.15]; it is not used for the
design because "15 min leads to critical flow" (the text of A says so for TF
too, although the TF table lists no critical-flow entries, see §10, item 6).

Thesis 0-D estimate, circular channel, 20 bar [T Tab.5.1, p.51]:

| Channel | Tavg | ΔT | Power | Length | d | Flow | Pressure drop | Compression loss |
|---|---|---|---|---|---|---|---|---|
| Upper limb | 90 K | 20 K | 266 W | 7.7 m | 8 mm | 2.5 g/s | 0.03 bar | 1 W |
| Upper limb | 120 K | 40 K | 266 W | 7.7 m | 8 mm | 1.3 g/s | 0.01 bar | 0 W |
| Core + lower | 90 K | 20 K | 974 W | 9.2 m | 8 mm | 9.3 g/s | 0.34 bar | 43 W |
| Core + lower | 120 K | 40 K | 974 W | 9.2 m | 8 mm | 4.7 g/s | 0.13 bar | 10 W |

"The effective heat-exchange length is approximately an order of magnitude
shorter than the physical channel length" [T §5.1.2, p.51]. The final loop
losses "have to be evaluated by the cryogenic system supplier" [A §5.2.3,
p.14].

### 4.3 Circulator (cold compressor) limits

| Item | Value | Source |
|---|---|---|
| Type, efficiency, one operating point, parasitic heat | as CS §4.3 | [T §4.2.1, p.37] |
| Loop pressure loss target | roughly **one tenth of the working pressure**: about 2.4 bar at 24 barg (**derived**) | [T §4.2.1, p.37] |
| Electric power, TF CC01 | **25 kW** (estimate; PF 20, CS 20, total 65) | [A §7.3, p.22] |
| Cooling water for CC | about 15 kW glycol/water, all CCs | [A §7.4, p.23] |

Heating by compression: the same equation as CS §4.3 [T Eq.4.5, p.43].
Applied to TF by that equation (**derived**, not in the source): a discharge
of 25 bar and a loop drop of 0.7 bar (the model's re-sized circulator,
[circulator-sizing.md](circulator-sizing.md)) give about
116 · [(25 / 24.3)^0.398 − 1] / 0.7 ≈ 1.9 K at T_in = 116 K, small compared
with the 20 bar examples of [T Tab.4.2, p.43].

## 5. Operating modes and sequence

Same as CS §5: the five modes of A [A §3.2, Fig.2, p.6], the state machine of
T [T §6.6, p.77–78] and the staged cooldown after a discharge
[T §6.2, p.74]. TF-specific statements:

- The TF loop is large-volume and low-pressure, so closing all isolation
  valves in a LoCA "may not fully prevent helium release" [T §6.6.2, p.78].
- The thermal-transition modes (cooldown, heatup) evaluate homogeneity by the
  return helium temperature **and the support-structure thermometry**
  [T §6.6.1, p.77]. The structure is the only object with its own
  thermometry in the sources; the model has none.
- The staged "40 K cooler → isolate" rule in T §6.2 is described for the
  coils of one loop; the structure is not mentioned as a participant.
  The model excludes it from isolation.

## 6. Equipment and instrumentation

Cold box, control valves RV01 – RV08, plant measurements and cold source as in
CS §6.1, §6.2 and §6.4 [A §6.1, p.17–18; T §6.3, p.74–75]. TF-specific:

- **Heating:** the electric heater **has to be used** for TF coils and the
  structure, because the structure has a huge weight; design case a 40 °C
  temperature difference [A §6.1, p.17]. (For CS and PF the compression heat
  is enough.) In T's list the heater is present "unless internal circulator
  losses provide sufficient heating" [T §6.3, p.75].
- **LIN flow of TF: 1.3 kg/s** at 6 barg (CS 0.27, PF 0.35, total 1.9)
  [A §7.2, p.22].
- **TF + SS cold box:** diameter 3.5 m, height 3.0 m; optional nitrogen
  vacuum pump 3.04 × 1.78 × 2.0 m [A §6.5.6, p.21].
- **Evaporator** and thermal shock at the start of the cooldown (LIN 77 K
  against 293 K helium): as CS §6.4 [A §6.2, p.18].
- **Bypass valves:** "a proportional bypass valve allowing full
  recirculation when all coil valves are closed" and "a temperature-regulating
  valve to limit cooling power at reduced flow" are in T's list for every loop
  [T §6.3, p.75]. The TF model has the temperature-regulating valve pair
  (valve5/valve6) but no circulator bypass RV01 (FIX-07).
- **Bus grouping:** for objects with many channels (TF, structure) the
  busses are duplicated [T §4.3.1, p.38]; the total bus cross-section equals
  the sum of the channels [T §4.3.1, p.38] (CS §7).

## 7. Interfaces and utilities

As CS §7: electrical supply 100 – 200 kW (mains 4.5 MW) [A §3.6, p.9],
glycol 10 °C / 100 kW [A §3.6, p.9], helium quality [A §7.1, p.22], dry air
[A §7.5, p.23], filters, tightness, autonomous control. TF items:

| Item | Value | Source |
|---|---|---|
| CC electric power | 25 kW | [A §7.3, p.22] |
| Electric heater | needed; no power is given | [A §6.1, p.17] |
| TF + SS cold-box area | Ø 3.5 m × 3.0 m | [A §6.5.6, p.21] |
| Total electric demand | 200 kW without the LIN blower; 300 kW recommended with a blower (about 122 kW for the blower) | [A §7.3, p.22] |

## 8. What the sources do **not** give for TF

- A balance for the **support structure**: heat extracted, mass, starting
  temperature, flow and pressure drop at the design point (A defers it).
  The thesis gives only 150 kW, 750 g/s minimum and the 7-day cooldown.
- The split of the 1.3 kg/s between the 224 coil channels and the structure.
- Per-channel design flow of the **upper limb** (A has only the lower-limb
  table).
- Maximum cooling rate of a TF coil in K/min; only the 40 K rule applies.
  For the structure the average is about 2 K/h [T §5.6.3, p.68].
- Heater power.
- Magnitude and duration of the "small flow" temperature probe; valve
  timings; time constants of valves, circulator and heat exchanger; pressure
  setpoint tolerance; helium inventory and header volumes; idle flow; the
  circulator characteristic (only 25 kW and the flow are given).
- Heat inleak per object in idle (T gives the budget for the whole assembly
  [T §7.2, p.79–80]).
- Setpoint for shutting a single branch when it reaches the target (the model
  uses 80 K, from the target temperature).

## 9. Model parameters traced to these sources

Only values that come from, or are compared with, A or T. Control parameters
are in [control-logic.md](control-logic.md); geometry and circulator are
in [circulator-sizing.md](circulator-sizing.md).

| Model | Value | Source / status |
|---|---|---|
| `nTF`, branches | 4: `TFCL1`, `Structure`, `TFUL1`, `TFUL2` | [A §3.3.3, §3.3.4, p.7–8] |
| `TFCL1` channels, length, wall mass | 112, 9.2 m, 13 900 kg | [A Tab.3, p.8] ✔ |
| `TFUL1` + `TFUL2` | 56 + 56 channels, 7.7 m, 7 808 kg total | [A Tab.3, p.8] ✔ |
| Coil channel D_h | 7.38 mm (6 × 10 mm ellipse, area 47.12 mm², perimeter 25.53 mm) | [A §5.2.3, p.14] ✔; T says about 7.8 mm (§10, item 4) |
| `Structure` | 120 channels, 3.5 m, 20 mm bore, 250 000 kg, 316LN | **Not found in the sources.** T has about 200 t, drilled channels, 10 mm connecting pipes (§10, item 5) |
| `TInitial` of the coil busses | 137 K | A has **116 K** [A Tab.6, p.13]; the model value equals the PF/CS number (§10, item 1) |
| `TInitial` of the structure and of the loop gas | 80 K | No source for the coil case; follows from "target 80 K" |
| `m_total` | 1.3 kg/s | [A §6.5.3, p.19] ✔ — documentation only, no controller uses it |
| `pressureSetpoint` | 2.5 MPa = 25 bara = 24 barg | [A §6.5.3, p.19] (nominal at the CC outlet) ✔ |
| Design pressure limit | 30 barg = 31 bara | [A §6.5.3, p.19]; check the peak discharge pressure of each run against it |
| `fan2ndOrder.T_nominal`, `p_nominal` | 116 K, 2.5 MPa | [A Tab.6, §6.5.3] ✔ |
| `tempMargin` | 40 K | [A §3.4, p.8; §3.2, p.6]; [T §6.1, §6.2] — see CS §2.3 |
| `T_supplyFloor` | 77 K | [A §3.4, p.8] (minimum target temperature) |
| `T_coldShut`, `T_releaseAll` | 80 K | [A §3.4, p.8] (target) |
| `coilIsolationCloseMargin`, `…ReopenMargin` | 40 K / 35 K | 40 K from [T §6.2, p.74]; the 35 K hysteresis is the model's own |
| `KvUpperLimb` = 45, `Structure.valveKvNominal` = 12 | static Kv values | **Not from the sources**: tuned in the model so that the upper limb does not finish first and the structure takes ~0.14 kg/s (see the `.mo` docstrings) |
| Coil flow target | 5.17 g/s per channel on all 224 channels | [A Tab.6, p.13] for the lower limb; applied to the upper limb by the model docs (§10, item 3) |
| Heater | present, driven by the temperature controller | [A §6.1, p.17] (required for TF) |
| `tube1` evaporator | resized 2026-10-06 to 4.5 m, 5 cells | **Not stated** in the sources |
| Circulator target | efficiency ~0.6, ~17 kW shaft power | A's electric estimate is **25 kW** [A §7.3, p.22] ✔ within budget |

## 10. Discrepancies and open points

1. **Starting temperature: 116 K (A) or 137 K (model), 160 K (T limit).**
   A's thermal balance for TF gives 116 K [A Tab.6, p.13; §6.5.3, p.19].
   T allows a rise of 80 K from 80 K, i.e. up to about 160 K
   [T §5.1.1, §5.2.4, p.54; §5.4.1, p.59 for PF/CS]. The model starts the coil
   busses at 137 K, the value A gives for **PF** (137 K); no TF source gives
   137 K. The case is not severe against the 116 K balance (the coils are
   21 K hotter than A assumes), but also does not reach the 160 K limit. Note
   the typo in A: the text under Tab.6 says "temperature of the **PF** coils
   is at about 116 K" [A §5.1.3, p.13]; it is read as TF. FIX-01 in
   [../to-fix.md](../to-fix.md) tracks the 40 K rule at startup (137 K coils
   against 80 K gas).
2. **Heat duty: 138.8 kW (A §6.5.3) vs. 250 kW (A §4.2).** §6.5.3 is
   reproduced by 196 + 53.76 MJ over 1800 s (**derived**, §3). §4.2 gives
   "TF coils: 250 kW cooling … 3 750 kW of electricity" [A §4.2, p.11]; this
   is not reproduced by any TF number (the 150 kW of the structure would give
   289 kW in total). The number 250 may be the 250 MJ of energy. Probably a
   leftover from an earlier version, as the 56 kW for CS and 69 kW for PF.
3. **Flow of the loop: 1.3 kg/s, and its split.** The coils alone need about
   0.74 kg/s at A's temperature rise (**derived**: 138.8 kW / (5.2 kJ/kg/K ×
   36.2 K); the lower limb alone is 112 × 0.00517 = 0.58 kg/s). The thesis
   gives 750 g/s for the structure [T §5.6.5, p.70]. Together about
   0.74 + 0.75 ≈ 1.5 kg/s, or 0.58 + 0.75 = 1.33 kg/s with only the lower
   limb counted (**derived**), so 1.3 kg/s is plausible as "coils +
   structure" but A does not say how it is built up. The model docs apply
   5.17 g/s to all 224 channels (1.16 kg/s) and leave 0.14 kg/s for the
   structure [Structure docstring in `TFCircuit.mo`]. The upper limb needs
   only about 1.3 – 1.4 g/s per channel (§3), a quarter of that, so the model
   gives it far more than the heat balance requires, and the structure far
   less than T's 750 g/s.
4. **Channel hydraulic diameter: 7.38 mm (A) vs. about 7.8 mm (T).** Same
   6 × 10 mm ellipse; A gives 7.379 mm [A §5.2.3, p.14; Tab.3, p.8], T
   "approximately 7.8 mm" [T §5.1.2, p.51]. The model uses 7.38 mm
   (4 × 47.12 / 25.53 mm). The difference is 5 % and affects Re and the
   pressure drop slightly.
5. **Support structure mass and channels.** The model has 250 000 kg and
   120 channels of 3.5 m, 20 mm bore. T gives about 200 t of structure
   [T §5.6.3, p.68] and 10 mm connecting pipes [T §5.6.5, p.70]. The origin
   of the model numbers is not in A or T. The 250 t may include the coil case
   or the vacuum-vessel supports; not checked.
6. **Critical flow for TF.** A says that 15 min "leads to the critical flow"
   for TF [A §5.2.3, p.15], but Tab.12 lists finite pressure drops
   (0.58 – 1.62 bar) for the 15 min case. The sentence appears to be copied
   from the PF and CS sections. The 30 min design time is also set by the
   structure's 7-day cooldown, not by the coils.
7. **Pressure: 24 barg (A) vs. 20 bar (T).** A proposes working pressure
   24 barg [A §5.3.3, p.16]; T's channel and structure models use a base
   pressure of 20 bar with an available drop of 0.1 bar
   [T §5.2.4, p.54; §5.6.5, p.70]. The model uses A.
8. **Structure cooldown time and the 30 min requirement.** The coil
   requirement (30 min) and the structure requirement (7 days) are different
   by a factor of 336. A model run of 1800 s therefore cools the coil busses
   only; the structure, if connected, is not expected to reach 80 K
   (it is disconnected by default).
9. **The 40 K rule: which signals?** As CS §10, item 7, plus the structure's
   own 40 K homogeneity limit (§2.3). The TF model sets the supply from the
   hottest cooled **wall** minus 40 K (C-TEMP-SP-b, FIX-28 on the
   wall-vs-outlet question) and reads the run against inlet − outlet.
10. **A has a revision with comments** ("připomínky" in the file name). If a
    later revision changes Tab.3, Tab.6 or §6.5.3, update this page and the
    model.
