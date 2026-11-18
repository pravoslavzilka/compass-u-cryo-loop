within CoilLoopCompassU.Common;
model CopperOFHC_Tdep
  "OFHC copper with temperature-dependent cp and lambda"
  extends TSMedia.SolidTypes.BaseSolid(
    cp_nominal = 385,      // room-temperature reference [J/(kg.K)]
    lambda_nominal = 400,  // room-temperature reference [W/(m.K)]
    d = 8960);             // density [kg/m3], treated as constant

  // -------------------------------------------------------------------
  // Specific heat capacity cp(T), J/(kg.K)
  // Table interpolation, 1-300 K, sampled from the NIST OFHC copper cp fit
  // (trc.nist.gov/cryogenics/materials/OFHC Copper, log10-polynomial a-h,
  // valid 4-300 K, ~1% error for T>=15 K). 2026-11-11: replaced the earlier
  // 8-point table, whose linear chords under-read cp by up to 13% at
  // 70-90 K (e.g. 171 vs 196 J/kg/K at 77 K). The 1 K point is an anchor
  // (cp ~ T below 4 K) so out-of-range Newton trials stay finite.
  // Interpolation error vs the fit is <1% above ~40 K (max 4% at 20-25 K,
  // where the coils never operate).
  // Copper cp falls steeply toward low T, so a constant value is badly
  // wrong for a cryogenic coil - which for a magnet coil is exactly
  // the wall thermal mass that sets cooldown time.
  //
  // -------------------------------------------------------------------

protected
  constant Real Tdata[:]  = {1, 4, 10, 15, 20, 25, 30, 40, 50, 60, 70, 77, 80, 90, 100, 110, 120, 135, 150, 175, 200, 225, 250, 275, 300};
  constant Real cpData[:] = {0.025, 0.1, 0.86, 2.96, 7.51, 15.26, 26.47, 57.84, 96.27, 135.88, 172.76, 195.92, 205.1, 232.5, 255.33, 274.24, 289.97, 309.01, 324.11, 343.73, 359.01, 371.24, 380.62, 386.84, 389.4};

  // Newton iterations on the wall-cell energy balance routinely probe T
  // values outside the physical range while searching for a consistent
  // solution (more so the more wall cells are coupled together, e.g. at
  // higher nCells). T^0.5 below is NaN for T<0, and the cp table
  // linearly extrapolates below 20K toward/through zero -- both blow up
  // the solver instead of just giving a bad-but-finite trial value.
  // Clamp the value fed to both correlations (not the true state T) so
  // out-of-range Newton trials stay finite; in-range physics (>=1K,
  // i.e. always in practice) is unaffected.
  Real Tc = noEvent(max(T, 1));

equation
  cp = Modelica.Math.Vectors.interpolate(Tdata, cpData, Tc);

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
  lambda = 10 ^ ( (a + c*Tc^0.5 + e*Tc + g*Tc^1.5 + ii*Tc^2)
                / (1 + b*Tc^0.5 + dd*Tc + f*Tc^1.5 + h*Tc^2));

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
