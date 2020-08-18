

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for cepubsub.idl:
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

MIDL_DEFINE_GUID(IID, IID_ISubscriber,0x93424894,0x24C1,0x4CEE,0xB7,0x8F,0xB6,0x33,0xE0,0x68,0x9F,0x46);


MIDL_DEFINE_GUID(IID, IID_IPublisher,0xECB85F81,0xA21F,0x4A21,0xB2,0x40,0x74,0xD6,0x3C,0xC1,0x0C,0x76);


MIDL_DEFINE_GUID(IID, IID_IPublisherManagement,0x6C6F881B,0x2CDA,0x4769,0x9C,0x21,0x72,0x09,0x53,0xA0,0x53,0xEB);


MIDL_DEFINE_GUID(IID, IID_IPublishSubscribeMgr,0xA84A7F8C,0x37ED,0x4132,0x89,0xA9,0xCD,0x61,0x60,0xB6,0xF7,0xB4);


MIDL_DEFINE_GUID(IID, LIBID_PUBSUBLib,0xA0CB5266,0x384E,0x4730,0xBA,0xA1,0x25,0xF4,0x02,0x78,0x88,0x7E);


MIDL_DEFINE_GUID(CLSID, CLSID_PublishSubscribeMgr,0xCB7EE2BC,0xD04A,0x4408,0x83,0x4E,0xD5,0xFA,0x9D,0x51,0x83,0xDC);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for cepubsub.idl:
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

MIDL_DEFINE_GUID(IID, IID_ISubscriber,0x93424894,0x24C1,0x4CEE,0xB7,0x8F,0xB6,0x33,0xE0,0x68,0x9F,0x46);


MIDL_DEFINE_GUID(IID, IID_IPublisher,0xECB85F81,0xA21F,0x4A21,0xB2,0x40,0x74,0xD6,0x3C,0xC1,0x0C,0x76);


MIDL_DEFINE_GUID(IID, IID_IPublisherManagement,0x6C6F881B,0x2CDA,0x4769,0x9C,0x21,0x72,0x09,0x53,0xA0,0x53,0xEB);


MIDL_DEFINE_GUID(IID, IID_IPublishSubscribeMgr,0xA84A7F8C,0x37ED,0x4132,0x89,0xA9,0xCD,0x61,0x60,0xB6,0xF7,0xB4);


MIDL_DEFINE_GUID(IID, LIBID_PUBSUBLib,0xA0CB5266,0x384E,0x4730,0xBA,0xA1,0x25,0xF4,0x02,0x78,0x88,0x7E);


MIDL_DEFINE_GUID(CLSID, CLSID_PublishSubscribeMgr,0xCB7EE2BC,0xD04A,0x4408,0x83,0x4E,0xD5,0xFA,0x9D,0x51,0x83,0xDC);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

