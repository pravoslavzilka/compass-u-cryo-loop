# CS circuit — requirements, conditions and limits from the sources

What the two source documents say about the central-solenoid (CS) cooling
circuit: requirements, operating conditions, limits and design parameters,
each with a citation. This is the *input* side. How the model uses these
numbers is in [circulator-sizing.md](circulator-sizing.md) (design basis) and
[control-logic.md](control-logic.md) (algorithms); results are read with
[../reading-simulations.md](../reading-simulations.md).

## Sources and citation format

| Key | Document | File (in `..\material`) |
|---|---|---|
| **A** | ATEKO a.s., *Study of a cryogenic system for tokamak cooling – COMPASS-U*, report 22172-Z-R1, rev. 1, 7.10.2025, 25 pp. | `22172-Z-R1-S2 Study of a cryogenic system for tokamak_připomínky.pdf` |
| **T** | P. Barto, *Cryogenic design of tokamak COMPASS Upgrade*, doctoral thesis, Charles University, Prague 2025, 106 pp. | `thesis_sis.pdf` |

A citation is `[A §3.4, p.8]` or `[T §6.2, p.74]`: document, section (or
`Tab.`/`Fig.`/`Eq.`), page. Page numbers are the printed ones, which equal the
PDF page numbers in both files.

Tags used for each value:

- **verbatim** — a number or statement written in the source.
- **derived** — computed here from source values; the arithmetic is shown.
  Not in the source.
