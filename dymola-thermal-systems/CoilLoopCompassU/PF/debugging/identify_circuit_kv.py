#!/usr/bin/env python3
"""
Identify the hydraulic flow coefficient Kv of the CIRCUIT branch in the
CoilLoopCompassU PFCircuit model, from a Dymola v4 .mat result file, using
two independent methods (flow-ratio and direct dp/mdot/rho), cross-checked
against each other.

Topology (from PFCircuit.mo, confirmed by connect() statements):

    fan2ndOrder.portB -> junction5.portA        (pump outlet feeds junction5)
    junction5.portB   -> valve1.portA/B         (BYPASS valve, direct
                          -> junction4.portB      short-circuit between the
                                                   two junctions)
    junction5.portC   -> junction6 -> valve2 -> ... -> junction18 ->
                          junction4.portA         (CIRCUIT branch: the whole
                                                   coil/header network)
    junction4.portC   -> fan2ndOrder.portA      (junction4 feeds pump inlet)

So Junction5 (split) and Junction4 (merge) bound the parallel section exactly
as expected, and 'valve1' is the physical bypass valve.

IMPORTANT DEVIATION FROM THE NOMINAL Kv = Kv_max * y MODEL
------------------------------------------------------------
In this model valve1 is NOT opening-modulated:
    valve1.use_KvValueInput = false
    valve1.KvValueFixed     = a small FIXED constant (differs per result file:
                               0.0001 m3/h in result.mat, 0.001 m3/h in
                               result_tol1e-5.mat) -- NOT 100.
There is no logged relative-opening ('y') signal for valve1 at all. The
component with KvValueFixed = 100 ('valve', no suffix) is a *different*,
unrelated valve on a cold-trap/recirculation sub-loop (volume/tube1/
coldSurface), not on the Junction4-Junction5 bypass.

Consequently this script treats valve1 as a small, FIXED reference orifice
(the classic technique of inferring a large branch's Kv from the flow split
against a small known leak) rather than a variable-opening control valve.
y is therefore held at the constant fallback value y = 1 for the whole run,
and "Kv_max" in the beta = Kv_max/Kv_c relation is valve1's fixed Kv for
this file. This is reported explicitly in the output -- do not mistake the
resulting single-beta values for a fitted line.

Variable mapping used (see also --dump-vars):
    m_dot_c  circuit branch mass flow   junction5.portC.m_flow   (kg/s)
    m_dot_b  bypass branch mass flow    valve1.portA.m_flow      (kg/s)
    y        valve relative opening     not present -> fallback y = 1
    p5       pressure at Junction5      junction5.p              (Pa)
    p4       pressure at Junction4      junction4.p              (Pa)
    rho_in   density at circuit inlet   valve2.summary.d_gas_A   (kg/m3)
             (valve2 sits immediately downstream of junction6, which is
             wired directly to junction5.portC with no resistive element
             in between)
    rho_out  density at circuit outlet  fan2ndOrder.summary.d_gas (kg/m3)
             (fan2ndOrder.portA is wired directly to junction4.portC;
             valid proxy for junction4's own pool density because the
             bypass contributes a negligible fraction of the merged flow)

Usage:
    python identify_circuit_kv.py [path/to/result.mat] [--dump-vars]
"""

import sys
import argparse
import numpy as np
import scipy.io as sio


# --------------------------------------------------------------------------
# Low-level Dymola v4 .mat reader
# --------------------------------------------------------------------------

class DymolaResult:
    def __init__(self, path):
        self.path = path
        d = sio.loadmat(path, chars_as_strings=False, squeeze_me=False)
        for key in ("name", "dataInfo", "data_1", "data_2"):
            if key not in d:
                raise ValueError(f"{path}: missing '{key}' matrix -- not a "
                                  f"Dymola v4 result file?")
        self.names = self._decode_names(d["name"])
        self.dataInfo = d["dataInfo"]
        self.data_1 = d["data_1"]
        self.data_2 = d["data_2"]
        self.n = self.data_2.shape[1]
        if "Time" not in self.names:
            raise ValueError(f"{path}: no 'Time' variable found")
        self.t = self.signal("Time")

    @staticmethod
    def _decode_names(namemat):
        nrows, ncols = namemat.shape
        return ["".join(namemat[:, j]).rstrip("\x00").rstrip()
                for j in range(ncols)]

    def has(self, varname):
        return varname in self.names

    def signal(self, varname):
        """Return the full time trajectory of varname as an (n,) array,
        broadcasting table_1 constants to the data_2 time base."""
        idx = self.names.index(varname)
        table = int(self.dataInfo[0, idx])
        col = int(self.dataInfo[1, idx])
        negate = col < 0
        col = abs(col)
        if table == 1:
            raw = self.data_1[col - 1, :]
            val = raw[-1] if len(raw) > 1 else raw[0]
            arr = np.full(self.n, float(val))
        else:  # table 0 (time) or 2 -> trajectories in data_2
            arr = self.data_2[col - 1, :].astype(float)
        if negate:
            arr = -arr
        return arr

    def const(self, varname):
        """Return a single scalar for a data_1 parameter (also works for
        data_2 signals that happen to be constant -- returns last sample)."""
        return float(self.signal(varname)[-1])


