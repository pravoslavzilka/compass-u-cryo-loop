#!/usr/bin/env python3
"""
Reproduce the numbers in pf-circulator-sizing.md (this same folder) from a
PFCircuit result.mat: fan2ndOrder's actual compiled parameters, the
hot-start/cold-end operating table, the true (CoolProp-corrected) suction
temperature and density, the impeller tip-speed/diameter buildability
check, and the cold-end shaft power vs. P_shaftLimit.

This script only reads and reports -- it does not modify the model or
draw conclusions beyond what's printed. Re-run it after any change to
fan2ndOrder's parameters or a fresh simulation, and diff the output
against pf-circulator-sizing.md to see what moved.

Requirements: numpy, DyMat, CoolProp
    pip install numpy DyMat CoolProp

Usage:
    python pf_circulator_sizing.py [path/to/result.mat]

Default path (relative to the repo root) is
    dymola-thermal-systems/CoilLoopCompassU/PF/debugging/result.mat
"""
import sys
import os
import numpy as np
import DyMat
import CoolProp.CoolProp as CP

DEFAULT_RESULT = os.path.join(
    "dymola-thermal-systems", "CoilLoopCompassU", "PF", "debugging", "result.mat"
)

# Loading coefficient assumed for the tip-speed buildability check -- not a
# model parameter, see pf-circulator-sizing.md section 7 for the rationale.
PSI = 0.55
TIP_SPEED_CEILING_M_S = 450.0
R_HELIUM = 8.314          # J/(mol.K)
M_HELIUM = 0.004003       # kg/mol
COOLDOWN_TARGET_K = 80.0
COOLDOWN_WINDOW_S = 1800.0


def load(path):
    d = DyMat.DyMatFile(path)
    t = d.abscissa("fan2ndOrder.P_shaft", valuesOnly=True)

    def get(name):
        v = np.asarray(d.data(name), dtype=float)
        if v.shape[0] == 2:
            return np.full(len(t), v[0])
        return v

    return d, t, get


def fan_parameters(get):
    names = [
        "n_nominal", "dp_nominal", "V_flow_nominal", "V_flow0", "deltaV_flow",
        "eta_maxPhyd", "bladeLossExponent", "impactLossCoefficient",
        "T_nominal", "p_nominal", "maxDeltaT", "V_flow_Start", "dpInitial",
    ]
    return {n: get(f"fan2ndOrder.{n}")[0] for n in names}


def enthalpy_datum_offset(get, t):
    """TSMedia (VDIWA2006.Helium) enthalpy is offset from CoolProp's HEOS
    Helium by an additive constant; fit it from coil-tube anchor points
    that log both T and h (see the conservation-law audit for the same
    technique applied loop-wide)."""
    anchors_T, anchors_p, anchors_h = [], [], []
    for comp in ["PF1U.tube1", "PF4L.tube1", "PF3U.tube2"]:
        TA = get(f"{comp}.summary.T_gas_A")
        pA = get(f"{comp}.portA.p")
        hA = get(f"{comp}.summary.h_gas_A")
        for i in np.arange(0, len(t), 80):
            anchors_T.append(TA[i]); anchors_p.append(pA[i]); anchors_h.append(hA[i])
    anchors_T, anchors_p, anchors_h = map(np.array, (anchors_T, anchors_p, anchors_h))
    cp_h = np.array([CP.PropsSI("H", "T", T, "P", p, "Helium")
                      for T, p in zip(anchors_T, anchors_p)])
    return float(np.mean(anchors_h - cp_h))


def true_suction_T(get, offset_h, idx):
    """Suction enthalpy comes from the upstream neighbor's outflow
    (junction4.portC), not fan2ndOrder.portA.h_outflow -- see the
    Modelica stream-connector note in pf-circulator-sizing.md / the
    conservation-law audit."""
    h = get("junction4.portC.h_outflow")[idx]
    p = get("junction4.portC.p")[idx]
    return CP.PropsSI("T", "P", p, "H", h - offset_h, "Helium"), p


def hot_start_index(t, Tmax):
    """First genuine hot-operation sample: after the fan's speed ramp
    settles and the ~1.2s junction-initial-condition artifact in
    T_gas_out_max clears (see PFCircuit.mo's controlActivationDelay
    docstring)."""
    mask = t > 5.0
    return np.where(mask)[0][np.argmax(Tmax[mask])]


