

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for cemgrui.idl:
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

#ifndef __cemgrui_h__
#define __cemgrui_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPlatformManagerUI_FWD_DEFINED__
#define __IPlatformManagerUI_FWD_DEFINED__
typedef interface IPlatformManagerUI IPlatformManagerUI;
#endif 	/* __IPlatformManagerUI_FWD_DEFINED__ */


#ifndef __IPlatformManagerUI2_FWD_DEFINED__
#define __IPlatformManagerUI2_FWD_DEFINED__
typedef interface IPlatformManagerUI2 IPlatformManagerUI2;
#endif 	/* __IPlatformManagerUI2_FWD_DEFINED__ */


#ifndef __PlatformManagerUI_FWD_DEFINED__
#define __PlatformManagerUI_FWD_DEFINED__

#ifdef __cplusplus
typedef class PlatformManagerUI PlatformManagerUI;
#else
typedef struct PlatformManagerUI PlatformManagerUI;
#endif /* __cplusplus */

#endif 	/* __PlatformManagerUI_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "cemgr.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IPlatformManagerUI_INTERFACE_DEFINED__
#define __IPlatformManagerUI_INTERFACE_DEFINED__

/* interface IPlatformManagerUI */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPlatformManagerUI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E835B19F-3DDF-11D2-BBB2-00A0C9C9CCEE")
    IPlatformManagerUI : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Configure( 
            /* [in] */ HWND hWnd) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [in] */ HWND hWnd,
            /* [in] */ IPlatformManager *piMgr,
            /* [out] */ IPlatformCE **ppiPlatform,
            /* [out] */ IRemoteDevice **ppiDevice) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ HWND hWnd,
            /* [in] */ IRemoteDevice *piDevice,
            /* [out] */ IConnection **ppiConnection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlatformManagerUIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlatformManagerUI * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlatformManagerUI * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlatformManagerUI * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Configure )( 
            IPlatformManagerUI * This,
            /* [in] */ HWND hWnd);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IPlatformManagerUI * This,
            /* [in] */ HWND hWnd,
            /* [in] */ IPlatformManager *piMgr,
            /* [out] */ IPlatformCE **ppiPlatform,
            /* [out] */ IRemoteDevice **ppiDevice);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IPlatformManagerUI * This,
            /* [in] */ HWND hWnd,
            /* [in] */ IRemoteDevice *piDevice,
            /* [out] */ IConnection **ppiConnection);
        
        END_INTERFACE
    } IPlatformManagerUIVtbl;

    interface IPlatformManagerUI
    {
        CONST_VTBL struct IPlatformManagerUIVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlatformManagerUI_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlatformManagerUI_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlatformManagerUI_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlatformManagerUI_Configure(This,hWnd)	\
    (This)->lpVtbl -> Configure(This,hWnd)

#define IPlatformManagerUI_GetDevice(This,hWnd,piMgr,ppiPlatform,ppiDevice)	\
    (This)->lpVtbl -> GetDevice(This,hWnd,piMgr,ppiPlatform,ppiDevice)

#define IPlatformManagerUI_Connect(This,hWnd,piDevice,ppiConnection)	\
    (This)->lpVtbl -> Connect(This,hWnd,piDevice,ppiConnection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPlatformManagerUI_Configure_Proxy( 
    IPlatformManagerUI * This,
    /* [in] */ HWND hWnd);


void __RPC_STUB IPlatformManagerUI_Configure_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPlatformManagerUI_GetDevice_Proxy( 
    IPlatformManagerUI * This,
    /* [in] */ HWND hWnd,
    /* [in] */ IPlatformManager *piMgr,
    /* [out] */ IPlatformCE **ppiPlatform,
    /* [out] */ IRemoteDevice **ppiDevice);


void __RPC_STUB IPlatformManagerUI_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPlatformManagerUI_Connect_Proxy( 
    IPlatformManagerUI * This,
    /* [in] */ HWND hWnd,
    /* [in] */ IRemoteDevice *piDevice,
    /* [out] */ IConnection **ppiConnection);


void __RPC_STUB IPlatformManagerUI_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlatformManagerUI_INTERFACE_DEFINED__ */


#ifndef __IPlatformManagerUI2_INTERFACE_DEFINED__
#define __IPlatformManagerUI2_INTERFACE_DEFINED__

/* interface IPlatformManagerUI2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPlatformManagerUI2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("85D50476-8861-41E4-B15D-52908B78C9BE")
    IPlatformManagerUI2 : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Configure( 
            /* [in] */ HWND hWnd,
            /* [in] */ WORD wMajorVersion,
            /* [defaultvalue][in] */ WORD wMinorVersion = 0) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [in] */ HWND hWnd,
            /* [in] */ IPlatformManager *piMgr,
            /* [in] */ WORD wMajorVersion,
            /* [in] */ WORD wMinorVersion,
            /* [out] */ IPlatformCE **ppiPlatform,
            /* [out] */ IRemoteDevice **ppiDevice) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ HWND hWnd,
            /* [in] */ IRemoteDevice *piDevice,
            /* [out] */ IConnection **ppiConnection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlatformManagerUI2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlatformManagerUI2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlatformManagerUI2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlatformManagerUI2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Configure )( 
            IPlatformManagerUI2 * This,
            /* [in] */ HWND hWnd,
            /* [in] */ WORD wMajorVersion,
            /* [defaultvalue][in] */ WORD wMinorVersion);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IPlatformManagerUI2 * This,
            /* [in] */ HWND hWnd,
            /* [in] */ IPlatformManager *piMgr,
            /* [in] */ WORD wMajorVersion,
            /* [in] */ WORD wMinorVersion,
            /* [out] */ IPlatformCE **ppiPlatform,
            /* [out] */ IRemoteDevice **ppiDevice);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IPlatformManagerUI2 * This,
            /* [in] */ HWND hWnd,
            /* [in] */ IRemoteDevice *piDevice,
            /* [out] */ IConnection **ppiConnection);
        
        END_INTERFACE
    } IPlatformManagerUI2Vtbl;

    interface IPlatformManagerUI2
    {
        CONST_VTBL struct IPlatformManagerUI2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlatformManagerUI2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlatformManagerUI2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlatformManagerUI2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlatformManagerUI2_Configure(This,hWnd,wMajorVersion,wMinorVersion)	\
    (This)->lpVtbl -> Configure(This,hWnd,wMajorVersion,wMinorVersion)

#define IPlatformManagerUI2_GetDevice(This,hWnd,piMgr,wMajorVersion,wMinorVersion,ppiPlatform,ppiDevice)	\
    (This)->lpVtbl -> GetDevice(This,hWnd,piMgr,wMajorVersion,wMinorVersion,ppiPlatform,ppiDevice)

#define IPlatformManagerUI2_Connect(This,hWnd,piDevice,ppiConnection)	\
    (This)->lpVtbl -> Connect(This,hWnd,piDevice,ppiConnection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPlatformManagerUI2_Configure_Proxy( 
    IPlatformManagerUI2 * This,
    /* [in] */ HWND hWnd,
    /* [in] */ WORD wMajorVersion,
    /* [defaultvalue][in] */ WORD wMinorVersion);


void __RPC_STUB IPlatformManagerUI2_Configure_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPlatformManagerUI2_GetDevice_Proxy( 
    IPlatformManagerUI2 * This,
    /* [in] */ HWND hWnd,
    /* [in] */ IPlatformManager *piMgr,
    /* [in] */ WORD wMajorVersion,
    /* [in] */ WORD wMinorVersion,
    /* [out] */ IPlatformCE **ppiPlatform,
    /* [out] */ IRemoteDevice **ppiDevice);


void __RPC_STUB IPlatformManagerUI2_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPlatformManagerUI2_Connect_Proxy( 
    IPlatformManagerUI2 * This,
    /* [in] */ HWND hWnd,
    /* [in] */ IRemoteDevice *piDevice,
    /* [out] */ IConnection **ppiConnection);


void __RPC_STUB IPlatformManagerUI2_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlatformManagerUI2_INTERFACE_DEFINED__ */



#ifndef __CEMGRUILib_LIBRARY_DEFINED__
#define __CEMGRUILib_LIBRARY_DEFINED__

/* library CEMGRUILib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_CEMGRUILib;

EXTERN_C const CLSID CLSID_PlatformManagerUI;

#ifdef __cplusplus

class DECLSPEC_UUID("E835B190-3DDF-11D2-BBB2-00A0C9C9CCEE")
PlatformManagerUI;
#endif
#endif /* __CEMGRUILib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


