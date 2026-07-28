from fmpy import dump, simulate_fmu
dump('CoilLoopCompassU_PF_PFCircuit.fmu')          # prints interface: inputs, outputs, params
result = simulate_fmu('CoilLoopCompassU_PF_PFCircuit.fmu', stop_time=60)  # does it actually run?