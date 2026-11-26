# PF circuit — requirements, conditions and limits from the sources

What the two source documents say about the poloidal-field (PF) cooling
circuit: requirements, operating conditions, limits and design parameters,
each with a citation. This is the *input* side. How the model uses these
numbers is in [circulator-sizing.md](circulator-sizing.md) (design basis) and
[control-logic.md](control-logic.md) (algorithms); results are read with
[../reading-simulations.md](../reading-simulations.md).

Items that are the same for all three circuits (the 40 K rule in its several
forms, the operating modes and the staged cooldown, what the plant measures,
cold-box equipment, utilities) are **not repeated** here. They are in
[../cs/requirements.md](../cs/requirements.md) §2.3, §5, §6 and §7 and are
referred to as "CS §…". This page holds what is specific to PF.

## Sources and citation format

| Key | Document | File (in `..\material`) |
|---|---|---|
| **A** | ATEKO a.s., *Study of a cryogenic system for tokamak cooling – COMPASS-U*, report 22172-Z-R1, rev. 1, 7.10.2025, 25 pp. | `22172-Z-R1-S2 Study of a cryogenic system for tokamak_připomínky.pdf` |
| **T** | P. Barto, *Cryogenic design of tokamak COMPASS Upgrade*, doctoral thesis, Charles University, Prague 2025, 106 pp. | `thesis_sis.pdf` |

A citation is `[A §3.4, p.8]` or `[T §5.4.4, p.62]`: document, section (or
`Tab.`/`Fig.`/`Eq.`), page. Page numbers are the printed ones, which equal the
PDF page numbers in both files.

Tags used for each value:

- **verbatim** — a number or statement written in the source.
- **derived** — computed here from source values; the arithmetic is shown.
  Not in the source.
