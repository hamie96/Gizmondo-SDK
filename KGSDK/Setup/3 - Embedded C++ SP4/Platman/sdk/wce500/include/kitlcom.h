

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#ifndef __kitlcom_h__
#define __kitlcom_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IKITLStream_FWD_DEFINED__
#define __IKITLStream_FWD_DEFINED__
typedef interface IKITLStream IKITLStream;
#endif 	/* __IKITLStream_FWD_DEFINED__ */


#ifndef __IKITLStreamEx_FWD_DEFINED__
#define __IKITLStreamEx_FWD_DEFINED__
typedef interface IKITLStreamEx IKITLStreamEx;
#endif 	/* __IKITLStreamEx_FWD_DEFINED__ */


#ifndef ___IPPSHCommandCB_FWD_DEFINED__
#define ___IPPSHCommandCB_FWD_DEFINED__
typedef interface _IPPSHCommandCB _IPPSHCommandCB;
#endif 	/* ___IPPSHCommandCB_FWD_DEFINED__ */


#ifndef ___IPPSHDataSink_FWD_DEFINED__
#define ___IPPSHDataSink_FWD_DEFINED__
typedef interface _IPPSHDataSink _IPPSHDataSink;
#endif 	/* ___IPPSHDataSink_FWD_DEFINED__ */


#ifndef __IPPSHStream_FWD_DEFINED__
#define __IPPSHStream_FWD_DEFINED__
typedef interface IPPSHStream IPPSHStream;
#endif 	/* __IPPSHStream_FWD_DEFINED__ */


#ifndef ___IDBGMSGDataSink_FWD_DEFINED__
#define ___IDBGMSGDataSink_FWD_DEFINED__
typedef interface _IDBGMSGDataSink _IDBGMSGDataSink;
#endif 	/* ___IDBGMSGDataSink_FWD_DEFINED__ */


#ifndef __IDBGMSGStream_FWD_DEFINED__
#define __IDBGMSGStream_FWD_DEFINED__
typedef interface IDBGMSGStream IDBGMSGStream;
#endif 	/* __IDBGMSGStream_FWD_DEFINED__ */


#ifndef __IKITL_FWD_DEFINED__
#define __IKITL_FWD_DEFINED__
typedef interface IKITL IKITL;
#endif 	/* __IKITL_FWD_DEFINED__ */


#ifndef __IKitlInit_FWD_DEFINED__
#define __IKitlInit_FWD_DEFINED__
typedef interface IKitlInit IKitlInit;
#endif 	/* __IKitlInit_FWD_DEFINED__ */


#ifndef __KitlInit_FWD_DEFINED__
#define __KitlInit_FWD_DEFINED__

#ifdef __cplusplus
typedef class KitlInit KitlInit;
#else
typedef struct KitlInit KitlInit;
#endif /* __cplusplus */

#endif 	/* __KitlInit_FWD_DEFINED__ */


#ifndef __KITLService_FWD_DEFINED__
#define __KITLService_FWD_DEFINED__

#ifdef __cplusplus
typedef class KITLService KITLService;
#else
typedef struct KITLService KITLService;
#endif /* __cplusplus */

#endif 	/* __KITLService_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_kitlcom_0000 */
/* [local] */ 

#ifndef  _PROPINFONAME_DEVICENAME_DEFINED
#define  _PROPINFONAME_DEVICENAME_DEFINED
DEFINE_GUID(PROPID_DEVICENAME, 0xa1371a36, 0x1dbd, 0x4177, 0xa8, 0xd, 0x4e, 0x69, 0x6, 0x74, 0x8e, 0xee);
static const wchar_t PROPINFONAME_DEVICENAME[] = L"DeviceName";
#endif   //_PROPINFONAME_DEVICENAME_DEFINED


extern RPC_IF_HANDLE __MIDL_itf_kitlcom_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_kitlcom_0000_v0_0_s_ifspec;

#ifndef __IKITLStream_INTERFACE_DEFINED__
#define __IKITLStream_INTERFACE_DEFINED__

