within CoilLoopCompassU.TF;
model TFCoilBusUpper
  outer ThermalSystems.SystemInformationManager sim;
  // ===========================================================================
  // TF "upper limb" coil bus. Two parallel busses (TFUL1, TFUL2 in
  // TFCircuit.mo), each 56 channels (112 total). Geometry: copper channels,
  // 6x10mm elliptical cross-section, hydraulic diameter 7.38mm, length 7.7m,
  // total coil weight 7808kg (3904kg/bus) (ATEKO 22172-Z-R1 Tab.3, S5.2.3,
  // PFD 22179-0-R0).
  // ===========================================================================

  parameter Modelica.Units.SI.Length length = 7.7 "Channel length.";
  parameter Modelica.Units.SI.Diameter diameter = 0.007379796
    "Hydraulic diameter D_h -- reference value only (Tube derives D_h itself from crossSectionArea/wettedPerimeter for the NonCircular geometry below).";
  parameter Modelica.Units.SI.Area crossSectionArea = 47.12e-6
    "Elliptical channel flow area (6x10mm ellipse).";
  parameter Modelica.Units.SI.Length wettedPerimeter = 25.53e-3
    "Elliptical channel wetted perimeter.";
  parameter Modelica.Units.SI.Area outerCrossSectionalArea = 0.0010576
    "Outer cross-sectional area of one channel (metal + bore), sized so the total modeled copper mass equals 7808kg across all 112 channels (69.71kg/channel, applied per-bus).";
  parameter Modelica.Units.SI.CoefficientOfHeatTransfer alphaConstant = 1899
    "Gas-side convective heat transfer coefficient, Dittus-Boelter estimate at this bus's design flow (56 channels/bus).";
  parameter Modelica.Units.SI.ThermalResistance wallConductionR = 4.947e-6
    "Lumped wall conduction resistance for one 56-channel bus.";
  parameter Integer nChannels = 56 "Number of parallel channels in this bus (112 total across TFUL1+TFUL2).";
  parameter Modelica.Units.SI.Length roughness = 2e-6 "Channel wall roughness (copper).";
  parameter Modelica.Units.SI.Power dischargeLoad = 0
    "Discharge heat load -- 0, coil thermal mass is represented via elevated wall initial temperature instead of a heat pulse.";
  parameter Modelica.Units.SI.Time pulseStart = 5 "Discharge start time -- unused while dischargeLoad=0.";
  parameter Modelica.Units.SI.Time pulseEnd = 10 "Discharge end time -- unused while dischargeLoad=0.";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1), KvValueFixed fallback -- TFCircuit.mo drives the valve dynamically via KvValue_in1.";
  parameter Real valveKvNominal = 100 "Isolation valve Kv at fully open.";
  parameter Modelica.Units.SI.Temperature TInitial = 80
    "Initial wall (metal) temperature -- overridden at the TFCircuit.mo instantiation. Coolant (gas) initial temperature is fixed at 80K independently, see tube2.";
  parameter Integer assemblyIndex = 0
    "Per-instance length offset index -- TFUL1/TFUL2 draw from the same header with otherwise-identical parameters; this breaks the flow-split degeneracy between them.";
  parameter Modelica.Units.SI.Thickness wallThickness = 0.014620
    "Equivalent wall thickness for 7808kg on a hydraulic-diameter basis -- reference only, not fed into tube2 (superseded by outerCrossSectionalArea).";

  final parameter Modelica.Units.SI.Length lengthAdjusted = length*(1 + 1e-5*assemblyIndex)
    "length with a tiny per-instance offset -- see assemblyIndex.";

  output Modelica.Units.SI.Temperature T_wall = tube2.heatPort[1].T "Coil wall temperature";
  output Modelica.Units.SI.Temperature T_gas_out = tube2.summary.T_gas_B "Helium outlet temperature";
  output Modelica.Units.SI.Temperature T_gas_in = tube2.summary.T_gas_A "Helium inlet temperature";
  output Modelica.Units.SI.MassFlowRate m_flow = tube2.summary.m_flow_gas_B "Bus mass flow (all 56 lumped channels)";

  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow
    annotation (Placement(transformation(extent={{16,62},{36,82}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoad,0})
    annotation (Placement(transformation(extent={{-20,66},{-8,78}})));
  ThermalSystems.GasComponents.Tubes.Tube tube2(
    tubeGeometry(
      length=lengthAdjusted,
      nParallelTubes=nChannels,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.NonCircular,
      innerCrossSectionalAreaNonCircular=crossSectionArea,
      outerCrossSectionalAreaNonCircular=outerCrossSectionalArea,
      innerPerimeterNonCircular=wettedPerimeter),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    nCells=10,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.ConstantAlpha
        (constantAlpha=alphaConstant),
    redeclare model WallHeatConductionModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.WallHeatTransfer.ConstantR
        (constantR=wallConductionR),
    redeclare model WallMaterial = CoilLoopCompassU.Common.CopperOFHC_RRR30_Tdep,
    fixedTInitialWall=false,
    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.325,
    pInitial=2500000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80,
    TInitialWall(displayUnit="K") = TInitial)
    "Wall material OFHC copper, RRR~30. Coolant (gas) initial temperature fixed at 80K; wall initial temperature follows TInitial (137K at the TFCircuit.mo instantiation)."
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
    "Prescribed Kv-value [m^3/h] -- driven by TFCircuit.mo's per-bus isolation logic."
    annotation (Placement(transformation(
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
  connect(valve1.KvValue_in, KvValue_in1) annotation (Line(points={{13,57.25},
          {13,-66},{104,-66}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end TFCoilBusUpper;
