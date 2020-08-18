

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for download.idl:
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

#ifndef __download_h__
#define __download_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDownload_FWD_DEFINED__
#define __IDownload_FWD_DEFINED__
typedef interface IDownload IDownload;
#endif 	/* __IDownload_FWD_DEFINED__ */


#ifndef ___IDownloadProgress_FWD_DEFINED__
#define ___IDownloadProgress_FWD_DEFINED__
typedef interface _IDownloadProgress _IDownloadProgress;
#endif 	/* ___IDownloadProgress_FWD_DEFINED__ */


#ifndef ___IDeviceReset_FWD_DEFINED__
#define ___IDeviceReset_FWD_DEFINED__
typedef interface _IDeviceReset _IDeviceReset;
#endif 	/* ___IDeviceReset_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IDownload_INTERFACE_DEFINED__
#define __IDownload_INTERFACE_DEFINED__

/* interface IDownload */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDownload;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A5E1F5B8-5FF6-4f72-98B3-5FCC553652EC")
    IDownload : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DownloadImage( 
            /* [in] */ LPCOLESTR pszImagePath,
            /* [in] */ DWORD dwRebootTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopDownloadImage( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE JumpToImage( 
            /* [in] */ DWORD dwJumpFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopJumpToImage( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDownloadVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDownload * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDownload * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDownload * This);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadImage )( 
            IDownload * This,
            /* [in] */ LPCOLESTR pszImagePath,
            /* [in] */ DWORD dwRebootTimeout);
        
        HRESULT ( STDMETHODCALLTYPE *StopDownloadImage )( 
            IDownload * This);
        
        HRESULT ( STDMETHODCALLTYPE *JumpToImage )( 
            IDownload * This,
            /* [in] */ DWORD dwJumpFlags);
        
        HRESULT ( STDMETHODCALLTYPE *StopJumpToImage )( 
            IDownload * This);
        
        END_INTERFACE
    } IDownloadVtbl;

    interface IDownload
    {
        CONST_VTBL struct IDownloadVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDownload_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDownload_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDownload_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDownload_DownloadImage(This,pszImagePath,dwRebootTimeout)	\
    (This)->lpVtbl -> DownloadImage(This,pszImagePath,dwRebootTimeout)

#define IDownload_StopDownloadImage(This)	\
    (This)->lpVtbl -> StopDownloadImage(This)

#define IDownload_JumpToImage(This,dwJumpFlags)	\
    (This)->lpVtbl -> JumpToImage(This,dwJumpFlags)

#define IDownload_StopJumpToImage(This)	\
    (This)->lpVtbl -> StopJumpToImage(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDownload_DownloadImage_Proxy( 
    IDownload * This,
    /* [in] */ LPCOLESTR pszImagePath,
    /* [in] */ DWORD dwRebootTimeout);


void __RPC_STUB IDownload_DownloadImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDownload_StopDownloadImage_Proxy( 
    IDownload * This);


void __RPC_STUB IDownload_StopDownloadImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDownload_JumpToImage_Proxy( 
    IDownload * This,
    /* [in] */ DWORD dwJumpFlags);


void __RPC_STUB IDownload_JumpToImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDownload_StopJumpToImage_Proxy( 
    IDownload * This);


void __RPC_STUB IDownload_StopJumpToImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDownload_INTERFACE_DEFINED__ */


#ifndef ___IDownloadProgress_INTERFACE_DEFINED__
#define ___IDownloadProgress_INTERFACE_DEFINED__

/* interface _IDownloadProgress */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID__IDownloadProgress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E3C0BD4B-8339-4712-8F9C-95983577C435")
    _IDownloadProgress : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnProgressNotify( 
            /* [in] */ DWORD dwCurrentSize,
            /* [in] */ DWORD dwTotalSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _IDownloadProgressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IDownloadProgress * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IDownloadProgress * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IDownloadProgress * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnProgressNotify )( 
            _IDownloadProgress * This,
            /* [in] */ DWORD dwCurrentSize,
            /* [in] */ DWORD dwTotalSize);
        
        END_INTERFACE
    } _IDownloadProgressVtbl;

    interface _IDownloadProgress
    {
        CONST_VTBL struct _IDownloadProgressVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IDownloadProgress_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IDownloadProgress_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IDownloadProgress_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IDownloadProgress_OnProgressNotify(This,dwCurrentSize,dwTotalSize)	\
    (This)->lpVtbl -> OnProgressNotify(This,dwCurrentSize,dwTotalSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE _IDownloadProgress_OnProgressNotify_Proxy( 
    _IDownloadProgress * This,
    /* [in] */ DWORD dwCurrentSize,
    /* [in] */ DWORD dwTotalSize);


void __RPC_STUB _IDownloadProgress_OnProgressNotify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___IDownloadProgress_INTERFACE_DEFINED__ */


#ifndef ___IDeviceReset_INTERFACE_DEFINED__
#define ___IDeviceReset_INTERFACE_DEFINED__

/* interface _IDeviceReset */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID__IDeviceReset;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ab47c2be-8b63-46bc-89c4-730872760f18")
    _IDeviceReset : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnResetNotify( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _IDeviceResetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IDeviceReset * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IDeviceReset * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IDeviceReset * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnResetNotify )( 
            _IDeviceReset * This);
        
        END_INTERFACE
    } _IDeviceResetVtbl;

    interface _IDeviceReset
    {
        CONST_VTBL struct _IDeviceResetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IDeviceReset_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IDeviceReset_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IDeviceReset_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IDeviceReset_OnResetNotify(This)	\
    (This)->lpVtbl -> OnResetNotify(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE _IDeviceReset_OnResetNotify_Proxy( 
    _IDeviceReset * This);


void __RPC_STUB _IDeviceReset_OnResetNotify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___IDeviceReset_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_download_0254 */
/* [local] */ 

#ifndef  _PROPINFONAME_DEVICENAME_DEFINED
#define  _PROPINFONAME_DEVICENAME_DEFINED
DEFINE_GUID(PROPID_DEVICENAME, 0xa1371a36, 0x1dbd, 0x4177, 0xa8, 0xd, 0x4e, 0x69, 0x6, 0x74, 0x8e, 0xee);
static const wchar_t PROPINFONAME_DEVICENAME[] = L"DeviceName";
#endif   //_PROPINFONAME_DEVICENAME_DEFINED


extern RPC_IF_HANDLE __MIDL_itf_download_0254_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_download_0254_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


