within CoilLoopCompassU.PF;
model  PFCircuit
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

  ThermalSystems.GasComponents.Fans.Fan2ndOrder fan2ndOrder(
    orientation="symmetric",
    use_mechanicalPort=true,
    T_nominal(displayUnit="K") = 160,
    p_nominal=4000000,
    dpInitial(displayUnit="bar") = 4000000,
    V_flow_Start=0.003)
    annotation (Placement(transformation(extent={{-8,-8},{8,8}},
        rotation=180,
        origin={64,52})));
  ThermalSystems.OtherComponents.Sources.SmoothStep smoothStep(
    initialValue=50,
    endValue=500,
    startTime=1,
    stepPeriod=20)
    annotation (Placement(transformation(extent={{-6,-6},{6,6}},
        rotation=0,
        origin={108,50})));
  ThermalSystems.OtherComponents.Mechanical.RotatoryBoundary rotatoryBoundary(
    phiInitial=0,
    boundaryType="n",
    use_nInput=true)
    annotation (Placement(transformation(extent={{-4,9},{4,-9}},
        rotation=180,
        origin={80,53})));
  Modelica.Thermal.HeatTransfer.Sources.FixedTemperature coldSurface(T(
        displayUnit="K") = 77)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=90,
        origin={26,28})));
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
    pInitial=4000000,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-8,-2},{8,2}},
        rotation=180,
        origin={26,46})));
  ThermalSystems.GasComponents.Volumes.Volume volume(
    volume=0.02,
    m_flowStart=0,
    pInitial=4000000,
    TInitial(displayUnit="K") = 80,
    nPorts=1)
    annotation (Placement(transformation(extent={{-3,-7},{3,7}},
        rotation=0,
        origin={-21,21})));
  ThermalSystems.GasComponents.Valves.Valve valve(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=100)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=90,
        origin={-6,21})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction2(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={-6,38})));
  CoilAssembly PF1U(
    length=64,
    nChannels=4,
    TInitial(displayUnit="K"))
    annotation (Placement(transformation(extent={{20,80},{40,100}})));
  CoilAssembly PF1L(length=74, nChannels=4)
    annotation (Placement(transformation(extent={{20,60},{40,80}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={8,80})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction3(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={50,80})));
equation

  connect(smoothStep.y,rotatoryBoundary. n_in)
    annotation (Line(points={{114.6,50},{118,50},{118,68},{84,68},{84,53}},
                                                     color={0,0,127}));
  connect(rotatoryBoundary.rotatoryFlange, fan2ndOrder.rotatoryFlange)
    annotation (Line(
      points={{80,53},{80,52},{72,52}},
      color={135,135,135},
      thickness=0.5));
  connect(coldSurface.port, tube1.heatPort[1]) annotation (Line(points={{26,38},
          {26,44}},                             color={191,0,0}));
  connect(volume.portArray[1], valve.portA) annotation (Line(
      points={{-21,14.175},{-20,14.175},{-20,10},{-6,10},{-6,15}},
      color={255,153,0},
      thickness=0.5));
  connect(tube1.portB, junction2.portC) annotation (Line(
      points={{18,46},{-6,46},{-6,42}},
      color={255,153,0},
      thickness=0.5));
  connect(valve.portB, junction2.portA) annotation (Line(
      points={{-6,27},{-6,34}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portC, PF1U.portA1) annotation (Line(
      points={{8,84},{17.2,84},{17.2,90}},
      color={255,153,0},
      thickness=0.5));
  connect(PF1U.portB1, junction3.portA) annotation (Line(
      points={{40.4,89.8},{44,89.8},{44,84},{50,84}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portA, PF1L.portA1) annotation (Line(
      points={{8,76},{12,76},{12,70},{17.2,70}},
      color={255,153,0},
      thickness=0.5));
  connect(junction3.portC, PF1L.portB1) annotation (Line(
      points={{50,76},{46,76},{46,69.8},{40.4,69.8}},
      color={255,153,0},
      thickness=0.5));
  connect(junction3.portB, fan2ndOrder.portA) annotation (Line(
      points={{54,80},{64,80},{64,60}},
      color={255,153,0},
      thickness=0.5));
  connect(fan2ndOrder.portB, tube1.portA) annotation (Line(
      points={{64,44},{64,40},{40,40},{40,46},{34,46}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portB, junction1.portB) annotation (Line(
      points={{-10,38},{-16,38},{-16,80},{4,80}},
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
end PFCircuit;
