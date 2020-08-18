/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Mon Jun 01 18:48:57 1998
 */
/* Compiler settings for logger.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __log_i_h__
#define __log_i_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ILogger_FWD_DEFINED__
#define __ILogger_FWD_DEFINED__
typedef interface ILogger ILogger;
#endif 	/* __ILogger_FWD_DEFINED__ */


#ifndef __Logger_FWD_DEFINED__
#define __Logger_FWD_DEFINED__

#ifdef __cplusplus
typedef class Logger Logger;
#else
typedef struct Logger Logger;
#endif /* __cplusplus */

#endif 	/* __Logger_FWD_DEFINED__ */


/* header files for imported files */
#include "oleidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __ILogger_INTERFACE_DEFINED__
#define __ILogger_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ILogger
 * at Mon Jun 01 18:48:57 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][uuid][object] */ 



EXTERN_C const IID IID_ILogger;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("ec4e9084-0a91-11d1-ae27-204c4f4f5020")
    ILogger : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Attach( 
            /* [in] */ DWORD dwProcessId,
            /* [in] */ LPOLESTR szProcessName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Detach( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddZone( 
            /* [in] */ DWORD dwZoneId,
            /* [in] */ LPOLESTR szZoneDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Message( 
            /* [in] */ DWORD dwZoneId,
            /* [in] */ LPOLESTR szMsg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Alert( 
            /* [in] */ DWORD dwZoneId,
            /* [in] */ LPOLESTR szMsg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILoggerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ILogger __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ILogger __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ILogger __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Attach )( 
            ILogger __RPC_FAR * This,
            /* [in] */ DWORD dwProcessId,
            /* [in] */ LPOLESTR szProcessName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Detach )( 
            ILogger __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddZone )( 
            ILogger __RPC_FAR * This,
            /* [in] */ DWORD dwZoneId,
            /* [in] */ LPOLESTR szZoneDesc);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Message )( 
            ILogger __RPC_FAR * This,
            /* [in] */ DWORD dwZoneId,
            /* [in] */ LPOLESTR szMsg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Alert )( 
            ILogger __RPC_FAR * This,
            /* [in] */ DWORD dwZoneId,
            /* [in] */ LPOLESTR szMsg);
        
        END_INTERFACE
    } ILoggerVtbl;

    interface ILogger
    {
        CONST_VTBL struct ILoggerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILogger_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILogger_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILogger_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILogger_Attach(This,dwProcessId,szProcessName)	\
    (This)->lpVtbl -> Attach(This,dwProcessId,szProcessName)

#define ILogger_Detach(This)	\
    (This)->lpVtbl -> Detach(This)

#define ILogger_AddZone(This,dwZoneId,szZoneDesc)	\
    (This)->lpVtbl -> AddZone(This,dwZoneId,szZoneDesc)

#define ILogger_Message(This,dwZoneId,szMsg)	\
    (This)->lpVtbl -> Message(This,dwZoneId,szMsg)

#define ILogger_Alert(This,dwZoneId,szMsg)	\
    (This)->lpVtbl -> Alert(This,dwZoneId,szMsg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ILogger_Attach_Proxy( 
    ILogger __RPC_FAR * This,
    /* [in] */ DWORD dwProcessId,
    /* [in] */ LPOLESTR szProcessName);


void __RPC_STUB ILogger_Attach_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ILogger_Detach_Proxy( 
    ILogger __RPC_FAR * This);


void __RPC_STUB ILogger_Detach_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ILogger_AddZone_Proxy( 
    ILogger __RPC_FAR * This,
    /* [in] */ DWORD dwZoneId,
    /* [in] */ LPOLESTR szZoneDesc);


void __RPC_STUB ILogger_AddZone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ILogger_Message_Proxy( 
    ILogger __RPC_FAR * This,
    /* [in] */ DWORD dwZoneId,
    /* [in] */ LPOLESTR szMsg);


void __RPC_STUB ILogger_Message_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ILogger_Alert_Proxy( 
    ILogger __RPC_FAR * This,
    /* [in] */ DWORD dwZoneId,
    /* [in] */ LPOLESTR szMsg);


void __RPC_STUB ILogger_Alert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILogger_INTERFACE_DEFINED__ */



#ifndef __ServerLib_LIBRARY_DEFINED__
#define __ServerLib_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: ServerLib
 * at Mon Jun 01 18:48:57 1998
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_ServerLib;

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_Logger;

class DECLSPEC_UUID("17D93E38-0A98-11d1-AE27-204C4F4F5020")
Logger;
#endif
#endif /* __ServerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
