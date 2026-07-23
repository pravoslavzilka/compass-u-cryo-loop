within CoilLoopCompassU.PF;
model  PFCircuit
  extends ThermalSystems.Internals.ClassTypes.ExampleModel;
  parameter Real m_wanted = 0.095 "flow I want in the circuit, kg/s";
  parameter Real m_total = 0.1 "total flow from the pump, kg/s";
  parameter Real u_dead = 1;
  parameter Real Kv_shut = 1e-4;
  parameter Real Kv_cool_max = 5000;
  parameter Real heater_gain = 100;
  parameter Real Kv_gain = 100;
  parameter Real bypass_limit = 10;
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
      condensingIndex=0)) annotation (Placement(transformation(extent={{180,160},
            {200,180}},
                      rotation=0)));

  ThermalSystems.GasComponents.Fans.Fan2ndOrder fan2ndOrder(
    orientation="symmetric",
    use_mechanicalPort=true,
    n_nominal=167,
    dp_nominal(displayUnit="bar") = 1000000,
    V_flow_nominal=0.021,
    V_flow0=0.040,
    T_nominal(displayUnit="K") = 80,
    p_nominal=4000000,
    dpInitial(displayUnit="bar") = 4000000,
    V_flow_Start=0.003)
    annotation (Placement(transformation(extent={{8,-8},{-8,8}},
        rotation=90,
        origin={-60,120})));
  ThermalSystems.OtherComponents.Sources.SmoothStep smoothStep(
    initialValue=167,
    endValue=167,
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
        origin={-50,-30})));
  ThermalSystems.GasComponents.Tubes.Tube tube1(
    tubeGeometry(
      innerDiameter=0.012,
      length=10,
      nParallelTubes=60,
      wallThickness=0.001,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    redeclare model WallMaterial =
        CoilLoopCompassU.Common.StainlessSteel304_Tdep,
    fixedTInitialWall=false,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=4000000,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-8,-2},{8,2}},
        rotation=0,
        origin={-50,-60})));
  ThermalSystems.GasComponents.Volumes.Volume volume(
    volume=0.5,
    m_flowStart=0,
    pInitial=4000000,
    TInitial(displayUnit="K") = 80,
    nPorts=1)
    annotation (Placement(transformation(extent={{-3,-7},{3,7}},
        rotation=0,
        origin={-107,-75})));
  ThermalSystems.GasComponents.Valves.Valve valve(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=3000)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=90,
        origin={-146,-77})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={60,60})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction3(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={140,80})));
  ThermalSystems.GasComponents.Valves.Valve valve1(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
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
        origin={-112,100})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction2(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,4},{4,-4}},
        rotation=270,
        origin={-112,68})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction8(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={80,80})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction9(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={140,40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction10(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={80,40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction11(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={160,60})));
  CoilAssembly2ch PF2U(lengths={80,83},
    dischargeLoads={0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=1)
    annotation (Placement(transformation(extent={{100,20},{120,40}})));
  CoilAssembly2ch PF2L(lengths={80,83},
    dischargeLoads={0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=2)
    annotation (Placement(transformation(extent={{100,40},{120,60}})));
  CoilAssembly4ch PF1L(
    lengths={61,64,70,74},
    dischargeLoads={0,0,0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=3)
    annotation (Placement(transformation(extent={{100,80},{120,100}})));
  CoilAssembly4ch PF1U(
    lengths={61,64,70,74},
    dischargeLoads={0,0,0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=4)
    annotation (Placement(transformation(extent={{100,60},{120,80}})));
  CoilAssembly3ch PF3L(lengths={83,84,87},
    dischargeLoads={0,0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=5)
    annotation (Placement(transformation(extent={{100,0},{120,20}})));
  CoilAssembly3ch PF3U(lengths={83,84,87},
    dischargeLoads={0,0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=6)
    annotation (Placement(transformation(extent={{100,-20},{120,0}})));
  CoilAssembly4ch PF4L(lengths={90,90,90,75}, diameters_mm={9,9,9,9},
    wallThickness=0.0059,
    dischargeLoads={0,0,0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=7)
    annotation (Placement(transformation(extent={{100,-40},{120,-20}})));
  CoilAssembly4ch PF4U(lengths={90,90,90,75}, diameters_mm={9,9,9,9},
    wallThickness=0.0059,
    dischargeLoads={0,0,0,0},
    TInitial(displayUnit="K") = 160,
    assemblyIndex=8)
    annotation (Placement(transformation(extent={{100,-60},{120,-40}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction12(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={60,-20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction13(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={80,0})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction14(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={80,-40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction15(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={140,0})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction16(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={140,-40})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction17(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={160,-20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction18(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={180,20})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction19(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={40,20})));
  Modelica.Blocks.Sources.RealExpression valveRegulator(y=(4.39)*(sensor_m_flow.sensorValue
         - m_wanted)/m_wanted)
    annotation (Placement(transformation(extent={{-140,160},{-120,180}})));
  ThermalSystems.GasComponents.Sensors.Sensor_m_flow sensor_m_flow
    annotation (Placement(transformation(extent={{-72,116},{-80,124}})));
  Modelica.Blocks.Continuous.LimPID PID(
    controllerType=Modelica.Blocks.Types.SimpleController.PI,
    k=0.05,
    Ti=30,
    yMax=60,
    yMin=-60,
    initType=Modelica.Blocks.Types.Init.InitialOutput,
    y_start=5)
            annotation (Placement(transformation(extent={{-10,10},{10,-10}},
        rotation=-90,
        origin={-50,50})));
  Modelica.Blocks.Sources.RealExpression wantedTemp(y=wanted_temp)
    annotation (Placement(transformation(extent={{-156,70},{-136,90}})));
  ThermalSystems.GasComponents.Sensors.Sensor_T sensor_T
    annotation (Placement(transformation(extent={{-16,40},{-8,48}})));
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax=500, uMin=0.001)
    annotation (Placement(transformation(extent={{-80,160},{-60,180}})));
  ThermalSystems.GasComponents.Valves.Valve valve3(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=4000)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=0,
        origin={-26,-59})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction20(
    volume=1e-1,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=180,
        origin={12,120})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction21(
    volume(displayUnit="l") = 0.2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=0,
        origin={12,20})));
  ThermalSystems.GasComponents.Valves.Valve valve4(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
    KvValueFixed=0.0001)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=90,
        origin={12,65})));
  Modelica.Blocks.Sources.RealExpression HeaterLimiter(y=if PID.y > u_dead
         then PID.y*heater_gain else 0)
    annotation (Placement(transformation(extent={{-298,30},{-278,50}})));
  Modelica.Blocks.Sources.RealExpression CoolingLimiter1(y=if PID.y < -u_dead
         then min(-PID.y*Kv_gain, Kv_cool_max) else Kv_shut)
    annotation (Placement(transformation(extent={{-226,-54},{-206,-34}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction7(
    volume=1e-2,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=270,
        origin={-112,-6})));
  ThermalSystems.GasComponents.Valves.Valve valve5(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=500)
    annotation (Placement(transformation(extent={{-6,-3},{6,3}},
        rotation=0,
        origin={-74,-5})));
  ThermalSystems.GasComponents.Valves.Valve valve6(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=5000)
    annotation (Placement(transformation(extent={{-6,3},{6,-3}},
        rotation=-90,
        origin={-112,-25})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction23(
    volume(displayUnit="l") = 0.1,
    m_flowStart=1e-5,
    pInitial=4000000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,4},{4,-4}},
        rotation=270,
        origin={-12,-6})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder(T=2)
    annotation (Placement(transformation(extent={{-192,-54},{-172,-34}})));
  ThermalSystems.GasComponents.Tubes.Tube Heater(
    tubeGeometry(
      innerDiameter=0.04,
      length=4,
      nParallelTubes=1,
      wallThickness=0.001,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    redeclare model WallMaterial =
        CoilLoopCompassU.Common.StainlessSteel304_Tdep,
    fixedTInitialWall=false,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=4000000,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = 80) annotation (Placement(transformation(
        extent={{8,-2},{-8,2}},
        rotation=90,
        origin={-114,40})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow1
    annotation (Placement(transformation(extent={{-200,30},{-180,50}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder1(T=1)
    annotation (Placement(transformation(extent={{-248,30},{-228,50}})));
  Modelica.Blocks.Sources.RealExpression BypassLimiter(y=if PID.y < -
        bypass_limit then max(500 - PID.y*10, Kv_shut) else 500)
    annotation (Placement(transformation(extent={{-242,-2},{-222,18}})));
  Modelica.Blocks.Continuous.FirstOrder firstOrder2(T=1)
    annotation (Placement(transformation(extent={{-192,-2},{-172,18}})));
equation

  connect(smoothStep.y,rotatoryBoundary. n_in)
    annotation (Line(points={{-123.4,142},{-60,142},{-60,135}},
                                                     color={0,0,127}));
  connect(rotatoryBoundary.rotatoryFlange, fan2ndOrder.rotatoryFlange)
    annotation (Line(
      points={{-60,131},{-60,128}},
      color={135,135,135},
      thickness=0.5));
  connect(coldSurface.port, tube1.heatPort[1]) annotation (Line(points={{-50,-40},
          {-50,-58}},                           color={191,0,0}));
  connect(volume.portArray[1], valve.portA) annotation (Line(
      points={{-107,-81.825},{-106,-81.825},{-106,-96},{-146,-96},{-146,-83}},
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
      points={{-48,99},{-50,100},{-108,100}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portC, junction8.portB) annotation (Line(
      points={{60,64},{60,80},{76,80}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portA, junction10.portB) annotation (Line(
      points={{60,56},{60,40},{76,40}},
      color={255,153,0},
      thickness=0.5));
  connect(junction3.portB, junction11.portA) annotation (Line(
      points={{144,80},{160,80},{160,64}},
      color={255,153,0},
      thickness=0.5));
  connect(junction9.portB, junction11.portC) annotation (Line(
      points={{144,40},{160,40},{160,56}},
      color={255,153,0},
      thickness=0.5));
  connect(junction10.portA, PF2U.portA1) annotation (Line(
      points={{80,36},{80,30},{97.2,30}},
      color={255,153,0},
      thickness=0.5));
  connect(PF2U.portB1, junction9.portC) annotation (Line(
      points={{120.4,29.8},{140,29.8},{140,36}},
      color={255,153,0},
      thickness=0.5));
  connect(junction10.portC, PF2L.portA1) annotation (Line(
      points={{80,44},{80,50},{97.2,50}},
      color={255,153,0},
      thickness=0.5));
  connect(PF2L.portB1, junction9.portA) annotation (Line(
      points={{120.4,49.8},{140,49.8},{140,44}},
      color={255,153,0},
      thickness=0.5));
  connect(junction8.portC, PF1L.portA1) annotation (Line(
      points={{80,84},{80,90},{97.2,90}},
      color={255,153,0},
      thickness=0.5));
  connect(junction8.portA, PF1U.portA1) annotation (Line(
      points={{80,76},{80,70},{97.2,70}},
      color={255,153,0},
      thickness=0.5));
  connect(PF1U.portB1, junction3.portC) annotation (Line(
      points={{120.4,69.8},{140,69.8},{140,76}},
      color={255,153,0},
      thickness=0.5));
  connect(PF1L.portB1, junction3.portA) annotation (Line(
      points={{120.4,89.8},{140,89.8},{140,84}},
      color={255,153,0},
      thickness=0.5));
  connect(junction12.portC, junction13.portB) annotation (Line(
      points={{60,-16},{60,0},{76,0}},
      color={255,153,0},
      thickness=0.5));
  connect(junction12.portA, junction14.portB) annotation (Line(
      points={{60,-24},{60,-40},{76,-40}},
      color={255,153,0},
      thickness=0.5));
  connect(junction15.portB, junction17.portA) annotation (Line(
      points={{144,0},{160,0},{160,-16}},
      color={255,153,0},
      thickness=0.5));
  connect(junction16.portB, junction17.portC) annotation (Line(
      points={{144,-40},{160,-40},{160,-24}},
      color={255,153,0},
      thickness=0.5));
  connect(junction17.portB, junction18.portC) annotation (Line(
      points={{164,-20},{180,-20},{180,16}},
      color={255,153,0},
      thickness=0.5));
  connect(junction11.portB, junction18.portA) annotation (Line(
      points={{164,60},{180,60},{180,24}},
      color={255,153,0},
      thickness=0.5));
  connect(junction13.portC, PF3L.portA1) annotation (Line(
      points={{80,4},{80,10},{97.2,10}},
      color={255,153,0},
      thickness=0.5));
  connect(junction13.portA, PF3U.portA1) annotation (Line(
      points={{80,-4},{80,-10},{97.2,-10}},
      color={255,153,0},
      thickness=0.5));
  connect(junction14.portC, PF4L.portA1) annotation (Line(
      points={{80,-36},{80,-30},{97.2,-30}},
      color={255,153,0},
      thickness=0.5));
  connect(junction14.portA, PF4U.portA1) annotation (Line(
      points={{80,-44},{80,-50},{97.2,-50}},
      color={255,153,0},
      thickness=0.5));
  connect(PF4U.portB1, junction16.portC) annotation (Line(
      points={{120.4,-50.2},{140,-50.2},{140,-44}},
      color={255,153,0},
      thickness=0.5));
  connect(PF4L.portB1, junction16.portA) annotation (Line(
      points={{120.4,-30.2},{140,-30.2},{140,-36}},
      color={255,153,0},
      thickness=0.5));
  connect(PF3U.portB1, junction15.portC) annotation (Line(
      points={{120.4,-10.2},{140,-10.2},{140,-4}},
      color={255,153,0},
      thickness=0.5));
  connect(PF3L.portB1, junction15.portA) annotation (Line(
      points={{120.4,9.8},{140,9.8},{140,4}},
      color={255,153,0},
      thickness=0.5));
  connect(junction19.portC, junction1.portB) annotation (Line(
      points={{40,24},{40,60},{56,60}},
      color={255,153,0},
      thickness=0.5));
  connect(junction19.portA, junction12.portB) annotation (Line(
      points={{40,16},{40,-20},{56,-20}},
      color={255,153,0},
      thickness=0.5));
  connect(fan2ndOrder.portB, sensor_m_flow.portA) annotation (Line(
      points={{-68,120},{-73,120}},
      color={255,153,0},
      thickness=0.5));
  connect(sensor_m_flow.portB, junction5.portA) annotation (Line(
      points={{-79,120},{-112,120},{-112,104}},
      color={255,153,0},
      thickness=0.5));
  connect(wantedTemp.y, PID.u_s) annotation (Line(points={{-135,80},{-50,80},{-50,
          62}},                   color={0,0,127}));
  connect(sensor_T.sensorValue, PID.u_m)
    annotation (Line(points={{-12,46},{-30,46},{-30,50},{-38,50}},
                                                          color={0,0,127}));
  connect(valveRegulator.y, limiter.u) annotation (Line(points={{-119,170},{-82,
          170}},                            color={0,0,127}));
  connect(limiter.y, valve1.KvValue_in) annotation (Line(points={{-59,170},{-42,
          170},{-42,102.75}},                     color={0,0,127}));
  connect(tube1.portB, valve3.portA) annotation (Line(
      points={{-42,-60},{-42,-59},{-32,-59}},
      color={255,153,0},
      thickness=0.5));
  connect(junction21.portC, junction19.portB) annotation (Line(
      points={{16,20},{36,20}},
      color={255,153,0},
      thickness=0.5));
  connect(junction21.portB, valve4.portA) annotation (Line(
      points={{12,24},{12,59}},
      color={255,153,0},
      thickness=0.5));
  connect(valve4.portB, junction20.portB) annotation (Line(
      points={{12,71},{12,116}},
      color={255,153,0},
      thickness=0.5));
  connect(junction20.portC, junction4.portA) annotation (Line(
      points={{8,120},{-16,120}},
      color={255,153,0},
      thickness=0.5));
  connect(junction20.portA, junction18.portB) annotation (Line(
      points={{16,120},{200,120},{200,20},{184,20}},
      color={255,153,0},
      thickness=0.5));
  connect(valve.portB, junction2.portB) annotation (Line(
      points={{-146,-71},{-146,68},{-116,68}},
      color={255,153,0},
      thickness=0.5));
  connect(junction7.portC, valve6.portA) annotation (Line(
      points={{-112,-10},{-112,-19}},
      color={255,153,0},
      thickness=0.5));
  connect(valve6.portB, tube1.portA) annotation (Line(
      points={{-112,-31},{-112,-60},{-58,-60}},
      color={255,153,0},
      thickness=0.5));
  connect(junction7.portB, valve5.portA) annotation (Line(
      points={{-108,-6},{-106,-5},{-80,-5}},
      color={255,153,0},
      thickness=0.5));
  connect(valve3.portB, junction23.portC) annotation (Line(
      points={{-20,-59},{-12,-59},{-12,-10}},
      color={255,153,0},
      thickness=0.5));
  connect(valve5.portB, junction23.portB) annotation (Line(
      points={{-68,-5},{-20,-5},{-20,-6},{-16,-6}},
      color={255,153,0},
      thickness=0.5));
  connect(junction5.portC, junction2.portA) annotation (Line(
      points={{-112,96},{-112,72}},
      color={255,153,0},
      thickness=0.5));
  connect(CoolingLimiter1.y, firstOrder.u)
    annotation (Line(points={{-205,-44},{-194,-44}}, color={0,0,127}));
  connect(firstOrder.y, valve6.KvValue_in) annotation (Line(points={{-171,-44},{
          -120,-44},{-120,-25},{-115.75,-25}}, color={0,0,127}));
  connect(HeaterLimiter.y, firstOrder1.u)
    annotation (Line(points={{-277,40},{-250,40}}, color={0,0,127}));
  connect(firstOrder1.y, prescribedHeatFlow1.Q_flow)
    annotation (Line(points={{-227,40},{-200,40}},color={0,0,127}));
  connect(junction2.portC, Heater.portA) annotation (Line(
      points={{-112,64},{-112,52},{-114,52},{-114,48}},
      color={255,153,0},
      thickness=0.5));
  connect(Heater.portB, junction7.portA) annotation (Line(
      points={{-114,32},{-114,2},{-112,2},{-112,-2}},
      color={255,153,0},
      thickness=0.5));
  connect(junction23.portA, junction21.portA) annotation (Line(
      points={{-12,-2},{-12,20},{8,20}},
      color={255,153,0},
      thickness=0.5));
  connect(junction23.portA, sensor_T.port) annotation (Line(
      points={{-12,-2},{-12,40}},
      color={255,153,0},
      thickness=0.5));
  connect(prescribedHeatFlow1.port, Heater.heatPort[1])
    annotation (Line(points={{-180,40},{-116,40}}, color={191,0,0}));
  connect(BypassLimiter.y, firstOrder2.u)
    annotation (Line(points={{-221,8},{-194,8}}, color={0,0,127}));
  connect(firstOrder2.y, valve5.KvValue_in)
    annotation (Line(points={{-171,8},{-74,8},{-74,-1.25}}, color={0,0,127}));
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