- **discrepancy** — the two sources, or two places in one source, disagree.
  Collected in [§10](#10-discrepancies-and-open-points).

The ATEKO text layer scrambles several tables (Tab.1, Tab.4, §6.5). They were
checked against the rendered pages, not against the extracted text. The
thesis Table 5.2 (p.62) also has a scrambled text layer (its channel lengths
are shifted by one row); its values are taken from the 0-D output in
[T §A.1, p.103–105] instead.

---

## 1. Cooled objects

**Eight PF assemblies, 2 – 4 cooling channels each, 26 channels in total.**
[A §3.3.1, p.6–7] Channel length 60 – 90 m.

| Assembly | Channels | Equivalent diameter | Length per channel | Copper mass | Energy to extract per assembly |
|---|---|---|---|---|---|
| PF1U | 4 | 7 mm | 61, 64, 61, 64 m (see §10, item 2) | 432 kg | 9.6 MJ |
| PF1L | 4 | 7 mm | 70, 74, 70, 74 m (see §10, item 2) | 432 kg | 9.6 MJ |
| PF2U | 2 | 7 mm | 80, 83 m | 261 kg | 5.8 MJ |
| PF2L | 2 | 7 mm | 80, 83 m | 261 kg | 5.8 MJ |
| PF3U | 3 | 7 mm | 83, 84, 87 m | 406 kg | 9 MJ |
| PF3L | 3 | 7 mm | 83, 84, 87 m | 406 kg | 9 MJ |
| PF4U | 4 | 9 mm | 75, 90, 90, 90 m | 840 kg | 18.7 MJ |
| PF4L | 4 | 9 mm | 75, 90, 90, 90 m | 840 kg | 18.7 MJ |

Source: [A Tab.1, p.7], rendered page. PFD number 22171-3-R0.

- **Channel:** circular, hydraulic diameter 7 mm for PF1 – PF3 and 9 mm for
  PF4. Copper, roughness Ra ≈ 2 µm [A §5.2.1, p.13]. Diameter classes of the
  PF and CS channels: 7 mm, 9 mm and the CS ellipse [T §5.4.4, p.62].
- **Conductor:** 15 × 14.7 mm (PF1 – PF3), 20 × 17 mm (PF4); 33 – 38 turns
  [T Tab.5.2, p.62; §A.1, p.103–104].
- **Coil units:** the thesis counts **10** PF coils (PF1a, PF1b, PF2, PF3, PF4,
  each upper and lower) on 8 power supplies; PF1Ua/PF1Ub and PF1La/PF1Lb are
  connected in series [T §5.4, p.59]. ATEKO's eight "objects" put PF1a + PF1b
  into one assembly: PF1U = pf1au (61, 64 m) + pf1bu (70, 74 m), mass
  200.7 + 230.7 = 431.4 kg ≈ 432 kg (**derived**, [T §A.1, p.103]). The model
  uses these eight assemblies (`PF1U … PF4L`).
- **Segmentation:** the longest segment of a PF/CS coil is about 90 m. PF4U
  has a conductor almost 400 m long, divided into four segments
  [T §5.4.2, p.60; §A.1, p.104]. Very long conductors must be divided because
  pressure drop grows roughly with the cube of the length
  [T §5.4.3, p.61].
- **Channel diameter limit:** for PF the diameter is limited by the electrical
  and thermal side (a bigger hole means less copper, more Joule heating, less
  heat capacity), not by mechanics as in CS [T §5.4.3, p.61–62].
- **Cooling concept:** a central channel through the conductor; the heat
  reaches the coolant by radial conduction through copper [T §5.4.2, p.60].
  Insulation: about 1 mm turn + 2.5 mm ground, glass fibre, VPI epoxy
  [T §5.4, p.59].
- **No internal coil sensors** [T §6.2, p.74].
- **Energy per discharge:** all PF coils together about **20 MJ** in one
  discharge [A §3.3.1, p.7]. The per-assembly figures above sum to 86.2 MJ
  (**derived**: 2 × (9.6 + 5.8 + 9 + 18.7)); the thesis gives 87.9 MJ for the
  rise 80 → 160 K [T §A.1, p.105; §5.4.4, p.63]. These are capacities, not a
  simultaneous load (see CS §1, and [§10](#10-discrepancies-and-open-points)).
- **Worst-case coil:** A names PF3U (406 kg, 9 MJ, 3 channels) for the flow
  design [A §5.1.1, p.12]. See §10, item 3.

## 2. Temperature requirements

### 2.1 Target and range

Same as CS §2.1: target **80 K**, minimum 77 K (design for it, not required),
maximum 82 K if 80 K cannot be reached, heating back to room temperature
[A §3.4, p.8]. LIN evaporates at 77 K at ambient pressure; the helium target
is 80 K at LIN 77 K and 0.2 barg [A §6.2, p.18].

### 2.2 Starting temperature after a discharge

- **137 K** for the PF coils "based on the thermal balance calculations"
  [A §5.1.1, Tab.4, p.12]; §6.5.1 states the design flow "at coil
  temperature 137 K" [A §6.5.1, p.19].
- **Allowed rise per coil 80 K**, from a typical 80 K to a maximum of
  **160 K**, set by the temperature gradient between copper and insulation
  [T §5.4.1, p.59–60].
- The thesis 0-D model starts at **160 K** and ends at 80 K in 30 min
  [T §A.1, p.103]. The model uses **160 K** (see
  [circulator-sizing.md](circulator-sizing.md) §2: "corrected worst case").
  See §10, item 1.
- Temperature differences between PF coils are expected: "it is impossible to
  predict reliably which coil will experience the worst-case thermal load"
  [T §5.4.4, p.63]. Coils may differ by up to 80 K from the coolant
  [T §6.1, p.74].

### 2.3 The 40 K rule

Same forms and same ambiguity as CS §2.3 (inlet − outlet, object − coolant,
coolant − coil, coil − coil). Two PF-specific points:

- A's Tab.7/8 compute the PF3U channel with "delta T 40 K"
  [A Tab.7, p.13], i.e. 40 K is the helium temperature rise used to size the
  flow.
- T says the effect of the 80 K coil rise is what makes the bank of
  individually actuated isolation valves necessary [T §6.1, p.74]. PF has
  eight such valves in the model.

## 3. Cooldown time and cooling capacity

| Item | Value | Source |
|---|---|---|
| Cooldown after a discharge, standard shot | about 15 min | [T §2.8, p.30] |
| Cooldown, high-performance shot | must not exceed **30 min** | [T §2.8, p.30] |
| Required time in A | 15 – 30 min | [A §3.5, p.8] |
| Design time of the PF loop | **30 min**; 15 min leads to critical flow | [A §5.2.1, p.13; §5.3.1, p.16] |

Heat balance for the worst PF coil, PF3U [A §5.1.1, Tab.4, p.12]:

| Time | Heat extracted | Coil mass | Coil temperature | Heat duty per channel | Flow per channel |
|---|---|---|---|---|---|
| 15 min | 9 MJ | 406 kg | 137 K | 3.33 kW | 0.01604 kg/s |
| 30 min | 9 MJ | 406 kg | 137 K | 1.67 kW | **0.00802 kg/s** |

Check (**derived**): 9 MJ / 3 channels = 3 MJ per channel; 3 MJ / 1800 s =
1.67 kW; 1.67 kW / (5.19 kJ/kg/K × 40 K) = 0.00804 kg/s.

**Total flow and duty (derived).** The stated design flow follows from the
sum of all eight assemblies, each cooled by its own energy:

    Σ E = 2 × (9.6 + 5.8 + 9 + 18.7) = 86.2 MJ
    duty  = 86.2 MJ / 1800 s                  = 47.9 kW   (A §6.5.1: 47.9 kW)
    flow  = 47.9 kW / (5.19 kJ/kg/K × 40 K)   = 0.231 kg/s (A §6.5.1: 0.23 kg/s)

The thesis 0-D model, 160 → 80 K in 30 min at 40 bar, sums its segment flows
to **230.6 g/s** (**derived** from [T §A.1, p.103–105]): the two sources agree
on 0.23 kg/s. A simple "26 channels × 0.00802 kg/s" would give only
0.209 kg/s, because PF4's channels carry more energy per channel
(§10, item 3).

## 4. Flow and pressure

### 4.1 Design point of the PF loop

| Item | Value | Source |
|---|---|---|
| Cooling medium | helium He-4 (hydrogen only if helium cannot be used) | [A §3.6, p.9; §6.5.1, p.19] |
| Minimal design flow | **0.23 kg/s** of helium at coil temperature 137 K | [A §6.5.1, p.19] |
| Design temperature (min / max) | 77 K / 323 K (−196 / 50 °C) | [A §6.5.1, p.19] |
| Design pressure (min / max) | −1 barg / **40 barg** | [A §6.5.1, p.19] |
| Nominal working pressure | **35.5 barg, at the outlet of the cold compressor (CC)** | [A §6.5.1, p.19] |
| Sum of heat duty | 47.9 kW | [A §6.5.1, p.19] |
| Original (before study) | working 20 barg, design 30 barg, cooldown 15–30 min | [A §5.3.1, p.15] |
| Proposed (this study) | working 35.5 barg, design 40 barg, cooldown 30 min | [A §5.3.1, p.16] |
| Base pressure in the thesis | **40 bar** for PF coils | [T §5.4.4, p.62; §6.1, p.74] |
| Mass flow class of the loop | medium, "≈ 100 g/s" | [T §6.1, p.74] |
| Pressure level during operation | constant; helium added from storage while cooling, removed while heating | [A §6.1, p.17] |

The pressure was raised because the original 20 barg gave critical flow or
too large a loss in the long channels at the design flow
[A Tab.7, Tab.8, p.13]. The channel diameters cannot be changed because the
coils are already under construction [A §5.3, p.15].

### 4.2 Pressure drop in the PF channel

PF3U channel (D 7 mm, L 87 m, ΔT 40 K), 0.00802 kg/s, 30 min case
[A Tab.7, p.13]:

| Inlet pressure | 80 K | 120 K | 137 K |
|---|---|---|---|
| 16 barg | 5.84 bar | 11.26 bar | critical flow |
| 20 barg | 4.39 bar | 7.39 bar | 8.93 bar |
| 25 barg | 3.42 bar | 5.52 bar | 6.5 bar |
| 30 barg | 2.82 bar | 4.48 bar | 5.23 bar |
| 35 barg | 2.42 bar | 3.79 bar | 4.41 bar |

At the working pressure 35.5 barg the drop is therefore about **4.4 bar at
137 K** and 2.4 bar at 80 K (taken from the 35 barg row; the difference to
35.5 barg is small, **derived**).

15 min case, 0.01604 kg/s: critical flow at 16 – 20 barg at 80 K and up to
30 barg at 120 K and 137 K; at 35 barg 10.12 bar (80 K), 17.58 bar (120 K),
22.07 bar (137 K) [A Tab.8, p.13]. Hence 30 min is the
design time, and "the worst condition for cold compressor design is at 137 K"
[A §5.2.1, p.13].

Thesis 0-D model, 40 bar, 160 → 80 K in 30 min [T §A.1, p.103–105]:

| Assembly | Segment lengths | Flow per segment | Pressure drop per segment | Compression loss (assembly) |
|---|---|---|---|---|
| PF1 (a + b) | 61 / 64 m and 70 / 74 m | 5.8 – 7.1 g/s | 0.82 – 1.41 bar | 0.18 kW (**derived**) |
| PF2 | 80 / 83 m | 7.6 – 7.9 g/s | 1.77 – 1.99 bar | 0.18 kW (**derived**) |
| PF3 | 83 / 84 / 87 m | 7.9 – 8.3 g/s | 1.97 – 2.23 bar | 0.32 kW (**derived**) |
| PF4 | 3 × 90 m, 75 m | 13.0 g/s (90 m), 10.8 g/s (75 m) | 1.56 bar (90 m), 0.92 bar (75 m) | 0.44 kW (**derived**) |

Summary in the text: "40 bar for PF coils, resulting in pressure drops of
approximately 1 – 2 bar" [T §5.4.4, p.62]. Total compression loss of the
eight assemblies about 2.2 kW (**derived**, sum of the segment values per
coil, upper and lower). The flow of the PF1 row is per upper or lower
assembly: PF1U = pf1au + pf1bu.

General method (Darcy–Weisbach, Colebrook–White, Dittus–Boelter): see CS
§4.2. "The final pressure losses of circuit and channels have to be evaluated
by the cryogenic system supplier" [A §5.2.1, p.13].

### 4.3 Circulator (cold compressor) limits

| Item | Value | Source |
|---|---|---|
| Type, efficiency, one operating point, parasitic heat | as CS §4.3 | [T §4.2.1, p.37] |
| Loop pressure loss target | not more than roughly **one tenth of the loop working pressure**: 3.65 bar at 36.5 bara (**derived**) | [T §4.2.1, p.37] |
| Electric power, PF CC01 | **20 kW** (estimate; CS 20, TF 25, total 65) | [A §7.3, p.22] |
| Cooling water for CC | about 15 kW glycol/water, all CCs | [A §7.4, p.23] |
| UPS | PLC loop, temperature and pressure measurement; not the CC | [A §6.4, p.19] |

Heating by compression (adiabatic, η ≈ 0.7, γ = 1.66)
[T Eq.4.5, p.43] and the 20 bar examples [T Tab.4.2, p.43] are as in CS §4.3.
Applied to PF by the same equation (**derived**, not in the source): at 36 bar
discharge and about 4.4 bar drop (A, 137 K) the rise is
ΔT = 137 · [(36/31.6)^0.398 − 1] / 0.7 ≈ 10.5 K.

## 5. Operating modes and sequence

Same as CS §5: five modes in A [A §3.2, Fig.2, p.6], the state machine in T
[T §6.6, p.77–78] and the staged cooldown after a discharge
[T §6.2, p.74]. PF-specific statements:

- The LoCA mode (all isolation valves close at once, circulators off) is
  "significantly effective in segmented, low-volume loops such as the PF coil
  channels", unlike the large-volume TF loop [T §6.6.2, p.78].
- The PF loop is the medium-pressure, medium-flow one: 40 bar, about 100 g/s
  [T §6.1, p.74].

## 6. Equipment and instrumentation

The cold box, the control valves RV01 – RV08, what the plant measures and the
cold source are as in CS §6.1, §6.2 and §6.4 (the same list for each circuit
[A §6.1, p.17–18; T §6.3, p.74–75]). PF-specific:

- **Heating:** the electric heater EH01 is off in normal operation; for CS
  and PF it **may not be used**, because compression work of the CC heats the
  circuit by about 30 °C/h at cold conditions [A §6.1, p.17]. (The PF model
  still contains `Heater`, driven by the temperature controller: see
  [control-logic.md](control-logic.md).)
- **LIN flow of PF: 0.35 kg/s** at 6 barg (CS 0.27, TF 1.3, total 1.9)
  [A §7.2, p.22].
- **PF cold box:** diameter 2.5 m, height 3.0 m; available area
  2 × 2 × 3.05 m [A §6.5.6, p.21].
- **Evaporator:** at the 80 K target and 77 K LIN, cooling the last 3 K needs
  about as much area as the first 37 K [A §6.2, p.18]. Thermal shock at the
  start of the cooldown (LIN 77 K against helium 293 K)
  [A §6.2, p.18].
- **Distribution:** one valve and one temperature sensor per coil, in the
  vacuum-insulated switchbox; six transfer lines in total
  [T §6.4.1, p.75].

## 7. Interfaces and utilities

As CS §7: electrical supply 100 – 200 kW (mains 4.5 MW) [A §3.6, p.9], glycol
10 °C / 100 kW [A §3.6, p.9], helium 4.6 or 5.0 [A §7.1, p.22], dry air
dew point −40 °C [A §7.5, p.23], filter 1 µm on all coils [A §6.3, p.18],
tightness [A §6.3, p.19], autonomous control [T §6.5, p.76]. Two PF items:

| Item | Value | Source |
|---|---|---|
| CC electric power | 20 kW | [A §7.3, p.22] |
| Cold-box vacuum pump (option) | 2.4 × 1.42 × 1.63 m | [A §6.5.6, p.21] |

## 8. What the sources do **not** give for PF

- Maximum cooling or heating **rate** (K/min) or temperature gradient inside
  a PF coil; only the 40 K and the 80 K rise are given.
- Cooling flow and pressure drop of PF4 at the design point: A's Tab.7 – 10
  are only for PF3U (the table has no PF4 or PF1/PF2 case). The thesis has
  PF4 only at 160 → 80 K and 40 bar.
- Magnitude and duration of the "small flow" temperature probe
  [T §6.2, p.74].
- Valve timings and time constants of valves, circulator and heat exchanger.
- Pressure setpoint tolerance, expansion-vessel size, helium inventory and
  header volumes (A received loop volumes by e-mail of 26.6.2025, not in the
  repository [A §2, p.4]).
- Idle flow and temperature stability; heat inleak per PF coil in idle (T
  gives the budget for the whole assembly [T §7.2, p.79–80]).
- Circulator characteristic: A gives its power (20 kW) and design flow, not
  the curve.
- Setpoint for turning off the cooling of a single coil (the model uses the
  relative 40 K / 35 K rule only; PF-LOWTEMP has no source and is off).

## 9. Model parameters traced to these sources

Only values that come from, or are compared with, A or T. Control parameters
(PID gains, delays, thresholds) have no source and are in
[control-logic.md](control-logic.md).

| Model | Value | Source / status |
|---|---|---|
| `nPF` | 8 assemblies, channels {4, 4, 2, 2, 3, 3, 4, 4} for PF1U, PF1L, PF2U, PF2L, PF3U, PF3L, PF4U, PF4L | [A Tab.1, p.7] ✔ |
| Coil `lengths` | PF1: {61, 64, 70, 74}; PF2 {80, 83}; PF3 {83, 84, 87}; PF4 {90, 90, 90, 75} | [A Tab.1] ✔, PF1 matches [T §A.1] rather than A's repeated pairs (§10, item 2) |
| `diameters_mm` | 7 (PF1 – PF3), 9 (PF4) | [A Tab.1, p.7] ✔ |
| `TInitial` of the assemblies | 160 K | [T §5.4.1, p.59; §A.1, p.103]; A uses 137 K (§10, item 1) |
| `TInitial` of the loop gas | 120 K since 2026-11-04 (was 80 K) | No source. Chosen as 160 − 40 K so the first contact respects the 40 K rule; see FIX-01 in [../to-fix.md](../to-fix.md) |
| `m_total` | 0.1 kg/s | **Not** the design flow. A gives 0.23 kg/s [A §6.5.1, p.19]; T "≈ 100 g/s" [T §6.1, p.74]. Not used by any controller |
| `pressureSetpoint` | 3.65 MPa = 36.5 bara = 35.5 barg | [A §6.5.1, p.19] (nominal at the CC outlet) ✔ |
| Design pressure limit | 40 barg = 41 bara | [A §6.5.1, p.19]; check the peak discharge pressure of each run against it |
| `tempMargin` | 40 K | [A §3.4, p.8; §3.2, p.6]; [T §6.1, §6.2] — signal pair not identical, see CS §2.3 |
| `coilIsolationCloseMargin`, `…ReopenMargin` | 40 K / 35 K | 40 K from [T §6.2, p.74]; the 35 K hysteresis is the model's own |
| `P_shaftLimit` | 50 kW | Not from the sources. A's CC01 estimate is **20 kW** [A §7.3, p.22]; see [circulator-sizing.md](circulator-sizing.md) §9 |
| `fan2ndOrder.T_nominal` | 160 K | design point, consistent with the thesis start temperature |
| LIN-side `coldSurface` | 77 K | [A §6.2, p.18] (evaporating temperature) |
| `tube1` evaporator | 60 × 12 mm × 10 m, one cell | **Not stated**; no source for the evaporator geometry (see FIX-25) |

## 10. Discrepancies and open points

1. **Starting temperature: 137 K (A) or 160 K (T).** A's thermal balance
   gives 137 K [A Tab.4, p.12]; T allows up to 160 K and models 160 → 80 K
   [T §5.4.1, p.59; §A.1, p.103]. The model starts at 160 K. The flow design
   in A (0.23 kg/s) is for the energy rise, not for the temperature itself,
   and agrees with T's 230.6 g/s, so it holds for both. The start
   temperature changes the first contact with the 80 K loop gas
   (FIX-01) and the circulator suction conditions.
2. **PF1 channel lengths in A Tab.1.** The rendered table gives PF1U
   "61, 64, 61, 64" and PF1L "70, 74, 70, 74". The thesis has each of PF1U
   and PF1L made of one "a" coil (61, 64 m) and one "b" coil (70, 74 m)
   [T §A.1, p.103]; mass (432 kg ≈ 200.7 + 230.7) and energy (9.6 MJ ≈
   4.6 + 5.2) fit the thesis. The model uses the thesis lengths {61, 64, 70,
   74} for both. Probably a typing error in A.
3. **"Worst case = PF3U" in A.** The flow per channel is set from PF3U
   (3 MJ per channel, 0.00802 kg/s) [A §5.1.1, p.12]. By energy per channel
   PF4 is worse: 18.7 MJ / 4 = 4.7 MJ, i.e. about 0.0125 kg/s per channel at
   the same 30 min and 40 K (**derived**; the thesis gives 13.0 g/s for
   three PF4 segments at 160 → 80 K, [T §A.1, p.104]). The total 0.23 kg/s
   comes out right only when each assembly is counted with its own energy
   (§3). A's pressure tables for PF3U therefore understate the loss in PF4
   (9 mm but 90 m and 13 g/s). PF4 is not tabulated.
4. **PF cooling power: 47.9 kW or 69 kW.** §6.5.1 gives 47.9 kW
   [A p.19], and 86.2 MJ / 1800 s = 47.9 kW (**derived**). §4.2 gives "PF
   coils: 69 kW cooling … 1 035 kW of electricity" [A §4.2, p.11]. Like the
   56 kW for CS, it is not reproduced by any number in the document (15 min
   would give 95.8 kW).
5. **Pressure drop: about 4.4 bar (A) vs. 1 – 2 bar (T).** A's Tab.7 gives
   4.41 bar at 137 K, 35 barg for a 87 m channel at 8 g/s [A Tab.7, p.13];
   T's 0-D model gives 2.05 – 2.23 bar for the 84 – 86.5 m segments of PF3 at
   40 bar and 160 → 80 K [T §A.1, p.104]. A's value is for the worst point
   (137 K, start of the cooldown); T does not say at which point of the
   cooldown its number is taken. Against the rule "loss not above one tenth
   of the working pressure" (3.65 bar) [T §4.2.1, p.37], T's 1 – 2 bar is
   met, A's 4.4 bar is **not**. The model's circulator head is 6.75 bar at
   the hot start and 10.8 bar at the end ([circulator-sizing.md](circulator-sizing.md)
   §4), which includes headers, valves and the evaporator, not only the
   channels.
6. **Flow of the loop: 0.23 kg/s (A) vs. "≈ 100 g/s" (T).**
   [A §6.5.1, p.19; T §6.1, p.74]. T's own 0-D output sums to 230.6 g/s
   (**derived**), so "100 g/s" is a rounded class, not a requirement. The
   model's `m_total` = 0.1 kg/s follows the thesis wording and is unused.
   The simulated flow is 0.38 kg/s at the hot start and 0.65 kg/s at the
   end ([circulator-sizing.md](circulator-sizing.md) §5), i.e. well above
   0.23 kg/s.
7. **Compression power: 20 kW (A) vs. 33 – 58 kW (model).** A gives a rough
   estimate for the whole CC01; the model's shaft power is 33.7 kW at the hot
   start and 58 kW at the end ([circulator-sizing.md](circulator-sizing.md)
   §5). A calls its figure an estimate ("estimated in power consumption"
   [A §7.3, p.22]), but the gap is a factor of 3 and is open.
8. **Number of PF coils: 8 (A) vs. 10 (T).** T counts PF1a and PF1b
   separately [T §5.4, p.59]; A and the model use eight assemblies
   (§1). They are the same hardware.
9. **The 40 K rule: which signals?** As CS §10, item 7. The PF model sets
   the supply from `T_gas_out_max − 40 K` (C-TEMP-SP-a, FIX-12) and reads the
   run against inlet − outlet; the coil temperature used by the algorithms is
   the gas outlet (FIX-16).
10. **A has a revision with comments** ("připomínky" in the file name). If a
    later revision changes Tab.1, Tab.4 or §6.5.1, update this page and the
    model.
