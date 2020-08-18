

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for vcecominterfaces.idl:
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

#ifndef __vcecominterfaces_h__
#define __vcecominterfaces_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDMATransportCompletionSink_FWD_DEFINED__
#define __IDMATransportCompletionSink_FWD_DEFINED__
typedef interface IDMATransportCompletionSink IDMATransportCompletionSink;
#endif 	/* __IDMATransportCompletionSink_FWD_DEFINED__ */


#ifndef __IEmulatorVirtualMachineManager_FWD_DEFINED__
#define __IEmulatorVirtualMachineManager_FWD_DEFINED__
typedef interface IEmulatorVirtualMachineManager IEmulatorVirtualMachineManager;
#endif 	/* __IEmulatorVirtualMachineManager_FWD_DEFINED__ */


#ifndef __IEmulatorVirtualTransportSink_FWD_DEFINED__
#define __IEmulatorVirtualTransportSink_FWD_DEFINED__
typedef interface IEmulatorVirtualTransportSink IEmulatorVirtualTransportSink;
#endif 	/* __IEmulatorVirtualTransportSink_FWD_DEFINED__ */


#ifndef __IEmulatorVirtualTransport_FWD_DEFINED__
#define __IEmulatorVirtualTransport_FWD_DEFINED__
typedef interface IEmulatorVirtualTransport IEmulatorVirtualTransport;
#endif 	/* __IEmulatorVirtualTransport_FWD_DEFINED__ */


#ifndef __EmulatorVirtualMachineManager_FWD_DEFINED__
#define __EmulatorVirtualMachineManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class EmulatorVirtualMachineManager EmulatorVirtualMachineManager;
#else
typedef struct EmulatorVirtualMachineManager EmulatorVirtualMachineManager;
#endif /* __cplusplus */

#endif 	/* __EmulatorVirtualMachineManager_FWD_DEFINED__ */


#ifndef __EmulatorVirtualTransport_FWD_DEFINED__
#define __EmulatorVirtualTransport_FWD_DEFINED__

#ifdef __cplusplus
typedef class EmulatorVirtualTransport EmulatorVirtualTransport;
#else
typedef struct EmulatorVirtualTransport EmulatorVirtualTransport;
#endif /* __cplusplus */

#endif 	/* __EmulatorVirtualTransport_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_vcecominterfaces_0000 */
/* [local] */ 

const ULONG kVCETypeLibrary_MajorVersion = 1;
const ULONG kVCETypeLibrary_MinorVersion = 0;


extern RPC_IF_HANDLE __MIDL_itf_vcecominterfaces_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vcecominterfaces_0000_v0_0_s_ifspec;

#ifndef __IDMATransportCompletionSink_INTERFACE_DEFINED__
#define __IDMATransportCompletionSink_INTERFACE_DEFINED__

