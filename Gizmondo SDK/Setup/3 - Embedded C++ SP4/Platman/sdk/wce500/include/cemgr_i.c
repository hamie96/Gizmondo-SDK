

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for cemgr.idl:
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

MIDL_DEFINE_GUID(IID, IID_IPlatformManager,0xF384D882,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPlatformManager2,0xD08B18FB,0x0471,0x4a4d,0x88,0xF3,0x9F,0x11,0x87,0xA0,0x58,0xAA);


MIDL_DEFINE_GUID(IID, IID_IPlatformManager3,0x91DAF806,0x2EEB,0x44a5,0xB7,0xD1,0xB1,0xEF,0x3D,0xB9,0xFC,0x88);


MIDL_DEFINE_GUID(IID, IID_IEnumServiceCategory,0x4E4527E8,0xBCE4,0x4675,0xB5,0x64,0xE7,0xDE,0x0E,0xA6,0xD1,0x63);


MIDL_DEFINE_GUID(IID, IID_IServiceCategory,0x73EA2A51,0x09D5,0x416c,0x99,0xFF,0xA6,0x93,0x5A,0x02,0x67,0x2B);


MIDL_DEFINE_GUID(IID, IID_IEnumServiceInfo,0x53CCA653,0x3F54,0x434c,0x8D,0xB0,0x3D,0x8A,0x61,0x07,0x45,0xE4);


MIDL_DEFINE_GUID(IID, IID_IServiceInfo,0x320494E2,0x0D2A,0x4594,0xA8,0xFC,0x73,0x91,0x3F,0xAE,0x85,0xC8);


MIDL_DEFINE_GUID(IID, IID_IEnumBootableDevice,0xB7D6E6F7,0x8D72,0x45f6,0xAE,0x37,0xD7,0x72,0x49,0x89,0xE5,0xCB);


MIDL_DEFINE_GUID(IID, IID_IBootableDevice,0x6014FEE5,0xB7BF,0x4c3c,0xA2,0xB8,0xA9,0xD0,0xF8,0xB6,0x41,0x10);


MIDL_DEFINE_GUID(IID, IID_IService,0xE408B5F2,0x348F,0x4263,0xB5,0x51,0x64,0x37,0x63,0x5C,0x46,0xE8);


MIDL_DEFINE_GUID(IID, IID_IPMServiceNuke,0xBDAF11A3,0x78BD,0x4B32,0x91,0xE8,0x89,0x11,0xB7,0xA7,0xFA,0xAF);


MIDL_DEFINE_GUID(IID, IID_IServiceConfig,0x768C9904,0x36E1,0x423b,0x91,0xB4,0x43,0x3D,0x70,0x9B,0x6A,0x19);


MIDL_DEFINE_GUID(IID, IID_IEnumPlatformCE,0xF384D885,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPlatformCE,0xF384D888,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IRemoteDevice,0xF384D88B,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IRemoteDevice2,0xC4C0EE08,0xFC65,0x40f0,0x86,0x3E,0xB3,0xC8,0x91,0xA7,0x50,0xC2);


MIDL_DEFINE_GUID(IID, IID_IEnumDevice,0xF384D88E,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IEnumProperty,0xF384D891,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IProperty,0xF384D894,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IEnumPropInfo,0xF384D897,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IConnection,0xDA438BAA,0xFA87,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IConnection2,0x073E4A43,0x45BC,0x46ef,0xB1,0x14,0xF4,0x2B,0xA5,0x1C,0x63,0x66);


MIDL_DEFINE_GUID(IID, IID_IConnectionStream,0xDA438BB0,0xFA87,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IConnectionStream2,0xEF075F33,0x141A,0x4D6A,0x9D,0x88,0x33,0x36,0x0E,0xBF,0xCB,0xA5);


MIDL_DEFINE_GUID(IID, IID_ICallBack,0xDA438BB3,0xFA87,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPlatManCallback2,0xEC0A1BC0,0xA1F4,0x11d3,0x98,0xFC,0x00,0x10,0x5A,0xA9,0x06,0x82);


MIDL_DEFINE_GUID(IID, IID_IPlatformManagerConfig,0xDA438BC2,0xFA87,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPlatformManagerConfig2,0x30A76E8E,0x8B0D,0x4E3b,0x8E,0xC7,0x9B,0x57,0x86,0x2E,0xFB,0xF1);


