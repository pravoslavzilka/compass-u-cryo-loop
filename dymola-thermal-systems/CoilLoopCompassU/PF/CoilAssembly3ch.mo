within CoilLoopCompassU.PF;
model CoilAssembly3ch
  outer ThermalSystems.SystemInformationManager sim;

  record ChannelSummary
    Modelica.Units.SI.Temperature T_wall "Coil wall temperature";
    Modelica.Units.SI.Temperature T_gas_out "Helium outlet temperature";
    Modelica.Units.SI.Temperature T_gas_in "Helium inlet temperature";
    Modelica.Units.SI.MassFlowRate m_flow "Coil mass flow";
    Modelica.Units.SI.Length length "Tube length used for this channel";
    Modelica.Units.SI.Diameter diameter "Tube inner diameter used for this channel";
  end ChannelSummary;

  parameter Modelica.Units.SI.Length lengths[3] = {90,75,60} "Per-channel tube length [m] (Channel1, Channel2, Channel3)";
  parameter Real diameters_mm[3](each unit="mm") = {7,7,7} "Per-channel tube inner diameter [mm] (Channel1, Channel2, Channel3)";
  parameter Modelica.Units.SI.Power dischargeLoads[3] = {50000,50000,50000} "Per-channel peak discharge heat [W] (Channel1, Channel2, Channel3)";
  parameter Modelica.Units.SI.Time pulseStart = 10 "Discharge start time (after fan finishes accelerating)";
  parameter Modelica.Units.SI.Time pulseEnd = 15 "Discharge end time (5s heat shock)";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1)";
  parameter Real valveKvNominal = 100 "Kv value at fully-open (valveOpening=1)";
  parameter Modelica.Units.SI.Temperature TInitial = 80 "Initial coil/gas temperature";
  parameter Integer assemblyIndex = 0
    "Unique index of this coil-assembly instance among all assemblies in the circuit (no physical meaning, only makes the anti-degeneracy offset below unique circuit-wide instead of just within this instance)";

  final parameter Modelica.Units.SI.Diameter diameters[3] = diameters_mm*1e-3 "Per-channel tube inner diameter, converted to m";
  final parameter Modelica.Units.SI.Length lengthsAdjusted[3] = {lengths[i]*(1 + 1e-5*(10*assemblyIndex + i)) for i in 1:3}
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
  output ChannelSummary Channel3(
    T_wall=tube3.heatPort[1].T,
    T_gas_out=tube3.summary.T_gas_B,
    T_gas_in=tube3.summary.T_gas_A,
    m_flow=tube3.summary.m_flow_gas_B,
    length=lengthsAdjusted[3],
    diameter=diameters[3]) "Channel 3 summary (tube3 branch)";

  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow
    annotation (Placement(transformation(extent={{-48,74},{-28,94}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[1],0})
    annotation (Placement(transformation(extent={{-84,78},{-72,90}})));
  ThermalSystems.GasComponents.Tubes.Tube tube2(
    tubeGeometry(
      innerDiameter=diameters[1],
      length=lengthsAdjusted[1],
      nParallelTubes=1,
      wallThickness=0.00488,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    redeclare model WallMaterial = TSMedia.SolidTypes.TSMedia_Copper,
    fixedTInitialWall=true,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=4000000,
    TInitial(displayUnit="K") = TInitial,
    TInitialWall(displayUnit="K") = TInitial)
    annotation (Placement(transformation(extent={{32,38},{48,42}})));
  ThermalSystems.GasComponents.Valves.Valve valve1(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=valveOpening*valveKvNominal)
    annotation (Placement(transformation(extent={{-80,-2},{-70,4}})));
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
        rotation=90)));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={20,20})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow1
    annotation (Placement(transformation(extent={{-48,54},{-28,74}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource1(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[2],0})
    annotation (Placement(transformation(extent={{-84,58},{-72,70}})));
  ThermalSystems.GasComponents.Tubes.Tube tube1(
    tubeGeometry(
      innerDiameter=diameters[2],
      length=lengthsAdjusted[2],
      nParallelTubes=1,
      wallThickness=0.00488,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    redeclare model WallMaterial = TSMedia.SolidTypes.TSMedia_Copper,
    fixedTInitialWall=true,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=4000000,
    TInitial(displayUnit="K") = TInitial,
    TInitialWall(displayUnit="K") = TInitial)
    annotation (Placement(transformation(extent={{32,-4},{48,0}})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow2
    annotation (Placement(transformation(extent={{-46,36},{-26,56}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource2(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[3],0})
    annotation (Placement(transformation(extent={{-84,40},{-72,52}})));
  ThermalSystems.GasComponents.Tubes.Tube tube3(
    tubeGeometry(
      innerDiameter=diameters[3],
      length=lengthsAdjusted[3],
      nParallelTubes=1,
      wallThickness=0.00488,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    redeclare model WallMaterial = TSMedia.SolidTypes.TSMedia_Copper,
    fixedTInitialWall=true,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=4000000,
    TInitial(displayUnit="K") = TInitial,
    TInitialWall(displayUnit="K") = TInitial)
    annotation (Placement(transformation(extent={{32,-42},{48,-38}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction3(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={80,20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction4(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={60,-20})));
  ThermalSystems.GasComponents.Sensors.Sensor_T sensor_T
    annotation (Placement(transformation(extent={{88,44},{96,52}})));
equation
  connect(stepSource.y, prescribedHeatFlow.Q_flow)
    annotation (Line(points={{-71,84},{-48,84}},
                                               color={0,0,127}));
  connect(prescribedHeatFlow.port, tube2.heatPort[1])
    annotation (Line(points={{-28,84},{40,84},{40,42}},color={191,0,0}));
  connect(valve1.portA, portA1) annotation (Line(
      points={{-80,1},{-114,1},{-114,0},{-128,0}},
      color={255,153,0},
      thickness=0.5));
  connect(stepSource1.y, prescribedHeatFlow1.Q_flow)
    annotation (Line(points={{-71,64},{-48,64}}, color={0,0,127}));
  connect(prescribedHeatFlow1.port, tube1.heatPort[1]) annotation (Line(points={{-28,64},
          {18,64},{18,38},{40,38},{40,0}},            color={191,0,0}));
  connect(stepSource2.y, prescribedHeatFlow2.Q_flow)
    annotation (Line(points={{-71,46},{-46,46}}, color={0,0,127}));
  connect(prescribedHeatFlow2.port, tube3.heatPort[1]) annotation (Line(points={{-26,46},
          {-22,46},{-22,34},{12,34},{12,-32},{40,-32},{40,-38}},
                                                      color={191,0,0}));
  connect(junction1.portC, tube2.portA) annotation (Line(
      points={{20,24},{20,40},{32,40}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portA, tube1.portA) annotation (Line(
      points={{20,16},{20,-2},{32,-2}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portC, junction1.portB) annotation (Line(
      points={{0,4},{0,20},{16,20}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portA, tube3.portA) annotation (Line(
      points={{0,-4},{0,-40},{32,-40}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portB, valve1.portB) annotation (Line(
      points={{-4,0},{-66,0},{-66,1},{-70,1}},
      color={255,153,0},
      thickness=0.5));
  connect(junction4.portC, tube3.portB) annotation (Line(
      points={{60,-24},{60,-40},{48,-40}},
      color={255,153,0},
      thickness=0.5));
  connect(junction4.portA, tube1.portB) annotation (Line(
      points={{60,-16},{60,-2},{48,-2}},
      color={255,153,0},
      thickness=0.5));
  connect(tube2.portB, junction3.portA) annotation (Line(
      points={{48,40},{80,40},{80,24}},
      color={255,153,0},
      thickness=0.5));
  connect(junction4.portB, junction3.portC) annotation (Line(
      points={{64,-20},{80,-20},{80,16}},
      color={255,153,0},
      thickness=0.5));
  connect(junction3.portB, portB1) annotation (Line(
      points={{84,20},{90,20},{90,-2},{104,-2}},
      color={255,153,0},
      thickness=0.5));
  connect(sensor_T.port, junction3.portB) annotation (Line(
      points={{92,44},{92,20},{84,20}},
      color={255,153,0},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end CoilAssembly3ch;
