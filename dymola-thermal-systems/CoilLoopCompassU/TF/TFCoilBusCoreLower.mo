within CoilLoopCompassU.TF;
model TFCoilBusCoreLower
  outer ThermalSystems.SystemInformationManager sim;
  // ===========================================================================
  // Lumps the WHOLE "TF core + lower limb" channel group (112 channels) into
  // a single instance -- TFCL2, formerly a second TFCoilBusCoreLower sibling
  // sharing this header 56/56 with TFCL1, was replaced by TFStructure
  // (Structure, a physically distinct coil-case/support-structure model) at
  // the same junctionCL/junctionReturnCL header, so nChannels now covers the
  // full 112 rather than an assumed 56/56 split -- see TFCircuit.mo's commit
  // history. FROM SOURCE (ATEKO 22172-Z-R1 Tab.3, S5.2.3, PFD 22179-0-R0):
  // 112 short copper channels, 6x10mm elliptical, length 9.2m each, coil
  // weight 13900kg, max deposited energy 196MJ. All 112 channels are lumped
  // into a single Tube instance via nParallelTubes=nChannels, the same
  // aggregation technique PF/CS's own (1-channel) CoilAssembly.mo uses --
  // modeling each channel as a separate branch would buy no accuracy here
  // since ATEKO gives no per-channel variation (all 112 assumed identical).
  // assemblyIndex/lengthAdjusted below are now largely vestigial (no sibling
  // TFCoilBusCoreLower instance remains to break degeneracy against), kept
  // harmless at their existing values rather than removed.
  // ===========================================================================

  parameter Modelica.Units.SI.Length length = 9.2
    "Channel length -- FROM SOURCE, ATEKO 22172-Z-R1 Tab.3 'TF core + lower limb' row (9.2 m), confirmed by PFD 22179-0-R0 channel callouts ('6x10mm, L=9.2m').";
  parameter Modelica.Units.SI.Diameter diameter = 0.007379796
    "Hydraulic diameter D_h -- FROM SOURCE, ATEKO Tab.3/S5.2.3 ('elliptical channel 6x10mm, hydraulic diameter 7.379mm'). INFORMATIONAL / cross-check only, not fed into tube2: since crossSectionType=NonCircular (see below), D_h is computed by the Tube model itself as 4*innerCrossSectionalAreaNonCircular/innerPerimeterNonCircular = 4*47.12/25.53 = 7.383mm, matching this FROM SOURCE value to within rounding -- confirms crossSectionArea/wettedPerimeter below are mutually consistent with ATEKO's own stated D_h.";
  parameter Modelica.Units.SI.Area crossSectionArea = 47.12e-6
    "True elliptical channel flow area (6x10mm ellipse) -- USER-SUPPLIED. Wired into tube2 as tubeGeometry.innerCrossSectionalAreaNonCircular now that crossSectionType=NonCircular is confirmed (ThermalSystems.GasComponents.Tubes.Geometry.TubeGeometry 1.13.0 doc, obtained via Dymola's class documentation after the earlier 'roughness' guess was confirmed wrong at translate-check) -- previously approximated via a Circular assumption at D_h (pi/4*D_h^2=42.78mm^2), ~9% low; that approximation is no longer used.";
  parameter Modelica.Units.SI.Length wettedPerimeter = 25.53e-3
    "True elliptical channel wetted perimeter -- USER-SUPPLIED. Wired into tube2 as tubeGeometry.innerPerimeterNonCircular.";
  parameter Modelica.Units.SI.Area outerCrossSectionalArea = 0.00155269
    "Outer cross-sectional area of one channel (metal + bore), CALCULATED so tube2's modeled copper mass (density 8960 kg/m3 x (outerCrossSectionalArea-crossSectionArea) x length x nChannels) equals ATEKO Tab.3's full 'TF core + lower limb' coil weight of 13900kg: annulus area = 13900/(8960*112*9.2) = 1505.57mm2/channel -> outerCrossSectionalArea = 47.12+1505.57 = 1552.69mm2. Wired into tube2 as tubeGeometry.outerCrossSectionalAreaNonCircular -- this is the NonCircular-geometry replacement for the old Circular-only wallThickness-based mass sizing (see wallThickness's docstring below, now unused/kept for traceability only).";
  parameter Modelica.Units.SI.CoefficientOfHeatTransfer alphaConstant = 1090
    "Gas-side convective heat transfer coefficient -- PLACEHOLDER, rough order-of-magnitude only. GnielinskiDittusBoelter (used elsewhere in this file family) asserts 'Geometry based correlation is valid for circular tubes only' and refuses crossSectionType=NonCircular at simulation start (confirmed at runtime, not translate-check) -- ConstantAlpha is used instead below, which needs a user-supplied coefficient rather than computing one from geometry+flow. Estimated via Dittus-Boelter (Nu=0.023*Re^0.8*Pr^0.4) at this model's ~116K/2.5MPa(a) design point: m_flow/channel=0.325/112=2.902e-3kg/s, D_h=7.38mm, A=47.12mm2 -> Re~44400; cp_He=5193 J/kg/K is essentially exact (monatomic ideal gas) but mu/k were EXTRAPOLATED from 300K reference values via a T^0.7 power law (mu=1.02e-5 Pa.s, k=0.0782 W/m/K, Pr~0.68), NOT looked up from TSMedia's actual Helium property functions at the true operating point -- replace with a TSMedia-computed value (or an in-Dymola parameter study) before trusting this quantitatively; +/-30-50% plausible given the extrapolation.";
  parameter Modelica.Units.SI.ThermalResistance wallConductionR = 1.903e-6
    "Whole-component wall conduction resistance (K/W, absolute -- NOT area-specific) -- PLACEHOLDER. The default WallHeatConductionModel (GeometryBasedConduction) throws the SAME 'Geometry based correlation is valid for circular tubes only' assertion as GnielinskiDittusBoelter did, but for the WALL side -- a separate replaceable model from HeatTransferModel/alphaConstant above. ConstantR is used instead below (ThermalSystems.GasComponents.Tubes.TransportPhenomena.WallHeatTransfer.ConstantR, field 'constantR', both confirmed via its full Modelica source: 'parameter SI.ThermalResistance constantR'). Per that source, constantR is scaled internally per cell as R_NS=constantR*(outerVolume-innerVolume)/cellGeometry.volume -- i.e. it wants the LUMPED resistance for the WHOLE tube (all nCells, all nChannels combined), not per-cell or per-area; the library auto-rescales per cell. Also per source, R_WE (the outer/heatPort-side path) is hardcoded to 1e12 (effectively adiabatic) by this model regardless of constantR -- harmless here since dischargeLoad=0 already means zero heat flows through that path. Value: planar-slab approximation R=t/(k*A_total), t=wallThickness=18.51mm (traceability figure), k=369.8 W/m/K (CopperOFHC_RRR30_Tdep at T=137K), A_total=wettedPerimeter*length*nChannels=26.31m2 -> R~1.9e-6 K/W -- extremely small (copper conducts well over this scale), so this correction should barely matter either way, but not independently verified beyond this planar-slab estimate.";
  parameter Integer nChannels = 112
    "Number of parallel channels lumped into this instance's single Tube (affects flow area) -- USER-SUPPLIED (nParallel), now the FULL 'TF core + lower limb' group (112, not a 56/56 split) since TFCL2 was replaced by TFStructure -- see this model's header comment.";
  parameter Modelica.Units.SI.Length roughness = 2e-6
    "Channel wall roughness -- USER-SUPPLIED (2 um, copper -- smoother than TFStructure's 12.5um stainless-case value). Declared but NOT wired into tube2: confirmed at translate-check that TubeGeometry has no roughness field; the Konakov PressureDropModel in use is a smooth-pipe correlation (Re-only, no roughness term) so there may be no consumer for this anywhere in the current component chain -- see TFStructure.mo's identical roughness parameter for the same open item.";
  parameter Modelica.Units.SI.Power dischargeLoad = 0
    "Peak discharge heat [W] for this instance's lumped 112 channels -- set to 0 (heat load removed): the discharge pulse is not modeled here, and the coil's stored thermal energy is instead represented via its elevated initial temperature (TInitial, overridden to 137K at the TFCircuit.mo instantiation). Was CALCULATED from ATEKO 22172-Z-R1 Tab.3's 196 MJ max deposited energy for this group; see git history for that value.";
  parameter Modelica.Units.SI.Time pulseStart = 5 "Discharge start time -- unused while dischargeLoad=0.";
  parameter Modelica.Units.SI.Time pulseEnd = 10 "Discharge end time -- unused while dischargeLoad=0.";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1), used only as the KvValueFixed fallback -- TFCircuit.mo drives this valve dynamically via KvValue_in1.";
  parameter Real valveKvNominal = 100 "Kv value at fully-open (valveOpening=1) -- ASSUMED, carried from PF/CS, no TF-specific valve Cv data found.";
  parameter Modelica.Units.SI.Temperature TInitial = 80 "Initial coil/gas temperature -- overridden to 137K at the TFCircuit.mo instantiation (stands in for the discharge heat load, which is set to 0 here).";
  parameter Integer assemblyIndex = 0
    "Unique index of this instance among all TF busses/structures (no physical meaning) -- vestigial now that TFCL2 (the sibling this offset used to disambiguate against) was replaced by TFStructure; kept harmless, see this model's header comment.";
  parameter Modelica.Units.SI.Thickness wallThickness = 0.018510
    "Equivalent D_h-basis wall thickness (13900kg -> 18.5mm, per USER confirmation) -- kept for TRACEABILITY ONLY, no longer fed into tube2: superseded by outerCrossSectionalArea now that crossSectionType=NonCircular is used (see that parameter's docstring for the actual mass-sizing calculation). Originally CALCULATED assuming a Circular tubeGeometry (innerDiameter=diameter=D_h); confirmed via TFCL1.tube2.summary.mass_component in an earlier translated result.mat that the Tube model's 0.5mm library default gives ~122x too little thermal mass for a solid-plate coil like this -- the root cause of a solver stall/blow-up a couple seconds after the discharge pulse start (back when a pulse was still modeled) -- same conclusion, now achieved via outerCrossSectionalArea instead.";

  final parameter Modelica.Units.SI.Length lengthAdjusted = length*(1 + 1e-5*assemblyIndex)
    "length with a tiny (<=0.004% for assemblyIndex<=4) per-instance offset -- see assemblyIndex.";

  output Modelica.Units.SI.Temperature T_wall = tube2.heatPort[1].T "Coil wall temperature";
  output Modelica.Units.SI.Temperature T_gas_out = tube2.summary.T_gas_B "Helium outlet temperature";
  output Modelica.Units.SI.Temperature T_gas_in = tube2.summary.T_gas_A "Helium inlet temperature";
  output Modelica.Units.SI.MassFlowRate m_flow = tube2.summary.m_flow_gas_B "Bus mass flow (all 112 lumped channels)";

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
    "Wall material OFHC copper, RRR~30 (ATEKO S5.2.3: 'TF channels are made from Copper'; RRR per USER-SUPPLIED spec, see CopperOFHC_RRR30_Tdep's docstring for the lambda(T) approximation caveat). HeatTransferModel=ConstantAlpha (see alphaConstant's docstring for why GnielinskiDittusBoelter can't be used here and for the PLACEHOLDER alpha derivation), field name confirmed as 'constantAlpha' via the 'don't have any value' translate error on tube2.heatTransfer[i].heatTransfer.constantAlpha (first guess was 'alpha', wrong). nCells=10 axial cells, wall nodes=1 (radial) per USER-SUPPLIED spec -- 1 matches this Tube model's existing behavior (no radial wall subdivision parameter found anywhere in this codebase, single lumped wall node per axial cell), so no change was needed there. pInitial=2.5MPa(a)/m_flowStart=0.325kg/s CALCULATED from TFCircuit.mo's own m_total=1.3kg/s split evenly across all 4 busses/structures (1.3/4), consistent with the rest of TFCircuit.mo's pInitial choices -- not independently resized for the new 112-channel flow area."
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
end TFCoilBusCoreLower;
