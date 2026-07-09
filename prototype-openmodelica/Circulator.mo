within ;
block Circulator
  Modelica.Blocks.Interfaces.RealOutput mdot_total
    annotation (Placement(transformation(extent={{130,36},{150,56}})));
  parameter Modelica.Units.SI.Pressure dp0 = 20000
  "Circulator shutoff head [Pa]";
parameter Modelica.Units.SI.MassFlowRate mdot_max = 0.03
  "Free-delivery flow [kg/s]";
parameter Real R_loop(unit = "Pa.s2/kg2") = 5e7
  "Lumped loop resistance coefficient";
equation
  mdot_total = sqrt(dp0/(R_loop + dp0/mdot_max^2));
  annotation (
    Icon(coordinateSystem(preserveAspectRatio=false)),
    Diagram(coordinateSystem(preserveAspectRatio=false)),
    uses(Modelica(version="4.0.0")));


end Circulator;
