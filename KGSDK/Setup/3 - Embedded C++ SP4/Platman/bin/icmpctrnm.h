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

#define CE_ICMPSTATS_OBJ			0 

#define CE_MESSAGES					2 
#define CE_MESSAGES_PER_SEC			4 
#define CE_ERRORS					6 
#define CE_DESC_UNREACHABLE			8 
#define CE_TIME_EXCEDED				10
#define CE_PARAM_PROBLEMS			12
#define CE_SOURCES_QUENCHES			14
#define CE_REDIRECTS				16
#define CE_REDIRECTS_PER_SEC      	18
#define CE_ECHOS					20
#define CE_ECHOS_PER_SEC          	22
#define CE_ECHO_REPS				24
#define CE_ECHO_PER_SEC_REPS      	26
#define CE_TIMESTAMPS				28
#define CE_TIMESTAMPS_PER_SEC     	30
#define CE_TIMESTAMPS_REPS			32
#define CE_TIMESTAMPS_PER_SEC_REPS	34
#define CE_ADDRESS_MASKS			36
#define CE_ADDRESS_MASKS_REPS		38
