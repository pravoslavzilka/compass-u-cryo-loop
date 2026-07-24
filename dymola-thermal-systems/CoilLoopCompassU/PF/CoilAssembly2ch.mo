within CoilLoopCompassU.PF;
model CoilAssembly2ch
  outer ThermalSystems.SystemInformationManager sim;

  record ChannelSummary
    Modelica.Units.SI.Temperature T_wall "Coil wall temperature";
    Modelica.Units.SI.Temperature T_gas_out "Helium outlet temperature";
    Modelica.Units.SI.Temperature T_gas_in "Helium inlet temperature";
    Modelica.Units.SI.MassFlowRate m_flow "Coil mass flow";
    Modelica.Units.SI.Length length "Tube length used for this channel";
    Modelica.Units.SI.Diameter diameter "Tube inner diameter used for this channel";
  end ChannelSummary;

  parameter Modelica.Units.SI.Length lengths[2] = {90,75} "Per-channel tube length [m] (Channel1, Channel2)";
  parameter Real diameters_mm[2](each unit="mm") = {7,7} "Per-channel tube inner diameter [mm] (Channel1, Channel2)";
  parameter Modelica.Units.SI.Power dischargeLoads[2] = {50000,50000} "Per-channel peak discharge heat [W] (Channel1, Channel2)";
  parameter Modelica.Units.SI.Time pulseStart = 10 "Discharge start time (after fan finishes accelerating)";
  parameter Modelica.Units.SI.Time pulseEnd = 15 "Discharge end time (5s heat shock)";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1)";
  parameter Real valveKvNominal = 100 "Kv value at fully-open (valveOpening=1)";
  parameter Modelica.Units.SI.Temperature TInitial = 80 "Initial coil/gas temperature";
  parameter Integer assemblyIndex = 0
    "Unique index of this coil-assembly instance among all assemblies in the circuit (no physical meaning, only makes the anti-degeneracy offset below unique circuit-wide instead of just within this instance)";

  final parameter Modelica.Units.SI.Diameter diameters[2] = diameters_mm*1e-3 "Per-channel tube inner diameter, converted to m";
  final parameter Modelica.Units.SI.Length lengthsAdjusted[2] = {lengths[i]*(1 + 1e-5*(10*assemblyIndex + i)) for i in 1:2}
    "Per-channel length with a tiny (<=0.09%) offset, unique per (assemblyIndex, channel) pair, so no two branches anywhere in the circuit are numerically identical and create a degenerate flow split";

  output Modelica.Units.SI.Temperature T_gas_out = sensor_T.sensorValue
    "Coil assembly gas outlet temperature";

  output ChannelSummary Channel1(
    T_wall=tube2.heatPort[1].T,
    T_gas_out=tube2.summary.T_gas_B,
    T_gas_in=tube2.summary.T_gas_A,
    m_flow=tube2.summary.m_flow_gas_B,
    length=lengthsAdjusted[1],
    diameter=diameters[1]) "Channel 1 summary (tube2 branch)";
  output ChannelSummary Channel2(
    T_wall=tube1.heatPort[1].T,
    T_gas_out=tube1.summary.T_gas_B,
    T_gas_in=tube1.summary.T_gas_A,
    m_flow=tube1.summary.m_flow_gas_B,
    length=lengthsAdjusted[2],
    diameter=diameters[2]) "Channel 2 summary (tube1 branch)";

  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow
    annotation (Placement(transformation(extent={{16,74},{36,94}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[1],0})
    annotation (Placement(transformation(extent={{-20,78},{-8,90}})));
  ThermalSystems.GasComponents.Tubes.Tube tube2(
    tubeGeometry(
      innerDiameter=diameters[1],
      length=lengthsAdjusted[1],
      nParallelTubes=1,
      wallThickness=0.00488,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    nCells=1,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    redeclare model WallMaterial = CoilLoopCompassU.Common.CopperOFHC_Tdep,
    fixedTInitialWall=true,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=4000000,
    TInitial(displayUnit="K") = TInitial,
    TInitialWall(displayUnit="K") = TInitial)
    annotation (Placement(transformation(extent={{32,18},{48,22}})));
  ThermalSystems.GasComponents.Valves.Valve valve1(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=valveOpening*valveKvNominal)
    annotation (Placement(transformation(extent={{-38,-2},{-28,4}})));
  ThermalSystems.Connectors.GasPort portA1(gasType(
      ID=sim.gasType1.ID,
      fixedMixingRatio=sim.gasType1.fixedMixingRatio,
      nc_propertyCalculation=sim.gasType1.nc_propertyCalculation,
      gasNames=sim.gasType1.gasNames,
      mixingRatio_propertyCalculation=sim.gasType1.mixingRatio_propertyCalculation,
      condensingIndex=sim.gasType1.condensingIndex))
                  "portA"
    annotation (Placement(transformation(extent={{-138,-10},{-118,10}})));
  ThermalSystems.Connectors.GasPort portB1(gasType(
      ID=sim.gasType1.ID,
      fixedMixingRatio=sim.gasType1.fixedMixingRatio,
      nc_propertyCalculation=sim.gasType1.nc_propertyCalculation,
      gasNames=sim.gasType1.gasNames,
      mixingRatio_propertyCalculation=sim.gasType1.mixingRatio_propertyCalculation,
      condensingIndex=sim.gasType1.condensingIndex))
    annotation (Placement(transformation(extent={{94,-12},{114,8}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction2(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={20,0})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow1
    annotation (Placement(transformation(extent={{4,52},{24,72}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource1(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[2],0})
    annotation (Placement(transformation(extent={{-32,56},{-20,68}})));
  ThermalSystems.GasComponents.Tubes.Tube tube1(
    tubeGeometry(
      innerDiameter=diameters[2],
      length=lengthsAdjusted[2],
      nParallelTubes=1,
      wallThickness=0.00488,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    nCells=1,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    redeclare model WallMaterial = CoilLoopCompassU.Common.CopperOFHC_Tdep,
    fixedTInitialWall=true,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=4000000,
    TInitial(displayUnit="K") = TInitial,
    TInitialWall(displayUnit="K") = TInitial)
    annotation (Placement(transformation(extent={{32,-22},{48,-18}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={60,0})));
  ThermalSystems.GasComponents.Sensors.Sensor_T sensor_T
    annotation (Placement(transformation(extent={{76,16},{84,24}})));
equation
  connect(stepSource.y, prescribedHeatFlow.Q_flow)
    annotation (Line(points={{-7,84},{16,84}}, color={0,0,127}));
  connect(prescribedHeatFlow.port, tube2.heatPort[1])
    annotation (Line(points={{36,84},{40,84},{40,21.55}},
                                                       color={191,0,0}));
  connect(valve1.portA, portA1) annotation (Line(
      points={{-38,1},{-114,1},{-114,0},{-128,0}},
      color={255,153,0},
      thickness=0.5));
  connect(stepSource1.y, prescribedHeatFlow1.Q_flow)
    annotation (Line(points={{-19,62},{4,62}},   color={0,0,127}));
  connect(prescribedHeatFlow1.port, tube1.heatPort[1]) annotation (Line(points={{24,62},
          {28,62},{28,-14},{40,-14},{40,-18.45}},    color={191,0,0}));
  connect(junction2.portC, tube2.portA) annotation (Line(
      points={{20,4},{20,20},{32,20}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portA, tube1.portA) annotation (Line(
      points={{20,-4},{20,-20},{32,-20}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portB, valve1.portB) annotation (Line(
      points={{16,0},{-22,0},{-22,1},{-28,1}},
      color={255,153,0},
      thickness=0.5));
  connect(tube2.portB, junction1.portA) annotation (Line(
      points={{48,20},{60,20},{60,4}},
      color={255,153,0},
      thickness=0.5));
  connect(tube1.portB, junction1.portC) annotation (Line(
      points={{48,-20},{60,-20},{60,-4}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portB, portB1) annotation (Line(
      points={{64,0},{90,0},{90,-2},{104,-2}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portB, sensor_T.port) annotation (Line(
      points={{64,0},{80,0},{80,16}},
      color={255,153,0},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end CoilAssembly2ch;