/* interface IKITLStream */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IKITLStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9B827231-5AC4-4C16-A3D9-23CFC985B716")
    IKITLStream : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Send( 
            /* [size_is][in] */ const BYTE *pData,
            /* [in] */ DWORD cbData,
            /* [in] */ DWORD dwTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Recv( 
            /* [length_is][size_is][out] */ BYTE *pBuffer,
            /* [out][in] */ DWORD *pcbBuffer,
            /* [in] */ DWORD dwTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceName( 
            /* [out] */ LPOLESTR *pszSvcName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsConnected( 
            /* [in] */ DWORD dwTimeout) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IKITLStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IKITLStream * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IKITLStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IKITLStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *Send )( 
            IKITLStream * This,
            /* [size_is][in] */ const BYTE *pData,
            /* [in] */ DWORD cbData,
            /* [in] */ DWORD dwTimeout);
        
        HRESULT ( STDMETHODCALLTYPE *Recv )( 
            IKITLStream * This,
            /* [length_is][size_is][out] */ BYTE *pBuffer,
            /* [out][in] */ DWORD *pcbBuffer,
            /* [in] */ DWORD dwTimeout);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceName )( 
            IKITLStream * This,
            /* [out] */ LPOLESTR *pszSvcName);
        
        HRESULT ( STDMETHODCALLTYPE *IsConnected )( 
            IKITLStream * This,
            /* [in] */ DWORD dwTimeout);
        
        END_INTERFACE
    } IKITLStreamVtbl;

    interface IKITLStream
    {
        CONST_VTBL struct IKITLStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IKITLStream_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IKITLStream_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IKITLStream_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IKITLStream_Send(This,pData,cbData,dwTimeout)	\
    (This)->lpVtbl -> Send(This,pData,cbData,dwTimeout)

#define IKITLStream_Recv(This,pBuffer,pcbBuffer,dwTimeout)	\
    (This)->lpVtbl -> Recv(This,pBuffer,pcbBuffer,dwTimeout)

#define IKITLStream_GetServiceName(This,pszSvcName)	\
    (This)->lpVtbl -> GetServiceName(This,pszSvcName)

#define IKITLStream_IsConnected(This,dwTimeout)	\
    (This)->lpVtbl -> IsConnected(This,dwTimeout)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IKITLStream_Send_Proxy( 
    IKITLStream * This,
    /* [size_is][in] */ const BYTE *pData,
    /* [in] */ DWORD cbData,
    /* [in] */ DWORD dwTimeout);


void __RPC_STUB IKITLStream_Send_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IKITLStream_Recv_Proxy( 
    IKITLStream * This,
    /* [length_is][size_is][out] */ BYTE *pBuffer,
    /* [out][in] */ DWORD *pcbBuffer,
    /* [in] */ DWORD dwTimeout);


void __RPC_STUB IKITLStream_Recv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IKITLStream_GetServiceName_Proxy( 
    IKITLStream * This,
    /* [out] */ LPOLESTR *pszSvcName);


void __RPC_STUB IKITLStream_GetServiceName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IKITLStream_IsConnected_Proxy( 
    IKITLStream * This,
    /* [in] */ DWORD dwTimeout);


void __RPC_STUB IKITLStream_IsConnected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IKITLStream_INTERFACE_DEFINED__ */


#ifndef __IKITLStreamEx_INTERFACE_DEFINED__
#define __IKITLStreamEx_INTERFACE_DEFINED__

/* interface IKITLStreamEx */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IKITLStreamEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E8A5211-6A5B-4142-83D8-F15E47C4F503")
    IKITLStreamEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetStreamID( 
            /* [out] */ DWORD *pdwStreamId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IKITLStreamExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IKITLStreamEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IKITLStreamEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IKITLStreamEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetStreamID )( 
            IKITLStreamEx * This,
            /* [out] */ DWORD *pdwStreamId);
        
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IKITLStreamEx * This);
        
        END_INTERFACE
    } IKITLStreamExVtbl;

    interface IKITLStreamEx
    {
        CONST_VTBL struct IKITLStreamExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IKITLStreamEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IKITLStreamEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IKITLStreamEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IKITLStreamEx_GetStreamID(This,pdwStreamId)	\
    (This)->lpVtbl -> GetStreamID(This,pdwStreamId)

#define IKITLStreamEx_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IKITLStreamEx_GetStreamID_Proxy( 
    IKITLStreamEx * This,
    /* [out] */ DWORD *pdwStreamId);


void __RPC_STUB IKITLStreamEx_GetStreamID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IKITLStreamEx_Disconnect_Proxy( 
    IKITLStreamEx * This);


void __RPC_STUB IKITLStreamEx_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IKITLStreamEx_INTERFACE_DEFINED__ */


