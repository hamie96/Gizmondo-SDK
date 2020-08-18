

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#ifndef __cepubsub_h__
#define __cepubsub_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISubscriber_FWD_DEFINED__
#define __ISubscriber_FWD_DEFINED__
typedef interface ISubscriber ISubscriber;
#endif 	/* __ISubscriber_FWD_DEFINED__ */


#ifndef __IPublisher_FWD_DEFINED__
#define __IPublisher_FWD_DEFINED__
typedef interface IPublisher IPublisher;
#endif 	/* __IPublisher_FWD_DEFINED__ */


#ifndef __IPublisherManagement_FWD_DEFINED__
#define __IPublisherManagement_FWD_DEFINED__
typedef interface IPublisherManagement IPublisherManagement;
#endif 	/* __IPublisherManagement_FWD_DEFINED__ */


#ifndef __IPublishSubscribeMgr_FWD_DEFINED__
#define __IPublishSubscribeMgr_FWD_DEFINED__
typedef interface IPublishSubscribeMgr IPublishSubscribeMgr;
#endif 	/* __IPublishSubscribeMgr_FWD_DEFINED__ */


#ifndef __PublishSubscribeMgr_FWD_DEFINED__
#define __PublishSubscribeMgr_FWD_DEFINED__

#ifdef __cplusplus
typedef class PublishSubscribeMgr PublishSubscribeMgr;
#else
typedef struct PublishSubscribeMgr PublishSubscribeMgr;
#endif /* __cplusplus */

#endif 	/* __PublishSubscribeMgr_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __ISubscriber_INTERFACE_DEFINED__
#define __ISubscriber_INTERFACE_DEFINED__

/* interface ISubscriber */
/* [unique][helpstring][uuid][object] */ 

//
// Subscriber notification codes.
// Range 0-1023 reserved.
//
#define SNC_PUBLISHER_EXCEPTION   0
#define SNC_LAST_RESERVED         1023
#define SNC_USER                  1024

