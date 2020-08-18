

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for vcecominterfaces.idl:
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

MIDL_DEFINE_GUID(IID, IID_IDMATransportCompletionSink,0xAC6A6347,0xECE0,0x46c1,0xB6,0x68,0x9D,0xF3,0xA1,0x71,0x53,0xC8);


MIDL_DEFINE_GUID(IID, IID_IEmulatorVirtualMachineManager,0x71D756A3,0xB729,0x472b,0x9C,0x90,0x12,0xF3,0x93,0xA9,0xBF,0xF8);


MIDL_DEFINE_GUID(IID, IID_IEmulatorVirtualTransportSink,0x6747A265,0x2720,0x4c36,0xB7,0x78,0x51,0xCD,0x2D,0x10,0x52,0x4A);


MIDL_DEFINE_GUID(IID, IID_IEmulatorVirtualTransport,0xF3D1162F,0xB815,0x4ae4,0x8C,0x86,0xDC,0x4A,0x95,0xFB,0x38,0x82);


MIDL_DEFINE_GUID(IID, LIBID_VirtualCE,0x0E61EFB0,0x48B2,0x4329,0x97,0x78,0xF9,0x79,0x76,0xFF,0x6D,0xD6);


MIDL_DEFINE_GUID(CLSID, CLSID_EmulatorVirtualMachineManager,0x98BBBEB9,0x4A0C,0x43c1,0x8D,0x83,0xA9,0x58,0xEA,0xD9,0x97,0x78);


MIDL_DEFINE_GUID(CLSID, CLSID_EmulatorVirtualTransport,0x35A9592F,0xC618,0x4b79,0x80,0x80,0xBC,0x3F,0xCC,0xAC,0x86,0xF6);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for vcecominterfaces.idl:
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

MIDL_DEFINE_GUID(IID, IID_IDMATransportCompletionSink,0xAC6A6347,0xECE0,0x46c1,0xB6,0x68,0x9D,0xF3,0xA1,0x71,0x53,0xC8);


MIDL_DEFINE_GUID(IID, IID_IEmulatorVirtualMachineManager,0x71D756A3,0xB729,0x472b,0x9C,0x90,0x12,0xF3,0x93,0xA9,0xBF,0xF8);


MIDL_DEFINE_GUID(IID, IID_IEmulatorVirtualTransportSink,0x6747A265,0x2720,0x4c36,0xB7,0x78,0x51,0xCD,0x2D,0x10,0x52,0x4A);


MIDL_DEFINE_GUID(IID, IID_IEmulatorVirtualTransport,0xF3D1162F,0xB815,0x4ae4,0x8C,0x86,0xDC,0x4A,0x95,0xFB,0x38,0x82);


MIDL_DEFINE_GUID(IID, LIBID_VirtualCE,0x0E61EFB0,0x48B2,0x4329,0x97,0x78,0xF9,0x79,0x76,0xFF,0x6D,0xD6);


MIDL_DEFINE_GUID(CLSID, CLSID_EmulatorVirtualMachineManager,0x98BBBEB9,0x4A0C,0x43c1,0x8D,0x83,0xA9,0x58,0xEA,0xD9,0x97,0x78);


MIDL_DEFINE_GUID(CLSID, CLSID_EmulatorVirtualTransport,0x35A9592F,0xC618,0x4b79,0x80,0x80,0xBC,0x3F,0xCC,0xAC,0x86,0xF6);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

