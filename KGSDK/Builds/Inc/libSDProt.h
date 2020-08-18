#ifndef LIBSDPROT_H
#define LIBSDPROT_H

#include <windef.h>

#ifdef __cplusplus
extern "C" {
#endif

BOOL __stdcall SDP_Init(const char* ProdIdString);
void __stdcall SDP_Deinit(void);
BOOL __stdcall SDP_IsSDInserted(void);
BOOL __stdcall SDP_IsSDValid(void);
void __stdcall SDP_ReturnFromPowerMenu(void);

#ifdef __cplusplus
}
#endif

#endif