within CoilLoopCompassU.Common;
model CopperOFHC_RRR30_Tdep
  "OFHC copper (RRR~30) with temperature-dependent cp and lambda"
  extends TSMedia.SolidTypes.BaseSolid(
    cp_nominal = 385,      // room-temperature reference [J/(kg.K)]
    lambda_nominal = 400,  // room-temperature reference [W/(m.K)]
    d = 8960);             // density [kg/m3], treated as constant -- RRR (residual
                            // resistivity ratio) is a purity/defect-density measure,
                            // does not meaningfully change mass density.

  // -------------------------------------------------------------------
  // Specific heat capacity cp(T) -- UNCHANGED from CopperOFHC_Tdep (RRR=50).
  // cp is a lattice (phonon) property, essentially RRR-independent for
  // OFHC copper at any purity level relevant here -- only the electronic
  // contribution to thermal conductivity (lambda) depends on RRR.
  //   T [K] :   20    40    80   100   150   200   250   300
  //   cp    :  7.5   58   180   250   322   356   377   385
  // -------------------------------------------------------------------

protected
  constant Real Tdata[:]  = {20, 40, 80, 100, 150, 200, 250, 300};
  constant Real cpData[:] = {7.5, 58, 180, 250, 322, 356, 377, 385};
  Real Tc = noEvent(max(T, 1)) "Clamped for Newton trial values outside 1-300K, see CopperOFHC_Tdep's identical guard.";

equation
  cp = Modelica.Math.Vectors.interpolate(Tdata, cpData, Tc);

  // Thermal conductivity lambda(T,RRR=30), W/(m.K)
  // ================================================================
  // NOT an independently NIST-sourced RRR=30 fit -- no such fit was
  // available to derive this from (the NIST OFHC copper curve-fit table
  // this codebase's CopperOFHC_Tdep already draws from is commonly
  // tabulated for RRR=50/100/150/300/500, not 30). This is instead an
  // ENGINEERING APPROXIMATION built on CopperOFHC_Tdep's RRR=50 curve,
  // via the standard Matthiessen's-rule argument (e.g. Woodcraft,
  // "Predicting the thermal conductivity of RRR copper", Cryogenics 45
  // (2005)): the electronic thermal conductivity contribution limited by
  // impurity/defect (residual) scattering is, by the Wiedemann-Franz
  // law, roughly proportional to RRR at a given T; the phonon-limited
  // (high-T, T>~150K) contribution is essentially RRR-independent, which
  // is why real OFHC lambda(T) curves of different RRR converge near
  // room temperature (as CopperOFHC_Tdep's and this curve both do here).
  //
  // Implementation: scale CopperOFHC_Tdep's RRR=50 curve by the RRR
  // ratio (30/50=0.6) below 100K (residual-scattering-dominated,
  // where RRR matters most), ramp linearly back to a 1.0 scale factor
  // by 150K (phonon-dominated, RRR-independent), and leave unscaled
  // above 150K.
  //
  // CONFIDENCE: qualitatively correct (lower peak conductivity than
  // RRR=50, same high-T asymptote), but NOT independently verified
  // against real RRR=30 measurement/fit data. If cooldown-time accuracy
  // depends on this curve, replace with a primary-sourced RRR=30 fit
  // (e.g. NIST Monograph 177, or a mill-cert-matched reference) before
  // trusting it quantitatively.
  // ================================================================
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
  constant Real rrrScaleLow = 30/50 "Applied for T<=100K.";
  Real lambda_RRR50 = 10 ^ ( (a + c*Tc^0.5 + e*Tc + g*Tc^1.5 + ii*Tc^2)
                / (1 + b*Tc^0.5 + dd*Tc + f*Tc^1.5 + h*Tc^2))
    "Same NIST RRR=50 fit as CopperOFHC_Tdep, used here only as the basis for the RRR=30 approximation below.";
  Real rrrScale = if Tc <= 100 then rrrScaleLow
                  elseif Tc >= 150 then 1.0
                  else rrrScaleLow + (Tc-100)/(150-100)*(1.0-rrrScaleLow)
    "1.0 above 150K (phonon-dominated, RRR-independent); 0.6 below 100K (residual-scattering-dominated, scaled by RRR ratio); linear blend between.";
equation
  lambda = lambda_RRR50 * rrrScale;

  annotation (Documentation(info="<html>
<p>Temperature-dependent OFHC copper solid material for RRR~30, extending
<code>TSMedia.SolidTypes.BaseSolid</code> -- structurally mirrors
<a href=\"modelica://CoilLoopCompassU.Common.CopperOFHC_Tdep\">CopperOFHC_Tdep</a>
(RRR=50), see that model's docstring for the cp table and general
approach.</p>

<p><b>cp</b> is unchanged from the RRR=50 record (RRR-independent lattice
property).</p>

<p><b>lambda</b> is an ENGINEERING APPROXIMATION, not an independently
NIST-sourced RRR=30 fit -- see the inline comment above the equation for
the Matthiessen's-rule derivation and its confidence caveats. Replace
with a primary-sourced curve if quantitative cooldown-time accuracy at
RRR=30 matters.</p>

<p>As with the other Common material records, confirm the consuming wall
component routes its live metal temperature into <code>input T</code>.</p>
</html>"));
end CopperOFHC_RRR30_Tdep;