MIDL_DEFINE_GUID(IID, IID_IPlatformManagerConfig3,0x817E8295,0xC9EE,0x48ec,0xB1,0xAC,0x37,0xA8,0x58,0xB7,0x36,0x09);


MIDL_DEFINE_GUID(IID, IID_IBootableDeviceConfig,0x016ED627,0x9104,0x4fb6,0x8F,0x82,0xE5,0x22,0x75,0x5C,0xC5,0xAA);


MIDL_DEFINE_GUID(IID, IID_IServiceCategoryConfig,0xC335A883,0xE95A,0x4ea4,0x9D,0xDA,0xFB,0xE8,0x3C,0x55,0xD5,0x19);


MIDL_DEFINE_GUID(IID, IID_IServiceInfoConfig,0x324AA352,0xF2F5,0x4c23,0xAD,0x31,0x10,0x88,0xD7,0xD8,0xEA,0x97);


MIDL_DEFINE_GUID(IID, IID_IPlatformConfig,0xDA438BC7,0xFA87,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPlatformConfig2,0xFA59C739,0xCFD3,0x4421,0xB7,0xF0,0xAA,0x22,0xD4,0x8D,0x86,0x4C);


MIDL_DEFINE_GUID(IID, IID_IRemoteDeviceConfig,0xDA438BCA,0xFA87,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IEnumComponent,0xDA438BCD,0xFA87,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPackage,0x2A4F783A,0x014E,0x11D2,0xBB,0xA0,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPackage2,0x64D0B782,0x47B7,0x4c30,0x8B,0x5F,0xDD,0xB7,0xB2,0x48,0xA9,0x1D);


MIDL_DEFINE_GUID(IID, IID_IEnumPackageFiles,0x2A4F783D,0x014E,0x11D2,0xBB,0xA0,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IEnumPackageFiles2,0xBA5F16F6,0xF3A3,0x44E4,0x88,0xF4,0x10,0xE2,0xB1,0xE9,0x21,0xF4);


MIDL_DEFINE_GUID(IID, IID_IEnumCPU,0x66B6C2DD,0x2590,0x11D2,0xBB,0xA9,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPMPlatformManager,0xEA720E9B,0x5C6D,0x4FBF,0x93,0x52,0xA0,0x84,0x86,0x65,0x96,0xA7);


MIDL_DEFINE_GUID(IID, IID_IPMPlatform,0x5BA32507,0x0015,0x40A2,0xA0,0xFE,0xAA,0x81,0xCB,0x26,0x5F,0xE1);


MIDL_DEFINE_GUID(IID, IID_IPMRemoteDevice,0xBCDAA3C8,0xE342,0x4DC0,0xA1,0x27,0x19,0x27,0x80,0xE4,0x24,0x4B);


MIDL_DEFINE_GUID(IID, IID_IPMProperty,0xD9956420,0xDF23,0x46E0,0x88,0xE1,0x4E,0x0D,0x75,0x9E,0x97,0xDB);


MIDL_DEFINE_GUID(IID, IID_IPMBootableDevice,0x6C8863F4,0x54B3,0x417E,0x83,0xBF,0x2D,0x63,0xBF,0xDD,0xE4,0x37);


MIDL_DEFINE_GUID(IID, IID_IPMPackage,0xAF7FD18F,0xEC3E,0x4760,0xB1,0xA7,0xEF,0x9E,0xC0,0xB8,0xD4,0xD1);


MIDL_DEFINE_GUID(IID, IID_IPMService,0xCBC7337C,0x2A7C,0x4062,0x83,0xA2,0x72,0xC3,0xE3,0x0C,0x42,0xBF);


MIDL_DEFINE_GUID(IID, IID_IPMServiceInfo,0x184E566E,0x2134,0x4EA6,0xB2,0x98,0xF1,0x77,0xDA,0xC4,0x89,0xDE);


MIDL_DEFINE_GUID(IID, IID_IPMServiceCategory,0x2E8C4F4D,0xBEFE,0x4FC0,0x81,0xD5,0xE7,0x31,0x14,0x17,0x84,0x3C);


MIDL_DEFINE_GUID(IID, IID_IPMConnectionStream,0xC41E4F72,0x6B73,0x4556,0x98,0xEA,0xD8,0x65,0x70,0x74,0x5D,0xDB);


