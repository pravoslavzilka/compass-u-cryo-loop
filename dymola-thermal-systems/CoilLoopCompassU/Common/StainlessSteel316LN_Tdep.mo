within CoilLoopCompassU.Common;
model StainlessSteel316LN_Tdep
  "316LN stainless steel with temperature-dependent cp and lambda"
  extends TSMedia.SolidTypes.BaseSolid(
    cp_nominal = 500,      // room-temperature reference value [J/(kg.K)]
    lambda_nominal = 13.5, // room-temperature reference value [W/(m.K)]
    d = 8000);              // density [kg/m3], ASSUMED (typical 316L value; no
                             // project-specific mill-cert density found), treated
                             // as constant -- same convention as StainlessSteel304_Tdep's d=7900.

  // -------------------------------------------------------------------
  // Specific heat capacity cp(T), J/(kg.K)
  // ASSUMED: reuses StainlessSteel304_Tdep's table unchanged. cp(T) for
  // austenitic stainless steels (304/304L/316/316L/316LN/321/347) is
  // dominated by lattice (phonon) heat capacity, not the minor alloying
  // differences (Mo, N) that distinguish 316LN from 304 -- differences
  // are a few percent at most at cryogenic temperatures, well within the
  // precision this lumped-wall model needs. Replace with 316LN-specific
  // data if a tighter source is found.
  //
  //   T [K] :   20    40    80   100   120   160   200   250   300
  //   cp    :   17   100   250   322   380   460   510   540   500
  // -------------------------------------------------------------------

protected
  constant Real Tdata[:]  = {20, 40, 80, 100, 120, 160, 200, 250, 300};
  constant Real cpData[:] = {17, 100, 250, 322, 380, 460, 510, 540, 500};

equation
  cp = Modelica.Math.Vectors.interpolate(Tdata, cpData, T);

  // Thermal conductivity lambda(T), W/(m.K)
  // FROM SOURCE: NIST's cryogenic thermal-conductivity curve fit for
  // "300 series stainless steels", published as applicable across
  // 304/304L/310/316/321/347 -- i.e. the same fit StainlessSteel304_Tdep
  // uses, carried unchanged (not 316LN-specific, but NIST's own stated
  // scope covers this family; N content in 316LN has a negligible effect
  // on lambda at this level of precision). Valid 1-300K, form:
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
<p>Temperature-dependent 316LN stainless steel solid material, extending
<code>TSMedia.SolidTypes.BaseSolid</code> -- same structure as
<a href=\"modelica://CoilLoopCompassU.Common.StainlessSteel304_Tdep\">StainlessSteel304_Tdep</a>,
see that model's docstring for the general rationale.</p>

<p><b>cp</b> and <b>lambda</b> are both carried unchanged from the 304
record (ASSUMED / FROM SOURCE respectively, see inline comments) --
316LN-specific cryogenic data was not found; the 300-series family is
close enough for this purpose. Replace either curve if a tighter
316LN-specific source turns up.</p>

<p><b>Density</b> d=8000 kg/m3 is ASSUMED (typical 316L handbook value),
held constant.</p>

<p>Before relying on this, confirm the wall component that consumes the
material actually routes its live metal temperature into
<code>input T</code>.</p>
</html>"));
end StainlessSteel316LN_Tdep;
