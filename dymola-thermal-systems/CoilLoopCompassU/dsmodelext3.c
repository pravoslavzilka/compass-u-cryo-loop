#include <moutil.c>
PreNonAliasDef(16)
PreNonAliasDef(17)
PreNonAliasDef(18)
PreNonAliasDef(19)
PreNonAliasDef(20)
StartNonAlias(15)
DeclareVariable("PF4U.valve1.simPort.vleFluidMass", "[kg]", 11965, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.valve1.simPort.vleFluidVolume", "[m3]", 11966, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.simPort.liquidMass", "[kg]", 11967, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.valve1.simPort.liquidVolume", "[m3]", 11968, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.valve1.simPort.gasMass", "[kg]", 11969, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.simPort.gasVolume", "[m3]", 11970, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("PF4U.valve1.simPort.dpdt", "", 11971, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.simPort.dpdtCounter", "", 11972, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.simPort.vleFluidPort.vleFluidMass", \
"Accumulated fluid mass [kg]", 11973, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.valve1.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 11974, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.valve1.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 11975, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.valve1.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 11976, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.valve1.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 11977, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.valve1.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 11978, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.valve1.simPort.dpdtPort.dpdt", "", 11979, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("PF4U.valve1.simPort.dpdtPort.counter", "", 11980, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.valve1.simPort.warningsPort.warnings", "Accumulated warnings",\
 17074, 0.0, 0.0,0.0,0.0,0,2824)
DeclareVariable("PF4U.valve1.valveFlowVariableType", "Flow variable type of valve (Aeff or Kv) [:#(type=ThermalSystems.Internals.ValveFlowVariableType)]",\
 11981, 2, 1.0,2.0,0.0,0,517)
DeclareVariable("PF4U.valve1.use_effectiveFlowAreaInput", "If true: effectiveFlowArea defined by input [:#(type=Boolean)]",\
 11982, false, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.valve1.effectiveFlowAreaFixed", "Effective flow area [m2]",\
 1203, 3E-06, 0.0,1.7976931348623157E+308,0.0,0,560)
DeclareVariable("PF4U.valve1.use_KvValueInput", "If true: Kv-value defined by input [:#(type=Boolean)]",\
 11983, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.valve1.KvValueFixed", "Kv-value [m3/h]", 11984, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,513)
DeclareParameter("PF4U.valve1.relativeLeakage", "Relative leakage in check valve operation [1]",\
 1204, 0.0001, 0.0,1.0,0.0,0,560)
DeclareParameter("PF4U.valve1.m_flowStart", "Mass flow rate at start [kg/s]", 1205,\
 1E-06, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.valve1.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 11985, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.valve1.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 11986,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.valve1.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 11987, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 11988,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 11989, 1,\
 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 11990, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 11991, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.valve1.portA.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1,\
 4)
DeclareAlias2("PF4U.valve1.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4U.portA1.m_flow", 1, 5, 17113, 132)
DeclareAlias2("PF4U.valve1.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction2.h", 1, 1, 102, 4)
DeclareVariable("PF4U.valve1.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 11992, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.valve1.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 11993,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.valve1.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 11994, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 11995,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 11996, 1,\
 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 11997, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 11998, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.valve1.portB.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.valve1.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.portA1.m_flow", -1, 5, 17113, 132)
DeclareAlias2("PF4U.valve1.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction14.h", 1, 1, 117, 4)
DeclareVariable("PF4U.valve1.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 11999, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.valve1.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12000,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12001, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12002,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12003, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12004, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12005, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasA.gasPointer.id", "[:#(type=Integer)]", 12006, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.valve1.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1206, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.valve1.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12007, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.valve1.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12008,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12009, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12010,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12011, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12012, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12013, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasB.gasPointer.id", "[:#(type=Integer)]", 12014, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.valve1.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1207, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.valve1.gasInA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12015, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.valve1.gasInA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12016,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12017, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12018,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasInA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12019, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasInA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12020, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12021, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInA.gasPointer.id", "[:#(type=Integer)]", 12022,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.valve1.gasInA.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 12023,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.valve1.gasInA.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 12024, false,\
 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.valve1.gasInA.d", "Density [kg/m3|g/cm3]", "PF4U.valve1.propertiesInA.d", 1,\
 5, 17064, 1024)
DeclareAlias2("PF4U.valve1.gasInA.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1,\
 1024)
DeclareAlias2("PF4U.valve1.gasInA.h", "Specific enthalpy [J/kg]", "junction14.h", 1,\
 1, 117, 1024)
DeclareAlias2("PF4U.valve1.gasInA.s", "Specific entropy [J/(kg.K)]", \
"PF4U.valve1.propertiesInA.s", 1, 5, 17065, 1024)
DeclareAlias2("PF4U.valve1.gasInA.T", "Temperature [K|degC]", "PF4U.valve1.propertiesInA.T", 1,\
 5, 17066, 1024)
DeclareAlias2("PF4U.valve1.gasInA.M", "Average molar mass [kg/mol]", \
"PF4U.valve1.gasInA.M_i[1]", 1, 5, 12030, 1024)
DeclareAlias2("PF4U.valve1.gasInA.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.valve1.propertiesInA.cp", 1, 5, 17067, 1024)
DeclareVariable("PF4U.valve1.gasInA.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17075, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17076, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.kappa", "Isothermal compressibility [1/Pa]",\
 17077, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.w", "Speed of sound [m/s]", 17078, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17079, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17080, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.p_i[1]", "Partial pressure [Pa|bar]", 17081,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17082, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.phi", "Relative humidity", 12025, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 12026, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.xi_s", "Saturation mass fraction of condensing component [1]",\
 12027, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 12028, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 12029, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17083, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInA.M_i[1]", "Molar mass of component i [kg/mol]",\
 12030, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.humRatio", "Content of condensing component aka humidity ratio [1]",\
 12031, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 12032, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 12033, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.transp.Pr", "Prandtl number [1]", 12034, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 12035, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.transp.eta", "Dynamic viscosity [Pa.s]", 12036,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.transp.sigma", "Surface tension [N/m]", 12037,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInA.computeFlags", "[:#(type=Integer)]", 12038, 0,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.valve1.gasInB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12039, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.valve1.gasInB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12040,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12041, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12042,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasInB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12043, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.valve1.gasInB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12044, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12045, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.valve1.gasInB.gasPointer.id", "[:#(type=Integer)]", 12046,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.valve1.gasInB.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 12047,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.valve1.gasInB.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 12048, false,\
 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.valve1.gasInB.d", "Density [kg/m3|g/cm3]", "PF4U.valve1.propertiesInB.d", 1,\
 5, 17069, 1024)
DeclareAlias2("PF4U.valve1.gasInB.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 1024)
DeclareAlias2("PF4U.valve1.gasInB.h", "Specific enthalpy [J/kg]", \
"PF4U.junction2.h", 1, 1, 102, 1024)
DeclareAlias2("PF4U.valve1.gasInB.s", "Specific entropy [J/(kg.K)]", \
"PF4U.valve1.propertiesInB.s", 1, 5, 17070, 1024)
DeclareAlias2("PF4U.valve1.gasInB.T", "Temperature [K|degC]", "PF4U.valve1.propertiesInB.T", 1,\
 5, 17071, 1024)
DeclareAlias2("PF4U.valve1.gasInB.M", "Average molar mass [kg/mol]", \
"PF4U.valve1.gasInB.M_i[1]", 1, 5, 12054, 1024)
DeclareAlias2("PF4U.valve1.gasInB.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.valve1.propertiesInB.cp", 1, 5, 17072, 1024)
DeclareVariable("PF4U.valve1.gasInB.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17084, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17085, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.kappa", "Isothermal compressibility [1/Pa]",\
 17086, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.w", "Speed of sound [m/s]", 17087, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17088, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17089, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.p_i[1]", "Partial pressure [Pa|bar]", 17090,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17091, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.phi", "Relative humidity", 12049, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 12050, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.xi_s", "Saturation mass fraction of condensing component [1]",\
 12051, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 12052, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 12053, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17092, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.gasInB.M_i[1]", "Molar mass of component i [kg/mol]",\
 12054, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.humRatio", "Content of condensing component aka humidity ratio [1]",\
 12055, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 12056, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 12057, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.transp.Pr", "Prandtl number [1]", 12058, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 12059, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.transp.eta", "Dynamic viscosity [Pa.s]", 12060,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.transp.sigma", "Surface tension [N/m]", 12061,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.gasInB.computeFlags", "[:#(type=Integer)]", 12062, 0,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.valve1.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 12063, false, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.valve1.flowPrinciple.warningLinearizationRange", "", \
"PF4U.valve1.warningLinearizationRange", 1, 5, 17112, 0)
DeclareAlias2("PF4U.valve1.flowPrinciple.massFlowRateDensity_A", "[kg/(s.m2)]", \
"PF4U.valve1.massFlowRateDensity", 1, 5, 17096, 512)
DeclareVariable("PF4U.valve1.flowPrinciple.w_gas", "Speed of sound at throttle [m/s]",\
 17093, 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("PF4U.valve1.flowPrinciple.velocity_gas", "Flow velocity at throttle [m/s]",\
 17094, 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("PF4U.valve1.flowPrinciple.Ma_gas", "Mach number at throttle [1]",\
 17095, 0.0, 0.0,0.0,0.0,0,1536)
DeclareVariable("PF4U.valve1.flowPrinciple.enableChokedFlow", "If true, then choked flow is taken into account [:#(type=Boolean)]",\
 12064, true, 0.0,0.0,0.0,0,2563)
DeclareParameter("PF4U.valve1.flowPrinciple.psiSquareSmooth", "Negative value for automatic detection.",\
 1208, 0.001, 0.0,0.0,0.0,0,2608)
DeclareParameter("PF4U.valve1.use_mdotLinearization", "If true, use mass flow rate for linearization, else default linearization [:#(type=Boolean)]",\
 1209, true, 0.0,0.0,0.0,0,562)
DeclareParameter("PF4U.valve1.d_nominal", "Nominal density [kg/m3|kg/m3]", 1210,\
 1000, 0.0,1.7976931348623157E+308,0.0,0,560)
DeclareVariable("PF4U.valve1.massFlowRateDensity", "[kg/(s.m2)]", 17096, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.valve1.massFlowRateDensityLinearization", "[kg/(s.m2)]", 12065,\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.valve1.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12066, true, 0.0,0.0,0.0,0,515)
DeclareAlias2("PF4U.valve1.summary.p_gas_A", "Pressure at port A [Pa|bar]", \
"tube1.p[1]", 1, 1, 1, 0)
DeclareAlias2("PF4U.valve1.summary.p_gas_B", "Pressure at port B [Pa|bar]", \
"PF4U.junction2.p", 1, 1, 103, 0)
DeclareVariable("PF4U.valve1.summary.T_gas_A", "Temperature at port A [K|degC]",\
 17097, 288.15, 0.0,1.7976931348623157E+308,300.0,0,512)
DeclareVariable("PF4U.valve1.summary.T_gas_B", "Temperature at port B [K|degC]",\
 17098, 288.15, 0.0,1.7976931348623157E+308,300.0,0,512)
DeclareVariable("PF4U.valve1.summary.T_degC_gas_A", "Temperature at port A [degC;]",\
 17099, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.T_degC_gas_B", "Temperature at port B [degC;]",\
 17100, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.h_gas_A", "Specific enthalpy at port A [J/kg]",\
 17101, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.h_gas_B", "Specific enthalpy at port B [J/kg]",\
 17102, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.d_gas_A", "Density at port A [kg/m3|g/cm3]",\
 17103, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.d_gas_B", "Density at port B [kg/m3|g/cm3]",\
 17104, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareAlias2("PF4U.valve1.summary.m_flow_gas_A", "Mass flow rate at port A [kg/s]",\
 "PF4U.portA1.m_flow", 1, 5, 17113, 0)
DeclareAlias2("PF4U.valve1.summary.m_flow_gas_B", "Mass flow rate at port B [kg/s]",\
 "PF4U.portA1.m_flow", -1, 5, 17113, 0)
DeclareVariable("PF4U.valve1.summary.V_flow_gas_A", "Volume flow rate at port A [m3/s]",\
 17105, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.V_flow_gas_B", "Volume flow rate at port B [m3/s]",\
 17106, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.phi_gas_A", "Relative humidity at port A", 17107,\
 0.0, 0.0,100.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.phi_gas_B", "Relative humidity at port B", 17108,\
 0.0, 0.0,100.0,0.0,0,512)
DeclareAlias2("PF4U.valve1.summary.effectiveFlowArea", "Effective flow area [m2]",\
 "PF4U.valve1.effectiveFlowArea", 1, 5, 11957, 0)
DeclareVariable("PF4U.valve1.summary.Kv", "Kv-value [m3/h]", 12067, 0.0, \
0.0,0.0,0.0,0,513)
DeclareAlias2("PF4U.valve1.summary.w_gas", "Speed of sound at throttle [m/s]", \
"PF4U.valve1.flowPrinciple.w_gas", 1, 5, 17093, 0)
DeclareVariable("PF4U.valve1.summary.velocity_gas", "Flow velocity at throttle [m/s]",\
 17109, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.Ma_gas", "Mach number at throttle [1]", 17110,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.dp_gas", "Total pressure drop [Pa|bar]", 17111,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.valve1.summary.nc_gas", "Number of components [:#(type=Integer)]",\
 12068, 1, 0.0,0.0,0.0,0,517)
DeclareVariable("PF4U.valve1.visualizeWarnings", "If true, warnings will be visualized in the diagram layer [:#(type=Boolean)]",\
 12069, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.valve1.warningNegativeFlowArea", "Flow Area is negative", 12070,\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.valve1.warningLinearizationRange", "Mass flow rate is within linearization range",\
 17112, 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.valve1.getInputs.effectiveFlowArea_in", "Prescribed effective flow area [m^2] [m2]",\
 "PF4U.valve1.effectiveFlowArea_in_.k", 1, 5, 12071, 1024)
DeclareAlias2("PF4U.valve1.getInputs.KvValue_in", "Prescribed Kv-value [m^3/h] [m3/h]",\
 "PF4U.valve1.KvValue_in_.k", 1, 5, 12072, 1024)
DeclareVariable("PF4U.valve1.effectiveFlowArea_in_.k", "Constant output value [m2]",\
 12071, 1, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.valve1.effectiveFlowArea_in_.y", "Connector of Real output signal [m2]",\
 "PF4U.valve1.effectiveFlowArea_in_.k", 1, 5, 12071, 1024)
DeclareVariable("PF4U.valve1.KvValue_in_.k", "Constant output value [m3/h]", 12072,\
 1, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.valve1.KvValue_in_.y", "Connector of Real output signal [m3/h]",\
 "PF4U.valve1.KvValue_in_.k", 1, 5, 12072, 1024)
DeclareVariable("PF4U.valve1.dp_nominal", "Reference pressure difference [Pa|bar]",\
 12073, 100000.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.portA1.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12074, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.portA1.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 12075, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.portA1.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12076, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.portA1.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12077,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.portA1.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 12078, 1, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.portA1.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12079, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.portA1.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12080, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.portA1.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareVariable("PF4U.portA1.m_flow", "Mass flow rate [kg/s]", 17113, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.portA1.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction2.h", 1, 1, 102, 4)
DeclareVariable("PF4U.portB1.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12081, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.portB1.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 12082, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.portB1.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12083, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.portB1.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12084,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.portB1.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 12085, 1, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.portB1.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12086, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.portB1.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12087, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.portB1.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18,\
 4)
DeclareVariable("PF4U.portB1.m_flow", "Mass flow rate [kg/s]", 17114, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.portB1.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction6.h", 1, 1, 114, 4)
DeclareVariable("PF4U.junction2.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12088, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12089,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12090, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12091,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 12092, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12093, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12094, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.simPort.vleFluidMass", "[kg]", 12095, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.simPort.vleFluidVolume", "[m3]", 12096, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.simPort.liquidMass", "[kg]", 12097, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.simPort.liquidVolume", "[m3]", 12098, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.junction2.simPort.gasMass", "[kg]", "PF4U.junction2.mass", 1,\
 5, 17130, 1024)
DeclareAlias2("PF4U.junction2.simPort.gasVolume", "[m3]", "PF4U.junction2.volume", 1,\
 7, 1211, 1024)
DeclareVariable("PF4U.junction2.simPort.dpdt", "", 12099, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.simPort.dpdtCounter", "", 12100, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.junction2.simPort.vleFluidPort.vleFluidMass", \
"Accumulated fluid mass [kg]", 12101, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction2.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 12102, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction2.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 12103, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction2.simPort.liquidPort.liquidVolume", \
"Accumulated liquid volume [m3]", 12104, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.junction2.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.junction2.mass", 1, 5, 17130, 1156)
DeclareAlias2("PF4U.junction2.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.junction2.volume", 1, 7, 1211, 1156)
DeclareVariable("PF4U.junction2.simPort.dpdtPort.dpdt", "", 12105, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.junction2.simPort.dpdtPort.counter", "", 12106, 0.0, \
0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction2.simPort.warningsPort.warnings", "Accumulated warnings",\
 12107, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction2.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 12108, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction2.portA.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12109, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12110,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12111, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.portA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12112,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12113, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12114, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12115, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction2.portA.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareVariable("PF4U.junction2.portA.m_flow", "Mass flow rate [kg/s]", 17115, \
0.0, 0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.junction2.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction2.h", 1, 1, 102, 4)
DeclareVariable("PF4U.junction2.portB.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12116, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12117,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12118, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.portB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12119,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12120, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12121, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12122, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction2.portB.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.junction2.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.portA1.m_flow", 1, 5, 17113, 132)
DeclareAlias2("PF4U.junction2.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction2.h", 1, 1, 102, 4)
DeclareVariable("PF4U.junction2.portC.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12123, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12124,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12125, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.portC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12126,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12127, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12128, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12129, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction2.portC.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareVariable("PF4U.junction2.portC.m_flow", "Mass flow rate [kg/s]", 17116, \
0.0, 0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.junction2.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction2.h", 1, 1, 102, 4)
DeclareVariable("PF4U.junction2.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12130, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12131,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12132, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gas.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12133,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gas.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12134, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12135, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12136, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gas.gasPointer.id", "[:#(type=Integer)]", 12137,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.junction2.gas.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 12138,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction2.gas.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 12139, false,\
 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction2.gas.d", "Density [kg/m3|g/cm3]", 17117, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.junction2.gas.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 1024)
DeclareAlias2("PF4U.junction2.gas.der(p)", "der(Pressure) [Pa/s]", \
"PF4U.junction2.der(p)", 1, 6, 103, 1024)
DeclareAlias2("PF4U.junction2.gas.h", "Specific enthalpy [J/kg]", \
"PF4U.junction2.h", 1, 1, 102, 1024)
DeclareAlias2("PF4U.junction2.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"PF4U.junction2.der(h)", 1, 6, 102, 1024)
DeclareVariable("PF4U.junction2.gas.s", "Specific entropy [J/(kg.K)]", 17118, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.T", "Temperature [K|degC]", 17119, 288.15, \
0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.junction2.gas.M", "Average molar mass [kg/mol]", \
"PF4U.junction2.gas.M_i[1]", 1, 5, 12145, 1024)
DeclareVariable("PF4U.junction2.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17120, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17121, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17122, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.kappa", "Isothermal compressibility [1/Pa]",\
 17123, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.w", "Speed of sound [m/s]", 17124, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17125, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17126, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.p_i[1]", "Partial pressure [Pa|bar]", 17127,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.junction2.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17128, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.phi", "Relative humidity", 12140, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 12141, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.junction2.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 12142, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 12143, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 12144, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17129, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction2.gas.M_i[1]", "Molar mass of component i [kg/mol]",\
 12145, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 12146, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 12147, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 12148, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.transp.Pr", "Prandtl number [1]", 12149, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 12150, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.transp.eta", "Dynamic viscosity [Pa.s]", 12151,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.transp.sigma", "Surface tension [N/m]", 12152,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction2.gas.computeFlags", "[:#(type=Integer)]", 12153, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction2.volume", "[m3]", 1211, 1E-05, 0.0,\
1.7976931348623157E+308,0.0,0,560)
DeclareParameter("PF4U.junction2.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1212, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.junction2.pInitial", "Initial value for air pressure [Pa|bar]",\
 1213, 2000000, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.junction2.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 12154, false, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.junction2.TInitial", "Initial value for air temperature [K|K]",\
 1214, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.junction2.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1215, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.junction2.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 12155, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.junction2.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1216, 1, 0.0,0.0,0.0,0,560)
DeclareState("PF4U.junction2.h", "Specific enthalpy [J/kg]", 102, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("PF4U.junction2.der(h)", "der(Specific enthalpy) [m2/s3]", 102,\
 0.0, 0.0,0.0,0.0,0,576)
DeclareState("PF4U.junction2.p", "[Pa|bar]", 103, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,544)
DeclareDerivative("PF4U.junction2.der(p)", "[Pa/s]", 103, 0.0, 0.0,0.0,0.0,0,576)
DeclareVariable("PF4U.junction2.mass", "Gas mass in control volume [kg]", 17130,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.junction2.drhodt", "[Pa.m-2.s]", 17131, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.junction2.hInitial", "[J/kg]", 12156, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12157, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.junction2.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12158, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction2.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12159, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12160,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12161, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12162,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12163, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12164, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12165, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasA.gasPointer.id", "[:#(type=Integer)]", 12166,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction2.gasA.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1217, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction2.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12167, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12168,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12169, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12170,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12171, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12172, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12173, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasB.gasPointer.id", "[:#(type=Integer)]", 12174,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction2.gasB.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1218, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction2.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12175, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction2.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12176,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12177, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12178,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12179, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction2.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12180, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12181, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction2.gasC.gasPointer.id", "[:#(type=Integer)]", 12182,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction2.gasC.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1219, false,\
 0.0,0.0,0.0,0,2610)
DeclareParameter("PF4U.prescribedHeatFlow1.T_ref", "Reference temperature [K|degC]",\
 1220, 293.15, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.prescribedHeatFlow1.alpha", "Temperature coefficient of heat flow rate [1/K]",\
 1221, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.prescribedHeatFlow1.Q_flow", "[W]", 17132, 0.0, 0.0,0.0,\
0.0,0,512)
DeclareAlias2("PF4U.prescribedHeatFlow1.port.T", "Port temperature [K|degC]", \
"PF4U.Channel2.T_wall", 1, 5, 16986, 4)
DeclareVariable("PF4U.prescribedHeatFlow1.port.Q_flow", "Heat flow rate (positive if flowing from outside into the component) [W]",\
 17133, 0, 0.0,0.0,0.0,0,776)
DeclareParameter("PF4U.stepSource1.transitionTime", "Duration of transition [s]",\
 1222, 0.5, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.stepSource1.initialValue", "Value before first step", 1223,\
 0.0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.stepSource1.stepTimes[1]", "Beginning of transitions [s]",\
 12183, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource1.stepTimes[2]", "Beginning of transitions [s]",\
 12184, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource1.stepValues[1]", "Values of steps", 12185, 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource1.stepValues[2]", "Values of steps", 12186, 0.0,\
 0.0,0.0,0.0,0,513)
DeclareAlias2("PF4U.stepSource1.y", "[W]", "PF4U.prescribedHeatFlow1.Q_flow", 1,\
 5, 17132, 0)
DeclareVariable("PF4U.stepSource1.stepCount", "[:#(type=Integer)]", 12187, 2, \
0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.stepSource1.const_finalValue.k", "Constant output value [W]",\
 12188, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.const_finalValue.y", "Connector of Real output signal [W]",\
 12189, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[1].switchTime", "[s]", 12190, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[1].transitionTime", "[s]", 12191, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[1].preSwitchValue", \
"Value to use before switching to input [W]", 12192, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[1].u", "[W]", 12193, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[1].y", "[W]", 17134, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("PF4U.stepSource1.timeSwitch[1].switchEndTime", "[s]", 12194, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[1].switchMidTime", "[s]", 12195, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[2].switchTime", "[s]", 12196, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[2].transitionTime", "[s]", 12197, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[2].preSwitchValue", \
"Value to use before switching to input [W]", 12198, 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.stepSource1.timeSwitch[2].u", "[W]", "PF4U.stepSource1.timeSwitch[1].y", 1,\
 5, 17134, 1024)
DeclareAlias2("PF4U.stepSource1.timeSwitch[2].y", "[W]", "PF4U.prescribedHeatFlow1.Q_flow", 1,\
 5, 17132, 1024)
DeclareVariable("PF4U.stepSource1.timeSwitch[2].switchEndTime", "[s]", 12199, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource1.timeSwitch[2].switchMidTime", "[s]", 12200, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12201, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube1.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 12202, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12203, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12204,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 12205, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12206, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12207, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.tubeGeometry.innerDiameter", "Inner diameter of circular tube [m]",\
 12208, 0.0, 0.0,1.7976931348623157E+308,0.0,0,513)
DeclareParameter("PF4U.tube1.tubeGeometry.wallThickness", "Wall thickness [m]", 1224,\
 0.0005, 0.0,1.7976931348623157E+308,0.0,0,560)
DeclareVariable("PF4U.tube1.tubeGeometry.length", "Length [m]", 12209, 0.0, 0.0,\
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
DeclareVariable("PF4U.tube1.tubeGeometry.outerDiameter", "[m]", 12210, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.innerCrossSectionalArea", \
"Inner cross-sectional area [m2]", 12211, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.outerCrossSectionalArea", \
"Outer cross-sectional area [m2]", 12212, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.hydraulicCrossSectionalArea", \
"Hydraulic cross sectional area [m2]", 12213, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.hydraulicDiameter", "Hydraulic diameter [m]",\
 12214, 0.0, 0.0,1.7976931348623157E+308,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.innerVolume", "Inner volume [m3]", 12215,\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.outerVolume", "Outer volume [m3]", 12216,\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.innerHeatTransferArea", "[m2]", 12217, \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube1.tubeGeometry.tubeIsCircular", "true, if tube's cross section is circular [:#(type=Boolean)]",\
 12218, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube1.simPort.vleFluidMass", "[kg]", 12219, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.simPort.vleFluidVolume", "[m3]", 12220, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.simPort.liquidMass", "[kg]", 12221, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("PF4U.tube1.simPort.liquidVolume", "[m3]", 12222, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("PF4U.tube1.simPort.gasMass", "[kg]", "PF4U.tube1.cellMass[1]", 1,\
 5, 17152, 1024)
DeclareAlias2("PF4U.tube1.simPort.gasVolume", "[m3]", "PF4U.tube1.tubeGeometry.innerVolume", 1,\
 5, 12215, 1024)
DeclareVariable("PF4U.tube1.simPort.dpdt", "", 12223, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.simPort.dpdtCounter", "", 12224, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 12225, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube1.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 12226, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube1.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 12227, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube1.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 12228, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.tube1.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.tube1.cellMass[1]", 1, 5, 17152, 1156)
DeclareAlias2("PF4U.tube1.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.tube1.tubeGeometry.innerVolume", 1, 5, 12215, 1156)
DeclareVariable("PF4U.tube1.simPort.dpdtPort.dpdt", "", 12229, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("PF4U.tube1.simPort.dpdtPort.counter", "", 12230, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.tube1.simPort.warningsPort.warnings", "Accumulated warnings",\
 12231, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube1.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12232, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube1.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12233,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube1.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12234, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12235,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12236, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12237, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12238, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.tube1.portA.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1, 1,\
 103, 4)
DeclareVariable("PF4U.tube1.portA.m_flow", "Mass flow rate [kg/s]", 17135, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.tube1.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.tube1.h[1]", 1, 1, 104, 4)
DeclareVariable("PF4U.tube1.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12239, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube1.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12240,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube1.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12241, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12242,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12243, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12244, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12245, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.tube1.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("PF4U.tube1.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.Channel2.m_flow", 1, 5, 16989, 132)
DeclareAlias2("PF4U.tube1.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.tube1.h[1]", 1, 1, 104, 4)
DeclareAlias2("PF4U.tube1.cellGeometry.length", "[m]", "PF4U.tube1.tubeGeometry.length", 1,\
 5, 12209, 1024)
DeclareAlias2("PF4U.tube1.cellGeometry.volume", "[m3]", "PF4U.tube1.tubeGeometry.innerVolume", 1,\
 5, 12215, 1024)
DeclareAlias2("PF4U.tube1.cellGeometry.heatTransferArea", "[m2]", \
"PF4U.tube1.tubeGeometry.innerHeatTransferArea", 1, 5, 12217, 1024)
DeclareParameter("PF4U.tube1.cellGeometry.finHeatTransferAreaRatio", \
"Fraction of fins on fin side heat transfer area", 1230, 0, 0.0,0.0,0.0,0,2608)
DeclareVariable("PF4U.tube1.cellGeometry.hydraulicCrossSectionalArea", "[m2]", 12246,\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.cellGeometry.nParallelHydraulicFlows", \
"Number of parallel flows [1]", 12247, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.dl[1]", "length portions of cells", 12248, 1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDropPosition", "Position of pressure drop in tube [:#(type=ThermalSystems.Internals.PressureDropPosition)]",\
 12249, 3, 1.0,3.0,0.0,0,517)
DeclareVariable("PF4U.tube1.nCells", "Discretization number of 'cells' [:#(type=Integer)]",\
 12250, 1, 0.0,0.0,0.0,0,517)
DeclareVariable("PF4U.tube1.enableHeatPorts", "true, if heat ports are enabled [:#(type=Boolean)]",\
 12251, true, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube1.generateEventsAtFlowReversal", "If true: Events will be generated at flow reversal [:#(type=Boolean)]",\
 12252, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube1.gas[1].gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12253, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube1.gas[1].gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12254,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube1.gas[1].gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12255, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gas[1].gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12256,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gas[1].gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12257, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gas[1].gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12258, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gas[1].gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12259, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gas[1].gasPointer.id", "[:#(type=Integer)]", 12260, 0,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.tube1.gas[1].stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 12261, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube1.gas[1].computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 12262, true, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube1.gas[1].d", "Density [kg/m3|g/cm3]", 17136, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.tube1.gas[1].p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 1024)
DeclareAlias2("PF4U.tube1.gas[1].h", "Specific enthalpy [J/kg]", \
"PF4U.tube1.h[1]", 1, 1, 104, 1024)
DeclareVariable("PF4U.tube1.gas[1].s", "Specific entropy [J/(kg.K)]", 17137, 0.0,\
 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube1.gas[1].T", "Temperature [K|degC]", "PF4U.tube1.T_gas_cell_[1]", 1,\
 5, 17197, 1024)
DeclareAlias2("PF4U.tube1.gas[1].M", "Average molar mass [kg/mol]", \
"PF4U.tube1.gas[1].M_i[1]", 1, 5, 12268, 1024)
DeclareVariable("PF4U.tube1.gas[1].cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17138, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17139, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].beta", "Isobaric thermal expansion coefficient [1/K]",\
 17140, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].kappa", "Isothermal compressibility [1/Pa]", 17141,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].w", "Speed of sound [m/s]", 17142, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17143, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17144, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].p_i[1]", "Partial pressure [Pa|bar]", 17145, \
0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17146, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].phi", "Relative humidity", 12263, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 12264, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].xi_s", "Saturation mass fraction of condensing component [1]",\
 12265, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 12266, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 12267, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17147, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].M_i[1]", "Molar mass of component i [kg/mol]",\
 12268, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].humRatio", "Content of condensing component aka humidity ratio [1]",\
 12269, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 12270, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 12271, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.gas[1].transp.Pr", "Prandtl number [1]", 17148, 0.0,\
 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].transp.lambda", "Thermal conductivity [W/(m.K)]",\
 17149, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].transp.eta", "Dynamic viscosity [Pa.s]", 17150,\
 0.0, -1.0,1.7976931348623157E+308,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].transp.sigma", "Surface tension [N/m]", 17151,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.gas[1].computeFlags", "[:#(type=Integer)]", 12272, 5,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.tube1.cellMass[1]", "Gas mass in one cell [kg]", 17152, \
0.0, 0.0,1.7976931348623157E+308,0.0,0,2560)
DeclareVariable("PF4U.tube1.drhodt[1]", "", 17153, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.p[1]", "[Pa|bar]", 17154, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2560)
DeclareAlias2("PF4U.tube1.der(p[1])", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18,\
 1024)
DeclareState("PF4U.tube1.h[1]", "Specific enthalpy [J/kg]", 104, 0.0, 0.0,0.0,\
100000.0,0,2592)
DeclareDerivative("PF4U.tube1.der(h[1])", "der(Specific enthalpy) [m2/s3]", 104,\
 0.0, 0.0,0.0,0.0,0,2624)
DeclareAlias2("PF4U.tube1.m_flow[1]", "[kg/s]", "PF4U.tube1.portA.m_flow", 1, 5,\
 17135, 1024)
DeclareAlias2("PF4U.tube1.m_flow[2]", "[kg/s]", "PF4U.Channel2.m_flow", -1, 5, 16989,\
 1024)
DeclareVariable("PF4U.tube1.H_flow[1]", "", 17155, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.H_flow[2]", "", 17156, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.mdotHydraulic", "[kg/s]", 17157, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube1.heatTransfer[1].mdotHydraulic", "Hydraulic mass flow rate [kg/s]",\
 "PF4U.tube1.mdotHydraulic", 1, 5, 17157, 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].QdotHydraulic", "Hydraulic heat flow rate [W]",\
 17158, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].wallTemperature", "Wall temperature [K|degC]",\
 17159, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.d", "Density [kg/m3|g/cm3]",\
 "PF4U.tube1.gas[1].d", 1, 5, 17136, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.h", "Specific enthalpy [J/kg]",\
 "PF4U.tube1.h[1]", 1, 1, 104, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.p", "Pressure [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.s", "Specific entropy [J/(kg.K)]",\
 "PF4U.tube1.gas[1].s", 1, 5, 17137, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.T", "Temperature [K|degC]",\
 "PF4U.tube1.T_gas_cell_[1]", 1, 5, 17197, 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.q", "Steam mass fraction (quality) [1]",\
 12273, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.tube1.gas[1].cp", 1, 5, 17138, 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.crit.d", "Critical density [kg/m3|g/cm3]",\
 12274, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.crit.h", "Critical specific enthalpy [J/kg]",\
 12275, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.crit.p", "Critical pressure [Pa|bar]",\
 12276, 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.crit.s", "Critical specific entropy [J/(kg.K)]",\
 12277, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.crit.T", "Critical temperature [K|degC]",\
 12278, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.d_l", \
"Density of liquid phase [kg/m3|g/cm3]", 12279, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.d_v", \
"Density of vapour phase [kg/m3|g/cm3]", 12280, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.h_l", \
"Specific enthalpy of liquid phase [J/kg]", 12281, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.h_v", \
"Specific enthalpy of vapour phase [J/kg]", 12282, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.p_l", \
"Pressure of liquid phase [Pa|bar]", 12283, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.p_v", \
"Pressure of vapour phase [Pa|bar]", 12284, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.s_l", \
"Specific entropy of liquid phase [J/(kg.K)]", 12285, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.s_v", \
"Specific entropy of vapour phase [J/(kg.K)]", 12286, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.T_l", \
"Temperature of liquid phase [K|degC]", 12287, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLE.T_v", \
"Temperature of vapour phase [K|degC]", 12288, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLETransp.Pr_l", \
"Prandtl number of liquid phase [1]", 12289, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLETransp.Pr_v", \
"Prandtl number of vapour phase [1]", 12290, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLETransp.lambda_l", \
"Thermal conductivity of liquid phase [W/(m.K)]", 12291, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLETransp.lambda_v", \
"Thermal conductivity of vapour phase [W/(m.K)]", 12292, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLETransp.eta_l", \
"Dynamic viscosity of liquid phase [Pa.s]", 12293, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].properties.VLETransp.eta_v", \
"Dynamic viscosity of vapour phase [Pa.s]", 12294, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.transp.Pr", \
"Prandtl number [1]", "PF4U.tube1.gas[1].transp.Pr", 1, 5, 17148, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.transp.lambda", \
"Thermal conductivity [W/(m.K)]", "PF4U.tube1.gas[1].transp.lambda", 1, 5, 17149,\
 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.transp.eta", \
"Dynamic viscosity [Pa.s]", "PF4U.tube1.gas[1].transp.eta", 1, 5, 17150, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].properties.transp.sigma", \
"Surface tension [N/m]", "PF4U.tube1.gas[1].transp.sigma", 1, 5, 17151, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].cellGeometry.length", "[m]", \
"PF4U.tube1.tubeGeometry.length", 1, 5, 12209, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].cellGeometry.volume", "[m3]", \
"PF4U.tube1.tubeGeometry.innerVolume", 1, 5, 12215, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].cellGeometry.heatTransferArea", "[m2]",\
 "PF4U.tube1.tubeGeometry.innerHeatTransferArea", 1, 5, 12217, 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].cellGeometry.finHeatTransferAreaRatio",\
 "Fraction of fins on fin side heat transfer area", 12295, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].cellGeometry.hydraulicCrossSectionalArea",\
 "[m2]", 12296, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].cellGeometry.nParallelHydraulicFlows",\
 "Number of parallel flows", 12297, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].alphaA", "Value for alphaA for one cell [W/K]",\
 17160, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.alphaA", "Value for alphaA for one cell [W/K]",\
 "PF4U.tube1.heatTransfer[1].alphaA", 1, 5, 17160, 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.computeTransportProperties",\
 "[:#(type=Boolean)]", 12298, true, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.useAlphaAState", \
"alphaA is a differential state [:#(type=Boolean)]", 12299, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.mdotHydraulic", \
"Hydraulic mass flow rate [kg/s]", "PF4U.tube1.mdotHydraulic", 1, 5, 17157, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.d", \
"Density [kg/m3|g/cm3]", "PF4U.tube1.gas[1].d", 1, 5, 17136, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.h", \
"Specific enthalpy [J/kg]", "PF4U.tube1.h[1]", 1, 1, 104, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.p", \
"Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.s", \
"Specific entropy [J/(kg.K)]", "PF4U.tube1.gas[1].s", 1, 5, 17137, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.T", \
"Temperature [K|degC]", "PF4U.tube1.T_gas_cell_[1]", 1, 5, 17197, 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.q", \
"Steam mass fraction (quality) [1]", 12300, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.cp", \
"Specific isobaric heat capacity cp [J/(kg.K)]", "PF4U.tube1.gas[1].cp", 1, 5, 17138,\
 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.crit.d",\
 "Critical density [kg/m3|g/cm3]", 12301, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.crit.h",\
 "Critical specific enthalpy [J/kg]", 12302, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.crit.p",\
 "Critical pressure [Pa|bar]", 12303, 0.0, 0.0,1.7976931348623157E+308,100000.0,\
0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.crit.s",\
 "Critical specific entropy [J/(kg.K)]", 12304, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.crit.T",\
 "Critical temperature [K|degC]", 12305, 0.0, 0.0,1.7976931348623157E+308,300.0,\
0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.d_l",\
 "Density of liquid phase [kg/m3|g/cm3]", 12306, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.d_v",\
 "Density of vapour phase [kg/m3|g/cm3]", 12307, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.h_l",\
 "Specific enthalpy of liquid phase [J/kg]", 12308, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.h_v",\
 "Specific enthalpy of vapour phase [J/kg]", 12309, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.p_l",\
 "Pressure of liquid phase [Pa|bar]", 12310, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.p_v",\
 "Pressure of vapour phase [Pa|bar]", 12311, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.s_l",\
 "Specific entropy of liquid phase [J/(kg.K)]", 12312, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.s_v",\
 "Specific entropy of vapour phase [J/(kg.K)]", 12313, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.T_l",\
 "Temperature of liquid phase [K|degC]", 12314, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLE.T_v",\
 "Temperature of vapour phase [K|degC]", 12315, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.Pr_l",\
 "Prandtl number of liquid phase [1]", 12316, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.Pr_v",\
 "Prandtl number of vapour phase [1]", 12317, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.lambda_l",\
 "Thermal conductivity of liquid phase [W/(m.K)]", 12318, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.lambda_v",\
 "Thermal conductivity of vapour phase [W/(m.K)]", 12319, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.eta_l",\
 "Dynamic viscosity of liquid phase [Pa.s]", 12320, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.eta_v",\
 "Dynamic viscosity of vapour phase [Pa.s]", 12321, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.transp.Pr",\
 "Prandtl number [1]", "PF4U.tube1.gas[1].transp.Pr", 1, 5, 17148, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.transp.lambda",\
 "Thermal conductivity [W/(m.K)]", "PF4U.tube1.gas[1].transp.lambda", 1, 5, 17149,\
 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.transp.eta",\
 "Dynamic viscosity [Pa.s]", "PF4U.tube1.gas[1].transp.eta", 1, 5, 17150, 1024)
DeclareAlias2("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.properties.transp.sigma",\
 "Surface tension [N/m]", "PF4U.tube1.gas[1].transp.sigma", 1, 5, 17151, 1024)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.alpha", \
"Coefficient of heat transfer [W/(m2.K)]", 17161, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.hydraulicDiameter",\
 "Hydraulic diameter [m]", 12322, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.hydraulicCrossSectionalArea",\
 "Hydraulic cross sectional area [m2]", 12323, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.Re", \
"Reynolds Number [1]", 17162, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.Nu", \
"Nusselt number [1]", 17163, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.averageVelocity", \
"Average velocity [m/s]", 17164, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.weightingFactor1", \
"", 17165, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.weightingFactor2", \
"", 17166, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.Nu1", "[1]", 17167,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.Nu_Gnielinski", \
"[1]", 17168, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.Nu_DittusBoelter", \
"[1]", 17169, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.heatTransfer[1].heatTransfer.gdb.zeta", "", 17170, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareParameter("PF4U.tube1.heatTransfer[1].heatTransfer.correctionFactor", \
"Linear correction factor for the overall alphaA calculated by this heat transfer model and its submodels. [1]",\
 1231, 1, 0.0,0.0,0.0,0,2608)
DeclareAlias2("PF4U.tube1.pressureDrop[1].mdotHydraulic", "Hydraulic mass flow rate [kg/s]",\
 "PF4U.tube1.mdotHydraulic", 1, 5, 17157, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.d", "Density [kg/m3|g/cm3]",\
 "PF4U.tube1.gas[1].d", 1, 5, 17136, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.h", "Specific enthalpy [J/kg]",\
 "PF4U.tube1.h[1]", 1, 1, 104, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.p", "Pressure [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.s", "Specific entropy [J/(kg.K)]",\
 "PF4U.tube1.gas[1].s", 1, 5, 17137, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.T", "Temperature [K|degC]",\
 "PF4U.tube1.T_gas_cell_[1]", 1, 5, 17197, 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.q", "Steam mass fraction (quality) [1]",\
 12324, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.tube1.gas[1].cp", 1, 5, 17138, 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.crit.d", "Critical density [kg/m3|g/cm3]",\
 12325, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.crit.h", "Critical specific enthalpy [J/kg]",\
 12326, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.crit.p", "Critical pressure [Pa|bar]",\
 12327, 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.crit.s", "Critical specific entropy [J/(kg.K)]",\
 12328, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.crit.T", "Critical temperature [K|degC]",\
 12329, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.d_l", \
"Density of liquid phase [kg/m3|g/cm3]", 12330, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.d_v", \
"Density of vapour phase [kg/m3|g/cm3]", 12331, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.h_l", \
"Specific enthalpy of liquid phase [J/kg]", 12332, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.h_v", \
"Specific enthalpy of vapour phase [J/kg]", 12333, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.p_l", \
"Pressure of liquid phase [Pa|bar]", 12334, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.p_v", \
"Pressure of vapour phase [Pa|bar]", 12335, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.s_l", \
"Specific entropy of liquid phase [J/(kg.K)]", 12336, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.s_v", \
"Specific entropy of vapour phase [J/(kg.K)]", 12337, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.T_l", \
"Temperature of liquid phase [K|degC]", 12338, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLE.T_v", \
"Temperature of vapour phase [K|degC]", 12339, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLETransp.Pr_l", \
"Prandtl number of liquid phase [1]", 12340, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLETransp.Pr_v", \
"Prandtl number of vapour phase [1]", 12341, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLETransp.lambda_l", \
"Thermal conductivity of liquid phase [W/(m.K)]", 12342, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLETransp.lambda_v", \
"Thermal conductivity of vapour phase [W/(m.K)]", 12343, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLETransp.eta_l", \
"Dynamic viscosity of liquid phase [Pa.s]", 12344, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].properties.VLETransp.eta_v", \
"Dynamic viscosity of vapour phase [Pa.s]", 12345, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.transp.Pr", \
"Prandtl number [1]", "PF4U.tube1.gas[1].transp.Pr", 1, 5, 17148, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.transp.lambda", \
"Thermal conductivity [W/(m.K)]", "PF4U.tube1.gas[1].transp.lambda", 1, 5, 17149,\
 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.transp.eta", \
"Dynamic viscosity [Pa.s]", "PF4U.tube1.gas[1].transp.eta", 1, 5, 17150, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].properties.transp.sigma", \
"Surface tension [N/m]", "PF4U.tube1.gas[1].transp.sigma", 1, 5, 17151, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].cellGeometry.length", "[m]", \
"PF4U.tube1.tubeGeometry.length", 1, 5, 12209, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].cellGeometry.volume", "[m3]", \
"PF4U.tube1.tubeGeometry.innerVolume", 1, 5, 12215, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].cellGeometry.heatTransferArea", "[m2]",\
 "PF4U.tube1.tubeGeometry.innerHeatTransferArea", 1, 5, 12217, 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].cellGeometry.finHeatTransferAreaRatio",\
 "Fraction of fins on fin side heat transfer area", 12346, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].cellGeometry.hydraulicCrossSectionalArea",\
 "[m2]", 12347, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].cellGeometry.nParallelHydraulicFlows",\
 "Number of parallel flows", 12348, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDrop", "Pressure drop for one cell [Pa|bar]",\
 17171, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.pressureDrop", \
"Pressure drop for one cell [Pa|bar]", "PF4U.tube1.pressureDrop[1].pressureDrop", 1,\
 5, 17171, 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.computeTransportProperties",\
 "[:#(type=Boolean)]", 12349, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.mdotHydraulic",\
 "Hydraulic mass flow rate [kg/s]", "PF4U.tube1.mdotHydraulic", 1, 5, 17157, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.d",\
 "Density [kg/m3|g/cm3]", "PF4U.tube1.gas[1].d", 1, 5, 17136, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.h",\
 "Specific enthalpy [J/kg]", "PF4U.tube1.h[1]", 1, 1, 104, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.p",\
 "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.s",\
 "Specific entropy [J/(kg.K)]", "PF4U.tube1.gas[1].s", 1, 5, 17137, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.T",\
 "Temperature [K|degC]", "PF4U.tube1.T_gas_cell_[1]", 1, 5, 17197, 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.q",\
 "Steam mass fraction (quality) [1]", 12350, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.cp",\
 "Specific isobaric heat capacity cp [J/(kg.K)]", "PF4U.tube1.gas[1].cp", 1, 5, 17138,\
 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.crit.d",\
 "Critical density [kg/m3|g/cm3]", 12351, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.crit.h",\
 "Critical specific enthalpy [J/kg]", 12352, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.crit.p",\
 "Critical pressure [Pa|bar]", 12353, 0.0, 0.0,1.7976931348623157E+308,100000.0,\
0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.crit.s",\
 "Critical specific entropy [J/(kg.K)]", 12354, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.crit.T",\
 "Critical temperature [K|degC]", 12355, 0.0, 0.0,1.7976931348623157E+308,300.0,\
0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.d_l",\
 "Density of liquid phase [kg/m3|g/cm3]", 12356, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.d_v",\
 "Density of vapour phase [kg/m3|g/cm3]", 12357, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.h_l",\
 "Specific enthalpy of liquid phase [J/kg]", 12358, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.h_v",\
 "Specific enthalpy of vapour phase [J/kg]", 12359, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.p_l",\
 "Pressure of liquid phase [Pa|bar]", 12360, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.p_v",\
 "Pressure of vapour phase [Pa|bar]", 12361, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.s_l",\
 "Specific entropy of liquid phase [J/(kg.K)]", 12362, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.s_v",\
 "Specific entropy of vapour phase [J/(kg.K)]", 12363, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.T_l",\
 "Temperature of liquid phase [K|degC]", 12364, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLE.T_v",\
 "Temperature of vapour phase [K|degC]", 12365, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.Pr_l",\
 "Prandtl number of liquid phase [1]", 12366, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.Pr_v",\
 "Prandtl number of vapour phase [1]", 12367, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.lambda_l",\
 "Thermal conductivity of liquid phase [W/(m.K)]", 12368, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.lambda_v",\
 "Thermal conductivity of vapour phase [W/(m.K)]", 12369, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.eta_l",\
 "Dynamic viscosity of liquid phase [Pa.s]", 12370, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.eta_v",\
 "Dynamic viscosity of vapour phase [Pa.s]", 12371, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.transp.Pr",\
 "Prandtl number [1]", "PF4U.tube1.gas[1].transp.Pr", 1, 5, 17148, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.transp.lambda",\
 "Thermal conductivity [W/(m.K)]", "PF4U.tube1.gas[1].transp.lambda", 1, 5, 17149,\
 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.transp.eta",\
 "Dynamic viscosity [Pa.s]", "PF4U.tube1.gas[1].transp.eta", 1, 5, 17150, 1024)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.properties.transp.sigma",\
 "Surface tension [N/m]", "PF4U.tube1.gas[1].transp.sigma", 1, 5, 17151, 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.pressureDrop",\
 "Pressure drop [Pa|bar]", 17172, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.hydraulicDiameter",\
 "Hydraulic diameter [m]", 12372, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.hydraulicCrossSectionalArea",\
 "Cross-sectional area [m2]", 12373, 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.length", \
"Length [m]", "PF4U.tube1.tubeGeometry.length", 1, 5, 12209, 1024)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.Re", \
"Reynold's number [1]", 17173, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.v", \
"Velocity [m/s]", 17174, 0.0, 0.0,0.0,0.0,0,2624)
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
 "Darcy-Weisbach friction factor for turbulent flow", 17175, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.pressureDropLaminar",\
 "Laminar pressure drop model [Pa|bar]", 17176, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.pressureDropTurbulent",\
 "Turbulent pressure drop model [Pa|bar]", 17177, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.pressureDrop[1].pressureDropModel.konakov.weightingFactor",\
 "Factor for transition between laminar and turbulent zone [1]", 17178, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareParameter("PF4U.tube1.pressureDrop[1].pressureDropModel.correctionFactor",\
 "Linear correction factor for the pressureDrop calculated by this pressure drop model and its submodels. [1]",\
 1235, 1, 0.0,0.0,0.0,0,2608)
DeclareParameter("PF4U.tube1.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1236, 0.003, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.tube1.pInitial", "Initial value for gas pressure [Pa|bar]",\
 12374, 4000000, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube1.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 12375, true, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube1.TInitial", "Initial value for gas temperature [K|K]",\
 12376, 288.15, 0.0,1.7976931348623157E+308,300.0,0,513)
DeclareParameter("PF4U.tube1.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1237, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.tube1.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 12377, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.tube1.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1238, 1, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.tube1.massFlowRateHomotopy", "Nominal mass flow rate for linear valve equation [kg/s]",\
 1239, 0.01, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.tube1.pressureDropHomotopy", "Nominal pressure drop for linear valve equation [Pa|bar]",\
 1240, 10000.0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.tube1.hInitial", "[J/kg]", 12378, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.TInitialWall", "Initial value for wall temperature [K|K]",\
 12379, 288.15, 0.0,1.7976931348623157E+308,300.0,0,513)
DeclareVariable("PF4U.tube1.connectWallCells", "If true: wall cells should be connected W-E [:#(type=Boolean)]",\
 12380, false, 0.0,0.0,0.0,0,515)
DeclareAlias2("PF4U.tube1.wallCell[1].cellGeometry.length", "[m]", \
"PF4U.tube1.tubeGeometry.length", 1, 5, 12209, 1024)
DeclareVariable("PF4U.tube1.wallCell[1].cellGeometry.volume", "[m3]", 12381, 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.tube1.wallCell[1].portN.T", "Port temperature [K|degC]", \
"PF4U.Channel2.T_wall", 1, 5, 16986, 1028)
DeclareAlias2("PF4U.tube1.wallCell[1].portN.Q_flow", "Heat flow rate [W]", \
"PF4U.prescribedHeatFlow1.port.Q_flow", -1, 5, 17133, 1156)
DeclareAlias2("PF4U.tube1.wallCell[1].portS.T", "Port temperature [K|degC]", \
"PF4U.tube1.heatTransfer[1].wallTemperature", 1, 5, 17159, 1028)
DeclareVariable("PF4U.tube1.wallCell[1].portS.Q_flow", "Heat flow rate [W]", 17179,\
 0.0, 0.0,0.0,0.0,0,2824)
DeclareVariable("PF4U.tube1.wallCell[1].portW.T", "Port temperature [K|degC]", 17180,\
 0.0, 0.0,1.7976931348623157E+308,300.0,0,2568)
DeclareVariable("PF4U.tube1.wallCell[1].portW.Q_flow", "Heat flow rate [W]", 12382,\
 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube1.wallCell[1].portE.T", "Port temperature [K|degC]", 17181,\
 0.0, 0.0,1.7976931348623157E+308,300.0,0,2568)
DeclareVariable("PF4U.tube1.wallCell[1].portE.Q_flow", "Heat flow rate [W]", 12383,\
 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube1.wallCell[1].TInitialWall", "Initial wall temperature [K|degC]",\
 12384, 288.15, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].fixedTInitialWall", "if true, force usage of initial value TInitialWall [:#(type=Boolean)]",\
 12385, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube1.wallCell[1].initSteadyState", "[:#(type=Boolean)]", 12386,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube1.wallCell[1].additionalHeatCapacity", "[J/K]", 12387,\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].properties.d", "Density [kg/m3|g/cm3]", 12388,\
 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube1.wallCell[1].properties.T", "Temperature [K|degC]", \
"PF4U.tube1.wallCell[1].wallStateTemperature", 1, 1, 105, 1024)
DeclareVariable("PF4U.tube1.wallCell[1].properties.cp", "Heat capacity [J/(kg.K)]",\
 12389, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].properties.lambda", "Thermal conductivity [W/(m.K)]",\
 12390, 40.0, 0.0,0.0,0.0,0,2561)
DeclareState("PF4U.tube1.wallCell[1].wallStateTemperature", "[K|degC]", 105, 0.0,\
 0.0,1.7976931348623157E+308,300.0,0,2592)
DeclareDerivative("PF4U.tube1.wallCell[1].der(wallStateTemperature)", "[K/s]", 105,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.d", "Density [kg/m3|g/cm3]",\
 12391, 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube1.wallCell[1].wallMaterial.T", "Temperature [K|degC]", \
"PF4U.tube1.wallCell[1].wallStateTemperature", 1, 1, 105, 1024)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.cp", "Heat capacity [J/(kg.K)]",\
 12392, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.lambda", "Thermal conductivity [W/(m.K)]",\
 12393, 40.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.cp_nominal", \
"Specific heat capacity at standard reference point [J/(kg.K)]", 12394, 490.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.lambda_nominal", \
"Thermal conductivity at standard reference point [W/(m.K)]", 12395, 40.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.solid.cp_nominal", \
"Specific heat capacity at standard reference point [J/(kg.K)]", 12396, 490.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.solid.lambda_nominal", \
"Thermal conductivity at standard reference point [W/(m.K)]", 12397, 40.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.solid.d", "Density [kg/m3|g/cm3]",\
 12398, 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube1.wallCell[1].wallMaterial.solid.T", "Temperature [K|degC]",\
 "PF4U.tube1.wallCell[1].wallStateTemperature", 1, 1, 105, 1024)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.solid.cp", "Heat capacity [J/(kg.K)]",\
 12399, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].wallMaterial.solid.lambda", \
"Thermal conductivity [W/(m.K)]", 12400, 40.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].heatTransfer.R_WE", "Thermal resistance (W-E) for one cell [K/W]",\
 12401, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].heatTransfer.R_NS", "Thermal resistance (N-S) for one cell [K/W]",\
 12402, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].heatTransfer.connectWallCells", \
"[:#(type=Boolean)]", 12403, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube1.wallCell[1].heatTransfer.R_NS_total", \
"Thermal resistance (N-S) for total HX [K/W]", 12404, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].heatTransfer.R_WE_total", \
"Thermal resistance (W-E) for total HX [K/W]", 12405, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].geometricMass", "Geometric mass [kg]", 12406,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube1.wallCell[1].SProd_dot", "Produced entropy [W/K]", 17182,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube1.getInputsThermal[1].heatPort.T", "Port temperature [K|degC]",\
 "PF4U.tube1.heatTransfer[1].wallTemperature", 1, 5, 17159, 1028)
DeclareAlias2("PF4U.tube1.getInputsThermal[1].heatPort.Q_flow", "Heat flow rate [W]",\
 "PF4U.tube1.wallCell[1].portS.Q_flow", -1, 5, 17179, 1156)
DeclareVariable("PF4U.tube1.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12407, true, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.tube1.includeSummaryArrays", "Obsolete & unused parameter for array entries in summary [:#(type=Boolean)]",\
 1241, true, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube1.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12408, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube1.summary.p_gas_A", "Pressure at port A [Pa|bar]", \
"PF4U.junction2.p", 1, 1, 103, 0)
DeclareAlias2("PF4U.tube1.summary.p_gas_B", "Pressure at port B [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.tube1.summary.T_gas_A", "Temperature at port A [K|degC]", \
"PF4U.Channel2.T_gas_in", 1, 5, 16988, 0)
DeclareAlias2("PF4U.tube1.summary.T_gas_B", "Temperature at port B [K|degC]", \
"PF4U.Channel2.T_gas_out", 1, 5, 16987, 0)
DeclareVariable("PF4U.tube1.summary.T_degC_gas_A", "Temperature at port A [degC;]",\
 17183, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube1.summary.T_degC_gas_B", "Temperature at port B [degC;]",\
 17184, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube1.summary.h_gas_A", "Specific enthalpy at port A [J/kg]",\
 17185, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube1.summary.h_gas_B", "Specific enthalpy at port B [J/kg]",\
 17186, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube1.summary.d_gas_A", "Density at port A [kg/m3|g/cm3]",\
 17187, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.tube1.summary.d_gas_B", "Density at port B [kg/m3|g/cm3]",\
 17188, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareAlias2("PF4U.tube1.summary.m_flow_gas_A", "Mass flow rate at port A [kg/s]",\
 "PF4U.tube1.portA.m_flow", 1, 5, 17135, 0)
DeclareAlias2("PF4U.tube1.summary.m_flow_gas_B", "Mass flow rate at port B [kg/s]",\
 "PF4U.Channel2.m_flow", 1, 5, 16989, 0)
DeclareVariable("PF4U.tube1.summary.w_gas_A", "Flow velocity at port A [m/s]", 17189,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube1.summary.w_gas_B", "Flow velocity at port B [m/s]", 17190,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube1.summary.dp_gas", "Total pressure drop [Pa|bar]", 17191,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube1.summary.Q_flow_gas", "Total heat flow rate [W]", \
"PF4U.tube1.wallCell[1].portS.Q_flow", -1, 5, 17179, 0)
DeclareVariable("PF4U.tube1.summary.mass_gas", "Total fluid mass [kg]", 17192, \
0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareAlias2("PF4U.tube1.summary.volume_gas", "Total fluid volume [m3]", \
"PF4U.tube1.tubeGeometry.innerVolume", 1, 5, 12215, 0)
DeclareVariable("PF4U.tube1.summary.alpha_average_gas", "Average coefficient of heat transfer [W/(m2.K)]",\
 17193, 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube1.summary.mass_component", "Total component mass [kg]", \
"PF4U.tube1.wallCell[1].geometricMass", 1, 5, 12406, 0)
DeclareVariable("PF4U.tube1.summary.arrays.n", "[:#(type=Integer)]", 12409, 1, \
0.0,0.0,0.0,0,517)
DeclareAlias2("PF4U.tube1.summary.arrays.T_gas_cell[1]", "[K|degC]", \
"PF4U.tube1.T_gas_cell_[1]", 1, 5, 17197, 0)
DeclareVariable("PF4U.tube1.summary.arrays.T_degC_gas_cell[1]", "[degC;]", 17194,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube1.summary.arrays.T_wall_cell[1]", "[K|degC]", \
"PF4U.tube1.wallCell[1].wallStateTemperature", 1, 1, 105, 0)
DeclareVariable("PF4U.tube1.summary.arrays.T_degC_wall_cell[1]", "[degC;]", 17195,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube1.summary.arrays.p_gas_cell[1]", "[Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.tube1.summary.arrays.h_gas_cell[1]", "[J/kg]", \
"PF4U.tube1.h[1]", 1, 1, 104, 0)
DeclareAlias2("PF4U.tube1.summary.arrays.d_gas_cell[1]", "[kg/m3|g/cm3]", \
"PF4U.tube1.gas[1].d", 1, 5, 17136, 0)
DeclareVariable("PF4U.tube1.summary.arrays.alpha_gas_cell[1]", "Heat transfer coefficient [W/(m2.K)]",\
 17196, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube1.T_gas_cell_[1]", "[K|degC]", 17197, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.tube1.T_wall_cell_[1]", "[K|degC]", "PF4U.tube1.wallCell[1].wallStateTemperature", 1,\
 1, 105, 1024)
DeclareVariable("PF4U.tube1.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12410, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube1.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12411,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12412, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12413,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12414, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12415, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12416, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasA.gasPointer.id", "[:#(type=Integer)]", 12417, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.tube1.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1242, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube1.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12418, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube1.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12419,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12420, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12421,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12422, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube1.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12423, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12424, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube1.gasB.gasPointer.id", "[:#(type=Integer)]", 12425, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.tube1.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1243, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube1.fixedTInitialWall", "if true, force usage of initial value TInitialWall [:#(type=Boolean)]",\
 12426, false, 0.0,0.0,0.0,0,515)
DeclareAlias2("PF4U.tube1.heatPort[1].T", "Port temperature [K|degC]", \
"PF4U.Channel2.T_wall", 1, 5, 16986, 4)
DeclareAlias2("PF4U.tube1.heatPort[1].Q_flow", "Heat flow rate [W]", \
"PF4U.prescribedHeatFlow1.port.Q_flow", -1, 5, 17133, 132)
DeclareParameter("PF4U.prescribedHeatFlow2.T_ref", "Reference temperature [K|degC]",\
 1244, 293.15, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.prescribedHeatFlow2.alpha", "Temperature coefficient of heat flow rate [1/K]",\
 1245, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.prescribedHeatFlow2.Q_flow", "[W]", 17198, 0.0, 0.0,0.0,\
0.0,0,512)
DeclareAlias2("PF4U.prescribedHeatFlow2.port.T", "Port temperature [K|degC]", \
"PF4U.Channel3.T_wall", 1, 5, 16990, 4)
DeclareVariable("PF4U.prescribedHeatFlow2.port.Q_flow", "Heat flow rate (positive if flowing from outside into the component) [W]",\
 17199, 0, 0.0,0.0,0.0,0,776)
DeclareParameter("PF4U.stepSource2.transitionTime", "Duration of transition [s]",\
 1246, 0.5, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.stepSource2.initialValue", "Value before first step", 1247,\
 0.0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.stepSource2.stepTimes[1]", "Beginning of transitions [s]",\
 12427, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource2.stepTimes[2]", "Beginning of transitions [s]",\
 12428, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource2.stepValues[1]", "Values of steps", 12429, 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource2.stepValues[2]", "Values of steps", 12430, 0.0,\
 0.0,0.0,0.0,0,513)
DeclareAlias2("PF4U.stepSource2.y", "[W]", "PF4U.prescribedHeatFlow2.Q_flow", 1,\
 5, 17198, 0)
DeclareVariable("PF4U.stepSource2.stepCount", "[:#(type=Integer)]", 12431, 2, \
0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.stepSource2.const_finalValue.k", "Constant output value [W]",\
 12432, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.const_finalValue.y", "Connector of Real output signal [W]",\
 12433, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[1].switchTime", "[s]", 12434, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[1].transitionTime", "[s]", 12435, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[1].preSwitchValue", \
"Value to use before switching to input [W]", 12436, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[1].u", "[W]", 12437, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[1].y", "[W]", 17200, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("PF4U.stepSource2.timeSwitch[1].switchEndTime", "[s]", 12438, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[1].switchMidTime", "[s]", 12439, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[2].switchTime", "[s]", 12440, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[2].transitionTime", "[s]", 12441, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[2].preSwitchValue", \
"Value to use before switching to input [W]", 12442, 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.stepSource2.timeSwitch[2].u", "[W]", "PF4U.stepSource2.timeSwitch[1].y", 1,\
 5, 17200, 1024)
DeclareAlias2("PF4U.stepSource2.timeSwitch[2].y", "[W]", "PF4U.prescribedHeatFlow2.Q_flow", 1,\
 5, 17198, 1024)
DeclareVariable("PF4U.stepSource2.timeSwitch[2].switchEndTime", "[s]", 12443, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource2.timeSwitch[2].switchMidTime", "[s]", 12444, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12445, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube3.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 12446, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12447, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12448,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 12449, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12450, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12451, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.tubeGeometry.innerDiameter", "Inner diameter of circular tube [m]",\
 12452, 0.0, 0.0,1.7976931348623157E+308,0.0,0,513)
DeclareParameter("PF4U.tube3.tubeGeometry.wallThickness", "Wall thickness [m]", 1248,\
 0.0005, 0.0,1.7976931348623157E+308,0.0,0,560)
DeclareVariable("PF4U.tube3.tubeGeometry.length", "Length [m]", 12453, 0.0, 0.0,\
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
DeclareVariable("PF4U.tube3.tubeGeometry.outerDiameter", "[m]", 12454, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.innerCrossSectionalArea", \
"Inner cross-sectional area [m2]", 12455, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.outerCrossSectionalArea", \
"Outer cross-sectional area [m2]", 12456, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.hydraulicCrossSectionalArea", \
"Hydraulic cross sectional area [m2]", 12457, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.hydraulicDiameter", "Hydraulic diameter [m]",\
 12458, 0.0, 0.0,1.7976931348623157E+308,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.innerVolume", "Inner volume [m3]", 12459,\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.outerVolume", "Outer volume [m3]", 12460,\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.innerHeatTransferArea", "[m2]", 12461, \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube3.tubeGeometry.tubeIsCircular", "true, if tube's cross section is circular [:#(type=Boolean)]",\
 12462, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube3.simPort.vleFluidMass", "[kg]", 12463, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.simPort.vleFluidVolume", "[m3]", 12464, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.simPort.liquidMass", "[kg]", 12465, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("PF4U.tube3.simPort.liquidVolume", "[m3]", 12466, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("PF4U.tube3.simPort.gasMass", "[kg]", "PF4U.tube3.cellMass[1]", 1,\
 5, 17218, 1024)
DeclareAlias2("PF4U.tube3.simPort.gasVolume", "[m3]", "PF4U.tube3.tubeGeometry.innerVolume", 1,\
 5, 12459, 1024)
DeclareVariable("PF4U.tube3.simPort.dpdt", "", 12467, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.simPort.dpdtCounter", "", 12468, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 12469, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube3.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 12470, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube3.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 12471, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube3.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 12472, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.tube3.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.tube3.cellMass[1]", 1, 5, 17218, 1156)
DeclareAlias2("PF4U.tube3.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.tube3.tubeGeometry.innerVolume", 1, 5, 12459, 1156)
DeclareVariable("PF4U.tube3.simPort.dpdtPort.dpdt", "", 12473, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("PF4U.tube3.simPort.dpdtPort.counter", "", 12474, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.tube3.simPort.warningsPort.warnings", "Accumulated warnings",\
 12475, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube3.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12476, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube3.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12477,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube3.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12478, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12479,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12480, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12481, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12482, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.tube3.portA.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1, 1,\
 103, 4)
DeclareVariable("PF4U.tube3.portA.m_flow", "Mass flow rate [kg/s]", 17201, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.tube3.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.tube3.h[1]", 1, 1, 106, 4)
DeclareVariable("PF4U.tube3.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12483, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube3.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12484,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube3.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12485, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12486,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12487, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12488, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12489, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.tube3.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("PF4U.tube3.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.Channel3.m_flow", 1, 5, 16993, 132)
DeclareAlias2("PF4U.tube3.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.tube3.h[1]", 1, 1, 106, 4)
DeclareAlias2("PF4U.tube3.cellGeometry.length", "[m]", "PF4U.tube3.tubeGeometry.length", 1,\
 5, 12453, 1024)
DeclareAlias2("PF4U.tube3.cellGeometry.volume", "[m3]", "PF4U.tube3.tubeGeometry.innerVolume", 1,\
 5, 12459, 1024)
DeclareAlias2("PF4U.tube3.cellGeometry.heatTransferArea", "[m2]", \
"PF4U.tube3.tubeGeometry.innerHeatTransferArea", 1, 5, 12461, 1024)
DeclareParameter("PF4U.tube3.cellGeometry.finHeatTransferAreaRatio", \
"Fraction of fins on fin side heat transfer area", 1254, 0, 0.0,0.0,0.0,0,2608)
DeclareVariable("PF4U.tube3.cellGeometry.hydraulicCrossSectionalArea", "[m2]", 12490,\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.cellGeometry.nParallelHydraulicFlows", \
"Number of parallel flows [1]", 12491, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.dl[1]", "length portions of cells", 12492, 1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDropPosition", "Position of pressure drop in tube [:#(type=ThermalSystems.Internals.PressureDropPosition)]",\
 12493, 3, 1.0,3.0,0.0,0,517)
DeclareVariable("PF4U.tube3.nCells", "Discretization number of 'cells' [:#(type=Integer)]",\
 12494, 1, 0.0,0.0,0.0,0,517)
DeclareVariable("PF4U.tube3.enableHeatPorts", "true, if heat ports are enabled [:#(type=Boolean)]",\
 12495, true, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube3.generateEventsAtFlowReversal", "If true: Events will be generated at flow reversal [:#(type=Boolean)]",\
 12496, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube3.gas[1].gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12497, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube3.gas[1].gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12498,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube3.gas[1].gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12499, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gas[1].gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12500,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gas[1].gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12501, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gas[1].gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12502, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gas[1].gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12503, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gas[1].gasPointer.id", "[:#(type=Integer)]", 12504, 0,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.tube3.gas[1].stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 12505, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube3.gas[1].computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 12506, true, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube3.gas[1].d", "Density [kg/m3|g/cm3]", 17202, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.tube3.gas[1].p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 1024)
DeclareAlias2("PF4U.tube3.gas[1].h", "Specific enthalpy [J/kg]", \
"PF4U.tube3.h[1]", 1, 1, 106, 1024)
DeclareVariable("PF4U.tube3.gas[1].s", "Specific entropy [J/(kg.K)]", 17203, 0.0,\
 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube3.gas[1].T", "Temperature [K|degC]", "PF4U.tube3.T_gas_cell_[1]", 1,\
 5, 17263, 1024)
DeclareAlias2("PF4U.tube3.gas[1].M", "Average molar mass [kg/mol]", \
"PF4U.tube3.gas[1].M_i[1]", 1, 5, 12512, 1024)
DeclareVariable("PF4U.tube3.gas[1].cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17204, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17205, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].beta", "Isobaric thermal expansion coefficient [1/K]",\
 17206, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].kappa", "Isothermal compressibility [1/Pa]", 17207,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].w", "Speed of sound [m/s]", 17208, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17209, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17210, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].p_i[1]", "Partial pressure [Pa|bar]", 17211, \
0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17212, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].phi", "Relative humidity", 12507, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 12508, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].xi_s", "Saturation mass fraction of condensing component [1]",\
 12509, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 12510, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 12511, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17213, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].M_i[1]", "Molar mass of component i [kg/mol]",\
 12512, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].humRatio", "Content of condensing component aka humidity ratio [1]",\
 12513, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 12514, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 12515, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.gas[1].transp.Pr", "Prandtl number [1]", 17214, 0.0,\
 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].transp.lambda", "Thermal conductivity [W/(m.K)]",\
 17215, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].transp.eta", "Dynamic viscosity [Pa.s]", 17216,\
 0.0, -1.0,1.7976931348623157E+308,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].transp.sigma", "Surface tension [N/m]", 17217,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.gas[1].computeFlags", "[:#(type=Integer)]", 12516, 5,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.tube3.cellMass[1]", "Gas mass in one cell [kg]", 17218, \
0.0, 0.0,1.7976931348623157E+308,0.0,0,2560)
DeclareVariable("PF4U.tube3.drhodt[1]", "", 17219, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.p[1]", "[Pa|bar]", 17220, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2560)
DeclareAlias2("PF4U.tube3.der(p[1])", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18,\
 1024)
DeclareState("PF4U.tube3.h[1]", "Specific enthalpy [J/kg]", 106, 0.0, 0.0,0.0,\
100000.0,0,2592)
DeclareDerivative("PF4U.tube3.der(h[1])", "der(Specific enthalpy) [m2/s3]", 106,\
 0.0, 0.0,0.0,0.0,0,2624)
DeclareAlias2("PF4U.tube3.m_flow[1]", "[kg/s]", "PF4U.tube3.portA.m_flow", 1, 5,\
 17201, 1024)
DeclareAlias2("PF4U.tube3.m_flow[2]", "[kg/s]", "PF4U.Channel3.m_flow", -1, 5, 16993,\
 1024)
DeclareVariable("PF4U.tube3.H_flow[1]", "", 17221, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.H_flow[2]", "", 17222, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.mdotHydraulic", "[kg/s]", 17223, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube3.heatTransfer[1].mdotHydraulic", "Hydraulic mass flow rate [kg/s]",\
 "PF4U.tube3.mdotHydraulic", 1, 5, 17223, 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].QdotHydraulic", "Hydraulic heat flow rate [W]",\
 17224, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].wallTemperature", "Wall temperature [K|degC]",\
 17225, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.d", "Density [kg/m3|g/cm3]",\
 "PF4U.tube3.gas[1].d", 1, 5, 17202, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.h", "Specific enthalpy [J/kg]",\
 "PF4U.tube3.h[1]", 1, 1, 106, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.p", "Pressure [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.s", "Specific entropy [J/(kg.K)]",\
 "PF4U.tube3.gas[1].s", 1, 5, 17203, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.T", "Temperature [K|degC]",\
 "PF4U.tube3.T_gas_cell_[1]", 1, 5, 17263, 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.q", "Steam mass fraction (quality) [1]",\
 12517, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.tube3.gas[1].cp", 1, 5, 17204, 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.crit.d", "Critical density [kg/m3|g/cm3]",\
 12518, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.crit.h", "Critical specific enthalpy [J/kg]",\
 12519, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.crit.p", "Critical pressure [Pa|bar]",\
 12520, 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.crit.s", "Critical specific entropy [J/(kg.K)]",\
 12521, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.crit.T", "Critical temperature [K|degC]",\
 12522, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.d_l", \
"Density of liquid phase [kg/m3|g/cm3]", 12523, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.d_v", \
"Density of vapour phase [kg/m3|g/cm3]", 12524, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.h_l", \
"Specific enthalpy of liquid phase [J/kg]", 12525, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.h_v", \
"Specific enthalpy of vapour phase [J/kg]", 12526, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.p_l", \
"Pressure of liquid phase [Pa|bar]", 12527, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.p_v", \
"Pressure of vapour phase [Pa|bar]", 12528, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.s_l", \
"Specific entropy of liquid phase [J/(kg.K)]", 12529, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.s_v", \
"Specific entropy of vapour phase [J/(kg.K)]", 12530, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.T_l", \
"Temperature of liquid phase [K|degC]", 12531, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLE.T_v", \
"Temperature of vapour phase [K|degC]", 12532, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLETransp.Pr_l", \
"Prandtl number of liquid phase [1]", 12533, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLETransp.Pr_v", \
"Prandtl number of vapour phase [1]", 12534, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLETransp.lambda_l", \
"Thermal conductivity of liquid phase [W/(m.K)]", 12535, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLETransp.lambda_v", \
"Thermal conductivity of vapour phase [W/(m.K)]", 12536, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLETransp.eta_l", \
"Dynamic viscosity of liquid phase [Pa.s]", 12537, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].properties.VLETransp.eta_v", \
"Dynamic viscosity of vapour phase [Pa.s]", 12538, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.transp.Pr", \
"Prandtl number [1]", "PF4U.tube3.gas[1].transp.Pr", 1, 5, 17214, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.transp.lambda", \
"Thermal conductivity [W/(m.K)]", "PF4U.tube3.gas[1].transp.lambda", 1, 5, 17215,\
 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.transp.eta", \
"Dynamic viscosity [Pa.s]", "PF4U.tube3.gas[1].transp.eta", 1, 5, 17216, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].properties.transp.sigma", \
"Surface tension [N/m]", "PF4U.tube3.gas[1].transp.sigma", 1, 5, 17217, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].cellGeometry.length", "[m]", \
"PF4U.tube3.tubeGeometry.length", 1, 5, 12453, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].cellGeometry.volume", "[m3]", \
"PF4U.tube3.tubeGeometry.innerVolume", 1, 5, 12459, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].cellGeometry.heatTransferArea", "[m2]",\
 "PF4U.tube3.tubeGeometry.innerHeatTransferArea", 1, 5, 12461, 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].cellGeometry.finHeatTransferAreaRatio",\
 "Fraction of fins on fin side heat transfer area", 12539, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].cellGeometry.hydraulicCrossSectionalArea",\
 "[m2]", 12540, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].cellGeometry.nParallelHydraulicFlows",\
 "Number of parallel flows", 12541, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].alphaA", "Value for alphaA for one cell [W/K]",\
 17226, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.alphaA", "Value for alphaA for one cell [W/K]",\
 "PF4U.tube3.heatTransfer[1].alphaA", 1, 5, 17226, 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.computeTransportProperties",\
 "[:#(type=Boolean)]", 12542, true, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.useAlphaAState", \
"alphaA is a differential state [:#(type=Boolean)]", 12543, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.mdotHydraulic", \
"Hydraulic mass flow rate [kg/s]", "PF4U.tube3.mdotHydraulic", 1, 5, 17223, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.d", \
"Density [kg/m3|g/cm3]", "PF4U.tube3.gas[1].d", 1, 5, 17202, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.h", \
"Specific enthalpy [J/kg]", "PF4U.tube3.h[1]", 1, 1, 106, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.p", \
"Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.s", \
"Specific entropy [J/(kg.K)]", "PF4U.tube3.gas[1].s", 1, 5, 17203, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.T", \
"Temperature [K|degC]", "PF4U.tube3.T_gas_cell_[1]", 1, 5, 17263, 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.q", \
"Steam mass fraction (quality) [1]", 12544, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.cp", \
"Specific isobaric heat capacity cp [J/(kg.K)]", "PF4U.tube3.gas[1].cp", 1, 5, 17204,\
 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.crit.d",\
 "Critical density [kg/m3|g/cm3]", 12545, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.crit.h",\
 "Critical specific enthalpy [J/kg]", 12546, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.crit.p",\
 "Critical pressure [Pa|bar]", 12547, 0.0, 0.0,1.7976931348623157E+308,100000.0,\
0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.crit.s",\
 "Critical specific entropy [J/(kg.K)]", 12548, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.crit.T",\
 "Critical temperature [K|degC]", 12549, 0.0, 0.0,1.7976931348623157E+308,300.0,\
0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.d_l",\
 "Density of liquid phase [kg/m3|g/cm3]", 12550, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.d_v",\
 "Density of vapour phase [kg/m3|g/cm3]", 12551, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.h_l",\
 "Specific enthalpy of liquid phase [J/kg]", 12552, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.h_v",\
 "Specific enthalpy of vapour phase [J/kg]", 12553, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.p_l",\
 "Pressure of liquid phase [Pa|bar]", 12554, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.p_v",\
 "Pressure of vapour phase [Pa|bar]", 12555, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.s_l",\
 "Specific entropy of liquid phase [J/(kg.K)]", 12556, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.s_v",\
 "Specific entropy of vapour phase [J/(kg.K)]", 12557, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.T_l",\
 "Temperature of liquid phase [K|degC]", 12558, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLE.T_v",\
 "Temperature of vapour phase [K|degC]", 12559, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.Pr_l",\
 "Prandtl number of liquid phase [1]", 12560, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.Pr_v",\
 "Prandtl number of vapour phase [1]", 12561, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.lambda_l",\
 "Thermal conductivity of liquid phase [W/(m.K)]", 12562, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.lambda_v",\
 "Thermal conductivity of vapour phase [W/(m.K)]", 12563, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.eta_l",\
 "Dynamic viscosity of liquid phase [Pa.s]", 12564, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.eta_v",\
 "Dynamic viscosity of vapour phase [Pa.s]", 12565, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.transp.Pr",\
 "Prandtl number [1]", "PF4U.tube3.gas[1].transp.Pr", 1, 5, 17214, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.transp.lambda",\
 "Thermal conductivity [W/(m.K)]", "PF4U.tube3.gas[1].transp.lambda", 1, 5, 17215,\
 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.transp.eta",\
 "Dynamic viscosity [Pa.s]", "PF4U.tube3.gas[1].transp.eta", 1, 5, 17216, 1024)
DeclareAlias2("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.properties.transp.sigma",\
 "Surface tension [N/m]", "PF4U.tube3.gas[1].transp.sigma", 1, 5, 17217, 1024)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.alpha", \
"Coefficient of heat transfer [W/(m2.K)]", 17227, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.hydraulicDiameter",\
 "Hydraulic diameter [m]", 12566, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.hydraulicCrossSectionalArea",\
 "Hydraulic cross sectional area [m2]", 12567, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.Re", \
"Reynolds Number [1]", 17228, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.Nu", \
"Nusselt number [1]", 17229, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.averageVelocity", \
"Average velocity [m/s]", 17230, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.weightingFactor1", \
"", 17231, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.weightingFactor2", \
"", 17232, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.Nu1", "[1]", 17233,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.Nu_Gnielinski", \
"[1]", 17234, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.Nu_DittusBoelter", \
"[1]", 17235, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.heatTransfer[1].heatTransfer.gdb.zeta", "", 17236, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareParameter("PF4U.tube3.heatTransfer[1].heatTransfer.correctionFactor", \
"Linear correction factor for the overall alphaA calculated by this heat transfer model and its submodels. [1]",\
 1255, 1, 0.0,0.0,0.0,0,2608)
DeclareAlias2("PF4U.tube3.pressureDrop[1].mdotHydraulic", "Hydraulic mass flow rate [kg/s]",\
 "PF4U.tube3.mdotHydraulic", 1, 5, 17223, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.d", "Density [kg/m3|g/cm3]",\
 "PF4U.tube3.gas[1].d", 1, 5, 17202, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.h", "Specific enthalpy [J/kg]",\
 "PF4U.tube3.h[1]", 1, 1, 106, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.p", "Pressure [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.s", "Specific entropy [J/(kg.K)]",\
 "PF4U.tube3.gas[1].s", 1, 5, 17203, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.T", "Temperature [K|degC]",\
 "PF4U.tube3.T_gas_cell_[1]", 1, 5, 17263, 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.q", "Steam mass fraction (quality) [1]",\
 12568, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.tube3.gas[1].cp", 1, 5, 17204, 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.crit.d", "Critical density [kg/m3|g/cm3]",\
 12569, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.crit.h", "Critical specific enthalpy [J/kg]",\
 12570, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.crit.p", "Critical pressure [Pa|bar]",\
 12571, 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.crit.s", "Critical specific entropy [J/(kg.K)]",\
 12572, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.crit.T", "Critical temperature [K|degC]",\
 12573, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.d_l", \
"Density of liquid phase [kg/m3|g/cm3]", 12574, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.d_v", \
"Density of vapour phase [kg/m3|g/cm3]", 12575, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.h_l", \
"Specific enthalpy of liquid phase [J/kg]", 12576, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.h_v", \
"Specific enthalpy of vapour phase [J/kg]", 12577, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.p_l", \
"Pressure of liquid phase [Pa|bar]", 12578, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.p_v", \
"Pressure of vapour phase [Pa|bar]", 12579, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.s_l", \
"Specific entropy of liquid phase [J/(kg.K)]", 12580, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.s_v", \
"Specific entropy of vapour phase [J/(kg.K)]", 12581, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.T_l", \
"Temperature of liquid phase [K|degC]", 12582, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLE.T_v", \
"Temperature of vapour phase [K|degC]", 12583, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLETransp.Pr_l", \
"Prandtl number of liquid phase [1]", 12584, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLETransp.Pr_v", \
"Prandtl number of vapour phase [1]", 12585, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLETransp.lambda_l", \
"Thermal conductivity of liquid phase [W/(m.K)]", 12586, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLETransp.lambda_v", \
"Thermal conductivity of vapour phase [W/(m.K)]", 12587, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLETransp.eta_l", \
"Dynamic viscosity of liquid phase [Pa.s]", 12588, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].properties.VLETransp.eta_v", \
"Dynamic viscosity of vapour phase [Pa.s]", 12589, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.transp.Pr", \
"Prandtl number [1]", "PF4U.tube3.gas[1].transp.Pr", 1, 5, 17214, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.transp.lambda", \
"Thermal conductivity [W/(m.K)]", "PF4U.tube3.gas[1].transp.lambda", 1, 5, 17215,\
 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.transp.eta", \
"Dynamic viscosity [Pa.s]", "PF4U.tube3.gas[1].transp.eta", 1, 5, 17216, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].properties.transp.sigma", \
"Surface tension [N/m]", "PF4U.tube3.gas[1].transp.sigma", 1, 5, 17217, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].cellGeometry.length", "[m]", \
"PF4U.tube3.tubeGeometry.length", 1, 5, 12453, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].cellGeometry.volume", "[m3]", \
"PF4U.tube3.tubeGeometry.innerVolume", 1, 5, 12459, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].cellGeometry.heatTransferArea", "[m2]",\
 "PF4U.tube3.tubeGeometry.innerHeatTransferArea", 1, 5, 12461, 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].cellGeometry.finHeatTransferAreaRatio",\
 "Fraction of fins on fin side heat transfer area", 12590, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].cellGeometry.hydraulicCrossSectionalArea",\
 "[m2]", 12591, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].cellGeometry.nParallelHydraulicFlows",\
 "Number of parallel flows", 12592, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDrop", "Pressure drop for one cell [Pa|bar]",\
 17237, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.pressureDrop", \
"Pressure drop for one cell [Pa|bar]", "PF4U.tube3.pressureDrop[1].pressureDrop", 1,\
 5, 17237, 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.computeTransportProperties",\
 "[:#(type=Boolean)]", 12593, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.mdotHydraulic",\
 "Hydraulic mass flow rate [kg/s]", "PF4U.tube3.mdotHydraulic", 1, 5, 17223, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.d",\
 "Density [kg/m3|g/cm3]", "PF4U.tube3.gas[1].d", 1, 5, 17202, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.h",\
 "Specific enthalpy [J/kg]", "PF4U.tube3.h[1]", 1, 1, 106, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.p",\
 "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.s",\
 "Specific entropy [J/(kg.K)]", "PF4U.tube3.gas[1].s", 1, 5, 17203, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.T",\
 "Temperature [K|degC]", "PF4U.tube3.T_gas_cell_[1]", 1, 5, 17263, 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.q",\
 "Steam mass fraction (quality) [1]", 12594, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.cp",\
 "Specific isobaric heat capacity cp [J/(kg.K)]", "PF4U.tube3.gas[1].cp", 1, 5, 17204,\
 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.crit.d",\
 "Critical density [kg/m3|g/cm3]", 12595, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.crit.h",\
 "Critical specific enthalpy [J/kg]", 12596, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.crit.p",\
 "Critical pressure [Pa|bar]", 12597, 0.0, 0.0,1.7976931348623157E+308,100000.0,\
0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.crit.s",\
 "Critical specific entropy [J/(kg.K)]", 12598, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.crit.T",\
 "Critical temperature [K|degC]", 12599, 0.0, 0.0,1.7976931348623157E+308,300.0,\
0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.d_l",\
 "Density of liquid phase [kg/m3|g/cm3]", 12600, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.d_v",\
 "Density of vapour phase [kg/m3|g/cm3]", 12601, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.h_l",\
 "Specific enthalpy of liquid phase [J/kg]", 12602, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.h_v",\
 "Specific enthalpy of vapour phase [J/kg]", 12603, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.p_l",\
 "Pressure of liquid phase [Pa|bar]", 12604, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.p_v",\
 "Pressure of vapour phase [Pa|bar]", 12605, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.s_l",\
 "Specific entropy of liquid phase [J/(kg.K)]", 12606, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.s_v",\
 "Specific entropy of vapour phase [J/(kg.K)]", 12607, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.T_l",\
 "Temperature of liquid phase [K|degC]", 12608, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLE.T_v",\
 "Temperature of vapour phase [K|degC]", 12609, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.Pr_l",\
 "Prandtl number of liquid phase [1]", 12610, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.Pr_v",\
 "Prandtl number of vapour phase [1]", 12611, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.lambda_l",\
 "Thermal conductivity of liquid phase [W/(m.K)]", 12612, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.lambda_v",\
 "Thermal conductivity of vapour phase [W/(m.K)]", 12613, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.eta_l",\
 "Dynamic viscosity of liquid phase [Pa.s]", 12614, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.eta_v",\
 "Dynamic viscosity of vapour phase [Pa.s]", 12615, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.transp.Pr",\
 "Prandtl number [1]", "PF4U.tube3.gas[1].transp.Pr", 1, 5, 17214, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.transp.lambda",\
 "Thermal conductivity [W/(m.K)]", "PF4U.tube3.gas[1].transp.lambda", 1, 5, 17215,\
 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.transp.eta",\
 "Dynamic viscosity [Pa.s]", "PF4U.tube3.gas[1].transp.eta", 1, 5, 17216, 1024)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.properties.transp.sigma",\
 "Surface tension [N/m]", "PF4U.tube3.gas[1].transp.sigma", 1, 5, 17217, 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.pressureDrop",\
 "Pressure drop [Pa|bar]", 17238, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.hydraulicDiameter",\
 "Hydraulic diameter [m]", 12616, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.hydraulicCrossSectionalArea",\
 "Cross-sectional area [m2]", 12617, 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.length", \
"Length [m]", "PF4U.tube3.tubeGeometry.length", 1, 5, 12453, 1024)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.Re", \
"Reynold's number [1]", 17239, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.v", \
"Velocity [m/s]", 17240, 0.0, 0.0,0.0,0.0,0,2624)
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
 "Darcy-Weisbach friction factor for turbulent flow", 17241, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.pressureDropLaminar",\
 "Laminar pressure drop model [Pa|bar]", 17242, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.pressureDropTurbulent",\
 "Turbulent pressure drop model [Pa|bar]", 17243, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.pressureDrop[1].pressureDropModel.konakov.weightingFactor",\
 "Factor for transition between laminar and turbulent zone [1]", 17244, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareParameter("PF4U.tube3.pressureDrop[1].pressureDropModel.correctionFactor",\
 "Linear correction factor for the pressureDrop calculated by this pressure drop model and its submodels. [1]",\
 1259, 1, 0.0,0.0,0.0,0,2608)
DeclareParameter("PF4U.tube3.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1260, 0.003, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.tube3.pInitial", "Initial value for gas pressure [Pa|bar]",\
 12618, 4000000, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube3.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 12619, true, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube3.TInitial", "Initial value for gas temperature [K|K]",\
 12620, 288.15, 0.0,1.7976931348623157E+308,300.0,0,513)
DeclareParameter("PF4U.tube3.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1261, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.tube3.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 12621, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.tube3.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1262, 1, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.tube3.massFlowRateHomotopy", "Nominal mass flow rate for linear valve equation [kg/s]",\
 1263, 0.01, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.tube3.pressureDropHomotopy", "Nominal pressure drop for linear valve equation [Pa|bar]",\
 1264, 10000.0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.tube3.hInitial", "[J/kg]", 12622, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.TInitialWall", "Initial value for wall temperature [K|K]",\
 12623, 288.15, 0.0,1.7976931348623157E+308,300.0,0,513)
DeclareVariable("PF4U.tube3.connectWallCells", "If true: wall cells should be connected W-E [:#(type=Boolean)]",\
 12624, false, 0.0,0.0,0.0,0,515)
DeclareAlias2("PF4U.tube3.wallCell[1].cellGeometry.length", "[m]", \
"PF4U.tube3.tubeGeometry.length", 1, 5, 12453, 1024)
DeclareVariable("PF4U.tube3.wallCell[1].cellGeometry.volume", "[m3]", 12625, 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.tube3.wallCell[1].portN.T", "Port temperature [K|degC]", \
"PF4U.Channel3.T_wall", 1, 5, 16990, 1028)
DeclareAlias2("PF4U.tube3.wallCell[1].portN.Q_flow", "Heat flow rate [W]", \
"PF4U.prescribedHeatFlow2.port.Q_flow", -1, 5, 17199, 1156)
DeclareAlias2("PF4U.tube3.wallCell[1].portS.T", "Port temperature [K|degC]", \
"PF4U.tube3.heatTransfer[1].wallTemperature", 1, 5, 17225, 1028)
DeclareVariable("PF4U.tube3.wallCell[1].portS.Q_flow", "Heat flow rate [W]", 17245,\
 0.0, 0.0,0.0,0.0,0,2824)
DeclareVariable("PF4U.tube3.wallCell[1].portW.T", "Port temperature [K|degC]", 17246,\
 0.0, 0.0,1.7976931348623157E+308,300.0,0,2568)
DeclareVariable("PF4U.tube3.wallCell[1].portW.Q_flow", "Heat flow rate [W]", 12626,\
 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube3.wallCell[1].portE.T", "Port temperature [K|degC]", 17247,\
 0.0, 0.0,1.7976931348623157E+308,300.0,0,2568)
DeclareVariable("PF4U.tube3.wallCell[1].portE.Q_flow", "Heat flow rate [W]", 12627,\
 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube3.wallCell[1].TInitialWall", "Initial wall temperature [K|degC]",\
 12628, 288.15, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].fixedTInitialWall", "if true, force usage of initial value TInitialWall [:#(type=Boolean)]",\
 12629, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube3.wallCell[1].initSteadyState", "[:#(type=Boolean)]", 12630,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube3.wallCell[1].additionalHeatCapacity", "[J/K]", 12631,\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].properties.d", "Density [kg/m3|g/cm3]", 12632,\
 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube3.wallCell[1].properties.T", "Temperature [K|degC]", \
"PF4U.tube3.wallCell[1].wallStateTemperature", 1, 1, 107, 1024)
DeclareVariable("PF4U.tube3.wallCell[1].properties.cp", "Heat capacity [J/(kg.K)]",\
 12633, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].properties.lambda", "Thermal conductivity [W/(m.K)]",\
 12634, 40.0, 0.0,0.0,0.0,0,2561)
DeclareState("PF4U.tube3.wallCell[1].wallStateTemperature", "[K|degC]", 107, 0.0,\
 0.0,1.7976931348623157E+308,300.0,0,2592)
DeclareDerivative("PF4U.tube3.wallCell[1].der(wallStateTemperature)", "[K/s]", 107,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.d", "Density [kg/m3|g/cm3]",\
 12635, 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube3.wallCell[1].wallMaterial.T", "Temperature [K|degC]", \
"PF4U.tube3.wallCell[1].wallStateTemperature", 1, 1, 107, 1024)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.cp", "Heat capacity [J/(kg.K)]",\
 12636, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.lambda", "Thermal conductivity [W/(m.K)]",\
 12637, 40.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.cp_nominal", \
"Specific heat capacity at standard reference point [J/(kg.K)]", 12638, 490.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.lambda_nominal", \
"Thermal conductivity at standard reference point [W/(m.K)]", 12639, 40.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.solid.cp_nominal", \
"Specific heat capacity at standard reference point [J/(kg.K)]", 12640, 490.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.solid.lambda_nominal", \
"Thermal conductivity at standard reference point [W/(m.K)]", 12641, 40.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.solid.d", "Density [kg/m3|g/cm3]",\
 12642, 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube3.wallCell[1].wallMaterial.solid.T", "Temperature [K|degC]",\
 "PF4U.tube3.wallCell[1].wallStateTemperature", 1, 1, 107, 1024)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.solid.cp", "Heat capacity [J/(kg.K)]",\
 12643, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].wallMaterial.solid.lambda", \
"Thermal conductivity [W/(m.K)]", 12644, 40.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].heatTransfer.R_WE", "Thermal resistance (W-E) for one cell [K/W]",\
 12645, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].heatTransfer.R_NS", "Thermal resistance (N-S) for one cell [K/W]",\
 12646, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].heatTransfer.connectWallCells", \
"[:#(type=Boolean)]", 12647, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube3.wallCell[1].heatTransfer.R_NS_total", \
"Thermal resistance (N-S) for total HX [K/W]", 12648, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].heatTransfer.R_WE_total", \
"Thermal resistance (W-E) for total HX [K/W]", 12649, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].geometricMass", "Geometric mass [kg]", 12650,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube3.wallCell[1].SProd_dot", "Produced entropy [W/K]", 17248,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube3.getInputsThermal[1].heatPort.T", "Port temperature [K|degC]",\
 "PF4U.tube3.heatTransfer[1].wallTemperature", 1, 5, 17225, 1028)
DeclareAlias2("PF4U.tube3.getInputsThermal[1].heatPort.Q_flow", "Heat flow rate [W]",\
 "PF4U.tube3.wallCell[1].portS.Q_flow", -1, 5, 17245, 1156)
DeclareVariable("PF4U.tube3.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12651, true, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.tube3.includeSummaryArrays", "Obsolete & unused parameter for array entries in summary [:#(type=Boolean)]",\
 1265, true, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube3.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12652, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube3.summary.p_gas_A", "Pressure at port A [Pa|bar]", \
"PF4U.junction2.p", 1, 1, 103, 0)
DeclareAlias2("PF4U.tube3.summary.p_gas_B", "Pressure at port B [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.tube3.summary.T_gas_A", "Temperature at port A [K|degC]", \
"PF4U.Channel3.T_gas_in", 1, 5, 16992, 0)
DeclareAlias2("PF4U.tube3.summary.T_gas_B", "Temperature at port B [K|degC]", \
"PF4U.Channel3.T_gas_out", 1, 5, 16991, 0)
DeclareVariable("PF4U.tube3.summary.T_degC_gas_A", "Temperature at port A [degC;]",\
 17249, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube3.summary.T_degC_gas_B", "Temperature at port B [degC;]",\
 17250, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube3.summary.h_gas_A", "Specific enthalpy at port A [J/kg]",\
 17251, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube3.summary.h_gas_B", "Specific enthalpy at port B [J/kg]",\
 17252, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube3.summary.d_gas_A", "Density at port A [kg/m3|g/cm3]",\
 17253, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.tube3.summary.d_gas_B", "Density at port B [kg/m3|g/cm3]",\
 17254, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareAlias2("PF4U.tube3.summary.m_flow_gas_A", "Mass flow rate at port A [kg/s]",\
 "PF4U.tube3.portA.m_flow", 1, 5, 17201, 0)
DeclareAlias2("PF4U.tube3.summary.m_flow_gas_B", "Mass flow rate at port B [kg/s]",\
 "PF4U.Channel3.m_flow", 1, 5, 16993, 0)
DeclareVariable("PF4U.tube3.summary.w_gas_A", "Flow velocity at port A [m/s]", 17255,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube3.summary.w_gas_B", "Flow velocity at port B [m/s]", 17256,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube3.summary.dp_gas", "Total pressure drop [Pa|bar]", 17257,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube3.summary.Q_flow_gas", "Total heat flow rate [W]", \
"PF4U.tube3.wallCell[1].portS.Q_flow", -1, 5, 17245, 0)
DeclareVariable("PF4U.tube3.summary.mass_gas", "Total fluid mass [kg]", 17258, \
0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareAlias2("PF4U.tube3.summary.volume_gas", "Total fluid volume [m3]", \
"PF4U.tube3.tubeGeometry.innerVolume", 1, 5, 12459, 0)
DeclareVariable("PF4U.tube3.summary.alpha_average_gas", "Average coefficient of heat transfer [W/(m2.K)]",\
 17259, 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube3.summary.mass_component", "Total component mass [kg]", \
"PF4U.tube3.wallCell[1].geometricMass", 1, 5, 12650, 0)
DeclareVariable("PF4U.tube3.summary.arrays.n", "[:#(type=Integer)]", 12653, 1, \
0.0,0.0,0.0,0,517)
DeclareAlias2("PF4U.tube3.summary.arrays.T_gas_cell[1]", "[K|degC]", \
"PF4U.tube3.T_gas_cell_[1]", 1, 5, 17263, 0)
DeclareVariable("PF4U.tube3.summary.arrays.T_degC_gas_cell[1]", "[degC;]", 17260,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube3.summary.arrays.T_wall_cell[1]", "[K|degC]", \
"PF4U.tube3.wallCell[1].wallStateTemperature", 1, 1, 107, 0)
DeclareVariable("PF4U.tube3.summary.arrays.T_degC_wall_cell[1]", "[degC;]", 17261,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube3.summary.arrays.p_gas_cell[1]", "[Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.tube3.summary.arrays.h_gas_cell[1]", "[J/kg]", \
"PF4U.tube3.h[1]", 1, 1, 106, 0)
DeclareAlias2("PF4U.tube3.summary.arrays.d_gas_cell[1]", "[kg/m3|g/cm3]", \
"PF4U.tube3.gas[1].d", 1, 5, 17202, 0)
DeclareVariable("PF4U.tube3.summary.arrays.alpha_gas_cell[1]", "Heat transfer coefficient [W/(m2.K)]",\
 17262, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube3.T_gas_cell_[1]", "[K|degC]", 17263, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.tube3.T_wall_cell_[1]", "[K|degC]", "PF4U.tube3.wallCell[1].wallStateTemperature", 1,\
 1, 107, 1024)
DeclareVariable("PF4U.tube3.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12654, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube3.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12655,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12656, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12657,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12658, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12659, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12660, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasA.gasPointer.id", "[:#(type=Integer)]", 12661, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.tube3.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1266, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube3.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12662, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube3.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12663,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12664, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12665,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12666, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube3.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12667, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12668, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube3.gasB.gasPointer.id", "[:#(type=Integer)]", 12669, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.tube3.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1267, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube3.fixedTInitialWall", "if true, force usage of initial value TInitialWall [:#(type=Boolean)]",\
 12670, false, 0.0,0.0,0.0,0,515)
DeclareAlias2("PF4U.tube3.heatPort[1].T", "Port temperature [K|degC]", \
"PF4U.Channel3.T_wall", 1, 5, 16990, 4)
DeclareAlias2("PF4U.tube3.heatPort[1].Q_flow", "Heat flow rate [W]", \
"PF4U.prescribedHeatFlow2.port.Q_flow", -1, 5, 17199, 132)
DeclareParameter("PF4U.prescribedHeatFlow3.T_ref", "Reference temperature [K|degC]",\
 1268, 293.15, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.prescribedHeatFlow3.alpha", "Temperature coefficient of heat flow rate [1/K]",\
 1269, 0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.prescribedHeatFlow3.Q_flow", "[W]", 17264, 0.0, 0.0,0.0,\
0.0,0,512)
DeclareAlias2("PF4U.prescribedHeatFlow3.port.T", "Port temperature [K|degC]", \
"PF4U.Channel4.T_wall", 1, 5, 16994, 4)
DeclareVariable("PF4U.prescribedHeatFlow3.port.Q_flow", "Heat flow rate (positive if flowing from outside into the component) [W]",\
 17265, 0, 0.0,0.0,0.0,0,776)
DeclareParameter("PF4U.stepSource3.transitionTime", "Duration of transition [s]",\
 1270, 0.5, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.stepSource3.initialValue", "Value before first step", 1271,\
 0.0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.stepSource3.stepTimes[1]", "Beginning of transitions [s]",\
 12671, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource3.stepTimes[2]", "Beginning of transitions [s]",\
 12672, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource3.stepValues[1]", "Values of steps", 12673, 0.0,\
 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.stepSource3.stepValues[2]", "Values of steps", 12674, 0.0,\
 0.0,0.0,0.0,0,513)
DeclareAlias2("PF4U.stepSource3.y", "[W]", "PF4U.prescribedHeatFlow3.Q_flow", 1,\
 5, 17264, 0)
DeclareVariable("PF4U.stepSource3.stepCount", "[:#(type=Integer)]", 12675, 2, \
0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.stepSource3.const_finalValue.k", "Constant output value [W]",\
 12676, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.const_finalValue.y", "Connector of Real output signal [W]",\
 12677, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[1].switchTime", "[s]", 12678, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[1].transitionTime", "[s]", 12679, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[1].preSwitchValue", \
"Value to use before switching to input [W]", 12680, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[1].u", "[W]", 12681, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[1].y", "[W]", 17266, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("PF4U.stepSource3.timeSwitch[1].switchEndTime", "[s]", 12682, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[1].switchMidTime", "[s]", 12683, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[2].switchTime", "[s]", 12684, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[2].transitionTime", "[s]", 12685, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[2].preSwitchValue", \
"Value to use before switching to input [W]", 12686, 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.stepSource3.timeSwitch[2].u", "[W]", "PF4U.stepSource3.timeSwitch[1].y", 1,\
 5, 17266, 1024)
DeclareAlias2("PF4U.stepSource3.timeSwitch[2].y", "[W]", "PF4U.prescribedHeatFlow3.Q_flow", 1,\
 5, 17264, 1024)
DeclareVariable("PF4U.stepSource3.timeSwitch[2].switchEndTime", "[s]", 12687, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.stepSource3.timeSwitch[2].switchMidTime", "[s]", 12688, \
0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12689, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube4.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 12690, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12691, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12692,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 12693, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12694, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12695, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.tubeGeometry.innerDiameter", "Inner diameter of circular tube [m]",\
 12696, 0.0, 0.0,1.7976931348623157E+308,0.0,0,513)
DeclareParameter("PF4U.tube4.tubeGeometry.wallThickness", "Wall thickness [m]", 1272,\
 0.0005, 0.0,1.7976931348623157E+308,0.0,0,560)
DeclareVariable("PF4U.tube4.tubeGeometry.length", "Length [m]", 12697, 0.0, 0.0,\
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
DeclareVariable("PF4U.tube4.tubeGeometry.outerDiameter", "[m]", 12698, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.innerCrossSectionalArea", \
"Inner cross-sectional area [m2]", 12699, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.outerCrossSectionalArea", \
"Outer cross-sectional area [m2]", 12700, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.hydraulicCrossSectionalArea", \
"Hydraulic cross sectional area [m2]", 12701, 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.hydraulicDiameter", "Hydraulic diameter [m]",\
 12702, 0.0, 0.0,1.7976931348623157E+308,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.innerVolume", "Inner volume [m3]", 12703,\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.outerVolume", "Outer volume [m3]", 12704,\
 0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.innerHeatTransferArea", "[m2]", 12705, \
0.0, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube4.tubeGeometry.tubeIsCircular", "true, if tube's cross section is circular [:#(type=Boolean)]",\
 12706, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube4.simPort.vleFluidMass", "[kg]", 12707, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.simPort.vleFluidVolume", "[m3]", 12708, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.simPort.liquidMass", "[kg]", 12709, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("PF4U.tube4.simPort.liquidVolume", "[m3]", 12710, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("PF4U.tube4.simPort.gasMass", "[kg]", "PF4U.tube4.cellMass[1]", 1,\
 5, 17284, 1024)
DeclareAlias2("PF4U.tube4.simPort.gasVolume", "[m3]", "PF4U.tube4.tubeGeometry.innerVolume", 1,\
 5, 12703, 1024)
DeclareVariable("PF4U.tube4.simPort.dpdt", "", 12711, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.simPort.dpdtCounter", "", 12712, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 12713, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube4.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 12714, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube4.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 12715, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube4.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 12716, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.tube4.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.tube4.cellMass[1]", 1, 5, 17284, 1156)
DeclareAlias2("PF4U.tube4.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.tube4.tubeGeometry.innerVolume", 1, 5, 12703, 1156)
DeclareVariable("PF4U.tube4.simPort.dpdtPort.dpdt", "", 12717, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("PF4U.tube4.simPort.dpdtPort.counter", "", 12718, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.tube4.simPort.warningsPort.warnings", "Accumulated warnings",\
 12719, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube4.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12720, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube4.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12721,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube4.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12722, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12723,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12724, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12725, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12726, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.tube4.portA.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1, 1,\
 103, 4)
DeclareVariable("PF4U.tube4.portA.m_flow", "Mass flow rate [kg/s]", 17267, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.tube4.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.tube4.h[1]", 1, 1, 108, 4)
DeclareVariable("PF4U.tube4.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12727, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube4.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12728,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube4.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12729, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12730,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12731, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12732, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12733, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.tube4.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("PF4U.tube4.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.Channel4.m_flow", 1, 5, 16997, 132)
DeclareAlias2("PF4U.tube4.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.tube4.h[1]", 1, 1, 108, 4)
DeclareAlias2("PF4U.tube4.cellGeometry.length", "[m]", "PF4U.tube4.tubeGeometry.length", 1,\
 5, 12697, 1024)
DeclareAlias2("PF4U.tube4.cellGeometry.volume", "[m3]", "PF4U.tube4.tubeGeometry.innerVolume", 1,\
 5, 12703, 1024)
DeclareAlias2("PF4U.tube4.cellGeometry.heatTransferArea", "[m2]", \
"PF4U.tube4.tubeGeometry.innerHeatTransferArea", 1, 5, 12705, 1024)
DeclareParameter("PF4U.tube4.cellGeometry.finHeatTransferAreaRatio", \
"Fraction of fins on fin side heat transfer area", 1278, 0, 0.0,0.0,0.0,0,2608)
DeclareVariable("PF4U.tube4.cellGeometry.hydraulicCrossSectionalArea", "[m2]", 12734,\
 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.cellGeometry.nParallelHydraulicFlows", \
"Number of parallel flows [1]", 12735, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.dl[1]", "length portions of cells", 12736, 1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDropPosition", "Position of pressure drop in tube [:#(type=ThermalSystems.Internals.PressureDropPosition)]",\
 12737, 3, 1.0,3.0,0.0,0,517)
DeclareVariable("PF4U.tube4.nCells", "Discretization number of 'cells' [:#(type=Integer)]",\
 12738, 1, 0.0,0.0,0.0,0,517)
DeclareVariable("PF4U.tube4.enableHeatPorts", "true, if heat ports are enabled [:#(type=Boolean)]",\
 12739, true, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube4.generateEventsAtFlowReversal", "If true: Events will be generated at flow reversal [:#(type=Boolean)]",\
 12740, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube4.gas[1].gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12741, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube4.gas[1].gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12742,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube4.gas[1].gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12743, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gas[1].gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12744,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gas[1].gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12745, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gas[1].gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12746, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gas[1].gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12747, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gas[1].gasPointer.id", "[:#(type=Integer)]", 12748, 0,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.tube4.gas[1].stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 12749, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube4.gas[1].computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 12750, true, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube4.gas[1].d", "Density [kg/m3|g/cm3]", 17268, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.tube4.gas[1].p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 1024)
DeclareAlias2("PF4U.tube4.gas[1].h", "Specific enthalpy [J/kg]", \
"PF4U.tube4.h[1]", 1, 1, 108, 1024)
DeclareVariable("PF4U.tube4.gas[1].s", "Specific entropy [J/(kg.K)]", 17269, 0.0,\
 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube4.gas[1].T", "Temperature [K|degC]", "PF4U.tube4.T_gas_cell_[1]", 1,\
 5, 17329, 1024)
DeclareAlias2("PF4U.tube4.gas[1].M", "Average molar mass [kg/mol]", \
"PF4U.tube4.gas[1].M_i[1]", 1, 5, 12756, 1024)
DeclareVariable("PF4U.tube4.gas[1].cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17270, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17271, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].beta", "Isobaric thermal expansion coefficient [1/K]",\
 17272, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].kappa", "Isothermal compressibility [1/Pa]", 17273,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].w", "Speed of sound [m/s]", 17274, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17275, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17276, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].p_i[1]", "Partial pressure [Pa|bar]", 17277, \
0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17278, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].phi", "Relative humidity", 12751, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 12752, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].xi_s", "Saturation mass fraction of condensing component [1]",\
 12753, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 12754, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 12755, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17279, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].M_i[1]", "Molar mass of component i [kg/mol]",\
 12756, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].humRatio", "Content of condensing component aka humidity ratio [1]",\
 12757, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 12758, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 12759, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.gas[1].transp.Pr", "Prandtl number [1]", 17280, 0.0,\
 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].transp.lambda", "Thermal conductivity [W/(m.K)]",\
 17281, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].transp.eta", "Dynamic viscosity [Pa.s]", 17282,\
 0.0, -1.0,1.7976931348623157E+308,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].transp.sigma", "Surface tension [N/m]", 17283,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.gas[1].computeFlags", "[:#(type=Integer)]", 12760, 5,\
 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.tube4.cellMass[1]", "Gas mass in one cell [kg]", 17284, \
0.0, 0.0,1.7976931348623157E+308,0.0,0,2560)
DeclareVariable("PF4U.tube4.drhodt[1]", "", 17285, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.p[1]", "[Pa|bar]", 17286, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2560)
DeclareAlias2("PF4U.tube4.der(p[1])", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18,\
 1024)
DeclareState("PF4U.tube4.h[1]", "Specific enthalpy [J/kg]", 108, 0.0, 0.0,0.0,\
100000.0,0,2592)
DeclareDerivative("PF4U.tube4.der(h[1])", "der(Specific enthalpy) [m2/s3]", 108,\
 0.0, 0.0,0.0,0.0,0,2624)
DeclareAlias2("PF4U.tube4.m_flow[1]", "[kg/s]", "PF4U.tube4.portA.m_flow", 1, 5,\
 17267, 1024)
DeclareAlias2("PF4U.tube4.m_flow[2]", "[kg/s]", "PF4U.Channel4.m_flow", -1, 5, 16997,\
 1024)
DeclareVariable("PF4U.tube4.H_flow[1]", "", 17287, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.H_flow[2]", "", 17288, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.mdotHydraulic", "[kg/s]", 17289, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube4.heatTransfer[1].mdotHydraulic", "Hydraulic mass flow rate [kg/s]",\
 "PF4U.tube4.mdotHydraulic", 1, 5, 17289, 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].QdotHydraulic", "Hydraulic heat flow rate [W]",\
 17290, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].wallTemperature", "Wall temperature [K|degC]",\
 17291, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.d", "Density [kg/m3|g/cm3]",\
 "PF4U.tube4.gas[1].d", 1, 5, 17268, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.h", "Specific enthalpy [J/kg]",\
 "PF4U.tube4.h[1]", 1, 1, 108, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.p", "Pressure [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.s", "Specific entropy [J/(kg.K)]",\
 "PF4U.tube4.gas[1].s", 1, 5, 17269, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.T", "Temperature [K|degC]",\
 "PF4U.tube4.T_gas_cell_[1]", 1, 5, 17329, 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.q", "Steam mass fraction (quality) [1]",\
 12761, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.tube4.gas[1].cp", 1, 5, 17270, 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.crit.d", "Critical density [kg/m3|g/cm3]",\
 12762, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.crit.h", "Critical specific enthalpy [J/kg]",\
 12763, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.crit.p", "Critical pressure [Pa|bar]",\
 12764, 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.crit.s", "Critical specific entropy [J/(kg.K)]",\
 12765, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.crit.T", "Critical temperature [K|degC]",\
 12766, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.d_l", \
"Density of liquid phase [kg/m3|g/cm3]", 12767, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.d_v", \
"Density of vapour phase [kg/m3|g/cm3]", 12768, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.h_l", \
"Specific enthalpy of liquid phase [J/kg]", 12769, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.h_v", \
"Specific enthalpy of vapour phase [J/kg]", 12770, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.p_l", \
"Pressure of liquid phase [Pa|bar]", 12771, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.p_v", \
"Pressure of vapour phase [Pa|bar]", 12772, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.s_l", \
"Specific entropy of liquid phase [J/(kg.K)]", 12773, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.s_v", \
"Specific entropy of vapour phase [J/(kg.K)]", 12774, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.T_l", \
"Temperature of liquid phase [K|degC]", 12775, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLE.T_v", \
"Temperature of vapour phase [K|degC]", 12776, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLETransp.Pr_l", \
"Prandtl number of liquid phase [1]", 12777, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLETransp.Pr_v", \
"Prandtl number of vapour phase [1]", 12778, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLETransp.lambda_l", \
"Thermal conductivity of liquid phase [W/(m.K)]", 12779, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLETransp.lambda_v", \
"Thermal conductivity of vapour phase [W/(m.K)]", 12780, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLETransp.eta_l", \
"Dynamic viscosity of liquid phase [Pa.s]", 12781, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].properties.VLETransp.eta_v", \
"Dynamic viscosity of vapour phase [Pa.s]", 12782, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.transp.Pr", \
"Prandtl number [1]", "PF4U.tube4.gas[1].transp.Pr", 1, 5, 17280, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.transp.lambda", \
"Thermal conductivity [W/(m.K)]", "PF4U.tube4.gas[1].transp.lambda", 1, 5, 17281,\
 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.transp.eta", \
"Dynamic viscosity [Pa.s]", "PF4U.tube4.gas[1].transp.eta", 1, 5, 17282, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].properties.transp.sigma", \
"Surface tension [N/m]", "PF4U.tube4.gas[1].transp.sigma", 1, 5, 17283, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].cellGeometry.length", "[m]", \
"PF4U.tube4.tubeGeometry.length", 1, 5, 12697, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].cellGeometry.volume", "[m3]", \
"PF4U.tube4.tubeGeometry.innerVolume", 1, 5, 12703, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].cellGeometry.heatTransferArea", "[m2]",\
 "PF4U.tube4.tubeGeometry.innerHeatTransferArea", 1, 5, 12705, 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].cellGeometry.finHeatTransferAreaRatio",\
 "Fraction of fins on fin side heat transfer area", 12783, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].cellGeometry.hydraulicCrossSectionalArea",\
 "[m2]", 12784, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].cellGeometry.nParallelHydraulicFlows",\
 "Number of parallel flows", 12785, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].alphaA", "Value for alphaA for one cell [W/K]",\
 17292, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.alphaA", "Value for alphaA for one cell [W/K]",\
 "PF4U.tube4.heatTransfer[1].alphaA", 1, 5, 17292, 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.computeTransportProperties",\
 "[:#(type=Boolean)]", 12786, true, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.useAlphaAState", \
"alphaA is a differential state [:#(type=Boolean)]", 12787, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.mdotHydraulic", \
"Hydraulic mass flow rate [kg/s]", "PF4U.tube4.mdotHydraulic", 1, 5, 17289, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.d", \
"Density [kg/m3|g/cm3]", "PF4U.tube4.gas[1].d", 1, 5, 17268, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.h", \
"Specific enthalpy [J/kg]", "PF4U.tube4.h[1]", 1, 1, 108, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.p", \
"Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.s", \
"Specific entropy [J/(kg.K)]", "PF4U.tube4.gas[1].s", 1, 5, 17269, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.T", \
"Temperature [K|degC]", "PF4U.tube4.T_gas_cell_[1]", 1, 5, 17329, 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.q", \
"Steam mass fraction (quality) [1]", 12788, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.cp", \
"Specific isobaric heat capacity cp [J/(kg.K)]", "PF4U.tube4.gas[1].cp", 1, 5, 17270,\
 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.crit.d",\
 "Critical density [kg/m3|g/cm3]", 12789, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.crit.h",\
 "Critical specific enthalpy [J/kg]", 12790, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.crit.p",\
 "Critical pressure [Pa|bar]", 12791, 0.0, 0.0,1.7976931348623157E+308,100000.0,\
0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.crit.s",\
 "Critical specific entropy [J/(kg.K)]", 12792, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.crit.T",\
 "Critical temperature [K|degC]", 12793, 0.0, 0.0,1.7976931348623157E+308,300.0,\
0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.d_l",\
 "Density of liquid phase [kg/m3|g/cm3]", 12794, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.d_v",\
 "Density of vapour phase [kg/m3|g/cm3]", 12795, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.h_l",\
 "Specific enthalpy of liquid phase [J/kg]", 12796, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.h_v",\
 "Specific enthalpy of vapour phase [J/kg]", 12797, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.p_l",\
 "Pressure of liquid phase [Pa|bar]", 12798, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.p_v",\
 "Pressure of vapour phase [Pa|bar]", 12799, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.s_l",\
 "Specific entropy of liquid phase [J/(kg.K)]", 12800, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.s_v",\
 "Specific entropy of vapour phase [J/(kg.K)]", 12801, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.T_l",\
 "Temperature of liquid phase [K|degC]", 12802, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLE.T_v",\
 "Temperature of vapour phase [K|degC]", 12803, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.Pr_l",\
 "Prandtl number of liquid phase [1]", 12804, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.Pr_v",\
 "Prandtl number of vapour phase [1]", 12805, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.lambda_l",\
 "Thermal conductivity of liquid phase [W/(m.K)]", 12806, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.lambda_v",\
 "Thermal conductivity of vapour phase [W/(m.K)]", 12807, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.eta_l",\
 "Dynamic viscosity of liquid phase [Pa.s]", 12808, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.VLETransp.eta_v",\
 "Dynamic viscosity of vapour phase [Pa.s]", 12809, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.transp.Pr",\
 "Prandtl number [1]", "PF4U.tube4.gas[1].transp.Pr", 1, 5, 17280, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.transp.lambda",\
 "Thermal conductivity [W/(m.K)]", "PF4U.tube4.gas[1].transp.lambda", 1, 5, 17281,\
 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.transp.eta",\
 "Dynamic viscosity [Pa.s]", "PF4U.tube4.gas[1].transp.eta", 1, 5, 17282, 1024)
DeclareAlias2("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.properties.transp.sigma",\
 "Surface tension [N/m]", "PF4U.tube4.gas[1].transp.sigma", 1, 5, 17283, 1024)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.alpha", \
"Coefficient of heat transfer [W/(m2.K)]", 17293, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.hydraulicDiameter",\
 "Hydraulic diameter [m]", 12810, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.hydraulicCrossSectionalArea",\
 "Hydraulic cross sectional area [m2]", 12811, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.Re", \
"Reynolds Number [1]", 17294, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.Nu", \
"Nusselt number [1]", 17295, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.averageVelocity", \
"Average velocity [m/s]", 17296, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.weightingFactor1", \
"", 17297, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.weightingFactor2", \
"", 17298, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.Nu1", "[1]", 17299,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.Nu_Gnielinski", \
"[1]", 17300, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.Nu_DittusBoelter", \
"[1]", 17301, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.heatTransfer[1].heatTransfer.gdb.zeta", "", 17302, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareParameter("PF4U.tube4.heatTransfer[1].heatTransfer.correctionFactor", \
"Linear correction factor for the overall alphaA calculated by this heat transfer model and its submodels. [1]",\
 1279, 1, 0.0,0.0,0.0,0,2608)
DeclareAlias2("PF4U.tube4.pressureDrop[1].mdotHydraulic", "Hydraulic mass flow rate [kg/s]",\
 "PF4U.tube4.mdotHydraulic", 1, 5, 17289, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.d", "Density [kg/m3|g/cm3]",\
 "PF4U.tube4.gas[1].d", 1, 5, 17268, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.h", "Specific enthalpy [J/kg]",\
 "PF4U.tube4.h[1]", 1, 1, 108, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.p", "Pressure [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.s", "Specific entropy [J/(kg.K)]",\
 "PF4U.tube4.gas[1].s", 1, 5, 17269, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.T", "Temperature [K|degC]",\
 "PF4U.tube4.T_gas_cell_[1]", 1, 5, 17329, 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.q", "Steam mass fraction (quality) [1]",\
 12812, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 "PF4U.tube4.gas[1].cp", 1, 5, 17270, 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.crit.d", "Critical density [kg/m3|g/cm3]",\
 12813, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.crit.h", "Critical specific enthalpy [J/kg]",\
 12814, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.crit.p", "Critical pressure [Pa|bar]",\
 12815, 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.crit.s", "Critical specific entropy [J/(kg.K)]",\
 12816, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.crit.T", "Critical temperature [K|degC]",\
 12817, 0.0, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.d_l", \
"Density of liquid phase [kg/m3|g/cm3]", 12818, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.d_v", \
"Density of vapour phase [kg/m3|g/cm3]", 12819, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.h_l", \
"Specific enthalpy of liquid phase [J/kg]", 12820, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.h_v", \
"Specific enthalpy of vapour phase [J/kg]", 12821, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.p_l", \
"Pressure of liquid phase [Pa|bar]", 12822, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.p_v", \
"Pressure of vapour phase [Pa|bar]", 12823, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.s_l", \
"Specific entropy of liquid phase [J/(kg.K)]", 12824, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.s_v", \
"Specific entropy of vapour phase [J/(kg.K)]", 12825, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.T_l", \
"Temperature of liquid phase [K|degC]", 12826, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLE.T_v", \
"Temperature of vapour phase [K|degC]", 12827, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLETransp.Pr_l", \
"Prandtl number of liquid phase [1]", 12828, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLETransp.Pr_v", \
"Prandtl number of vapour phase [1]", 12829, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLETransp.lambda_l", \
"Thermal conductivity of liquid phase [W/(m.K)]", 12830, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLETransp.lambda_v", \
"Thermal conductivity of vapour phase [W/(m.K)]", 12831, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLETransp.eta_l", \
"Dynamic viscosity of liquid phase [Pa.s]", 12832, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].properties.VLETransp.eta_v", \
"Dynamic viscosity of vapour phase [Pa.s]", 12833, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.transp.Pr", \
"Prandtl number [1]", "PF4U.tube4.gas[1].transp.Pr", 1, 5, 17280, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.transp.lambda", \
"Thermal conductivity [W/(m.K)]", "PF4U.tube4.gas[1].transp.lambda", 1, 5, 17281,\
 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.transp.eta", \
"Dynamic viscosity [Pa.s]", "PF4U.tube4.gas[1].transp.eta", 1, 5, 17282, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].properties.transp.sigma", \
"Surface tension [N/m]", "PF4U.tube4.gas[1].transp.sigma", 1, 5, 17283, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].cellGeometry.length", "[m]", \
"PF4U.tube4.tubeGeometry.length", 1, 5, 12697, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].cellGeometry.volume", "[m3]", \
"PF4U.tube4.tubeGeometry.innerVolume", 1, 5, 12703, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].cellGeometry.heatTransferArea", "[m2]",\
 "PF4U.tube4.tubeGeometry.innerHeatTransferArea", 1, 5, 12705, 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].cellGeometry.finHeatTransferAreaRatio",\
 "Fraction of fins on fin side heat transfer area", 12834, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].cellGeometry.hydraulicCrossSectionalArea",\
 "[m2]", 12835, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].cellGeometry.nParallelHydraulicFlows",\
 "Number of parallel flows", 12836, 1.0, 1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDrop", "Pressure drop for one cell [Pa|bar]",\
 17303, 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.pressureDrop", \
"Pressure drop for one cell [Pa|bar]", "PF4U.tube4.pressureDrop[1].pressureDrop", 1,\
 5, 17303, 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.computeTransportProperties",\
 "[:#(type=Boolean)]", 12837, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.mdotHydraulic",\
 "Hydraulic mass flow rate [kg/s]", "PF4U.tube4.mdotHydraulic", 1, 5, 17289, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.d",\
 "Density [kg/m3|g/cm3]", "PF4U.tube4.gas[1].d", 1, 5, 17268, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.h",\
 "Specific enthalpy [J/kg]", "PF4U.tube4.h[1]", 1, 1, 108, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.p",\
 "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.s",\
 "Specific entropy [J/(kg.K)]", "PF4U.tube4.gas[1].s", 1, 5, 17269, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.T",\
 "Temperature [K|degC]", "PF4U.tube4.T_gas_cell_[1]", 1, 5, 17329, 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.q",\
 "Steam mass fraction (quality) [1]", 12838, 0, 0.0,1.0,0.0,0,2561)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.cp",\
 "Specific isobaric heat capacity cp [J/(kg.K)]", "PF4U.tube4.gas[1].cp", 1, 5, 17270,\
 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.crit.d",\
 "Critical density [kg/m3|g/cm3]", 12839, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.crit.h",\
 "Critical specific enthalpy [J/kg]", 12840, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.crit.p",\
 "Critical pressure [Pa|bar]", 12841, 0.0, 0.0,1.7976931348623157E+308,100000.0,\
0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.crit.s",\
 "Critical specific entropy [J/(kg.K)]", 12842, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.crit.T",\
 "Critical temperature [K|degC]", 12843, 0.0, 0.0,1.7976931348623157E+308,300.0,\
0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.d_l",\
 "Density of liquid phase [kg/m3|g/cm3]", 12844, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.d_v",\
 "Density of vapour phase [kg/m3|g/cm3]", 12845, 0.0, 0.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.h_l",\
 "Specific enthalpy of liquid phase [J/kg]", 12846, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.h_v",\
 "Specific enthalpy of vapour phase [J/kg]", 12847, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.p_l",\
 "Pressure of liquid phase [Pa|bar]", 12848, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.p_v",\
 "Pressure of vapour phase [Pa|bar]", 12849, 0.0, 0.0,1.7976931348623157E+308,\
100000.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.s_l",\
 "Specific entropy of liquid phase [J/(kg.K)]", 12850, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.s_v",\
 "Specific entropy of vapour phase [J/(kg.K)]", 12851, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.T_l",\
 "Temperature of liquid phase [K|degC]", 12852, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLE.T_v",\
 "Temperature of vapour phase [K|degC]", 12853, 0.0, 0.0,1.7976931348623157E+308,\
300.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.Pr_l",\
 "Prandtl number of liquid phase [1]", 12854, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.Pr_v",\
 "Prandtl number of vapour phase [1]", 12855, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.lambda_l",\
 "Thermal conductivity of liquid phase [W/(m.K)]", 12856, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.lambda_v",\
 "Thermal conductivity of vapour phase [W/(m.K)]", 12857, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.eta_l",\
 "Dynamic viscosity of liquid phase [Pa.s]", 12858, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.VLETransp.eta_v",\
 "Dynamic viscosity of vapour phase [Pa.s]", 12859, 0.0, -1.0,1.7976931348623157E+308,\
0.0,0,2561)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.transp.Pr",\
 "Prandtl number [1]", "PF4U.tube4.gas[1].transp.Pr", 1, 5, 17280, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.transp.lambda",\
 "Thermal conductivity [W/(m.K)]", "PF4U.tube4.gas[1].transp.lambda", 1, 5, 17281,\
 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.transp.eta",\
 "Dynamic viscosity [Pa.s]", "PF4U.tube4.gas[1].transp.eta", 1, 5, 17282, 1024)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.properties.transp.sigma",\
 "Surface tension [N/m]", "PF4U.tube4.gas[1].transp.sigma", 1, 5, 17283, 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.pressureDrop",\
 "Pressure drop [Pa|bar]", 17304, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.hydraulicDiameter",\
 "Hydraulic diameter [m]", 12860, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.hydraulicCrossSectionalArea",\
 "Cross-sectional area [m2]", 12861, 0.0, 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.length", \
"Length [m]", "PF4U.tube4.tubeGeometry.length", 1, 5, 12697, 1024)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.Re", \
"Reynold's number [1]", 17305, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.v", \
"Velocity [m/s]", 17306, 0.0, 0.0,0.0,0.0,0,2624)
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
 "Darcy-Weisbach friction factor for turbulent flow", 17307, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.pressureDropLaminar",\
 "Laminar pressure drop model [Pa|bar]", 17308, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.pressureDropTurbulent",\
 "Turbulent pressure drop model [Pa|bar]", 17309, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.pressureDrop[1].pressureDropModel.konakov.weightingFactor",\
 "Factor for transition between laminar and turbulent zone [1]", 17310, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareParameter("PF4U.tube4.pressureDrop[1].pressureDropModel.correctionFactor",\
 "Linear correction factor for the pressureDrop calculated by this pressure drop model and its submodels. [1]",\
 1283, 1, 0.0,0.0,0.0,0,2608)
DeclareParameter("PF4U.tube4.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1284, 0.003, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.tube4.pInitial", "Initial value for gas pressure [Pa|bar]",\
 12862, 4000000, 0.0,0.0,0.0,0,513)
DeclareVariable("PF4U.tube4.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 12863, true, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.tube4.TInitial", "Initial value for gas temperature [K|K]",\
 12864, 288.15, 0.0,1.7976931348623157E+308,300.0,0,513)
DeclareParameter("PF4U.tube4.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1285, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.tube4.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 12865, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.tube4.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1286, 1, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.tube4.massFlowRateHomotopy", "Nominal mass flow rate for linear valve equation [kg/s]",\
 1287, 0.01, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.tube4.pressureDropHomotopy", "Nominal pressure drop for linear valve equation [Pa|bar]",\
 1288, 10000.0, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.tube4.hInitial", "[J/kg]", 12866, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.TInitialWall", "Initial value for wall temperature [K|K]",\
 12867, 288.15, 0.0,1.7976931348623157E+308,300.0,0,513)
DeclareVariable("PF4U.tube4.connectWallCells", "If true: wall cells should be connected W-E [:#(type=Boolean)]",\
 12868, false, 0.0,0.0,0.0,0,515)
DeclareAlias2("PF4U.tube4.wallCell[1].cellGeometry.length", "[m]", \
"PF4U.tube4.tubeGeometry.length", 1, 5, 12697, 1024)
DeclareVariable("PF4U.tube4.wallCell[1].cellGeometry.volume", "[m3]", 12869, 0.0,\
 0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.tube4.wallCell[1].portN.T", "Port temperature [K|degC]", \
"PF4U.Channel4.T_wall", 1, 5, 16994, 1028)
DeclareAlias2("PF4U.tube4.wallCell[1].portN.Q_flow", "Heat flow rate [W]", \
"PF4U.prescribedHeatFlow3.port.Q_flow", -1, 5, 17265, 1156)
DeclareAlias2("PF4U.tube4.wallCell[1].portS.T", "Port temperature [K|degC]", \
"PF4U.tube4.heatTransfer[1].wallTemperature", 1, 5, 17291, 1028)
DeclareVariable("PF4U.tube4.wallCell[1].portS.Q_flow", "Heat flow rate [W]", 17311,\
 0.0, 0.0,0.0,0.0,0,2824)
DeclareVariable("PF4U.tube4.wallCell[1].portW.T", "Port temperature [K|degC]", 17312,\
 0.0, 0.0,1.7976931348623157E+308,300.0,0,2568)
DeclareVariable("PF4U.tube4.wallCell[1].portW.Q_flow", "Heat flow rate [W]", 12870,\
 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube4.wallCell[1].portE.T", "Port temperature [K|degC]", 17313,\
 0.0, 0.0,1.7976931348623157E+308,300.0,0,2568)
DeclareVariable("PF4U.tube4.wallCell[1].portE.Q_flow", "Heat flow rate [W]", 12871,\
 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.tube4.wallCell[1].TInitialWall", "Initial wall temperature [K|degC]",\
 12872, 288.15, 0.0,1.7976931348623157E+308,300.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].fixedTInitialWall", "if true, force usage of initial value TInitialWall [:#(type=Boolean)]",\
 12873, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube4.wallCell[1].initSteadyState", "[:#(type=Boolean)]", 12874,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube4.wallCell[1].additionalHeatCapacity", "[J/K]", 12875,\
 0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].properties.d", "Density [kg/m3|g/cm3]", 12876,\
 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube4.wallCell[1].properties.T", "Temperature [K|degC]", \
"PF4U.tube4.wallCell[1].wallStateTemperature", 1, 1, 109, 1024)
DeclareVariable("PF4U.tube4.wallCell[1].properties.cp", "Heat capacity [J/(kg.K)]",\
 12877, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].properties.lambda", "Thermal conductivity [W/(m.K)]",\
 12878, 40.0, 0.0,0.0,0.0,0,2561)
DeclareState("PF4U.tube4.wallCell[1].wallStateTemperature", "[K|degC]", 109, 0.0,\
 0.0,1.7976931348623157E+308,300.0,0,2592)
DeclareDerivative("PF4U.tube4.wallCell[1].der(wallStateTemperature)", "[K/s]", 109,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.d", "Density [kg/m3|g/cm3]",\
 12879, 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube4.wallCell[1].wallMaterial.T", "Temperature [K|degC]", \
"PF4U.tube4.wallCell[1].wallStateTemperature", 1, 1, 109, 1024)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.cp", "Heat capacity [J/(kg.K)]",\
 12880, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.lambda", "Thermal conductivity [W/(m.K)]",\
 12881, 40.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.cp_nominal", \
"Specific heat capacity at standard reference point [J/(kg.K)]", 12882, 490.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.lambda_nominal", \
"Thermal conductivity at standard reference point [W/(m.K)]", 12883, 40.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.solid.cp_nominal", \
"Specific heat capacity at standard reference point [J/(kg.K)]", 12884, 490.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.solid.lambda_nominal", \
"Thermal conductivity at standard reference point [W/(m.K)]", 12885, 40.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.solid.d", "Density [kg/m3|g/cm3]",\
 12886, 7800.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareAlias2("PF4U.tube4.wallCell[1].wallMaterial.solid.T", "Temperature [K|degC]",\
 "PF4U.tube4.wallCell[1].wallStateTemperature", 1, 1, 109, 1024)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.solid.cp", "Heat capacity [J/(kg.K)]",\
 12887, 490.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].wallMaterial.solid.lambda", \
"Thermal conductivity [W/(m.K)]", 12888, 40.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].heatTransfer.R_WE", "Thermal resistance (W-E) for one cell [K/W]",\
 12889, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].heatTransfer.R_NS", "Thermal resistance (N-S) for one cell [K/W]",\
 12890, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].heatTransfer.connectWallCells", \
"[:#(type=Boolean)]", 12891, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.tube4.wallCell[1].heatTransfer.R_NS_total", \
"Thermal resistance (N-S) for total HX [K/W]", 12892, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].heatTransfer.R_WE_total", \
"Thermal resistance (W-E) for total HX [K/W]", 12893, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].geometricMass", "Geometric mass [kg]", 12894,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.tube4.wallCell[1].SProd_dot", "Produced entropy [W/K]", 17314,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareAlias2("PF4U.tube4.getInputsThermal[1].heatPort.T", "Port temperature [K|degC]",\
 "PF4U.tube4.heatTransfer[1].wallTemperature", 1, 5, 17291, 1028)
DeclareAlias2("PF4U.tube4.getInputsThermal[1].heatPort.Q_flow", "Heat flow rate [W]",\
 "PF4U.tube4.wallCell[1].portS.Q_flow", -1, 5, 17311, 1156)
DeclareVariable("PF4U.tube4.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12895, true, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.tube4.includeSummaryArrays", "Obsolete & unused parameter for array entries in summary [:#(type=Boolean)]",\
 1289, true, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube4.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12896, true, 0.0,0.0,0.0,0,2563)
DeclareAlias2("PF4U.tube4.summary.p_gas_A", "Pressure at port A [Pa|bar]", \
"PF4U.junction2.p", 1, 1, 103, 0)
DeclareAlias2("PF4U.tube4.summary.p_gas_B", "Pressure at port B [Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.tube4.summary.T_gas_A", "Temperature at port A [K|degC]", \
"PF4U.Channel4.T_gas_in", 1, 5, 16996, 0)
DeclareAlias2("PF4U.tube4.summary.T_gas_B", "Temperature at port B [K|degC]", \
"PF4U.Channel4.T_gas_out", 1, 5, 16995, 0)
DeclareVariable("PF4U.tube4.summary.T_degC_gas_A", "Temperature at port A [degC;]",\
 17315, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube4.summary.T_degC_gas_B", "Temperature at port B [degC;]",\
 17316, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube4.summary.h_gas_A", "Specific enthalpy at port A [J/kg]",\
 17317, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube4.summary.h_gas_B", "Specific enthalpy at port B [J/kg]",\
 17318, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube4.summary.d_gas_A", "Density at port A [kg/m3|g/cm3]",\
 17319, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.tube4.summary.d_gas_B", "Density at port B [kg/m3|g/cm3]",\
 17320, 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareAlias2("PF4U.tube4.summary.m_flow_gas_A", "Mass flow rate at port A [kg/s]",\
 "PF4U.tube4.portA.m_flow", 1, 5, 17267, 0)
DeclareAlias2("PF4U.tube4.summary.m_flow_gas_B", "Mass flow rate at port B [kg/s]",\
 "PF4U.Channel4.m_flow", 1, 5, 16997, 0)
DeclareVariable("PF4U.tube4.summary.w_gas_A", "Flow velocity at port A [m/s]", 17321,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube4.summary.w_gas_B", "Flow velocity at port B [m/s]", 17322,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube4.summary.dp_gas", "Total pressure drop [Pa|bar]", 17323,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube4.summary.Q_flow_gas", "Total heat flow rate [W]", \
"PF4U.tube4.wallCell[1].portS.Q_flow", -1, 5, 17311, 0)
DeclareVariable("PF4U.tube4.summary.mass_gas", "Total fluid mass [kg]", 17324, \
0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareAlias2("PF4U.tube4.summary.volume_gas", "Total fluid volume [m3]", \
"PF4U.tube4.tubeGeometry.innerVolume", 1, 5, 12703, 0)
DeclareVariable("PF4U.tube4.summary.alpha_average_gas", "Average coefficient of heat transfer [W/(m2.K)]",\
 17325, 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube4.summary.mass_component", "Total component mass [kg]", \
"PF4U.tube4.wallCell[1].geometricMass", 1, 5, 12894, 0)
DeclareVariable("PF4U.tube4.summary.arrays.n", "[:#(type=Integer)]", 12897, 1, \
0.0,0.0,0.0,0,517)
DeclareAlias2("PF4U.tube4.summary.arrays.T_gas_cell[1]", "[K|degC]", \
"PF4U.tube4.T_gas_cell_[1]", 1, 5, 17329, 0)
DeclareVariable("PF4U.tube4.summary.arrays.T_degC_gas_cell[1]", "[degC;]", 17326,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube4.summary.arrays.T_wall_cell[1]", "[K|degC]", \
"PF4U.tube4.wallCell[1].wallStateTemperature", 1, 1, 109, 0)
DeclareVariable("PF4U.tube4.summary.arrays.T_degC_wall_cell[1]", "[degC;]", 17327,\
 0.0, 0.0,0.0,0.0,0,512)
DeclareAlias2("PF4U.tube4.summary.arrays.p_gas_cell[1]", "[Pa|bar]", \
"PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.tube4.summary.arrays.h_gas_cell[1]", "[J/kg]", \
"PF4U.tube4.h[1]", 1, 1, 108, 0)
DeclareAlias2("PF4U.tube4.summary.arrays.d_gas_cell[1]", "[kg/m3|g/cm3]", \
"PF4U.tube4.gas[1].d", 1, 5, 17268, 0)
DeclareVariable("PF4U.tube4.summary.arrays.alpha_gas_cell[1]", "Heat transfer coefficient [W/(m2.K)]",\
 17328, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.tube4.T_gas_cell_[1]", "[K|degC]", 17329, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.tube4.T_wall_cell_[1]", "[K|degC]", "PF4U.tube4.wallCell[1].wallStateTemperature", 1,\
 1, 109, 1024)
DeclareVariable("PF4U.tube4.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12898, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube4.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12899,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12900, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12901,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12902, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12903, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12904, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasA.gasPointer.id", "[:#(type=Integer)]", 12905, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.tube4.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1290, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube4.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12906, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.tube4.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12907,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12908, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12909,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12910, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.tube4.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12911, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12912, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.tube4.gasB.gasPointer.id", "[:#(type=Integer)]", 12913, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.tube4.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1291, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.tube4.fixedTInitialWall", "if true, force usage of initial value TInitialWall [:#(type=Boolean)]",\
 12914, false, 0.0,0.0,0.0,0,515)
DeclareAlias2("PF4U.tube4.heatPort[1].T", "Port temperature [K|degC]", \
"PF4U.Channel4.T_wall", 1, 5, 16994, 4)
DeclareAlias2("PF4U.tube4.heatPort[1].Q_flow", "Heat flow rate [W]", \
"PF4U.prescribedHeatFlow3.port.Q_flow", -1, 5, 17265, 132)
DeclareVariable("PF4U.junction1.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12915, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12916,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12917, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 12918,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 12919, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12920, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12921, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.simPort.vleFluidMass", "[kg]", 12922, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.simPort.vleFluidVolume", "[m3]", 12923, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.simPort.liquidMass", "[kg]", 12924, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.simPort.liquidVolume", "[m3]", 12925, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.junction1.simPort.gasMass", "[kg]", "PF4U.junction1.mass", 1,\
 5, 17343, 1024)
DeclareAlias2("PF4U.junction1.simPort.gasVolume", "[m3]", "PF4U.junction1.volume", 1,\
 7, 1292, 1024)
DeclareVariable("PF4U.junction1.simPort.dpdt", "", 12926, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.simPort.dpdtCounter", "", 12927, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.junction1.simPort.vleFluidPort.vleFluidMass", \
"Accumulated fluid mass [kg]", 12928, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction1.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 12929, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction1.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 12930, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction1.simPort.liquidPort.liquidVolume", \
"Accumulated liquid volume [m3]", 12931, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.junction1.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.junction1.mass", 1, 5, 17343, 1156)
DeclareAlias2("PF4U.junction1.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.junction1.volume", 1, 7, 1292, 1156)
DeclareVariable("PF4U.junction1.simPort.dpdtPort.dpdt", "", 12932, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.junction1.simPort.dpdtPort.counter", "", 12933, 0.0, \
0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction1.simPort.warningsPort.warnings", "Accumulated warnings",\
 12934, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction1.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 12935, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction1.portA.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12936, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12937,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12938, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.portA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12939,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12940, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12941, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12942, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction1.portA.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.junction1.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4U.tube4.portA.m_flow", -1, 5, 17267, 132)
DeclareAlias2("PF4U.junction1.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction1.h", 1, 1, 110, 4)
DeclareVariable("PF4U.junction1.portB.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12943, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12944,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12945, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.portB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12946,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12947, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12948, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12949, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction1.portB.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.junction1.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.junction2.portA.m_flow", -1, 5, 17115, 132)
DeclareAlias2("PF4U.junction1.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction1.h", 1, 1, 110, 4)
DeclareVariable("PF4U.junction1.portC.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12950, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12951,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12952, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.portC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12953,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12954, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12955, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12956, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction1.portC.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.junction1.portC.m_flow", "Mass flow rate [kg/s]", \
"PF4U.tube3.portA.m_flow", -1, 5, 17201, 132)
DeclareAlias2("PF4U.junction1.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction1.h", 1, 1, 110, 4)
DeclareVariable("PF4U.junction1.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12957, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12958,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12959, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gas.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12960,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gas.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12961, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12962, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12963, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gas.gasPointer.id", "[:#(type=Integer)]", 12964,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.junction1.gas.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 12965,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction1.gas.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 12966, false,\
 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction1.gas.d", "Density [kg/m3|g/cm3]", 17330, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.junction1.gas.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 1024)
DeclareAlias2("PF4U.junction1.gas.der(p)", "der(Pressure) [Pa/s]", \
"PF4U.junction2.der(p)", 1, 6, 103, 1024)
DeclareAlias2("PF4U.junction1.gas.h", "Specific enthalpy [J/kg]", \
"PF4U.junction1.h", 1, 1, 110, 1024)
DeclareAlias2("PF4U.junction1.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"PF4U.junction1.der(h)", 1, 6, 110, 1024)
DeclareVariable("PF4U.junction1.gas.s", "Specific entropy [J/(kg.K)]", 17331, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.T", "Temperature [K|degC]", 17332, 288.15, \
0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.junction1.gas.M", "Average molar mass [kg/mol]", \
"PF4U.junction1.gas.M_i[1]", 1, 5, 12972, 1024)
DeclareVariable("PF4U.junction1.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17333, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17334, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17335, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.kappa", "Isothermal compressibility [1/Pa]",\
 17336, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.w", "Speed of sound [m/s]", 17337, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17338, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17339, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.p_i[1]", "Partial pressure [Pa|bar]", 17340,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.junction1.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17341, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.phi", "Relative humidity", 12967, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 12968, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.junction1.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 12969, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 12970, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 12971, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17342, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction1.gas.M_i[1]", "Molar mass of component i [kg/mol]",\
 12972, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 12973, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 12974, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 12975, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.transp.Pr", "Prandtl number [1]", 12976, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 12977, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.transp.eta", "Dynamic viscosity [Pa.s]", 12978,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.transp.sigma", "Surface tension [N/m]", 12979,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction1.gas.computeFlags", "[:#(type=Integer)]", 12980, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction1.volume", "[m3]", 1292, 1E-05, 0.0,\
1.7976931348623157E+308,0.0,0,560)
DeclareParameter("PF4U.junction1.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1293, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.junction1.pInitial", "Initial value for air pressure [Pa|bar]",\
 1294, 2000000, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.junction1.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 12981, false, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.junction1.TInitial", "Initial value for air temperature [K|K]",\
 1295, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.junction1.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1296, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.junction1.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 12982, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.junction1.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1297, 1, 0.0,0.0,0.0,0,560)
DeclareState("PF4U.junction1.h", "Specific enthalpy [J/kg]", 110, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("PF4U.junction1.der(h)", "der(Specific enthalpy) [m2/s3]", 110,\
 0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("PF4U.junction1.p", "[Pa|bar]", "PF4U.junction2.p", 1, 1, 103, 0)
DeclareAlias2("PF4U.junction1.der(p)", "[Pa/s]", "PF4U.junction2.der(p)", 1, 6, 103,\
 0)
DeclareVariable("PF4U.junction1.mass", "Gas mass in control volume [kg]", 17343,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.junction1.drhodt", "[Pa.m-2.s]", 17344, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.junction1.hInitial", "[J/kg]", 12983, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12984, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.junction1.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 12985, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction1.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12986, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12987,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12988, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12989,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12990, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12991, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 12992, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasA.gasPointer.id", "[:#(type=Integer)]", 12993,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction1.gasA.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1298, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction1.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 12994, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 12995,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 12996, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 12997,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 12998, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 12999, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13000, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasB.gasPointer.id", "[:#(type=Integer)]", 13001,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction1.gasB.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1299, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction1.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13002, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction1.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13003,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13004, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13005,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13006, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction1.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13007, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13008, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction1.gasC.gasPointer.id", "[:#(type=Integer)]", 13009,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction1.gasC.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1300, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction3.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13010, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13011,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13012, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13013,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13014, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13015, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13016, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.simPort.vleFluidMass", "[kg]", 13017, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.simPort.vleFluidVolume", "[m3]", 13018, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.simPort.liquidMass", "[kg]", 13019, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.simPort.liquidVolume", "[m3]", 13020, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.junction3.simPort.gasMass", "[kg]", "PF4U.junction3.mass", 1,\
 5, 17358, 1024)
DeclareAlias2("PF4U.junction3.simPort.gasVolume", "[m3]", "PF4U.junction3.volume", 1,\
 7, 1301, 1024)
DeclareVariable("PF4U.junction3.simPort.dpdt", "", 13021, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.simPort.dpdtCounter", "", 13022, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.junction3.simPort.vleFluidPort.vleFluidMass", \
"Accumulated fluid mass [kg]", 13023, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction3.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13024, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction3.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13025, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction3.simPort.liquidPort.liquidVolume", \
"Accumulated liquid volume [m3]", 13026, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.junction3.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.junction3.mass", 1, 5, 17358, 1156)
DeclareAlias2("PF4U.junction3.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.junction3.volume", 1, 7, 1301, 1156)
DeclareVariable("PF4U.junction3.simPort.dpdtPort.dpdt", "", 13027, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.junction3.simPort.dpdtPort.counter", "", 13028, 0.0, \
0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction3.simPort.warningsPort.warnings", "Accumulated warnings",\
 13029, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction3.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13030, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction3.portA.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13031, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13032,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13033, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.portA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13034,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13035, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13036, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13037, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction3.portA.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.junction3.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4U.tube1.portA.m_flow", -1, 5, 17135, 132)
DeclareAlias2("PF4U.junction3.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction3.h", 1, 1, 111, 4)
DeclareVariable("PF4U.junction3.portB.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13038, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13039,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13040, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.portB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13041,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13042, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13043, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13044, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction3.portB.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.junction3.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.junction2.portC.m_flow", -1, 5, 17116, 132)
DeclareAlias2("PF4U.junction3.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction3.h", 1, 1, 111, 4)
DeclareVariable("PF4U.junction3.portC.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13045, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13046,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13047, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.portC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13048,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13049, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13050, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13051, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction3.portC.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 4)
DeclareAlias2("PF4U.junction3.portC.m_flow", "Mass flow rate [kg/s]", \
"PF4U.tube2.portA.m_flow", -1, 5, 17001, 132)
DeclareAlias2("PF4U.junction3.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction3.h", 1, 1, 111, 4)
DeclareVariable("PF4U.junction3.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13052, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13053,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13054, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gas.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13055,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gas.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13056, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13057, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13058, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gas.gasPointer.id", "[:#(type=Integer)]", 13059,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.junction3.gas.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 13060,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction3.gas.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 13061, false,\
 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction3.gas.d", "Density [kg/m3|g/cm3]", 17345, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.junction3.gas.p", "Pressure [Pa|bar]", "PF4U.junction2.p", 1,\
 1, 103, 1024)
DeclareAlias2("PF4U.junction3.gas.der(p)", "der(Pressure) [Pa/s]", \
"PF4U.junction2.der(p)", 1, 6, 103, 1024)
DeclareAlias2("PF4U.junction3.gas.h", "Specific enthalpy [J/kg]", \
"PF4U.junction3.h", 1, 1, 111, 1024)
DeclareAlias2("PF4U.junction3.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"PF4U.junction3.der(h)", 1, 6, 111, 1024)
DeclareVariable("PF4U.junction3.gas.s", "Specific entropy [J/(kg.K)]", 17346, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.T", "Temperature [K|degC]", 17347, 288.15, \
0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.junction3.gas.M", "Average molar mass [kg/mol]", \
"PF4U.junction3.gas.M_i[1]", 1, 5, 13067, 1024)
DeclareVariable("PF4U.junction3.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17348, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17349, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17350, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.kappa", "Isothermal compressibility [1/Pa]",\
 17351, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.w", "Speed of sound [m/s]", 17352, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17353, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17354, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.p_i[1]", "Partial pressure [Pa|bar]", 17355,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.junction3.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17356, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.phi", "Relative humidity", 13062, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13063, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.junction3.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13064, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13065, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13066, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17357, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction3.gas.M_i[1]", "Molar mass of component i [kg/mol]",\
 13067, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13068, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13069, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13070, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.transp.Pr", "Prandtl number [1]", 13071, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13072, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13073,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.transp.sigma", "Surface tension [N/m]", 13074,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction3.gas.computeFlags", "[:#(type=Integer)]", 13075, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction3.volume", "[m3]", 1301, 1E-05, 0.0,\
1.7976931348623157E+308,0.0,0,560)
DeclareParameter("PF4U.junction3.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1302, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.junction3.pInitial", "Initial value for air pressure [Pa|bar]",\
 1303, 2000000, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.junction3.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13076, false, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.junction3.TInitial", "Initial value for air temperature [K|K]",\
 1304, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.junction3.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1305, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.junction3.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13077, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.junction3.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1306, 1, 0.0,0.0,0.0,0,560)
DeclareState("PF4U.junction3.h", "Specific enthalpy [J/kg]", 111, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("PF4U.junction3.der(h)", "der(Specific enthalpy) [m2/s3]", 111,\
 0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("PF4U.junction3.p", "[Pa|bar]", "PF4U.junction2.p", 1, 1, 103, 0)
DeclareAlias2("PF4U.junction3.der(p)", "[Pa/s]", "PF4U.junction2.der(p)", 1, 6, 103,\
 0)
DeclareVariable("PF4U.junction3.mass", "Gas mass in control volume [kg]", 17358,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.junction3.drhodt", "[Pa.m-2.s]", 17359, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.junction3.hInitial", "[J/kg]", 13078, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13079, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.junction3.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13080, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction3.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13081, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13082,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13083, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13084,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13085, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13086, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13087, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasA.gasPointer.id", "[:#(type=Integer)]", 13088,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction3.gasA.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1307, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction3.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13089, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13090,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13091, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13092,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13093, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13094, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13095, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasB.gasPointer.id", "[:#(type=Integer)]", 13096,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction3.gasB.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1308, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction3.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13097, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction3.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13098,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13099, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13100,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13101, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction3.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13102, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13103, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction3.gasC.gasPointer.id", "[:#(type=Integer)]", 13104,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction3.gasC.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1309, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction4.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13105, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13106,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13107, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13108,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13109, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13110, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13111, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.simPort.vleFluidMass", "[kg]", 13112, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.simPort.vleFluidVolume", "[m3]", 13113, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.simPort.liquidMass", "[kg]", 13114, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.simPort.liquidVolume", "[m3]", 13115, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.junction4.simPort.gasMass", "[kg]", "PF4U.junction4.mass", 1,\
 5, 17374, 1024)
DeclareAlias2("PF4U.junction4.simPort.gasVolume", "[m3]", "PF4U.junction4.volume", 1,\
 7, 1310, 1024)
DeclareVariable("PF4U.junction4.simPort.dpdt", "", 13116, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.simPort.dpdtCounter", "", 13117, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.junction4.simPort.vleFluidPort.vleFluidMass", \
"Accumulated fluid mass [kg]", 13118, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction4.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13119, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction4.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13120, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction4.simPort.liquidPort.liquidVolume", \
"Accumulated liquid volume [m3]", 13121, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.junction4.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.junction4.mass", 1, 5, 17374, 1156)
DeclareAlias2("PF4U.junction4.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.junction4.volume", 1, 7, 1310, 1156)
DeclareVariable("PF4U.junction4.simPort.dpdtPort.dpdt", "", 13122, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.junction4.simPort.dpdtPort.counter", "", 13123, 0.0, \
0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction4.simPort.warningsPort.warnings", "Accumulated warnings",\
 13124, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction4.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13125, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction4.portA.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13126, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13127,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13128, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.portA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13129,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13130, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13131, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13132, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction4.portA.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareAlias2("PF4U.junction4.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4U.Channel1.m_flow", -1, 5, 16985, 132)
DeclareAlias2("PF4U.junction4.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction4.h", 1, 1, 112, 4)
DeclareVariable("PF4U.junction4.portB.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13133, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13134,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13135, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.portB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13136,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13137, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13138, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13139, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction4.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareVariable("PF4U.junction4.portB.m_flow", "Mass flow rate [kg/s]", 17360, \
0.0, 0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.junction4.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction4.h", 1, 1, 112, 4)
DeclareVariable("PF4U.junction4.portC.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13140, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13141,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13142, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.portC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13143,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13144, \
1.0, 0.0,0.0,0.0,0,1537)
EndNonAlias(15)
PreNonAliasNew(16)
StartNonAlias(16)
DeclareVariable("PF4U.junction4.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13145, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13146, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction4.portC.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareAlias2("PF4U.junction4.portC.m_flow", "Mass flow rate [kg/s]", \
"PF4U.Channel2.m_flow", -1, 5, 16989, 132)
DeclareAlias2("PF4U.junction4.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction4.h", 1, 1, 112, 4)
DeclareVariable("PF4U.junction4.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13147, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13148,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13149, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gas.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13150,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gas.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13151, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13152, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13153, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gas.gasPointer.id", "[:#(type=Integer)]", 13154,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.junction4.gas.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 13155,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction4.gas.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 13156, false,\
 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction4.gas.d", "Density [kg/m3|g/cm3]", 17361, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.junction4.gas.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 1024)
DeclareAlias2("PF4U.junction4.gas.der(p)", "der(Pressure) [Pa/s]", \
"PF2U.tube2.der(p[1])", 1, 6, 18, 1024)
DeclareAlias2("PF4U.junction4.gas.h", "Specific enthalpy [J/kg]", \
"PF4U.junction4.h", 1, 1, 112, 1024)
DeclareAlias2("PF4U.junction4.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"PF4U.junction4.der(h)", 1, 6, 112, 1024)
DeclareVariable("PF4U.junction4.gas.s", "Specific entropy [J/(kg.K)]", 17362, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.T", "Temperature [K|degC]", 17363, 288.15, \
0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.junction4.gas.M", "Average molar mass [kg/mol]", \
"PF4U.junction4.gas.M_i[1]", 1, 5, 13162, 1024)
DeclareVariable("PF4U.junction4.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17364, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17365, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17366, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.kappa", "Isothermal compressibility [1/Pa]",\
 17367, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.w", "Speed of sound [m/s]", 17368, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17369, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17370, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.p_i[1]", "Partial pressure [Pa|bar]", 17371,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.junction4.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17372, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.phi", "Relative humidity", 13157, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13158, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.junction4.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13159, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13160, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13161, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17373, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction4.gas.M_i[1]", "Molar mass of component i [kg/mol]",\
 13162, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13163, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13164, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13165, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.transp.Pr", "Prandtl number [1]", 13166, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13167, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13168,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.transp.sigma", "Surface tension [N/m]", 13169,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction4.gas.computeFlags", "[:#(type=Integer)]", 13170, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction4.volume", "[m3]", 1310, 1E-05, 0.0,\
1.7976931348623157E+308,0.0,0,560)
DeclareParameter("PF4U.junction4.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1311, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.junction4.pInitial", "Initial value for air pressure [Pa|bar]",\
 1312, 2000000, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.junction4.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13171, false, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.junction4.TInitial", "Initial value for air temperature [K|K]",\
 1313, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.junction4.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1314, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.junction4.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13172, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.junction4.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1315, 1, 0.0,0.0,0.0,0,560)
DeclareState("PF4U.junction4.h", "Specific enthalpy [J/kg]", 112, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("PF4U.junction4.der(h)", "der(Specific enthalpy) [m2/s3]", 112,\
 0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("PF4U.junction4.p", "[Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.junction4.der(p)", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18,\
 0)
DeclareVariable("PF4U.junction4.mass", "Gas mass in control volume [kg]", 17374,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.junction4.drhodt", "[Pa.m-2.s]", 17375, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.junction4.hInitial", "[J/kg]", 13173, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13174, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.junction4.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13175, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction4.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13176, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13177,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13178, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13179,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13180, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13181, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13182, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasA.gasPointer.id", "[:#(type=Integer)]", 13183,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction4.gasA.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1316, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction4.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13184, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13185,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13186, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13187,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13188, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13189, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13190, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasB.gasPointer.id", "[:#(type=Integer)]", 13191,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction4.gasB.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1317, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction4.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13192, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction4.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13193,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13194, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13195,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13196, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction4.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13197, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13198, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction4.gasC.gasPointer.id", "[:#(type=Integer)]", 13199,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction4.gasC.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1318, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction5.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13200, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13201,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13202, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13203,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13204, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13205, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13206, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.simPort.vleFluidMass", "[kg]", 13207, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.simPort.vleFluidVolume", "[m3]", 13208, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.simPort.liquidMass", "[kg]", 13209, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.simPort.liquidVolume", "[m3]", 13210, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.junction5.simPort.gasMass", "[kg]", "PF4U.junction5.mass", 1,\
 5, 17390, 1024)
DeclareAlias2("PF4U.junction5.simPort.gasVolume", "[m3]", "PF4U.junction5.volume", 1,\
 7, 1319, 1024)
DeclareVariable("PF4U.junction5.simPort.dpdt", "", 13211, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.simPort.dpdtCounter", "", 13212, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.junction5.simPort.vleFluidPort.vleFluidMass", \
"Accumulated fluid mass [kg]", 13213, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction5.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13214, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction5.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13215, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction5.simPort.liquidPort.liquidVolume", \
"Accumulated liquid volume [m3]", 13216, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.junction5.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.junction5.mass", 1, 5, 17390, 1156)
DeclareAlias2("PF4U.junction5.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.junction5.volume", 1, 7, 1319, 1156)
DeclareVariable("PF4U.junction5.simPort.dpdtPort.dpdt", "", 13217, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.junction5.simPort.dpdtPort.counter", "", 13218, 0.0, \
0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction5.simPort.warningsPort.warnings", "Accumulated warnings",\
 13219, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction5.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13220, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction5.portA.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13221, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13222,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13223, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.portA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13224,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13225, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13226, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13227, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction5.portA.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareAlias2("PF4U.junction5.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4U.Channel3.m_flow", -1, 5, 16993, 132)
DeclareAlias2("PF4U.junction5.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction5.h", 1, 1, 113, 4)
DeclareVariable("PF4U.junction5.portB.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13228, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13229,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13230, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.portB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13231,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13232, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13233, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13234, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction5.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareVariable("PF4U.junction5.portB.m_flow", "Mass flow rate [kg/s]", 17376, \
0.0, 0.0,0.0,0.0,0,776)
DeclareAlias2("PF4U.junction5.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction5.h", 1, 1, 113, 4)
DeclareVariable("PF4U.junction5.portC.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13235, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13236,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13237, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.portC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13238,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13239, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13240, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13241, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction5.portC.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareAlias2("PF4U.junction5.portC.m_flow", "Mass flow rate [kg/s]", \
"PF4U.Channel4.m_flow", -1, 5, 16997, 132)
DeclareAlias2("PF4U.junction5.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction5.h", 1, 1, 113, 4)
DeclareVariable("PF4U.junction5.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13242, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13243,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13244, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gas.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13245,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gas.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13246, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13247, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13248, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gas.gasPointer.id", "[:#(type=Integer)]", 13249,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.junction5.gas.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 13250,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction5.gas.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 13251, false,\
 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction5.gas.d", "Density [kg/m3|g/cm3]", 17377, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.junction5.gas.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 1024)
DeclareAlias2("PF4U.junction5.gas.der(p)", "der(Pressure) [Pa/s]", \
"PF2U.tube2.der(p[1])", 1, 6, 18, 1024)
DeclareAlias2("PF4U.junction5.gas.h", "Specific enthalpy [J/kg]", \
"PF4U.junction5.h", 1, 1, 113, 1024)
DeclareAlias2("PF4U.junction5.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"PF4U.junction5.der(h)", 1, 6, 113, 1024)
DeclareVariable("PF4U.junction5.gas.s", "Specific entropy [J/(kg.K)]", 17378, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.T", "Temperature [K|degC]", 17379, 288.15, \
0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.junction5.gas.M", "Average molar mass [kg/mol]", \
"PF4U.junction5.gas.M_i[1]", 1, 5, 13257, 1024)
DeclareVariable("PF4U.junction5.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17380, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17381, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17382, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.kappa", "Isothermal compressibility [1/Pa]",\
 17383, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.w", "Speed of sound [m/s]", 17384, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17385, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17386, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.p_i[1]", "Partial pressure [Pa|bar]", 17387,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.junction5.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17388, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.phi", "Relative humidity", 13252, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13253, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.junction5.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13254, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13255, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13256, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17389, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction5.gas.M_i[1]", "Molar mass of component i [kg/mol]",\
 13257, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13258, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13259, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13260, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.transp.Pr", "Prandtl number [1]", 13261, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13262, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13263,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.transp.sigma", "Surface tension [N/m]", 13264,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction5.gas.computeFlags", "[:#(type=Integer)]", 13265, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction5.volume", "[m3]", 1319, 1E-05, 0.0,\
1.7976931348623157E+308,0.0,0,560)
DeclareParameter("PF4U.junction5.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1320, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.junction5.pInitial", "Initial value for air pressure [Pa|bar]",\
 1321, 2000000, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.junction5.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13266, false, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.junction5.TInitial", "Initial value for air temperature [K|K]",\
 1322, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.junction5.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1323, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.junction5.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13267, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.junction5.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1324, 1, 0.0,0.0,0.0,0,560)
DeclareState("PF4U.junction5.h", "Specific enthalpy [J/kg]", 113, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("PF4U.junction5.der(h)", "der(Specific enthalpy) [m2/s3]", 113,\
 0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("PF4U.junction5.p", "[Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.junction5.der(p)", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18,\
 0)
DeclareVariable("PF4U.junction5.mass", "Gas mass in control volume [kg]", 17390,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.junction5.drhodt", "[Pa.m-2.s]", 17391, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.junction5.hInitial", "[J/kg]", 13268, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13269, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.junction5.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13270, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction5.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13271, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13272,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13273, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13274,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13275, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13276, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13277, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasA.gasPointer.id", "[:#(type=Integer)]", 13278,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction5.gasA.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1325, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction5.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13279, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13280,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13281, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13282,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13283, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13284, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13285, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasB.gasPointer.id", "[:#(type=Integer)]", 13286,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction5.gasB.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1326, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction5.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13287, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction5.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13288,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13289, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13290,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13291, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction5.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13292, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13293, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction5.gasC.gasPointer.id", "[:#(type=Integer)]", 13294,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction5.gasC.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1327, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction6.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13295, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13296,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13297, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13298,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13299, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13300, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13301, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.simPort.vleFluidMass", "[kg]", 13302, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.simPort.vleFluidVolume", "[m3]", 13303, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.simPort.liquidMass", "[kg]", 13304, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.simPort.liquidVolume", "[m3]", 13305, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareAlias2("PF4U.junction6.simPort.gasMass", "[kg]", "PF4U.junction6.mass", 1,\
 5, 17405, 1024)
DeclareAlias2("PF4U.junction6.simPort.gasVolume", "[m3]", "PF4U.junction6.volume", 1,\
 7, 1328, 1024)
DeclareVariable("PF4U.junction6.simPort.dpdt", "", 13306, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.simPort.dpdtCounter", "", 13307, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("PF4U.junction6.simPort.vleFluidPort.vleFluidMass", \
"Accumulated fluid mass [kg]", 13308, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction6.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13309, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction6.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13310, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction6.simPort.liquidPort.liquidVolume", \
"Accumulated liquid volume [m3]", 13311, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("PF4U.junction6.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "PF4U.junction6.mass", 1, 5, 17405, 1156)
DeclareAlias2("PF4U.junction6.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "PF4U.junction6.volume", 1, 7, 1328, 1156)
DeclareVariable("PF4U.junction6.simPort.dpdtPort.dpdt", "", 13312, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("PF4U.junction6.simPort.dpdtPort.counter", "", 13313, 0.0, \
0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction6.simPort.warningsPort.warnings", "Accumulated warnings",\
 13314, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("PF4U.junction6.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13315, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction6.portA.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13316, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13317,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13318, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.portA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13319,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13320, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13321, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13322, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction6.portA.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareAlias2("PF4U.junction6.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4U.junction4.portB.m_flow", -1, 5, 17360, 132)
DeclareAlias2("PF4U.junction6.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction6.h", 1, 1, 114, 4)
DeclareVariable("PF4U.junction6.portB.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13323, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13324,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13325, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.portB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13326,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13327, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13328, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13329, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction6.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareAlias2("PF4U.junction6.portB.m_flow", "Mass flow rate [kg/s]", \
"PF4U.portB1.m_flow", 1, 5, 17114, 132)
DeclareAlias2("PF4U.junction6.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction6.h", 1, 1, 114, 4)
DeclareVariable("PF4U.junction6.portC.gasType.fixedMixingRatio", \
"Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13330, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13331,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13332, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.portC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13333,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13334, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13335, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13336, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("PF4U.junction6.portC.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 4)
DeclareAlias2("PF4U.junction6.portC.m_flow", "Mass flow rate [kg/s]", \
"PF4U.junction5.portB.m_flow", -1, 5, 17376, 132)
DeclareAlias2("PF4U.junction6.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "PF4U.junction6.h", 1, 1, 114, 4)
DeclareVariable("PF4U.junction6.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13337, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13338,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13339, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gas.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13340,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gas.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13341, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13342, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13343, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gas.gasPointer.id", "[:#(type=Integer)]", 13344,\
 0, 0.0,0.0,0.0,0,2565)
DeclareVariable("PF4U.junction6.gas.stateSelectPreferForInputs", \
"=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]", 13345,\
 false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction6.gas.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 13346, false,\
 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction6.gas.d", "Density [kg/m3|g/cm3]", 17392, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("PF4U.junction6.gas.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1,\
 1, 18, 1024)
DeclareAlias2("PF4U.junction6.gas.der(p)", "der(Pressure) [Pa/s]", \
"PF2U.tube2.der(p[1])", 1, 6, 18, 1024)
DeclareAlias2("PF4U.junction6.gas.h", "Specific enthalpy [J/kg]", \
"PF4U.junction6.h", 1, 1, 114, 1024)
DeclareAlias2("PF4U.junction6.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"PF4U.junction6.der(h)", 1, 6, 114, 1024)
DeclareVariable("PF4U.junction6.gas.s", "Specific entropy [J/(kg.K)]", 17393, \
0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.T", "Temperature [K|degC]", 17394, 288.15, \
0.0,1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("PF4U.junction6.gas.M", "Average molar mass [kg/mol]", \
"PF4U.junction6.gas.M_i[1]", 1, 5, 13352, 1024)
DeclareVariable("PF4U.junction6.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17395, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17396, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17397, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.kappa", "Isothermal compressibility [1/Pa]",\
 17398, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.w", "Speed of sound [m/s]", 17399, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17400, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17401, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.p_i[1]", "Partial pressure [Pa|bar]", 17402,\
 0.0, 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("PF4U.junction6.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17403, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.phi", "Relative humidity", 13347, -1, -1.0,\
100.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13348, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("PF4U.junction6.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13349, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13350, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13351, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17404, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("PF4U.junction6.gas.M_i[1]", "Molar mass of component i [kg/mol]",\
 13352, 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13353, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13354, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13355, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.transp.Pr", "Prandtl number [1]", 13356, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13357, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13358,\
 -1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.transp.sigma", "Surface tension [N/m]", 13359,\
 -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("PF4U.junction6.gas.computeFlags", "[:#(type=Integer)]", 13360, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction6.volume", "[m3]", 1328, 1E-05, 0.0,\
1.7976931348623157E+308,0.0,0,560)
DeclareParameter("PF4U.junction6.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1329, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("PF4U.junction6.pInitial", "Initial value for air pressure [Pa|bar]",\
 1330, 2000000, 0.0,0.0,0.0,0,560)
DeclareVariable("PF4U.junction6.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13361, false, 0.0,0.0,0.0,0,515)
DeclareParameter("PF4U.junction6.TInitial", "Initial value for air temperature [K|K]",\
 1331, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("PF4U.junction6.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1332, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("PF4U.junction6.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13362, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("PF4U.junction6.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1333, 1, 0.0,0.0,0.0,0,560)
DeclareState("PF4U.junction6.h", "Specific enthalpy [J/kg]", 114, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("PF4U.junction6.der(h)", "der(Specific enthalpy) [m2/s3]", 114,\
 0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("PF4U.junction6.p", "[Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("PF4U.junction6.der(p)", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18,\
 0)
DeclareVariable("PF4U.junction6.mass", "Gas mass in control volume [kg]", 17405,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("PF4U.junction6.drhodt", "[Pa.m-2.s]", 17406, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("PF4U.junction6.hInitial", "[J/kg]", 13363, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13364, false, 0.0,0.0,0.0,0,515)
DeclareVariable("PF4U.junction6.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13365, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("PF4U.junction6.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13366, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13367,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13368, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasA.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13369,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13370, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13371, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13372, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasA.gasPointer.id", "[:#(type=Integer)]", 13373,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction6.gasA.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1334, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction6.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13374, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13375,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13376, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasB.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13377,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13378, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13379, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13380, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasB.gasPointer.id", "[:#(type=Integer)]", 13381,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction6.gasB.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1335, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("PF4U.junction6.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13382, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("PF4U.junction6.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13383,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13384, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasC.gasType.mixingRatio_propertyCalculation[1]",\
 "Mixing ratio for fluid property calculation (={1} for pure components)", 13385,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13386, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("PF4U.junction6.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13387, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13388, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("PF4U.junction6.gasC.gasPointer.id", "[:#(type=Integer)]", 13389,\
 0, 0.0,0.0,0.0,0,2565)
DeclareParameter("PF4U.junction6.gasC.computeTransportProperties", \
"=true, if transport properties are calculated [:#(type=Boolean)]", 1336, false,\
 0.0,0.0,0.0,0,2610)
DeclareVariable("junction12.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13390, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 13391, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13392, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13393,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13394, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13395, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13396, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.simPort.vleFluidMass", "[kg]", 13397, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction12.simPort.vleFluidVolume", "[m3]", 13398, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.simPort.liquidMass", "[kg]", 13399, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction12.simPort.liquidVolume", "[m3]", 13400, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction12.simPort.gasMass", "[kg]", "junction12.mass", 1, 5, 17423,\
 1024)
DeclareAlias2("junction12.simPort.gasVolume", "[m3]", "junction12.volume", 1, 7,\
 1337, 1024)
DeclareVariable("junction12.simPort.dpdt", "", 13401, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.simPort.dpdtCounter", "", 13402, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 13403, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction12.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13404, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction12.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13405, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction12.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 13406, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction12.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction12.mass", 1, 5, 17423, 1156)
DeclareAlias2("junction12.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction12.volume", 1, 7, 1337, 1156)
DeclareVariable("junction12.simPort.dpdtPort.dpdt", "", 13407, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction12.simPort.dpdtPort.counter", "", 13408, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction12.simPort.warningsPort.warnings", "Accumulated warnings",\
 13409, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction12.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13410, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction12.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13411, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13412,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13413, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13414,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13415, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13416, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13417, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction12.portA.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareVariable("junction12.portA.m_flow", "Mass flow rate [kg/s]", 17407, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("junction12.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction12.h", 1, 1, 115, 4)
DeclareVariable("junction12.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13418, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13419,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13420, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13421,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13422, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13423, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13424, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction12.portB.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareVariable("junction12.portB.m_flow", "Mass flow rate [kg/s]", 17408, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("junction12.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction12.h", 1, 1, 115, 4)
DeclareVariable("junction12.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13425, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13426,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13427, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13428,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13429, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13430, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13431, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction12.portC.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareVariable("junction12.portC.m_flow", "Mass flow rate [kg/s]", 17409, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("junction12.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction12.h", 1, 1, 115, 4)
DeclareVariable("junction12.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13432, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13433,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13434, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13435,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13436, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13437, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13438, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gas.gasPointer.id", "[:#(type=Integer)]", 13439, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction12.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 13440, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction12.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 13441, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction12.gas.d", "Density [kg/m3|g/cm3]", 17410, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction12.gas.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 1024)
DeclareAlias2("junction12.gas.der(p)", "der(Pressure) [Pa/s]", "tube1.der(p[1])", 1,\
 6, 1, 1024)
DeclareAlias2("junction12.gas.h", "Specific enthalpy [J/kg]", "junction12.h", 1,\
 1, 115, 1024)
DeclareAlias2("junction12.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction12.der(h)", 1, 6, 115, 1024)
DeclareVariable("junction12.gas.s", "Specific entropy [J/(kg.K)]", 17411, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.T", "Temperature [K|degC]", 17412, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction12.gas.M", "Average molar mass [kg/mol]", \
"junction12.gas.M_i[1]", 1, 5, 13447, 1024)
DeclareVariable("junction12.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17413, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17414, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17415, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.kappa", "Isothermal compressibility [1/Pa]", 17416,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.w", "Speed of sound [m/s]", 17417, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction12.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17418, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17419, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.p_i[1]", "Partial pressure [Pa|bar]", 17420, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction12.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17421, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction12.gas.phi", "Relative humidity", 13442, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction12.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13443, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction12.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13444, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction12.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13445, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13446, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17422, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction12.gas.M_i[1]", "Molar mass of component i [kg/mol]", 13447,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction12.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13448, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13449, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13450, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.transp.Pr", "Prandtl number [1]", 13451, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13452, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13453, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction12.gas.transp.sigma", "Surface tension [N/m]", 13454, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction12.gas.computeFlags", "[:#(type=Integer)]", 13455, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction12.volume", "[m3]", 1337, 1E-05, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction12.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1338, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction12.pInitial", "Initial value for air pressure [Pa|bar]",\
 1339, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction12.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13456, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction12.TInitial", "Initial value for air temperature [K|K]",\
 1340, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction12.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1341, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction12.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13457, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction12.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1342, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction12.h", "Specific enthalpy [J/kg]", 115, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction12.der(h)", "der(Specific enthalpy) [m2/s3]", 115, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction12.p", "[Pa|bar]", "tube1.p[1]", 1, 1, 1, 0)
DeclareAlias2("junction12.der(p)", "[Pa/s]", "tube1.der(p[1])", 1, 6, 1, 0)
DeclareVariable("junction12.mass", "Gas mass in control volume [kg]", 17423, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction12.drhodt", "[Pa.m-2.s]", 17424, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction12.hInitial", "[J/kg]", 13458, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13459, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction12.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13460, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction12.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13461, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13462,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13463, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13464,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13465, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13466, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13467, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasA.gasPointer.id", "[:#(type=Integer)]", 13468, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction12.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1343, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction12.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13469, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13470,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13471, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13472,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13473, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13474, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13475, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasB.gasPointer.id", "[:#(type=Integer)]", 13476, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction12.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1344, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction12.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13477, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction12.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13478,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction12.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13479, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13480,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13481, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction12.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13482, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13483, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction12.gasC.gasPointer.id", "[:#(type=Integer)]", 13484, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction12.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1345, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction13.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13485, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 13486, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13487, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13488,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13489, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13490, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13491, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.simPort.vleFluidMass", "[kg]", 13492, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction13.simPort.vleFluidVolume", "[m3]", 13493, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.simPort.liquidMass", "[kg]", 13494, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction13.simPort.liquidVolume", "[m3]", 13495, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction13.simPort.gasMass", "[kg]", "junction13.mass", 1, 5, 17438,\
 1024)
DeclareAlias2("junction13.simPort.gasVolume", "[m3]", "junction13.volume", 1, 7,\
 1346, 1024)
DeclareVariable("junction13.simPort.dpdt", "", 13496, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.simPort.dpdtCounter", "", 13497, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 13498, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction13.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13499, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction13.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13500, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction13.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 13501, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction13.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction13.mass", 1, 5, 17438, 1156)
DeclareAlias2("junction13.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction13.volume", 1, 7, 1346, 1156)
DeclareVariable("junction13.simPort.dpdtPort.dpdt", "", 13502, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction13.simPort.dpdtPort.counter", "", 13503, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction13.simPort.warningsPort.warnings", "Accumulated warnings",\
 13504, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction13.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13505, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction13.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13506, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13507,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13508, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13509,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13510, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13511, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13512, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction13.portA.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction13.portA.m_flow", "Mass flow rate [kg/s]", \
"PF3U.portA1.m_flow", -1, 5, 16361, 132)
DeclareAlias2("junction13.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction13.h", 1, 1, 116, 4)
DeclareVariable("junction13.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13513, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13514,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13515, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13516,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13517, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13518, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13519, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction13.portB.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction13.portB.m_flow", "Mass flow rate [kg/s]", \
"junction12.portC.m_flow", -1, 5, 17409, 132)
DeclareAlias2("junction13.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction13.h", 1, 1, 116, 4)
DeclareVariable("junction13.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13520, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13521,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13522, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13523,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13524, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13525, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13526, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction13.portC.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction13.portC.m_flow", "Mass flow rate [kg/s]", \
"PF3L.portA1.m_flow", -1, 5, 16038, 132)
DeclareAlias2("junction13.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction13.h", 1, 1, 116, 4)
DeclareVariable("junction13.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13527, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13528,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13529, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13530,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13531, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13532, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13533, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gas.gasPointer.id", "[:#(type=Integer)]", 13534, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction13.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 13535, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction13.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 13536, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction13.gas.d", "Density [kg/m3|g/cm3]", 17425, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction13.gas.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 1024)
DeclareAlias2("junction13.gas.der(p)", "der(Pressure) [Pa/s]", "tube1.der(p[1])", 1,\
 6, 1, 1024)
DeclareAlias2("junction13.gas.h", "Specific enthalpy [J/kg]", "junction13.h", 1,\
 1, 116, 1024)
DeclareAlias2("junction13.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction13.der(h)", 1, 6, 116, 1024)
DeclareVariable("junction13.gas.s", "Specific entropy [J/(kg.K)]", 17426, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.T", "Temperature [K|degC]", 17427, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction13.gas.M", "Average molar mass [kg/mol]", \
"junction13.gas.M_i[1]", 1, 5, 13542, 1024)
DeclareVariable("junction13.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17428, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17429, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17430, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.kappa", "Isothermal compressibility [1/Pa]", 17431,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.w", "Speed of sound [m/s]", 17432, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction13.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17433, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17434, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.p_i[1]", "Partial pressure [Pa|bar]", 17435, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction13.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17436, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction13.gas.phi", "Relative humidity", 13537, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction13.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13538, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction13.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13539, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction13.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13540, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13541, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17437, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction13.gas.M_i[1]", "Molar mass of component i [kg/mol]", 13542,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction13.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13543, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13544, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13545, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.transp.Pr", "Prandtl number [1]", 13546, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13547, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13548, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction13.gas.transp.sigma", "Surface tension [N/m]", 13549, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction13.gas.computeFlags", "[:#(type=Integer)]", 13550, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction13.volume", "[m3]", 1346, 1E-05, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction13.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1347, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction13.pInitial", "Initial value for air pressure [Pa|bar]",\
 1348, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction13.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13551, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction13.TInitial", "Initial value for air temperature [K|K]",\
 1349, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction13.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1350, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction13.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13552, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction13.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1351, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction13.h", "Specific enthalpy [J/kg]", 116, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction13.der(h)", "der(Specific enthalpy) [m2/s3]", 116, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction13.p", "[Pa|bar]", "tube1.p[1]", 1, 1, 1, 0)
DeclareAlias2("junction13.der(p)", "[Pa/s]", "tube1.der(p[1])", 1, 6, 1, 0)
DeclareVariable("junction13.mass", "Gas mass in control volume [kg]", 17438, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction13.drhodt", "[Pa.m-2.s]", 17439, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction13.hInitial", "[J/kg]", 13553, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13554, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction13.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13555, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction13.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13556, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13557,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13558, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13559,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13560, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13561, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13562, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasA.gasPointer.id", "[:#(type=Integer)]", 13563, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction13.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1352, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction13.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13564, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13565,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13566, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13567,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13568, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13569, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13570, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasB.gasPointer.id", "[:#(type=Integer)]", 13571, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction13.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1353, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction13.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13572, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction13.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13573,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction13.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13574, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13575,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13576, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction13.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13577, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13578, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction13.gasC.gasPointer.id", "[:#(type=Integer)]", 13579, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction13.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1354, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction14.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13580, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 13581, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13582, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13583,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13584, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13585, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13586, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.simPort.vleFluidMass", "[kg]", 13587, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction14.simPort.vleFluidVolume", "[m3]", 13588, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.simPort.liquidMass", "[kg]", 13589, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction14.simPort.liquidVolume", "[m3]", 13590, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction14.simPort.gasMass", "[kg]", "junction14.mass", 1, 5, 17453,\
 1024)
DeclareAlias2("junction14.simPort.gasVolume", "[m3]", "junction14.volume", 1, 7,\
 1355, 1024)
DeclareVariable("junction14.simPort.dpdt", "", 13591, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.simPort.dpdtCounter", "", 13592, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 13593, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction14.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13594, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction14.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13595, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction14.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 13596, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction14.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction14.mass", 1, 5, 17453, 1156)
DeclareAlias2("junction14.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction14.volume", 1, 7, 1355, 1156)
DeclareVariable("junction14.simPort.dpdtPort.dpdt", "", 13597, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction14.simPort.dpdtPort.counter", "", 13598, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction14.simPort.warningsPort.warnings", "Accumulated warnings",\
 13599, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction14.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13600, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction14.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13601, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13602,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13603, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13604,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13605, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13606, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13607, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction14.portA.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction14.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4U.portA1.m_flow", -1, 5, 17113, 132)
DeclareAlias2("junction14.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction14.h", 1, 1, 117, 4)
DeclareVariable("junction14.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13608, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13609,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13610, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13611,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13612, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13613, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13614, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction14.portB.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction14.portB.m_flow", "Mass flow rate [kg/s]", \
"junction12.portA.m_flow", -1, 5, 17407, 132)
DeclareAlias2("junction14.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction14.h", 1, 1, 117, 4)
DeclareVariable("junction14.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13615, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13616,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13617, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13618,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13619, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13620, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13621, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction14.portC.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction14.portC.m_flow", "Mass flow rate [kg/s]", \
"PF4L.portA1.m_flow", -1, 5, 16688, 132)
DeclareAlias2("junction14.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction14.h", 1, 1, 117, 4)
DeclareVariable("junction14.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13622, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13623,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13624, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13625,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13626, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13627, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13628, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gas.gasPointer.id", "[:#(type=Integer)]", 13629, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction14.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 13630, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction14.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 13631, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction14.gas.d", "Density [kg/m3|g/cm3]", 17440, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction14.gas.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 1024)
DeclareAlias2("junction14.gas.der(p)", "der(Pressure) [Pa/s]", "tube1.der(p[1])", 1,\
 6, 1, 1024)
DeclareAlias2("junction14.gas.h", "Specific enthalpy [J/kg]", "junction14.h", 1,\
 1, 117, 1024)
DeclareAlias2("junction14.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction14.der(h)", 1, 6, 117, 1024)
DeclareVariable("junction14.gas.s", "Specific entropy [J/(kg.K)]", 17441, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.T", "Temperature [K|degC]", 17442, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction14.gas.M", "Average molar mass [kg/mol]", \
"junction14.gas.M_i[1]", 1, 5, 13637, 1024)
DeclareVariable("junction14.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17443, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17444, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17445, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.kappa", "Isothermal compressibility [1/Pa]", 17446,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.w", "Speed of sound [m/s]", 17447, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction14.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17448, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17449, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.p_i[1]", "Partial pressure [Pa|bar]", 17450, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction14.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17451, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction14.gas.phi", "Relative humidity", 13632, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction14.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13633, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction14.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13634, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction14.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13635, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13636, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17452, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction14.gas.M_i[1]", "Molar mass of component i [kg/mol]", 13637,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction14.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13638, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13639, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13640, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.transp.Pr", "Prandtl number [1]", 13641, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13642, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13643, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction14.gas.transp.sigma", "Surface tension [N/m]", 13644, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction14.gas.computeFlags", "[:#(type=Integer)]", 13645, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction14.volume", "[m3]", 1355, 1E-05, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction14.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1356, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction14.pInitial", "Initial value for air pressure [Pa|bar]",\
 1357, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction14.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13646, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction14.TInitial", "Initial value for air temperature [K|K]",\
 1358, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction14.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1359, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction14.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13647, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction14.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1360, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction14.h", "Specific enthalpy [J/kg]", 117, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction14.der(h)", "der(Specific enthalpy) [m2/s3]", 117, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction14.p", "[Pa|bar]", "tube1.p[1]", 1, 1, 1, 0)
DeclareAlias2("junction14.der(p)", "[Pa/s]", "tube1.der(p[1])", 1, 6, 1, 0)
DeclareVariable("junction14.mass", "Gas mass in control volume [kg]", 17453, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction14.drhodt", "[Pa.m-2.s]", 17454, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction14.hInitial", "[J/kg]", 13648, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13649, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction14.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13650, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction14.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13651, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13652,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13653, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13654,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13655, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13656, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13657, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasA.gasPointer.id", "[:#(type=Integer)]", 13658, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction14.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1361, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction14.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13659, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13660,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13661, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13662,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13663, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13664, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13665, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasB.gasPointer.id", "[:#(type=Integer)]", 13666, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction14.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1362, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction14.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13667, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction14.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13668,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction14.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13669, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13670,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13671, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction14.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13672, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13673, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction14.gasC.gasPointer.id", "[:#(type=Integer)]", 13674, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction14.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1363, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction15.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13675, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 13676, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13677, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13678,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13679, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13680, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13681, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.simPort.vleFluidMass", "[kg]", 13682, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction15.simPort.vleFluidVolume", "[m3]", 13683, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.simPort.liquidMass", "[kg]", 13684, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction15.simPort.liquidVolume", "[m3]", 13685, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction15.simPort.gasMass", "[kg]", "junction15.mass", 1, 5, 17469,\
 1024)
DeclareAlias2("junction15.simPort.gasVolume", "[m3]", "junction15.volume", 1, 7,\
 1364, 1024)
DeclareVariable("junction15.simPort.dpdt", "", 13686, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.simPort.dpdtCounter", "", 13687, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 13688, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction15.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13689, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction15.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13690, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction15.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 13691, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction15.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction15.mass", 1, 5, 17469, 1156)
DeclareAlias2("junction15.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction15.volume", 1, 7, 1364, 1156)
DeclareVariable("junction15.simPort.dpdtPort.dpdt", "", 13692, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction15.simPort.dpdtPort.counter", "", 13693, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction15.simPort.warningsPort.warnings", "Accumulated warnings",\
 13694, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction15.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13695, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction15.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13696, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13697,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13698, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13699,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13700, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13701, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13702, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction15.portA.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction15.portA.m_flow", "Mass flow rate [kg/s]", \
"PF3L.portB1.m_flow", -1, 5, 16039, 132)
DeclareAlias2("junction15.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction15.h", 1, 1, 118, 4)
DeclareVariable("junction15.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13703, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13704,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13705, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13706,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13707, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13708, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13709, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction15.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareVariable("junction15.portB.m_flow", "Mass flow rate [kg/s]", 17455, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("junction15.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction15.h", 1, 1, 118, 4)
DeclareVariable("junction15.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13710, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13711,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13712, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13713,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13714, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13715, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13716, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction15.portC.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction15.portC.m_flow", "Mass flow rate [kg/s]", \
"PF3U.portB1.m_flow", -1, 5, 16362, 132)
DeclareAlias2("junction15.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction15.h", 1, 1, 118, 4)
DeclareVariable("junction15.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13717, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13718,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13719, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13720,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13721, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13722, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13723, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gas.gasPointer.id", "[:#(type=Integer)]", 13724, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction15.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 13725, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction15.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 13726, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction15.gas.d", "Density [kg/m3|g/cm3]", 17456, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction15.gas.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18,\
 1024)
DeclareAlias2("junction15.gas.der(p)", "der(Pressure) [Pa/s]", "PF2U.tube2.der(p[1])", 1,\
 6, 18, 1024)
DeclareAlias2("junction15.gas.h", "Specific enthalpy [J/kg]", "junction15.h", 1,\
 1, 118, 1024)
DeclareAlias2("junction15.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction15.der(h)", 1, 6, 118, 1024)
DeclareVariable("junction15.gas.s", "Specific entropy [J/(kg.K)]", 17457, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.T", "Temperature [K|degC]", 17458, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction15.gas.M", "Average molar mass [kg/mol]", \
"junction15.gas.M_i[1]", 1, 5, 13732, 1024)
DeclareVariable("junction15.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17459, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17460, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17461, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.kappa", "Isothermal compressibility [1/Pa]", 17462,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.w", "Speed of sound [m/s]", 17463, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction15.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17464, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17465, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.p_i[1]", "Partial pressure [Pa|bar]", 17466, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction15.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17467, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction15.gas.phi", "Relative humidity", 13727, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction15.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13728, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction15.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13729, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction15.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13730, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13731, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17468, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction15.gas.M_i[1]", "Molar mass of component i [kg/mol]", 13732,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction15.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13733, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13734, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13735, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.transp.Pr", "Prandtl number [1]", 13736, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13737, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13738, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction15.gas.transp.sigma", "Surface tension [N/m]", 13739, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction15.gas.computeFlags", "[:#(type=Integer)]", 13740, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction15.volume", "[m3]", 1364, 1E-05, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction15.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1365, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction15.pInitial", "Initial value for air pressure [Pa|bar]",\
 1366, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction15.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13741, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction15.TInitial", "Initial value for air temperature [K|K]",\
 1367, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction15.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1368, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction15.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13742, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction15.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1369, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction15.h", "Specific enthalpy [J/kg]", 118, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction15.der(h)", "der(Specific enthalpy) [m2/s3]", 118, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction15.p", "[Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("junction15.der(p)", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18, 0)
DeclareVariable("junction15.mass", "Gas mass in control volume [kg]", 17469, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction15.drhodt", "[Pa.m-2.s]", 17470, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction15.hInitial", "[J/kg]", 13743, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13744, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction15.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13745, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction15.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13746, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13747,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13748, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13749,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13750, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13751, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13752, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasA.gasPointer.id", "[:#(type=Integer)]", 13753, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction15.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1370, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction15.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13754, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13755,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13756, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13757,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13758, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13759, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13760, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasB.gasPointer.id", "[:#(type=Integer)]", 13761, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction15.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1371, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction15.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13762, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction15.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13763,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction15.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13764, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13765,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13766, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction15.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13767, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13768, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction15.gasC.gasPointer.id", "[:#(type=Integer)]", 13769, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction15.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1372, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction16.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13770, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 13771, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13772, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13773,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13774, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13775, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13776, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.simPort.vleFluidMass", "[kg]", 13777, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction16.simPort.vleFluidVolume", "[m3]", 13778, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.simPort.liquidMass", "[kg]", 13779, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction16.simPort.liquidVolume", "[m3]", 13780, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction16.simPort.gasMass", "[kg]", "junction16.mass", 1, 5, 17485,\
 1024)
DeclareAlias2("junction16.simPort.gasVolume", "[m3]", "junction16.volume", 1, 7,\
 1373, 1024)
DeclareVariable("junction16.simPort.dpdt", "", 13781, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.simPort.dpdtCounter", "", 13782, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 13783, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction16.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13784, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction16.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13785, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction16.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 13786, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction16.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction16.mass", 1, 5, 17485, 1156)
DeclareAlias2("junction16.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction16.volume", 1, 7, 1373, 1156)
DeclareVariable("junction16.simPort.dpdtPort.dpdt", "", 13787, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction16.simPort.dpdtPort.counter", "", 13788, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction16.simPort.warningsPort.warnings", "Accumulated warnings",\
 13789, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction16.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13790, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction16.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13791, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13792,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13793, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13794,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13795, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13796, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13797, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction16.portA.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction16.portA.m_flow", "Mass flow rate [kg/s]", \
"PF4L.portB1.m_flow", -1, 5, 16689, 132)
DeclareAlias2("junction16.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction16.h", 1, 1, 119, 4)
DeclareVariable("junction16.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13798, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13799,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13800, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13801,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13802, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13803, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13804, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction16.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareVariable("junction16.portB.m_flow", "Mass flow rate [kg/s]", 17471, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("junction16.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction16.h", 1, 1, 119, 4)
DeclareVariable("junction16.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13805, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13806,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13807, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13808,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13809, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13810, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13811, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction16.portC.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction16.portC.m_flow", "Mass flow rate [kg/s]", \
"PF4U.portB1.m_flow", -1, 5, 17114, 132)
DeclareAlias2("junction16.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction16.h", 1, 1, 119, 4)
DeclareVariable("junction16.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13812, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13813,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13814, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13815,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13816, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13817, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13818, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gas.gasPointer.id", "[:#(type=Integer)]", 13819, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction16.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 13820, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction16.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 13821, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction16.gas.d", "Density [kg/m3|g/cm3]", 17472, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction16.gas.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18,\
 1024)
DeclareAlias2("junction16.gas.der(p)", "der(Pressure) [Pa/s]", "PF2U.tube2.der(p[1])", 1,\
 6, 18, 1024)
DeclareAlias2("junction16.gas.h", "Specific enthalpy [J/kg]", "junction16.h", 1,\
 1, 119, 1024)
DeclareAlias2("junction16.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction16.der(h)", 1, 6, 119, 1024)
DeclareVariable("junction16.gas.s", "Specific entropy [J/(kg.K)]", 17473, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.T", "Temperature [K|degC]", 17474, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction16.gas.M", "Average molar mass [kg/mol]", \
"junction16.gas.M_i[1]", 1, 5, 13827, 1024)
DeclareVariable("junction16.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17475, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17476, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17477, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.kappa", "Isothermal compressibility [1/Pa]", 17478,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.w", "Speed of sound [m/s]", 17479, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction16.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17480, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17481, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.p_i[1]", "Partial pressure [Pa|bar]", 17482, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction16.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17483, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction16.gas.phi", "Relative humidity", 13822, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction16.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13823, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction16.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13824, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction16.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13825, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13826, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17484, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction16.gas.M_i[1]", "Molar mass of component i [kg/mol]", 13827,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction16.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13828, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13829, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13830, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.transp.Pr", "Prandtl number [1]", 13831, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13832, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13833, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction16.gas.transp.sigma", "Surface tension [N/m]", 13834, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction16.gas.computeFlags", "[:#(type=Integer)]", 13835, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction16.volume", "[m3]", 1373, 1E-05, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction16.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1374, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction16.pInitial", "Initial value for air pressure [Pa|bar]",\
 1375, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction16.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13836, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction16.TInitial", "Initial value for air temperature [K|K]",\
 1376, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction16.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1377, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction16.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13837, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction16.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1378, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction16.h", "Specific enthalpy [J/kg]", 119, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction16.der(h)", "der(Specific enthalpy) [m2/s3]", 119, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction16.p", "[Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("junction16.der(p)", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18, 0)
DeclareVariable("junction16.mass", "Gas mass in control volume [kg]", 17485, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction16.drhodt", "[Pa.m-2.s]", 17486, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction16.hInitial", "[J/kg]", 13838, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13839, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction16.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13840, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction16.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13841, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13842,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13843, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13844,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13845, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13846, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13847, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasA.gasPointer.id", "[:#(type=Integer)]", 13848, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction16.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1379, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction16.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13849, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13850,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13851, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13852,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13853, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13854, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13855, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasB.gasPointer.id", "[:#(type=Integer)]", 13856, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction16.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1380, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction16.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13857, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction16.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13858,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction16.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13859, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13860,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13861, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction16.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13862, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13863, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction16.gasC.gasPointer.id", "[:#(type=Integer)]", 13864, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction16.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1381, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction17.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13865, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 13866, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13867, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13868,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13869, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13870, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13871, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.simPort.vleFluidMass", "[kg]", 13872, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction17.simPort.vleFluidVolume", "[m3]", 13873, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.simPort.liquidMass", "[kg]", 13874, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction17.simPort.liquidVolume", "[m3]", 13875, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction17.simPort.gasMass", "[kg]", "junction17.mass", 1, 5, 17501,\
 1024)
DeclareAlias2("junction17.simPort.gasVolume", "[m3]", "junction17.volume", 1, 7,\
 1382, 1024)
DeclareVariable("junction17.simPort.dpdt", "", 13876, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.simPort.dpdtCounter", "", 13877, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 13878, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction17.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13879, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction17.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13880, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction17.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 13881, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction17.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction17.mass", 1, 5, 17501, 1156)
DeclareAlias2("junction17.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction17.volume", 1, 7, 1382, 1156)
DeclareVariable("junction17.simPort.dpdtPort.dpdt", "", 13882, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction17.simPort.dpdtPort.counter", "", 13883, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction17.simPort.warningsPort.warnings", "Accumulated warnings",\
 13884, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction17.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13885, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction17.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13886, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13887,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13888, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13889,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13890, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13891, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13892, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction17.portA.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction17.portA.m_flow", "Mass flow rate [kg/s]", \
"junction15.portB.m_flow", -1, 5, 17455, 132)
DeclareAlias2("junction17.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction17.h", 1, 1, 120, 4)
DeclareVariable("junction17.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13893, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13894,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13895, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13896,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13897, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13898, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13899, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction17.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareVariable("junction17.portB.m_flow", "Mass flow rate [kg/s]", 17487, 0.0, \
0.0,0.0,0.0,0,776)
DeclareAlias2("junction17.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction17.h", 1, 1, 120, 4)
DeclareVariable("junction17.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13900, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13901,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13902, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13903,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13904, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13905, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13906, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction17.portC.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction17.portC.m_flow", "Mass flow rate [kg/s]", \
"junction16.portB.m_flow", -1, 5, 17471, 132)
DeclareAlias2("junction17.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction17.h", 1, 1, 120, 4)
DeclareVariable("junction17.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13907, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13908,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13909, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13910,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13911, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13912, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13913, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gas.gasPointer.id", "[:#(type=Integer)]", 13914, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction17.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 13915, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction17.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 13916, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction17.gas.d", "Density [kg/m3|g/cm3]", 17488, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction17.gas.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18,\
 1024)
DeclareAlias2("junction17.gas.der(p)", "der(Pressure) [Pa/s]", "PF2U.tube2.der(p[1])", 1,\
 6, 18, 1024)
DeclareAlias2("junction17.gas.h", "Specific enthalpy [J/kg]", "junction17.h", 1,\
 1, 120, 1024)
DeclareAlias2("junction17.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction17.der(h)", 1, 6, 120, 1024)
DeclareVariable("junction17.gas.s", "Specific entropy [J/(kg.K)]", 17489, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.T", "Temperature [K|degC]", 17490, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction17.gas.M", "Average molar mass [kg/mol]", \
"junction17.gas.M_i[1]", 1, 5, 13922, 1024)
DeclareVariable("junction17.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17491, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17492, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17493, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.kappa", "Isothermal compressibility [1/Pa]", 17494,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.w", "Speed of sound [m/s]", 17495, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction17.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17496, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17497, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.p_i[1]", "Partial pressure [Pa|bar]", 17498, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction17.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17499, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction17.gas.phi", "Relative humidity", 13917, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction17.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 13918, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction17.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 13919, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction17.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 13920, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 13921, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17500, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction17.gas.M_i[1]", "Molar mass of component i [kg/mol]", 13922,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction17.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 13923, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 13924, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 13925, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.transp.Pr", "Prandtl number [1]", 13926, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 13927, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.transp.eta", "Dynamic viscosity [Pa.s]", 13928, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction17.gas.transp.sigma", "Surface tension [N/m]", 13929, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction17.gas.computeFlags", "[:#(type=Integer)]", 13930, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction17.volume", "[m3]", 1382, 1E-05, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction17.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1383, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction17.pInitial", "Initial value for air pressure [Pa|bar]",\
 1384, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction17.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 13931, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction17.TInitial", "Initial value for air temperature [K|K]",\
 1385, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction17.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1386, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction17.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 13932, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction17.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1387, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction17.h", "Specific enthalpy [J/kg]", 120, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction17.der(h)", "der(Specific enthalpy) [m2/s3]", 120, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction17.p", "[Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("junction17.der(p)", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18, 0)
DeclareVariable("junction17.mass", "Gas mass in control volume [kg]", 17501, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction17.drhodt", "[Pa.m-2.s]", 17502, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction17.hInitial", "[J/kg]", 13933, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13934, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction17.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 13935, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction17.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13936, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13937,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13938, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13939,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13940, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13941, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13942, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasA.gasPointer.id", "[:#(type=Integer)]", 13943, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction17.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1388, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction17.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13944, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13945,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13946, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13947,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13948, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13949, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13950, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasB.gasPointer.id", "[:#(type=Integer)]", 13951, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction17.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1389, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction17.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13952, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction17.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13953,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction17.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13954, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13955,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13956, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction17.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13957, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13958, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction17.gasC.gasPointer.id", "[:#(type=Integer)]", 13959, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction17.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1390, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction18.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13960, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 13961, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13962, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13963,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 13964, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13965, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13966, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.simPort.vleFluidMass", "[kg]", 13967, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction18.simPort.vleFluidVolume", "[m3]", 13968, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.simPort.liquidMass", "[kg]", 13969, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction18.simPort.liquidVolume", "[m3]", 13970, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction18.simPort.gasMass", "[kg]", "junction18.mass", 1, 5, 17516,\
 1024)
DeclareAlias2("junction18.simPort.gasVolume", "[m3]", "junction18.volume", 1, 7,\
 1391, 1024)
DeclareVariable("junction18.simPort.dpdt", "", 13971, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.simPort.dpdtCounter", "", 13972, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 13973, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction18.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 13974, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction18.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 13975, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction18.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 13976, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction18.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction18.mass", 1, 5, 17516, 1156)
DeclareAlias2("junction18.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction18.volume", 1, 7, 1391, 1156)
DeclareVariable("junction18.simPort.dpdtPort.dpdt", "", 13977, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction18.simPort.dpdtPort.counter", "", 13978, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction18.simPort.warningsPort.warnings", "Accumulated warnings",\
 13979, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction18.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 13980, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction18.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13981, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13982,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13983, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13984,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13985, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13986, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13987, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction18.portA.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction18.portA.m_flow", "Mass flow rate [kg/s]", \
"junction11.portB.m_flow", -1, 5, 14612, 132)
DeclareAlias2("junction18.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction18.h", 1, 1, 121, 4)
DeclareVariable("junction18.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13988, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13989,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13990, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13991,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13992, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 13993, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 13994, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction18.portB.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction18.portB.m_flow", "Mass flow rate [kg/s]", \
"junction4.portA.m_flow", -1, 5, 14431, 132)
DeclareAlias2("junction18.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction18.h", 1, 1, 121, 4)
DeclareVariable("junction18.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 13995, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 13996,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 13997, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 13998,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 13999, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14000, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14001, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction18.portC.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1,\
 18, 4)
DeclareAlias2("junction18.portC.m_flow", "Mass flow rate [kg/s]", \
"junction17.portB.m_flow", -1, 5, 17487, 132)
DeclareAlias2("junction18.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction18.h", 1, 1, 121, 4)
DeclareVariable("junction18.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14002, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14003,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14004, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14005,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 14006, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14007, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14008, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gas.gasPointer.id", "[:#(type=Integer)]", 14009, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction18.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 14010, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction18.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 14011, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction18.gas.d", "Density [kg/m3|g/cm3]", 17503, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction18.gas.p", "Pressure [Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18,\
 1024)
DeclareAlias2("junction18.gas.der(p)", "der(Pressure) [Pa/s]", "PF2U.tube2.der(p[1])", 1,\
 6, 18, 1024)
DeclareAlias2("junction18.gas.h", "Specific enthalpy [J/kg]", "junction18.h", 1,\
 1, 121, 1024)
DeclareAlias2("junction18.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction18.der(h)", 1, 6, 121, 1024)
DeclareVariable("junction18.gas.s", "Specific entropy [J/(kg.K)]", 17504, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.T", "Temperature [K|degC]", 17505, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction18.gas.M", "Average molar mass [kg/mol]", \
"junction18.gas.M_i[1]", 1, 5, 14017, 1024)
DeclareVariable("junction18.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17506, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17507, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17508, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.kappa", "Isothermal compressibility [1/Pa]", 17509,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.w", "Speed of sound [m/s]", 17510, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction18.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17511, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17512, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.p_i[1]", "Partial pressure [Pa|bar]", 17513, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction18.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17514, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction18.gas.phi", "Relative humidity", 14012, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction18.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 14013, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction18.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 14014, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction18.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 14015, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 14016, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17515, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction18.gas.M_i[1]", "Molar mass of component i [kg/mol]", 14017,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction18.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 14018, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 14019, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 14020, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.transp.Pr", "Prandtl number [1]", 14021, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 14022, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.transp.eta", "Dynamic viscosity [Pa.s]", 14023, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction18.gas.transp.sigma", "Surface tension [N/m]", 14024, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction18.gas.computeFlags", "[:#(type=Integer)]", 14025, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction18.volume", "[m3]", 1391, 1E-05, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction18.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1392, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction18.pInitial", "Initial value for air pressure [Pa|bar]",\
 1393, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction18.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 14026, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction18.TInitial", "Initial value for air temperature [K|K]",\
 1394, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction18.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1395, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction18.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 14027, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction18.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1396, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction18.h", "Specific enthalpy [J/kg]", 121, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction18.der(h)", "der(Specific enthalpy) [m2/s3]", 121, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction18.p", "[Pa|bar]", "PF2U.tube2.p[1]", 1, 1, 18, 0)
DeclareAlias2("junction18.der(p)", "[Pa/s]", "PF2U.tube2.der(p[1])", 1, 6, 18, 0)
DeclareVariable("junction18.mass", "Gas mass in control volume [kg]", 17516, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction18.drhodt", "[Pa.m-2.s]", 17517, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction18.hInitial", "[J/kg]", 14028, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 14029, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction18.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 14030, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction18.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14031, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14032,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14033, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14034,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14035, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14036, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14037, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasA.gasPointer.id", "[:#(type=Integer)]", 14038, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction18.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1397, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction18.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14039, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14040,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14041, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14042,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14043, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14044, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14045, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasB.gasPointer.id", "[:#(type=Integer)]", 14046, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction18.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1398, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction18.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14047, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction18.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14048,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction18.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14049, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14050,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14051, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction18.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14052, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14053, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction18.gasC.gasPointer.id", "[:#(type=Integer)]", 14054, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction18.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1399, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction19.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14055, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.gasType.nc_propertyCalculation", "Number of components for fluid property calculations [:#(type=Integer)]",\
 14056, 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14057, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14058,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 14059, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14060, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14061, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.simPort.vleFluidMass", "[kg]", 14062, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareVariable("junction19.simPort.vleFluidVolume", "[m3]", 14063, 0.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.simPort.liquidMass", "[kg]", 14064, 0.0, 0.0,0.0,0.0,\
0,2561)
DeclareVariable("junction19.simPort.liquidVolume", "[m3]", 14065, 0.0, 0.0,0.0,\
0.0,0,2561)
DeclareAlias2("junction19.simPort.gasMass", "[kg]", "junction19.mass", 1, 5, 17531,\
 1024)
DeclareAlias2("junction19.simPort.gasVolume", "[m3]", "junction19.volume", 1, 7,\
 1400, 1024)
DeclareVariable("junction19.simPort.dpdt", "", 14066, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.simPort.dpdtCounter", "", 14067, 0.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.simPort.vleFluidPort.vleFluidMass", "Accumulated fluid mass [kg]",\
 14068, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction19.simPort.vleFluidPort.vleFluidVolume", \
"Accumulated fluid volume [m3]", 14069, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction19.simPort.liquidPort.liquidMass", "Accumulated liquid mass [kg]",\
 14070, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction19.simPort.liquidPort.liquidVolume", "Accumulated liquid volume [m3]",\
 14071, 0.0, 0.0,0.0,0.0,0,2825)
DeclareAlias2("junction19.simPort.gasPort.gasMass", "Accumulated gas mass [kg]",\
 "junction19.mass", 1, 5, 17531, 1156)
DeclareAlias2("junction19.simPort.gasPort.gasVolume", "Accumulated gas volume [m3]",\
 "junction19.volume", 1, 7, 1400, 1156)
DeclareVariable("junction19.simPort.dpdtPort.dpdt", "", 14072, 0.0, 0.0,0.0,0.0,\
0,2825)
DeclareVariable("junction19.simPort.dpdtPort.counter", "", 14073, 0.0, 0.0,0.0,\
0.0,0,2825)
DeclareVariable("junction19.simPort.warningsPort.warnings", "Accumulated warnings",\
 14074, 0.0, 0.0,0.0,0.0,0,2825)
DeclareVariable("junction19.generateEventsAtFlowReversal", "[:#(type=Boolean)]",\
 14075, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction19.portA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14076, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.portA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14077,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.portA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14078, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.portA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14079,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.portA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14080, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.portA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14081, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.portA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14082, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction19.portA.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction19.portA.m_flow", "Mass flow rate [kg/s]", \
"junction12.portB.m_flow", -1, 5, 17408, 132)
DeclareAlias2("junction19.portA.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction19.h", 1, 1, 122, 4)
DeclareVariable("junction19.portB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14083, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.portB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14084,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.portB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14085, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.portB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14086,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.portB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14087, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.portB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14088, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.portB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14089, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction19.portB.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction19.portB.m_flow", "Mass flow rate [kg/s]", \
"junction7.portB.m_flow", -1, 5, 14544, 132)
DeclareAlias2("junction19.portB.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction19.h", 1, 1, 122, 4)
DeclareVariable("junction19.portC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14090, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.portC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14091,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.portC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14092, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.portC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14093,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.portC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14094, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.portC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14095, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.portC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14096, 1, 0.0,0.0,0.0,0,1541)
DeclareAlias2("junction19.portC.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 4)
DeclareAlias2("junction19.portC.m_flow", "Mass flow rate [kg/s]", \
"junction1.portB.m_flow", -1, 5, 14346, 132)
DeclareAlias2("junction19.portC.h_outflow", "Specific thermodynamic enthalpy close to the connection point if m_flow < 0 [J/kg]",\
 "junction19.h", 1, 1, 122, 4)
DeclareVariable("junction19.gas.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14097, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.gas.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14098,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.gas.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14099, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gas.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14100,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gas.gasType.defaultMixingRatio[1]", "Default composition for models in Modelica (={1} for pure components)",\
 14101, 1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gas.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14102, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gas.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14103, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gas.gasPointer.id", "[:#(type=Integer)]", 14104, 0, \
0.0,0.0,0.0,0,2565)
DeclareVariable("junction19.gas.stateSelectPreferForInputs", "=true, StateSelect.prefer is set for input variables [:#(type=Boolean)]",\
 14105, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction19.gas.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 14106, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction19.gas.d", "Density [kg/m3|g/cm3]", 17518, 0.0, 0.0,\
1.7976931348623157E+308,0.0,0,2560)
DeclareAlias2("junction19.gas.p", "Pressure [Pa|bar]", "tube1.p[1]", 1, 1, 1, 1024)
DeclareAlias2("junction19.gas.der(p)", "der(Pressure) [Pa/s]", "tube1.der(p[1])", 1,\
 6, 1, 1024)
DeclareAlias2("junction19.gas.h", "Specific enthalpy [J/kg]", "junction19.h", 1,\
 1, 122, 1024)
DeclareAlias2("junction19.gas.der(h)", "der(Specific enthalpy) [m2/s3]", \
"junction19.der(h)", 1, 6, 122, 1024)
DeclareVariable("junction19.gas.s", "Specific entropy [J/(kg.K)]", 17519, 0.0, \
0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.T", "Temperature [K|degC]", 17520, 288.15, 0.0,\
1.7976931348623157E+308,300.0,0,2560)
DeclareAlias2("junction19.gas.M", "Average molar mass [kg/mol]", \
"junction19.gas.M_i[1]", 1, 5, 14112, 1024)
DeclareVariable("junction19.gas.cp", "Specific isobaric heat capacity cp [J/(kg.K)]",\
 17521, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.cv", "Specific isochoric heat capacity cv [J/(kg.K)]",\
 17522, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.beta", "Isobaric thermal expansion coefficient [1/K]",\
 17523, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.kappa", "Isothermal compressibility [1/Pa]", 17524,\
 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.w", "Speed of sound [m/s]", 17525, 0.0, 0.0,0.0,\
0.0,0,2560)
DeclareVariable("junction19.gas.drhodh_pxi", "Derivative of density wrt specific enthalpy at constant pressure and mass fraction [kg.s2/m5]",\
 17526, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.drhodp_hxi", "Derivative of density wrt pressure at specific enthalpy and mass fraction [s2/m2]",\
 17527, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.p_i[1]", "Partial pressure [Pa|bar]", 17528, 0.0,\
 0.0,1.7976931348623157E+308,100000.0,0,2560)
DeclareVariable("junction19.gas.xi_gas", "Mass fraction of gasoues condensing component [1]",\
 17529, 0.0, 0.0,1.0,0.0,0,2560)
DeclareVariable("junction19.gas.phi", "Relative humidity", 14107, -1, -1.0,100.0,\
0.0,0,2561)
DeclareVariable("junction19.gas.p_s", "Saturation partial pressure of condensing component [Pa|bar]",\
 14108, -1, -1.0,1.7976931348623157E+308,100000.0,0,2561)
DeclareVariable("junction19.gas.xi_s", "Saturation mass fraction of condensing component [1]",\
 14109, -1, -1.0,1.0,0.0,0,2561)
DeclareVariable("junction19.gas.delta_hv", "Specific enthalpy of vaporation of condensing component [J/kg]",\
 14110, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.delta_hd", "Specific enthalpy of desublimation of condensing component [J/kg]",\
 14111, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.h_i[1]", "Specific enthalpy of pure ideal gas component [J/kg]",\
 17530, 0.0, 0.0,0.0,0.0,0,2560)
DeclareVariable("junction19.gas.M_i[1]", "Molar mass of component i [kg/mol]", 14112,\
 0.0, 0.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction19.gas.humRatio", "Content of condensing component aka humidity ratio [1]",\
 14113, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.humRatio_s", "Saturation content of condensing component aka saturation humidity ratio",\
 14114, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.h1px", "Enthalpy H divided by the mass of components that cannot condense [J/kg]",\
 14115, -1, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.transp.Pr", "Prandtl number [1]", 14116, -1.0, \
0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.transp.lambda", "Thermal conductivity [W/(m.K)]",\
 14117, -1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.transp.eta", "Dynamic viscosity [Pa.s]", 14118, \
-1.0, -1.0,1.7976931348623157E+308,0.0,0,2561)
DeclareVariable("junction19.gas.transp.sigma", "Surface tension [N/m]", 14119, \
-1.0, 0.0,0.0,0.0,0,2561)
DeclareVariable("junction19.gas.computeFlags", "[:#(type=Integer)]", 14120, 0, \
0.0,0.0,0.0,0,2565)
DeclareParameter("junction19.volume", "[m3]", 1400, 1E-05, 0.0,1.7976931348623157E+308,\
0.0,0,560)
DeclareParameter("junction19.m_flowStart", "Start value for mass flow rate [kg/s]",\
 1401, 1E-05, 0.0,0.0,0.0,0,560)
DeclareParameter("junction19.pInitial", "Initial value for air pressure [Pa|bar]",\
 1402, 4000000, 0.0,0.0,0.0,0,560)
DeclareVariable("junction19.fixedInitialPressure", "if true, initial pressure is fixed [:#(type=Boolean)]",\
 14121, false, 0.0,0.0,0.0,0,515)
DeclareParameter("junction19.TInitial", "Initial value for air temperature [K|K]",\
 1403, 80, 0.0,1.7976931348623157E+308,300.0,0,560)
DeclareParameter("junction19.phiInitial", "Initial value for gas relative humidity (0%-100%)",\
 1404, 60.0, 0.0,100.0,0.0,0,560)
DeclareVariable("junction19.mixingRatioInitial[1]", "Initial array for mixing ratio of mass fraction e.g. {2, 10, 0.3}",\
 14122, 1.0, 0.0,0.0,0.0,0,513)
DeclareParameter("junction19.molarMixingRatioInitial[1]", "Initial array for mixing ratio of mole fraction e.g. {2, 10, 0.3}",\
 1405, 1, 0.0,0.0,0.0,0,560)
DeclareState("junction19.h", "Specific enthalpy [J/kg]", 122, 0.0, 0.0,0.0,\
100000.0,0,544)
DeclareDerivative("junction19.der(h)", "der(Specific enthalpy) [m2/s3]", 122, \
0.0, 0.0,0.0,0.0,0,576)
DeclareAlias2("junction19.p", "[Pa|bar]", "tube1.p[1]", 1, 1, 1, 0)
DeclareAlias2("junction19.der(p)", "[Pa/s]", "tube1.der(p[1])", 1, 6, 1, 0)
DeclareVariable("junction19.mass", "Gas mass in control volume [kg]", 17531, 0.0,\
 0.0,1.7976931348623157E+308,0.0,0,512)
DeclareVariable("junction19.drhodt", "[Pa.m-2.s]", 17532, 0.0, 0.0,0.0,0.0,0,512)
DeclareVariable("junction19.hInitial", "[J/kg]", 14123, 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.includeDefaultSummary", "Include summary record in model results [:#(type=Boolean)]",\
 14124, false, 0.0,0.0,0.0,0,515)
DeclareVariable("junction19.includeSummary", "Include summary record in model results [:#(type=Boolean)]",\
 14125, false, 0.0,0.0,0.0,0,2563)
DeclareVariable("junction19.gasA.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14126, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.gasA.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14127,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.gasA.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14128, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasA.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14129,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasA.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14130, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasA.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14131, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasA.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14132, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasA.gasPointer.id", "[:#(type=Integer)]", 14133, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction19.gasA.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1406, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction19.gasB.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14134, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.gasB.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14135,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.gasB.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14136, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasB.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14137,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasB.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14138, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasB.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14139, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasB.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14140, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasB.gasPointer.id", "[:#(type=Integer)]", 14141, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction19.gasB.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1407, false, 0.0,0.0,0.0,0,2610)
DeclareVariable("junction19.gasC.gasType.fixedMixingRatio", "Treat medium as pseudo pure in Modelica if it is a mixture [:#(type=Boolean)]",\
 14142, true, 0.0,0.0,0.0,0,1539)
DeclareVariable("junction19.gasC.gasType.nc_propertyCalculation", \
"Number of components for fluid property calculations [:#(type=Integer)]", 14143,\
 1, 1.0,1.7976931348623157E+308,0.0,0,1541)
DeclareVariable("junction19.gasC.gasType.nc", "Number of components in Modelica models [:#(type=Integer)]",\
 14144, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasC.gasType.mixingRatio_propertyCalculation[1]", \
"Mixing ratio for fluid property calculation (={1} for pure components)", 14145,\
 0.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasC.gasType.defaultMixingRatio[1]", \
"Default composition for models in Modelica (={1} for pure components)", 14146, \
1.0, 0.0,0.0,0.0,0,1537)
DeclareVariable("junction19.gasC.gasType.condensingIndex", "Index of condensing component (=0, if no condensation is desired) [:#(type=Integer)]",\
 14147, 0, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasC.gasType.ID", "ID is used to map the selected Gas to the sim.cumulatedGasMass array item [:#(type=Integer)]",\
 14148, 1, 0.0,0.0,0.0,0,1541)
DeclareVariable("junction19.gasC.gasPointer.id", "[:#(type=Integer)]", 14149, 0,\
 0.0,0.0,0.0,0,2565)
DeclareParameter("junction19.gasC.computeTransportProperties", "=true, if transport properties are calculated [:#(type=Boolean)]",\
 1408, false, 0.0,0.0,0.0,0,2610)
EndNonAlias(16)
PreNonAliasNew(17)
