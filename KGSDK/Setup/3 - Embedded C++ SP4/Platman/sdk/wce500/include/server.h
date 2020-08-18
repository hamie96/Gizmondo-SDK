

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for server.idl:
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

#ifndef __server_h__
#define __server_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IServer_FWD_DEFINED__
#define __IServer_FWD_DEFINED__
typedef interface IServer IServer;
#endif 	/* __IServer_FWD_DEFINED__ */


#ifndef __IServerConnection_FWD_DEFINED__
#define __IServerConnection_FWD_DEFINED__
typedef interface IServerConnection IServerConnection;
#endif 	/* __IServerConnection_FWD_DEFINED__ */


#ifndef __IServerConnectionEx_FWD_DEFINED__
#define __IServerConnectionEx_FWD_DEFINED__
typedef interface IServerConnectionEx IServerConnectionEx;
#endif 	/* __IServerConnectionEx_FWD_DEFINED__ */


#ifndef __IServerConnectionEx2_FWD_DEFINED__
#define __IServerConnectionEx2_FWD_DEFINED__
typedef interface IServerConnectionEx2 IServerConnectionEx2;
#endif 	/* __IServerConnectionEx2_FWD_DEFINED__ */


#ifndef __IServerConnectionEx3_FWD_DEFINED__
#define __IServerConnectionEx3_FWD_DEFINED__
typedef interface IServerConnectionEx3 IServerConnectionEx3;
#endif 	/* __IServerConnectionEx3_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "cemgr.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_server_0000 */
/* [local] */ 

static const unsigned long SERVER_FLAG_SERVER_COPY  = 0x00000001;
static const unsigned long SERVER_FLAG_EXTRA_COPY   = 0x00000002;



extern RPC_IF_HANDLE __MIDL_itf_server_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_server_0000_v0_0_s_ifspec;

#ifndef __IServer_INTERFACE_DEFINED__
#define __IServer_INTERFACE_DEFINED__

