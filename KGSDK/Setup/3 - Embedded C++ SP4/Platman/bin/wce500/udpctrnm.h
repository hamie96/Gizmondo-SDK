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

#define CE_UDPSTATS_OBJ				0
#define CE_IN_DATAGRAMS				2
#define CE_IN_DATAGRAMS_PER_SEC	    4
#define CE_NO_PORTS		        	6
#define CE_NO_PORTS_PER_SEC		    8
#define CE_IN_ERRORS				10
#define CE_OUT_DATAGRAMS			12
#define CE_OUT_DATAGRAMS_PER_SEC    14
#define CE_NUM_ADDRS				16
#define CE_DATAGRAMS_PER_SEC		18


