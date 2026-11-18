"""Run PF for every scenario in data/working_scenarios/model_coil_start.csv through the VM watcher,
one after another, and save each run under data/PF/working_scenarios/<scenario>/.
usage: run_cs_scenarios.py [scenario-name ...]   (default: all not yet saved)"""
import csv, os, sys, time, shutil, subprocess
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..'))
PF = ['PF1U','PF1L','PF2U','PF2L','PF3U','PF3L','PF4U','PF4L']
FLAGS = {'enableCoilIsolation': 'true', 'enableCirculatorPowerOptimization': 'true', 'enablePressureControl': 'true',
         'enableOverCoolPrevention': 'true', 'enableOverCoolRecovery': 'true'}
TAG = 'working_scenarios'
ARGS = []
for a in sys.argv[1:]:
    if a.startswith('--tag='): TAG = a[6:]          # results go to data/PF/<tag>/<scenario>/
    elif a.startswith('--set='):                      # --set=param=value, adds/overrides a model parameter
        k, v = a[6:].split('=', 1); FLAGS[k] = v
    else: ARGS.append(a)
ALGO = ', '.join('%s=%s' % kv for kv in FLAGS.items())
rows = list(csv.DictReader(open(f'{ROOT}/data/working_scenarios/model_coil_start.csv')))
scen = []
for r in rows:
    if r['scenario'] not in scen: scen.append(r['scenario'])
todo = ARGS or scen
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
  Modelica.Utilities.Streams.print("RUNNING: simulate 1815 s", st);
  OutputCPUtime := true;
  simOk := simulateModel("CoilLoopCompassU.PF.PFCircuit(%s)", stopTime=1815, tolerance=1e-4,
                         resultFile=outd + "/result");
  savelog(outd + "/log.txt");
  if simOk then
    Modelica.Utilities.Streams.print("OK: simulated 1815 s", st);
  else
    Modelica.Utilities.Streams.print("FAIL: simulation", st);
    Modelica.Utilities.Streams.print(getLastErrorLog(), outd + "/last_error.txt");
  end if;
end if;
'''
inbox = f'{ROOT}/vm-inbox'
for name in todo:
    dest = f'{ROOT}/data/PF/{TAG}/{name}'
    if os.path.exists(f'{dest}/summary.json') and not ARGS:
        print('skip (saved):', name); continue
    T = {r['model_coil']: r['T_start_energy_conserving_K'] for r in rows if r['scenario'] == name}
    vec = ALGO + ', ' + ', '.join('%s(TInitial=%s)' % (c, T[c]) for c in PF)
    print(name, vec, flush=True)
    outd = f'{inbox}/pf_scen'
    if os.path.isdir(outd): shutil.rmtree(outd)
    os.makedirs(outd)
    open(f'{ROOT}/tools/vm/pf_scen.mos', 'w').write(MOS % (vec, vec))
    open(f'{inbox}/run.request', 'w').write('script=tools/vm/pf_scen.mos\ntimeout_min=100\n')
    t0 = time.time()
    time.sleep(15)
    while True:
        st = open(f'{inbox}/watcher_status.txt').read()
        if st.startswith('IDLE') and os.path.exists(f'{outd}/status.txt') and time.time() - t0 > 30: break
        if time.time() - t0 > 110 * 60: sys.exit('timeout ' + name)
        time.sleep(10)
    status = open(f'{outd}/status.txt').read()
    print('  status:', status.strip().splitlines()[-1], f'({(time.time()-t0)/60:.1f} min)', flush=True)
    if 'OK' not in status:
        keep = f'{inbox}/failed_{name}'
        if os.path.isdir(keep): shutil.rmtree(keep)
        shutil.copytree(outd, keep, ignore=shutil.ignore_patterns('*.exe'))
        print('  FAILED, logs kept in', keep, flush=True); continue
    os.makedirs(dest, exist_ok=True)
    shutil.copy(f'{outd}/result.mat', f'{dest}/{name}.mat')
    for f in ('dsin.txt', 'dslog.txt'): shutil.copy(f'{outd}/{f}', dest)
    shutil.copy(f'{ROOT}/dymola-thermal-systems/CoilLoopCompassU/PF/PFCircuit.mo', f'{dest}/PFCircuit.mo.snapshot')
    shutil.copy(f'{ROOT}/tools/vm/pf_scen.mos', f'{dest}/pf_scen.mos')
    subprocess.run([sys.executable, f'{ROOT}/tools/scenarios/summarize_pf_run.py', f'{dest}/{name}.mat', dest, name],
                   stdout=subprocess.DEVNULL, check=True)
    print('  saved', dest, flush=True)
