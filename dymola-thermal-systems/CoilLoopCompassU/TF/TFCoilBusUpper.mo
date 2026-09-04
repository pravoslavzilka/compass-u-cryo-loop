within CoilLoopCompassU.TF;
model TFCoilBusUpper
  "One of the two 'upper limb' TF cooling busses (see TFCircuit.mo) -- 56
  identical, lumped-parallel channels per bus. Geometry FROM SOURCE: ATEKO
  study 22172-Z-R1 Tab.3/S3.3.3 (TF upper limb: 112 channels total,
  equivalent diameter 7.379796 mm, length 7.7 m) -- this bus carries half
  that channel count (56), per the CALCULATED 4-bus split documented in
  docs/design-basis/tf-circulator-sizing.md S1. Same structure as
  TFCoilBusCoreLower, shorter channel length only -- kept as a separate
  model (rather than one model with a length parameter override at the
  instance) to mirror PF's convention of one named model per physically
  distinct coil/bus type (CoilAssembly2ch/3ch/4ch)."
  outer ThermalSystems.SystemInformationManager sim;
  parameter Modelica.Units.SI.Length length = 7.7 "Channel length [m] -- FROM SOURCE, ATEKO 22172-Z-R1 Tab.3 (TF upper limb)";
  parameter Modelica.Units.SI.Diameter diameter = 0.007379796 "Equivalent channel diameter [m] -- FROM SOURCE, ATEKO 22172-Z-R1 Tab.3/S5.2.3 (elliptical 6x10mm, D_eq=7.379796mm)";
  parameter Integer nChannels = 56 "Parallel channel count for this bus -- CALCULATED: 112 upper-limb channels (ATEKO Tab.3) / 2 busses, see tf-circulator-sizing.md S1";
  parameter Modelica.Units.SI.Power dischargeLoad = 0 "Peak discharge heat [W] -- 0, mirrors PFCircuit.mo's convention of zeroing dischargeLoads at circuit level";
  parameter Modelica.Units.SI.Time pulseStart = 5 "Discharge start time";
  parameter Modelica.Units.SI.Time pulseEnd = 10 "Discharge end time";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1)";
  parameter Real valveKvNominal = 100 "Kv value at fully-open (valveOpening=1)";
  parameter Modelica.Units.SI.Temperature TInitial = 80 "Initial coil/gas temperature";

  output Modelica.Units.SI.Temperature T_wall = tube2.heatPort[1].T "Coil wall temperature";
  output Modelica.Units.SI.Temperature T_gas_out = tube2.summary.T_gas_B "Helium outlet temperature";
  output Modelica.Units.SI.Temperature T_gas_in = tube2.summary.T_gas_A "Helium inlet temperature";
  output Modelica.Units.SI.MassFlowRate m_flow = tube2.summary.m_flow_gas_B "Bus mass flow (sum over all nChannels parallel channels)";

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
    nCells=8,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    redeclare model WallMaterial = CoilLoopCompassU.Common.CopperOFHC_Tdep,
    fixedTInitialWall=false,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=2500000,
    TInitial(displayUnit="K") = TInitial,
    TInitialWall(displayUnit="K") = TInitial)
    annotation (Placement(transformation(extent={{32,52},{48,56}})));
  ThermalSystems.GasComponents.Valves.Valve valve1(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=valveOpening*valveKvNominal)
    annotation (Placement(transformation(extent={{8,52},{18,58}})));
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
  Modelica.Blocks.Interfaces.RealInput KvValue_in1
    "Prescribed Kv-value [m^3/h]" annotation (Placement(transformation(
        extent={{-20,-20},{20,20}},
        rotation=180,
        origin={104,-66})));
equation
  connect(stepSource.y, prescribedHeatFlow.Q_flow)
    annotation (Line(points={{-7,72},{16,72}}, color={0,0,127}));
  connect(prescribedHeatFlow.port, tube2.heatPort[1])
    annotation (Line(points={{36,72},{40,72},{40,55.525}},
                                                       color={191,0,0}));
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
  connect(valve1.KvValue_in, KvValue_in1) annotation (Line(points={{13,58.75},
          {13,70},{60,70},{60,-66},{104,-66}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end TFCoilBusUpper;
