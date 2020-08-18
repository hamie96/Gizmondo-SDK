

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for server.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IServer,0xE1EBB0FC,0x00A2,0x11D2,0xBB,0xA0,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IServerConnection,0xE1EBB0FE,0x00A2,0x11D2,0xBB,0xA0,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IServerConnectionEx,0x66C1CB98,0xE7EE,0x11d2,0xBB,0xEC,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IServerConnectionEx2,0xF764C0AC,0xBD25,0x4529,0xB3,0xCD,0x4D,0x96,0xEB,0xF5,0x61,0xF4);


MIDL_DEFINE_GUID(IID, IID_IServerConnectionEx3,0x67E498EF,0x22A7,0x4506,0x81,0x76,0xA4,0xA2,0xE2,0x3E,0x46,0xD8);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for server.idl:
    Oicf, W1, Zp8, env=Win64 (32b run,appending)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if defined(_M_IA64) || defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IServer,0xE1EBB0FC,0x00A2,0x11D2,0xBB,0xA0,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IServerConnection,0xE1EBB0FE,0x00A2,0x11D2,0xBB,0xA0,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IServerConnectionEx,0x66C1CB98,0xE7EE,0x11d2,0xBB,0xEC,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IServerConnectionEx2,0xF764C0AC,0xBD25,0x4529,0xB3,0xCD,0x4D,0x96,0xEB,0xF5,0x61,0xF4);


MIDL_DEFINE_GUID(IID, IID_IServerConnectionEx3,0x67E498EF,0x22A7,0x4506,0x81,0x76,0xA4,0xA2,0xE2,0x3E,0x46,0xD8);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

