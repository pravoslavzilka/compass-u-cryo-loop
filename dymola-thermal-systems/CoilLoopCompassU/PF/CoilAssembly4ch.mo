within CoilLoopCompassU.PF;
model CoilAssembly4ch
  outer ThermalSystems.SystemInformationManager sim;

  record ChannelSummary
    Modelica.Units.SI.Temperature T_wall "Coil wall temperature";
    Modelica.Units.SI.Temperature T_gas_out "Helium outlet temperature";
    Modelica.Units.SI.Temperature T_gas_in "Helium inlet temperature";
    Modelica.Units.SI.MassFlowRate m_flow "Coil mass flow";
    Modelica.Units.SI.Length length "Tube length used for this channel";
    Modelica.Units.SI.Diameter diameter "Tube inner diameter used for this channel";
  end ChannelSummary;

  parameter Modelica.Units.SI.Length lengths[4] = {90,75,60,50} "Per-channel tube length [m] (Channel1..Channel4)";
  parameter Real diameters_mm[4](each unit="mm") = {7,7,7,7} "Per-channel tube inner diameter [mm] (Channel1..Channel4)";
  parameter Modelica.Units.SI.Power dischargeLoads[4] = {50000,50000,50000,50000} "Per-channel peak discharge heat [W] (Channel1..Channel4)";
  parameter Modelica.Units.SI.Time pulseStart = 5 "Discharge start time";
  parameter Modelica.Units.SI.Time pulseEnd = 10 "Discharge end time";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1)";
  parameter Real valveKvNominal = 100 "Kv value at fully-open (valveOpening=1)";
  parameter Modelica.Units.SI.Temperature TInitial = 80 "Initial coil/gas temperature";

  final parameter Modelica.Units.SI.Diameter diameters[4] = diameters_mm*1e-3 "Per-channel tube inner diameter, converted to m";

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
  output ChannelSummary Channel4(
    T_wall=tube4.heatPort[1].T,
    T_gas_out=tube4.summary.T_gas_B,
    T_gas_in=tube4.summary.T_gas_A,
    m_flow=tube4.summary.m_flow_gas_B,
    length=lengths[4],
    diameter=diameters[4]) "Channel 4 summary (tube4 branch)";

  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow
    annotation (Placement(transformation(extent={{-24,72},{-4,92}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[1],0})
    annotation (Placement(transformation(extent={{-60,76},{-48,88}})));
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
    annotation (Placement(transformation(extent={{18,22},{34,26}})));
  ThermalSystems.GasComponents.Valves.Valve valve1(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=valveOpening*valveKvNominal)
    annotation (Placement(transformation(extent={{-86,-2},{-76,4}})));
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
        origin={-46,0})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow1
    annotation (Placement(transformation(extent={{-24,58},{-4,78}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource1(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[2],0})
    annotation (Placement(transformation(extent={{-60,62},{-48,74}})));
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
    annotation (Placement(transformation(extent={{18,8},{34,12}})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow2
    annotation (Placement(transformation(extent={{-24,46},{-4,66}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource2(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[3],0})
    annotation (Placement(transformation(extent={{-60,50},{-48,62}})));
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
    annotation (Placement(transformation(extent={{18,-4},{34,0}})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow3
    annotation (Placement(transformation(extent={{-24,32},{-4,52}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource3(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[4],0})
    annotation (Placement(transformation(extent={{-60,36},{-48,48}})));
  ThermalSystems.GasComponents.Tubes.Tube tube4(
    tubeGeometry(
      innerDiameter=diameters[4],
      length=lengths[4],
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
    annotation (Placement(transformation(extent={{18,-18},{34,-14}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={-8,-8})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction3(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={-14,18})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction4(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={50,18})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction5(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={50,-10})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction6(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={76,0})));
equation
  connect(stepSource.y, prescribedHeatFlow.Q_flow)
    annotation (Line(points={{-47,82},{-24,82}},
                                               color={0,0,127}));
  connect(prescribedHeatFlow.port, tube2.heatPort[1])
    annotation (Line(points={{-4,82},{26,82},{26,26}}, color={191,0,0}));
  connect(stepSource1.y, prescribedHeatFlow1.Q_flow)
    annotation (Line(points={{-47,68},{-24,68}}, color={0,0,127}));
  connect(prescribedHeatFlow1.port, tube1.heatPort[1]) annotation (Line(points=
          {{-4,68},{12,68},{12,16},{26,16},{26,12}}, color={191,0,0}));
  connect(stepSource2.y, prescribedHeatFlow2.Q_flow)
    annotation (Line(points={{-47,56},{-24,56}}, color={0,0,127}));
  connect(prescribedHeatFlow2.port, tube3.heatPort[1]) annotation (Line(points=
          {{-4,56},{10,56},{10,4},{26,4},{26,0}}, color={191,0,0}));
  connect(stepSource3.y, prescribedHeatFlow3.Q_flow)
    annotation (Line(points={{-47,42},{-24,42}}, color={0,0,127}));
  connect(prescribedHeatFlow3.port, tube4.heatPort[1]) annotation (Line(points=
          {{-4,42},{8,42},{8,-8},{26,-8},{26,-14}}, color={191,0,0}));
  connect(junction2.portC, junction3.portB) annotation (Line(
      points={{-46,4},{-42,4},{-42,16},{-18,16},{-18,18}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portA, junction1.portB) annotation (Line(
      points={{-46,-4},{-38,-4},{-38,-8},{-12,-8}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portC, tube3.portA) annotation (Line(
      points={{-8,-4},{-8,-2},{18,-2}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portA, tube4.portA) annotation (Line(
      points={{-8,-12},{-8,-16},{18,-16}},
      color={255,153,0},
      thickness=0.5));
  connect(junction3.portC, tube2.portA) annotation (Line(
      points={{-14,22},{-8,22},{-8,24},{18,24}},
      color={255,153,0},
      thickness=0.5));
  connect(junction3.portA, tube1.portA) annotation (Line(
      points={{-14,14},{-4,14},{-4,10},{18,10}},
      color={255,153,0},
      thickness=0.5));
  connect(valve1.portB, junction2.portB) annotation (Line(
      points={{-76,1},{-54,1},{-54,0},{-50,0}},
      color={255,153,0},
      thickness=0.5));
  connect(valve1.portA, portA1) annotation (Line(
      points={{-86,1},{-114,1},{-114,0},{-128,0}},
      color={255,153,0},
      thickness=0.5));
  connect(tube3.portB, junction5.portA) annotation (Line(
      points={{34,-2},{50,-2},{50,-6}},
      color={255,153,0},
      thickness=0.5));
  connect(tube4.portB, junction5.portC) annotation (Line(
      points={{34,-16},{42,-16},{42,-18},{50,-18},{50,-14}},
      color={255,153,0},
      thickness=0.5));
  connect(tube1.portB, junction4.portC) annotation (Line(
      points={{34,10},{50,10},{50,14}},
      color={255,153,0},
      thickness=0.5));
  connect(tube2.portB, junction4.portA) annotation (Line(
      points={{34,24},{40,24},{40,26},{50,26},{50,22}},
      color={255,153,0},
      thickness=0.5));
  connect(junction4.portB, junction6.portA) annotation (Line(
      points={{54,18},{64,18},{64,14},{76,14},{76,4}},
      color={255,153,0},
      thickness=0.5));
  connect(junction5.portB, junction6.portC) annotation (Line(
      points={{54,-10},{62,-10},{62,-4},{76,-4}},
      color={255,153,0},
      thickness=0.5));
  connect(junction6.portB, portB1) annotation (Line(
      points={{80,0},{92,0},{92,-2},{104,-2}},
      color={255,153,0},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end CoilAssembly4ch;
