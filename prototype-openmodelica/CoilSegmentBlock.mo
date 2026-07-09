block CoilSegmentBlock
  Modelica.Blocks.Interfaces.RealInput T_he_in annotation(
    Placement(transformation(origin = {-216, 12}, extent = {{-20, -20}, {20, 20}}), iconTransformation(origin = {-188, 26}, extent = {{-20, -20}, {20, 20}})));
  Modelica.Blocks.Interfaces.RealOutput T_he_out annotation(
    Placement(transformation(origin = {164, 6}, extent = {{-10, -10}, {10, 10}}), iconTransformation(origin = {154, 14}, extent = {{-10, -10}, {10, 10}})));
  Modelica.Blocks.Interfaces.RealInput Q_gen annotation(
    Placement(transformation(origin = {-200, -30}, extent = {{-20, -20}, {20, 20}}), iconTransformation(origin = {-182, -50}, extent = {{-20, -20}, {20, 20}})));
  Modelica.Blocks.Interfaces.RealOutput T_cu (start = T_cu_start, fixed = true)  annotation(
    Placement(transformation(origin = {164, -46}, extent = {{-10, -10}, {10, 10}}), iconTransformation(origin = {154, -50}, extent = {{-10, -10}, {10, 10}})));
  parameter Modelica.Units.SI.Length L = 1.0;
parameter Modelica.Units.SI.Area A_cu = 2e-4;
parameter Modelica.Units.SI.Length P_wet = 0.03;
parameter Modelica.Units.SI.Density rho_cu = 8960;
parameter Modelica.Units.SI.SpecificHeatCapacity cp_cu = 385;
parameter Modelica.Units.SI.SpecificHeatCapacity cp_He = 5193;
parameter Modelica.Units.SI.CoefficientOfHeatTransfer h = 500;
parameter Modelica.Units.SI.MassFlowRate mdot = 0.005;
parameter Modelica.Units.SI.Temperature T_cu_start = 80;

protected
  parameter Modelica.Units.SI.HeatCapacity C_cu = rho_cu*cp_cu*A_cu*L;
  parameter Real NTU(unit="1") = h*P_wet*L/(mdot*cp_He);
  Modelica.Units.SI.HeatFlowRate Q_conv;

equation
  T_he_out = T_cu - (T_cu - T_he_in)*exp(-NTU);
  Q_conv   = mdot*cp_He*(T_he_out - T_he_in);
  C_cu*der(T_cu) = Q_gen - Q_conv;    
    
annotation(
    uses(Modelica(version = "4.1.0")));
end CoilSegmentBlock;
