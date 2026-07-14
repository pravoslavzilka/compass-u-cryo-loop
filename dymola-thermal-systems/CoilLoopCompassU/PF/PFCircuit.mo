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
      condensingIndex=0)) annotation (Placement(transformation(extent={{186,92},
            {206,112}},
                      rotation=0)));

  ThermalSystems.GasComponents.Fans.Fan2ndOrder fan2ndOrder(
    orientation="symmetric",
    use_mechanicalPort=true,
    T_nominal(displayUnit="K") = 160,
    p_nominal=4000000,
    dpInitial(displayUnit="bar") = 4000000,
    V_flow_Start=0.003)
    annotation (Placement(transformation(extent={{-8,-8},{8,8}},
        rotation=90,
        origin={-66,122})));
  ThermalSystems.OtherComponents.Sources.SmoothStep smoothStep(
    initialValue=50,
    endValue=500,
    startTime=1,
    stepPeriod=20)
    annotation (Placement(transformation(extent={{-6,-6},{6,6}},
        rotation=0,
        origin={-118,108})));
  ThermalSystems.OtherComponents.Mechanical.RotatoryBoundary rotatoryBoundary(
    phiInitial=0,
    boundaryType="n",
    use_nInput=true)
    annotation (Placement(transformation(extent={{-4,9},{4,-9}},
        rotation=90,
        origin={-66,111})));
  Modelica.Thermal.HeatTransfer.Sources.FixedTemperature coldSurface(T(
        displayUnit="K") = 77)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=270,
        origin={-50,10})));
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
        rotation=0,
        origin={-50,-12})));
  ThermalSystems.GasComponents.Volumes.Volume volume(
    volume=0.02,
    m_flowStart=0,
    pInitial=4000000,
    TInitial(displayUnit="K") = 80,
    nPorts=1)
    annotation (Placement(transformation(extent={{-3,-7},{3,7}},
        rotation=0,
        origin={-51,-43})));
  ThermalSystems.GasComponents.Valves.Valve valve(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=100)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=90,
        origin={-86,-43})));
  CoilAssembly PF1U(
    length=64,
    nChannels=4,
    TInitial(displayUnit="K"))
    annotation (Placement(transformation(extent={{60,80},{80,100}})));
  CoilAssembly PF1L(length=74, nChannels=4)
    annotation (Placement(transformation(extent={{60,60},{80,80}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={-2,56})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction3(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={96,80})));
  ThermalSystems.GasComponents.Valves.Valve valve1(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=0.001)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=0,
        origin={-42,101})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction4(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=180,
        origin={-20,122})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction5(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=270,
        origin={-86,100})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction2(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=270,
        origin={-86,-12})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction6(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=270,
        origin={-86,44})));
  ThermalSystems.GasComponents.Valves.Valve valve2(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=0.001)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=0,
        origin={-58,45})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction7(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={-26,44})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction8(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={44,80})));
  CoilAssembly PF2U(
    length=80,
    nChannels=2,
    TInitial(displayUnit="K"))
    annotation (Placement(transformation(extent={{60,40},{80,60}})));
  CoilAssembly PF2L(length=80, nChannels=2)
    annotation (Placement(transformation(extent={{60,20},{80,40}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction9(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={96,40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction10(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={44,40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction11(
    volume=1e-5,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={122,62})));
equation

  connect(smoothStep.y,rotatoryBoundary. n_in)
    annotation (Line(points={{-111.4,108},{-80,108},{-80,107},{-66,107}},
                                                     color={0,0,127}));
  connect(rotatoryBoundary.rotatoryFlange, fan2ndOrder.rotatoryFlange)
    annotation (Line(
      points={{-66,111},{-66,114}},
      color={135,135,135},
      thickness=0.5));
  connect(coldSurface.port, tube1.heatPort[1]) annotation (Line(points={{-50,0},
          {-50,-10}},                           color={191,0,0}));
  connect(volume.portArray[1], valve.portA) annotation (Line(
      points={{-51,-49.825},{-52,-49.825},{-52,-54},{-86,-54},{-86,-49}},
      color={255,153,0},
      thickness=0.5));
  connect(PF1U.portB1, junction3.portA) annotation (Line(
      points={{80.4,89.8},{96,89.8},{96,84}},
      color={255,153,0},
      thickness=0.5));
  connect(junction3.portC, PF1L.portB1) annotation (Line(
      points={{96,76},{96,69.8},{80.4,69.8}},
      color={255,153,0},
      thickness=0.5));
  connect(fan2ndOrder.portA, junction4.portC) annotation (Line(
      points={{-58,122},{-24,122}},
      color={255,153,0},
      thickness=0.5));
  connect(junction4.portB, valve1.portB) annotation (Line(
      points={{-20,118},{-20,101},{-36,101}},
      color={255,153,0},
      thickness=0.5));
  connect(valve1.portA, junction5.portB) annotation (Line(
      points={{-48,101},{-64,101},{-64,100},{-82,100}},
      color={255,153,0},
      thickness=0.5));
  connect(junction5.portA, fan2ndOrder.portB) annotation (Line(
      points={{-86,104},{-86,122},{-74,122}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portC, valve.portB) annotation (Line(
      points={{-86,-16},{-86,-37}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portB, tube1.portA) annotation (Line(
      points={{-82,-12},{-58,-12}},
      color={255,153,0},
      thickness=0.5));
  connect(junction6.portA, junction5.portC) annotation (Line(
      points={{-86,48},{-86,96}},
      color={255,153,0},
      thickness=0.5));
  connect(junction6.portC, junction2.portA) annotation (Line(
      points={{-86,40},{-86,-8}},
      color={255,153,0},
      thickness=0.5));
  connect(tube1.portB, junction7.portA) annotation (Line(
      points={{-42,-12},{-26,-12},{-26,40}},
      color={255,153,0},
      thickness=0.5));
  connect(valve2.portB, junction7.portB) annotation (Line(
      points={{-52,45},{-44,45},{-44,44},{-30,44}},
      color={255,153,0},
      thickness=0.5));
  connect(valve2.portA, junction6.portB) annotation (Line(
      points={{-64,45},{-68,45},{-68,44},{-82,44}},
      color={255,153,0},
      thickness=0.5));
  connect(junction7.portC, junction1.portB) annotation (Line(
      points={{-26,48},{-26,56},{-6,56}},
      color={255,153,0},
      thickness=0.5));
  connect(PF1U.portA1, junction8.portC) annotation (Line(
      points={{57.2,90},{44,90},{44,84}},
      color={255,153,0},
      thickness=0.5));
  connect(PF1L.portA1, junction8.portA) annotation (Line(
      points={{57.2,70},{44,70},{44,76}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portC, junction8.portB) annotation (Line(
      points={{-2,60},{-2,80},{40,80}},
      color={255,153,0},
      thickness=0.5));
  connect(PF2U.portB1, junction9.portA) annotation (Line(
      points={{80.4,49.8},{96,49.8},{96,44}},
      color={255,153,0},
      thickness=0.5));
  connect(junction9.portC, PF2L.portB1) annotation (Line(
      points={{96,36},{96,29.8},{80.4,29.8}},
      color={255,153,0},
      thickness=0.5));
  connect(PF2U.portA1, junction10.portC) annotation (Line(
      points={{57.2,50},{44,50},{44,44}},
      color={255,153,0},
      thickness=0.5));
  connect(PF2L.portA1, junction10.portA) annotation (Line(
      points={{57.2,30},{44,30},{44,36}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portA, junction10.portB) annotation (Line(
      points={{-2,52},{-2,40},{40,40}},
      color={255,153,0},
      thickness=0.5));
  connect(junction3.portB, junction11.portA) annotation (Line(
      points={{100,80},{122,80},{122,66}},
      color={255,153,0},
      thickness=0.5));
  connect(junction9.portB, junction11.portC) annotation (Line(
      points={{100,40},{122,40},{122,58}},
      color={255,153,0},
      thickness=0.5));
  connect(junction11.portB, junction4.portA) annotation (Line(
      points={{126,62},{134,62},{134,122},{-16,122}},
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
