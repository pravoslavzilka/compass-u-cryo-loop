"""Run CS for every scenario in data/working_scenarios/model_coil_start.csv through the VM watcher,
one after another, and save each run under data/CS/working_scenarios/<scenario>/.
usage: run_cs_scenarios.py [scenario-name ...]   (default: all not yet saved)"""
import csv, os, sys, time, shutil, subprocess
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..'))
CS = ['CS1', 'CS2U', 'CS2L', 'CS3U', 'CS3L']
rows = list(csv.DictReader(open(f'{ROOT}/data/working_scenarios/model_coil_start.csv')))
scen = []
for r in rows:
    if r['scenario'] not in scen: scen.append(r['scenario'])
todo = sys.argv[1:] or scen
MOS = '''root  := "Z:/compass-u-cryo-loop";
outd  := root + "/vm-inbox/cs_scen";
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
ok := translateModel("CoilLoopCompassU.CS.CSCircuit(TInitialCoilCS={%s})");
savelog(outd + "/log.txt");
if not ok then
  Modelica.Utilities.Streams.print("FAIL: translation", st);
  Modelica.Utilities.Streams.print(getLastErrorLog(), outd + "/last_error.txt");
else
  Modelica.Utilities.Streams.print("RUNNING: simulate 1800 s", st);
  OutputCPUtime := true;
  simOk := simulateModel("CoilLoopCompassU.CS.CSCircuit(TInitialCoilCS={%s})", stopTime=1800, tolerance=1e-4,
                         resultFile=outd + "/result");
  savelog(outd + "/log.txt");
  if simOk then
    Modelica.Utilities.Streams.print("OK: simulated 1800 s", st);
  else
    Modelica.Utilities.Streams.print("FAIL: simulation", st);
    Modelica.Utilities.Streams.print(getLastErrorLog(), outd + "/last_error.txt");
  end if;
end if;
'''
inbox = f'{ROOT}/vm-inbox'
for name in todo:
    dest = f'{ROOT}/data/CS/working_scenarios/{name}'
    if os.path.exists(f'{dest}/summary.json') and not sys.argv[1:]:
        print('skip (saved):', name); continue
    T = {r['model_coil']: r['T_start_energy_conserving_K'] for r in rows if r['scenario'] == name}
    vec = ', '.join(T[c] for c in CS)
    print(name, vec, flush=True)
    outd = f'{inbox}/cs_scen'
    if os.path.isdir(outd): shutil.rmtree(outd)
    os.makedirs(outd)
    open(f'{ROOT}/tools/vm/cs_scen.mos', 'w').write(MOS % (vec, vec))
    open(f'{inbox}/run.request', 'w').write('script=tools/vm/cs_scen.mos\ntimeout_min=90\n')
    t0 = time.time()
    time.sleep(15)
    while True:
        st = open(f'{inbox}/watcher_status.txt').read()
        if st.startswith('IDLE') and os.path.exists(f'{outd}/status.txt') and time.time() - t0 > 30: break
        if time.time() - t0 > 95 * 60: sys.exit('timeout ' + name)
        time.sleep(10)
    status = open(f'{outd}/status.txt').read()
    print('  status:', status.strip().splitlines()[-1], f'({(time.time()-t0)/60:.1f} min)', flush=True)
    if 'OK' not in status: print('  FAILED, see', outd); continue
    os.makedirs(dest, exist_ok=True)
    shutil.copy(f'{outd}/result.mat', f'{dest}/{name}.mat')
    for f in ('dsin.txt', 'dslog.txt'): shutil.copy(f'{outd}/{f}', dest)
    shutil.copy(f'{ROOT}/dymola-thermal-systems/CoilLoopCompassU/CS/CSCircuit.mo', f'{dest}/CSCircuit.mo.snapshot')
    shutil.copy(f'{ROOT}/tools/vm/cs_scen.mos', f'{dest}/cs_scen.mos')
    subprocess.run([sys.executable, f'{ROOT}/tools/scenarios/summarize_cs_run.py', f'{dest}/{name}.mat', dest, name],
                   stdout=subprocess.DEVNULL, check=True)
    print('  saved', dest, flush=True)
