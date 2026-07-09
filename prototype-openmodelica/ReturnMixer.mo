block ReturnMixer
  Modelica.Blocks.Interfaces.RealInput T1 annotation(
    Placement(transformation(origin = {-266, 62}, extent = {{-20, -20}, {20, 20}}), iconTransformation(origin = {-354, 62}, extent = {{-20, -20}, {20, 20}})));
  Modelica.Blocks.Interfaces.RealInput T2 annotation(
    Placement(transformation(origin = {-262, -10}, extent = {{-20, -20}, {20, 20}}), iconTransformation(origin = {-330, -14}, extent = {{-20, -20}, {20, 20}})));
  Modelica.Blocks.Interfaces.RealInput T3 annotation(
    Placement(transformation(origin = {-266, -68}, extent = {{-20, -20}, {20, 20}}), iconTransformation(origin = {-322, -78}, extent = {{-20, -20}, {20, 20}})));
  Modelica.Blocks.Interfaces.RealOutput T_mix annotation(
    Placement(transformation(origin = {196, 4}, extent = {{-10, -10}, {10, 10}}), iconTransformation(origin = {214, 4}, extent = {{-10, -10}, {10, 10}})));
  parameter Modelica.Units.SI.MassFlowRate mdot1 = 0.006;
parameter Modelica.Units.SI.MassFlowRate mdot2 = 0.004;
parameter Modelica.Units.SI.MassFlowRate mdot3 = 0.002;

equation
  T_mix = (mdot1*T1 + mdot2*T2 + mdot3*T3)/(mdot1 + mdot2 + mdot3);
annotation(
    uses(Modelica(version = "4.1.0")));
end ReturnMixer;
