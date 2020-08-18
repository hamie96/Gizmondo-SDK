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

#define CE_SYSTEMSTATS_OBJ			0
#define CE_SYSTEM_PERCENT_PRIVILEGE 2
#define CE_SYSTEM_PERCENT_PROCESSOR 4
#define CE_SYSTEM_PERCENT_USER      6
#define CE_SYSTEM_PROCESS_COUNT     8
#define CE_SYSTEM_THREAD_COUNT      10
#define CE_SYSTEM_SECONDS_UPTIME    12
#define CE_SYSTEM_TOTAL_PRIV_TIME   14
#define CE_SYSTEM_TOTAL_USER_TIME   16
