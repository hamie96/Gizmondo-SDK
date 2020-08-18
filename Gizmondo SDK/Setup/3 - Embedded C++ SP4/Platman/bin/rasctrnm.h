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

#define CE_RASSTATS_OBJ       0
#define BYTES_XMITED          2
#define BYTES_RCVED           4
#define FRAMES_XMITED         6
#define FRAMES_RCVED          8
#define CRC_ERR               10
#define TIMEOUT_ERR           12
#define ALIGNMENT_ERR         14
#define HARDWARE_OVERRUN_ERR  16
#define FRAMING_ERR           18
#define BUFFER_OVERRUN_ERR    20
#define COMP_RATION_IN        22
#define COMP_RATION_OUT       24
#define BPS                   26
#define CONN_DURATION         28
#define TOTAL_ERRORS          30
#define BYTES_XMITED_PER_SEC  32
#define BYTES_RCVED_PER_SEC   34
#define FRAMES_XMITED_PER_SEC 36
#define FRAMES_RCVED_PER_SEC  38
#define TOTAL_ERRORS_PER_SEC  40
