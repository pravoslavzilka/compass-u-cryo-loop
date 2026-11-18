"""Short probe runs of PF for one scenario through the VM watcher (to find why a scenario fails).
usage: probe_pf.py --name=<tag> [--scen=6400-rev17-...] [--stop=60] [--timeout=15] [--tol=1e-4]
                   [--tinit=PF1L=160 ...] [--set=param=value ...]
Result: vm-inbox/probe_<tag>/ (logs kept), one summary line printed."""
import csv, os, sys, time, shutil
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..'))
PF = ['PF1U','PF1L','PF2U','PF2L','PF3U','PF3L','PF4U','PF4L']
FLAGS = {'enableCoilIsolation': 'true', 'enableCirculatorPowerOptimization': 'true', 'enablePressureControl': 'true',
         'enableOverCoolPrevention': 'true', 'enableOverCoolRecovery': 'true'}
name, scen, stop, timeout, tol, tinit = 'x', '6400-rev17-ver_vacuum-rrr30-77K-rump50kAs-1', '60', '15', '1e-4', {}
for a in sys.argv[1:]:
    if a.startswith('--name='): name = a[7:]
    elif a.startswith('--scen='): scen = a[7:]
    elif a.startswith('--stop='): stop = a[7:]
    elif a.startswith('--timeout='): timeout = a[10:]
    elif a.startswith('--tol='): tol = a[6:]
    elif a.startswith('--tinit='): k, v = a[8:].split('=', 1); tinit[k] = v
    elif a.startswith('--set='): k, v = a[6:].split('=', 1); FLAGS[k] = v
rows = list(csv.DictReader(open(f'{ROOT}/data/working_scenarios/model_coil_start.csv')))
T = {r['model_coil']: r['T_start_energy_conserving_K'] for r in rows if r['scenario'] == scen}
T.update(tinit)
vec = ', '.join('%s=%s' % kv for kv in FLAGS.items()) + ', ' + ', '.join('%s(TInitial=%s)' % (c, T[c]) for c in PF)
MOS = '''root  := "Z:/compass-u-cryo-loop";
outd  := root + "/vm-inbox/pf_scen";
Modelica.Utilities.Files.createDirectory(outd);
st := outd + "/status.txt";
if Modelica.Utilities.Files.exist(st) then
  Modelica.Utilities.Files.remove(st);
end if;
clearlog();
Modelica.Utilities.Streams.print("RUNNING: load + translate", st);
openModel("C:/Program Files/Dymola 2024x Refresh 1/Modelica/Library/ThermalSystems 1.13.0/package.mo", mustRead=true);
openModel(root + "/dymola-thermal-systems/CoilLoopCompassU/package.mo", mustRead=true);
cd(outd);
ok := translateModel("CoilLoopCompassU.PF.PFCircuit(%s)");
savelog(outd + "/log.txt");
if not ok then
  Modelica.Utilities.Streams.print("FAIL: translation", st);
  Modelica.Utilities.Streams.print(getLastErrorLog(), outd + "/last_error.txt");
else
  Modelica.Utilities.Streams.print("RUNNING: simulate %s s", st);
  OutputCPUtime := true;
  simOk := simulateModel("CoilLoopCompassU.PF.PFCircuit(%s)", stopTime=%s, tolerance=%s,
                         resultFile=outd + "/result");
  savelog(outd + "/log.txt");
  if simOk then
    Modelica.Utilities.Streams.print("OK: simulated %s s", st);
  else
    Modelica.Utilities.Streams.print("FAIL: simulation", st);
    Modelica.Utilities.Streams.print(getLastErrorLog(), outd + "/last_error.txt");
  end if;
end if;
'''
inbox = f'{ROOT}/vm-inbox'
outd = f'{inbox}/pf_scen'
if os.path.isdir(outd): shutil.rmtree(outd)
os.makedirs(outd)
open(f'{ROOT}/tools/vm/pf_scen.mos', 'w').write(MOS % (vec, stop, vec, stop, tol, stop))
open(f'{inbox}/run.request', 'w').write('script=tools/vm/pf_scen.mos' + chr(10) + 'timeout_min=' + timeout + chr(10))
t0 = time.time(); time.sleep(15)
while True:
    st = open(f'{inbox}/watcher_status.txt').read()
    if st.startswith('IDLE') and os.path.exists(f'{outd}/status.txt') and time.time() - t0 > 30: break
    if time.time() - t0 > (int(timeout) + 10) * 60: sys.exit('probe timeout')
    time.sleep(10)
status = open(f'{outd}/status.txt').read().strip().splitlines()[-1]
keep = f'{inbox}/probe_{name}'
if os.path.isdir(keep): shutil.rmtree(keep)
shutil.copytree(outd, keep, ignore=shutil.ignore_patterns('*.exe', 'dsmodel*.c'))
nfail = 0; last = ''
try:
    L = open(f'{keep}/dslog.txt', errors='replace').read().splitlines()
    nfail = sum('Failed to solve nonlinear' in x for x in L)
    last = next((x for x in L if 'Integration terminated' in x), '')
except Exception: pass

def salvage_time(p):
    """Last simulated time in a (possibly killed, so unreadable by scipy) Dymola result.mat."""
    import struct, numpy as np
    sz = os.path.getsize(p); f = open(p, 'rb'); pos = 0
    while pos < sz - 20:
        f.seek(pos); typ, m, n, imag, nl = struct.unpack('<5i', f.read(20))
        nm = f.read(nl).split(bytes([0]))[0].decode(); P = (typ // 10) % 10
        data = pos + 20 + nl
        if nm == 'data_2':
            npts = (sz - data) // (m * 4); f.seek(data + (npts - 1) * m * 4)
            return float(np.fromfile(f, dtype='<f4', count=1)[0]), npts
        pos = data + m * n * {0: 8, 1: 4, 2: 4, 3: 2, 4: 2, 5: 1}[P]
    return None, 0
try: tl, npts = salvage_time(f'{keep}/result.mat')
except Exception as e: tl, npts = None, 0
print(f'PROBE {name}: {status} | {(time.time()-t0)/60:.1f} min | newton failures {nfail} | reached t={tl} s ({npts} pts) | {last}', flush=True)
