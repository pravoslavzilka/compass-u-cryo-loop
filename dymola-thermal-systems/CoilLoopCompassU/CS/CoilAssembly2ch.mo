within CoilLoopCompassU.CS;
model CoilAssembly2ch
  outer ThermalSystems.SystemInformationManager sim;

  record ChannelSummary
    Modelica.Units.SI.Temperature T_wall "Coil wall temperature";
    Modelica.Units.SI.Temperature T_gas_out "Helium outlet temperature";
    Modelica.Units.SI.Temperature T_gas_in "Helium inlet temperature";
    Modelica.Units.SI.MassFlowRate m_flow "Coil mass flow";
    Modelica.Units.SI.Length length "Tube length used for this channel";
    Modelica.Units.SI.Diameter diameter "Tube inner diameter used for this channel";
  end ChannelSummary;

  parameter Modelica.Units.SI.Length lengths[2] = {88,88}
    "Per-channel tube length [m] (Channel1, Channel2) -- ATEKO 22172-Z-R1 Tab.2: CS1/CS3U/CS3L are each 2 channels of 88 m, unlike PF's asymmetric per-channel lengths";
  parameter Real diameters_mm[2](each unit="mm") = {6.96025,6.96025}
    "Per-channel equivalent diameter [mm] (Channel1, Channel2) -- reference only, not fed into tube1/tube2 (superseded by crossSectionArea/outerCrossSectionalArea below, same as CoilAssembly.mo/TF's convention). ATEKO Tab.2 'Ekvivalent diameter' for the elliptical 8x6.2mm CS channel cross-section -- consistent with crossSectionArea/wettedPerimeter's directly-computed Dh=6.9584mm to within ~0.03mm.";
  parameter Modelica.Units.SI.Area crossSectionArea = 38.956e-6
    "[CALCULATED] Elliptical channel flow area, shared by both channels (same 8x6.2mm ellipse per ATEKO Tab.2 as CS2U/CS2L) -- see CoilAssembly.mo's docstring for the pi*a*b derivation and cross-check against TF's own 6x10mm ellipse.";
  parameter Modelica.Units.SI.Length wettedPerimeter = 22.396e-3
    "[CALCULATED] Elliptical channel wetted perimeter -- see CoilAssembly.mo's docstring (Ramanujan approximation).";
  parameter Modelica.Units.SI.Area outerCrossSectionalArea = 491.73e-6
    "[CALCULATED] Outer cross-sectional area per channel, sized so modeled copper mass matches ATEKO Tab.5's real CS1/CS3U/CS3L coil weight (714kg total, split evenly across the 2 channels -> 357kg/channel, same even-split convention as dischargeLoads below), length 88m, d_Cu=8960 kg/m3: copperArea=(357/8960)/88=452.77e-6 m^2; outerCrossSectionalArea=crossSectionArea+copperArea=491.73e-6 m^2. Same method as CoilAssembly.mo/TF's acba24f fix. Old wallThickness=0.00488m default (circular approximation) gave ~286kg total for both channels -- roughly 2.5x too little copper thermal mass versus the real 714kg.";
  parameter Modelica.Units.SI.CoefficientOfHeatTransfer alphaConstant = 5284
    "[CALCULATED] Gas-side convective heat transfer coefficient, Dittus-Boelter estimate at design flow: mdot_per_channel = (0.17 kg/s total design flow / 5 coil branches) / 2 channels = 0.017 kg/s. Scaled from TF's own reverse-engineered TFCoilBusCoreLower value the same way as CoilAssembly.mo's alphaConstant -- see its docstring for the full method and the TF-internal cross-check.";
  parameter Modelica.Units.SI.ThermalResistance wallConductionR = 1.764e-5
    "[CALCULATED] Lumped wall conduction resistance per channel -- same method as CoilAssembly.mo's wallConductionR (area-equivalent circular radii, k_Cu=130 W/(m.K) reverse-engineered from TF's own two bus instances).";
  parameter Modelica.Units.SI.Power dischargeLoads[2] = {1600000,1600000}
    "Per-channel peak discharge heat [W] (Channel1, Channel2) -- CS1/CS3U/CS3L max deposited energy per coil is 16 MJ (ATEKO Tab.2), split evenly across 2 channels and divided by a 5s pulse window carried from PF's own CoilAssembly2ch.mo convention, not a CS-specific sourced transient shape -- see docs/design-basis/cs-circulator-sizing.md Open Items";
  parameter Modelica.Units.SI.Time pulseStart = 5 "Discharge start time (after fan finishes accelerating)";
  parameter Modelica.Units.SI.Time pulseEnd = 10 "Discharge end time (5s heat shock)";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1)";
  parameter Real valveKvNominal = 100 "Kv value at fully-open (valveOpening=1)";
  parameter Modelica.Units.SI.Temperature TInitial = 80 "Initial coil/gas temperature";
  parameter Integer assemblyIndex = 0
    "Unique index of this coil-assembly instance among all assemblies in the circuit (no physical meaning, only makes the anti-degeneracy offset below unique circuit-wide instead of just within this instance) -- carried from PF's CoilAssembly2ch.mo, same numerical-degeneracy rationale applies here";
  parameter Integer nCellsPerTube = 1
    "Per-tube wall/gas discretization cell count for this coil assembly instance only -- carried from PF's CoilAssembly2ch.mo (see its docstring: project memory on nCells>1 circuit-wide Newton failures)";

  final parameter Modelica.Units.SI.Diameter dHydraulic = 4*crossSectionArea/wettedPerimeter
    "Hydraulic diameter computed directly from the real ellipse, used only for ChannelSummary reporting below (reference, matches diameters_mm to ~0.03mm).";
  final parameter Modelica.Units.SI.Length lengthsAdjusted[2] = {lengths[i]*(1 + 1e-5*(10*assemblyIndex + i)) for i in 1:2}
    "Per-channel length with a tiny (<=0.09%) offset, unique per (assemblyIndex, channel) pair, so no two branches anywhere in the circuit are numerically identical and create a degenerate flow split";

  output Modelica.Units.SI.Temperature T_gas_out = sensor_T.sensorValue
    "Coil assembly gas outlet temperature";

  output ChannelSummary Channel1(
    T_wall=tube2.heatPort[1].T,
    T_gas_out=tube2.summary.T_gas_B,
    T_gas_in=tube2.summary.T_gas_A,
    m_flow=tube2.summary.m_flow_gas_B,
    length=lengthsAdjusted[1],
    diameter=dHydraulic) "Channel 1 summary (tube2 branch)";
  output ChannelSummary Channel2(
    T_wall=tube1.heatPort[1].T,
    T_gas_out=tube1.summary.T_gas_B,
    T_gas_in=tube1.summary.T_gas_A,
    m_flow=tube1.summary.m_flow_gas_B,
    length=lengthsAdjusted[2],
    diameter=dHydraulic) "Channel 2 summary (tube1 branch)";

  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow
    annotation (Placement(transformation(extent={{16,74},{36,94}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[1],0})
    annotation (Placement(transformation(extent={{-20,78},{-8,90}})));
  ThermalSystems.GasComponents.Tubes.Tube tube2(
    tubeGeometry(
      length=lengthsAdjusted[1],
      nParallelTubes=1,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.NonCircular,
      innerCrossSectionalAreaNonCircular=crossSectionArea,
      outerCrossSectionalAreaNonCircular=outerCrossSectionalArea,
      innerPerimeterNonCircular=wettedPerimeter),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    nCells=nCellsPerTube,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.ConstantAlpha
        (constantAlpha=alphaConstant),
    redeclare model WallHeatConductionModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.WallHeatTransfer.ConstantR
        (constantR=wallConductionR),
    redeclare model WallMaterial = CoilLoopCompassU.Common.CopperOFHC_Tdep,
    fixedTInitialWall=true,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=8200000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = TInitial,
    TInitialWall(displayUnit="K") = TInitial)
    "NonCircular geometry (real 8x6.2mm ellipse) with ConstantAlpha/ConstantR heat transfer -- same combination as CoilAssembly.mo/TF, since the library's geometry-based correlations (GnielinskiDittusBoelter, used here previously) only support circular tubes."
    annotation (Placement(transformation(extent={{32,18},{48,22}})));
  ThermalSystems.GasComponents.Valves.Valve valve1(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=valveOpening*valveKvNominal)
    annotation (Placement(transformation(extent={{-38,-2},{-28,4}})));
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
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction2(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=8200000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={20,0})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow prescribedHeatFlow1
    annotation (Placement(transformation(extent={{4,52},{24,72}})));
  ThermalSystems.OtherComponents.Sources.StepSource stepSource1(
    transitionTime=0.5,
    stepTimes={pulseStart,pulseEnd},
    stepValues={dischargeLoads[2],0})
    annotation (Placement(transformation(extent={{-32,56},{-20,68}})));
  ThermalSystems.GasComponents.Tubes.Tube tube1(
    tubeGeometry(
      length=lengthsAdjusted[2],
      nParallelTubes=1,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.NonCircular,
      innerCrossSectionalAreaNonCircular=crossSectionArea,
      outerCrossSectionalAreaNonCircular=outerCrossSectionalArea,
      innerPerimeterNonCircular=wettedPerimeter),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    nCells=nCellsPerTube,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.ConstantAlpha
        (constantAlpha=alphaConstant),
    redeclare model WallHeatConductionModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.WallHeatTransfer.ConstantR
        (constantR=wallConductionR),
    redeclare model WallMaterial = CoilLoopCompassU.Common.CopperOFHC_Tdep,
    fixedTInitialWall=true,

    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.003,
    pInitial=8200000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = TInitial,
    TInitialWall(displayUnit="K") = TInitial)
    "NonCircular geometry with ConstantAlpha/ConstantR heat transfer -- see tube2's docstring."
    annotation (Placement(transformation(extent={{32,-22},{48,-18}})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=8200000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = 80)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={60,0})));
  ThermalSystems.GasComponents.Sensors.Sensor_T sensor_T
    annotation (Placement(transformation(extent={{76,16},{84,24}})));
  Modelica.Blocks.Interfaces.RealInput KvValue_in1
    "Prescribed Kv-value [m^3/h]" annotation (Placement(transformation(
        extent={{-20,-20},{20,20}},
        rotation=180,
        origin={104,-66})));
