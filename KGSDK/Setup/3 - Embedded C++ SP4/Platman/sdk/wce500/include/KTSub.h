

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for ktsub.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ktsub_h__
#define __ktsub_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IKTSubscriber_FWD_DEFINED__
#define __IKTSubscriber_FWD_DEFINED__
typedef interface IKTSubscriber IKTSubscriber;
#endif 	/* __IKTSubscriber_FWD_DEFINED__ */


#ifndef __KTSubscriber_FWD_DEFINED__
#define __KTSubscriber_FWD_DEFINED__

#ifdef __cplusplus
typedef class KTSubscriber KTSubscriber;
#else
typedef struct KTSubscriber KTSubscriber;
#endif /* __cplusplus */

#endif 	/* __KTSubscriber_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "CePubSub.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IKTSubscriber_INTERFACE_DEFINED__
#define __IKTSubscriber_INTERFACE_DEFINED__

/* interface IKTSubscriber */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IKTSubscriber;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("349EDC0E-6FB3-4B83-A232-AF93E34FF9F8")
    IKTSubscriber : public ISubscriber
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Initialize( 
            GUID guidPlatform,
            GUID guidDevice) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ShutDown( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetZones( 
            /* [in] */ DWORD dwZoneUser,
            /* [in] */ DWORD dwZoneCE,
            /* [in] */ DWORD dwZoneProcess) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadEvent( 
            /* [length_is][size_is][out][in] */ BYTE *pbCEEvent,
            /* [out][in] */ DWORD *pdwLength) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadMultipleEvents( 
            /* [length_is][size_is][out][in] */ BYTE *pbCEEvents,
            /* [out][in] */ DWORD *pdwLength) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbortRead( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ResetAbortEvent( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IKTSubscriberVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IKTSubscriber * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IKTSubscriber * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IKTSubscriber * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            IKTSubscriber * This,
            /* [in] */ DWORD dwBufSize,
            /* [size_is][in] */ BYTE *pbData);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Notify )( 
            IKTSubscriber * This,
            DWORD dwEventCode,
            DWORD dwFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IKTSubscriber * This,
            GUID guidPlatform,
            GUID guidDevice);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ShutDown )( 
            IKTSubscriber * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetZones )( 
            IKTSubscriber * This,
            /* [in] */ DWORD dwZoneUser,
            /* [in] */ DWORD dwZoneCE,
            /* [in] */ DWORD dwZoneProcess);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReadEvent )( 
            IKTSubscriber * This,
            /* [length_is][size_is][out][in] */ BYTE *pbCEEvent,
            /* [out][in] */ DWORD *pdwLength);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReadMultipleEvents )( 
            IKTSubscriber * This,
            /* [length_is][size_is][out][in] */ BYTE *pbCEEvents,
            /* [out][in] */ DWORD *pdwLength);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbortRead )( 
            IKTSubscriber * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ResetAbortEvent )( 
            IKTSubscriber * This);
        
        END_INTERFACE
    } IKTSubscriberVtbl;

    interface IKTSubscriber
    {
        CONST_VTBL struct IKTSubscriberVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IKTSubscriber_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IKTSubscriber_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IKTSubscriber_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IKTSubscriber_Write(This,dwBufSize,pbData)	\
    (This)->lpVtbl -> Write(This,dwBufSize,pbData)

#define IKTSubscriber_Notify(This,dwEventCode,dwFlags)	\
    (This)->lpVtbl -> Notify(This,dwEventCode,dwFlags)


#define IKTSubscriber_Initialize(This,guidPlatform,guidDevice)	\
    (This)->lpVtbl -> Initialize(This,guidPlatform,guidDevice)

#define IKTSubscriber_ShutDown(This)	\
    (This)->lpVtbl -> ShutDown(This)

#define IKTSubscriber_SetZones(This,dwZoneUser,dwZoneCE,dwZoneProcess)	\
    (This)->lpVtbl -> SetZones(This,dwZoneUser,dwZoneCE,dwZoneProcess)

#define IKTSubscriber_ReadEvent(This,pbCEEvent,pdwLength)	\
    (This)->lpVtbl -> ReadEvent(This,pbCEEvent,pdwLength)

#define IKTSubscriber_ReadMultipleEvents(This,pbCEEvents,pdwLength)	\
    (This)->lpVtbl -> ReadMultipleEvents(This,pbCEEvents,pdwLength)

#define IKTSubscriber_AbortRead(This)	\
    (This)->lpVtbl -> AbortRead(This)

#define IKTSubscriber_ResetAbortEvent(This)	\
    (This)->lpVtbl -> ResetAbortEvent(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IKTSubscriber_Initialize_Proxy( 
    IKTSubscriber * This,
    GUID guidPlatform,
    GUID guidDevice);


void __RPC_STUB IKTSubscriber_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IKTSubscriber_ShutDown_Proxy( 
    IKTSubscriber * This);


void __RPC_STUB IKTSubscriber_ShutDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IKTSubscriber_SetZones_Proxy( 
    IKTSubscriber * This,
    /* [in] */ DWORD dwZoneUser,
    /* [in] */ DWORD dwZoneCE,
    /* [in] */ DWORD dwZoneProcess);


void __RPC_STUB IKTSubscriber_SetZones_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IKTSubscriber_ReadEvent_Proxy( 
    IKTSubscriber * This,
    /* [length_is][size_is][out][in] */ BYTE *pbCEEvent,
    /* [out][in] */ DWORD *pdwLength);


void __RPC_STUB IKTSubscriber_ReadEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IKTSubscriber_ReadMultipleEvents_Proxy( 
    IKTSubscriber * This,
    /* [length_is][size_is][out][in] */ BYTE *pbCEEvents,
    /* [out][in] */ DWORD *pdwLength);


void __RPC_STUB IKTSubscriber_ReadMultipleEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IKTSubscriber_AbortRead_Proxy( 
    IKTSubscriber * This);


void __RPC_STUB IKTSubscriber_AbortRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IKTSubscriber_ResetAbortEvent_Proxy( 
    IKTSubscriber * This);


void __RPC_STUB IKTSubscriber_ResetAbortEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IKTSubscriber_INTERFACE_DEFINED__ */



#ifndef __KTSUBLib_LIBRARY_DEFINED__
#define __KTSUBLib_LIBRARY_DEFINED__

/* library KTSUBLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_KTSUBLib;

EXTERN_C const CLSID CLSID_KTSubscriber;

#ifdef __cplusplus

class DECLSPEC_UUID("3C2A061A-7F04-4401-A75C-68FEB041392E")
KTSubscriber;
#endif
#endif /* __KTSUBLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


