block HeatExchanger
  Modelica.Blocks.Interfaces.RealInput T_return annotation(
    Placement(transformation(origin={-162,40},    extent = {{-20, -20}, {20, 20}}), iconTransformation(origin = {-282, 50}, extent = {{-20, -20}, {20, 20}})));
  Modelica.Blocks.Interfaces.RealOutput T_supply annotation(
    Placement(transformation(origin = {148, 34}, extent = {{-10, -10}, {10, 10}}), iconTransformation(origin = {148, 34}, extent = {{-10, -10}, {10, 10}})));
  Modelica.Blocks.Interfaces.RealOutput Q_hx annotation(
    Placement(transformation(origin = {148, -24}, extent = {{-10, -10}, {10, 10}}), iconTransformation(origin = {162, -24}, extent = {{-10, -10}, {10, 10}})));
  parameter Modelica.Units.SI.Temperature T_cold = 77;
  parameter Modelica.Units.SI.ThermalConductance UA_hx = 500;
      Modelica.Blocks.Interfaces.RealInput mdot_total
  annotation(Placement(transformation(extent={{-178,-68},{-138,-28}})));
  parameter Modelica.Units.SI.SpecificHeatCapacity cp_He = 5193;
  protected
  Real NTU_hx(unit = "1")
    "Number of transfer units - now recomputed every instant since mdot_total can vary";


equation
    NTU_hx   = UA_hx/(mdot_total*cp_He);
    T_supply = T_cold + (T_return - T_cold)*exp(-NTU_hx);
    Q_hx     = mdot_total*cp_He*(T_return - T_supply);
  annotation(
    uses(Modelica(version="4.0.0")));



end HeatExchanger;
