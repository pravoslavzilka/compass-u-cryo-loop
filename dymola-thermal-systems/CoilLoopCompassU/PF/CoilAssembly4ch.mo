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
  parameter Modelica.Units.SI.Length wallThickness = 0.00488 "Tube wall thickness, same for all 4 channels";
  parameter Modelica.Units.SI.Power dischargeLoads[4] = {50000,50000,50000,50000} "Per-channel peak discharge heat [W] (Channel1..Channel4)";
  parameter Modelica.Units.SI.Time pulseStart = 10 "Discharge start time (after fan finishes accelerating)";
  parameter Modelica.Units.SI.Time pulseEnd = 15 "Discharge end time (5s heat shock)";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1)";
  parameter Real valveKvNominal = 100 "Kv value at fully-open (valveOpening=1)";
  parameter Modelica.Units.SI.Temperature TInitial = 80 "Initial coil/gas temperature";
  parameter Integer assemblyIndex = 0
    "Unique index of this coil-assembly instance among all assemblies in the circuit (no physical meaning, only makes the anti-degeneracy offset below unique circuit-wide instead of just within this instance)";

  final parameter Modelica.Units.SI.Diameter diameters[4] = diameters_mm*1e-3 "Per-channel tube inner diameter, converted to m";
  final parameter Modelica.Units.SI.Length lengthsAdjusted[4] = {lengths[i]*(1 + 1e-5*(10*assemblyIndex + i)) for i in 1:4}
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
  output ChannelSummary Channel4(
    T_wall=tube4.heatPort[1].T,
    T_gas_out=tube4.summary.T_gas_B,
    T_gas_in=tube4.summary.T_gas_A,
    m_flow=tube4.summary.m_flow_gas_B,
    length=lengthsAdjusted[4],
    diameter=diameters[4]) "Channel 4 summary (tube4 branch)";

  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow
    annotation (Placement(transformation(extent={{-50,76},{-30,96}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[1],0})
    annotation (Placement(transformation(extent={{-86,80},{-74,92}})));
  ThermalSystems.GasComponents.Tubes.Tube tube2(
    tubeGeometry(
      innerDiameter=diameters[1],
      length=lengthsAdjusted[1],
      nParallelTubes=1,
      wallThickness=wallThickness,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
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
    annotation (Placement(transformation(extent={{14,38},{30,42}})));
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
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={-40,0})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow1
    annotation (Placement(transformation(extent={{-50,62},{-30,82}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource1(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[2],0})
    annotation (Placement(transformation(extent={{-86,66},{-74,78}})));
  ThermalSystems.GasComponents.Tubes.Tube tube1(
    tubeGeometry(
      innerDiameter=diameters[2],
      length=lengthsAdjusted[2],
      nParallelTubes=1,
      wallThickness=wallThickness,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
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
    annotation (Placement(transformation(extent={{12,-2},{28,2}})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow2
    annotation (Placement(transformation(extent={{-50,50},{-30,70}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource2(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[3],0})
    annotation (Placement(transformation(extent={{-86,54},{-74,66}})));
  ThermalSystems.GasComponents.Tubes.Tube tube3(
    tubeGeometry(
      innerDiameter=diameters[3],
      length=lengthsAdjusted[3],
      nParallelTubes=1,
      wallThickness=wallThickness,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
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
    annotation (Placement(transformation(extent={{12,-22},{28,-18}})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow3
    annotation (Placement(transformation(extent={{-50,36},{-30,56}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource3(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[4],0})
    annotation (Placement(transformation(extent={{-86,40},{-74,52}})));
  ThermalSystems.GasComponents.Tubes.Tube tube4(
    tubeGeometry(
      innerDiameter=diameters[4],
      length=lengthsAdjusted[4],
      nParallelTubes=1,
      wallThickness=wallThickness,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
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
    annotation (Placement(transformation(extent={{12,-62},{28,-58}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={0,-40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction3(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={0,20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction4(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={40,20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction5(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={40,-40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction6(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={80,-2})));
  ThermalSystems.GasComponents.Sensors.Sensor_T sensor_T
    annotation (Placement(transformation(extent={{86,28},{94,36}})));
equation
  connect(stepSource.y, prescribedHeatFlow.Q_flow)
    annotation (Line(points={{-73,86},{-50,86}},
                                               color={0,0,127}));
  connect(prescribedHeatFlow.port, tube2.heatPort[1])
    annotation (Line(points={{-30,86},{22,86},{22,42}},color={191,0,0}));
  connect(stepSource1.y, prescribedHeatFlow1.Q_flow)
    annotation (Line(points={{-73,72},{-50,72}}, color={0,0,127}));
  connect(prescribedHeatFlow1.port, tube1.heatPort[1]) annotation (Line(points={{-30,72},
          {-24,72},{-24,8},{20,8},{20,2}},           color={191,0,0}));
  connect(stepSource2.y, prescribedHeatFlow2.Q_flow)
    annotation (Line(points={{-73,60},{-50,60}}, color={0,0,127}));
  connect(prescribedHeatFlow2.port, tube3.heatPort[1]) annotation (Line(points={{-30,60},
          {-20,60},{-20,-12},{20,-12},{20,-18}},  color={191,0,0}));
  connect(stepSource3.y, prescribedHeatFlow3.Q_flow)
    annotation (Line(points={{-73,46},{-50,46}}, color={0,0,127}));
  connect(prescribedHeatFlow3.port, tube4.heatPort[1]) annotation (Line(points={{-30,46},
          {-16,46},{-16,-32},{20,-32},{20,-58}},    color={191,0,0}));
  connect(junction2.portC, junction3.portB) annotation (Line(
      points={{-40,4},{-40,20},{-4,20}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portA, junction1.portB) annotation (Line(
      points={{-40,-4},{-40,-40},{-4,-40}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portC, tube3.portA) annotation (Line(
      points={{0,-36},{0,-20},{12,-20}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portA, tube4.portA) annotation (Line(
      points={{0,-44},{0,-60},{12,-60}},
      color={255,153,0},
      thickness=0.5));
  connect(junction3.portC, tube2.portA) annotation (Line(
      points={{0,24},{0,40},{14,40}},
      color={255,153,0},
      thickness=0.5));
  connect(junction3.portA, tube1.portA) annotation (Line(
      points={{0,16},{0,0},{12,0}},
      color={255,153,0},
      thickness=0.5));
  connect(valve1.portB, junction2.portB) annotation (Line(
      points={{-76,1},{-54,1},{-54,0},{-44,0}},
      color={255,153,0},
      thickness=0.5));
  connect(valve1.portA, portA1) annotation (Line(
      points={{-86,1},{-114,1},{-114,0},{-128,0}},
      color={255,153,0},
      thickness=0.5));
  connect(tube3.portB, junction5.portA) annotation (Line(
      points={{28,-20},{40,-20},{40,-36}},
      color={255,153,0},
      thickness=0.5));
  connect(tube4.portB, junction5.portC) annotation (Line(
      points={{28,-60},{40,-60},{40,-44}},
      color={255,153,0},
      thickness=0.5));
  connect(tube1.portB, junction4.portC) annotation (Line(
      points={{28,0},{40,0},{40,16}},
      color={255,153,0},
      thickness=0.5));
  connect(tube2.portB, junction4.portA) annotation (Line(
      points={{30,40},{40,40},{40,24}},
      color={255,153,0},
      thickness=0.5));
  connect(junction4.portB, junction6.portA) annotation (Line(
      points={{44,20},{80,20},{80,2}},
      color={255,153,0},
      thickness=0.5));
  connect(junction5.portB, junction6.portC) annotation (Line(
      points={{44,-40},{80,-40},{80,-6}},
      color={255,153,0},
      thickness=0.5));
  connect(junction6.portB, portB1) annotation (Line(
      points={{84,-2},{104,-2}},
      color={255,153,0},
      thickness=0.5));
  connect(junction6.portB, sensor_T.port) annotation (Line(
      points={{84,-2},{90,-2},{90,28}},
      color={255,153,0},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end CoilAssembly4ch;
