within CoilLoopCompassU.CS;
model CoilAssembly2ch
  outer ThermalSystems.SystemInformationManager sim;
  // ===========================================================================
  // CS two-channel coil (CS1, CS3U, CS3L in CSCircuit.mo). Two parallel copper
  // channels, 8x6.2mm elliptical cross-section, coil weight 714 kg (ATEKO
  // 22172-Z-R1 Tab.2, PFD 22178-3-R0). Same structure as TF's coil busses:
  // no discharge heat pulse (the shot is represented by the elevated wall
  // initial temperature, 137.5K per ATEKO Tab.5), inlet and outlet isolation
  // valves driven by one KvValue_in1 command.
  // ===========================================================================

  record ChannelSummary
    Modelica.Units.SI.Temperature T_wall "Coil wall temperature (cell 1)";
    Modelica.Units.SI.Temperature T_wall_max "Hottest wall cell";
    Modelica.Units.SI.Temperature T_gas_out "Helium outlet temperature";
    Modelica.Units.SI.Temperature T_gas_in "Helium inlet temperature";
    Modelica.Units.SI.MassFlowRate m_flow "Channel mass flow";
    Modelica.Units.SI.Length length "Tube length used for this channel";
    Modelica.Units.SI.Diameter diameter "Hydraulic diameter of this channel";
  end ChannelSummary;

  parameter Modelica.Units.SI.Length lengths[2] = {88,88}
    "Per-channel length -- ATEKO 22172-Z-R1 Tab.2: 2 x 88 m for CS1/CS3U/CS3L. PFD 22178-3-R0 draws CS3U/CS3L as 2 x 86 m (CS1 2 x 88 m); Tab.2 is used (same 714 kg for all three) until IPP confirms.";
  parameter Modelica.Units.SI.Area crossSectionArea = 38.956e-6
    "8x6.2mm ellipse flow area, pi*4mm*3.1mm -- see CoilAssembly.mo.";
  parameter Modelica.Units.SI.Length wettedPerimeter = 22.396e-3
    "8x6.2mm ellipse perimeter (Ramanujan) -- see CoilAssembly.mo.";
  parameter Modelica.Units.SI.Area outerCrossSectionalArea = 491.73e-6
    "Metal + bore area per channel, sized so the modeled copper mass is ATEKO Tab.5's 714 kg (357 kg per channel): (357/8960)/88 + crossSectionArea.";
  parameter Modelica.Units.SI.CoefficientOfHeatTransfer alphaConstant = 6350
    "Gas-side heat transfer coefficient at the ATEKO Tab.5 design flow 0.0214 kg/s per channel -- see CoilAssembly.mo (was 5284, derived for an assumed 0.017 kg/s per channel).";
  parameter Modelica.Units.SI.ThermalResistance wallConductionR = 1.764e-5
    "Lumped wall conduction resistance per channel -- see CoilAssembly.mo.";
  parameter Integer nCellsPerTube = 10 "Wall/gas cells along each channel -- same as TF's coil busses.";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1), KvValueFixed fallback only.";
  parameter Real valveKvNominal = 100 "Isolation valve Kv at fully open.";
  parameter Real outletKvRatio = 50
    "Outlet valve Kv = KvValue_in1*outletKvRatio -- see CoilAssembly.mo.";
  parameter Real KvFrictionTrim = 0.44
    "Channel-friction correction to ATEKO Tab.9, combined into valve2's Kv -- see CoilAssembly.mo. 2 x 0.22: valve2 carries both channels, so twice the Kv gives each channel the same extra loss.";
  parameter Modelica.Units.SI.Temperature TInitial = 80
    "Initial wall (copper) temperature -- set to 137.5K in CSCircuit.mo (ATEKO Tab.5).";
  parameter Modelica.Units.SI.Temperature TInitialGas = 80
    "Initial helium temperature -- CSCircuit.mo sets it to the wall temperature (gas trapped in a shut, hot coil).";
  parameter Modelica.Units.SI.AbsolutePressure pInitial = 8200000 "Initial gas pressure.";
  parameter Integer assemblyIndex = 0
    "Unique per-instance index -- gives every channel in the circuit a slightly different length so no two parallel branches are numerically identical (PF/TF anti-degeneracy fix).";

  final parameter Modelica.Units.SI.Diameter dHydraulic = 4*crossSectionArea/wettedPerimeter
    "Hydraulic diameter, for ChannelSummary reporting.";
  final parameter Modelica.Units.SI.Length lengthsAdjusted[2] = {lengths[i]*(1 + 1e-5*(10*assemblyIndex + i)) for i in 1:2}
    "Per-channel length with a tiny offset unique per (assemblyIndex, channel).";

  output Modelica.Units.SI.Temperature T_gas_out = sensor_T.sensorValue
    "Coil gas outlet temperature (both channels mixed)";
  output Modelica.Units.SI.Temperature T_wall_max = max(max(tube1.heatPort.T), max(tube2.heatPort.T))
    "Hottest wall cell of the coil (both channels).";

  output ChannelSummary Channel1(
    T_wall=tube2.heatPort[1].T,
    T_wall_max=max(tube2.heatPort.T),
    T_gas_out=tube2.summary.T_gas_B,
    T_gas_in=tube2.summary.T_gas_A,
    m_flow=tube2.summary.m_flow_gas_B,
    length=lengthsAdjusted[1],
    diameter=dHydraulic) "Channel 1 summary (tube2 branch)";
  output ChannelSummary Channel2(
    T_wall=tube1.heatPort[1].T,
    T_wall_max=max(tube1.heatPort.T),
    T_gas_out=tube1.summary.T_gas_B,
    T_gas_in=tube1.summary.T_gas_A,
    m_flow=tube1.summary.m_flow_gas_B,
    length=lengthsAdjusted[2],
    diameter=dHydraulic) "Channel 2 summary (tube1 branch)";

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
    fixedTInitialWall=false,
    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.0214,
    pInitial=pInitial,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = TInitialGas,
    TInitialWall(displayUnit="K") = TInitial)
    "Channel 1: gas starts at TInitialGas, wall at TInitial (137.5K in CSCircuit.mo)."
    annotation (Placement(transformation(extent={{32,18},{48,22}})));
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
    fixedTInitialWall=false,
    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.0214,
    pInitial=pInitial,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = TInitialGas,
    TInitialWall(displayUnit="K") = TInitial)
    "Channel 2, same as tube2."
    annotation (Placement(transformation(extent={{32,-22},{48,-18}})));
  ThermalSystems.GasComponents.Valves.Valve valve1(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=valveOpening*valveKvNominal)
    "Inlet ON/OFF valve (CS_V01/CS_V04/CS_V05 on PFD 22178-3-R0)."
    annotation (Placement(transformation(extent={{-38,-2},{-28,4}})));
  ThermalSystems.GasComponents.Valves.Valve valve2(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=valveOpening*valveKvNominal*outletKvRatio)
    "Outlet shut-off valve, driven by the same KvValue_in1 as valve1 (scaled by outletKvRatio)."
    annotation (Placement(transformation(extent={{76,-3},{86,3}})));
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
    pInitial=pInitial,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = TInitialGas)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=90,
        origin={20,0})));
  ThermalSystems.GasComponents.JunctionElements.VolumeJunction junction1(
    volume=1e-4,
    m_flowStart=1e-5,
    pInitial=pInitial,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = TInitialGas)
    annotation (Placement(transformation(extent={{-4,-4},{4,4}},
        rotation=-90,
        origin={60,0})));
  ThermalSystems.GasComponents.Sensors.Sensor_T sensor_T
    annotation (Placement(transformation(extent={{66,16},{74,24}})));
  Modelica.Blocks.Interfaces.RealInput KvValue_in1
    "Prescribed Kv-value [m^3/h] -- driven by CSCircuit.mo's per-coil isolation logic."
    annotation (Placement(transformation(
        extent={{-20,-20},{20,20}},
        rotation=180,
        origin={104,-66})));
equation
  connect(valve1.portA, portA1) annotation (Line(
      points={{-38,1},{-114,1},{-114,0},{-128,0}},
      color={255,153,0},
      thickness=0.5));
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
  connect(junction1.portB, valve2.portA) annotation (Line(
      points={{64,0},{76,0}},
      color={255,153,0},
      thickness=0.5));
  connect(valve2.portB, portB1) annotation (Line(
      points={{86,0},{104,0},{104,-2}},
      color={255,153,0},
      thickness=0.5));
  connect(junction1.portB, sensor_T.port) annotation (Line(
      points={{64,0},{70,0},{70,16}},
      color={255,153,0},
      thickness=0.5));
  valve2.KvValue_in = 1/sqrt(1/KvFrictionTrim^2 + 1/max(KvValue_in1*outletKvRatio, 1e-12)^2);
  connect(valve1.KvValue_in, KvValue_in1) annotation (Line(points={{-33,4.75},{
          -34,4.75},{-34,-66},{104,-66}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end CoilAssembly2ch;
