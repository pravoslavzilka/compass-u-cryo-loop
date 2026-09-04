within CoilLoopCompassU.Common;
model StainlessSteel316LN_Tdep
  "316LN stainless steel with temperature-dependent cp and lambda"
  extends TSMedia.SolidTypes.BaseSolid(
    cp_nominal = 500,      // room-temperature reference value [J/(kg.K)]
    lambda_nominal = 13.5, // room-temperature reference value [W/(m.K)]
    d = 8000);              // density [kg/m3]

  // cp(T): same table as StainlessSteel304_Tdep -- 300-series austenitic
  // steels share essentially the same lattice specific heat.
protected
  constant Real Tdata[:]  = {20, 40, 80, 100, 120, 160, 200, 250, 300};
  constant Real cpData[:] = {17, 100, 250, 322, 380, 460, 510, 540, 500};

equation
  cp = Modelica.Math.Vectors.interpolate(Tdata, cpData, T);

  // lambda(T): NIST 300-series stainless steel fit (covers 304/310/316/
  // 321/347), same as StainlessSteel304_Tdep. Valid 1-300K.
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
<p>Temperature-dependent 316LN stainless steel solid material, extending
<code>TSMedia.SolidTypes.BaseSolid</code> -- same structure as
<a href=\"modelica://CoilLoopCompassU.Common.StainlessSteel304_Tdep\">StainlessSteel304_Tdep</a>.</p>
</html>"));
end StainlessSteel316LN_Tdep;
