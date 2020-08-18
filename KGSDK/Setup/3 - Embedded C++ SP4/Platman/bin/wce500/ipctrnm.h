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


#define CE_IPSTATS_OBJ			    0  
#define FORWARDING				    2  
#define DEFAULT_TTL					4
#define IN_RECEIVES					6
#define IN_RECEIVES_PER_SEC			8		
#define IN_HEADER_ERRORS			10
#define IN_ADDRESS_ERRORS			12
#define FORWARD_DATAGRAMS			14
#define FORWARD_DATAGRAMS_PER_SEC   16
#define IN_UNKNOWN_PROTOCOLS	    18
#define IN_DISCARDS	                20       	
#define IN_DELIVERS		            22          
#define IN_DELIVERS_PER_SEC         24      
#define OUT_REQUESTS			    26
#define OUT_REQUESTS_PER_SEC        28     
#define ROUTING_DISCARDS			30
#define OUT_DISCARDS                32
#define OUT_NO_ROUTES               34
#define REASM_TIMEOUT		        36
#define REASMS_REQUIRED			    38
#define REASMS_OK			        40
#define REASMS_OK_PER_SEC           42    
#define REASMS_FAILED	            44
#define FRAGS_OK                    46
#define FRAGS_OK_PER_SEC            48 
#define FRAGS_FAILED                50
#define FRAGS_FAILED_PER_SEC        52
#define FRAG_CREATES                54
#define FRAG_CREATES_PER_SEC        56  
#define NUM_IF                      58
#define NUM_ADDR                    60
#define NUM_ROUTES                  62
                        
