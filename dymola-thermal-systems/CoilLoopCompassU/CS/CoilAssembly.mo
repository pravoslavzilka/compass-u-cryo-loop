within CoilLoopCompassU.CS;
model CoilAssembly
  outer ThermalSystems.SystemInformationManager sim;
  // ===========================================================================
  // CS single-channel coil (CS2U, CS2L in CSCircuit.mo). Copper channel,
  // 8x6.2mm elliptical cross-section, 86 m, coil weight 349 kg (ATEKO
  // 22172-Z-R1 Tab.2, PFD 22178-3-R0). Same structure as TF's
  // TFCoilBusUpper: no discharge heat pulse (the shot is represented by the
  // elevated wall initial temperature, 137.5K per ATEKO Tab.5), inlet and
  // outlet isolation valves driven by one KvValue_in1 command.
  // ===========================================================================

  parameter Modelica.Units.SI.Length length = 86
    "Channel length -- ATEKO 22172-Z-R1 Tab.2 and PFD 22178-3-R0: 86 m, single channel.";
  parameter Modelica.Units.SI.Diameter diameter = 0.00696025
    "Equivalent diameter, ATEKO Tab.2 -- reference only (Tube derives D_h from crossSectionArea/wettedPerimeter).";
  parameter Modelica.Units.SI.Area crossSectionArea = 38.956e-6
    "8x6.2mm ellipse flow area, pi*4mm*3.1mm.";
  parameter Modelica.Units.SI.Length wettedPerimeter = 22.396e-3
    "8x6.2mm ellipse perimeter (Ramanujan) -- D_h = 6.958mm vs ATEKO Tab.2's 6.960mm.";
  parameter Modelica.Units.SI.Area outerCrossSectionalArea = 491.87e-6
    "Metal + bore area, sized so the modeled copper mass is ATEKO Tab.5's 349 kg: (349/8960)/86 + crossSectionArea.";
  parameter Modelica.Units.SI.CoefficientOfHeatTransfer alphaConstant = 6350
    "Gas-side heat transfer coefficient at the ATEKO Tab.5 design flow 0.0214 kg/s per channel (equal in all 8 CS channels: 8 x 0.0214 = 0.17 kg/s, S6.5.2), Dittus-Boelter scaled from the 0.017 kg/s/5284 W/m2K estimate: 5284*(0.0214/0.017)^0.8. Was 9197, derived for an assumed 0.034 kg/s per single channel; the 2026-09-16 run showed equal per-channel flow in all coils.";
  parameter Modelica.Units.SI.ThermalResistance wallConductionR = 1.806e-5
    "Lumped wall conduction resistance, ln(r2/r1)/(2*pi*k*L), k_Cu=130 W/(m.K) -- ~20x smaller than the convective resistance, so its uncertainty matters little.";
  parameter Integer nChannels = 1 "Number of parallel channels -- 1 per ATEKO Tab.2.";
  parameter Integer nCellsPerTube = 10 "Wall/gas cells along the channel -- same as TF's coil busses.";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1), KvValueFixed fallback only.";
  parameter Real valveKvNominal = 100 "Isolation valve Kv at fully open.";
  parameter Real outletKvRatio = 50
    "Outlet valve Kv = KvValue_in1*outletKvRatio (open: negligible dp; shut: 5e-3) -- same as TFCoilBusUpper: a shut coil is closed at both ends, so its gas is trapped instead of breathing through an open outlet (the reversing-flow chatter TF hit).";
  parameter Real KvFrictionTrim = 0.22
    "Fixed restriction in series with the outlet valve (combined into valve2's Kv: 1/Kv^2 = 1/KvFrictionTrim^2 + 1/(KvValue_in1*outletKvRatio)^2). Konakov is a smooth-tube correlation; the 2026-10-07 run gave 0.77-0.88 of ATEKO Tab.9's channel loss (13.89 bar at 137K, 7.89 bar at 80K, 0.0214 kg/s, Ra<=2um copper). Was 0.34 (sized at the 2026-10-07 run's 0.028-0.045 kg/s); at the design 0.0214 kg/s that is only 1.1 bar, and the 2026-10-08 run gave 6.4 bar header-to-header at 80K vs Tab.9's 7.89. Kv 0.22 gives 2.6 bar at 0.0214 kg/s/47 kg/m3, closing the gap at the cold end.";
  parameter Modelica.Units.SI.Temperature TInitial = 80
    "Initial wall (copper) temperature -- set to 137.5K in CSCircuit.mo (ATEKO Tab.5 coil temperature after a shot).";
  parameter Modelica.Units.SI.Temperature TInitialGas = 80
    "Initial helium temperature in the channel -- CSCircuit.mo sets it to the wall temperature (gas trapped in a shut, hot coil).";
  parameter Modelica.Units.SI.AbsolutePressure pInitial = 8200000 "Initial gas pressure.";
  parameter Integer assemblyIndex = 0
    "Per-instance length offset index -- CS2U/CS2L are otherwise identical branches of the same headers; this breaks the flow-split degeneracy (same fix as TF's TFUL1/TFUL2).";
  final parameter Modelica.Units.SI.Length lengthAdjusted = length*(1 + 1e-5*assemblyIndex)
    "length with a tiny per-instance offset -- see assemblyIndex.";

  output Modelica.Units.SI.Temperature T_wall = tube2.heatPort[1].T "Wall temperature of cell 1 (cold inlet end)";
  output Modelica.Units.SI.Temperature T_wall_max = max(tube2.heatPort.T)
    "Hottest wall cell of the coil.";
  output Modelica.Units.SI.Temperature T_gas_out = tube2.summary.T_gas_B "Helium outlet temperature";
  output Modelica.Units.SI.Temperature T_gas_in = tube2.summary.T_gas_A "Helium inlet temperature";
  output Modelica.Units.SI.MassFlowRate m_flow = tube2.summary.m_flow_gas_B "Coil mass flow";

  ThermalSystems.GasComponents.Tubes.Tube tube2(
    tubeGeometry(
      length=lengthAdjusted,
      nParallelTubes=nChannels,
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
    "Copper channel: gas starts at TInitialGas, wall at TInitial (137.5K in CSCircuit.mo) -- same convention as TF."
    annotation (Placement(transformation(extent={{32,52},{48,56}})));
  ThermalSystems.GasComponents.Valves.Valve valve1(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=valveOpening*valveKvNominal)
    "Inlet ON/OFF valve (CS_V02/CS_V03 on PFD 22178-3-R0)."
    annotation (Placement(transformation(extent={{8,52},{18,58}})));
  ThermalSystems.GasComponents.Valves.Valve valve2(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=true,
    KvValueFixed=valveOpening*valveKvNominal*outletKvRatio)
    "Outlet shut-off valve, driven by the same KvValue_in1 as valve1 (scaled by outletKvRatio)."
    annotation (Placement(transformation(extent={{56,51},{66,57}})));
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
    "Prescribed Kv-value [m^3/h] -- driven by CSCircuit.mo's per-coil isolation logic."
    annotation (Placement(transformation(
        extent={{-20,-20},{20,20}},
        rotation=180,
        origin={104,-66})));
equation
  connect(valve1.portB, tube2.portA) annotation (Line(
      points={{18,55},{18,54},{32,54}},
      color={255,153,0},
      thickness=0.5));
  connect(valve1.portA, portA1) annotation (Line(
      points={{8,55},{-4,55},{-4,36},{-100,36},{-100,0},{-128,0}},
      color={255,153,0},
      thickness=0.5));
  connect(tube2.portB, valve2.portA) annotation (Line(
      points={{48,54},{56,54}},
      color={255,153,0},
      thickness=0.5));
  connect(valve2.portB, portB1) annotation (Line(
      points={{66,54},{74,54},{74,0},{104,0},{104,-2}},
      color={255,153,0},
      thickness=0.5));
  valve2.KvValue_in = 1/sqrt(1/KvFrictionTrim^2 + 1/max(KvValue_in1*outletKvRatio, 1e-12)^2);
  connect(valve1.KvValue_in, KvValue_in1) annotation (Line(points={{13,57.25},
          {13,-66},{104,-66}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end CoilAssembly;