/* interface IServer */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E1EBB0FC-00A2-11D2-BBA0-00A0C9C9CCEE")
    IServer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [out] */ DEVICE_TYPE *pdt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ LPOLESTR *ppszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Configure( 
            /* [in] */ HWND hWnd,
            /* [in] */ IRemoteDevice *piDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ IRemoteDevice *piDevice,
            /* [out] */ IServerConnection **ppiServerConnect) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IServer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IServer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IServer * This,
            /* [out] */ DEVICE_TYPE *pdt);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IServer * This,
            /* [out] */ LPOLESTR *ppszName);
        
        HRESULT ( STDMETHODCALLTYPE *Configure )( 
            IServer * This,
            /* [in] */ HWND hWnd,
            /* [in] */ IRemoteDevice *piDevice);
        
        HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IServer * This,
            /* [in] */ IRemoteDevice *piDevice,
            /* [out] */ IServerConnection **ppiServerConnect);
        
        END_INTERFACE
    } IServerVtbl;

    interface IServer
    {
        CONST_VTBL struct IServerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServer_GetType(This,pdt)	\
    (This)->lpVtbl -> GetType(This,pdt)

#define IServer_GetName(This,ppszName)	\
    (This)->lpVtbl -> GetName(This,ppszName)

#define IServer_Configure(This,hWnd,piDevice)	\
    (This)->lpVtbl -> Configure(This,hWnd,piDevice)

#define IServer_Connect(This,piDevice,ppiServerConnect)	\
    (This)->lpVtbl -> Connect(This,piDevice,ppiServerConnect)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IServer_GetType_Proxy( 
    IServer * This,
    /* [out] */ DEVICE_TYPE *pdt);


void __RPC_STUB IServer_GetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServer_GetName_Proxy( 
    IServer * This,
    /* [out] */ LPOLESTR *ppszName);


void __RPC_STUB IServer_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServer_Configure_Proxy( 
    IServer * This,
    /* [in] */ HWND hWnd,
    /* [in] */ IRemoteDevice *piDevice);


void __RPC_STUB IServer_Configure_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServer_Connect_Proxy( 
    IServer * This,
    /* [in] */ IRemoteDevice *piDevice,
    /* [out] */ IServerConnection **ppiServerConnect);


void __RPC_STUB IServer_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IServer_INTERFACE_DEFINED__ */


#ifndef __IServerConnection_INTERFACE_DEFINED__
#define __IServerConnection_INTERFACE_DEFINED__

/* interface IServerConnection */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IServerConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E1EBB0FE-00A2-11D2-BBA0-00A0C9C9CCEE")
    IServerConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CheckFile( 
            /* [in] */ DWORD dwTimeDateStamp,
            /* [in] */ LPCOLESTR pszDestFileName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSystemInfo( 
            /* [out] */ LPWORD pwArchitecture,
            /* [out] */ LPDWORD pdwCPUType,
            /* [out] */ LPWORD pwMinorVersion,
            /* [out] */ LPWORD pwMajorVersion) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Copy( 
            /* [in] */ LPCOLESTR pszSrcFullPath,
            /* [in] */ LPCOLESTR pszDestFileName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Launch( 
            /* [in] */ LPCOLESTR pszExeName,
            /* [in] */ LPCOLESTR pszCmdLine) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServerConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IServerConnection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IServerConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IServerConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *CheckFile )( 
            IServerConnection * This,
            /* [in] */ DWORD dwTimeDateStamp,
            /* [in] */ LPCOLESTR pszDestFileName);
        
        HRESULT ( STDMETHODCALLTYPE *GetSystemInfo )( 
            IServerConnection * This,
            /* [out] */ LPWORD pwArchitecture,
            /* [out] */ LPDWORD pdwCPUType,
            /* [out] */ LPWORD pwMinorVersion,
            /* [out] */ LPWORD pwMajorVersion);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IServerConnection * This,
            /* [in] */ LPCOLESTR pszSrcFullPath,
            /* [in] */ LPCOLESTR pszDestFileName);
        
        HRESULT ( STDMETHODCALLTYPE *Launch )( 
            IServerConnection * This,
            /* [in] */ LPCOLESTR pszExeName,
            /* [in] */ LPCOLESTR pszCmdLine);
        
        END_INTERFACE
    } IServerConnectionVtbl;

    interface IServerConnection
    {
        CONST_VTBL struct IServerConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServerConnection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServerConnection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServerConnection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServerConnection_CheckFile(This,dwTimeDateStamp,pszDestFileName)	\
    (This)->lpVtbl -> CheckFile(This,dwTimeDateStamp,pszDestFileName)

#define IServerConnection_GetSystemInfo(This,pwArchitecture,pdwCPUType,pwMinorVersion,pwMajorVersion)	\
    (This)->lpVtbl -> GetSystemInfo(This,pwArchitecture,pdwCPUType,pwMinorVersion,pwMajorVersion)

#define IServerConnection_Copy(This,pszSrcFullPath,pszDestFileName)	\
    (This)->lpVtbl -> Copy(This,pszSrcFullPath,pszDestFileName)

#define IServerConnection_Launch(This,pszExeName,pszCmdLine)	\
    (This)->lpVtbl -> Launch(This,pszExeName,pszCmdLine)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IServerConnection_CheckFile_Proxy( 
    IServerConnection * This,
    /* [in] */ DWORD dwTimeDateStamp,
    /* [in] */ LPCOLESTR pszDestFileName);


void __RPC_STUB IServerConnection_CheckFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnection_GetSystemInfo_Proxy( 
    IServerConnection * This,
    /* [out] */ LPWORD pwArchitecture,
    /* [out] */ LPDWORD pdwCPUType,
    /* [out] */ LPWORD pwMinorVersion,
    /* [out] */ LPWORD pwMajorVersion);


void __RPC_STUB IServerConnection_GetSystemInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnection_Copy_Proxy( 
    IServerConnection * This,
    /* [in] */ LPCOLESTR pszSrcFullPath,
    /* [in] */ LPCOLESTR pszDestFileName);


void __RPC_STUB IServerConnection_Copy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnection_Launch_Proxy( 
    IServerConnection * This,
    /* [in] */ LPCOLESTR pszExeName,
    /* [in] */ LPCOLESTR pszCmdLine);


void __RPC_STUB IServerConnection_Launch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IServerConnection_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_server_0316 */
/* [local] */ 

#define FILL_TIMESTAMP			0x00000001
#define FILL_MACHINETYPE			0x00000002
#define FILL_CHARACTERISTICS		0x00000004
#define FILL_ENTRYPOINT			0x00000100
#define FILL_OSVERSION			0x00000200
#define FILL_SUBSYSTEM			0x00000400
#define FILL_SUBSYSTEMVERSION	0x00000800
#define FILL_CHECKSUM			0x00001000
#define LOAD_IFH					0x000000FF
#define LOAD_OPTIONAL			0x0000FF00
typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_server_0316_0001
    {
    DWORD PleaseFill;
    DWORD DidFill;
    DWORD Timestamp;
    WORD Machine;
    WORD Characteristics;
    DWORD EntryPoint;
    DWORD OsVersion;
    WORD Subsystem;
    DWORD SubsystemVersion;
    DWORD Checksum;
    } 	EXEINFO;



extern RPC_IF_HANDLE __MIDL_itf_server_0316_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_server_0316_v0_0_s_ifspec;

#ifndef __IServerConnectionEx_INTERFACE_DEFINED__
#define __IServerConnectionEx_INTERFACE_DEFINED__

/* interface IServerConnectionEx */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IServerConnectionEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("66C1CB98-E7EE-11d2-BBEC-00A0C9C9CCEE")
    IServerConnectionEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetServerFlags( 
            /* [out] */ LPDWORD pdwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FileCopy( 
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDest,
            /* [in] */ ICallBack *piCallBack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FileGetInfo( 
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [out] */ LPDWORD pdwFileAttributes,
            /* [out] */ LPDWORD pdwFileSize,
            /* [out] */ LPFILETIME pCreationTime,
            /* [out] */ LPDWORD pdwTimeDateStamp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFreeStoreSpace( 
            /* [out] */ LPDWORD pdwFree) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRemoteExeInfo( 
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [out][in] */ EXEINFO *pExeInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServerConnectionExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IServerConnectionEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IServerConnectionEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IServerConnectionEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetServerFlags )( 
            IServerConnectionEx * This,
            /* [out] */ LPDWORD pdwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *FileCopy )( 
            IServerConnectionEx * This,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDest,
            /* [in] */ ICallBack *piCallBack);
        
        HRESULT ( STDMETHODCALLTYPE *FileGetInfo )( 
            IServerConnectionEx * This,
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [out] */ LPDWORD pdwFileAttributes,
            /* [out] */ LPDWORD pdwFileSize,
            /* [out] */ LPFILETIME pCreationTime,
            /* [out] */ LPDWORD pdwTimeDateStamp);
        
        HRESULT ( STDMETHODCALLTYPE *GetFreeStoreSpace )( 
            IServerConnectionEx * This,
            /* [out] */ LPDWORD pdwFree);
        
        HRESULT ( STDMETHODCALLTYPE *GetRemoteExeInfo )( 
            IServerConnectionEx * This,
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [out][in] */ EXEINFO *pExeInfo);
        
        END_INTERFACE
    } IServerConnectionExVtbl;

    interface IServerConnectionEx
    {
        CONST_VTBL struct IServerConnectionExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServerConnectionEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServerConnectionEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServerConnectionEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServerConnectionEx_GetServerFlags(This,pdwFlags)	\
    (This)->lpVtbl -> GetServerFlags(This,pdwFlags)

#define IServerConnectionEx_FileCopy(This,pszSource,pszDest,piCallBack)	\
    (This)->lpVtbl -> FileCopy(This,pszSource,pszDest,piCallBack)

#define IServerConnectionEx_FileGetInfo(This,pszRemotePath,pdwFileAttributes,pdwFileSize,pCreationTime,pdwTimeDateStamp)	\
    (This)->lpVtbl -> FileGetInfo(This,pszRemotePath,pdwFileAttributes,pdwFileSize,pCreationTime,pdwTimeDateStamp)

#define IServerConnectionEx_GetFreeStoreSpace(This,pdwFree)	\
    (This)->lpVtbl -> GetFreeStoreSpace(This,pdwFree)

#define IServerConnectionEx_GetRemoteExeInfo(This,pszRemotePath,pExeInfo)	\
    (This)->lpVtbl -> GetRemoteExeInfo(This,pszRemotePath,pExeInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IServerConnectionEx_GetServerFlags_Proxy( 
    IServerConnectionEx * This,
    /* [out] */ LPDWORD pdwFlags);


void __RPC_STUB IServerConnectionEx_GetServerFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnectionEx_FileCopy_Proxy( 
    IServerConnectionEx * This,
    /* [in] */ LPCOLESTR pszSource,
    /* [in] */ LPCOLESTR pszDest,
    /* [in] */ ICallBack *piCallBack);


void __RPC_STUB IServerConnectionEx_FileCopy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnectionEx_FileGetInfo_Proxy( 
    IServerConnectionEx * This,
    /* [in] */ LPCOLESTR pszRemotePath,
    /* [out] */ LPDWORD pdwFileAttributes,
    /* [out] */ LPDWORD pdwFileSize,
    /* [out] */ LPFILETIME pCreationTime,
    /* [out] */ LPDWORD pdwTimeDateStamp);


void __RPC_STUB IServerConnectionEx_FileGetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnectionEx_GetFreeStoreSpace_Proxy( 
    IServerConnectionEx * This,
    /* [out] */ LPDWORD pdwFree);


void __RPC_STUB IServerConnectionEx_GetFreeStoreSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnectionEx_GetRemoteExeInfo_Proxy( 
    IServerConnectionEx * This,
    /* [in] */ LPCOLESTR pszRemotePath,
    /* [out][in] */ EXEINFO *pExeInfo);


void __RPC_STUB IServerConnectionEx_GetRemoteExeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IServerConnectionEx_INTERFACE_DEFINED__ */


#ifndef __IServerConnectionEx2_INTERFACE_DEFINED__
#define __IServerConnectionEx2_INTERFACE_DEFINED__

/* interface IServerConnectionEx2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IServerConnectionEx2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F764C0AC-BD25-4529-B3CD-4D96EBF561F4")
    IServerConnectionEx2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSystemInfoEx( 
            /* [out] */ LPWORD pwArchitecture,
            /* [out] */ LPDWORD pdwCPUType,
            /* [out] */ LPWORD pwMinorVersion,
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ GUID *OSTypeId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFile( 
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [in] */ LPCOLESTR pszDest,
            /* [in] */ ICallBack *piCallBack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateStream( 
            /* [in] */ GUID HostId,
            /* [in] */ DWORD dwPortId,
            /* [out] */ IConnectionStream **ppiConnectionStream,
            /* [in] */ ICallBack *piCallBack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FileDelete( 
            /* [in] */ LPCOLESTR pszFullPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServerFlags( 
            /* [out] */ LPDWORD pdwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FileCopy( 
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDest,
            /* [in] */ ICallBack *piCallBack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FileGetInfo( 
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [out] */ LPDWORD pdwFileAttributes,
            /* [out] */ LPDWORD pdwFileSize,
            /* [out] */ LPFILETIME pCreationTime,
            /* [out] */ LPDWORD pdwTimeDateStamp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFreeStoreSpace( 
            /* [out] */ LPDWORD pdwFree) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRemoteExeInfo( 
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [out][in] */ EXEINFO *pExeInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Launch( 
            /* [in] */ LPCOLESTR pszExeName,
            /* [full][in] */ LPCOLESTR pszCmdLine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterFile( 
            /* [in] */ LPCOLESTR pszName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServerConnectionEx2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IServerConnectionEx2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IServerConnectionEx2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IServerConnectionEx2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSystemInfoEx )( 
            IServerConnectionEx2 * This,
            /* [out] */ LPWORD pwArchitecture,
            /* [out] */ LPDWORD pdwCPUType,
            /* [out] */ LPWORD pwMinorVersion,
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ GUID *OSTypeId);
        
        HRESULT ( STDMETHODCALLTYPE *GetFile )( 
            IServerConnectionEx2 * This,
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [in] */ LPCOLESTR pszDest,
            /* [in] */ ICallBack *piCallBack);
        
        HRESULT ( STDMETHODCALLTYPE *CreateStream )( 
            IServerConnectionEx2 * This,
            /* [in] */ GUID HostId,
            /* [in] */ DWORD dwPortId,
            /* [out] */ IConnectionStream **ppiConnectionStream,
            /* [in] */ ICallBack *piCallBack);
        
        HRESULT ( STDMETHODCALLTYPE *FileDelete )( 
            IServerConnectionEx2 * This,
            /* [in] */ LPCOLESTR pszFullPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetServerFlags )( 
            IServerConnectionEx2 * This,
            /* [out] */ LPDWORD pdwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *FileCopy )( 
            IServerConnectionEx2 * This,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDest,
            /* [in] */ ICallBack *piCallBack);
        
        HRESULT ( STDMETHODCALLTYPE *FileGetInfo )( 
            IServerConnectionEx2 * This,
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [out] */ LPDWORD pdwFileAttributes,
            /* [out] */ LPDWORD pdwFileSize,
            /* [out] */ LPFILETIME pCreationTime,
            /* [out] */ LPDWORD pdwTimeDateStamp);
        
        HRESULT ( STDMETHODCALLTYPE *GetFreeStoreSpace )( 
            IServerConnectionEx2 * This,
            /* [out] */ LPDWORD pdwFree);
        
        HRESULT ( STDMETHODCALLTYPE *GetRemoteExeInfo )( 
            IServerConnectionEx2 * This,
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [out][in] */ EXEINFO *pExeInfo);
        
        HRESULT ( STDMETHODCALLTYPE *Launch )( 
            IServerConnectionEx2 * This,
            /* [in] */ LPCOLESTR pszExeName,
            /* [full][in] */ LPCOLESTR pszCmdLine);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterFile )( 
            IServerConnectionEx2 * This,
            /* [in] */ LPCOLESTR pszName);
        
        END_INTERFACE
    } IServerConnectionEx2Vtbl;

    interface IServerConnectionEx2
    {
        CONST_VTBL struct IServerConnectionEx2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServerConnectionEx2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServerConnectionEx2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServerConnectionEx2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServerConnectionEx2_GetSystemInfoEx(This,pwArchitecture,pdwCPUType,pwMinorVersion,pwMajorVersion,OSTypeId)	\
    (This)->lpVtbl -> GetSystemInfoEx(This,pwArchitecture,pdwCPUType,pwMinorVersion,pwMajorVersion,OSTypeId)

#define IServerConnectionEx2_GetFile(This,pszRemotePath,pszDest,piCallBack)	\
    (This)->lpVtbl -> GetFile(This,pszRemotePath,pszDest,piCallBack)

#define IServerConnectionEx2_CreateStream(This,HostId,dwPortId,ppiConnectionStream,piCallBack)	\
    (This)->lpVtbl -> CreateStream(This,HostId,dwPortId,ppiConnectionStream,piCallBack)

#define IServerConnectionEx2_FileDelete(This,pszFullPath)	\
    (This)->lpVtbl -> FileDelete(This,pszFullPath)

#define IServerConnectionEx2_GetServerFlags(This,pdwFlags)	\
    (This)->lpVtbl -> GetServerFlags(This,pdwFlags)

#define IServerConnectionEx2_FileCopy(This,pszSource,pszDest,piCallBack)	\
    (This)->lpVtbl -> FileCopy(This,pszSource,pszDest,piCallBack)

#define IServerConnectionEx2_FileGetInfo(This,pszRemotePath,pdwFileAttributes,pdwFileSize,pCreationTime,pdwTimeDateStamp)	\
    (This)->lpVtbl -> FileGetInfo(This,pszRemotePath,pdwFileAttributes,pdwFileSize,pCreationTime,pdwTimeDateStamp)

#define IServerConnectionEx2_GetFreeStoreSpace(This,pdwFree)	\
    (This)->lpVtbl -> GetFreeStoreSpace(This,pdwFree)

#define IServerConnectionEx2_GetRemoteExeInfo(This,pszRemotePath,pExeInfo)	\
    (This)->lpVtbl -> GetRemoteExeInfo(This,pszRemotePath,pExeInfo)

#define IServerConnectionEx2_Launch(This,pszExeName,pszCmdLine)	\
    (This)->lpVtbl -> Launch(This,pszExeName,pszCmdLine)

#define IServerConnectionEx2_RegisterFile(This,pszName)	\
    (This)->lpVtbl -> RegisterFile(This,pszName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IServerConnectionEx2_GetSystemInfoEx_Proxy( 
    IServerConnectionEx2 * This,
    /* [out] */ LPWORD pwArchitecture,
    /* [out] */ LPDWORD pdwCPUType,
    /* [out] */ LPWORD pwMinorVersion,
    /* [out] */ LPWORD pwMajorVersion,
    /* [out] */ GUID *OSTypeId);


void __RPC_STUB IServerConnectionEx2_GetSystemInfoEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnectionEx2_GetFile_Proxy( 
    IServerConnectionEx2 * This,
    /* [in] */ LPCOLESTR pszRemotePath,
    /* [in] */ LPCOLESTR pszDest,
    /* [in] */ ICallBack *piCallBack);


void __RPC_STUB IServerConnectionEx2_GetFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnectionEx2_CreateStream_Proxy( 
    IServerConnectionEx2 * This,
    /* [in] */ GUID HostId,
    /* [in] */ DWORD dwPortId,
    /* [out] */ IConnectionStream **ppiConnectionStream,
    /* [in] */ ICallBack *piCallBack);


void __RPC_STUB IServerConnectionEx2_CreateStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnectionEx2_FileDelete_Proxy( 
    IServerConnectionEx2 * This,
    /* [in] */ LPCOLESTR pszFullPath);


void __RPC_STUB IServerConnectionEx2_FileDelete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnectionEx2_GetServerFlags_Proxy( 
    IServerConnectionEx2 * This,
    /* [out] */ LPDWORD pdwFlags);


void __RPC_STUB IServerConnectionEx2_GetServerFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnectionEx2_FileCopy_Proxy( 
    IServerConnectionEx2 * This,
    /* [in] */ LPCOLESTR pszSource,
    /* [in] */ LPCOLESTR pszDest,
    /* [in] */ ICallBack *piCallBack);


void __RPC_STUB IServerConnectionEx2_FileCopy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnectionEx2_FileGetInfo_Proxy( 
    IServerConnectionEx2 * This,
    /* [in] */ LPCOLESTR pszRemotePath,
    /* [out] */ LPDWORD pdwFileAttributes,
    /* [out] */ LPDWORD pdwFileSize,
    /* [out] */ LPFILETIME pCreationTime,
    /* [out] */ LPDWORD pdwTimeDateStamp);


void __RPC_STUB IServerConnectionEx2_FileGetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnectionEx2_GetFreeStoreSpace_Proxy( 
    IServerConnectionEx2 * This,
    /* [out] */ LPDWORD pdwFree);


void __RPC_STUB IServerConnectionEx2_GetFreeStoreSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnectionEx2_GetRemoteExeInfo_Proxy( 
    IServerConnectionEx2 * This,
    /* [in] */ LPCOLESTR pszRemotePath,
    /* [out][in] */ EXEINFO *pExeInfo);


void __RPC_STUB IServerConnectionEx2_GetRemoteExeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnectionEx2_Launch_Proxy( 
    IServerConnectionEx2 * This,
    /* [in] */ LPCOLESTR pszExeName,
    /* [full][in] */ LPCOLESTR pszCmdLine);


void __RPC_STUB IServerConnectionEx2_Launch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnectionEx2_RegisterFile_Proxy( 
    IServerConnectionEx2 * This,
    /* [in] */ LPCOLESTR pszName);


void __RPC_STUB IServerConnectionEx2_RegisterFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IServerConnectionEx2_INTERFACE_DEFINED__ */


#ifndef __IServerConnectionEx3_INTERFACE_DEFINED__
#define __IServerConnectionEx3_INTERFACE_DEFINED__

/* interface IServerConnectionEx3 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IServerConnectionEx3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("67E498EF-22A7-4506-8176-A4A2E23E46D8")
    IServerConnectionEx3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsDeviceConnected( 
            /* [out] */ BOOL *bConnected) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Shutdown( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServerConnectionEx3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IServerConnectionEx3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IServerConnectionEx3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IServerConnectionEx3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsDeviceConnected )( 
            IServerConnectionEx3 * This,
            /* [out] */ BOOL *bConnected);
        
        HRESULT ( STDMETHODCALLTYPE *Shutdown )( 
            IServerConnectionEx3 * This);
        
        END_INTERFACE
    } IServerConnectionEx3Vtbl;

    interface IServerConnectionEx3
    {
        CONST_VTBL struct IServerConnectionEx3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServerConnectionEx3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServerConnectionEx3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServerConnectionEx3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServerConnectionEx3_IsDeviceConnected(This,bConnected)	\
    (This)->lpVtbl -> IsDeviceConnected(This,bConnected)

#define IServerConnectionEx3_Shutdown(This)	\
    (This)->lpVtbl -> Shutdown(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IServerConnectionEx3_IsDeviceConnected_Proxy( 
    IServerConnectionEx3 * This,
    /* [out] */ BOOL *bConnected);


void __RPC_STUB IServerConnectionEx3_IsDeviceConnected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServerConnectionEx3_Shutdown_Proxy( 
    IServerConnectionEx3 * This);


void __RPC_STUB IServerConnectionEx3_Shutdown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IServerConnectionEx3_INTERFACE_DEFINED__ */


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


