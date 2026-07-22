within CoilLoopCompassU.PF;
model  PFCircuit
  extends ThermalSystems.Internals.ClassTypes.ExampleModel;
  parameter Real m_wanted = 0.095 "flow I want in the circuit, kg/s";
  parameter Real m_total = 0.1 "total flow from the pump, kg/s";
  parameter Modelica.Units.SI.TemperatureDifference tempMargin = 40
    "Margin below the hottest coil-assembly gas outlet temperature";

  output Modelica.Units.SI.Temperature T_gas_out_max = max({PF1U.T_gas_out,
      PF1L.T_gas_out, PF2U.T_gas_out, PF2L.T_gas_out, PF3U.T_gas_out,
      PF3L.T_gas_out, PF4U.T_gas_out, PF4L.T_gas_out})
    "Hottest coil-assembly gas outlet temperature (all 8 coils)";
  output Modelica.Units.SI.Temperature wanted_temp = T_gas_out_max - tempMargin
    "PID setpoint: hottest coil outlet minus margin, revalued continuously";

  inner ThermalSystems.SystemInformationManager sim(
      generateEventsAtFlowReversalGas=false,
      redeclare
      TSMedia.GasTypes.BaseGas gasType1(
      fixedMixingRatio=true,
      nc_propertyCalculation=1,
      gasNames={"VDIWA2006.Helium"},
      mixingRatio_propertyCalculation={1},
      condensingIndex=0)) annotation (Placement(transformation(extent={{180,102},
            {200,122}},
                      rotation=0)));

  ThermalSystems.GasComponents.Fans.Fan2ndOrder fan2ndOrder(
    orientation="symmetric",
    use_mechanicalPort=true,
    n_nominal=10000,
    dp_nominal(displayUnit="bar") = 200000,
    V_flow_nominal=0.0042,
    V_flow0=0.008,
    T_nominal(displayUnit="K") = 80,
    p_nominal=4000000,
    dpInitial(displayUnit="bar") = 4000000,
    V_flow_Start=0.003)
    annotation (Placement(transformation(extent={{8,-8},{-8,8}},
        rotation=90,
        origin={-60,120})));
  ThermalSystems.OtherComponents.Sources.SmoothStep smoothStep(
    initialValue=6000,
    endValue=6000,
    startTime=1,
    stepPeriod=10)
    annotation (Placement(transformation(extent={{-6,-6},{6,6}},
        rotation=0,
        origin={-130,142})));
  ThermalSystems.OtherComponents.Mechanical.RotatoryBoundary rotatoryBoundary(
    phiInitial=0,
    boundaryType="n",
    use_nInput=true)
    annotation (Placement(transformation(extent={{-4,9},{4,-9}},
        rotation=270,
        origin={-60,131})));
  Modelica.Thermal.HeatTransfer.Sources.FixedTemperature coldSurface(T(
        displayUnit="K") = 77)
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},
        rotation=270,
        origin={-50,10})));
  ThermalSystems.GasComponents.Tubes.Tube tube1(
    tubeGeometry(
      innerDiameter=0.012,
      length=3,
      nParallelTubes=60,
      wallThickness=0.001,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    redeclare model WallMaterial = TSMedia.SolidTypes.TSMedia_StainlessSteel,
    fixedTInitialWall=false,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=4000000,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-8,-2},{8,2}},
        rotation=0,
        origin={-50,-20})));
  ThermalSystems.GasComponents.Volumes.Volume volume(
    volume=0.5,
    m_flowStart=0,
    pInitial=4000000,
    TInitial(displayUnit="K") = 80,
    nPorts=1)
    annotation (Placement(transformation(extent={{-3,-7},{3,7}},
        rotation=0,
        origin={-41,-39})));
  ThermalSystems.GasComponents.Valves.Valve valve(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=100)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=90,
        origin={-80,-41})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={20,60})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction3(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={100,80})));
  ThermalSystems.GasComponents.Valves.Valve valve1(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=0.0001)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=0,
        origin={-42,99})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction4(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=180,
        origin={-20,120})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction5(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=270,
        origin={-80,100})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction2(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=270,
        origin={-80,-20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction6(
    volume=1e-1,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=270,
        origin={-80,40})));
  ThermalSystems.GasComponents.Valves.Valve valve2(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=1000)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=0,
        origin={-50,39})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction7(
    volume=1e-1,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=270,
        origin={-20,20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction8(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={40,80})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction9(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={100,40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction10(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={40,40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction11(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={120,60})));
  CoilAssembly2ch PF2U(lengths={80,83},
    dischargeLoads={0,0},
    TInitial(displayUnit="K") = 160)
    annotation (Placement(transformation(extent={{60,20},{80,40}})));
  CoilAssembly2ch PF2L(lengths={80,83},
    dischargeLoads={0,0},
    TInitial(displayUnit="K") = 160)
    annotation (Placement(transformation(extent={{60,40},{80,60}})));
  CoilAssembly4ch PF1L(
    lengths={61,64,70,74},
    dischargeLoads={0,0,0,0},
    TInitial(displayUnit="K") = 160)
    annotation (Placement(transformation(extent={{60,80},{80,100}})));
  CoilAssembly4ch PF1U(
    lengths={61,64,70,74},
    dischargeLoads={0,0,0,0},
    TInitial(displayUnit="K") = 160)
    annotation (Placement(transformation(extent={{60,60},{80,80}})));
  CoilAssembly3ch PF3L(lengths={83,84,87},
    dischargeLoads={0,0,0},
    TInitial(displayUnit="K") = 160)
    annotation (Placement(transformation(extent={{60,0},{80,20}})));
  CoilAssembly3ch PF3U(lengths={83,84,87},
    dischargeLoads={0,0,0},
    TInitial(displayUnit="K") = 160)
    annotation (Placement(transformation(extent={{60,-20},{80,0}})));
  CoilAssembly4ch PF4L(lengths={90,90,90,75}, diameters_mm={9,9,9,9},
    dischargeLoads={0,0,0,0},
    TInitial(displayUnit="K") = 160)
    annotation (Placement(transformation(extent={{60,-40},{80,-20}})));
  CoilAssembly4ch PF4U(lengths={90,90,90,75}, diameters_mm={9,9,9,9},
    dischargeLoads={0,0,0,0},
    TInitial(displayUnit="K") = 160)
    annotation (Placement(transformation(extent={{60,-60},{80,-40}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction12(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={20,-20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction13(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={40,0})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction14(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={40,-40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction15(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={100,0})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction16(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={100,-40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction17(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={120,-20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction18(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={140,20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction19(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={0,20})));
  Modelica.Blocks.Sources.RealExpression valveRegulator(y=4.39*(sensor_m_flow.sensorValue
         - m_wanted)/m_wanted)
    annotation (Placement(transformation(extent={{-140,160},{-120,180}})));
  ThermalSystems.GasComponents.Sensors.Sensor_m_flow sensor_m_flow
    annotation (Placement(transformation(extent={{-72,116},{-80,124}})));
  Modelica.Blocks.Continuous.LimPID PID(
    controllerType=Modelica.Blocks.Types.SimpleController.PI,
    k=0.05,
    Ti=20,
    yMax=6000,
    yMin=0.001,
    initType=Modelica.Blocks.Types.Init.InitialOutput,
    y_start=3000)
            annotation (Placement(transformation(extent={{-10,10},{10,-10}},
        rotation=-90,
        origin={-48,70})));
  Modelica.Blocks.Sources.RealExpression wantedTemp(y=wanted_temp)
    annotation (Placement(transformation(extent={{-184,70},{-164,90}})));
  ThermalSystems.GasComponents.Sensors.Sensor_T sensor_T
    annotation (Placement(transformation(extent={{-16,40},{-8,48}})));
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=500, uMin=0.001)
    annotation (Placement(transformation(extent={{-80,160},{-60,180}})));
equation

  connect(smoothStep.y,rotatoryBoundary. n_in)
    annotation (Line(points={{-123.4,142},{-60,142},{-60,135}},
                                                     color={0,0,127}));
  connect(rotatoryBoundary.rotatoryFlange, fan2ndOrder.rotatoryFlange)
    annotation (Line(
      points={{-60,131},{-60,128}},
      color={135,135,135},
      thickness=0.5));
  connect(coldSurface.port, tube1.heatPort[1]) annotation (Line(points={{-50,0},
          {-50,-18}},                           color={191,0,0}));
  connect(volume.portArray[1], valve.portA) annotation (Line(
      points={{-41,-45.825},{-40,-45.825},{-40,-60},{-80,-60},{-80,-47}},
      color={255,153,0},
      thickness=0.5));
  connect(fan2ndOrder.portA, junction4.portC) annotation (Line(
      points={{-52,120},{-24,120}},
      color={255,153,0},
      thickness=0.5));
  connect(junction4.portB, valve1.portB) annotation (Line(
      points={{-20,116},{-20,99},{-36,99}},
      color={255,153,0},
      thickness=0.5));
  connect(valve1.portA, junction5.portB) annotation (Line(
      points={{-48,99},{-64,99},{-64,100},{-76,100}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portC, valve.portB) annotation (Line(
      points={{-80,-24},{-80,-35}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portC, junction8.portB) annotation (Line(
      points={{20,64},{20,80},{36,80}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portA, junction10.portB) annotation (Line(
      points={{20,56},{20,40},{36,40}},
      color={255,153,0},
      thickness=0.5));
  connect(junction3.portB, junction11.portA) annotation (Line(
      points={{104,80},{120,80},{120,64}},
      color={255,153,0},
      thickness=0.5));
  connect(junction9.portB, junction11.portC) annotation (Line(
      points={{104,40},{120,40},{120,56}},
      color={255,153,0},
      thickness=0.5));
  connect(junction10.portA, PF2U.portA1) annotation (Line(
      points={{40,36},{40,30},{57.2,30}},
      color={255,153,0},
      thickness=0.5));
  connect(PF2U.portB1, junction9.portC) annotation (Line(
      points={{80.4,29.8},{100,29.8},{100,36}},
      color={255,153,0},
      thickness=0.5));
  connect(junction10.portC, PF2L.portA1) annotation (Line(
      points={{40,44},{40,50},{57.2,50}},
      color={255,153,0},
      thickness=0.5));
  connect(PF2L.portB1, junction9.portA) annotation (Line(
      points={{80.4,49.8},{100,49.8},{100,44}},
      color={255,153,0},
      thickness=0.5));
  connect(junction8.portC, PF1L.portA1) annotation (Line(
      points={{40,84},{40,90},{57.2,90}},
      color={255,153,0},
      thickness=0.5));
  connect(junction8.portA, PF1U.portA1) annotation (Line(
      points={{40,76},{40,70},{57.2,70}},
      color={255,153,0},
      thickness=0.5));
  connect(PF1U.portB1, junction3.portC) annotation (Line(
      points={{80.4,69.8},{100,69.8},{100,76}},
      color={255,153,0},
      thickness=0.5));
  connect(PF1L.portB1, junction3.portA) annotation (Line(
      points={{80.4,89.8},{100,89.8},{100,84}},
      color={255,153,0},
      thickness=0.5));
  connect(junction12.portC, junction13.portB) annotation (Line(
      points={{20,-16},{20,0},{36,0}},
      color={255,153,0},
      thickness=0.5));
  connect(junction12.portA, junction14.portB) annotation (Line(
      points={{20,-24},{20,-40},{36,-40}},
      color={255,153,0},
      thickness=0.5));
  connect(junction15.portB, junction17.portA) annotation (Line(
      points={{104,0},{120,0},{120,-16}},
      color={255,153,0},
      thickness=0.5));
  connect(junction16.portB, junction17.portC) annotation (Line(
      points={{104,-40},{120,-40},{120,-24}},
      color={255,153,0},
      thickness=0.5));
  connect(junction17.portB, junction18.portC) annotation (Line(
      points={{124,-20},{140,-20},{140,16}},
      color={255,153,0},
      thickness=0.5));
  connect(junction11.portB, junction18.portA) annotation (Line(
      points={{124,60},{140,60},{140,24}},
      color={255,153,0},
      thickness=0.5));
  connect(junction18.portB, junction4.portA) annotation (Line(
      points={{144,20},{160,20},{160,120},{-16,120}},
      color={255,153,0},
      thickness=0.5));
  connect(junction13.portC, PF3L.portA1) annotation (Line(
      points={{40,4},{40,10},{57.2,10}},
      color={255,153,0},
      thickness=0.5));
  connect(junction13.portA, PF3U.portA1) annotation (Line(
      points={{40,-4},{40,-10},{57.2,-10}},
      color={255,153,0},
      thickness=0.5));
  connect(junction14.portC, PF4L.portA1) annotation (Line(
      points={{40,-36},{40,-30},{57.2,-30}},
      color={255,153,0},
      thickness=0.5));
  connect(junction14.portA, PF4U.portA1) annotation (Line(
      points={{40,-44},{40,-50},{57.2,-50}},
      color={255,153,0},
      thickness=0.5));
  connect(PF4U.portB1, junction16.portC) annotation (Line(
      points={{80.4,-50.2},{100,-50.2},{100,-44}},
      color={255,153,0},
      thickness=0.5));
  connect(PF4L.portB1, junction16.portA) annotation (Line(
      points={{80.4,-30.2},{100,-30.2},{100,-36}},
      color={255,153,0},
      thickness=0.5));
  connect(PF3U.portB1, junction15.portC) annotation (Line(
      points={{80.4,-10.2},{100,-10.2},{100,-4}},
      color={255,153,0},
      thickness=0.5));
  connect(PF3L.portB1, junction15.portA) annotation (Line(
      points={{80.4,9.8},{100,9.8},{100,4}},
      color={255,153,0},
      thickness=0.5));
  connect(valve2.portB, junction7.portA) annotation (Line(
      points={{-44,39},{-20,39},{-20,24}},
      color={255,153,0},
      thickness=0.5));
  connect(tube1.portB, junction7.portC) annotation (Line(
      points={{-42,-20},{-20,-20},{-20,16}},
      color={255,153,0},
      thickness=0.5));
  connect(junction7.portB, junction19.portB) annotation (Line(
      points={{-16,20},{-4,20}},
      color={255,153,0},
      thickness=0.5));
  connect(junction19.portC, junction1.portB) annotation (Line(
      points={{0,24},{0,60},{16,60}},
      color={255,153,0},
      thickness=0.5));
  connect(junction19.portA, junction12.portB) annotation (Line(
      points={{0,16},{0,-20},{16,-20}},
      color={255,153,0},
      thickness=0.5));
  connect(fan2ndOrder.portB, sensor_m_flow.portA) annotation (Line(
      points={{-68,120},{-73,120}},
      color={255,153,0},
      thickness=0.5));
  connect(sensor_m_flow.portB, junction5.portA) annotation (Line(
      points={{-79,120},{-80,120},{-80,104}},
      color={255,153,0},
      thickness=0.5));
  connect(wantedTemp.y, PID.u_s) annotation (Line(points={{-163,80},{-66,80},{
          -66,90},{-48,90},{-48,82}},
                                  color={0,0,127}));
  connect(sensor_T.port, junction7.portB) annotation (Line(
      points={{-12,40},{-12,20},{-16,20}},
      color={255,153,0},
      thickness=0.5));
  connect(sensor_T.sensorValue, PID.u_m)
    annotation (Line(points={{-12,46},{-12,70},{-36,70}}, color={0,0,127}));
  connect(PID.y, valve2.KvValue_in)
    annotation (Line(points={{-48,59},{-48,50},{-50,50},{-50,42.75}},
                                                    color={0,0,127}));
  connect(valveRegulator.y, limiter.u) annotation (Line(points={{-119,170},{-82,
          170}},                            color={0,0,127}));
  connect(limiter.y, valve1.KvValue_in) annotation (Line(points={{-59,170},{-42,
          170},{-42,102.75}},                     color={0,0,127}));
  connect(junction5.portC, junction2.portA) annotation (Line(
      points={{-80,96},{-82,96},{-82,-12},{-84,-12},{-84,-16},{-80,-16}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portB, junction6.portA) annotation (Line(
      points={{-76,-20},{-92,-20},{-92,44},{-80,44}},
      color={255,153,0},
      thickness=0.5));
  connect(junction6.portC, tube1.portA) annotation (Line(
      points={{-80,36},{-80,8},{-58,8},{-58,-20}},
      color={255,153,0},
      thickness=0.5));
  connect(junction6.portB, valve2.portA) annotation (Line(
      points={{-76,40},{-74,39},{-56,39}},
      color={255,153,0},
      thickness=0.5));
  annotation (Diagram(coordinateSystem(preserveAspectRatio=false, extent={{-100,
            -100},{100,100}})),
    experiment(
      StopTime=1815,
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
