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

#define CE_PROCESSSTATS_OBJ			0
#define CE_PROCESS_KERNAL_TIME		2
#define CE_PROCESS_USER_TIME		4
#define CE_PROCESS_PROCESSOR_TIME	6
#define CE_PROCESS_THREAD_COUNT		8
#define CE_PROCESS_HEAP_BYTES		10
#define CE_PROCESS_ID				12
#define CE_PROCESS_TOTAL_PRIV_TIME  16 
#define CE_PROCESS_TOTAL_USER_TIME  18
