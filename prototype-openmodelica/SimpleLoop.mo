model SimpleLoop
  CoilSegmentBlock coilSegmentBlock_1 annotation(
    Placement(transformation(origin={-67,105},    extent = {{-23, -23}, {23, 23}})));
  CoilSegmentBlock coilSegmentBlock_2 annotation(
    Placement(transformation(origin={-70,32},    extent = {{-22, -22}, {22, 22}})));
  CoilSegmentBlock coilSegmentBlock_3 annotation(
    Placement(transformation(origin={-66,-42},    extent = {{-22, -22}, {22, 22}})));
  Modelica.Blocks.Sources.Pulse pulse(amplitude = 200, width = 50, period = 10, nperiod = 3, startTime = 5)  annotation(
    Placement(transformation(origin = {-296, 62}, extent = {{-10, -10}, {10, 10}})));
  ReturnMixer returnMixer(mdot1 = 0.005, mdot2 = 0.005, mdot3 = 0.005)  annotation(
    Placement(transformation(origin={128,10},    extent = {{-20, -20}, {20, 20}})));
  HeatExchanger heatExchanger(T_cold(displayUnit = "K") = 77, UA_hx = 500)  annotation(
    Placement(transformation(origin={244,0},      extent = {{-20, -20}, {20, 20}})));
  Modelica.Blocks.Sources.Pulse pulse1(amplitude = 200, nperiod = 3, period = 10, startTime = 5, width = 50) annotation(
    Placement(transformation(origin = {-296, -6}, extent = {{-10, -10}, {10, 10}})));
  Modelica.Blocks.Sources.Pulse pulse2(amplitude = 200, nperiod = 3, period = 10, startTime = 5, width = 50) annotation(
    Placement(transformation(origin = {-296, -60}, extent = {{-10, -10}, {10, 10}})));
  Circulator circulator
    annotation (Placement(transformation(extent={{102,-148},{152,-102}})));
equation
  connect(coilSegmentBlock_1.T_he_out, returnMixer.T1) annotation(
    Line(points={{-31.58,108.22},{57.2,108.22},{57.2,22.4}},
                                                     color = {0, 0, 127}));
  connect(coilSegmentBlock_2.T_he_out, returnMixer.T2) annotation(
    Line(points={{-36.12,35.08},{-36.12,34},{12,34},{12,6},{36,6},{36,7.2},{62,7.2}},
                                                    color = {0, 0, 127}));
  connect(coilSegmentBlock_3.T_he_out, returnMixer.T3) annotation(
    Line(points={{-32.12,-38.92},{12,-38.92},{12,-8},{63.6,-8},{63.6,-5.6}},
                                                      color = {0, 0, 127}));
  connect(returnMixer.T_mix, heatExchanger.T_return) annotation(
    Line(points={{170.8,10.8},{172,10.8},{172,10},{187.6,10}},
                                            color = {0, 0, 127}));
  connect(pulse.y, coilSegmentBlock_1.Q_gen) annotation(
    Line(points={{-285,62},{-108.86,62},{-108.86,93.5}},                                                                                color = {0, 0, 127}));
  connect(pulse1.y, coilSegmentBlock_2.Q_gen) annotation(
    Line(points={{-285,-6},{-196,-6},{-196,21},{-110.04,21}},       color = {0, 0, 127}));
  connect(pulse2.y, coilSegmentBlock_3.Q_gen) annotation(
    Line(points={{-285,-60},{-192,-60},{-192,-53},{-106.04,-53}},       color = {0, 0, 127}));
  connect(heatExchanger.T_supply, coilSegmentBlock_2.T_he_in) annotation(
    Line(points={{273.6,6.8},{273.6,8},{282,8},{282,-72},{-96,-72},{-96,-36},{
          -100,-36},{-100,37.72},{-111.36,37.72}},                                         color = {0, 0, 127}));
  connect(heatExchanger.T_supply, coilSegmentBlock_3.T_he_in) annotation(
    Line(points={{273.6,6.8},{273.6,8},{282,8},{282,-72},{-96,-72},{-96,-36.28},
          {-107.36,-36.28}},                                                                     color = {0, 0, 127}));

  connect(heatExchanger.T_supply, coilSegmentBlock_1.T_he_in) annotation (Line(
        points={{273.6,6.8},{273.6,134},{-110.24,134},{-110.24,110.98}}, color={
          0,0,127}));
  connect(circulator.mdot_total, heatExchanger.mdot_total) annotation (Line(
        points={{162,-114.42},{192,-114.42},{192,-90},{212.4,-90},{212.4,-9.6}},
        color={0,0,127}));
annotation(
    uses(Modelica(version="4.0.0")));
end SimpleLoop;
