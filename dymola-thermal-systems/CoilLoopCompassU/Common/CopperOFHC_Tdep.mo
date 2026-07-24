within CoilLoopCompassU.Common;
model CopperOFHC_Tdep
  "OFHC copper with temperature-dependent cp and lambda"
  extends TSMedia.SolidTypes.BaseSolid(
    cp_nominal = 385,      // room-temperature reference [J/(kg.K)]
    lambda_nominal = 400,  // room-temperature reference [W/(m.K)]
    d = 8960);             // density [kg/m3], treated as constant

  // -------------------------------------------------------------------
  // Specific heat capacity cp(T), J/(kg.K)
  // Table interpolation across 20-300 K. Copper cp falls even more
  // steeply than steel toward low T, so a constant value is badly
  // wrong for a cryogenic coil - which for a magnet coil is exactly
  // the wall thermal mass that sets cooldown time.
  //
  //   T [K] :   20    40    80   100   150   200   250   300
  //   cp    :  7.5   58   180   250   322   356   377   385
  // -------------------------------------------------------------------

protected
  constant Real Tdata[:]  = {20, 40, 80, 100, 150, 200, 250, 300};
  constant Real cpData[:] = {7.5, 58, 180, 250, 322, 356, 377, 385};

equation
  cp = Modelica.Math.Vectors.interpolate(Tdata, cpData, T);

  // Thermal conductivity lambda(T), W/(m.K)ss
  // NIST OFHC copper fit, RRR=50, valid 4-300 K, form:
  //   lambda = 10 ^ ( (a + c*T^0.5 + e*T + g*T^1.5 + i*T^2)
  //                  /(1 + b*T^0.5 + d*T + f*T^1.5 + h*T^2) )
  // Coefficients for RRR=50 (typical technical OFHC).
protected
  constant Real a =  1.8743;
  constant Real b = -0.41538;
  constant Real c = -0.6018;
  constant Real dd =  0.13294;
  constant Real e =  0.26426;
  constant Real f = -0.0219;
  constant Real g = -0.051276;
  constant Real h =  0.0014871;
  constant Real ii =  0.003723;
equation
  lambda = 10 ^ ( (a + c*T^0.5 + e*T + g*T^1.5 + ii*T^2)
                / (1 + b*T^0.5 + dd*T + f*T^1.5 + h*T^2));

  annotation (Documentation(info="<html>
<p>Temperature-dependent OFHC copper solid material, extending
<code>TSMedia.SolidTypes.BaseSolid</code>.</p>

<p><b>cp</b> is table-interpolated over 20-300 K. For a magnet coil this
is the thermal mass that governs cooldown time, so the low-temperature
drop matters directly.</p>

<p><b>lambda</b> uses the NIST OFHC copper rational-function fit for
RRR=50 (valid 4-300 K). If your copper has a different residual
resistivity ratio, swap the coefficient set - RRR strongly affects
low-temperature conductivity but barely changes it near room
temperature.</p>

<p>As with the steel record, confirm the consuming wall component feeds
live temperature into <code>input T</code>.</p>
</html>"));
end CopperOFHC_Tdep;
