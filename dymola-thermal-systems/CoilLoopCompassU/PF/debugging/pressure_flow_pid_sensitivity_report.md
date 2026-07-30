# PFCircuit: Mass-Flow / Pressure Sensitivity to PID and Coil-Isolation Tuning

**Model:** `CoilLoopCompassU.PF.PFCircuit` (8-assembly PF coil cooldown loop, closed-loop Helium circuit, `fan2ndOrder` fixed-speed blower, PID-controlled heater/cooling sub-loop, per-assembly isolation valves)
**Fixed simulation budget:** `StopTime = 1815 s` — this is a real operational constraint (maximum allowed cooldown window), not a solver setting; it cannot be extended to let the system reach a converged steady state.
**Status:** Empirical finding confirmed and reproduced; underlying physical/numerical root cause **not yet conclusively identified**. Two plausible mechanisms were tested against data and ruled out (see below). This report documents what is solid, what was ruled out, and what remains open.

---

## 1. The observed phenomenon

Two runs of the same 1815 s cooldown scenario, differing only in PID gains and coil-isolation stabilization margins — both changes well within the range of routine tuning — produce dramatically different outcomes despite reaching **very similar coolant temperatures**:

| Quantity (at t = 1815 s) | Run A ("aggressive" PID) | Run B ("gentle" PID) | Difference |
|---|---|---|---|
| `PID.k`, `PID.Ti` | 0.12, 12 | 0.08, 20 | — |
| `overCoolStabilizeDelay`, `overCoolStabilityBand` | 20, 20 | 5, 30 | — |
| `sensor_T` (coolant supply temp) | 77.9 K | 77.9 K | ~identical |
| `T_gas_out_max` (hottest coil) | 82.87 K | 81.19 K | Run B slightly *better* |
| **`sensor_m_flow` (circuit mass flow)** | **0.532 kg/s** | **0.855 kg/s** | **+61% in Run B** |
| Loop pressure (`junction5.p`) | 3.79 MPa | 5.85 MPa | +54% in Run B |
| Fan-inlet gas density | 20.4 kg/m³ | 31.9 kg/m³ | +56% in Run B |
| Fan shaft power (`P_shaft`) | 64.9 kW | 106.2 kW | +64% in Run B |
| Fraction of run with `PID.y` pinned at max cooling (-60) | 42.97% | 29.41% | — |

**Key point:** the coolant *temperature* control is doing its job about equally well in both cases (both land within ~1 K of each other), but the **mass flow delivered to the coils differs by 61%**, and it tracks a **loop pressure that differs by over 50%** — despite gas temperature being nearly identical between the two runs at every comparable timestamp. Since cooling power ≈ ṁ·cp·ΔT, this pressure/flow gap dominates the actual heat-removal outcome far more than the temperature-tracking quality does.

---

## 2. What the divergence looks like over time

Both runs start identically and dip together early on (m_flow ~0.4-0.55 kg/s from t≈100-1000s in both). They diverge sharply only in the **back third of the run**:

- Run A: m_flow stays essentially flat (~0.53 kg/s) from t≈1000s to t=1815s; loop pressure *declines* monotonically the whole time (4.55 → 3.79 MPa over that span).
- Run B: m_flow climbs steadily from ~0.54 kg/s (t≈1000s) to 0.855 kg/s (t=1815s); loop pressure *recovers and climbs* (5.30 → 5.85 MPa over the same span).

**Neither run has reached a converged state by the 1815 s cutoff** — Run A's pressure/flow are still falling, Run B's are still rising, when the simulation is forced to stop. The two "final" numbers being compared are two different points on two different, still-moving trajectories, not two steady-state outcomes.

---

## 3. Hypotheses tested and ruled out

### 3.1 Self-referential setpoint (partial context, not the mechanism)
`wanted_temp = T_gas_out_max - tempMargin` is revalued continuously from the very quantity the loop is trying to cool. This means the PID is regulating a *gap* (coolant vs. hottest coil), not driving an absolute target — a "well-tracked" PID says nothing about whether the underlying plant is actually improving. This is real and worth keeping in mind, but it does not by itself explain the pressure/flow divergence documented here.

