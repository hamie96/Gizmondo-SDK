

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for cemgr.idl:
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

#ifndef __cemgr_h__
#define __cemgr_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPlatformManager_FWD_DEFINED__
#define __IPlatformManager_FWD_DEFINED__
typedef interface IPlatformManager IPlatformManager;
#endif 	/* __IPlatformManager_FWD_DEFINED__ */


#ifndef __IPlatformManager2_FWD_DEFINED__
#define __IPlatformManager2_FWD_DEFINED__
typedef interface IPlatformManager2 IPlatformManager2;
#endif 	/* __IPlatformManager2_FWD_DEFINED__ */


#ifndef __IPlatformManager3_FWD_DEFINED__
#define __IPlatformManager3_FWD_DEFINED__
typedef interface IPlatformManager3 IPlatformManager3;
#endif 	/* __IPlatformManager3_FWD_DEFINED__ */


#ifndef __IEnumServiceCategory_FWD_DEFINED__
#define __IEnumServiceCategory_FWD_DEFINED__
typedef interface IEnumServiceCategory IEnumServiceCategory;
#endif 	/* __IEnumServiceCategory_FWD_DEFINED__ */


#ifndef __IServiceCategory_FWD_DEFINED__
#define __IServiceCategory_FWD_DEFINED__
typedef interface IServiceCategory IServiceCategory;
#endif 	/* __IServiceCategory_FWD_DEFINED__ */


#ifndef __IEnumServiceInfo_FWD_DEFINED__
#define __IEnumServiceInfo_FWD_DEFINED__
typedef interface IEnumServiceInfo IEnumServiceInfo;
#endif 	/* __IEnumServiceInfo_FWD_DEFINED__ */


#ifndef __IServiceInfo_FWD_DEFINED__
#define __IServiceInfo_FWD_DEFINED__
typedef interface IServiceInfo IServiceInfo;
#endif 	/* __IServiceInfo_FWD_DEFINED__ */


#ifndef __IEnumBootableDevice_FWD_DEFINED__
#define __IEnumBootableDevice_FWD_DEFINED__
typedef interface IEnumBootableDevice IEnumBootableDevice;
#endif 	/* __IEnumBootableDevice_FWD_DEFINED__ */


#ifndef __IBootableDevice_FWD_DEFINED__
#define __IBootableDevice_FWD_DEFINED__
typedef interface IBootableDevice IBootableDevice;
#endif 	/* __IBootableDevice_FWD_DEFINED__ */


#ifndef __IService_FWD_DEFINED__
#define __IService_FWD_DEFINED__
typedef interface IService IService;
#endif 	/* __IService_FWD_DEFINED__ */


#ifndef __IPMServiceNuke_FWD_DEFINED__
#define __IPMServiceNuke_FWD_DEFINED__
typedef interface IPMServiceNuke IPMServiceNuke;
#endif 	/* __IPMServiceNuke_FWD_DEFINED__ */


#ifndef __IServiceConfig_FWD_DEFINED__
#define __IServiceConfig_FWD_DEFINED__
typedef interface IServiceConfig IServiceConfig;
#endif 	/* __IServiceConfig_FWD_DEFINED__ */


#ifndef __IEnumPlatformCE_FWD_DEFINED__
#define __IEnumPlatformCE_FWD_DEFINED__
typedef interface IEnumPlatformCE IEnumPlatformCE;
#endif 	/* __IEnumPlatformCE_FWD_DEFINED__ */


#ifndef __IPlatformCE_FWD_DEFINED__
#define __IPlatformCE_FWD_DEFINED__
typedef interface IPlatformCE IPlatformCE;
#endif 	/* __IPlatformCE_FWD_DEFINED__ */


#ifndef __IRemoteDevice_FWD_DEFINED__
#define __IRemoteDevice_FWD_DEFINED__
typedef interface IRemoteDevice IRemoteDevice;
#endif 	/* __IRemoteDevice_FWD_DEFINED__ */


#ifndef __IRemoteDevice2_FWD_DEFINED__
#define __IRemoteDevice2_FWD_DEFINED__
typedef interface IRemoteDevice2 IRemoteDevice2;
#endif 	/* __IRemoteDevice2_FWD_DEFINED__ */


#ifndef __IEnumDevice_FWD_DEFINED__
#define __IEnumDevice_FWD_DEFINED__
typedef interface IEnumDevice IEnumDevice;
#endif 	/* __IEnumDevice_FWD_DEFINED__ */


#ifndef __IEnumProperty_FWD_DEFINED__
#define __IEnumProperty_FWD_DEFINED__
typedef interface IEnumProperty IEnumProperty;
#endif 	/* __IEnumProperty_FWD_DEFINED__ */


#ifndef __IProperty_FWD_DEFINED__
#define __IProperty_FWD_DEFINED__
typedef interface IProperty IProperty;
#endif 	/* __IProperty_FWD_DEFINED__ */


#ifndef __IEnumPropInfo_FWD_DEFINED__
#define __IEnumPropInfo_FWD_DEFINED__
typedef interface IEnumPropInfo IEnumPropInfo;
#endif 	/* __IEnumPropInfo_FWD_DEFINED__ */


#ifndef __IConnection_FWD_DEFINED__
#define __IConnection_FWD_DEFINED__
typedef interface IConnection IConnection;
#endif 	/* __IConnection_FWD_DEFINED__ */


#ifndef __IConnection2_FWD_DEFINED__
#define __IConnection2_FWD_DEFINED__
typedef interface IConnection2 IConnection2;
#endif 	/* __IConnection2_FWD_DEFINED__ */


#ifndef __IConnectionStream_FWD_DEFINED__
#define __IConnectionStream_FWD_DEFINED__
typedef interface IConnectionStream IConnectionStream;
#endif 	/* __IConnectionStream_FWD_DEFINED__ */


#ifndef __IConnectionStream2_FWD_DEFINED__
#define __IConnectionStream2_FWD_DEFINED__
typedef interface IConnectionStream2 IConnectionStream2;
#endif 	/* __IConnectionStream2_FWD_DEFINED__ */


#ifndef __ICallBack_FWD_DEFINED__
#define __ICallBack_FWD_DEFINED__
typedef interface ICallBack ICallBack;
#endif 	/* __ICallBack_FWD_DEFINED__ */


#ifndef __IPlatManCallback2_FWD_DEFINED__
#define __IPlatManCallback2_FWD_DEFINED__
typedef interface IPlatManCallback2 IPlatManCallback2;
#endif 	/* __IPlatManCallback2_FWD_DEFINED__ */


#ifndef __IPlatformManagerConfig_FWD_DEFINED__
#define __IPlatformManagerConfig_FWD_DEFINED__
typedef interface IPlatformManagerConfig IPlatformManagerConfig;
#endif 	/* __IPlatformManagerConfig_FWD_DEFINED__ */


#ifndef __IPlatformManagerConfig2_FWD_DEFINED__
#define __IPlatformManagerConfig2_FWD_DEFINED__
typedef interface IPlatformManagerConfig2 IPlatformManagerConfig2;
#endif 	/* __IPlatformManagerConfig2_FWD_DEFINED__ */


#ifndef __IPlatformManagerConfig3_FWD_DEFINED__
#define __IPlatformManagerConfig3_FWD_DEFINED__
typedef interface IPlatformManagerConfig3 IPlatformManagerConfig3;
#endif 	/* __IPlatformManagerConfig3_FWD_DEFINED__ */


#ifndef __IBootableDeviceConfig_FWD_DEFINED__
#define __IBootableDeviceConfig_FWD_DEFINED__
typedef interface IBootableDeviceConfig IBootableDeviceConfig;
#endif 	/* __IBootableDeviceConfig_FWD_DEFINED__ */


#ifndef __IServiceCategoryConfig_FWD_DEFINED__
#define __IServiceCategoryConfig_FWD_DEFINED__
typedef interface IServiceCategoryConfig IServiceCategoryConfig;
#endif 	/* __IServiceCategoryConfig_FWD_DEFINED__ */


#ifndef __IServiceInfoConfig_FWD_DEFINED__
#define __IServiceInfoConfig_FWD_DEFINED__
typedef interface IServiceInfoConfig IServiceInfoConfig;
#endif 	/* __IServiceInfoConfig_FWD_DEFINED__ */


#ifndef __IPlatformConfig_FWD_DEFINED__
#define __IPlatformConfig_FWD_DEFINED__
typedef interface IPlatformConfig IPlatformConfig;
#endif 	/* __IPlatformConfig_FWD_DEFINED__ */


#ifndef __IPlatformConfig2_FWD_DEFINED__
#define __IPlatformConfig2_FWD_DEFINED__
typedef interface IPlatformConfig2 IPlatformConfig2;
#endif 	/* __IPlatformConfig2_FWD_DEFINED__ */


#ifndef __IRemoteDeviceConfig_FWD_DEFINED__
#define __IRemoteDeviceConfig_FWD_DEFINED__
typedef interface IRemoteDeviceConfig IRemoteDeviceConfig;
#endif 	/* __IRemoteDeviceConfig_FWD_DEFINED__ */


#ifndef __IEnumComponent_FWD_DEFINED__
#define __IEnumComponent_FWD_DEFINED__
typedef interface IEnumComponent IEnumComponent;
#endif 	/* __IEnumComponent_FWD_DEFINED__ */


#ifndef __IPackage_FWD_DEFINED__
#define __IPackage_FWD_DEFINED__
typedef interface IPackage IPackage;
#endif 	/* __IPackage_FWD_DEFINED__ */


#ifndef __IPackage2_FWD_DEFINED__
#define __IPackage2_FWD_DEFINED__
typedef interface IPackage2 IPackage2;
#endif 	/* __IPackage2_FWD_DEFINED__ */


#ifndef __IEnumPackageFiles_FWD_DEFINED__
#define __IEnumPackageFiles_FWD_DEFINED__
typedef interface IEnumPackageFiles IEnumPackageFiles;
#endif 	/* __IEnumPackageFiles_FWD_DEFINED__ */


#ifndef __IEnumPackageFiles2_FWD_DEFINED__
#define __IEnumPackageFiles2_FWD_DEFINED__
typedef interface IEnumPackageFiles2 IEnumPackageFiles2;
#endif 	/* __IEnumPackageFiles2_FWD_DEFINED__ */


#ifndef __IEnumCPU_FWD_DEFINED__
#define __IEnumCPU_FWD_DEFINED__
typedef interface IEnumCPU IEnumCPU;
#endif 	/* __IEnumCPU_FWD_DEFINED__ */


#ifndef __IPMPlatformManager_FWD_DEFINED__
#define __IPMPlatformManager_FWD_DEFINED__
typedef interface IPMPlatformManager IPMPlatformManager;
#endif 	/* __IPMPlatformManager_FWD_DEFINED__ */


#ifndef __IPMPlatform_FWD_DEFINED__
#define __IPMPlatform_FWD_DEFINED__
typedef interface IPMPlatform IPMPlatform;
#endif 	/* __IPMPlatform_FWD_DEFINED__ */


#ifndef __IPMRemoteDevice_FWD_DEFINED__
#define __IPMRemoteDevice_FWD_DEFINED__
typedef interface IPMRemoteDevice IPMRemoteDevice;
#endif 	/* __IPMRemoteDevice_FWD_DEFINED__ */


#ifndef __IPMProperty_FWD_DEFINED__
#define __IPMProperty_FWD_DEFINED__
typedef interface IPMProperty IPMProperty;
#endif 	/* __IPMProperty_FWD_DEFINED__ */


#ifndef __IPMBootableDevice_FWD_DEFINED__
#define __IPMBootableDevice_FWD_DEFINED__
typedef interface IPMBootableDevice IPMBootableDevice;
#endif 	/* __IPMBootableDevice_FWD_DEFINED__ */


#ifndef __IPMPackage_FWD_DEFINED__
#define __IPMPackage_FWD_DEFINED__
typedef interface IPMPackage IPMPackage;
#endif 	/* __IPMPackage_FWD_DEFINED__ */


#ifndef __IPMService_FWD_DEFINED__
#define __IPMService_FWD_DEFINED__
typedef interface IPMService IPMService;
#endif 	/* __IPMService_FWD_DEFINED__ */


#ifndef __IPMServiceInfo_FWD_DEFINED__
#define __IPMServiceInfo_FWD_DEFINED__
typedef interface IPMServiceInfo IPMServiceInfo;
#endif 	/* __IPMServiceInfo_FWD_DEFINED__ */


#ifndef __IPMServiceCategory_FWD_DEFINED__
#define __IPMServiceCategory_FWD_DEFINED__
typedef interface IPMServiceCategory IPMServiceCategory;
#endif 	/* __IPMServiceCategory_FWD_DEFINED__ */


#ifndef __IPMConnectionStream_FWD_DEFINED__
#define __IPMConnectionStream_FWD_DEFINED__
typedef interface IPMConnectionStream IPMConnectionStream;
#endif 	/* __IPMConnectionStream_FWD_DEFINED__ */


#ifndef __IPMConnection_FWD_DEFINED__
#define __IPMConnection_FWD_DEFINED__
typedef interface IPMConnection IPMConnection;
#endif 	/* __IPMConnection_FWD_DEFINED__ */


#ifndef __IPMCPU_FWD_DEFINED__
#define __IPMCPU_FWD_DEFINED__
typedef interface IPMCPU IPMCPU;
#endif 	/* __IPMCPU_FWD_DEFINED__ */


#ifndef __IPMOS_FWD_DEFINED__
#define __IPMOS_FWD_DEFINED__
typedef interface IPMOS IPMOS;
#endif 	/* __IPMOS_FWD_DEFINED__ */


#ifndef __IPMStartupServerInfo_FWD_DEFINED__
#define __IPMStartupServerInfo_FWD_DEFINED__
typedef interface IPMStartupServerInfo IPMStartupServerInfo;
#endif 	/* __IPMStartupServerInfo_FWD_DEFINED__ */


#ifndef __IPMTransportInfo_FWD_DEFINED__
#define __IPMTransportInfo_FWD_DEFINED__
typedef interface IPMTransportInfo IPMTransportInfo;
#endif 	/* __IPMTransportInfo_FWD_DEFINED__ */


#ifndef __IPMPropInfo_FWD_DEFINED__
#define __IPMPropInfo_FWD_DEFINED__
typedef interface IPMPropInfo IPMPropInfo;
#endif 	/* __IPMPropInfo_FWD_DEFINED__ */


#ifndef __IPMPackageFile_FWD_DEFINED__
#define __IPMPackageFile_FWD_DEFINED__
typedef interface IPMPackageFile IPMPackageFile;
#endif 	/* __IPMPackageFile_FWD_DEFINED__ */


#ifndef __IEnumVariant_FWD_DEFINED__
#define __IEnumVariant_FWD_DEFINED__
typedef interface IEnumVariant IEnumVariant;
#endif 	/* __IEnumVariant_FWD_DEFINED__ */


#ifndef __IClientInfo_FWD_DEFINED__
#define __IClientInfo_FWD_DEFINED__
typedef interface IClientInfo IClientInfo;
#endif 	/* __IClientInfo_FWD_DEFINED__ */


#ifndef __PlatformManager_FWD_DEFINED__
#define __PlatformManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class PlatformManager PlatformManager;
#else
typedef struct PlatformManager PlatformManager;
#endif /* __cplusplus */

#endif 	/* __PlatformManager_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_cemgr_0000 */
/* [local] */ 


















































// error codes
//
static const int E_BAD_PARAM				= MAKE_HRESULT(1, FACILITY_ITF, 0x01);
static const int E_DUPLICATE				= MAKE_HRESULT(1, FACILITY_ITF, 0x02);
static const int E_BUSY					= MAKE_HRESULT(1, FACILITY_ITF, 0x03);
static const int E_BAD_CONFIG			= MAKE_HRESULT(1, FACILITY_ITF, 0x04);
static const int E_NOSYSFILES			= MAKE_HRESULT(1, FACILITY_ITF, 0x05);
static const int E_TIMEOUT				= MAKE_HRESULT(1, FACILITY_ITF, 0x06);
static const int E_REFED					= MAKE_HRESULT(1, FACILITY_ITF, 0x07);
static const int E_VERIFY				= MAKE_HRESULT(1, FACILITY_ITF, 0x01);
static const int E_EXISTS				= MAKE_HRESULT(1, FACILITY_ITF, 0x02);
static const int E_REGISTER				= MAKE_HRESULT(1, FACILITY_ITF, 0x03);
static const int E_SKIP					= MAKE_HRESULT(1, FACILITY_ITF, 0x01);
static const GUID PROPID_CURRENT_CONNECTION = {0xc5562463, 0xa1cc, 0x4b78, { 0xb7, 0xe2, 0xf2, 0x7, 0x9, 0xd2, 0xf7, 0x9d}};
static const wchar_t PROPINFO_BOOTABLE_DEVICE[] = L"CurrentDevice";
static const wchar_t PROPINFO_IMAGE[] = L"Image";
static const GUID CEMGRC2_ID = { 0x69793847, 0x677e, 0x4658, { 0x92, 0xd3, 0xb3, 0x2a, 0x2e, 0xd1, 0x3f, 0xe4 } };
static const GUID PROPID_UNIVERSAL_SDK = { 0x1315cf7c, 0xd79b, 0x47e8, { 0xa1, 0x41, 0xcc, 0x39, 0x65, 0x4e, 0x76, 0x7f } };
static const wchar_t PROPINFO_TUSDK[] = L"TUSDK";
static const wchar_t PROPVALUE_UNIVERSAL[] = L"Universal";
static const wchar_t PROPVALUE_PARENTS[] = L"Parents";
static const GUID PROP_SERIAL_GUID = { 0xEC345961, 0x5500, 0x4d8e, { 0x8C, 0x27, 0x38, 0x75, 0x42, 0xFA, 0xB8, 0x12 } };
static const wchar_t PROP_SERIAL_STRING[] = L"{EC345961-5500-4d8e-8C27-387542FAB812}";
static const GUID PROPID_CFG_REM_SRV = { 0x44f1dbd2, 0x16c1, 0x4e8a, { 0x9b, 0xc2, 0x3, 0xe6, 0x6a, 0xdb, 0x3, 0xe } };
static const wchar_t PROPINFONAME_PROCID[] = L"Process ID messages";
static const wchar_t PROPINFONAME_THRDID[] = L"Thread ID messages";
static const wchar_t PROPINFONAME_TSTAMP[] = L"Time stamp messages";
static const wchar_t PROPINFONAME_DLOAD[] = L"Download Image";
static const wchar_t PROPINFONAME_JUMP[] = L"Jump to Image";
static const wchar_t PROPINFONAME_CONNNECT[] = L"Connect On Download";
static const wchar_t PROPINFONAME_HARDWARE[] = L"Hardware Debugger";
static const wchar_t PROPINFONAME_DBGMSGFILENAME[] = L"Dbg Msg Filename";
static const wchar_t PROPINFONAME_SENDDBGMSGOUTPUT[] = L"Send Dbg Output";
static const wchar_t PROPINFONAME_DOWNLOAD_CFGSETTING[] = L"Download Config Setting";
static const wchar_t PROPINFONAME_KERNEL_CFGSETTING[] = L"Kernel Config Setting";
static const wchar_t PROPINFONAME_HARDWARE_DBG_GUID[] = L"eXdi Driver GUID";
static const wchar_t PROPINFONAME_HARDWARE_DBG_DESC[] = L"eXdi Driver Name";
static const wchar_t PROPINFONAME_COLDBOOT[] = L"Cold Reboot";
static const wchar_t PROPINFONAME_RESET_DL_ALWAYS[] = L"Reset DL Always";
static const wchar_t PROPINFONAME_RESET_DL_IMAGE_CHANGE[] = L"Reset DL Image Change";
static const wchar_t PROPINFONAME_RESET_JTI_ONLY[] = L"Reset JTI Only";
static const wchar_t PROPINFONAMR_LAST_OPEN_BIN_IMAGE[] = L"Last Open Bin Image";
static const wchar_t PROPINFONAME_SENDDBGMSGOUTPUTWINDOW[] = L"Send Dbg Output Window";
static const wchar_t PROPINFONAME_SENDDBGMSGOUTPUTWINDOWNL[] = L"DBGMSG append new line";
static const wchar_t PROPINFONAME_ALLOW_ACCESS_TO_FILESYSTEM[] = L"Allow Remote Access to Local File System";
static const wchar_t REGKEY_PLATMAN_PPFSACCESS[] = L"Software\\Microsoft\\Windows CE Tools\\Platform Manager\\PPFSAccess";
static const wchar_t REGVAL_PB_PPFS_ACCESS[] = L"AllowPPFSAccess";
typedef 
enum component_kind
    {	COMPONENT_TRANSPORT	= 0,
	COMPONENT_SERVER	= COMPONENT_TRANSPORT + 1
    } 	COMPONENT_KIND;


enum __MIDL___MIDL_itf_cemgr_0000_0001
    {	DEVICE_TYPE_EMULATION	= 0x1,
	DEVICE_TYPE_CE	= 0x2,
	DEVICE_TYPE_NT	= 0x4
    } ;
typedef ULONG DEVICE_TYPE;

typedef 
enum report_action_type
    {	SERVER_START	= 0,
	SERVER_FAIL	= SERVER_START + 1,
	SERVER_FINISH	= SERVER_FAIL + 1,
	CONNECT_START	= SERVER_FINISH + 1,
	CONNECT_FAIL	= CONNECT_START + 1,
	CONNECT_FINISH	= CONNECT_FAIL + 1,
	VERIFY_START	= CONNECT_FINISH + 1,
	VERIFY_FAIL	= VERIFY_START + 1,
	VERIFY_FINISH	= VERIFY_FAIL + 1,
	COPY_START	= VERIFY_FINISH + 1,
	COPY_FAILED	= COPY_START + 1,
	COPY_FINISH	= COPY_FAILED + 1,
	REGISTER_START	= COPY_FINISH + 1,
	REGISTER_FAILED	= REGISTER_START + 1,
	REGISTER_FINISH	= REGISTER_FAILED + 1,
	COPY_COMPLETE	= REGISTER_FINISH + 1,
	ATTACH_TIMEOUT	= COPY_COMPLETE + 1,
	COPY_SOURCENOTFOUND	= ATTACH_TIMEOUT + 1
    } 	REPORT_ACTION_TYPE;

static const int FILE_FLAG_REQUIRED	= 0x00000001;
static const int FILE_FLAG_16BIT		= 0x00000002;
static const int FILE_FLAG_FPSUPPORT	= 0x00000004;
static const int FILE_FLAG_CPUNUM   	= 0x00000008;
static const int DEVICE_FLAG_NO_FILESYS = 0x00000001;
typedef struct package_file_info
    {
    DEVICE_TYPE dt;
    WORD wArchitecture;
    DWORD dwCPUType;
    WORD wProcessorLevel;
    DWORD dwPageSize;
    WORD wMajorVersion;
    WORD wMinorVersion;
    DWORD dwLocaleId;
    DWORD dwFlags;
    } 	PACKAGE_FILE_INFO;

typedef struct package_file_info *PPACKAGE_FILE_INFO;

typedef struct package_file_info2
    {
    DEVICE_TYPE dt;
    WORD wArchitecture;
    DWORD dwCPUType;
    WORD wProcessorLevel;
    DWORD dwPageSize;
    WORD wMajorVersion;
    WORD wMinorVersion;
    DWORD dwLocaleId;
    DWORD dwFlags;
    GUID OSTypeId;
    } 	PACKAGE_FILE_INFO2;

typedef struct package_file_info2 *PPACKAGE_FILE_INFO2;



extern RPC_IF_HANDLE __MIDL_itf_cemgr_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_cemgr_0000_v0_0_s_ifspec;

#ifndef __IPlatformManager_INTERFACE_DEFINED__
#define __IPlatformManager_INTERFACE_DEFINED__

/* interface IPlatformManager */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IPlatformManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F384D882-F9AA-11D1-BB9E-00A0C9C9CCEE")
    IPlatformManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumPlatforms( 
            /* [out] */ IEnumPlatformCE **ppiEnumPlatform) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteProperty( 
            /* [in] */ GUID PropId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumProperties( 
            /* [out] */ IEnumProperty **ppiEnumProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPlatform( 
            /* [in] */ GUID PlatformId,
            /* [out] */ IPlatformCE **ppiPlatform) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlatformManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlatformManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlatformManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlatformManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPlatforms )( 
            IPlatformManager * This,
            /* [out] */ IEnumPlatformCE **ppiEnumPlatform);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IPlatformManager * This,
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IPlatformManager * This,
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IPlatformManager * This,
            /* [in] */ GUID PropId);
        
        HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IPlatformManager * This,
            /* [out] */ IEnumProperty **ppiEnumProperty);
        
        HRESULT ( STDMETHODCALLTYPE *GetPlatform )( 
            IPlatformManager * This,
            /* [in] */ GUID PlatformId,
            /* [out] */ IPlatformCE **ppiPlatform);
        
        END_INTERFACE
    } IPlatformManagerVtbl;

    interface IPlatformManager
    {
        CONST_VTBL struct IPlatformManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlatformManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlatformManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlatformManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlatformManager_EnumPlatforms(This,ppiEnumPlatform)	\
    (This)->lpVtbl -> EnumPlatforms(This,ppiEnumPlatform)

#define IPlatformManager_GetProperty(This,PropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,PropId,ppiProperty)

#define IPlatformManager_AddProperty(This,PropId,pszLinkName,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,PropId,pszLinkName,ppiProperty)

#define IPlatformManager_DeleteProperty(This,PropId)	\
    (This)->lpVtbl -> DeleteProperty(This,PropId)

#define IPlatformManager_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IPlatformManager_GetPlatform(This,PlatformId,ppiPlatform)	\
    (This)->lpVtbl -> GetPlatform(This,PlatformId,ppiPlatform)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlatformManager_EnumPlatforms_Proxy( 
    IPlatformManager * This,
    /* [out] */ IEnumPlatformCE **ppiEnumPlatform);


void __RPC_STUB IPlatformManager_EnumPlatforms_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManager_GetProperty_Proxy( 
    IPlatformManager * This,
    /* [in] */ GUID PropId,
    /* [out] */ IProperty **ppiProperty);


void __RPC_STUB IPlatformManager_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManager_AddProperty_Proxy( 
    IPlatformManager * This,
    /* [in] */ GUID PropId,
    /* [full][in] */ LPCOLESTR pszLinkName,
    /* [out] */ IProperty **ppiProperty);


void __RPC_STUB IPlatformManager_AddProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManager_DeleteProperty_Proxy( 
    IPlatformManager * This,
    /* [in] */ GUID PropId);


void __RPC_STUB IPlatformManager_DeleteProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManager_EnumProperties_Proxy( 
    IPlatformManager * This,
    /* [out] */ IEnumProperty **ppiEnumProperty);


void __RPC_STUB IPlatformManager_EnumProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManager_GetPlatform_Proxy( 
    IPlatformManager * This,
    /* [in] */ GUID PlatformId,
    /* [out] */ IPlatformCE **ppiPlatform);


void __RPC_STUB IPlatformManager_GetPlatform_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlatformManager_INTERFACE_DEFINED__ */


#ifndef __IPlatformManager2_INTERFACE_DEFINED__
#define __IPlatformManager2_INTERFACE_DEFINED__

/* interface IPlatformManager2 */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IPlatformManager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D08B18FB-0471-4a4d-88F3-9F1187A058AA")
    IPlatformManager2 : public IPlatformManager
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetConnection( 
            /* [in] */ GUID ConnectId,
            /* [out] */ IConnection **ppiConnection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlatformManager2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlatformManager2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlatformManager2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlatformManager2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPlatforms )( 
            IPlatformManager2 * This,
            /* [out] */ IEnumPlatformCE **ppiEnumPlatform);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IPlatformManager2 * This,
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IPlatformManager2 * This,
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IPlatformManager2 * This,
            /* [in] */ GUID PropId);
        
        HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IPlatformManager2 * This,
            /* [out] */ IEnumProperty **ppiEnumProperty);
        
        HRESULT ( STDMETHODCALLTYPE *GetPlatform )( 
            IPlatformManager2 * This,
            /* [in] */ GUID PlatformId,
            /* [out] */ IPlatformCE **ppiPlatform);
        
        HRESULT ( STDMETHODCALLTYPE *GetConnection )( 
            IPlatformManager2 * This,
            /* [in] */ GUID ConnectId,
            /* [out] */ IConnection **ppiConnection);
        
        END_INTERFACE
    } IPlatformManager2Vtbl;

    interface IPlatformManager2
    {
        CONST_VTBL struct IPlatformManager2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlatformManager2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlatformManager2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlatformManager2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlatformManager2_EnumPlatforms(This,ppiEnumPlatform)	\
    (This)->lpVtbl -> EnumPlatforms(This,ppiEnumPlatform)

#define IPlatformManager2_GetProperty(This,PropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,PropId,ppiProperty)

#define IPlatformManager2_AddProperty(This,PropId,pszLinkName,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,PropId,pszLinkName,ppiProperty)

#define IPlatformManager2_DeleteProperty(This,PropId)	\
    (This)->lpVtbl -> DeleteProperty(This,PropId)

#define IPlatformManager2_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IPlatformManager2_GetPlatform(This,PlatformId,ppiPlatform)	\
    (This)->lpVtbl -> GetPlatform(This,PlatformId,ppiPlatform)


#define IPlatformManager2_GetConnection(This,ConnectId,ppiConnection)	\
    (This)->lpVtbl -> GetConnection(This,ConnectId,ppiConnection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlatformManager2_GetConnection_Proxy( 
    IPlatformManager2 * This,
    /* [in] */ GUID ConnectId,
    /* [out] */ IConnection **ppiConnection);


void __RPC_STUB IPlatformManager2_GetConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlatformManager2_INTERFACE_DEFINED__ */


#ifndef __IPlatformManager3_INTERFACE_DEFINED__
#define __IPlatformManager3_INTERFACE_DEFINED__

/* interface IPlatformManager3 */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IPlatformManager3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("91DAF806-2EEB-44a5-B7D1-B1EF3DB9FC88")
    IPlatformManager3 : public IPlatformManager2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumBootableDevice( 
            /* [out] */ IEnumBootableDevice **ppiEnumBootableDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBootableDevice( 
            /* [in] */ GUID BootableDeviceId,
            /* [out] */ IBootableDevice **ppiBootableDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumServiceCategory( 
            /* [out] */ IEnumServiceCategory **ppiEnumServiceCategory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceCategory( 
            /* [in] */ GUID ServiceCategoryId,
            /* [out] */ IServiceCategory **ppiServiceCategory) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlatformManager3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlatformManager3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlatformManager3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlatformManager3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPlatforms )( 
            IPlatformManager3 * This,
            /* [out] */ IEnumPlatformCE **ppiEnumPlatform);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IPlatformManager3 * This,
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IPlatformManager3 * This,
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IPlatformManager3 * This,
            /* [in] */ GUID PropId);
        
        HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IPlatformManager3 * This,
            /* [out] */ IEnumProperty **ppiEnumProperty);
        
        HRESULT ( STDMETHODCALLTYPE *GetPlatform )( 
            IPlatformManager3 * This,
            /* [in] */ GUID PlatformId,
            /* [out] */ IPlatformCE **ppiPlatform);
        
        HRESULT ( STDMETHODCALLTYPE *GetConnection )( 
            IPlatformManager3 * This,
            /* [in] */ GUID ConnectId,
            /* [out] */ IConnection **ppiConnection);
        
        HRESULT ( STDMETHODCALLTYPE *EnumBootableDevice )( 
            IPlatformManager3 * This,
            /* [out] */ IEnumBootableDevice **ppiEnumBootableDevice);
        
        HRESULT ( STDMETHODCALLTYPE *GetBootableDevice )( 
            IPlatformManager3 * This,
            /* [in] */ GUID BootableDeviceId,
            /* [out] */ IBootableDevice **ppiBootableDevice);
        
        HRESULT ( STDMETHODCALLTYPE *EnumServiceCategory )( 
            IPlatformManager3 * This,
            /* [out] */ IEnumServiceCategory **ppiEnumServiceCategory);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceCategory )( 
            IPlatformManager3 * This,
            /* [in] */ GUID ServiceCategoryId,
            /* [out] */ IServiceCategory **ppiServiceCategory);
        
        END_INTERFACE
    } IPlatformManager3Vtbl;

    interface IPlatformManager3
    {
        CONST_VTBL struct IPlatformManager3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlatformManager3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlatformManager3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlatformManager3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlatformManager3_EnumPlatforms(This,ppiEnumPlatform)	\
    (This)->lpVtbl -> EnumPlatforms(This,ppiEnumPlatform)

#define IPlatformManager3_GetProperty(This,PropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,PropId,ppiProperty)

#define IPlatformManager3_AddProperty(This,PropId,pszLinkName,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,PropId,pszLinkName,ppiProperty)

#define IPlatformManager3_DeleteProperty(This,PropId)	\
    (This)->lpVtbl -> DeleteProperty(This,PropId)

#define IPlatformManager3_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IPlatformManager3_GetPlatform(This,PlatformId,ppiPlatform)	\
    (This)->lpVtbl -> GetPlatform(This,PlatformId,ppiPlatform)


#define IPlatformManager3_GetConnection(This,ConnectId,ppiConnection)	\
    (This)->lpVtbl -> GetConnection(This,ConnectId,ppiConnection)


#define IPlatformManager3_EnumBootableDevice(This,ppiEnumBootableDevice)	\
    (This)->lpVtbl -> EnumBootableDevice(This,ppiEnumBootableDevice)

#define IPlatformManager3_GetBootableDevice(This,BootableDeviceId,ppiBootableDevice)	\
    (This)->lpVtbl -> GetBootableDevice(This,BootableDeviceId,ppiBootableDevice)

#define IPlatformManager3_EnumServiceCategory(This,ppiEnumServiceCategory)	\
    (This)->lpVtbl -> EnumServiceCategory(This,ppiEnumServiceCategory)

#define IPlatformManager3_GetServiceCategory(This,ServiceCategoryId,ppiServiceCategory)	\
    (This)->lpVtbl -> GetServiceCategory(This,ServiceCategoryId,ppiServiceCategory)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlatformManager3_EnumBootableDevice_Proxy( 
    IPlatformManager3 * This,
    /* [out] */ IEnumBootableDevice **ppiEnumBootableDevice);


void __RPC_STUB IPlatformManager3_EnumBootableDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManager3_GetBootableDevice_Proxy( 
    IPlatformManager3 * This,
    /* [in] */ GUID BootableDeviceId,
    /* [out] */ IBootableDevice **ppiBootableDevice);


void __RPC_STUB IPlatformManager3_GetBootableDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManager3_EnumServiceCategory_Proxy( 
    IPlatformManager3 * This,
    /* [out] */ IEnumServiceCategory **ppiEnumServiceCategory);


void __RPC_STUB IPlatformManager3_EnumServiceCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManager3_GetServiceCategory_Proxy( 
    IPlatformManager3 * This,
    /* [in] */ GUID ServiceCategoryId,
    /* [out] */ IServiceCategory **ppiServiceCategory);


void __RPC_STUB IPlatformManager3_GetServiceCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlatformManager3_INTERFACE_DEFINED__ */


#ifndef __IEnumServiceCategory_INTERFACE_DEFINED__
#define __IEnumServiceCategory_INTERFACE_DEFINED__

/* interface IEnumServiceCategory */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumServiceCategory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4E4527E8-BCE4-4675-B564-E7DE0EA6D163")
    IEnumServiceCategory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IServiceCategory *rgelt[  ],
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumServiceCategory **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG *pcelt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNext( 
            /* [out] */ IServiceCategory **ppiServiceCategory) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumServiceCategoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumServiceCategory * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumServiceCategory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumServiceCategory * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumServiceCategory * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IServiceCategory *rgelt[  ],
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumServiceCategory * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumServiceCategory * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumServiceCategory * This,
            /* [out] */ IEnumServiceCategory **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IEnumServiceCategory * This,
            /* [out] */ ULONG *pcelt);
        
        HRESULT ( STDMETHODCALLTYPE *GetNext )( 
            IEnumServiceCategory * This,
            /* [out] */ IServiceCategory **ppiServiceCategory);
        
        END_INTERFACE
    } IEnumServiceCategoryVtbl;

    interface IEnumServiceCategory
    {
        CONST_VTBL struct IEnumServiceCategoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumServiceCategory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumServiceCategory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumServiceCategory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumServiceCategory_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumServiceCategory_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumServiceCategory_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumServiceCategory_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#define IEnumServiceCategory_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)

#define IEnumServiceCategory_GetNext(This,ppiServiceCategory)	\
    (This)->lpVtbl -> GetNext(This,ppiServiceCategory)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumServiceCategory_Next_Proxy( 
    IEnumServiceCategory * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IServiceCategory *rgelt[  ],
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumServiceCategory_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumServiceCategory_Skip_Proxy( 
    IEnumServiceCategory * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumServiceCategory_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumServiceCategory_Reset_Proxy( 
    IEnumServiceCategory * This);


void __RPC_STUB IEnumServiceCategory_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumServiceCategory_Clone_Proxy( 
    IEnumServiceCategory * This,
    /* [out] */ IEnumServiceCategory **ppEnum);


void __RPC_STUB IEnumServiceCategory_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumServiceCategory_GetCount_Proxy( 
    IEnumServiceCategory * This,
    /* [out] */ ULONG *pcelt);


void __RPC_STUB IEnumServiceCategory_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumServiceCategory_GetNext_Proxy( 
    IEnumServiceCategory * This,
    /* [out] */ IServiceCategory **ppiServiceCategory);


void __RPC_STUB IEnumServiceCategory_GetNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumServiceCategory_INTERFACE_DEFINED__ */


#ifndef __IServiceCategory_INTERFACE_DEFINED__
#define __IServiceCategory_INTERFACE_DEFINED__

/* interface IServiceCategory */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IServiceCategory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("73EA2A51-09D5-416c-99FF-A6935A02672B")
    IServiceCategory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetServiceCategoryId( 
            /* [out] */ GUID *pServiceCategoryId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceCategoryName( 
            /* [out] */ LPOLESTR *ppszServiceCategoryName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumServiceInfo( 
            /* [out] */ IEnumServiceInfo **ppiEnumServiceInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceInfo( 
            /* [in] */ GUID ServiceCLSID,
            /* [out] */ IServiceInfo **ppiServiceInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumProperties( 
            /* [out] */ IEnumProperty **ppiEnumProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteProperty( 
            /* [in] */ GUID PropId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServiceCategoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IServiceCategory * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IServiceCategory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IServiceCategory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceCategoryId )( 
            IServiceCategory * This,
            /* [out] */ GUID *pServiceCategoryId);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceCategoryName )( 
            IServiceCategory * This,
            /* [out] */ LPOLESTR *ppszServiceCategoryName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumServiceInfo )( 
            IServiceCategory * This,
            /* [out] */ IEnumServiceInfo **ppiEnumServiceInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceInfo )( 
            IServiceCategory * This,
            /* [in] */ GUID ServiceCLSID,
            /* [out] */ IServiceInfo **ppiServiceInfo);
        
        HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IServiceCategory * This,
            /* [out] */ IEnumProperty **ppiEnumProperty);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IServiceCategory * This,
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IServiceCategory * This,
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IServiceCategory * This,
            /* [in] */ GUID PropId);
        
        END_INTERFACE
    } IServiceCategoryVtbl;

    interface IServiceCategory
    {
        CONST_VTBL struct IServiceCategoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServiceCategory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServiceCategory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServiceCategory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServiceCategory_GetServiceCategoryId(This,pServiceCategoryId)	\
    (This)->lpVtbl -> GetServiceCategoryId(This,pServiceCategoryId)

#define IServiceCategory_GetServiceCategoryName(This,ppszServiceCategoryName)	\
    (This)->lpVtbl -> GetServiceCategoryName(This,ppszServiceCategoryName)

#define IServiceCategory_EnumServiceInfo(This,ppiEnumServiceInfo)	\
    (This)->lpVtbl -> EnumServiceInfo(This,ppiEnumServiceInfo)

#define IServiceCategory_GetServiceInfo(This,ServiceCLSID,ppiServiceInfo)	\
    (This)->lpVtbl -> GetServiceInfo(This,ServiceCLSID,ppiServiceInfo)

#define IServiceCategory_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IServiceCategory_GetProperty(This,PropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,PropId,ppiProperty)

#define IServiceCategory_AddProperty(This,PropId,pszLinkName,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,PropId,pszLinkName,ppiProperty)

#define IServiceCategory_DeleteProperty(This,PropId)	\
    (This)->lpVtbl -> DeleteProperty(This,PropId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IServiceCategory_GetServiceCategoryId_Proxy( 
    IServiceCategory * This,
    /* [out] */ GUID *pServiceCategoryId);


void __RPC_STUB IServiceCategory_GetServiceCategoryId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServiceCategory_GetServiceCategoryName_Proxy( 
    IServiceCategory * This,
    /* [out] */ LPOLESTR *ppszServiceCategoryName);


void __RPC_STUB IServiceCategory_GetServiceCategoryName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServiceCategory_EnumServiceInfo_Proxy( 
    IServiceCategory * This,
    /* [out] */ IEnumServiceInfo **ppiEnumServiceInfo);


void __RPC_STUB IServiceCategory_EnumServiceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServiceCategory_GetServiceInfo_Proxy( 
    IServiceCategory * This,
    /* [in] */ GUID ServiceCLSID,
    /* [out] */ IServiceInfo **ppiServiceInfo);


void __RPC_STUB IServiceCategory_GetServiceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServiceCategory_EnumProperties_Proxy( 
    IServiceCategory * This,
    /* [out] */ IEnumProperty **ppiEnumProperty);


void __RPC_STUB IServiceCategory_EnumProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServiceCategory_GetProperty_Proxy( 
    IServiceCategory * This,
    /* [in] */ GUID PropId,
    /* [out] */ IProperty **ppiProperty);


void __RPC_STUB IServiceCategory_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServiceCategory_AddProperty_Proxy( 
    IServiceCategory * This,
    /* [in] */ GUID PropId,
    /* [full][in] */ LPCOLESTR pszLinkName,
    /* [out] */ IProperty **ppiProperty);


void __RPC_STUB IServiceCategory_AddProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServiceCategory_DeleteProperty_Proxy( 
    IServiceCategory * This,
    /* [in] */ GUID PropId);


void __RPC_STUB IServiceCategory_DeleteProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IServiceCategory_INTERFACE_DEFINED__ */


#ifndef __IEnumServiceInfo_INTERFACE_DEFINED__
#define __IEnumServiceInfo_INTERFACE_DEFINED__

/* interface IEnumServiceInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumServiceInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("53CCA653-3F54-434c-8DB0-3D8A610745E4")
    IEnumServiceInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IServiceInfo *rgelt[  ],
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumServiceInfo **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG *pcelt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNext( 
            /* [out] */ IServiceInfo **ppiServiceInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumServiceInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumServiceInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumServiceInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumServiceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumServiceInfo * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IServiceInfo *rgelt[  ],
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumServiceInfo * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumServiceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumServiceInfo * This,
            /* [out] */ IEnumServiceInfo **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IEnumServiceInfo * This,
            /* [out] */ ULONG *pcelt);
        
        HRESULT ( STDMETHODCALLTYPE *GetNext )( 
            IEnumServiceInfo * This,
            /* [out] */ IServiceInfo **ppiServiceInfo);
        
        END_INTERFACE
    } IEnumServiceInfoVtbl;

    interface IEnumServiceInfo
    {
        CONST_VTBL struct IEnumServiceInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumServiceInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumServiceInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumServiceInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumServiceInfo_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumServiceInfo_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumServiceInfo_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumServiceInfo_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#define IEnumServiceInfo_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)

#define IEnumServiceInfo_GetNext(This,ppiServiceInfo)	\
    (This)->lpVtbl -> GetNext(This,ppiServiceInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumServiceInfo_Next_Proxy( 
    IEnumServiceInfo * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IServiceInfo *rgelt[  ],
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumServiceInfo_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumServiceInfo_Skip_Proxy( 
    IEnumServiceInfo * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumServiceInfo_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumServiceInfo_Reset_Proxy( 
    IEnumServiceInfo * This);


void __RPC_STUB IEnumServiceInfo_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumServiceInfo_Clone_Proxy( 
    IEnumServiceInfo * This,
    /* [out] */ IEnumServiceInfo **ppEnum);


void __RPC_STUB IEnumServiceInfo_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumServiceInfo_GetCount_Proxy( 
    IEnumServiceInfo * This,
    /* [out] */ ULONG *pcelt);


void __RPC_STUB IEnumServiceInfo_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumServiceInfo_GetNext_Proxy( 
    IEnumServiceInfo * This,
    /* [out] */ IServiceInfo **ppiServiceInfo);


void __RPC_STUB IEnumServiceInfo_GetNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumServiceInfo_INTERFACE_DEFINED__ */


#ifndef __IServiceInfo_INTERFACE_DEFINED__
#define __IServiceInfo_INTERFACE_DEFINED__

/* interface IServiceInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IServiceInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("320494E2-0D2A-4594-A8FC-73913FAE85C8")
    IServiceInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetServiceCLSID( 
            /* [out] */ GUID *pServiceCLSID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceInfoName( 
            /* [out] */ LPOLESTR *ppszServiceInfoName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumProperties( 
            /* [out] */ IEnumProperty **ppiEnumProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteProperty( 
            /* [in] */ GUID PropId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServiceInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IServiceInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IServiceInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IServiceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceCLSID )( 
            IServiceInfo * This,
            /* [out] */ GUID *pServiceCLSID);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceInfoName )( 
            IServiceInfo * This,
            /* [out] */ LPOLESTR *ppszServiceInfoName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IServiceInfo * This,
            /* [out] */ IEnumProperty **ppiEnumProperty);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IServiceInfo * This,
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IServiceInfo * This,
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IServiceInfo * This,
            /* [in] */ GUID PropId);
        
        END_INTERFACE
    } IServiceInfoVtbl;

    interface IServiceInfo
    {
        CONST_VTBL struct IServiceInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServiceInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServiceInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServiceInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServiceInfo_GetServiceCLSID(This,pServiceCLSID)	\
    (This)->lpVtbl -> GetServiceCLSID(This,pServiceCLSID)

#define IServiceInfo_GetServiceInfoName(This,ppszServiceInfoName)	\
    (This)->lpVtbl -> GetServiceInfoName(This,ppszServiceInfoName)

#define IServiceInfo_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IServiceInfo_GetProperty(This,PropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,PropId,ppiProperty)

#define IServiceInfo_AddProperty(This,PropId,pszLinkName,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,PropId,pszLinkName,ppiProperty)

#define IServiceInfo_DeleteProperty(This,PropId)	\
    (This)->lpVtbl -> DeleteProperty(This,PropId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IServiceInfo_GetServiceCLSID_Proxy( 
    IServiceInfo * This,
    /* [out] */ GUID *pServiceCLSID);


void __RPC_STUB IServiceInfo_GetServiceCLSID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServiceInfo_GetServiceInfoName_Proxy( 
    IServiceInfo * This,
    /* [out] */ LPOLESTR *ppszServiceInfoName);


void __RPC_STUB IServiceInfo_GetServiceInfoName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServiceInfo_EnumProperties_Proxy( 
    IServiceInfo * This,
    /* [out] */ IEnumProperty **ppiEnumProperty);


void __RPC_STUB IServiceInfo_EnumProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServiceInfo_GetProperty_Proxy( 
    IServiceInfo * This,
    /* [in] */ GUID PropId,
    /* [out] */ IProperty **ppiProperty);


void __RPC_STUB IServiceInfo_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServiceInfo_AddProperty_Proxy( 
    IServiceInfo * This,
    /* [in] */ GUID PropId,
    /* [full][in] */ LPCOLESTR pszLinkName,
    /* [out] */ IProperty **ppiProperty);


void __RPC_STUB IServiceInfo_AddProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServiceInfo_DeleteProperty_Proxy( 
    IServiceInfo * This,
    /* [in] */ GUID PropId);


void __RPC_STUB IServiceInfo_DeleteProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IServiceInfo_INTERFACE_DEFINED__ */


#ifndef __IEnumBootableDevice_INTERFACE_DEFINED__
#define __IEnumBootableDevice_INTERFACE_DEFINED__

/* interface IEnumBootableDevice */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumBootableDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B7D6E6F7-8D72-45f6-AE37-D7724989E5CB")
    IEnumBootableDevice : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IBootableDevice *rgelt[  ],
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumBootableDevice **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG *pcelt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNext( 
            /* [out] */ IBootableDevice **ppiBootableDevice) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumBootableDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumBootableDevice * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumBootableDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumBootableDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumBootableDevice * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IBootableDevice *rgelt[  ],
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumBootableDevice * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumBootableDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumBootableDevice * This,
            /* [out] */ IEnumBootableDevice **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IEnumBootableDevice * This,
            /* [out] */ ULONG *pcelt);
        
        HRESULT ( STDMETHODCALLTYPE *GetNext )( 
            IEnumBootableDevice * This,
            /* [out] */ IBootableDevice **ppiBootableDevice);
        
        END_INTERFACE
    } IEnumBootableDeviceVtbl;

    interface IEnumBootableDevice
    {
        CONST_VTBL struct IEnumBootableDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumBootableDevice_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumBootableDevice_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumBootableDevice_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumBootableDevice_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumBootableDevice_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumBootableDevice_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumBootableDevice_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#define IEnumBootableDevice_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)

#define IEnumBootableDevice_GetNext(This,ppiBootableDevice)	\
    (This)->lpVtbl -> GetNext(This,ppiBootableDevice)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumBootableDevice_Next_Proxy( 
    IEnumBootableDevice * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IBootableDevice *rgelt[  ],
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumBootableDevice_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumBootableDevice_Skip_Proxy( 
    IEnumBootableDevice * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumBootableDevice_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumBootableDevice_Reset_Proxy( 
    IEnumBootableDevice * This);


void __RPC_STUB IEnumBootableDevice_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumBootableDevice_Clone_Proxy( 
    IEnumBootableDevice * This,
    /* [out] */ IEnumBootableDevice **ppEnum);


void __RPC_STUB IEnumBootableDevice_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumBootableDevice_GetCount_Proxy( 
    IEnumBootableDevice * This,
    /* [out] */ ULONG *pcelt);


void __RPC_STUB IEnumBootableDevice_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumBootableDevice_GetNext_Proxy( 
    IEnumBootableDevice * This,
    /* [out] */ IBootableDevice **ppiBootableDevice);


void __RPC_STUB IEnumBootableDevice_GetNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumBootableDevice_INTERFACE_DEFINED__ */


#ifndef __IBootableDevice_INTERFACE_DEFINED__
#define __IBootableDevice_INTERFACE_DEFINED__

/* interface IBootableDevice */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBootableDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6014FEE5-B7BF-4c3c-A2B8-A9D0F8B64110")
    IBootableDevice : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBootableDeviceId( 
            /* [out] */ GUID *pBootableDeviceId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBootableDeviceName( 
            /* [out] */ LPOLESTR *ppszBootableDeviceName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetService( 
            /* [in] */ GUID ServiceCategoryId,
            /* [out] */ IService **ppiService) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumProperties( 
            /* [out] */ IEnumProperty **ppiEnumProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteProperty( 
            /* [in] */ GUID PropId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShutdownService( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBootableDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBootableDevice * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBootableDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBootableDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBootableDeviceId )( 
            IBootableDevice * This,
            /* [out] */ GUID *pBootableDeviceId);
        
        HRESULT ( STDMETHODCALLTYPE *GetBootableDeviceName )( 
            IBootableDevice * This,
            /* [out] */ LPOLESTR *ppszBootableDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *GetService )( 
            IBootableDevice * This,
            /* [in] */ GUID ServiceCategoryId,
            /* [out] */ IService **ppiService);
        
        HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IBootableDevice * This,
            /* [out] */ IEnumProperty **ppiEnumProperty);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IBootableDevice * This,
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IBootableDevice * This,
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IBootableDevice * This,
            /* [in] */ GUID PropId);
        
        HRESULT ( STDMETHODCALLTYPE *ShutdownService )( 
            IBootableDevice * This);
        
        END_INTERFACE
    } IBootableDeviceVtbl;

    interface IBootableDevice
    {
        CONST_VTBL struct IBootableDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBootableDevice_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBootableDevice_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBootableDevice_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBootableDevice_GetBootableDeviceId(This,pBootableDeviceId)	\
    (This)->lpVtbl -> GetBootableDeviceId(This,pBootableDeviceId)

#define IBootableDevice_GetBootableDeviceName(This,ppszBootableDeviceName)	\
    (This)->lpVtbl -> GetBootableDeviceName(This,ppszBootableDeviceName)

#define IBootableDevice_GetService(This,ServiceCategoryId,ppiService)	\
    (This)->lpVtbl -> GetService(This,ServiceCategoryId,ppiService)

#define IBootableDevice_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IBootableDevice_GetProperty(This,PropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,PropId,ppiProperty)

#define IBootableDevice_AddProperty(This,PropId,pszLinkName,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,PropId,pszLinkName,ppiProperty)

#define IBootableDevice_DeleteProperty(This,PropId)	\
    (This)->lpVtbl -> DeleteProperty(This,PropId)

#define IBootableDevice_ShutdownService(This)	\
    (This)->lpVtbl -> ShutdownService(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IBootableDevice_GetBootableDeviceId_Proxy( 
    IBootableDevice * This,
    /* [out] */ GUID *pBootableDeviceId);


void __RPC_STUB IBootableDevice_GetBootableDeviceId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBootableDevice_GetBootableDeviceName_Proxy( 
    IBootableDevice * This,
    /* [out] */ LPOLESTR *ppszBootableDeviceName);


void __RPC_STUB IBootableDevice_GetBootableDeviceName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBootableDevice_GetService_Proxy( 
    IBootableDevice * This,
    /* [in] */ GUID ServiceCategoryId,
    /* [out] */ IService **ppiService);


void __RPC_STUB IBootableDevice_GetService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBootableDevice_EnumProperties_Proxy( 
    IBootableDevice * This,
    /* [out] */ IEnumProperty **ppiEnumProperty);


void __RPC_STUB IBootableDevice_EnumProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBootableDevice_GetProperty_Proxy( 
    IBootableDevice * This,
    /* [in] */ GUID PropId,
    /* [out] */ IProperty **ppiProperty);


void __RPC_STUB IBootableDevice_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBootableDevice_AddProperty_Proxy( 
    IBootableDevice * This,
    /* [in] */ GUID PropId,
    /* [full][in] */ LPCOLESTR pszLinkName,
    /* [out] */ IProperty **ppiProperty);


void __RPC_STUB IBootableDevice_AddProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBootableDevice_DeleteProperty_Proxy( 
    IBootableDevice * This,
    /* [in] */ GUID PropId);


void __RPC_STUB IBootableDevice_DeleteProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBootableDevice_ShutdownService_Proxy( 
    IBootableDevice * This);


void __RPC_STUB IBootableDevice_ShutdownService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBootableDevice_INTERFACE_DEFINED__ */


#ifndef __IService_INTERFACE_DEFINED__
#define __IService_INTERFACE_DEFINED__

/* interface IService */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E408B5F2-348F-4263-B551-6437635C46E8")
    IService : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitService( 
            /* [in] */ IBootableDevice *piBootableDevice,
            /* [in] */ IServiceInfo *piServiceInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceCLSID( 
            /* [out] */ GUID *pServiceCLSID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceCategoryId( 
            /* [out] */ GUID *pServiceCategoryId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsServiceReleaseable( 
            /* [out] */ BOOL *pBool) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsServiceConfigured( 
            /* [out] */ BOOL *pConfigured) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServiceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IService * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IService * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IService * This);
        
        HRESULT ( STDMETHODCALLTYPE *InitService )( 
            IService * This,
            /* [in] */ IBootableDevice *piBootableDevice,
            /* [in] */ IServiceInfo *piServiceInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceCLSID )( 
            IService * This,
            /* [out] */ GUID *pServiceCLSID);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceCategoryId )( 
            IService * This,
            /* [out] */ GUID *pServiceCategoryId);
        
        HRESULT ( STDMETHODCALLTYPE *IsServiceReleaseable )( 
            IService * This,
            /* [out] */ BOOL *pBool);
        
        HRESULT ( STDMETHODCALLTYPE *IsServiceConfigured )( 
            IService * This,
            /* [out] */ BOOL *pConfigured);
        
        END_INTERFACE
    } IServiceVtbl;

    interface IService
    {
        CONST_VTBL struct IServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IService_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IService_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IService_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IService_InitService(This,piBootableDevice,piServiceInfo)	\
    (This)->lpVtbl -> InitService(This,piBootableDevice,piServiceInfo)

#define IService_GetServiceCLSID(This,pServiceCLSID)	\
    (This)->lpVtbl -> GetServiceCLSID(This,pServiceCLSID)

#define IService_GetServiceCategoryId(This,pServiceCategoryId)	\
    (This)->lpVtbl -> GetServiceCategoryId(This,pServiceCategoryId)

#define IService_IsServiceReleaseable(This,pBool)	\
    (This)->lpVtbl -> IsServiceReleaseable(This,pBool)

#define IService_IsServiceConfigured(This,pConfigured)	\
    (This)->lpVtbl -> IsServiceConfigured(This,pConfigured)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IService_InitService_Proxy( 
    IService * This,
    /* [in] */ IBootableDevice *piBootableDevice,
    /* [in] */ IServiceInfo *piServiceInfo);


void __RPC_STUB IService_InitService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IService_GetServiceCLSID_Proxy( 
    IService * This,
    /* [out] */ GUID *pServiceCLSID);


void __RPC_STUB IService_GetServiceCLSID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IService_GetServiceCategoryId_Proxy( 
    IService * This,
    /* [out] */ GUID *pServiceCategoryId);


void __RPC_STUB IService_GetServiceCategoryId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IService_IsServiceReleaseable_Proxy( 
    IService * This,
    /* [out] */ BOOL *pBool);


void __RPC_STUB IService_IsServiceReleaseable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IService_IsServiceConfigured_Proxy( 
    IService * This,
    /* [out] */ BOOL *pConfigured);


void __RPC_STUB IService_IsServiceConfigured_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IService_INTERFACE_DEFINED__ */


#ifndef __IPMServiceNuke_INTERFACE_DEFINED__
#define __IPMServiceNuke_INTERFACE_DEFINED__

/* interface IPMServiceNuke */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPMServiceNuke;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BDAF11A3-78BD-4B32-91E8-8911B7A7FAAF")
    IPMServiceNuke : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE UnloadServiceProvider( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMServiceNukeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMServiceNuke * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMServiceNuke * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMServiceNuke * This);
        
        HRESULT ( STDMETHODCALLTYPE *UnloadServiceProvider )( 
            IPMServiceNuke * This);
        
        END_INTERFACE
    } IPMServiceNukeVtbl;

    interface IPMServiceNuke
    {
        CONST_VTBL struct IPMServiceNukeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMServiceNuke_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMServiceNuke_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMServiceNuke_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMServiceNuke_UnloadServiceProvider(This)	\
    (This)->lpVtbl -> UnloadServiceProvider(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPMServiceNuke_UnloadServiceProvider_Proxy( 
    IPMServiceNuke * This);


void __RPC_STUB IPMServiceNuke_UnloadServiceProvider_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMServiceNuke_INTERFACE_DEFINED__ */


#ifndef __IServiceConfig_INTERFACE_DEFINED__
#define __IServiceConfig_INTERFACE_DEFINED__

/* interface IServiceConfig */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IServiceConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("768C9904-36E1-423b-91B4-433D709B6A19")
    IServiceConfig : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ConfigureServiceUI( 
            /* [in] */ HWND hWnd,
            /* [in] */ IBootableDevice *piDevice,
            /* [in] */ IServiceInfo *piServiceInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServiceConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IServiceConfig * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IServiceConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IServiceConfig * This);
        
        HRESULT ( STDMETHODCALLTYPE *ConfigureServiceUI )( 
            IServiceConfig * This,
            /* [in] */ HWND hWnd,
            /* [in] */ IBootableDevice *piDevice,
            /* [in] */ IServiceInfo *piServiceInfo);
        
        END_INTERFACE
    } IServiceConfigVtbl;

    interface IServiceConfig
    {
        CONST_VTBL struct IServiceConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServiceConfig_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServiceConfig_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServiceConfig_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServiceConfig_ConfigureServiceUI(This,hWnd,piDevice,piServiceInfo)	\
    (This)->lpVtbl -> ConfigureServiceUI(This,hWnd,piDevice,piServiceInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IServiceConfig_ConfigureServiceUI_Proxy( 
    IServiceConfig * This,
    /* [in] */ HWND hWnd,
    /* [in] */ IBootableDevice *piDevice,
    /* [in] */ IServiceInfo *piServiceInfo);


void __RPC_STUB IServiceConfig_ConfigureServiceUI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IServiceConfig_INTERFACE_DEFINED__ */


#ifndef __IEnumPlatformCE_INTERFACE_DEFINED__
#define __IEnumPlatformCE_INTERFACE_DEFINED__

/* interface IEnumPlatformCE */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumPlatformCE;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F384D885-F9AA-11D1-BB9E-00A0C9C9CCEE")
    IEnumPlatformCE : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IPlatformCE *rgelt[  ],
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumPlatformCE **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG *pcelt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNext( 
            /* [out] */ IPlatformCE **ppiPlatform) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumPlatformCEVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumPlatformCE * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumPlatformCE * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumPlatformCE * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumPlatformCE * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IPlatformCE *rgelt[  ],
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumPlatformCE * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumPlatformCE * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumPlatformCE * This,
            /* [out] */ IEnumPlatformCE **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IEnumPlatformCE * This,
            /* [out] */ ULONG *pcelt);
        
        HRESULT ( STDMETHODCALLTYPE *GetNext )( 
            IEnumPlatformCE * This,
            /* [out] */ IPlatformCE **ppiPlatform);
        
        END_INTERFACE
    } IEnumPlatformCEVtbl;

    interface IEnumPlatformCE
    {
        CONST_VTBL struct IEnumPlatformCEVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumPlatformCE_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumPlatformCE_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumPlatformCE_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumPlatformCE_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumPlatformCE_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumPlatformCE_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumPlatformCE_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#define IEnumPlatformCE_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)

#define IEnumPlatformCE_GetNext(This,ppiPlatform)	\
    (This)->lpVtbl -> GetNext(This,ppiPlatform)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumPlatformCE_Next_Proxy( 
    IEnumPlatformCE * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IPlatformCE *rgelt[  ],
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumPlatformCE_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPlatformCE_Skip_Proxy( 
    IEnumPlatformCE * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumPlatformCE_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPlatformCE_Reset_Proxy( 
    IEnumPlatformCE * This);


void __RPC_STUB IEnumPlatformCE_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPlatformCE_Clone_Proxy( 
    IEnumPlatformCE * This,
    /* [out] */ IEnumPlatformCE **ppEnum);


void __RPC_STUB IEnumPlatformCE_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPlatformCE_GetCount_Proxy( 
    IEnumPlatformCE * This,
    /* [out] */ ULONG *pcelt);


void __RPC_STUB IEnumPlatformCE_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPlatformCE_GetNext_Proxy( 
    IEnumPlatformCE * This,
    /* [out] */ IPlatformCE **ppiPlatform);


void __RPC_STUB IEnumPlatformCE_GetNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumPlatformCE_INTERFACE_DEFINED__ */


#ifndef __IPlatformCE_INTERFACE_DEFINED__
#define __IPlatformCE_INTERFACE_DEFINED__

/* interface IPlatformCE */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPlatformCE;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F384D888-F9AA-11D1-BB9E-00A0C9C9CCEE")
    IPlatformCE : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPlatformId( 
            /* [out] */ GUID *pPlatformId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumProperties( 
            /* [out] */ IEnumProperty **ppiEnumProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteProperty( 
            /* [in] */ GUID PropId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPlatformName( 
            /* [out] */ LPOLESTR *ppszPlatformName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumDevices( 
            /* [out] */ IEnumDevice **ppiEnumDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [in] */ GUID DeviceId,
            /* [out] */ IRemoteDevice **ppiRemoteDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumCPU( 
            /* [out] */ IEnumCPU **ppiEnumCPU) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOSInfo( 
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ LPWORD pwMinorVersion) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlatformCEVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlatformCE * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlatformCE * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlatformCE * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPlatformId )( 
            IPlatformCE * This,
            /* [out] */ GUID *pPlatformId);
        
        HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IPlatformCE * This,
            /* [out] */ IEnumProperty **ppiEnumProperty);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IPlatformCE * This,
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IPlatformCE * This,
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IPlatformCE * This,
            /* [in] */ GUID PropId);
        
        HRESULT ( STDMETHODCALLTYPE *GetPlatformName )( 
            IPlatformCE * This,
            /* [out] */ LPOLESTR *ppszPlatformName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumDevices )( 
            IPlatformCE * This,
            /* [out] */ IEnumDevice **ppiEnumDevice);
        
        HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IPlatformCE * This,
            /* [in] */ GUID DeviceId,
            /* [out] */ IRemoteDevice **ppiRemoteDevice);
        
        HRESULT ( STDMETHODCALLTYPE *EnumCPU )( 
            IPlatformCE * This,
            /* [out] */ IEnumCPU **ppiEnumCPU);
        
        HRESULT ( STDMETHODCALLTYPE *GetOSInfo )( 
            IPlatformCE * This,
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ LPWORD pwMinorVersion);
        
        END_INTERFACE
    } IPlatformCEVtbl;

    interface IPlatformCE
    {
        CONST_VTBL struct IPlatformCEVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlatformCE_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlatformCE_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlatformCE_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlatformCE_GetPlatformId(This,pPlatformId)	\
    (This)->lpVtbl -> GetPlatformId(This,pPlatformId)

#define IPlatformCE_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IPlatformCE_GetProperty(This,PropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,PropId,ppiProperty)

#define IPlatformCE_AddProperty(This,PropId,pszLinkName,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,PropId,pszLinkName,ppiProperty)

#define IPlatformCE_DeleteProperty(This,PropId)	\
    (This)->lpVtbl -> DeleteProperty(This,PropId)

#define IPlatformCE_GetPlatformName(This,ppszPlatformName)	\
    (This)->lpVtbl -> GetPlatformName(This,ppszPlatformName)

#define IPlatformCE_EnumDevices(This,ppiEnumDevice)	\
    (This)->lpVtbl -> EnumDevices(This,ppiEnumDevice)

#define IPlatformCE_GetDevice(This,DeviceId,ppiRemoteDevice)	\
    (This)->lpVtbl -> GetDevice(This,DeviceId,ppiRemoteDevice)

#define IPlatformCE_EnumCPU(This,ppiEnumCPU)	\
    (This)->lpVtbl -> EnumCPU(This,ppiEnumCPU)

#define IPlatformCE_GetOSInfo(This,pwMajorVersion,pwMinorVersion)	\
    (This)->lpVtbl -> GetOSInfo(This,pwMajorVersion,pwMinorVersion)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlatformCE_GetPlatformId_Proxy( 
    IPlatformCE * This,
    /* [out] */ GUID *pPlatformId);


void __RPC_STUB IPlatformCE_GetPlatformId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformCE_EnumProperties_Proxy( 
    IPlatformCE * This,
    /* [out] */ IEnumProperty **ppiEnumProperty);


void __RPC_STUB IPlatformCE_EnumProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformCE_GetProperty_Proxy( 
    IPlatformCE * This,
    /* [in] */ GUID PropId,
    /* [out] */ IProperty **ppiProperty);


void __RPC_STUB IPlatformCE_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformCE_AddProperty_Proxy( 
    IPlatformCE * This,
    /* [in] */ GUID PropId,
    /* [full][in] */ LPCOLESTR pszLinkName,
    /* [out] */ IProperty **ppiProperty);


void __RPC_STUB IPlatformCE_AddProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformCE_DeleteProperty_Proxy( 
    IPlatformCE * This,
    /* [in] */ GUID PropId);


void __RPC_STUB IPlatformCE_DeleteProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformCE_GetPlatformName_Proxy( 
    IPlatformCE * This,
    /* [out] */ LPOLESTR *ppszPlatformName);


void __RPC_STUB IPlatformCE_GetPlatformName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformCE_EnumDevices_Proxy( 
    IPlatformCE * This,
    /* [out] */ IEnumDevice **ppiEnumDevice);


void __RPC_STUB IPlatformCE_EnumDevices_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformCE_GetDevice_Proxy( 
    IPlatformCE * This,
    /* [in] */ GUID DeviceId,
    /* [out] */ IRemoteDevice **ppiRemoteDevice);


void __RPC_STUB IPlatformCE_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformCE_EnumCPU_Proxy( 
    IPlatformCE * This,
    /* [out] */ IEnumCPU **ppiEnumCPU);


void __RPC_STUB IPlatformCE_EnumCPU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformCE_GetOSInfo_Proxy( 
    IPlatformCE * This,
    /* [out] */ LPWORD pwMajorVersion,
    /* [out] */ LPWORD pwMinorVersion);


void __RPC_STUB IPlatformCE_GetOSInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlatformCE_INTERFACE_DEFINED__ */


#ifndef __IRemoteDevice_INTERFACE_DEFINED__
#define __IRemoteDevice_INTERFACE_DEFINED__

/* interface IRemoteDevice */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRemoteDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F384D88B-F9AA-11D1-BB9E-00A0C9C9CCEE")
    IRemoteDevice : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumProperties( 
            /* [out] */ IEnumProperty **ppiEnumProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteProperty( 
            /* [in] */ GUID PropId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceId( 
            /* [out] */ GUID *pDeviceId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceType( 
            /* [out] */ DEVICE_TYPE *pdt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceName( 
            /* [out] */ LPOLESTR *ppszDeviceName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Attach( 
            /* [in] */ DWORD dwProcessId,
            /* [in] */ LPCOLESTR pszProcessName,
            /* [in] */ DWORD dwTimeOut,
            /* [out] */ IConnection **ppiConnection,
            /* [in] */ ICallBack *piCallBack) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRemoteDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRemoteDevice * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRemoteDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRemoteDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IRemoteDevice * This,
            /* [out] */ IEnumProperty **ppiEnumProperty);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IRemoteDevice * This,
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IRemoteDevice * This,
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IRemoteDevice * This,
            /* [in] */ GUID PropId);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceId )( 
            IRemoteDevice * This,
            /* [out] */ GUID *pDeviceId);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceType )( 
            IRemoteDevice * This,
            /* [out] */ DEVICE_TYPE *pdt);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceName )( 
            IRemoteDevice * This,
            /* [out] */ LPOLESTR *ppszDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IRemoteDevice * This,
            /* [in] */ DWORD dwProcessId,
            /* [in] */ LPCOLESTR pszProcessName,
            /* [in] */ DWORD dwTimeOut,
            /* [out] */ IConnection **ppiConnection,
            /* [in] */ ICallBack *piCallBack);
        
        END_INTERFACE
    } IRemoteDeviceVtbl;

    interface IRemoteDevice
    {
        CONST_VTBL struct IRemoteDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRemoteDevice_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRemoteDevice_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRemoteDevice_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRemoteDevice_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IRemoteDevice_GetProperty(This,PropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,PropId,ppiProperty)

#define IRemoteDevice_AddProperty(This,PropId,pszLinkName,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,PropId,pszLinkName,ppiProperty)

#define IRemoteDevice_DeleteProperty(This,PropId)	\
    (This)->lpVtbl -> DeleteProperty(This,PropId)

#define IRemoteDevice_GetDeviceId(This,pDeviceId)	\
    (This)->lpVtbl -> GetDeviceId(This,pDeviceId)

#define IRemoteDevice_GetDeviceType(This,pdt)	\
    (This)->lpVtbl -> GetDeviceType(This,pdt)

#define IRemoteDevice_GetDeviceName(This,ppszDeviceName)	\
    (This)->lpVtbl -> GetDeviceName(This,ppszDeviceName)

#define IRemoteDevice_Attach(This,dwProcessId,pszProcessName,dwTimeOut,ppiConnection,piCallBack)	\
    (This)->lpVtbl -> Attach(This,dwProcessId,pszProcessName,dwTimeOut,ppiConnection,piCallBack)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRemoteDevice_EnumProperties_Proxy( 
    IRemoteDevice * This,
    /* [out] */ IEnumProperty **ppiEnumProperty);


void __RPC_STUB IRemoteDevice_EnumProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteDevice_GetProperty_Proxy( 
    IRemoteDevice * This,
    /* [in] */ GUID PropId,
    /* [out] */ IProperty **ppiProperty);


void __RPC_STUB IRemoteDevice_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteDevice_AddProperty_Proxy( 
    IRemoteDevice * This,
    /* [in] */ GUID PropId,
    /* [full][in] */ LPCOLESTR pszLinkName,
    /* [out] */ IProperty **ppiProperty);


void __RPC_STUB IRemoteDevice_AddProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteDevice_DeleteProperty_Proxy( 
    IRemoteDevice * This,
    /* [in] */ GUID PropId);


void __RPC_STUB IRemoteDevice_DeleteProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteDevice_GetDeviceId_Proxy( 
    IRemoteDevice * This,
    /* [out] */ GUID *pDeviceId);


void __RPC_STUB IRemoteDevice_GetDeviceId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteDevice_GetDeviceType_Proxy( 
    IRemoteDevice * This,
    /* [out] */ DEVICE_TYPE *pdt);


void __RPC_STUB IRemoteDevice_GetDeviceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteDevice_GetDeviceName_Proxy( 
    IRemoteDevice * This,
    /* [out] */ LPOLESTR *ppszDeviceName);


void __RPC_STUB IRemoteDevice_GetDeviceName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteDevice_Attach_Proxy( 
    IRemoteDevice * This,
    /* [in] */ DWORD dwProcessId,
    /* [in] */ LPCOLESTR pszProcessName,
    /* [in] */ DWORD dwTimeOut,
    /* [out] */ IConnection **ppiConnection,
    /* [in] */ ICallBack *piCallBack);


void __RPC_STUB IRemoteDevice_Attach_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRemoteDevice_INTERFACE_DEFINED__ */


#ifndef __IRemoteDevice2_INTERFACE_DEFINED__
#define __IRemoteDevice2_INTERFACE_DEFINED__

/* interface IRemoteDevice2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRemoteDevice2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4C0EE08-FC65-40f0-863E-B3C891A750C2")
    IRemoteDevice2 : public IRemoteDevice
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetConnection( 
            /* [in] */ GUID ConnectId,
            /* [out] */ IConnection **ppiConnection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRemoteDevice2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRemoteDevice2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRemoteDevice2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRemoteDevice2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IRemoteDevice2 * This,
            /* [out] */ IEnumProperty **ppiEnumProperty);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IRemoteDevice2 * This,
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IRemoteDevice2 * This,
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IRemoteDevice2 * This,
            /* [in] */ GUID PropId);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceId )( 
            IRemoteDevice2 * This,
            /* [out] */ GUID *pDeviceId);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceType )( 
            IRemoteDevice2 * This,
            /* [out] */ DEVICE_TYPE *pdt);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceName )( 
            IRemoteDevice2 * This,
            /* [out] */ LPOLESTR *ppszDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IRemoteDevice2 * This,
            /* [in] */ DWORD dwProcessId,
            /* [in] */ LPCOLESTR pszProcessName,
            /* [in] */ DWORD dwTimeOut,
            /* [out] */ IConnection **ppiConnection,
            /* [in] */ ICallBack *piCallBack);
        
        HRESULT ( STDMETHODCALLTYPE *GetConnection )( 
            IRemoteDevice2 * This,
            /* [in] */ GUID ConnectId,
            /* [out] */ IConnection **ppiConnection);
        
        END_INTERFACE
    } IRemoteDevice2Vtbl;

    interface IRemoteDevice2
    {
        CONST_VTBL struct IRemoteDevice2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRemoteDevice2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRemoteDevice2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRemoteDevice2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRemoteDevice2_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IRemoteDevice2_GetProperty(This,PropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,PropId,ppiProperty)

#define IRemoteDevice2_AddProperty(This,PropId,pszLinkName,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,PropId,pszLinkName,ppiProperty)

#define IRemoteDevice2_DeleteProperty(This,PropId)	\
    (This)->lpVtbl -> DeleteProperty(This,PropId)

#define IRemoteDevice2_GetDeviceId(This,pDeviceId)	\
    (This)->lpVtbl -> GetDeviceId(This,pDeviceId)

#define IRemoteDevice2_GetDeviceType(This,pdt)	\
    (This)->lpVtbl -> GetDeviceType(This,pdt)

#define IRemoteDevice2_GetDeviceName(This,ppszDeviceName)	\
    (This)->lpVtbl -> GetDeviceName(This,ppszDeviceName)

#define IRemoteDevice2_Attach(This,dwProcessId,pszProcessName,dwTimeOut,ppiConnection,piCallBack)	\
    (This)->lpVtbl -> Attach(This,dwProcessId,pszProcessName,dwTimeOut,ppiConnection,piCallBack)


#define IRemoteDevice2_GetConnection(This,ConnectId,ppiConnection)	\
    (This)->lpVtbl -> GetConnection(This,ConnectId,ppiConnection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRemoteDevice2_GetConnection_Proxy( 
    IRemoteDevice2 * This,
    /* [in] */ GUID ConnectId,
    /* [out] */ IConnection **ppiConnection);


void __RPC_STUB IRemoteDevice2_GetConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRemoteDevice2_INTERFACE_DEFINED__ */


#ifndef __IEnumDevice_INTERFACE_DEFINED__
#define __IEnumDevice_INTERFACE_DEFINED__

/* interface IEnumDevice */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F384D88E-F9AA-11D1-BB9E-00A0C9C9CCEE")
    IEnumDevice : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IRemoteDevice *rgelt[  ],
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumDevice **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG *pcelt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNext( 
            /* [out] */ IRemoteDevice **ppiRemoteDevice) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumDevice * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumDevice * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IRemoteDevice *rgelt[  ],
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumDevice * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumDevice * This,
            /* [out] */ IEnumDevice **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IEnumDevice * This,
            /* [out] */ ULONG *pcelt);
        
        HRESULT ( STDMETHODCALLTYPE *GetNext )( 
            IEnumDevice * This,
            /* [out] */ IRemoteDevice **ppiRemoteDevice);
        
        END_INTERFACE
    } IEnumDeviceVtbl;

    interface IEnumDevice
    {
        CONST_VTBL struct IEnumDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumDevice_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumDevice_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumDevice_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumDevice_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumDevice_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumDevice_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumDevice_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#define IEnumDevice_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)

#define IEnumDevice_GetNext(This,ppiRemoteDevice)	\
    (This)->lpVtbl -> GetNext(This,ppiRemoteDevice)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumDevice_Next_Proxy( 
    IEnumDevice * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IRemoteDevice *rgelt[  ],
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumDevice_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumDevice_Skip_Proxy( 
    IEnumDevice * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumDevice_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumDevice_Reset_Proxy( 
    IEnumDevice * This);


void __RPC_STUB IEnumDevice_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumDevice_Clone_Proxy( 
    IEnumDevice * This,
    /* [out] */ IEnumDevice **ppEnum);


void __RPC_STUB IEnumDevice_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumDevice_GetCount_Proxy( 
    IEnumDevice * This,
    /* [out] */ ULONG *pcelt);


void __RPC_STUB IEnumDevice_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumDevice_GetNext_Proxy( 
    IEnumDevice * This,
    /* [out] */ IRemoteDevice **ppiRemoteDevice);


void __RPC_STUB IEnumDevice_GetNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumDevice_INTERFACE_DEFINED__ */


#ifndef __IEnumProperty_INTERFACE_DEFINED__
#define __IEnumProperty_INTERFACE_DEFINED__

/* interface IEnumProperty */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F384D891-F9AA-11D1-BB9E-00A0C9C9CCEE")
    IEnumProperty : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IProperty *rgelt[  ],
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumProperty **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG *pcelt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNext( 
            /* [out] */ IProperty **ppiProperty) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumPropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumProperty * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumProperty * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumProperty * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumProperty * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IProperty *rgelt[  ],
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumProperty * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumProperty * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumProperty * This,
            /* [out] */ IEnumProperty **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IEnumProperty * This,
            /* [out] */ ULONG *pcelt);
        
        HRESULT ( STDMETHODCALLTYPE *GetNext )( 
            IEnumProperty * This,
            /* [out] */ IProperty **ppiProperty);
        
        END_INTERFACE
    } IEnumPropertyVtbl;

    interface IEnumProperty
    {
        CONST_VTBL struct IEnumPropertyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumProperty_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumProperty_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumProperty_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumProperty_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumProperty_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumProperty_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumProperty_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#define IEnumProperty_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)

#define IEnumProperty_GetNext(This,ppiProperty)	\
    (This)->lpVtbl -> GetNext(This,ppiProperty)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumProperty_Next_Proxy( 
    IEnumProperty * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IProperty *rgelt[  ],
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumProperty_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumProperty_Skip_Proxy( 
    IEnumProperty * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumProperty_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumProperty_Reset_Proxy( 
    IEnumProperty * This);


void __RPC_STUB IEnumProperty_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumProperty_Clone_Proxy( 
    IEnumProperty * This,
    /* [out] */ IEnumProperty **ppEnum);


void __RPC_STUB IEnumProperty_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumProperty_GetCount_Proxy( 
    IEnumProperty * This,
    /* [out] */ ULONG *pcelt);


void __RPC_STUB IEnumProperty_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumProperty_GetNext_Proxy( 
    IEnumProperty * This,
    /* [out] */ IProperty **ppiProperty);


void __RPC_STUB IEnumProperty_GetNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumProperty_INTERFACE_DEFINED__ */


#ifndef __IProperty_INTERFACE_DEFINED__
#define __IProperty_INTERFACE_DEFINED__

/* interface IProperty */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F384D894-F9AA-11D1-BB9E-00A0C9C9CCEE")
    IProperty : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumProperties( 
            /* [out] */ IEnumProperty **ppiEnumProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyId( 
            /* [out] */ GUID *pPropId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteProperty( 
            /* [in] */ GUID PropId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumPropInfo( 
            /* [out] */ IEnumPropInfo **ppiEnumPropInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropInfo( 
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ DWORD dwPropSize,
            /* [in] */ DWORD dwPropType,
            /* [size_is][in] */ BYTE *pPropValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeletePropInfo( 
            /* [in] */ LPCOLESTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropInfo( 
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ DWORD dwSizeIn,
            /* [out] */ LPDWORD pdwPropType,
            /* [length_is][size_is][out] */ BYTE *pBuffer,
            /* [out] */ DWORD *pdwSizeReturned,
            /* [out] */ DWORD *pdwSizeActual) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProperty * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProperty * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProperty * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IProperty * This,
            /* [out] */ IEnumProperty **ppiEnumProperty);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyId )( 
            IProperty * This,
            /* [out] */ GUID *pPropId);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IProperty * This,
            /* [in] */ GUID PropId,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IProperty * This,
            /* [in] */ GUID PropId,
            /* [full][in] */ LPCOLESTR pszLinkName,
            /* [out] */ IProperty **ppiProperty);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IProperty * This,
            /* [in] */ GUID PropId);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPropInfo )( 
            IProperty * This,
            /* [out] */ IEnumPropInfo **ppiEnumPropInfo);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropInfo )( 
            IProperty * This,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ DWORD dwPropSize,
            /* [in] */ DWORD dwPropType,
            /* [size_is][in] */ BYTE *pPropValue);
        
        HRESULT ( STDMETHODCALLTYPE *DeletePropInfo )( 
            IProperty * This,
            /* [in] */ LPCOLESTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropInfo )( 
            IProperty * This,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ DWORD dwSizeIn,
            /* [out] */ LPDWORD pdwPropType,
            /* [length_is][size_is][out] */ BYTE *pBuffer,
            /* [out] */ DWORD *pdwSizeReturned,
            /* [out] */ DWORD *pdwSizeActual);
        
        END_INTERFACE
    } IPropertyVtbl;

    interface IProperty
    {
        CONST_VTBL struct IPropertyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProperty_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IProperty_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IProperty_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IProperty_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IProperty_GetPropertyId(This,pPropId)	\
    (This)->lpVtbl -> GetPropertyId(This,pPropId)

#define IProperty_GetProperty(This,PropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,PropId,ppiProperty)

#define IProperty_AddProperty(This,PropId,pszLinkName,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,PropId,pszLinkName,ppiProperty)

#define IProperty_DeleteProperty(This,PropId)	\
    (This)->lpVtbl -> DeleteProperty(This,PropId)

#define IProperty_EnumPropInfo(This,ppiEnumPropInfo)	\
    (This)->lpVtbl -> EnumPropInfo(This,ppiEnumPropInfo)

#define IProperty_SetPropInfo(This,pszName,dwPropSize,dwPropType,pPropValue)	\
    (This)->lpVtbl -> SetPropInfo(This,pszName,dwPropSize,dwPropType,pPropValue)

#define IProperty_DeletePropInfo(This,pszName)	\
    (This)->lpVtbl -> DeletePropInfo(This,pszName)

#define IProperty_GetPropInfo(This,pszName,dwSizeIn,pdwPropType,pBuffer,pdwSizeReturned,pdwSizeActual)	\
    (This)->lpVtbl -> GetPropInfo(This,pszName,dwSizeIn,pdwPropType,pBuffer,pdwSizeReturned,pdwSizeActual)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IProperty_EnumProperties_Proxy( 
    IProperty * This,
    /* [out] */ IEnumProperty **ppiEnumProperty);


void __RPC_STUB IProperty_EnumProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IProperty_GetPropertyId_Proxy( 
    IProperty * This,
    /* [out] */ GUID *pPropId);


void __RPC_STUB IProperty_GetPropertyId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IProperty_GetProperty_Proxy( 
    IProperty * This,
    /* [in] */ GUID PropId,
    /* [out] */ IProperty **ppiProperty);


void __RPC_STUB IProperty_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IProperty_AddProperty_Proxy( 
    IProperty * This,
    /* [in] */ GUID PropId,
    /* [full][in] */ LPCOLESTR pszLinkName,
    /* [out] */ IProperty **ppiProperty);


void __RPC_STUB IProperty_AddProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IProperty_DeleteProperty_Proxy( 
    IProperty * This,
    /* [in] */ GUID PropId);


void __RPC_STUB IProperty_DeleteProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IProperty_EnumPropInfo_Proxy( 
    IProperty * This,
    /* [out] */ IEnumPropInfo **ppiEnumPropInfo);


void __RPC_STUB IProperty_EnumPropInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IProperty_SetPropInfo_Proxy( 
    IProperty * This,
    /* [in] */ LPCOLESTR pszName,
    /* [in] */ DWORD dwPropSize,
    /* [in] */ DWORD dwPropType,
    /* [size_is][in] */ BYTE *pPropValue);


void __RPC_STUB IProperty_SetPropInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IProperty_DeletePropInfo_Proxy( 
    IProperty * This,
    /* [in] */ LPCOLESTR pszName);


void __RPC_STUB IProperty_DeletePropInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IProperty_GetPropInfo_Proxy( 
    IProperty * This,
    /* [in] */ LPCOLESTR pszName,
    /* [in] */ DWORD dwSizeIn,
    /* [out] */ LPDWORD pdwPropType,
    /* [length_is][size_is][out] */ BYTE *pBuffer,
    /* [out] */ DWORD *pdwSizeReturned,
    /* [out] */ DWORD *pdwSizeActual);


void __RPC_STUB IProperty_GetPropInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IProperty_INTERFACE_DEFINED__ */


#ifndef __IEnumPropInfo_INTERFACE_DEFINED__
#define __IEnumPropInfo_INTERFACE_DEFINED__

/* interface IEnumPropInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumPropInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F384D897-F9AA-11D1-BB9E-00A0C9C9CCEE")
    IEnumPropInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ LPOLESTR rgelt[  ],
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumPropInfo **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG *pcelt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNext( 
            /* [out] */ LPOLESTR *ppszName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumPropInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumPropInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumPropInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumPropInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumPropInfo * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ LPOLESTR rgelt[  ],
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumPropInfo * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumPropInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumPropInfo * This,
            /* [out] */ IEnumPropInfo **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IEnumPropInfo * This,
            /* [out] */ ULONG *pcelt);
        
        HRESULT ( STDMETHODCALLTYPE *GetNext )( 
            IEnumPropInfo * This,
            /* [out] */ LPOLESTR *ppszName);
        
        END_INTERFACE
    } IEnumPropInfoVtbl;

    interface IEnumPropInfo
    {
        CONST_VTBL struct IEnumPropInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumPropInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumPropInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumPropInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumPropInfo_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumPropInfo_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumPropInfo_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumPropInfo_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#define IEnumPropInfo_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)

#define IEnumPropInfo_GetNext(This,ppszName)	\
    (This)->lpVtbl -> GetNext(This,ppszName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumPropInfo_Next_Proxy( 
    IEnumPropInfo * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ LPOLESTR rgelt[  ],
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumPropInfo_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPropInfo_Skip_Proxy( 
    IEnumPropInfo * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumPropInfo_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPropInfo_Reset_Proxy( 
    IEnumPropInfo * This);


void __RPC_STUB IEnumPropInfo_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPropInfo_Clone_Proxy( 
    IEnumPropInfo * This,
    /* [out] */ IEnumPropInfo **ppEnum);


void __RPC_STUB IEnumPropInfo_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPropInfo_GetCount_Proxy( 
    IEnumPropInfo * This,
    /* [out] */ ULONG *pcelt);


void __RPC_STUB IEnumPropInfo_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPropInfo_GetNext_Proxy( 
    IEnumPropInfo * This,
    /* [out] */ LPOLESTR *ppszName);


void __RPC_STUB IEnumPropInfo_GetNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumPropInfo_INTERFACE_DEFINED__ */


#ifndef __IConnection_INTERFACE_DEFINED__
#define __IConnection_INTERFACE_DEFINED__

/* interface IConnection */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA438BAA-FA87-11D1-BB9E-00A0C9C9CCEE")
    IConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE FileCopy( 
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDest,
            /* [in] */ BOOL fOverWrite,
            /* [in] */ ICallBack *piCallBack,
            /* [out] */ LPDWORD pdwTotalSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyPackage( 
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszDestPath,
            /* [in] */ BOOL fOverWrite,
            /* [in] */ ICallBack *piCallBack,
            /* [out] */ LPDWORD pdwTotalSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueuePackage( 
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszDestPath,
            /* [in] */ BOOL fOverWrite) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueueFile( 
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDest,
            /* [in] */ BOOL fOverWrite) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyQueuedFiles( 
            /* [in] */ ICallBack *piCallBack,
            /* [out] */ LPDWORD pdwTotalSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetQueueCount( 
            /* [out] */ LPDWORD pdwCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Launch( 
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [full][in] */ LPCOLESTR pszCmdLine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SystemGetInfo( 
            /* [out] */ LPWORD pwArchitecture,
            /* [out] */ LPDWORD pdwCPUType,
            /* [out] */ LPDWORD pdwPageSize,
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ LPWORD pwMinorVersion) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FileGetInfo( 
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [out] */ LPDWORD pdwFileAttributes,
            /* [out] */ LPDWORD pdwFileSize,
            /* [out] */ LPFILETIME pCreationTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FileDelete( 
            /* [in] */ LPCOLESTR pszFullPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateStream( 
            /* [in] */ GUID HostId,
            /* [in] */ DWORD dwPortId,
            /* [out] */ IConnectionStream **ppiConnectionStream,
            /* [in] */ ICallBack *piCallBack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLocalInfo( 
            /* [out] */ LPDWORD pdwLocaleId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFile( 
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [in] */ LPCOLESTR pszDest,
            /* [in] */ ICallBack *piCallBack,
            /* [out] */ LPDWORD pdwTotalSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPlatformId( 
            /* [out] */ GUID *pPlatformId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetQueue( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseAllStreams( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IConnection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *FileCopy )( 
            IConnection * This,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDest,
            /* [in] */ BOOL fOverWrite,
            /* [in] */ ICallBack *piCallBack,
            /* [out] */ LPDWORD pdwTotalSize);
        
        HRESULT ( STDMETHODCALLTYPE *CopyPackage )( 
            IConnection * This,
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszDestPath,
            /* [in] */ BOOL fOverWrite,
            /* [in] */ ICallBack *piCallBack,
            /* [out] */ LPDWORD pdwTotalSize);
        
        HRESULT ( STDMETHODCALLTYPE *QueuePackage )( 
            IConnection * This,
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszDestPath,
            /* [in] */ BOOL fOverWrite);
        
        HRESULT ( STDMETHODCALLTYPE *QueueFile )( 
            IConnection * This,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDest,
            /* [in] */ BOOL fOverWrite);
        
        HRESULT ( STDMETHODCALLTYPE *CopyQueuedFiles )( 
            IConnection * This,
            /* [in] */ ICallBack *piCallBack,
            /* [out] */ LPDWORD pdwTotalSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetQueueCount )( 
            IConnection * This,
            /* [out] */ LPDWORD pdwCount);
        
        HRESULT ( STDMETHODCALLTYPE *Launch )( 
            IConnection * This,
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [full][in] */ LPCOLESTR pszCmdLine);
        
        HRESULT ( STDMETHODCALLTYPE *SystemGetInfo )( 
            IConnection * This,
            /* [out] */ LPWORD pwArchitecture,
            /* [out] */ LPDWORD pdwCPUType,
            /* [out] */ LPDWORD pdwPageSize,
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ LPWORD pwMinorVersion);
        
        HRESULT ( STDMETHODCALLTYPE *FileGetInfo )( 
            IConnection * This,
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [out] */ LPDWORD pdwFileAttributes,
            /* [out] */ LPDWORD pdwFileSize,
            /* [out] */ LPFILETIME pCreationTime);
        
        HRESULT ( STDMETHODCALLTYPE *FileDelete )( 
            IConnection * This,
            /* [in] */ LPCOLESTR pszFullPath);
        
        HRESULT ( STDMETHODCALLTYPE *CreateStream )( 
            IConnection * This,
            /* [in] */ GUID HostId,
            /* [in] */ DWORD dwPortId,
            /* [out] */ IConnectionStream **ppiConnectionStream,
            /* [in] */ ICallBack *piCallBack);
        
        HRESULT ( STDMETHODCALLTYPE *GetLocalInfo )( 
            IConnection * This,
            /* [out] */ LPDWORD pdwLocaleId);
        
        HRESULT ( STDMETHODCALLTYPE *GetFile )( 
            IConnection * This,
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [in] */ LPCOLESTR pszDest,
            /* [in] */ ICallBack *piCallBack,
            /* [out] */ LPDWORD pdwTotalSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPlatformId )( 
            IConnection * This,
            /* [out] */ GUID *pPlatformId);
        
        HRESULT ( STDMETHODCALLTYPE *ResetQueue )( 
            IConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *CloseAllStreams )( 
            IConnection * This);
        
        END_INTERFACE
    } IConnectionVtbl;

    interface IConnection
    {
        CONST_VTBL struct IConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConnection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IConnection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IConnection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IConnection_FileCopy(This,pszSource,pszDest,fOverWrite,piCallBack,pdwTotalSize)	\
    (This)->lpVtbl -> FileCopy(This,pszSource,pszDest,fOverWrite,piCallBack,pdwTotalSize)

#define IConnection_CopyPackage(This,PackageId,pszDestPath,fOverWrite,piCallBack,pdwTotalSize)	\
    (This)->lpVtbl -> CopyPackage(This,PackageId,pszDestPath,fOverWrite,piCallBack,pdwTotalSize)

#define IConnection_QueuePackage(This,PackageId,pszDestPath,fOverWrite)	\
    (This)->lpVtbl -> QueuePackage(This,PackageId,pszDestPath,fOverWrite)

#define IConnection_QueueFile(This,pszSource,pszDest,fOverWrite)	\
    (This)->lpVtbl -> QueueFile(This,pszSource,pszDest,fOverWrite)

#define IConnection_CopyQueuedFiles(This,piCallBack,pdwTotalSize)	\
    (This)->lpVtbl -> CopyQueuedFiles(This,piCallBack,pdwTotalSize)

#define IConnection_GetQueueCount(This,pdwCount)	\
    (This)->lpVtbl -> GetQueueCount(This,pdwCount)

#define IConnection_Launch(This,pszRemotePath,pszCmdLine)	\
    (This)->lpVtbl -> Launch(This,pszRemotePath,pszCmdLine)

#define IConnection_SystemGetInfo(This,pwArchitecture,pdwCPUType,pdwPageSize,pwMajorVersion,pwMinorVersion)	\
    (This)->lpVtbl -> SystemGetInfo(This,pwArchitecture,pdwCPUType,pdwPageSize,pwMajorVersion,pwMinorVersion)

#define IConnection_FileGetInfo(This,pszRemotePath,pdwFileAttributes,pdwFileSize,pCreationTime)	\
    (This)->lpVtbl -> FileGetInfo(This,pszRemotePath,pdwFileAttributes,pdwFileSize,pCreationTime)

#define IConnection_FileDelete(This,pszFullPath)	\
    (This)->lpVtbl -> FileDelete(This,pszFullPath)

#define IConnection_CreateStream(This,HostId,dwPortId,ppiConnectionStream,piCallBack)	\
    (This)->lpVtbl -> CreateStream(This,HostId,dwPortId,ppiConnectionStream,piCallBack)

#define IConnection_GetLocalInfo(This,pdwLocaleId)	\
    (This)->lpVtbl -> GetLocalInfo(This,pdwLocaleId)

#define IConnection_GetFile(This,pszRemotePath,pszDest,piCallBack,pdwTotalSize)	\
    (This)->lpVtbl -> GetFile(This,pszRemotePath,pszDest,piCallBack,pdwTotalSize)

#define IConnection_GetPlatformId(This,pPlatformId)	\
    (This)->lpVtbl -> GetPlatformId(This,pPlatformId)

#define IConnection_ResetQueue(This)	\
    (This)->lpVtbl -> ResetQueue(This)

#define IConnection_CloseAllStreams(This)	\
    (This)->lpVtbl -> CloseAllStreams(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IConnection_FileCopy_Proxy( 
    IConnection * This,
    /* [in] */ LPCOLESTR pszSource,
    /* [in] */ LPCOLESTR pszDest,
    /* [in] */ BOOL fOverWrite,
    /* [in] */ ICallBack *piCallBack,
    /* [out] */ LPDWORD pdwTotalSize);


void __RPC_STUB IConnection_FileCopy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection_CopyPackage_Proxy( 
    IConnection * This,
    /* [in] */ GUID PackageId,
    /* [in] */ LPCOLESTR pszDestPath,
    /* [in] */ BOOL fOverWrite,
    /* [in] */ ICallBack *piCallBack,
    /* [out] */ LPDWORD pdwTotalSize);


void __RPC_STUB IConnection_CopyPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection_QueuePackage_Proxy( 
    IConnection * This,
    /* [in] */ GUID PackageId,
    /* [in] */ LPCOLESTR pszDestPath,
    /* [in] */ BOOL fOverWrite);


void __RPC_STUB IConnection_QueuePackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection_QueueFile_Proxy( 
    IConnection * This,
    /* [in] */ LPCOLESTR pszSource,
    /* [in] */ LPCOLESTR pszDest,
    /* [in] */ BOOL fOverWrite);


void __RPC_STUB IConnection_QueueFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection_CopyQueuedFiles_Proxy( 
    IConnection * This,
    /* [in] */ ICallBack *piCallBack,
    /* [out] */ LPDWORD pdwTotalSize);


void __RPC_STUB IConnection_CopyQueuedFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection_GetQueueCount_Proxy( 
    IConnection * This,
    /* [out] */ LPDWORD pdwCount);


void __RPC_STUB IConnection_GetQueueCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection_Launch_Proxy( 
    IConnection * This,
    /* [in] */ LPCOLESTR pszRemotePath,
    /* [full][in] */ LPCOLESTR pszCmdLine);


void __RPC_STUB IConnection_Launch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection_SystemGetInfo_Proxy( 
    IConnection * This,
    /* [out] */ LPWORD pwArchitecture,
    /* [out] */ LPDWORD pdwCPUType,
    /* [out] */ LPDWORD pdwPageSize,
    /* [out] */ LPWORD pwMajorVersion,
    /* [out] */ LPWORD pwMinorVersion);


void __RPC_STUB IConnection_SystemGetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection_FileGetInfo_Proxy( 
    IConnection * This,
    /* [in] */ LPCOLESTR pszRemotePath,
    /* [out] */ LPDWORD pdwFileAttributes,
    /* [out] */ LPDWORD pdwFileSize,
    /* [out] */ LPFILETIME pCreationTime);


void __RPC_STUB IConnection_FileGetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection_FileDelete_Proxy( 
    IConnection * This,
    /* [in] */ LPCOLESTR pszFullPath);


void __RPC_STUB IConnection_FileDelete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection_CreateStream_Proxy( 
    IConnection * This,
    /* [in] */ GUID HostId,
    /* [in] */ DWORD dwPortId,
    /* [out] */ IConnectionStream **ppiConnectionStream,
    /* [in] */ ICallBack *piCallBack);


void __RPC_STUB IConnection_CreateStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection_GetLocalInfo_Proxy( 
    IConnection * This,
    /* [out] */ LPDWORD pdwLocaleId);


void __RPC_STUB IConnection_GetLocalInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection_GetFile_Proxy( 
    IConnection * This,
    /* [in] */ LPCOLESTR pszRemotePath,
    /* [in] */ LPCOLESTR pszDest,
    /* [in] */ ICallBack *piCallBack,
    /* [out] */ LPDWORD pdwTotalSize);


void __RPC_STUB IConnection_GetFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection_GetPlatformId_Proxy( 
    IConnection * This,
    /* [out] */ GUID *pPlatformId);


void __RPC_STUB IConnection_GetPlatformId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection_ResetQueue_Proxy( 
    IConnection * This);


void __RPC_STUB IConnection_ResetQueue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection_CloseAllStreams_Proxy( 
    IConnection * This);


void __RPC_STUB IConnection_CloseAllStreams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IConnection_INTERFACE_DEFINED__ */


#ifndef __IConnection2_INTERFACE_DEFINED__
#define __IConnection2_INTERFACE_DEFINED__

/* interface IConnection2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IConnection2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("073E4A43-45BC-46ef-B114-F42BA51C6366")
    IConnection2 : public IConnection
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SystemGetInfoEx( 
            /* [out] */ LPWORD pwArchitecture,
            /* [out] */ LPDWORD pdwCPUType,
            /* [out] */ LPDWORD pdwPageSize,
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ LPWORD pwMinorVersion,
            /* [out] */ GUID *OSTypeId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConnectId( 
            /* [out] */ GUID *pConnectId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IConnection2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IConnection2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IConnection2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IConnection2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *FileCopy )( 
            IConnection2 * This,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDest,
            /* [in] */ BOOL fOverWrite,
            /* [in] */ ICallBack *piCallBack,
            /* [out] */ LPDWORD pdwTotalSize);
        
        HRESULT ( STDMETHODCALLTYPE *CopyPackage )( 
            IConnection2 * This,
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszDestPath,
            /* [in] */ BOOL fOverWrite,
            /* [in] */ ICallBack *piCallBack,
            /* [out] */ LPDWORD pdwTotalSize);
        
        HRESULT ( STDMETHODCALLTYPE *QueuePackage )( 
            IConnection2 * This,
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszDestPath,
            /* [in] */ BOOL fOverWrite);
        
        HRESULT ( STDMETHODCALLTYPE *QueueFile )( 
            IConnection2 * This,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDest,
            /* [in] */ BOOL fOverWrite);
        
        HRESULT ( STDMETHODCALLTYPE *CopyQueuedFiles )( 
            IConnection2 * This,
            /* [in] */ ICallBack *piCallBack,
            /* [out] */ LPDWORD pdwTotalSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetQueueCount )( 
            IConnection2 * This,
            /* [out] */ LPDWORD pdwCount);
        
        HRESULT ( STDMETHODCALLTYPE *Launch )( 
            IConnection2 * This,
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [full][in] */ LPCOLESTR pszCmdLine);
        
        HRESULT ( STDMETHODCALLTYPE *SystemGetInfo )( 
            IConnection2 * This,
            /* [out] */ LPWORD pwArchitecture,
            /* [out] */ LPDWORD pdwCPUType,
            /* [out] */ LPDWORD pdwPageSize,
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ LPWORD pwMinorVersion);
        
        HRESULT ( STDMETHODCALLTYPE *FileGetInfo )( 
            IConnection2 * This,
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [out] */ LPDWORD pdwFileAttributes,
            /* [out] */ LPDWORD pdwFileSize,
            /* [out] */ LPFILETIME pCreationTime);
        
        HRESULT ( STDMETHODCALLTYPE *FileDelete )( 
            IConnection2 * This,
            /* [in] */ LPCOLESTR pszFullPath);
        
        HRESULT ( STDMETHODCALLTYPE *CreateStream )( 
            IConnection2 * This,
            /* [in] */ GUID HostId,
            /* [in] */ DWORD dwPortId,
            /* [out] */ IConnectionStream **ppiConnectionStream,
            /* [in] */ ICallBack *piCallBack);
        
        HRESULT ( STDMETHODCALLTYPE *GetLocalInfo )( 
            IConnection2 * This,
            /* [out] */ LPDWORD pdwLocaleId);
        
        HRESULT ( STDMETHODCALLTYPE *GetFile )( 
            IConnection2 * This,
            /* [in] */ LPCOLESTR pszRemotePath,
            /* [in] */ LPCOLESTR pszDest,
            /* [in] */ ICallBack *piCallBack,
            /* [out] */ LPDWORD pdwTotalSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPlatformId )( 
            IConnection2 * This,
            /* [out] */ GUID *pPlatformId);
        
        HRESULT ( STDMETHODCALLTYPE *ResetQueue )( 
            IConnection2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *CloseAllStreams )( 
            IConnection2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SystemGetInfoEx )( 
            IConnection2 * This,
            /* [out] */ LPWORD pwArchitecture,
            /* [out] */ LPDWORD pdwCPUType,
            /* [out] */ LPDWORD pdwPageSize,
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ LPWORD pwMinorVersion,
            /* [out] */ GUID *OSTypeId);
        
        HRESULT ( STDMETHODCALLTYPE *GetConnectId )( 
            IConnection2 * This,
            /* [out] */ GUID *pConnectId);
        
        END_INTERFACE
    } IConnection2Vtbl;

    interface IConnection2
    {
        CONST_VTBL struct IConnection2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConnection2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IConnection2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IConnection2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IConnection2_FileCopy(This,pszSource,pszDest,fOverWrite,piCallBack,pdwTotalSize)	\
    (This)->lpVtbl -> FileCopy(This,pszSource,pszDest,fOverWrite,piCallBack,pdwTotalSize)

#define IConnection2_CopyPackage(This,PackageId,pszDestPath,fOverWrite,piCallBack,pdwTotalSize)	\
    (This)->lpVtbl -> CopyPackage(This,PackageId,pszDestPath,fOverWrite,piCallBack,pdwTotalSize)

#define IConnection2_QueuePackage(This,PackageId,pszDestPath,fOverWrite)	\
    (This)->lpVtbl -> QueuePackage(This,PackageId,pszDestPath,fOverWrite)

#define IConnection2_QueueFile(This,pszSource,pszDest,fOverWrite)	\
    (This)->lpVtbl -> QueueFile(This,pszSource,pszDest,fOverWrite)

#define IConnection2_CopyQueuedFiles(This,piCallBack,pdwTotalSize)	\
    (This)->lpVtbl -> CopyQueuedFiles(This,piCallBack,pdwTotalSize)

#define IConnection2_GetQueueCount(This,pdwCount)	\
    (This)->lpVtbl -> GetQueueCount(This,pdwCount)

#define IConnection2_Launch(This,pszRemotePath,pszCmdLine)	\
    (This)->lpVtbl -> Launch(This,pszRemotePath,pszCmdLine)

#define IConnection2_SystemGetInfo(This,pwArchitecture,pdwCPUType,pdwPageSize,pwMajorVersion,pwMinorVersion)	\
    (This)->lpVtbl -> SystemGetInfo(This,pwArchitecture,pdwCPUType,pdwPageSize,pwMajorVersion,pwMinorVersion)

#define IConnection2_FileGetInfo(This,pszRemotePath,pdwFileAttributes,pdwFileSize,pCreationTime)	\
    (This)->lpVtbl -> FileGetInfo(This,pszRemotePath,pdwFileAttributes,pdwFileSize,pCreationTime)

#define IConnection2_FileDelete(This,pszFullPath)	\
    (This)->lpVtbl -> FileDelete(This,pszFullPath)

#define IConnection2_CreateStream(This,HostId,dwPortId,ppiConnectionStream,piCallBack)	\
    (This)->lpVtbl -> CreateStream(This,HostId,dwPortId,ppiConnectionStream,piCallBack)

#define IConnection2_GetLocalInfo(This,pdwLocaleId)	\
    (This)->lpVtbl -> GetLocalInfo(This,pdwLocaleId)

#define IConnection2_GetFile(This,pszRemotePath,pszDest,piCallBack,pdwTotalSize)	\
    (This)->lpVtbl -> GetFile(This,pszRemotePath,pszDest,piCallBack,pdwTotalSize)

#define IConnection2_GetPlatformId(This,pPlatformId)	\
    (This)->lpVtbl -> GetPlatformId(This,pPlatformId)

#define IConnection2_ResetQueue(This)	\
    (This)->lpVtbl -> ResetQueue(This)

#define IConnection2_CloseAllStreams(This)	\
    (This)->lpVtbl -> CloseAllStreams(This)


#define IConnection2_SystemGetInfoEx(This,pwArchitecture,pdwCPUType,pdwPageSize,pwMajorVersion,pwMinorVersion,OSTypeId)	\
    (This)->lpVtbl -> SystemGetInfoEx(This,pwArchitecture,pdwCPUType,pdwPageSize,pwMajorVersion,pwMinorVersion,OSTypeId)

#define IConnection2_GetConnectId(This,pConnectId)	\
    (This)->lpVtbl -> GetConnectId(This,pConnectId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IConnection2_SystemGetInfoEx_Proxy( 
    IConnection2 * This,
    /* [out] */ LPWORD pwArchitecture,
    /* [out] */ LPDWORD pdwCPUType,
    /* [out] */ LPDWORD pdwPageSize,
    /* [out] */ LPWORD pwMajorVersion,
    /* [out] */ LPWORD pwMinorVersion,
    /* [out] */ GUID *OSTypeId);


void __RPC_STUB IConnection2_SystemGetInfoEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnection2_GetConnectId_Proxy( 
    IConnection2 * This,
    /* [out] */ GUID *pConnectId);


void __RPC_STUB IConnection2_GetConnectId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IConnection2_INTERFACE_DEFINED__ */


#ifndef __IConnectionStream_INTERFACE_DEFINED__
#define __IConnectionStream_INTERFACE_DEFINED__

/* interface IConnectionStream */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IConnectionStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA438BB0-FA87-11D1-BB9E-00A0C9C9CCEE")
    IConnectionStream : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Send( 
            /* [in] */ DWORD dwSize,
            /* [size_is][in] */ BYTE *pBuffer,
            /* [out] */ LPDWORD pdwSizeSent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Receive( 
            /* [out] */ LPDWORD pdwBytesReceived) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadBytes( 
            /* [in] */ DWORD dwSize,
            /* [length_is][size_is][out] */ BYTE *pBuffer,
            /* [out] */ LPDWORD pdwSizeRecv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReceiveAsync( 
            /* [in] */ ICallBack *piCallBack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendAsync( 
            /* [in] */ ICallBack *piCallBack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IConnectionStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IConnectionStream * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IConnectionStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IConnectionStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *Send )( 
            IConnectionStream * This,
            /* [in] */ DWORD dwSize,
            /* [size_is][in] */ BYTE *pBuffer,
            /* [out] */ LPDWORD pdwSizeSent);
        
        HRESULT ( STDMETHODCALLTYPE *Receive )( 
            IConnectionStream * This,
            /* [out] */ LPDWORD pdwBytesReceived);
        
        HRESULT ( STDMETHODCALLTYPE *ReadBytes )( 
            IConnectionStream * This,
            /* [in] */ DWORD dwSize,
            /* [length_is][size_is][out] */ BYTE *pBuffer,
            /* [out] */ LPDWORD pdwSizeRecv);
        
        HRESULT ( STDMETHODCALLTYPE *ReceiveAsync )( 
            IConnectionStream * This,
            /* [in] */ ICallBack *piCallBack);
        
        HRESULT ( STDMETHODCALLTYPE *SendAsync )( 
            IConnectionStream * This,
            /* [in] */ ICallBack *piCallBack);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IConnectionStream * This);
        
        END_INTERFACE
    } IConnectionStreamVtbl;

    interface IConnectionStream
    {
        CONST_VTBL struct IConnectionStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConnectionStream_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IConnectionStream_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IConnectionStream_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IConnectionStream_Send(This,dwSize,pBuffer,pdwSizeSent)	\
    (This)->lpVtbl -> Send(This,dwSize,pBuffer,pdwSizeSent)

#define IConnectionStream_Receive(This,pdwBytesReceived)	\
    (This)->lpVtbl -> Receive(This,pdwBytesReceived)

#define IConnectionStream_ReadBytes(This,dwSize,pBuffer,pdwSizeRecv)	\
    (This)->lpVtbl -> ReadBytes(This,dwSize,pBuffer,pdwSizeRecv)

#define IConnectionStream_ReceiveAsync(This,piCallBack)	\
    (This)->lpVtbl -> ReceiveAsync(This,piCallBack)

#define IConnectionStream_SendAsync(This,piCallBack)	\
    (This)->lpVtbl -> SendAsync(This,piCallBack)

#define IConnectionStream_Close(This)	\
    (This)->lpVtbl -> Close(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IConnectionStream_Send_Proxy( 
    IConnectionStream * This,
    /* [in] */ DWORD dwSize,
    /* [size_is][in] */ BYTE *pBuffer,
    /* [out] */ LPDWORD pdwSizeSent);


void __RPC_STUB IConnectionStream_Send_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionStream_Receive_Proxy( 
    IConnectionStream * This,
    /* [out] */ LPDWORD pdwBytesReceived);


void __RPC_STUB IConnectionStream_Receive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionStream_ReadBytes_Proxy( 
    IConnectionStream * This,
    /* [in] */ DWORD dwSize,
    /* [length_is][size_is][out] */ BYTE *pBuffer,
    /* [out] */ LPDWORD pdwSizeRecv);


void __RPC_STUB IConnectionStream_ReadBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionStream_ReceiveAsync_Proxy( 
    IConnectionStream * This,
    /* [in] */ ICallBack *piCallBack);


void __RPC_STUB IConnectionStream_ReceiveAsync_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionStream_SendAsync_Proxy( 
    IConnectionStream * This,
    /* [in] */ ICallBack *piCallBack);


void __RPC_STUB IConnectionStream_SendAsync_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionStream_Close_Proxy( 
    IConnectionStream * This);


void __RPC_STUB IConnectionStream_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IConnectionStream_INTERFACE_DEFINED__ */


#ifndef __IConnectionStream2_INTERFACE_DEFINED__
#define __IConnectionStream2_INTERFACE_DEFINED__

/* interface IConnectionStream2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IConnectionStream2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EF075F33-141A-4D6A-9D88-33360EBFCBA5")
    IConnectionStream2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Receive( 
            /* [in] */ DWORD dwTimeout,
            /* [out] */ LPDWORD pdwBytesReceived) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadBytes( 
            /* [in] */ DWORD dwSize,
            /* [in] */ DWORD dwTimeout,
            /* [length_is][size_is][out] */ BYTE *pBuffer,
            /* [out] */ LPDWORD pdwSizeRecv) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IConnectionStream2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IConnectionStream2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IConnectionStream2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IConnectionStream2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Receive )( 
            IConnectionStream2 * This,
            /* [in] */ DWORD dwTimeout,
            /* [out] */ LPDWORD pdwBytesReceived);
        
        HRESULT ( STDMETHODCALLTYPE *ReadBytes )( 
            IConnectionStream2 * This,
            /* [in] */ DWORD dwSize,
            /* [in] */ DWORD dwTimeout,
            /* [length_is][size_is][out] */ BYTE *pBuffer,
            /* [out] */ LPDWORD pdwSizeRecv);
        
        END_INTERFACE
    } IConnectionStream2Vtbl;

    interface IConnectionStream2
    {
        CONST_VTBL struct IConnectionStream2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConnectionStream2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IConnectionStream2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IConnectionStream2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IConnectionStream2_Receive(This,dwTimeout,pdwBytesReceived)	\
    (This)->lpVtbl -> Receive(This,dwTimeout,pdwBytesReceived)

#define IConnectionStream2_ReadBytes(This,dwSize,dwTimeout,pBuffer,pdwSizeRecv)	\
    (This)->lpVtbl -> ReadBytes(This,dwSize,dwTimeout,pBuffer,pdwSizeRecv)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IConnectionStream2_Receive_Proxy( 
    IConnectionStream2 * This,
    /* [in] */ DWORD dwTimeout,
    /* [out] */ LPDWORD pdwBytesReceived);


void __RPC_STUB IConnectionStream2_Receive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionStream2_ReadBytes_Proxy( 
    IConnectionStream2 * This,
    /* [in] */ DWORD dwSize,
    /* [in] */ DWORD dwTimeout,
    /* [length_is][size_is][out] */ BYTE *pBuffer,
    /* [out] */ LPDWORD pdwSizeRecv);


void __RPC_STUB IConnectionStream2_ReadBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IConnectionStream2_INTERFACE_DEFINED__ */


#ifndef __ICallBack_INTERFACE_DEFINED__
#define __ICallBack_INTERFACE_DEFINED__

/* interface ICallBack */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ICallBack;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA438BB3-FA87-11D1-BB9E-00A0C9C9CCEE")
    ICallBack : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ IConnection *piConnection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RecvNotify( 
            /* [in] */ DWORD dwSize,
            /* [size_is][in] */ BYTE *pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendNotify( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReportAction( 
            /* [in] */ REPORT_ACTION_TYPE at,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ HRESULT hrActionFailed,
            /* [in] */ DWORD dwSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConfirmCopy( 
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ FILETIME ftSource,
            /* [in] */ FILETIME ftDest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyUpdate( 
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ DWORD dwSizeCopied,
            /* [in] */ DWORD dwSizeTotal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StreamNotify( 
            /* [in] */ IConnectionStream *piConnectionStream) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICallBackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICallBack * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICallBack * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICallBack * This);
        
        HRESULT ( STDMETHODCALLTYPE *Connect )( 
            ICallBack * This,
            /* [in] */ IConnection *piConnection);
        
        HRESULT ( STDMETHODCALLTYPE *RecvNotify )( 
            ICallBack * This,
            /* [in] */ DWORD dwSize,
            /* [size_is][in] */ BYTE *pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *SendNotify )( 
            ICallBack * This);
        
        HRESULT ( STDMETHODCALLTYPE *ReportAction )( 
            ICallBack * This,
            /* [in] */ REPORT_ACTION_TYPE at,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ HRESULT hrActionFailed,
            /* [in] */ DWORD dwSize);
        
        HRESULT ( STDMETHODCALLTYPE *ConfirmCopy )( 
            ICallBack * This,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ FILETIME ftSource,
            /* [in] */ FILETIME ftDest);
        
        HRESULT ( STDMETHODCALLTYPE *CopyUpdate )( 
            ICallBack * This,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ DWORD dwSizeCopied,
            /* [in] */ DWORD dwSizeTotal);
        
        HRESULT ( STDMETHODCALLTYPE *StreamNotify )( 
            ICallBack * This,
            /* [in] */ IConnectionStream *piConnectionStream);
        
        END_INTERFACE
    } ICallBackVtbl;

    interface ICallBack
    {
        CONST_VTBL struct ICallBackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICallBack_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICallBack_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICallBack_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICallBack_Connect(This,piConnection)	\
    (This)->lpVtbl -> Connect(This,piConnection)

#define ICallBack_RecvNotify(This,dwSize,pBuffer)	\
    (This)->lpVtbl -> RecvNotify(This,dwSize,pBuffer)

#define ICallBack_SendNotify(This)	\
    (This)->lpVtbl -> SendNotify(This)

#define ICallBack_ReportAction(This,at,pszName,hrActionFailed,dwSize)	\
    (This)->lpVtbl -> ReportAction(This,at,pszName,hrActionFailed,dwSize)

#define ICallBack_ConfirmCopy(This,pszName,ftSource,ftDest)	\
    (This)->lpVtbl -> ConfirmCopy(This,pszName,ftSource,ftDest)

#define ICallBack_CopyUpdate(This,pszName,dwSizeCopied,dwSizeTotal)	\
    (This)->lpVtbl -> CopyUpdate(This,pszName,dwSizeCopied,dwSizeTotal)

#define ICallBack_StreamNotify(This,piConnectionStream)	\
    (This)->lpVtbl -> StreamNotify(This,piConnectionStream)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICallBack_Connect_Proxy( 
    ICallBack * This,
    /* [in] */ IConnection *piConnection);


void __RPC_STUB ICallBack_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICallBack_RecvNotify_Proxy( 
    ICallBack * This,
    /* [in] */ DWORD dwSize,
    /* [size_is][in] */ BYTE *pBuffer);


void __RPC_STUB ICallBack_RecvNotify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICallBack_SendNotify_Proxy( 
    ICallBack * This);


void __RPC_STUB ICallBack_SendNotify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICallBack_ReportAction_Proxy( 
    ICallBack * This,
    /* [in] */ REPORT_ACTION_TYPE at,
    /* [in] */ LPCOLESTR pszName,
    /* [in] */ HRESULT hrActionFailed,
    /* [in] */ DWORD dwSize);


void __RPC_STUB ICallBack_ReportAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICallBack_ConfirmCopy_Proxy( 
    ICallBack * This,
    /* [in] */ LPCOLESTR pszName,
    /* [in] */ FILETIME ftSource,
    /* [in] */ FILETIME ftDest);


void __RPC_STUB ICallBack_ConfirmCopy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICallBack_CopyUpdate_Proxy( 
    ICallBack * This,
    /* [in] */ LPCOLESTR pszName,
    /* [in] */ DWORD dwSizeCopied,
    /* [in] */ DWORD dwSizeTotal);


void __RPC_STUB ICallBack_CopyUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICallBack_StreamNotify_Proxy( 
    ICallBack * This,
    /* [in] */ IConnectionStream *piConnectionStream);


void __RPC_STUB ICallBack_StreamNotify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICallBack_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_cemgr_0276 */
/* [local] */ 

typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_cemgr_0276_0001
    {
    BOOL fIsPeExe;
    FILETIME FileTime;
    WORD TargetCpu;
    } 	CB2_FILEINFO;



extern RPC_IF_HANDLE __MIDL_itf_cemgr_0276_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_cemgr_0276_v0_0_s_ifspec;

#ifndef __IPlatManCallback2_INTERFACE_DEFINED__
#define __IPlatManCallback2_INTERFACE_DEFINED__

/* interface IPlatManCallback2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPlatManCallback2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC0A1BC0-A1F4-11d3-98FC-00105AA90682")
    IPlatManCallback2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ConfirmCopy2( 
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ CB2_FILEINFO *pSrcFileInfo,
            /* [in] */ CB2_FILEINFO *pDestFileInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlatManCallback2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlatManCallback2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlatManCallback2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlatManCallback2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *ConfirmCopy2 )( 
            IPlatManCallback2 * This,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ CB2_FILEINFO *pSrcFileInfo,
            /* [in] */ CB2_FILEINFO *pDestFileInfo);
        
        END_INTERFACE
    } IPlatManCallback2Vtbl;

    interface IPlatManCallback2
    {
        CONST_VTBL struct IPlatManCallback2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlatManCallback2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlatManCallback2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlatManCallback2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlatManCallback2_ConfirmCopy2(This,pszName,pSrcFileInfo,pDestFileInfo)	\
    (This)->lpVtbl -> ConfirmCopy2(This,pszName,pSrcFileInfo,pDestFileInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlatManCallback2_ConfirmCopy2_Proxy( 
    IPlatManCallback2 * This,
    /* [in] */ LPCOLESTR pszName,
    /* [in] */ CB2_FILEINFO *pSrcFileInfo,
    /* [in] */ CB2_FILEINFO *pDestFileInfo);


void __RPC_STUB IPlatManCallback2_ConfirmCopy2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlatManCallback2_INTERFACE_DEFINED__ */


#ifndef __IPlatformManagerConfig_INTERFACE_DEFINED__
#define __IPlatformManagerConfig_INTERFACE_DEFINED__

/* interface IPlatformManagerConfig */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPlatformManagerConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA438BC2-FA87-11D1-BB9E-00A0C9C9CCEE")
    IPlatformManagerConfig : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddPackage( 
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszPackageName,
            /* [out] */ IPackage **ppiPackage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPackage( 
            /* [in] */ GUID PackageId,
            /* [out] */ IPackage **ppiPackage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeletePackage( 
            /* [in] */ GUID PackageId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddPlatform( 
            /* [in] */ GUID PlatformId,
            /* [in] */ LPCOLESTR pszPlatformName,
            /* [out] */ IPlatformCE **ppiPlatform) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeletePlatform( 
            /* [in] */ GUID PlatformId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ LPWORD pwMinorVersion,
            /* [out] */ LPDWORD pdwBuildNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersion2( 
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ LPWORD pwMinorVersion,
            /* [out] */ LPDWORD pdwBuildNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddToolkit( 
            /* [in] */ GUID ToolkitId,
            /* [in] */ LPCOLESTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteToolkit( 
            /* [in] */ GUID ToolkitId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlatformManagerConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlatformManagerConfig * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlatformManagerConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlatformManagerConfig * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddPackage )( 
            IPlatformManagerConfig * This,
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszPackageName,
            /* [out] */ IPackage **ppiPackage);
        
        HRESULT ( STDMETHODCALLTYPE *GetPackage )( 
            IPlatformManagerConfig * This,
            /* [in] */ GUID PackageId,
            /* [out] */ IPackage **ppiPackage);
        
        HRESULT ( STDMETHODCALLTYPE *DeletePackage )( 
            IPlatformManagerConfig * This,
            /* [in] */ GUID PackageId);
        
        HRESULT ( STDMETHODCALLTYPE *AddPlatform )( 
            IPlatformManagerConfig * This,
            /* [in] */ GUID PlatformId,
            /* [in] */ LPCOLESTR pszPlatformName,
            /* [out] */ IPlatformCE **ppiPlatform);
        
        HRESULT ( STDMETHODCALLTYPE *DeletePlatform )( 
            IPlatformManagerConfig * This,
            /* [in] */ GUID PlatformId);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            IPlatformManagerConfig * This,
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ LPWORD pwMinorVersion,
            /* [out] */ LPDWORD pdwBuildNumber);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersion2 )( 
            IPlatformManagerConfig * This,
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ LPWORD pwMinorVersion,
            /* [out] */ LPDWORD pdwBuildNumber);
        
        HRESULT ( STDMETHODCALLTYPE *AddToolkit )( 
            IPlatformManagerConfig * This,
            /* [in] */ GUID ToolkitId,
            /* [in] */ LPCOLESTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteToolkit )( 
            IPlatformManagerConfig * This,
            /* [in] */ GUID ToolkitId);
        
        END_INTERFACE
    } IPlatformManagerConfigVtbl;

    interface IPlatformManagerConfig
    {
        CONST_VTBL struct IPlatformManagerConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlatformManagerConfig_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlatformManagerConfig_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlatformManagerConfig_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlatformManagerConfig_AddPackage(This,PackageId,pszPackageName,ppiPackage)	\
    (This)->lpVtbl -> AddPackage(This,PackageId,pszPackageName,ppiPackage)

#define IPlatformManagerConfig_GetPackage(This,PackageId,ppiPackage)	\
    (This)->lpVtbl -> GetPackage(This,PackageId,ppiPackage)

#define IPlatformManagerConfig_DeletePackage(This,PackageId)	\
    (This)->lpVtbl -> DeletePackage(This,PackageId)

#define IPlatformManagerConfig_AddPlatform(This,PlatformId,pszPlatformName,ppiPlatform)	\
    (This)->lpVtbl -> AddPlatform(This,PlatformId,pszPlatformName,ppiPlatform)

#define IPlatformManagerConfig_DeletePlatform(This,PlatformId)	\
    (This)->lpVtbl -> DeletePlatform(This,PlatformId)

#define IPlatformManagerConfig_GetVersion(This,pwMajorVersion,pwMinorVersion,pdwBuildNumber)	\
    (This)->lpVtbl -> GetVersion(This,pwMajorVersion,pwMinorVersion,pdwBuildNumber)

#define IPlatformManagerConfig_GetVersion2(This,pwMajorVersion,pwMinorVersion,pdwBuildNumber)	\
    (This)->lpVtbl -> GetVersion2(This,pwMajorVersion,pwMinorVersion,pdwBuildNumber)

#define IPlatformManagerConfig_AddToolkit(This,ToolkitId,pszName)	\
    (This)->lpVtbl -> AddToolkit(This,ToolkitId,pszName)

#define IPlatformManagerConfig_DeleteToolkit(This,ToolkitId)	\
    (This)->lpVtbl -> DeleteToolkit(This,ToolkitId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlatformManagerConfig_AddPackage_Proxy( 
    IPlatformManagerConfig * This,
    /* [in] */ GUID PackageId,
    /* [in] */ LPCOLESTR pszPackageName,
    /* [out] */ IPackage **ppiPackage);


void __RPC_STUB IPlatformManagerConfig_AddPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManagerConfig_GetPackage_Proxy( 
    IPlatformManagerConfig * This,
    /* [in] */ GUID PackageId,
    /* [out] */ IPackage **ppiPackage);


void __RPC_STUB IPlatformManagerConfig_GetPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManagerConfig_DeletePackage_Proxy( 
    IPlatformManagerConfig * This,
    /* [in] */ GUID PackageId);


void __RPC_STUB IPlatformManagerConfig_DeletePackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManagerConfig_AddPlatform_Proxy( 
    IPlatformManagerConfig * This,
    /* [in] */ GUID PlatformId,
    /* [in] */ LPCOLESTR pszPlatformName,
    /* [out] */ IPlatformCE **ppiPlatform);


void __RPC_STUB IPlatformManagerConfig_AddPlatform_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManagerConfig_DeletePlatform_Proxy( 
    IPlatformManagerConfig * This,
    /* [in] */ GUID PlatformId);


void __RPC_STUB IPlatformManagerConfig_DeletePlatform_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManagerConfig_GetVersion_Proxy( 
    IPlatformManagerConfig * This,
    /* [out] */ LPWORD pwMajorVersion,
    /* [out] */ LPWORD pwMinorVersion,
    /* [out] */ LPDWORD pdwBuildNumber);


void __RPC_STUB IPlatformManagerConfig_GetVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManagerConfig_GetVersion2_Proxy( 
    IPlatformManagerConfig * This,
    /* [out] */ LPWORD pwMajorVersion,
    /* [out] */ LPWORD pwMinorVersion,
    /* [out] */ LPDWORD pdwBuildNumber);


void __RPC_STUB IPlatformManagerConfig_GetVersion2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManagerConfig_AddToolkit_Proxy( 
    IPlatformManagerConfig * This,
    /* [in] */ GUID ToolkitId,
    /* [in] */ LPCOLESTR pszName);


void __RPC_STUB IPlatformManagerConfig_AddToolkit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManagerConfig_DeleteToolkit_Proxy( 
    IPlatformManagerConfig * This,
    /* [in] */ GUID ToolkitId);


void __RPC_STUB IPlatformManagerConfig_DeleteToolkit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlatformManagerConfig_INTERFACE_DEFINED__ */


#ifndef __IPlatformManagerConfig2_INTERFACE_DEFINED__
#define __IPlatformManagerConfig2_INTERFACE_DEFINED__

/* interface IPlatformManagerConfig2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPlatformManagerConfig2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("30A76E8E-8B0D-4E3b-8EC7-9B57862EFBF1")
    IPlatformManagerConfig2 : public IPlatformManagerConfig
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddPackage2( 
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszPackageName,
            /* [out] */ IPackage2 **ppiPackage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPackage2( 
            /* [in] */ GUID PackageId,
            /* [out] */ IPackage2 **ppiPackage) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlatformManagerConfig2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlatformManagerConfig2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlatformManagerConfig2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlatformManagerConfig2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddPackage )( 
            IPlatformManagerConfig2 * This,
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszPackageName,
            /* [out] */ IPackage **ppiPackage);
        
        HRESULT ( STDMETHODCALLTYPE *GetPackage )( 
            IPlatformManagerConfig2 * This,
            /* [in] */ GUID PackageId,
            /* [out] */ IPackage **ppiPackage);
        
        HRESULT ( STDMETHODCALLTYPE *DeletePackage )( 
            IPlatformManagerConfig2 * This,
            /* [in] */ GUID PackageId);
        
        HRESULT ( STDMETHODCALLTYPE *AddPlatform )( 
            IPlatformManagerConfig2 * This,
            /* [in] */ GUID PlatformId,
            /* [in] */ LPCOLESTR pszPlatformName,
            /* [out] */ IPlatformCE **ppiPlatform);
        
        HRESULT ( STDMETHODCALLTYPE *DeletePlatform )( 
            IPlatformManagerConfig2 * This,
            /* [in] */ GUID PlatformId);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            IPlatformManagerConfig2 * This,
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ LPWORD pwMinorVersion,
            /* [out] */ LPDWORD pdwBuildNumber);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersion2 )( 
            IPlatformManagerConfig2 * This,
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ LPWORD pwMinorVersion,
            /* [out] */ LPDWORD pdwBuildNumber);
        
        HRESULT ( STDMETHODCALLTYPE *AddToolkit )( 
            IPlatformManagerConfig2 * This,
            /* [in] */ GUID ToolkitId,
            /* [in] */ LPCOLESTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteToolkit )( 
            IPlatformManagerConfig2 * This,
            /* [in] */ GUID ToolkitId);
        
        HRESULT ( STDMETHODCALLTYPE *AddPackage2 )( 
            IPlatformManagerConfig2 * This,
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszPackageName,
            /* [out] */ IPackage2 **ppiPackage);
        
        HRESULT ( STDMETHODCALLTYPE *GetPackage2 )( 
            IPlatformManagerConfig2 * This,
            /* [in] */ GUID PackageId,
            /* [out] */ IPackage2 **ppiPackage);
        
        END_INTERFACE
    } IPlatformManagerConfig2Vtbl;

    interface IPlatformManagerConfig2
    {
        CONST_VTBL struct IPlatformManagerConfig2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlatformManagerConfig2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlatformManagerConfig2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlatformManagerConfig2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlatformManagerConfig2_AddPackage(This,PackageId,pszPackageName,ppiPackage)	\
    (This)->lpVtbl -> AddPackage(This,PackageId,pszPackageName,ppiPackage)

#define IPlatformManagerConfig2_GetPackage(This,PackageId,ppiPackage)	\
    (This)->lpVtbl -> GetPackage(This,PackageId,ppiPackage)

#define IPlatformManagerConfig2_DeletePackage(This,PackageId)	\
    (This)->lpVtbl -> DeletePackage(This,PackageId)

#define IPlatformManagerConfig2_AddPlatform(This,PlatformId,pszPlatformName,ppiPlatform)	\
    (This)->lpVtbl -> AddPlatform(This,PlatformId,pszPlatformName,ppiPlatform)

#define IPlatformManagerConfig2_DeletePlatform(This,PlatformId)	\
    (This)->lpVtbl -> DeletePlatform(This,PlatformId)

#define IPlatformManagerConfig2_GetVersion(This,pwMajorVersion,pwMinorVersion,pdwBuildNumber)	\
    (This)->lpVtbl -> GetVersion(This,pwMajorVersion,pwMinorVersion,pdwBuildNumber)

#define IPlatformManagerConfig2_GetVersion2(This,pwMajorVersion,pwMinorVersion,pdwBuildNumber)	\
    (This)->lpVtbl -> GetVersion2(This,pwMajorVersion,pwMinorVersion,pdwBuildNumber)

#define IPlatformManagerConfig2_AddToolkit(This,ToolkitId,pszName)	\
    (This)->lpVtbl -> AddToolkit(This,ToolkitId,pszName)

#define IPlatformManagerConfig2_DeleteToolkit(This,ToolkitId)	\
    (This)->lpVtbl -> DeleteToolkit(This,ToolkitId)


#define IPlatformManagerConfig2_AddPackage2(This,PackageId,pszPackageName,ppiPackage)	\
    (This)->lpVtbl -> AddPackage2(This,PackageId,pszPackageName,ppiPackage)

#define IPlatformManagerConfig2_GetPackage2(This,PackageId,ppiPackage)	\
    (This)->lpVtbl -> GetPackage2(This,PackageId,ppiPackage)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlatformManagerConfig2_AddPackage2_Proxy( 
    IPlatformManagerConfig2 * This,
    /* [in] */ GUID PackageId,
    /* [in] */ LPCOLESTR pszPackageName,
    /* [out] */ IPackage2 **ppiPackage);


void __RPC_STUB IPlatformManagerConfig2_AddPackage2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManagerConfig2_GetPackage2_Proxy( 
    IPlatformManagerConfig2 * This,
    /* [in] */ GUID PackageId,
    /* [out] */ IPackage2 **ppiPackage);


void __RPC_STUB IPlatformManagerConfig2_GetPackage2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlatformManagerConfig2_INTERFACE_DEFINED__ */


#ifndef __IPlatformManagerConfig3_INTERFACE_DEFINED__
#define __IPlatformManagerConfig3_INTERFACE_DEFINED__

/* interface IPlatformManagerConfig3 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPlatformManagerConfig3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("817E8295-C9EE-48ec-B1AC-37A858B73609")
    IPlatformManagerConfig3 : public IPlatformManagerConfig2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddBootableDevice( 
            /* [in] */ GUID BootableDeviceId,
            /* [in] */ LPCOLESTR pszBootableDeviceName,
            /* [out] */ IBootableDevice **ppiBootableDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteBootableDevice( 
            /* [in] */ GUID BootableDeviceId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddServiceCategory( 
            /* [in] */ GUID ServiceCategoryId,
            /* [in] */ LPCOLESTR pszServiceCategoryName,
            /* [out] */ IServiceCategory **ppiServiceCategory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteServiceCategory( 
            /* [in] */ GUID ServiceCategoryId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlatformManagerConfig3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlatformManagerConfig3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlatformManagerConfig3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlatformManagerConfig3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddPackage )( 
            IPlatformManagerConfig3 * This,
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszPackageName,
            /* [out] */ IPackage **ppiPackage);
        
        HRESULT ( STDMETHODCALLTYPE *GetPackage )( 
            IPlatformManagerConfig3 * This,
            /* [in] */ GUID PackageId,
            /* [out] */ IPackage **ppiPackage);
        
        HRESULT ( STDMETHODCALLTYPE *DeletePackage )( 
            IPlatformManagerConfig3 * This,
            /* [in] */ GUID PackageId);
        
        HRESULT ( STDMETHODCALLTYPE *AddPlatform )( 
            IPlatformManagerConfig3 * This,
            /* [in] */ GUID PlatformId,
            /* [in] */ LPCOLESTR pszPlatformName,
            /* [out] */ IPlatformCE **ppiPlatform);
        
        HRESULT ( STDMETHODCALLTYPE *DeletePlatform )( 
            IPlatformManagerConfig3 * This,
            /* [in] */ GUID PlatformId);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            IPlatformManagerConfig3 * This,
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ LPWORD pwMinorVersion,
            /* [out] */ LPDWORD pdwBuildNumber);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersion2 )( 
            IPlatformManagerConfig3 * This,
            /* [out] */ LPWORD pwMajorVersion,
            /* [out] */ LPWORD pwMinorVersion,
            /* [out] */ LPDWORD pdwBuildNumber);
        
        HRESULT ( STDMETHODCALLTYPE *AddToolkit )( 
            IPlatformManagerConfig3 * This,
            /* [in] */ GUID ToolkitId,
            /* [in] */ LPCOLESTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteToolkit )( 
            IPlatformManagerConfig3 * This,
            /* [in] */ GUID ToolkitId);
        
        HRESULT ( STDMETHODCALLTYPE *AddPackage2 )( 
            IPlatformManagerConfig3 * This,
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszPackageName,
            /* [out] */ IPackage2 **ppiPackage);
        
        HRESULT ( STDMETHODCALLTYPE *GetPackage2 )( 
            IPlatformManagerConfig3 * This,
            /* [in] */ GUID PackageId,
            /* [out] */ IPackage2 **ppiPackage);
        
        HRESULT ( STDMETHODCALLTYPE *AddBootableDevice )( 
            IPlatformManagerConfig3 * This,
            /* [in] */ GUID BootableDeviceId,
            /* [in] */ LPCOLESTR pszBootableDeviceName,
            /* [out] */ IBootableDevice **ppiBootableDevice);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteBootableDevice )( 
            IPlatformManagerConfig3 * This,
            /* [in] */ GUID BootableDeviceId);
        
        HRESULT ( STDMETHODCALLTYPE *AddServiceCategory )( 
            IPlatformManagerConfig3 * This,
            /* [in] */ GUID ServiceCategoryId,
            /* [in] */ LPCOLESTR pszServiceCategoryName,
            /* [out] */ IServiceCategory **ppiServiceCategory);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteServiceCategory )( 
            IPlatformManagerConfig3 * This,
            /* [in] */ GUID ServiceCategoryId);
        
        END_INTERFACE
    } IPlatformManagerConfig3Vtbl;

    interface IPlatformManagerConfig3
    {
        CONST_VTBL struct IPlatformManagerConfig3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlatformManagerConfig3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlatformManagerConfig3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlatformManagerConfig3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlatformManagerConfig3_AddPackage(This,PackageId,pszPackageName,ppiPackage)	\
    (This)->lpVtbl -> AddPackage(This,PackageId,pszPackageName,ppiPackage)

#define IPlatformManagerConfig3_GetPackage(This,PackageId,ppiPackage)	\
    (This)->lpVtbl -> GetPackage(This,PackageId,ppiPackage)

#define IPlatformManagerConfig3_DeletePackage(This,PackageId)	\
    (This)->lpVtbl -> DeletePackage(This,PackageId)

#define IPlatformManagerConfig3_AddPlatform(This,PlatformId,pszPlatformName,ppiPlatform)	\
    (This)->lpVtbl -> AddPlatform(This,PlatformId,pszPlatformName,ppiPlatform)

#define IPlatformManagerConfig3_DeletePlatform(This,PlatformId)	\
    (This)->lpVtbl -> DeletePlatform(This,PlatformId)

#define IPlatformManagerConfig3_GetVersion(This,pwMajorVersion,pwMinorVersion,pdwBuildNumber)	\
    (This)->lpVtbl -> GetVersion(This,pwMajorVersion,pwMinorVersion,pdwBuildNumber)

#define IPlatformManagerConfig3_GetVersion2(This,pwMajorVersion,pwMinorVersion,pdwBuildNumber)	\
    (This)->lpVtbl -> GetVersion2(This,pwMajorVersion,pwMinorVersion,pdwBuildNumber)

#define IPlatformManagerConfig3_AddToolkit(This,ToolkitId,pszName)	\
    (This)->lpVtbl -> AddToolkit(This,ToolkitId,pszName)

#define IPlatformManagerConfig3_DeleteToolkit(This,ToolkitId)	\
    (This)->lpVtbl -> DeleteToolkit(This,ToolkitId)


#define IPlatformManagerConfig3_AddPackage2(This,PackageId,pszPackageName,ppiPackage)	\
    (This)->lpVtbl -> AddPackage2(This,PackageId,pszPackageName,ppiPackage)

#define IPlatformManagerConfig3_GetPackage2(This,PackageId,ppiPackage)	\
    (This)->lpVtbl -> GetPackage2(This,PackageId,ppiPackage)


#define IPlatformManagerConfig3_AddBootableDevice(This,BootableDeviceId,pszBootableDeviceName,ppiBootableDevice)	\
    (This)->lpVtbl -> AddBootableDevice(This,BootableDeviceId,pszBootableDeviceName,ppiBootableDevice)

#define IPlatformManagerConfig3_DeleteBootableDevice(This,BootableDeviceId)	\
    (This)->lpVtbl -> DeleteBootableDevice(This,BootableDeviceId)

#define IPlatformManagerConfig3_AddServiceCategory(This,ServiceCategoryId,pszServiceCategoryName,ppiServiceCategory)	\
    (This)->lpVtbl -> AddServiceCategory(This,ServiceCategoryId,pszServiceCategoryName,ppiServiceCategory)

#define IPlatformManagerConfig3_DeleteServiceCategory(This,ServiceCategoryId)	\
    (This)->lpVtbl -> DeleteServiceCategory(This,ServiceCategoryId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlatformManagerConfig3_AddBootableDevice_Proxy( 
    IPlatformManagerConfig3 * This,
    /* [in] */ GUID BootableDeviceId,
    /* [in] */ LPCOLESTR pszBootableDeviceName,
    /* [out] */ IBootableDevice **ppiBootableDevice);


void __RPC_STUB IPlatformManagerConfig3_AddBootableDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManagerConfig3_DeleteBootableDevice_Proxy( 
    IPlatformManagerConfig3 * This,
    /* [in] */ GUID BootableDeviceId);


void __RPC_STUB IPlatformManagerConfig3_DeleteBootableDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManagerConfig3_AddServiceCategory_Proxy( 
    IPlatformManagerConfig3 * This,
    /* [in] */ GUID ServiceCategoryId,
    /* [in] */ LPCOLESTR pszServiceCategoryName,
    /* [out] */ IServiceCategory **ppiServiceCategory);


void __RPC_STUB IPlatformManagerConfig3_AddServiceCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformManagerConfig3_DeleteServiceCategory_Proxy( 
    IPlatformManagerConfig3 * This,
    /* [in] */ GUID ServiceCategoryId);


void __RPC_STUB IPlatformManagerConfig3_DeleteServiceCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlatformManagerConfig3_INTERFACE_DEFINED__ */


#ifndef __IBootableDeviceConfig_INTERFACE_DEFINED__
#define __IBootableDeviceConfig_INTERFACE_DEFINED__

/* interface IBootableDeviceConfig */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBootableDeviceConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("016ED627-9104-4fb6-8F82-E522755CC5AA")
    IBootableDeviceConfig : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetBootableDeviceName( 
            /* [in] */ LPCOLESTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddService( 
            /* [in] */ GUID ServiceCategoryId,
            /* [in] */ GUID ServiceCLSID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteService( 
            /* [in] */ GUID ServiceCategoryId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBootableDeviceConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBootableDeviceConfig * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBootableDeviceConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBootableDeviceConfig * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetBootableDeviceName )( 
            IBootableDeviceConfig * This,
            /* [in] */ LPCOLESTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *AddService )( 
            IBootableDeviceConfig * This,
            /* [in] */ GUID ServiceCategoryId,
            /* [in] */ GUID ServiceCLSID);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteService )( 
            IBootableDeviceConfig * This,
            /* [in] */ GUID ServiceCategoryId);
        
        END_INTERFACE
    } IBootableDeviceConfigVtbl;

    interface IBootableDeviceConfig
    {
        CONST_VTBL struct IBootableDeviceConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBootableDeviceConfig_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBootableDeviceConfig_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBootableDeviceConfig_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBootableDeviceConfig_SetBootableDeviceName(This,pszName)	\
    (This)->lpVtbl -> SetBootableDeviceName(This,pszName)

#define IBootableDeviceConfig_AddService(This,ServiceCategoryId,ServiceCLSID)	\
    (This)->lpVtbl -> AddService(This,ServiceCategoryId,ServiceCLSID)

#define IBootableDeviceConfig_DeleteService(This,ServiceCategoryId)	\
    (This)->lpVtbl -> DeleteService(This,ServiceCategoryId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IBootableDeviceConfig_SetBootableDeviceName_Proxy( 
    IBootableDeviceConfig * This,
    /* [in] */ LPCOLESTR pszName);


void __RPC_STUB IBootableDeviceConfig_SetBootableDeviceName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBootableDeviceConfig_AddService_Proxy( 
    IBootableDeviceConfig * This,
    /* [in] */ GUID ServiceCategoryId,
    /* [in] */ GUID ServiceCLSID);


void __RPC_STUB IBootableDeviceConfig_AddService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBootableDeviceConfig_DeleteService_Proxy( 
    IBootableDeviceConfig * This,
    /* [in] */ GUID ServiceCategoryId);


void __RPC_STUB IBootableDeviceConfig_DeleteService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBootableDeviceConfig_INTERFACE_DEFINED__ */


#ifndef __IServiceCategoryConfig_INTERFACE_DEFINED__
#define __IServiceCategoryConfig_INTERFACE_DEFINED__

/* interface IServiceCategoryConfig */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IServiceCategoryConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C335A883-E95A-4ea4-9DDA-FBE83C55D519")
    IServiceCategoryConfig : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetServiceCategoryName( 
            /* [in] */ LPCOLESTR pszServiceCategoryName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddServiceInfo( 
            /* [in] */ GUID ServiceCLSID,
            /* [in] */ LPCOLESTR pszServiceName,
            /* [out] */ IServiceInfo **ppiServiceInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteServiceInfo( 
            /* [in] */ GUID ServiceCLSID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServiceCategoryConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IServiceCategoryConfig * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IServiceCategoryConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IServiceCategoryConfig * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetServiceCategoryName )( 
            IServiceCategoryConfig * This,
            /* [in] */ LPCOLESTR pszServiceCategoryName);
        
        HRESULT ( STDMETHODCALLTYPE *AddServiceInfo )( 
            IServiceCategoryConfig * This,
            /* [in] */ GUID ServiceCLSID,
            /* [in] */ LPCOLESTR pszServiceName,
            /* [out] */ IServiceInfo **ppiServiceInfo);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteServiceInfo )( 
            IServiceCategoryConfig * This,
            /* [in] */ GUID ServiceCLSID);
        
        END_INTERFACE
    } IServiceCategoryConfigVtbl;

    interface IServiceCategoryConfig
    {
        CONST_VTBL struct IServiceCategoryConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServiceCategoryConfig_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServiceCategoryConfig_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServiceCategoryConfig_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServiceCategoryConfig_SetServiceCategoryName(This,pszServiceCategoryName)	\
    (This)->lpVtbl -> SetServiceCategoryName(This,pszServiceCategoryName)

#define IServiceCategoryConfig_AddServiceInfo(This,ServiceCLSID,pszServiceName,ppiServiceInfo)	\
    (This)->lpVtbl -> AddServiceInfo(This,ServiceCLSID,pszServiceName,ppiServiceInfo)

#define IServiceCategoryConfig_DeleteServiceInfo(This,ServiceCLSID)	\
    (This)->lpVtbl -> DeleteServiceInfo(This,ServiceCLSID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IServiceCategoryConfig_SetServiceCategoryName_Proxy( 
    IServiceCategoryConfig * This,
    /* [in] */ LPCOLESTR pszServiceCategoryName);


void __RPC_STUB IServiceCategoryConfig_SetServiceCategoryName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServiceCategoryConfig_AddServiceInfo_Proxy( 
    IServiceCategoryConfig * This,
    /* [in] */ GUID ServiceCLSID,
    /* [in] */ LPCOLESTR pszServiceName,
    /* [out] */ IServiceInfo **ppiServiceInfo);


void __RPC_STUB IServiceCategoryConfig_AddServiceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IServiceCategoryConfig_DeleteServiceInfo_Proxy( 
    IServiceCategoryConfig * This,
    /* [in] */ GUID ServiceCLSID);


void __RPC_STUB IServiceCategoryConfig_DeleteServiceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IServiceCategoryConfig_INTERFACE_DEFINED__ */


#ifndef __IServiceInfoConfig_INTERFACE_DEFINED__
#define __IServiceInfoConfig_INTERFACE_DEFINED__

/* interface IServiceInfoConfig */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IServiceInfoConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("324AA352-F2F5-4c23-AD31-1088D7D8EA97")
    IServiceInfoConfig : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetServiceInfoName( 
            /* [in] */ LPCOLESTR pszServiceInfoName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServiceInfoConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IServiceInfoConfig * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IServiceInfoConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IServiceInfoConfig * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetServiceInfoName )( 
            IServiceInfoConfig * This,
            /* [in] */ LPCOLESTR pszServiceInfoName);
        
        END_INTERFACE
    } IServiceInfoConfigVtbl;

    interface IServiceInfoConfig
    {
        CONST_VTBL struct IServiceInfoConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServiceInfoConfig_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServiceInfoConfig_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServiceInfoConfig_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServiceInfoConfig_SetServiceInfoName(This,pszServiceInfoName)	\
    (This)->lpVtbl -> SetServiceInfoName(This,pszServiceInfoName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IServiceInfoConfig_SetServiceInfoName_Proxy( 
    IServiceInfoConfig * This,
    /* [in] */ LPCOLESTR pszServiceInfoName);


void __RPC_STUB IServiceInfoConfig_SetServiceInfoName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IServiceInfoConfig_INTERFACE_DEFINED__ */


#ifndef __IPlatformConfig_INTERFACE_DEFINED__
#define __IPlatformConfig_INTERFACE_DEFINED__

/* interface IPlatformConfig */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPlatformConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA438BC7-FA87-11D1-BB9E-00A0C9C9CCEE")
    IPlatformConfig : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddPackage( 
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszPackageName,
            /* [out] */ IPackage **ppiPackage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPackage( 
            /* [in] */ GUID PackageId,
            /* [out] */ IPackage **ppiPackage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeletePackage( 
            /* [in] */ GUID PackageId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddComponent( 
            /* [in] */ COMPONENT_KIND ck,
            /* [in] */ GUID ComponentId,
            /* [in] */ BOOL fDefault) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPlatformName( 
            /* [in] */ LPCOLESTR pszPlatformName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddDevice( 
            /* [in] */ GUID DeviceId,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ DEVICE_TYPE dt,
            /* [out] */ IRemoteDevice **ppiDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteDevice( 
            /* [in] */ GUID DeviceId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumComponent( 
            /* [in] */ COMPONENT_KIND ck,
            /* [out] */ IEnumComponent **ppiEnumComponent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetComponentName( 
            /* [in] */ COMPONENT_KIND ck,
            /* [in] */ GUID ComponentId,
            /* [out] */ LPOLESTR *pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetComponentType( 
            /* [in] */ COMPONENT_KIND ck,
            /* [in] */ GUID ComponentId,
            /* [out] */ DEVICE_TYPE *pdt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddSupportedCPU( 
            /* [in] */ WORD wArchitecture,
            /* [in] */ DWORD dwCPUType,
            /* [in] */ LPCOLESTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOSInfo( 
            /* [in] */ WORD wMajorVersion,
            /* [in] */ WORD wMinorVersion) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlatformConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlatformConfig * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlatformConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlatformConfig * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddPackage )( 
            IPlatformConfig * This,
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszPackageName,
            /* [out] */ IPackage **ppiPackage);
        
        HRESULT ( STDMETHODCALLTYPE *GetPackage )( 
            IPlatformConfig * This,
            /* [in] */ GUID PackageId,
            /* [out] */ IPackage **ppiPackage);
        
        HRESULT ( STDMETHODCALLTYPE *DeletePackage )( 
            IPlatformConfig * This,
            /* [in] */ GUID PackageId);
        
        HRESULT ( STDMETHODCALLTYPE *AddComponent )( 
            IPlatformConfig * This,
            /* [in] */ COMPONENT_KIND ck,
            /* [in] */ GUID ComponentId,
            /* [in] */ BOOL fDefault);
        
        HRESULT ( STDMETHODCALLTYPE *SetPlatformName )( 
            IPlatformConfig * This,
            /* [in] */ LPCOLESTR pszPlatformName);
        
        HRESULT ( STDMETHODCALLTYPE *AddDevice )( 
            IPlatformConfig * This,
            /* [in] */ GUID DeviceId,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ DEVICE_TYPE dt,
            /* [out] */ IRemoteDevice **ppiDevice);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteDevice )( 
            IPlatformConfig * This,
            /* [in] */ GUID DeviceId);
        
        HRESULT ( STDMETHODCALLTYPE *EnumComponent )( 
            IPlatformConfig * This,
            /* [in] */ COMPONENT_KIND ck,
            /* [out] */ IEnumComponent **ppiEnumComponent);
        
        HRESULT ( STDMETHODCALLTYPE *GetComponentName )( 
            IPlatformConfig * This,
            /* [in] */ COMPONENT_KIND ck,
            /* [in] */ GUID ComponentId,
            /* [out] */ LPOLESTR *pszName);
        
        HRESULT ( STDMETHODCALLTYPE *GetComponentType )( 
            IPlatformConfig * This,
            /* [in] */ COMPONENT_KIND ck,
            /* [in] */ GUID ComponentId,
            /* [out] */ DEVICE_TYPE *pdt);
        
        HRESULT ( STDMETHODCALLTYPE *AddSupportedCPU )( 
            IPlatformConfig * This,
            /* [in] */ WORD wArchitecture,
            /* [in] */ DWORD dwCPUType,
            /* [in] */ LPCOLESTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *SetOSInfo )( 
            IPlatformConfig * This,
            /* [in] */ WORD wMajorVersion,
            /* [in] */ WORD wMinorVersion);
        
        END_INTERFACE
    } IPlatformConfigVtbl;

    interface IPlatformConfig
    {
        CONST_VTBL struct IPlatformConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlatformConfig_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlatformConfig_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlatformConfig_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlatformConfig_AddPackage(This,PackageId,pszPackageName,ppiPackage)	\
    (This)->lpVtbl -> AddPackage(This,PackageId,pszPackageName,ppiPackage)

#define IPlatformConfig_GetPackage(This,PackageId,ppiPackage)	\
    (This)->lpVtbl -> GetPackage(This,PackageId,ppiPackage)

#define IPlatformConfig_DeletePackage(This,PackageId)	\
    (This)->lpVtbl -> DeletePackage(This,PackageId)

#define IPlatformConfig_AddComponent(This,ck,ComponentId,fDefault)	\
    (This)->lpVtbl -> AddComponent(This,ck,ComponentId,fDefault)

#define IPlatformConfig_SetPlatformName(This,pszPlatformName)	\
    (This)->lpVtbl -> SetPlatformName(This,pszPlatformName)

#define IPlatformConfig_AddDevice(This,DeviceId,pszName,dt,ppiDevice)	\
    (This)->lpVtbl -> AddDevice(This,DeviceId,pszName,dt,ppiDevice)

#define IPlatformConfig_DeleteDevice(This,DeviceId)	\
    (This)->lpVtbl -> DeleteDevice(This,DeviceId)

#define IPlatformConfig_EnumComponent(This,ck,ppiEnumComponent)	\
    (This)->lpVtbl -> EnumComponent(This,ck,ppiEnumComponent)

#define IPlatformConfig_GetComponentName(This,ck,ComponentId,pszName)	\
    (This)->lpVtbl -> GetComponentName(This,ck,ComponentId,pszName)

#define IPlatformConfig_GetComponentType(This,ck,ComponentId,pdt)	\
    (This)->lpVtbl -> GetComponentType(This,ck,ComponentId,pdt)

#define IPlatformConfig_AddSupportedCPU(This,wArchitecture,dwCPUType,pszName)	\
    (This)->lpVtbl -> AddSupportedCPU(This,wArchitecture,dwCPUType,pszName)

#define IPlatformConfig_SetOSInfo(This,wMajorVersion,wMinorVersion)	\
    (This)->lpVtbl -> SetOSInfo(This,wMajorVersion,wMinorVersion)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlatformConfig_AddPackage_Proxy( 
    IPlatformConfig * This,
    /* [in] */ GUID PackageId,
    /* [in] */ LPCOLESTR pszPackageName,
    /* [out] */ IPackage **ppiPackage);


void __RPC_STUB IPlatformConfig_AddPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformConfig_GetPackage_Proxy( 
    IPlatformConfig * This,
    /* [in] */ GUID PackageId,
    /* [out] */ IPackage **ppiPackage);


void __RPC_STUB IPlatformConfig_GetPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformConfig_DeletePackage_Proxy( 
    IPlatformConfig * This,
    /* [in] */ GUID PackageId);


void __RPC_STUB IPlatformConfig_DeletePackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformConfig_AddComponent_Proxy( 
    IPlatformConfig * This,
    /* [in] */ COMPONENT_KIND ck,
    /* [in] */ GUID ComponentId,
    /* [in] */ BOOL fDefault);


void __RPC_STUB IPlatformConfig_AddComponent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformConfig_SetPlatformName_Proxy( 
    IPlatformConfig * This,
    /* [in] */ LPCOLESTR pszPlatformName);


void __RPC_STUB IPlatformConfig_SetPlatformName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformConfig_AddDevice_Proxy( 
    IPlatformConfig * This,
    /* [in] */ GUID DeviceId,
    /* [in] */ LPCOLESTR pszName,
    /* [in] */ DEVICE_TYPE dt,
    /* [out] */ IRemoteDevice **ppiDevice);


void __RPC_STUB IPlatformConfig_AddDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformConfig_DeleteDevice_Proxy( 
    IPlatformConfig * This,
    /* [in] */ GUID DeviceId);


void __RPC_STUB IPlatformConfig_DeleteDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformConfig_EnumComponent_Proxy( 
    IPlatformConfig * This,
    /* [in] */ COMPONENT_KIND ck,
    /* [out] */ IEnumComponent **ppiEnumComponent);


void __RPC_STUB IPlatformConfig_EnumComponent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformConfig_GetComponentName_Proxy( 
    IPlatformConfig * This,
    /* [in] */ COMPONENT_KIND ck,
    /* [in] */ GUID ComponentId,
    /* [out] */ LPOLESTR *pszName);


void __RPC_STUB IPlatformConfig_GetComponentName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformConfig_GetComponentType_Proxy( 
    IPlatformConfig * This,
    /* [in] */ COMPONENT_KIND ck,
    /* [in] */ GUID ComponentId,
    /* [out] */ DEVICE_TYPE *pdt);


void __RPC_STUB IPlatformConfig_GetComponentType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformConfig_AddSupportedCPU_Proxy( 
    IPlatformConfig * This,
    /* [in] */ WORD wArchitecture,
    /* [in] */ DWORD dwCPUType,
    /* [in] */ LPCOLESTR pszName);


void __RPC_STUB IPlatformConfig_AddSupportedCPU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformConfig_SetOSInfo_Proxy( 
    IPlatformConfig * This,
    /* [in] */ WORD wMajorVersion,
    /* [in] */ WORD wMinorVersion);


void __RPC_STUB IPlatformConfig_SetOSInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlatformConfig_INTERFACE_DEFINED__ */


#ifndef __IPlatformConfig2_INTERFACE_DEFINED__
#define __IPlatformConfig2_INTERFACE_DEFINED__

/* interface IPlatformConfig2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPlatformConfig2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FA59C739-CFD3-4421-B7F0-AA22D48D864C")
    IPlatformConfig2 : public IPlatformConfig
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddPackage2( 
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszPackageName,
            /* [out] */ IPackage2 **ppiPackage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPackage2( 
            /* [in] */ GUID PackageId,
            /* [out] */ IPackage2 **ppiPackage) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlatformConfig2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlatformConfig2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlatformConfig2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlatformConfig2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddPackage )( 
            IPlatformConfig2 * This,
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszPackageName,
            /* [out] */ IPackage **ppiPackage);
        
        HRESULT ( STDMETHODCALLTYPE *GetPackage )( 
            IPlatformConfig2 * This,
            /* [in] */ GUID PackageId,
            /* [out] */ IPackage **ppiPackage);
        
        HRESULT ( STDMETHODCALLTYPE *DeletePackage )( 
            IPlatformConfig2 * This,
            /* [in] */ GUID PackageId);
        
        HRESULT ( STDMETHODCALLTYPE *AddComponent )( 
            IPlatformConfig2 * This,
            /* [in] */ COMPONENT_KIND ck,
            /* [in] */ GUID ComponentId,
            /* [in] */ BOOL fDefault);
        
        HRESULT ( STDMETHODCALLTYPE *SetPlatformName )( 
            IPlatformConfig2 * This,
            /* [in] */ LPCOLESTR pszPlatformName);
        
        HRESULT ( STDMETHODCALLTYPE *AddDevice )( 
            IPlatformConfig2 * This,
            /* [in] */ GUID DeviceId,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ DEVICE_TYPE dt,
            /* [out] */ IRemoteDevice **ppiDevice);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteDevice )( 
            IPlatformConfig2 * This,
            /* [in] */ GUID DeviceId);
        
        HRESULT ( STDMETHODCALLTYPE *EnumComponent )( 
            IPlatformConfig2 * This,
            /* [in] */ COMPONENT_KIND ck,
            /* [out] */ IEnumComponent **ppiEnumComponent);
        
        HRESULT ( STDMETHODCALLTYPE *GetComponentName )( 
            IPlatformConfig2 * This,
            /* [in] */ COMPONENT_KIND ck,
            /* [in] */ GUID ComponentId,
            /* [out] */ LPOLESTR *pszName);
        
        HRESULT ( STDMETHODCALLTYPE *GetComponentType )( 
            IPlatformConfig2 * This,
            /* [in] */ COMPONENT_KIND ck,
            /* [in] */ GUID ComponentId,
            /* [out] */ DEVICE_TYPE *pdt);
        
        HRESULT ( STDMETHODCALLTYPE *AddSupportedCPU )( 
            IPlatformConfig2 * This,
            /* [in] */ WORD wArchitecture,
            /* [in] */ DWORD dwCPUType,
            /* [in] */ LPCOLESTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *SetOSInfo )( 
            IPlatformConfig2 * This,
            /* [in] */ WORD wMajorVersion,
            /* [in] */ WORD wMinorVersion);
        
        HRESULT ( STDMETHODCALLTYPE *AddPackage2 )( 
            IPlatformConfig2 * This,
            /* [in] */ GUID PackageId,
            /* [in] */ LPCOLESTR pszPackageName,
            /* [out] */ IPackage2 **ppiPackage);
        
        HRESULT ( STDMETHODCALLTYPE *GetPackage2 )( 
            IPlatformConfig2 * This,
            /* [in] */ GUID PackageId,
            /* [out] */ IPackage2 **ppiPackage);
        
        END_INTERFACE
    } IPlatformConfig2Vtbl;

    interface IPlatformConfig2
    {
        CONST_VTBL struct IPlatformConfig2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlatformConfig2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlatformConfig2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlatformConfig2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlatformConfig2_AddPackage(This,PackageId,pszPackageName,ppiPackage)	\
    (This)->lpVtbl -> AddPackage(This,PackageId,pszPackageName,ppiPackage)

#define IPlatformConfig2_GetPackage(This,PackageId,ppiPackage)	\
    (This)->lpVtbl -> GetPackage(This,PackageId,ppiPackage)

#define IPlatformConfig2_DeletePackage(This,PackageId)	\
    (This)->lpVtbl -> DeletePackage(This,PackageId)

#define IPlatformConfig2_AddComponent(This,ck,ComponentId,fDefault)	\
    (This)->lpVtbl -> AddComponent(This,ck,ComponentId,fDefault)

#define IPlatformConfig2_SetPlatformName(This,pszPlatformName)	\
    (This)->lpVtbl -> SetPlatformName(This,pszPlatformName)

#define IPlatformConfig2_AddDevice(This,DeviceId,pszName,dt,ppiDevice)	\
    (This)->lpVtbl -> AddDevice(This,DeviceId,pszName,dt,ppiDevice)

#define IPlatformConfig2_DeleteDevice(This,DeviceId)	\
    (This)->lpVtbl -> DeleteDevice(This,DeviceId)

#define IPlatformConfig2_EnumComponent(This,ck,ppiEnumComponent)	\
    (This)->lpVtbl -> EnumComponent(This,ck,ppiEnumComponent)

#define IPlatformConfig2_GetComponentName(This,ck,ComponentId,pszName)	\
    (This)->lpVtbl -> GetComponentName(This,ck,ComponentId,pszName)

#define IPlatformConfig2_GetComponentType(This,ck,ComponentId,pdt)	\
    (This)->lpVtbl -> GetComponentType(This,ck,ComponentId,pdt)

#define IPlatformConfig2_AddSupportedCPU(This,wArchitecture,dwCPUType,pszName)	\
    (This)->lpVtbl -> AddSupportedCPU(This,wArchitecture,dwCPUType,pszName)

#define IPlatformConfig2_SetOSInfo(This,wMajorVersion,wMinorVersion)	\
    (This)->lpVtbl -> SetOSInfo(This,wMajorVersion,wMinorVersion)


#define IPlatformConfig2_AddPackage2(This,PackageId,pszPackageName,ppiPackage)	\
    (This)->lpVtbl -> AddPackage2(This,PackageId,pszPackageName,ppiPackage)

#define IPlatformConfig2_GetPackage2(This,PackageId,ppiPackage)	\
    (This)->lpVtbl -> GetPackage2(This,PackageId,ppiPackage)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlatformConfig2_AddPackage2_Proxy( 
    IPlatformConfig2 * This,
    /* [in] */ GUID PackageId,
    /* [in] */ LPCOLESTR pszPackageName,
    /* [out] */ IPackage2 **ppiPackage);


void __RPC_STUB IPlatformConfig2_AddPackage2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlatformConfig2_GetPackage2_Proxy( 
    IPlatformConfig2 * This,
    /* [in] */ GUID PackageId,
    /* [out] */ IPackage2 **ppiPackage);


void __RPC_STUB IPlatformConfig2_GetPackage2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlatformConfig2_INTERFACE_DEFINED__ */


#ifndef __IRemoteDeviceConfig_INTERFACE_DEFINED__
#define __IRemoteDeviceConfig_INTERFACE_DEFINED__

/* interface IRemoteDeviceConfig */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRemoteDeviceConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA438BCA-FA87-11D1-BB9E-00A0C9C9CCEE")
    IRemoteDeviceConfig : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetDeviceName( 
            /* [in] */ LPCOLESTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetComponent( 
            /* [in] */ COMPONENT_KIND ck,
            /* [in] */ GUID ComponentId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetComponent( 
            /* [in] */ COMPONENT_KIND ck,
            /* [out] */ GUID *pComponentId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConfigureComponent( 
            /* [in] */ HWND hWnd,
            /* [in] */ COMPONENT_KIND ck,
            /* [in] */ GUID ComponentId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRemoteDeviceConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRemoteDeviceConfig * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRemoteDeviceConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRemoteDeviceConfig * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetDeviceName )( 
            IRemoteDeviceConfig * This,
            /* [in] */ LPCOLESTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *SetComponent )( 
            IRemoteDeviceConfig * This,
            /* [in] */ COMPONENT_KIND ck,
            /* [in] */ GUID ComponentId);
        
        HRESULT ( STDMETHODCALLTYPE *GetComponent )( 
            IRemoteDeviceConfig * This,
            /* [in] */ COMPONENT_KIND ck,
            /* [out] */ GUID *pComponentId);
        
        HRESULT ( STDMETHODCALLTYPE *ConfigureComponent )( 
            IRemoteDeviceConfig * This,
            /* [in] */ HWND hWnd,
            /* [in] */ COMPONENT_KIND ck,
            /* [in] */ GUID ComponentId);
        
        END_INTERFACE
    } IRemoteDeviceConfigVtbl;

    interface IRemoteDeviceConfig
    {
        CONST_VTBL struct IRemoteDeviceConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRemoteDeviceConfig_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRemoteDeviceConfig_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRemoteDeviceConfig_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRemoteDeviceConfig_SetDeviceName(This,pszName)	\
    (This)->lpVtbl -> SetDeviceName(This,pszName)

#define IRemoteDeviceConfig_SetComponent(This,ck,ComponentId)	\
    (This)->lpVtbl -> SetComponent(This,ck,ComponentId)

#define IRemoteDeviceConfig_GetComponent(This,ck,pComponentId)	\
    (This)->lpVtbl -> GetComponent(This,ck,pComponentId)

#define IRemoteDeviceConfig_ConfigureComponent(This,hWnd,ck,ComponentId)	\
    (This)->lpVtbl -> ConfigureComponent(This,hWnd,ck,ComponentId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRemoteDeviceConfig_SetDeviceName_Proxy( 
    IRemoteDeviceConfig * This,
    /* [in] */ LPCOLESTR pszName);


void __RPC_STUB IRemoteDeviceConfig_SetDeviceName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteDeviceConfig_SetComponent_Proxy( 
    IRemoteDeviceConfig * This,
    /* [in] */ COMPONENT_KIND ck,
    /* [in] */ GUID ComponentId);


void __RPC_STUB IRemoteDeviceConfig_SetComponent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteDeviceConfig_GetComponent_Proxy( 
    IRemoteDeviceConfig * This,
    /* [in] */ COMPONENT_KIND ck,
    /* [out] */ GUID *pComponentId);


void __RPC_STUB IRemoteDeviceConfig_GetComponent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteDeviceConfig_ConfigureComponent_Proxy( 
    IRemoteDeviceConfig * This,
    /* [in] */ HWND hWnd,
    /* [in] */ COMPONENT_KIND ck,
    /* [in] */ GUID ComponentId);


void __RPC_STUB IRemoteDeviceConfig_ConfigureComponent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRemoteDeviceConfig_INTERFACE_DEFINED__ */


#ifndef __IEnumComponent_INTERFACE_DEFINED__
#define __IEnumComponent_INTERFACE_DEFINED__

/* interface IEnumComponent */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumComponent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA438BCD-FA87-11D1-BB9E-00A0C9C9CCEE")
    IEnumComponent : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ GUID *rgelt[  ],
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumComponent **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG *pcelt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNext( 
            /* [out] */ GUID *pComponentId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumComponentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumComponent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumComponent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumComponent * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumComponent * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ GUID *rgelt[  ],
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumComponent * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumComponent * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumComponent * This,
            /* [out] */ IEnumComponent **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IEnumComponent * This,
            /* [out] */ ULONG *pcelt);
        
        HRESULT ( STDMETHODCALLTYPE *GetNext )( 
            IEnumComponent * This,
            /* [out] */ GUID *pComponentId);
        
        END_INTERFACE
    } IEnumComponentVtbl;

    interface IEnumComponent
    {
        CONST_VTBL struct IEnumComponentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumComponent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumComponent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumComponent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumComponent_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumComponent_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumComponent_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumComponent_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#define IEnumComponent_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)

#define IEnumComponent_GetNext(This,pComponentId)	\
    (This)->lpVtbl -> GetNext(This,pComponentId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumComponent_Next_Proxy( 
    IEnumComponent * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ GUID *rgelt[  ],
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumComponent_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumComponent_Skip_Proxy( 
    IEnumComponent * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumComponent_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumComponent_Reset_Proxy( 
    IEnumComponent * This);


void __RPC_STUB IEnumComponent_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumComponent_Clone_Proxy( 
    IEnumComponent * This,
    /* [out] */ IEnumComponent **ppEnum);


void __RPC_STUB IEnumComponent_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumComponent_GetCount_Proxy( 
    IEnumComponent * This,
    /* [out] */ ULONG *pcelt);


void __RPC_STUB IEnumComponent_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumComponent_GetNext_Proxy( 
    IEnumComponent * This,
    /* [out] */ GUID *pComponentId);


void __RPC_STUB IEnumComponent_GetNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumComponent_INTERFACE_DEFINED__ */


#ifndef __IPackage_INTERFACE_DEFINED__
#define __IPackage_INTERFACE_DEFINED__

/* interface IPackage */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPackage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A4F783A-014E-11D2-BBA0-00A0C9C9CCEE")
    IPackage : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddFile( 
            /* [in] */ LPCOLESTR pszFullPath,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ DEVICE_TYPE dt,
            /* [in] */ WORD wArchitecture,
            /* [in] */ DWORD dwCPUType,
            /* [in] */ WORD wProcessorLevel,
            /* [in] */ DWORD dwPageSize,
            /* [in] */ WORD wMajorVersion,
            /* [in] */ WORD wMinorVersion,
            /* [in] */ DWORD dwLocaleId,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddPackageFile( 
            /* [in] */ LPCOLESTR pszFullPath,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ PACKAGE_FILE_INFO pfi) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteFile( 
            /* [in] */ LPCOLESTR pszFullPath,
            /* [in] */ LPCOLESTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumFiles( 
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ PACKAGE_FILE_INFO pfi,
            /* [out] */ IEnumPackageFiles **ppiEnumFiles) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPackageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPackage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPackage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPackage * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddFile )( 
            IPackage * This,
            /* [in] */ LPCOLESTR pszFullPath,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ DEVICE_TYPE dt,
            /* [in] */ WORD wArchitecture,
            /* [in] */ DWORD dwCPUType,
            /* [in] */ WORD wProcessorLevel,
            /* [in] */ DWORD dwPageSize,
            /* [in] */ WORD wMajorVersion,
            /* [in] */ WORD wMinorVersion,
            /* [in] */ DWORD dwLocaleId,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *AddPackageFile )( 
            IPackage * This,
            /* [in] */ LPCOLESTR pszFullPath,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ PACKAGE_FILE_INFO pfi);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteFile )( 
            IPackage * This,
            /* [in] */ LPCOLESTR pszFullPath,
            /* [in] */ LPCOLESTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumFiles )( 
            IPackage * This,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ PACKAGE_FILE_INFO pfi,
            /* [out] */ IEnumPackageFiles **ppiEnumFiles);
        
        END_INTERFACE
    } IPackageVtbl;

    interface IPackage
    {
        CONST_VTBL struct IPackageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPackage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPackage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPackage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPackage_AddFile(This,pszFullPath,pszName,dt,wArchitecture,dwCPUType,wProcessorLevel,dwPageSize,wMajorVersion,wMinorVersion,dwLocaleId,dwFlags)	\
    (This)->lpVtbl -> AddFile(This,pszFullPath,pszName,dt,wArchitecture,dwCPUType,wProcessorLevel,dwPageSize,wMajorVersion,wMinorVersion,dwLocaleId,dwFlags)

#define IPackage_AddPackageFile(This,pszFullPath,pszName,pfi)	\
    (This)->lpVtbl -> AddPackageFile(This,pszFullPath,pszName,pfi)

#define IPackage_DeleteFile(This,pszFullPath,pszName)	\
    (This)->lpVtbl -> DeleteFile(This,pszFullPath,pszName)

#define IPackage_EnumFiles(This,pszName,pfi,ppiEnumFiles)	\
    (This)->lpVtbl -> EnumFiles(This,pszName,pfi,ppiEnumFiles)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPackage_AddFile_Proxy( 
    IPackage * This,
    /* [in] */ LPCOLESTR pszFullPath,
    /* [in] */ LPCOLESTR pszName,
    /* [in] */ DEVICE_TYPE dt,
    /* [in] */ WORD wArchitecture,
    /* [in] */ DWORD dwCPUType,
    /* [in] */ WORD wProcessorLevel,
    /* [in] */ DWORD dwPageSize,
    /* [in] */ WORD wMajorVersion,
    /* [in] */ WORD wMinorVersion,
    /* [in] */ DWORD dwLocaleId,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB IPackage_AddFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPackage_AddPackageFile_Proxy( 
    IPackage * This,
    /* [in] */ LPCOLESTR pszFullPath,
    /* [in] */ LPCOLESTR pszName,
    /* [in] */ PACKAGE_FILE_INFO pfi);


void __RPC_STUB IPackage_AddPackageFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPackage_DeleteFile_Proxy( 
    IPackage * This,
    /* [in] */ LPCOLESTR pszFullPath,
    /* [in] */ LPCOLESTR pszName);


void __RPC_STUB IPackage_DeleteFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPackage_EnumFiles_Proxy( 
    IPackage * This,
    /* [in] */ LPCOLESTR pszName,
    /* [in] */ PACKAGE_FILE_INFO pfi,
    /* [out] */ IEnumPackageFiles **ppiEnumFiles);


void __RPC_STUB IPackage_EnumFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPackage_INTERFACE_DEFINED__ */


#ifndef __IPackage2_INTERFACE_DEFINED__
#define __IPackage2_INTERFACE_DEFINED__

/* interface IPackage2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPackage2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("64D0B782-47B7-4c30-8B5F-DDB7B248A91D")
    IPackage2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddFile( 
            /* [in] */ LPCOLESTR pszFullPath,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ DEVICE_TYPE dt,
            /* [in] */ WORD wArchitecture,
            /* [in] */ DWORD dwCPUType,
            /* [in] */ WORD wProcessorLevel,
            /* [in] */ DWORD dwPageSize,
            /* [in] */ WORD wMajorVersion,
            /* [in] */ WORD wMinorVersion,
            /* [in] */ DWORD dwLocaleId,
            /* [in] */ DWORD dwFlags,
            /* [in] */ GUID OSTypeId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddPackageFile( 
            /* [in] */ LPCOLESTR pszFullPath,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ PACKAGE_FILE_INFO2 pfi) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteFile( 
            /* [in] */ LPCOLESTR pszFullPath,
            /* [in] */ LPCOLESTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumFiles( 
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ PACKAGE_FILE_INFO2 pfi,
            /* [out] */ IEnumPackageFiles2 **ppiEnumFiles) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPackage2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPackage2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPackage2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPackage2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddFile )( 
            IPackage2 * This,
            /* [in] */ LPCOLESTR pszFullPath,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ DEVICE_TYPE dt,
            /* [in] */ WORD wArchitecture,
            /* [in] */ DWORD dwCPUType,
            /* [in] */ WORD wProcessorLevel,
            /* [in] */ DWORD dwPageSize,
            /* [in] */ WORD wMajorVersion,
            /* [in] */ WORD wMinorVersion,
            /* [in] */ DWORD dwLocaleId,
            /* [in] */ DWORD dwFlags,
            /* [in] */ GUID OSTypeId);
        
        HRESULT ( STDMETHODCALLTYPE *AddPackageFile )( 
            IPackage2 * This,
            /* [in] */ LPCOLESTR pszFullPath,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ PACKAGE_FILE_INFO2 pfi);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteFile )( 
            IPackage2 * This,
            /* [in] */ LPCOLESTR pszFullPath,
            /* [in] */ LPCOLESTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumFiles )( 
            IPackage2 * This,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ PACKAGE_FILE_INFO2 pfi,
            /* [out] */ IEnumPackageFiles2 **ppiEnumFiles);
        
        END_INTERFACE
    } IPackage2Vtbl;

    interface IPackage2
    {
        CONST_VTBL struct IPackage2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPackage2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPackage2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPackage2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPackage2_AddFile(This,pszFullPath,pszName,dt,wArchitecture,dwCPUType,wProcessorLevel,dwPageSize,wMajorVersion,wMinorVersion,dwLocaleId,dwFlags,OSTypeId)	\
    (This)->lpVtbl -> AddFile(This,pszFullPath,pszName,dt,wArchitecture,dwCPUType,wProcessorLevel,dwPageSize,wMajorVersion,wMinorVersion,dwLocaleId,dwFlags,OSTypeId)

#define IPackage2_AddPackageFile(This,pszFullPath,pszName,pfi)	\
    (This)->lpVtbl -> AddPackageFile(This,pszFullPath,pszName,pfi)

#define IPackage2_DeleteFile(This,pszFullPath,pszName)	\
    (This)->lpVtbl -> DeleteFile(This,pszFullPath,pszName)

#define IPackage2_EnumFiles(This,pszName,pfi,ppiEnumFiles)	\
    (This)->lpVtbl -> EnumFiles(This,pszName,pfi,ppiEnumFiles)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPackage2_AddFile_Proxy( 
    IPackage2 * This,
    /* [in] */ LPCOLESTR pszFullPath,
    /* [in] */ LPCOLESTR pszName,
    /* [in] */ DEVICE_TYPE dt,
    /* [in] */ WORD wArchitecture,
    /* [in] */ DWORD dwCPUType,
    /* [in] */ WORD wProcessorLevel,
    /* [in] */ DWORD dwPageSize,
    /* [in] */ WORD wMajorVersion,
    /* [in] */ WORD wMinorVersion,
    /* [in] */ DWORD dwLocaleId,
    /* [in] */ DWORD dwFlags,
    /* [in] */ GUID OSTypeId);


void __RPC_STUB IPackage2_AddFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPackage2_AddPackageFile_Proxy( 
    IPackage2 * This,
    /* [in] */ LPCOLESTR pszFullPath,
    /* [in] */ LPCOLESTR pszName,
    /* [in] */ PACKAGE_FILE_INFO2 pfi);


void __RPC_STUB IPackage2_AddPackageFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPackage2_DeleteFile_Proxy( 
    IPackage2 * This,
    /* [in] */ LPCOLESTR pszFullPath,
    /* [in] */ LPCOLESTR pszName);


void __RPC_STUB IPackage2_DeleteFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPackage2_EnumFiles_Proxy( 
    IPackage2 * This,
    /* [in] */ LPCOLESTR pszName,
    /* [in] */ PACKAGE_FILE_INFO2 pfi,
    /* [out] */ IEnumPackageFiles2 **ppiEnumFiles);


void __RPC_STUB IPackage2_EnumFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPackage2_INTERFACE_DEFINED__ */


#ifndef __IEnumPackageFiles_INTERFACE_DEFINED__
#define __IEnumPackageFiles_INTERFACE_DEFINED__

/* interface IEnumPackageFiles */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumPackageFiles;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A4F783D-014E-11D2-BBA0-00A0C9C9CCEE")
    IEnumPackageFiles : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ LPOLESTR rgeltFullPath[  ],
            /* [length_is][size_is][out] */ LPOLESTR rgeltName[  ],
            /* [length_is][size_is][out] */ PACKAGE_FILE_INFO rgeltInfo[  ],
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumPackageFiles **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG *pcelt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNext( 
            /* [out] */ LPOLESTR *pszFullPath,
            /* [out] */ LPOLESTR *pszName,
            /* [out] */ PACKAGE_FILE_INFO *ppfi) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumPackageFilesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumPackageFiles * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumPackageFiles * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumPackageFiles * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumPackageFiles * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ LPOLESTR rgeltFullPath[  ],
            /* [length_is][size_is][out] */ LPOLESTR rgeltName[  ],
            /* [length_is][size_is][out] */ PACKAGE_FILE_INFO rgeltInfo[  ],
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumPackageFiles * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumPackageFiles * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumPackageFiles * This,
            /* [out] */ IEnumPackageFiles **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IEnumPackageFiles * This,
            /* [out] */ ULONG *pcelt);
        
        HRESULT ( STDMETHODCALLTYPE *GetNext )( 
            IEnumPackageFiles * This,
            /* [out] */ LPOLESTR *pszFullPath,
            /* [out] */ LPOLESTR *pszName,
            /* [out] */ PACKAGE_FILE_INFO *ppfi);
        
        END_INTERFACE
    } IEnumPackageFilesVtbl;

    interface IEnumPackageFiles
    {
        CONST_VTBL struct IEnumPackageFilesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumPackageFiles_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumPackageFiles_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumPackageFiles_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumPackageFiles_Next(This,celt,rgeltFullPath,rgeltName,rgeltInfo,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgeltFullPath,rgeltName,rgeltInfo,pceltFetched)

#define IEnumPackageFiles_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumPackageFiles_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumPackageFiles_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#define IEnumPackageFiles_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)

#define IEnumPackageFiles_GetNext(This,pszFullPath,pszName,ppfi)	\
    (This)->lpVtbl -> GetNext(This,pszFullPath,pszName,ppfi)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumPackageFiles_Next_Proxy( 
    IEnumPackageFiles * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ LPOLESTR rgeltFullPath[  ],
    /* [length_is][size_is][out] */ LPOLESTR rgeltName[  ],
    /* [length_is][size_is][out] */ PACKAGE_FILE_INFO rgeltInfo[  ],
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumPackageFiles_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPackageFiles_Skip_Proxy( 
    IEnumPackageFiles * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumPackageFiles_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPackageFiles_Reset_Proxy( 
    IEnumPackageFiles * This);


void __RPC_STUB IEnumPackageFiles_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPackageFiles_Clone_Proxy( 
    IEnumPackageFiles * This,
    /* [out] */ IEnumPackageFiles **ppEnum);


void __RPC_STUB IEnumPackageFiles_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPackageFiles_GetCount_Proxy( 
    IEnumPackageFiles * This,
    /* [out] */ ULONG *pcelt);


void __RPC_STUB IEnumPackageFiles_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPackageFiles_GetNext_Proxy( 
    IEnumPackageFiles * This,
    /* [out] */ LPOLESTR *pszFullPath,
    /* [out] */ LPOLESTR *pszName,
    /* [out] */ PACKAGE_FILE_INFO *ppfi);


void __RPC_STUB IEnumPackageFiles_GetNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumPackageFiles_INTERFACE_DEFINED__ */


#ifndef __IEnumPackageFiles2_INTERFACE_DEFINED__
#define __IEnumPackageFiles2_INTERFACE_DEFINED__

/* interface IEnumPackageFiles2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumPackageFiles2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BA5F16F6-F3A3-44E4-88F4-10E2B1E921F4")
    IEnumPackageFiles2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ LPOLESTR rgeltFullPath[  ],
            /* [length_is][size_is][out] */ LPOLESTR rgeltName[  ],
            /* [length_is][size_is][out] */ PACKAGE_FILE_INFO2 rgeltInfo[  ],
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumPackageFiles2 **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG *pcelt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNext( 
            /* [out] */ LPOLESTR *pszFullPath,
            /* [out] */ LPOLESTR *pszName,
            /* [out] */ PACKAGE_FILE_INFO2 *ppfi) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumPackageFiles2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumPackageFiles2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumPackageFiles2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumPackageFiles2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumPackageFiles2 * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ LPOLESTR rgeltFullPath[  ],
            /* [length_is][size_is][out] */ LPOLESTR rgeltName[  ],
            /* [length_is][size_is][out] */ PACKAGE_FILE_INFO2 rgeltInfo[  ],
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumPackageFiles2 * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumPackageFiles2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumPackageFiles2 * This,
            /* [out] */ IEnumPackageFiles2 **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IEnumPackageFiles2 * This,
            /* [out] */ ULONG *pcelt);
        
        HRESULT ( STDMETHODCALLTYPE *GetNext )( 
            IEnumPackageFiles2 * This,
            /* [out] */ LPOLESTR *pszFullPath,
            /* [out] */ LPOLESTR *pszName,
            /* [out] */ PACKAGE_FILE_INFO2 *ppfi);
        
        END_INTERFACE
    } IEnumPackageFiles2Vtbl;

    interface IEnumPackageFiles2
    {
        CONST_VTBL struct IEnumPackageFiles2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumPackageFiles2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumPackageFiles2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumPackageFiles2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumPackageFiles2_Next(This,celt,rgeltFullPath,rgeltName,rgeltInfo,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgeltFullPath,rgeltName,rgeltInfo,pceltFetched)

#define IEnumPackageFiles2_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumPackageFiles2_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumPackageFiles2_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#define IEnumPackageFiles2_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)

#define IEnumPackageFiles2_GetNext(This,pszFullPath,pszName,ppfi)	\
    (This)->lpVtbl -> GetNext(This,pszFullPath,pszName,ppfi)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumPackageFiles2_Next_Proxy( 
    IEnumPackageFiles2 * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ LPOLESTR rgeltFullPath[  ],
    /* [length_is][size_is][out] */ LPOLESTR rgeltName[  ],
    /* [length_is][size_is][out] */ PACKAGE_FILE_INFO2 rgeltInfo[  ],
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumPackageFiles2_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPackageFiles2_Skip_Proxy( 
    IEnumPackageFiles2 * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumPackageFiles2_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPackageFiles2_Reset_Proxy( 
    IEnumPackageFiles2 * This);


void __RPC_STUB IEnumPackageFiles2_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPackageFiles2_Clone_Proxy( 
    IEnumPackageFiles2 * This,
    /* [out] */ IEnumPackageFiles2 **ppEnum);


void __RPC_STUB IEnumPackageFiles2_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPackageFiles2_GetCount_Proxy( 
    IEnumPackageFiles2 * This,
    /* [out] */ ULONG *pcelt);


void __RPC_STUB IEnumPackageFiles2_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPackageFiles2_GetNext_Proxy( 
    IEnumPackageFiles2 * This,
    /* [out] */ LPOLESTR *pszFullPath,
    /* [out] */ LPOLESTR *pszName,
    /* [out] */ PACKAGE_FILE_INFO2 *ppfi);


void __RPC_STUB IEnumPackageFiles2_GetNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumPackageFiles2_INTERFACE_DEFINED__ */


#ifndef __IEnumCPU_INTERFACE_DEFINED__
#define __IEnumCPU_INTERFACE_DEFINED__

/* interface IEnumCPU */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumCPU;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("66B6C2DD-2590-11D2-BBA9-00A0C9C9CCEE")
    IEnumCPU : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ WORD rgeltArchitecture[  ],
            /* [length_is][size_is][out] */ DWORD rgeltCPUType[  ],
            /* [length_is][size_is][out] */ LPOLESTR rgetName[  ],
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumCPU **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG *pcelt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNext( 
            /* [out] */ LPWORD pwArchitecture,
            /* [out] */ LPDWORD pdwCPUType,
            /* [out] */ LPOLESTR *pszName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumCPUVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumCPU * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumCPU * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumCPU * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumCPU * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ WORD rgeltArchitecture[  ],
            /* [length_is][size_is][out] */ DWORD rgeltCPUType[  ],
            /* [length_is][size_is][out] */ LPOLESTR rgetName[  ],
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumCPU * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumCPU * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumCPU * This,
            /* [out] */ IEnumCPU **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IEnumCPU * This,
            /* [out] */ ULONG *pcelt);
        
        HRESULT ( STDMETHODCALLTYPE *GetNext )( 
            IEnumCPU * This,
            /* [out] */ LPWORD pwArchitecture,
            /* [out] */ LPDWORD pdwCPUType,
            /* [out] */ LPOLESTR *pszName);
        
        END_INTERFACE
    } IEnumCPUVtbl;

    interface IEnumCPU
    {
        CONST_VTBL struct IEnumCPUVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumCPU_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumCPU_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumCPU_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumCPU_Next(This,celt,rgeltArchitecture,rgeltCPUType,rgetName,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgeltArchitecture,rgeltCPUType,rgetName,pceltFetched)

#define IEnumCPU_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumCPU_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumCPU_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#define IEnumCPU_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)

#define IEnumCPU_GetNext(This,pwArchitecture,pdwCPUType,pszName)	\
    (This)->lpVtbl -> GetNext(This,pwArchitecture,pdwCPUType,pszName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumCPU_Next_Proxy( 
    IEnumCPU * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ WORD rgeltArchitecture[  ],
    /* [length_is][size_is][out] */ DWORD rgeltCPUType[  ],
    /* [length_is][size_is][out] */ LPOLESTR rgetName[  ],
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumCPU_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumCPU_Skip_Proxy( 
    IEnumCPU * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumCPU_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumCPU_Reset_Proxy( 
    IEnumCPU * This);


void __RPC_STUB IEnumCPU_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumCPU_Clone_Proxy( 
    IEnumCPU * This,
    /* [out] */ IEnumCPU **ppEnum);


void __RPC_STUB IEnumCPU_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumCPU_GetCount_Proxy( 
    IEnumCPU * This,
    /* [out] */ ULONG *pcelt);


void __RPC_STUB IEnumCPU_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumCPU_GetNext_Proxy( 
    IEnumCPU * This,
    /* [out] */ LPWORD pwArchitecture,
    /* [out] */ LPDWORD pdwCPUType,
    /* [out] */ LPOLESTR *pszName);


void __RPC_STUB IEnumCPU_GetNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumCPU_INTERFACE_DEFINED__ */


#ifndef __IPMPlatformManager_INTERFACE_DEFINED__
#define __IPMPlatformManager_INTERFACE_DEFINED__

/* interface IPMPlatformManager */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMPlatformManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EA720E9B-5C6D-4FBF-9352-A084866596A7")
    IPMPlatformManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumPlatforms( 
            /* [retval][out] */ IEnumVariant **ppiEnumPlatform) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPlatform( 
            /* [in] */ BSTR bstrPlatformIdOrName,
            /* [retval][out] */ IPMPlatform **ppiPlatform) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddPlatform( 
            /* [in] */ BSTR bstrPlatformName,
            /* [defaultvalue][in] */ BSTR bstrPlatformId,
            /* [retval][out] */ IPMPlatform **ppiPlatform) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeletePlatform( 
            /* [in] */ BSTR bstrPlatformIdOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumProperties( 
            /* [retval][out] */ IEnumVariant **ppiEnumProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ BSTR bstrLinkName,
            /* [defaultvalue][in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteProperty( 
            /* [in] */ BSTR bstrPropId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumBootableDevices( 
            /* [retval][out] */ IEnumVariant **ppiEnumBootableDevice) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBootableDevice( 
            /* [in] */ BSTR bstrBootableDeviceIdOrName,
            /* [retval][out] */ IPMBootableDevice **ppiBootableDevice) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddBootableDevice( 
            /* [in] */ BSTR bstrBootableDeviceName,
            /* [defaultvalue][in] */ BSTR bstrBootableDeviceId,
            /* [retval][out] */ IPMBootableDevice **ppiBootableDevice) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteBootableDevice( 
            /* [in] */ BSTR bstrBootableDeviceIdOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumServiceCategories( 
            /* [retval][out] */ IEnumVariant **ppiEnumServiceCategory) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetServiceCategory( 
            /* [in] */ BSTR bstrServiceCategoryIdOrName,
            /* [retval][out] */ IPMServiceCategory **ppiServiceCategory) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddServiceCategory( 
            /* [in] */ BSTR bstrServiceCategoryName,
            /* [defaultvalue][in] */ BSTR bstrServiceCategoryId,
            /* [retval][out] */ IPMServiceCategory **ppiServiceCategory) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteServiceCategory( 
            /* [in] */ BSTR bstrServiceCategoryIdOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumCPUs( 
            /* [retval][out] */ IEnumVariant **ppiEnumCPU) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCPU( 
            /* [in] */ BSTR bstrCPUIdOrName,
            /* [retval][out] */ IPMCPU **ppiCPU) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddCPU( 
            /* [in] */ BSTR bstrCPUName,
            /* [in] */ long dwCpuNum,
            /* [defaultvalue][in] */ int wArchitecture,
            /* [defaultvalue][in] */ long dwCPUType,
            /* [defaultvalue][in] */ BSTR bstrCPUId,
            /* [optional][in] */ VARIANT vtPageSize,
            /* [optional][in] */ VARIANT vtLevel,
            /* [defaultvalue][in] */ BSTR bstrDefaultValue,
            /* [retval][out] */ IPMCPU **ppiCPU) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteCPU( 
            /* [in] */ BSTR bstrCPUIdOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumOSs( 
            /* [retval][out] */ IEnumVariant **ppiEnumOS) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOS( 
            /* [in] */ BSTR bstrOSIdOrName,
            /* [retval][out] */ IPMOS **ppiOS) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddOS( 
            /* [in] */ BSTR bstrOSName,
            /* [in] */ int wMajorVersion,
            /* [in] */ int wMinorVersion,
            /* [in] */ BSTR bstrOSTypeId,
            /* [defaultvalue][in] */ BSTR bstrOSId,
            /* [retval][out] */ IPMOS **ppiOS) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteOS( 
            /* [in] */ BSTR bstrOSIdOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumPackages( 
            /* [retval][out] */ IEnumVariant **ppiEnumPackage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPackage( 
            /* [in] */ BSTR bstrPackageIdOrName,
            /* [retval][out] */ IPMPackage **ppiPackage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddPackage( 
            /* [in] */ BSTR bstrPackageName,
            /* [defaultvalue][in] */ BSTR bstrPackageId,
            /* [retval][out] */ IPMPackage **ppiPackage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeletePackage( 
            /* [in] */ BSTR bstrPackageIdOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddToolkit( 
            /* [in] */ BSTR bstrName,
            /* [defaultvalue][in] */ BSTR bstrToolkitId = L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteToolkit( 
            /* [in] */ BSTR bstrToolkitIdOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetConnection( 
            /* [in] */ BSTR bstrConnectId,
            /* [retval][out] */ IPMConnection **ppiConnection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [out] */ VARIANT *pwMajorVersion,
            /* [out] */ VARIANT *pwMinorVersion,
            /* [out] */ VARIANT *pdwBuildNumber) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateGUID( 
            /* [retval][out] */ BSTR *pbstrNewGuid) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CleanRegistry( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumUniversalPlatforms( 
            /* [retval][out] */ IEnumVariant **ppiEnumUniversalPlatform) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMPlatformManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMPlatformManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMPlatformManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMPlatformManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMPlatformManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMPlatformManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMPlatformManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMPlatformManager * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumPlatforms )( 
            IPMPlatformManager * This,
            /* [retval][out] */ IEnumVariant **ppiEnumPlatform);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPlatform )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrPlatformIdOrName,
            /* [retval][out] */ IPMPlatform **ppiPlatform);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddPlatform )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrPlatformName,
            /* [defaultvalue][in] */ BSTR bstrPlatformId,
            /* [retval][out] */ IPMPlatform **ppiPlatform);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeletePlatform )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrPlatformIdOrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IPMPlatformManager * This,
            /* [retval][out] */ IEnumVariant **ppiEnumProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrLinkName,
            /* [defaultvalue][in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrPropId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumBootableDevices )( 
            IPMPlatformManager * This,
            /* [retval][out] */ IEnumVariant **ppiEnumBootableDevice);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBootableDevice )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrBootableDeviceIdOrName,
            /* [retval][out] */ IPMBootableDevice **ppiBootableDevice);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddBootableDevice )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrBootableDeviceName,
            /* [defaultvalue][in] */ BSTR bstrBootableDeviceId,
            /* [retval][out] */ IPMBootableDevice **ppiBootableDevice);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteBootableDevice )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrBootableDeviceIdOrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumServiceCategories )( 
            IPMPlatformManager * This,
            /* [retval][out] */ IEnumVariant **ppiEnumServiceCategory);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetServiceCategory )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrServiceCategoryIdOrName,
            /* [retval][out] */ IPMServiceCategory **ppiServiceCategory);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddServiceCategory )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrServiceCategoryName,
            /* [defaultvalue][in] */ BSTR bstrServiceCategoryId,
            /* [retval][out] */ IPMServiceCategory **ppiServiceCategory);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteServiceCategory )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrServiceCategoryIdOrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumCPUs )( 
            IPMPlatformManager * This,
            /* [retval][out] */ IEnumVariant **ppiEnumCPU);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCPU )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrCPUIdOrName,
            /* [retval][out] */ IPMCPU **ppiCPU);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddCPU )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrCPUName,
            /* [in] */ long dwCpuNum,
            /* [defaultvalue][in] */ int wArchitecture,
            /* [defaultvalue][in] */ long dwCPUType,
            /* [defaultvalue][in] */ BSTR bstrCPUId,
            /* [optional][in] */ VARIANT vtPageSize,
            /* [optional][in] */ VARIANT vtLevel,
            /* [defaultvalue][in] */ BSTR bstrDefaultValue,
            /* [retval][out] */ IPMCPU **ppiCPU);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteCPU )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrCPUIdOrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumOSs )( 
            IPMPlatformManager * This,
            /* [retval][out] */ IEnumVariant **ppiEnumOS);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetOS )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrOSIdOrName,
            /* [retval][out] */ IPMOS **ppiOS);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddOS )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrOSName,
            /* [in] */ int wMajorVersion,
            /* [in] */ int wMinorVersion,
            /* [in] */ BSTR bstrOSTypeId,
            /* [defaultvalue][in] */ BSTR bstrOSId,
            /* [retval][out] */ IPMOS **ppiOS);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteOS )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrOSIdOrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumPackages )( 
            IPMPlatformManager * This,
            /* [retval][out] */ IEnumVariant **ppiEnumPackage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPackage )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrPackageIdOrName,
            /* [retval][out] */ IPMPackage **ppiPackage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddPackage )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrPackageName,
            /* [defaultvalue][in] */ BSTR bstrPackageId,
            /* [retval][out] */ IPMPackage **ppiPackage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeletePackage )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrPackageIdOrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddToolkit )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrName,
            /* [defaultvalue][in] */ BSTR bstrToolkitId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteToolkit )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrToolkitIdOrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnection )( 
            IPMPlatformManager * This,
            /* [in] */ BSTR bstrConnectId,
            /* [retval][out] */ IPMConnection **ppiConnection);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            IPMPlatformManager * This,
            /* [out] */ VARIANT *pwMajorVersion,
            /* [out] */ VARIANT *pwMinorVersion,
            /* [out] */ VARIANT *pdwBuildNumber);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateGUID )( 
            IPMPlatformManager * This,
            /* [retval][out] */ BSTR *pbstrNewGuid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CleanRegistry )( 
            IPMPlatformManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumUniversalPlatforms )( 
            IPMPlatformManager * This,
            /* [retval][out] */ IEnumVariant **ppiEnumUniversalPlatform);
        
        END_INTERFACE
    } IPMPlatformManagerVtbl;

    interface IPMPlatformManager
    {
        CONST_VTBL struct IPMPlatformManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMPlatformManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMPlatformManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMPlatformManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMPlatformManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMPlatformManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMPlatformManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMPlatformManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMPlatformManager_EnumPlatforms(This,ppiEnumPlatform)	\
    (This)->lpVtbl -> EnumPlatforms(This,ppiEnumPlatform)

#define IPMPlatformManager_GetPlatform(This,bstrPlatformIdOrName,ppiPlatform)	\
    (This)->lpVtbl -> GetPlatform(This,bstrPlatformIdOrName,ppiPlatform)

#define IPMPlatformManager_AddPlatform(This,bstrPlatformName,bstrPlatformId,ppiPlatform)	\
    (This)->lpVtbl -> AddPlatform(This,bstrPlatformName,bstrPlatformId,ppiPlatform)

#define IPMPlatformManager_DeletePlatform(This,bstrPlatformIdOrName)	\
    (This)->lpVtbl -> DeletePlatform(This,bstrPlatformIdOrName)

#define IPMPlatformManager_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IPMPlatformManager_GetProperty(This,bstrPropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,bstrPropId,ppiProperty)

#define IPMPlatformManager_AddProperty(This,bstrLinkName,bstrPropId,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,bstrLinkName,bstrPropId,ppiProperty)

#define IPMPlatformManager_DeleteProperty(This,bstrPropId)	\
    (This)->lpVtbl -> DeleteProperty(This,bstrPropId)

#define IPMPlatformManager_EnumBootableDevices(This,ppiEnumBootableDevice)	\
    (This)->lpVtbl -> EnumBootableDevices(This,ppiEnumBootableDevice)

#define IPMPlatformManager_GetBootableDevice(This,bstrBootableDeviceIdOrName,ppiBootableDevice)	\
    (This)->lpVtbl -> GetBootableDevice(This,bstrBootableDeviceIdOrName,ppiBootableDevice)

#define IPMPlatformManager_AddBootableDevice(This,bstrBootableDeviceName,bstrBootableDeviceId,ppiBootableDevice)	\
    (This)->lpVtbl -> AddBootableDevice(This,bstrBootableDeviceName,bstrBootableDeviceId,ppiBootableDevice)

#define IPMPlatformManager_DeleteBootableDevice(This,bstrBootableDeviceIdOrName)	\
    (This)->lpVtbl -> DeleteBootableDevice(This,bstrBootableDeviceIdOrName)

#define IPMPlatformManager_EnumServiceCategories(This,ppiEnumServiceCategory)	\
    (This)->lpVtbl -> EnumServiceCategories(This,ppiEnumServiceCategory)

#define IPMPlatformManager_GetServiceCategory(This,bstrServiceCategoryIdOrName,ppiServiceCategory)	\
    (This)->lpVtbl -> GetServiceCategory(This,bstrServiceCategoryIdOrName,ppiServiceCategory)

#define IPMPlatformManager_AddServiceCategory(This,bstrServiceCategoryName,bstrServiceCategoryId,ppiServiceCategory)	\
    (This)->lpVtbl -> AddServiceCategory(This,bstrServiceCategoryName,bstrServiceCategoryId,ppiServiceCategory)

#define IPMPlatformManager_DeleteServiceCategory(This,bstrServiceCategoryIdOrName)	\
    (This)->lpVtbl -> DeleteServiceCategory(This,bstrServiceCategoryIdOrName)

#define IPMPlatformManager_EnumCPUs(This,ppiEnumCPU)	\
    (This)->lpVtbl -> EnumCPUs(This,ppiEnumCPU)

#define IPMPlatformManager_GetCPU(This,bstrCPUIdOrName,ppiCPU)	\
    (This)->lpVtbl -> GetCPU(This,bstrCPUIdOrName,ppiCPU)

#define IPMPlatformManager_AddCPU(This,bstrCPUName,dwCpuNum,wArchitecture,dwCPUType,bstrCPUId,vtPageSize,vtLevel,bstrDefaultValue,ppiCPU)	\
    (This)->lpVtbl -> AddCPU(This,bstrCPUName,dwCpuNum,wArchitecture,dwCPUType,bstrCPUId,vtPageSize,vtLevel,bstrDefaultValue,ppiCPU)

#define IPMPlatformManager_DeleteCPU(This,bstrCPUIdOrName)	\
    (This)->lpVtbl -> DeleteCPU(This,bstrCPUIdOrName)

#define IPMPlatformManager_EnumOSs(This,ppiEnumOS)	\
    (This)->lpVtbl -> EnumOSs(This,ppiEnumOS)

#define IPMPlatformManager_GetOS(This,bstrOSIdOrName,ppiOS)	\
    (This)->lpVtbl -> GetOS(This,bstrOSIdOrName,ppiOS)

#define IPMPlatformManager_AddOS(This,bstrOSName,wMajorVersion,wMinorVersion,bstrOSTypeId,bstrOSId,ppiOS)	\
    (This)->lpVtbl -> AddOS(This,bstrOSName,wMajorVersion,wMinorVersion,bstrOSTypeId,bstrOSId,ppiOS)

#define IPMPlatformManager_DeleteOS(This,bstrOSIdOrName)	\
    (This)->lpVtbl -> DeleteOS(This,bstrOSIdOrName)

#define IPMPlatformManager_EnumPackages(This,ppiEnumPackage)	\
    (This)->lpVtbl -> EnumPackages(This,ppiEnumPackage)

#define IPMPlatformManager_GetPackage(This,bstrPackageIdOrName,ppiPackage)	\
    (This)->lpVtbl -> GetPackage(This,bstrPackageIdOrName,ppiPackage)

#define IPMPlatformManager_AddPackage(This,bstrPackageName,bstrPackageId,ppiPackage)	\
    (This)->lpVtbl -> AddPackage(This,bstrPackageName,bstrPackageId,ppiPackage)

#define IPMPlatformManager_DeletePackage(This,bstrPackageIdOrName)	\
    (This)->lpVtbl -> DeletePackage(This,bstrPackageIdOrName)

#define IPMPlatformManager_AddToolkit(This,bstrName,bstrToolkitId)	\
    (This)->lpVtbl -> AddToolkit(This,bstrName,bstrToolkitId)

#define IPMPlatformManager_DeleteToolkit(This,bstrToolkitIdOrName)	\
    (This)->lpVtbl -> DeleteToolkit(This,bstrToolkitIdOrName)

#define IPMPlatformManager_GetConnection(This,bstrConnectId,ppiConnection)	\
    (This)->lpVtbl -> GetConnection(This,bstrConnectId,ppiConnection)

#define IPMPlatformManager_GetVersion(This,pwMajorVersion,pwMinorVersion,pdwBuildNumber)	\
    (This)->lpVtbl -> GetVersion(This,pwMajorVersion,pwMinorVersion,pdwBuildNumber)

#define IPMPlatformManager_CreateGUID(This,pbstrNewGuid)	\
    (This)->lpVtbl -> CreateGUID(This,pbstrNewGuid)

#define IPMPlatformManager_CleanRegistry(This)	\
    (This)->lpVtbl -> CleanRegistry(This)

#define IPMPlatformManager_EnumUniversalPlatforms(This,ppiEnumUniversalPlatform)	\
    (This)->lpVtbl -> EnumUniversalPlatforms(This,ppiEnumUniversalPlatform)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_EnumPlatforms_Proxy( 
    IPMPlatformManager * This,
    /* [retval][out] */ IEnumVariant **ppiEnumPlatform);


void __RPC_STUB IPMPlatformManager_EnumPlatforms_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_GetPlatform_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrPlatformIdOrName,
    /* [retval][out] */ IPMPlatform **ppiPlatform);


void __RPC_STUB IPMPlatformManager_GetPlatform_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_AddPlatform_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrPlatformName,
    /* [defaultvalue][in] */ BSTR bstrPlatformId,
    /* [retval][out] */ IPMPlatform **ppiPlatform);


void __RPC_STUB IPMPlatformManager_AddPlatform_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_DeletePlatform_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrPlatformIdOrName);


void __RPC_STUB IPMPlatformManager_DeletePlatform_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_EnumProperties_Proxy( 
    IPMPlatformManager * This,
    /* [retval][out] */ IEnumVariant **ppiEnumProperty);


void __RPC_STUB IPMPlatformManager_EnumProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_GetProperty_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrPropId,
    /* [retval][out] */ IPMProperty **ppiProperty);


void __RPC_STUB IPMPlatformManager_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_AddProperty_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrLinkName,
    /* [defaultvalue][in] */ BSTR bstrPropId,
    /* [retval][out] */ IPMProperty **ppiProperty);


void __RPC_STUB IPMPlatformManager_AddProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_DeleteProperty_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrPropId);


void __RPC_STUB IPMPlatformManager_DeleteProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_EnumBootableDevices_Proxy( 
    IPMPlatformManager * This,
    /* [retval][out] */ IEnumVariant **ppiEnumBootableDevice);


void __RPC_STUB IPMPlatformManager_EnumBootableDevices_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_GetBootableDevice_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrBootableDeviceIdOrName,
    /* [retval][out] */ IPMBootableDevice **ppiBootableDevice);


void __RPC_STUB IPMPlatformManager_GetBootableDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_AddBootableDevice_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrBootableDeviceName,
    /* [defaultvalue][in] */ BSTR bstrBootableDeviceId,
    /* [retval][out] */ IPMBootableDevice **ppiBootableDevice);


void __RPC_STUB IPMPlatformManager_AddBootableDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_DeleteBootableDevice_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrBootableDeviceIdOrName);


void __RPC_STUB IPMPlatformManager_DeleteBootableDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_EnumServiceCategories_Proxy( 
    IPMPlatformManager * This,
    /* [retval][out] */ IEnumVariant **ppiEnumServiceCategory);


void __RPC_STUB IPMPlatformManager_EnumServiceCategories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_GetServiceCategory_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrServiceCategoryIdOrName,
    /* [retval][out] */ IPMServiceCategory **ppiServiceCategory);


void __RPC_STUB IPMPlatformManager_GetServiceCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_AddServiceCategory_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrServiceCategoryName,
    /* [defaultvalue][in] */ BSTR bstrServiceCategoryId,
    /* [retval][out] */ IPMServiceCategory **ppiServiceCategory);


void __RPC_STUB IPMPlatformManager_AddServiceCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_DeleteServiceCategory_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrServiceCategoryIdOrName);


void __RPC_STUB IPMPlatformManager_DeleteServiceCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_EnumCPUs_Proxy( 
    IPMPlatformManager * This,
    /* [retval][out] */ IEnumVariant **ppiEnumCPU);


void __RPC_STUB IPMPlatformManager_EnumCPUs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_GetCPU_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrCPUIdOrName,
    /* [retval][out] */ IPMCPU **ppiCPU);


void __RPC_STUB IPMPlatformManager_GetCPU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_AddCPU_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrCPUName,
    /* [in] */ long dwCpuNum,
    /* [defaultvalue][in] */ int wArchitecture,
    /* [defaultvalue][in] */ long dwCPUType,
    /* [defaultvalue][in] */ BSTR bstrCPUId,
    /* [optional][in] */ VARIANT vtPageSize,
    /* [optional][in] */ VARIANT vtLevel,
    /* [defaultvalue][in] */ BSTR bstrDefaultValue,
    /* [retval][out] */ IPMCPU **ppiCPU);


void __RPC_STUB IPMPlatformManager_AddCPU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_DeleteCPU_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrCPUIdOrName);


void __RPC_STUB IPMPlatformManager_DeleteCPU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_EnumOSs_Proxy( 
    IPMPlatformManager * This,
    /* [retval][out] */ IEnumVariant **ppiEnumOS);


void __RPC_STUB IPMPlatformManager_EnumOSs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_GetOS_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrOSIdOrName,
    /* [retval][out] */ IPMOS **ppiOS);


void __RPC_STUB IPMPlatformManager_GetOS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_AddOS_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrOSName,
    /* [in] */ int wMajorVersion,
    /* [in] */ int wMinorVersion,
    /* [in] */ BSTR bstrOSTypeId,
    /* [defaultvalue][in] */ BSTR bstrOSId,
    /* [retval][out] */ IPMOS **ppiOS);


void __RPC_STUB IPMPlatformManager_AddOS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_DeleteOS_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrOSIdOrName);


void __RPC_STUB IPMPlatformManager_DeleteOS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_EnumPackages_Proxy( 
    IPMPlatformManager * This,
    /* [retval][out] */ IEnumVariant **ppiEnumPackage);


void __RPC_STUB IPMPlatformManager_EnumPackages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_GetPackage_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrPackageIdOrName,
    /* [retval][out] */ IPMPackage **ppiPackage);


void __RPC_STUB IPMPlatformManager_GetPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_AddPackage_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrPackageName,
    /* [defaultvalue][in] */ BSTR bstrPackageId,
    /* [retval][out] */ IPMPackage **ppiPackage);


void __RPC_STUB IPMPlatformManager_AddPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_DeletePackage_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrPackageIdOrName);


void __RPC_STUB IPMPlatformManager_DeletePackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_AddToolkit_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrName,
    /* [defaultvalue][in] */ BSTR bstrToolkitId);


void __RPC_STUB IPMPlatformManager_AddToolkit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_DeleteToolkit_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrToolkitIdOrName);


void __RPC_STUB IPMPlatformManager_DeleteToolkit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_GetConnection_Proxy( 
    IPMPlatformManager * This,
    /* [in] */ BSTR bstrConnectId,
    /* [retval][out] */ IPMConnection **ppiConnection);


void __RPC_STUB IPMPlatformManager_GetConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_GetVersion_Proxy( 
    IPMPlatformManager * This,
    /* [out] */ VARIANT *pwMajorVersion,
    /* [out] */ VARIANT *pwMinorVersion,
    /* [out] */ VARIANT *pdwBuildNumber);


void __RPC_STUB IPMPlatformManager_GetVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_CreateGUID_Proxy( 
    IPMPlatformManager * This,
    /* [retval][out] */ BSTR *pbstrNewGuid);


void __RPC_STUB IPMPlatformManager_CreateGUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_CleanRegistry_Proxy( 
    IPMPlatformManager * This);


void __RPC_STUB IPMPlatformManager_CleanRegistry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatformManager_EnumUniversalPlatforms_Proxy( 
    IPMPlatformManager * This,
    /* [retval][out] */ IEnumVariant **ppiEnumUniversalPlatform);


void __RPC_STUB IPMPlatformManager_EnumUniversalPlatforms_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMPlatformManager_INTERFACE_DEFINED__ */


#ifndef __IPMPlatform_INTERFACE_DEFINED__
#define __IPMPlatform_INTERFACE_DEFINED__

/* interface IPMPlatform */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMPlatform;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5BA32507-0015-40A2-A0FE-AA81CB265FE1")
    IPMPlatform : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ BSTR *pbstrPlatformId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrPlatformName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrPlatformName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumProperties( 
            /* [retval][out] */ IEnumVariant **ppiEnumProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ BSTR pszLinkName,
            /* [defaultvalue][in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteProperty( 
            /* [in] */ BSTR bstrPropId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumDevices( 
            /* [retval][out] */ IEnumVariant **ppiEnumDevice) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [in] */ BSTR bstrDeviceIdOrName,
            /* [retval][out] */ IPMRemoteDevice **ppiRemoteDevice) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddDevice( 
            /* [in] */ BSTR bstrName,
            /* [defaultvalue][in] */ BSTR bstrDeviceId,
            /* [retval][out] */ IPMRemoteDevice **ppiDevice) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteDevice( 
            /* [in] */ BSTR bstrDeviceIdOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumCPUs( 
            /* [retval][out] */ IEnumVariant **ppiEnumCPU) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCPU( 
            /* [in] */ BSTR bstrCPUIdOrName,
            /* [retval][out] */ IPMCPU **ppiCPU) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddCPU( 
            /* [in] */ BSTR bstrIdOrName,
            /* [retval][out] */ IPMCPU **ppiCPU) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteCPU( 
            /* [in] */ BSTR bstrCPUIdOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOS( 
            /* [retval][out] */ IPMOS **ppiOS) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddOS( 
            /* [in] */ BSTR bstrIdOrName,
            /* [retval][out] */ IPMOS **ppiOS) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteOS( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumPackages( 
            /* [retval][out] */ IEnumVariant **ppiEnumPackage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPackage( 
            /* [in] */ BSTR bstrPackageIdOrName,
            /* [retval][out] */ IPMPackage **ppiPackage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddPackage( 
            /* [in] */ BSTR bstrPackageName,
            /* [defaultvalue][in] */ BSTR bstrPackageId,
            /* [retval][out] */ IPMPackage **ppiPackage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeletePackage( 
            /* [in] */ BSTR bstrPackageIdOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumStartupServers( 
            /* [retval][out] */ IEnumVariant **ppiEnumStartupServer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStartupServer( 
            /* [in] */ BSTR bstrStartupServerIdOrName,
            /* [retval][out] */ IPMStartupServerInfo **ppiStartupServer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddStartupServer( 
            /* [in] */ BSTR bstrStartupServerId,
            /* [defaultvalue][in] */ VARIANT_BOOL bDefault,
            /* [retval][out] */ IPMStartupServerInfo **ppiStartupServer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteStartupServer( 
            /* [in] */ BSTR bstrStartupServerIdOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumTransports( 
            /* [retval][out] */ IEnumVariant **ppiEnumTransport) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTransport( 
            /* [in] */ BSTR bstrTransportIdOrName,
            /* [retval][out] */ IPMTransportInfo **ppiTransport) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddTransport( 
            /* [in] */ BSTR bstrTransportId,
            /* [defaultvalue][in] */ VARIANT_BOOL bDefault,
            /* [retval][out] */ IPMTransportInfo **ppiTransport) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteTransport( 
            /* [in] */ BSTR bstrTransportIdOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOSInfo( 
            /* [out] */ VARIANT *pwMajorVersion,
            /* [out] */ VARIANT *pwMinorVersion) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UniversalSDK( 
            /* [retval][out] */ BSTR *pbstrUniversalSDKGuid) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UniversalSDK( 
            /* [in] */ BSTR bstrUniversalSDKGuid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RemoteDbgDirectory( 
            /* [retval][out] */ BSTR *pbstrRemoteDbgDirectory) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMPlatformVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMPlatform * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMPlatform * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMPlatform * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMPlatform * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMPlatform * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMPlatform * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMPlatform * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IPMPlatform * This,
            /* [retval][out] */ BSTR *pbstrPlatformId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IPMPlatform * This,
            /* [retval][out] */ BSTR *pbstrPlatformName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrPlatformName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IPMPlatform * This,
            /* [retval][out] */ IEnumVariant **ppiEnumProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IPMPlatform * This,
            /* [in] */ BSTR pszLinkName,
            /* [defaultvalue][in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrPropId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumDevices )( 
            IPMPlatform * This,
            /* [retval][out] */ IEnumVariant **ppiEnumDevice);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrDeviceIdOrName,
            /* [retval][out] */ IPMRemoteDevice **ppiRemoteDevice);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddDevice )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrName,
            /* [defaultvalue][in] */ BSTR bstrDeviceId,
            /* [retval][out] */ IPMRemoteDevice **ppiDevice);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteDevice )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrDeviceIdOrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumCPUs )( 
            IPMPlatform * This,
            /* [retval][out] */ IEnumVariant **ppiEnumCPU);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCPU )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrCPUIdOrName,
            /* [retval][out] */ IPMCPU **ppiCPU);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddCPU )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrIdOrName,
            /* [retval][out] */ IPMCPU **ppiCPU);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteCPU )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrCPUIdOrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetOS )( 
            IPMPlatform * This,
            /* [retval][out] */ IPMOS **ppiOS);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddOS )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrIdOrName,
            /* [retval][out] */ IPMOS **ppiOS);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteOS )( 
            IPMPlatform * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumPackages )( 
            IPMPlatform * This,
            /* [retval][out] */ IEnumVariant **ppiEnumPackage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPackage )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrPackageIdOrName,
            /* [retval][out] */ IPMPackage **ppiPackage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddPackage )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrPackageName,
            /* [defaultvalue][in] */ BSTR bstrPackageId,
            /* [retval][out] */ IPMPackage **ppiPackage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeletePackage )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrPackageIdOrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumStartupServers )( 
            IPMPlatform * This,
            /* [retval][out] */ IEnumVariant **ppiEnumStartupServer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetStartupServer )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrStartupServerIdOrName,
            /* [retval][out] */ IPMStartupServerInfo **ppiStartupServer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddStartupServer )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrStartupServerId,
            /* [defaultvalue][in] */ VARIANT_BOOL bDefault,
            /* [retval][out] */ IPMStartupServerInfo **ppiStartupServer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteStartupServer )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrStartupServerIdOrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumTransports )( 
            IPMPlatform * This,
            /* [retval][out] */ IEnumVariant **ppiEnumTransport);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTransport )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrTransportIdOrName,
            /* [retval][out] */ IPMTransportInfo **ppiTransport);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddTransport )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrTransportId,
            /* [defaultvalue][in] */ VARIANT_BOOL bDefault,
            /* [retval][out] */ IPMTransportInfo **ppiTransport);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteTransport )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrTransportIdOrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetOSInfo )( 
            IPMPlatform * This,
            /* [out] */ VARIANT *pwMajorVersion,
            /* [out] */ VARIANT *pwMinorVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UniversalSDK )( 
            IPMPlatform * This,
            /* [retval][out] */ BSTR *pbstrUniversalSDKGuid);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UniversalSDK )( 
            IPMPlatform * This,
            /* [in] */ BSTR bstrUniversalSDKGuid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteDbgDirectory )( 
            IPMPlatform * This,
            /* [retval][out] */ BSTR *pbstrRemoteDbgDirectory);
        
        END_INTERFACE
    } IPMPlatformVtbl;

    interface IPMPlatform
    {
        CONST_VTBL struct IPMPlatformVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMPlatform_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMPlatform_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMPlatform_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMPlatform_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMPlatform_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMPlatform_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMPlatform_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMPlatform_get_Id(This,pbstrPlatformId)	\
    (This)->lpVtbl -> get_Id(This,pbstrPlatformId)

#define IPMPlatform_get_Name(This,pbstrPlatformName)	\
    (This)->lpVtbl -> get_Name(This,pbstrPlatformName)

#define IPMPlatform_put_Name(This,bstrPlatformName)	\
    (This)->lpVtbl -> put_Name(This,bstrPlatformName)

#define IPMPlatform_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IPMPlatform_GetProperty(This,bstrPropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,bstrPropId,ppiProperty)

#define IPMPlatform_AddProperty(This,pszLinkName,bstrPropId,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,pszLinkName,bstrPropId,ppiProperty)

#define IPMPlatform_DeleteProperty(This,bstrPropId)	\
    (This)->lpVtbl -> DeleteProperty(This,bstrPropId)

#define IPMPlatform_EnumDevices(This,ppiEnumDevice)	\
    (This)->lpVtbl -> EnumDevices(This,ppiEnumDevice)

#define IPMPlatform_GetDevice(This,bstrDeviceIdOrName,ppiRemoteDevice)	\
    (This)->lpVtbl -> GetDevice(This,bstrDeviceIdOrName,ppiRemoteDevice)

#define IPMPlatform_AddDevice(This,bstrName,bstrDeviceId,ppiDevice)	\
    (This)->lpVtbl -> AddDevice(This,bstrName,bstrDeviceId,ppiDevice)

#define IPMPlatform_DeleteDevice(This,bstrDeviceIdOrName)	\
    (This)->lpVtbl -> DeleteDevice(This,bstrDeviceIdOrName)

#define IPMPlatform_EnumCPUs(This,ppiEnumCPU)	\
    (This)->lpVtbl -> EnumCPUs(This,ppiEnumCPU)

#define IPMPlatform_GetCPU(This,bstrCPUIdOrName,ppiCPU)	\
    (This)->lpVtbl -> GetCPU(This,bstrCPUIdOrName,ppiCPU)

#define IPMPlatform_AddCPU(This,bstrIdOrName,ppiCPU)	\
    (This)->lpVtbl -> AddCPU(This,bstrIdOrName,ppiCPU)

#define IPMPlatform_DeleteCPU(This,bstrCPUIdOrName)	\
    (This)->lpVtbl -> DeleteCPU(This,bstrCPUIdOrName)

#define IPMPlatform_GetOS(This,ppiOS)	\
    (This)->lpVtbl -> GetOS(This,ppiOS)

#define IPMPlatform_AddOS(This,bstrIdOrName,ppiOS)	\
    (This)->lpVtbl -> AddOS(This,bstrIdOrName,ppiOS)

#define IPMPlatform_DeleteOS(This)	\
    (This)->lpVtbl -> DeleteOS(This)

#define IPMPlatform_EnumPackages(This,ppiEnumPackage)	\
    (This)->lpVtbl -> EnumPackages(This,ppiEnumPackage)

#define IPMPlatform_GetPackage(This,bstrPackageIdOrName,ppiPackage)	\
    (This)->lpVtbl -> GetPackage(This,bstrPackageIdOrName,ppiPackage)

#define IPMPlatform_AddPackage(This,bstrPackageName,bstrPackageId,ppiPackage)	\
    (This)->lpVtbl -> AddPackage(This,bstrPackageName,bstrPackageId,ppiPackage)

#define IPMPlatform_DeletePackage(This,bstrPackageIdOrName)	\
    (This)->lpVtbl -> DeletePackage(This,bstrPackageIdOrName)

#define IPMPlatform_EnumStartupServers(This,ppiEnumStartupServer)	\
    (This)->lpVtbl -> EnumStartupServers(This,ppiEnumStartupServer)

#define IPMPlatform_GetStartupServer(This,bstrStartupServerIdOrName,ppiStartupServer)	\
    (This)->lpVtbl -> GetStartupServer(This,bstrStartupServerIdOrName,ppiStartupServer)

#define IPMPlatform_AddStartupServer(This,bstrStartupServerId,bDefault,ppiStartupServer)	\
    (This)->lpVtbl -> AddStartupServer(This,bstrStartupServerId,bDefault,ppiStartupServer)

#define IPMPlatform_DeleteStartupServer(This,bstrStartupServerIdOrName)	\
    (This)->lpVtbl -> DeleteStartupServer(This,bstrStartupServerIdOrName)

#define IPMPlatform_EnumTransports(This,ppiEnumTransport)	\
    (This)->lpVtbl -> EnumTransports(This,ppiEnumTransport)

#define IPMPlatform_GetTransport(This,bstrTransportIdOrName,ppiTransport)	\
    (This)->lpVtbl -> GetTransport(This,bstrTransportIdOrName,ppiTransport)

#define IPMPlatform_AddTransport(This,bstrTransportId,bDefault,ppiTransport)	\
    (This)->lpVtbl -> AddTransport(This,bstrTransportId,bDefault,ppiTransport)

#define IPMPlatform_DeleteTransport(This,bstrTransportIdOrName)	\
    (This)->lpVtbl -> DeleteTransport(This,bstrTransportIdOrName)

#define IPMPlatform_GetOSInfo(This,pwMajorVersion,pwMinorVersion)	\
    (This)->lpVtbl -> GetOSInfo(This,pwMajorVersion,pwMinorVersion)

#define IPMPlatform_get_UniversalSDK(This,pbstrUniversalSDKGuid)	\
    (This)->lpVtbl -> get_UniversalSDK(This,pbstrUniversalSDKGuid)

#define IPMPlatform_put_UniversalSDK(This,bstrUniversalSDKGuid)	\
    (This)->lpVtbl -> put_UniversalSDK(This,bstrUniversalSDKGuid)

#define IPMPlatform_get_RemoteDbgDirectory(This,pbstrRemoteDbgDirectory)	\
    (This)->lpVtbl -> get_RemoteDbgDirectory(This,pbstrRemoteDbgDirectory)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPlatform_get_Id_Proxy( 
    IPMPlatform * This,
    /* [retval][out] */ BSTR *pbstrPlatformId);


void __RPC_STUB IPMPlatform_get_Id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPlatform_get_Name_Proxy( 
    IPMPlatform * This,
    /* [retval][out] */ BSTR *pbstrPlatformName);


void __RPC_STUB IPMPlatform_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMPlatform_put_Name_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrPlatformName);


void __RPC_STUB IPMPlatform_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_EnumProperties_Proxy( 
    IPMPlatform * This,
    /* [retval][out] */ IEnumVariant **ppiEnumProperty);


void __RPC_STUB IPMPlatform_EnumProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_GetProperty_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrPropId,
    /* [retval][out] */ IPMProperty **ppiProperty);


void __RPC_STUB IPMPlatform_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_AddProperty_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR pszLinkName,
    /* [defaultvalue][in] */ BSTR bstrPropId,
    /* [retval][out] */ IPMProperty **ppiProperty);


void __RPC_STUB IPMPlatform_AddProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_DeleteProperty_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrPropId);


void __RPC_STUB IPMPlatform_DeleteProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_EnumDevices_Proxy( 
    IPMPlatform * This,
    /* [retval][out] */ IEnumVariant **ppiEnumDevice);


void __RPC_STUB IPMPlatform_EnumDevices_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_GetDevice_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrDeviceIdOrName,
    /* [retval][out] */ IPMRemoteDevice **ppiRemoteDevice);


void __RPC_STUB IPMPlatform_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_AddDevice_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrName,
    /* [defaultvalue][in] */ BSTR bstrDeviceId,
    /* [retval][out] */ IPMRemoteDevice **ppiDevice);


void __RPC_STUB IPMPlatform_AddDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_DeleteDevice_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrDeviceIdOrName);


void __RPC_STUB IPMPlatform_DeleteDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_EnumCPUs_Proxy( 
    IPMPlatform * This,
    /* [retval][out] */ IEnumVariant **ppiEnumCPU);


void __RPC_STUB IPMPlatform_EnumCPUs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_GetCPU_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrCPUIdOrName,
    /* [retval][out] */ IPMCPU **ppiCPU);


void __RPC_STUB IPMPlatform_GetCPU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_AddCPU_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrIdOrName,
    /* [retval][out] */ IPMCPU **ppiCPU);


void __RPC_STUB IPMPlatform_AddCPU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_DeleteCPU_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrCPUIdOrName);


void __RPC_STUB IPMPlatform_DeleteCPU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_GetOS_Proxy( 
    IPMPlatform * This,
    /* [retval][out] */ IPMOS **ppiOS);


void __RPC_STUB IPMPlatform_GetOS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_AddOS_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrIdOrName,
    /* [retval][out] */ IPMOS **ppiOS);


void __RPC_STUB IPMPlatform_AddOS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_DeleteOS_Proxy( 
    IPMPlatform * This);


void __RPC_STUB IPMPlatform_DeleteOS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_EnumPackages_Proxy( 
    IPMPlatform * This,
    /* [retval][out] */ IEnumVariant **ppiEnumPackage);


void __RPC_STUB IPMPlatform_EnumPackages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_GetPackage_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrPackageIdOrName,
    /* [retval][out] */ IPMPackage **ppiPackage);


void __RPC_STUB IPMPlatform_GetPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_AddPackage_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrPackageName,
    /* [defaultvalue][in] */ BSTR bstrPackageId,
    /* [retval][out] */ IPMPackage **ppiPackage);


void __RPC_STUB IPMPlatform_AddPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_DeletePackage_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrPackageIdOrName);


void __RPC_STUB IPMPlatform_DeletePackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_EnumStartupServers_Proxy( 
    IPMPlatform * This,
    /* [retval][out] */ IEnumVariant **ppiEnumStartupServer);


void __RPC_STUB IPMPlatform_EnumStartupServers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_GetStartupServer_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrStartupServerIdOrName,
    /* [retval][out] */ IPMStartupServerInfo **ppiStartupServer);


void __RPC_STUB IPMPlatform_GetStartupServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_AddStartupServer_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrStartupServerId,
    /* [defaultvalue][in] */ VARIANT_BOOL bDefault,
    /* [retval][out] */ IPMStartupServerInfo **ppiStartupServer);


void __RPC_STUB IPMPlatform_AddStartupServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_DeleteStartupServer_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrStartupServerIdOrName);


void __RPC_STUB IPMPlatform_DeleteStartupServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_EnumTransports_Proxy( 
    IPMPlatform * This,
    /* [retval][out] */ IEnumVariant **ppiEnumTransport);


void __RPC_STUB IPMPlatform_EnumTransports_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_GetTransport_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrTransportIdOrName,
    /* [retval][out] */ IPMTransportInfo **ppiTransport);


void __RPC_STUB IPMPlatform_GetTransport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_AddTransport_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrTransportId,
    /* [defaultvalue][in] */ VARIANT_BOOL bDefault,
    /* [retval][out] */ IPMTransportInfo **ppiTransport);


void __RPC_STUB IPMPlatform_AddTransport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_DeleteTransport_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrTransportIdOrName);


void __RPC_STUB IPMPlatform_DeleteTransport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPlatform_GetOSInfo_Proxy( 
    IPMPlatform * This,
    /* [out] */ VARIANT *pwMajorVersion,
    /* [out] */ VARIANT *pwMinorVersion);


void __RPC_STUB IPMPlatform_GetOSInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPlatform_get_UniversalSDK_Proxy( 
    IPMPlatform * This,
    /* [retval][out] */ BSTR *pbstrUniversalSDKGuid);


void __RPC_STUB IPMPlatform_get_UniversalSDK_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMPlatform_put_UniversalSDK_Proxy( 
    IPMPlatform * This,
    /* [in] */ BSTR bstrUniversalSDKGuid);


void __RPC_STUB IPMPlatform_put_UniversalSDK_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPlatform_get_RemoteDbgDirectory_Proxy( 
    IPMPlatform * This,
    /* [retval][out] */ BSTR *pbstrRemoteDbgDirectory);


void __RPC_STUB IPMPlatform_get_RemoteDbgDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMPlatform_INTERFACE_DEFINED__ */


#ifndef __IPMRemoteDevice_INTERFACE_DEFINED__
#define __IPMRemoteDevice_INTERFACE_DEFINED__

/* interface IPMRemoteDevice */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMRemoteDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BCDAA3C8-E342-4DC0-A127-192780E4244B")
    IPMRemoteDevice : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ BSTR *pbstrDeviceId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrDeviceName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StartupServer( 
            /* [retval][out] */ BSTR *pbstrStartupServerId) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StartupServer( 
            /* [in] */ BSTR bstrStartupServerId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Transport( 
            /* [retval][out] */ BSTR *pbstrTransportId) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Transport( 
            /* [in] */ BSTR bstrTransportId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumProperties( 
            /* [retval][out] */ IEnumVariant **ppiEnumProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ BSTR bstrLinkName,
            /* [defaultvalue][in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteProperty( 
            /* [in] */ BSTR bstrPropId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Attach( 
            /* [in] */ BSTR bstrProcessName,
            /* [in] */ long dwTimeOut,
            /* [optional][in] */ VARIANT vtProcessId,
            /* [retval][out] */ IPMConnection **ppiConnection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetConnection( 
            /* [in] */ BSTR bstrConnectId,
            /* [retval][out] */ IPMConnection **ppiConnection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConfigureStartupServer( 
            /* [optional][in] */ VARIANT hWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConfigureTransport( 
            /* [optional][in] */ VARIANT hWnd) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Platform( 
            /* [retval][out] */ IPMPlatform **ppiPlatform) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMRemoteDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMRemoteDevice * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMRemoteDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMRemoteDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMRemoteDevice * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMRemoteDevice * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMRemoteDevice * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMRemoteDevice * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IPMRemoteDevice * This,
            /* [retval][out] */ BSTR *pbstrDeviceId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IPMRemoteDevice * This,
            /* [retval][out] */ BSTR *pbstrDeviceName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IPMRemoteDevice * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartupServer )( 
            IPMRemoteDevice * This,
            /* [retval][out] */ BSTR *pbstrStartupServerId);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StartupServer )( 
            IPMRemoteDevice * This,
            /* [in] */ BSTR bstrStartupServerId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Transport )( 
            IPMRemoteDevice * This,
            /* [retval][out] */ BSTR *pbstrTransportId);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Transport )( 
            IPMRemoteDevice * This,
            /* [in] */ BSTR bstrTransportId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IPMRemoteDevice * This,
            /* [retval][out] */ IEnumVariant **ppiEnumProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IPMRemoteDevice * This,
            /* [in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IPMRemoteDevice * This,
            /* [in] */ BSTR bstrLinkName,
            /* [defaultvalue][in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IPMRemoteDevice * This,
            /* [in] */ BSTR bstrPropId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IPMRemoteDevice * This,
            /* [in] */ BSTR bstrProcessName,
            /* [in] */ long dwTimeOut,
            /* [optional][in] */ VARIANT vtProcessId,
            /* [retval][out] */ IPMConnection **ppiConnection);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnection )( 
            IPMRemoteDevice * This,
            /* [in] */ BSTR bstrConnectId,
            /* [retval][out] */ IPMConnection **ppiConnection);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConfigureStartupServer )( 
            IPMRemoteDevice * This,
            /* [optional][in] */ VARIANT hWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConfigureTransport )( 
            IPMRemoteDevice * This,
            /* [optional][in] */ VARIANT hWnd);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Platform )( 
            IPMRemoteDevice * This,
            /* [retval][out] */ IPMPlatform **ppiPlatform);
        
        END_INTERFACE
    } IPMRemoteDeviceVtbl;

    interface IPMRemoteDevice
    {
        CONST_VTBL struct IPMRemoteDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMRemoteDevice_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMRemoteDevice_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMRemoteDevice_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMRemoteDevice_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMRemoteDevice_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMRemoteDevice_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMRemoteDevice_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMRemoteDevice_get_Id(This,pbstrDeviceId)	\
    (This)->lpVtbl -> get_Id(This,pbstrDeviceId)

#define IPMRemoteDevice_get_Name(This,pbstrDeviceName)	\
    (This)->lpVtbl -> get_Name(This,pbstrDeviceName)

#define IPMRemoteDevice_put_Name(This,bstrName)	\
    (This)->lpVtbl -> put_Name(This,bstrName)

#define IPMRemoteDevice_get_StartupServer(This,pbstrStartupServerId)	\
    (This)->lpVtbl -> get_StartupServer(This,pbstrStartupServerId)

#define IPMRemoteDevice_put_StartupServer(This,bstrStartupServerId)	\
    (This)->lpVtbl -> put_StartupServer(This,bstrStartupServerId)

#define IPMRemoteDevice_get_Transport(This,pbstrTransportId)	\
    (This)->lpVtbl -> get_Transport(This,pbstrTransportId)

#define IPMRemoteDevice_put_Transport(This,bstrTransportId)	\
    (This)->lpVtbl -> put_Transport(This,bstrTransportId)

#define IPMRemoteDevice_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IPMRemoteDevice_GetProperty(This,bstrPropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,bstrPropId,ppiProperty)

#define IPMRemoteDevice_AddProperty(This,bstrLinkName,bstrPropId,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,bstrLinkName,bstrPropId,ppiProperty)

#define IPMRemoteDevice_DeleteProperty(This,bstrPropId)	\
    (This)->lpVtbl -> DeleteProperty(This,bstrPropId)

#define IPMRemoteDevice_Attach(This,bstrProcessName,dwTimeOut,vtProcessId,ppiConnection)	\
    (This)->lpVtbl -> Attach(This,bstrProcessName,dwTimeOut,vtProcessId,ppiConnection)

#define IPMRemoteDevice_GetConnection(This,bstrConnectId,ppiConnection)	\
    (This)->lpVtbl -> GetConnection(This,bstrConnectId,ppiConnection)

#define IPMRemoteDevice_ConfigureStartupServer(This,hWnd)	\
    (This)->lpVtbl -> ConfigureStartupServer(This,hWnd)

#define IPMRemoteDevice_ConfigureTransport(This,hWnd)	\
    (This)->lpVtbl -> ConfigureTransport(This,hWnd)

#define IPMRemoteDevice_get_Platform(This,ppiPlatform)	\
    (This)->lpVtbl -> get_Platform(This,ppiPlatform)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_get_Id_Proxy( 
    IPMRemoteDevice * This,
    /* [retval][out] */ BSTR *pbstrDeviceId);


void __RPC_STUB IPMRemoteDevice_get_Id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_get_Name_Proxy( 
    IPMRemoteDevice * This,
    /* [retval][out] */ BSTR *pbstrDeviceName);


void __RPC_STUB IPMRemoteDevice_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_put_Name_Proxy( 
    IPMRemoteDevice * This,
    /* [in] */ BSTR bstrName);


void __RPC_STUB IPMRemoteDevice_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_get_StartupServer_Proxy( 
    IPMRemoteDevice * This,
    /* [retval][out] */ BSTR *pbstrStartupServerId);


void __RPC_STUB IPMRemoteDevice_get_StartupServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_put_StartupServer_Proxy( 
    IPMRemoteDevice * This,
    /* [in] */ BSTR bstrStartupServerId);


void __RPC_STUB IPMRemoteDevice_put_StartupServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_get_Transport_Proxy( 
    IPMRemoteDevice * This,
    /* [retval][out] */ BSTR *pbstrTransportId);


void __RPC_STUB IPMRemoteDevice_get_Transport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_put_Transport_Proxy( 
    IPMRemoteDevice * This,
    /* [in] */ BSTR bstrTransportId);


void __RPC_STUB IPMRemoteDevice_put_Transport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_EnumProperties_Proxy( 
    IPMRemoteDevice * This,
    /* [retval][out] */ IEnumVariant **ppiEnumProperty);


void __RPC_STUB IPMRemoteDevice_EnumProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_GetProperty_Proxy( 
    IPMRemoteDevice * This,
    /* [in] */ BSTR bstrPropId,
    /* [retval][out] */ IPMProperty **ppiProperty);


void __RPC_STUB IPMRemoteDevice_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_AddProperty_Proxy( 
    IPMRemoteDevice * This,
    /* [in] */ BSTR bstrLinkName,
    /* [defaultvalue][in] */ BSTR bstrPropId,
    /* [retval][out] */ IPMProperty **ppiProperty);


void __RPC_STUB IPMRemoteDevice_AddProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_DeleteProperty_Proxy( 
    IPMRemoteDevice * This,
    /* [in] */ BSTR bstrPropId);


void __RPC_STUB IPMRemoteDevice_DeleteProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_Attach_Proxy( 
    IPMRemoteDevice * This,
    /* [in] */ BSTR bstrProcessName,
    /* [in] */ long dwTimeOut,
    /* [optional][in] */ VARIANT vtProcessId,
    /* [retval][out] */ IPMConnection **ppiConnection);


void __RPC_STUB IPMRemoteDevice_Attach_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_GetConnection_Proxy( 
    IPMRemoteDevice * This,
    /* [in] */ BSTR bstrConnectId,
    /* [retval][out] */ IPMConnection **ppiConnection);


void __RPC_STUB IPMRemoteDevice_GetConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_ConfigureStartupServer_Proxy( 
    IPMRemoteDevice * This,
    /* [optional][in] */ VARIANT hWnd);


void __RPC_STUB IPMRemoteDevice_ConfigureStartupServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_ConfigureTransport_Proxy( 
    IPMRemoteDevice * This,
    /* [optional][in] */ VARIANT hWnd);


void __RPC_STUB IPMRemoteDevice_ConfigureTransport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMRemoteDevice_get_Platform_Proxy( 
    IPMRemoteDevice * This,
    /* [retval][out] */ IPMPlatform **ppiPlatform);


void __RPC_STUB IPMRemoteDevice_get_Platform_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMRemoteDevice_INTERFACE_DEFINED__ */


#ifndef __IPMProperty_INTERFACE_DEFINED__
#define __IPMProperty_INTERFACE_DEFINED__

/* interface IPMProperty */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D9956420-DF23-46E0-88E1-4E0D759E97DB")
    IPMProperty : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ BSTR *pbstrPropId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumProperties( 
            /* [retval][out] */ IEnumVariant **ppiEnumProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ BSTR bstrLinkName,
            /* [defaultvalue][in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteProperty( 
            /* [in] */ BSTR bstrPropId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumPropInfos( 
            /* [retval][out] */ IEnumVariant **ppiEnumPropInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPropInfo( 
            /* [in] */ BSTR bstrPropName,
            /* [retval][out] */ IPMPropInfo **ppiPropInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddPropInfo( 
            /* [in] */ BSTR bstrPropInfoName,
            /* [in] */ long dwPropInfoType,
            /* [in] */ BSTR bstrPropInfoValue,
            /* [retval][out] */ IPMPropInfo **ppiPropInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeletePropInfo( 
            /* [in] */ BSTR bstrPropInfoName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMPropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMProperty * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMProperty * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMProperty * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMProperty * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMProperty * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMProperty * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMProperty * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IPMProperty * This,
            /* [retval][out] */ BSTR *pbstrPropId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IPMProperty * This,
            /* [retval][out] */ IEnumVariant **ppiEnumProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IPMProperty * This,
            /* [in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IPMProperty * This,
            /* [in] */ BSTR bstrLinkName,
            /* [defaultvalue][in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IPMProperty * This,
            /* [in] */ BSTR bstrPropId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumPropInfos )( 
            IPMProperty * This,
            /* [retval][out] */ IEnumVariant **ppiEnumPropInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPropInfo )( 
            IPMProperty * This,
            /* [in] */ BSTR bstrPropName,
            /* [retval][out] */ IPMPropInfo **ppiPropInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddPropInfo )( 
            IPMProperty * This,
            /* [in] */ BSTR bstrPropInfoName,
            /* [in] */ long dwPropInfoType,
            /* [in] */ BSTR bstrPropInfoValue,
            /* [retval][out] */ IPMPropInfo **ppiPropInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeletePropInfo )( 
            IPMProperty * This,
            /* [in] */ BSTR bstrPropInfoName);
        
        END_INTERFACE
    } IPMPropertyVtbl;

    interface IPMProperty
    {
        CONST_VTBL struct IPMPropertyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMProperty_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMProperty_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMProperty_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMProperty_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMProperty_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMProperty_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMProperty_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMProperty_get_Id(This,pbstrPropId)	\
    (This)->lpVtbl -> get_Id(This,pbstrPropId)

#define IPMProperty_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IPMProperty_GetProperty(This,bstrPropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,bstrPropId,ppiProperty)

#define IPMProperty_AddProperty(This,bstrLinkName,bstrPropId,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,bstrLinkName,bstrPropId,ppiProperty)

#define IPMProperty_DeleteProperty(This,bstrPropId)	\
    (This)->lpVtbl -> DeleteProperty(This,bstrPropId)

#define IPMProperty_EnumPropInfos(This,ppiEnumPropInfo)	\
    (This)->lpVtbl -> EnumPropInfos(This,ppiEnumPropInfo)

#define IPMProperty_GetPropInfo(This,bstrPropName,ppiPropInfo)	\
    (This)->lpVtbl -> GetPropInfo(This,bstrPropName,ppiPropInfo)

#define IPMProperty_AddPropInfo(This,bstrPropInfoName,dwPropInfoType,bstrPropInfoValue,ppiPropInfo)	\
    (This)->lpVtbl -> AddPropInfo(This,bstrPropInfoName,dwPropInfoType,bstrPropInfoValue,ppiPropInfo)

#define IPMProperty_DeletePropInfo(This,bstrPropInfoName)	\
    (This)->lpVtbl -> DeletePropInfo(This,bstrPropInfoName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMProperty_get_Id_Proxy( 
    IPMProperty * This,
    /* [retval][out] */ BSTR *pbstrPropId);


void __RPC_STUB IPMProperty_get_Id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMProperty_EnumProperties_Proxy( 
    IPMProperty * This,
    /* [retval][out] */ IEnumVariant **ppiEnumProperty);


void __RPC_STUB IPMProperty_EnumProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMProperty_GetProperty_Proxy( 
    IPMProperty * This,
    /* [in] */ BSTR bstrPropId,
    /* [retval][out] */ IPMProperty **ppiProperty);


void __RPC_STUB IPMProperty_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMProperty_AddProperty_Proxy( 
    IPMProperty * This,
    /* [in] */ BSTR bstrLinkName,
    /* [defaultvalue][in] */ BSTR bstrPropId,
    /* [retval][out] */ IPMProperty **ppiProperty);


void __RPC_STUB IPMProperty_AddProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMProperty_DeleteProperty_Proxy( 
    IPMProperty * This,
    /* [in] */ BSTR bstrPropId);


void __RPC_STUB IPMProperty_DeleteProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMProperty_EnumPropInfos_Proxy( 
    IPMProperty * This,
    /* [retval][out] */ IEnumVariant **ppiEnumPropInfo);


void __RPC_STUB IPMProperty_EnumPropInfos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMProperty_GetPropInfo_Proxy( 
    IPMProperty * This,
    /* [in] */ BSTR bstrPropName,
    /* [retval][out] */ IPMPropInfo **ppiPropInfo);


void __RPC_STUB IPMProperty_GetPropInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMProperty_AddPropInfo_Proxy( 
    IPMProperty * This,
    /* [in] */ BSTR bstrPropInfoName,
    /* [in] */ long dwPropInfoType,
    /* [in] */ BSTR bstrPropInfoValue,
    /* [retval][out] */ IPMPropInfo **ppiPropInfo);


void __RPC_STUB IPMProperty_AddPropInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMProperty_DeletePropInfo_Proxy( 
    IPMProperty * This,
    /* [in] */ BSTR bstrPropInfoName);


void __RPC_STUB IPMProperty_DeletePropInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMProperty_INTERFACE_DEFINED__ */


#ifndef __IPMBootableDevice_INTERFACE_DEFINED__
#define __IPMBootableDevice_INTERFACE_DEFINED__

/* interface IPMBootableDevice */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMBootableDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6C8863F4-54B3-417E-83BF-2D63BFDDE437")
    IPMBootableDevice : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ BSTR *pbstrBootableDeviceId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrBootableDeviceName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumProperties( 
            /* [retval][out] */ IEnumVariant **ppiEnumProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ BSTR bstrLinkName,
            /* [defaultvalue][in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteProperty( 
            /* [in] */ BSTR bstrPropId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetService( 
            /* [in] */ BSTR bstrServiceCategoryIdOrName,
            /* [retval][out] */ IPMService **ppiService) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddServiceInfo( 
            /* [in] */ BSTR bstrServiceCategoryIdOrName,
            /* [in] */ BSTR bstrServiceCLSID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteService( 
            /* [in] */ BSTR bstrServiceCategoryIdOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMBootableDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMBootableDevice * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMBootableDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMBootableDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMBootableDevice * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMBootableDevice * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMBootableDevice * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMBootableDevice * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IPMBootableDevice * This,
            /* [retval][out] */ BSTR *pbstrBootableDeviceId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IPMBootableDevice * This,
            /* [retval][out] */ BSTR *pbstrBootableDeviceName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IPMBootableDevice * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IPMBootableDevice * This,
            /* [retval][out] */ IEnumVariant **ppiEnumProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IPMBootableDevice * This,
            /* [in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IPMBootableDevice * This,
            /* [in] */ BSTR bstrLinkName,
            /* [defaultvalue][in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IPMBootableDevice * This,
            /* [in] */ BSTR bstrPropId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetService )( 
            IPMBootableDevice * This,
            /* [in] */ BSTR bstrServiceCategoryIdOrName,
            /* [retval][out] */ IPMService **ppiService);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddServiceInfo )( 
            IPMBootableDevice * This,
            /* [in] */ BSTR bstrServiceCategoryIdOrName,
            /* [in] */ BSTR bstrServiceCLSID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteService )( 
            IPMBootableDevice * This,
            /* [in] */ BSTR bstrServiceCategoryIdOrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IPMBootableDevice * This);
        
        END_INTERFACE
    } IPMBootableDeviceVtbl;

    interface IPMBootableDevice
    {
        CONST_VTBL struct IPMBootableDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMBootableDevice_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMBootableDevice_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMBootableDevice_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMBootableDevice_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMBootableDevice_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMBootableDevice_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMBootableDevice_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMBootableDevice_get_Id(This,pbstrBootableDeviceId)	\
    (This)->lpVtbl -> get_Id(This,pbstrBootableDeviceId)

#define IPMBootableDevice_get_Name(This,pbstrBootableDeviceName)	\
    (This)->lpVtbl -> get_Name(This,pbstrBootableDeviceName)

#define IPMBootableDevice_put_Name(This,bstrName)	\
    (This)->lpVtbl -> put_Name(This,bstrName)

#define IPMBootableDevice_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IPMBootableDevice_GetProperty(This,bstrPropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,bstrPropId,ppiProperty)

#define IPMBootableDevice_AddProperty(This,bstrLinkName,bstrPropId,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,bstrLinkName,bstrPropId,ppiProperty)

#define IPMBootableDevice_DeleteProperty(This,bstrPropId)	\
    (This)->lpVtbl -> DeleteProperty(This,bstrPropId)

#define IPMBootableDevice_GetService(This,bstrServiceCategoryIdOrName,ppiService)	\
    (This)->lpVtbl -> GetService(This,bstrServiceCategoryIdOrName,ppiService)

#define IPMBootableDevice_AddServiceInfo(This,bstrServiceCategoryIdOrName,bstrServiceCLSID)	\
    (This)->lpVtbl -> AddServiceInfo(This,bstrServiceCategoryIdOrName,bstrServiceCLSID)

#define IPMBootableDevice_DeleteService(This,bstrServiceCategoryIdOrName)	\
    (This)->lpVtbl -> DeleteService(This,bstrServiceCategoryIdOrName)

#define IPMBootableDevice_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMBootableDevice_get_Id_Proxy( 
    IPMBootableDevice * This,
    /* [retval][out] */ BSTR *pbstrBootableDeviceId);


void __RPC_STUB IPMBootableDevice_get_Id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMBootableDevice_get_Name_Proxy( 
    IPMBootableDevice * This,
    /* [retval][out] */ BSTR *pbstrBootableDeviceName);


void __RPC_STUB IPMBootableDevice_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMBootableDevice_put_Name_Proxy( 
    IPMBootableDevice * This,
    /* [in] */ BSTR bstrName);


void __RPC_STUB IPMBootableDevice_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMBootableDevice_EnumProperties_Proxy( 
    IPMBootableDevice * This,
    /* [retval][out] */ IEnumVariant **ppiEnumProperty);


void __RPC_STUB IPMBootableDevice_EnumProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMBootableDevice_GetProperty_Proxy( 
    IPMBootableDevice * This,
    /* [in] */ BSTR bstrPropId,
    /* [retval][out] */ IPMProperty **ppiProperty);


void __RPC_STUB IPMBootableDevice_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMBootableDevice_AddProperty_Proxy( 
    IPMBootableDevice * This,
    /* [in] */ BSTR bstrLinkName,
    /* [defaultvalue][in] */ BSTR bstrPropId,
    /* [retval][out] */ IPMProperty **ppiProperty);


void __RPC_STUB IPMBootableDevice_AddProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMBootableDevice_DeleteProperty_Proxy( 
    IPMBootableDevice * This,
    /* [in] */ BSTR bstrPropId);


void __RPC_STUB IPMBootableDevice_DeleteProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMBootableDevice_GetService_Proxy( 
    IPMBootableDevice * This,
    /* [in] */ BSTR bstrServiceCategoryIdOrName,
    /* [retval][out] */ IPMService **ppiService);


void __RPC_STUB IPMBootableDevice_GetService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMBootableDevice_AddServiceInfo_Proxy( 
    IPMBootableDevice * This,
    /* [in] */ BSTR bstrServiceCategoryIdOrName,
    /* [in] */ BSTR bstrServiceCLSID);


void __RPC_STUB IPMBootableDevice_AddServiceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMBootableDevice_DeleteService_Proxy( 
    IPMBootableDevice * This,
    /* [in] */ BSTR bstrServiceCategoryIdOrName);


void __RPC_STUB IPMBootableDevice_DeleteService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMBootableDevice_Disconnect_Proxy( 
    IPMBootableDevice * This);


void __RPC_STUB IPMBootableDevice_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMBootableDevice_INTERFACE_DEFINED__ */


#ifndef __IPMPackage_INTERFACE_DEFINED__
#define __IPMPackage_INTERFACE_DEFINED__

/* interface IPMPackage */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMPackage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AF7FD18F-EC3E-4760-B1A7-EF9EC0B8D4D1")
    IPMPackage : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ BSTR *pbstrPackageId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrPackageName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumFiles( 
            /* [retval][out] */ IEnumVariant **ppiEnumFiles) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFile( 
            /* [in] */ BSTR bstrFullPath,
            /* [in] */ BSTR bstrKeyName,
            /* [retval][out] */ IPMPackageFile **ppiPMPackageFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddFile( 
            /* [in] */ BSTR bstrFullPath,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ IPMCPU *piPMCPU,
            /* [in] */ IPMOS *piPMOS,
            /* [in] */ long dwLocaleId,
            /* [in] */ long dwFlags,
            /* [retval][out] */ IPMPackageFile **ppiPMPackageFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteFile( 
            /* [in] */ BSTR bstrFullPath,
            /* [in] */ BSTR bstrKeyName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddCPUFiles( 
            /* [in] */ BSTR bstrFullPath,
            /* [in] */ BSTR bstrKeyName,
            /* [defaultvalue][in] */ BSTR bsOSIdOrName,
            /* [optional][in] */ VARIANT vtLocaleId,
            /* [optional][in] */ VARIANT vtFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMPackageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMPackage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMPackage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMPackage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMPackage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMPackage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMPackage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMPackage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IPMPackage * This,
            /* [retval][out] */ BSTR *pbstrPackageId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IPMPackage * This,
            /* [retval][out] */ BSTR *pbstrPackageName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumFiles )( 
            IPMPackage * This,
            /* [retval][out] */ IEnumVariant **ppiEnumFiles);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFile )( 
            IPMPackage * This,
            /* [in] */ BSTR bstrFullPath,
            /* [in] */ BSTR bstrKeyName,
            /* [retval][out] */ IPMPackageFile **ppiPMPackageFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddFile )( 
            IPMPackage * This,
            /* [in] */ BSTR bstrFullPath,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ IPMCPU *piPMCPU,
            /* [in] */ IPMOS *piPMOS,
            /* [in] */ long dwLocaleId,
            /* [in] */ long dwFlags,
            /* [retval][out] */ IPMPackageFile **ppiPMPackageFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteFile )( 
            IPMPackage * This,
            /* [in] */ BSTR bstrFullPath,
            /* [in] */ BSTR bstrKeyName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddCPUFiles )( 
            IPMPackage * This,
            /* [in] */ BSTR bstrFullPath,
            /* [in] */ BSTR bstrKeyName,
            /* [defaultvalue][in] */ BSTR bsOSIdOrName,
            /* [optional][in] */ VARIANT vtLocaleId,
            /* [optional][in] */ VARIANT vtFlags);
        
        END_INTERFACE
    } IPMPackageVtbl;

    interface IPMPackage
    {
        CONST_VTBL struct IPMPackageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMPackage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMPackage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMPackage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMPackage_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMPackage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMPackage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMPackage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMPackage_get_Id(This,pbstrPackageId)	\
    (This)->lpVtbl -> get_Id(This,pbstrPackageId)

#define IPMPackage_get_Name(This,pbstrPackageName)	\
    (This)->lpVtbl -> get_Name(This,pbstrPackageName)

#define IPMPackage_EnumFiles(This,ppiEnumFiles)	\
    (This)->lpVtbl -> EnumFiles(This,ppiEnumFiles)

#define IPMPackage_GetFile(This,bstrFullPath,bstrKeyName,ppiPMPackageFile)	\
    (This)->lpVtbl -> GetFile(This,bstrFullPath,bstrKeyName,ppiPMPackageFile)

#define IPMPackage_AddFile(This,bstrFullPath,bstrKeyName,piPMCPU,piPMOS,dwLocaleId,dwFlags,ppiPMPackageFile)	\
    (This)->lpVtbl -> AddFile(This,bstrFullPath,bstrKeyName,piPMCPU,piPMOS,dwLocaleId,dwFlags,ppiPMPackageFile)

#define IPMPackage_DeleteFile(This,bstrFullPath,bstrKeyName)	\
    (This)->lpVtbl -> DeleteFile(This,bstrFullPath,bstrKeyName)

#define IPMPackage_AddCPUFiles(This,bstrFullPath,bstrKeyName,bsOSIdOrName,vtLocaleId,vtFlags)	\
    (This)->lpVtbl -> AddCPUFiles(This,bstrFullPath,bstrKeyName,bsOSIdOrName,vtLocaleId,vtFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPackage_get_Id_Proxy( 
    IPMPackage * This,
    /* [retval][out] */ BSTR *pbstrPackageId);


void __RPC_STUB IPMPackage_get_Id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPackage_get_Name_Proxy( 
    IPMPackage * This,
    /* [retval][out] */ BSTR *pbstrPackageName);


void __RPC_STUB IPMPackage_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPackage_EnumFiles_Proxy( 
    IPMPackage * This,
    /* [retval][out] */ IEnumVariant **ppiEnumFiles);


void __RPC_STUB IPMPackage_EnumFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPackage_GetFile_Proxy( 
    IPMPackage * This,
    /* [in] */ BSTR bstrFullPath,
    /* [in] */ BSTR bstrKeyName,
    /* [retval][out] */ IPMPackageFile **ppiPMPackageFile);


void __RPC_STUB IPMPackage_GetFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPackage_AddFile_Proxy( 
    IPMPackage * This,
    /* [in] */ BSTR bstrFullPath,
    /* [in] */ BSTR bstrKeyName,
    /* [in] */ IPMCPU *piPMCPU,
    /* [in] */ IPMOS *piPMOS,
    /* [in] */ long dwLocaleId,
    /* [in] */ long dwFlags,
    /* [retval][out] */ IPMPackageFile **ppiPMPackageFile);


void __RPC_STUB IPMPackage_AddFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPackage_DeleteFile_Proxy( 
    IPMPackage * This,
    /* [in] */ BSTR bstrFullPath,
    /* [in] */ BSTR bstrKeyName);


void __RPC_STUB IPMPackage_DeleteFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMPackage_AddCPUFiles_Proxy( 
    IPMPackage * This,
    /* [in] */ BSTR bstrFullPath,
    /* [in] */ BSTR bstrKeyName,
    /* [defaultvalue][in] */ BSTR bsOSIdOrName,
    /* [optional][in] */ VARIANT vtLocaleId,
    /* [optional][in] */ VARIANT vtFlags);


void __RPC_STUB IPMPackage_AddCPUFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMPackage_INTERFACE_DEFINED__ */


#ifndef __IPMService_INTERFACE_DEFINED__
#define __IPMService_INTERFACE_DEFINED__

/* interface IPMService */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CBC7337C-2A7C-4062-83A2-72C3E30C42BF")
    IPMService : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ BSTR *pbstrServiceCLSID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CategoryId( 
            /* [retval][out] */ BSTR *pbstrServiceCategoryId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitService( 
            /* [in] */ IPMBootableDevice *piBootableDevice,
            /* [in] */ IPMServiceInfo *piServiceInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsServiceReleaseable( 
            /* [retval][out] */ VARIANT_BOOL *pBool) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConfigureServiceUI( 
            /* [in] */ IPMBootableDevice *piDevice,
            /* [in] */ IPMServiceInfo *piServiceInfo,
            /* [optional][in] */ VARIANT hWnd) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMServiceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMService * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMService * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMService * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMService * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMService * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMService * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMService * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IPMService * This,
            /* [retval][out] */ BSTR *pbstrServiceCLSID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IPMService * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IPMService * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CategoryId )( 
            IPMService * This,
            /* [retval][out] */ BSTR *pbstrServiceCategoryId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitService )( 
            IPMService * This,
            /* [in] */ IPMBootableDevice *piBootableDevice,
            /* [in] */ IPMServiceInfo *piServiceInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsServiceReleaseable )( 
            IPMService * This,
            /* [retval][out] */ VARIANT_BOOL *pBool);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConfigureServiceUI )( 
            IPMService * This,
            /* [in] */ IPMBootableDevice *piDevice,
            /* [in] */ IPMServiceInfo *piServiceInfo,
            /* [optional][in] */ VARIANT hWnd);
        
        END_INTERFACE
    } IPMServiceVtbl;

    interface IPMService
    {
        CONST_VTBL struct IPMServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMService_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMService_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMService_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMService_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMService_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMService_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMService_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMService_get_Id(This,pbstrServiceCLSID)	\
    (This)->lpVtbl -> get_Id(This,pbstrServiceCLSID)

#define IPMService_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define IPMService_put_Name(This,bstrName)	\
    (This)->lpVtbl -> put_Name(This,bstrName)

#define IPMService_get_CategoryId(This,pbstrServiceCategoryId)	\
    (This)->lpVtbl -> get_CategoryId(This,pbstrServiceCategoryId)

#define IPMService_InitService(This,piBootableDevice,piServiceInfo)	\
    (This)->lpVtbl -> InitService(This,piBootableDevice,piServiceInfo)

#define IPMService_IsServiceReleaseable(This,pBool)	\
    (This)->lpVtbl -> IsServiceReleaseable(This,pBool)

#define IPMService_ConfigureServiceUI(This,piDevice,piServiceInfo,hWnd)	\
    (This)->lpVtbl -> ConfigureServiceUI(This,piDevice,piServiceInfo,hWnd)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMService_get_Id_Proxy( 
    IPMService * This,
    /* [retval][out] */ BSTR *pbstrServiceCLSID);


void __RPC_STUB IPMService_get_Id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMService_get_Name_Proxy( 
    IPMService * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB IPMService_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMService_put_Name_Proxy( 
    IPMService * This,
    /* [in] */ BSTR bstrName);


void __RPC_STUB IPMService_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMService_get_CategoryId_Proxy( 
    IPMService * This,
    /* [retval][out] */ BSTR *pbstrServiceCategoryId);


void __RPC_STUB IPMService_get_CategoryId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMService_InitService_Proxy( 
    IPMService * This,
    /* [in] */ IPMBootableDevice *piBootableDevice,
    /* [in] */ IPMServiceInfo *piServiceInfo);


void __RPC_STUB IPMService_InitService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMService_IsServiceReleaseable_Proxy( 
    IPMService * This,
    /* [retval][out] */ VARIANT_BOOL *pBool);


void __RPC_STUB IPMService_IsServiceReleaseable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMService_ConfigureServiceUI_Proxy( 
    IPMService * This,
    /* [in] */ IPMBootableDevice *piDevice,
    /* [in] */ IPMServiceInfo *piServiceInfo,
    /* [optional][in] */ VARIANT hWnd);


void __RPC_STUB IPMService_ConfigureServiceUI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMService_INTERFACE_DEFINED__ */


#ifndef __IPMServiceInfo_INTERFACE_DEFINED__
#define __IPMServiceInfo_INTERFACE_DEFINED__

/* interface IPMServiceInfo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMServiceInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("184E566E-2134-4EA6-B298-F177DAC489DE")
    IPMServiceInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ BSTR *pbstrServiceCLSID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrServiceInfoName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrServiceInfoName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumProperties( 
            /* [retval][out] */ IEnumVariant **ppiEnumProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ BSTR bstrLinkName,
            /* [defaultvalue][in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteProperty( 
            /* [in] */ BSTR bstrPropId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMServiceInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMServiceInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMServiceInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMServiceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMServiceInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMServiceInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMServiceInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMServiceInfo * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IPMServiceInfo * This,
            /* [retval][out] */ BSTR *pbstrServiceCLSID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IPMServiceInfo * This,
            /* [retval][out] */ BSTR *pbstrServiceInfoName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IPMServiceInfo * This,
            /* [in] */ BSTR bstrServiceInfoName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IPMServiceInfo * This,
            /* [retval][out] */ IEnumVariant **ppiEnumProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IPMServiceInfo * This,
            /* [in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IPMServiceInfo * This,
            /* [in] */ BSTR bstrLinkName,
            /* [defaultvalue][in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IPMServiceInfo * This,
            /* [in] */ BSTR bstrPropId);
        
        END_INTERFACE
    } IPMServiceInfoVtbl;

    interface IPMServiceInfo
    {
        CONST_VTBL struct IPMServiceInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMServiceInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMServiceInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMServiceInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMServiceInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMServiceInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMServiceInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMServiceInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMServiceInfo_get_Id(This,pbstrServiceCLSID)	\
    (This)->lpVtbl -> get_Id(This,pbstrServiceCLSID)

#define IPMServiceInfo_get_Name(This,pbstrServiceInfoName)	\
    (This)->lpVtbl -> get_Name(This,pbstrServiceInfoName)

#define IPMServiceInfo_put_Name(This,bstrServiceInfoName)	\
    (This)->lpVtbl -> put_Name(This,bstrServiceInfoName)

#define IPMServiceInfo_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IPMServiceInfo_GetProperty(This,bstrPropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,bstrPropId,ppiProperty)

#define IPMServiceInfo_AddProperty(This,bstrLinkName,bstrPropId,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,bstrLinkName,bstrPropId,ppiProperty)

#define IPMServiceInfo_DeleteProperty(This,bstrPropId)	\
    (This)->lpVtbl -> DeleteProperty(This,bstrPropId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMServiceInfo_get_Id_Proxy( 
    IPMServiceInfo * This,
    /* [retval][out] */ BSTR *pbstrServiceCLSID);


void __RPC_STUB IPMServiceInfo_get_Id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMServiceInfo_get_Name_Proxy( 
    IPMServiceInfo * This,
    /* [retval][out] */ BSTR *pbstrServiceInfoName);


void __RPC_STUB IPMServiceInfo_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMServiceInfo_put_Name_Proxy( 
    IPMServiceInfo * This,
    /* [in] */ BSTR bstrServiceInfoName);


void __RPC_STUB IPMServiceInfo_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMServiceInfo_EnumProperties_Proxy( 
    IPMServiceInfo * This,
    /* [retval][out] */ IEnumVariant **ppiEnumProperty);


void __RPC_STUB IPMServiceInfo_EnumProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMServiceInfo_GetProperty_Proxy( 
    IPMServiceInfo * This,
    /* [in] */ BSTR bstrPropId,
    /* [retval][out] */ IPMProperty **ppiProperty);


void __RPC_STUB IPMServiceInfo_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMServiceInfo_AddProperty_Proxy( 
    IPMServiceInfo * This,
    /* [in] */ BSTR bstrLinkName,
    /* [defaultvalue][in] */ BSTR bstrPropId,
    /* [retval][out] */ IPMProperty **ppiProperty);


void __RPC_STUB IPMServiceInfo_AddProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMServiceInfo_DeleteProperty_Proxy( 
    IPMServiceInfo * This,
    /* [in] */ BSTR bstrPropId);


void __RPC_STUB IPMServiceInfo_DeleteProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMServiceInfo_INTERFACE_DEFINED__ */


#ifndef __IPMServiceCategory_INTERFACE_DEFINED__
#define __IPMServiceCategory_INTERFACE_DEFINED__

/* interface IPMServiceCategory */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMServiceCategory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2E8C4F4D-BEFE-4FC0-81D5-E7311417843C")
    IPMServiceCategory : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ BSTR *pbstrServiceCategoryId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrServiceCategoryName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrServiceCategoryName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumServiceInfos( 
            /* [retval][out] */ IEnumVariant **ppiEnumServiceInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetServiceInfo( 
            /* [in] */ BSTR bstrServiceIdOrName,
            /* [retval][out] */ IPMServiceInfo **ppiServiceInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddServiceInfo( 
            /* [in] */ BSTR bstrServiceCLSID,
            /* [in] */ BSTR bstrServiceName,
            /* [retval][out] */ IPMServiceInfo **ppiServiceInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteServiceInfo( 
            /* [in] */ BSTR bstrServiceIdOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumProperties( 
            /* [retval][out] */ IEnumVariant **ppiEnumProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ BSTR bstrLinkName,
            /* [defaultvalue][in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteProperty( 
            /* [in] */ BSTR bstrPropId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMServiceCategoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMServiceCategory * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMServiceCategory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMServiceCategory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMServiceCategory * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMServiceCategory * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMServiceCategory * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMServiceCategory * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IPMServiceCategory * This,
            /* [retval][out] */ BSTR *pbstrServiceCategoryId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IPMServiceCategory * This,
            /* [retval][out] */ BSTR *pbstrServiceCategoryName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IPMServiceCategory * This,
            /* [in] */ BSTR bstrServiceCategoryName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumServiceInfos )( 
            IPMServiceCategory * This,
            /* [retval][out] */ IEnumVariant **ppiEnumServiceInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetServiceInfo )( 
            IPMServiceCategory * This,
            /* [in] */ BSTR bstrServiceIdOrName,
            /* [retval][out] */ IPMServiceInfo **ppiServiceInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddServiceInfo )( 
            IPMServiceCategory * This,
            /* [in] */ BSTR bstrServiceCLSID,
            /* [in] */ BSTR bstrServiceName,
            /* [retval][out] */ IPMServiceInfo **ppiServiceInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteServiceInfo )( 
            IPMServiceCategory * This,
            /* [in] */ BSTR bstrServiceIdOrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumProperties )( 
            IPMServiceCategory * This,
            /* [retval][out] */ IEnumVariant **ppiEnumProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IPMServiceCategory * This,
            /* [in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IPMServiceCategory * This,
            /* [in] */ BSTR bstrLinkName,
            /* [defaultvalue][in] */ BSTR bstrPropId,
            /* [retval][out] */ IPMProperty **ppiProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteProperty )( 
            IPMServiceCategory * This,
            /* [in] */ BSTR bstrPropId);
        
        END_INTERFACE
    } IPMServiceCategoryVtbl;

    interface IPMServiceCategory
    {
        CONST_VTBL struct IPMServiceCategoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMServiceCategory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMServiceCategory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMServiceCategory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMServiceCategory_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMServiceCategory_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMServiceCategory_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMServiceCategory_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMServiceCategory_get_Id(This,pbstrServiceCategoryId)	\
    (This)->lpVtbl -> get_Id(This,pbstrServiceCategoryId)

#define IPMServiceCategory_get_Name(This,pbstrServiceCategoryName)	\
    (This)->lpVtbl -> get_Name(This,pbstrServiceCategoryName)

#define IPMServiceCategory_put_Name(This,bstrServiceCategoryName)	\
    (This)->lpVtbl -> put_Name(This,bstrServiceCategoryName)

#define IPMServiceCategory_EnumServiceInfos(This,ppiEnumServiceInfo)	\
    (This)->lpVtbl -> EnumServiceInfos(This,ppiEnumServiceInfo)

#define IPMServiceCategory_GetServiceInfo(This,bstrServiceIdOrName,ppiServiceInfo)	\
    (This)->lpVtbl -> GetServiceInfo(This,bstrServiceIdOrName,ppiServiceInfo)

#define IPMServiceCategory_AddServiceInfo(This,bstrServiceCLSID,bstrServiceName,ppiServiceInfo)	\
    (This)->lpVtbl -> AddServiceInfo(This,bstrServiceCLSID,bstrServiceName,ppiServiceInfo)

#define IPMServiceCategory_DeleteServiceInfo(This,bstrServiceIdOrName)	\
    (This)->lpVtbl -> DeleteServiceInfo(This,bstrServiceIdOrName)

#define IPMServiceCategory_EnumProperties(This,ppiEnumProperty)	\
    (This)->lpVtbl -> EnumProperties(This,ppiEnumProperty)

#define IPMServiceCategory_GetProperty(This,bstrPropId,ppiProperty)	\
    (This)->lpVtbl -> GetProperty(This,bstrPropId,ppiProperty)

#define IPMServiceCategory_AddProperty(This,bstrLinkName,bstrPropId,ppiProperty)	\
    (This)->lpVtbl -> AddProperty(This,bstrLinkName,bstrPropId,ppiProperty)

#define IPMServiceCategory_DeleteProperty(This,bstrPropId)	\
    (This)->lpVtbl -> DeleteProperty(This,bstrPropId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMServiceCategory_get_Id_Proxy( 
    IPMServiceCategory * This,
    /* [retval][out] */ BSTR *pbstrServiceCategoryId);


void __RPC_STUB IPMServiceCategory_get_Id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMServiceCategory_get_Name_Proxy( 
    IPMServiceCategory * This,
    /* [retval][out] */ BSTR *pbstrServiceCategoryName);


void __RPC_STUB IPMServiceCategory_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMServiceCategory_put_Name_Proxy( 
    IPMServiceCategory * This,
    /* [in] */ BSTR bstrServiceCategoryName);


void __RPC_STUB IPMServiceCategory_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMServiceCategory_EnumServiceInfos_Proxy( 
    IPMServiceCategory * This,
    /* [retval][out] */ IEnumVariant **ppiEnumServiceInfo);


void __RPC_STUB IPMServiceCategory_EnumServiceInfos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMServiceCategory_GetServiceInfo_Proxy( 
    IPMServiceCategory * This,
    /* [in] */ BSTR bstrServiceIdOrName,
    /* [retval][out] */ IPMServiceInfo **ppiServiceInfo);


void __RPC_STUB IPMServiceCategory_GetServiceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMServiceCategory_AddServiceInfo_Proxy( 
    IPMServiceCategory * This,
    /* [in] */ BSTR bstrServiceCLSID,
    /* [in] */ BSTR bstrServiceName,
    /* [retval][out] */ IPMServiceInfo **ppiServiceInfo);


void __RPC_STUB IPMServiceCategory_AddServiceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMServiceCategory_DeleteServiceInfo_Proxy( 
    IPMServiceCategory * This,
    /* [in] */ BSTR bstrServiceIdOrName);


void __RPC_STUB IPMServiceCategory_DeleteServiceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMServiceCategory_EnumProperties_Proxy( 
    IPMServiceCategory * This,
    /* [retval][out] */ IEnumVariant **ppiEnumProperty);


void __RPC_STUB IPMServiceCategory_EnumProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMServiceCategory_GetProperty_Proxy( 
    IPMServiceCategory * This,
    /* [in] */ BSTR bstrPropId,
    /* [retval][out] */ IPMProperty **ppiProperty);


void __RPC_STUB IPMServiceCategory_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMServiceCategory_AddProperty_Proxy( 
    IPMServiceCategory * This,
    /* [in] */ BSTR bstrLinkName,
    /* [defaultvalue][in] */ BSTR bstrPropId,
    /* [retval][out] */ IPMProperty **ppiProperty);


void __RPC_STUB IPMServiceCategory_AddProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMServiceCategory_DeleteProperty_Proxy( 
    IPMServiceCategory * This,
    /* [in] */ BSTR bstrPropId);


void __RPC_STUB IPMServiceCategory_DeleteProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMServiceCategory_INTERFACE_DEFINED__ */


#ifndef __IPMConnectionStream_INTERFACE_DEFINED__
#define __IPMConnectionStream_INTERFACE_DEFINED__

/* interface IPMConnectionStream */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMConnectionStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C41E4F72-6B73-4556-98EA-D86570745DDB")
    IPMConnectionStream : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Send( 
            /* [in] */ long dwSize,
            /* [in] */ VARIANT vtArray,
            /* [retval][out] */ long *pdwSizeSent) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Receive( 
            /* [retval][out] */ long *pdwBytesReceived) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBytes( 
            /* [in] */ long dwSize,
            /* [out] */ VARIANT *pvtArray,
            /* [retval][out] */ long *pdwSizeRecv) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMConnectionStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMConnectionStream * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMConnectionStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMConnectionStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMConnectionStream * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMConnectionStream * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMConnectionStream * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMConnectionStream * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Send )( 
            IPMConnectionStream * This,
            /* [in] */ long dwSize,
            /* [in] */ VARIANT vtArray,
            /* [retval][out] */ long *pdwSizeSent);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Receive )( 
            IPMConnectionStream * This,
            /* [retval][out] */ long *pdwBytesReceived);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadBytes )( 
            IPMConnectionStream * This,
            /* [in] */ long dwSize,
            /* [out] */ VARIANT *pvtArray,
            /* [retval][out] */ long *pdwSizeRecv);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IPMConnectionStream * This);
        
        END_INTERFACE
    } IPMConnectionStreamVtbl;

    interface IPMConnectionStream
    {
        CONST_VTBL struct IPMConnectionStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMConnectionStream_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMConnectionStream_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMConnectionStream_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMConnectionStream_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMConnectionStream_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMConnectionStream_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMConnectionStream_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMConnectionStream_Send(This,dwSize,vtArray,pdwSizeSent)	\
    (This)->lpVtbl -> Send(This,dwSize,vtArray,pdwSizeSent)

#define IPMConnectionStream_Receive(This,pdwBytesReceived)	\
    (This)->lpVtbl -> Receive(This,pdwBytesReceived)

#define IPMConnectionStream_ReadBytes(This,dwSize,pvtArray,pdwSizeRecv)	\
    (This)->lpVtbl -> ReadBytes(This,dwSize,pvtArray,pdwSizeRecv)

#define IPMConnectionStream_Close(This)	\
    (This)->lpVtbl -> Close(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnectionStream_Send_Proxy( 
    IPMConnectionStream * This,
    /* [in] */ long dwSize,
    /* [in] */ VARIANT vtArray,
    /* [retval][out] */ long *pdwSizeSent);


void __RPC_STUB IPMConnectionStream_Send_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnectionStream_Receive_Proxy( 
    IPMConnectionStream * This,
    /* [retval][out] */ long *pdwBytesReceived);


void __RPC_STUB IPMConnectionStream_Receive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnectionStream_ReadBytes_Proxy( 
    IPMConnectionStream * This,
    /* [in] */ long dwSize,
    /* [out] */ VARIANT *pvtArray,
    /* [retval][out] */ long *pdwSizeRecv);


void __RPC_STUB IPMConnectionStream_ReadBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnectionStream_Close_Proxy( 
    IPMConnectionStream * This);


void __RPC_STUB IPMConnectionStream_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMConnectionStream_INTERFACE_DEFINED__ */


#ifndef __IPMConnection_INTERFACE_DEFINED__
#define __IPMConnection_INTERFACE_DEFINED__

/* interface IPMConnection */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A887B5D6-A18E-41FB-BFC5-B6ABB419A3D3")
    IPMConnection : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ BSTR *pbstrConnectId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PlatformId( 
            /* [retval][out] */ BSTR *pbstrPlatformId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LocaleId( 
            /* [retval][out] */ long *pdwLocaleId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FileCopy( 
            /* [in] */ BSTR bstrSource,
            /* [in] */ BSTR bstrDest,
            /* [in] */ VARIANT_BOOL bOverWrite,
            /* [retval][out] */ long *pdwTotalSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFile( 
            /* [in] */ BSTR bstrRemotePath,
            /* [in] */ BSTR bstrDest,
            /* [retval][out] */ long *pdwTotalSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FileGetInfo( 
            /* [in] */ BSTR bstrRemotePath,
            /* [out] */ long *pdwFileAttributes,
            /* [out] */ long *pdwFileSize,
            /* [out] */ VARIANT *pvtCreationTime) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FileDelete( 
            /* [in] */ BSTR bstrFullPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QueueFile( 
            /* [in] */ BSTR bstrSource,
            /* [in] */ BSTR bstrDest,
            /* [in] */ VARIANT_BOOL bOverWrite) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyQueuedFiles( 
            /* [retval][out] */ long *pdwTotalSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyPackage( 
            /* [in] */ BSTR bstrPackageId,
            /* [in] */ BSTR bstrDestPath,
            /* [in] */ VARIANT_BOOL bOverWrite,
            /* [retval][out] */ long *pdwTotalSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QueuePackage( 
            /* [in] */ BSTR bstrPackageId,
            /* [in] */ BSTR bstrDestPath,
            /* [in] */ VARIANT_BOOL bOverWrite) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetQueueCount( 
            /* [retval][out] */ long *pdwCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetQueue( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateStream( 
            /* [in] */ BSTR bstrHostId,
            /* [in] */ long dwPortId,
            /* [retval][out] */ IPMConnectionStream **ppiConnectionStream) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseAllStreams( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Launch( 
            /* [in] */ BSTR bstrRemotePath,
            /* [in] */ BSTR bstrCmdLine) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SystemGetInfo( 
            /* [out] */ VARIANT *pwArchitecture,
            /* [out] */ VARIANT *pdwCPUType,
            /* [out] */ VARIANT *pdwPageSize,
            /* [out] */ VARIANT *pwMajorVersion,
            /* [out] */ VARIANT *pwMinorVersion,
            /* [out] */ VARIANT *bstrOSTypeId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSystemInfo( 
            /* [out] */ IPMCPU **piCpu,
            /* [out] */ IPMOS **piOs) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMConnection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMConnection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMConnection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMConnection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMConnection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IPMConnection * This,
            /* [retval][out] */ BSTR *pbstrConnectId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlatformId )( 
            IPMConnection * This,
            /* [retval][out] */ BSTR *pbstrPlatformId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocaleId )( 
            IPMConnection * This,
            /* [retval][out] */ long *pdwLocaleId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FileCopy )( 
            IPMConnection * This,
            /* [in] */ BSTR bstrSource,
            /* [in] */ BSTR bstrDest,
            /* [in] */ VARIANT_BOOL bOverWrite,
            /* [retval][out] */ long *pdwTotalSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFile )( 
            IPMConnection * This,
            /* [in] */ BSTR bstrRemotePath,
            /* [in] */ BSTR bstrDest,
            /* [retval][out] */ long *pdwTotalSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FileGetInfo )( 
            IPMConnection * This,
            /* [in] */ BSTR bstrRemotePath,
            /* [out] */ long *pdwFileAttributes,
            /* [out] */ long *pdwFileSize,
            /* [out] */ VARIANT *pvtCreationTime);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FileDelete )( 
            IPMConnection * This,
            /* [in] */ BSTR bstrFullPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QueueFile )( 
            IPMConnection * This,
            /* [in] */ BSTR bstrSource,
            /* [in] */ BSTR bstrDest,
            /* [in] */ VARIANT_BOOL bOverWrite);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyQueuedFiles )( 
            IPMConnection * This,
            /* [retval][out] */ long *pdwTotalSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyPackage )( 
            IPMConnection * This,
            /* [in] */ BSTR bstrPackageId,
            /* [in] */ BSTR bstrDestPath,
            /* [in] */ VARIANT_BOOL bOverWrite,
            /* [retval][out] */ long *pdwTotalSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QueuePackage )( 
            IPMConnection * This,
            /* [in] */ BSTR bstrPackageId,
            /* [in] */ BSTR bstrDestPath,
            /* [in] */ VARIANT_BOOL bOverWrite);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetQueueCount )( 
            IPMConnection * This,
            /* [retval][out] */ long *pdwCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetQueue )( 
            IPMConnection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateStream )( 
            IPMConnection * This,
            /* [in] */ BSTR bstrHostId,
            /* [in] */ long dwPortId,
            /* [retval][out] */ IPMConnectionStream **ppiConnectionStream);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CloseAllStreams )( 
            IPMConnection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Launch )( 
            IPMConnection * This,
            /* [in] */ BSTR bstrRemotePath,
            /* [in] */ BSTR bstrCmdLine);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SystemGetInfo )( 
            IPMConnection * This,
            /* [out] */ VARIANT *pwArchitecture,
            /* [out] */ VARIANT *pdwCPUType,
            /* [out] */ VARIANT *pdwPageSize,
            /* [out] */ VARIANT *pwMajorVersion,
            /* [out] */ VARIANT *pwMinorVersion,
            /* [out] */ VARIANT *bstrOSTypeId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSystemInfo )( 
            IPMConnection * This,
            /* [out] */ IPMCPU **piCpu,
            /* [out] */ IPMOS **piOs);
        
        END_INTERFACE
    } IPMConnectionVtbl;

    interface IPMConnection
    {
        CONST_VTBL struct IPMConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMConnection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMConnection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMConnection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMConnection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMConnection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMConnection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMConnection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMConnection_get_Id(This,pbstrConnectId)	\
    (This)->lpVtbl -> get_Id(This,pbstrConnectId)

#define IPMConnection_get_PlatformId(This,pbstrPlatformId)	\
    (This)->lpVtbl -> get_PlatformId(This,pbstrPlatformId)

#define IPMConnection_get_LocaleId(This,pdwLocaleId)	\
    (This)->lpVtbl -> get_LocaleId(This,pdwLocaleId)

#define IPMConnection_FileCopy(This,bstrSource,bstrDest,bOverWrite,pdwTotalSize)	\
    (This)->lpVtbl -> FileCopy(This,bstrSource,bstrDest,bOverWrite,pdwTotalSize)

#define IPMConnection_GetFile(This,bstrRemotePath,bstrDest,pdwTotalSize)	\
    (This)->lpVtbl -> GetFile(This,bstrRemotePath,bstrDest,pdwTotalSize)

#define IPMConnection_FileGetInfo(This,bstrRemotePath,pdwFileAttributes,pdwFileSize,pvtCreationTime)	\
    (This)->lpVtbl -> FileGetInfo(This,bstrRemotePath,pdwFileAttributes,pdwFileSize,pvtCreationTime)

#define IPMConnection_FileDelete(This,bstrFullPath)	\
    (This)->lpVtbl -> FileDelete(This,bstrFullPath)

#define IPMConnection_QueueFile(This,bstrSource,bstrDest,bOverWrite)	\
    (This)->lpVtbl -> QueueFile(This,bstrSource,bstrDest,bOverWrite)

#define IPMConnection_CopyQueuedFiles(This,pdwTotalSize)	\
    (This)->lpVtbl -> CopyQueuedFiles(This,pdwTotalSize)

#define IPMConnection_CopyPackage(This,bstrPackageId,bstrDestPath,bOverWrite,pdwTotalSize)	\
    (This)->lpVtbl -> CopyPackage(This,bstrPackageId,bstrDestPath,bOverWrite,pdwTotalSize)

#define IPMConnection_QueuePackage(This,bstrPackageId,bstrDestPath,bOverWrite)	\
    (This)->lpVtbl -> QueuePackage(This,bstrPackageId,bstrDestPath,bOverWrite)

#define IPMConnection_GetQueueCount(This,pdwCount)	\
    (This)->lpVtbl -> GetQueueCount(This,pdwCount)

#define IPMConnection_ResetQueue(This)	\
    (This)->lpVtbl -> ResetQueue(This)

#define IPMConnection_CreateStream(This,bstrHostId,dwPortId,ppiConnectionStream)	\
    (This)->lpVtbl -> CreateStream(This,bstrHostId,dwPortId,ppiConnectionStream)

#define IPMConnection_CloseAllStreams(This)	\
    (This)->lpVtbl -> CloseAllStreams(This)

#define IPMConnection_Launch(This,bstrRemotePath,bstrCmdLine)	\
    (This)->lpVtbl -> Launch(This,bstrRemotePath,bstrCmdLine)

#define IPMConnection_SystemGetInfo(This,pwArchitecture,pdwCPUType,pdwPageSize,pwMajorVersion,pwMinorVersion,bstrOSTypeId)	\
    (This)->lpVtbl -> SystemGetInfo(This,pwArchitecture,pdwCPUType,pdwPageSize,pwMajorVersion,pwMinorVersion,bstrOSTypeId)

#define IPMConnection_GetSystemInfo(This,piCpu,piOs)	\
    (This)->lpVtbl -> GetSystemInfo(This,piCpu,piOs)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMConnection_get_Id_Proxy( 
    IPMConnection * This,
    /* [retval][out] */ BSTR *pbstrConnectId);


void __RPC_STUB IPMConnection_get_Id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMConnection_get_PlatformId_Proxy( 
    IPMConnection * This,
    /* [retval][out] */ BSTR *pbstrPlatformId);


void __RPC_STUB IPMConnection_get_PlatformId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMConnection_get_LocaleId_Proxy( 
    IPMConnection * This,
    /* [retval][out] */ long *pdwLocaleId);


void __RPC_STUB IPMConnection_get_LocaleId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnection_FileCopy_Proxy( 
    IPMConnection * This,
    /* [in] */ BSTR bstrSource,
    /* [in] */ BSTR bstrDest,
    /* [in] */ VARIANT_BOOL bOverWrite,
    /* [retval][out] */ long *pdwTotalSize);


void __RPC_STUB IPMConnection_FileCopy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnection_GetFile_Proxy( 
    IPMConnection * This,
    /* [in] */ BSTR bstrRemotePath,
    /* [in] */ BSTR bstrDest,
    /* [retval][out] */ long *pdwTotalSize);


void __RPC_STUB IPMConnection_GetFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnection_FileGetInfo_Proxy( 
    IPMConnection * This,
    /* [in] */ BSTR bstrRemotePath,
    /* [out] */ long *pdwFileAttributes,
    /* [out] */ long *pdwFileSize,
    /* [out] */ VARIANT *pvtCreationTime);


void __RPC_STUB IPMConnection_FileGetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnection_FileDelete_Proxy( 
    IPMConnection * This,
    /* [in] */ BSTR bstrFullPath);


void __RPC_STUB IPMConnection_FileDelete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnection_QueueFile_Proxy( 
    IPMConnection * This,
    /* [in] */ BSTR bstrSource,
    /* [in] */ BSTR bstrDest,
    /* [in] */ VARIANT_BOOL bOverWrite);


void __RPC_STUB IPMConnection_QueueFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnection_CopyQueuedFiles_Proxy( 
    IPMConnection * This,
    /* [retval][out] */ long *pdwTotalSize);


void __RPC_STUB IPMConnection_CopyQueuedFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnection_CopyPackage_Proxy( 
    IPMConnection * This,
    /* [in] */ BSTR bstrPackageId,
    /* [in] */ BSTR bstrDestPath,
    /* [in] */ VARIANT_BOOL bOverWrite,
    /* [retval][out] */ long *pdwTotalSize);


void __RPC_STUB IPMConnection_CopyPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnection_QueuePackage_Proxy( 
    IPMConnection * This,
    /* [in] */ BSTR bstrPackageId,
    /* [in] */ BSTR bstrDestPath,
    /* [in] */ VARIANT_BOOL bOverWrite);


void __RPC_STUB IPMConnection_QueuePackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnection_GetQueueCount_Proxy( 
    IPMConnection * This,
    /* [retval][out] */ long *pdwCount);


void __RPC_STUB IPMConnection_GetQueueCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnection_ResetQueue_Proxy( 
    IPMConnection * This);


void __RPC_STUB IPMConnection_ResetQueue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnection_CreateStream_Proxy( 
    IPMConnection * This,
    /* [in] */ BSTR bstrHostId,
    /* [in] */ long dwPortId,
    /* [retval][out] */ IPMConnectionStream **ppiConnectionStream);


void __RPC_STUB IPMConnection_CreateStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnection_CloseAllStreams_Proxy( 
    IPMConnection * This);


void __RPC_STUB IPMConnection_CloseAllStreams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnection_Launch_Proxy( 
    IPMConnection * This,
    /* [in] */ BSTR bstrRemotePath,
    /* [in] */ BSTR bstrCmdLine);


void __RPC_STUB IPMConnection_Launch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnection_SystemGetInfo_Proxy( 
    IPMConnection * This,
    /* [out] */ VARIANT *pwArchitecture,
    /* [out] */ VARIANT *pdwCPUType,
    /* [out] */ VARIANT *pdwPageSize,
    /* [out] */ VARIANT *pwMajorVersion,
    /* [out] */ VARIANT *pwMinorVersion,
    /* [out] */ VARIANT *bstrOSTypeId);


void __RPC_STUB IPMConnection_SystemGetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPMConnection_GetSystemInfo_Proxy( 
    IPMConnection * This,
    /* [out] */ IPMCPU **piCpu,
    /* [out] */ IPMOS **piOs);


void __RPC_STUB IPMConnection_GetSystemInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMConnection_INTERFACE_DEFINED__ */


#ifndef __IPMCPU_INTERFACE_DEFINED__
#define __IPMCPU_INTERFACE_DEFINED__

/* interface IPMCPU */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMCPU;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D32ACC9F-D772-41AA-9D5A-AC11AD5154B9")
    IPMCPU : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ BSTR *pbstrGuid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Architecture( 
            /* [retval][out] */ int *pwArchitecture) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Architecture( 
            /* [in] */ int wArchitecture) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ long *pdwType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Type( 
            /* [in] */ long dwType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PageSize( 
            /* [retval][out] */ long *pdwPageSize) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PageSize( 
            /* [in] */ long dwPageSize) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Level( 
            /* [retval][out] */ long *pdwLevel) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Level( 
            /* [in] */ long dwLevel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultValue( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultValue( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CpuNum( 
            /* [retval][out] */ long *pdwNum) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CpuNum( 
            /* [in] */ long dwNum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMCPUVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMCPU * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMCPU * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMCPU * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMCPU * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMCPU * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMCPU * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMCPU * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IPMCPU * This,
            /* [retval][out] */ BSTR *pbstrGuid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IPMCPU * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IPMCPU * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Architecture )( 
            IPMCPU * This,
            /* [retval][out] */ int *pwArchitecture);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Architecture )( 
            IPMCPU * This,
            /* [in] */ int wArchitecture);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IPMCPU * This,
            /* [retval][out] */ long *pdwType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Type )( 
            IPMCPU * This,
            /* [in] */ long dwType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PageSize )( 
            IPMCPU * This,
            /* [retval][out] */ long *pdwPageSize);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PageSize )( 
            IPMCPU * This,
            /* [in] */ long dwPageSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Level )( 
            IPMCPU * This,
            /* [retval][out] */ long *pdwLevel);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Level )( 
            IPMCPU * This,
            /* [in] */ long dwLevel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultValue )( 
            IPMCPU * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultValue )( 
            IPMCPU * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CpuNum )( 
            IPMCPU * This,
            /* [retval][out] */ long *pdwNum);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CpuNum )( 
            IPMCPU * This,
            /* [in] */ long dwNum);
        
        END_INTERFACE
    } IPMCPUVtbl;

    interface IPMCPU
    {
        CONST_VTBL struct IPMCPUVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMCPU_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMCPU_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMCPU_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMCPU_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMCPU_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMCPU_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMCPU_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMCPU_get_Id(This,pbstrGuid)	\
    (This)->lpVtbl -> get_Id(This,pbstrGuid)

#define IPMCPU_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define IPMCPU_put_Name(This,bstrName)	\
    (This)->lpVtbl -> put_Name(This,bstrName)

#define IPMCPU_get_Architecture(This,pwArchitecture)	\
    (This)->lpVtbl -> get_Architecture(This,pwArchitecture)

#define IPMCPU_put_Architecture(This,wArchitecture)	\
    (This)->lpVtbl -> put_Architecture(This,wArchitecture)

#define IPMCPU_get_Type(This,pdwType)	\
    (This)->lpVtbl -> get_Type(This,pdwType)

#define IPMCPU_put_Type(This,dwType)	\
    (This)->lpVtbl -> put_Type(This,dwType)

#define IPMCPU_get_PageSize(This,pdwPageSize)	\
    (This)->lpVtbl -> get_PageSize(This,pdwPageSize)

#define IPMCPU_put_PageSize(This,dwPageSize)	\
    (This)->lpVtbl -> put_PageSize(This,dwPageSize)

#define IPMCPU_get_Level(This,pdwLevel)	\
    (This)->lpVtbl -> get_Level(This,pdwLevel)

#define IPMCPU_put_Level(This,dwLevel)	\
    (This)->lpVtbl -> put_Level(This,dwLevel)

#define IPMCPU_get_DefaultValue(This,pbstrName)	\
    (This)->lpVtbl -> get_DefaultValue(This,pbstrName)

#define IPMCPU_put_DefaultValue(This,bstrName)	\
    (This)->lpVtbl -> put_DefaultValue(This,bstrName)

#define IPMCPU_get_CpuNum(This,pdwNum)	\
    (This)->lpVtbl -> get_CpuNum(This,pdwNum)

#define IPMCPU_put_CpuNum(This,dwNum)	\
    (This)->lpVtbl -> put_CpuNum(This,dwNum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMCPU_get_Id_Proxy( 
    IPMCPU * This,
    /* [retval][out] */ BSTR *pbstrGuid);


void __RPC_STUB IPMCPU_get_Id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMCPU_get_Name_Proxy( 
    IPMCPU * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB IPMCPU_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMCPU_put_Name_Proxy( 
    IPMCPU * This,
    /* [in] */ BSTR bstrName);


void __RPC_STUB IPMCPU_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMCPU_get_Architecture_Proxy( 
    IPMCPU * This,
    /* [retval][out] */ int *pwArchitecture);


void __RPC_STUB IPMCPU_get_Architecture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMCPU_put_Architecture_Proxy( 
    IPMCPU * This,
    /* [in] */ int wArchitecture);


void __RPC_STUB IPMCPU_put_Architecture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMCPU_get_Type_Proxy( 
    IPMCPU * This,
    /* [retval][out] */ long *pdwType);


void __RPC_STUB IPMCPU_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMCPU_put_Type_Proxy( 
    IPMCPU * This,
    /* [in] */ long dwType);


void __RPC_STUB IPMCPU_put_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMCPU_get_PageSize_Proxy( 
    IPMCPU * This,
    /* [retval][out] */ long *pdwPageSize);


void __RPC_STUB IPMCPU_get_PageSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMCPU_put_PageSize_Proxy( 
    IPMCPU * This,
    /* [in] */ long dwPageSize);


void __RPC_STUB IPMCPU_put_PageSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMCPU_get_Level_Proxy( 
    IPMCPU * This,
    /* [retval][out] */ long *pdwLevel);


void __RPC_STUB IPMCPU_get_Level_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMCPU_put_Level_Proxy( 
    IPMCPU * This,
    /* [in] */ long dwLevel);


void __RPC_STUB IPMCPU_put_Level_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMCPU_get_DefaultValue_Proxy( 
    IPMCPU * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB IPMCPU_get_DefaultValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMCPU_put_DefaultValue_Proxy( 
    IPMCPU * This,
    /* [in] */ BSTR bstrName);


void __RPC_STUB IPMCPU_put_DefaultValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMCPU_get_CpuNum_Proxy( 
    IPMCPU * This,
    /* [retval][out] */ long *pdwNum);


void __RPC_STUB IPMCPU_get_CpuNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMCPU_put_CpuNum_Proxy( 
    IPMCPU * This,
    /* [in] */ long dwNum);


void __RPC_STUB IPMCPU_put_CpuNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMCPU_INTERFACE_DEFINED__ */


#ifndef __IPMOS_INTERFACE_DEFINED__
#define __IPMOS_INTERFACE_DEFINED__

/* interface IPMOS */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMOS;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("57E91F66-D7C4-41BD-A4A9-C28060D00C57")
    IPMOS : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ BSTR *pbstrGuid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MajorVersion( 
            /* [retval][out] */ int *pwMajor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MajorVersion( 
            /* [in] */ int wMajor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MinorVersion( 
            /* [retval][out] */ int *pwMinor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MinorVersion( 
            /* [in] */ int wMinor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TypeId( 
            /* [retval][out] */ BSTR *pbstrTypeId) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TypeId( 
            /* [in] */ BSTR bstrTypeId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMOSVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMOS * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMOS * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMOS * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMOS * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMOS * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMOS * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMOS * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IPMOS * This,
            /* [retval][out] */ BSTR *pbstrGuid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IPMOS * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IPMOS * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MajorVersion )( 
            IPMOS * This,
            /* [retval][out] */ int *pwMajor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MajorVersion )( 
            IPMOS * This,
            /* [in] */ int wMajor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinorVersion )( 
            IPMOS * This,
            /* [retval][out] */ int *pwMinor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MinorVersion )( 
            IPMOS * This,
            /* [in] */ int wMinor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TypeId )( 
            IPMOS * This,
            /* [retval][out] */ BSTR *pbstrTypeId);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TypeId )( 
            IPMOS * This,
            /* [in] */ BSTR bstrTypeId);
        
        END_INTERFACE
    } IPMOSVtbl;

    interface IPMOS
    {
        CONST_VTBL struct IPMOSVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMOS_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMOS_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMOS_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMOS_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMOS_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMOS_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMOS_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMOS_get_Id(This,pbstrGuid)	\
    (This)->lpVtbl -> get_Id(This,pbstrGuid)

#define IPMOS_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define IPMOS_put_Name(This,bstrName)	\
    (This)->lpVtbl -> put_Name(This,bstrName)

#define IPMOS_get_MajorVersion(This,pwMajor)	\
    (This)->lpVtbl -> get_MajorVersion(This,pwMajor)

#define IPMOS_put_MajorVersion(This,wMajor)	\
    (This)->lpVtbl -> put_MajorVersion(This,wMajor)

#define IPMOS_get_MinorVersion(This,pwMinor)	\
    (This)->lpVtbl -> get_MinorVersion(This,pwMinor)

#define IPMOS_put_MinorVersion(This,wMinor)	\
    (This)->lpVtbl -> put_MinorVersion(This,wMinor)

#define IPMOS_get_TypeId(This,pbstrTypeId)	\
    (This)->lpVtbl -> get_TypeId(This,pbstrTypeId)

#define IPMOS_put_TypeId(This,bstrTypeId)	\
    (This)->lpVtbl -> put_TypeId(This,bstrTypeId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMOS_get_Id_Proxy( 
    IPMOS * This,
    /* [retval][out] */ BSTR *pbstrGuid);


void __RPC_STUB IPMOS_get_Id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMOS_get_Name_Proxy( 
    IPMOS * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB IPMOS_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMOS_put_Name_Proxy( 
    IPMOS * This,
    /* [in] */ BSTR bstrName);


void __RPC_STUB IPMOS_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMOS_get_MajorVersion_Proxy( 
    IPMOS * This,
    /* [retval][out] */ int *pwMajor);


void __RPC_STUB IPMOS_get_MajorVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMOS_put_MajorVersion_Proxy( 
    IPMOS * This,
    /* [in] */ int wMajor);


void __RPC_STUB IPMOS_put_MajorVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMOS_get_MinorVersion_Proxy( 
    IPMOS * This,
    /* [retval][out] */ int *pwMinor);


void __RPC_STUB IPMOS_get_MinorVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMOS_put_MinorVersion_Proxy( 
    IPMOS * This,
    /* [in] */ int wMinor);


void __RPC_STUB IPMOS_put_MinorVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMOS_get_TypeId_Proxy( 
    IPMOS * This,
    /* [retval][out] */ BSTR *pbstrTypeId);


void __RPC_STUB IPMOS_get_TypeId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMOS_put_TypeId_Proxy( 
    IPMOS * This,
    /* [in] */ BSTR bstrTypeId);


void __RPC_STUB IPMOS_put_TypeId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMOS_INTERFACE_DEFINED__ */


#ifndef __IPMStartupServerInfo_INTERFACE_DEFINED__
#define __IPMStartupServerInfo_INTERFACE_DEFINED__

/* interface IPMStartupServerInfo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMStartupServerInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A8FA6E12-2D8C-46B7-A25D-64C04FA69214")
    IPMStartupServerInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ BSTR *pbstrGuid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMStartupServerInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMStartupServerInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMStartupServerInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMStartupServerInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMStartupServerInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMStartupServerInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMStartupServerInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMStartupServerInfo * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IPMStartupServerInfo * This,
            /* [retval][out] */ BSTR *pbstrGuid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IPMStartupServerInfo * This,
            /* [retval][out] */ BSTR *pbstrValue);
        
        END_INTERFACE
    } IPMStartupServerInfoVtbl;

    interface IPMStartupServerInfo
    {
        CONST_VTBL struct IPMStartupServerInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMStartupServerInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMStartupServerInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMStartupServerInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMStartupServerInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMStartupServerInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMStartupServerInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMStartupServerInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMStartupServerInfo_get_Id(This,pbstrGuid)	\
    (This)->lpVtbl -> get_Id(This,pbstrGuid)

#define IPMStartupServerInfo_get_Name(This,pbstrValue)	\
    (This)->lpVtbl -> get_Name(This,pbstrValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMStartupServerInfo_get_Id_Proxy( 
    IPMStartupServerInfo * This,
    /* [retval][out] */ BSTR *pbstrGuid);


void __RPC_STUB IPMStartupServerInfo_get_Id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMStartupServerInfo_get_Name_Proxy( 
    IPMStartupServerInfo * This,
    /* [retval][out] */ BSTR *pbstrValue);


void __RPC_STUB IPMStartupServerInfo_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMStartupServerInfo_INTERFACE_DEFINED__ */


#ifndef __IPMTransportInfo_INTERFACE_DEFINED__
#define __IPMTransportInfo_INTERFACE_DEFINED__

/* interface IPMTransportInfo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMTransportInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0761A737-372D-4020-800A-B52CCD06D25D")
    IPMTransportInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ BSTR *pbstrGuid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMTransportInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMTransportInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMTransportInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMTransportInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMTransportInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMTransportInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMTransportInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMTransportInfo * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IPMTransportInfo * This,
            /* [retval][out] */ BSTR *pbstrGuid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IPMTransportInfo * This,
            /* [retval][out] */ BSTR *pbstrValue);
        
        END_INTERFACE
    } IPMTransportInfoVtbl;

    interface IPMTransportInfo
    {
        CONST_VTBL struct IPMTransportInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMTransportInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMTransportInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMTransportInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMTransportInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMTransportInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMTransportInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMTransportInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMTransportInfo_get_Id(This,pbstrGuid)	\
    (This)->lpVtbl -> get_Id(This,pbstrGuid)

#define IPMTransportInfo_get_Name(This,pbstrValue)	\
    (This)->lpVtbl -> get_Name(This,pbstrValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMTransportInfo_get_Id_Proxy( 
    IPMTransportInfo * This,
    /* [retval][out] */ BSTR *pbstrGuid);


void __RPC_STUB IPMTransportInfo_get_Id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMTransportInfo_get_Name_Proxy( 
    IPMTransportInfo * This,
    /* [retval][out] */ BSTR *pbstrValue);


void __RPC_STUB IPMTransportInfo_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMTransportInfo_INTERFACE_DEFINED__ */


#ifndef __IPMPropInfo_INTERFACE_DEFINED__
#define __IPMPropInfo_INTERFACE_DEFINED__

/* interface IPMPropInfo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMPropInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F7B2D7E0-44B5-4715-A156-A5B3B42D7D5A")
    IPMPropInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ long *pdwType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Type( 
            /* [in] */ long dwType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT *pdwValue) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ BSTR bstrValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMPropInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMPropInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMPropInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMPropInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMPropInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMPropInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMPropInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMPropInfo * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IPMPropInfo * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IPMPropInfo * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IPMPropInfo * This,
            /* [retval][out] */ long *pdwType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Type )( 
            IPMPropInfo * This,
            /* [in] */ long dwType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IPMPropInfo * This,
            /* [retval][out] */ VARIANT *pdwValue);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IPMPropInfo * This,
            /* [in] */ BSTR bstrValue);
        
        END_INTERFACE
    } IPMPropInfoVtbl;

    interface IPMPropInfo
    {
        CONST_VTBL struct IPMPropInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMPropInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMPropInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMPropInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMPropInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMPropInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMPropInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMPropInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMPropInfo_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define IPMPropInfo_put_Name(This,bstrName)	\
    (This)->lpVtbl -> put_Name(This,bstrName)

#define IPMPropInfo_get_Type(This,pdwType)	\
    (This)->lpVtbl -> get_Type(This,pdwType)

#define IPMPropInfo_put_Type(This,dwType)	\
    (This)->lpVtbl -> put_Type(This,dwType)

#define IPMPropInfo_get_Value(This,pdwValue)	\
    (This)->lpVtbl -> get_Value(This,pdwValue)

#define IPMPropInfo_put_Value(This,bstrValue)	\
    (This)->lpVtbl -> put_Value(This,bstrValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPropInfo_get_Name_Proxy( 
    IPMPropInfo * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB IPMPropInfo_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMPropInfo_put_Name_Proxy( 
    IPMPropInfo * This,
    /* [in] */ BSTR bstrName);


void __RPC_STUB IPMPropInfo_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPropInfo_get_Type_Proxy( 
    IPMPropInfo * This,
    /* [retval][out] */ long *pdwType);


void __RPC_STUB IPMPropInfo_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMPropInfo_put_Type_Proxy( 
    IPMPropInfo * This,
    /* [in] */ long dwType);


void __RPC_STUB IPMPropInfo_put_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPropInfo_get_Value_Proxy( 
    IPMPropInfo * This,
    /* [retval][out] */ VARIANT *pdwValue);


void __RPC_STUB IPMPropInfo_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPMPropInfo_put_Value_Proxy( 
    IPMPropInfo * This,
    /* [in] */ BSTR bstrValue);


void __RPC_STUB IPMPropInfo_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMPropInfo_INTERFACE_DEFINED__ */


#ifndef __IPMPackageFile_INTERFACE_DEFINED__
#define __IPMPackageFile_INTERFACE_DEFINED__

/* interface IPMPackageFile */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPMPackageFile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("93BD6B7A-4340-45FF-B062-A4187BBB8D0B")
    IPMPackageFile : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrFileName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Locale( 
            /* [retval][out] */ long *pdwLocale) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Flags( 
            /* [retval][out] */ long *pdwFlags) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_KeyName( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MajorVersion( 
            /* [retval][out] */ int *pwMajor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MinorVersion( 
            /* [retval][out] */ int *pwMinor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TypeId( 
            /* [retval][out] */ BSTR *pbstrTypeId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Architecture( 
            /* [retval][out] */ int *pwArchitecture) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ long *pdwType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PageSize( 
            /* [retval][out] */ long *pdwPageSize) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Level( 
            /* [retval][out] */ long *pdwLevel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CpuNum( 
            /* [retval][out] */ long *pdwCpuNum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPMPackageFileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMPackageFile * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMPackageFile * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMPackageFile * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPMPackageFile * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPMPackageFile * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPMPackageFile * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPMPackageFile * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IPMPackageFile * This,
            /* [retval][out] */ BSTR *pbstrFileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Locale )( 
            IPMPackageFile * This,
            /* [retval][out] */ long *pdwLocale);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flags )( 
            IPMPackageFile * This,
            /* [retval][out] */ long *pdwFlags);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_KeyName )( 
            IPMPackageFile * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MajorVersion )( 
            IPMPackageFile * This,
            /* [retval][out] */ int *pwMajor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinorVersion )( 
            IPMPackageFile * This,
            /* [retval][out] */ int *pwMinor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TypeId )( 
            IPMPackageFile * This,
            /* [retval][out] */ BSTR *pbstrTypeId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Architecture )( 
            IPMPackageFile * This,
            /* [retval][out] */ int *pwArchitecture);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IPMPackageFile * This,
            /* [retval][out] */ long *pdwType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PageSize )( 
            IPMPackageFile * This,
            /* [retval][out] */ long *pdwPageSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Level )( 
            IPMPackageFile * This,
            /* [retval][out] */ long *pdwLevel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CpuNum )( 
            IPMPackageFile * This,
            /* [retval][out] */ long *pdwCpuNum);
        
        END_INTERFACE
    } IPMPackageFileVtbl;

    interface IPMPackageFile
    {
        CONST_VTBL struct IPMPackageFileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMPackageFile_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPMPackageFile_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPMPackageFile_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPMPackageFile_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPMPackageFile_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPMPackageFile_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPMPackageFile_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPMPackageFile_get_Name(This,pbstrFileName)	\
    (This)->lpVtbl -> get_Name(This,pbstrFileName)

#define IPMPackageFile_get_Locale(This,pdwLocale)	\
    (This)->lpVtbl -> get_Locale(This,pdwLocale)

#define IPMPackageFile_get_Flags(This,pdwFlags)	\
    (This)->lpVtbl -> get_Flags(This,pdwFlags)

#define IPMPackageFile_get_KeyName(This,pbstrName)	\
    (This)->lpVtbl -> get_KeyName(This,pbstrName)

#define IPMPackageFile_get_MajorVersion(This,pwMajor)	\
    (This)->lpVtbl -> get_MajorVersion(This,pwMajor)

#define IPMPackageFile_get_MinorVersion(This,pwMinor)	\
    (This)->lpVtbl -> get_MinorVersion(This,pwMinor)

#define IPMPackageFile_get_TypeId(This,pbstrTypeId)	\
    (This)->lpVtbl -> get_TypeId(This,pbstrTypeId)

#define IPMPackageFile_get_Architecture(This,pwArchitecture)	\
    (This)->lpVtbl -> get_Architecture(This,pwArchitecture)

#define IPMPackageFile_get_Type(This,pdwType)	\
    (This)->lpVtbl -> get_Type(This,pdwType)

#define IPMPackageFile_get_PageSize(This,pdwPageSize)	\
    (This)->lpVtbl -> get_PageSize(This,pdwPageSize)

#define IPMPackageFile_get_Level(This,pdwLevel)	\
    (This)->lpVtbl -> get_Level(This,pdwLevel)

#define IPMPackageFile_get_CpuNum(This,pdwCpuNum)	\
    (This)->lpVtbl -> get_CpuNum(This,pdwCpuNum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPackageFile_get_Name_Proxy( 
    IPMPackageFile * This,
    /* [retval][out] */ BSTR *pbstrFileName);


void __RPC_STUB IPMPackageFile_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPackageFile_get_Locale_Proxy( 
    IPMPackageFile * This,
    /* [retval][out] */ long *pdwLocale);


void __RPC_STUB IPMPackageFile_get_Locale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPackageFile_get_Flags_Proxy( 
    IPMPackageFile * This,
    /* [retval][out] */ long *pdwFlags);


void __RPC_STUB IPMPackageFile_get_Flags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPackageFile_get_KeyName_Proxy( 
    IPMPackageFile * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB IPMPackageFile_get_KeyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPackageFile_get_MajorVersion_Proxy( 
    IPMPackageFile * This,
    /* [retval][out] */ int *pwMajor);


void __RPC_STUB IPMPackageFile_get_MajorVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPackageFile_get_MinorVersion_Proxy( 
    IPMPackageFile * This,
    /* [retval][out] */ int *pwMinor);


void __RPC_STUB IPMPackageFile_get_MinorVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPackageFile_get_TypeId_Proxy( 
    IPMPackageFile * This,
    /* [retval][out] */ BSTR *pbstrTypeId);


void __RPC_STUB IPMPackageFile_get_TypeId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPackageFile_get_Architecture_Proxy( 
    IPMPackageFile * This,
    /* [retval][out] */ int *pwArchitecture);


void __RPC_STUB IPMPackageFile_get_Architecture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPackageFile_get_Type_Proxy( 
    IPMPackageFile * This,
    /* [retval][out] */ long *pdwType);


void __RPC_STUB IPMPackageFile_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPackageFile_get_PageSize_Proxy( 
    IPMPackageFile * This,
    /* [retval][out] */ long *pdwPageSize);


void __RPC_STUB IPMPackageFile_get_PageSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPackageFile_get_Level_Proxy( 
    IPMPackageFile * This,
    /* [retval][out] */ long *pdwLevel);


void __RPC_STUB IPMPackageFile_get_Level_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPMPackageFile_get_CpuNum_Proxy( 
    IPMPackageFile * This,
    /* [retval][out] */ long *pdwCpuNum);


void __RPC_STUB IPMPackageFile_get_CpuNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPMPackageFile_INTERFACE_DEFINED__ */


#ifndef __IEnumVariant_INTERFACE_DEFINED__
#define __IEnumVariant_INTERFACE_DEFINED__

/* interface IEnumVariant */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IEnumVariant;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AF8278EC-A3C4-44B3-85B3-6B8CF9BC7237")
    IEnumVariant : public IDispatch
    {
    public:
        virtual /* [helpstring][id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pUnk) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ VARIANT *pVariant) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumVariantVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumVariant * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumVariant * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumVariant * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEnumVariant * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEnumVariant * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEnumVariant * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEnumVariant * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IEnumVariant * This,
            /* [retval][out] */ IUnknown **pUnk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IEnumVariant * This,
            /* [in] */ long Index,
            /* [retval][out] */ VARIANT *pVariant);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IEnumVariant * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } IEnumVariantVtbl;

    interface IEnumVariant
    {
        CONST_VTBL struct IEnumVariantVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumVariant_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumVariant_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumVariant_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumVariant_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEnumVariant_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEnumVariant_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEnumVariant_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IEnumVariant_get__NewEnum(This,pUnk)	\
    (This)->lpVtbl -> get__NewEnum(This,pUnk)

#define IEnumVariant_get_Item(This,Index,pVariant)	\
    (This)->lpVtbl -> get_Item(This,Index,pVariant)

#define IEnumVariant_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][restricted][propget] */ HRESULT STDMETHODCALLTYPE IEnumVariant_get__NewEnum_Proxy( 
    IEnumVariant * This,
    /* [retval][out] */ IUnknown **pUnk);


void __RPC_STUB IEnumVariant_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IEnumVariant_get_Item_Proxy( 
    IEnumVariant * This,
    /* [in] */ long Index,
    /* [retval][out] */ VARIANT *pVariant);


void __RPC_STUB IEnumVariant_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IEnumVariant_get_Count_Proxy( 
    IEnumVariant * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IEnumVariant_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumVariant_INTERFACE_DEFINED__ */


#ifndef __IClientInfo_INTERFACE_DEFINED__
#define __IClientInfo_INTERFACE_DEFINED__

/* interface IClientInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IClientInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B293E1A7-B804-498e-8597-B9105C58C371")
    IClientInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetClientProcessId( 
            /* [in] */ DWORD dwPid) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClientInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClientInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClientInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClientInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetClientProcessId )( 
            IClientInfo * This,
            /* [in] */ DWORD dwPid);
        
        END_INTERFACE
    } IClientInfoVtbl;

    interface IClientInfo
    {
        CONST_VTBL struct IClientInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClientInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClientInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClientInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClientInfo_SetClientProcessId(This,dwPid)	\
    (This)->lpVtbl -> SetClientProcessId(This,dwPid)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClientInfo_SetClientProcessId_Proxy( 
    IClientInfo * This,
    /* [in] */ DWORD dwPid);


void __RPC_STUB IClientInfo_SetClientProcessId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClientInfo_INTERFACE_DEFINED__ */



#ifndef __CEMGRLib_LIBRARY_DEFINED__
#define __CEMGRLib_LIBRARY_DEFINED__

/* library CEMGRLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_CEMGRLib;

EXTERN_C const CLSID CLSID_PlatformManager;

#ifdef __cplusplus

class DECLSPEC_UUID("F384D883-F9AA-11D1-BB9E-00A0C9C9CCEE")
PlatformManager;
#endif
#endif /* __CEMGRLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