equation
  connect(stepSource.y, prescribedHeatFlow.Q_flow)
    annotation (Line(points={{-7,84},{16,84}}, color={0,0,127}));
  connect(prescribedHeatFlow.port, tube2.heatPort[1])
    annotation (Line(points={{36,84},{40,84},{40,21.6}},
                                                       color={191,0,0}));
  connect(valve1.portA, portA1) annotation (Line(
      points={{-38,1},{-114,1},{-114,0},{-128,0}},
      color={255,153,0},
      thickness=0.5));
  connect(stepSource1.y, prescribedHeatFlow1.Q_flow)
    annotation (Line(points={{-19,62},{4,62}},   color={0,0,127}));
  connect(prescribedHeatFlow1.port, tube1.heatPort[1]) annotation (Line(points={{24,62},
          {28,62},{28,-14},{40,-14},{40,-18.4}},     color={191,0,0}));
  connect(junction2.portC, tube2.portA) annotation (Line(
      points={{20,4},{20,20},{32,20}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portA, tube1.portA) annotation (Line(
      points={{20,-4},{20,-20},{32,-20}},
      color={255,153,0},
      thickness=0.5));
  connect(junction2.portB, valve1.portB) annotation (Line(
      points={{16,0},{-22,0},{-22,1},{-28,1}},
      color={255,153,0},
      thickness=0.5));
  connect(tube2.portB, junction1.portA) annotation (Line(
      points={{48,20},{60,20},{60,4}},
      color={255,153,0},
      thickness=0.5));
  connect(tube1.portB, junction1.portC) annotation (Line(
      points={{48,-20},{60,-20},{60,-4}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portB, portB1) annotation (Line(
      points={{64,0},{90,0},{90,-2},{104,-2}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portB, sensor_T.port) annotation (Line(
      points={{64,0},{80,0},{80,16}},
      color={255,153,0},
      thickness=0.5));
  connect(valve1.KvValue_in, KvValue_in1) annotation (Line(points={{-33,4.75},{
          -34,4.75},{-34,-66},{104,-66}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end CoilAssembly2ch;