EXTERN_C const IID IID_ISubscriber;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("93424894-24C1-4CEE-B78F-B633E0689F46")
    ISubscriber : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ DWORD dwBufSize,
            /* [size_is][in] */ BYTE *pbData) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Notify( 
            DWORD dwEventCode,
            DWORD dwFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISubscriberVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISubscriber * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISubscriber * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISubscriber * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISubscriber * This,
            /* [in] */ DWORD dwBufSize,
            /* [size_is][in] */ BYTE *pbData);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Notify )( 
            ISubscriber * This,
            DWORD dwEventCode,
            DWORD dwFlags);
        
        END_INTERFACE
    } ISubscriberVtbl;

    interface ISubscriber
    {
        CONST_VTBL struct ISubscriberVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISubscriber_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISubscriber_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISubscriber_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISubscriber_Write(This,dwBufSize,pbData)	\
    (This)->lpVtbl -> Write(This,dwBufSize,pbData)

#define ISubscriber_Notify(This,dwEventCode,dwFlags)	\
    (This)->lpVtbl -> Notify(This,dwEventCode,dwFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISubscriber_Write_Proxy( 
    ISubscriber * This,
    /* [in] */ DWORD dwBufSize,
    /* [size_is][in] */ BYTE *pbData);


void __RPC_STUB ISubscriber_Write_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISubscriber_Notify_Proxy( 
    ISubscriber * This,
    DWORD dwEventCode,
    DWORD dwFlags);


void __RPC_STUB ISubscriber_Notify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISubscriber_INTERFACE_DEFINED__ */


#ifndef __IPublisher_INTERFACE_DEFINED__
#define __IPublisher_INTERFACE_DEFINED__

/* interface IPublisher */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPublisher;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ECB85F81-A21F-4A21-B240-74D63CC10C76")
    IPublisher : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Control( 
            DWORD dwControl,
            DWORD dwBufSize,
            /* [size_is][in] */ BYTE *pbData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPublisherVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPublisher * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPublisher * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPublisher * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Control )( 
            IPublisher * This,
            DWORD dwControl,
            DWORD dwBufSize,
            /* [size_is][in] */ BYTE *pbData);
        
        END_INTERFACE
    } IPublisherVtbl;

    interface IPublisher
    {
        CONST_VTBL struct IPublisherVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPublisher_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPublisher_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPublisher_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPublisher_Control(This,dwControl,dwBufSize,pbData)	\
    (This)->lpVtbl -> Control(This,dwControl,dwBufSize,pbData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPublisher_Control_Proxy( 
    IPublisher * This,
    DWORD dwControl,
    DWORD dwBufSize,
    /* [size_is][in] */ BYTE *pbData);


void __RPC_STUB IPublisher_Control_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPublisher_INTERFACE_DEFINED__ */


#ifndef __IPublisherManagement_INTERFACE_DEFINED__
#define __IPublisherManagement_INTERFACE_DEFINED__

/* interface IPublisherManagement */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPublisherManagement;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6C6F881B-2CDA-4769-9C21-720953A053EB")
    IPublisherManagement : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Initialize( 
            ISubscriber *pSubscriber,
            BOOL *bUseBuffering,
            DWORD *pdwBufSize) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StopPublishing( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StartPublishing( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPublisherManagementVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPublisherManagement * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPublisherManagement * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPublisherManagement * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IPublisherManagement * This,
            ISubscriber *pSubscriber,
            BOOL *bUseBuffering,
            DWORD *pdwBufSize);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StopPublishing )( 
            IPublisherManagement * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StartPublishing )( 
            IPublisherManagement * This);
        
        END_INTERFACE
    } IPublisherManagementVtbl;

    interface IPublisherManagement
    {
        CONST_VTBL struct IPublisherManagementVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPublisherManagement_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPublisherManagement_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPublisherManagement_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPublisherManagement_Initialize(This,pSubscriber,bUseBuffering,pdwBufSize)	\
    (This)->lpVtbl -> Initialize(This,pSubscriber,bUseBuffering,pdwBufSize)

#define IPublisherManagement_StopPublishing(This)	\
    (This)->lpVtbl -> StopPublishing(This)

#define IPublisherManagement_StartPublishing(This)	\
    (This)->lpVtbl -> StartPublishing(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPublisherManagement_Initialize_Proxy( 
    IPublisherManagement * This,
    ISubscriber *pSubscriber,
    BOOL *bUseBuffering,
    DWORD *pdwBufSize);


void __RPC_STUB IPublisherManagement_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPublisherManagement_StopPublishing_Proxy( 
    IPublisherManagement * This);


void __RPC_STUB IPublisherManagement_StopPublishing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPublisherManagement_StartPublishing_Proxy( 
    IPublisherManagement * This);


void __RPC_STUB IPublisherManagement_StartPublishing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPublisherManagement_INTERFACE_DEFINED__ */


#ifndef __IPublishSubscribeMgr_INTERFACE_DEFINED__
#define __IPublishSubscribeMgr_INTERFACE_DEFINED__

/* interface IPublishSubscribeMgr */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPublishSubscribeMgr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A84A7F8C-37ED-4132-89A9-CD6160B6F7B4")
    IPublishSubscribeMgr : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Subscribe( 
            GUID PlatformID,
            GUID DeviceID,
            GUID PublisherID,
            ISubscriber *pSubscriber,
            /* [out] */ IPublisher **ppPublisher,
            /* [out] */ GUID *pCookieID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Unsubscribe( 
            GUID cookieID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPublishSubscribeMgrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPublishSubscribeMgr * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPublishSubscribeMgr * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPublishSubscribeMgr * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Subscribe )( 
            IPublishSubscribeMgr * This,
            GUID PlatformID,
            GUID DeviceID,
            GUID PublisherID,
            ISubscriber *pSubscriber,
            /* [out] */ IPublisher **ppPublisher,
            /* [out] */ GUID *pCookieID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Unsubscribe )( 
            IPublishSubscribeMgr * This,
            GUID cookieID);
        
        END_INTERFACE
    } IPublishSubscribeMgrVtbl;

    interface IPublishSubscribeMgr
    {
        CONST_VTBL struct IPublishSubscribeMgrVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPublishSubscribeMgr_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPublishSubscribeMgr_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPublishSubscribeMgr_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPublishSubscribeMgr_Subscribe(This,PlatformID,DeviceID,PublisherID,pSubscriber,ppPublisher,pCookieID)	\
    (This)->lpVtbl -> Subscribe(This,PlatformID,DeviceID,PublisherID,pSubscriber,ppPublisher,pCookieID)

#define IPublishSubscribeMgr_Unsubscribe(This,cookieID)	\
    (This)->lpVtbl -> Unsubscribe(This,cookieID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPublishSubscribeMgr_Subscribe_Proxy( 
    IPublishSubscribeMgr * This,
    GUID PlatformID,
    GUID DeviceID,
    GUID PublisherID,
    ISubscriber *pSubscriber,
    /* [out] */ IPublisher **ppPublisher,
    /* [out] */ GUID *pCookieID);


void __RPC_STUB IPublishSubscribeMgr_Subscribe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPublishSubscribeMgr_Unsubscribe_Proxy( 
    IPublishSubscribeMgr * This,
    GUID cookieID);


void __RPC_STUB IPublishSubscribeMgr_Unsubscribe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPublishSubscribeMgr_INTERFACE_DEFINED__ */



#ifndef __PUBSUBLib_LIBRARY_DEFINED__
#define __PUBSUBLib_LIBRARY_DEFINED__

/* library PUBSUBLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_PUBSUBLib;

EXTERN_C const CLSID CLSID_PublishSubscribeMgr;

#ifdef __cplusplus

class DECLSPEC_UUID("CB7EE2BC-D04A-4408-834E-D5FA9D5183DC")
PublishSubscribeMgr;
#endif
#endif /* __PUBSUBLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


