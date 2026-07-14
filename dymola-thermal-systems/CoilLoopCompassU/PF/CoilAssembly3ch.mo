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
  parameter Modelica.Units.SI.Time pulseStart = 5 "Discharge start time";
  parameter Modelica.Units.SI.Time pulseEnd = 10 "Discharge end time";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1)";
  parameter Real valveKvNominal = 100 "Kv value at fully-open (valveOpening=1)";
  parameter Modelica.Units.SI.Temperature TInitial = 80 "Initial coil/gas temperature";

  final parameter Modelica.Units.SI.Diameter diameters[3] = diameters_mm*1e-3 "Per-channel tube inner diameter, converted to m";

  output ChannelSummary Channel1(
    T_wall=tube2.heatPort[1].T,
    T_gas_out=tube2.summary.T_gas_B,
    T_gas_in=tube2.summary.T_gas_A,
    m_flow=tube2.summary.m_flow_gas_B,
    length=lengths[1],
    diameter=diameters[1]) "Channel 1 summary (tube2 branch)";
  output ChannelSummary Channel2(
    T_wall=tube1.heatPort[1].T,
    T_gas_out=tube1.summary.T_gas_B,
    T_gas_in=tube1.summary.T_gas_A,
    m_flow=tube1.summary.m_flow_gas_B,
    length=lengths[2],
    diameter=diameters[2]) "Channel 2 summary (tube1 branch)";
  output ChannelSummary Channel3(
    T_wall=tube3.heatPort[1].T,
    T_gas_out=tube3.summary.T_gas_B,
    T_gas_in=tube3.summary.T_gas_A,
    m_flow=tube3.summary.m_flow_gas_B,
    length=lengths[3],
    diameter=diameters[3]) "Channel 3 summary (tube3 branch)";

  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow
    annotation (Placement(transformation(extent={{-48,88},{-28,108}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[1],0})
    annotation (Placement(transformation(extent={{-84,92},{-72,104}})));
  ThermalSystems.GasComponents.Tubes.Tube tube2(
    tubeGeometry(
      innerDiameter=diameters[1],
      length=lengths[1],
      nParallelTubes=1,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    fixedTInitialWall=false,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=4000000,
    TInitial(displayUnit="K") = TInitial,
    TInitialWall(displayUnit="K") = TInitial)
    annotation (Placement(transformation(extent={{32,52},{48,56}})));
  ThermalSystems.GasComponents.Valves.Valve valve1(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=valveOpening*valveKvNominal)
    annotation (Placement(transformation(extent={{-84,32},{-74,38}})));
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
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={-24,26})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={0,44})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow1
    annotation (Placement(transformation(extent={{-48,68},{-28,88}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource1(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[2],0})
    annotation (Placement(transformation(extent={{-84,72},{-72,84}})));
  ThermalSystems.GasComponents.Tubes.Tube tube1(
    tubeGeometry(
      innerDiameter=diameters[2],
      length=lengths[2],
      nParallelTubes=1,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    fixedTInitialWall=false,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=4000000,
    TInitial(displayUnit="K") = TInitial,
    TInitialWall(displayUnit="K") = TInitial)
    annotation (Placement(transformation(extent={{32,32},{48,36}})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow2
    annotation (Placement(transformation(extent={{-46,50},{-26,70}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource2(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[3],0})
    annotation (Placement(transformation(extent={{-84,54},{-72,66}})));
  ThermalSystems.GasComponents.Tubes.Tube tube3(
    tubeGeometry(
      innerDiameter=diameters[3],
      length=lengths[3],
      nParallelTubes=1,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    fixedTInitialWall=false,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=4000000,
    TInitial(displayUnit="K") = TInitial,
    TInitialWall(displayUnit="K") = TInitial)
    annotation (Placement(transformation(extent={{32,14},{48,18}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction3(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={68,40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction4(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={58,24})));
equation
  connect(stepSource.y, prescribedHeatFlow.Q_flow)
    annotation (Line(points={{-71,98},{-48,98}},
                                               color={0,0,127}));
  connect(prescribedHeatFlow.port, tube2.heatPort[1])
    annotation (Line(points={{-28,98},{40,98},{40,56}},color={191,0,0}));
  connect(valve1.portA, portA1) annotation (Line(
      points={{-84,35},{-114,35},{-114,0},{-128,0}},
      color={255,153,0},
      thickness=0.5));
  connect(stepSource1.y, prescribedHeatFlow1.Q_flow)
    annotation (Line(points={{-71,78},{-48,78}}, color={0,0,127}));
  connect(prescribedHeatFlow1.port, tube1.heatPort[1]) annotation (Line(points=
          {{-28,78},{26,78},{26,40},{40,40},{40,36}}, color={191,0,0}));
  connect(stepSource2.y, prescribedHeatFlow2.Q_flow)
    annotation (Line(points={{-71,60},{-46,60}}, color={0,0,127}));
  connect(prescribedHeatFlow2.port, tube3.heatPort[1]) annotation (Line(points=
          {{-26,60},{22,60},{22,24},{40,24},{40,18}}, color={191,0,0}));
  connect(junction1.portC, tube2.portA) annotation (Line(
      points={{0,48},{14,48},{14,54},{32,54}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portA, tube1.portA) annotation (Line(
      points={{0,40},{14,40},{14,30},{32,30},{32,34}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portC, junction1.portB) annotation (Line(
      points={{-24,30},{-24,44},{-4,44}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portA, tube3.portA) annotation (Line(
      points={{-24,22},{2,22},{2,14},{32,14},{32,16}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portB, valve1.portB) annotation (Line(
      points={{-28,26},{-46,26},{-46,35},{-74,35}},
      color={255,153,0},
      thickness=0.5));
  connect(junction4.portC, tube3.portB) annotation (Line(
      points={{58,20},{58,16},{48,16}},
      color={255,153,0},
      thickness=0.5));
  connect(junction4.portA, tube1.portB) annotation (Line(
      points={{58,28},{56,28},{56,36},{48,36},{48,34}},
      color={255,153,0},
      thickness=0.5));
  connect(tube2.portB, junction3.portA) annotation (Line(
      points={{48,54},{68,54},{68,44}},
      color={255,153,0},
      thickness=0.5));
  connect(junction4.portB, junction3.portC) annotation (Line(
      points={{62,24},{66,24},{66,28},{68,28},{68,36}},
      color={255,153,0},
      thickness=0.5));
  connect(junction3.portB, portB1) annotation (Line(
      points={{72,40},{78,40},{78,2},{76,2},{76,0},{104,0},{104,-2}},
      color={255,153,0},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end CoilAssembly3ch;