### 3.2 "Fan constantly adds heat vs. shrinking cold-surface capacity" (retracted)
Initial hypothesis: the fixed-RPM fan continuously does real shaft work on the gas (confirmed: `fan2ndOrder.summary.speed_rpm` is bit-identical constant, 10,020 rpm, in both runs — shaft power is NOT constant, though: it scales with the density/flow being moved). The cold surface (fixed 77 K) has a heat-removal capacity that shrinks as gas approaches 77 K (smaller ΔT). The theory was that once fan heat input exceeds shrinking cooling capacity, pressure/flow self-reinforce upward. This is *consistent* with the data (net `P_shaft − Q_cold` does flip sign into positive territory in the back third of both runs, and flow acceleration follows), but it does not fully explain why the two runs' crossover timing and post-crossover growth *rate* differ as much as they do, and it was not independently verified beyond correlation. **Not confirmed as the root cause.**

### 3.3 "Cold trap hoarding gas mass" (refuted by direct measurement)
Theory: the coldest point in the loop (`tube1`/`coldSurface` sub-branch) accumulates disproportionate gas density/mass at the expense of the rest of the circuit, starving the fan/coils.
**Directly tested:** pulled `tube1`'s own gas mass (density × volume) over time in both runs. If hoarding were happening, `tube1` mass should rise while the rest of the loop's pressure falls (inverse relationship). **Observed: they move together, same direction, in both runs** (both decline in Run A, both climb in Run B). This mechanism is **ruled out**.

### 3.4 Coil-to-coil non-uniformity (checked, not a factor here)
Checked whether some coil assemblies cool much faster than others, creating an uneven load. **Found the opposite**: all 8 assemblies track within ~1-1.5 K of each other throughout the 90-170 s window (e.g., at t=90.6s: 158.96–159.27 K across all 8; at t=167.0s: 156.60–157.63 K across all 8). The coils behave essentially as one lumped mass thermally, at least in this window. Not the source of the divergence.

---

## 4. Confirmed, measured facts (solid ground)

