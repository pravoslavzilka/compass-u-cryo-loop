within CoilLoopCompassU.TF;
model TFCoilBusCoreLower
  outer ThermalSystems.SystemInformationManager sim;
  // ===========================================================================
  // One of 2 parallel busses (TFCL1, TFCL2 in TFCircuit.mo) lumping half of the
  // "TF core + lower limb" channel group. FROM SOURCE (ATEKO 22172-Z-R1 Tab.3,
  // S5.2.3, PFD 22179-0-R0): this group is 112 short copper channels (6x10mm
  // elliptical, equivalent/hydraulic diameter 7.379796mm, length 9.2m each,
  // coil weight 13900kg, max deposited energy 196MJ), confirmed by the PFD
  // drawing itself to be fed from a single header that splits left/right into
  // two symmetric halves around the ring -- i.e. exactly the 2-bus split this
  // model and TFCoilBusUpper implement. What the PFD does NOT show is the
  // per-half channel count, so nChannels=56 (112/2) is ASSUMED even, not read
  // off the drawing -- see docs/design-basis/tf-circulator-sizing.md Open
  // Items. All 56 channels of one bus are lumped into a single Tube instance
  // via nParallelTubes=nChannels, the same aggregation technique PF/CS's own
  // (1-channel) CoilAssembly.mo uses for its nChannels parameter -- modeling
  // each channel as a separate branch (as CoilAssembly2ch.mo does for CS's
  // 2-channel coils) would mean 56 explicit Tube instances per bus, which
  // buys no accuracy here since ATEKO gives no per-channel variation within
  // a bus (all 56 assumed identical).
  // ===========================================================================

  parameter Modelica.Units.SI.Length length = 9.2
    "Channel length -- FROM SOURCE, ATEKO 22172-Z-R1 Tab.3 'TF core + lower limb' row (9.2 m), confirmed by PFD 22179-0-R0 channel callouts ('6x10mm, L=9.2m').";
  parameter Modelica.Units.SI.Diameter diameter = 0.007379796
    "Equivalent/hydraulic channel diameter -- FROM SOURCE, ATEKO Tab.3 'TF core + lower limb' row, confirmed by S5.2.3 ('elliptical channel 6x10mm, hydraulic diameter 7.379mm').";
  parameter Integer nChannels = 56
    "Number of parallel channels lumped into this bus's single Tube (affects flow area) -- CALCULATED: Tab.3 states 112 channels total for 'TF core + lower limb', TFCircuit.mo models this group as 2 busses (TFCL1, TFCL2); 112/2=56 is an ASSUMED even split -- the PFD confirms the header splits symmetrically left/right but does not itself state a per-half channel count.";
  parameter Modelica.Units.SI.Power dischargeLoad = 0
    "Peak discharge heat [W] for this bus's lumped 56 channels -- set to 0 (heat load removed): the discharge pulse is not modeled here, and the coil's stored thermal energy is instead represented via its elevated initial temperature (TInitial, overridden to 137K at the TFCircuit.mo instantiation). Was CALCULATED from ATEKO 22172-Z-R1 Tab.3's 196 MJ max deposited energy for this group; see git history for that value.";
  parameter Modelica.Units.SI.Time pulseStart = 5 "Discharge start time -- unused while dischargeLoad=0.";
  parameter Modelica.Units.SI.Time pulseEnd = 10 "Discharge end time -- unused while dischargeLoad=0.";
  parameter Real valveOpening = 1.0 "Isolation valve opening (0-1), used only as the KvValueFixed fallback -- TFCircuit.mo drives this valve dynamically via KvValue_in1.";
  parameter Real valveKvNominal = 100 "Kv value at fully-open (valveOpening=1) -- ASSUMED, carried from PF/CS, no TF-specific valve Cv data found.";
  parameter Modelica.Units.SI.Temperature TInitial = 80 "Initial coil/gas temperature -- overridden to 137K at the TFCircuit.mo instantiation (stands in for the discharge heat load, which is set to 0 here).";
  parameter Integer assemblyIndex = 0
    "Unique index of this bus instance among all 4 TF busses (no physical meaning) -- TFCL1/TFCL2 both draw from the same junctionCL with otherwise-identical parameters, the same symmetric-parallel-branch degeneracy CS's CoilAssembly2ch.mo guards against; this tiny per-instance length offset (see lengthAdjusted) breaks that degeneracy so the flow split isn't numerically ambiguous.";
  parameter Modelica.Units.SI.Thickness wallThickness = 0.018510
    "CALCULATED, NOT the Tube model's library default (0.5mm, a thin structural pipe wall): sized so tube2's modeled copper mass (density 8960 kg/m3 x annulus volume x nChannels) equals half of ATEKO Tab.3's real 'TF core + lower limb' coil weight (13900kg total / 2 busses = 6950kg), reflecting that the real channels are drilled/brazed through a solid copper coil plate ('One huge coil made out of copper plates with brazed-on pipe', ATEKO S3.3.3), not thin-walled tubing. Confirmed via TFCL1.tube2.summary.mass_component in a translated result.mat: the 0.5mm default gave only ~57kg (vs the 6950kg target), ~122x too little thermal mass to absorb the discharge pulse -- the root cause of a solver stall/blow-up (gas temperature reaching ~3976K, TSMedia viscosity/lambda floor warnings) a couple seconds after the t=5s pulse start. Does not affect flow/pressure drop (those use innerDiameter only).";

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
      innerDiameter=diameter,
      length=lengthAdjusted,
      nParallelTubes=nChannels,
      wallThickness=wallThickness,
      crossSectionType=ThermalSystems.Internals.CrossSectionType.Circular),
    pressureDropPosition=ThermalSystems.Internals.PressureDropPosition.center,
    nCells=20,
    enableHeatPorts=true,
    redeclare model HeatTransferModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.HeatTransfer.GnielinskiDittusBoelter,
    redeclare model WallMaterial = CoilLoopCompassU.Common.CopperOFHC_Tdep,
    fixedTInitialWall=false,
    redeclare model PressureDropModel =
        ThermalSystems.GasComponents.Tubes.TransportPhenomena.PressureDrop.Konakov,
    m_flowStart=0.325,
    pInitial=2500000,
    fixedInitialPressure=false,
    TInitial(displayUnit="K") = TInitial,
    TInitialWall(displayUnit="K") = TInitial)
    "Wall material Copper (ATEKO S5.2.3: 'TF channels are made from Copper'). pInitial=2.5MPa(a)/m_flowStart=0.325kg/s CALCULATED from TFCircuit.mo's own m_total=1.3kg/s split evenly across all 4 busses (1.3/4), consistent with the rest of TFCircuit.mo's pInitial choices -- not independently sized per bus."
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
