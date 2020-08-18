

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for tl.idl:
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

#ifndef __tl_h__
#define __tl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITransport_FWD_DEFINED__
#define __ITransport_FWD_DEFINED__
typedef interface ITransport ITransport;
#endif 	/* __ITransport_FWD_DEFINED__ */


#ifndef __ITransportConnection_FWD_DEFINED__
#define __ITransportConnection_FWD_DEFINED__
typedef interface ITransportConnection ITransportConnection;
#endif 	/* __ITransportConnection_FWD_DEFINED__ */


#ifndef __ITransportConnection2_FWD_DEFINED__
#define __ITransportConnection2_FWD_DEFINED__
typedef interface ITransportConnection2 ITransportConnection2;
#endif 	/* __ITransportConnection2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "cemgr.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_tl_0000 */
/* [local] */ 

static const int E_BAD_BUFFER			= MAKE_HRESULT(11, FACILITY_ITF, 0x01);
static const int E_INSUFFICIENT_BUFFER	= MAKE_HRESULT(1, FACILITY_ITF, 0x02);
static const int E_SEND_FAILED			= MAKE_HRESULT(11, FACILITY_ITF, 0x03);
static const int E_READ_FAILED			= MAKE_HRESULT(11, FACILITY_ITF, 0x04);

enum __MIDL___MIDL_itf_tl_0000_0001
    {	TL_KEEPALIVE	= 0x1,
	TL_DIRECT_CONNECT	= 0x2,
	TL_AUTO_REGISTER	= 0x4,
	TL_AUTO_STARTUP	= 0x8,
	TL_NO_CONNECT	= 0x10,
	TL_STRING_DATA	= 0x20,
	TL_PPP_PEER	= 0x40
    } ;
typedef ULONG TL_FLAGS;

typedef struct tlpubinfo
    {
    DWORD cbSize;
    DWORD dwVersion;
    DWORD dwFlags;
    DWORD dwConnectTimeOut;
    DWORD dwKeepAliveTimeOut;
    DWORD cbDataSize;
    BYTE pData[ 1 ];
    } 	TLPUBINFO;

typedef struct tlpubinfo *PTLPUBINFO;




extern RPC_IF_HANDLE __MIDL_itf_tl_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tl_0000_v0_0_s_ifspec;

#ifndef __ITransport_INTERFACE_DEFINED__
#define __ITransport_INTERFACE_DEFINED__

