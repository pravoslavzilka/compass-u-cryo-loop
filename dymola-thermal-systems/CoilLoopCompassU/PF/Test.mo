within CoilLoopCompassU.PF;
model  Test
  extends ThermalSystems.Internals.ClassTypes.ExampleModel;

  inner ThermalSystems.SystemInformationManager sim(
      generateEventsAtFlowReversalGas=false,
      redeclare
      TSMedia.GasTypes.BaseGas gasType1(
      fixedMixingRatio=true,
      nc_propertyCalculation=1,
      gasNames={"VDIWA2006.Helium"},
      mixingRatio_propertyCalculation={1},
      condensingIndex=0)) annotation (Placement(transformation(extent={{80,80},
            {100,100}},
                      rotation=0)));

  ThermalSystems.GasComponents.Sensors.StatePoint statePoint1(index=1)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=180,
        origin={-28,-6})));
  ThermalSystems.GasComponents.Fans.Fan2ndOrder fan2ndOrder(
    orientation="symmetric",
    use_mechanicalPort=true,
    T_nominal(displayUnit="K") = 160,
    p_nominal=2000000,
    dpInitial(displayUnit="bar") = 2000000,
    V_flow_Start=0.003)
    annotation (Placement(transformation(extent={{-36,12},{-20,28}})));
  ThermalSystems.OtherComponents.Sources.SmoothStep smoothStep(
    initialValue=50,
    endValue=500,
    startTime=1,
    stepPeriod=20)
    annotation (Placement(transformation(extent={{-68,14},{-56,26}})));
  ThermalSystems.OtherComponents.Mechanical.RotatoryBoundary rotatoryBoundary(
    phiInitial=0,
    boundaryType="n",
    use_nInput=true)
    annotation (Placement(transformation(extent={{-48,28},{-40,10}})));
  Modelica.Thermal.HeatTransfer.Sources.FixedTemperature coldSurface(T(
        displayUnit="K") = 77)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=90,
        origin={34,-2})));
  ThermalSystems.GasComponents.Tubes.Tube tube1(
    tubeGeometry(
      innerDiameter=0.007,
      length=70,
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
    pInitial=2000000,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-8,-2},{8,2}},
        rotation=180,
        origin={34,16})));
  ThermalSystems.GasComponents.Volumes.Volume volume(
    volume=0.02,
    m_flowStart=0,
    pInitial=2000000,
    TInitial(displayUnit="K") = 80,
    nPorts=1)
    annotation (Placement(transformation(extent={{-3,-7},{3,7}},
        rotation=0,
        origin={-13,-9})));
  ThermalSystems.GasComponents.Valves.Valve valve(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=100)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=90,
        origin={2,-9})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction2(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=2000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={2,8})));
  CoilAssembly coilAssembly
    annotation (Placement(transformation(extent={{28,34},{48,54}})));
equation

  connect(statePoint1.port, fan2ndOrder.portA) annotation (Line(
      points={{-28,-2},{-28,12}},
      color={255,153,0},
      thickness=0.5));
  connect(smoothStep.y,rotatoryBoundary. n_in)
    annotation (Line(points={{-55.4,20},{-56,19},{-48,19}},
                                                     color={0,0,127}));
  connect(rotatoryBoundary.rotatoryFlange, fan2ndOrder.rotatoryFlange)
    annotation (Line(
      points={{-44,19},{-44,20},{-36,20}},
      color={135,135,135},
      thickness=0.5));
  connect(coldSurface.port, tube1.heatPort[1]) annotation (Line(points={{34,8},{
          34,14}},                              color={191,0,0}));
  connect(volume.portArray[1], valve.portA) annotation (Line(
      points={{-13,-15.825},{-12,-15.825},{-12,-20},{2,-20},{2,-15}},
      color={255,153,0},
      thickness=0.5));
  connect(tube1.portB, junction2.portC) annotation (Line(
      points={{26,16},{2,16},{2,12}},
      color={255,153,0},
      thickness=0.5));
  connect(valve.portB, junction2.portA) annotation (Line(
      points={{2,-3},{2,4}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portB, fan2ndOrder.portA) annotation (Line(
      points={{-2,8},{-28,8},{-28,12}},
      color={255,153,0},
      thickness=0.5));
  connect(coilAssembly.portA1, fan2ndOrder.portB) annotation (Line(
      points={{25.2,44},{-28,44},{-28,28}},
      color={255,153,0},
      thickness=0.5));
  connect(coilAssembly.portB1, tube1.portA) annotation (Line(
      points={{48.4,43.8},{48.4,16},{42,16}},
      color={255,153,0},
      thickness=0.5));
  annotation (Diagram(coordinateSystem(preserveAspectRatio=false, extent={{-100,
            -100},{100,100}})),
    experiment(
      StopTime=1800,
      __Dymola_NumberOfIntervals=50,
      __Dymola_Algorithm="Dassl"),
    __Dymola_experimentSetupOutput,
    uses(
      ThermalSystems(version="1.13.0"),
      TSMedia(version="1.13.0"),
      Modelica(version="4.0.0")),
    version="1",
    conversion(noneFromVersion=""));
end Test;
