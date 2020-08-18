//
//  genctrnm.h
//
//  Offset definition file for exensible counter objects and counters
//
//  These "relative" offsets must start at 0 and be multiples of 2 (i.e.
//  even numbers). In the Open Procedure, they will be added to the 
//  "First Counter" and "First Help" values fo the device they belong to, 
//  in order to determine the  absolute location of the counter and 
//  object names and corresponding help text in the registry.
//
//  this file is used by the extensible counter DLL code as well as the 
//  counter name and help text definition file (.INI) file that is used
//  by LODCTR to load the names into the registry.
//

#define CE_BATTERYSTATS_OBJ			0
#define CE_BATTERY_ACPOWERSTATUS	2
#define CE_BATTERY_CHARGESTATUS		4
#define CE_BATTERY_PERCENTLIFE		6
#define CE_BATTERY_SECBATTERYLEFT	8
#define CE_BATTERY_SECBATTERYFULL	10
#define CE_BATTERY_BUCHARGESTATUS	12
#define CE_BATTERY_BUPERCENTLIFE	14
#define CE_BATTERY_BUSECBATTERYLEFT	16
#define CE_BATTERY_BUSECBATTERYFULL	18

