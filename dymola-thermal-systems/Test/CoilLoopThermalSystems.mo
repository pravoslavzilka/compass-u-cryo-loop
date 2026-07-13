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
      annotation (Placement(transformation(extent={{28,32},{44,36}})));
    ThermalSystems.GasComponents.Sensors.Sensor_m_flow sensor_m_flow
      annotation (Placement(transformation(extent={{-28,16},{-20,24}})));
    ThermalSystems.GasComponents.Sensors.StatePoint statePoint
      annotation (Placement(transformation(extent={{-44,30},{-36,38}})));
    ThermalSystems.GasComponents.Sensors.StatePoint statePoint1(index=1)
      annotation (Placement(transformation(extent={{-112,-30},{-104,-22}})));
    ThermalSystems.GasComponents.Fans.Fan2ndOrder fan2ndOrder(
      orientation="symmetric",
      use_mechanicalPort=true,
      T_nominal(displayUnit="K") = 160,
      p_nominal=2000000,
      dpInitial(displayUnit="bar") = 2000000,
      V_flow_Start=0.003)
      annotation (Placement(transformation(extent={{-48,-8},{-32,8}})));
    ThermalSystems.OtherComponents.Sources.SmoothStep smoothStep(
      initialValue=50,
      endValue=500,
      startTime=1,
      stepPeriod=20)
      annotation (Placement(transformation(extent={{-86,-6},{-74,6}})));
    ThermalSystems.OtherComponents.Mechanical.RotatoryBoundary rotatoryBoundary(
      phiInitial=0,
      boundaryType="n",
      use_nInput=true)
      annotation (Placement(transformation(extent={{-64,-10},{-56,10}})));
    ThermalSystems.OtherComponents.Sources.StepSource stepSource(
      transitionTime=0.5,
      stepTimes={5,10},
      stepValues={50000,0})
      annotation (Placement(transformation(extent={{-70,64},{-58,76}})));
    Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow
      annotation (Placement(transformation(extent={{-44,60},{-24,80}})));
    Modelica.Thermal.HeatTransfer.Sources.FixedTemperature coldSurface(T(
          displayUnit="K") = 77)
      annotation (Placement(transformation(extent={{60,-58},{80,-38}})));
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
      annotation (Placement(transformation(extent={{-18,-18},{-2,-14}})));
    ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction(volume=1e-5,
      m_flowStart=1e-5,
      pInitial=2000000,
      fixedInitialPressure=false,
      TInitial(displayUnit="K") = 80)
      annotation (Placement(transformation(extent={{-10,12},{-2,20}})));
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
      annotation (Placement(transformation(extent={{28,46},{44,50}})));
    ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(volume
        =1e-5,
      m_flowStart=1e-5,
      pInitial=2000000,
      fixedInitialPressure=false,
      TInitial(displayUnit="K") = 80)
      annotation (Placement(transformation(extent={{22,4},{30,12}})));
    ThermalSystems.OtherComponents.Sources.StepSource stepSource1(
      transitionTime=0.5,
      stepTimes={5,10},
      stepValues={50000,0})
      annotation (Placement(transformation(extent={{-80,42},{-68,54}})));
    Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow1
      annotation (Placement(transformation(extent={{-54,38},{-34,58}})));
    ThermalSystems.GasComponents.Volumes.Volume volume(
      volume=0.02,
      m_flowStart=0,
      pInitial=2000000,
      TInitial(displayUnit="K") = 80,
      nPorts=1)
      annotation (Placement(transformation(extent={{-86,-64},{-80,-50}})));
    ThermalSystems.GasComponents.Valves.Valve valve(
      valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
      use_effectiveFlowAreaInput=false,
      use_KvValueInput=false,
      KvValueFixed=100)
      annotation (Placement(transformation(extent={{-68,-72},{-52,-64}})));
    ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction2(
      volume=1e-5,
      m_flowStart=1e-5,
      pInitial=2000000,
      fixedInitialPressure=false,
      TInitial(displayUnit="K") = 80)
      annotation (Placement(transformation(extent={{-30,-46},{-22,-38}})));
    ThermalSystems.GasComponents.Valves.Valve valve1(
      valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
      use_effectiveFlowAreaInput=false,
      use_KvValueInput=false,
      KvValueFixed=100)
      annotation (Placement(transformation(extent={{8,44},{18,50}})));
    ThermalSystems.GasComponents.Valves.Valve valve2(
      valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
      use_effectiveFlowAreaInput=false,
      use_KvValueInput=false,
      KvValueFixed=100)
      annotation (Placement(transformation(extent={{10,28},{20,34}})));
  equation

    connect(fan2ndOrder.portB, sensor_m_flow.portA) annotation (Line(
        points={{-40,8},{-40,20},{-27,20}},
        color={255,153,0},
        thickness=0.5));
    connect(statePoint.port, sensor_m_flow.portA) annotation (Line(
        points={{-40,30},{-40,20},{-27,20}},
        color={255,153,0},
        thickness=0.5));
    connect(statePoint1.port, fan2ndOrder.portA) annotation (Line(
        points={{-108,-30},{-108,-34},{-40,-34},{-40,-8}},
        color={255,153,0},
        thickness=0.5));
    connect(smoothStep.y,rotatoryBoundary. n_in)
      annotation (Line(points={{-73.4,0},{-64,0}},     color={0,0,127}));
    connect(rotatoryBoundary.rotatoryFlange, fan2ndOrder.rotatoryFlange)
      annotation (Line(
        points={{-60,0},{-48,0}},
        color={135,135,135},
        thickness=0.5));
    connect(stepSource.y, prescribedHeatFlow.Q_flow)
      annotation (Line(points={{-57,70},{-44,70}}, color={0,0,127}));
    connect(coldSurface.port, tube1.heatPort[1]) annotation (Line(points={{80,-48},
            {80,-8},{-10,-8},{-10,-14}},          color={191,0,0}));
    connect(stepSource1.y, prescribedHeatFlow1.Q_flow)
      annotation (Line(points={{-67,48},{-54,48}}, color={0,0,127}));
    connect(prescribedHeatFlow1.port, tube.heatPort[1]) annotation (Line(points={{-34,48},
            {-16,48},{-16,38},{24,38},{24,40},{36,40},{36,36}},
                                                        color={191,0,0}));
    connect(prescribedHeatFlow.port, tube2.heatPort[1])
      annotation (Line(points={{-24,70},{36,70},{36,50}}, color={191,0,0}));
    connect(tube.portB, junction1.portC) annotation (Line(
        points={{44,34},{50,34},{50,8},{30,8}},
        color={255,153,0},
        thickness=0.5));
    connect(sensor_m_flow.portB, junction.portB) annotation (Line(
        points={{-21,20},{-6,20}},
        color={255,153,0},
        thickness=0.5));
    connect(tube2.portB, junction1.portA) annotation (Line(
        points={{44,48},{48,48},{48,0},{18,0},{18,8},{22,8}},
        color={255,153,0},
        thickness=0.5));
    connect(junction1.portB, tube1.portA) annotation (Line(
        points={{26,12},{26,16},{14,16},{14,-6},{-24,-6},{-24,-16},{-18,-16}},
        color={255,153,0},
        thickness=0.5));
    connect(volume.portArray[1], valve.portA) annotation (Line(
        points={{-83,-63.825},{-84,-63.825},{-84,-74},{-68,-74},{-68,-68}},
        color={255,153,0},
        thickness=0.5));
    connect(tube1.portB, junction2.portC) annotation (Line(
        points={{-2,-16},{2,-16},{2,-42},{-22,-42}},
        color={255,153,0},
        thickness=0.5));
    connect(valve.portB, junction2.portA) annotation (Line(
        points={{-52,-68},{-36,-68},{-36,-42},{-30,-42}},
        color={255,153,0},
        thickness=0.5));
    connect(junction2.portB, fan2ndOrder.portA) annotation (Line(
        points={{-26,-38},{-26,-34},{-40,-34},{-40,-8}},
        color={255,153,0},
        thickness=0.5));
    connect(tube2.portA, valve1.portB) annotation (Line(
        points={{28,48},{28,47},{18,47}},
        color={255,153,0},
        thickness=0.5));
    connect(tube.portA, valve2.portB) annotation (Line(
        points={{28,34},{20,34},{20,31}},
        color={255,153,0},
        thickness=0.5));
    connect(valve1.portA, junction.portA) annotation (Line(
        points={{8,47},{-4,47},{-4,32},{-10,32},{-10,16}},
        color={255,153,0},
        thickness=0.5));
    connect(valve2.portA, junction.portC) annotation (Line(
        points={{10,31},{4,31},{4,20},{-2,20},{-2,16}},
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
