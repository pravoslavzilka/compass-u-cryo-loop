within CoilLoopCompassU.TF;
model TFStructure
  outer ThermalSystems.SystemInformationManager sim;
  // ===========================================================================
  // Replaces TFCL2 (formerly a second TFCoilBusCoreLower instance) at the same
  // junctionCL/junctionReturnCL header. NOT the ATEKO channel geometry used by
  // TFCoilBusCoreLower/TFCoilBusUpper -- this represents the TF coil case /
  // support structure itself (316LN stainless, per ATEKO S6.1's "support
  // structure has huge weight"), a single lumped cooling-channel network
  // through that structure rather than the 6x10mm elliptical copper channels
  // used elsewhere. Geometry below is USER-SUPPLIED (not independently
  // reconciled against ATEKO source tables) -- see each parameter's docstring.
  // ===========================================================================

  parameter Modelica.Units.SI.Length length = 3.5
    "Channel length -- USER-SUPPLIED.";
  parameter Modelica.Units.SI.Diameter diameter = 0.020
    "Channel (bore) diameter -- USER-SUPPLIED.";
  parameter Integer nChannels = 120
    "Number of parallel channels lumped into this structure's single Tube (affects flow area) -- USER-SUPPLIED (nParallel).";
  parameter Modelica.Units.SI.Length roughness = 12.5e-6
    "Channel wall roughness -- USER-SUPPLIED (12.5 um), currently UNUSED. Confirmed at translate-check that ThermalSystems.GasComponents.Tubes.Geometry.TubeGeometry (1.13.0) has no roughness field, so it cannot be wired into tubeGeometry as guessed before. Plausible reason: the PressureDropModel in use here (Konakov) is a smooth-pipe correlation (f = (1.8*log10(Re)-1.5)^-2, Re-only, no roughness term), so there may be no roughness input anywhere on this component for that correlation choice -- a rough-pipe correlation (Colebrook/Haaland or similar, if the ThermalSystems library offers one) would be needed to make this parameter have any effect. Left declared (unconnected) so the requested value isn't lost; wire it in once the right consumer is identified.";
  parameter Modelica.Units.SI.Power dischargeLoad = 0
    "Peak discharge heat [W] -- 0 (heat load removed), same convention as TFCoilBusCoreLower/TFCoilBusUpper: stored thermal energy is represented via TInitial (overridden to 137K at the TFCircuit.mo instantiation) instead of a discharge pulse.";
  parameter Modelica.Units.SI.Time pulseStart = 5 "Discharge start time -- unused while dischargeLoad=0.";
  parameter Modelica.Units.SI.Time pulseEnd = 10 "Discharge end time -- unused while dischargeLoad=0.";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1), used only as the KvValueFixed fallback -- TFCircuit.mo drives this valve dynamically via KvValue_in1.";
  parameter Real valveKvNominal = 100 "Kv value at fully-open (valveOpening=1) -- ASSUMED, carried from PF/CS, no TF-specific valve Cv data found.";
  parameter Modelica.Units.SI.Temperature TInitial = 80 "Initial coil/gas temperature -- overridden to 137K at the TFCircuit.mo instantiation (stands in for the discharge heat load, which is set to 0 here).";
  parameter Integer assemblyIndex = 2
    "Unique index of this instance among all 4 TF busses/structures (no physical meaning) -- carried over from the TFCL2 instance this model replaces, at the same junctionCL header; this tiny per-instance length offset (see lengthAdjusted) breaks the symmetric-parallel-branch flow-split degeneracy against TFCL1, same role as in TFCoilBusCoreLower/TFCoilBusUpper.";
  parameter Modelica.Units.SI.Thickness wallThickness = 0.144220
    "CALCULATED so tube2's modeled 316LN mass (density 8000 kg/m3 x annulus volume x nChannels) equals the USER-SUPPLIED target wall mass of 250,000 kg: annulus OD solved from 120 * 8000 * 3.5 * (pi/4) * (OD^2 - 0.020^2) = 250000 -> OD=0.308440m -> wallThickness=(OD-diameter)/2=0.144220m. See TFCoilBusCoreLower's docstring for why the Tube model's 0.5mm library default is wrong for a structure like this (thin-walled-pipe assumption, ~122x too little thermal mass in that case) -- same reasoning applies here, more so given the scale. Does not affect flow/pressure drop (those use innerDiameter only).";

  final parameter Modelica.Units.SI.Length lengthAdjusted = length*(1 + 1e-5*assemblyIndex)
    "length with a tiny (<=0.006% for assemblyIndex=2) per-instance offset -- see assemblyIndex.";

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
      innerDiameter=diameter,
      length=lengthAdjusted,
      nParallelTubes=nChannels,
      wallThickness=wallThickness,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    nCells=10,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    redeclare model WallMaterial = CoilLoopCompassU.Common.StainlessSteel316LN_Tdep,
    fixedTInitialWall=false,
    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.325,
    pInitial=2500000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = TInitial,
    TInitialWall(displayUnit="K") = TInitial)
    "Wall material 316LN stainless (USER-SUPPLIED, see StainlessSteel316LN_Tdep). nCells=10 axial cells per USER-SUPPLIED spec. pInitial=2.5MPa(a)/m_flowStart=0.325kg/s CALCULATED from TFCircuit.mo's own m_total=1.3kg/s split evenly across all 4 busses/structures (1.3/4), consistent with the rest of TFCircuit.mo's pInitial choices -- not independently resized for this structure's much larger flow area. OPEN ITEM: the requested 2-3 radial wall nodes could NOT be mapped to a verified parameter -- nothing else in this codebase (or the unvendored ThermalSystems.GasComponents.Tubes.Tube API) exposes radial wall discretization, only the axial nCells above; confirm in the Dymola parameter dialog whether such a control exists (e.g. under tubeGeometry or a WallMaterial-side setting) before assuming this Tube model only ever uses a single lumped radial wall node per axial cell."
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
    "Prescribed Kv-value [m^3/h] -- driven by TFCircuit.mo's per-bus isolation logic (firstOrderCoilKv), same role as CS's CoilAssembly2ch.KvValue_in1."
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
  connect(valve1.KvValue_in, KvValue_in1) annotation (Line(points={{13,58.75},{
          13,-66},{104,-66}},  color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end TFStructure;