# --------------------------------------------------------------------------
# Step 0 -- variable inspection
# --------------------------------------------------------------------------

NARROW_KEYWORDS = ["junction5.", "junction4.", "valve", "opening", "massFlow"]
BROAD_KEYWORDS = {
    "m_flow": lambda n: "m_flow" in n,
    "pressure (.p / .p_)": lambda n: n.endswith(".p") or ".p_" in n or n.endswith(".p1") or n.endswith(".p2"),
    "density (.d_ / rho / density)": lambda n: ".d_" in n or "rho" in n.lower() or "density" in n.lower(),
    "temperature (.T / T_gas / T_degC)": lambda n: n.endswith(".T") or "T_gas" in n or "T_degC" in n,
}


def dump_vars(res):
    print("=" * 78)
    print("STEP 0 -- variable inspection (%s)" % res.path)
    print("=" * 78)
    print("NOTE: 'junction4'/'junction5' are also used as *local* instance "
          "names inside each PF coil assembly (e.g. PF1L.junction5.*). Those "
          "are unrelated nested components, not the top-level split/merge "
          "nodes. The listing below for junction4/junction5 is restricted "
          "to the top-level instances (name starts with 'junction4.' / "
          "'junction5.'); nested PFxx.junction4/5.* matches are counted but "
          "not printed.")
    for kw in NARROW_KEYWORDS:
        all_matches = [n for n in res.names if kw.lower() in n.lower()]
        # "top-level" = not nested inside a PF-coil assembly instance
        matches = [n for n in all_matches if "." not in n.split(kw, 1)[0]]
        nested = len(all_matches) - len(matches)
        label = "top-level" if nested else "contains"
        print(f"\n-- {label} '{kw}': {len(matches)} variable(s)"
              + (f" (+{nested} nested inside PF-coil sub-assemblies, not shown)"
                 if nested else ""))
        for m in matches:
            print("   ", m)

    print("\nBroad keywords (m_flow / p / d,rho / T) match hundreds of "
          "unrelated internal variables (e.g. 'pInitial', 'portA.p', "
          "'T_nominal') in a 4600+ variable model, so only counts + a "
          "curated subset are shown:")
    for label, pred in BROAD_KEYWORDS.items():
        matches = [n for n in res.names if pred(n)]
        print(f"\n-- {label}: {len(matches)} total matches (showing junction4/5, "
              f"valve1/2, fan2ndOrder subset)")
        for m in matches:
            if any(m.startswith(p) for p in
                   ("junction4.", "junction5.", "junction6.", "junction18.",
                    "valve1.", "valve2.", "fan2ndOrder.")):
                print("   ", m)


# --------------------------------------------------------------------------
# Mapping + sanity checks
# --------------------------------------------------------------------------

MAP = dict(
    m_dot_c="junction5.portC.m_flow",
    m_dot_c_check="junction4.portA.m_flow",
    m_dot_b="valve1.portA.m_flow",
    m_dot_b_check="junction5.portB.m_flow",
    p5="junction5.p",
    p4="junction4.p",
    rho_in="valve2.summary.d_gas_A",
    rho_out="fan2ndOrder.summary.d_gas",
    Kv_bypass_fixed="valve1.KvValueFixed",
    Kv_bypass_input_flag="valve1.use_KvValueInput",
    Kv_other_valve="valve.KvValueFixed",
)


def get_mapped_signals(res):
    sig = {}
    for key, name in MAP.items():
        if not res.has(name):
            raise ValueError(f"Expected variable '{name}' (for '{key}') not "
                              f"found in {res.path}")
        sig[key] = res.signal(name)
    sig["t"] = res.t
    return sig


