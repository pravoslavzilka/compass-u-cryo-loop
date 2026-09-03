# Migration notes: OpenModelica prototype → Dymola (TIL/TSMedia) rebuild

Troubleshooting log for the COMPASS-U cryo helium loop model as it's rebuilt
from the hand-derived causal prototype (`prototype-openmodelica/`) into the
full Dymola Thermal Systems model (`dymola-thermal-systems/`).

Purpose: record non-obvious issues and their root causes so the next person
(or the next AI session) hitting the same symptom doesn't have to re-derive
it from scratch. Add a new dated entry per issue, most recent first. Keep
entries even after they're fixed — "what it looked like" is often the only
way to recognize the same bug again.

---

## 2026-09-03 — **IMPORTANT:** `fan2ndOrder.maxDeltaT` default (5K) silently violated energy conservation across the whole loop — raised to 20K, confirmed against a fresh run

**Status: fix confirmed working**, via a full before/after conservation-law
audit (mass, energy, second law, CoolProp property cross-checks) of two
`debugging/result.mat` runs — not just a parameter diff. Because this
distorts every circulator-power, loop-energy, and HX-duty number from any
run made before this fix, **treat P_shaft, total loop energy balance, and
downstream Q_HX/duty-cycle figures from any `result.mat` older than
2026-09-03 16:59 as unreliable** until re-checked.

**Symptom:** an independent conservation-law audit of `debugging/result.mat`
(a passive coil cooldown from a 160K initial condition, no active heat
pulse) found the whole-loop energy balance short by 48.8 MJ — 44.5% of the
heat extracted at the HX. Localizing it: `fan2ndOrder`'s own enthalpy rise
(`mdot·(h_out−h_in)`, using the true upstream neighbor's outflow enthalpy,
not the degenerate `port.h_outflow` — see the note in the audit report)
was only 13.3 kW against a reported `P_shaft` of 40.3 kW (67.8% residual),
and — the more serious finding — the circulator's outlet entropy was
*lower* than its inlet on 79% of the sampled points, a straight-up
second-law violation for an adiabatic compressor. None of this showed up
as a solver failure, state-event spike, or `dslog.txt` warning storm — the
run reported `SUCCESSFUL simulation` throughout. It was only visible by
independently checking mass/energy/entropy balances against the
trajectory data, not from any log Dymola produces on its own.

**Root cause:** `fan2ndOrder.maxDeltaT` — a TIL `Fan2ndOrder` parameter
that hard-limits the temperature rise it will compute from portA to
portB — was left at its default, `5 K`. The measured ΔT sat clustered at
4.5–4.8 K for the *entire* run regardless of operating point (mass flow
swung 0.32–1.01 kg/s, P_shaft swung 28–71 kW) — the signature of a clamp,
not free physics; a real compression ΔT would track those swings far more
loosely. `fan2ndOrder.warningQ_flow_loss` was active 100% of the 641
logged samples the whole time, and TIL's own User's Guide documents
exactly this condition: *"warningQ_flow_loss indicates that the maximal
possible temperature difference from portA to portB is reached. To avoid
the warning, you can increase the value of maxDeltaT in the advanced
tab."* 5 K reads like a generic/HVAC-fan default — nowhere near sized for
a cryogenic helium circulator with this much compression heating.

**Fix applied:** `PFCircuit.mo`, `fan2ndOrder` instance declaration (~line
181) — added `maxDeltaT=20`. The same change also flipped
`enableCirculatorPowerOptimization` `true→false` (forces `PF_RV01` shut
for the whole run); that's a **separate, bundled, not-yet-isolated**
change — see "Not yet confirmed" below.

**Confirmed via a fresh VM run** (`debugging/result.mat`, re-run
2026-09-03 16:59, `dslog_simulate.txt` shows `SUCCESSFUL simulation`, 52
state events, no solver failures):

| Check | Before (maxDeltaT=5) | After (maxDeltaT=20) |
|---|---|---|
| Circulator enthalpy balance | 67.8% residual | 0.38% |
| Whole-loop energy balance | 44.5% short (48.8 MJ) | 0.96% (1.53 MJ) |
| Circulator second law (entropy rise) | true 21% of samples, mean Δs = −154 J/(kg·K) | true 100%, mean Δs = +206 J/(kg·K), min +145 |
| Coil copper cooldown closure (unaffected, sanity check) | 0.04–0.05% | 0.01–0.02% |

The whole-loop fix shows up as `∫Q_cold` rising from 109.65 MJ to
159.37 MJ, not `P_shaft` moving much (71.6→74.1 MJ) — the physically
correct signature: previously the circulator was under-heating the gas,
so less heat ever reached the HX to extract; fixed, the gas properly
carries the circulator's full shaft input through to the coldSurface
boundary.

**Not yet confirmed:**
- This run bundled two changes (`maxDeltaT` and
  `enableCirculatorPowerOptimization`). The circulator-thermodynamics
  fixes above (Check 3a/6a in the audit) are attributable to `maxDeltaT`
  alone — `enableCirculatorPowerOptimization` only affects `PF_RV01`'s Kv
  command, a separate valve, not `fan2ndOrder`'s own h/T/s relationship —
  but the power-optimization control loop itself has not been re-tested
  *with* the circulator fix in place. Needs a follow-up run with
  `maxDeltaT=20` and `enableCirculatorPowerOptimization=true` together.
- `warningQ_flow_loss` is still active 96.9% of the run at `maxDeltaT=20`
  — ΔT now runs close to (occasionally at) the new 20K ceiling during the
  hottest part of the cooldown, just no longer clamping hard enough to
  lose energy. If this circuit is ever driven to a hotter/higher-flow duty
  cycle than this scenario, re-check whether 20K still has margin.
- `RV08.warningNegativeFlowArea` chatter (42% active, 50 toggles) is
  **unchanged** by this fix — a separate, already-partially-documented
  issue (see the RV07/RV08 entries elsewhere in this doc), still open.

