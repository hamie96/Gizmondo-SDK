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


#define CE_TCPSTATS_OBJ			  0
#define RTO_ALGO				  2
#define RTO_MIN					  4
#define RTO_MAX					  6
#define MAX_CONNECTIONS			  8
#define ACTIVE_OPENS			  10
#define PASSIVE_OPENS			  12
#define FAILED_ATTEMPTS			  14
#define ESTABLISHED_RESETS		  16
#define CURRENT_ESTABLISHED		  18
#define SEGMENTS_RECV			  20
#define SEGMENTS_RECV_PER_SEC	  22
#define SEGMENTS_SENT			  24
#define SEGMENTS_SENT_PER_SEC	  26
#define SEGMENTS_RETRANS		  28
#define SEGMENTS_RETRANS_PER_SEC  30
#define INCOMING_ERRORS			  32
#define OUTGOING_RESETS			  34
#define CUMULATIVE_CONNECTIONS	  36
