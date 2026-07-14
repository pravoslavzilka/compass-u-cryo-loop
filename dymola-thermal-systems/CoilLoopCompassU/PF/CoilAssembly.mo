within CoilLoopCompassU.PF;
model CoilAssembly
  outer ThermalSystems.SystemInformationManager sim;
  parameter Modelica.Units.SI.Length length = 80 "Equivalent channel length";
  parameter Modelica.Units.SI.Diameter diameter = 0.007 "Equivalent channel diameter";
  parameter Integer nChannels = 2 "Number of parallel channels (affects flow area)";
  parameter Modelica.Units.SI.Power dischargeLoad = 50000 "Peak discharge heat [W]";
  parameter Modelica.Units.SI.Time pulseStart = 5 "Discharge start time";
  parameter Modelica.Units.SI.Time pulseEnd = 10 "Discharge end time";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1)";
  parameter Real valveKvNominal = 100 "Kv value at fully-open (valveOpening=1)";
  parameter Modelica.Units.SI.Temperature TInitial = 80 "Initial coil/gas temperature";

  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow
    annotation (Placement(transformation(extent={{16,62},{36,82}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoad,0})
    annotation (Placement(transformation(extent={{-20,66},{-8,78}})));
  ThermalSystems.GasComponents.Tubes.Tube tube2(
    tubeGeometry(
      innerDiameter=diameter,
      length=length,
      nParallelTubes=nChannels,
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
    annotation (Placement(transformation(extent={{8,52},{18,58}})));
  ThermalSystems.Connectors.GasPort portA1
                  "portA"
    annotation (Placement(transformation(extent={{-138,-10},{-118,10}})));
  ThermalSystems.Connectors.GasPort portB1
    annotation (Placement(transformation(extent={{94,-12},{114,8}})));
equation
  connect(stepSource.y, prescribedHeatFlow.Q_flow)
    annotation (Line(points={{-7,72},{16,72}}, color={0,0,127}));
  connect(prescribedHeatFlow.port, tube2.heatPort[1])
    annotation (Line(points={{36,72},{40,72},{40,56}}, color={191,0,0}));
  connect(valve1.portB, tube2.portA) annotation (Line(
      points={{18,55},{18,54},{32,54}},
      color={255,153,0},
      thickness=0.5));
  connect(valve1.portA, portA1) annotation (Line(
      points={{8,55},{-4,55},{-4,36},{-100,36},{-100,0},{-128,0}},
      color={255,153,0},
      thickness=0.5));
  connect(tube2.portB, portB1) annotation (Line(
      points={{48,54},{66,54},{66,38},{74,38},{74,0},{104,0},{104,-2}},
      color={255,153,0},
      thickness=0.5));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end CoilAssembly;
