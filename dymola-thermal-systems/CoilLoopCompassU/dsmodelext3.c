#include <moutil.c>
PreNonAliasDef(16)
PreNonAliasDef(17)
PreNonAliasDef(18)
PreNonAliasDef(19)
PreNonAliasDef(20)
StartNonAlias(15)
DeclareVariable("PF4U.valve1.propertiesInB.VLE.T_l", "Temperature of liquid phase [K|degC]",\
 11968, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.valve1.propertiesInB.VLE.T_v", "Temperature of vapour phase [K|degC]",\
 11969, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.valve1.propertiesInB.VLETransp.Pr_l", "Prandtl number of liquid phase [1]",\
 11970, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.propertiesInB.VLETransp.Pr_v", "Prandtl number of vapour phase [1]",\
 11971, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.propertiesInB.VLETransp.lambda_l", "Thermal conductivity of liquid phase [W/(m.K)]",\
 11972, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.propertiesInB.VLETransp.lambda_v", "Thermal conductivity of vapour phase [W/(m.K)]",\
 11973, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.propertiesInB.VLETransp.eta_l", "Dynamic viscosity of liquid phase [Pa.s]",\
 11974, 0.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.valve1.propertiesInB.VLETransp.eta_v", "Dynamic viscosity of vapour phase [Pa.s]",\
 11975, 0.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.valve1.propertiesInB.transp.Pr", "Prandtl number [1]", 11976,\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.propertiesInB.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 11977, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.propertiesInB.transp.eta", "Dynamic viscosity [Pa.s]",\
 11978, 0.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.valve1.propertiesInB.transp.sigma", "Surface tension [N/m]",\
 11979, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.propertiesInB.gamma", "Heat capacity ratio aka isentropic expansion factor [1]",\
 17099, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.propertiesInB.w", "Speed of sound [m/s]", 11980, 0,\
 0.0,0.0,0.0,0,2561)
