# Project context: Dymola cryo helium loop (COMPASS-U tokamak)

## Environment and workflow

I'm working on a simulation model of a cryogenic helium cooling loop for
the COMPASS-U tokamak (IPP), in **Dymola**, using the
**Thermal Systems (TIL/TSMedia)** libraries. I'm progressively rebuilding
the model from a hand-derived causal prototype into a full Dymola model.

**Important constraint:** Dymola runs inside a **VirtualBox VM that is
completely network-isolated** (adapter set to "Not attached" — no
internet, no network connection at all, intentionally, for
licensing/security reasons). You (Claude Code) run on the host Windows
PC and **do not have, and will never have, direct access to Dymola or
the VM** — you cannot run translate/simulate commands, cannot restart
the VM, cannot execute anything inside the VM. The only link between
the VM and the host is a **VirtualBox Shared Folder**, i.e. a regular
disk folder visible from both sides.

## Shared folder

Path on the host (you can see this too): D:\projects\IPP\Cryogenics\Dymola\

Inside the VM, the same folder is mounted as the Dymola working
directory. Inside the VM I run a `.mos` script (`auto_translate_log.mos`)
that, after every translate/simulate run, writes:

- `status.txt` – quick status: `OK: translation successful` or `FAIL: ...`
- `translation_log.txt` – the **full** Dymola log (translate and
  simulate), including solver warnings, state events, etc.
- `last_error.txt` – just the last error message (quick context)
- the `.mo` source files of the model (the same ones being compiled
  inside the VM)

## What I need from you

1. When I ask you to "check the latest error" or similar, first read
   `status.txt`, then `translation_log.txt` (or `last_error.txt` for a
   quick overview).
2. Find the corresponding `.mo` file and review/fix the code directly
   in it (in the same shared folder, so Dymola inside the VM sees it).
3. **Do not try to run translate/simulate yourself** — you can't, since
   you have no access to the VM. After making a change, clearly tell me
   what you changed and why, and I'll re-run the compilation inside the
   VM manually.
4. The specific recurring issue we're working on: **solver chattering
   at junction flow-direction state events** in TIL/TSMedia components
   (rebuild from the hand-derived prototype to the Dymola Thermal
   Systems library). If you see a high number of event iterations or
   zero-crossing issues around junction/flow-reversal logic in the
   warnings, this is likely related.
5. If the log doesn't contain enough information to diagnose the issue,
   tell me exactly what I should additionally enable/output in Dymola
   (e.g. a different debug level, different solver output), and I'll
   set it up inside the VM manually.

## Source materials

The design inputs are in `C:\Users\pravo\projects\IPP\Dymola\materials`
(outside this repo) — check requirements against these, not only against
the design-basis docs that quote them:

- `22172-Z-R1-S2 Study of a cryogenic system for tokamak_připomínky.pdf` —
  ATEKO study R1 (2025-10-07): operating modes and the 40 K rule (§3.2,
  §3.4, target 80 K, max 82 K if 80 K is not reachable), coil tables
  (Tab.1–3), heat balance (Tab.4–6), channel pressure losses (Tab.7–12),
  working/design pressures (§5.3, §6.5), LIN and CC power (§7.2, §7.3).
- `22171-3-R0-S1 - PFD PF COILS.pdf`, `22178-3-R0-S1 - PFD CS COILS.pdf`,
  `22179-0-R0-S1 - PFD TF COILS, SUPPORT STR.-1.pdf` — process flow
  diagrams. No text layer: render to an image to read the channel
  labels (they are rotated 90°).

Known discrepancies between them: CS3U/CS3L channel length 2×88 m
(study Tab.2) vs 2×86 m (PFD, drawn 2025-09-15, older than the study);
CS hydraulic diameter 6.96 mm (Tab.2, Tab.9) vs 6.817 mm (§5.2.2 text,
which is the value for an 8×6.0 ellipse).

## Modelling lessons (PF/TF/CS) — apply to any new coil circuit

Learned while building the PF, TF and CS loops; per-circuit numbers and
derivations live in `docs/design-basis/*-circulator-sizing.md`.

- **Identical parallel branches → structural singularity.** Two
  parameter-identical coil branches between the same pair of junctions
  (or a chain of zero-resistance `VolumeJunction`s) gave TF a
  "22890 unknowns / 22889 equations" error. Fix: every coil-assembly class
  carries `assemblyIndex` + `lengthAdjusted = length*(1 + 1e-5*assemblyIndex)`,
  and each instance in a circuit gets a unique index.
- **Wall thermal mass must match the real coil weight.** Size
  `outerCrossSectionalArea = crossSectionArea + mass/(density*length)`
  from the ATEKO coil masses. Too little copper (TF was ~122x short) made
  the solver blow up.
- **Elliptical channels:** use `crossSectionType=NonCircular` with area
  π·a·b and Ramanujan's perimeter. The geometry-based heat-transfer
  correlations (`GnielinskiDittusBoelter`) only support circular tubes, so
  NonCircular needs `ConstantAlpha` + `ConstantR`.
- **Copper cp vs ATEKO's energy balances.** `CopperOFHC_Tdep` and
  `CopperOFHC_RRR30_Tdep` share the same cryogenic cp table (only lambda
  differs). ATEKO's post-shot coil temperatures assume room-temperature cp
  (~390 J/kgK); with real cp the same shot energy heats the copper further
  (PF: 137 → 160 K per the thesis; CS: 137.5 K → ~160 K by the same
  calculation, not yet adopted in the model).
- **Suction/pressure control:** TF and CS use a plain continuous
  proportional trim on RV07/RV08. PF needed a hysteresis-gated
  pulse-then-trim scheme; port that only if a run shows the pressure
  limit-cycling. TF's `bypassHysteresis`/`BypassLimiter` wiring belongs to
  the heater/cooling/bypass temperature split range, not to pressure control.
- **Circulator (`Fan2ndOrder`) equations are readable from `debugging/dsmodel.c`**
  (the flattened Modelica source of `calcCoefficients`, `semiSquareFunction`,
  `maxHydraulicPower` and the loss equations is embedded there). Losses scale
  with density × speed³ × (V/V_maxPhyd)^2.3, so at fixed speed they grow as the
  helium densifies, and running near `V_flow0` (zero head) wrecks efficiency.
  Size the machine so its design point is the hardest duty point; for
  bypass (RV01) flow control a steep curve (`V_flow0` close to nominal) is
  better. Never fit a fan curve from a run where speed was controlled on flow.
- **Evaporator** is an idealised LIN boundary in all circuits (no
  HE01/HE02/VE01 thermosiphon) — a known, shared simplification.
- **Mark every number** in design-basis docs as [FROM SOURCE] (ATEKO
  22172-Z-R1 page/table), [CALCULATED] (formula shown) or [ASSUMED], and
  re-check calculated values against the next real `result.mat`.
- **Reading results:** `result.mat` files are Dymola `binTrans` format
  (`data_2` is variables × time). A `.mat` with a single time column is
  only an initialization snapshot, not a run.

## Work cycle (since there's no direct connection to the VM)

```
You (in Dymola inside the VM) run translate/simulate
        ↓
Log lands in the shared folder
        ↓
I (Claude Code) read the log, fix the .mo code
        ↓
You re-run translate/simulate inside the VM
        ↓
(repeat)
```
