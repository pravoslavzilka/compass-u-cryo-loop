"""Extract per-coil end-of-pulse state from the tokamak-coil-tools scenarios.

Usage: python tools/scenarios/extract_coil_end_state.py [scenario_dir] [out_dir]
Writes (default out_dir = data/working_scenarios):
  coil_end_state.csv   tool values per scenario x coil (T0, T_end, Eheat, C, mass, cp)
  model_coil_start.csv per Dymola coil: T_start that conserves the tool's stored
                       heat when integrated with the model's cp(T) and copper mass
"""
import csv, math, re, sys
from pathlib import Path
import h5py
import numpy as np

SRC = Path(sys.argv[1] if len(sys.argv) > 1 else "D:/fast_files/downloads/compass-u-scenare")
OUT = Path(sys.argv[2] if len(sys.argv) > 2 else Path(__file__).resolve().parents[2] / "data" / "working_scenarios")

# CopperOFHC_Tdep cp table (Common/CopperOFHC_Tdep.mo, NIST OFHC copper fit samples)
TD = np.array([1, 4, 10, 15, 20, 25, 30, 40, 50, 60, 70, 77, 80, 90, 100, 110, 120, 135, 150, 175, 200, 225, 250, 275, 300.])
CD = np.array([0.025, 0.1, 0.86, 2.96, 7.51, 15.26, 26.47, 57.84, 96.27, 135.88, 172.76, 195.92, 205.1, 232.5, 255.33, 274.24, 289.97, 309.01, 324.11, 343.73, 359.01, 371.24, 380.62, 386.84, 389.4])
RHO = 8960.0

def tube_mass(d_mm, t_mm, lengths):
    d, t = d_mm * 1e-3, t_mm * 1e-3
    return math.pi / 4 * ((d + 2 * t) ** 2 - d ** 2) * sum(lengths) * RHO

# Dymola coil -> (copper mass kg, tool coils it represents). PF masses from the
# Tube wall geometry (assumed annulus, inner d, wall t) in PFCircuit.mo;
# CS masses are ATEKO Tab.5 values the model is sized to.
MODEL = {
    "CS1":  (714.0, ["CS1"]),   "CS2U": (349.0, ["CS2U"]), "CS2L": (349.0, ["CS2L"]),
    "CS3U": (714.0, ["CS3U"]),  "CS3L": (714.0, ["CS3L"]),
    "PF1U": (tube_mass(7, 4.88, [61, 64, 70, 74]), ["PF1Ua", "PF1Ub"]),
    "PF1L": (tube_mass(7, 4.88, [61, 64, 70, 74]), ["PF1La", "PF1Lb"]),
    "PF2U": (tube_mass(7, 4.88, [80, 83]), ["PF2U"]), "PF2L": (tube_mass(7, 4.88, [80, 83]), ["PF2L"]),
    "PF3U": (tube_mass(7, 4.88, [83, 84, 87]), ["PF3U"]), "PF3L": (tube_mass(7, 4.88, [83, 84, 87]), ["PF3L"]),
    "PF4U": (tube_mass(9, 5.9, [90, 90, 90, 75]), ["PF4U"]), "PF4L": (tube_mass(9, 5.9, [90, 90, 90, 75]), ["PF4L"]),
}

def heat_to_T(q_per_kg, T0):
    """Solve integral_{T0}^{T} cp(T')dT' = q_per_kg for the model cp table."""
    lo, hi = T0, 300.0
    for _ in range(80):
        mid = 0.5 * (lo + hi)
        Tg = np.linspace(T0, mid, 2001)
        if np.trapezoid(np.interp(Tg, TD, CD), Tg) < q_per_kg: lo = mid
        else: hi = mid
    return 0.5 * (lo + hi)

def key(p):
    return [int(s) if s.isdigit() else s for s in re.split(r"(\d+)", p.parent.name)]

rows, model_rows = [], []
for p in sorted(SRC.glob("*/tokamak-coil-tools-output.nc"), key=key):
    scen = p.parent.name
    with h5py.File(p, "r") as f:
        labels = [x.decode() if isinstance(x, bytes) else str(x) for x in f["coil_label"][:]]
        t = f["time"][:]; T = f["T"][:]; E = f["Eheat"][:]; C = f["C"][:]
        T0 = f["T0"][:]; mass = f["mass"][:]
        info = {}
        for i, c in enumerate(labels):
            info[c] = dict(T0=T0[i], Tend=T[i, -1], E=E[i, -1], C=C[i, -1], m=mass[i])
            rows.append([scen, c, f"{T0[i]:.3f}", f"{T[i,-1]:.3f}", f"{T[:,:].max(axis=1)[i]:.3f}",
                         f"{E[i,-1]:.1f}", f"{C[i,-1]:.1f}", f"{mass[i]:.1f}", f"{C[i,-1]/mass[i]:.2f}", f"{t[-1]:.3f}"])
    for mc, (mm, tools) in MODEL.items():
        Et = sum(info[c]["E"] for c in tools); Ct = sum(info[c]["C"] for c in tools)
        mt = sum(info[c]["m"] for c in tools)
        T_tool = Ct and sum(info[c]["Tend"] * info[c]["C"] for c in tools) / Ct  # C-weighted mean
        T_model = heat_to_T(Et / mm, info[tools[0]]["T0"])
        model_rows.append([scen, mc, f"{mm:.1f}", f"{mt:.1f}", f"{mm/mt:.3f}", f"{T_tool:.3f}",
                           f"{Et:.1f}", f"{T_model:.3f}", f"{T_model-T_tool:+.3f}"])

OUT.mkdir(parents=True, exist_ok=True)
with open(OUT / "coil_end_state.csv", "w", newline="") as fh:
    w = csv.writer(fh)
    w.writerow(["scenario", "coil", "T0_K", "T_end_K", "T_max_K", "Eheat_J", "C_end_J_per_K", "mass_kg", "cp_end_J_per_kgK", "t_end_s"])
    w.writerows(rows)
with open(OUT / "model_coil_start.csv", "w", newline="") as fh:
    w = csv.writer(fh)
    w.writerow(["scenario", "model_coil", "model_mass_kg", "tool_mass_kg", "mass_ratio", "T_end_tool_K",
                "Eheat_J", "T_start_energy_conserving_K", "delta_K"])
    w.writerows(model_rows)
print("wrote", OUT)
