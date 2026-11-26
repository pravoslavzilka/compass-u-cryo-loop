"""Key-variable summary + plot of a PF run. usage: summarize_pf_run.py result.mat out_dir name"""
import sys, os, re, json, numpy as np
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from matlib import Result
import matplotlib; matplotlib.use('Agg'); import matplotlib.pyplot as plt
res, out, name = sys.argv[1:4]
r = Result(res); t = r.time; g = r.get
coils = ['PF1U','PF1L','PF2U','PF2L','PF3U','PF3L','PF4U','PF4L']
def settled_le(a, thr):
    k = np.where(a > thr)[0]
    if len(k) == 0: return 0.0
    return float(t[k[-1]]) if k[-1] < len(t)-1 else None
def events(a):
    d = np.where(np.diff((a > 0.5).astype(int)) != 0)[0]
    return [(float(t[i+1]), 'open' if a[i+1] > 0.5 else 'shut') for i in d]
S = {}
Tg = np.array([g(f'T_gas_out_PF[{i}]') for i in range(1, 9)])
Tw = []
for c in coils:
    cols = [n for n in r.names if re.match(rf'^{c}\.tube\d\.heatPort\[\d+\]\.T$', n)]
    Tw.append(np.max([g(n) for n in cols], axis=0))
Tw = np.array(Tw)
S['coils'] = {}
for i, c in enumerate(coils):
    S['coils'][c] = dict(T0_wall_K=float(Tw[i,0]), T_end_wall_K=float(Tw[i,-1]), wall_settled_le_80K_s=settled_le(Tw[i], 80.0), wall_settled_le_81K_s=settled_le(Tw[i], 81.0),
                         T_gas_out_end_K=float(Tg[i,-1]), T_gas_out_peak_K=float(Tg[i].max()),
                         isolation_events=events(g(f'coilOpen[{i+1}]')))
hot = Tw.max(0)
S['slowest_wall_settled_le_80K_s'] = settled_le(hot, 80.0)
S['slowest_wall_settled_le_81K_s'] = settled_le(hot, 81.0)  # PF supply floors at ~80 K, so 80.0 itself is barely missed
S['T_wall_hot_peak_K'] = float(hot.max()); S['T_wall_hot_end_K'] = float(hot[-1])
Tmx = g('T_gas_out_max'); S['T_gas_out_max_K'] = dict(start=float(Tmx[0]), peak=float(Tmx.max()), end=float(Tmx[-1]))
sup = g('sensor_T.sensorValue'); S['supply_T_K'] = dict(start=float(sup[0]), min=float(sup.min()), max=float(sup.max()), end=float(sup[-1]))
S['coil_to_coil_spread_wall_K_max'] = float((Tw.max(0) - Tw.min(0)).max())
S['hot_wall_minus_supply_K_max'] = float((hot - sup).max())
m = g('sensor_m_flow.sensorValueSI') if r.has('sensor_m_flow.sensorValueSI') else g('sensor_m_flow.sensorValue')
P = g('fan2ndOrder.P_shaft'); p = g('sensor_p_discharge.sensorValue')
S['m_flow_kg_s'] = dict(max=float(m.max()), end=float(m[-1]))
S['P_shaft_kW'] = dict(start=float(P[0]/1e3), peak=float(P.max()/1e3), end=float(P[-1]/1e3))
S['circulator_energy_kWh'] = float(np.trapezoid(P, t)/3.6e6)
S['p_discharge_bar'] = dict(min=float(p.min()/1e5), max=float(p.max()/1e5), end=float(p[-1]/1e5))
json.dump(S, open(f'{out}/summary.json', 'w'), indent=2)
fig, ax = plt.subplots(4, 1, figsize=(9, 10), sharex=True)
for i, c in enumerate(coils): ax[0].plot(t, Tw[i], label=c)
ax[0].plot(t, sup, 'k--', label='supply'); ax[0].axhline(80, c='grey', lw=.5); ax[0].set_ylabel('wall T [K]'); ax[0].legend(ncol=5, fontsize=6)
ax[1].plot(t, Tmx, label='T_gas_out_max'); ax[1].plot(t, g('wanted_temp'), '--', label='wanted_temp'); ax[1].set_ylabel('K'); ax[1].legend()
ax[2].plot(t, P/1e3); ax[2].set_ylabel('P_shaft [kW]')
ax[3].plot(t, m); ax[3].set_ylabel('m_flow [kg/s]'); ax[3].set_xlabel('time [s]')
fig.suptitle(name, fontsize=8); fig.tight_layout(); fig.savefig(f'{out}/overview.png', dpi=110)
print(json.dumps({k: v for k, v in S.items() if k != 'coils'}, indent=1))
