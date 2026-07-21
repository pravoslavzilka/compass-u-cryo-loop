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