def cooldown_crossing(t, Tmax):
    mask = t > 10.0
    for i in np.where(mask)[0]:
        if Tmax[i] <= COOLDOWN_TARGET_K and np.all(Tmax[i:i + 5] <= COOLDOWN_TARGET_K + 0.5):
            return i
    return None


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else DEFAULT_RESULT
    if not os.path.exists(path):
        print(f"error: {path} not found", file=sys.stderr)
        sys.exit(1)

    d, t, get = load(path)
    params = fan_parameters(get)
    Tmax = get("T_gas_out_max")
    mdot = np.abs(get("fan2ndOrder.portB.m_flow"))
    pA = get("fan2ndOrder.portA.p")
    pB = get("fan2ndOrder.portB.p")
    Psh = get("fan2ndOrder.P_shaft")
    try:
        P_shaftLimit = get("P_shaftLimit")[0]
    except Exception:
        P_shaftLimit = None

    print(f"=== fan2ndOrder parameters ({path}) ===")
    for k, v in params.items():
        print(f"  {k:24s} {v:g}")

    i_hot = hot_start_index(t, Tmax)
    i_end = len(t) - 1
    print()
    print("=== hot start vs cold end ===")
    for label, i in [("hot start", i_hot), ("cold end (run end)", i_end)]:
        print(f"  {label:20s} t={t[i]:8.1f}s  T_gas_out_max={Tmax[i]:7.2f}K  "
              f"mdot={mdot[i]:.4f}kg/s  p_suction={pA[i]/1e5:.2f}bar  "
              f"p_discharge={pB[i]/1e5:.2f}bar  P_shaft={Psh[i]/1e3:.2f}kW")

    i_cross = cooldown_crossing(t, Tmax)
    print()
    print("=== cooldown vs. requirement (<=80K within 1800s) ===")
    if i_cross is not None:
        margin = COOLDOWN_WINDOW_S - t[i_cross]
        print(f"  permanent <=80K crossing at t={t[i_cross]:.1f}s, "
              f"margin to {COOLDOWN_WINDOW_S:.0f}s = {margin:.1f}s")
    else:
        print("  never permanently crosses <=80K within this run")
    i_1800 = int(np.argmin(np.abs(t - COOLDOWN_WINDOW_S)))
    print(f"  T_gas_out_max at t={t[i_1800]:.1f}s: {Tmax[i_1800]:.2f}K "
          f"(coolant supply ~77-78K -- approach is asymptotic, "
          f"exact convergence to the coolant temperature is not expected "
          f"in finite time)")

    print()
    print("=== true suction condition (CoolProp real-gas Helium) ===")
    offset_h = enthalpy_datum_offset(get, t)
    print(f"  TSMedia/CoolProp enthalpy datum offset: {offset_h:,.0f} J/kg")
    for label, i in [("hot start", i_hot), ("cold end", i_end)]:
        T_true, p_true = true_suction_T(get, offset_h, i)
        rho_cp = CP.PropsSI("D", "T", T_true, "P", p_true, "Helium")
        rho_ig = p_true * M_HELIUM / (R_HELIUM * T_true)
        V_flow = mdot[i] / rho_cp
        print(f"  {label:12s} true T_suction={T_true:.1f}K (vs. T_nominal={params['T_nominal']:.0f}K)  "
              f"rho_realgas={rho_cp:.3f}kg/m3  rho_idealgas={rho_ig:.3f}kg/m3 "
              f"({100*(rho_ig-rho_cp)/rho_cp:+.1f}%)  V_flow={V_flow:.4f}m3/s "
              f"(vs. V_flow_nominal={params['V_flow_nominal']:.3f}m3/s)")

    print()
    print("=== buildability check (impeller tip speed / diameter) ===")
    print(f"  assumed loading coefficient psi = {PSI}")
    rho_nom_cp = CP.PropsSI("D", "T", params["T_nominal"], "P", params["p_nominal"], "Helium")
    rho_nom_ig = params["p_nominal"] * M_HELIUM / (R_HELIUM * params["T_nominal"])
    for label, rho in [("real-gas", rho_nom_cp), ("ideal-gas", rho_nom_ig)]:
        u = (params["dp_nominal"] / (rho * PSI)) ** 0.5
        D = u / (np.pi * params["n_nominal"])
        flag = "OK" if u <= TIP_SPEED_CEILING_M_S else "OVER CEILING"
        print(f"  {label:10s} rho={rho:.3f}kg/m3  u={u:6.1f}m/s  D={D:.3f}m ({D*1000:.0f}mm)  "
              f"[{flag}, ceiling={TIP_SPEED_CEILING_M_S:.0f}m/s]")

    print()
    print("=== cold-end shaft power vs. P_shaftLimit ===")
    if P_shaftLimit:
        pct_hot = 100 * Psh[i_hot] / P_shaftLimit
        pct_end = 100 * Psh[i_end] / P_shaftLimit
        print(f"  P_shaftLimit = {P_shaftLimit/1e3:.1f}kW")
        print(f"  P_shaft at hot start = {Psh[i_hot]/1e3:.2f}kW  ({pct_hot:.1f}% of limit)")
        print(f"  P_shaft at cold end  = {Psh[i_end]/1e3:.2f}kW  ({pct_end:.1f}% of limit"
              f"{', OVER LIMIT' if pct_end > 100 else ''})")
        print("  If over limit: enableCirculatorPowerOptimization (PID_circulatorPower ->")
        print("  PF_RV01) exists specifically to trim this back to P_shaftLimit and can be")
        print("  switched on at any time -- see pf-circulator-sizing.md section 9.")
    else:
        print("  P_shaftLimit not found in this result file")


if __name__ == "__main__":
    main()