MIDL_DEFINE_GUID(IID, IID_IPMConnection,0xA887B5D6,0xA18E,0x41FB,0xBF,0xC5,0xB6,0xAB,0xB4,0x19,0xA3,0xD3);


MIDL_DEFINE_GUID(IID, IID_IPMCPU,0xD32ACC9F,0xD772,0x41AA,0x9D,0x5A,0xAC,0x11,0xAD,0x51,0x54,0xB9);


MIDL_DEFINE_GUID(IID, IID_IPMOS,0x57E91F66,0xD7C4,0x41BD,0xA4,0xA9,0xC2,0x80,0x60,0xD0,0x0C,0x57);


MIDL_DEFINE_GUID(IID, IID_IPMStartupServerInfo,0xA8FA6E12,0x2D8C,0x46B7,0xA2,0x5D,0x64,0xC0,0x4F,0xA6,0x92,0x14);


MIDL_DEFINE_GUID(IID, IID_IPMTransportInfo,0x0761A737,0x372D,0x4020,0x80,0x0A,0xB5,0x2C,0xCD,0x06,0xD2,0x5D);


MIDL_DEFINE_GUID(IID, IID_IPMPropInfo,0xF7B2D7E0,0x44B5,0x4715,0xA1,0x56,0xA5,0xB3,0xB4,0x2D,0x7D,0x5A);


MIDL_DEFINE_GUID(IID, IID_IPMPackageFile,0x93BD6B7A,0x4340,0x45FF,0xB0,0x62,0xA4,0x18,0x7B,0xBB,0x8D,0x0B);


MIDL_DEFINE_GUID(IID, IID_IEnumVariant,0xAF8278EC,0xA3C4,0x44B3,0x85,0xB3,0x6B,0x8C,0xF9,0xBC,0x72,0x37);


MIDL_DEFINE_GUID(IID, IID_IClientInfo,0xB293E1A7,0xB804,0x498e,0x85,0x97,0xB9,0x10,0x5C,0x58,0xC3,0x71);


