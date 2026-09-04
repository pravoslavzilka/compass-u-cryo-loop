within CoilLoopCompassU.Common;
model CopperOFHC_RRR30_Tdep
  "OFHC copper (RRR~30) with temperature-dependent cp and lambda"
  extends TSMedia.SolidTypes.BaseSolid(
    cp_nominal = 385,      // room-temperature reference [J/(kg.K)]
    lambda_nominal = 400,  // room-temperature reference [W/(m.K)]
    d = 8960);              // density [kg/m3]

  // cp(T): same table as CopperOFHC_Tdep (RRR=50) -- cp is a lattice
  // property, essentially RRR-independent.
protected
  constant Real Tdata[:]  = {20, 40, 80, 100, 150, 200, 250, 300};
  constant Real cpData[:] = {7.5, 58, 180, 250, 322, 356, 377, 385};
  Real Tc = noEvent(max(T, 1)) "Clamped for Newton trial values outside 1-300K.";

equation
  cp = Modelica.Math.Vectors.interpolate(Tdata, cpData, Tc);

  // lambda(T,RRR=30): scaled from the RRR=50 curve via Matthiessen's rule
  // (electronic conductivity from residual/impurity scattering is roughly
  // proportional to RRR; phonon-limited conduction above ~150K is
  // RRR-independent). Scale factor 0.6 (=30/50) below 100K, ramping to 1.0
  // by 150K, unscaled above.
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
                / (1 + b*Tc^0.5 + dd*Tc + f*Tc^1.5 + h*Tc^2));
  Real rrrScale = if Tc <= 100 then rrrScaleLow
                  elseif Tc >= 150 then 1.0
                  else rrrScaleLow + (Tc-100)/(150-100)*(1.0-rrrScaleLow);
equation
  lambda = lambda_RRR50 * rrrScale;

  annotation (Documentation(info="<html>
<p>Temperature-dependent OFHC copper solid material for RRR~30, extending
<code>TSMedia.SolidTypes.BaseSolid</code> -- structurally mirrors
<a href=\"modelica://CoilLoopCompassU.Common.CopperOFHC_Tdep\">CopperOFHC_Tdep</a>
(RRR=50).</p>
</html>"));
end CopperOFHC_RRR30_Tdep;