- **discrepancy** — the two sources, or two places in one source, disagree.
  Collected in [§10](#10-discrepancies-and-open-points).

The ATEKO text layer scrambles several tables (Tab.2, §6.5, §7.2). Those were
checked against the rendered pages, not against the extracted text.

---

## 1. Cooled objects

**Five CS coils, one or two cooling channels each, 8 channels in total.**
[A §3.3.2, p.7] Channel length about 90 m.

| Coil | Channels | Equivalent diameter | Length per channel | Copper mass | Energy to extract per coil |
|---|---|---|---|---|---|
| CS1 | 2 | 0.00696025 m | 88 m, 88 m | 714 kg | 16 MJ |
| CS2U | 1 | 0.00696025 m | 86 m | 349 kg | 7.8 MJ |
| CS2L | 1 | 0.00696025 m | 86 m | 349 kg | 7.8 MJ |
| CS3U | 2 | 0.00696025 m | 88 m, 88 m | 714 kg | 16 MJ |
| CS3L | 2 | 0.00696025 m | 88 m, 88 m | 714 kg | 16 MJ |

Source: [A Tab.2, p.7]. PFD number 22178-3-R0.

- **Channel shape:** elliptical, 8 × 6.2 mm; hydraulic diameter 6.817 mm
  [A §5.2.2, p.14]. (Tab.2 gives the equivalent diameter 6.96 mm; both values are in
  the source, the reason for the difference is not stated.)
- **Material:** copper, roughness Ra ≈ 2 µm [A §5.2.2, p.14]. OFHC copper
  [T §2.6, p.27].
- **Conductor:** 24 × 20.5 mm (CS1, CS3: 61 turns; CS2: 29 turns)
  [T Tab.5.2, p.62]. In the model-output listing it is written 20.5 × 24.0 mm
  [T §A.1, p.105].
- **Segmentation:** the maximum length of one cooling segment is about 90 m;
  CS channel diameter cannot be increased because of mechanical stress (8 T
  toroidal field, Lorentz forces of several MN) [T §5.4.3, p.62; §5.4.4, p.62].
  CS coils "would benefit from further subdivision … or a larger channel
  diameter", which is not feasible; the only remaining lever is pressure
  [T §5.4.4, p.63].
- **Wiring:** 5 CS coils on 4 power supplies; CS2U and CS2L are connected in
  series [T §5.4, p.59].
- **Cooling concept:** a central channel through the middle of the conductor;
  heat reaches the coolant by radial conduction through copper
  [T §5.4.2, p.60]. Coil insulation: about 1 mm turn insulation + 2.5 mm ground
  insulation, glass fibre, VPI epoxy [T §5.4, p.59].
- **No internal coil sensors**, because of insulation and reliability
  constraints [T §6.2, p.74].
- **Energy per discharge:** all 5 CS coils together ≈ 30 MJ in one discharge
  [A §3.3.2, p.7]. The per-coil figures above (sum 63.6 MJ, **derived**:
  16 + 7.8 + 7.8 + 16 + 16) are the energy for a rise of 80 K, 80 → 160 K, per
  coil; the sum is 63.5 MJ in [T §5.4.4, p.63 and §A.1, p.105]. They are
  capacities, not a simultaneous load: "it is impossible to predict reliably
  which coil will experience the worst-case thermal load"
  [T §5.4.4, p.63]. See [§10](#10-discrepancies-and-open-points).

Naming: Tab.5 of A calls its worst-case coil "CS1U" [A §5.1.2, p.12]. There is
no such coil. Its numbers (714 kg, 16 MJ) match CS1, CS3U and CS3L, so it is
read as a typo for one of these (see also circulator-sizing.md §2). T lists
coils without U/L suffix; "upper and lower coils are almost the same"
[T Tab.5.2, p.62].

## 2. Temperature requirements

### 2.1 Target and range

| Item | Value | Source |
|---|---|---|
| Target temperature of the assembly | **80 K**, cooled from room temperature | [A §3.4, p.8] |
| Minimum target temperature | 77 K — the system is designed for it, but the cryogenic system must not be required to reach it; it must allow later modification for it | [A §3.4, p.8] |
| Maximum target temperature | **82 K**, if 80 K cannot be reached | [A §3.4, p.8] |
| Coil operating baseline | 77 K | [T §2.6, p.28] |
| Possible later extension | down to about 60 K | [T §2.6, p.28] |
| Optimum from resistivity / heat capacity (RRR 30) | about 55 K | [T §2.6, p.28] |
| LIN evaporation temperature | 77 K at ambient pressure; helium target 80 K at LIN 77 K and 0.2 barg | [A §4.1, p.9; §6.2, p.18] |
| Heating target | back to room temperature, from 80 K | [A §3.4, p.8] |
| Idle | "keep the components at set temperature" | [A §3.2, p.6] |

### 2.2 Starting temperature after a discharge

- **137.5 K** for the CS coils "based on the thermal balance calculations"
  [A §5.1.2, Tab.5, p.12]. §6.5.2 states the design flow "at coil temperature
  137 K" [A §6.5.2, p.19]. (PF: 137 K; TF: 116 K [A §5.1.1, §5.1.3, p.12–13].)
- **Allowed rise per coil 80 K**, from a typical 80 K to a maximum of **160 K**
  [T §5.4.1, p.59]. The limit comes from mechanical analysis: temperature
  gradients inside the winding, especially between copper and insulation, lead
  to differential expansion, shear stress and long-term degradation of the
  insulation [T §5.4.1, p.59–60].
- T's 0-D simulation of the CS coils starts at **160 K** and ends at 80 K in
  30 min [T §A.1, p.103]. This differs from A's 137.5 K
  ([§10](#10-discrepancies-and-open-points), item 1).
- At t = 0 of a cooldown inside the coil, gradients are large even inside the
  insulation; after about 300 s the winding pack has equalised, while the bulk
  insulation outside the conductor is still much colder [T §5.5.1, p.64].

### 2.3 The 40 K rule

The sources state it in several forms. Which signal pair it bounds is **not the
same** in all of them.

| Form | Wording | Source |
|---|---|---|
| Cooling loops | "maximal temperature difference 40 K (T inlet − T outlet)" | [A §3.4, p.8] |
| Cooldown mode | "Limit (T_object − T_coolant) ≤ 40 K" | [A §3.2, Fig.2, p.6] |
| Coil and coolant | "maximum allowed temperature difference of 40 K between coolant and coil is required, and coils may reach temperature differences of up to 80 K" — hence the bank of individually actuated isolation valves | [T §6.1, p.74] |
| Coil to coil | all coils more than 40 K cooler than the hottest coil are temporarily isolated; a coil is opened when the hottest one approaches the 40 K difference to it | [T §6.2, p.74] |
| Cooldown mode (state diagram) | "Keep dT < 40 K !!!" | [T Fig.6.3, p.78] |
| Thermal margin | "the maximum permissible temperature difference between coil and coolant is only 40 K" | [T §4.4.3, p.44] |
| Flow sizing | the flow per channel is computed from "the maximum helium temperature difference 40 K", coil mass, channels and heat extracted | [A §5.1, p.12] |

The thesis also gives the reason: the limit protects mechanical integrity and
prevents excessive thermal stress between coolant and cooled structure
[T §2.8, p.31].

Cooling direction: the 3D CS2U model shows a cooling wave from the coolant
inlet at the **outer** radii toward the outlet on the **inside**. Cooling must
proceed from the outside inward, because the glass-fibre insulation withstands
compression much better than tension; cooling from the inside outward would
put it in tension [T §5.5.1, p.64–65]. Whether the real CS channels are routed
this way is not checked here.

### 2.4 Outlet temperature behaviour

- A 0-D model predicts an exponential decay of the outlet temperature. The 3D
  model of CS2U shows instead a **plateau** in the early cooldown: the outlet
  temperature changes only a little, so the extracted power is nearly
  constant; the outlet starts to fall only after the cooling wave has moved
  deeper into the winding [T §5.5.2, p.65]. The model was a simplified one
  without the final geometry, pressures and segmentation, so the numbers are
  "not fully representative" [T §5.5, p.64]. This matters when the outlet
  temperature stands in for the coil temperature (see
  [../reading-simulations.md](../reading-simulations.md)).

## 3. Cooldown time and cooling capacity

| Item | Value | Source |
|---|---|---|
| Cooldown after a discharge, standard (lower-performance) shot | about 15 min | [T §2.8, p.30] |
| Cooldown, high-performance shot (full field, full pulse) | must not exceed **30 min** | [T §2.8, p.30] |
| Required time in A | 15 – 30 min "for run the experiment" | [A §3.5, p.8] |
| Design time of the CS loop | **30 min** (15 min leads to critical flow) | [A §5.2.2, p.14; §5.3.2, p.16] |
| Maximum deposited energy does not reduce cooling capacity, because the energy per coil is not proportional and differs from experiment to experiment | — | [A §3.5, p.8] |

Heat balance for the worst CS coil [A §5.1.2, Tab.5, p.12]:

| Time | Heat extracted | Coil mass | Coil temperature | Heat duty per channel | Flow per channel |
|---|---|---|---|---|---|
| 15 min | 16 MJ | 714 kg | 137.5 K | 8.89 kW | 0.0428 kg/s |
| 30 min | 16 MJ | 714 kg | 137.5 K | 4.44 kW | **0.0214 kg/s** |

Check (**derived**): 16 MJ / 2 channels = 8 MJ per channel; 8 MJ / 1800 s =
4.44 kW; 4.44 kW / (5.19 kJ/kg/K × 40 K) = 0.0214 kg/s, with
c_p ≈ 5.2 kJ/kg/K for helium at 80 K, 20 bar [T Tab.4.1, p.36]. So the design
flow follows from the 40 K helium temperature rise.

**Total (derived):** 8 channels × 0.0214 = 0.171 kg/s, matching the stated
design flow. 8 channels × 4.44 kW = 35.5 kW, matching the stated sum of heat
duty 35.3 kW [A §6.5.2, p.19].

## 4. Flow and pressure

### 4.1 Design point of the CS loop

| Item | Value | Source |
|---|---|---|
| Cooling medium | helium He-4 (hydrogen only if helium cannot be used) | [A §3.6, p.9; §6.5.2, p.19] |
| Minimal design flow | **0.17 kg/s** of helium at coil temperature 137 K | [A §6.5.2, p.19] |
| Design temperature (min / max) | 77 K / 323 K (−196 / 50 °C) | [A §6.5.2, p.19] |
| Design pressure (min / max) | −1 barg / **95 barg** | [A §6.5.2, p.19] |
| Nominal working pressure | **81 barg, at the outlet of the cold compressor (CC)** | [A §6.5.2, p.19] |
| Sum of heat duty | 35.3 kW | [A §6.5.2, p.19] |
| Original (before study) | working 60 barg, design 90 barg, cooldown 15–30 min | [A §5.3.2, p.16] |
| Proposed (this study) | working 81 barg, design 95 barg, cooldown 30 min | [A §5.3.2, p.16] |
| Base pressure in the thesis | 90 bar for CS coils | [T §5.4.4, p.62–63; §6.1, p.73] |
| Pressure level during operation | the cooling circuit is operated at **constant pressure**; helium is added from storage while cooling and removed to storage while heating | [A §6.1, p.17] |
| Mass flow class of the loop | medium, "≈ 100 g/s" | [T §6.1, p.74] |

The thesis explains why the pressure is high: 20 bar did not give acceptable
pressure drops in the long CS channels [T §5.4.4, p.62–63; §4.5, p.45].
Density scales with pressure, velocity falls, and pressure drop falls roughly
with velocity squared [T §4.5, p.44]. The pressure level cannot change the
channel; "the diameter of channels … are fixed and cannot be changed because
the coils have already been under construction" [A §5.3, p.15]. IPP must
confirm the increased design pressures; the supplier may change the proposal
[A §5.3, p.15].

### 4.2 Pressure drop in the CS channel

At the design flow 0.0214 kg/s per channel, channel CS1U (D_h 6.96 mm,
ΔT 57.5 K), 30 min case [A Tab.9, p.14]:

| Inlet pressure | 80 K | 120 K | 137 K |
|---|---|---|---|
| 48 barg | 13.71 bar | 23.46 bar | 29.17 bar |
| 60 barg | 10.56 bar | 16.78 bar | 19.77 bar |
| 75 barg | 8.40 bar | 12.89 bar | 14.94 bar |
| 80 barg | 7.89 bar | 12.02 bar | 13.89 bar |
| 85 barg | 7.46 bar | 11.28 bar | 13.00 bar |
| 90 barg | 7.08 bar | 10.64 bar | 12.24 bar |

(Full table has 48, 50, 55, 60, 65, 70, 75, 80, 85, 90 barg.) At the
working pressure 81 barg, linear interpolation between 80 and 85 barg gives
about **13.7 bar at 137 K**, 11.9 bar at 120 K and 7.8 bar at 80 K (**derived**).

15 min case, 0.0428 kg/s: **critical (choked) flow** at nearly all pressures
and temperatures; at 80 K only above 70 barg it is possible (50.8 bar at
70 barg … 31.7 bar at 90 barg), at 137 K critical up to 85 barg
[A Tab.10, p.14]. Hence 30 min is the design time, and "the worst condition for
cold compressor design is at 137 K" [A §5.2.2, p.14].

Thesis 0-D model, 90 bar, 160 → 80 K in 30 min [T §A.1, p.105]:

| Coil | Segments | Length | Flow per segment | Pressure drop | Compression loss per segment |
|---|---|---|---|---|---|
| CS2L, CS2U | 1 | 86.0 m | 20.19 g/s | 5.77 bar | 349.8 W |
| CS1, CS3L, CS3U | 2 | 88.0 m each | 20.66 g/s | 6.16 bar | 382.2 W |

Summary in the text: "90 bar for CS coils, resulting in pressure drops of
approximately 5 – 6 bar" [T §5.4.4, p.63]. Totals (**derived**): flow
6 × 20.66 + 2 × 20.19 = 164.3 g/s, compression loss about 3.0 kW.

The general method: Darcy–Weisbach, Colebrook–White, typical Re ≈ 10⁵,
relative roughness ≈ 5 × 10⁻⁴, friction factor f_D ≈ 0.02
[T §4.4.1, p.41–42]; heat transfer by Dittus–Boelter
Nu = 0.023 Re^0.8 Pr^0.3 [T Eq.4.4, p.43]. "The final pressure losses of
circuit and channels have to be evaluated by the cryogenic system supplier"
[A §5.2.2, p.14].

### 4.3 Circulator (cold compressor) limits

| Item | Value | Source |
|---|---|---|
| Type | turbocompressor, the only viable solution | [T §4.2.1, p.37] |
| Efficiency | about 70 % (cryogenic conditions and compression ratios) | [T §4.2.1, p.37; §4.4.3, p.43] |
| Operating point | best performance only near the design speed; the system is designed for **one target operating point** | [T §4.2.1, p.37] |
| Loop pressure loss target | not more than roughly **one tenth of the loop working pressure** | [T §4.2.1, p.37] |
| Parasitic heat | must be minimal | [T §4.2.1, p.37] |
| Function in the loop | gives the flow through the plant, VIP and coils; raises pressure by the pressure loss of the whole system; sucks from the collector where the coils' helium is gathered | [A §6.1, p.17] |
| Instrumentation | measurement and control for continuous running "at all regimes" | [A §6.1, p.17] |
| Electric power, CS CC01 | **20 kW** | [A §7.3, p.22] |
| Cooling water for CC | about 15 kW glycol/water (all CCs) | [A §7.4, p.23] |
| UPS | for PLC loop, temperature and pressure measurement; **not** for CC operation | [A §6.4, p.19] |
| Oil-free technology | required for all parts | [A §6.3, p.18] |

Heating by compression. For adiabatic compression with efficiency η
[T Eq.4.5, p.43]:

    ΔT = T_in · [ (p_out / p_in)^((γ−1)/γ) − 1 ] / η,   γ = 1.66, η = 0.70

[T Tab.4.2, p.43] lists 20 bar cases: 17 → 20 bar at 80 K gives 7.6 K, at
160 K gives 15.3 K. "A pressure drop of 3 bar … around 10 K … one quarter of
the thermal margin … an increase of cooling power by approximately 25 %"
[T §4.4.3, p.44]. Applied to CS by the same equation (**derived**, not in the
source): 82 bar discharge and a 13.7 bar drop (A, 137 K) gives about 14.8 K at
T_in = 137.5 K; 7.8 bar (A, 80 K) gives about 4.6 K at 80 K.

## 5. Operating modes and sequence

### 5.1 The five modes in A [A §3.2, Fig.2, p.6]

1. **Cooldown from room temperature:** whole assembly RT → 80 K; focus on
   temperature homogeneity.
2. **Idle:** keep the components at set temperature; helium circulation
   optimised to save power.
3. **Tokamak discharge:** circulate with a **small mass flow** through all
   channels, "not heating or cooling"; **read object temperature**.
4. **Cooldown after the discharge:** cool all components to the set
   temperature as fast as possible; limit (T_object − T_coolant) ≤ 40 K.
5. **Heat up:** back to RT; focus on temperature homogeneity.

### 5.2 State machine in T [T §6.6, p.77–78; Fig.6.3, p.78]

| Mode | Content | Source |
|---|---|---|
| Cooldown / Heatup | whole assembly, full cooling (heating) power, homogeneity evaluated by return helium temperature; started by the operator, ends automatically at the target temperature | [T §6.6.1, p.77] |
| Idle | hold the set temperature, minimise required cooling power | [T §6.6.1, p.77; Fig.6.3] |
| Discharge | coolant flow to the coils reduced or stopped, to limit a loss-of-coolant accident; minimal mass flow, only circulate coolant, measure outlet T | [T §6.6.1, p.77; Fig.6.3] |
| Fast cooldown | after the diagnostic checks; maximum available power, staged reconnection; "as fast as possible", "keep dT < 40 K"; ends when the post-discharge temperature is reached | [T §6.6.1, p.77; Fig.6.3] |
| General fault | on a missing or incorrect reading, or a dead actuator or circulator; flow reduced to the minimum that still gives reliable coil temperature information; safe for hours because of the insulation | [T §6.6.2, p.78] |
| LoCA | detected by vacuum degradation in the cryostat; all isolation valves close at once and the circulators turn off | [T §6.6.2, p.78; Fig.6.3] |

Transitions in Fig.6.3: idle → discharge ("discharge countdown start"),
discharge → idle ("discharge aborted"), discharge → fast cooldown
("cooldown start"), fast cooldown → idle ("temperature reached").

### 5.3 Staged cooldown after a discharge [T §6.2, p.74]

1. During the discharge **all coil valves are closed** (smaller helium escape
   if a pipe breaks under the electromagnetic forces); the main flow goes
   through a **dedicated bypass line**.
2. After the discharge the coils are gradually reconnected. **A small helium
   flow goes through each coil to assess its temperature indirectly**, "since
   no internal temperature sensors are installed". Based on the measured
   **return temperature** the hottest coil in each loop is identified.
3. All coils more than **40 K cooler** than the hottest are temporarily
   isolated, to prevent overcooling by excessive local cooling power.
4. Cooling proceeds at the maximum available power. When the hottest coil
   approaches the 40 K difference to the next coil in sequence, that coil is
   opened. "All coils are gradually reconnected in a thermally safe manner."
5. Before the next shot, when all temperatures are below the required
   threshold, the bypass is reopened and all coil valves close.

## 6. Equipment and instrumentation described

### 6.1 Cold box of the CS circuit [A §6.1, p.17–18; §6.5.6, p.21]

Per circuit, in the cold box: cold compressor CC01; helium/nitrogen heat
exchanger (evaporator) HE01; helium/nitrogen heat exchanger HE02; nitrogen
buffer tank/phase separation vessel VE01; electric heater EH01; measurements;
ON/OFF solenoid valves "flow control of the cooling loops"; blower for LIN
evaporation below ambient pressure. CS cold box: diameter 2.5 m, height 3.0 m.

Control valves [A §6.1, p.18]:

| Valve | Duty in A |
|---|---|
| RV01 | on the cold-compressor bypass |
| RV02 | temperature control |
| RV03 | nitrogen control at outlet |
| RV04 | liquid nitrogen control at inlet |
| RV05 | helium flow control |
| RV06 | helium control at HE02 inlet |
| RV07 | helium management, at inlet |
| RV08 | helium management, at outlet |

Description: "ON/OFF valve switch ON/OFF flow rate trough coils according to
their temperature" [A §6.1, p.17]. Each coil has a separate pipeline for the
helium supply; the pipelines are proposed in one vacuum-insulated main
channel [A §6.1, p.17].

T's list for each loop [T §6.3, p.74–75]: circulator; LN2 heat exchanger
(using latent and sensible heat of the nitrogen); electric heater unless
circulator losses suffice; distribution valves isolating individual coils;
**a proportional bypass valve** for full recirculation when all coil valves are
closed or only a minor flow is needed; **a temperature-regulating valve to
limit cooling power at reduced flow (e.g. at the start of cooldown)**,
"thereby protecting the coils from excessive thermal gradients"; temperature,
pressure and flow sensors.

### 6.2 What the plant measures

- "Only coil temperature transmitters are located outside of the cold box.
  These transmitters are out of scope of the cryogenic system, but
  information about these temperatures will be provided to the cryogenic
  control system." [A §6.1, p.17]
- "Since most coils lack internal thermometry, the temperature of the returning
  helium serves as a proxy for their thermal state." [T §6.3, p.75]
- The distribution valves and temperature sensors of all coils sit in a
  vacuum-insulated switchbox one floor below the tokamak; only six
  vacuum-insulated lines run to the cold boxes (inlet and outlet of each of the
  three loops) [T §6.4.1, p.75].

This is the basis of the outlet-temperature rule in
[../reading-simulations.md](../reading-simulations.md).

### 6.3 Heating

- The electric heater EH01 is off in normal operation [A §6.1, p.17].
- For CS and PF it **may not be used**, because compression work of the CC can
  heat the circuit: about **30 °C/h** at cold conditions, lower at ambient
  temperature because of the smaller flow per coil, but still enough "during
  few hours" [A §6.1, p.17].
- For TF and the support structure the heater is needed (design case 40 °C
  temperature difference) [A §6.1, p.17]. Not a CS item.

### 6.4 Cold source (shared by the circuit)

- LIN evaporation, no cold cycle: the Brayton variant is excluded because the
  site has not enough electric power, cooling-medium capacity or permitted
  noise [A §4.3, p.11–12; T §4.2.2, p.37–38].
- The helium target 80 K and LIN 77 K leave a small temperature difference
  between helium and LIN at the exchanger outlets; cooling the last 3 K needs
  about as much exchanger area as the first 37 K [A §6.2, p.18]. Reaching the
  target is not guaranteed at ambient pressure; under vacuum the theoretical
  LIN limit is about 65 K [T §4.2.2, p.37–38].
- Thermal shock: at the start of coil cooling the difference between LIN (77 K)
  and helium (293 K) "can damage standard plate heat exchanger"
  [A §6.2, p.18].
- CS LIN flow **0.27 kg/s** (PF 0.35, TF 1.3, total 1.9 kg/s) at 6 barg
  [A §7.2, p.22].

## 7. Interfaces and utilities

| Item | Value | Source |
|---|---|---|
| Electric supply | 3 × 400 V, 50 Hz; study basis 100–200 kW available; mains capacity 4.5 MW | [A §3.6, p.9; §7.3, p.22] |
| Electric power available to the cryoplant (T) | about 1 MW | [T §2.8, p.31] |
| CS CC01 | 20 kW (PF 20, TF 25; total 65 kW) | [A §7.3, p.22] |
| Glycol/water | 10 °C, 100 kW available; about 15 kW used by the CCs | [A §3.6, p.9; §7.4, p.23] |
| Helium quality | 4.6 or 5.0; consumption negligible | [A §7.1, p.22] |
| Dry compressed air | dew point −40 °C for pneumatic control valves; consumption negligible (high if gas boosters are used) | [A §7.5, p.23] |
| Valve actuation | pneumatic control valves | [A §7.5, p.23] |
| Cold-box space for CS | cold box Ø 2.5 m × H 3.0 m; available area 2 × 2 × 3.05 m | [A §6.5.6, p.21] |
| Filters | all coils must have a filter, filtration size 1 µm (µ unreadable in the text layer) | [A §6.3, p.18] |
| Tightness | every set of coils better than 2·10⁻³ Pa·m³/s; whole plant better than 6·10⁻³ Pa·m³/s (below 1.9 Nm³/year) | [A §6.3, p.19] |
| Cryostat vacuum | target below 1·10⁻³ Pa, ideal about 1·10⁻⁵ Pa | [T §2.7, p.29] |
| Control system | separate cabinet; ESD by safety relay; no safety PLC and no PLC redundancy; local touch panel; PLC talks to the tokamak control system; HMI belongs to the tokamak | [A §6.4, p.19] |
| Control autonomy | fully autonomous; independent decisions; keeps running on battery in a blackout | [T §6.5, p.76] |
| Inventory management | cylinders, pressure reducing station, compressor/boosters, vacuum pump; recompresses helium to cylinders in maintenance | [A §6.5.5, p.20; T §6.5, p.76–77] |
| Expansion vessel | the circuit "can be equipped" with one, for fast temperature changes e.g. during a shot | [A §6.1, p.17–18] |
| Delivery boundary | channels in the coils and the galvanic isolators are **not** in the scope of delivery | [A §6.5.5, p.20] |
| Coil electrical isolation | ceramic insulation breaks between each coil channel and the grounded bus; coil voltage up to 1 kV | [T §4.3.3, p.39–40] |
| Bus sizing | the total bus cross-section equals the sum of its channels, so bus velocity equals channel velocity and bus pressure loss is negligible | [T §4.3.1, p.38] |
| Bus grouping | only channels of the same coil are joined in one bus, to allow individual regulation of each coil | [T §4.3.1, p.38] |

## 8. What the sources do **not** give for CS

Values the model or the control logic needs and that neither document
specifies (they are therefore assumptions in the model docs):

- Maximum cooling or heating **rate** of a CS coil (K/min), or maximum
  temperature **gradient** inside a coil. Only the 40 K difference and, for TF
  support structure, an average of about 2 K/h appear [T §5.6, p.68].
- Valve timings, and time constants of valves, circulator and heat exchanger.
- Magnitude and duration of the "small flow" for discharge and for the
  temperature probe. T gives only "small helium flow" and "minimal mass flow"
  [T §6.2, p.74; §6.6.1, p.77]; A gives "small mass flow" [A §3.2, p.6].
- Allowed time between probe and cooldown start after a discharge.
- Pressure setpoint tolerance, expansion-vessel size, helium inventory volumes
  and the volumes of headers and tees. (A received loop volumes by e-mail of
  26.6.2025, "Cooling p_V and p_d evaluation", which is not in the repository
  [A §2, p.4].)
- Idle flow and idle temperature stability (only "optimised to save power").
- Heat inleak to the CS coils in idle. T gives the thermal budget for the whole
  assembly [T §7.2, p.79–80], not per coil.
- Setpoint of the "turn-off" of cooling of a single coil (the model uses 80 K,
  taken from the target temperature).
- Circulator curve. A gives its power (20 kW) and the design flow
  [A §7.3, p.22], not the characteristic.

## 9. Model parameters traced to these sources

Only values that come from, or are compared with, A or T. Parameters of
the control algorithms (PID gains, delays, CS-PREP timings) have no source and
are described in [control-logic.md](control-logic.md).

| Model | Value | Source / status |
|---|---|---|
| `nCS`, `nChannels_CS` | 5 coils; {2, 1, 1, 2, 2} | [A Tab.2, p.7] ✔ |
| Coil lengths in `CS1…CS3L` | 88 m (2-channel coils), 86 m (CS2U, CS2L) | [A Tab.2, p.7] ✔. Comment in the model: the PFD draws 2 × 86 m for CS3 |
| `CoilAssembly.diameter` | 0.00696025 m | [A Tab.2, p.7] (reference only; D_h is derived from `crossSectionArea` / `wettedPerimeter`) |
| Coil mass | 714 kg / 349 kg | [A Tab.2, p.7] ✔ (outer cross-section chosen to match) |
| `TInitialCoil` | 137.5 K | [A Tab.5, p.12]; T uses 160 K ([§10](#10-discrepancies-and-open-points), item 1) |
| `m_flow_design` | 0.17 kg/s | [A §6.5.2, p.19] ✔ |
| CS-FLOW-SP: flow per open channel | 0.0214 kg/s | [A Tab.5, p.12] ✔ |
| `pressureSetpoint` | 82 bara = 81 barg + 1 | [A §6.5.2, p.19] (nominal at the CC outlet) ✔ |
| Design pressure limit | 95 barg | [A §6.5.2, p.19]; check the peak discharge pressure of each run against it |
| `tempMargin` | 40 K | [A §3.2, §3.4, p.6, 8]; [T §6.1, §6.2] — signal pair not identical, see [§2.3](#23-the-40-k-rule) |
| `T_supplyFloor` | 77 K | [A §3.4, p.8] (minimum target temperature) |
| `T_coldShut`, `T_releaseAll` | 80 K | [A §3.4, p.8] (target) |
| `T_LIN` | 77 K | [A §6.2, p.18] |
| `Q_LINmax` | 60 kW | **Not stated.** Derived by the model docs from the LIN flow 0.27 kg/s [A §7.2, p.22]; compare the 35.3 kW and 56 kW in A |
| `T_loopInitial` | 80 K | No number in the sources; follows from "idle: keep at set temperature" [A §3.2, p.6] |
| `n_nominal_Hz` | 200 Hz | **Assumed**, carried over from PF (no circulator data in A or T) |
| `coilIsolationCloseMargin`, `…ReopenMargin` | 40 K / 35 K | 40 K from [T §6.2, p.74]; the 35 K hysteresis is the model's own |
| Idle thermal budget, cooling-wave plateau, outlet-vs-wall offset | — | not in the model; see [§2.4](#24-outlet-temperature-behaviour) for what T says |

## 10. Discrepancies and open points

1. **Starting temperature: 137.5 K (A) or 160 K (T).** A's thermal balance
   gives 137.5 K [A Tab.5, p.12]. T allows up to 160 K and models 160 → 80 K
   [T §5.4.1, p.59; §A.1, p.103]. The model starts at 137.5 K. The PF design
   basis already moved to 160 K for the same reason; the CS one has not
   been checked until now. A 160 K start is a more severe case for CS-PREP
   (the probe would read about 160 K and the supply target would be 120 K)
   and for the pressure and power at the start. It should be run at least
   once.
2. **Coil heat per discharge: 30 MJ (A) vs. 63.5 MJ (sum of coils).** The
   30 MJ is the maximum deposited in one discharge for all five coils
   [A §3.3.2, p.7]; the per-coil figures sum to 63.6 MJ and equal T's
   80 K-rise energy of 63.5 MJ [T §A.1, p.105]. Sizing the cooling for one
   coil at 16 MJ, as A does, is consistent; the total is a capacity.
3. **CS cooling power: 35.3 kW or 56 kW.** §6.5.2 gives 35.3 kW
   [A p.19] and 8 × 4.44 kW = 35.5 kW (**derived**). §4.2 gives "CS coils:
   56 kW cooling … 840 kW of electricity" [A §4.2, p.11]. 56 kW is not
   reproduced by any of the CS numbers (8 × 8.89 kW for 15 min would be
   71 kW). Probably left over from an earlier version.
4. **Pressure: 81 barg (A) vs. 90 bar (T).** A proposes working pressure 81 barg
   and design 95 barg; T's 0-D model uses 90 bar and also speaks of "60 bar and
   90 bar" for two loops in §4.5 while §5.4.4 gives 40 bar for PF
   [A §5.3.2, p.16; T §4.5, p.45; §5.4.4, p.62]. The model uses A.
5. **Pressure drop: about 13.7 bar (A) vs. 5–6 bar (T).** A's Tab.9 gives
   13.9 bar at 137 K and 80 barg, T's model 5.77–6.16 bar at 90 bar
   [A Tab.9, p.14; T §A.1, p.105]. A's number is for the worst point (137 K,
   0.0214 kg/s); T's tool runs 160 → 80 K with 20.2–20.7 g/s, and the source
   does not say at which point of the cooldown its 5–6 bar is taken. Not
   checked which one the circulator has to deliver. The loop target "pressure loss not above one tenth of the working
   pressure" [T §4.2.1, p.37] means about 8 bar at 81 bar: met by T's 5–6 bar,
   **not** by A's 13.7 bar at the start of the cooldown.
6. **Flow of the loop: 0.17 kg/s (A) vs. "≈ 100 g/s" (T).**
   [A §6.5.2, p.19; T §6.1, p.74]. T's own model output sums to 164 g/s
   (**derived**), so "100 g/s" is a rounded class, not a requirement.
7. **The 40 K rule: which signals?** A §3.4 says inlet − outlet, A §3.2 says
   object − coolant, T §6.1 says coolant − coil and T §6.2 says coil − coil
   (see [§2.3](#23-the-40-k-rule)). The model sets the supply temperature from
   the hottest coil **wall** minus 40 K (C-TEMP-SP-b) and reads the run against
   inlet − outlet. FIX-16 records the decision to use the coil outlet
   temperature for the coil temperature.
8. **Coil naming.** "CS1U" in A Tab.5, no such coil; T lists "CS1, CS2, CS3".
   Read as CS1 / CS3U / CS3L (714 kg).
9. **A has a revision with comments** ("připomínky" in the file name). The
    values above are those in the file in `..\material`; if a later revision
    changes Tab.2, Tab.5 or §6.5.2, update this page and the model.