MIDL_DEFINE_GUID(IID, LIBID_CEMGRLib,0x2C99AFCB,0xF99D,0x11D1,0xBB,0x9D,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(CLSID, CLSID_PlatformManager,0xF384D883,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for cemgr.idl:
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

MIDL_DEFINE_GUID(IID, IID_IPlatformManager,0xF384D882,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPlatformManager2,0xD08B18FB,0x0471,0x4a4d,0x88,0xF3,0x9F,0x11,0x87,0xA0,0x58,0xAA);


MIDL_DEFINE_GUID(IID, IID_IPlatformManager3,0x91DAF806,0x2EEB,0x44a5,0xB7,0xD1,0xB1,0xEF,0x3D,0xB9,0xFC,0x88);


MIDL_DEFINE_GUID(IID, IID_IEnumServiceCategory,0x4E4527E8,0xBCE4,0x4675,0xB5,0x64,0xE7,0xDE,0x0E,0xA6,0xD1,0x63);


MIDL_DEFINE_GUID(IID, IID_IServiceCategory,0x73EA2A51,0x09D5,0x416c,0x99,0xFF,0xA6,0x93,0x5A,0x02,0x67,0x2B);


MIDL_DEFINE_GUID(IID, IID_IEnumServiceInfo,0x53CCA653,0x3F54,0x434c,0x8D,0xB0,0x3D,0x8A,0x61,0x07,0x45,0xE4);


MIDL_DEFINE_GUID(IID, IID_IServiceInfo,0x320494E2,0x0D2A,0x4594,0xA8,0xFC,0x73,0x91,0x3F,0xAE,0x85,0xC8);


MIDL_DEFINE_GUID(IID, IID_IEnumBootableDevice,0xB7D6E6F7,0x8D72,0x45f6,0xAE,0x37,0xD7,0x72,0x49,0x89,0xE5,0xCB);


MIDL_DEFINE_GUID(IID, IID_IBootableDevice,0x6014FEE5,0xB7BF,0x4c3c,0xA2,0xB8,0xA9,0xD0,0xF8,0xB6,0x41,0x10);


MIDL_DEFINE_GUID(IID, IID_IService,0xE408B5F2,0x348F,0x4263,0xB5,0x51,0x64,0x37,0x63,0x5C,0x46,0xE8);


MIDL_DEFINE_GUID(IID, IID_IPMServiceNuke,0xBDAF11A3,0x78BD,0x4B32,0x91,0xE8,0x89,0x11,0xB7,0xA7,0xFA,0xAF);


MIDL_DEFINE_GUID(IID, IID_IServiceConfig,0x768C9904,0x36E1,0x423b,0x91,0xB4,0x43,0x3D,0x70,0x9B,0x6A,0x19);


MIDL_DEFINE_GUID(IID, IID_IEnumPlatformCE,0xF384D885,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPlatformCE,0xF384D888,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IRemoteDevice,0xF384D88B,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IRemoteDevice2,0xC4C0EE08,0xFC65,0x40f0,0x86,0x3E,0xB3,0xC8,0x91,0xA7,0x50,0xC2);


MIDL_DEFINE_GUID(IID, IID_IEnumDevice,0xF384D88E,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IEnumProperty,0xF384D891,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IProperty,0xF384D894,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IEnumPropInfo,0xF384D897,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IConnection,0xDA438BAA,0xFA87,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IConnection2,0x073E4A43,0x45BC,0x46ef,0xB1,0x14,0xF4,0x2B,0xA5,0x1C,0x63,0x66);


MIDL_DEFINE_GUID(IID, IID_IConnectionStream,0xDA438BB0,0xFA87,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IConnectionStream2,0xEF075F33,0x141A,0x4D6A,0x9D,0x88,0x33,0x36,0x0E,0xBF,0xCB,0xA5);


MIDL_DEFINE_GUID(IID, IID_ICallBack,0xDA438BB3,0xFA87,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPlatManCallback2,0xEC0A1BC0,0xA1F4,0x11d3,0x98,0xFC,0x00,0x10,0x5A,0xA9,0x06,0x82);


MIDL_DEFINE_GUID(IID, IID_IPlatformManagerConfig,0xDA438BC2,0xFA87,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPlatformManagerConfig2,0x30A76E8E,0x8B0D,0x4E3b,0x8E,0xC7,0x9B,0x57,0x86,0x2E,0xFB,0xF1);


MIDL_DEFINE_GUID(IID, IID_IPlatformManagerConfig3,0x817E8295,0xC9EE,0x48ec,0xB1,0xAC,0x37,0xA8,0x58,0xB7,0x36,0x09);


MIDL_DEFINE_GUID(IID, IID_IBootableDeviceConfig,0x016ED627,0x9104,0x4fb6,0x8F,0x82,0xE5,0x22,0x75,0x5C,0xC5,0xAA);


MIDL_DEFINE_GUID(IID, IID_IServiceCategoryConfig,0xC335A883,0xE95A,0x4ea4,0x9D,0xDA,0xFB,0xE8,0x3C,0x55,0xD5,0x19);


MIDL_DEFINE_GUID(IID, IID_IServiceInfoConfig,0x324AA352,0xF2F5,0x4c23,0xAD,0x31,0x10,0x88,0xD7,0xD8,0xEA,0x97);


MIDL_DEFINE_GUID(IID, IID_IPlatformConfig,0xDA438BC7,0xFA87,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPlatformConfig2,0xFA59C739,0xCFD3,0x4421,0xB7,0xF0,0xAA,0x22,0xD4,0x8D,0x86,0x4C);


MIDL_DEFINE_GUID(IID, IID_IRemoteDeviceConfig,0xDA438BCA,0xFA87,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IEnumComponent,0xDA438BCD,0xFA87,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPackage,0x2A4F783A,0x014E,0x11D2,0xBB,0xA0,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPackage2,0x64D0B782,0x47B7,0x4c30,0x8B,0x5F,0xDD,0xB7,0xB2,0x48,0xA9,0x1D);


MIDL_DEFINE_GUID(IID, IID_IEnumPackageFiles,0x2A4F783D,0x014E,0x11D2,0xBB,0xA0,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IEnumPackageFiles2,0xBA5F16F6,0xF3A3,0x44E4,0x88,0xF4,0x10,0xE2,0xB1,0xE9,0x21,0xF4);


MIDL_DEFINE_GUID(IID, IID_IEnumCPU,0x66B6C2DD,0x2590,0x11D2,0xBB,0xA9,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(IID, IID_IPMPlatformManager,0xEA720E9B,0x5C6D,0x4FBF,0x93,0x52,0xA0,0x84,0x86,0x65,0x96,0xA7);


MIDL_DEFINE_GUID(IID, IID_IPMPlatform,0x5BA32507,0x0015,0x40A2,0xA0,0xFE,0xAA,0x81,0xCB,0x26,0x5F,0xE1);


MIDL_DEFINE_GUID(IID, IID_IPMRemoteDevice,0xBCDAA3C8,0xE342,0x4DC0,0xA1,0x27,0x19,0x27,0x80,0xE4,0x24,0x4B);


MIDL_DEFINE_GUID(IID, IID_IPMProperty,0xD9956420,0xDF23,0x46E0,0x88,0xE1,0x4E,0x0D,0x75,0x9E,0x97,0xDB);


MIDL_DEFINE_GUID(IID, IID_IPMBootableDevice,0x6C8863F4,0x54B3,0x417E,0x83,0xBF,0x2D,0x63,0xBF,0xDD,0xE4,0x37);


MIDL_DEFINE_GUID(IID, IID_IPMPackage,0xAF7FD18F,0xEC3E,0x4760,0xB1,0xA7,0xEF,0x9E,0xC0,0xB8,0xD4,0xD1);


MIDL_DEFINE_GUID(IID, IID_IPMService,0xCBC7337C,0x2A7C,0x4062,0x83,0xA2,0x72,0xC3,0xE3,0x0C,0x42,0xBF);


MIDL_DEFINE_GUID(IID, IID_IPMServiceInfo,0x184E566E,0x2134,0x4EA6,0xB2,0x98,0xF1,0x77,0xDA,0xC4,0x89,0xDE);


MIDL_DEFINE_GUID(IID, IID_IPMServiceCategory,0x2E8C4F4D,0xBEFE,0x4FC0,0x81,0xD5,0xE7,0x31,0x14,0x17,0x84,0x3C);


MIDL_DEFINE_GUID(IID, IID_IPMConnectionStream,0xC41E4F72,0x6B73,0x4556,0x98,0xEA,0xD8,0x65,0x70,0x74,0x5D,0xDB);


MIDL_DEFINE_GUID(IID, IID_IPMConnection,0xA887B5D6,0xA18E,0x41FB,0xBF,0xC5,0xB6,0xAB,0xB4,0x19,0xA3,0xD3);


MIDL_DEFINE_GUID(IID, IID_IPMCPU,0xD32ACC9F,0xD772,0x41AA,0x9D,0x5A,0xAC,0x11,0xAD,0x51,0x54,0xB9);


MIDL_DEFINE_GUID(IID, IID_IPMOS,0x57E91F66,0xD7C4,0x41BD,0xA4,0xA9,0xC2,0x80,0x60,0xD0,0x0C,0x57);


MIDL_DEFINE_GUID(IID, IID_IPMStartupServerInfo,0xA8FA6E12,0x2D8C,0x46B7,0xA2,0x5D,0x64,0xC0,0x4F,0xA6,0x92,0x14);


MIDL_DEFINE_GUID(IID, IID_IPMTransportInfo,0x0761A737,0x372D,0x4020,0x80,0x0A,0xB5,0x2C,0xCD,0x06,0xD2,0x5D);


MIDL_DEFINE_GUID(IID, IID_IPMPropInfo,0xF7B2D7E0,0x44B5,0x4715,0xA1,0x56,0xA5,0xB3,0xB4,0x2D,0x7D,0x5A);


MIDL_DEFINE_GUID(IID, IID_IPMPackageFile,0x93BD6B7A,0x4340,0x45FF,0xB0,0x62,0xA4,0x18,0x7B,0xBB,0x8D,0x0B);


MIDL_DEFINE_GUID(IID, IID_IEnumVariant,0xAF8278EC,0xA3C4,0x44B3,0x85,0xB3,0x6B,0x8C,0xF9,0xBC,0x72,0x37);


MIDL_DEFINE_GUID(IID, IID_IClientInfo,0xB293E1A7,0xB804,0x498e,0x85,0x97,0xB9,0x10,0x5C,0x58,0xC3,0x71);


MIDL_DEFINE_GUID(IID, LIBID_CEMGRLib,0x2C99AFCB,0xF99D,0x11D1,0xBB,0x9D,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);


MIDL_DEFINE_GUID(CLSID, CLSID_PlatformManager,0xF384D883,0xF9AA,0x11D1,0xBB,0x9E,0x00,0xA0,0xC9,0xC9,0xCC,0xEE);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