# --------------------------------------------------------------------------
# Steady-state gating
# --------------------------------------------------------------------------

def steady_mask(t, m_dot_c, dp, rel_threshold=0.01, window_s=100.0):
    """Flag samples where the normalized rate of change of m_dot_c and dp,
    evaluated with a centered finite-difference derivative and scaled by
    window_s, stays below rel_threshold (relative to the local magnitude)."""
    dmdt = np.gradient(m_dot_c, t)
    ddpdt = np.gradient(dp, t)
    rel_dmdt = np.abs(dmdt) * window_s / np.maximum(np.abs(m_dot_c), 1e-12)
    rel_ddpdt = np.abs(ddpdt) * window_s / np.maximum(np.abs(dp), 1e-12)
    ok = (rel_dmdt < rel_threshold) & (rel_ddpdt < rel_threshold)
    return ok, rel_dmdt, rel_ddpdt


# --------------------------------------------------------------------------
# Main analysis
# --------------------------------------------------------------------------

def analyze(path, n_samples=6, y_lo=0.05, y_hi=0.95,
            steady_rel_threshold=0.01, steady_window_s=100.0):
    res = DymolaResult(path)
    sig = get_mapped_signals(res)

    # Dymola frequently logs a duplicated final timestamp (e.g. from a
    # terminal event). Duplicate/non-increasing time samples break
    # np.gradient (division by zero) -- drop them, keeping the first
    # occurrence of each t.
    t_raw = sig["t"]
    keep = np.concatenate(([True], np.diff(t_raw) > 0))
    n_dropped = np.sum(~keep)
    if n_dropped:
        print(f"NOTE: dropped {n_dropped} duplicated/non-increasing time "
              f"sample(s) (t={t_raw[~keep]}) before analysis.\n")
    for key in sig:
        sig[key] = sig[key][keep]

    t = sig["t"]
    m_dot_c = np.abs(sig["m_dot_c"])
    m_dot_c_check = np.abs(sig["m_dot_c_check"])
    m_dot_b = np.abs(sig["m_dot_b"])
    m_dot_b_check = np.abs(sig["m_dot_b_check"])
    p5 = sig["p5"]
    p4 = sig["p4"]
    rho_in = sig["rho_in"]
    rho_out = sig["rho_out"]
    rho_mean = 0.5 * (rho_in + rho_out)
    dp = p5 - p4

    Kv_bypass_fixed = sig["Kv_bypass_fixed"][-1]
    Kv_bypass_is_input = bool(sig["Kv_bypass_input_flag"][-1])
    Kv_other_valve = sig["Kv_other_valve"][-1]

    print("=" * 78)
    print("VALVE / Kv_max SANITY CHECK")
    print("=" * 78)
    print(f"valve1 (the actual bypass, junction5<->junction4):")
    print(f"    use_KvValueInput = {Kv_bypass_is_input}  "
          f"({'modulated by input signal' if Kv_bypass_is_input else 'FIXED constant, no opening signal'})")
    print(f"    KvValueFixed     = {Kv_bypass_fixed:.6g} m3/h")
    if abs(Kv_bypass_fixed - 100.0) > 1e-9:
        print(f"    *** DEVIATES from the assumed Kv_max = 100 m3/h. Using "
              f"{Kv_bypass_fixed:.6g} m3/h as Kv_max for this file. ***")
    print(f"    NOTE: a *different* component named 'valve' (unrelated cold-"
          f"trap sub-loop) has KvValueFixed = {Kv_other_valve:.6g} m3/h -- "
          f"this is almost certainly where the assumed 100 m3/h figure "
          f"belongs, but it is NOT on the Junction4/5 bypass.")
    if not Kv_bypass_is_input:
        print(f"    -> No commanded-opening 'y' signal exists for valve1 in "
              f"this run. Falling back to the single-y case: y == 1 for "
              f"all samples (valve1 is simply a fixed small reference "
              f"orifice). beta is therefore computed point-wise, not via "
              f"a line fit.")
    y = np.ones_like(t)

    # sign / orientation check
    print("\n" + "=" * 78)
    print("SIGN / ORIENTATION CHECK (raw signed values at t=0 and t=t_end)")
    print("=" * 78)
    for label, raw in [("junction5.portC.m_flow (m_dot_c)", sig["m_dot_c"]),
                        ("junction4.portA.m_flow (m_dot_c check)", sig["m_dot_c_check"]),
                        ("valve1.portA.m_flow (m_dot_b)", sig["m_dot_b"]),
                        ("junction5.portB.m_flow (m_dot_b check)", sig["m_dot_b_check"])]:
        print(f"  {label:45s}  t=0: {raw[0]: .6e}   t=end: {raw[-1]: .6e}"
              f"   {'(negative -> outflow convention)' if raw[-1] < 0 else ''}")

    max_rel_mismatch_c = np.max(np.abs(m_dot_c - m_dot_c_check) /
                                 np.maximum(m_dot_c, 1e-9))
    print(f"\n  max relative mismatch between the two m_dot_c measurement "
          f"points over the WHOLE run (junction5.portC vs junction4.portA): "
          f"{max_rel_mismatch_c*100:.3f}% -- this is dominated by the t=0 "
          f"initial-condition transient (junction4.portA starts near zero "
          f"while junction5.portC starts at its own initial guess); it is "
          f"not evidence of a sign/mapping error, just an unsettled start. "
          f"The steady-state gate below removes the transient before this "
          f"pair is used for anything.")

    # dp units check
    print("\n" + "=" * 78)
    print("dp UNITS CHECK")
    print("=" * 78)
    print(f"  dp = p5 - p4 range over run: [{dp.min():.6g}, {dp.max():.6g}] Pa")
    if np.median(np.abs(dp)) < 100:
        print("  *** dp values look like they might be in bar, not Pa -- "
              "STOP AND CHECK. ***")
    else:
        print("  dp is in the expected O(1e3-1e5) Pa range -- OK.")

    # leakage check
    leak_pct = 100.0 * m_dot_b / np.maximum(m_dot_c, 1e-12)
    print("\n" + "=" * 78)
    print("BYPASS LEAKAGE CHECK (valve1 is fixed near-shut for this whole run)")
    print("=" * 78)
    print(f"  m_dot_b as %% of m_dot_c: min={leak_pct.min():.4g}%%, "
          f"max={leak_pct.max():.4g}%%, mean={leak_pct.mean():.4g}%%")

    # ------------------------------------------------------------------
    # Steady-state gating
    # ------------------------------------------------------------------
    ok, rel_dmdt, rel_ddpdt = steady_mask(t, m_dot_c, dp,
                                           rel_threshold=steady_rel_threshold,
                                           window_s=steady_window_s)
    n_excluded = np.sum(~ok)
    print("\n" + "=" * 78)
    print(f"STEADY-STATE GATING (relative rate of change over a "
          f"{steady_window_s:.0f}s window < {steady_rel_threshold*100:.1f}%)")
    print("=" * 78)
    print(f"  {n_excluded} / {len(t)} samples excluded as not-steady.")
    if n_excluded > 0:
        first_ok_idx = np.argmax(ok) if ok.any() else None
        if first_ok_idx is not None and first_ok_idx > 0:
            print(f"  Samples t < {t[first_ok_idx]:.1f}s are excluded "
                  f"(initial transient / slow blow-down of the loop "
                  f"inventory -- p5 {'drops' if p5[-1] < p5[0] else 'rises'} "
                  f"from ~{p5[0]:.3e} Pa to ~{p5[-1]:.3e} Pa over the run).")

    # y-window gating: the [y_lo, y_hi] exclusion exists to protect against
    # dividing by a near-zero branch flow when y really is a commanded
    # opening. Here y is a fallback constant (=1, not a real signal, see
    # warning above) representing "valve1 is always at its one fixed Kv" --
    # applying the [0.05, 0.95] window to that fallback would incorrectly
    # exclude every sample. Skip the gate in that case; keep it active for
    # future files where valve1 actually has a real, varying opening signal.
    if Kv_bypass_is_input:
        y_ok = (y >= y_lo) & (y <= y_hi)
        n_y_excluded = np.sum(~y_ok)
        print(f"  {n_y_excluded} / {len(t)} samples excluded by the y in "
              f"[{y_lo}, {y_hi}] gate.")
    else:
        y_ok = np.ones_like(y, dtype=bool)
        print(f"  y-window gate [{y_lo}, {y_hi}] SKIPPED: valve1 has no real "
              f"opening signal in this run (y is the constant fallback = 1), "
              f"so the gate would spuriously exclude every sample.")

    usable = ok & y_ok
    n_usable = np.sum(usable)
    print(f"  {n_usable} / {len(t)} samples usable after both gates.")
    if n_usable < n_samples:
        print(f"\n  *** Only {n_usable} usable sample(s), need at least "
              f"{n_samples} for the requested table. This run never reaches "
              f"a state passing the {steady_rel_threshold*100:.1f}%/"
              f"{steady_window_s:.0f}s steady-state gate -- either it is "
              f"still transient at the end of the recorded time span, or "
              f"the gate is too strict for this run. Re-run with a looser "
              f"--steady-threshold / --steady-window if you believe the "
              f"tail of the run is close enough to steady for your "
              f"purposes; do not trust Kv_c numbers from a run that never "
              f"settles. ***")
        return None

    usable_idx = np.where(usable)[0]

    steady_mismatch_c = np.max(np.abs(m_dot_c[usable_idx] - m_dot_c_check[usable_idx]) /
                                np.maximum(m_dot_c[usable_idx], 1e-9))
    print(f"  max relative mismatch between the two m_dot_c measurement "
          f"points, restricted to usable/steady samples only: "
          f"{steady_mismatch_c*100:.3f}%")

    # ------------------------------------------------------------------
    # Method A -- flow ratio
    # ------------------------------------------------------------------
    with np.errstate(divide="ignore", invalid="ignore"):
        ratio = m_dot_b / m_dot_c
        beta_pointwise = ratio / y  # y == 1 here
        Kv_c_A = Kv_bypass_fixed / beta_pointwise

    print("\n" + "=" * 78)
    print("METHOD A -- flow ratio (m_dot_b / m_dot_c = beta * y)")
    print("=" * 78)
    y_unique = np.unique(np.round(y[usable_idx], 6))
    if len(y_unique) <= 1:
        print(f"  Only one y value present in this run (y = "
              f"{y_unique[0] if len(y_unique) else 'n/a'}, constant because "
              f"valve1.use_KvValueInput = False). Computing beta point-wise "
              f"per the single-y fallback -- NOT a line fit.")
    else:
        A = y[usable_idx]
        Bv = ratio[usable_idx]
        slope = np.sum(A * Bv) / np.sum(A * A)  # least squares through origin
        resid = Bv - slope * A
        ss_res = np.sum(resid ** 2)
        ss_tot = np.sum((Bv - Bv.mean()) ** 2)
        r2 = 1 - ss_res / ss_tot if ss_tot > 0 else float("nan")
        print(f"  Multiple y values found -- fitted beta (slope through "
              f"origin) = {slope:.6g}, R^2 = {r2:.6f}")
        beta_pointwise = np.full_like(beta_pointwise, slope)
        Kv_c_A = Kv_bypass_fixed / beta_pointwise

    n_excluded_ywin = np.sum(~y_ok)
    print(f"  Samples excluded for y outside [{y_lo}, {y_hi}]: {n_excluded_ywin}")

    # ------------------------------------------------------------------
    # Method B -- direct
    # ------------------------------------------------------------------
    Kv_c_B_rho_in = 36000.0 * m_dot_c / np.sqrt(np.maximum(rho_in * dp, 1e-30))
    Kv_c_B_rho_out = 36000.0 * m_dot_c / np.sqrt(np.maximum(rho_out * dp, 1e-30))
    Kv_c_B_rho_mean = 36000.0 * m_dot_c / np.sqrt(np.maximum(rho_mean * dp, 1e-30))
    rho_ratio = rho_in / rho_out

    print("\n" + "=" * 78)
    print("METHOD B -- direct (Kv_c = 36000 * m_dot_c / sqrt(rho * dp))")
    print("=" * 78)
    print("  (valid across the whole run here since the 'bypass shut' "
          "condition is permanent -- valve1 never opens beyond its fixed "
          "near-zero Kv)")
    max_rho_dev = np.max(np.abs(rho_ratio[usable_idx] - 1.0)) * 100
    print(f"  rho_in/rho_out max deviation from 1 over usable samples: "
          f"{max_rho_dev:.2f}%")
    if max_rho_dev > 20:
        print("  *** rho_in/rho_out differs from 1 by more than ~20%% -- "
              "the lumped Kv_c is only an approximation. ***")

    # ------------------------------------------------------------------
    # Sample table
    # ------------------------------------------------------------------
    sample_idx = usable_idx[np.linspace(0, len(usable_idx) - 1, n_samples).astype(int)]
    sample_idx = np.unique(sample_idx)

    print("\n" + "=" * 78)
    print(f"SAMPLE TABLE ({len(sample_idx)} steady, in-window samples)")
    print("=" * 78)
    hdr = (f"{'t[s]':>9} {'y':>6} {'m_dot_c':>10} {'m_dot_b':>12} "
           f"{'dp[Pa]':>10} {'rho_in':>8} {'rho_out':>8} "
           f"{'Kv_c_A':>10} {'Kv_c_B(in)':>11} {'Kv_c_B(out)':>12} "
           f"{'Kv_c_B(mean)':>13}")
    print(hdr)
    for i in sample_idx:
        print(f"{t[i]:9.1f} {y[i]:6.3f} {m_dot_c[i]:10.5f} {m_dot_b[i]:12.4e} "
              f"{dp[i]:10.1f} {rho_in[i]:8.4f} {rho_out[i]:8.4f} "
              f"{Kv_c_A[i]:10.4f} {Kv_c_B_rho_in[i]:11.4f} "
              f"{Kv_c_B_rho_out[i]:12.4f} {Kv_c_B_rho_mean[i]:13.4f}")

    def stats(arr, idx):
        a = arr[idx]
        mean = a.mean()
        std = a.std()
        spread = (a.max() - a.min()) / mean if mean != 0 else float("nan")
        return mean, std, spread

    print("\n" + "-" * 78)
    print(f"{'':20s} {'mean':>12} {'std':>12} {'spread(%)':>12}")
    for label, arr in [("Kv_c Method A", Kv_c_A),
                        ("Kv_c Method B (rho_in)", Kv_c_B_rho_in),
                        ("Kv_c Method B (rho_out)", Kv_c_B_rho_out),
                        ("Kv_c Method B (rho_mean)", Kv_c_B_rho_mean)]:
        mean, std, spread = stats(arr, sample_idx)
        print(f"{label:20s} {mean:12.4f} {std:12.4f} {spread*100:12.3f}")

    # drift with mass flow (Reynolds-dependence check)
    corr = np.corrcoef(m_dot_c[sample_idx], Kv_c_B_rho_mean[sample_idx])[0, 1]
    print(f"\n  correlation(Kv_c Method B mean, m_dot_c) over sample table = "
          f"{corr:.4f} "
          f"({'notable trend with flow -> possible Reynolds dependence' if abs(corr) > 0.5 else 'no strong trend with flow'})")

    # ------------------------------------------------------------------
    # Cross-check and final numbers
    # ------------------------------------------------------------------
    Kv_c_A_mean = Kv_c_A[sample_idx].mean()
    Kv_c_A_std = Kv_c_A[sample_idx].std()
    Kv_c_B_mean = Kv_c_B_rho_mean[sample_idx].mean()
    Kv_c_B_std = Kv_c_B_rho_mean[sample_idx].std()
    pct_diff = 100.0 * (Kv_c_A_mean - Kv_c_B_mean) / Kv_c_B_mean

    print("\n" + "=" * 78)
    print("CROSS-CHECK")
    print("=" * 78)
    print(f"  Method A : Kv_c = {Kv_c_A_mean:.4f} +/- {Kv_c_A_std:.4f} m3/h")
    print(f"  Method B : Kv_c = {Kv_c_B_mean:.4f} +/- {Kv_c_B_std:.4f} m3/h  "
          f"(rho_mean variant)")
    print(f"  percent difference (A vs B): {pct_diff:+.2f}%")
    if abs(pct_diff) < 5:
        print("  -> Agreement within a few percent: both trustworthy. "
              "Reporting Method A as final.")
        final_Kv_c = Kv_c_A_mean
        final_Kv_c_unc = Kv_c_A_std
    elif Kv_c_B_mean < Kv_c_A_mean:
        print("  -> Method B is systematically SMALLER than Method A: "
              "likely the pressure taps (junction5.p/junction4.p) include "
              "piping/resistance beyond the parallel section itself, or "
              "there's series resistance between the junctions and the "
              "branch inlets (e.g. junction6/valve2/junction18 add "
              "additional drop not captured by a single lumped Kv_c).")
        final_Kv_c = Kv_c_A_mean
        final_Kv_c_unc = Kv_c_A_std
    else:
        print("  -> Methods disagree by more than a few percent in a way "
              "not explained by a simple series-resistance bias -- check "
              "density choice and flow regime (Reynolds dependence).")
        final_Kv_c = Kv_c_A_mean
        final_Kv_c_unc = Kv_c_A_std

    beta_final = Kv_bypass_fixed / final_Kv_c if final_Kv_c else float("nan")
    frac_full_open = 1.0 / (1.0 + beta_final)

    print("\n" + "=" * 78)
    print("FINAL OUTPUT")
    print("=" * 78)
    print(f"  1) Kv_c            = {final_Kv_c:.4f} +/- {final_Kv_c_unc:.4f} m3/h")
    print(f"  2) beta = Kv_max/Kv_c = {beta_final:.6g}   "
          f"(Kv_max here = valve1's fixed Kv = {Kv_bypass_fixed:.6g} m3/h, "
          f"NOT the assumed 100 m3/h -- see warning above)")
    print(f"  3) circuit flow fraction at full bypass opening, "
          f"1/(1+beta) = {frac_full_open:.6f} "
          f"({frac_full_open*100:.4f}%) -- with this file's tiny fixed "
          f"bypass Kv, beta << 1, so this number is only meaningful if you "
          f"scale Kv_max up to the real bypass valve's actual full-open Kv.")
    print(f"  4) Methods agree within {abs(pct_diff):.2f}% "
          f"({'YES, within a few percent' if abs(pct_diff) < 5 else 'NO, see cross-check discussion above'}).")
    if abs(corr) > 0.5:
        print(f"\n  Kv_c drifts systematically with mass flow across the "
              f"sample table (correlation = {corr:.3f}, Kv_c rises from "
              f"~{Kv_c_B_rho_mean[sample_idx][0]:.3f} to "
              f"~{Kv_c_B_rho_mean[sample_idx][-1]:.3f} m3/h as m_dot_c rises "
              f"from ~{m_dot_c[sample_idx][0]:.4f} to "
              f"~{m_dot_c[sample_idx][-1]:.4f} kg/s). This indicates "
              f"Reynolds-dependent friction in the circuit branch -- Kv_c "
              f"is only valid near the flow range it was identified at "
              f"({m_dot_c[sample_idx].min():.4f}-{m_dot_c[sample_idx].max():.4f} kg/s "
              f"here), not as a flow-independent constant.")

    if beta_final > 10:
        y_half = 1.0 / beta_final
        print(f"\n  beta > 10: most control authority would sit in the "
              f"bottom few percent of travel *if* this were a real "
              f"variable-opening valve. y at which circuit flow drops to "
              f"50% of its shut-bypass value: y = 1/beta = {y_half:.6g} "
              f"-- NOTE beta here is computed against the tiny FIXED Kv of "
              f"valve1, not against a real Kv_max=100 valve, so this figure "
              f"is not directly usable for sizing the real control valve "
              f"('valve', Kv_max={Kv_other_valve:.6g} m3/h) without rerunning "
              f"this analysis on a result file where that valve is the one "
              f"on the bypass.")
    else:
        beta_100 = Kv_other_valve / final_Kv_c
        print(f"\n  For reference, if the OTHER valve (Kv_max = "
              f"{Kv_other_valve:.6g} m3/h) were placed on this bypass "
              f"instead: beta = {beta_100:.6g}, y at 50% circuit flow = "
              f"{1.0/beta_100 if beta_100 else float('nan'):.6g}.")

    return dict(Kv_c=final_Kv_c, Kv_c_unc=final_Kv_c_unc, beta=beta_final,
                pct_diff=pct_diff)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("path", nargs="?",
                     default="result.mat",
                     help="path to the Dymola v4 .mat result file")
    ap.add_argument("--dump-vars", action="store_true",
                     help="print the Step-0 variable inspection listing")
    ap.add_argument("--n-samples", type=int, default=6)
    ap.add_argument("--steady-threshold", type=float, default=0.01,
                     help="relative rate-of-change threshold for the "
                          "steady-state gate (default 1%%)")
    ap.add_argument("--steady-window", type=float, default=100.0,
                     help="window [s] used to scale the derivative in the "
                          "steady-state gate (default 100s)")
    args = ap.parse_args()

    res = DymolaResult(args.path)
    if args.dump_vars:
        dump_vars(res)

    analyze(args.path, n_samples=args.n_samples,
            steady_rel_threshold=args.steady_threshold,
            steady_window_s=args.steady_window)


if __name__ == "__main__":
    main()
