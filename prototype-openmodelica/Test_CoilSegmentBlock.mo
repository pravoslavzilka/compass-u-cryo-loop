model Test_CoilSegmentBlock
  CoilSegmentBlock coilSegmentBlock annotation(
    Placement(transformation(origin = {-61, -3}, extent = {{-39, -39}, {39, 39}})));
  Modelica.Blocks.Sources.Constant const(k = 80)  annotation(
    Placement(transformation(origin = {-268, 6}, extent = {{-10, -10}, {10, 10}})));
  Modelica.Blocks.Sources.Pulse pulse(amplitude = 200, width = 50, period = 10, nperiod = 3, startTime = 5)  annotation(
    Placement(transformation(origin = {-266, -48}, extent = {{-10, -10}, {10, 10}})));
equation
  connect(const.y, coilSegmentBlock.T_he_in) annotation(
    Line(points = {{-256, 6}, {-256, 7}, {-134, 7}}, color = {0, 0, 127}));
  connect(pulse.y, coilSegmentBlock.Q_gen) annotation(
    Line(points = {{-254, -48}, {-178, -48}, {-178, -22.5}, {-132, -22.5}}, color = {0, 0, 127}));

annotation(
    uses(Modelica(version = "4.1.0")));
end Test_CoilSegmentBlock;