1. **The valve states are not the cause.** Both runs converge to *identical* local heater/cooling sub-loop valve commands once fully saturated (`valve6` pinned at Kv=5000 / fully open, `valve5` pinned near-shut) — yet flow/pressure keep diverging afterward regardless.
2. **Temperature is not the cause, at least not directly.** Gas temperature at the fan, at the cold-trap tube, and at the coil outlets is nearly identical between the two runs at matching times. The pressure/density divergence tracks almost exactly with `P/T` (ideal-gas-consistent), meaning it is fundamentally a **pressure-level** divergence, not a temperature-driven density difference.
3. **It is loop-wide, not local.** Every point checked (fan, cold-trap tube, a representative coil assembly) rises and falls *together* — this is a system-wide pressure-level effect, not mass moving from one region to another.
4. **The system never reaches steady state within the 1815 s budget**, in either configuration — flow and pressure are both still actively moving when the simulation is cut off.
5. **The commonly-cited "40 bar operating pressure" is not enforced anywhere past t = 0.** Every fluid volume in the model uses `pInitial = 4×10⁶ Pa` as an initial *guess*; only one component (the 0.5 m³ `volume` near `coldSurface`, plus `tube1`) has `fixedInitialPressure` left at its class default of `true` — genuinely anchoring the whole network to a consistent 40 bar at t=0 (confirmed: every other junction's actual solved t=0 pressure reads exactly 4.0 MPa in saved results, propagated from that one anchor). But `fixed=true` in Modelica only pins the *initial* value for solving consistent initial conditions — it does **not** hold the pressure at that value during the transient. Nothing in the model regulates or bounds the loop's pressure once the simulation starts running; it is free to end up anywhere the fan-work/cooling/mass-conservation balance takes it.
6. **Attempting to force every component to a fixed 40 bar start (rather than free-floating from a 40-bar guess) breaks the model.** Setting `fixedInitialPressure=true` on all ~33 volumes/junctions across `PFCircuit.mo` and the `CoilAssembly*ch.mo` files over-constrains Dymola's initialization DAE (`"72 too many scalar conditions... 14 too few"`) — junction pressures are not independent of their neighboring (already-fixed) tube pressures; the network can only tolerate one class of anchor, not all of them simultaneously. Reverted.
7. **11 junction components (inside the `CoilAssembly2ch/3ch/4ch` per-coil geometry) use `pInitial = 2×10⁶ Pa` (20 bar) instead of 40 bar.** This was suspected to be a stale/incorrect value and "corrected" to 4×10⁶ Pa — but verification against a completed run showed these 20-bar values are the **genuine, physically consistent solved pressures** at those specific junctions (confirmed directly: `PF1U.junction1.p` and `PF1U.junction2.p` read exactly 2.0 MPa at t=0 in real simulation output, not just as an initial guess). Changing the guess to 40 bar broke Newton-solver convergence at initialization entirely (`"Failed to solve nonlinear system... could not solve simplified initialization for homotopy method"`). Reverted. This strongly suggests a genuine ~20 bar pressure drop is expected/designed-in at those specific points (likely across a valve/restriction between the 40-bar tube and that junction), not an error.

---

## 5. Sensitivity to small parameter changes

The two runs compared above differ only in four tuning parameters, all of which are "normal" PID/isolation-margin knobs, not structural changes:

| Parameter | Baseline (code default) | Run A | Run B |
|---|---|---|---|
| `PID.k` | 0.085 | 0.12 | 0.08 |
| `PID.Ti` | 18 | 12 | 20 |
| `overCoolStabilizeDelay` | 5 | 20 | 5 |
| `overCoolStabilityBand` | 20 | 20 | 30 |

A roughly 40% change in `k`/`Ti` and a factor-of-4 change in `overCoolStabilizeDelay` between two otherwise-reasonable tunings produced a **61% difference in delivered mass flow** and a **54% difference in loop pressure** at the fixed cutoff time. Separately, a newly added per-coil isolation rule (`lowTempCoolantOptimization`, absolute 80 K threshold + neighbor-hot-count condition) closed 6 of 8 coil assemblies and stalled the solver for 12+ hours in a window (t≈95-170 s) already flagged as numerically fragile by a pre-existing code comment (from 2026-07-27, well before this investigation) describing a "6-decade Kv collapse" issue in that exact time range. A 10-second continuous-dwell debounce (mirroring the existing `overCoolStabilizeDelay` pattern) was added to fix the immediate stall, but its effect on the broader flow/pressure sensitivity described in this report has not yet been evaluated.

---

## 6. Open questions for review

1. **Is there a real, quantifiable physical mechanism** (e.g., a closed-loop energy balance between constant fan shaft work and a cold-surface heat sink whose capacity shrinks as gas approaches ~77-80 K) that would predict this kind of path-dependent, self-reinforcing pressure divergence in a fixed-mass compressible-gas loop — or is this symptomatic of something else (numerical/solver behavior, an under-specified boundary condition, a missing pressure-regulation element in the model)?
2. **Should the loop have an explicit, enforced operating-pressure boundary condition** (e.g., a relief/makeup mechanism, or a genuinely regulated 40 bar reference) rather than leaving system pressure as a free, history-dependent outcome of the fan/cooling/mass-conservation balance? Right now "40 bar" is only ever a t=0 solver anchor, not an operating setpoint.
3. **Is 1815 s enough simulated time to draw "final value" conclusions at all**, given neither tested configuration reaches a converged state by then? If the real cooldown window truly is capped at 1815 s, should evaluation criteria be redefined around trajectory shape / rate-of-change at cutoff rather than point values?
4. **Given the demonstrated sensitivity**, is comparing point-in-time outcomes across differently-tuned runs a valid methodology at all, or does a fair comparison require normalizing for where each run sits along its own unfinished transient (e.g., comparing at matched `PID.y`-saturation-fraction rather than matched wall/sim time)?
5. The 20-bar vs 40-bar junction finding (§4.7) suggests the model may already encode a real, intentional pressure drop at specific points — is that geometry/valve configuration actually correct and intended, or does it itself warrant review?

---

*Prepared from a Claude Code investigation session analyzing saved Dymola results (`data/PF/overCoolStabilize delay/result_ideal-run-PID.mat`, `result_not-ideal-run-PID.mat`) and `debugging/dslog.txt`/`dsin.txt` from the CoilLoopCompassU PFCircuit model. All temperature/pressure/flow figures above are pulled directly from those result files, not estimated.*