**How it was found:** not from `dslog.txt`/warnings — the run looked
completely clean at the solver level. Found by treating "solver reports
success" and "physically conserves mass/energy/entropy" as two different
claims and checking the second one directly: extracted the full
trajectory set via `DyMat`/`scipy.io.loadmat`, computed mass and energy
balance residuals at every node/component, and cross-checked density and
entropy against CoolProp's real-gas Helium EOS (with a datum-offset
correction for TSMedia's enthalpy reference, fit from components that log
both T and h). Once the residual was localized to `fan2ndOrder`, TIL's own
`warningQ_flow_loss` documentation (surfaced by asking what the flag
means, in Dymola's own diagnostic message) confirmed the mechanism
directly — no source access to the proprietary `Fan2ndOrder` model was
needed.

**General lesson:** a component defaulting to "successful simulation, no
warnings that look fatal" is not the same as "conserves energy correctly"
— `maxDeltaT`'s clamp fired continuously for 1815s without ever aborting
the run or spiking the event count, because it's designed to protect the
solver from nonphysical Newton trial states, not to signal a steady-state
energy leak. Any TIL/Modelica component with a similar protective clamp
(anything with a `max*`/`min*` "advanced tab" parameter and a matching
`warning*` output) is worth checking the same way — active-100%-of-the-run
on that warning is a strong tell that the clamp isn't just protecting
against transients anymore, it's silently gating the steady-state
solution. Add this to the same "successful-looking run can still hide a
real bug" family as the 2026-09-01 RV07/RV08 entry below.

---

## 2026-09-01 — RV07/RV08 pulse controller stuck permanently open: chained `when/elsewhen` branch collision silently ate a transition

**Status: fix applied.** The run that exposed the bug is also the evidence
for it (see below); the fix itself needs a fresh VM run to confirm.

**Symptom:** after rewriting RV07/RV08's suction-pressure control from a
plain hysteresis band to a feedforward-pulse-then-PID-trim design (see
`docs/algorithms.md` for the full design), a run came back looking
dramatically better: state events dropped to 51 (vs. 731–1007 in prior
hysteresis-only runs) and `sensor_p_suction` sat dead flat at exactly
`3,650,000` Pa for hundreds of seconds at a stretch, from t≈400s to the
1815s stop time. It looked like the rewrite had worked perfectly on the
first try.

**Root cause:** it hadn't — `makeupActive` got stuck `true` for the entire
second half of the run (confirmed via `result.mat`: an unbroken `1` from
t=126s to t=1815s). The cause was the three-branch `when ... elsewhen ...
elsewhen ... end when` block driving `makeupActive`/`makeupPulsing`. A
chained `when/elsewhen` behaves like an if-elseif: whenever ANY branch's
condition gets a fresh edge, Dymola evaluates all branches top-to-bottom
and executes only the body of the FIRST one that's currently true — even
if a later branch's own condition is also true at that same instant, its
body is silently skipped. The "stop pulsing" branch
(`makeupDeliveredMass >= makeupPulseTargetMass OR sensor_p_suction >=
pMakeupClose`) and the "stop active" branch (`sensor_p_suction >=
pMakeupClose`) shared that same pressure-crossing trigger. Whenever a
pulse happened to end because pressure itself reached `pMakeupClose`
(rather than the mass integral reaching its target first), both
conditions went true at the identical instant, and "stop pulsing" —
listed first — silently swallowed "stop active" every time. With
`makeupActive` stuck `true`, `RV07Limiter`'s PID-trim branch ran
unconditionally for the rest of the run, quietly converging the whole
loop to `pressureSetpoint` with a tiny self-balancing Kv — a genuine
stable equilibrium, which is exactly why the run *looked* like a clean
success rather than a bug. `RV08`/relief happened to escape the same
collision in this particular run only because its pulse ended much
earlier (t≈5s) than its active-close event (t≈124s) — no shared instant,
no collision, purely by luck of the timing.

**Fix applied:** split each valve's chained `when/elsewhen/elsewhen` into
three independent `when` blocks (`PFCircuit.mo`, RV07/RV08 make-up/relief
section, right before the final `equation` block). Independent
`when`-blocks are each evaluated on their own edge regardless of what
else is true at the same instant — Modelica does not apply if-elseif
branch priority *across* separate `when` statements, only *within* one
chained `when/elsewhen` — so this exact collision can no longer suppress
one transition with another.

**How it was found:** the "it looks too good" result itself was the
trigger to investigate rather than accept it. Pulled `makeupActive`/
`reliefActive`/`makeupPulsing`/`RV07.KvValue_in`/`PID_pressure.y` traces
from `result.mat` via `scipy.io.loadmat`, saw `makeupActive` never
toggling back to `false` after ~t=126s despite pressure clearly climbing
well past `pMakeupClose` shortly after, then re-read the `.mo` source's
`when/elsewhen` chain against Modelica's documented if-elseif
branch-priority semantics to find the exact collision.

**General lesson:** a suspiciously clean result right after a nontrivial
control-logic rewrite is itself a signal worth checking, not just
accepting — "51 state events and dead-flat pressure" was a symptom of a
stuck latch, not evidence the new design worked. Separately: a chained
`when ... elsewhen ... end when` is only safe when the branch conditions
are genuinely mutually exclusive. If two branches' conditions can
plausibly become true at the same simulation instant — here, both driven
off the identical threshold crossing — use independent `when` blocks
instead, so each transition is guaranteed to fire on its own edge rather
than competing for priority with another.

---

## 2026-09-01 — RV07/RV08 capacity raised 5 → 15 (first incremental step), paired with buffer volume and `PID_pressure.yMax`/`yMin` increases

**Status: change applied, not yet run in the VM to confirm.**

**Context:** once the `when`-clause initialization bug below was fixed,
RV08 started actually opening — but it saturated at its `KvReliefMax=5`
cap almost immediately and stayed there for ~1700s of a 1815s run without
bringing suction pressure into the `pressureSetpoint` deadband; it only
managed to plateau the rise around 3.0 MPa, ~350,000 Pa above target. `5`
was deliberately undersized (cut from an original `500` after the
2026-08-10 debugging runs — see `KvGainMakeup`'s docstring) specifically
because this loop's small internal compliance next to the effectively
rigid, fixed-pressure `makeupReservoir`/`reliefReservoir` boundaries makes
a large Kv numerically stiff enough to collapse the solver's corrector
step. Simply raising the cap back toward the old value risks reproducing
that exact failure.

**Change applied (incremental, paired, not a jump back to 500):**
- `KvMakeupMax`/`KvReliefMax`: `5 → 15`.
- `makeupBuffer`/`reliefBuffer` volume: `1e-3 → 1e-2` m³ — raised
  alongside the Kv cap specifically to buy back some of the compliance
  margin a bigger Kv spends, rather than just pushing more flow through
  the same narrow numerical bottleneck.
- `PID_pressure.yMax`/`yMin`: `2.5 → 7.5` — kept at exactly
  `KvReliefMax/KvGainRelief` (`15/2=7.5`), preserving the "yMax sits at
  the downstream Kv clamp, no windup headroom past what's usable"
  invariant the 2026-08-31 anti-windup fix established (see
  `PID_pressure`'s own docstring) — raising the Kv cap without also
  raising this in proportion would have made `PID_pressure`'s own output
  saturation the new hidden bottleneck instead, silently capping the
  effective Kv at the *old* value regardless of what `KvReliefMax` said.

**Not changed:** `KvGainMakeup`/`KvGainRelief` (still `2`), `valveRampTime`
(still `8`s), `pInitial` (still `3650000` everywhere). Intent is to take
one incremental step, re-run in the VM, and check `dslog.txt` for
corrector-step collapse or a warning-count spike before raising further —
per `KvGainMakeup`'s docstring, even `Kv~15` alone (without the larger
buffer) was already enough to nearly equalize the loop with the reservoir
within one dwell window in the 2026-08-10 runs, so this step is not
assumed safe, just a smaller, more diagnosable step than jumping straight
back to a much larger cap.

**How to confirm:** re-run in the VM, then check `reliefActive`/
`RV08.KvValue_in`/`fan2ndOrder.portA.p` in the new `result.mat` the same
way as the entry below, and check `dslog.txt`'s warning/state-event counts
and CPU time against this run's baseline (7 state events, 65.5s CPU,
`SUCCESSFUL simulation`) for signs of the 2026-08-10 stiffness failure
re-emerging.

---

## 2026-09-01 — RV07/RV08 make-up/relief mechanism silently inert for a full run when `pInitial` and `pressureSetpoint` disagree: `when`-clause rising edge missed at t=0

**Status: fix applied, not yet re-run in the VM to confirm** — the trace below
is from the *pre-fix* run that exposed the bug; a fresh run is needed to
confirm `reliefOpenPending`/`reliefActive` actually engage now.

**Symptom:** lowered `pressureSetpoint` from `3650000` to `2650000` Pa
(26.5 bar) to see whether the pressure-control loop's earlier oscillation
would go away. It did — but `fan2ndOrder.portA.p`/`portB.p` never converged
anywhere near the new setpoint either: suction pressure traced a smooth decay
from ~5.5 MPa (t≈25s, startup transient) down to a minimum of ~2.83 MPa
(t≈1400s), then crept back up to ~2.89 MPa by the 1815s stop time — nowhere
near the intended 2.65 MPa band, for the entire run.

**Root cause:** confirmed directly from `debugging/result.mat`
(`scipy.io.loadmat`, same technique as the 2026-07-14 entries below):
`makeupActive`, `reliefActive`, `makeupOpenPending`, `reliefOpenPending` were
`false` for all 518 saved points, and `RV07.KvValue_in`/`RV08.KvValue_in` sat
flat at `Kv_shut_pressureValves` (0.01) for the entire run — both valves
stayed fully commanded shut throughout. Every junction in the loop still
initializes at `pInitial=3650000` Pa (unchanged), so
`dp_suction.y(0) = sensor_p_suction(0) - pressureSetpoint = 1,000,000` Pa —
already ~50x past the `pressureDeadband=20000` Pa threshold before
integration even starts. The `when` clauses driving
`makeupOpenPending`/`reliefOpenPending` (`PFCircuit.mo`, ~line 781/795) only
fire on a false→true transition of their condition; per Modelica semantics
`pre(v)=v` for every variable at the initial event, so a condition already
true at t=0 registers no transition and the clause never fires.
`dp_suction.y`'s minimum over the whole run was 177,231 Pa — it never dipped
back inside the deadband either, so there was never a second chance at a
rising edge. Net effect: the entire pressure-control mechanism was silently
disabled for the full 1815s, and the smooth pressure trace could easily be
misread as "it converged" — it was actually just the loop's own
thermal/hydraulic dynamics (compressor dp establishing itself from a
uniform initial pressure field, plus `coldSurface`'s constant 77K heat
removal cooling the bulk gas at ~constant mass) running completely
unregulated.

This is the same trap the original `pInitial=pressureSetpoint=3650000`
configuration avoided by accident, not by design — with the two matched,
`dp_suction.y(0)~=0` starts *inside* the deadband, so ordinary
startup/transient noise crossing the deadband edges generated real events
and the FSM engaged (arguably too eagerly — see the RV07/RV08 chattering
referenced in `pressureDwellTime`'s own docstring, from the 2026-08-10
debugging runs). Changing only `pressureSetpoint` without touching
`pInitial` (or the FSM's initialization) traded "chatters right at the
noisy start" for "never engages at all" — neither is the intended behavior.

**Fix applied:** `makeupOpenPending` and `reliefOpenPending`'s `start`
values (`PFCircuit.mo`, ~line 102/109) now evaluate
`dp_suction.y < -pressureDeadband` / `dp_suction.y > pressureDeadband`
instead of a hardcoded `false`. `*OpenPendingSince` stays `start=0` (dwell
timing starts from t=0 if already pending at initialization). Deliberately
did **not** initialize `makeupActive`/`reliefActive` directly to skip
straight to "open" — that would bypass `pressureDwellTime`'s debounce for
the initial condition; routing through `*OpenPending` first means an
already-outside-deadband start still has to survive the same 15s dwell as
any mid-run excursion before a valve actually opens, matching the existing
noise-filtering intent. `pInitial` was deliberately left untouched — setting
it equal to `pressureSetpoint` was considered and rejected (see root cause
above: it only avoids this specific bug by accident, and reintroduces
edge-of-deadband startup sensitivity).

**How it was found:** `result.mat` from a live VM run (2026-09-01,
`dslog.txt` timestamp 10:20:32, `SUCCESSFUL simulation`, 7 state events,
17.8s CPU) pulled via `scipy.io.loadmat` on the host and cross-checked
against the `PFCircuit.mo` source for `pInitial`/`pressureSetpoint`/the
`when`-clause definitions.

**General lesson:** a `Boolean`/`Real` discrete state driven only by `when`
clauses (never given a defining equation) needs its `start` value to
actually reflect the condition it's meant to track, if that condition can
plausibly already be true when the simulation starts. Hardcoding
`start=false` "for a clean initial state" is only safe if the corresponding
condition is also guaranteed false at t=0 — here that guarantee depended on
an unstated coupling between two independently-tunable parameters
(`pInitial` and `pressureSetpoint`) that nothing in the model enforced. Any
other edge-triggered dwell/pending FSM in this file (the
`overCoolRecovering`/`coilOpen` families use the same pattern) is worth
checking for the same silent assumption before changing an initial
condition or a setpoint independently of the other.

---

## 2026-08-31 — Dead-end `volume`/`valve` pocket on the Heater-inlet branch stalled `PFCircuit` for days: TSMedia `h_min` chattering

**Status: fix confirmed working**, via before/after `dslog_simulate.txt` (commit
`893d480`, "Buffer tank removed completly") plus two live VM runs during the
investigation.

**Symptom:** simulation runs that should finish in minutes were taking days
without completing, or dying outright mid-log. Two runs observed directly:
one whose `dslog.txt` simply stopped mid-line (no `Integration terminated`,
no stats block) after simulating only to t≈1571s; a later one that crawled
for 4+ days of wall-clock time and only reached t≈1178s. Both showed the
same warning storm building up through the run:
```
TSMedia-Error(PFCircuit.valve.gasInB.gasPointer, ...): h (=-8.93e+06 J/kg)
< h_min (-1.54e+06 J/kg at T=2 K), T limited to 2 K, ...
```
on `PFCircuit.valve.gasInB`/`gasInA` and `PFCircuit.junction2.gas` (200+
occurrences in the 4-day run, clustering ever more densely — t≈186s, 240s,
360s, 901s, 924s, 936s, 980s, 1193s, 1556s, 1571s — with sub-millisecond
gaps between repeats at each cluster, plus confirmed Newton-solver failures
(`simulation.nonlinear[40]`) right at those points).

**False lead (ruled out):** the same session had just changed
`kPressurePID` 0.05→0.12 and `TiPressurePID` 30→15 (more aggressive suction
pressure PI loop), which looked like a plausible trigger given the timing.
Reverting both to their original baseline values (0.05/30) and rerunning
did **not** stop the chattering — if anything it got worse, spreading to
`valve.gasInA` and `volume.gas` in addition to `valve.gasInB`/`junction2.gas`.
Ruled out; the pressure-loop gains were not the cause.

**Root cause:** a plain `ThermalSystems.GasComponents.Volumes.Volume volume`
(0.05 m³, `nPorts=1`) sat at the Heater-inlet end of the loop (near
`tube1`/`coldSurface`), connected through exactly one port to a
`ThermalSystems.GasComponents.Valves.Valve valve` (`KvValueFixed=3000`,
`use_KvValueInput=false` — permanently wide open, no control logic) into
`junction2`, a live compliant network node. With only one port, `volume`
is a dead end, not a through-flow branch — gas can only slosh in and back
out through the same port, so its net flow trends to zero over any
meaningful timescale. Combined with the valve being essentially
unrestricted, any pressure jitter at `junction2` pushed a burst of mass
into or out of this near-empty pocket almost undamped. Since specific
enthalpy `h = energy/mass`, near-zero mass turns small energy residuals
into huge `h` swings — tripping TSMedia's `h_min` floor on every burst,
and each clamp forces the solver to stop and relocate, which is the
chattering that stalled the run.

Git blame traces `volume`/`valve` to 2026-07-14 (commit `5b2ee814`) — three
weeks *before* the `makeupBuffer`/`reliefBuffer` fix below (2026-08-10),
which solves a structurally similar-looking problem (a valve bridging a
compliant node to something rigid) but does it correctly: `makeupBuffer`/
`reliefBuffer` are wired **inline** with 2 ports each, carrying continuous
through-flow instead of dead-ending. `volume`/`valve` never got the same
treatment. Also worth noting: an earlier session had already seen a faint
version of this exact warning (only ~18 hits, at 2 timestamps) on the same
two components and logged it as a minor, apparently self-correcting,
unexplained side effect — it wasn't minor, it was this root cause,
just not yet escalated to the point of stalling a run.

**Fix applied:** removed `volume`, `valve`, and the `junction2` merge node
they fed entirely, rewiring `junction5.portC` directly to `Heater.portA`
(same pattern as every other coil-return branch in the model). No real
compliance was lost — `junction2`'s own regularization volume
(`volume=1e-2`) was numerics-only, same as the `1e-2` every other top-level
junction in this file already carries; the dead-end pocket wasn't
contributing anything the rest of the network doesn't already provide.

**Confirmed via `dslog_simulate.txt` before/after** (same file path, diffed
across commit `893d480`):
- Before: `Integration terminated before reaching "StopTime" at T = 17.4332242`
  after 191s CPU-time — never got close to the 1815s target.
- After: `Integration terminated successfully at T = 1815`, CPU-time
  **391 seconds** — full run completes in under 7 minutes.

**How it was found:** live VM runs were diagnosed purely from the shared
folder (per the working-constraints section below) — `dslog.txt` mtime vs.
`result.mat` mtime showed the run was still crawling forward (not fully
hung) but pathologically slow; the warning block itself named the exact
component ports (`valve.gasInB`, `junction2.gas`); `git blame` on the
component's declaration lines dated its introduction relative to the
`makeupBuffer`/`reliefBuffer` fix; the before/after CPU-time and
termination-time numbers came directly from `dslog_simulate.txt`, already
preserved per-run by `auto_translate_log.mos` (see the file-location notes
in the 2026-07-14 "PFCircuit Newton-solver convergence warnings" entry
below).

**General lesson:** a `Volume` component with only **one** port connection
in use, wired through a wide-open/uncontrolled valve into a live network
node, is a red flag in this codebase — no through-flow means its mass
trends toward zero, and near-zero mass makes its specific-enthalpy state
numerically singular. This is a different flavor of the same "degenerate
near-zero-flow" family as the branch-split-degeneracy and
rigid-boundary-vs-compliant-node entries elsewhere in this doc — add
"single-port dead-end `Volume` behind an undamped valve" to the checklist.
Fix by removing the dead end if it isn't load-bearing (as here), or by
restructuring it as a proper inline 2-port buffer (`makeupBuffer`/
`reliefBuffer` pattern) if the branch needs to stay.

---

## 2026-07-28 — Coolant-temperature bump at t≈513s after forcing the main bypass (`valve1`) shut: overcool safety valve slamming open/closed

**Status: fix confirmed working**, via a real post-change VM run
(`result.mat`, run finished 18:39). Before the fix, `valve4` opened and
closed twice — once at the expected t≈5s startup transient, and again in
a fast, spurious ~3.3s cycle at t≈512–515s that produced the bump. After
the fix, `valve4` opens **only once** for the entire 1815s run (t=5.0s →
t=68.6s, the expected startup episode) and never re-triggers — the
`T_gas_out_max`-minus-coolant-temperature gap now peaks around 28K near
t≈500-560s, comfortably under the 45K trip margin that used to be crossed
there. The coolant-temperature trace is smooth (largest single-step change
0.58K) for the entire run after the pre-existing t=72–166s startup
transient settles — no trace of the t≈513s bump anywhere. Side benefits:
Newton-solver failures dropped 81→42, state events 20→11, CPU time
966s→477s (roughly half), still zero `h_min` warnings.

**Symptom:** after changing `valve1` (the main circuit bypass) to stay
fully shut past the first `controlActivationDelay=5s` startup window
instead of continuously trimming toward `m_wanted`, the coolant
temperature reading (`sensor_T` — used only as the variable name below)
started showing a sharp ~18K dip-and-recover bump around t≈513–520s,
where a previous run (with `valve1` still trimming) had already settled
into a smooth decline by that point.

**Root cause:** with `valve1`'s continuous bypass flow removed, the gap
between the hottest coil reading (`T_gas_out_max`) and the downstream
coolant temperature grew large enough to cross the overcool safety
valve's trip threshold (`overCoolReopenMargin=45K`) at t=512.448s —
confirmed directly from `result.mat`: the gap climbs smoothly and
monotonically (33.9K at t=497 → 44.5K at t=511.8) before crossing exactly
`45.000` (Dymola's own event-iteration pins several consecutive stored
rows at that exact value while it homes in on the crossing instant).
`valve4` (the overcool bypass, Kv≈5000 when open) then snapped from
essentially closed (`KvValue_in=0.001`) to nearly fully open
(`KvValue_in≈4800`, flow briefly overshooting to 7.4 kg/s) within about
half a second, then closed again only ~3.3s later once the coolant
temperature recovered past `overCoolShutMargin=40K` below the `T_ref`
snapshot taken at open. That fast open/close cycle produced a real,
physically-simulated main-circuit flow spike (~0.44 → ~0.99 → ~0.5 kg/s)
which is what dragged the coolant temperature through the visible bump,
and also triggered a cluster of 39 Newton-solver retries in that window
(new — not present in the run before `valve1` was forced shut).

**Fix applied:** added a "stabilize" hold to `valve4`'s closing logic in
`PFCircuit.mo` — new parameter `overCoolStabilizeDelay=5s`, new state
`overCoolRecovering`/`overCoolRecoveredAt`, extending the existing
`when`/`elsewhen` block that opens/closes `valve4`. Previously `valve4`
closed the instant the coolant temperature first crossed back within
`overCoolShutMargin`. Now, once that recovery condition is first met,
`valve4` keeps flowing through the bypass branch for
`overCoolStabilizeDelay` (5s) more, and only actually closes (pushing
flow back through the coils) once the coolant temperature has stayed
within the safe band for the whole hold — if it dips back out of range
during the hold, the recovery timer restarts on the next rising edge.
Intent: let the coolant temperature actually settle near its new
equilibrium before yanking the bypass away, instead of slamming `valve4`
shut the instant it first touches the threshold.

**How it was found:** same technique as other entries in this doc — real
`result.mat` trajectory data (via `scipy.io.loadmat` on the host), not
log warnings alone. `T_gas_out_max - sensor_T.sensorValue` was tracked
point-by-point to confirm the 45K crossing was smooth and genuine, and
`valve4.KvValue_in`/`valve4.portA.m_flow` were pulled directly to confirm
`valve4` physically opened (rather than trusting the `valve4Open` boolean
flag alone).

**General lesson:** a threshold-triggered discrete valve — even one with
a real hysteresis-style margin (45K open / 40K close here, so not
literally chattering) — can still produce a large, physically-real
flow/temperature transient right at the instant it fires, if nothing
damps how fast it reopens or closes. Adding a settle/dwell time on the
closing edge (mirroring the `controlActivationDelay` startup-window
pattern already used elsewhere in this model) is a reusable pattern for
any other bang-bang latch in this file found to be causing a similar
transient.

---

## 2026-07-14 — `Modelica.Utilities.System.getTime()` corrupts `dslog.txt`/`dsfinal.txt` — don't use it for timing

**Symptom:** added wall-clock instrumentation to `PF/auto_translate_log.mos` to
separate translate+compile time from simulate/integration time, using
`(ms,sec,min,hour,mday,mon,year) := Modelica.Utilities.System.getTime();`
at three checkpoints. On the next run: `dslog.txt` was replaced with a
bogus few-line log for `Modelica.Utilities.System.getTime.exe` (its
"dymosim input file" was literally `empty.txt`) instead of the real
`PFCircuit` run, and `dsfinal.txt` — while still containing genuine
`PFCircuit`/`PF1U`/`fan2ndOrder` variable data (9750 matches) — had a
corrupted timeline: `StartTime=2.33s`, `StopTime=1802.33s` instead of the
expected `0`/`1800`.

**Root cause:** not confirmed with certainty (no interactive VM access to
step through it), but the evidence points to Dymola's script interpreter
treating that function call as an implicit "simulate this class path"
request rather than a plain utility call, side-effecting the real model's
`dsin`/`dsfinal` state in the process.

**Fix:** removed all three `getTime()` checkpoints from
`auto_translate_log.mos`. Timing is derived instead from the mtimes of
files Dymola already writes on its own — `statusFile`'s mtime ≈
translate-done time, `result.mat`'s mtime ≈ simulate-done time — which
carries zero risk since it never calls into Dymola's scripting API at all,
just reads filesystem metadata from the host side.

**General lesson:** don't add an unfamiliar Dymola/Modelica scripting API
call into a script the whole diagnostic workflow depends on without a way
to verify it's safe first — a "just fetch a timestamp" convenience ended
up destroying the exact files the script exists to produce. When timing
info is needed, prefer deriving it from side-effects Dymola already
produces (file mtimes) over adding new API calls whose behavior in this
specific scripting context isn't confirmed.

---

## 2026-07-14 — Scaling `PFCircuit` from 2 to 8 coil assemblies: from ~40min/7595 warnings to ~18min/2850 warnings

**Context:** `PFCircuit.mo` grew from 2 `CoilAssembly` instances
(`PF1U`/`PF1L`) to 8 (`PF1U/PF1L/PF2U/PF2L/PF3U/PF3L/PF4U/PF4L`, mixing
`CoilAssembly2ch/3ch/4ch`), pushing the DAE to 4579 variables and ~55
`VolumeJunction`s. This re-surfaced old failure modes at a bigger scale
and introduced a new one from simultaneously pushing the fan speed target
much higher. Multiple fixes accumulated over several iterations; recorded
together since they compound.

**Fixes applied, most impactful first:**

1. **Exact-duplicate channel lengths → degenerate parallel branches.**
   `PF1U(lengths={61,64,61,64})`, `PF1L(lengths={70,74,70,74})`,
   `PF4U/PF4L(lengths={90,90,90,75})` all had channels sharing the exact
   same length within one assembly — the same branch-split-degeneracy
   category as the entry below, just re-emerging inside the new
   multi-channel components. Fixed in `CoilAssembly2ch/3ch/4ch.mo` by
   adding `lengthsAdjusted[i] = lengths[i]*(1 + 0.0001*(i-1))` — a
   per-channel offset of at most 0.01–0.03%, physically negligible but
   enough to break the exact tie. All tube geometries and the
   `Channel*` summary outputs use the adjusted value.

2. **Heat pulse overlapping fan startup stacked two stiff transients.**
   `pulseStart=5`/`pulseEnd=10` (the original default) fired while the
   fan was still in its near-zero-flow startup window — combining two
   independently-known-stiff transients (see the entry below) into one.
   Fixed by moving the pulse to `pulseStart=25`/`pulseEnd=30` (a 5s heat
   shock) and tuning the fan's `smoothStep.stepPeriod` so the ramp
   finishes (~t=21s) before the pulse starts. Result: heat-pulse-window
   warnings dropped from ~2830–3310 (when overlapping startup) to **10**
   — confirms the separation strategy works.

3. **Aggressive fan-speed targets caused real (non-recoverable) failures,
   not just noise.** Pushing `smoothStep.endValue` to 6750 rpm over a
   fast 20s ramp caused a hard integration termination via a `TSMedia`
   medium-validity violation — `PF1L` (the highest-resistance branch)
   collapsed to `p=30.6 Pa`, `T` clamped to `2 K` (near-vacuum, near
   absolute zero). Root cause: fan pressure rise scales with speed
   squared (`Δp ∝ n²`), so 6750 rpm vs. the previously-validated 500 rpm
   baseline is roughly a **182×** pressure-rise increase — physically
   unsustainable for this network, not a solver-tuning problem. Backing
   the target down to 2000–3000 rpm avoided the hard failure. Even at
   2000 rpm, warnings still concentrate 99.5% in the ramp window itself
   (t=1–21s) — the ramp slope (~97.5 rpm/s) is still ~4× the
   ~22–25 rpm/s previously validated as quiet, so some residual noise
   there is expected, not a new bug.

4. **`simulateModel` tolerance progressively loosened `1e-6→1e-5→1e-4`.**
   Each step cut warning counts and Jacobian-evaluation counts further;
   combined with fixes 1–3, Jacobian evaluations dropped from 29,642 to
   **7,657** and CPU-time for integration from 2370s to **1060s**.

5. **`VolumeJunction.volume` bumped `1e-5→1e-4`** inside
   `CoilAssembly2ch/3ch/4ch.mo`'s internal junctions (numerics-only
   regularization, not physically meaningful — see the "junctions are a
   numerical device, not real hardware volume" discussion). Note: at
   time of writing this is **not** applied on `PFCircuit.mo`'s 19
   top-level junctions (currently back at `1e-5` there) — asymmetric
   state, flagged here in case it wasn't intentional.

**Current result:** latest successful run completes the full 1800s,
2850 total warnings (down from 7595 at the start of this investigation),
99.5% concentrated specifically in the t=1–21s fan-ramp window, CPU-time
1060s (down from 2370s).

**How it was found:** same technique as the entry below — `dslog.txt`
warning timestamps bucketed against known model transition points (fan
ramp end ~t=21s, pulse window t=25–30s) — reapplied at the larger scale.
Also used `scipy.io.loadmat` on backed-up `result.mat` copies
(`PF/debugging/result_tol1e-5.mat` etc.) to compare key outputs
(`Channel1`/`Channel2` `T_wall`/`m_flow`) across tolerance settings before
trusting the looser one — `auto_translate_log.mos` always overwrites
`result.mat` at the same path, so a baseline must be copied aside *before*
the next run if you want to diff against it.

**General lesson:** when scaling a validated small model up in component
count *and* simultaneously pushing operating parameters (fan speed)
further from what was validated, those are two independent axes of risk —
conflating them costs iterations, because a failure could be "the bigger
circuit re-exposed an old degeneracy" or "the new operating point is
itself unphysical," and each needs different evidence to tell apart
(compare against a known-good baseline's `.mat` data, and bucket warning
timestamps against the model's own timeline, rather than guessing from
symptom shape alone).

---

## 2026-07-14 — `PFCircuit` Newton-solver convergence warnings ("wobbling")

**Symptom:** `dslog.txt` showed 7595 occurrences of
`Warning: Failed to solve nonlinear system using Newton solver.` (tag
`simulation.nonlinear[3]`) during a `CoilLoopCompassU.PF.PFCircuit`
simulation with two parallel coil branches (`PF1U`, `PF1L`, both
`CoilAssembly` instances). Simulation still completed the full 1800s and
`result.mat` was a normal size — not the runaway/bloat failure mode from
the 2026-07-13 chattering entry below, just persistent solver noise.

**False lead (ruled out, recorded so it isn't retried):** because the
symptom superficially resembled the 2026-07-13 branch-split-degeneracy
chattering issue, the first hypothesis was that `PF1U`/`PF1L`'s isolation
valves (`valveKvNominal=100` on both, identical) dominated flow resistance
and kept the branch split numerically degenerate even after giving the two
coils different tube lengths (64 vs 74). This was **wrong on two counts**:
(1) `Kv=100` at full opening is a large/non-restrictive flow coefficient
for a 7mm helium tube — asserted as fact without checking, should have
been a hypothesis; (2) actually reading the `.mat` result data (via
`scipy.io.loadmat` on the host — see "How it was found") showed the two
branches split ~15% asymmetrically from early in the run
(`PF1U.valve1.portA.m_flow` vs `PF1L.valve1.portA.m_flow` at t=3.6s:
3.62e-4 vs 3.14e-4 kg/s, tracking the tube-length ratio), i.e. the split
was never actually degenerate. Don't reach for the 2026-07-13 fix pattern
just because the symptom (Newton/solver warnings) looks similar — check
the actual trajectory data first.

**Root cause (confirmed from `dslog.txt` warning timestamps bucketed
against the model's own timeline):** two distinct, benign, self-recovering
stiff transients, unrelated to branch symmetry:
1. **Near-zero-flow startup** (t < 1s, before `fan2ndOrder`'s
   `smoothStep` even begins ramping at `startTime=1`) — 3722 of the 7595
   warnings (49%). Mass flow is ~1e-16 to 1e-4 kg/s in this window;
   turbulent-flow correlations (`Konakov` pressure drop,
   `GnielinskiDittusBoelter` heat transfer) are steep/ill-conditioned near
   zero Reynolds number, a standard Newton-convergence trap.
2. **Heat-pulse onset** (t=5–8.79s) — 2830 warnings (37%). `CoilAssembly`'s
   `stepSource` injects `dischargeLoad=50000` W into both coils
   simultaneously over `transitionTime=0.5`s, a fast transient into a
   small gas volume.

Zero warnings after t=8.79s for the remaining ~1791s of the run in either
case.

**Fix applied:** loosened `tolerance` in `PF/auto_translate_log.mos`'s
`simulateModel(...)` call from `1e-6` to `1e-5`. Result: startup-window
warnings dropped 96% (3722→154, and the t=1–5s ramp window 845→36) — a
looser tolerance absorbs exactly this kind of transient Newton noise
without changing the settled result. **Did not fix the heat-pulse window**
(2830→3310, slightly worse in absolute count) — total warnings roughly
halved overall (7595→3642) but the pulse-onset stiffness needs a different
lever. Not yet applied: soften `transitionTime` (currently hardcoded
`0.5` in `CoilAssembly.mo`'s `stepSource`) to ~1–2s to smooth the 50kW
step into more of a ramp.

**How it was found:** `dslog.txt`/`buildlog.txt`/`dsfinal.txt` for a
package-structured model (`CoilLoopCompassU/`, directory-based, opened via
its root `package.mo`) land in **the package's root folder**
(`CoilLoopCompassU/dslog.txt`), not in wherever `resultFile`/`logFile` in
the `.mos` script point (`PF/debugging/`) — different from the flat
single-file `Test/CoilLoopThermalSystems.mo` case where they landed
alongside the model. Worth checking both locations. To actually confirm
the branch-split hypothesis (rather than guess), the host-side result
`.mat` was read directly: `pip install scipy numpy` on the host (has
internet, unlike the VM), then
`scipy.io.loadmat('result.mat')` — Dymola's MAT-v4 format stores variable
names as a character matrix (`d['name']`, shape `(nameLength, nVars)`,
needs transposing back into per-variable strings) and trajectories via
`d['dataInfo']` (row 0 = which of `data_1`/`data_2` holds the variable,
row 1 = signed 1-based row index, negative sign means negate the stored
value) indexing into `d['data_1']` (constants) or `d['data_2']`
(time-varying, first row is `Time`).

**General lesson:** don't assume a component's parameter value implies
its physical significance (e.g. "Kv=100 sounds like a normal number, must
be restrictive") — check the actual unit/reference-condition definition,
or better, check the real simulated trajectory before building a fix on
top of an assumption. When the host has internet and the VM doesn't,
`scipy.io.loadmat` on the shared-folder `result.mat` is a fast way to get
ground truth on what a model actually did, instead of reasoning from logs
and warnings alone.

---

## 2026-07-13 — "Circular equalities detected" / model is structurally singular

**Symptom:** Translation aborted with:
```
The DAE has 1254 scalar unknowns and 1254 scalar equations.
Model is singular: Circular equalities detected.
The equations
  junction.portB.p = junction.portA.p;
  junction.portA.p = junction.portB.p;
which was derived from
  junction.portA.p-junction.portB.p = 0;
mean circular equalities for junction.portA.p, junction.portB.p
```

**Root cause:** a stray `connect(junction.portA, junction.portB)` had been added
directly in `Test/CoilLoopThermalSystems.mo` (self-loop connecting two ports
of the *same* `VolumeJunction` instance to each other). `VolumeJunction` is a
single lumped-volume component — all of its ports already share one internal
pressure state, so `portA.p = portB.p` is already implied internally. Adding
an external `connect` between them asserts the exact same equality a second
time: two equations that reduce to the same relation, with nothing left to
pin down the actual value → structurally singular ("circular"). It was also
topologically wrong on top of being redundant, since `portA` and `portB`
were each already wired to different external components (`tube2.portA` and
`sensor_m_flow.portB`), so the extra connect tried to weld four ports into
one node instead of leaving `junction` as a normal 3-way split/merge.

**Fix:** delete the stray `connect(junction.portA, junction.portB)` statement.

**How it was found:** the Dymola translation error itself names the exact
two variables and the reduced equation directly — for this class of error
you don't need `dsfinal.txt`/`dsin.txt` forensics, just grep the `.mo` file
for the named variables' component (`junction`) and look for any `connect(...)`
involving two ports of the *same* instance — that's almost always the tell
for "circular equalities" on a component that internally ties its own ports
together (single-pressure-state volumes, ideal junctions, sensors with
`portA`≡`portB`, etc.).

**General lesson:** "Circular equalities detected" in Dymola almost always
means two (or more) equations assert the *same* relationship between the
same variables — not that there's a physical loop in the network. Check for:
redundant/duplicate `connect()` statements, a component's own internal
port-equality equations being re-asserted externally, or two different
initial-condition fixes pinning the same state twice.

---

## 2026-07-13 — Result file bloat (66MB) / "many state events" chattering warning

**Symptom:** `SimpleLoop.mat` was 66MB for a 10s / ~100-interval simulation
(later confirmed as 25,903 state events over 10s). Dymola printed:
```
WARNING: You have many state events. It might be due to chattering.
```
Simulation was extremely slow (minimum integration stepsize `5.14e-11`,
263,365 crossing-function evaluations for a trivial model).

**Root cause:** `generateEventsAtFlowReversalGas` (a parameter on
`ThermalSystems.SystemInformationManager`, inherited by all gas components
unless locally overridden) defaults to `true`. This is *not* about the bulk
loop flow reversing — the fan drives that monotonically positive the whole
time. It's about the **flow split between two parallel branches**
(`tube`/`tube2` in `SimpleLoop`, both identical geometry, both driven by
identically-profiled heat sources). With no physical basis to prefer one
branch over the other, the split is numerically degenerate. Early in the
run the *total* flow being split is tiny (junction `m_flowStart=1e-5`, fan
still ramping up), so ordinary solver roundoff (~1e-9 to 1e-12) is
comparable to or larger than the quantity being split — the computed
per-branch flow can briefly read slightly negative in one branch while the
other over-compensates to conserve mass. That's a real sign change on the
variable Dymola is watching, even though it's physically meaningless.
`generateEventsAtFlowReversal` can't tell "meaningful reversal" from
"roundoff-scale noise on a degenerate split" — every flip forces a full
state event: stop, iterate to localize the crossing to `eveps` (1e-10s)
tolerance, restart. And because `dsin.txt` has `evgrid=1`, every such event
also becomes an extra stored row, ballooning the result file.

**Fix:** set `generateEventsAtFlowReversalGas=false` on the `sim`
(`ThermalSystems.SystemInformationManager`) instance — single point of
control, all gas components inherit it unless they override locally. This
doesn't remove the branch-split degeneracy (still structurally there if you
build genuinely symmetric parallel branches) — it changes the upwind switch
from a hard state-event to a continuous/smoothed evaluation, so the same
noise gets absorbed for free instead of forcing expensive event handling.

**When this fix is/isn't appropriate:** safe when the topology has no
scenario where flow should *actually* reverse and you need to catch that
moment precisely (true here — single fan, one-directional loop). Do **not**
blanket-disable this on a model where real flow reversal is physically
expected and matters (e.g. a natural-convection loop, or anything with
bidirectional operation) — you'd lose accurate switching there.

**How it was actually found:** confirmed directly from the compiled model's
own parameter dump rather than guessed — `dsfinal.txt` (and `dsin.txt`) are
plain-text and contain an `initialValue` matrix; grepping for
`generateEventsAtFlowReversal` there shows the actual compiled value (4th
number in the row's continuation line) for every component. This is the
reliable way to check *what value a parameter actually compiled to*,
independent of what the `.mo` source says — see the next entry for why that
distinction matters.

---

## 2026-07-13 — `.mo` edit had "no effect" after re-running

**Symptom:** After adding `generateEventsAtFlowReversalGas=false` to the
`.mo` source and re-running `auto_translate_log.mos`, translate reported
success but the chattering warning and event counts were unchanged.
Checking `dsin.txt`/`dsfinal.txt` confirmed the parameter was still
compiling to `true` — the edit genuinely never reached the model.

**Root cause:** `translateModel(modelName)` re-translates whatever class
definition is **already loaded in Dymola's workspace** — it does not
re-read the `.mo` file from disk. If the model was opened once in the GUI
(or a previous script run) and left loaded, external edits to the file sit
unused indefinitely, silently, with no error.

**Fix:** `auto_translate_log.mos` now calls
`openModel(sharedPath + "/CoilLoopThermalSystems.mo", mustRead=true)`
immediately before `translateModel()`, forcing a fresh read from the shared
folder every run.

**Lesson:** when a model-source edit appears to have no effect, don't
conclude the hypothesis was wrong before checking `dsin.txt`/`dsfinal.txt`
for whether the parameter's *compiled* value actually changed. "Translate
succeeded" only means the syntax was valid, not that your edit was used.

---

## 2026-07-13 — `auto_translate_log.mos` errors before producing any log

**Symptom:** Running the automation script produced no `status.txt` /
`last_error.txt` at all (translate/compile clearly succeeded per
`buildlog.txt`, but the script never got to write a status file).

**Root causes found (all in the same script):**
1. `Modelica.Utilities.Streams.print(string, fileName, false)` — this
   function only takes **2** arguments (`string`, `fileName`); there is no
   append/overwrite flag. The 3-argument call throws
   `Error: Too many positional arguments for function ... print` and aborts
   the script at that line, before the status file gets written. (Since the
   function always *appends*, stale status/error files from previous runs
   also need to be explicitly deleted at the start of each run, or old and
   new statuses stack up in the same file forever.)
2. `simulateModel(modelName, StopTime=10, Tolerance=1e-6, ResultFile=...)`
   — the named arguments were capitalized, but the actual function
   signature uses lowerCamelCase: `stopTime`, `tolerance`, `resultFile`.
   Capitalized names throw `Error: Unknown named argument '...'`.
3. `sharedPath` was written with backslashes
   (`"Z:\compass-u-cryo-loop\..."`) — backslash is a Modelica string escape
   character. This happened to work here only because none of the path
   segments started with a letter Modelica recognizes as an escape
   (`'`,`"`,`?`,`\`,`a`,`b`,`f`,`n`,`r`,`t`,`v`,`0`) — fragile, not a
   guarantee. Use forward slashes in `.mos` path strings.

**Fix:** corrected all of the above in `Test/auto_translate_log.mos`; also
added a `"RUNNING: translate started"` marker written to `status.txt`
immediately at the start of the run (after clearing any stale status/error
files), so a hung or crashed Dymola session can be distinguished from a
stale leftover file by its timestamp/content instead of looking identical.

---

## Known-unexplained / flagged, not fixed

- `Test/request` and `Test/status` (no `.txt` extension) — both contain
  just a single space + CRLF. Not written by `auto_translate_log.mos`
  (which writes `status.txt`, not `status`). Likely leftover manual-test
  artifacts from earlier debugging, unrelated to the actual pipeline. Safe
  to delete if unrecognized, left in place for now.

---

## Working constraints worth remembering

- Dymola runs inside a network-isolated VM; only a shared disk folder
  connects it to the host. No one working from the host side (including an
  AI assistant) can run translate/simulate directly — diagnosis has to come
  from the shared-folder files (`status.txt`, `translation_log.txt`,
  `last_error.txt`, `dslog.txt`, `dsin.txt`, `dsfinal.txt`, result `.mat`)
  plus static reading of `.mo` sources. Every fix needs a real re-run inside
  the VM to confirm — don't trust "should work" without seeing the new log.
- `dsin.txt`/`dsfinal.txt` are plain text but can be 300KB+ — grep for the
  variable name rather than reading the whole file. Each variable's actual
  compiled value lives in the `initialValue(N,6)` matrix; each row wraps
  across 2 physical lines, and the row is matched to its name by matching
  order with the `initialName(N,77)` block (or just grep the trailing
  `# variable.name` comment Dymola prints on the first of the two lines).
