"""Chain of PF scenario rounds, started after the 6400 rerun has finished.
 round 1: enableCirculatorPowerOptimization=false  (no power limit)      -> data/PF/working_scenarios_noPowerOpt/
 round 2: staged PFCircuit_speedlimit.mo installed, enableCirculatorPowerOptimization=false,
          enableSpeedPowerLimit=true                                      -> data/PF/working_scenarios_speedPowerLimit/
usage: pipeline_pf_rounds.py <log of the running run_pf_scenarios.py to wait for>"""
import os, sys, time, shutil, subprocess
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..'))
log = sys.argv[1]
def say(m): print(time.strftime('%H:%M:%S'), m, flush=True)
say('waiting for ' + log)
while True:
    txt = open(log, errors='replace').read() if os.path.exists(log) else ''
    if 'saved' in txt or 'FAILED' in txt: break
    time.sleep(20)
say('previous run finished; letting the watcher settle')
time.sleep(60)
run = [sys.executable, f'{ROOT}/tools/scenarios/run_pf_scenarios.py']
say('ROUND 1: power optimisation off')
subprocess.run(run + ['--tag=working_scenarios_noPowerOpt', '--set=enableCirculatorPowerOptimization=false'])
say('installing staged speed-limit model')
mo = f'{ROOT}/dymola-thermal-systems/CoilLoopCompassU/PF/PFCircuit.mo'
shutil.copy(mo, f'{ROOT}/tools/scenarios/staged/PFCircuit_before_speedlimit.mo.bak')
shutil.copy(f'{ROOT}/tools/scenarios/staged/PFCircuit_speedlimit.mo', mo)
say('ROUND 2: speed power limit on')
subprocess.run(run + ['--tag=working_scenarios_speedPowerLimit', '--set=enableCirculatorPowerOptimization=false',
                      '--set=enableSpeedPowerLimit=true'])
say('PIPELINE DONE')
