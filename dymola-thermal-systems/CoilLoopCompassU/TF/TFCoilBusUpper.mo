within CoilLoopCompassU.TF;
model TFCoilBusUpper
  outer ThermalSystems.SystemInformationManager sim;
  // ===========================================================================
  // One of 2 parallel busses (TFUL1, TFUL2 in TFCircuit.mo) lumping half of
  // the "TF upper limb" channel group -- USER CONFIRMED this stays a 2-bus
  // split (unlike TFCoilBusCoreLower's TFCL2->TFStructure consolidation):
  // TFUL1/TFUL2 remain two separate circuits, so nChannels=56 (112/2), not
  // 112. FROM SOURCE (ATEKO 22172-Z-R1 Tab.3, S5.2.3, PFD 22179-0-R0): 112
  // short copper channels total, 6x10mm elliptical, length 7.7m each, coil
  // weight 7808kg (3904kg/bus), max deposited energy 53.76MJ.
  // crossSectionArea/wettedPerimeter/outerCrossSectionalArea/wallThickness
  // below are PER-CHANNEL geometric properties and are therefore unchanged
  // from the (reverted) 112-channel/single-instance version: per-channel
  // mass is identical either way (3904kg/56=7808kg/112=69.71kg/channel).
  // Only nChannels, wallConductionR (a whole-component lumped resistance,
  // scales with total surface area = nChannels) and alphaConstant (depends
  // on per-channel flow, which doubles if the bus's own m_flowStart is left
  // unchanged -- see alphaConstant's docstring) actually change with the split.
  // ===========================================================================

  parameter Modelica.Units.SI.Length length = 7.7
    "Channel length -- FROM SOURCE, ATEKO 22172-Z-R1 Tab.3 'TF upper limb' row (7.7 m), confirmed by PFD 22179-0-R0 channel callouts ('6x10mm, L=7.7m').";
  parameter Modelica.Units.SI.Diameter diameter = 0.007379796
    "Hydraulic diameter D_h -- FROM SOURCE, ATEKO Tab.3/S5.2.3 (same 6x10mm ellipse as the core+lower limb group, hydraulic diameter 7.379mm; USER-SUPPLIED value 7.384mm essentially identical). INFORMATIONAL / cross-check only, not fed into tube2: crossSectionType=NonCircular (see below), so D_h is computed by the Tube model itself as 4*innerCrossSectionalAreaNonCircular/innerPerimeterNonCircular -- see TFCoilBusCoreLower's identical parameter for the full explanation of why (a Circular assumption at D_h under-estimates true elliptical flow area by ~9%).";
  parameter Modelica.Units.SI.Area crossSectionArea = 47.12e-6
    "True elliptical channel flow area (6x10mm ellipse, same channel type as core+lower limb) -- USER-SUPPLIED. Wired into tube2 as tubeGeometry.innerCrossSectionalAreaNonCircular.";
  parameter Modelica.Units.SI.Length wettedPerimeter = 25.53e-3
    "True elliptical channel wetted perimeter -- USER-SUPPLIED. Wired into tube2 as tubeGeometry.innerPerimeterNonCircular.";
  parameter Modelica.Units.SI.Area outerCrossSectionalArea = 0.0010576
    "Outer cross-sectional area of one channel (metal + bore), CALCULATED so tube2's modeled copper mass (density 8960 kg/m3 x (outerCrossSectionalArea-crossSectionArea) x length x nChannels) equals ATEKO Tab.3's full 'TF upper limb' coil weight of 7808kg: annulus area = 7808/(8960*112*7.7) = 1010.47mm2/channel -> outerCrossSectionalArea = 47.12+1010.47 = 1057.59mm2. Wired into tube2 as tubeGeometry.outerCrossSectionalAreaNonCircular -- see TFCoilBusCoreLower's identical parameter for why (NonCircular-geometry replacement for the old Circular-only wallThickness-based mass sizing).";
  parameter Modelica.Units.SI.CoefficientOfHeatTransfer alphaConstant = 1899
    "Gas-side convective heat transfer coefficient -- PLACEHOLDER, recomputed for the 56-channel split (per-channel flow doubles vs the 112-channel version, since this bus's own m_flowStart=0.325kg/s is unchanged: 0.325/56=5.80g/s/channel here vs 0.325/112=2.90g/s/channel there -- roughly double the USER-SUPPLIED 'flow per channel: 2.91g/s required' figure, see m_flowStart's note in tube2's docstring for the open item this implies). Dittus-Boelter (Nu=0.023*Re^0.8*Pr^0.4) at m_flow/channel=5.80e-3kg/s, D_h=7.38mm, A=47.12mm2 -> Re~88900 (vs ~44400 at half the flow), Pr~0.68 (same gas-property caveats as TFCoilBusCoreLower's identical calculation) -> alpha~1899 W/m2/K. GnielinskiDittusBoelter (the Tube model's default) asserts 'Geometry based correlation is valid for circular tubes only' and refuses crossSectionType=NonCircular -- ConstantAlpha is used instead below.";
  parameter Modelica.Units.SI.ThermalResistance wallConductionR = 4.947e-6
    "Whole-component wall conduction resistance (K/W, absolute -- NOT area-specific) for ONE 56-channel bus, same role/derivation as TFCoilBusCoreLower's identical parameter (see there for the ConstantR/constantR/R_NS/R_WE explanation, confirmed via the library's own Modelica source). Value: R=t/(k*A_total), t=wallThickness=14.62mm, k=268.4 W/m/K (CopperOFHC_RRR30_Tdep at T=98K), A_total=wettedPerimeter*length*nChannels=11.01m2 (half the 112-channel case's total surface area, since R~1/A -> this R is roughly double that version's 2.474e-6) -> R~4.95e-6 K/W, still small enough that wall conduction should barely matter.";
  parameter Integer nChannels = 56
    "Number of parallel channels lumped into this bus's single Tube (affects flow area) -- CALCULATED: Tab.3 states 112 channels total for 'TF upper limb', TFCircuit.mo models this group as 2 busses (TFUL1, TFUL2), USER CONFIRMED to stay that way (not consolidated like TFCoilBusCoreLower's TFCL1); 112/2=56.";
  parameter Modelica.Units.SI.Length roughness = 2e-6
    "Channel wall roughness -- USER-SUPPLIED (2 um, copper). Declared but NOT wired into tube2: TubeGeometry (ThermalSystems.GasComponents.Tubes.Geometry.TubeGeometry 1.13.0) has no roughness field (confirmed at translate-check on TFCoilBusCoreLower), and the Konakov PressureDropModel in use is a smooth-pipe correlation (Re-only) with no roughness term -- same open item as TFCoilBusCoreLower/TFStructure. USER-SUPPLIED spec calls for Colebrook/Haaland friction (which DOES use roughness) -- not implemented here; would need a different PressureDropModel redeclare, out of scope for this pass.";
  parameter Modelica.Units.SI.Power dischargeLoad = 0
    "Peak discharge heat [W] for this bus's lumped 56 channels -- set to 0 (heat load removed): the discharge pulse is not modeled here, and the coil's stored thermal energy is instead represented via its elevated initial temperature (TInitial, overridden to 137K at the TFCircuit.mo instantiation -- USER-SUPPLIED spec separately gives this branch its own baseline/sensitivity initial temperatures of 98K/109K, not yet reconciled with the current uniform 137K, see TInitial's docstring). Was CALCULATED from half of ATEKO 22172-Z-R1 Tab.3's 53.76 MJ max deposited energy for this group; see git history for that value.";
  parameter Modelica.Units.SI.Time pulseStart = 5 "Discharge start time -- unused while dischargeLoad=0.";
  parameter Modelica.Units.SI.Time pulseEnd = 10 "Discharge end time -- unused while dischargeLoad=0.";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1), used only as the KvValueFixed fallback -- TFCircuit.mo drives this valve dynamically via KvValue_in1.";
  parameter Real valveKvNominal = 100 "Kv value at fully-open (valveOpening=1) -- ASSUMED, carried from PF/CS, no TF-specific valve Cv data found.";
  parameter Modelica.Units.SI.Temperature TInitial = 80 "Initial coil/gas temperature -- overridden to 137K at the TFCircuit.mo instantiation (stands in for the discharge heat load, which is set to 0 here) -- NOTE: USER-SUPPLIED spec gives this branch its OWN baseline/sensitivity metal initial temperature (98K/109K), distinct from TFCoilBusCoreLower's (116K/134K) and from the current uniform 137K at every TFCircuit.mo instantiation; not reconciled by this edit.";
  parameter Integer assemblyIndex = 0
    "Unique index of this bus instance among all 4 TF busses (no physical meaning) -- TFUL1/TFUL2 both draw from the same junctionUL with otherwise-identical parameters, the same symmetric-parallel-branch degeneracy CS's CoilAssembly2ch.mo guards against; this tiny per-instance length offset (see lengthAdjusted) breaks that degeneracy so the flow split isn't numerically ambiguous.";
  parameter Modelica.Units.SI.Thickness wallThickness = 0.014620
    "Equivalent D_h-basis wall thickness (7808kg -> 14.6mm, matches the USER-SUPPLIED spec exactly) -- kept for TRACEABILITY ONLY, no longer fed into tube2: superseded by outerCrossSectionalArea now that crossSectionType=NonCircular is used (see that parameter's docstring for the actual mass-sizing calculation).";

  final parameter Modelica.Units.SI.Length lengthAdjusted = length*(1 + 1e-5*assemblyIndex)
    "length with a tiny (<=0.004% for assemblyIndex<=4) per-instance offset -- see assemblyIndex.";

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
    TInitial(displayUnit="K") = TInitial,
    TInitialWall(displayUnit="K") = TInitial)
    "Wall material OFHC copper, RRR~30 (ATEKO S5.2.3: 'TF channels are made from Copper'; RRR per USER-SUPPLIED spec). HeatTransferModel=ConstantAlpha, WallHeatConductionModel=ConstantR -- both required because the Tube model's default correlations (GnielinskiDittusBoelter / GeometryBasedConduction) are circular-tube-only and refuse crossSectionType=NonCircular at simulation start, see alphaConstant/wallConductionR docstrings (and TFCoilBusCoreLower's, where this was first confirmed via translate/runtime errors). nCells=10 axial cells, wall nodes=1 (radial) per USER-SUPPLIED spec -- matches this Tube model's existing behavior (no radial wall subdivision parameter exists). pInitial=2.5MPa(a)/m_flowStart=0.325kg/s CALCULATED from TFCircuit.mo's own m_total=1.3kg/s split evenly across all 4 busses (1.3/4), same convention as before the 112-channel detour -- but per-channel this now gives 0.325/56=5.80g/s, roughly DOUBLE the USER-SUPPLIED 'flow per channel: 2.91g/s required' figure; OPEN ITEM, not resolved here -- halving m_flowStart to ~0.163kg/s would match the spec exactly but wasn't requested this pass."
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
  connect(valve1.KvValue_in, KvValue_in1) annotation (Line(points={{13,57.25},
          {13,-66},{104,-66}}, color={0,0,127}));
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end TFCoilBusUpper;
