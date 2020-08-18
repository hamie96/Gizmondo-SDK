

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for kitlcom.idl:
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

MIDL_DEFINE_GUID(IID, IID_IKITLStream,0x9B827231,0x5AC4,0x4C16,0xA3,0xD9,0x23,0xCF,0xC9,0x85,0xB7,0x16);


MIDL_DEFINE_GUID(IID, IID_IKITLStreamEx,0x6E8A5211,0x6A5B,0x4142,0x83,0xD8,0xF1,0x5E,0x47,0xC4,0xF5,0x03);


MIDL_DEFINE_GUID(IID, IID__IPPSHCommandCB,0x4F4B6BE3,0x1BAE,0x11d5,0xA6,0x62,0x40,0x80,0x4F,0xC1,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID__IPPSHDataSink,0xCF76FB4F,0x149C,0x45b5,0x9F,0xD7,0x96,0x93,0x59,0xA3,0x05,0xD2);


MIDL_DEFINE_GUID(IID, IID_IPPSHStream,0xCF061356,0x7968,0x44D0,0xB6,0x06,0xD1,0x74,0x6E,0x87,0x3B,0xE4);


MIDL_DEFINE_GUID(IID, IID__IDBGMSGDataSink,0x4130D2CA,0x8310,0x41a2,0xBC,0x55,0x24,0xF2,0x64,0xCA,0x79,0xBF);


MIDL_DEFINE_GUID(IID, IID_IDBGMSGStream,0x3556165F,0xCDF4,0x4869,0x91,0xCB,0x4E,0xAA,0x80,0xDB,0x68,0x97);


MIDL_DEFINE_GUID(IID, IID_IKITL,0xBC3DAD2D,0xF4F3,0x4C32,0xA5,0x27,0xC3,0x94,0x42,0xE2,0x01,0x00);


MIDL_DEFINE_GUID(IID, IID_IKitlInit,0x4766C31D,0x8C78,0x4636,0x92,0x89,0xAE,0xB0,0xC1,0x13,0x48,0x25);


MIDL_DEFINE_GUID(IID, LIBID_KITLCOMLib,0x53E652A7,0xA86A,0x46A6,0x99,0x81,0xC3,0x08,0x5A,0x5E,0x0A,0x7C);


MIDL_DEFINE_GUID(CLSID, CLSID_KitlInit,0xCC6578D9,0xF20D,0x495D,0x8B,0xED,0x9C,0x56,0x7C,0xBC,0xCC,0xDA);


MIDL_DEFINE_GUID(CLSID, CLSID_KITLService,0x702FFE21,0x037A,0x4C15,0xBD,0x18,0x6B,0x39,0xDD,0x74,0x61,0x1A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for kitlcom.idl:
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

MIDL_DEFINE_GUID(IID, IID_IKITLStream,0x9B827231,0x5AC4,0x4C16,0xA3,0xD9,0x23,0xCF,0xC9,0x85,0xB7,0x16);


MIDL_DEFINE_GUID(IID, IID_IKITLStreamEx,0x6E8A5211,0x6A5B,0x4142,0x83,0xD8,0xF1,0x5E,0x47,0xC4,0xF5,0x03);


MIDL_DEFINE_GUID(IID, IID__IPPSHCommandCB,0x4F4B6BE3,0x1BAE,0x11d5,0xA6,0x62,0x40,0x80,0x4F,0xC1,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID__IPPSHDataSink,0xCF76FB4F,0x149C,0x45b5,0x9F,0xD7,0x96,0x93,0x59,0xA3,0x05,0xD2);


MIDL_DEFINE_GUID(IID, IID_IPPSHStream,0xCF061356,0x7968,0x44D0,0xB6,0x06,0xD1,0x74,0x6E,0x87,0x3B,0xE4);


MIDL_DEFINE_GUID(IID, IID__IDBGMSGDataSink,0x4130D2CA,0x8310,0x41a2,0xBC,0x55,0x24,0xF2,0x64,0xCA,0x79,0xBF);


MIDL_DEFINE_GUID(IID, IID_IDBGMSGStream,0x3556165F,0xCDF4,0x4869,0x91,0xCB,0x4E,0xAA,0x80,0xDB,0x68,0x97);


MIDL_DEFINE_GUID(IID, IID_IKITL,0xBC3DAD2D,0xF4F3,0x4C32,0xA5,0x27,0xC3,0x94,0x42,0xE2,0x01,0x00);


MIDL_DEFINE_GUID(IID, IID_IKitlInit,0x4766C31D,0x8C78,0x4636,0x92,0x89,0xAE,0xB0,0xC1,0x13,0x48,0x25);


MIDL_DEFINE_GUID(IID, LIBID_KITLCOMLib,0x53E652A7,0xA86A,0x46A6,0x99,0x81,0xC3,0x08,0x5A,0x5E,0x0A,0x7C);


MIDL_DEFINE_GUID(CLSID, CLSID_KitlInit,0xCC6578D9,0xF20D,0x495D,0x8B,0xED,0x9C,0x56,0x7C,0xBC,0xCC,0xDA);


MIDL_DEFINE_GUID(CLSID, CLSID_KITLService,0x702FFE21,0x037A,0x4C15,0xBD,0x18,0x6B,0x39,0xDD,0x74,0x61,0x1A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

