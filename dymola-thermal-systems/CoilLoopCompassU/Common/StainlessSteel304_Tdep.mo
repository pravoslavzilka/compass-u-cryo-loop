within CoilLoopCompassU.Common;
model StainlessSteel304_Tdep
  "304/304L stainless steel with temperature-dependent cp and lambda"
  extends TSMedia.SolidTypes.BaseSolid(
    cp_nominal = 500,      // room-temperature reference value [J/(kg.K)]
    lambda_nominal = 15,   // room-temperature reference value [W/(m.K)]
    d = 7900);             // density [kg/m3], treated as constant

  // -------------------------------------------------------------------
  // Specific heat capacity cp(T), J/(kg.K)
  // Table interpolation, valid across the full 20-300 K range.
  // Values from standard cryogenic references (304/304L austenitic SS).
  // cp drops steeply toward low temperature - this is the whole point
  // of making it T-dependent, since a flat 500 J/(kg.K) massively
  // overstates wall thermal mass below ~150 K.
  //
  //   T [K] :   20    40    80   100   120   160   200   250   300
  //   cp    :   17   100   250   322   380   460   510   540   500
  // -------------------------------------------------------------------

protected
  constant Real Tdata[:]  = {20, 40, 80, 100, 120, 160, 200, 250, 300};
  constant Real cpData[:] = {17, 100, 250, 322, 380, 460, 510, 540, 500};

equation
  // Linear interpolation of cp on the table above.
  // Modelica.Math.Vectors.interpolate does 1-D linear interpolation
  // and clamps (holds the end value) outside the table range.
  cp = Modelica.Math.Vectors.interpolate(Tdata, cpData, T);

  // Thermal conductivity lambda(T), W/(m.K)
  // NIST 304L fit, valid 1-300 K, form:
  //   log10(lambda) = a + b*L + c*L^2 + ... + i*L^8,  L = log10(T)
  lambda = 10 ^ ( -1.4087
                  + 1.3982 * log10(T)
                  + 0.2543 * log10(T)^2
                  - 0.6260 * log10(T)^3
                  + 0.2334 * log10(T)^4
                  + 0.4256 * log10(T)^5
                  - 0.4658 * log10(T)^6
                  + 0.1650 * log10(T)^7
                  - 0.0199 * log10(T)^8);

  annotation (Documentation(info="<html>
<p>Temperature-dependent 304/304L stainless steel solid material,
extending <code>TSMedia.SolidTypes.BaseSolid</code>.</p>

<p>The base record declares <code>cp</code> and <code>lambda</code> as
variables and provides an <code>input T</code>, so it is designed for
temperature dependence - the stock <code>TSMedia_Steel</code> simply
never wrote the equations and set <code>cp = cp_nominal</code>. This
record supplies them.</p>

<p><b>cp</b> is interpolated from a table valid over 20-300 K. Replace
the tabulated values with your preferred data source if needed; the
low-temperature drop is the physically important feature.</p>

<p><b>lambda</b> uses the NIST 304L polynomial fit (valid 1-300 K).</p>

<p><b>Density</b> is held constant; solid thermal contraction is
negligible for wall thermal-mass purposes.</p>

<p>Before relying on this, confirm the wall component that consumes the
material actually routes its live metal temperature into
<code>input T</code>. If the wall passes a fixed reference temperature,
this record will evaluate at that single point and give no benefit.</p>
</html>"));
end StainlessSteel304_Tdep;
