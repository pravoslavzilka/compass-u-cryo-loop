within ;
package CoilLoopThermalSystems "Testing circuit"

  model  SimpleLoop
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

    ThermalSystems.GasComponents.Tubes.Tube tube(
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
      annotation (Placement(transformation(extent={{28,30},{44,34}})));
    ThermalSystems.GasComponents.Sensors.Sensor_m_flow sensor_m_flow
      annotation (Placement(transformation(extent={{-16,36},{-8,44}})));
    ThermalSystems.GasComponents.Sensors.StatePoint statePoint
      annotation (Placement(transformation(extent={{-4,-4},{4,4}},
          rotation=90,
          origin={-38,40})));
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
    ThermalSystems.OtherComponents.Sources.StepSource stepSource(
      transitionTime=0.5,
      stepTimes={5,10},
      stepValues={50000,0})
      annotation (Placement(transformation(extent={{-14,94},{-2,106}})));
    Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow
      annotation (Placement(transformation(extent={{14,90},{34,110}})));
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
    ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction(volume=1e-5,
      m_flowStart=1e-5,
      pInitial=2000000,
      fixedInitialPressure=false,
      TInitial(displayUnit="K") = 80)
      annotation (Placement(transformation(extent={{-4,-4},{4,4}},
          rotation=90,
          origin={2,40})));
    ThermalSystems.GasComponents.Tubes.Tube tube2(
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
      annotation (Placement(transformation(extent={{28,48},{44,52}})));
    ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(volume
        =1e-5,
      m_flowStart=1e-5,
      pInitial=2000000,
      fixedInitialPressure=false,
      TInitial(displayUnit="K") = 80)
      annotation (Placement(transformation(extent={{-4,-4},{4,4}},
          rotation=-90,
          origin={50,40})));
    ThermalSystems.OtherComponents.Sources.StepSource stepSource1(
      transitionTime=0.5,
      stepTimes={5,10},
      stepValues={50000,0})
      annotation (Placement(transformation(extent={{-44,66},{-32,78}})));
    Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow1
      annotation (Placement(transformation(extent={{-10,62},{10,82}})));
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
    ThermalSystems.GasComponents.Valves.Valve valve1(
      valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
      use_effectiveFlowAreaInput=false,
      use_KvValueInput=false,
      KvValueFixed=100)
      annotation (Placement(transformation(extent={{10,46},{20,52}})));
    ThermalSystems.GasComponents.Valves.Valve valve2(
      valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
      use_effectiveFlowAreaInput=false,
      use_KvValueInput=false,
      KvValueFixed=100)
      annotation (Placement(transformation(extent={{10,28},{20,34}})));
  equation

    connect(fan2ndOrder.portB, sensor_m_flow.portA) annotation (Line(
        points={{-28,28},{-28,40},{-15,40}},
        color={255,153,0},
        thickness=0.5));
    connect(statePoint.port, sensor_m_flow.portA) annotation (Line(
        points={{-34,40},{-15,40}},
        color={255,153,0},
        thickness=0.5));
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
    connect(stepSource.y, prescribedHeatFlow.Q_flow)
      annotation (Line(points={{-1,100},{14,100}}, color={0,0,127}));
    connect(coldSurface.port, tube1.heatPort[1]) annotation (Line(points={{34,8},{
            34,14}},                              color={191,0,0}));
    connect(stepSource1.y, prescribedHeatFlow1.Q_flow)
      annotation (Line(points={{-31,72},{-10,72}}, color={0,0,127}));
    connect(prescribedHeatFlow1.port, tube.heatPort[1]) annotation (Line(points={{10,72},
            {24,72},{24,40},{36,40},{36,34}},           color={191,0,0}));
    connect(prescribedHeatFlow.port, tube2.heatPort[1])
      annotation (Line(points={{34,100},{38,100},{38,54},{36,54},{36,52}},
                                                          color={191,0,0}));
    connect(tube.portB, junction1.portC) annotation (Line(
        points={{44,32},{50,32},{50,36}},
        color={255,153,0},
        thickness=0.5));
    connect(sensor_m_flow.portB, junction.portB) annotation (Line(
        points={{-9,40},{-2,40}},
        color={255,153,0},
        thickness=0.5));
    connect(tube2.portB, junction1.portA) annotation (Line(
        points={{44,50},{50,50},{50,44}},
        color={255,153,0},
        thickness=0.5));
    connect(junction1.portB, tube1.portA) annotation (Line(
        points={{54,40},{58,40},{58,16},{42,16}},
        color={255,153,0},
        thickness=0.5));
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
    connect(tube2.portA, valve1.portB) annotation (Line(
        points={{28,50},{28,49},{20,49}},
        color={255,153,0},
        thickness=0.5));
    connect(tube.portA, valve2.portB) annotation (Line(
        points={{28,32},{20,32},{20,31}},
        color={255,153,0},
        thickness=0.5));
    connect(junction.portC, valve1.portA) annotation (Line(
        points={{2,44},{2,49},{10,49}},
        color={255,153,0},
        thickness=0.5));
    connect(junction.portA, valve2.portA) annotation (Line(
        points={{2,36},{2,31},{10,31}},
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
  end SimpleLoop;
  annotation (uses(ThermalSystems(version="1.13.0"), Modelica(version="4.0.0")));
end CoilLoopThermalSystems;