DeclareParameter("PF4U.valve1.mdotSmooth", "Below this value, root function is approximated [kg/s]",\
 1201, 0.0005, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.valve1.effectiveFlowAreaTypical", "Typical effective flow area [m2]",\
 1202, 3E-06, 0.0,1.7976931348623157E+308,0.0,0,560)
DeclareVariable("PF4U.valve1.smoothMode", "1=mdotSmooth, 2=psiSmooth [:#(type=Integer)]",\
 11981, 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.valve1.includeDefaultSummary", "include default entries in summary [:#(type=Boolean)]",\
 11982, true, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.valve1.effectiveFlowArea", "Effective flow area [m2]", 11983,\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 11984, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.valve1.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 11985, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 11986, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 11987,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 11988, 1, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 11989, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 11990, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.simPort.vleFluidMass", "[kg]", 11991, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.valve1.simPort.vleFluidVolume", "[m3]", 11992, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.simPort.liquidMass", "[kg]", 11993, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.valve1.simPort.liquidVolume", "[m3]", 11994, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.valve1.simPort.gasMass", "[kg]", 11995, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.simPort.gasVolume", "[m3]", 11996, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("PF4U.valve1.simPort.dpdt", "", 11997, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.simPort.dpdtCounter", "", 11998, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.simPort.vleFluidPort.vleFluidMass", \
"Accumulated fluid mass [kg]", 11999, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.valve1.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 12000, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.valve1.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 12001, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.valve1.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 12002, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.valve1.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 12003, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.valve1.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 12004, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.valve1.simPort.dpdtPort.dpdt", "", 12005, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("PF4U.valve1.simPort.dpdtPort.counter", "", 12006, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.valve1.simPort.warningsPort.warnings", "Accumulated warnings",\
 17100, 0.0, 0.0,0.0,0.0,0,2824)
DeclareVariable("PF4U.valve1.valveFlowVariableType", "Flow variable type of valve (Aeff or Kv) [:#(type=ThermalSystems.Internals.ValveFlowVariableType)]",\
 12007, 2, 1.0,2.0,0.0,0,517)
DeclareVariable("PF4U.valve1.use_effectiveFlowAreaInput", "If true: effectiveFlowArea defined by input [:#(type=Boolean)]",\
 12008, false, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.valve1.effectiveFlowAreaFixed", "Effective flow area [m2]",\
 1203, 3E-06, 0.0,1.7976931348623157E+308,0.0,0,560)
DeclareVariable("PF4U.valve1.use_KvValueInput", "If true: Kv-value defined by input [:#(type=Boolean)]",\
 12009, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.valve1.KvValueFixed", "Kv-value [m3/h]", 12010, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,513)
DeclareParameter("PF4U.valve1.relativeLeakage", "Relative leakage in check valve operation [1]",\
 1204, 0.0001, 0.0,1.0,0.0,0,560)
DeclareParameter("PF4U.valve1.m_flowStart", "Mass flow rate at start [kg/s]", 1205,\
 1E-06, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.valve1.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12011, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.valve1.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12012,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.valve1.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12013, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12014,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12015, 1,\
 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12016, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12017, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.valve1.portA.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1,\
 4)
DeclareAlias2("PF4U.valve1.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4U.portA1.m_flow", 1, 5, 17139, 132)
DeclareAlias2("PF4U.valve1.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction2.h", 1, 1, 102, 4)
DeclareVariable("PF4U.valve1.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12018, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.valve1.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12019,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.valve1.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12020, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12021,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12022, 1,\
 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12023, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12024, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.valve1.portB.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.valve1.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.portA1.m_flow", -1, 5, 17139, 132)
DeclareAlias2("PF4U.valve1.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction14.h", 1, 1, 117, 4)
DeclareVariable("PF4U.valve1.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12025, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.valve1.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12026,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12027, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12028,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12029, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12030, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12031, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasA.gasPointer.id", "[:#(type=Integer)]", 12032, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.valve1.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1206, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.valve1.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12033, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.valve1.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12034,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12035, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12036,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12037, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12038, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12039, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasB.gasPointer.id", "[:#(type=Integer)]", 12040, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.valve1.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1207, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.valve1.gasInA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12041, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.valve1.gasInA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12042,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12043, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12044,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasInA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12045, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasInA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12046, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12047, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInA.gasPointer.id", "[:#(type=Integer)]", 12048,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.valve1.gasInA.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 12049,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.valve1.gasInA.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 12050, false,\
 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.valve1.gasInA.d", "Density [kg/m3|g/cm3]", "PF4U.valve1.propertiesInA.d", 1,\
 5, 17090, 1024)
DeclareAlias2("PF4U.valve1.gasInA.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1,\
 1024)
DeclareAlias2("PF4U.valve1.gasInA.h", "Specific enthalpy [J/kg]", "junction14.h", 1,\
 1, 117, 1024)
DeclareAlias2("PF4U.valve1.gasInA.s", "Specific entropy [J/(kg.K)]", \
"PF4U.valve1.propertiesInA.s", 1, 5, 17091, 1024)
DeclareAlias2("PF4U.valve1.gasInA.T", "Temperature [K|degC]", "PF4U.valve1.propertiesInA.T", 1,\
 5, 17092, 1024)
DeclareAlias2("PF4U.valve1.gasInA.M", "Average molar mass [kg/mol]", \
"PF4U.valve1.gasInA.M_i[1]", 1, 5, 12056, 1024)
DeclareAlias2("PF4U.valve1.gasInA.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.valve1.propertiesInA.cp", 1, 5, 17093, 1024)
DeclareVariable("PF4U.valve1.gasInA.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17101, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17102, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.kappa", "Isothermal compressibility [1/Pa]",\
 17103, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.w", "Speed of sound [m/s]", 17104, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17105, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17106, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.p_i[1]", "Partial pressure [Pa|bar]", 17107,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17108, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.phi", "Relative humidity", 12051, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 12052, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.xi_s", "Saturation mass fraction of condensing component [1]",\
 12053, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 12054, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 12055, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17109, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.M_i[1]", "Molar mass of component i [kg/mol]",\
 12056, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.humRatio", "Content of condensing component aka humidity ratio [1]",\
 12057, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 12058, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 12059, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.transp.Pr", "Prandtl number [1]", 12060, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 12061, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.transp.eta", "Dynamic viscosity [Pa.s]", 12062,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.transp.sigma", "Surface tension [N/m]", 12063,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.computeFlags", "[:#(type=Integer)]", 12064, 0,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.valve1.gasInB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12065, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.valve1.gasInB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12066,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12067, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12068,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasInB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12069, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasInB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12070, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12071, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInB.gasPointer.id", "[:#(type=Integer)]", 12072,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.valve1.gasInB.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 12073,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.valve1.gasInB.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 12074, false,\
 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.valve1.gasInB.d", "Density [kg/m3|g/cm3]", "PF4U.valve1.propertiesInB.d", 1,\
 5, 17095, 1024)
DeclareAlias2("PF4U.valve1.gasInB.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 1024)
DeclareAlias2("PF4U.valve1.gasInB.h", "Specific enthalpy [J/kg]", \
"PF4U.junction2.h", 1, 1, 102, 1024)
DeclareAlias2("PF4U.valve1.gasInB.s", "Specific entropy [J/(kg.K)]", \
"PF4U.valve1.propertiesInB.s", 1, 5, 17096, 1024)
DeclareAlias2("PF4U.valve1.gasInB.T", "Temperature [K|degC]", "PF4U.valve1.propertiesInB.T", 1,\
 5, 17097, 1024)
DeclareAlias2("PF4U.valve1.gasInB.M", "Average molar mass [kg/mol]", \
"PF4U.valve1.gasInB.M_i[1]", 1, 5, 12080, 1024)
DeclareAlias2("PF4U.valve1.gasInB.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.valve1.propertiesInB.cp", 1, 5, 17098, 1024)
DeclareVariable("PF4U.valve1.gasInB.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17110, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17111, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.kappa", "Isothermal compressibility [1/Pa]",\
 17112, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.w", "Speed of sound [m/s]", 17113, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17114, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17115, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.p_i[1]", "Partial pressure [Pa|bar]", 17116,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17117, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.phi", "Relative humidity", 12075, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 12076, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.xi_s", "Saturation mass fraction of condensing component [1]",\
 12077, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 12078, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 12079, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17118, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.M_i[1]", "Molar mass of component i [kg/mol]",\
 12080, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.humRatio", "Content of condensing component aka humidity ratio [1]",\
 12081, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 12082, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 12083, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.transp.Pr", "Prandtl number [1]", 12084, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 12085, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.transp.eta", "Dynamic viscosity [Pa.s]", 12086,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.transp.sigma", "Surface tension [N/m]", 12087,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.computeFlags", "[:#(type=Integer)]", 12088, 0,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.valve1.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 12089, false, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.valve1.flowPrinciple.warningLinearizationRange", "", \
"PF4U.valve1.warningLinearizationRange", 1, 5, 17138, 0)
DeclareAlias2("PF4U.valve1.flowPrinciple.massFlowRateDensity_A", "[kg/(s.m2)]", \
"PF4U.valve1.massFlowRateDensity", 1, 5, 17122, 512)
DeclareVariable("PF4U.valve1.flowPrinciple.w_gas", "Speed of sound at throttle [m/s]",\
 17119, 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("PF4U.valve1.flowPrinciple.velocity_gas", "Flow velocity at throttle [m/s]",\
 17120, 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("PF4U.valve1.flowPrinciple.Ma_gas", "Mach number at throttle [1]",\
 17121, 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("PF4U.valve1.flowPrinciple.enableChokedFlow", "If true, then choked flow is taken into account [:#(type=Boolean)]",\
 12090, true, 0.0,0.0,0.0,0,2563)
DeclareParameter("PF4U.valve1.flowPrinciple.psiSquareSmooth", "Negative value for automatic detection.",\
 1208, 0.001, 0.0,0.0,0.0,0,2608)
DeclareParameter("PF4U.valve1.use_mdotLinearization", "If true, use mass flow rate for linearization, else default linearization [:#(type=Boolean)]",\
 1209, true, 0.0,0.0,0.0,0,562)
DeclareParameter("PF4U.valve1.d_nominal", "Nominal density [kg/m3|kg/m3]", 1210,\
 1000, 0.0,1.7976931348623157E+308,0.0,0,560)
DeclareVariable("PF4U.valve1.massFlowRateDensity", "[kg/(s.m2)]", 17122, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.massFlowRateDensityLinearization", "[kg/(s.m2)]", 12091,\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12092, true, 0.0,0.0,0.0,0,515)
DeclareAlias2("PF4U.valve1.summary.p_gas_A", "Pressure at port A [Pa|bar]", \
"tube1.p[1]", 1, 1, 1, 0)
DeclareAlias2("PF4U.valve1.summary.p_gas_B", "Pressure at port B [Pa|bar]", \
"PF4U.junction2.p", 1, 1, 103, 0)
DeclareVariable("PF4U.valve1.summary.T_gas_A", "Temperature at port A [K|degC]",\
 17123, 288.15, 0.0,1.7976931348623157E+308,300.0,0,512)
DeclareVariable("PF4U.valve1.summary.T_gas_B", "Temperature at port B [K|degC]",\
 17124, 288.15, 0.0,1.7976931348623157E+308,300.0,0,512)
DeclareVariable("PF4U.valve1.summary.T_degC_gas_A", "Temperature at port A [degC;]",\
 17125, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.T_degC_gas_B", "Temperature at port B [degC;]",\
 17126, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.h_gas_A", "Specific enthalpy at port A [J/kg]",\
 17127, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.h_gas_B", "Specific enthalpy at port B [J/kg]",\
 17128, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.d_gas_A", "Density at port A [kg/m3|g/cm3]",\
 17129, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.d_gas_B", "Density at port B [kg/m3|g/cm3]",\
 17130, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareAlias2("PF4U.valve1.summary.m_flow_gas_A", "Mass flow rate at port A [kg/s]",\
 "PF4U.portA1.m_flow", 1, 5, 17139, 0)
DeclareAlias2("PF4U.valve1.summary.m_flow_gas_B", "Mass flow rate at port B [kg/s]",\
 "PF4U.portA1.m_flow", -1, 5, 17139, 0)
DeclareVariable("PF4U.valve1.summary.V_flow_gas_A", "Volume flow rate at port A [m3/s]",\
 17131, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.V_flow_gas_B", "Volume flow rate at port B [m3/s]",\
 17132, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.phi_gas_A", "Relative humidity at port A", 17133,\
 0.0, 0.0,100.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.phi_gas_B", "Relative humidity at port B", 17134,\
 0.0, 0.0,100.0,0.0,0,512)
DeclareAlias2("PF4U.valve1.summary.effectiveFlowArea", "Effective flow area [m2]",\
 "PF4U.valve1.effectiveFlowArea", 1, 5, 11983, 0)
DeclareVariable("PF4U.valve1.summary.Kv", "Kv-value [m3/h]", 12093, 0.0, \
0.0,0.0,0.0,0,513)
DeclareAlias2("PF4U.valve1.summary.w_gas", "Speed of sound at throttle [m/s]", \
"PF4U.valve1.flowPrinciple.w_gas", 1, 5, 17119, 0)
DeclareVariable("PF4U.valve1.summary.velocity_gas", "Flow velocity at throttle [m/s]",\
 17135, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.Ma_gas", "Mach number at throttle [1]", 17136,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.dp_gas", "Total pressure drop [Pa|bar]", 17137,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.nc_gas", "Number of components [:#(type=Integer)]",\
 12094, 1, 0.0,0.0,0.0,0,517)
DeclareVariable("PF4U.valve1.visualizeWarnings", "If true, warnings will be visualized in the diagram layer [:#(type=Boolean)]",\
 12095, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.valve1.warningNegativeFlowArea", "Flow Area is negative", 12096,\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.valve1.warningLinearizationRange", "Mass flow rate is within linearization range",\
 17138, 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.valve1.getInputs.effectiveFlowArea_in", "Prescribed effective flow area [m^2] [m2]",\
 "PF4U.valve1.effectiveFlowArea_in_.k", 1, 5, 12097, 1024)
DeclareAlias2("PF4U.valve1.getInputs.KvValue_in", "Prescribed Kv-value [m^3/h] [m3/h]",\
 "PF4U.valve1.KvValue_in_.k", 1, 5, 12098, 1024)
DeclareVariable("PF4U.valve1.effectiveFlowArea_in_.k", "Constant output value [m2]",\
 12097, 1, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.valve1.effectiveFlowArea_in_.y", "Connector of Real output signal [m2]",\
 "PF4U.valve1.effectiveFlowArea_in_.k", 1, 5, 12097, 1024)
DeclareVariable("PF4U.valve1.KvValue_in_.k", "Constant output value [m3/h]", 12098,\
 1, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.valve1.KvValue_in_.y", "Connector of Real output signal [m3/h]",\
 "PF4U.valve1.KvValue_in_.k", 1, 5, 12098, 1024)
DeclareVariable("PF4U.valve1.dp_nominal", "Reference pressure difference [Pa|bar]",\
 12099, 100000.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.portA1.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12100, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.portA1.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 12101, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.portA1.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12102, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.portA1.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12103,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.portA1.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 12104, 1, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.portA1.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12105, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.portA1.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12106, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.portA1.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareVariable("PF4U.portA1.m_flow", "Mass flow rate [kg/s]", 17139, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.portA1.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction2.h", 1, 1, 102, 4)
DeclareVariable("PF4U.portB1.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12107, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.portB1.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 12108, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.portB1.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12109, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.portB1.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12110,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.portB1.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 12111, 1, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.portB1.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12112, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.portB1.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12113, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.portB1.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18,\
 4)
DeclareVariable("PF4U.portB1.m_flow", "Mass flow rate [kg/s]", 17140, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.portB1.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction6.h", 1, 1, 114, 4)
DeclareVariable("PF4U.junction2.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12114, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12115,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12116, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12117,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 12118, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12119, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12120, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.simPort.vleFluidMass", "[kg]", 12121, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.simPort.vleFluidVolume", "[m3]", 12122, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.simPort.liquidMass", "[kg]", 12123, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.simPort.liquidVolume", "[m3]", 12124, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.junction2.simPort.gasMass", "[kg]", "PF4U.junction2.mass", 1,\
 5, 17156, 1024)
DeclareAlias2("PF4U.junction2.simPort.gasVolume", "[m3]", "PF4U.junction2.volume", 1,\
 7, 1211, 1024)
DeclareVariable("PF4U.junction2.simPort.dpdt", "", 12125, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.simPort.dpdtCounter", "", 12126, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.junction2.simPort.vleFluidPort.vleFluidMass", \
"Accumulated fluid mass [kg]", 12127, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction2.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 12128, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction2.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 12129, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction2.simPort.liquidPort.liquidVolume", \
"Accumulated liquid volume [m3]", 12130, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.junction2.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.junction2.mass", 1, 5, 17156, 1156)
DeclareAlias2("PF4U.junction2.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.junction2.volume", 1, 7, 1211, 1156)
DeclareVariable("PF4U.junction2.simPort.dpdtPort.dpdt", "", 12131, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.junction2.simPort.dpdtPort.counter", "", 12132, 0.0, \
0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction2.simPort.warningsPort.warnings", "Accumulated warnings",\
 12133, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction2.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 12134, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction2.portA.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12135, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12136,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12137, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.portA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12138,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12139, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12140, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12141, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction2.portA.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareVariable("PF4U.junction2.portA.m_flow", "Mass flow rate [kg/s]", 17141, \
0.0, 0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.junction2.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction2.h", 1, 1, 102, 4)
DeclareVariable("PF4U.junction2.portB.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12142, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12143,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12144, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.portB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12145,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12146, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12147, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12148, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction2.portB.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.junction2.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.portA1.m_flow", 1, 5, 17139, 132)
DeclareAlias2("PF4U.junction2.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction2.h", 1, 1, 102, 4)
DeclareVariable("PF4U.junction2.portC.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12149, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12150,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12151, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.portC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12152,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12153, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12154, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12155, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction2.portC.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareVariable("PF4U.junction2.portC.m_flow", "Mass flow rate [kg/s]", 17142, \
0.0, 0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.junction2.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction2.h", 1, 1, 102, 4)
DeclareVariable("PF4U.junction2.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12156, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12157,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12158, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gas.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12159,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gas.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12160, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12161, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12162, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gas.gasPointer.id", "[:#(type=Integer)]", 12163,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.junction2.gas.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 12164,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction2.gas.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 12165, false,\
 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction2.gas.d", "Density [kg/m3|g/cm3]", 17143, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.junction2.gas.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 1024)
DeclareAlias2("PF4U.junction2.gas.der(p)", "der(Pressure) [Pa/s]", \
"PF4U.junction2.der(p)", 1, 6, 103, 1024)
DeclareAlias2("PF4U.junction2.gas.h", "Specific enthalpy [J/kg]", \
"PF4U.junction2.h", 1, 1, 102, 1024)
DeclareAlias2("PF4U.junction2.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"PF4U.junction2.der(h)", 1, 6, 102, 1024)
DeclareVariable("PF4U.junction2.gas.s", "Specific entropy [J/(kg.K)]", 17144, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.T", "Temperature [K|degC]", 17145, 288.15, \
0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.junction2.gas.M", "Average molar mass [kg/mol]", \
"PF4U.junction2.gas.M_i[1]", 1, 5, 12171, 1024)
DeclareVariable("PF4U.junction2.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17146, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17147, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17148, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.kappa", "Isothermal compressibility [1/Pa]",\
 17149, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.w", "Speed of sound [m/s]", 17150, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17151, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17152, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.p_i[1]", "Partial pressure [Pa|bar]", 17153,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.junction2.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17154, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.phi", "Relative humidity", 12166, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 12167, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.junction2.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 12168, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 12169, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 12170, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17155, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.M_i[1]", "Molar mass of component i [kg/mol]",\
 12171, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 12172, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 12173, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 12174, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.transp.Pr", "Prandtl number [1]", 12175, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 12176, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.transp.eta", "Dynamic viscosity [Pa.s]", 12177,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.transp.sigma", "Surface tension [N/m]", 12178,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.computeFlags", "[:#(type=Integer)]", 12179, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction2.volume", "[m3]", 1211, 0.0001, 0.0,\
1.7976931348623157E+308,0.0,0,560)
DeclareParameter("PF4U.junction2.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1212, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.junction2.pInitial", "Initial value for air pressure [Pa|bar]",\
 1213, 2000000, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.junction2.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 12180, false, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.junction2.TInitial", "Initial value for air temperature [K|K]",\
 1214, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.junction2.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1215, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.junction2.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 12181, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.junction2.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1216, 1, 0.0,0.0,0.0,0,560)
DeclareState("PF4U.junction2.h", "Specific enthalpy [J/kg]", 102, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("PF4U.junction2.der(h)", "der(Specific enthalpy) [m2/s3]", 102,\
 0.0, 0.0,0.0,0.0,0,576)
DeclareState("PF4U.junction2.p", "[Pa|bar]", 103, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,544)
DeclareDerivative("PF4U.junction2.der(p)", "[Pa/s]", 103, 0.0, 0.0,0.0,0.0,0,576)
DeclareVariable("PF4U.junction2.mass", "Gas mass in control volume [kg]", 17156,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.junction2.drhodt", "[Pa.m-2.s]", 17157, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.junction2.hInitial", "[J/kg]", 12182, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12183, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.junction2.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12184, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction2.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12185, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12186,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12187, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12188,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12189, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12190, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12191, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasA.gasPointer.id", "[:#(type=Integer)]", 12192,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction2.gasA.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1217, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction2.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12193, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12194,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12195, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12196,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12197, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12198, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12199, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasB.gasPointer.id", "[:#(type=Integer)]", 12200,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction2.gasB.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1218, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction2.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12201, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12202,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12203, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12204,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12205, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12206, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12207, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasC.gasPointer.id", "[:#(type=Integer)]", 12208,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction2.gasC.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1219, false,\
 0.0,0.0,0.0,0,2610)
DeclareParameter("PF4U.prescribedHeatFlow1.T_ref", "Reference temperature [K|degC]",\
 1220, 293.15, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.prescribedHeatFlow1.alpha", "Temperature coefficient of heat flow rate [1/K]",\
 1221, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.prescribedHeatFlow1.Q_flow", "[W]", 17158, 0.0, 0.0,0.0,\
0.0,0,512)
DeclareAlias2("PF4U.prescribedHeatFlow1.port.T", "Port temperature [K|degC]", \
"PF4U.Channel2.T_wall", 1, 5, 17012, 4)
DeclareVariable("PF4U.prescribedHeatFlow1.port.Q_flow", "Heat flow rate (positive if flowing from outside into the component) [W]",\
 17159, 0, 0.0,0.0,0.0,0,776)
DeclareParameter("PF4U.stepSource1.transitionTime", "Duration of transition [s]",\
 1222, 0.5, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.stepSource1.initialValue", "Value before first step", 1223,\
 0.0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.stepSource1.stepTimes[1]", "Beginning of transitions [s]",\
 12209, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource1.stepTimes[2]", "Beginning of transitions [s]",\
 12210, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource1.stepValues[1]", "Values of steps", 12211, 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource1.stepValues[2]", "Values of steps", 12212, 0.0,\
 0.0,0.0,0.0,0,513)
DeclareAlias2("PF4U.stepSource1.y", "[W]", "PF4U.prescribedHeatFlow1.Q_flow", 1,\
 5, 17158, 0)
DeclareVariable("PF4U.stepSource1.stepCount", "[:#(type=Integer)]", 12213, 2, \
0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.stepSource1.const_finalValue.k", "Constant output value [W]",\
 12214, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.const_finalValue.y", "Connector of Real output signal [W]",\
 12215, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[1].switchTime", "[s]", 12216, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[1].transitionTime", "[s]", 12217, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[1].preSwitchValue", \
"Value to use before switching to input [W]", 12218, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[1].u", "[W]", 12219, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[1].y", "[W]", 17160, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("PF4U.stepSource1.timeSwitch[1].switchEndTime", "[s]", 12220, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[1].switchMidTime", "[s]", 12221, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[2].switchTime", "[s]", 12222, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[2].transitionTime", "[s]", 12223, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[2].preSwitchValue", \
"Value to use before switching to input [W]", 12224, 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.stepSource1.timeSwitch[2].u", "[W]", "PF4U.stepSource1.timeSwitch[1].y", 1,\
 5, 17160, 1024)
DeclareAlias2("PF4U.stepSource1.timeSwitch[2].y", "[W]", "PF4U.prescribedHeatFlow1.Q_flow", 1,\
 5, 17158, 1024)
DeclareVariable("PF4U.stepSource1.timeSwitch[2].switchEndTime", "[s]", 12225, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[2].switchMidTime", "[s]", 12226, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12227, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube1.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 12228, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12229, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12230,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 12231, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12232, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12233, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.tubeGeometry.innerDiameter", "Inner diameter of circular tube [m]",\
 12234, 0.0, 0.0,1.7976931348623157E+308,0.0,0,513)
DeclareParameter("PF4U.tube1.tubeGeometry.wallThickness", "Wall thickness [m]", 1224,\
 0.0005, 0.0,1.7976931348623157E+308,0.0,0,560)
DeclareVariable("PF4U.tube1.tubeGeometry.length", "Length [m]", 12235, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,513)
DeclareParameter("PF4U.tube1.tubeGeometry.nParallelTubes", "Number of parallel Tubes [:#(type=Integer)]",\
 1225, 1, 1.0,1.7976931348623157E+308,0.0,0,564)
DeclareParameter("PF4U.tube1.tubeGeometry.crossSectionType", "Tube Cross Section Type [:#(type=ThermalSystems.Internals.CrossSectionType)]",\
 1226, 1, 1.0,2.0,0.0,0,564)
DeclareParameter("PF4U.tube1.tubeGeometry.innerCrossSectionalAreaNonCircular", \
"Inner cross sectional area of one non-circular tube [m2]", 1227, 0, 0.0,0.0,0.0,\
0,560)
DeclareParameter("PF4U.tube1.tubeGeometry.outerCrossSectionalAreaNonCircular", \
"Outer cross sectional area of one non-circular tube [m2]", 1228, 0, 0.0,0.0,0.0,\
0,560)
DeclareParameter("PF4U.tube1.tubeGeometry.innerPerimeterNonCircular", \
"Perimeter of one non-circular tube [m]", 1229, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.tube1.tubeGeometry.outerDiameter", "[m]", 12236, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.innerCrossSectionalArea", \
"Inner cross-sectional area [m2]", 12237, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.outerCrossSectionalArea", \
"Outer cross-sectional area [m2]", 12238, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.hydraulicCrossSectionalArea", \
"Hydraulic cross sectional area [m2]", 12239, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.hydraulicDiameter", "Hydraulic diameter [m]",\
 12240, 0.0, 0.0,1.7976931348623157E+308,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.innerVolume", "Inner volume [m3]", 12241,\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.outerVolume", "Outer volume [m3]", 12242,\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.innerHeatTransferArea", "[m2]", 12243, \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.tubeIsCircular", "true, if tube's cross section is circular [:#(type=Boolean)]",\
 12244, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube1.simPort.vleFluidMass", "[kg]", 12245, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.simPort.vleFluidVolume", "[m3]", 12246, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.simPort.liquidMass", "[kg]", 12247, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("PF4U.tube1.simPort.liquidVolume", "[m3]", 12248, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("PF4U.tube1.simPort.gasMass", "[kg]", "PF4U.tube1.cellMass[1]", 1,\
 5, 17178, 1024)
DeclareAlias2("PF4U.tube1.simPort.gasVolume", "[m3]", "PF4U.tube1.tubeGeometry.innerVolume", 1,\
 5, 12241, 1024)
DeclareVariable("PF4U.tube1.simPort.dpdt", "", 12249, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.simPort.dpdtCounter", "", 12250, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 12251, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube1.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 12252, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube1.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 12253, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube1.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 12254, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.tube1.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.tube1.cellMass[1]", 1, 5, 17178, 1156)
DeclareAlias2("PF4U.tube1.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.tube1.tubeGeometry.innerVolume", 1, 5, 12241, 1156)
DeclareVariable("PF4U.tube1.simPort.dpdtPort.dpdt", "", 12255, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("PF4U.tube1.simPort.dpdtPort.counter", "", 12256, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.tube1.simPort.warningsPort.warnings", "Accumulated warnings",\
 12257, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube1.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12258, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube1.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12259,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube1.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12260, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12261,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12262, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12263, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12264, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.tube1.portA.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1, 1,\
 103, 4)
DeclareVariable("PF4U.tube1.portA.m_flow", "Mass flow rate [kg/s]", 17161, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.tube1.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.tube1.h[1]", 1, 1, 104, 4)
DeclareVariable("PF4U.tube1.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12265, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube1.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12266,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube1.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12267, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12268,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12269, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12270, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12271, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.tube1.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("PF4U.tube1.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.Channel2.m_flow", 1, 5, 17015, 132)
DeclareAlias2("PF4U.tube1.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.tube1.h[1]", 1, 1, 104, 4)
DeclareAlias2("PF4U.tube1.cellGeometry.length", "[m]", "PF4U.tube1.tubeGeometry.length", 1,\
 5, 12235, 1024)
DeclareAlias2("PF4U.tube1.cellGeometry.volume", "[m3]", "PF4U.tube1.tubeGeometry.innerVolume", 1,\
 5, 12241, 1024)
DeclareAlias2("PF4U.tube1.cellGeometry.heatTransferArea", "[m2]", \
"PF4U.tube1.tubeGeometry.innerHeatTransferArea", 1, 5, 12243, 1024)
DeclareParameter("PF4U.tube1.cellGeometry.finHeatTransferAreaRatio", \
"Fraction of fins on fin side heat transfer area", 1230, 0, 0.0,0.0,0.0,0,2608)
DeclareVariable("PF4U.tube1.cellGeometry.hydraulicCrossSectionalArea", "[m2]", 12272,\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.cellGeometry.nParallelHydraulicFlows", \
"Number of parallel flows [1]", 12273, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.dl[1]", "length portions of cells", 12274, 1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDropPosition", "Position of pressure drop in tube [:#(type=ThermalSystems.Internals.PressureDropPosition)]",\
 12275, 3, 1.0,3.0,0.0,0,517)
DeclareVariable("PF4U.tube1.nCells", "Discretization number of 'cells' [:#(type=Integer)]",\
 12276, 1, 0.0,0.0,0.0,0,517)
DeclareVariable("PF4U.tube1.enableHeatPorts", "true, if heat ports are enabled [:#(type=Boolean)]",\
 12277, true, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube1.generateEventsAtFlowReversal", "If true: Events will be generated at flow reversal [:#(type=Boolean)]",\
 12278, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube1.gas[1].gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12279, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube1.gas[1].gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12280,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube1.gas[1].gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12281, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gas[1].gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12282,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gas[1].gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12283, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gas[1].gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12284, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gas[1].gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12285, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gas[1].gasPointer.id", "[:#(type=Integer)]", 12286, 0,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.tube1.gas[1].stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 12287, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube1.gas[1].computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 12288, true, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube1.gas[1].d", "Density [kg/m3|g/cm3]", 17162, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.tube1.gas[1].p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 1024)
DeclareAlias2("PF4U.tube1.gas[1].h", "Specific enthalpy [J/kg]", \
"PF4U.tube1.h[1]", 1, 1, 104, 1024)
DeclareVariable("PF4U.tube1.gas[1].s", "Specific entropy [J/(kg.K)]", 17163, 0.0,\
 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube1.gas[1].T", "Temperature [K|degC]", "PF4U.tube1.T_gas_cell_[1]", 1,\
 5, 17223, 1024)
DeclareAlias2("PF4U.tube1.gas[1].M", "Average molar mass [kg/mol]", \
"PF4U.tube1.gas[1].M_i[1]", 1, 5, 12294, 1024)
DeclareVariable("PF4U.tube1.gas[1].cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17164, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17165, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].beta", "Isobaric thermal expansion coefficient [1/K]",\
 17166, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].kappa", "Isothermal compressibility [1/Pa]", 17167,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].w", "Speed of sound [m/s]", 17168, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17169, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17170, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].p_i[1]", "Partial pressure [Pa|bar]", 17171, \
0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17172, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].phi", "Relative humidity", 12289, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 12290, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].xi_s", "Saturation mass fraction of condensing component [1]",\
 12291, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 12292, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 12293, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17173, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].M_i[1]", "Molar mass of component i [kg/mol]",\
 12294, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].humRatio", "Content of condensing component aka humidity ratio [1]",\
 12295, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 12296, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 12297, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].transp.Pr", "Prandtl number [1]", 17174, 0.0,\
 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].transp.lambda", "Thermal conductivity [W/(m.K)]",\
 17175, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].transp.eta", "Dynamic viscosity [Pa.s]", 17176,\
 0.0, -1.0,1.7976931348623157E+308,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].transp.sigma", "Surface tension [N/m]", 17177,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].computeFlags", "[:#(type=Integer)]", 12298, 5,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.tube1.cellMass[1]", "Gas mass in one cell [kg]", 17178, \
0.0, 0.0,1.7976931348623157E+308,0.0,0,2560)
DeclareVariable("PF4U.tube1.drhodt[1]", "", 17179, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.p[1]", "[Pa|bar]", 17180, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2560)
DeclareAlias2("PF4U.tube1.der(p[1])", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18,\
 1024)
DeclareState("PF4U.tube1.h[1]", "Specific enthalpy [J/kg]", 104, 0.0, 0.0,0.0,\
100000.0,0,2592)
DeclareDerivative("PF4U.tube1.der(h[1])", "der(Specific enthalpy) [m2/s3]", 104,\
 0.0, 0.0,0.0,0.0,0,2624)
DeclareAlias2("PF4U.tube1.m_flow[1]", "[kg/s]", "PF4U.tube1.portA.m_flow", 1, 5,\
 17161, 1024)
DeclareAlias2("PF4U.tube1.m_flow[2]", "[kg/s]", "PF4U.Channel2.m_flow", -1, 5, 17015,\
 1024)
DeclareVariable("PF4U.tube1.H_flow[1]", "", 17181, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.H_flow[2]", "", 17182, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.mdotHydraulic", "[kg/s]", 17183, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube1.heatTransfer[1].mdotHydraulic", "Hydraulic mass flow rate [kg/s]",\
 "PF4U.tube1.mdotHydraulic", 1, 5, 17183, 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].QdotHydraulic", "Hydraulic heat flow rate [W]",\
 17184, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].wallTemperature", "Wall temperature [K|degC]",\
 17185, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.d", "Density [kg/m3|g/cm3]",\
 "PF4U.tube1.gas[1].d", 1, 5, 17162, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.h", "Specific enthalpy [J/kg]",\
 "PF4U.tube1.h[1]", 1, 1, 104, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.p", "Pressure [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.s", "Specific entropy [J/(kg.K)]",\
 "PF4U.tube1.gas[1].s", 1, 5, 17163, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.T", "Temperature [K|degC]",\
 "PF4U.tube1.T_gas_cell_[1]", 1, 5, 17223, 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.q", "Steam mass fraction (quality) [1]",\
 12299, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.tube1.gas[1].cp", 1, 5, 17164, 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.crit.d", "Critical density [kg/m3|g/cm3]",\
 12300, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.crit.h", "Critical specific enthalpy [J/kg]",\
 12301, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.crit.p", "Critical pressure [Pa|bar]",\
 12302, 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.crit.s", "Critical specific entropy [J/(kg.K)]",\
 12303, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.crit.T", "Critical temperature [K|degC]",\
 12304, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.d_l", \
"Density of liquid phase [kg/m3|g/cm3]", 12305, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.d_v", \
"Density of vapour phase [kg/m3|g/cm3]", 12306, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.h_l", \
"Specific enthalpy of liquid phase [J/kg]", 12307, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.h_v", \
"Specific enthalpy of vapour phase [J/kg]", 12308, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.p_l", \
"Pressure of liquid phase [Pa|bar]", 12309, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.p_v", \
"Pressure of vapour phase [Pa|bar]", 12310, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.s_l", \
"Specific entropy of liquid phase [J/(kg.K)]", 12311, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.s_v", \
"Specific entropy of vapour phase [J/(kg.K)]", 12312, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.T_l", \
"Temperature of liquid phase [K|degC]", 12313, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.T_v", \
"Temperature of vapour phase [K|degC]", 12314, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLETransp.Pr_l", \
"Prandtl number of liquid phase [1]", 12315, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLETransp.Pr_v", \
"Prandtl number of vapour phase [1]", 12316, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLETransp.lambda_l", \
"Thermal conductivity of liquid phase [W/(m.K)]", 12317, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLETransp.lambda_v", \
"Thermal conductivity of vapour phase [W/(m.K)]", 12318, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLETransp.eta_l", \
"Dynamic viscosity of liquid phase [Pa.s]", 12319, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLETransp.eta_v", \
"Dynamic viscosity of vapour phase [Pa.s]", 12320, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.transp.Pr", \
"Prandtl number [1]", "PF4U.tube1.gas[1].transp.Pr", 1, 5, 17174, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.transp.lambda", \
"Thermal conductivity [W/(m.K)]", "PF4U.tube1.gas[1].transp.lambda", 1, 5, 17175,\
 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.transp.eta", \
"Dynamic viscosity [Pa.s]", "PF4U.tube1.gas[1].transp.eta", 1, 5, 17176, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.transp.sigma", \
"Surface tension [N/m]", "PF4U.tube1.gas[1].transp.sigma", 1, 5, 17177, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].cellGeometry.length", "[m]", \
"PF4U.tube1.tubeGeometry.length", 1, 5, 12235, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].cellGeometry.volume", "[m3]", \
"PF4U.tube1.tubeGeometry.innerVolume", 1, 5, 12241, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].cellGeometry.heatTransferArea", "[m2]",\
 "PF4U.tube1.tubeGeometry.innerHeatTransferArea", 1, 5, 12243, 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].cellGeometry.finHeatTransferAreaRatio",\
 "Fraction of fins on fin side heat transfer area", 12321, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].cellGeometry.hydraulicCrossSectionalArea",\
 "[m2]", 12322, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].cellGeometry.nParallelHydraulicFlows",\
 "Number of parallel flows", 12323, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].alphaA", "Value for alphaA for one cell [W/K]",\
 17186, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.alphaA", "Value for alphaA for one cell [W/K]",\
 "PF4U.tube1.heatTransfer[1].alphaA", 1, 5, 17186, 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.computeTransportProperties",\
 "[:#(type=Boolean)]", 12324, true, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.useAlphaAState", \
"alphaA is a differential state [:#(type=Boolean)]", 12325, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.mdotHydraulic", \
"Hydraulic mass flow rate [kg/s]", "PF4U.tube1.mdotHydraulic", 1, 5, 17183, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.d", \
"Density [kg/m3|g/cm3]", "PF4U.tube1.gas[1].d", 1, 5, 17162, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.h", \
"Specific enthalpy [J/kg]", "PF4U.tube1.h[1]", 1, 1, 104, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.p", \
"Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.s", \
"Specific entropy [J/(kg.K)]", "PF4U.tube1.gas[1].s", 1, 5, 17163, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.T", \
"Temperature [K|degC]", "PF4U.tube1.T_gas_cell_[1]", 1, 5, 17223, 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.q", \
"Steam mass fraction (quality) [1]", 12326, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.cp", \
"Specific isobaric heat capacity cp [J/(kg.K)]", "PF4U.tube1.gas[1].cp", 1, 5, 17164,\
 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.crit.d",\
 "Critical density [kg/m3|g/cm3]", 12327, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.crit.h",\
 "Critical specific enthalpy [J/kg]", 12328, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.crit.p",\
 "Critical pressure [Pa|bar]", 12329, 0.0, 0.0,1.7976931348623157E+308,100000.0,\
0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.crit.s",\
 "Critical specific entropy [J/(kg.K)]", 12330, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.crit.T",\
 "Critical temperature [K|degC]", 12331, 0.0, 0.0,1.7976931348623157E+308,300.0,\
0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.d_l",\
 "Density of liquid phase [kg/m3|g/cm3]", 12332, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.d_v",\
 "Density of vapour phase [kg/m3|g/cm3]", 12333, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.h_l",\
 "Specific enthalpy of liquid phase [J/kg]", 12334, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.h_v",\
 "Specific enthalpy of vapour phase [J/kg]", 12335, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.p_l",\
 "Pressure of liquid phase [Pa|bar]", 12336, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.p_v",\
 "Pressure of vapour phase [Pa|bar]", 12337, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.s_l",\
 "Specific entropy of liquid phase [J/(kg.K)]", 12338, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.s_v",\
 "Specific entropy of vapour phase [J/(kg.K)]", 12339, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.T_l",\
 "Temperature of liquid phase [K|degC]", 12340, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.T_v",\
 "Temperature of vapour phase [K|degC]", 12341, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.Pr_l",\
 "Prandtl number of liquid phase [1]", 12342, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.Pr_v",\
 "Prandtl number of vapour phase [1]", 12343, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.lambda_l",\
 "Thermal conductivity of liquid phase [W/(m.K)]", 12344, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.lambda_v",\
 "Thermal conductivity of vapour phase [W/(m.K)]", 12345, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.eta_l",\
 "Dynamic viscosity of liquid phase [Pa.s]", 12346, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.eta_v",\
 "Dynamic viscosity of vapour phase [Pa.s]", 12347, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.transp.Pr",\
 "Prandtl number [1]", "PF4U.tube1.gas[1].transp.Pr", 1, 5, 17174, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.transp.lambda",\
 "Thermal conductivity [W/(m.K)]", "PF4U.tube1.gas[1].transp.lambda", 1, 5, 17175,\
 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.transp.eta",\
 "Dynamic viscosity [Pa.s]", "PF4U.tube1.gas[1].transp.eta", 1, 5, 17176, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.transp.sigma",\
 "Surface tension [N/m]", "PF4U.tube1.gas[1].transp.sigma", 1, 5, 17177, 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.alpha", \
"Coefficient of heat transfer [W/(m2.K)]", 17187, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.hydraulicDiameter",\
 "Hydraulic diameter [m]", 12348, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.hydraulicCrossSectionalArea",\
 "Hydraulic cross sectional area [m2]", 12349, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.Re", \
"Reynolds Number [1]", 17188, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.Nu", \
"Nusselt number [1]", 17189, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.averageVelocity", \
"Average velocity [m/s]", 17190, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.weightingFactor1", \
"", 17191, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.weightingFactor2", \
"", 17192, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.Nu1", "[1]", 17193,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.Nu_Gnielinski", \
"[1]", 17194, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.Nu_DittusBoelter", \
"[1]", 17195, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.zeta", "", 17196, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareParameter("PF4U.tube1.heatTransfer[1].heatTransfer.correctionFactor", \
"Linear correction factor for the overall alphaA calculated by this heat transfer model and its submodels. [1]",\
 1231, 1, 0.0,0.0,0.0,0,2608)
DeclareAlias2("PF4U.tube1.pressureDrop[1].mdotHydraulic", "Hydraulic mass flow rate [kg/s]",\
 "PF4U.tube1.mdotHydraulic", 1, 5, 17183, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.d", "Density [kg/m3|g/cm3]",\
 "PF4U.tube1.gas[1].d", 1, 5, 17162, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.h", "Specific enthalpy [J/kg]",\
 "PF4U.tube1.h[1]", 1, 1, 104, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.p", "Pressure [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.s", "Specific entropy [J/(kg.K)]",\
 "PF4U.tube1.gas[1].s", 1, 5, 17163, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.T", "Temperature [K|degC]",\
 "PF4U.tube1.T_gas_cell_[1]", 1, 5, 17223, 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.q", "Steam mass fraction (quality) [1]",\
 12350, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.tube1.gas[1].cp", 1, 5, 17164, 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.crit.d", "Critical density [kg/m3|g/cm3]",\
 12351, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.crit.h", "Critical specific enthalpy [J/kg]",\
 12352, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.crit.p", "Critical pressure [Pa|bar]",\
 12353, 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.crit.s", "Critical specific entropy [J/(kg.K)]",\
 12354, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.crit.T", "Critical temperature [K|degC]",\
 12355, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.d_l", \
"Density of liquid phase [kg/m3|g/cm3]", 12356, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.d_v", \
"Density of vapour phase [kg/m3|g/cm3]", 12357, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.h_l", \
"Specific enthalpy of liquid phase [J/kg]", 12358, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.h_v", \
"Specific enthalpy of vapour phase [J/kg]", 12359, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.p_l", \
"Pressure of liquid phase [Pa|bar]", 12360, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.p_v", \
"Pressure of vapour phase [Pa|bar]", 12361, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.s_l", \
"Specific entropy of liquid phase [J/(kg.K)]", 12362, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.s_v", \
"Specific entropy of vapour phase [J/(kg.K)]", 12363, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.T_l", \
"Temperature of liquid phase [K|degC]", 12364, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.T_v", \
"Temperature of vapour phase [K|degC]", 12365, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLETransp.Pr_l", \
"Prandtl number of liquid phase [1]", 12366, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLETransp.Pr_v", \
"Prandtl number of vapour phase [1]", 12367, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLETransp.lambda_l", \
"Thermal conductivity of liquid phase [W/(m.K)]", 12368, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLETransp.lambda_v", \
"Thermal conductivity of vapour phase [W/(m.K)]", 12369, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLETransp.eta_l", \
"Dynamic viscosity of liquid phase [Pa.s]", 12370, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLETransp.eta_v", \
"Dynamic viscosity of vapour phase [Pa.s]", 12371, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.transp.Pr", \
"Prandtl number [1]", "PF4U.tube1.gas[1].transp.Pr", 1, 5, 17174, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.transp.lambda", \
"Thermal conductivity [W/(m.K)]", "PF4U.tube1.gas[1].transp.lambda", 1, 5, 17175,\
 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.transp.eta", \
"Dynamic viscosity [Pa.s]", "PF4U.tube1.gas[1].transp.eta", 1, 5, 17176, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.transp.sigma", \
"Surface tension [N/m]", "PF4U.tube1.gas[1].transp.sigma", 1, 5, 17177, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].cellGeometry.length", "[m]", \
"PF4U.tube1.tubeGeometry.length", 1, 5, 12235, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].cellGeometry.volume", "[m3]", \
"PF4U.tube1.tubeGeometry.innerVolume", 1, 5, 12241, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].cellGeometry.heatTransferArea", "[m2]",\
 "PF4U.tube1.tubeGeometry.innerHeatTransferArea", 1, 5, 12243, 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].cellGeometry.finHeatTransferAreaRatio",\
 "Fraction of fins on fin side heat transfer area", 12372, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].cellGeometry.hydraulicCrossSectionalArea",\
 "[m2]", 12373, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].cellGeometry.nParallelHydraulicFlows",\
 "Number of parallel flows", 12374, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDrop", "Pressure drop for one cell [Pa|bar]",\
 17197, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.pressureDrop", \
"Pressure drop for one cell [Pa|bar]", "PF4U.tube1.pressureDrop[1].pressureDrop", 1,\
 5, 17197, 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.computeTransportProperties",\
 "[:#(type=Boolean)]", 12375, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.mdotHydraulic",\
 "Hydraulic mass flow rate [kg/s]", "PF4U.tube1.mdotHydraulic", 1, 5, 17183, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.d",\
 "Density [kg/m3|g/cm3]", "PF4U.tube1.gas[1].d", 1, 5, 17162, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.h",\
 "Specific enthalpy [J/kg]", "PF4U.tube1.h[1]", 1, 1, 104, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.p",\
 "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.s",\
 "Specific entropy [J/(kg.K)]", "PF4U.tube1.gas[1].s", 1, 5, 17163, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.T",\
 "Temperature [K|degC]", "PF4U.tube1.T_gas_cell_[1]", 1, 5, 17223, 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.q",\
 "Steam mass fraction (quality) [1]", 12376, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.cp",\
 "Specific isobaric heat capacity cp [J/(kg.K)]", "PF4U.tube1.gas[1].cp", 1, 5, 17164,\
 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.crit.d",\
 "Critical density [kg/m3|g/cm3]", 12377, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.crit.h",\
 "Critical specific enthalpy [J/kg]", 12378, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.crit.p",\
 "Critical pressure [Pa|bar]", 12379, 0.0, 0.0,1.7976931348623157E+308,100000.0,\
0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.crit.s",\
 "Critical specific entropy [J/(kg.K)]", 12380, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.crit.T",\
 "Critical temperature [K|degC]", 12381, 0.0, 0.0,1.7976931348623157E+308,300.0,\
0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.d_l",\
 "Density of liquid phase [kg/m3|g/cm3]", 12382, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.d_v",\
 "Density of vapour phase [kg/m3|g/cm3]", 12383, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.h_l",\
 "Specific enthalpy of liquid phase [J/kg]", 12384, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.h_v",\
 "Specific enthalpy of vapour phase [J/kg]", 12385, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.p_l",\
 "Pressure of liquid phase [Pa|bar]", 12386, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.p_v",\
 "Pressure of vapour phase [Pa|bar]", 12387, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.s_l",\
 "Specific entropy of liquid phase [J/(kg.K)]", 12388, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.s_v",\
 "Specific entropy of vapour phase [J/(kg.K)]", 12389, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.T_l",\
 "Temperature of liquid phase [K|degC]", 12390, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.T_v",\
 "Temperature of vapour phase [K|degC]", 12391, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.Pr_l",\
 "Prandtl number of liquid phase [1]", 12392, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.Pr_v",\
 "Prandtl number of vapour phase [1]", 12393, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.lambda_l",\
 "Thermal conductivity of liquid phase [W/(m.K)]", 12394, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.lambda_v",\
 "Thermal conductivity of vapour phase [W/(m.K)]", 12395, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.eta_l",\
 "Dynamic viscosity of liquid phase [Pa.s]", 12396, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.eta_v",\
 "Dynamic viscosity of vapour phase [Pa.s]", 12397, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.transp.Pr",\
 "Prandtl number [1]", "PF4U.tube1.gas[1].transp.Pr", 1, 5, 17174, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.transp.lambda",\
 "Thermal conductivity [W/(m.K)]", "PF4U.tube1.gas[1].transp.lambda", 1, 5, 17175,\
 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.transp.eta",\
 "Dynamic viscosity [Pa.s]", "PF4U.tube1.gas[1].transp.eta", 1, 5, 17176, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.transp.sigma",\
 "Surface tension [N/m]", "PF4U.tube1.gas[1].transp.sigma", 1, 5, 17177, 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.pressureDrop",\
 "Pressure drop [Pa|bar]", 17198, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.hydraulicDiameter",\
 "Hydraulic diameter [m]", 12398, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.hydraulicCrossSectionalArea",\
 "Cross-sectional area [m2]", 12399, 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.length", \
"Length [m]", "PF4U.tube1.tubeGeometry.length", 1, 5, 12235, 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.Re", \
"Reynold's number [1]", 17199, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.v", \
"Velocity [m/s]", 17200, 0.0, 0.0,0.0,0.0,0,2624)
DeclareParameter("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.Re_transitionBegin",\
 "At this Reynold's number the transition from laminar to turbulent begins [1]",\
 1232, 2250, 0.0,0.0,0.0,0,2608)
DeclareParameter("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.Re_transitionEnd",\
 "At this Reynold's number the transition from laminar to turbulent ends [1]", 1233,\
 2350, 0.0,0.0,0.0,0,2608)
DeclareParameter("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.vLimit", \
"Obsolete - Fluid velocity below which the pressure drop relation is regularized [m/s]",\
 1234, 0.001, 0.0,0.0,0.0,0,2608)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.lambdaTurbulent",\
 "Darcy-Weisbach friction factor for turbulent flow", 17201, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.pressureDropLaminar",\
 "Laminar pressure drop model [Pa|bar]", 17202, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.pressureDropTurbulent",\
 "Turbulent pressure drop model [Pa|bar]", 17203, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.weightingFactor",\
 "Factor for transition between laminar and turbulent zone [1]", 17204, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareParameter("PF4U.tube1.pressureDrop[1].pressureDropModel.correctionFactor",\
 "Linear correction factor for the pressureDrop calculated by this pressure drop model and its submodels. [1]",\
 1235, 1, 0.0,0.0,0.0,0,2608)
DeclareParameter("PF4U.tube1.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1236, 0.003, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.tube1.pInitial", "Initial value for gas pressure [Pa|bar]",\
 12400, 4000000, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube1.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 12401, true, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube1.TInitial", "Initial value for gas temperature [K|K]",\
 12402, 288.15, 0.0,1.7976931348623157E+308,300.0,0,513)
DeclareParameter("PF4U.tube1.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1237, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.tube1.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 12403, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.tube1.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1238, 1, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.tube1.massFlowRateHomotopy", "Nominal mass flow rate for linear valve equation [kg/s]",\
 1239, 0.01, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.tube1.pressureDropHomotopy", "Nominal pressure drop for linear valve equation [Pa|bar]",\
 1240, 10000.0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.tube1.hInitial", "[J/kg]", 12404, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.TInitialWall", "Initial value for wall temperature [K|K]",\
 12405, 288.15, 0.0,1.7976931348623157E+308,300.0,0,513)
DeclareVariable("PF4U.tube1.connectWallCells", "If true: wall cells should be connected W-E [:#(type=Boolean)]",\
 12406, false, 0.0,0.0,0.0,0,515)
DeclareAlias2("PF4U.tube1.wallCell[1].cellGeometry.length", "[m]", \
"PF4U.tube1.tubeGeometry.length", 1, 5, 12235, 1024)
DeclareVariable("PF4U.tube1.wallCell[1].cellGeometry.volume", "[m3]", 12407, 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.tube1.wallCell[1].portN.T", "Port temperature [K|degC]", \
"PF4U.Channel2.T_wall", 1, 5, 17012, 1028)
DeclareAlias2("PF4U.tube1.wallCell[1].portN.Q_flow", "Heat flow rate [W]", \
"PF4U.prescribedHeatFlow1.port.Q_flow", -1, 5, 17159, 1156)
DeclareAlias2("PF4U.tube1.wallCell[1].portS.T", "Port temperature [K|degC]", \
"PF4U.tube1.heatTransfer[1].wallTemperature", 1, 5, 17185, 1028)
DeclareVariable("PF4U.tube1.wallCell[1].portS.Q_flow", "Heat flow rate [W]", 17205,\
 0.0, 0.0,0.0,0.0,0,2824)
DeclareVariable("PF4U.tube1.wallCell[1].portW.T", "Port temperature [K|degC]", 17206,\
 0.0, 0.0,1.7976931348623157E+308,300.0,0,2568)
DeclareVariable("PF4U.tube1.wallCell[1].portW.Q_flow", "Heat flow rate [W]", 12408,\
 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube1.wallCell[1].portE.T", "Port temperature [K|degC]", 17207,\
 0.0, 0.0,1.7976931348623157E+308,300.0,0,2568)
DeclareVariable("PF4U.tube1.wallCell[1].portE.Q_flow", "Heat flow rate [W]", 12409,\
 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube1.wallCell[1].TInitialWall", "Initial wall temperature [K|degC]",\
 12410, 288.15, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].fixedTInitialWall", "if true, force usage of initial value TInitialWall [:#(type=Boolean)]",\
 12411, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube1.wallCell[1].initSteadyState", "[:#(type=Boolean)]", 12412,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube1.wallCell[1].additionalHeatCapacity", "[J/K]", 12413,\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].properties.d", "Density [kg/m3|g/cm3]", 12414,\
 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube1.wallCell[1].properties.T", "Temperature [K|degC]", \
"PF4U.tube1.wallCell[1].wallStateTemperature", 1, 1, 105, 1024)
DeclareVariable("PF4U.tube1.wallCell[1].properties.cp", "Heat capacity [J/(kg.K)]",\
 12415, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].properties.lambda", "Thermal conductivity [W/(m.K)]",\
 12416, 40.0, 0.0,0.0,0.0,0,2561)
DeclareState("PF4U.tube1.wallCell[1].wallStateTemperature", "[K|degC]", 105, 0.0,\
 0.0,1.7976931348623157E+308,300.0,0,2592)
DeclareDerivative("PF4U.tube1.wallCell[1].der(wallStateTemperature)", "[K/s]", 105,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.d", "Density [kg/m3|g/cm3]",\
 12417, 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube1.wallCell[1].wallMaterial.T", "Temperature [K|degC]", \
"PF4U.tube1.wallCell[1].wallStateTemperature", 1, 1, 105, 1024)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.cp", "Heat capacity [J/(kg.K)]",\
 12418, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.lambda", "Thermal conductivity [W/(m.K)]",\
 12419, 40.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.cp_nominal", \
"Specific heat capacity at standard reference point [J/(kg.K)]", 12420, 490.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.lambda_nominal", \
"Thermal conductivity at standard reference point [W/(m.K)]", 12421, 40.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.solid.cp_nominal", \
"Specific heat capacity at standard reference point [J/(kg.K)]", 12422, 490.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.solid.lambda_nominal", \
"Thermal conductivity at standard reference point [W/(m.K)]", 12423, 40.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.solid.d", "Density [kg/m3|g/cm3]",\
 12424, 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube1.wallCell[1].wallMaterial.solid.T", "Temperature [K|degC]",\
 "PF4U.tube1.wallCell[1].wallStateTemperature", 1, 1, 105, 1024)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.solid.cp", "Heat capacity [J/(kg.K)]",\
 12425, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.solid.lambda", \
"Thermal conductivity [W/(m.K)]", 12426, 40.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].heatTransfer.R_WE", "Thermal resistance (W-E) for one cell [K/W]",\
 12427, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].heatTransfer.R_NS", "Thermal resistance (N-S) for one cell [K/W]",\
 12428, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].heatTransfer.connectWallCells", \
"[:#(type=Boolean)]", 12429, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube1.wallCell[1].heatTransfer.R_NS_total", \
"Thermal resistance (N-S) for total HX [K/W]", 12430, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].heatTransfer.R_WE_total", \
"Thermal resistance (W-E) for total HX [K/W]", 12431, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].geometricMass", "Geometric mass [kg]", 12432,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].SProd_dot", "Produced entropy [W/K]", 17208,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube1.getInputsThermal[1].heatPort.T", "Port temperature [K|degC]",\
 "PF4U.tube1.heatTransfer[1].wallTemperature", 1, 5, 17185, 1028)
DeclareAlias2("PF4U.tube1.getInputsThermal[1].heatPort.Q_flow", "Heat flow rate [W]",\
 "PF4U.tube1.wallCell[1].portS.Q_flow", -1, 5, 17205, 1156)
DeclareVariable("PF4U.tube1.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12433, true, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.tube1.includeSummaryArrays", "Obsolete & unused parameter for array entries in summary [:#(type=Boolean)]",\
 1241, true, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube1.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12434, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube1.summary.p_gas_A", "Pressure at port A [Pa|bar]", \
"PF4U.junction2.p", 1, 1, 103, 0)
DeclareAlias2("PF4U.tube1.summary.p_gas_B", "Pressure at port B [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.tube1.summary.T_gas_A", "Temperature at port A [K|degC]", \
"PF4U.Channel2.T_gas_in", 1, 5, 17014, 0)
DeclareAlias2("PF4U.tube1.summary.T_gas_B", "Temperature at port B [K|degC]", \
"PF4U.Channel2.T_gas_out", 1, 5, 17013, 0)
DeclareVariable("PF4U.tube1.summary.T_degC_gas_A", "Temperature at port A [degC;]",\
 17209, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube1.summary.T_degC_gas_B", "Temperature at port B [degC;]",\
 17210, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube1.summary.h_gas_A", "Specific enthalpy at port A [J/kg]",\
 17211, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube1.summary.h_gas_B", "Specific enthalpy at port B [J/kg]",\
 17212, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube1.summary.d_gas_A", "Density at port A [kg/m3|g/cm3]",\
 17213, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.tube1.summary.d_gas_B", "Density at port B [kg/m3|g/cm3]",\
 17214, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareAlias2("PF4U.tube1.summary.m_flow_gas_A", "Mass flow rate at port A [kg/s]",\
 "PF4U.tube1.portA.m_flow", 1, 5, 17161, 0)
DeclareAlias2("PF4U.tube1.summary.m_flow_gas_B", "Mass flow rate at port B [kg/s]",\
 "PF4U.Channel2.m_flow", 1, 5, 17015, 0)
DeclareVariable("PF4U.tube1.summary.w_gas_A", "Flow velocity at port A [m/s]", 17215,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube1.summary.w_gas_B", "Flow velocity at port B [m/s]", 17216,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube1.summary.dp_gas", "Total pressure drop [Pa|bar]", 17217,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube1.summary.Q_flow_gas", "Total heat flow rate [W]", \
"PF4U.tube1.wallCell[1].portS.Q_flow", -1, 5, 17205, 0)
DeclareVariable("PF4U.tube1.summary.mass_gas", "Total fluid mass [kg]", 17218, \
0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareAlias2("PF4U.tube1.summary.volume_gas", "Total fluid volume [m3]", \
"PF4U.tube1.tubeGeometry.innerVolume", 1, 5, 12241, 0)
DeclareVariable("PF4U.tube1.summary.alpha_average_gas", "Average coefficient of heat transfer [W/(m2.K)]",\
 17219, 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube1.summary.mass_component", "Total component mass [kg]", \
"PF4U.tube1.wallCell[1].geometricMass", 1, 5, 12432, 0)
DeclareVariable("PF4U.tube1.summary.arrays.n", "[:#(type=Integer)]", 12435, 1, \
0.0,0.0,0.0,0,517)
DeclareAlias2("PF4U.tube1.summary.arrays.T_gas_cell[1]", "[K|degC]", \
"PF4U.tube1.T_gas_cell_[1]", 1, 5, 17223, 0)
DeclareVariable("PF4U.tube1.summary.arrays.T_degC_gas_cell[1]", "[degC;]", 17220,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube1.summary.arrays.T_wall_cell[1]", "[K|degC]", \
"PF4U.tube1.wallCell[1].wallStateTemperature", 1, 1, 105, 0)
DeclareVariable("PF4U.tube1.summary.arrays.T_degC_wall_cell[1]", "[degC;]", 17221,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube1.summary.arrays.p_gas_cell[1]", "[Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.tube1.summary.arrays.h_gas_cell[1]", "[J/kg]", \
"PF4U.tube1.h[1]", 1, 1, 104, 0)
DeclareAlias2("PF4U.tube1.summary.arrays.d_gas_cell[1]", "[kg/m3|g/cm3]", \
"PF4U.tube1.gas[1].d", 1, 5, 17162, 0)
DeclareVariable("PF4U.tube1.summary.arrays.alpha_gas_cell[1]", "Heat transfer coefficient [W/(m2.K)]",\
 17222, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube1.T_gas_cell_[1]", "[K|degC]", 17223, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.tube1.T_wall_cell_[1]", "[K|degC]", "PF4U.tube1.wallCell[1].wallStateTemperature", 1,\
 1, 105, 1024)
DeclareVariable("PF4U.tube1.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12436, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube1.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12437,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12438, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12439,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12440, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12441, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12442, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasA.gasPointer.id", "[:#(type=Integer)]", 12443, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.tube1.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1242, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube1.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12444, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube1.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12445,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12446, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12447,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12448, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12449, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12450, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasB.gasPointer.id", "[:#(type=Integer)]", 12451, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.tube1.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1243, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube1.fixedTInitialWall", "if true, force usage of initial value TInitialWall [:#(type=Boolean)]",\
 12452, false, 0.0,0.0,0.0,0,515)
DeclareAlias2("PF4U.tube1.heatPort[1].T", "Port temperature [K|degC]", \
"PF4U.Channel2.T_wall", 1, 5, 17012, 4)
DeclareAlias2("PF4U.tube1.heatPort[1].Q_flow", "Heat flow rate [W]", \
"PF4U.prescribedHeatFlow1.port.Q_flow", -1, 5, 17159, 132)
DeclareParameter("PF4U.prescribedHeatFlow2.T_ref", "Reference temperature [K|degC]",\
 1244, 293.15, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.prescribedHeatFlow2.alpha", "Temperature coefficient of heat flow rate [1/K]",\
 1245, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.prescribedHeatFlow2.Q_flow", "[W]", 17224, 0.0, 0.0,0.0,\
0.0,0,512)
DeclareAlias2("PF4U.prescribedHeatFlow2.port.T", "Port temperature [K|degC]", \
"PF4U.Channel3.T_wall", 1, 5, 17016, 4)
DeclareVariable("PF4U.prescribedHeatFlow2.port.Q_flow", "Heat flow rate (positive if flowing from outside into the component) [W]",\
 17225, 0, 0.0,0.0,0.0,0,776)
DeclareParameter("PF4U.stepSource2.transitionTime", "Duration of transition [s]",\
 1246, 0.5, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.stepSource2.initialValue", "Value before first step", 1247,\
 0.0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.stepSource2.stepTimes[1]", "Beginning of transitions [s]",\
 12453, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource2.stepTimes[2]", "Beginning of transitions [s]",\
 12454, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource2.stepValues[1]", "Values of steps", 12455, 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource2.stepValues[2]", "Values of steps", 12456, 0.0,\
 0.0,0.0,0.0,0,513)
DeclareAlias2("PF4U.stepSource2.y", "[W]", "PF4U.prescribedHeatFlow2.Q_flow", 1,\
 5, 17224, 0)
DeclareVariable("PF4U.stepSource2.stepCount", "[:#(type=Integer)]", 12457, 2, \
0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.stepSource2.const_finalValue.k", "Constant output value [W]",\
 12458, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.const_finalValue.y", "Connector of Real output signal [W]",\
 12459, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[1].switchTime", "[s]", 12460, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[1].transitionTime", "[s]", 12461, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[1].preSwitchValue", \
"Value to use before switching to input [W]", 12462, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[1].u", "[W]", 12463, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[1].y", "[W]", 17226, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("PF4U.stepSource2.timeSwitch[1].switchEndTime", "[s]", 12464, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[1].switchMidTime", "[s]", 12465, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[2].switchTime", "[s]", 12466, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[2].transitionTime", "[s]", 12467, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[2].preSwitchValue", \
"Value to use before switching to input [W]", 12468, 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.stepSource2.timeSwitch[2].u", "[W]", "PF4U.stepSource2.timeSwitch[1].y", 1,\
 5, 17226, 1024)
DeclareAlias2("PF4U.stepSource2.timeSwitch[2].y", "[W]", "PF4U.prescribedHeatFlow2.Q_flow", 1,\
 5, 17224, 1024)
DeclareVariable("PF4U.stepSource2.timeSwitch[2].switchEndTime", "[s]", 12469, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[2].switchMidTime", "[s]", 12470, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12471, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube3.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 12472, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12473, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12474,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 12475, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12476, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12477, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.tubeGeometry.innerDiameter", "Inner diameter of circular tube [m]",\
 12478, 0.0, 0.0,1.7976931348623157E+308,0.0,0,513)
DeclareParameter("PF4U.tube3.tubeGeometry.wallThickness", "Wall thickness [m]", 1248,\
 0.0005, 0.0,1.7976931348623157E+308,0.0,0,560)
DeclareVariable("PF4U.tube3.tubeGeometry.length", "Length [m]", 12479, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,513)
DeclareParameter("PF4U.tube3.tubeGeometry.nParallelTubes", "Number of parallel Tubes [:#(type=Integer)]",\
 1249, 1, 1.0,1.7976931348623157E+308,0.0,0,564)
DeclareParameter("PF4U.tube3.tubeGeometry.crossSectionType", "Tube Cross Section Type [:#(type=ThermalSystems.Internals.CrossSectionType)]",\
 1250, 1, 1.0,2.0,0.0,0,564)
DeclareParameter("PF4U.tube3.tubeGeometry.innerCrossSectionalAreaNonCircular", \
"Inner cross sectional area of one non-circular tube [m2]", 1251, 0, 0.0,0.0,0.0,\
0,560)
DeclareParameter("PF4U.tube3.tubeGeometry.outerCrossSectionalAreaNonCircular", \
"Outer cross sectional area of one non-circular tube [m2]", 1252, 0, 0.0,0.0,0.0,\
0,560)
DeclareParameter("PF4U.tube3.tubeGeometry.innerPerimeterNonCircular", \
"Perimeter of one non-circular tube [m]", 1253, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.tube3.tubeGeometry.outerDiameter", "[m]", 12480, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.innerCrossSectionalArea", \
"Inner cross-sectional area [m2]", 12481, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.outerCrossSectionalArea", \
"Outer cross-sectional area [m2]", 12482, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.hydraulicCrossSectionalArea", \
"Hydraulic cross sectional area [m2]", 12483, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.hydraulicDiameter", "Hydraulic diameter [m]",\
 12484, 0.0, 0.0,1.7976931348623157E+308,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.innerVolume", "Inner volume [m3]", 12485,\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.outerVolume", "Outer volume [m3]", 12486,\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.innerHeatTransferArea", "[m2]", 12487, \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.tubeIsCircular", "true, if tube's cross section is circular [:#(type=Boolean)]",\
 12488, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube3.simPort.vleFluidMass", "[kg]", 12489, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.simPort.vleFluidVolume", "[m3]", 12490, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.simPort.liquidMass", "[kg]", 12491, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("PF4U.tube3.simPort.liquidVolume", "[m3]", 12492, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("PF4U.tube3.simPort.gasMass", "[kg]", "PF4U.tube3.cellMass[1]", 1,\
 5, 17244, 1024)
DeclareAlias2("PF4U.tube3.simPort.gasVolume", "[m3]", "PF4U.tube3.tubeGeometry.innerVolume", 1,\
 5, 12485, 1024)
DeclareVariable("PF4U.tube3.simPort.dpdt", "", 12493, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.simPort.dpdtCounter", "", 12494, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 12495, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube3.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 12496, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube3.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 12497, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube3.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 12498, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.tube3.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.tube3.cellMass[1]", 1, 5, 17244, 1156)
DeclareAlias2("PF4U.tube3.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.tube3.tubeGeometry.innerVolume", 1, 5, 12485, 1156)
DeclareVariable("PF4U.tube3.simPort.dpdtPort.dpdt", "", 12499, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("PF4U.tube3.simPort.dpdtPort.counter", "", 12500, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.tube3.simPort.warningsPort.warnings", "Accumulated warnings",\
 12501, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube3.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12502, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube3.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12503,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube3.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12504, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12505,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12506, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12507, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12508, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.tube3.portA.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1, 1,\
 103, 4)
DeclareVariable("PF4U.tube3.portA.m_flow", "Mass flow rate [kg/s]", 17227, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.tube3.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.tube3.h[1]", 1, 1, 106, 4)
DeclareVariable("PF4U.tube3.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12509, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube3.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12510,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube3.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12511, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12512,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12513, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12514, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12515, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.tube3.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("PF4U.tube3.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.Channel3.m_flow", 1, 5, 17019, 132)
DeclareAlias2("PF4U.tube3.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.tube3.h[1]", 1, 1, 106, 4)
DeclareAlias2("PF4U.tube3.cellGeometry.length", "[m]", "PF4U.tube3.tubeGeometry.length", 1,\
 5, 12479, 1024)
DeclareAlias2("PF4U.tube3.cellGeometry.volume", "[m3]", "PF4U.tube3.tubeGeometry.innerVolume", 1,\
 5, 12485, 1024)
DeclareAlias2("PF4U.tube3.cellGeometry.heatTransferArea", "[m2]", \
"PF4U.tube3.tubeGeometry.innerHeatTransferArea", 1, 5, 12487, 1024)
DeclareParameter("PF4U.tube3.cellGeometry.finHeatTransferAreaRatio", \
"Fraction of fins on fin side heat transfer area", 1254, 0, 0.0,0.0,0.0,0,2608)
DeclareVariable("PF4U.tube3.cellGeometry.hydraulicCrossSectionalArea", "[m2]", 12516,\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.cellGeometry.nParallelHydraulicFlows", \
"Number of parallel flows [1]", 12517, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.dl[1]", "length portions of cells", 12518, 1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDropPosition", "Position of pressure drop in tube [:#(type=ThermalSystems.Internals.PressureDropPosition)]",\
 12519, 3, 1.0,3.0,0.0,0,517)
DeclareVariable("PF4U.tube3.nCells", "Discretization number of 'cells' [:#(type=Integer)]",\
 12520, 1, 0.0,0.0,0.0,0,517)
DeclareVariable("PF4U.tube3.enableHeatPorts", "true, if heat ports are enabled [:#(type=Boolean)]",\
 12521, true, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube3.generateEventsAtFlowReversal", "If true: Events will be generated at flow reversal [:#(type=Boolean)]",\
 12522, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube3.gas[1].gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12523, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube3.gas[1].gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12524,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube3.gas[1].gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12525, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gas[1].gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12526,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gas[1].gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12527, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gas[1].gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12528, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gas[1].gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12529, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gas[1].gasPointer.id", "[:#(type=Integer)]", 12530, 0,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.tube3.gas[1].stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 12531, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube3.gas[1].computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 12532, true, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube3.gas[1].d", "Density [kg/m3|g/cm3]", 17228, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.tube3.gas[1].p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 1024)
DeclareAlias2("PF4U.tube3.gas[1].h", "Specific enthalpy [J/kg]", \
"PF4U.tube3.h[1]", 1, 1, 106, 1024)
DeclareVariable("PF4U.tube3.gas[1].s", "Specific entropy [J/(kg.K)]", 17229, 0.0,\
 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube3.gas[1].T", "Temperature [K|degC]", "PF4U.tube3.T_gas_cell_[1]", 1,\
 5, 17289, 1024)
DeclareAlias2("PF4U.tube3.gas[1].M", "Average molar mass [kg/mol]", \
"PF4U.tube3.gas[1].M_i[1]", 1, 5, 12538, 1024)
DeclareVariable("PF4U.tube3.gas[1].cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17230, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17231, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].beta", "Isobaric thermal expansion coefficient [1/K]",\
 17232, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].kappa", "Isothermal compressibility [1/Pa]", 17233,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].w", "Speed of sound [m/s]", 17234, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17235, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17236, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].p_i[1]", "Partial pressure [Pa|bar]", 17237, \
0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17238, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].phi", "Relative humidity", 12533, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 12534, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].xi_s", "Saturation mass fraction of condensing component [1]",\
 12535, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 12536, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 12537, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17239, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].M_i[1]", "Molar mass of component i [kg/mol]",\
 12538, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].humRatio", "Content of condensing component aka humidity ratio [1]",\
 12539, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 12540, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 12541, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].transp.Pr", "Prandtl number [1]", 17240, 0.0,\
 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].transp.lambda", "Thermal conductivity [W/(m.K)]",\
 17241, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].transp.eta", "Dynamic viscosity [Pa.s]", 17242,\
 0.0, -1.0,1.7976931348623157E+308,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].transp.sigma", "Surface tension [N/m]", 17243,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].computeFlags", "[:#(type=Integer)]", 12542, 5,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.tube3.cellMass[1]", "Gas mass in one cell [kg]", 17244, \
0.0, 0.0,1.7976931348623157E+308,0.0,0,2560)
DeclareVariable("PF4U.tube3.drhodt[1]", "", 17245, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.p[1]", "[Pa|bar]", 17246, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2560)
DeclareAlias2("PF4U.tube3.der(p[1])", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18,\
 1024)
DeclareState("PF4U.tube3.h[1]", "Specific enthalpy [J/kg]", 106, 0.0, 0.0,0.0,\
100000.0,0,2592)
DeclareDerivative("PF4U.tube3.der(h[1])", "der(Specific enthalpy) [m2/s3]", 106,\
 0.0, 0.0,0.0,0.0,0,2624)
DeclareAlias2("PF4U.tube3.m_flow[1]", "[kg/s]", "PF4U.tube3.portA.m_flow", 1, 5,\
 17227, 1024)
DeclareAlias2("PF4U.tube3.m_flow[2]", "[kg/s]", "PF4U.Channel3.m_flow", -1, 5, 17019,\
 1024)
DeclareVariable("PF4U.tube3.H_flow[1]", "", 17247, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.H_flow[2]", "", 17248, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.mdotHydraulic", "[kg/s]", 17249, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube3.heatTransfer[1].mdotHydraulic", "Hydraulic mass flow rate [kg/s]",\
 "PF4U.tube3.mdotHydraulic", 1, 5, 17249, 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].QdotHydraulic", "Hydraulic heat flow rate [W]",\
 17250, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].wallTemperature", "Wall temperature [K|degC]",\
 17251, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.d", "Density [kg/m3|g/cm3]",\
 "PF4U.tube3.gas[1].d", 1, 5, 17228, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.h", "Specific enthalpy [J/kg]",\
 "PF4U.tube3.h[1]", 1, 1, 106, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.p", "Pressure [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.s", "Specific entropy [J/(kg.K)]",\
 "PF4U.tube3.gas[1].s", 1, 5, 17229, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.T", "Temperature [K|degC]",\
 "PF4U.tube3.T_gas_cell_[1]", 1, 5, 17289, 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.q", "Steam mass fraction (quality) [1]",\
 12543, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.tube3.gas[1].cp", 1, 5, 17230, 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.crit.d", "Critical density [kg/m3|g/cm3]",\
 12544, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.crit.h", "Critical specific enthalpy [J/kg]",\
 12545, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.crit.p", "Critical pressure [Pa|bar]",\
 12546, 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.crit.s", "Critical specific entropy [J/(kg.K)]",\
 12547, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.crit.T", "Critical temperature [K|degC]",\
 12548, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.d_l", \
"Density of liquid phase [kg/m3|g/cm3]", 12549, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.d_v", \
"Density of vapour phase [kg/m3|g/cm3]", 12550, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.h_l", \
"Specific enthalpy of liquid phase [J/kg]", 12551, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.h_v", \
"Specific enthalpy of vapour phase [J/kg]", 12552, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.p_l", \
"Pressure of liquid phase [Pa|bar]", 12553, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.p_v", \
"Pressure of vapour phase [Pa|bar]", 12554, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.s_l", \
"Specific entropy of liquid phase [J/(kg.K)]", 12555, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.s_v", \
"Specific entropy of vapour phase [J/(kg.K)]", 12556, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.T_l", \
"Temperature of liquid phase [K|degC]", 12557, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.T_v", \
"Temperature of vapour phase [K|degC]", 12558, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLETransp.Pr_l", \
"Prandtl number of liquid phase [1]", 12559, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLETransp.Pr_v", \
"Prandtl number of vapour phase [1]", 12560, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLETransp.lambda_l", \
"Thermal conductivity of liquid phase [W/(m.K)]", 12561, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLETransp.lambda_v", \
"Thermal conductivity of vapour phase [W/(m.K)]", 12562, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLETransp.eta_l", \
"Dynamic viscosity of liquid phase [Pa.s]", 12563, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLETransp.eta_v", \
"Dynamic viscosity of vapour phase [Pa.s]", 12564, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.transp.Pr", \
"Prandtl number [1]", "PF4U.tube3.gas[1].transp.Pr", 1, 5, 17240, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.transp.lambda", \
"Thermal conductivity [W/(m.K)]", "PF4U.tube3.gas[1].transp.lambda", 1, 5, 17241,\
 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.transp.eta", \
"Dynamic viscosity [Pa.s]", "PF4U.tube3.gas[1].transp.eta", 1, 5, 17242, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.transp.sigma", \
"Surface tension [N/m]", "PF4U.tube3.gas[1].transp.sigma", 1, 5, 17243, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].cellGeometry.length", "[m]", \
"PF4U.tube3.tubeGeometry.length", 1, 5, 12479, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].cellGeometry.volume", "[m3]", \
"PF4U.tube3.tubeGeometry.innerVolume", 1, 5, 12485, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].cellGeometry.heatTransferArea", "[m2]",\
 "PF4U.tube3.tubeGeometry.innerHeatTransferArea", 1, 5, 12487, 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].cellGeometry.finHeatTransferAreaRatio",\
 "Fraction of fins on fin side heat transfer area", 12565, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].cellGeometry.hydraulicCrossSectionalArea",\
 "[m2]", 12566, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].cellGeometry.nParallelHydraulicFlows",\
 "Number of parallel flows", 12567, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].alphaA", "Value for alphaA for one cell [W/K]",\
 17252, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.alphaA", "Value for alphaA for one cell [W/K]",\
 "PF4U.tube3.heatTransfer[1].alphaA", 1, 5, 17252, 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.computeTransportProperties",\
 "[:#(type=Boolean)]", 12568, true, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.useAlphaAState", \
"alphaA is a differential state [:#(type=Boolean)]", 12569, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.mdotHydraulic", \
"Hydraulic mass flow rate [kg/s]", "PF4U.tube3.mdotHydraulic", 1, 5, 17249, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.d", \
"Density [kg/m3|g/cm3]", "PF4U.tube3.gas[1].d", 1, 5, 17228, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.h", \
"Specific enthalpy [J/kg]", "PF4U.tube3.h[1]", 1, 1, 106, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.p", \
"Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.s", \
"Specific entropy [J/(kg.K)]", "PF4U.tube3.gas[1].s", 1, 5, 17229, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.T", \
"Temperature [K|degC]", "PF4U.tube3.T_gas_cell_[1]", 1, 5, 17289, 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.q", \
"Steam mass fraction (quality) [1]", 12570, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.cp", \
"Specific isobaric heat capacity cp [J/(kg.K)]", "PF4U.tube3.gas[1].cp", 1, 5, 17230,\
 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.crit.d",\
 "Critical density [kg/m3|g/cm3]", 12571, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.crit.h",\
 "Critical specific enthalpy [J/kg]", 12572, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.crit.p",\
 "Critical pressure [Pa|bar]", 12573, 0.0, 0.0,1.7976931348623157E+308,100000.0,\
0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.crit.s",\
 "Critical specific entropy [J/(kg.K)]", 12574, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.crit.T",\
 "Critical temperature [K|degC]", 12575, 0.0, 0.0,1.7976931348623157E+308,300.0,\
0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.d_l",\
 "Density of liquid phase [kg/m3|g/cm3]", 12576, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.d_v",\
 "Density of vapour phase [kg/m3|g/cm3]", 12577, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.h_l",\
 "Specific enthalpy of liquid phase [J/kg]", 12578, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.h_v",\
 "Specific enthalpy of vapour phase [J/kg]", 12579, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.p_l",\
 "Pressure of liquid phase [Pa|bar]", 12580, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.p_v",\
 "Pressure of vapour phase [Pa|bar]", 12581, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.s_l",\
 "Specific entropy of liquid phase [J/(kg.K)]", 12582, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.s_v",\
 "Specific entropy of vapour phase [J/(kg.K)]", 12583, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.T_l",\
 "Temperature of liquid phase [K|degC]", 12584, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.T_v",\
 "Temperature of vapour phase [K|degC]", 12585, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.Pr_l",\
 "Prandtl number of liquid phase [1]", 12586, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.Pr_v",\
 "Prandtl number of vapour phase [1]", 12587, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.lambda_l",\
 "Thermal conductivity of liquid phase [W/(m.K)]", 12588, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.lambda_v",\
 "Thermal conductivity of vapour phase [W/(m.K)]", 12589, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.eta_l",\
 "Dynamic viscosity of liquid phase [Pa.s]", 12590, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.eta_v",\
 "Dynamic viscosity of vapour phase [Pa.s]", 12591, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.transp.Pr",\
 "Prandtl number [1]", "PF4U.tube3.gas[1].transp.Pr", 1, 5, 17240, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.transp.lambda",\
 "Thermal conductivity [W/(m.K)]", "PF4U.tube3.gas[1].transp.lambda", 1, 5, 17241,\
 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.transp.eta",\
 "Dynamic viscosity [Pa.s]", "PF4U.tube3.gas[1].transp.eta", 1, 5, 17242, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.transp.sigma",\
 "Surface tension [N/m]", "PF4U.tube3.gas[1].transp.sigma", 1, 5, 17243, 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.alpha", \
"Coefficient of heat transfer [W/(m2.K)]", 17253, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.hydraulicDiameter",\
 "Hydraulic diameter [m]", 12592, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.hydraulicCrossSectionalArea",\
 "Hydraulic cross sectional area [m2]", 12593, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.Re", \
"Reynolds Number [1]", 17254, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.Nu", \
"Nusselt number [1]", 17255, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.averageVelocity", \
"Average velocity [m/s]", 17256, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.weightingFactor1", \
"", 17257, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.weightingFactor2", \
"", 17258, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.Nu1", "[1]", 17259,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.Nu_Gnielinski", \
"[1]", 17260, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.Nu_DittusBoelter", \
"[1]", 17261, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.zeta", "", 17262, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareParameter("PF4U.tube3.heatTransfer[1].heatTransfer.correctionFactor", \
"Linear correction factor for the overall alphaA calculated by this heat transfer model and its submodels. [1]",\
 1255, 1, 0.0,0.0,0.0,0,2608)
DeclareAlias2("PF4U.tube3.pressureDrop[1].mdotHydraulic", "Hydraulic mass flow rate [kg/s]",\
 "PF4U.tube3.mdotHydraulic", 1, 5, 17249, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.d", "Density [kg/m3|g/cm3]",\
 "PF4U.tube3.gas[1].d", 1, 5, 17228, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.h", "Specific enthalpy [J/kg]",\
 "PF4U.tube3.h[1]", 1, 1, 106, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.p", "Pressure [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.s", "Specific entropy [J/(kg.K)]",\
 "PF4U.tube3.gas[1].s", 1, 5, 17229, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.T", "Temperature [K|degC]",\
 "PF4U.tube3.T_gas_cell_[1]", 1, 5, 17289, 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.q", "Steam mass fraction (quality) [1]",\
 12594, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.tube3.gas[1].cp", 1, 5, 17230, 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.crit.d", "Critical density [kg/m3|g/cm3]",\
 12595, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.crit.h", "Critical specific enthalpy [J/kg]",\
 12596, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.crit.p", "Critical pressure [Pa|bar]",\
 12597, 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.crit.s", "Critical specific entropy [J/(kg.K)]",\
 12598, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.crit.T", "Critical temperature [K|degC]",\
 12599, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.d_l", \
"Density of liquid phase [kg/m3|g/cm3]", 12600, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.d_v", \
"Density of vapour phase [kg/m3|g/cm3]", 12601, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.h_l", \
"Specific enthalpy of liquid phase [J/kg]", 12602, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.h_v", \
"Specific enthalpy of vapour phase [J/kg]", 12603, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.p_l", \
"Pressure of liquid phase [Pa|bar]", 12604, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.p_v", \
"Pressure of vapour phase [Pa|bar]", 12605, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.s_l", \
"Specific entropy of liquid phase [J/(kg.K)]", 12606, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.s_v", \
"Specific entropy of vapour phase [J/(kg.K)]", 12607, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.T_l", \
"Temperature of liquid phase [K|degC]", 12608, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.T_v", \
"Temperature of vapour phase [K|degC]", 12609, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLETransp.Pr_l", \
"Prandtl number of liquid phase [1]", 12610, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLETransp.Pr_v", \
"Prandtl number of vapour phase [1]", 12611, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLETransp.lambda_l", \
"Thermal conductivity of liquid phase [W/(m.K)]", 12612, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLETransp.lambda_v", \
"Thermal conductivity of vapour phase [W/(m.K)]", 12613, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLETransp.eta_l", \
"Dynamic viscosity of liquid phase [Pa.s]", 12614, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLETransp.eta_v", \
"Dynamic viscosity of vapour phase [Pa.s]", 12615, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.transp.Pr", \
"Prandtl number [1]", "PF4U.tube3.gas[1].transp.Pr", 1, 5, 17240, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.transp.lambda", \
"Thermal conductivity [W/(m.K)]", "PF4U.tube3.gas[1].transp.lambda", 1, 5, 17241,\
 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.transp.eta", \
"Dynamic viscosity [Pa.s]", "PF4U.tube3.gas[1].transp.eta", 1, 5, 17242, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.transp.sigma", \
"Surface tension [N/m]", "PF4U.tube3.gas[1].transp.sigma", 1, 5, 17243, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].cellGeometry.length", "[m]", \
"PF4U.tube3.tubeGeometry.length", 1, 5, 12479, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].cellGeometry.volume", "[m3]", \
"PF4U.tube3.tubeGeometry.innerVolume", 1, 5, 12485, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].cellGeometry.heatTransferArea", "[m2]",\
 "PF4U.tube3.tubeGeometry.innerHeatTransferArea", 1, 5, 12487, 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].cellGeometry.finHeatTransferAreaRatio",\
 "Fraction of fins on fin side heat transfer area", 12616, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].cellGeometry.hydraulicCrossSectionalArea",\
 "[m2]", 12617, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].cellGeometry.nParallelHydraulicFlows",\
 "Number of parallel flows", 12618, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDrop", "Pressure drop for one cell [Pa|bar]",\
 17263, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.pressureDrop", \
"Pressure drop for one cell [Pa|bar]", "PF4U.tube3.pressureDrop[1].pressureDrop", 1,\
 5, 17263, 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.computeTransportProperties",\
 "[:#(type=Boolean)]", 12619, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.mdotHydraulic",\
 "Hydraulic mass flow rate [kg/s]", "PF4U.tube3.mdotHydraulic", 1, 5, 17249, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.d",\
 "Density [kg/m3|g/cm3]", "PF4U.tube3.gas[1].d", 1, 5, 17228, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.h",\
 "Specific enthalpy [J/kg]", "PF4U.tube3.h[1]", 1, 1, 106, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.p",\
 "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.s",\
 "Specific entropy [J/(kg.K)]", "PF4U.tube3.gas[1].s", 1, 5, 17229, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.T",\
 "Temperature [K|degC]", "PF4U.tube3.T_gas_cell_[1]", 1, 5, 17289, 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.q",\
 "Steam mass fraction (quality) [1]", 12620, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.cp",\
 "Specific isobaric heat capacity cp [J/(kg.K)]", "PF4U.tube3.gas[1].cp", 1, 5, 17230,\
 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.crit.d",\
 "Critical density [kg/m3|g/cm3]", 12621, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.crit.h",\
 "Critical specific enthalpy [J/kg]", 12622, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.crit.p",\
 "Critical pressure [Pa|bar]", 12623, 0.0, 0.0,1.7976931348623157E+308,100000.0,\
0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.crit.s",\
 "Critical specific entropy [J/(kg.K)]", 12624, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.crit.T",\
 "Critical temperature [K|degC]", 12625, 0.0, 0.0,1.7976931348623157E+308,300.0,\
0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.d_l",\
 "Density of liquid phase [kg/m3|g/cm3]", 12626, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.d_v",\
 "Density of vapour phase [kg/m3|g/cm3]", 12627, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.h_l",\
 "Specific enthalpy of liquid phase [J/kg]", 12628, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.h_v",\
 "Specific enthalpy of vapour phase [J/kg]", 12629, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.p_l",\
 "Pressure of liquid phase [Pa|bar]", 12630, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.p_v",\
 "Pressure of vapour phase [Pa|bar]", 12631, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.s_l",\
 "Specific entropy of liquid phase [J/(kg.K)]", 12632, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.s_v",\
 "Specific entropy of vapour phase [J/(kg.K)]", 12633, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.T_l",\
 "Temperature of liquid phase [K|degC]", 12634, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.T_v",\
 "Temperature of vapour phase [K|degC]", 12635, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.Pr_l",\
 "Prandtl number of liquid phase [1]", 12636, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.Pr_v",\
 "Prandtl number of vapour phase [1]", 12637, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.lambda_l",\
 "Thermal conductivity of liquid phase [W/(m.K)]", 12638, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.lambda_v",\
 "Thermal conductivity of vapour phase [W/(m.K)]", 12639, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.eta_l",\
 "Dynamic viscosity of liquid phase [Pa.s]", 12640, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.eta_v",\
 "Dynamic viscosity of vapour phase [Pa.s]", 12641, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.transp.Pr",\
 "Prandtl number [1]", "PF4U.tube3.gas[1].transp.Pr", 1, 5, 17240, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.transp.lambda",\
 "Thermal conductivity [W/(m.K)]", "PF4U.tube3.gas[1].transp.lambda", 1, 5, 17241,\
 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.transp.eta",\
 "Dynamic viscosity [Pa.s]", "PF4U.tube3.gas[1].transp.eta", 1, 5, 17242, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.transp.sigma",\
 "Surface tension [N/m]", "PF4U.tube3.gas[1].transp.sigma", 1, 5, 17243, 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.pressureDrop",\
 "Pressure drop [Pa|bar]", 17264, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.hydraulicDiameter",\
 "Hydraulic diameter [m]", 12642, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.hydraulicCrossSectionalArea",\
 "Cross-sectional area [m2]", 12643, 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.length", \
"Length [m]", "PF4U.tube3.tubeGeometry.length", 1, 5, 12479, 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.Re", \
"Reynold's number [1]", 17265, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.v", \
"Velocity [m/s]", 17266, 0.0, 0.0,0.0,0.0,0,2624)
DeclareParameter("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.Re_transitionBegin",\
 "At this Reynold's number the transition from laminar to turbulent begins [1]",\
 1256, 2250, 0.0,0.0,0.0,0,2608)
DeclareParameter("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.Re_transitionEnd",\
 "At this Reynold's number the transition from laminar to turbulent ends [1]", 1257,\
 2350, 0.0,0.0,0.0,0,2608)
DeclareParameter("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.vLimit", \
"Obsolete - Fluid velocity below which the pressure drop relation is regularized [m/s]",\
 1258, 0.001, 0.0,0.0,0.0,0,2608)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.lambdaTurbulent",\
 "Darcy-Weisbach friction factor for turbulent flow", 17267, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.pressureDropLaminar",\
 "Laminar pressure drop model [Pa|bar]", 17268, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.pressureDropTurbulent",\
 "Turbulent pressure drop model [Pa|bar]", 17269, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.weightingFactor",\
 "Factor for transition between laminar and turbulent zone [1]", 17270, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareParameter("PF4U.tube3.pressureDrop[1].pressureDropModel.correctionFactor",\
 "Linear correction factor for the pressureDrop calculated by this pressure drop model and its submodels. [1]",\
 1259, 1, 0.0,0.0,0.0,0,2608)
DeclareParameter("PF4U.tube3.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1260, 0.003, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.tube3.pInitial", "Initial value for gas pressure [Pa|bar]",\
 12644, 4000000, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube3.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 12645, true, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube3.TInitial", "Initial value for gas temperature [K|K]",\
 12646, 288.15, 0.0,1.7976931348623157E+308,300.0,0,513)
DeclareParameter("PF4U.tube3.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1261, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.tube3.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 12647, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.tube3.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1262, 1, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.tube3.massFlowRateHomotopy", "Nominal mass flow rate for linear valve equation [kg/s]",\
 1263, 0.01, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.tube3.pressureDropHomotopy", "Nominal pressure drop for linear valve equation [Pa|bar]",\
 1264, 10000.0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.tube3.hInitial", "[J/kg]", 12648, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.TInitialWall", "Initial value for wall temperature [K|K]",\
 12649, 288.15, 0.0,1.7976931348623157E+308,300.0,0,513)
DeclareVariable("PF4U.tube3.connectWallCells", "If true: wall cells should be connected W-E [:#(type=Boolean)]",\
 12650, false, 0.0,0.0,0.0,0,515)
DeclareAlias2("PF4U.tube3.wallCell[1].cellGeometry.length", "[m]", \
"PF4U.tube3.tubeGeometry.length", 1, 5, 12479, 1024)
DeclareVariable("PF4U.tube3.wallCell[1].cellGeometry.volume", "[m3]", 12651, 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.tube3.wallCell[1].portN.T", "Port temperature [K|degC]", \
"PF4U.Channel3.T_wall", 1, 5, 17016, 1028)
DeclareAlias2("PF4U.tube3.wallCell[1].portN.Q_flow", "Heat flow rate [W]", \
"PF4U.prescribedHeatFlow2.port.Q_flow", -1, 5, 17225, 1156)
DeclareAlias2("PF4U.tube3.wallCell[1].portS.T", "Port temperature [K|degC]", \
"PF4U.tube3.heatTransfer[1].wallTemperature", 1, 5, 17251, 1028)
DeclareVariable("PF4U.tube3.wallCell[1].portS.Q_flow", "Heat flow rate [W]", 17271,\
 0.0, 0.0,0.0,0.0,0,2824)
DeclareVariable("PF4U.tube3.wallCell[1].portW.T", "Port temperature [K|degC]", 17272,\
 0.0, 0.0,1.7976931348623157E+308,300.0,0,2568)
DeclareVariable("PF4U.tube3.wallCell[1].portW.Q_flow", "Heat flow rate [W]", 12652,\
 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube3.wallCell[1].portE.T", "Port temperature [K|degC]", 17273,\
 0.0, 0.0,1.7976931348623157E+308,300.0,0,2568)
DeclareVariable("PF4U.tube3.wallCell[1].portE.Q_flow", "Heat flow rate [W]", 12653,\
 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube3.wallCell[1].TInitialWall", "Initial wall temperature [K|degC]",\
 12654, 288.15, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].fixedTInitialWall", "if true, force usage of initial value TInitialWall [:#(type=Boolean)]",\
 12655, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube3.wallCell[1].initSteadyState", "[:#(type=Boolean)]", 12656,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube3.wallCell[1].additionalHeatCapacity", "[J/K]", 12657,\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].properties.d", "Density [kg/m3|g/cm3]", 12658,\
 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube3.wallCell[1].properties.T", "Temperature [K|degC]", \
"PF4U.tube3.wallCell[1].wallStateTemperature", 1, 1, 107, 1024)
DeclareVariable("PF4U.tube3.wallCell[1].properties.cp", "Heat capacity [J/(kg.K)]",\
 12659, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].properties.lambda", "Thermal conductivity [W/(m.K)]",\
 12660, 40.0, 0.0,0.0,0.0,0,2561)
DeclareState("PF4U.tube3.wallCell[1].wallStateTemperature", "[K|degC]", 107, 0.0,\
 0.0,1.7976931348623157E+308,300.0,0,2592)
DeclareDerivative("PF4U.tube3.wallCell[1].der(wallStateTemperature)", "[K/s]", 107,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.d", "Density [kg/m3|g/cm3]",\
 12661, 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube3.wallCell[1].wallMaterial.T", "Temperature [K|degC]", \
"PF4U.tube3.wallCell[1].wallStateTemperature", 1, 1, 107, 1024)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.cp", "Heat capacity [J/(kg.K)]",\
 12662, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.lambda", "Thermal conductivity [W/(m.K)]",\
 12663, 40.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.cp_nominal", \
"Specific heat capacity at standard reference point [J/(kg.K)]", 12664, 490.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.lambda_nominal", \
"Thermal conductivity at standard reference point [W/(m.K)]", 12665, 40.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.solid.cp_nominal", \
"Specific heat capacity at standard reference point [J/(kg.K)]", 12666, 490.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.solid.lambda_nominal", \
"Thermal conductivity at standard reference point [W/(m.K)]", 12667, 40.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.solid.d", "Density [kg/m3|g/cm3]",\
 12668, 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube3.wallCell[1].wallMaterial.solid.T", "Temperature [K|degC]",\
 "PF4U.tube3.wallCell[1].wallStateTemperature", 1, 1, 107, 1024)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.solid.cp", "Heat capacity [J/(kg.K)]",\
 12669, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.solid.lambda", \
"Thermal conductivity [W/(m.K)]", 12670, 40.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].heatTransfer.R_WE", "Thermal resistance (W-E) for one cell [K/W]",\
 12671, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].heatTransfer.R_NS", "Thermal resistance (N-S) for one cell [K/W]",\
 12672, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].heatTransfer.connectWallCells", \
"[:#(type=Boolean)]", 12673, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube3.wallCell[1].heatTransfer.R_NS_total", \
"Thermal resistance (N-S) for total HX [K/W]", 12674, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].heatTransfer.R_WE_total", \
"Thermal resistance (W-E) for total HX [K/W]", 12675, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].geometricMass", "Geometric mass [kg]", 12676,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].SProd_dot", "Produced entropy [W/K]", 17274,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube3.getInputsThermal[1].heatPort.T", "Port temperature [K|degC]",\
 "PF4U.tube3.heatTransfer[1].wallTemperature", 1, 5, 17251, 1028)
DeclareAlias2("PF4U.tube3.getInputsThermal[1].heatPort.Q_flow", "Heat flow rate [W]",\
 "PF4U.tube3.wallCell[1].portS.Q_flow", -1, 5, 17271, 1156)
DeclareVariable("PF4U.tube3.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12677, true, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.tube3.includeSummaryArrays", "Obsolete & unused parameter for array entries in summary [:#(type=Boolean)]",\
 1265, true, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube3.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12678, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube3.summary.p_gas_A", "Pressure at port A [Pa|bar]", \
"PF4U.junction2.p", 1, 1, 103, 0)
DeclareAlias2("PF4U.tube3.summary.p_gas_B", "Pressure at port B [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.tube3.summary.T_gas_A", "Temperature at port A [K|degC]", \
"PF4U.Channel3.T_gas_in", 1, 5, 17018, 0)
DeclareAlias2("PF4U.tube3.summary.T_gas_B", "Temperature at port B [K|degC]", \
"PF4U.Channel3.T_gas_out", 1, 5, 17017, 0)
DeclareVariable("PF4U.tube3.summary.T_degC_gas_A", "Temperature at port A [degC;]",\
 17275, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube3.summary.T_degC_gas_B", "Temperature at port B [degC;]",\
 17276, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube3.summary.h_gas_A", "Specific enthalpy at port A [J/kg]",\
 17277, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube3.summary.h_gas_B", "Specific enthalpy at port B [J/kg]",\
 17278, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube3.summary.d_gas_A", "Density at port A [kg/m3|g/cm3]",\
 17279, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.tube3.summary.d_gas_B", "Density at port B [kg/m3|g/cm3]",\
 17280, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareAlias2("PF4U.tube3.summary.m_flow_gas_A", "Mass flow rate at port A [kg/s]",\
 "PF4U.tube3.portA.m_flow", 1, 5, 17227, 0)
DeclareAlias2("PF4U.tube3.summary.m_flow_gas_B", "Mass flow rate at port B [kg/s]",\
 "PF4U.Channel3.m_flow", 1, 5, 17019, 0)
DeclareVariable("PF4U.tube3.summary.w_gas_A", "Flow velocity at port A [m/s]", 17281,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube3.summary.w_gas_B", "Flow velocity at port B [m/s]", 17282,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube3.summary.dp_gas", "Total pressure drop [Pa|bar]", 17283,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube3.summary.Q_flow_gas", "Total heat flow rate [W]", \
"PF4U.tube3.wallCell[1].portS.Q_flow", -1, 5, 17271, 0)
DeclareVariable("PF4U.tube3.summary.mass_gas", "Total fluid mass [kg]", 17284, \
0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareAlias2("PF4U.tube3.summary.volume_gas", "Total fluid volume [m3]", \
"PF4U.tube3.tubeGeometry.innerVolume", 1, 5, 12485, 0)
DeclareVariable("PF4U.tube3.summary.alpha_average_gas", "Average coefficient of heat transfer [W/(m2.K)]",\
 17285, 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube3.summary.mass_component", "Total component mass [kg]", \
"PF4U.tube3.wallCell[1].geometricMass", 1, 5, 12676, 0)
DeclareVariable("PF4U.tube3.summary.arrays.n", "[:#(type=Integer)]", 12679, 1, \
0.0,0.0,0.0,0,517)
DeclareAlias2("PF4U.tube3.summary.arrays.T_gas_cell[1]", "[K|degC]", \
"PF4U.tube3.T_gas_cell_[1]", 1, 5, 17289, 0)
DeclareVariable("PF4U.tube3.summary.arrays.T_degC_gas_cell[1]", "[degC;]", 17286,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube3.summary.arrays.T_wall_cell[1]", "[K|degC]", \
"PF4U.tube3.wallCell[1].wallStateTemperature", 1, 1, 107, 0)
DeclareVariable("PF4U.tube3.summary.arrays.T_degC_wall_cell[1]", "[degC;]", 17287,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube3.summary.arrays.p_gas_cell[1]", "[Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.tube3.summary.arrays.h_gas_cell[1]", "[J/kg]", \
"PF4U.tube3.h[1]", 1, 1, 106, 0)
DeclareAlias2("PF4U.tube3.summary.arrays.d_gas_cell[1]", "[kg/m3|g/cm3]", \
"PF4U.tube3.gas[1].d", 1, 5, 17228, 0)
DeclareVariable("PF4U.tube3.summary.arrays.alpha_gas_cell[1]", "Heat transfer coefficient [W/(m2.K)]",\
 17288, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube3.T_gas_cell_[1]", "[K|degC]", 17289, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.tube3.T_wall_cell_[1]", "[K|degC]", "PF4U.tube3.wallCell[1].wallStateTemperature", 1,\
 1, 107, 1024)
DeclareVariable("PF4U.tube3.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12680, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube3.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12681,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12682, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12683,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12684, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12685, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12686, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasA.gasPointer.id", "[:#(type=Integer)]", 12687, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.tube3.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1266, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube3.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12688, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube3.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12689,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12690, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12691,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12692, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12693, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12694, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasB.gasPointer.id", "[:#(type=Integer)]", 12695, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.tube3.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1267, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube3.fixedTInitialWall", "if true, force usage of initial value TInitialWall [:#(type=Boolean)]",\
 12696, false, 0.0,0.0,0.0,0,515)
DeclareAlias2("PF4U.tube3.heatPort[1].T", "Port temperature [K|degC]", \
"PF4U.Channel3.T_wall", 1, 5, 17016, 4)
DeclareAlias2("PF4U.tube3.heatPort[1].Q_flow", "Heat flow rate [W]", \
"PF4U.prescribedHeatFlow2.port.Q_flow", -1, 5, 17225, 132)
DeclareParameter("PF4U.prescribedHeatFlow3.T_ref", "Reference temperature [K|degC]",\
 1268, 293.15, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.prescribedHeatFlow3.alpha", "Temperature coefficient of heat flow rate [1/K]",\
 1269, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.prescribedHeatFlow3.Q_flow", "[W]", 17290, 0.0, 0.0,0.0,\
0.0,0,512)
DeclareAlias2("PF4U.prescribedHeatFlow3.port.T", "Port temperature [K|degC]", \
"PF4U.Channel4.T_wall", 1, 5, 17020, 4)
DeclareVariable("PF4U.prescribedHeatFlow3.port.Q_flow", "Heat flow rate (positive if flowing from outside into the component) [W]",\
 17291, 0, 0.0,0.0,0.0,0,776)
DeclareParameter("PF4U.stepSource3.transitionTime", "Duration of transition [s]",\
 1270, 0.5, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.stepSource3.initialValue", "Value before first step", 1271,\
 0.0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.stepSource3.stepTimes[1]", "Beginning of transitions [s]",\
 12697, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource3.stepTimes[2]", "Beginning of transitions [s]",\
 12698, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource3.stepValues[1]", "Values of steps", 12699, 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource3.stepValues[2]", "Values of steps", 12700, 0.0,\
 0.0,0.0,0.0,0,513)
DeclareAlias2("PF4U.stepSource3.y", "[W]", "PF4U.prescribedHeatFlow3.Q_flow", 1,\
 5, 17290, 0)
DeclareVariable("PF4U.stepSource3.stepCount", "[:#(type=Integer)]", 12701, 2, \
0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.stepSource3.const_finalValue.k", "Constant output value [W]",\
 12702, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.const_finalValue.y", "Connector of Real output signal [W]",\
 12703, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[1].switchTime", "[s]", 12704, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[1].transitionTime", "[s]", 12705, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[1].preSwitchValue", \
"Value to use before switching to input [W]", 12706, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[1].u", "[W]", 12707, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[1].y", "[W]", 17292, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("PF4U.stepSource3.timeSwitch[1].switchEndTime", "[s]", 12708, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[1].switchMidTime", "[s]", 12709, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[2].switchTime", "[s]", 12710, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[2].transitionTime", "[s]", 12711, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[2].preSwitchValue", \
"Value to use before switching to input [W]", 12712, 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.stepSource3.timeSwitch[2].u", "[W]", "PF4U.stepSource3.timeSwitch[1].y", 1,\
 5, 17292, 1024)
DeclareAlias2("PF4U.stepSource3.timeSwitch[2].y", "[W]", "PF4U.prescribedHeatFlow3.Q_flow", 1,\
 5, 17290, 1024)
DeclareVariable("PF4U.stepSource3.timeSwitch[2].switchEndTime", "[s]", 12713, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[2].switchMidTime", "[s]", 12714, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12715, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube4.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 12716, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12717, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12718,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 12719, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12720, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12721, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.tubeGeometry.innerDiameter", "Inner diameter of circular tube [m]",\
 12722, 0.0, 0.0,1.7976931348623157E+308,0.0,0,513)
DeclareParameter("PF4U.tube4.tubeGeometry.wallThickness", "Wall thickness [m]", 1272,\
 0.0005, 0.0,1.7976931348623157E+308,0.0,0,560)
DeclareVariable("PF4U.tube4.tubeGeometry.length", "Length [m]", 12723, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,513)
DeclareParameter("PF4U.tube4.tubeGeometry.nParallelTubes", "Number of parallel Tubes [:#(type=Integer)]",\
 1273, 1, 1.0,1.7976931348623157E+308,0.0,0,564)
DeclareParameter("PF4U.tube4.tubeGeometry.crossSectionType", "Tube Cross Section Type [:#(type=ThermalSystems.Internals.CrossSectionType)]",\
 1274, 1, 1.0,2.0,0.0,0,564)
DeclareParameter("PF4U.tube4.tubeGeometry.innerCrossSectionalAreaNonCircular", \
"Inner cross sectional area of one non-circular tube [m2]", 1275, 0, 0.0,0.0,0.0,\
0,560)
DeclareParameter("PF4U.tube4.tubeGeometry.outerCrossSectionalAreaNonCircular", \
"Outer cross sectional area of one non-circular tube [m2]", 1276, 0, 0.0,0.0,0.0,\
0,560)
DeclareParameter("PF4U.tube4.tubeGeometry.innerPerimeterNonCircular", \
"Perimeter of one non-circular tube [m]", 1277, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.tube4.tubeGeometry.outerDiameter", "[m]", 12724, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.innerCrossSectionalArea", \
"Inner cross-sectional area [m2]", 12725, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.outerCrossSectionalArea", \
"Outer cross-sectional area [m2]", 12726, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.hydraulicCrossSectionalArea", \
"Hydraulic cross sectional area [m2]", 12727, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.hydraulicDiameter", "Hydraulic diameter [m]",\
 12728, 0.0, 0.0,1.7976931348623157E+308,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.innerVolume", "Inner volume [m3]", 12729,\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.outerVolume", "Outer volume [m3]", 12730,\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.innerHeatTransferArea", "[m2]", 12731, \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.tubeIsCircular", "true, if tube's cross section is circular [:#(type=Boolean)]",\
 12732, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube4.simPort.vleFluidMass", "[kg]", 12733, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.simPort.vleFluidVolume", "[m3]", 12734, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.simPort.liquidMass", "[kg]", 12735, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("PF4U.tube4.simPort.liquidVolume", "[m3]", 12736, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("PF4U.tube4.simPort.gasMass", "[kg]", "PF4U.tube4.cellMass[1]", 1,\
 5, 17310, 1024)
DeclareAlias2("PF4U.tube4.simPort.gasVolume", "[m3]", "PF4U.tube4.tubeGeometry.innerVolume", 1,\
 5, 12729, 1024)
DeclareVariable("PF4U.tube4.simPort.dpdt", "", 12737, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.simPort.dpdtCounter", "", 12738, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 12739, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube4.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 12740, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube4.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 12741, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube4.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 12742, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.tube4.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.tube4.cellMass[1]", 1, 5, 17310, 1156)
DeclareAlias2("PF4U.tube4.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.tube4.tubeGeometry.innerVolume", 1, 5, 12729, 1156)
DeclareVariable("PF4U.tube4.simPort.dpdtPort.dpdt", "", 12743, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("PF4U.tube4.simPort.dpdtPort.counter", "", 12744, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.tube4.simPort.warningsPort.warnings", "Accumulated warnings",\
 12745, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube4.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12746, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube4.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12747,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube4.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12748, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12749,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12750, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12751, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12752, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.tube4.portA.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1, 1,\
 103, 4)
DeclareVariable("PF4U.tube4.portA.m_flow", "Mass flow rate [kg/s]", 17293, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.tube4.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.tube4.h[1]", 1, 1, 108, 4)
DeclareVariable("PF4U.tube4.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12753, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube4.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12754,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube4.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12755, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12756,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12757, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12758, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12759, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.tube4.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("PF4U.tube4.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.Channel4.m_flow", 1, 5, 17023, 132)
DeclareAlias2("PF4U.tube4.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.tube4.h[1]", 1, 1, 108, 4)
DeclareAlias2("PF4U.tube4.cellGeometry.length", "[m]", "PF4U.tube4.tubeGeometry.length", 1,\
 5, 12723, 1024)
DeclareAlias2("PF4U.tube4.cellGeometry.volume", "[m3]", "PF4U.tube4.tubeGeometry.innerVolume", 1,\
 5, 12729, 1024)
DeclareAlias2("PF4U.tube4.cellGeometry.heatTransferArea", "[m2]", \
"PF4U.tube4.tubeGeometry.innerHeatTransferArea", 1, 5, 12731, 1024)
DeclareParameter("PF4U.tube4.cellGeometry.finHeatTransferAreaRatio", \
"Fraction of fins on fin side heat transfer area", 1278, 0, 0.0,0.0,0.0,0,2608)
DeclareVariable("PF4U.tube4.cellGeometry.hydraulicCrossSectionalArea", "[m2]", 12760,\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.cellGeometry.nParallelHydraulicFlows", \
"Number of parallel flows [1]", 12761, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.dl[1]", "length portions of cells", 12762, 1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDropPosition", "Position of pressure drop in tube [:#(type=ThermalSystems.Internals.PressureDropPosition)]",\
 12763, 3, 1.0,3.0,0.0,0,517)
DeclareVariable("PF4U.tube4.nCells", "Discretization number of 'cells' [:#(type=Integer)]",\
 12764, 1, 0.0,0.0,0.0,0,517)
DeclareVariable("PF4U.tube4.enableHeatPorts", "true, if heat ports are enabled [:#(type=Boolean)]",\
 12765, true, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube4.generateEventsAtFlowReversal", "If true: Events will be generated at flow reversal [:#(type=Boolean)]",\
 12766, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube4.gas[1].gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12767, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube4.gas[1].gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12768,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube4.gas[1].gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12769, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gas[1].gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12770,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gas[1].gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12771, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gas[1].gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12772, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gas[1].gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12773, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gas[1].gasPointer.id", "[:#(type=Integer)]", 12774, 0,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.tube4.gas[1].stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 12775, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube4.gas[1].computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 12776, true, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube4.gas[1].d", "Density [kg/m3|g/cm3]", 17294, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.tube4.gas[1].p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 1024)
DeclareAlias2("PF4U.tube4.gas[1].h", "Specific enthalpy [J/kg]", \
"PF4U.tube4.h[1]", 1, 1, 108, 1024)
DeclareVariable("PF4U.tube4.gas[1].s", "Specific entropy [J/(kg.K)]", 17295, 0.0,\
 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube4.gas[1].T", "Temperature [K|degC]", "PF4U.tube4.T_gas_cell_[1]", 1,\
 5, 17355, 1024)
DeclareAlias2("PF4U.tube4.gas[1].M", "Average molar mass [kg/mol]", \
"PF4U.tube4.gas[1].M_i[1]", 1, 5, 12782, 1024)
DeclareVariable("PF4U.tube4.gas[1].cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17296, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17297, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].beta", "Isobaric thermal expansion coefficient [1/K]",\
 17298, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].kappa", "Isothermal compressibility [1/Pa]", 17299,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].w", "Speed of sound [m/s]", 17300, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17301, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17302, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].p_i[1]", "Partial pressure [Pa|bar]", 17303, \
0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17304, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].phi", "Relative humidity", 12777, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 12778, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].xi_s", "Saturation mass fraction of condensing component [1]",\
 12779, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 12780, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 12781, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17305, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].M_i[1]", "Molar mass of component i [kg/mol]",\
 12782, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].humRatio", "Content of condensing component aka humidity ratio [1]",\
 12783, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 12784, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 12785, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].transp.Pr", "Prandtl number [1]", 17306, 0.0,\
 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].transp.lambda", "Thermal conductivity [W/(m.K)]",\
 17307, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].transp.eta", "Dynamic viscosity [Pa.s]", 17308,\
 0.0, -1.0,1.7976931348623157E+308,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].transp.sigma", "Surface tension [N/m]", 17309,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].computeFlags", "[:#(type=Integer)]", 12786, 5,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.tube4.cellMass[1]", "Gas mass in one cell [kg]", 17310, \
0.0, 0.0,1.7976931348623157E+308,0.0,0,2560)
DeclareVariable("PF4U.tube4.drhodt[1]", "", 17311, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.p[1]", "[Pa|bar]", 17312, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2560)
DeclareAlias2("PF4U.tube4.der(p[1])", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18,\
 1024)
DeclareState("PF4U.tube4.h[1]", "Specific enthalpy [J/kg]", 108, 0.0, 0.0,0.0,\
100000.0,0,2592)
DeclareDerivative("PF4U.tube4.der(h[1])", "der(Specific enthalpy) [m2/s3]", 108,\
 0.0, 0.0,0.0,0.0,0,2624)
DeclareAlias2("PF4U.tube4.m_flow[1]", "[kg/s]", "PF4U.tube4.portA.m_flow", 1, 5,\
 17293, 1024)
DeclareAlias2("PF4U.tube4.m_flow[2]", "[kg/s]", "PF4U.Channel4.m_flow", -1, 5, 17023,\
 1024)
DeclareVariable("PF4U.tube4.H_flow[1]", "", 17313, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.H_flow[2]", "", 17314, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.mdotHydraulic", "[kg/s]", 17315, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube4.heatTransfer[1].mdotHydraulic", "Hydraulic mass flow rate [kg/s]",\
 "PF4U.tube4.mdotHydraulic", 1, 5, 17315, 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].QdotHydraulic", "Hydraulic heat flow rate [W]",\
 17316, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].wallTemperature", "Wall temperature [K|degC]",\
 17317, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.d", "Density [kg/m3|g/cm3]",\
 "PF4U.tube4.gas[1].d", 1, 5, 17294, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.h", "Specific enthalpy [J/kg]",\
 "PF4U.tube4.h[1]", 1, 1, 108, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.p", "Pressure [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.s", "Specific entropy [J/(kg.K)]",\
 "PF4U.tube4.gas[1].s", 1, 5, 17295, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.T", "Temperature [K|degC]",\
 "PF4U.tube4.T_gas_cell_[1]", 1, 5, 17355, 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.q", "Steam mass fraction (quality) [1]",\
 12787, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.tube4.gas[1].cp", 1, 5, 17296, 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.crit.d", "Critical density [kg/m3|g/cm3]",\
 12788, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.crit.h", "Critical specific enthalpy [J/kg]",\
 12789, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.crit.p", "Critical pressure [Pa|bar]",\
 12790, 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.crit.s", "Critical specific entropy [J/(kg.K)]",\
 12791, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.crit.T", "Critical temperature [K|degC]",\
 12792, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.d_l", \
"Density of liquid phase [kg/m3|g/cm3]", 12793, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.d_v", \
"Density of vapour phase [kg/m3|g/cm3]", 12794, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.h_l", \
"Specific enthalpy of liquid phase [J/kg]", 12795, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.h_v", \
"Specific enthalpy of vapour phase [J/kg]", 12796, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.p_l", \
"Pressure of liquid phase [Pa|bar]", 12797, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.p_v", \
"Pressure of vapour phase [Pa|bar]", 12798, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.s_l", \
"Specific entropy of liquid phase [J/(kg.K)]", 12799, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.s_v", \
"Specific entropy of vapour phase [J/(kg.K)]", 12800, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.T_l", \
"Temperature of liquid phase [K|degC]", 12801, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.T_v", \
"Temperature of vapour phase [K|degC]", 12802, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLETransp.Pr_l", \
"Prandtl number of liquid phase [1]", 12803, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLETransp.Pr_v", \
"Prandtl number of vapour phase [1]", 12804, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLETransp.lambda_l", \
"Thermal conductivity of liquid phase [W/(m.K)]", 12805, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLETransp.lambda_v", \
"Thermal conductivity of vapour phase [W/(m.K)]", 12806, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLETransp.eta_l", \
"Dynamic viscosity of liquid phase [Pa.s]", 12807, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLETransp.eta_v", \
"Dynamic viscosity of vapour phase [Pa.s]", 12808, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.transp.Pr", \
"Prandtl number [1]", "PF4U.tube4.gas[1].transp.Pr", 1, 5, 17306, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.transp.lambda", \
"Thermal conductivity [W/(m.K)]", "PF4U.tube4.gas[1].transp.lambda", 1, 5, 17307,\
 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.transp.eta", \
"Dynamic viscosity [Pa.s]", "PF4U.tube4.gas[1].transp.eta", 1, 5, 17308, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.transp.sigma", \
"Surface tension [N/m]", "PF4U.tube4.gas[1].transp.sigma", 1, 5, 17309, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].cellGeometry.length", "[m]", \
"PF4U.tube4.tubeGeometry.length", 1, 5, 12723, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].cellGeometry.volume", "[m3]", \
"PF4U.tube4.tubeGeometry.innerVolume", 1, 5, 12729, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].cellGeometry.heatTransferArea", "[m2]",\
 "PF4U.tube4.tubeGeometry.innerHeatTransferArea", 1, 5, 12731, 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].cellGeometry.finHeatTransferAreaRatio",\
 "Fraction of fins on fin side heat transfer area", 12809, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].cellGeometry.hydraulicCrossSectionalArea",\
 "[m2]", 12810, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].cellGeometry.nParallelHydraulicFlows",\
 "Number of parallel flows", 12811, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].alphaA", "Value for alphaA for one cell [W/K]",\
 17318, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.alphaA", "Value for alphaA for one cell [W/K]",\
 "PF4U.tube4.heatTransfer[1].alphaA", 1, 5, 17318, 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.computeTransportProperties",\
 "[:#(type=Boolean)]", 12812, true, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.useAlphaAState", \
"alphaA is a differential state [:#(type=Boolean)]", 12813, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.mdotHydraulic", \
"Hydraulic mass flow rate [kg/s]", "PF4U.tube4.mdotHydraulic", 1, 5, 17315, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.d", \
"Density [kg/m3|g/cm3]", "PF4U.tube4.gas[1].d", 1, 5, 17294, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.h", \
"Specific enthalpy [J/kg]", "PF4U.tube4.h[1]", 1, 1, 108, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.p", \
"Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.s", \
"Specific entropy [J/(kg.K)]", "PF4U.tube4.gas[1].s", 1, 5, 17295, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.T", \
"Temperature [K|degC]", "PF4U.tube4.T_gas_cell_[1]", 1, 5, 17355, 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.q", \
"Steam mass fraction (quality) [1]", 12814, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.cp", \
"Specific isobaric heat capacity cp [J/(kg.K)]", "PF4U.tube4.gas[1].cp", 1, 5, 17296,\
 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.crit.d",\
 "Critical density [kg/m3|g/cm3]", 12815, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.crit.h",\
 "Critical specific enthalpy [J/kg]", 12816, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.crit.p",\
 "Critical pressure [Pa|bar]", 12817, 0.0, 0.0,1.7976931348623157E+308,100000.0,\
0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.crit.s",\
 "Critical specific entropy [J/(kg.K)]", 12818, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.crit.T",\
 "Critical temperature [K|degC]", 12819, 0.0, 0.0,1.7976931348623157E+308,300.0,\
0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.d_l",\
 "Density of liquid phase [kg/m3|g/cm3]", 12820, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.d_v",\
 "Density of vapour phase [kg/m3|g/cm3]", 12821, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.h_l",\
 "Specific enthalpy of liquid phase [J/kg]", 12822, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.h_v",\
 "Specific enthalpy of vapour phase [J/kg]", 12823, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.p_l",\
 "Pressure of liquid phase [Pa|bar]", 12824, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.p_v",\
 "Pressure of vapour phase [Pa|bar]", 12825, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.s_l",\
 "Specific entropy of liquid phase [J/(kg.K)]", 12826, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.s_v",\
 "Specific entropy of vapour phase [J/(kg.K)]", 12827, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.T_l",\
 "Temperature of liquid phase [K|degC]", 12828, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.T_v",\
 "Temperature of vapour phase [K|degC]", 12829, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.Pr_l",\
 "Prandtl number of liquid phase [1]", 12830, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.Pr_v",\
 "Prandtl number of vapour phase [1]", 12831, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.lambda_l",\
 "Thermal conductivity of liquid phase [W/(m.K)]", 12832, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.lambda_v",\
 "Thermal conductivity of vapour phase [W/(m.K)]", 12833, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.eta_l",\
 "Dynamic viscosity of liquid phase [Pa.s]", 12834, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.eta_v",\
 "Dynamic viscosity of vapour phase [Pa.s]", 12835, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.transp.Pr",\
 "Prandtl number [1]", "PF4U.tube4.gas[1].transp.Pr", 1, 5, 17306, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.transp.lambda",\
 "Thermal conductivity [W/(m.K)]", "PF4U.tube4.gas[1].transp.lambda", 1, 5, 17307,\
 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.transp.eta",\
 "Dynamic viscosity [Pa.s]", "PF4U.tube4.gas[1].transp.eta", 1, 5, 17308, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.transp.sigma",\
 "Surface tension [N/m]", "PF4U.tube4.gas[1].transp.sigma", 1, 5, 17309, 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.alpha", \
"Coefficient of heat transfer [W/(m2.K)]", 17319, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.hydraulicDiameter",\
 "Hydraulic diameter [m]", 12836, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.hydraulicCrossSectionalArea",\
 "Hydraulic cross sectional area [m2]", 12837, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.Re", \
"Reynolds Number [1]", 17320, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.Nu", \
"Nusselt number [1]", 17321, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.averageVelocity", \
"Average velocity [m/s]", 17322, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.weightingFactor1", \
"", 17323, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.weightingFactor2", \
"", 17324, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.Nu1", "[1]", 17325,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.Nu_Gnielinski", \
"[1]", 17326, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.Nu_DittusBoelter", \
"[1]", 17327, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.zeta", "", 17328, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareParameter("PF4U.tube4.heatTransfer[1].heatTransfer.correctionFactor", \
"Linear correction factor for the overall alphaA calculated by this heat transfer model and its submodels. [1]",\
 1279, 1, 0.0,0.0,0.0,0,2608)
DeclareAlias2("PF4U.tube4.pressureDrop[1].mdotHydraulic", "Hydraulic mass flow rate [kg/s]",\
 "PF4U.tube4.mdotHydraulic", 1, 5, 17315, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.d", "Density [kg/m3|g/cm3]",\
 "PF4U.tube4.gas[1].d", 1, 5, 17294, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.h", "Specific enthalpy [J/kg]",\
 "PF4U.tube4.h[1]", 1, 1, 108, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.p", "Pressure [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.s", "Specific entropy [J/(kg.K)]",\
 "PF4U.tube4.gas[1].s", 1, 5, 17295, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.T", "Temperature [K|degC]",\
 "PF4U.tube4.T_gas_cell_[1]", 1, 5, 17355, 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.q", "Steam mass fraction (quality) [1]",\
 12838, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.tube4.gas[1].cp", 1, 5, 17296, 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.crit.d", "Critical density [kg/m3|g/cm3]",\
 12839, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.crit.h", "Critical specific enthalpy [J/kg]",\
 12840, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.crit.p", "Critical pressure [Pa|bar]",\
 12841, 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.crit.s", "Critical specific entropy [J/(kg.K)]",\
 12842, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.crit.T", "Critical temperature [K|degC]",\
 12843, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.d_l", \
"Density of liquid phase [kg/m3|g/cm3]", 12844, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.d_v", \
"Density of vapour phase [kg/m3|g/cm3]", 12845, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.h_l", \
"Specific enthalpy of liquid phase [J/kg]", 12846, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.h_v", \
"Specific enthalpy of vapour phase [J/kg]", 12847, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.p_l", \
"Pressure of liquid phase [Pa|bar]", 12848, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.p_v", \
"Pressure of vapour phase [Pa|bar]", 12849, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.s_l", \
"Specific entropy of liquid phase [J/(kg.K)]", 12850, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.s_v", \
"Specific entropy of vapour phase [J/(kg.K)]", 12851, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.T_l", \
"Temperature of liquid phase [K|degC]", 12852, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.T_v", \
"Temperature of vapour phase [K|degC]", 12853, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLETransp.Pr_l", \
"Prandtl number of liquid phase [1]", 12854, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLETransp.Pr_v", \
"Prandtl number of vapour phase [1]", 12855, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLETransp.lambda_l", \
"Thermal conductivity of liquid phase [W/(m.K)]", 12856, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLETransp.lambda_v", \
"Thermal conductivity of vapour phase [W/(m.K)]", 12857, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLETransp.eta_l", \
"Dynamic viscosity of liquid phase [Pa.s]", 12858, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLETransp.eta_v", \
"Dynamic viscosity of vapour phase [Pa.s]", 12859, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.transp.Pr", \
"Prandtl number [1]", "PF4U.tube4.gas[1].transp.Pr", 1, 5, 17306, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.transp.lambda", \
"Thermal conductivity [W/(m.K)]", "PF4U.tube4.gas[1].transp.lambda", 1, 5, 17307,\
 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.transp.eta", \
"Dynamic viscosity [Pa.s]", "PF4U.tube4.gas[1].transp.eta", 1, 5, 17308, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.transp.sigma", \
"Surface tension [N/m]", "PF4U.tube4.gas[1].transp.sigma", 1, 5, 17309, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].cellGeometry.length", "[m]", \
"PF4U.tube4.tubeGeometry.length", 1, 5, 12723, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].cellGeometry.volume", "[m3]", \
"PF4U.tube4.tubeGeometry.innerVolume", 1, 5, 12729, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].cellGeometry.heatTransferArea", "[m2]",\
 "PF4U.tube4.tubeGeometry.innerHeatTransferArea", 1, 5, 12731, 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].cellGeometry.finHeatTransferAreaRatio",\
 "Fraction of fins on fin side heat transfer area", 12860, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].cellGeometry.hydraulicCrossSectionalArea",\
 "[m2]", 12861, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].cellGeometry.nParallelHydraulicFlows",\
 "Number of parallel flows", 12862, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDrop", "Pressure drop for one cell [Pa|bar]",\
 17329, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.pressureDrop", \
"Pressure drop for one cell [Pa|bar]", "PF4U.tube4.pressureDrop[1].pressureDrop", 1,\
 5, 17329, 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.computeTransportProperties",\
 "[:#(type=Boolean)]", 12863, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.mdotHydraulic",\
 "Hydraulic mass flow rate [kg/s]", "PF4U.tube4.mdotHydraulic", 1, 5, 17315, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.d",\
 "Density [kg/m3|g/cm3]", "PF4U.tube4.gas[1].d", 1, 5, 17294, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.h",\
 "Specific enthalpy [J/kg]", "PF4U.tube4.h[1]", 1, 1, 108, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.p",\
 "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.s",\
 "Specific entropy [J/(kg.K)]", "PF4U.tube4.gas[1].s", 1, 5, 17295, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.T",\
 "Temperature [K|degC]", "PF4U.tube4.T_gas_cell_[1]", 1, 5, 17355, 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.q",\
 "Steam mass fraction (quality) [1]", 12864, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.cp",\
 "Specific isobaric heat capacity cp [J/(kg.K)]", "PF4U.tube4.gas[1].cp", 1, 5, 17296,\
 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.crit.d",\
 "Critical density [kg/m3|g/cm3]", 12865, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.crit.h",\
 "Critical specific enthalpy [J/kg]", 12866, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.crit.p",\
 "Critical pressure [Pa|bar]", 12867, 0.0, 0.0,1.7976931348623157E+308,100000.0,\
0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.crit.s",\
 "Critical specific entropy [J/(kg.K)]", 12868, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.crit.T",\
 "Critical temperature [K|degC]", 12869, 0.0, 0.0,1.7976931348623157E+308,300.0,\
0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.d_l",\
 "Density of liquid phase [kg/m3|g/cm3]", 12870, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.d_v",\
 "Density of vapour phase [kg/m3|g/cm3]", 12871, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.h_l",\
 "Specific enthalpy of liquid phase [J/kg]", 12872, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.h_v",\
 "Specific enthalpy of vapour phase [J/kg]", 12873, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.p_l",\
 "Pressure of liquid phase [Pa|bar]", 12874, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.p_v",\
 "Pressure of vapour phase [Pa|bar]", 12875, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.s_l",\
 "Specific entropy of liquid phase [J/(kg.K)]", 12876, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.s_v",\
 "Specific entropy of vapour phase [J/(kg.K)]", 12877, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.T_l",\
 "Temperature of liquid phase [K|degC]", 12878, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.T_v",\
 "Temperature of vapour phase [K|degC]", 12879, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.Pr_l",\
 "Prandtl number of liquid phase [1]", 12880, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.Pr_v",\
 "Prandtl number of vapour phase [1]", 12881, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.lambda_l",\
 "Thermal conductivity of liquid phase [W/(m.K)]", 12882, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.lambda_v",\
 "Thermal conductivity of vapour phase [W/(m.K)]", 12883, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.eta_l",\
 "Dynamic viscosity of liquid phase [Pa.s]", 12884, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.eta_v",\
 "Dynamic viscosity of vapour phase [Pa.s]", 12885, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.transp.Pr",\
 "Prandtl number [1]", "PF4U.tube4.gas[1].transp.Pr", 1, 5, 17306, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.transp.lambda",\
 "Thermal conductivity [W/(m.K)]", "PF4U.tube4.gas[1].transp.lambda", 1, 5, 17307,\
 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.transp.eta",\
 "Dynamic viscosity [Pa.s]", "PF4U.tube4.gas[1].transp.eta", 1, 5, 17308, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.transp.sigma",\
 "Surface tension [N/m]", "PF4U.tube4.gas[1].transp.sigma", 1, 5, 17309, 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.pressureDrop",\
 "Pressure drop [Pa|bar]", 17330, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.hydraulicDiameter",\
 "Hydraulic diameter [m]", 12886, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.hydraulicCrossSectionalArea",\
 "Cross-sectional area [m2]", 12887, 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.length", \
"Length [m]", "PF4U.tube4.tubeGeometry.length", 1, 5, 12723, 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.Re", \
"Reynold's number [1]", 17331, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.v", \
"Velocity [m/s]", 17332, 0.0, 0.0,0.0,0.0,0,2624)
DeclareParameter("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.Re_transitionBegin",\
 "At this Reynold's number the transition from laminar to turbulent begins [1]",\
 1280, 2250, 0.0,0.0,0.0,0,2608)
DeclareParameter("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.Re_transitionEnd",\
 "At this Reynold's number the transition from laminar to turbulent ends [1]", 1281,\
 2350, 0.0,0.0,0.0,0,2608)
DeclareParameter("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.vLimit", \
"Obsolete - Fluid velocity below which the pressure drop relation is regularized [m/s]",\
 1282, 0.001, 0.0,0.0,0.0,0,2608)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.lambdaTurbulent",\
 "Darcy-Weisbach friction factor for turbulent flow", 17333, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.pressureDropLaminar",\
 "Laminar pressure drop model [Pa|bar]", 17334, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.pressureDropTurbulent",\
 "Turbulent pressure drop model [Pa|bar]", 17335, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.weightingFactor",\
 "Factor for transition between laminar and turbulent zone [1]", 17336, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareParameter("PF4U.tube4.pressureDrop[1].pressureDropModel.correctionFactor",\
 "Linear correction factor for the pressureDrop calculated by this pressure drop model and its submodels. [1]",\
 1283, 1, 0.0,0.0,0.0,0,2608)
DeclareParameter("PF4U.tube4.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1284, 0.003, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.tube4.pInitial", "Initial value for gas pressure [Pa|bar]",\
 12888, 4000000, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube4.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 12889, true, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube4.TInitial", "Initial value for gas temperature [K|K]",\
 12890, 288.15, 0.0,1.7976931348623157E+308,300.0,0,513)
DeclareParameter("PF4U.tube4.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1285, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.tube4.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 12891, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.tube4.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1286, 1, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.tube4.massFlowRateHomotopy", "Nominal mass flow rate for linear valve equation [kg/s]",\
 1287, 0.01, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.tube4.pressureDropHomotopy", "Nominal pressure drop for linear valve equation [Pa|bar]",\
 1288, 10000.0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.tube4.hInitial", "[J/kg]", 12892, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.TInitialWall", "Initial value for wall temperature [K|K]",\
 12893, 288.15, 0.0,1.7976931348623157E+308,300.0,0,513)
DeclareVariable("PF4U.tube4.connectWallCells", "If true: wall cells should be connected W-E [:#(type=Boolean)]",\
 12894, false, 0.0,0.0,0.0,0,515)
DeclareAlias2("PF4U.tube4.wallCell[1].cellGeometry.length", "[m]", \
"PF4U.tube4.tubeGeometry.length", 1, 5, 12723, 1024)
DeclareVariable("PF4U.tube4.wallCell[1].cellGeometry.volume", "[m3]", 12895, 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.tube4.wallCell[1].portN.T", "Port temperature [K|degC]", \
"PF4U.Channel4.T_wall", 1, 5, 17020, 1028)
DeclareAlias2("PF4U.tube4.wallCell[1].portN.Q_flow", "Heat flow rate [W]", \
"PF4U.prescribedHeatFlow3.port.Q_flow", -1, 5, 17291, 1156)
DeclareAlias2("PF4U.tube4.wallCell[1].portS.T", "Port temperature [K|degC]", \
"PF4U.tube4.heatTransfer[1].wallTemperature", 1, 5, 17317, 1028)
DeclareVariable("PF4U.tube4.wallCell[1].portS.Q_flow", "Heat flow rate [W]", 17337,\
 0.0, 0.0,0.0,0.0,0,2824)
DeclareVariable("PF4U.tube4.wallCell[1].portW.T", "Port temperature [K|degC]", 17338,\
 0.0, 0.0,1.7976931348623157E+308,300.0,0,2568)
DeclareVariable("PF4U.tube4.wallCell[1].portW.Q_flow", "Heat flow rate [W]", 12896,\
 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube4.wallCell[1].portE.T", "Port temperature [K|degC]", 17339,\
 0.0, 0.0,1.7976931348623157E+308,300.0,0,2568)
DeclareVariable("PF4U.tube4.wallCell[1].portE.Q_flow", "Heat flow rate [W]", 12897,\
 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube4.wallCell[1].TInitialWall", "Initial wall temperature [K|degC]",\
 12898, 288.15, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].fixedTInitialWall", "if true, force usage of initial value TInitialWall [:#(type=Boolean)]",\
 12899, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube4.wallCell[1].initSteadyState", "[:#(type=Boolean)]", 12900,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube4.wallCell[1].additionalHeatCapacity", "[J/K]", 12901,\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].properties.d", "Density [kg/m3|g/cm3]", 12902,\
 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube4.wallCell[1].properties.T", "Temperature [K|degC]", \
"PF4U.tube4.wallCell[1].wallStateTemperature", 1, 1, 109, 1024)
DeclareVariable("PF4U.tube4.wallCell[1].properties.cp", "Heat capacity [J/(kg.K)]",\
 12903, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].properties.lambda", "Thermal conductivity [W/(m.K)]",\
 12904, 40.0, 0.0,0.0,0.0,0,2561)
DeclareState("PF4U.tube4.wallCell[1].wallStateTemperature", "[K|degC]", 109, 0.0,\
 0.0,1.7976931348623157E+308,300.0,0,2592)
DeclareDerivative("PF4U.tube4.wallCell[1].der(wallStateTemperature)", "[K/s]", 109,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.d", "Density [kg/m3|g/cm3]",\
 12905, 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube4.wallCell[1].wallMaterial.T", "Temperature [K|degC]", \
"PF4U.tube4.wallCell[1].wallStateTemperature", 1, 1, 109, 1024)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.cp", "Heat capacity [J/(kg.K)]",\
 12906, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.lambda", "Thermal conductivity [W/(m.K)]",\
 12907, 40.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.cp_nominal", \
"Specific heat capacity at standard reference point [J/(kg.K)]", 12908, 490.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.lambda_nominal", \
"Thermal conductivity at standard reference point [W/(m.K)]", 12909, 40.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.solid.cp_nominal", \
"Specific heat capacity at standard reference point [J/(kg.K)]", 12910, 490.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.solid.lambda_nominal", \
"Thermal conductivity at standard reference point [W/(m.K)]", 12911, 40.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.solid.d", "Density [kg/m3|g/cm3]",\
 12912, 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube4.wallCell[1].wallMaterial.solid.T", "Temperature [K|degC]",\
 "PF4U.tube4.wallCell[1].wallStateTemperature", 1, 1, 109, 1024)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.solid.cp", "Heat capacity [J/(kg.K)]",\
 12913, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.solid.lambda", \
"Thermal conductivity [W/(m.K)]", 12914, 40.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].heatTransfer.R_WE", "Thermal resistance (W-E) for one cell [K/W]",\
 12915, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].heatTransfer.R_NS", "Thermal resistance (N-S) for one cell [K/W]",\
 12916, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].heatTransfer.connectWallCells", \
"[:#(type=Boolean)]", 12917, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube4.wallCell[1].heatTransfer.R_NS_total", \
"Thermal resistance (N-S) for total HX [K/W]", 12918, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].heatTransfer.R_WE_total", \
"Thermal resistance (W-E) for total HX [K/W]", 12919, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].geometricMass", "Geometric mass [kg]", 12920,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].SProd_dot", "Produced entropy [W/K]", 17340,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube4.getInputsThermal[1].heatPort.T", "Port temperature [K|degC]",\
 "PF4U.tube4.heatTransfer[1].wallTemperature", 1, 5, 17317, 1028)
DeclareAlias2("PF4U.tube4.getInputsThermal[1].heatPort.Q_flow", "Heat flow rate [W]",\
 "PF4U.tube4.wallCell[1].portS.Q_flow", -1, 5, 17337, 1156)
DeclareVariable("PF4U.tube4.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12921, true, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.tube4.includeSummaryArrays", "Obsolete & unused parameter for array entries in summary [:#(type=Boolean)]",\
 1289, true, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube4.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12922, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube4.summary.p_gas_A", "Pressure at port A [Pa|bar]", \
"PF4U.junction2.p", 1, 1, 103, 0)
DeclareAlias2("PF4U.tube4.summary.p_gas_B", "Pressure at port B [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.tube4.summary.T_gas_A", "Temperature at port A [K|degC]", \
"PF4U.Channel4.T_gas_in", 1, 5, 17022, 0)
DeclareAlias2("PF4U.tube4.summary.T_gas_B", "Temperature at port B [K|degC]", \
"PF4U.Channel4.T_gas_out", 1, 5, 17021, 0)
DeclareVariable("PF4U.tube4.summary.T_degC_gas_A", "Temperature at port A [degC;]",\
 17341, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube4.summary.T_degC_gas_B", "Temperature at port B [degC;]",\
 17342, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube4.summary.h_gas_A", "Specific enthalpy at port A [J/kg]",\
 17343, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube4.summary.h_gas_B", "Specific enthalpy at port B [J/kg]",\
 17344, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube4.summary.d_gas_A", "Density at port A [kg/m3|g/cm3]",\
 17345, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.tube4.summary.d_gas_B", "Density at port B [kg/m3|g/cm3]",\
 17346, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareAlias2("PF4U.tube4.summary.m_flow_gas_A", "Mass flow rate at port A [kg/s]",\
 "PF4U.tube4.portA.m_flow", 1, 5, 17293, 0)
DeclareAlias2("PF4U.tube4.summary.m_flow_gas_B", "Mass flow rate at port B [kg/s]",\
 "PF4U.Channel4.m_flow", 1, 5, 17023, 0)
DeclareVariable("PF4U.tube4.summary.w_gas_A", "Flow velocity at port A [m/s]", 17347,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube4.summary.w_gas_B", "Flow velocity at port B [m/s]", 17348,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube4.summary.dp_gas", "Total pressure drop [Pa|bar]", 17349,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube4.summary.Q_flow_gas", "Total heat flow rate [W]", \
"PF4U.tube4.wallCell[1].portS.Q_flow", -1, 5, 17337, 0)
DeclareVariable("PF4U.tube4.summary.mass_gas", "Total fluid mass [kg]", 17350, \
0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareAlias2("PF4U.tube4.summary.volume_gas", "Total fluid volume [m3]", \
"PF4U.tube4.tubeGeometry.innerVolume", 1, 5, 12729, 0)
DeclareVariable("PF4U.tube4.summary.alpha_average_gas", "Average coefficient of heat transfer [W/(m2.K)]",\
 17351, 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube4.summary.mass_component", "Total component mass [kg]", \
"PF4U.tube4.wallCell[1].geometricMass", 1, 5, 12920, 0)
DeclareVariable("PF4U.tube4.summary.arrays.n", "[:#(type=Integer)]", 12923, 1, \
0.0,0.0,0.0,0,517)
DeclareAlias2("PF4U.tube4.summary.arrays.T_gas_cell[1]", "[K|degC]", \
"PF4U.tube4.T_gas_cell_[1]", 1, 5, 17355, 0)
DeclareVariable("PF4U.tube4.summary.arrays.T_degC_gas_cell[1]", "[degC;]", 17352,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube4.summary.arrays.T_wall_cell[1]", "[K|degC]", \
"PF4U.tube4.wallCell[1].wallStateTemperature", 1, 1, 109, 0)
DeclareVariable("PF4U.tube4.summary.arrays.T_degC_wall_cell[1]", "[degC;]", 17353,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube4.summary.arrays.p_gas_cell[1]", "[Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.tube4.summary.arrays.h_gas_cell[1]", "[J/kg]", \
"PF4U.tube4.h[1]", 1, 1, 108, 0)
DeclareAlias2("PF4U.tube4.summary.arrays.d_gas_cell[1]", "[kg/m3|g/cm3]", \
"PF4U.tube4.gas[1].d", 1, 5, 17294, 0)
DeclareVariable("PF4U.tube4.summary.arrays.alpha_gas_cell[1]", "Heat transfer coefficient [W/(m2.K)]",\
 17354, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube4.T_gas_cell_[1]", "[K|degC]", 17355, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.tube4.T_wall_cell_[1]", "[K|degC]", "PF4U.tube4.wallCell[1].wallStateTemperature", 1,\
 1, 109, 1024)
DeclareVariable("PF4U.tube4.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12924, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube4.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12925,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12926, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12927,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12928, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12929, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12930, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasA.gasPointer.id", "[:#(type=Integer)]", 12931, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.tube4.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1290, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube4.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12932, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube4.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12933,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12934, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12935,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12936, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12937, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12938, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasB.gasPointer.id", "[:#(type=Integer)]", 12939, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.tube4.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1291, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube4.fixedTInitialWall", "if true, force usage of initial value TInitialWall [:#(type=Boolean)]",\
 12940, false, 0.0,0.0,0.0,0,515)
DeclareAlias2("PF4U.tube4.heatPort[1].T", "Port temperature [K|degC]", \
"PF4U.Channel4.T_wall", 1, 5, 17020, 4)
DeclareAlias2("PF4U.tube4.heatPort[1].Q_flow", "Heat flow rate [W]", \
"PF4U.prescribedHeatFlow3.port.Q_flow", -1, 5, 17291, 132)
DeclareVariable("PF4U.junction1.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12941, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12942,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12943, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12944,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 12945, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12946, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12947, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.simPort.vleFluidMass", "[kg]", 12948, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.simPort.vleFluidVolume", "[m3]", 12949, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.simPort.liquidMass", "[kg]", 12950, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.simPort.liquidVolume", "[m3]", 12951, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.junction1.simPort.gasMass", "[kg]", "PF4U.junction1.mass", 1,\
 5, 17369, 1024)
DeclareAlias2("PF4U.junction1.simPort.gasVolume", "[m3]", "PF4U.junction1.volume", 1,\
 7, 1292, 1024)
DeclareVariable("PF4U.junction1.simPort.dpdt", "", 12952, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.simPort.dpdtCounter", "", 12953, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.junction1.simPort.vleFluidPort.vleFluidMass", \
"Accumulated fluid mass [kg]", 12954, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction1.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 12955, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction1.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 12956, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction1.simPort.liquidPort.liquidVolume", \
"Accumulated liquid volume [m3]", 12957, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.junction1.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.junction1.mass", 1, 5, 17369, 1156)
DeclareAlias2("PF4U.junction1.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.junction1.volume", 1, 7, 1292, 1156)
DeclareVariable("PF4U.junction1.simPort.dpdtPort.dpdt", "", 12958, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.junction1.simPort.dpdtPort.counter", "", 12959, 0.0, \
0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction1.simPort.warningsPort.warnings", "Accumulated warnings",\
 12960, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction1.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 12961, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction1.portA.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12962, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12963,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12964, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.portA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12965,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12966, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12967, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12968, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction1.portA.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.junction1.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4U.tube4.portA.m_flow", -1, 5, 17293, 132)
DeclareAlias2("PF4U.junction1.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction1.h", 1, 1, 110, 4)
DeclareVariable("PF4U.junction1.portB.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12969, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12970,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12971, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.portB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12972,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12973, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12974, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12975, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction1.portB.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.junction1.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.junction2.portA.m_flow", -1, 5, 17141, 132)
DeclareAlias2("PF4U.junction1.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction1.h", 1, 1, 110, 4)
DeclareVariable("PF4U.junction1.portC.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12976, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12977,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12978, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.portC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12979,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12980, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12981, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12982, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction1.portC.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.junction1.portC.m_flow", "Mass flow rate [kg/s]", \
"PF4U.tube3.portA.m_flow", -1, 5, 17227, 132)
DeclareAlias2("PF4U.junction1.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction1.h", 1, 1, 110, 4)
DeclareVariable("PF4U.junction1.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12983, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12984,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12985, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gas.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12986,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gas.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12987, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12988, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12989, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gas.gasPointer.id", "[:#(type=Integer)]", 12990,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.junction1.gas.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 12991,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction1.gas.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 12992, false,\
 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction1.gas.d", "Density [kg/m3|g/cm3]", 17356, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.junction1.gas.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 1024)
DeclareAlias2("PF4U.junction1.gas.der(p)", "der(Pressure) [Pa/s]", \
"PF4U.junction2.der(p)", 1, 6, 103, 1024)
DeclareAlias2("PF4U.junction1.gas.h", "Specific enthalpy [J/kg]", \
"PF4U.junction1.h", 1, 1, 110, 1024)
DeclareAlias2("PF4U.junction1.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"PF4U.junction1.der(h)", 1, 6, 110, 1024)
DeclareVariable("PF4U.junction1.gas.s", "Specific entropy [J/(kg.K)]", 17357, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.T", "Temperature [K|degC]", 17358, 288.15, \
0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.junction1.gas.M", "Average molar mass [kg/mol]", \
"PF4U.junction1.gas.M_i[1]", 1, 5, 12998, 1024)
DeclareVariable("PF4U.junction1.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17359, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17360, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17361, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.kappa", "Isothermal compressibility [1/Pa]",\
 17362, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.w", "Speed of sound [m/s]", 17363, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17364, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17365, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.p_i[1]", "Partial pressure [Pa|bar]", 17366,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.junction1.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17367, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.phi", "Relative humidity", 12993, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 12994, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.junction1.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 12995, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 12996, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 12997, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17368, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.M_i[1]", "Molar mass of component i [kg/mol]",\
 12998, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 12999, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13000, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13001, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.transp.Pr", "Prandtl number [1]", 13002, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13003, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13004,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.transp.sigma", "Surface tension [N/m]", 13005,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.computeFlags", "[:#(type=Integer)]", 13006, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction1.volume", "[m3]", 1292, 0.0001, 0.0,\
1.7976931348623157E+308,0.0,0,560)
DeclareParameter("PF4U.junction1.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1293, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.junction1.pInitial", "Initial value for air pressure [Pa|bar]",\
 1294, 2000000, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.junction1.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13007, false, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.junction1.TInitial", "Initial value for air temperature [K|K]",\
 1295, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.junction1.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1296, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.junction1.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13008, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.junction1.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1297, 1, 0.0,0.0,0.0,0,560)
DeclareState("PF4U.junction1.h", "Specific enthalpy [J/kg]", 110, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("PF4U.junction1.der(h)", "der(Specific enthalpy) [m2/s3]", 110,\
 0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("PF4U.junction1.p", "[Pa|bar]", "PF4U.junction2.p", 1, 1, 103, 0)
DeclareAlias2("PF4U.junction1.der(p)", "[Pa/s]", "PF4U.junction2.der(p)", 1, 6, 103,\
 0)
DeclareVariable("PF4U.junction1.mass", "Gas mass in control volume [kg]", 17369,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.junction1.drhodt", "[Pa.m-2.s]", 17370, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.junction1.hInitial", "[J/kg]", 13009, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13010, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.junction1.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13011, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction1.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13012, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13013,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13014, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13015,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13016, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13017, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13018, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasA.gasPointer.id", "[:#(type=Integer)]", 13019,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction1.gasA.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1298, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction1.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13020, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13021,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13022, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13023,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13024, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13025, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13026, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasB.gasPointer.id", "[:#(type=Integer)]", 13027,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction1.gasB.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1299, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction1.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13028, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13029,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13030, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13031,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13032, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13033, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13034, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasC.gasPointer.id", "[:#(type=Integer)]", 13035,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction1.gasC.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1300, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction3.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13036, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13037,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13038, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13039,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13040, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13041, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13042, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.simPort.vleFluidMass", "[kg]", 13043, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.simPort.vleFluidVolume", "[m3]", 13044, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.simPort.liquidMass", "[kg]", 13045, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.simPort.liquidVolume", "[m3]", 13046, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.junction3.simPort.gasMass", "[kg]", "PF4U.junction3.mass", 1,\
 5, 17384, 1024)
DeclareAlias2("PF4U.junction3.simPort.gasVolume", "[m3]", "PF4U.junction3.volume", 1,\
 7, 1301, 1024)
DeclareVariable("PF4U.junction3.simPort.dpdt", "", 13047, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.simPort.dpdtCounter", "", 13048, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.junction3.simPort.vleFluidPort.vleFluidMass", \
"Accumulated fluid mass [kg]", 13049, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction3.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13050, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction3.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13051, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction3.simPort.liquidPort.liquidVolume", \
"Accumulated liquid volume [m3]", 13052, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.junction3.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.junction3.mass", 1, 5, 17384, 1156)
DeclareAlias2("PF4U.junction3.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.junction3.volume", 1, 7, 1301, 1156)
DeclareVariable("PF4U.junction3.simPort.dpdtPort.dpdt", "", 13053, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.junction3.simPort.dpdtPort.counter", "", 13054, 0.0, \
0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction3.simPort.warningsPort.warnings", "Accumulated warnings",\
 13055, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction3.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13056, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction3.portA.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13057, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13058,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13059, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.portA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13060,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13061, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13062, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13063, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction3.portA.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.junction3.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4U.tube1.portA.m_flow", -1, 5, 17161, 132)
DeclareAlias2("PF4U.junction3.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction3.h", 1, 1, 111, 4)
DeclareVariable("PF4U.junction3.portB.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13064, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13065,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13066, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.portB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13067,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13068, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13069, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13070, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction3.portB.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.junction3.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.junction2.portC.m_flow", -1, 5, 17142, 132)
DeclareAlias2("PF4U.junction3.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction3.h", 1, 1, 111, 4)
DeclareVariable("PF4U.junction3.portC.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13071, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13072,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13073, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.portC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13074,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13075, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13076, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13077, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction3.portC.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.junction3.portC.m_flow", "Mass flow rate [kg/s]", \
"PF4U.tube2.portA.m_flow", -1, 5, 17027, 132)
DeclareAlias2("PF4U.junction3.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction3.h", 1, 1, 111, 4)
DeclareVariable("PF4U.junction3.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13078, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13079,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13080, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gas.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13081,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gas.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13082, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13083, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13084, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gas.gasPointer.id", "[:#(type=Integer)]", 13085,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.junction3.gas.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 13086,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction3.gas.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 13087, false,\
 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction3.gas.d", "Density [kg/m3|g/cm3]", 17371, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.junction3.gas.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 1024)
DeclareAlias2("PF4U.junction3.gas.der(p)", "der(Pressure) [Pa/s]", \
"PF4U.junction2.der(p)", 1, 6, 103, 1024)
DeclareAlias2("PF4U.junction3.gas.h", "Specific enthalpy [J/kg]", \
"PF4U.junction3.h", 1, 1, 111, 1024)
DeclareAlias2("PF4U.junction3.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"PF4U.junction3.der(h)", 1, 6, 111, 1024)
DeclareVariable("PF4U.junction3.gas.s", "Specific entropy [J/(kg.K)]", 17372, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.T", "Temperature [K|degC]", 17373, 288.15, \
0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.junction3.gas.M", "Average molar mass [kg/mol]", \
"PF4U.junction3.gas.M_i[1]", 1, 5, 13093, 1024)
DeclareVariable("PF4U.junction3.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17374, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17375, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17376, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.kappa", "Isothermal compressibility [1/Pa]",\
 17377, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.w", "Speed of sound [m/s]", 17378, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17379, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17380, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.p_i[1]", "Partial pressure [Pa|bar]", 17381,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.junction3.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17382, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.phi", "Relative humidity", 13088, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13089, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.junction3.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13090, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13091, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13092, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17383, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.M_i[1]", "Molar mass of component i [kg/mol]",\
 13093, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13094, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13095, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13096, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.transp.Pr", "Prandtl number [1]", 13097, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13098, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13099,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.transp.sigma", "Surface tension [N/m]", 13100,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.computeFlags", "[:#(type=Integer)]", 13101, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction3.volume", "[m3]", 1301, 0.0001, 0.0,\
1.7976931348623157E+308,0.0,0,560)
DeclareParameter("PF4U.junction3.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1302, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.junction3.pInitial", "Initial value for air pressure [Pa|bar]",\
 1303, 2000000, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.junction3.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13102, false, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.junction3.TInitial", "Initial value for air temperature [K|K]",\
 1304, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.junction3.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1305, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.junction3.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13103, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.junction3.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1306, 1, 0.0,0.0,0.0,0,560)
DeclareState("PF4U.junction3.h", "Specific enthalpy [J/kg]", 111, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("PF4U.junction3.der(h)", "der(Specific enthalpy) [m2/s3]", 111,\
 0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("PF4U.junction3.p", "[Pa|bar]", "PF4U.junction2.p", 1, 1, 103, 0)
DeclareAlias2("PF4U.junction3.der(p)", "[Pa/s]", "PF4U.junction2.der(p)", 1, 6, 103,\
 0)
DeclareVariable("PF4U.junction3.mass", "Gas mass in control volume [kg]", 17384,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.junction3.drhodt", "[Pa.m-2.s]", 17385, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.junction3.hInitial", "[J/kg]", 13104, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13105, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.junction3.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13106, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction3.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13107, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13108,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13109, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13110,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13111, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13112, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13113, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasA.gasPointer.id", "[:#(type=Integer)]", 13114,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction3.gasA.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1307, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction3.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13115, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13116,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13117, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13118,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13119, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13120, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13121, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasB.gasPointer.id", "[:#(type=Integer)]", 13122,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction3.gasB.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1308, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction3.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13123, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13124,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13125, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13126,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13127, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13128, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13129, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasC.gasPointer.id", "[:#(type=Integer)]", 13130,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction3.gasC.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1309, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction4.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13131, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13132,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13133, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13134,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13135, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13136, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13137, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.simPort.vleFluidMass", "[kg]", 13138, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.simPort.vleFluidVolume", "[m3]", 13139, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.simPort.liquidMass", "[kg]", 13140, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.simPort.liquidVolume", "[m3]", 13141, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.junction4.simPort.gasMass", "[kg]", "PF4U.junction4.mass", 1,\
 5, 17400, 1024)
DeclareAlias2("PF4U.junction4.simPort.gasVolume", "[m3]", "PF4U.junction4.volume", 1,\
 7, 1310, 1024)
DeclareVariable("PF4U.junction4.simPort.dpdt", "", 13142, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.simPort.dpdtCounter", "", 13143, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.junction4.simPort.vleFluidPort.vleFluidMass", \
"Accumulated fluid mass [kg]", 13144, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction4.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13145, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction4.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13146, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction4.simPort.liquidPort.liquidVolume", \
"Accumulated liquid volume [m3]", 13147, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.junction4.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.junction4.mass", 1, 5, 17400, 1156)
DeclareAlias2("PF4U.junction4.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.junction4.volume", 1, 7, 1310, 1156)
DeclareVariable("PF4U.junction4.simPort.dpdtPort.dpdt", "", 13148, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.junction4.simPort.dpdtPort.counter", "", 13149, 0.0, \
0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction4.simPort.warningsPort.warnings", "Accumulated warnings",\
 13150, 0.0, 0.0,0.0,0.0,0,2825)
EndNonAlias(15)
PreNonAliasNew(16)
StartNonAlias(16)
DeclareVariable("PF4U.junction4.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13151, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction4.portA.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13152, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13153,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13154, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.portA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13155,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13156, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13157, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13158, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction4.portA.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareAlias2("PF4U.junction4.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4U.Channel1.m_flow", -1, 5, 17011, 132)
DeclareAlias2("PF4U.junction4.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction4.h", 1, 1, 112, 4)
DeclareVariable("PF4U.junction4.portB.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13159, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13160,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13161, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.portB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13162,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13163, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13164, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13165, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction4.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareVariable("PF4U.junction4.portB.m_flow", "Mass flow rate [kg/s]", 17386, \
0.0, 0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.junction4.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction4.h", 1, 1, 112, 4)
DeclareVariable("PF4U.junction4.portC.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13166, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13167,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13168, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.portC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13169,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13170, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13171, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13172, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction4.portC.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareAlias2("PF4U.junction4.portC.m_flow", "Mass flow rate [kg/s]", \
"PF4U.Channel2.m_flow", -1, 5, 17015, 132)
DeclareAlias2("PF4U.junction4.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction4.h", 1, 1, 112, 4)
DeclareVariable("PF4U.junction4.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13173, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13174,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13175, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gas.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13176,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gas.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13177, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13178, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13179, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gas.gasPointer.id", "[:#(type=Integer)]", 13180,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.junction4.gas.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 13181,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction4.gas.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 13182, false,\
 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction4.gas.d", "Density [kg/m3|g/cm3]", 17387, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.junction4.gas.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 1024)
DeclareAlias2("PF4U.junction4.gas.der(p)", "der(Pressure) [Pa/s]", \
"PF2U.tube2.der(p[1])", 1, 6, 18, 1024)
DeclareAlias2("PF4U.junction4.gas.h", "Specific enthalpy [J/kg]", \
"PF4U.junction4.h", 1, 1, 112, 1024)
DeclareAlias2("PF4U.junction4.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"PF4U.junction4.der(h)", 1, 6, 112, 1024)
DeclareVariable("PF4U.junction4.gas.s", "Specific entropy [J/(kg.K)]", 17388, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.T", "Temperature [K|degC]", 17389, 288.15, \
0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.junction4.gas.M", "Average molar mass [kg/mol]", \
"PF4U.junction4.gas.M_i[1]", 1, 5, 13188, 1024)
DeclareVariable("PF4U.junction4.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17390, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17391, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17392, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.kappa", "Isothermal compressibility [1/Pa]",\
 17393, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.w", "Speed of sound [m/s]", 17394, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17395, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17396, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.p_i[1]", "Partial pressure [Pa|bar]", 17397,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.junction4.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17398, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.phi", "Relative humidity", 13183, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13184, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.junction4.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13185, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13186, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13187, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17399, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.M_i[1]", "Molar mass of component i [kg/mol]",\
 13188, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13189, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13190, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13191, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.transp.Pr", "Prandtl number [1]", 13192, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13193, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13194,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.transp.sigma", "Surface tension [N/m]", 13195,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.computeFlags", "[:#(type=Integer)]", 13196, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction4.volume", "[m3]", 1310, 0.0001, 0.0,\
1.7976931348623157E+308,0.0,0,560)
DeclareParameter("PF4U.junction4.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1311, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.junction4.pInitial", "Initial value for air pressure [Pa|bar]",\
 1312, 2000000, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.junction4.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13197, false, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.junction4.TInitial", "Initial value for air temperature [K|K]",\
 1313, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.junction4.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1314, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.junction4.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13198, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.junction4.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1315, 1, 0.0,0.0,0.0,0,560)
DeclareState("PF4U.junction4.h", "Specific enthalpy [J/kg]", 112, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("PF4U.junction4.der(h)", "der(Specific enthalpy) [m2/s3]", 112,\
 0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("PF4U.junction4.p", "[Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.junction4.der(p)", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18,\
 0)
DeclareVariable("PF4U.junction4.mass", "Gas mass in control volume [kg]", 17400,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.junction4.drhodt", "[Pa.m-2.s]", 17401, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.junction4.hInitial", "[J/kg]", 13199, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13200, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.junction4.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13201, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction4.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13202, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13203,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13204, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13205,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13206, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13207, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13208, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasA.gasPointer.id", "[:#(type=Integer)]", 13209,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction4.gasA.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1316, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction4.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13210, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13211,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13212, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13213,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13214, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13215, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13216, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasB.gasPointer.id", "[:#(type=Integer)]", 13217,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction4.gasB.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1317, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction4.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13218, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13219,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13220, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13221,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13222, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13223, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13224, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasC.gasPointer.id", "[:#(type=Integer)]", 13225,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction4.gasC.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1318, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction5.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13226, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13227,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13228, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13229,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13230, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13231, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13232, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.simPort.vleFluidMass", "[kg]", 13233, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.simPort.vleFluidVolume", "[m3]", 13234, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.simPort.liquidMass", "[kg]", 13235, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.simPort.liquidVolume", "[m3]", 13236, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.junction5.simPort.gasMass", "[kg]", "PF4U.junction5.mass", 1,\
 5, 17416, 1024)
DeclareAlias2("PF4U.junction5.simPort.gasVolume", "[m3]", "PF4U.junction5.volume", 1,\
 7, 1319, 1024)
DeclareVariable("PF4U.junction5.simPort.dpdt", "", 13237, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.simPort.dpdtCounter", "", 13238, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.junction5.simPort.vleFluidPort.vleFluidMass", \
"Accumulated fluid mass [kg]", 13239, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction5.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13240, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction5.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13241, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction5.simPort.liquidPort.liquidVolume", \
"Accumulated liquid volume [m3]", 13242, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.junction5.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.junction5.mass", 1, 5, 17416, 1156)
DeclareAlias2("PF4U.junction5.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.junction5.volume", 1, 7, 1319, 1156)
DeclareVariable("PF4U.junction5.simPort.dpdtPort.dpdt", "", 13243, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.junction5.simPort.dpdtPort.counter", "", 13244, 0.0, \
0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction5.simPort.warningsPort.warnings", "Accumulated warnings",\
 13245, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction5.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13246, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction5.portA.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13247, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13248,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13249, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.portA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13250,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13251, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13252, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13253, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction5.portA.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareAlias2("PF4U.junction5.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4U.Channel3.m_flow", -1, 5, 17019, 132)
DeclareAlias2("PF4U.junction5.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction5.h", 1, 1, 113, 4)
DeclareVariable("PF4U.junction5.portB.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13254, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13255,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13256, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.portB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13257,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13258, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13259, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13260, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction5.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareVariable("PF4U.junction5.portB.m_flow", "Mass flow rate [kg/s]", 17402, \
0.0, 0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.junction5.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction5.h", 1, 1, 113, 4)
DeclareVariable("PF4U.junction5.portC.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13261, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13262,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13263, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.portC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13264,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13265, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13266, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13267, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction5.portC.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareAlias2("PF4U.junction5.portC.m_flow", "Mass flow rate [kg/s]", \
"PF4U.Channel4.m_flow", -1, 5, 17023, 132)
DeclareAlias2("PF4U.junction5.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction5.h", 1, 1, 113, 4)
DeclareVariable("PF4U.junction5.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13268, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13269,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13270, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gas.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13271,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gas.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13272, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13273, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13274, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gas.gasPointer.id", "[:#(type=Integer)]", 13275,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.junction5.gas.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 13276,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction5.gas.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 13277, false,\
 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction5.gas.d", "Density [kg/m3|g/cm3]", 17403, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.junction5.gas.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 1024)
DeclareAlias2("PF4U.junction5.gas.der(p)", "der(Pressure) [Pa/s]", \
"PF2U.tube2.der(p[1])", 1, 6, 18, 1024)
DeclareAlias2("PF4U.junction5.gas.h", "Specific enthalpy [J/kg]", \
"PF4U.junction5.h", 1, 1, 113, 1024)
DeclareAlias2("PF4U.junction5.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"PF4U.junction5.der(h)", 1, 6, 113, 1024)
DeclareVariable("PF4U.junction5.gas.s", "Specific entropy [J/(kg.K)]", 17404, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.T", "Temperature [K|degC]", 17405, 288.15, \
0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.junction5.gas.M", "Average molar mass [kg/mol]", \
"PF4U.junction5.gas.M_i[1]", 1, 5, 13283, 1024)
DeclareVariable("PF4U.junction5.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17406, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17407, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17408, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.kappa", "Isothermal compressibility [1/Pa]",\
 17409, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.w", "Speed of sound [m/s]", 17410, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17411, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17412, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.p_i[1]", "Partial pressure [Pa|bar]", 17413,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.junction5.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17414, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.phi", "Relative humidity", 13278, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13279, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.junction5.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13280, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13281, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13282, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17415, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.M_i[1]", "Molar mass of component i [kg/mol]",\
 13283, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13284, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13285, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13286, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.transp.Pr", "Prandtl number [1]", 13287, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13288, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13289,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.transp.sigma", "Surface tension [N/m]", 13290,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.computeFlags", "[:#(type=Integer)]", 13291, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction5.volume", "[m3]", 1319, 0.0001, 0.0,\
1.7976931348623157E+308,0.0,0,560)
DeclareParameter("PF4U.junction5.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1320, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.junction5.pInitial", "Initial value for air pressure [Pa|bar]",\
 1321, 2000000, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.junction5.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13292, false, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.junction5.TInitial", "Initial value for air temperature [K|K]",\
 1322, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.junction5.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1323, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.junction5.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13293, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.junction5.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1324, 1, 0.0,0.0,0.0,0,560)
DeclareState("PF4U.junction5.h", "Specific enthalpy [J/kg]", 113, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("PF4U.junction5.der(h)", "der(Specific enthalpy) [m2/s3]", 113,\
 0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("PF4U.junction5.p", "[Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.junction5.der(p)", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18,\
 0)
DeclareVariable("PF4U.junction5.mass", "Gas mass in control volume [kg]", 17416,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.junction5.drhodt", "[Pa.m-2.s]", 17417, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.junction5.hInitial", "[J/kg]", 13294, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13295, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.junction5.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13296, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction5.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13297, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13298,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13299, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13300,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13301, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13302, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13303, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasA.gasPointer.id", "[:#(type=Integer)]", 13304,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction5.gasA.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1325, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction5.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13305, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13306,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13307, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13308,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13309, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13310, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13311, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasB.gasPointer.id", "[:#(type=Integer)]", 13312,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction5.gasB.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1326, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction5.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13313, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13314,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13315, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13316,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13317, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13318, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13319, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasC.gasPointer.id", "[:#(type=Integer)]", 13320,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction5.gasC.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1327, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction6.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13321, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13322,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13323, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13324,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13325, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13326, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13327, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.simPort.vleFluidMass", "[kg]", 13328, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.simPort.vleFluidVolume", "[m3]", 13329, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.simPort.liquidMass", "[kg]", 13330, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.simPort.liquidVolume", "[m3]", 13331, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.junction6.simPort.gasMass", "[kg]", "PF4U.junction6.mass", 1,\
 5, 17431, 1024)
DeclareAlias2("PF4U.junction6.simPort.gasVolume", "[m3]", "PF4U.junction6.volume", 1,\
 7, 1328, 1024)
DeclareVariable("PF4U.junction6.simPort.dpdt", "", 13332, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.simPort.dpdtCounter", "", 13333, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.junction6.simPort.vleFluidPort.vleFluidMass", \
"Accumulated fluid mass [kg]", 13334, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction6.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13335, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction6.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13336, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction6.simPort.liquidPort.liquidVolume", \
"Accumulated liquid volume [m3]", 13337, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.junction6.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.junction6.mass", 1, 5, 17431, 1156)
DeclareAlias2("PF4U.junction6.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.junction6.volume", 1, 7, 1328, 1156)
DeclareVariable("PF4U.junction6.simPort.dpdtPort.dpdt", "", 13338, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.junction6.simPort.dpdtPort.counter", "", 13339, 0.0, \
0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction6.simPort.warningsPort.warnings", "Accumulated warnings",\
 13340, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction6.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13341, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction6.portA.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13342, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13343,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13344, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.portA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13345,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13346, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13347, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13348, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction6.portA.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareAlias2("PF4U.junction6.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4U.junction4.portB.m_flow", -1, 5, 17386, 132)
DeclareAlias2("PF4U.junction6.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction6.h", 1, 1, 114, 4)
DeclareVariable("PF4U.junction6.portB.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13349, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13350,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13351, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.portB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13352,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13353, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13354, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13355, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction6.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareAlias2("PF4U.junction6.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.portB1.m_flow", 1, 5, 17140, 132)
DeclareAlias2("PF4U.junction6.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction6.h", 1, 1, 114, 4)
DeclareVariable("PF4U.junction6.portC.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13356, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13357,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13358, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.portC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13359,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13360, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13361, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13362, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction6.portC.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareAlias2("PF4U.junction6.portC.m_flow", "Mass flow rate [kg/s]", \
"PF4U.junction5.portB.m_flow", -1, 5, 17402, 132)
DeclareAlias2("PF4U.junction6.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction6.h", 1, 1, 114, 4)
DeclareVariable("PF4U.junction6.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13363, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13364,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13365, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gas.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13366,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gas.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13367, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13368, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13369, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gas.gasPointer.id", "[:#(type=Integer)]", 13370,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.junction6.gas.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 13371,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction6.gas.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 13372, false,\
 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction6.gas.d", "Density [kg/m3|g/cm3]", 17418, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.junction6.gas.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 1024)
DeclareAlias2("PF4U.junction6.gas.der(p)", "der(Pressure) [Pa/s]", \
"PF2U.tube2.der(p[1])", 1, 6, 18, 1024)
DeclareAlias2("PF4U.junction6.gas.h", "Specific enthalpy [J/kg]", \
"PF4U.junction6.h", 1, 1, 114, 1024)
DeclareAlias2("PF4U.junction6.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"PF4U.junction6.der(h)", 1, 6, 114, 1024)
DeclareVariable("PF4U.junction6.gas.s", "Specific entropy [J/(kg.K)]", 17419, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.T", "Temperature [K|degC]", 17420, 288.15, \
0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.junction6.gas.M", "Average molar mass [kg/mol]", \
"PF4U.junction6.gas.M_i[1]", 1, 5, 13378, 1024)
DeclareVariable("PF4U.junction6.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17421, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17422, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17423, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.kappa", "Isothermal compressibility [1/Pa]",\
 17424, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.w", "Speed of sound [m/s]", 17425, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17426, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17427, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.p_i[1]", "Partial pressure [Pa|bar]", 17428,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.junction6.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17429, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.phi", "Relative humidity", 13373, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13374, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.junction6.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13375, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13376, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13377, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17430, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.M_i[1]", "Molar mass of component i [kg/mol]",\
 13378, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13379, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13380, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13381, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.transp.Pr", "Prandtl number [1]", 13382, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13383, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13384,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.transp.sigma", "Surface tension [N/m]", 13385,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.computeFlags", "[:#(type=Integer)]", 13386, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction6.volume", "[m3]", 1328, 0.0001, 0.0,\
1.7976931348623157E+308,0.0,0,560)
DeclareParameter("PF4U.junction6.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1329, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.junction6.pInitial", "Initial value for air pressure [Pa|bar]",\
 1330, 2000000, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.junction6.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13387, false, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.junction6.TInitial", "Initial value for air temperature [K|K]",\
 1331, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.junction6.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1332, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.junction6.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13388, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.junction6.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1333, 1, 0.0,0.0,0.0,0,560)
DeclareState("PF4U.junction6.h", "Specific enthalpy [J/kg]", 114, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("PF4U.junction6.der(h)", "der(Specific enthalpy) [m2/s3]", 114,\
 0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("PF4U.junction6.p", "[Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.junction6.der(p)", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18,\
 0)
DeclareVariable("PF4U.junction6.mass", "Gas mass in control volume [kg]", 17431,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.junction6.drhodt", "[Pa.m-2.s]", 17432, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.junction6.hInitial", "[J/kg]", 13389, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13390, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.junction6.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13391, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction6.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13392, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13393,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13394, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13395,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13396, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13397, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13398, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasA.gasPointer.id", "[:#(type=Integer)]", 13399,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction6.gasA.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1334, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction6.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13400, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13401,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13402, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13403,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13404, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13405, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13406, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasB.gasPointer.id", "[:#(type=Integer)]", 13407,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction6.gasB.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1335, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction6.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13408, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13409,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13410, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13411,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13412, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13413, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13414, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasC.gasPointer.id", "[:#(type=Integer)]", 13415,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction6.gasC.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1336, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("junction12.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13416, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 13417, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13418, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13419,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13420, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13421, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13422, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.simPort.vleFluidMass", "[kg]", 13423, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction12.simPort.vleFluidVolume", "[m3]", 13424, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.simPort.liquidMass", "[kg]", 13425, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction12.simPort.liquidVolume", "[m3]", 13426, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction12.simPort.gasMass", "[kg]", "junction12.mass", 1, 5, 17449,\
 1024)
DeclareAlias2("junction12.simPort.gasVolume", "[m3]", "junction12.volume", 1, 7,\
 1337, 1024)
DeclareVariable("junction12.simPort.dpdt", "", 13427, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.simPort.dpdtCounter", "", 13428, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 13429, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction12.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13430, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction12.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13431, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction12.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 13432, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction12.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction12.mass", 1, 5, 17449, 1156)
DeclareAlias2("junction12.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction12.volume", 1, 7, 1337, 1156)
DeclareVariable("junction12.simPort.dpdtPort.dpdt", "", 13433, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction12.simPort.dpdtPort.counter", "", 13434, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction12.simPort.warningsPort.warnings", "Accumulated warnings",\
 13435, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction12.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13436, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction12.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13437, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13438,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13439, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13440,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13441, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13442, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13443, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction12.portA.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareVariable("junction12.portA.m_flow", "Mass flow rate [kg/s]", 17433, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("junction12.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction12.h", 1, 1, 115, 4)
DeclareVariable("junction12.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13444, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13445,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13446, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13447,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13448, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13449, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13450, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction12.portB.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareVariable("junction12.portB.m_flow", "Mass flow rate [kg/s]", 17434, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("junction12.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction12.h", 1, 1, 115, 4)
DeclareVariable("junction12.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13451, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13452,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13453, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13454,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13455, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13456, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13457, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction12.portC.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareVariable("junction12.portC.m_flow", "Mass flow rate [kg/s]", 17435, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("junction12.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction12.h", 1, 1, 115, 4)
DeclareVariable("junction12.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13458, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13459,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13460, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13461,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13462, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13463, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13464, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gas.gasPointer.id", "[:#(type=Integer)]", 13465, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction12.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 13466, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction12.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 13467, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction12.gas.d", "Density [kg/m3|g/cm3]", 17436, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction12.gas.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 1024)
DeclareAlias2("junction12.gas.der(p)", "der(Pressure) [Pa/s]", "tube1.der(p[1])", 1,\
 6, 1, 1024)
DeclareAlias2("junction12.gas.h", "Specific enthalpy [J/kg]", "junction12.h", 1,\
 1, 115, 1024)
DeclareAlias2("junction12.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction12.der(h)", 1, 6, 115, 1024)
DeclareVariable("junction12.gas.s", "Specific entropy [J/(kg.K)]", 17437, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.T", "Temperature [K|degC]", 17438, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction12.gas.M", "Average molar mass [kg/mol]", \
"junction12.gas.M_i[1]", 1, 5, 13473, 1024)
DeclareVariable("junction12.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17439, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17440, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17441, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.kappa", "Isothermal compressibility [1/Pa]", 17442,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.w", "Speed of sound [m/s]", 17443, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction12.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17444, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17445, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.p_i[1]", "Partial pressure [Pa|bar]", 17446, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction12.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17447, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction12.gas.phi", "Relative humidity", 13468, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction12.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13469, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction12.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13470, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction12.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13471, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13472, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17448, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.M_i[1]", "Molar mass of component i [kg/mol]", 13473,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction12.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13474, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13475, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13476, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.transp.Pr", "Prandtl number [1]", 13477, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13478, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13479, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction12.gas.transp.sigma", "Surface tension [N/m]", 13480, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.computeFlags", "[:#(type=Integer)]", 13481, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction12.volume", "[m3]", 1337, 0.0001, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction12.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1338, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction12.pInitial", "Initial value for air pressure [Pa|bar]",\
 1339, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction12.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13482, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction12.TInitial", "Initial value for air temperature [K|K]",\
 1340, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction12.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1341, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction12.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13483, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction12.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1342, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction12.h", "Specific enthalpy [J/kg]", 115, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction12.der(h)", "der(Specific enthalpy) [m2/s3]", 115, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction12.p", "[Pa|bar]", "tube1.p[1]", 1, 1, 1, 0)
DeclareAlias2("junction12.der(p)", "[Pa/s]", "tube1.der(p[1])", 1, 6, 1, 0)
DeclareVariable("junction12.mass", "Gas mass in control volume [kg]", 17449, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction12.drhodt", "[Pa.m-2.s]", 17450, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction12.hInitial", "[J/kg]", 13484, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13485, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction12.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13486, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction12.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13487, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13488,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13489, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13490,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13491, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13492, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13493, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasA.gasPointer.id", "[:#(type=Integer)]", 13494, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction12.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1343, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction12.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13495, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13496,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13497, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13498,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13499, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13500, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13501, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasB.gasPointer.id", "[:#(type=Integer)]", 13502, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction12.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1344, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction12.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13503, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13504,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13505, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13506,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13507, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13508, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13509, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasC.gasPointer.id", "[:#(type=Integer)]", 13510, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction12.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1345, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction13.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13511, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 13512, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13513, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13514,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13515, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13516, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13517, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.simPort.vleFluidMass", "[kg]", 13518, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction13.simPort.vleFluidVolume", "[m3]", 13519, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.simPort.liquidMass", "[kg]", 13520, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction13.simPort.liquidVolume", "[m3]", 13521, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction13.simPort.gasMass", "[kg]", "junction13.mass", 1, 5, 17464,\
 1024)
DeclareAlias2("junction13.simPort.gasVolume", "[m3]", "junction13.volume", 1, 7,\
 1346, 1024)
DeclareVariable("junction13.simPort.dpdt", "", 13522, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.simPort.dpdtCounter", "", 13523, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 13524, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction13.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13525, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction13.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13526, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction13.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 13527, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction13.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction13.mass", 1, 5, 17464, 1156)
DeclareAlias2("junction13.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction13.volume", 1, 7, 1346, 1156)
DeclareVariable("junction13.simPort.dpdtPort.dpdt", "", 13528, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction13.simPort.dpdtPort.counter", "", 13529, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction13.simPort.warningsPort.warnings", "Accumulated warnings",\
 13530, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction13.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13531, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction13.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13532, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13533,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13534, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13535,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13536, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13537, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13538, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction13.portA.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction13.portA.m_flow", "Mass flow rate [kg/s]", \
"PF3U.portA1.m_flow", -1, 5, 16387, 132)
DeclareAlias2("junction13.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction13.h", 1, 1, 116, 4)
DeclareVariable("junction13.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13539, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13540,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13541, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13542,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13543, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13544, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13545, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction13.portB.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction13.portB.m_flow", "Mass flow rate [kg/s]", \
"junction12.portC.m_flow", -1, 5, 17435, 132)
DeclareAlias2("junction13.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction13.h", 1, 1, 116, 4)
DeclareVariable("junction13.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13546, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13547,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13548, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13549,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13550, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13551, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13552, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction13.portC.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction13.portC.m_flow", "Mass flow rate [kg/s]", \
"PF3L.portA1.m_flow", -1, 5, 16064, 132)
DeclareAlias2("junction13.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction13.h", 1, 1, 116, 4)
DeclareVariable("junction13.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13553, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13554,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13555, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13556,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13557, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13558, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13559, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gas.gasPointer.id", "[:#(type=Integer)]", 13560, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction13.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 13561, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction13.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 13562, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction13.gas.d", "Density [kg/m3|g/cm3]", 17451, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction13.gas.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 1024)
DeclareAlias2("junction13.gas.der(p)", "der(Pressure) [Pa/s]", "tube1.der(p[1])", 1,\
 6, 1, 1024)
DeclareAlias2("junction13.gas.h", "Specific enthalpy [J/kg]", "junction13.h", 1,\
 1, 116, 1024)
DeclareAlias2("junction13.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction13.der(h)", 1, 6, 116, 1024)
DeclareVariable("junction13.gas.s", "Specific entropy [J/(kg.K)]", 17452, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.T", "Temperature [K|degC]", 17453, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction13.gas.M", "Average molar mass [kg/mol]", \
"junction13.gas.M_i[1]", 1, 5, 13568, 1024)
DeclareVariable("junction13.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17454, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17455, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17456, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.kappa", "Isothermal compressibility [1/Pa]", 17457,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.w", "Speed of sound [m/s]", 17458, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction13.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17459, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17460, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.p_i[1]", "Partial pressure [Pa|bar]", 17461, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction13.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17462, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction13.gas.phi", "Relative humidity", 13563, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction13.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13564, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction13.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13565, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction13.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13566, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13567, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17463, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.M_i[1]", "Molar mass of component i [kg/mol]", 13568,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction13.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13569, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13570, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13571, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.transp.Pr", "Prandtl number [1]", 13572, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13573, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13574, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction13.gas.transp.sigma", "Surface tension [N/m]", 13575, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.computeFlags", "[:#(type=Integer)]", 13576, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction13.volume", "[m3]", 1346, 0.0001, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction13.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1347, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction13.pInitial", "Initial value for air pressure [Pa|bar]",\
 1348, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction13.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13577, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction13.TInitial", "Initial value for air temperature [K|K]",\
 1349, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction13.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1350, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction13.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13578, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction13.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1351, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction13.h", "Specific enthalpy [J/kg]", 116, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction13.der(h)", "der(Specific enthalpy) [m2/s3]", 116, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction13.p", "[Pa|bar]", "tube1.p[1]", 1, 1, 1, 0)
DeclareAlias2("junction13.der(p)", "[Pa/s]", "tube1.der(p[1])", 1, 6, 1, 0)
DeclareVariable("junction13.mass", "Gas mass in control volume [kg]", 17464, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction13.drhodt", "[Pa.m-2.s]", 17465, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction13.hInitial", "[J/kg]", 13579, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13580, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction13.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13581, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction13.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13582, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13583,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13584, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13585,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13586, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13587, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13588, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasA.gasPointer.id", "[:#(type=Integer)]", 13589, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction13.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1352, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction13.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13590, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13591,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13592, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13593,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13594, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13595, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13596, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasB.gasPointer.id", "[:#(type=Integer)]", 13597, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction13.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1353, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction13.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13598, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13599,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13600, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13601,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13602, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13603, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13604, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasC.gasPointer.id", "[:#(type=Integer)]", 13605, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction13.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1354, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction14.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13606, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 13607, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13608, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13609,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13610, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13611, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13612, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.simPort.vleFluidMass", "[kg]", 13613, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction14.simPort.vleFluidVolume", "[m3]", 13614, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.simPort.liquidMass", "[kg]", 13615, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction14.simPort.liquidVolume", "[m3]", 13616, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction14.simPort.gasMass", "[kg]", "junction14.mass", 1, 5, 17479,\
 1024)
DeclareAlias2("junction14.simPort.gasVolume", "[m3]", "junction14.volume", 1, 7,\
 1355, 1024)
DeclareVariable("junction14.simPort.dpdt", "", 13617, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.simPort.dpdtCounter", "", 13618, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 13619, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction14.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13620, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction14.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13621, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction14.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 13622, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction14.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction14.mass", 1, 5, 17479, 1156)
DeclareAlias2("junction14.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction14.volume", 1, 7, 1355, 1156)
DeclareVariable("junction14.simPort.dpdtPort.dpdt", "", 13623, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction14.simPort.dpdtPort.counter", "", 13624, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction14.simPort.warningsPort.warnings", "Accumulated warnings",\
 13625, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction14.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13626, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction14.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13627, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13628,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13629, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13630,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13631, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13632, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13633, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction14.portA.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction14.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4U.portA1.m_flow", -1, 5, 17139, 132)
DeclareAlias2("junction14.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction14.h", 1, 1, 117, 4)
DeclareVariable("junction14.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13634, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13635,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13636, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13637,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13638, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13639, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13640, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction14.portB.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction14.portB.m_flow", "Mass flow rate [kg/s]", \
"junction12.portA.m_flow", -1, 5, 17433, 132)
DeclareAlias2("junction14.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction14.h", 1, 1, 117, 4)
DeclareVariable("junction14.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13641, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13642,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13643, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13644,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13645, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13646, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13647, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction14.portC.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction14.portC.m_flow", "Mass flow rate [kg/s]", \
"PF4L.portA1.m_flow", -1, 5, 16714, 132)
DeclareAlias2("junction14.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction14.h", 1, 1, 117, 4)
DeclareVariable("junction14.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13648, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13649,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13650, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13651,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13652, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13653, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13654, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gas.gasPointer.id", "[:#(type=Integer)]", 13655, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction14.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 13656, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction14.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 13657, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction14.gas.d", "Density [kg/m3|g/cm3]", 17466, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction14.gas.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 1024)
DeclareAlias2("junction14.gas.der(p)", "der(Pressure) [Pa/s]", "tube1.der(p[1])", 1,\
 6, 1, 1024)
DeclareAlias2("junction14.gas.h", "Specific enthalpy [J/kg]", "junction14.h", 1,\
 1, 117, 1024)
DeclareAlias2("junction14.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction14.der(h)", 1, 6, 117, 1024)
DeclareVariable("junction14.gas.s", "Specific entropy [J/(kg.K)]", 17467, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.T", "Temperature [K|degC]", 17468, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction14.gas.M", "Average molar mass [kg/mol]", \
"junction14.gas.M_i[1]", 1, 5, 13663, 1024)
DeclareVariable("junction14.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17469, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17470, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17471, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.kappa", "Isothermal compressibility [1/Pa]", 17472,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.w", "Speed of sound [m/s]", 17473, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction14.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17474, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17475, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.p_i[1]", "Partial pressure [Pa|bar]", 17476, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction14.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17477, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction14.gas.phi", "Relative humidity", 13658, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction14.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13659, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction14.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13660, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction14.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13661, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13662, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17478, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.M_i[1]", "Molar mass of component i [kg/mol]", 13663,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction14.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13664, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13665, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13666, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.transp.Pr", "Prandtl number [1]", 13667, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13668, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13669, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction14.gas.transp.sigma", "Surface tension [N/m]", 13670, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.computeFlags", "[:#(type=Integer)]", 13671, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction14.volume", "[m3]", 1355, 0.0001, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction14.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1356, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction14.pInitial", "Initial value for air pressure [Pa|bar]",\
 1357, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction14.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13672, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction14.TInitial", "Initial value for air temperature [K|K]",\
 1358, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction14.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1359, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction14.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13673, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction14.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1360, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction14.h", "Specific enthalpy [J/kg]", 117, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction14.der(h)", "der(Specific enthalpy) [m2/s3]", 117, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction14.p", "[Pa|bar]", "tube1.p[1]", 1, 1, 1, 0)
DeclareAlias2("junction14.der(p)", "[Pa/s]", "tube1.der(p[1])", 1, 6, 1, 0)
DeclareVariable("junction14.mass", "Gas mass in control volume [kg]", 17479, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction14.drhodt", "[Pa.m-2.s]", 17480, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction14.hInitial", "[J/kg]", 13674, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13675, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction14.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13676, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction14.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13677, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13678,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13679, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13680,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13681, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13682, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13683, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasA.gasPointer.id", "[:#(type=Integer)]", 13684, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction14.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1361, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction14.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13685, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13686,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13687, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13688,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13689, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13690, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13691, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasB.gasPointer.id", "[:#(type=Integer)]", 13692, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction14.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1362, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction14.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13693, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13694,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13695, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13696,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13697, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13698, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13699, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasC.gasPointer.id", "[:#(type=Integer)]", 13700, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction14.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1363, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction15.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13701, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 13702, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13703, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13704,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13705, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13706, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13707, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.simPort.vleFluidMass", "[kg]", 13708, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction15.simPort.vleFluidVolume", "[m3]", 13709, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.simPort.liquidMass", "[kg]", 13710, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction15.simPort.liquidVolume", "[m3]", 13711, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction15.simPort.gasMass", "[kg]", "junction15.mass", 1, 5, 17495,\
 1024)
DeclareAlias2("junction15.simPort.gasVolume", "[m3]", "junction15.volume", 1, 7,\
 1364, 1024)
DeclareVariable("junction15.simPort.dpdt", "", 13712, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.simPort.dpdtCounter", "", 13713, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 13714, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction15.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13715, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction15.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13716, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction15.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 13717, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction15.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction15.mass", 1, 5, 17495, 1156)
DeclareAlias2("junction15.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction15.volume", 1, 7, 1364, 1156)
DeclareVariable("junction15.simPort.dpdtPort.dpdt", "", 13718, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction15.simPort.dpdtPort.counter", "", 13719, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction15.simPort.warningsPort.warnings", "Accumulated warnings",\
 13720, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction15.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13721, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction15.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13722, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13723,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13724, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13725,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13726, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13727, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13728, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction15.portA.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction15.portA.m_flow", "Mass flow rate [kg/s]", \
"PF3L.portB1.m_flow", -1, 5, 16065, 132)
DeclareAlias2("junction15.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction15.h", 1, 1, 118, 4)
DeclareVariable("junction15.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13729, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13730,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13731, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13732,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13733, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13734, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13735, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction15.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareVariable("junction15.portB.m_flow", "Mass flow rate [kg/s]", 17481, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("junction15.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction15.h", 1, 1, 118, 4)
DeclareVariable("junction15.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13736, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13737,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13738, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13739,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13740, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13741, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13742, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction15.portC.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction15.portC.m_flow", "Mass flow rate [kg/s]", \
"PF3U.portB1.m_flow", -1, 5, 16388, 132)
DeclareAlias2("junction15.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction15.h", 1, 1, 118, 4)
DeclareVariable("junction15.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13743, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13744,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13745, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13746,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13747, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13748, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13749, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gas.gasPointer.id", "[:#(type=Integer)]", 13750, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction15.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 13751, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction15.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 13752, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction15.gas.d", "Density [kg/m3|g/cm3]", 17482, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction15.gas.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18,\
 1024)
DeclareAlias2("junction15.gas.der(p)", "der(Pressure) [Pa/s]", "PF2U.tube2.der(p[1])", 1,\
 6, 18, 1024)
DeclareAlias2("junction15.gas.h", "Specific enthalpy [J/kg]", "junction15.h", 1,\
 1, 118, 1024)
DeclareAlias2("junction15.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction15.der(h)", 1, 6, 118, 1024)
DeclareVariable("junction15.gas.s", "Specific entropy [J/(kg.K)]", 17483, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.T", "Temperature [K|degC]", 17484, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction15.gas.M", "Average molar mass [kg/mol]", \
"junction15.gas.M_i[1]", 1, 5, 13758, 1024)
DeclareVariable("junction15.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17485, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17486, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17487, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.kappa", "Isothermal compressibility [1/Pa]", 17488,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.w", "Speed of sound [m/s]", 17489, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction15.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17490, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17491, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.p_i[1]", "Partial pressure [Pa|bar]", 17492, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction15.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17493, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction15.gas.phi", "Relative humidity", 13753, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction15.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13754, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction15.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13755, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction15.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13756, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13757, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17494, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.M_i[1]", "Molar mass of component i [kg/mol]", 13758,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction15.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13759, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13760, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13761, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.transp.Pr", "Prandtl number [1]", 13762, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13763, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13764, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction15.gas.transp.sigma", "Surface tension [N/m]", 13765, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.computeFlags", "[:#(type=Integer)]", 13766, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction15.volume", "[m3]", 1364, 0.0001, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction15.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1365, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction15.pInitial", "Initial value for air pressure [Pa|bar]",\
 1366, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction15.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13767, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction15.TInitial", "Initial value for air temperature [K|K]",\
 1367, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction15.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1368, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction15.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13768, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction15.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1369, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction15.h", "Specific enthalpy [J/kg]", 118, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction15.der(h)", "der(Specific enthalpy) [m2/s3]", 118, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction15.p", "[Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("junction15.der(p)", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18, 0)
DeclareVariable("junction15.mass", "Gas mass in control volume [kg]", 17495, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction15.drhodt", "[Pa.m-2.s]", 17496, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction15.hInitial", "[J/kg]", 13769, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13770, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction15.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13771, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction15.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13772, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13773,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13774, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13775,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13776, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13777, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13778, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasA.gasPointer.id", "[:#(type=Integer)]", 13779, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction15.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1370, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction15.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13780, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13781,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13782, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13783,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13784, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13785, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13786, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasB.gasPointer.id", "[:#(type=Integer)]", 13787, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction15.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1371, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction15.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13788, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13789,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13790, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13791,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13792, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13793, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13794, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasC.gasPointer.id", "[:#(type=Integer)]", 13795, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction15.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1372, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction16.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13796, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 13797, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13798, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13799,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13800, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13801, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13802, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.simPort.vleFluidMass", "[kg]", 13803, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction16.simPort.vleFluidVolume", "[m3]", 13804, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.simPort.liquidMass", "[kg]", 13805, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction16.simPort.liquidVolume", "[m3]", 13806, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction16.simPort.gasMass", "[kg]", "junction16.mass", 1, 5, 17511,\
 1024)
DeclareAlias2("junction16.simPort.gasVolume", "[m3]", "junction16.volume", 1, 7,\
 1373, 1024)
DeclareVariable("junction16.simPort.dpdt", "", 13807, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.simPort.dpdtCounter", "", 13808, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 13809, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction16.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13810, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction16.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13811, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction16.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 13812, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction16.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction16.mass", 1, 5, 17511, 1156)
DeclareAlias2("junction16.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction16.volume", 1, 7, 1373, 1156)
DeclareVariable("junction16.simPort.dpdtPort.dpdt", "", 13813, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction16.simPort.dpdtPort.counter", "", 13814, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction16.simPort.warningsPort.warnings", "Accumulated warnings",\
 13815, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction16.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13816, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction16.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13817, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13818,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13819, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13820,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13821, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13822, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13823, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction16.portA.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction16.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4L.portB1.m_flow", -1, 5, 16715, 132)
DeclareAlias2("junction16.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction16.h", 1, 1, 119, 4)
DeclareVariable("junction16.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13824, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13825,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13826, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13827,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13828, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13829, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13830, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction16.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareVariable("junction16.portB.m_flow", "Mass flow rate [kg/s]", 17497, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("junction16.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction16.h", 1, 1, 119, 4)
DeclareVariable("junction16.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13831, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13832,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13833, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13834,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13835, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13836, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13837, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction16.portC.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction16.portC.m_flow", "Mass flow rate [kg/s]", \
"PF4U.portB1.m_flow", -1, 5, 17140, 132)
DeclareAlias2("junction16.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction16.h", 1, 1, 119, 4)
DeclareVariable("junction16.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13838, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13839,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13840, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13841,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13842, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13843, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13844, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gas.gasPointer.id", "[:#(type=Integer)]", 13845, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction16.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 13846, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction16.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 13847, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction16.gas.d", "Density [kg/m3|g/cm3]", 17498, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction16.gas.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18,\
 1024)
DeclareAlias2("junction16.gas.der(p)", "der(Pressure) [Pa/s]", "PF2U.tube2.der(p[1])", 1,\
 6, 18, 1024)
DeclareAlias2("junction16.gas.h", "Specific enthalpy [J/kg]", "junction16.h", 1,\
 1, 119, 1024)
DeclareAlias2("junction16.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction16.der(h)", 1, 6, 119, 1024)
DeclareVariable("junction16.gas.s", "Specific entropy [J/(kg.K)]", 17499, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.T", "Temperature [K|degC]", 17500, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction16.gas.M", "Average molar mass [kg/mol]", \
"junction16.gas.M_i[1]", 1, 5, 13853, 1024)
DeclareVariable("junction16.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17501, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17502, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17503, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.kappa", "Isothermal compressibility [1/Pa]", 17504,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.w", "Speed of sound [m/s]", 17505, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction16.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17506, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17507, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.p_i[1]", "Partial pressure [Pa|bar]", 17508, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction16.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17509, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction16.gas.phi", "Relative humidity", 13848, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction16.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13849, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction16.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13850, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction16.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13851, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13852, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17510, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.M_i[1]", "Molar mass of component i [kg/mol]", 13853,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction16.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13854, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13855, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13856, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.transp.Pr", "Prandtl number [1]", 13857, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13858, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13859, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction16.gas.transp.sigma", "Surface tension [N/m]", 13860, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.computeFlags", "[:#(type=Integer)]", 13861, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction16.volume", "[m3]", 1373, 0.0001, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction16.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1374, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction16.pInitial", "Initial value for air pressure [Pa|bar]",\
 1375, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction16.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13862, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction16.TInitial", "Initial value for air temperature [K|K]",\
 1376, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction16.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1377, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction16.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13863, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction16.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1378, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction16.h", "Specific enthalpy [J/kg]", 119, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction16.der(h)", "der(Specific enthalpy) [m2/s3]", 119, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction16.p", "[Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("junction16.der(p)", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18, 0)
DeclareVariable("junction16.mass", "Gas mass in control volume [kg]", 17511, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction16.drhodt", "[Pa.m-2.s]", 17512, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction16.hInitial", "[J/kg]", 13864, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13865, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction16.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13866, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction16.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13867, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13868,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13869, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13870,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13871, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13872, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13873, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasA.gasPointer.id", "[:#(type=Integer)]", 13874, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction16.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1379, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction16.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13875, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13876,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13877, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13878,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13879, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13880, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13881, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasB.gasPointer.id", "[:#(type=Integer)]", 13882, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction16.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1380, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction16.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13883, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13884,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13885, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13886,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13887, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13888, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13889, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasC.gasPointer.id", "[:#(type=Integer)]", 13890, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction16.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1381, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction17.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13891, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 13892, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13893, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13894,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13895, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13896, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13897, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.simPort.vleFluidMass", "[kg]", 13898, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction17.simPort.vleFluidVolume", "[m3]", 13899, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.simPort.liquidMass", "[kg]", 13900, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction17.simPort.liquidVolume", "[m3]", 13901, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction17.simPort.gasMass", "[kg]", "junction17.mass", 1, 5, 17527,\
 1024)
DeclareAlias2("junction17.simPort.gasVolume", "[m3]", "junction17.volume", 1, 7,\
 1382, 1024)
DeclareVariable("junction17.simPort.dpdt", "", 13902, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.simPort.dpdtCounter", "", 13903, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 13904, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction17.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13905, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction17.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13906, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction17.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 13907, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction17.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction17.mass", 1, 5, 17527, 1156)
DeclareAlias2("junction17.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction17.volume", 1, 7, 1382, 1156)
DeclareVariable("junction17.simPort.dpdtPort.dpdt", "", 13908, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction17.simPort.dpdtPort.counter", "", 13909, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction17.simPort.warningsPort.warnings", "Accumulated warnings",\
 13910, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction17.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13911, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction17.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13912, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13913,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13914, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13915,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13916, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13917, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13918, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction17.portA.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction17.portA.m_flow", "Mass flow rate [kg/s]", \
"junction15.portB.m_flow", -1, 5, 17481, 132)
DeclareAlias2("junction17.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction17.h", 1, 1, 120, 4)
DeclareVariable("junction17.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13919, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13920,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13921, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13922,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13923, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13924, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13925, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction17.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareVariable("junction17.portB.m_flow", "Mass flow rate [kg/s]", 17513, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("junction17.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction17.h", 1, 1, 120, 4)
DeclareVariable("junction17.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13926, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13927,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13928, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13929,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13930, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13931, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13932, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction17.portC.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction17.portC.m_flow", "Mass flow rate [kg/s]", \
"junction16.portB.m_flow", -1, 5, 17497, 132)
DeclareAlias2("junction17.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction17.h", 1, 1, 120, 4)
DeclareVariable("junction17.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13933, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13934,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13935, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13936,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13937, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13938, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13939, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gas.gasPointer.id", "[:#(type=Integer)]", 13940, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction17.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 13941, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction17.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 13942, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction17.gas.d", "Density [kg/m3|g/cm3]", 17514, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction17.gas.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18,\
 1024)
DeclareAlias2("junction17.gas.der(p)", "der(Pressure) [Pa/s]", "PF2U.tube2.der(p[1])", 1,\
 6, 18, 1024)
DeclareAlias2("junction17.gas.h", "Specific enthalpy [J/kg]", "junction17.h", 1,\
 1, 120, 1024)
DeclareAlias2("junction17.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction17.der(h)", 1, 6, 120, 1024)
DeclareVariable("junction17.gas.s", "Specific entropy [J/(kg.K)]", 17515, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.T", "Temperature [K|degC]", 17516, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction17.gas.M", "Average molar mass [kg/mol]", \
"junction17.gas.M_i[1]", 1, 5, 13948, 1024)
DeclareVariable("junction17.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17517, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17518, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17519, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.kappa", "Isothermal compressibility [1/Pa]", 17520,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.w", "Speed of sound [m/s]", 17521, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction17.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17522, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17523, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.p_i[1]", "Partial pressure [Pa|bar]", 17524, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction17.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17525, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction17.gas.phi", "Relative humidity", 13943, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction17.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13944, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction17.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13945, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction17.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13946, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13947, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17526, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.M_i[1]", "Molar mass of component i [kg/mol]", 13948,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction17.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13949, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13950, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13951, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.transp.Pr", "Prandtl number [1]", 13952, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13953, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13954, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction17.gas.transp.sigma", "Surface tension [N/m]", 13955, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.computeFlags", "[:#(type=Integer)]", 13956, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction17.volume", "[m3]", 1382, 0.0001, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction17.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1383, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction17.pInitial", "Initial value for air pressure [Pa|bar]",\
 1384, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction17.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13957, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction17.TInitial", "Initial value for air temperature [K|K]",\
 1385, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction17.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1386, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction17.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13958, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction17.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1387, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction17.h", "Specific enthalpy [J/kg]", 120, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction17.der(h)", "der(Specific enthalpy) [m2/s3]", 120, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction17.p", "[Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("junction17.der(p)", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18, 0)
DeclareVariable("junction17.mass", "Gas mass in control volume [kg]", 17527, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction17.drhodt", "[Pa.m-2.s]", 17528, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction17.hInitial", "[J/kg]", 13959, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13960, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction17.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13961, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction17.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13962, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13963,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13964, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13965,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13966, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13967, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13968, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasA.gasPointer.id", "[:#(type=Integer)]", 13969, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction17.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1388, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction17.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13970, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13971,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13972, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13973,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13974, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13975, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13976, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasB.gasPointer.id", "[:#(type=Integer)]", 13977, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction17.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1389, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction17.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13978, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13979,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13980, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13981,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13982, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13983, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13984, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasC.gasPointer.id", "[:#(type=Integer)]", 13985, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction17.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1390, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction18.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13986, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 13987, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13988, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13989,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13990, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13991, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13992, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.simPort.vleFluidMass", "[kg]", 13993, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction18.simPort.vleFluidVolume", "[m3]", 13994, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.simPort.liquidMass", "[kg]", 13995, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction18.simPort.liquidVolume", "[m3]", 13996, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction18.simPort.gasMass", "[kg]", "junction18.mass", 1, 5, 17542,\
 1024)
DeclareAlias2("junction18.simPort.gasVolume", "[m3]", "junction18.volume", 1, 7,\
 1391, 1024)
DeclareVariable("junction18.simPort.dpdt", "", 13997, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.simPort.dpdtCounter", "", 13998, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 13999, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction18.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 14000, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction18.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 14001, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction18.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 14002, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction18.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction18.mass", 1, 5, 17542, 1156)
DeclareAlias2("junction18.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction18.volume", 1, 7, 1391, 1156)
DeclareVariable("junction18.simPort.dpdtPort.dpdt", "", 14003, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction18.simPort.dpdtPort.counter", "", 14004, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction18.simPort.warningsPort.warnings", "Accumulated warnings",\
 14005, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction18.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 14006, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction18.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14007, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14008,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14009, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14010,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14011, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14012, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14013, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction18.portA.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction18.portA.m_flow", "Mass flow rate [kg/s]", \
"junction11.portB.m_flow", -1, 5, 14638, 132)
DeclareAlias2("junction18.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction18.h", 1, 1, 121, 4)
DeclareVariable("junction18.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14014, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14015,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14016, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14017,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14018, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14019, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14020, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction18.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction18.portB.m_flow", "Mass flow rate [kg/s]", \
"junction4.portA.m_flow", -1, 5, 14457, 132)
DeclareAlias2("junction18.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction18.h", 1, 1, 121, 4)
DeclareVariable("junction18.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14021, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14022,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14023, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14024,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14025, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14026, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14027, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction18.portC.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction18.portC.m_flow", "Mass flow rate [kg/s]", \
"junction17.portB.m_flow", -1, 5, 17513, 132)
DeclareAlias2("junction18.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction18.h", 1, 1, 121, 4)
DeclareVariable("junction18.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14028, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14029,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14030, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14031,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 14032, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14033, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14034, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gas.gasPointer.id", "[:#(type=Integer)]", 14035, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction18.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 14036, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction18.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 14037, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction18.gas.d", "Density [kg/m3|g/cm3]", 17529, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction18.gas.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18,\
 1024)
DeclareAlias2("junction18.gas.der(p)", "der(Pressure) [Pa/s]", "PF2U.tube2.der(p[1])", 1,\
 6, 18, 1024)
DeclareAlias2("junction18.gas.h", "Specific enthalpy [J/kg]", "junction18.h", 1,\
 1, 121, 1024)
DeclareAlias2("junction18.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction18.der(h)", 1, 6, 121, 1024)
DeclareVariable("junction18.gas.s", "Specific entropy [J/(kg.K)]", 17530, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.T", "Temperature [K|degC]", 17531, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction18.gas.M", "Average molar mass [kg/mol]", \
"junction18.gas.M_i[1]", 1, 5, 14043, 1024)
DeclareVariable("junction18.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17532, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17533, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17534, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.kappa", "Isothermal compressibility [1/Pa]", 17535,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.w", "Speed of sound [m/s]", 17536, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction18.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17537, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17538, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.p_i[1]", "Partial pressure [Pa|bar]", 17539, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction18.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17540, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction18.gas.phi", "Relative humidity", 14038, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction18.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 14039, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction18.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 14040, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction18.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 14041, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 14042, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17541, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.M_i[1]", "Molar mass of component i [kg/mol]", 14043,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction18.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 14044, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 14045, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 14046, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.transp.Pr", "Prandtl number [1]", 14047, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 14048, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.transp.eta", "Dynamic viscosity [Pa.s]", 14049, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction18.gas.transp.sigma", "Surface tension [N/m]", 14050, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.computeFlags", "[:#(type=Integer)]", 14051, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction18.volume", "[m3]", 1391, 0.0001, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction18.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1392, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction18.pInitial", "Initial value for air pressure [Pa|bar]",\
 1393, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction18.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 14052, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction18.TInitial", "Initial value for air temperature [K|K]",\
 1394, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction18.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1395, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction18.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 14053, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction18.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1396, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction18.h", "Specific enthalpy [J/kg]", 121, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction18.der(h)", "der(Specific enthalpy) [m2/s3]", 121, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction18.p", "[Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("junction18.der(p)", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18, 0)
DeclareVariable("junction18.mass", "Gas mass in control volume [kg]", 17542, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction18.drhodt", "[Pa.m-2.s]", 17543, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction18.hInitial", "[J/kg]", 14054, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 14055, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction18.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 14056, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction18.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14057, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14058,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14059, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14060,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14061, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14062, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14063, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasA.gasPointer.id", "[:#(type=Integer)]", 14064, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction18.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1397, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction18.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14065, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14066,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14067, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14068,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14069, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14070, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14071, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasB.gasPointer.id", "[:#(type=Integer)]", 14072, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction18.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1398, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction18.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14073, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14074,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14075, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14076,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14077, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14078, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14079, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasC.gasPointer.id", "[:#(type=Integer)]", 14080, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction18.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1399, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction19.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14081, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 14082, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14083, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14084,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 14085, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14086, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14087, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.simPort.vleFluidMass", "[kg]", 14088, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction19.simPort.vleFluidVolume", "[m3]", 14089, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.simPort.liquidMass", "[kg]", 14090, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction19.simPort.liquidVolume", "[m3]", 14091, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction19.simPort.gasMass", "[kg]", "junction19.mass", 1, 5, 17557,\
 1024)
DeclareAlias2("junction19.simPort.gasVolume", "[m3]", "junction19.volume", 1, 7,\
 1400, 1024)
DeclareVariable("junction19.simPort.dpdt", "", 14092, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.simPort.dpdtCounter", "", 14093, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 14094, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction19.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 14095, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction19.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 14096, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction19.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 14097, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction19.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction19.mass", 1, 5, 17557, 1156)
DeclareAlias2("junction19.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction19.volume", 1, 7, 1400, 1156)
DeclareVariable("junction19.simPort.dpdtPort.dpdt", "", 14098, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction19.simPort.dpdtPort.counter", "", 14099, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction19.simPort.warningsPort.warnings", "Accumulated warnings",\
 14100, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction19.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 14101, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction19.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14102, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14103,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14104, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14105,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14106, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14107, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14108, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction19.portA.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction19.portA.m_flow", "Mass flow rate [kg/s]", \
"junction12.portB.m_flow", -1, 5, 17434, 132)
DeclareAlias2("junction19.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction19.h", 1, 1, 122, 4)
DeclareVariable("junction19.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14109, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14110,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14111, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14112,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14113, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14114, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14115, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction19.portB.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction19.portB.m_flow", "Mass flow rate [kg/s]", \
"junction7.portB.m_flow", -1, 5, 14570, 132)
DeclareAlias2("junction19.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction19.h", 1, 1, 122, 4)
DeclareVariable("junction19.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14116, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14117,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14118, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14119,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14120, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14121, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14122, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction19.portC.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction19.portC.m_flow", "Mass flow rate [kg/s]", \
"junction1.portB.m_flow", -1, 5, 14372, 132)
DeclareAlias2("junction19.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction19.h", 1, 1, 122, 4)
DeclareVariable("junction19.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14123, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14124,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14125, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14126,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 14127, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14128, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14129, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gas.gasPointer.id", "[:#(type=Integer)]", 14130, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction19.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 14131, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction19.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 14132, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction19.gas.d", "Density [kg/m3|g/cm3]", 17544, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction19.gas.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 1024)
DeclareAlias2("junction19.gas.der(p)", "der(Pressure) [Pa/s]", "tube1.der(p[1])", 1,\
 6, 1, 1024)
DeclareAlias2("junction19.gas.h", "Specific enthalpy [J/kg]", "junction19.h", 1,\
 1, 122, 1024)
DeclareAlias2("junction19.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction19.der(h)", 1, 6, 122, 1024)
DeclareVariable("junction19.gas.s", "Specific entropy [J/(kg.K)]", 17545, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.T", "Temperature [K|degC]", 17546, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction19.gas.M", "Average molar mass [kg/mol]", \
"junction19.gas.M_i[1]", 1, 5, 14138, 1024)
DeclareVariable("junction19.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17547, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17548, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17549, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.kappa", "Isothermal compressibility [1/Pa]", 17550,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.w", "Speed of sound [m/s]", 17551, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction19.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17552, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17553, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.p_i[1]", "Partial pressure [Pa|bar]", 17554, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction19.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17555, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction19.gas.phi", "Relative humidity", 14133, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction19.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 14134, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction19.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 14135, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction19.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 14136, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 14137, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17556, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.M_i[1]", "Molar mass of component i [kg/mol]", 14138,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction19.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 14139, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 14140, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 14141, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.transp.Pr", "Prandtl number [1]", 14142, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 14143, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.transp.eta", "Dynamic viscosity [Pa.s]", 14144, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction19.gas.transp.sigma", "Surface tension [N/m]", 14145, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.computeFlags", "[:#(type=Integer)]", 14146, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction19.volume", "[m3]", 1400, 0.0001, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction19.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1401, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction19.pInitial", "Initial value for air pressure [Pa|bar]",\
 1402, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction19.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 14147, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction19.TInitial", "Initial value for air temperature [K|K]",\
 1403, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction19.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1404, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction19.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 14148, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction19.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1405, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction19.h", "Specific enthalpy [J/kg]", 122, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction19.der(h)", "der(Specific enthalpy) [m2/s3]", 122, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction19.p", "[Pa|bar]", "tube1.p[1]", 1, 1, 1, 0)
DeclareAlias2("junction19.der(p)", "[Pa/s]", "tube1.der(p[1])", 1, 6, 1, 0)
DeclareVariable("junction19.mass", "Gas mass in control volume [kg]", 17557, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction19.drhodt", "[Pa.m-2.s]", 17558, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction19.hInitial", "[J/kg]", 14149, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 14150, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction19.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 14151, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction19.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14152, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14153,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14154, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14155,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14156, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14157, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14158, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasA.gasPointer.id", "[:#(type=Integer)]", 14159, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction19.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1406, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction19.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14160, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14161,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14162, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14163,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14164, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14165, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14166, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasB.gasPointer.id", "[:#(type=Integer)]", 14167, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction19.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1407, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction19.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14168, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14169,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14170, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14171,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14172, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14173, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14174, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasC.gasPointer.id", "[:#(type=Integer)]", 14175, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction19.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1408, false, 0.0,0.0,0.0,0,2610)
EndNonAlias(16)
PreNonAliasNew(17)