/* interface IDMATransportCompletionSink */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDMATransportCompletionSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AC6A6347-ECE0-46c1-B668-9DF3A17153C8")
    IDMATransportCompletionSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompletionCallback( 
            /* [in] */ DWORD stage) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDMATransportCompletionSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDMATransportCompletionSink * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDMATransportCompletionSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDMATransportCompletionSink * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompletionCallback )( 
            IDMATransportCompletionSink * This,
            /* [in] */ DWORD stage);
        
        END_INTERFACE
    } IDMATransportCompletionSinkVtbl;

    interface IDMATransportCompletionSink
    {
        CONST_VTBL struct IDMATransportCompletionSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDMATransportCompletionSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDMATransportCompletionSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDMATransportCompletionSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDMATransportCompletionSink_CompletionCallback(This,stage)	\
    (This)->lpVtbl -> CompletionCallback(This,stage)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDMATransportCompletionSink_CompletionCallback_Proxy( 
    IDMATransportCompletionSink * This,
    /* [in] */ DWORD stage);


void __RPC_STUB IDMATransportCompletionSink_CompletionCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDMATransportCompletionSink_INTERFACE_DEFINED__ */


#ifndef __IEmulatorVirtualMachineManager_INTERFACE_DEFINED__
#define __IEmulatorVirtualMachineManager_INTERFACE_DEFINED__

/* interface IEmulatorVirtualMachineManager */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEmulatorVirtualMachineManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("71D756A3-B729-472b-9C90-12F393A9BFF8")
    IEmulatorVirtualMachineManager : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetVirtualMachineCount( 
            /* [retval][out] */ ULONG *numberOfVMs) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnumerateVirtualMachines( 
            /* [out][in] */ ULONG *numberOfVMs,
            /* [size_is][out] */ GUID virtualMachineID[  ]) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsVirtualMachineRunning( 
            /* [in] */ GUID *virtualMachineID,
            /* [retval][out] */ boolean *isRunning) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ResetVirtualMachine( 
            /* [in] */ GUID *virtualMachineID,
            /* [in] */ boolean hardReset) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateVirtualMachine( 
            /* [in] */ LPOLESTR commandLine) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateVirtualMachineWithTransportCompletion( 
            /* [in] */ LPOLESTR commandLine,
            /* [in] */ IDMATransportCompletionSink *completionSink,
            /* [in] */ DWORD dmaTransportCompletionRoutineIdentifier) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ShutdownVirtualMachine( 
            /* [in] */ GUID *virtualMachineID,
            /* [in] */ boolean saveMachine) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RestoreVirtualMachine( 
            /* [in] */ GUID *virtualMachineID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RestoreVirtualMachineWithTransportCompletion( 
            /* [in] */ GUID *virtualMachineID,
            /* [in] */ IDMATransportCompletionSink *completionSink,
            /* [in] */ DWORD dmaTransportCompletionRoutineIdentifier) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteVirtualMachine( 
            /* [in] */ GUID *virtualMachineID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetVirtualMachineName( 
            /* [in] */ GUID *virtualMachineID,
            /* [out] */ LPOLESTR *virtualMachineName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetVirtualMachineName( 
            /* [in] */ GUID *virtualMachineID,
            /* [in] */ LPOLESTR virtualMachineName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE UninstallVirtualMachineDMATransportCompletionRoutine( 
            /* [in] */ GUID *inVirtualMachineID,
            /* [in] */ DWORD inId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BringVirtualMachineToFront( 
            /* [in] */ GUID *virtualMachineID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE VirtualMachineManagerVersion( 
            /* [out] */ DWORD *version) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEmulatorVirtualMachineManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEmulatorVirtualMachineManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEmulatorVirtualMachineManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEmulatorVirtualMachineManager * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetVirtualMachineCount )( 
            IEmulatorVirtualMachineManager * This,
            /* [retval][out] */ ULONG *numberOfVMs);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumerateVirtualMachines )( 
            IEmulatorVirtualMachineManager * This,
            /* [out][in] */ ULONG *numberOfVMs,
            /* [size_is][out] */ GUID virtualMachineID[  ]);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsVirtualMachineRunning )( 
            IEmulatorVirtualMachineManager * This,
            /* [in] */ GUID *virtualMachineID,
            /* [retval][out] */ boolean *isRunning);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ResetVirtualMachine )( 
            IEmulatorVirtualMachineManager * This,
            /* [in] */ GUID *virtualMachineID,
            /* [in] */ boolean hardReset);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateVirtualMachine )( 
            IEmulatorVirtualMachineManager * This,
            /* [in] */ LPOLESTR commandLine);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateVirtualMachineWithTransportCompletion )( 
            IEmulatorVirtualMachineManager * This,
            /* [in] */ LPOLESTR commandLine,
            /* [in] */ IDMATransportCompletionSink *completionSink,
            /* [in] */ DWORD dmaTransportCompletionRoutineIdentifier);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ShutdownVirtualMachine )( 
            IEmulatorVirtualMachineManager * This,
            /* [in] */ GUID *virtualMachineID,
            /* [in] */ boolean saveMachine);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RestoreVirtualMachine )( 
            IEmulatorVirtualMachineManager * This,
            /* [in] */ GUID *virtualMachineID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RestoreVirtualMachineWithTransportCompletion )( 
            IEmulatorVirtualMachineManager * This,
            /* [in] */ GUID *virtualMachineID,
            /* [in] */ IDMATransportCompletionSink *completionSink,
            /* [in] */ DWORD dmaTransportCompletionRoutineIdentifier);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DeleteVirtualMachine )( 
            IEmulatorVirtualMachineManager * This,
            /* [in] */ GUID *virtualMachineID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetVirtualMachineName )( 
            IEmulatorVirtualMachineManager * This,
            /* [in] */ GUID *virtualMachineID,
            /* [out] */ LPOLESTR *virtualMachineName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetVirtualMachineName )( 
            IEmulatorVirtualMachineManager * This,
            /* [in] */ GUID *virtualMachineID,
            /* [in] */ LPOLESTR virtualMachineName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *UninstallVirtualMachineDMATransportCompletionRoutine )( 
            IEmulatorVirtualMachineManager * This,
            /* [in] */ GUID *inVirtualMachineID,
            /* [in] */ DWORD inId);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *BringVirtualMachineToFront )( 
            IEmulatorVirtualMachineManager * This,
            /* [in] */ GUID *virtualMachineID);
        
        HRESULT ( STDMETHODCALLTYPE *VirtualMachineManagerVersion )( 
            IEmulatorVirtualMachineManager * This,
            /* [out] */ DWORD *version);
        
        END_INTERFACE
    } IEmulatorVirtualMachineManagerVtbl;

    interface IEmulatorVirtualMachineManager
    {
        CONST_VTBL struct IEmulatorVirtualMachineManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEmulatorVirtualMachineManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEmulatorVirtualMachineManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEmulatorVirtualMachineManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEmulatorVirtualMachineManager_GetVirtualMachineCount(This,numberOfVMs)	\
    (This)->lpVtbl -> GetVirtualMachineCount(This,numberOfVMs)

#define IEmulatorVirtualMachineManager_EnumerateVirtualMachines(This,numberOfVMs,virtualMachineID)	\
    (This)->lpVtbl -> EnumerateVirtualMachines(This,numberOfVMs,virtualMachineID)

#define IEmulatorVirtualMachineManager_IsVirtualMachineRunning(This,virtualMachineID,isRunning)	\
    (This)->lpVtbl -> IsVirtualMachineRunning(This,virtualMachineID,isRunning)

#define IEmulatorVirtualMachineManager_ResetVirtualMachine(This,virtualMachineID,hardReset)	\
    (This)->lpVtbl -> ResetVirtualMachine(This,virtualMachineID,hardReset)

#define IEmulatorVirtualMachineManager_CreateVirtualMachine(This,commandLine)	\
    (This)->lpVtbl -> CreateVirtualMachine(This,commandLine)

#define IEmulatorVirtualMachineManager_CreateVirtualMachineWithTransportCompletion(This,commandLine,completionSink,dmaTransportCompletionRoutineIdentifier)	\
    (This)->lpVtbl -> CreateVirtualMachineWithTransportCompletion(This,commandLine,completionSink,dmaTransportCompletionRoutineIdentifier)

#define IEmulatorVirtualMachineManager_ShutdownVirtualMachine(This,virtualMachineID,saveMachine)	\
    (This)->lpVtbl -> ShutdownVirtualMachine(This,virtualMachineID,saveMachine)

#define IEmulatorVirtualMachineManager_RestoreVirtualMachine(This,virtualMachineID)	\
    (This)->lpVtbl -> RestoreVirtualMachine(This,virtualMachineID)

#define IEmulatorVirtualMachineManager_RestoreVirtualMachineWithTransportCompletion(This,virtualMachineID,completionSink,dmaTransportCompletionRoutineIdentifier)	\
    (This)->lpVtbl -> RestoreVirtualMachineWithTransportCompletion(This,virtualMachineID,completionSink,dmaTransportCompletionRoutineIdentifier)

#define IEmulatorVirtualMachineManager_DeleteVirtualMachine(This,virtualMachineID)	\
    (This)->lpVtbl -> DeleteVirtualMachine(This,virtualMachineID)

#define IEmulatorVirtualMachineManager_GetVirtualMachineName(This,virtualMachineID,virtualMachineName)	\
    (This)->lpVtbl -> GetVirtualMachineName(This,virtualMachineID,virtualMachineName)

#define IEmulatorVirtualMachineManager_SetVirtualMachineName(This,virtualMachineID,virtualMachineName)	\
    (This)->lpVtbl -> SetVirtualMachineName(This,virtualMachineID,virtualMachineName)

#define IEmulatorVirtualMachineManager_UninstallVirtualMachineDMATransportCompletionRoutine(This,inVirtualMachineID,inId)	\
    (This)->lpVtbl -> UninstallVirtualMachineDMATransportCompletionRoutine(This,inVirtualMachineID,inId)

#define IEmulatorVirtualMachineManager_BringVirtualMachineToFront(This,virtualMachineID)	\
    (This)->lpVtbl -> BringVirtualMachineToFront(This,virtualMachineID)

#define IEmulatorVirtualMachineManager_VirtualMachineManagerVersion(This,version)	\
    (This)->lpVtbl -> VirtualMachineManagerVersion(This,version)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualMachineManager_GetVirtualMachineCount_Proxy( 
    IEmulatorVirtualMachineManager * This,
    /* [retval][out] */ ULONG *numberOfVMs);


void __RPC_STUB IEmulatorVirtualMachineManager_GetVirtualMachineCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualMachineManager_EnumerateVirtualMachines_Proxy( 
    IEmulatorVirtualMachineManager * This,
    /* [out][in] */ ULONG *numberOfVMs,
    /* [size_is][out] */ GUID virtualMachineID[  ]);


void __RPC_STUB IEmulatorVirtualMachineManager_EnumerateVirtualMachines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualMachineManager_IsVirtualMachineRunning_Proxy( 
    IEmulatorVirtualMachineManager * This,
    /* [in] */ GUID *virtualMachineID,
    /* [retval][out] */ boolean *isRunning);


void __RPC_STUB IEmulatorVirtualMachineManager_IsVirtualMachineRunning_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualMachineManager_ResetVirtualMachine_Proxy( 
    IEmulatorVirtualMachineManager * This,
    /* [in] */ GUID *virtualMachineID,
    /* [in] */ boolean hardReset);


void __RPC_STUB IEmulatorVirtualMachineManager_ResetVirtualMachine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualMachineManager_CreateVirtualMachine_Proxy( 
    IEmulatorVirtualMachineManager * This,
    /* [in] */ LPOLESTR commandLine);


void __RPC_STUB IEmulatorVirtualMachineManager_CreateVirtualMachine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualMachineManager_CreateVirtualMachineWithTransportCompletion_Proxy( 
    IEmulatorVirtualMachineManager * This,
    /* [in] */ LPOLESTR commandLine,
    /* [in] */ IDMATransportCompletionSink *completionSink,
    /* [in] */ DWORD dmaTransportCompletionRoutineIdentifier);


void __RPC_STUB IEmulatorVirtualMachineManager_CreateVirtualMachineWithTransportCompletion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualMachineManager_ShutdownVirtualMachine_Proxy( 
    IEmulatorVirtualMachineManager * This,
    /* [in] */ GUID *virtualMachineID,
    /* [in] */ boolean saveMachine);


void __RPC_STUB IEmulatorVirtualMachineManager_ShutdownVirtualMachine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualMachineManager_RestoreVirtualMachine_Proxy( 
    IEmulatorVirtualMachineManager * This,
    /* [in] */ GUID *virtualMachineID);


void __RPC_STUB IEmulatorVirtualMachineManager_RestoreVirtualMachine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualMachineManager_RestoreVirtualMachineWithTransportCompletion_Proxy( 
    IEmulatorVirtualMachineManager * This,
    /* [in] */ GUID *virtualMachineID,
    /* [in] */ IDMATransportCompletionSink *completionSink,
    /* [in] */ DWORD dmaTransportCompletionRoutineIdentifier);


void __RPC_STUB IEmulatorVirtualMachineManager_RestoreVirtualMachineWithTransportCompletion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualMachineManager_DeleteVirtualMachine_Proxy( 
    IEmulatorVirtualMachineManager * This,
    /* [in] */ GUID *virtualMachineID);


void __RPC_STUB IEmulatorVirtualMachineManager_DeleteVirtualMachine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualMachineManager_GetVirtualMachineName_Proxy( 
    IEmulatorVirtualMachineManager * This,
    /* [in] */ GUID *virtualMachineID,
    /* [out] */ LPOLESTR *virtualMachineName);


void __RPC_STUB IEmulatorVirtualMachineManager_GetVirtualMachineName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualMachineManager_SetVirtualMachineName_Proxy( 
    IEmulatorVirtualMachineManager * This,
    /* [in] */ GUID *virtualMachineID,
    /* [in] */ LPOLESTR virtualMachineName);


void __RPC_STUB IEmulatorVirtualMachineManager_SetVirtualMachineName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualMachineManager_UninstallVirtualMachineDMATransportCompletionRoutine_Proxy( 
    IEmulatorVirtualMachineManager * This,
    /* [in] */ GUID *inVirtualMachineID,
    /* [in] */ DWORD inId);


void __RPC_STUB IEmulatorVirtualMachineManager_UninstallVirtualMachineDMATransportCompletionRoutine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualMachineManager_BringVirtualMachineToFront_Proxy( 
    IEmulatorVirtualMachineManager * This,
    /* [in] */ GUID *virtualMachineID);


void __RPC_STUB IEmulatorVirtualMachineManager_BringVirtualMachineToFront_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEmulatorVirtualMachineManager_VirtualMachineManagerVersion_Proxy( 
    IEmulatorVirtualMachineManager * This,
    /* [out] */ DWORD *version);


void __RPC_STUB IEmulatorVirtualMachineManager_VirtualMachineManagerVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEmulatorVirtualMachineManager_INTERFACE_DEFINED__ */


#ifndef __IEmulatorVirtualTransportSink_INTERFACE_DEFINED__
#define __IEmulatorVirtualTransportSink_INTERFACE_DEFINED__

/* interface IEmulatorVirtualTransportSink */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEmulatorVirtualTransportSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6747A265-2720-4c36-B778-51CD2D10524A")
    IEmulatorVirtualTransportSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ReceiveData( 
            /* [in] */ ULONG transportID,
            /* [size_is][in] */ const BYTE *dataBuffer,
            /* [in] */ USHORT byteCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEmulatorVirtualTransportSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEmulatorVirtualTransportSink * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEmulatorVirtualTransportSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEmulatorVirtualTransportSink * This);
        
        HRESULT ( STDMETHODCALLTYPE *ReceiveData )( 
            IEmulatorVirtualTransportSink * This,
            /* [in] */ ULONG transportID,
            /* [size_is][in] */ const BYTE *dataBuffer,
            /* [in] */ USHORT byteCount);
        
        END_INTERFACE
    } IEmulatorVirtualTransportSinkVtbl;

    interface IEmulatorVirtualTransportSink
    {
        CONST_VTBL struct IEmulatorVirtualTransportSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEmulatorVirtualTransportSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEmulatorVirtualTransportSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEmulatorVirtualTransportSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEmulatorVirtualTransportSink_ReceiveData(This,transportID,dataBuffer,byteCount)	\
    (This)->lpVtbl -> ReceiveData(This,transportID,dataBuffer,byteCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEmulatorVirtualTransportSink_ReceiveData_Proxy( 
    IEmulatorVirtualTransportSink * This,
    /* [in] */ ULONG transportID,
    /* [size_is][in] */ const BYTE *dataBuffer,
    /* [in] */ USHORT byteCount);


void __RPC_STUB IEmulatorVirtualTransportSink_ReceiveData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEmulatorVirtualTransportSink_INTERFACE_DEFINED__ */


#ifndef __IEmulatorVirtualTransport_INTERFACE_DEFINED__
#define __IEmulatorVirtualTransport_INTERFACE_DEFINED__

/* interface IEmulatorVirtualTransport */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEmulatorVirtualTransport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F3D1162F-B815-4ae4-8C86-DC4A95FB3882")
    IEmulatorVirtualTransport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TearDown( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ GUID *virtualMachineID,
            /* [in] */ ULONG dmaChannel,
            /* [out] */ ULONG *transportID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ ULONG transportID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Advise( 
            /* [in] */ IEmulatorVirtualTransportSink *transportSink) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Send( 
            /* [in] */ ULONG transportID,
            /* [size_is][in] */ const BYTE *dataBuffer,
            /* [in] */ USHORT byteCount,
            /* [in] */ ULONG timeout) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Receive( 
            /* [in] */ ULONG transportID,
            /* [length_is][size_is][out] */ BYTE *dataBuffer,
            /* [out][in] */ USHORT *byteCount,
            /* [in] */ ULONG timeout) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetVirtualMachineIDForTransport( 
            /* [in] */ ULONG transportID,
            /* [in] */ GUID *virtualMachineID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEmulatorVirtualTransportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEmulatorVirtualTransport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEmulatorVirtualTransport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEmulatorVirtualTransport * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IEmulatorVirtualTransport * This);
        
        HRESULT ( STDMETHODCALLTYPE *TearDown )( 
            IEmulatorVirtualTransport * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Create )( 
            IEmulatorVirtualTransport * This,
            /* [in] */ GUID *virtualMachineID,
            /* [in] */ ULONG dmaChannel,
            /* [out] */ ULONG *transportID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IEmulatorVirtualTransport * This,
            /* [in] */ ULONG transportID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Advise )( 
            IEmulatorVirtualTransport * This,
            /* [in] */ IEmulatorVirtualTransportSink *transportSink);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Send )( 
            IEmulatorVirtualTransport * This,
            /* [in] */ ULONG transportID,
            /* [size_is][in] */ const BYTE *dataBuffer,
            /* [in] */ USHORT byteCount,
            /* [in] */ ULONG timeout);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Receive )( 
            IEmulatorVirtualTransport * This,
            /* [in] */ ULONG transportID,
            /* [length_is][size_is][out] */ BYTE *dataBuffer,
            /* [out][in] */ USHORT *byteCount,
            /* [in] */ ULONG timeout);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetVirtualMachineIDForTransport )( 
            IEmulatorVirtualTransport * This,
            /* [in] */ ULONG transportID,
            /* [in] */ GUID *virtualMachineID);
        
        END_INTERFACE
    } IEmulatorVirtualTransportVtbl;

    interface IEmulatorVirtualTransport
    {
        CONST_VTBL struct IEmulatorVirtualTransportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEmulatorVirtualTransport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEmulatorVirtualTransport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEmulatorVirtualTransport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEmulatorVirtualTransport_Initialize(This)	\
    (This)->lpVtbl -> Initialize(This)

#define IEmulatorVirtualTransport_TearDown(This)	\
    (This)->lpVtbl -> TearDown(This)

#define IEmulatorVirtualTransport_Create(This,virtualMachineID,dmaChannel,transportID)	\
    (This)->lpVtbl -> Create(This,virtualMachineID,dmaChannel,transportID)

#define IEmulatorVirtualTransport_Delete(This,transportID)	\
    (This)->lpVtbl -> Delete(This,transportID)

#define IEmulatorVirtualTransport_Advise(This,transportSink)	\
    (This)->lpVtbl -> Advise(This,transportSink)

#define IEmulatorVirtualTransport_Send(This,transportID,dataBuffer,byteCount,timeout)	\
    (This)->lpVtbl -> Send(This,transportID,dataBuffer,byteCount,timeout)

#define IEmulatorVirtualTransport_Receive(This,transportID,dataBuffer,byteCount,timeout)	\
    (This)->lpVtbl -> Receive(This,transportID,dataBuffer,byteCount,timeout)

#define IEmulatorVirtualTransport_SetVirtualMachineIDForTransport(This,transportID,virtualMachineID)	\
    (This)->lpVtbl -> SetVirtualMachineIDForTransport(This,transportID,virtualMachineID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEmulatorVirtualTransport_Initialize_Proxy( 
    IEmulatorVirtualTransport * This);


void __RPC_STUB IEmulatorVirtualTransport_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEmulatorVirtualTransport_TearDown_Proxy( 
    IEmulatorVirtualTransport * This);


void __RPC_STUB IEmulatorVirtualTransport_TearDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualTransport_Create_Proxy( 
    IEmulatorVirtualTransport * This,
    /* [in] */ GUID *virtualMachineID,
    /* [in] */ ULONG dmaChannel,
    /* [out] */ ULONG *transportID);


void __RPC_STUB IEmulatorVirtualTransport_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualTransport_Delete_Proxy( 
    IEmulatorVirtualTransport * This,
    /* [in] */ ULONG transportID);


void __RPC_STUB IEmulatorVirtualTransport_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualTransport_Advise_Proxy( 
    IEmulatorVirtualTransport * This,
    /* [in] */ IEmulatorVirtualTransportSink *transportSink);


void __RPC_STUB IEmulatorVirtualTransport_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualTransport_Send_Proxy( 
    IEmulatorVirtualTransport * This,
    /* [in] */ ULONG transportID,
    /* [size_is][in] */ const BYTE *dataBuffer,
    /* [in] */ USHORT byteCount,
    /* [in] */ ULONG timeout);


void __RPC_STUB IEmulatorVirtualTransport_Send_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualTransport_Receive_Proxy( 
    IEmulatorVirtualTransport * This,
    /* [in] */ ULONG transportID,
    /* [length_is][size_is][out] */ BYTE *dataBuffer,
    /* [out][in] */ USHORT *byteCount,
    /* [in] */ ULONG timeout);


void __RPC_STUB IEmulatorVirtualTransport_Receive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEmulatorVirtualTransport_SetVirtualMachineIDForTransport_Proxy( 
    IEmulatorVirtualTransport * This,
    /* [in] */ ULONG transportID,
    /* [in] */ GUID *virtualMachineID);


void __RPC_STUB IEmulatorVirtualTransport_SetVirtualMachineIDForTransport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEmulatorVirtualTransport_INTERFACE_DEFINED__ */



#ifndef __VirtualCE_LIBRARY_DEFINED__
#define __VirtualCE_LIBRARY_DEFINED__

/* library VirtualCE */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_VirtualCE;

EXTERN_C const CLSID CLSID_EmulatorVirtualMachineManager;

#ifdef __cplusplus

class DECLSPEC_UUID("98BBBEB9-4A0C-43c1-8D83-A958EAD99778")
EmulatorVirtualMachineManager;
#endif

EXTERN_C const CLSID CLSID_EmulatorVirtualTransport;

#ifdef __cplusplus

class DECLSPEC_UUID("35A9592F-C618-4b79-8080-BC3FCCAC86F6")
EmulatorVirtualTransport;
#endif
#endif /* __VirtualCE_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


