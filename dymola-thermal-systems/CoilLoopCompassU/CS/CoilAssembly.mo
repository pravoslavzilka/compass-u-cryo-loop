within CoilLoopCompassU.CS;
model CoilAssembly
  outer ThermalSystems.SystemInformationManager sim;
  parameter Modelica.Units.SI.Length length = 86
    "Equivalent channel length -- CS2U/CS2L default (ATEKO 22172-Z-R1 Tab.2: 86 m, single channel)";
  parameter Modelica.Units.SI.Diameter diameter = 0.00696025
    "Equivalent channel diameter -- reference only, not fed into tube2 (superseded by crossSectionArea/outerCrossSectionalArea below, same as TF's TFCoilBusCoreLower/TFCoilBusUpper convention). ATEKO 22172-Z-R1 Tab.2 'Ekvivalent diameter' column for the elliptical 8x6.2mm CS channel cross-section (0.00696025 m); a separate hydraulic-diameter figure of 6.817mm appears in the same document's S5.2.2 pressure-drop narrative. crossSectionArea/wettedPerimeter below give Dh=6.9584mm by direct computation from the real ellipse -- consistent with this Tab.2 figure to within ~0.03mm, cross-checking that 8x6.2mm is the right ellipse.";
  parameter Modelica.Units.SI.Area crossSectionArea = 38.956e-6
    "[CALCULATED] Elliptical channel flow area, 8x6.2mm ellipse (semi-axes 4mm x 3.1mm): area = pi*4mm*3.1mm = 38.9557 mm^2 -- ATEKO 22172-Z-R1 Tab.2 gives the 8x6.2mm cross-section dimensions (see CoilAssembly2ch.mo's docstring and cs-circulator-sizing.md S1 for the topology note re: this label). Replaces the old 'equivalent diameter' circular approximation, same fix as TF's TFCoilBusCoreLower/TFCoilBusUpper gap 1.";
  parameter Modelica.Units.SI.Length wettedPerimeter = 22.396e-3
    "[CALCULATED] Elliptical channel wetted perimeter, Ramanujan's approximation: P = pi*[3(a+b) - sqrt((3a+b)(a+3b))], a=4mm, b=3.1mm -> P=22.3956mm. Method verified against TF's own 6x10mm ellipse (a=5,b=3): same formula reproduces TF's documented 47.12mm^2 area and 25.53mm wetted perimeter exactly.";
  parameter Modelica.Units.SI.Area outerCrossSectionalArea = 491.87e-6
    "[CALCULATED] Outer cross-sectional area of the channel (metal + bore), sized so modeled copper mass matches ATEKO Tab.5's real CS2U/CS2L coil weight (349kg, single channel, length 86m; d_Cu=8960 kg/m3 per Common/CopperOFHC_Tdep.mo): copperArea = (349/8960)/86 = 452.92e-6 m^2; outerCrossSectionalArea = crossSectionArea + copperArea = 491.87e-6 m^2. Same method as TF's acba24f fix (reverse-verified: applying this formula to TF's own TFCoilBusCoreLower/TFCoilBusUpper numbers reproduces their documented outerCrossSectionalArea to within rounding). Old default (no wallThickness set -> library default ~0.5mm) had the same order-of-magnitude thermal-mass shortfall TF hit before acba24f.";
  parameter Modelica.Units.SI.CoefficientOfHeatTransfer alphaConstant = 9197
    "[CALCULATED] Gas-side convective heat transfer coefficient, Dittus-Boelter estimate at design flow: mdot_per_channel = (0.17 kg/s total design flow / 5 coil branches) / 1 channel = 0.034 kg/s (branches split evenly as a first-order estimate, same convention as TF's own m_flowStart=m_total/4 split). Scaled from TF's own reverse-engineered TFCoilBusCoreLower value (alphaConstant=1090 at Dh=7.38mm, A=47.12mm^2, mdot/channel=2.90e-3 kg/s) via Nu=0.023*Re^0.8*Pr^0.4 with gas properties (mu,k,cp) held fixed between TF's ~116K and CS's ~137.5K design points (ASSUMED -- helium mu/k vary only mildly, ~14% net exponent, over this T range; not independently computed from a property table, see cs-circulator-sizing.md Open Items). Scaling validated against TF's own two instances first (TFCoilBusCoreLower vs TFCoilBusUpper, same T/geometry, different mdot/channel): predicted ratio 2.0^0.8=1.741 vs actual 1899/1090=1.742, near-exact match.";
  parameter Modelica.Units.SI.ThermalResistance wallConductionR = 1.806e-5
    "[CALCULATED] Lumped wall conduction resistance for this single channel: R=ln(r2/r1)/(2*pi*k_Cu*length), r1/r2 = area-equivalent circular radii from crossSectionArea/outerCrossSectionalArea, k_Cu=130 W/(m.K) -- reverse-engineered from TF's own TFCoilBusCoreLower/TFCoilBusUpper wallConductionR values via the same formula (gave k=142/116 W/(m.K) respectively for the two TF instances, averaged here; the ~20% spread between them means this number is a rougher estimate than crossSectionArea/outerCrossSectionalArea above). Convection resistance (1/(alphaConstant*innerArea)) dominates over this conduction term by roughly 20x, so this parameter's imprecision has a small effect on overall wall-gas coupling.";
  parameter Integer nChannels = 1
    "Number of parallel channels (affects flow area) -- CS2U/CS2L each have exactly 1 channel per ATEKO Tab.2, unlike PF's coils which mostly have 2-4";
  parameter Modelica.Units.SI.Power dischargeLoad = 1560000
    "Peak discharge heat [W] -- CS2U/CS2L max deposited energy per coil is 7.8 MJ (ATEKO Tab.2); divided by a 5s pulse window following PF's own CoilAssembly.mo pulse-timing convention (pulseStart=5, pulseEnd=10 below) -- the 5s window is a structural convention carried from PF, not a CS-specific transient profile sourced from any document (ATEKO gives only total deposited energy per shot, not its power-time shape). See docs/design-basis/cs-circulator-sizing.md Open Items.";
  parameter Modelica.Units.SI.Time pulseStart = 5 "Discharge start time";
  parameter Modelica.Units.SI.Time pulseEnd = 10 "Discharge end time";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1)";
  parameter Real valveKvNominal = 100 "Kv value at fully-open (valveOpening=1)";
  parameter Modelica.Units.SI.Temperature TInitial = 80 "Initial coil/gas temperature";
  parameter Integer assemblyIndex = 0
    "Per-instance length offset index -- CS2U and CS2L are two structurally-identical CoilAssembly instances tapped off/returned through a chain of zero-resistance VolumeJunctions in CSCircuit.mo (same symmetric-parallel-branch topology as TF's TFUL1/TFUL2, which needed this fix in TF's acba24f commit -- see cs-circulator-sizing.md). This class previously had no such mechanism at all (unlike CoilAssembly2ch, which already carries PF's analogous fix), so CS2U/CS2L were fully exposed to the same class of structural-singularity risk. Give CS2U/CS2L distinct assemblyIndex values in CSCircuit.mo.";
  final parameter Modelica.Units.SI.Length lengthAdjusted = length*(1 + 1e-5*assemblyIndex)
    "length with a tiny per-instance offset -- see assemblyIndex.";

  output Modelica.Units.SI.Temperature T_wall = tube2.heatPort[1].T "Coil wall temperature";
  output Modelica.Units.SI.Temperature T_gas_out = tube2.summary.T_gas_B "Helium outlet temperature";
  output Modelica.Units.SI.Temperature T_gas_in = tube2.summary.T_gas_A "Helium inlet temperature";
  output Modelica.Units.SI.MassFlowRate m_flow = tube2.summary.m_flow_gas_B "Coil mass flow";

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
    nCells=20,
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
    m_flowStart=0.003,
    pInitial=8200000,
    TInitial(displayUnit="K") = TInitial,
    TInitialWall(displayUnit="K") = TInitial)
    "NonCircular geometry (real 8x6.2mm ellipse) with ConstantAlpha/ConstantR heat transfer -- same combination as TF's TFCoilBusCoreLower/TFCoilBusUpper, since the library's geometry-based correlations (e.g. GnielinskiDittusBoelter, used here previously) only support circular tubes."
    annotation (Placement(transformation(extent={{32,52},{48,56}})));
  ThermalSystems.GasComponents.Valves.Valve valve1(
    valveFlowVariableType=ThermalSystems.Internals.ValveFlowVariableType.KvValue,
    use_effectiveFlowAreaInput=false,
    use_KvValueInput=false,
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
  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end CoilAssembly;