/* interface ITransport */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_ITransport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5C6F612B-0158-11D2-BBA0-00A0C9C9CCEE")
    ITransport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [out] */ DEVICE_TYPE *pdt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ LPOLESTR *ppszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClientName( 
            /* [out] */ LPOLESTR *ppszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Configure( 
            /* [in] */ HWND hWnd,
            /* [in] */ IRemoteDevice *piDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitConnection( 
            /* [in] */ IRemoteDevice *piDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConnectionInfo( 
            /* [in] */ DWORD dwMaxSize,
            /* [length_is][size_is][out] */ BYTE *pData,
            /* [out] */ LPDWORD pdwActualSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Accept( 
            /* [out] */ ITransportConnection **ppiTransportConnect) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITransport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITransport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITransport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            ITransport * This,
            /* [out] */ DEVICE_TYPE *pdt);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            ITransport * This,
            /* [out] */ LPOLESTR *ppszName);
        
        HRESULT ( STDMETHODCALLTYPE *GetClientName )( 
            ITransport * This,
            /* [out] */ LPOLESTR *ppszName);
        
        HRESULT ( STDMETHODCALLTYPE *Configure )( 
            ITransport * This,
            /* [in] */ HWND hWnd,
            /* [in] */ IRemoteDevice *piDevice);
        
        HRESULT ( STDMETHODCALLTYPE *InitConnection )( 
            ITransport * This,
            /* [in] */ IRemoteDevice *piDevice);
        
        HRESULT ( STDMETHODCALLTYPE *GetConnectionInfo )( 
            ITransport * This,
            /* [in] */ DWORD dwMaxSize,
            /* [length_is][size_is][out] */ BYTE *pData,
            /* [out] */ LPDWORD pdwActualSize);
        
        HRESULT ( STDMETHODCALLTYPE *Accept )( 
            ITransport * This,
            /* [out] */ ITransportConnection **ppiTransportConnect);
        
        END_INTERFACE
    } ITransportVtbl;

    interface ITransport
    {
        CONST_VTBL struct ITransportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITransport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITransport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITransport_GetType(This,pdt)	\
    (This)->lpVtbl -> GetType(This,pdt)

#define ITransport_GetName(This,ppszName)	\
    (This)->lpVtbl -> GetName(This,ppszName)

#define ITransport_GetClientName(This,ppszName)	\
    (This)->lpVtbl -> GetClientName(This,ppszName)

#define ITransport_Configure(This,hWnd,piDevice)	\
    (This)->lpVtbl -> Configure(This,hWnd,piDevice)

#define ITransport_InitConnection(This,piDevice)	\
    (This)->lpVtbl -> InitConnection(This,piDevice)

#define ITransport_GetConnectionInfo(This,dwMaxSize,pData,pdwActualSize)	\
    (This)->lpVtbl -> GetConnectionInfo(This,dwMaxSize,pData,pdwActualSize)

#define ITransport_Accept(This,ppiTransportConnect)	\
    (This)->lpVtbl -> Accept(This,ppiTransportConnect)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITransport_GetType_Proxy( 
    ITransport * This,
    /* [out] */ DEVICE_TYPE *pdt);


void __RPC_STUB ITransport_GetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITransport_GetName_Proxy( 
    ITransport * This,
    /* [out] */ LPOLESTR *ppszName);


void __RPC_STUB ITransport_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITransport_GetClientName_Proxy( 
    ITransport * This,
    /* [out] */ LPOLESTR *ppszName);


void __RPC_STUB ITransport_GetClientName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITransport_Configure_Proxy( 
    ITransport * This,
    /* [in] */ HWND hWnd,
    /* [in] */ IRemoteDevice *piDevice);


void __RPC_STUB ITransport_Configure_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITransport_InitConnection_Proxy( 
    ITransport * This,
    /* [in] */ IRemoteDevice *piDevice);


void __RPC_STUB ITransport_InitConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITransport_GetConnectionInfo_Proxy( 
    ITransport * This,
    /* [in] */ DWORD dwMaxSize,
    /* [length_is][size_is][out] */ BYTE *pData,
    /* [out] */ LPDWORD pdwActualSize);


void __RPC_STUB ITransport_GetConnectionInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITransport_Accept_Proxy( 
    ITransport * This,
    /* [out] */ ITransportConnection **ppiTransportConnect);


void __RPC_STUB ITransport_Accept_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransport_INTERFACE_DEFINED__ */


#ifndef __ITransportConnection_INTERFACE_DEFINED__
#define __ITransportConnection_INTERFACE_DEFINED__

/* interface ITransportConnection */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_ITransportConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5C6F612D-0158-11D2-BBA0-00A0C9C9CCEE")
    ITransportConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ReadBytes( 
            /* [in] */ DWORD dwSize,
            /* [length_is][size_is][out] */ BYTE *pData,
            /* [out] */ LPDWORD pdwBytesAvailable,
            /* [out] */ LPDWORD pdwBytesRead) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteBytes( 
            /* [in] */ DWORD dwSize,
            /* [size_is][in] */ BYTE *pData,
            /* [out] */ LPDWORD pdwBytesWritten) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransportConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITransportConnection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITransportConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITransportConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *ReadBytes )( 
            ITransportConnection * This,
            /* [in] */ DWORD dwSize,
            /* [length_is][size_is][out] */ BYTE *pData,
            /* [out] */ LPDWORD pdwBytesAvailable,
            /* [out] */ LPDWORD pdwBytesRead);
        
        HRESULT ( STDMETHODCALLTYPE *WriteBytes )( 
            ITransportConnection * This,
            /* [in] */ DWORD dwSize,
            /* [size_is][in] */ BYTE *pData,
            /* [out] */ LPDWORD pdwBytesWritten);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            ITransportConnection * This);
        
        END_INTERFACE
    } ITransportConnectionVtbl;

    interface ITransportConnection
    {
        CONST_VTBL struct ITransportConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransportConnection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITransportConnection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITransportConnection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITransportConnection_ReadBytes(This,dwSize,pData,pdwBytesAvailable,pdwBytesRead)	\
    (This)->lpVtbl -> ReadBytes(This,dwSize,pData,pdwBytesAvailable,pdwBytesRead)

#define ITransportConnection_WriteBytes(This,dwSize,pData,pdwBytesWritten)	\
    (This)->lpVtbl -> WriteBytes(This,dwSize,pData,pdwBytesWritten)

#define ITransportConnection_Close(This)	\
    (This)->lpVtbl -> Close(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITransportConnection_ReadBytes_Proxy( 
    ITransportConnection * This,
    /* [in] */ DWORD dwSize,
    /* [length_is][size_is][out] */ BYTE *pData,
    /* [out] */ LPDWORD pdwBytesAvailable,
    /* [out] */ LPDWORD pdwBytesRead);


void __RPC_STUB ITransportConnection_ReadBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITransportConnection_WriteBytes_Proxy( 
    ITransportConnection * This,
    /* [in] */ DWORD dwSize,
    /* [size_is][in] */ BYTE *pData,
    /* [out] */ LPDWORD pdwBytesWritten);


void __RPC_STUB ITransportConnection_WriteBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITransportConnection_Close_Proxy( 
    ITransportConnection * This);


void __RPC_STUB ITransportConnection_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransportConnection_INTERFACE_DEFINED__ */


#ifndef __ITransportConnection2_INTERFACE_DEFINED__
#define __ITransportConnection2_INTERFACE_DEFINED__

/* interface ITransportConnection2 */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_ITransportConnection2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9AAEF5B7-8C4B-4369-B103-4D5FFB0AC2AD")
    ITransportConnection2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ReadBytes( 
            /* [in] */ DWORD dwSize,
            /* [in] */ DWORD dwTimeout,
            /* [length_is][size_is][out] */ BYTE *pData,
            /* [out] */ LPDWORD pdwBytesAvailable,
            /* [out] */ LPDWORD pdwBytesRead) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransportConnection2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITransportConnection2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITransportConnection2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITransportConnection2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *ReadBytes )( 
            ITransportConnection2 * This,
            /* [in] */ DWORD dwSize,
            /* [in] */ DWORD dwTimeout,
            /* [length_is][size_is][out] */ BYTE *pData,
            /* [out] */ LPDWORD pdwBytesAvailable,
            /* [out] */ LPDWORD pdwBytesRead);
        
        END_INTERFACE
    } ITransportConnection2Vtbl;

    interface ITransportConnection2
    {
        CONST_VTBL struct ITransportConnection2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransportConnection2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITransportConnection2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITransportConnection2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITransportConnection2_ReadBytes(This,dwSize,dwTimeout,pData,pdwBytesAvailable,pdwBytesRead)	\
    (This)->lpVtbl -> ReadBytes(This,dwSize,dwTimeout,pData,pdwBytesAvailable,pdwBytesRead)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITransportConnection2_ReadBytes_Proxy( 
    ITransportConnection2 * This,
    /* [in] */ DWORD dwSize,
    /* [in] */ DWORD dwTimeout,
    /* [length_is][size_is][out] */ BYTE *pData,
    /* [out] */ LPDWORD pdwBytesAvailable,
    /* [out] */ LPDWORD pdwBytesRead);


void __RPC_STUB ITransportConnection2_ReadBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransportConnection2_INTERFACE_DEFINED__ */


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