#ifndef ___IPPSHCommandCB_INTERFACE_DEFINED__
#define ___IPPSHCommandCB_INTERFACE_DEFINED__

/* interface _IPPSHCommandCB */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID__IPPSHCommandCB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4F4B6BE3-1BAE-11d5-A662-40804FC10000")
    _IPPSHCommandCB : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCommand( 
            /* [out] */ BSTR *pbstrCommand,
            /* [in] */ int nMaxCmdSize,
            /* [out] */ BOOL *pfFinished,
            /* [out] */ BOOL *pfResubmit) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CmdOut( 
            /* [in] */ BSTR bstrData) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FindFile( 
            /* [in] */ BSTR bstrFileName,
            /* [in] */ BOOL fUseExisting,
            /* [out] */ BSTR *pbstrFullPath) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _IPPSHCommandCBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IPPSHCommandCB * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IPPSHCommandCB * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IPPSHCommandCB * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCommand )( 
            _IPPSHCommandCB * This,
            /* [out] */ BSTR *pbstrCommand,
            /* [in] */ int nMaxCmdSize,
            /* [out] */ BOOL *pfFinished,
            /* [out] */ BOOL *pfResubmit);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CmdOut )( 
            _IPPSHCommandCB * This,
            /* [in] */ BSTR bstrData);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindFile )( 
            _IPPSHCommandCB * This,
            /* [in] */ BSTR bstrFileName,
            /* [in] */ BOOL fUseExisting,
            /* [out] */ BSTR *pbstrFullPath);
        
        END_INTERFACE
    } _IPPSHCommandCBVtbl;

    interface _IPPSHCommandCB
    {
        CONST_VTBL struct _IPPSHCommandCBVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IPPSHCommandCB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IPPSHCommandCB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IPPSHCommandCB_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IPPSHCommandCB_GetCommand(This,pbstrCommand,nMaxCmdSize,pfFinished,pfResubmit)	\
    (This)->lpVtbl -> GetCommand(This,pbstrCommand,nMaxCmdSize,pfFinished,pfResubmit)

#define _IPPSHCommandCB_CmdOut(This,bstrData)	\
    (This)->lpVtbl -> CmdOut(This,bstrData)

#define _IPPSHCommandCB_FindFile(This,bstrFileName,fUseExisting,pbstrFullPath)	\
    (This)->lpVtbl -> FindFile(This,bstrFileName,fUseExisting,pbstrFullPath)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE _IPPSHCommandCB_GetCommand_Proxy( 
    _IPPSHCommandCB * This,
    /* [out] */ BSTR *pbstrCommand,
    /* [in] */ int nMaxCmdSize,
    /* [out] */ BOOL *pfFinished,
    /* [out] */ BOOL *pfResubmit);


void __RPC_STUB _IPPSHCommandCB_GetCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE _IPPSHCommandCB_CmdOut_Proxy( 
    _IPPSHCommandCB * This,
    /* [in] */ BSTR bstrData);


void __RPC_STUB _IPPSHCommandCB_CmdOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE _IPPSHCommandCB_FindFile_Proxy( 
    _IPPSHCommandCB * This,
    /* [in] */ BSTR bstrFileName,
    /* [in] */ BOOL fUseExisting,
    /* [out] */ BSTR *pbstrFullPath);


void __RPC_STUB _IPPSHCommandCB_FindFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___IPPSHCommandCB_INTERFACE_DEFINED__ */


#ifndef ___IPPSHDataSink_INTERFACE_DEFINED__
#define ___IPPSHDataSink_INTERFACE_DEFINED__

/* interface _IPPSHDataSink */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID__IPPSHDataSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CF76FB4F-149C-45b5-9FD7-969359A305D2")
    _IPPSHDataSink : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CmdOut( 
            /* [in] */ BSTR bstrData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _IPPSHDataSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IPPSHDataSink * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IPPSHDataSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IPPSHDataSink * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CmdOut )( 
            _IPPSHDataSink * This,
            /* [in] */ BSTR bstrData);
        
        END_INTERFACE
    } _IPPSHDataSinkVtbl;

    interface _IPPSHDataSink
    {
        CONST_VTBL struct _IPPSHDataSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IPPSHDataSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IPPSHDataSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IPPSHDataSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IPPSHDataSink_CmdOut(This,bstrData)	\
    (This)->lpVtbl -> CmdOut(This,bstrData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE _IPPSHDataSink_CmdOut_Proxy( 
    _IPPSHDataSink * This,
    /* [in] */ BSTR bstrData);


void __RPC_STUB _IPPSHDataSink_CmdOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___IPPSHDataSink_INTERFACE_DEFINED__ */


#ifndef __IPPSHStream_INTERFACE_DEFINED__
#define __IPPSHStream_INTERFACE_DEFINED__

/* interface IPPSHStream */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPPSHStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CF061356-7968-44D0-B606-D1746E873BE4")
    IPPSHStream : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SendCommand( 
            /* [in] */ _IPPSHCommandCB *piCommand,
            /* [out] */ DWORD *pdwCancelCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CancelCommand( 
            /* [in] */ DWORD dwCancelCookie) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPPSHStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPPSHStream * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPPSHStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPPSHStream * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendCommand )( 
            IPPSHStream * This,
            /* [in] */ _IPPSHCommandCB *piCommand,
            /* [out] */ DWORD *pdwCancelCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CancelCommand )( 
            IPPSHStream * This,
            /* [in] */ DWORD dwCancelCookie);
        
        END_INTERFACE
    } IPPSHStreamVtbl;

    interface IPPSHStream
    {
        CONST_VTBL struct IPPSHStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPPSHStream_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPPSHStream_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPPSHStream_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPPSHStream_SendCommand(This,piCommand,pdwCancelCookie)	\
    (This)->lpVtbl -> SendCommand(This,piCommand,pdwCancelCookie)

#define IPPSHStream_CancelCommand(This,dwCancelCookie)	\
    (This)->lpVtbl -> CancelCommand(This,dwCancelCookie)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPPSHStream_SendCommand_Proxy( 
    IPPSHStream * This,
    /* [in] */ _IPPSHCommandCB *piCommand,
    /* [out] */ DWORD *pdwCancelCookie);


void __RPC_STUB IPPSHStream_SendCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPPSHStream_CancelCommand_Proxy( 
    IPPSHStream * This,
    /* [in] */ DWORD dwCancelCookie);


void __RPC_STUB IPPSHStream_CancelCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPPSHStream_INTERFACE_DEFINED__ */


#ifndef ___IDBGMSGDataSink_INTERFACE_DEFINED__
#define ___IDBGMSGDataSink_INTERFACE_DEFINED__

/* interface _IDBGMSGDataSink */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID__IDBGMSGDataSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4130D2CA-8310-41a2-BC55-24F264CA79BF")
    _IDBGMSGDataSink : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MsgOut( 
            /* [in] */ BSTR bstrData,
            /* [in] */ unsigned long dwThrdId,
            /* [in] */ unsigned long dwProcId,
            /* [in] */ unsigned long dwTimeStamp) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _IDBGMSGDataSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IDBGMSGDataSink * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IDBGMSGDataSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IDBGMSGDataSink * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *MsgOut )( 
            _IDBGMSGDataSink * This,
            /* [in] */ BSTR bstrData,
            /* [in] */ unsigned long dwThrdId,
            /* [in] */ unsigned long dwProcId,
            /* [in] */ unsigned long dwTimeStamp);
        
        END_INTERFACE
    } _IDBGMSGDataSinkVtbl;

    interface _IDBGMSGDataSink
    {
        CONST_VTBL struct _IDBGMSGDataSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IDBGMSGDataSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IDBGMSGDataSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IDBGMSGDataSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IDBGMSGDataSink_MsgOut(This,bstrData,dwThrdId,dwProcId,dwTimeStamp)	\
    (This)->lpVtbl -> MsgOut(This,bstrData,dwThrdId,dwProcId,dwTimeStamp)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE _IDBGMSGDataSink_MsgOut_Proxy( 
    _IDBGMSGDataSink * This,
    /* [in] */ BSTR bstrData,
    /* [in] */ unsigned long dwThrdId,
    /* [in] */ unsigned long dwProcId,
    /* [in] */ unsigned long dwTimeStamp);


void __RPC_STUB _IDBGMSGDataSink_MsgOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___IDBGMSGDataSink_INTERFACE_DEFINED__ */


#ifndef __IDBGMSGStream_INTERFACE_DEFINED__
#define __IDBGMSGStream_INTERFACE_DEFINED__

/* interface IDBGMSGStream */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDBGMSGStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3556165F-CDF4-4869-91CB-4EAA80DB6897")
    IDBGMSGStream : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IDBGMSGStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDBGMSGStream * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDBGMSGStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDBGMSGStream * This);
        
        END_INTERFACE
    } IDBGMSGStreamVtbl;

    interface IDBGMSGStream
    {
        CONST_VTBL struct IDBGMSGStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBGMSGStream_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBGMSGStream_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBGMSGStream_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDBGMSGStream_INTERFACE_DEFINED__ */


#ifndef __IKITL_INTERFACE_DEFINED__
#define __IKITL_INTERFACE_DEFINED__

/* interface IKITL */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IKITL;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BC3DAD2D-F4F3-4C32-A527-C39442E20100")
    IKITL : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OpenStream( 
            /* [in] */ LPCOLESTR pszServiceName,
            /* [in] */ DWORD dwTimeout,
            /* [out] */ IKITLStream **ppIKITLStream) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MTU( 
            /* [retval][out] */ long *pMTU) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Bandwidth( 
            /* [retval][out] */ long *pRate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenPPSHStream( 
            /* [out] */ IPPSHStream **ppIPPSHStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenDBGMSGStream( 
            /* [out] */ IDBGMSGStream **ppIDBGMSGStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( 
            /* [in] */ BOOL fCleanBoot) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBootFlags( 
            /* [out] */ DWORD *pdwBootFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBootFlags( 
            /* [in] */ DWORD dwBootFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DebugBreak( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTranId( 
            /* [out] */ DWORD *pdwTranId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IKITLVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IKITL * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IKITL * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IKITL * This);
        
        HRESULT ( STDMETHODCALLTYPE *OpenStream )( 
            IKITL * This,
            /* [in] */ LPCOLESTR pszServiceName,
            /* [in] */ DWORD dwTimeout,
            /* [out] */ IKITLStream **ppIKITLStream);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MTU )( 
            IKITL * This,
            /* [retval][out] */ long *pMTU);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Bandwidth )( 
            IKITL * This,
            /* [retval][out] */ long *pRate);
        
        HRESULT ( STDMETHODCALLTYPE *OpenPPSHStream )( 
            IKITL * This,
            /* [out] */ IPPSHStream **ppIPPSHStream);
        
        HRESULT ( STDMETHODCALLTYPE *OpenDBGMSGStream )( 
            IKITL * This,
            /* [out] */ IDBGMSGStream **ppIDBGMSGStream);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IKITL * This,
            /* [in] */ BOOL fCleanBoot);
        
        HRESULT ( STDMETHODCALLTYPE *GetBootFlags )( 
            IKITL * This,
            /* [out] */ DWORD *pdwBootFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetBootFlags )( 
            IKITL * This,
            /* [in] */ DWORD dwBootFlags);
        
        HRESULT ( STDMETHODCALLTYPE *DebugBreak )( 
            IKITL * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTranId )( 
            IKITL * This,
            /* [out] */ DWORD *pdwTranId);
        
        END_INTERFACE
    } IKITLVtbl;

    interface IKITL
    {
        CONST_VTBL struct IKITLVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IKITL_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IKITL_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IKITL_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IKITL_OpenStream(This,pszServiceName,dwTimeout,ppIKITLStream)	\
    (This)->lpVtbl -> OpenStream(This,pszServiceName,dwTimeout,ppIKITLStream)

#define IKITL_get_MTU(This,pMTU)	\
    (This)->lpVtbl -> get_MTU(This,pMTU)

#define IKITL_get_Bandwidth(This,pRate)	\
    (This)->lpVtbl -> get_Bandwidth(This,pRate)

#define IKITL_OpenPPSHStream(This,ppIPPSHStream)	\
    (This)->lpVtbl -> OpenPPSHStream(This,ppIPPSHStream)

#define IKITL_OpenDBGMSGStream(This,ppIDBGMSGStream)	\
    (This)->lpVtbl -> OpenDBGMSGStream(This,ppIDBGMSGStream)

#define IKITL_Reset(This,fCleanBoot)	\
    (This)->lpVtbl -> Reset(This,fCleanBoot)

#define IKITL_GetBootFlags(This,pdwBootFlags)	\
    (This)->lpVtbl -> GetBootFlags(This,pdwBootFlags)

#define IKITL_SetBootFlags(This,dwBootFlags)	\
    (This)->lpVtbl -> SetBootFlags(This,dwBootFlags)

#define IKITL_DebugBreak(This)	\
    (This)->lpVtbl -> DebugBreak(This)

#define IKITL_GetTranId(This,pdwTranId)	\
    (This)->lpVtbl -> GetTranId(This,pdwTranId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IKITL_OpenStream_Proxy( 
    IKITL * This,
    /* [in] */ LPCOLESTR pszServiceName,
    /* [in] */ DWORD dwTimeout,
    /* [out] */ IKITLStream **ppIKITLStream);


void __RPC_STUB IKITL_OpenStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IKITL_get_MTU_Proxy( 
    IKITL * This,
    /* [retval][out] */ long *pMTU);


void __RPC_STUB IKITL_get_MTU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IKITL_get_Bandwidth_Proxy( 
    IKITL * This,
    /* [retval][out] */ long *pRate);


void __RPC_STUB IKITL_get_Bandwidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IKITL_OpenPPSHStream_Proxy( 
    IKITL * This,
    /* [out] */ IPPSHStream **ppIPPSHStream);


void __RPC_STUB IKITL_OpenPPSHStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IKITL_OpenDBGMSGStream_Proxy( 
    IKITL * This,
    /* [out] */ IDBGMSGStream **ppIDBGMSGStream);


void __RPC_STUB IKITL_OpenDBGMSGStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IKITL_Reset_Proxy( 
    IKITL * This,
    /* [in] */ BOOL fCleanBoot);


void __RPC_STUB IKITL_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IKITL_GetBootFlags_Proxy( 
    IKITL * This,
    /* [out] */ DWORD *pdwBootFlags);


void __RPC_STUB IKITL_GetBootFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IKITL_SetBootFlags_Proxy( 
    IKITL * This,
    /* [in] */ DWORD dwBootFlags);


void __RPC_STUB IKITL_SetBootFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IKITL_DebugBreak_Proxy( 
    IKITL * This);


void __RPC_STUB IKITL_DebugBreak_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IKITL_GetTranId_Proxy( 
    IKITL * This,
    /* [out] */ DWORD *pdwTranId);


void __RPC_STUB IKITL_GetTranId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IKITL_INTERFACE_DEFINED__ */


#ifndef __IKitlInit_INTERFACE_DEFINED__
#define __IKitlInit_INTERFACE_DEFINED__

/* interface IKitlInit */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IKitlInit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4766C31D-8C78-4636-9289-AEB0C1134825")
    IKitlInit : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ UINT KitlLibId,
            /* [in] */ BSTR bstrPropertyGUID,
            /* [out] */ IKITL **ppiKitl) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IKitlInitVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IKitlInit * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IKitlInit * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IKitlInit * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IKitlInit * This,
            /* [in] */ UINT KitlLibId,
            /* [in] */ BSTR bstrPropertyGUID,
            /* [out] */ IKITL **ppiKitl);
        
        END_INTERFACE
    } IKitlInitVtbl;

    interface IKitlInit
    {
        CONST_VTBL struct IKitlInitVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IKitlInit_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IKitlInit_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IKitlInit_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IKitlInit_Initialize(This,KitlLibId,bstrPropertyGUID,ppiKitl)	\
    (This)->lpVtbl -> Initialize(This,KitlLibId,bstrPropertyGUID,ppiKitl)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IKitlInit_Initialize_Proxy( 
    IKitlInit * This,
    /* [in] */ UINT KitlLibId,
    /* [in] */ BSTR bstrPropertyGUID,
    /* [out] */ IKITL **ppiKitl);


void __RPC_STUB IKitlInit_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IKitlInit_INTERFACE_DEFINED__ */



#ifndef __KITLCOMLib_LIBRARY_DEFINED__
#define __KITLCOMLib_LIBRARY_DEFINED__

/* library KITLCOMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_KITLCOMLib;

EXTERN_C const CLSID CLSID_KitlInit;

#ifdef __cplusplus

class DECLSPEC_UUID("CC6578D9-F20D-495D-8BED-9C567CBCCCDA")
KitlInit;
#endif

EXTERN_C const CLSID CLSID_KITLService;

#ifdef __cplusplus

class DECLSPEC_UUID("702FFE21-037A-4C15-BD18-6B39DD74611A")
KITLService;
#endif
#endif /* __KITLCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


