"""Key-variable summary + plot of a CS run. usage: summarize_cs_run.py result.mat out_dir name"""
import sys, json, numpy as np
import os; sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from matlib import Result
import matplotlib; matplotlib.use('Agg'); import matplotlib.pyplot as plt
res, out, name = sys.argv[1:4]
r = Result(res); t = r.time; g = r.get
def first(a, thr=0.5):
    i = int(np.argmax(a > thr)); return float(t[i]) if a.max() > thr else None
def first_below(a, thr):
    """Time after which a stays <= thr (None if never; 0 if always)."""
    k = np.where(a > thr)[0]
    if len(k) == 0: return 0.0
    return float(t[k[-1]]) if k[-1] < len(t)-1 else None
coils = ['CS1','CS2U','CS2L','CS3U','CS3L']
S = {}
S['phases_s'] = dict(probe_end=first(1-g('prepProbing')), flush_start=first(g('prepFlushing')),
                     coolantReady=first(g('coolantReady')), controlsActive=first(g('controlsActive')),
                     allReleased=first(g('allReleased')))
S['T_probe_K'] = float(g('T_probe').max()); S['T_prepTarget_K'] = float(g('T_prepTarget')[-1])
S['T_loopInitial_K'] = float(g('T_loopInitial')[0])
Tw = np.array([g(f'T_wall_max_CS[{i}]') for i in range(1,6)])
S['coils'] = {c: dict(T0_K=float(Tw[i,0]), T_end_K=float(Tw[i,-1]), settled_le_80K_s=first_below(Tw[i],80.0),
              coldShut_s=first(g(f'coldShut[{i+1}]'))) for i,c in enumerate(coils)}
hot = Tw.max(axis=0)
S['slowest_coil_settled_le_80K_s'] = first_below(hot, 80.0)
S['T_wall_hot_end_K'] = float(hot[-1]); S['T_wall_hot_max_K'] = float(hot.max())
rd = t >= (S['phases_s']['coolantReady'] or 0)
sup = g('sensor_T_header.sensorValue'); sup_all = g('sensor_T.sensorValue')
S['supply_T_K'] = dict(min=float(sup_all.min()), max=float(sup_all.max()), end=float(sup_all[-1]))
S['max_hotwall_minus_header_K_after_ready'] = float((hot - sup)[rd].max())
S['min_hotwall_minus_header_K_after_ready'] = float((hot - sup)[rd].min())
S['spread_between_coils_K_max_after_ready'] = float((Tw.max(0) - Tw.min(0))[rd].max())
m = g('m_flow_loop'); P = g('fan2ndOrder.P_shaft'); Q = g('Q_evaporator'); p = g('sensor_p_discharge.sensorValue')
S['m_flow_loop_kg_s'] = dict(max=float(m.max()), end=float(m[-1]))
S['P_shaft_kW'] = dict(start=float(P[0]/1e3), peak=float(P.max()/1e3), end=float(P[-1]/1e3))
S['circulator_energy_kWh'] = float(np.trapezoid(P, t)/3.6e6)
S['LIN_energy_MJ'] = float(np.trapezoid(np.maximum(Q,0), t)/1e6); S['Q_evaporator_kW'] = dict(max=float(Q.max()/1e3), end=float(Q[-1]/1e3))
S['p_discharge_bar'] = dict(min=float(p.min()/1e5), max=float(p.max()/1e5), end=float(p[-1]/1e5))
json.dump(S, open(f'{out}/summary.json','w'), indent=2)
fig, ax = plt.subplots(4,1, figsize=(9,10), sharex=True)
for i,c in enumerate(coils): ax[0].plot(t, Tw[i], label=c)
ax[0].plot(t, sup_all, 'k--', label='supply'); ax[0].axhline(80, c='grey', lw=.5); ax[0].set_ylabel('T [K]'); ax[0].legend(ncol=3, fontsize=7)
ax[1].plot(t, m, label='m_flow_loop'); ax[1].plot(t, g('m_flow_set'), '--', label='m_flow_set'); ax[1].set_ylabel('kg/s'); ax[1].legend()
ax[2].plot(t, P/1e3); ax[2].set_ylabel('P_shaft [kW]')
ax[3].plot(t, Q/1e3); ax[3].set_ylabel('Q_evap [kW]'); ax[3].set_xlabel('time [s]')
for a in ax:
    for k in ('coolantReady','allReleased'):
        v = S['phases_s'][k]
        if v: a.axvline(v, c='r', lw=.4, ls=':')
fig.suptitle(name, fontsize=8); fig.tight_layout(); fig.savefig(f'{out}/overview.png', dpi=110)
print(json.dumps(S, indent=1))
