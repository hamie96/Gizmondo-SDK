// platman_idl.inc : Include file
//
// This file is included by both cemgr.idl and cemgrhm.idl. Any changes to any interfaces need to
// be done only to this file.
//
// Copyright 2001 Microsoft, All Rights Reserved

import "oaidl.idl";
import "ocidl.idl";

// Standard interfaces
interface IPlatformManager;
interface IEnumPlatformCE;
interface IPlatformCE;
interface IRemoteDevice;
interface IEnumDevice;
interface IEnumProperty;
interface IProperty;
interface IEnumPropInfo;
interface IConnection;
interface ICallBack;
interface IPlatManCallback2;	// QI'd from ICallBack
interface IConnectionStream;

// Configuration version
interface IPlatformManagerConfig; // QI'd from IPlatformManager
interface IPlatformConfig;	// QI'd from IPlatform
interface IRemoteDeviceConfig; // QI'd from IRemoteDevice
interface IPackage;  // IPlatformManagerConfig->AddPackage
interface IEnumComponent; // IPlatform->EnumComponents
interface IEnumPackageFiles; // IPackage->EnumFiles
interface IEnumCPU; // IPlatformConfig->EnumCPU

// VS7 updated version
interface IRemoteDeviceConfig2; //IPlatformManager stuff.
interface IEnumPackageFiles2; // IPackage2->EnumFiles
interface IPackage2;  // IPlatformManagerConfig2->AddPackage
interface IPlatformManagerConfig2; // QI'd from IPlatformManager

//Ver 4.0
interface IEnumBootableDevice;
interface IBootableDevice;
interface IServiceCategory;
interface IEnumServiceCategory;
interface IEnumServiceInfo;
interface IServiceInfo;
interface IService;

//Automation Interfaces
interface IPMPlatformManager;
interface IPMPlatform;
interface IPMRemoteDevice;
interface IPMBootableDevice;
interface IPMProperty;
interface IPMConnection;
interface IPMConnectionStream;
interface IPMPackage;
interface IPMService;
interface IPMServiceInfo;
interface IPMServiceCategory;
interface IPMCPU;
interface IPMOS;
interface IPMStartupServerInfo;
interface IPMTransportInfo;
interface IPMPropInfo;
interface IPMPackageFile;

//Automation Enumeration/Collection Interface
interface IEnumVariant;

// client info interface to get the process id's
interface IClientInfo;

//
// error codes
//
cpp_quote("// error codes")
cpp_quote("//")
cpp_quote("static const int E_BAD_PARAM				= MAKE_HRESULT(1, FACILITY_ITF, 0x01);")
cpp_quote("static const int E_DUPLICATE				= MAKE_HRESULT(1, FACILITY_ITF, 0x02);")
cpp_quote("static const int E_BUSY					= MAKE_HRESULT(1, FACILITY_ITF, 0x03);")
cpp_quote("static const int E_BAD_CONFIG			= MAKE_HRESULT(1, FACILITY_ITF, 0x04);")
cpp_quote("static const int E_NOSYSFILES			= MAKE_HRESULT(1, FACILITY_ITF, 0x05);")
cpp_quote("static const int E_TIMEOUT				= MAKE_HRESULT(1, FACILITY_ITF, 0x06);")
cpp_quote("static const int E_REFED					= MAKE_HRESULT(1, FACILITY_ITF, 0x07);")
//


// error codes for copy commands 
cpp_quote("static const int E_VERIFY				= MAKE_HRESULT(1, FACILITY_ITF, 0x01);")
cpp_quote("static const int E_EXISTS				= MAKE_HRESULT(1, FACILITY_ITF, 0x02);")
cpp_quote("static const int E_REGISTER				= MAKE_HRESULT(1, FACILITY_ITF, 0x03);")

// Return code for IConnectCallBack->Report
cpp_quote("static const int E_SKIP					= MAKE_HRESULT(1, FACILITY_ITF, 0x01);")

// Property GUIDs
cpp_quote("static const GUID PROPID_CURRENT_CONNECTION = {0xc5562463, 0xa1cc, 0x4b78, { 0xb7, 0xe2, 0xf2, 0x7, 0x9, 0xd2, 0xf7, 0x9d}};")
cpp_quote("static const wchar_t PROPINFO_BOOTABLE_DEVICE[] = L\"CurrentDevice\";")
cpp_quote("static const wchar_t PROPINFO_IMAGE[] = L\"Image\";")

//used for the updated CEMGRC.EXE
// {69793847-677E-4658-92D3-B32A2ED13FE4}
cpp_quote("static const GUID CEMGRC2_ID = { 0x69793847, 0x677e, 0x4658, { 0x92, 0xd3, 0xb3, 0x2a, 0x2e, 0xd1, 0x3f, 0xe4 } };")

// used for universal sdks property within a platform and platform manager
// {1315CF7C-D79B-47e8-A141-CC39654E767F}
cpp_quote("static const GUID PROPID_UNIVERSAL_SDK = { 0x1315cf7c, 0xd79b, 0x47e8, { 0xa1, 0x41, 0xcc, 0x39, 0x65, 0x4e, 0x76, 0x7f } };")
cpp_quote("static const wchar_t PROPINFO_TUSDK[] = L\"TUSDK\";")
cpp_quote("static const wchar_t PROPVALUE_UNIVERSAL[] = L\"Universal\";")
cpp_quote("static const wchar_t PROPVALUE_PARENTS[] = L\"Parents\";")

// used for serial download and serial kitl property storage
// {EC345961-5500-4d8e-8C27-387542FAB812}
cpp_quote("static const GUID PROP_SERIAL_GUID = { 0xEC345961, 0x5500, 0x4d8e, { 0x8C, 0x27, 0x38, 0x75, 0x42, 0xFA, 0xB8, 0x12 } };")
cpp_quote("static const wchar_t PROP_SERIAL_STRING[] = L\"{EC345961-5500-4d8e-8C27-387542FAB812}\";")

// Configure Remote Services Dialog Property on 
// Platform Managers IBootable Device 
// GUID for Dialog Property
// {44F1DBD2-16C1-4e8a-9BC2-03E66ADB030E}
cpp_quote("static const GUID PROPID_CFG_REM_SRV = { 0x44f1dbd2, 0x16c1, 0x4e8a, { 0x9b, 0xc2, 0x3, 0xe6, 0x6a, 0xdb, 0x3, 0xe } };")
cpp_quote("static const wchar_t PROPINFONAME_PROCID[] = L\"Process ID messages\";")
cpp_quote("static const wchar_t PROPINFONAME_THRDID[] = L\"Thread ID messages\";")
cpp_quote("static const wchar_t PROPINFONAME_TSTAMP[] = L\"Time stamp messages\";")
cpp_quote("static const wchar_t PROPINFONAME_DLOAD[] = L\"Download Image\";")
cpp_quote("static const wchar_t PROPINFONAME_JUMP[] = L\"Jump to Image\";")
cpp_quote("static const wchar_t PROPINFONAME_CONNNECT[] = L\"Connect On Download\";")
cpp_quote("static const wchar_t PROPINFONAME_HARDWARE[] = L\"Hardware Debugger\";")
cpp_quote("static const wchar_t PROPINFONAME_DBGMSGFILENAME[] = L\"Dbg Msg Filename\";")
cpp_quote("static const wchar_t PROPINFONAME_SENDDBGMSGOUTPUT[] = L\"Send Dbg Output\";")
cpp_quote("static const wchar_t PROPINFONAME_DOWNLOAD_CFGSETTING[] = L\"Download Config Setting\";")
cpp_quote("static const wchar_t PROPINFONAME_KERNEL_CFGSETTING[] = L\"Kernel Config Setting\";")
cpp_quote("static const wchar_t PROPINFONAME_HARDWARE_DBG_GUID[] = L\"eXdi Driver GUID\";")
cpp_quote("static const wchar_t PROPINFONAME_HARDWARE_DBG_DESC[] = L\"eXdi Driver Name\";")
cpp_quote("static const wchar_t PROPINFONAME_COLDBOOT[] = L\"Cold Reboot\";")
cpp_quote("static const wchar_t PROPINFONAME_RESET_DL_ALWAYS[] = L\"Reset DL Always\";")
cpp_quote("static const wchar_t PROPINFONAME_RESET_DL_IMAGE_CHANGE[] = L\"Reset DL Image Change\";")
cpp_quote("static const wchar_t PROPINFONAME_RESET_JTI_ONLY[] = L\"Reset JTI Only\";")
cpp_quote("static const wchar_t PROPINFONAMR_LAST_OPEN_BIN_IMAGE[] = L\"Last Open Bin Image\";")
cpp_quote("static const wchar_t PROPINFONAME_SENDDBGMSGOUTPUTWINDOW[] = L\"Send Dbg Output Window\";")
cpp_quote("static const wchar_t PROPINFONAME_SENDDBGMSGOUTPUTWINDOWNL[] = L\"DBGMSG append new line\";")
cpp_quote("static const wchar_t PROPINFONAME_ALLOW_ACCESS_TO_FILESYSTEM[] = L\"Allow Remote Access to Local File System\";")
cpp_quote("static const wchar_t REGKEY_PLATMAN_PPFSACCESS[] = L\"Software\\\\Microsoft\\\\Windows CE Tools\\\\Platform Manager\\\\PPFSAccess\";")
cpp_quote("static const wchar_t REGVAL_PB_PPFS_ACCESS[] = L\"AllowPPFSAccess\";")


//
// Defines
//
typedef enum component_kind {
	COMPONENT_TRANSPORT,
	COMPONENT_SERVER
} COMPONENT_KIND;

enum {
	DEVICE_TYPE_EMULATION = 0x1,
	DEVICE_TYPE_CE = 0x2,
	DEVICE_TYPE_NT = 0x4 // Only for testing purposes
};
typedef ULONG DEVICE_TYPE;

typedef enum report_action_type {
	SERVER_START,
	SERVER_FAIL,
	SERVER_FINISH,
	CONNECT_START,
	CONNECT_FAIL,
	CONNECT_FINISH,
	VERIFY_START,
	VERIFY_FAIL,
	VERIFY_FINISH,
	COPY_START,
	COPY_FAILED,
	COPY_FINISH,
	REGISTER_START,
	REGISTER_FAILED,
	REGISTER_FINISH,
	COPY_COMPLETE,
	ATTACH_TIMEOUT,
	COPY_SOURCENOTFOUND,
} REPORT_ACTION_TYPE;

// Flags for Packages
cpp_quote("static const int FILE_FLAG_REQUIRED	= 0x00000001;")
cpp_quote("static const int FILE_FLAG_16BIT		= 0x00000002;")
cpp_quote("static const int FILE_FLAG_FPSUPPORT	= 0x00000004;")
cpp_quote("static const int FILE_FLAG_CPUNUM   	= 0x00000008;")

// Flags for Platforms
cpp_quote("static const int DEVICE_FLAG_NO_FILESYS = 0x00000001;")

// If the FILE_FLAG_CPUNUM bit is set in dwFlags, then the dwCPUType
// is the return value of QueryInstructionSet, which uniquely identifies
// the device.
// Else we do the old matching based on architechture, cputype, processor level
// and page size.

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
} PACKAGE_FILE_INFO, *PPACKAGE_FILE_INFO;

//New package to support the OS item.
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
} PACKAGE_FILE_INFO2, *PPACKAGE_FILE_INFO2;

	[
		uuid(F384D882-F9AA-11D1-BB9E-00A0C9C9CCEE),
	
		helpstring("IPlatformManager Interface"),
		pointer_default(unique)
	]
	interface IPlatformManager : IUnknown
	{
		HRESULT EnumPlatforms
		(
			[out]  IEnumPlatformCE **ppiEnumPlatform
		);
		HRESULT GetProperty
		(
			[in] GUID PropId, 
			[out] IProperty **ppiProperty
		);
		HRESULT AddProperty
		(
			[in] GUID PropId, 
			[in,ptr] LPCOLESTR pszLinkName,
			[out] IProperty **ppiProperty
		);
		HRESULT DeleteProperty					   
		(
			[in] GUID PropId
		);
		HRESULT EnumProperties
		(
			[out] IEnumProperty **ppiEnumProperty
		);
		HRESULT GetPlatform
		(
			[in] GUID PlatformId, 
			[out] IPlatformCE **ppiPlatform
		);
	};
	// Updated IPlatformManger2 interface to support
	// the new GetConnection method
	[
		uuid(D08B18FB-0471-4a4d-88F3-9F1187A058AA),

		helpstring("IPlatformManager2 Interface"),
		pointer_default(unique)
	]
	interface IPlatformManager2 : IPlatformManager
	{
		// GetConnection will return a IConnection from a GUID.  If
		// there are no connections active that is assigned with the 
		// specified GUID then E_FAIL is returned
		HRESULT GetConnection
		(
			[in] GUID ConnectId,
			[out] IConnection **ppiConnection	
		);	
	};







	// IPlatformManger3 interface to support
	// bootable devices
	[
		uuid(91DAF806-2EEB-44a5-B7D1-B1EF3DB9FC88),

		helpstring("IPlatformManager3 Interface"),
		pointer_default(unique)
	]
	interface IPlatformManager3 : IPlatformManager2
	{

		HRESULT EnumBootableDevice
		(
			[out]  IEnumBootableDevice **ppiEnumBootableDevice
		);

		HRESULT GetBootableDevice
		(
			[in] GUID BootableDeviceId, 
			[out] IBootableDevice **ppiBootableDevice
		);

		
		HRESULT EnumServiceCategory
		(
			[out]  IEnumServiceCategory **ppiEnumServiceCategory
		);

		HRESULT GetServiceCategory
		(
			[in] GUID ServiceCategoryId, 
			[out] IServiceCategory **ppiServiceCategory
		);

	};


	// IEnumServiceCategory to support
	// bootable devices
	[
		object,
		uuid(4E4527E8-BCE4-4675-B564-E7DE0EA6D163),
		helpstring("IEnumServiceCategory Interface"),
		pointer_default(unique)
	]
	interface IEnumServiceCategory : IUnknown
	{
		HRESULT Next
		(
			[in] ULONG celt,
			[out, size_is(celt), length_is(*pceltFetched)] IServiceCategory *rgelt[],
			[out] ULONG *pceltFetched
		);

		HRESULT Skip
		(
			[in] ULONG celt
		);

		HRESULT Reset
		(
		);

		HRESULT Clone
		(
			[out] IEnumServiceCategory **ppEnum
		);

		HRESULT GetCount
		(
			[out] ULONG *pcelt
		);

		HRESULT GetNext
		(
			[out] IServiceCategory **ppiServiceCategory
		);
	};
	

	// IServiceCategory to support
	// bootable devices
	[
		object,
		uuid(73EA2A51-09D5-416c-99FF-A6935A02672B),
		helpstring("IServiceCategory Interface"),
		pointer_default(unique)
	]
	interface IServiceCategory : IUnknown
	{
		HRESULT GetServiceCategoryId
		(
			[out] GUID *pServiceCategoryId
		);
		HRESULT GetServiceCategoryName
		(
			[out] LPOLESTR *ppszServiceCategoryName
		);
		HRESULT EnumServiceInfo
		(
			[out] IEnumServiceInfo **ppiEnumServiceInfo
		);
		HRESULT GetServiceInfo
		(
			[in] GUID ServiceCLSID,
			[out] IServiceInfo **ppiServiceInfo
		);
		HRESULT EnumProperties
		(
			[out] IEnumProperty **ppiEnumProperty
		);
		HRESULT GetProperty
		(
			[in] GUID PropId,
			[out] IProperty **ppiProperty
		);
		HRESULT AddProperty
		(
			[in] GUID PropId,
			[in,ptr] LPCOLESTR pszLinkName,
			[out] IProperty **ppiProperty
		);
		HRESULT DeleteProperty
		(
			[in] GUID PropId
		);

	};




	// IEnumServiceInfo to support
	// bootable devices
	[
		object,
		uuid(53CCA653-3F54-434c-8DB0-3D8A610745E4),
		helpstring("IEnumServiceInfo Interface"),
		pointer_default(unique)
	]
	interface IEnumServiceInfo : IUnknown
	{
		HRESULT Next
		(
			[in] ULONG celt,
			[out, size_is(celt), length_is(*pceltFetched)] IServiceInfo *rgelt[],
			[out] ULONG *pceltFetched
		);

		HRESULT Skip
		(
			[in] ULONG celt
		);

		HRESULT Reset
		(
		);

		HRESULT Clone
		(
			[out] IEnumServiceInfo **ppEnum
		);

		HRESULT GetCount
		(
			[out] ULONG *pcelt
		);

		HRESULT GetNext
		(
			[out] IServiceInfo **ppiServiceInfo
		);
	};
	

	// IServiceInfo to support
	// bootable devices
	[
		object,
		uuid(320494E2-0D2A-4594-A8FC-73913FAE85C8),
		helpstring("IServiceInfo Interface"),
		pointer_default(unique)
	]
	interface IServiceInfo : IUnknown
	{
		HRESULT GetServiceCLSID
		(
			[out] GUID *pServiceCLSID
		);
		HRESULT GetServiceInfoName
		(
			[out] LPOLESTR *ppszServiceInfoName
		);
		HRESULT EnumProperties
		(
			[out] IEnumProperty **ppiEnumProperty
		);
		HRESULT GetProperty
		(
			[in] GUID PropId,
			[out] IProperty **ppiProperty
		);
		HRESULT AddProperty
		(
			[in] GUID PropId,
			[in,ptr] LPCOLESTR pszLinkName,
			[out] IProperty **ppiProperty
		);
		HRESULT DeleteProperty
		(
			[in] GUID PropId
		);

	};





	// IEnumBootableDevice to support
	// bootable devices
	[
		object,
		uuid(B7D6E6F7-8D72-45f6-AE37-D7724989E5CB),
		helpstring("IEnumBootableDevice Interface"),
		pointer_default(unique)
	]
	interface IEnumBootableDevice : IUnknown
	{
		HRESULT Next
		(
			[in] ULONG celt,
			[out, size_is(celt), length_is(*pceltFetched)] IBootableDevice *rgelt[],
			[out] ULONG *pceltFetched
		);

		HRESULT Skip
		(
			[in] ULONG celt
		);

		HRESULT Reset
		(
		);

		HRESULT Clone
		(
			[out] IEnumBootableDevice **ppEnum
		);

		HRESULT GetCount
		(
			[out] ULONG *pcelt
		);

		HRESULT GetNext
		(
			[out] IBootableDevice **ppiBootableDevice
		);
	};
	

	// IBootableDevice to support
	// bootable devices
	//    Notes:
	//	EnumService : Enumerates through all selected services for BootableDevice
	//	GetService  : Loads the service and returns an IService Interface
	[
		object,
		uuid(6014FEE5-B7BF-4c3c-A2B8-A9D0F8B64110),
		helpstring("IBootableDevice Interface"),
		pointer_default(unique)
	]
	interface IBootableDevice : IUnknown
	{
		HRESULT GetBootableDeviceId
		(
			[out] GUID *pBootableDeviceId
		);
		HRESULT GetBootableDeviceName
		(
			[out] LPOLESTR *ppszBootableDeviceName
		);
		HRESULT GetService
		(
			[in] GUID ServiceCategoryId,
			[out] IService **ppiService
		);
		HRESULT EnumProperties
		(
			[out] IEnumProperty **ppiEnumProperty
		);
		HRESULT GetProperty
		(
			[in] GUID PropId,
			[out] IProperty **ppiProperty
		);
		HRESULT AddProperty
		(
			[in] GUID PropId,
			[in,ptr] LPCOLESTR pszLinkName,
			[out] IProperty **ppiProperty
		);
		HRESULT DeleteProperty
		(
			[in] GUID PropId
		);
		HRESULT ShutdownService
		(
		);
	};

	// IService to support
	// bootable devices
	[
		object,
		uuid(E408B5F2-348F-4263-B551-6437635C46E8),
		helpstring("IService Interface"),
		pointer_default(unique)
	]
	interface IService : IUnknown
	{
		HRESULT InitService
		(
			[in] IBootableDevice *piBootableDevice,
			[in] IServiceInfo *piServiceInfo
		);
		HRESULT GetServiceCLSID
		(
			[out] GUID *pServiceCLSID
		);
		HRESULT GetServiceCategoryId
		(
			[out] GUID *pServiceCategoryId
		);
		HRESULT IsServiceReleaseable 
		(
			[out] BOOL *pBool
		);
		HRESULT IsServiceConfigured
		(
			[out] BOOL *pConfigured
		);
	};

	// IPMServiceNuke to support self-unloading services 
	[
		object,
		uuid(BDAF11A3-78BD-4B32-91E8-8911B7A7FAAF),
		helpstring("IPMServiceNuke Interface: Used to cleanup any resources on an abnormal termination"),
		pointer_default(unique)
	]
	interface IPMServiceNuke : IUnknown
	{
		HRESULT UnloadServiceProvider
		(
		);
	};

	[
		object,
		uuid(768C9904-36E1-423b-91B4-433D709B6A19),
		helpstring("IServiceConfig Interface"),
		pointer_default(unique)
	]
	interface IServiceConfig : IUnknown
	{
		HRESULT ConfigureServiceUI
		(
			[in] HWND hWnd, 
			[in] IBootableDevice *piDevice,
			[in] IServiceInfo *piServiceInfo
		);

	};



	[
		object,
		uuid(F384D885-F9AA-11D1-BB9E-00A0C9C9CCEE),
		helpstring("IEnumPlatformCE Interface"),
		pointer_default(unique)
	]
	interface IEnumPlatformCE : IUnknown
	{
		HRESULT Next
		(
			[in] ULONG celt,
			[out, size_is(celt), length_is(*pceltFetched)] IPlatformCE *rgelt[],
			[out] ULONG *pceltFetched
		);

		HRESULT Skip
		(
			[in] ULONG celt
		);

		HRESULT Reset
		(
		);

		HRESULT Clone
		(
			[out] IEnumPlatformCE **ppEnum
		);

		HRESULT GetCount
		(
			[out] ULONG *pcelt
		);

		HRESULT GetNext
		(
			[out] IPlatformCE **ppiPlatform
		);
	};
	
	[
		object,
		uuid(F384D888-F9AA-11D1-BB9E-00A0C9C9CCEE),
		helpstring("IPlatformCE Interface"),
		pointer_default(unique)
	]
	interface IPlatformCE : IUnknown
	{
		HRESULT GetPlatformId
		(
			[out] GUID *pPlatformId
		);
		HRESULT EnumProperties
		(
			[out] IEnumProperty **ppiEnumProperty
		);
		HRESULT GetProperty
		(
			[in] GUID PropId,
			[out] IProperty **ppiProperty
		);
		HRESULT AddProperty
		(
			[in] GUID PropId,
			[in,ptr] LPCOLESTR pszLinkName,
			[out] IProperty **ppiProperty
		);
		HRESULT DeleteProperty
		(
			[in] GUID PropId
		);
		HRESULT GetPlatformName
		(
			[out] LPOLESTR *ppszPlatformName
		);
		HRESULT EnumDevices
		(
			[out] IEnumDevice **ppiEnumDevice
		);
		HRESULT GetDevice
		(
			[in] GUID DeviceId,
			[out] IRemoteDevice **ppiRemoteDevice
		);
		HRESULT EnumCPU
		(
			[out] IEnumCPU **ppiEnumCPU
		);
		HRESULT GetOSInfo
		(
			[out] LPWORD pwMajorVersion,
			[out] LPWORD pwMinorVersion
		);
	};
	
	
	[
		object,
		uuid(F384D88B-F9AA-11D1-BB9E-00A0C9C9CCEE),
		helpstring("IRemoteDevice Interface"),
		pointer_default(unique)
	]
	interface IRemoteDevice : IUnknown
	{
		HRESULT EnumProperties
		(
			[out] IEnumProperty **ppiEnumProperty
		);
		HRESULT GetProperty
		(
			[in] GUID PropId,
			[out] IProperty **ppiProperty
		);
		HRESULT AddProperty
		(
			[in] GUID PropId,
			[in,ptr] LPCOLESTR pszLinkName,
			[out] IProperty **ppiProperty
		);
		HRESULT DeleteProperty
		(
			[in] GUID PropId
		);
		HRESULT GetDeviceId
		(
			[out] GUID *pDeviceId
		);
		HRESULT GetDeviceType
		(
			[out] DEVICE_TYPE *pdt
		);
		HRESULT GetDeviceName
		(
			[out] LPOLESTR *ppszDeviceName
		);
		HRESULT Attach
		(
			[in] DWORD dwProcessId, 
			[in] LPCOLESTR pszProcessName,
			[in] DWORD dwTimeOut,
			[out] IConnection **ppiConnection,
			[in] ICallBack *piCallBack
		);
	};
	
	// IRemoteDevice2 interface to support
	// the new GetConnection method
	[
		object,
		uuid(C4C0EE08-FC65-40f0-863E-B3C891A750C2),
		helpstring("IRemoteDevice2 Interface"),
		pointer_default(unique)
	]
	interface IRemoteDevice2 : IRemoteDevice
	{
		// GetConnection will return a IConnection from a GUID.  If
		// there are no connections active that is assigned with the 
		// specified GUID then E_FAIL is returned
		HRESULT GetConnection
		(
			[in] GUID ConnectId,
			[out] IConnection **ppiConnection
		);
	};

	[
		object,
		uuid(F384D88E-F9AA-11D1-BB9E-00A0C9C9CCEE),
		helpstring("IEnumDevice Interface"),
		pointer_default(unique)
	]
	interface IEnumDevice : IUnknown
	{
		HRESULT Next
		(
			[in] ULONG celt,
			[out, size_is(celt), length_is(*pceltFetched)] IRemoteDevice *rgelt[],
			[out] ULONG *pceltFetched
		);

		HRESULT Skip
		(
			[in] ULONG celt
		);

		HRESULT Reset
		(
		);

		HRESULT Clone
		(
			[out] IEnumDevice **ppEnum
		);

		HRESULT GetCount
		(
			[out] ULONG *pcelt
		);

		HRESULT GetNext
		(
			[out] IRemoteDevice **ppiRemoteDevice
		);
	};
	
	[
		object,
		uuid(F384D891-F9AA-11D1-BB9E-00A0C9C9CCEE),
		helpstring("IEnumProperty Interface"),
		pointer_default(unique)
	]
	interface IEnumProperty : IUnknown
	{
		HRESULT Next
		(
			[in] ULONG celt,
			[out, size_is(celt), length_is(*pceltFetched)] IProperty *rgelt[],
			[out] ULONG *pceltFetched
		);

		HRESULT Skip
		(
			[in] ULONG celt
		);

		HRESULT Reset
		(
		);

		HRESULT Clone
		(
			[out] IEnumProperty **ppEnum
		);

		HRESULT GetCount
		(
			[out] ULONG *pcelt
		);

		HRESULT GetNext
		(
			[out] IProperty **ppiProperty
		);
	};
		
	[
		object,
		uuid(F384D894-F9AA-11D1-BB9E-00A0C9C9CCEE),
		helpstring("IProperty Interface"),
		pointer_default(unique)
	]
	interface IProperty : IUnknown
	{
		HRESULT EnumProperties
		(
			[out] IEnumProperty **ppiEnumProperty
		);
		HRESULT GetPropertyId
		(
			[out] GUID *pPropId
		);
		HRESULT GetProperty
		(
			[in] GUID PropId,
			[out] IProperty **ppiProperty
		);
		HRESULT AddProperty
		(
			[in] GUID PropId,
			[in,ptr] LPCOLESTR pszLinkName,
			[out] IProperty **ppiProperty
		);
		HRESULT DeleteProperty
		(
			[in] GUID PropId
		);
		HRESULT EnumPropInfo
		(
			[out] IEnumPropInfo **ppiEnumPropInfo
		);

		//
		//
		// dwPropType can be one of the following values
		//
		/*
			#define REG_SZ                      ( 1 )   // Unicode nul terminated string
			#define REG_EXPAND_SZ               ( 2 )   // Unicode nul terminated string
														// (with environment variable references)
			#define REG_BINARY                  ( 3 )   // Free form binary
			#define REG_DWORD                   ( 4 )   // 32-bit number
			#define REG_DWORD_LITTLE_ENDIAN     ( 4 )   // 32-bit number (same as REG_DWORD)
			#define REG_DWORD_BIG_ENDIAN        ( 5 )   // 32-bit number
			#define REG_LINK                    ( 6 )   // Symbolic Link (unicode)
			#define REG_MULTI_SZ                ( 7 )   // Multiple Unicode strings
			#define REG_RESOURCE_LIST           ( 8 )   // Resource list in the resource map
		*/
		HRESULT SetPropInfo
		(
			[in] LPCOLESTR pszName,
			[in] DWORD dwPropSize,
			[in] DWORD dwPropType,
			[in, size_is(dwPropSize)] BYTE *pPropValue
		);
		HRESULT DeletePropInfo
		(
			[in] LPCOLESTR pszName
		);

		// see notes for SetPropInfo
		HRESULT GetPropInfo
		(
			[in] LPCOLESTR pszName,
			[in] DWORD dwSizeIn,
			[out] LPDWORD pdwPropType,
			[out, size_is(dwSizeIn), length_is(*pdwSizeReturned)] BYTE *pBuffer,
			[out] DWORD *pdwSizeReturned,
			[out] DWORD *pdwSizeActual
		);
	};
	
	[
		object,
		uuid(F384D897-F9AA-11D1-BB9E-00A0C9C9CCEE),
		helpstring("IEnumPropInfo Interface"),
		pointer_default(unique)
	]
	interface IEnumPropInfo : IUnknown
	{
		HRESULT Next
		(
			[in] ULONG celt,
			[out, size_is(celt), length_is(*pceltFetched)] LPOLESTR rgelt[],
			[out] ULONG *pceltFetched
		);

		HRESULT Skip
		(
			[in] ULONG celt
		);

		HRESULT Reset
		(
		);

		HRESULT Clone
		(
			[out] IEnumPropInfo **ppEnum
		);

		HRESULT GetCount
		(
			[out] ULONG *pcelt
		);

		HRESULT GetNext
		(
			[out] LPOLESTR *ppszName
		);
	};
	
	[
		object,
		uuid(DA438BAA-FA87-11D1-BB9E-00A0C9C9CCEE),
		helpstring("IConnection Interface"),
		pointer_default(unique)
	]
	interface IConnection : IUnknown
	{
		HRESULT FileCopy
		(
			[in] LPCOLESTR pszSource,
			[in] LPCOLESTR pszDest,
			[in] BOOL   fOverWrite,
			[in] ICallBack *piCallBack,
			[out] LPDWORD pdwTotalSize
		);
		HRESULT CopyPackage
		(
			[in] GUID PackageId,
			[in] LPCOLESTR pszDestPath,
			[in] BOOL   fOverWrite,
			[in] ICallBack *piCallBack,
			[out] LPDWORD pdwTotalSize
		);
		HRESULT QueuePackage
		(
			[in] GUID PackageId,
			[in] LPCOLESTR pszDestPath,
			[in] BOOL fOverWrite
		);
		HRESULT QueueFile
		(
			[in] LPCOLESTR pszSource,
			[in] LPCOLESTR pszDest,
			[in] BOOL	fOverWrite
		);
		HRESULT CopyQueuedFiles
		(
			[in] ICallBack *piCallBack,
			[out] LPDWORD pdwTotalSize
		);
		HRESULT GetQueueCount
		(
			[out] LPDWORD pdwCount
		);
		HRESULT Launch
		(
			[in] LPCOLESTR pszRemotePath,
			[in,ptr] LPCOLESTR pszCmdLine
		);
		HRESULT SystemGetInfo
		(
			[out] LPWORD pwArchitecture,
			[out] LPDWORD pdwCPUType,
			[out] LPDWORD pdwPageSize,
			[out] LPWORD pwMajorVersion,
			[out] LPWORD pwMinorVersion
		);
		HRESULT FileGetInfo
		(
			[in] LPCOLESTR pszRemotePath,
			[out] LPDWORD pdwFileAttributes,
			[out] LPDWORD pdwFileSize,
			[out] LPFILETIME pCreationTime
		);
		HRESULT FileDelete
		(
			[in] LPCOLESTR pszFullPath
		);
		HRESULT CreateStream
		(
			[in] GUID HostId,
			[in] DWORD dwPortId,
			[out] IConnectionStream **ppiConnectionStream,
			[in] ICallBack *piCallBack
		);
		HRESULT GetLocalInfo
		(
			[out] LPDWORD pdwLocaleId
		);
		HRESULT GetFile
		(
			[in] LPCOLESTR pszRemotePath,
			[in] LPCOLESTR pszDest,
			[in] ICallBack *piCallBack,
			[out] LPDWORD pdwTotalSize
		);
		HRESULT GetPlatformId
		(
			[out] GUID *pPlatformId
		);
		HRESULT ResetQueue
		(
		);
		HRESULT CloseAllStreams
		(
		);

	};

	// IConnection2 interface to support the updated SystemGetInfo method.
	// GetConnectId method to retrieve the GUID that represents 
	// the connection.
	[
		object,
		uuid(073E4A43-45BC-46ef-B114-F42BA51C6366),
		helpstring("IConnection2 Interface"),
		pointer_default(unique)
	]
	interface IConnection2 : IConnection
	{
		
		//SystemGetInfoEx will also query the Device for the OSTypeId, which should be
		//specified as a GUID
		HRESULT SystemGetInfoEx
		(
			[out] LPWORD pwArchitecture,
			[out] LPDWORD pdwCPUType,
			[out] LPDWORD pdwPageSize,
			[out] LPWORD pwMajorVersion,
			[out] LPWORD pwMinorVersion,
			[out] GUID *OSTypeId
		);
		
		//ConnectId will query the connection object for a GUID that represents 
		// the connection
		HRESULT GetConnectId //Get the GUID that represents the connection.
		(
			[out] GUID *pConnectId
		);

	};



	[
		object,
		uuid(DA438BB0-FA87-11D1-BB9E-00A0C9C9CCEE),
		helpstring("IStream Interface"),
		pointer_default(unique)
	]
	interface IConnectionStream : IUnknown
	{
		HRESULT Send
		(
			[in] DWORD dwSize,
			[in, size_is(dwSize)] BYTE *pBuffer,
			[out] LPDWORD pdwSizeSent
		);
		HRESULT Receive
		(
			[out] LPDWORD pdwBytesReceived
		);
		HRESULT ReadBytes
		(
			[in] DWORD dwSize,
			[out, size_is(dwSize), length_is(*pdwSizeRecv)] BYTE *pBuffer,
			[out] LPDWORD pdwSizeRecv
		);
		HRESULT ReceiveAsync
		(
			[in] ICallBack *piCallBack
		);
		HRESULT SendAsync
		(
			[in] ICallBack *piCallBack
		);
		HRESULT Close
		(
		);
	};

	[
		object,
		uuid(EF075F33-141A-4D6A-9D88-33360EBFCBA5),
		helpstring("IConnectionStream2 Interface which provides timeout option on receive"),
		pointer_default(unique)
	]
	interface IConnectionStream2 : IUnknown
	{
		HRESULT Receive
		(
			[in] DWORD dwTimeout,
			[out] LPDWORD pdwBytesReceived
		);
		HRESULT ReadBytes
		(
			[in] DWORD dwSize,
			[in] DWORD dwTimeout,
			[out, size_is(dwSize), length_is(*pdwSizeRecv)] BYTE *pBuffer,
			[out] LPDWORD pdwSizeRecv
		);
	};
	
	[
		object,
		uuid(DA438BB3-FA87-11D1-BB9E-00A0C9C9CCEE),
		helpstring("ICallBack Interface"),
		pointer_default(unique)
	]
	interface ICallBack : IUnknown
	{
		HRESULT Connect
		(
			[in] IConnection *piConnection
		);
		HRESULT RecvNotify
		(
			[in] DWORD dwSize,
			[in, size_is(dwSize)] BYTE *pBuffer
		);
		HRESULT SendNotify
		(
		);
		HRESULT ReportAction
		(
			[in] REPORT_ACTION_TYPE at,
			[in] LPCOLESTR pszName,
			[in] HRESULT hrActionFailed,
			[in] DWORD dwSize
		);
		HRESULT ConfirmCopy
		(
			[in] LPCOLESTR pszName,
			[in] FILETIME ftSource,
			[in] FILETIME ftDest
		);
		HRESULT CopyUpdate
		(
			[in] LPCOLESTR pszName,
			[in] DWORD dwSizeCopied,
			[in] DWORD dwSizeTotal
		);
		HRESULT StreamNotify
		(
			[in] IConnectionStream *piConnectionStream
		);
	};
	


	// You can build a class that inherits from ICallBack and from IPlatManCallback2.
	// You must pass the ICallBack interface to the routines like Attach, 
	// CopyQueuedFiles, SendAsync, etc.  Some of these routines will, however, QI the
	// ICallBack interface for IID_IPlatManCallback2.  If your callback object can export
	// an IPlatManCallback2 interface, then the routine will pass information to that
	// interface.

	typedef struct 
	{
		BOOL		fIsPeExe;
		FILETIME	FileTime;
		WORD		TargetCpu;
	} CB2_FILEINFO;

	[
		object,
		uuid(EC0A1BC0-A1F4-11d3-98FC-00105AA90682),
		helpstring("IPlatManCallback2 Interface"),
		pointer_default(unique)
	]
	interface IPlatManCallback2 : IUnknown
	{
		HRESULT ConfirmCopy2
		(
			[in] LPCOLESTR		pszName,
			[in] CB2_FILEINFO*	pSrcFileInfo,
			[in] CB2_FILEINFO*	pDestFileInfo
		);
	};
	
	[
		object,
		uuid(DA438BC2-FA87-11D1-BB9E-00A0C9C9CCEE),
		helpstring("IPlatformManagerConfig Interface"),
		pointer_default(unique)
	]
	interface IPlatformManagerConfig : IUnknown
	{
		HRESULT AddPackage
		(
			[in] GUID PackageId,
			[in] LPCOLESTR pszPackageName,
			[out] IPackage **ppiPackage
		);
		HRESULT GetPackage
		(
			[in] GUID PackageId,
			[out] IPackage **ppiPackage
		);
		HRESULT DeletePackage
		(
			[in] GUID PackageId
		);
		HRESULT AddPlatform
		(
			[in] GUID PlatformId, 
			[in] LPCOLESTR pszPlatformName,
			[out] IPlatformCE **ppiPlatform
		);
		HRESULT DeletePlatform
		(
			[in] GUID PlatformId
		);
		HRESULT GetVersion
		(
			[out] LPWORD pwMajorVersion,
			[out] LPWORD pwMinorVersion,
			[out] LPDWORD pdwBuildNumber
		);
		HRESULT GetVersion2
		(
			[out] LPWORD pwMajorVersion,
			[out] LPWORD pwMinorVersion,
			[out] LPDWORD pdwBuildNumber
		);
		HRESULT AddToolkit
		(
			[in] GUID ToolkitId,
			[in] LPCOLESTR pszName
		);
		HRESULT DeleteToolkit
		(
			[in] GUID ToolkitId
		); 
	};

	[
		object,
		uuid(30A76E8E-8B0D-4E3b-8EC7-9B57862EFBF1),
		helpstring("IPlatformManagerConfig2 Interface"),
		pointer_default(unique)
	]
	interface IPlatformManagerConfig2 : IPlatformManagerConfig
	{
		// AddPackage adds an IPackage2 interface
		HRESULT AddPackage2
		(
			[in] GUID PackageId,
			[in] LPCOLESTR pszPackageName,
			[out] IPackage2 **ppiPackage
		);

		//GetPackage retrieves an IPackage2 interface
		HRESULT GetPackage2
		(
			[in] GUID PackageId,
			[out] IPackage2 **ppiPackage
		);
		
	};


	//The IPlatformManagerConfig3 interface is to help configure Bootable Devices
	//   and add Service Categories.
	[
		object,
		uuid(817E8295-C9EE-48ec-B1AC-37A858B73609),
		helpstring("IPlatformManagerConfig3 Interface"),
		pointer_default(unique)
	]
	interface IPlatformManagerConfig3 : IPlatformManagerConfig2
	{
		HRESULT AddBootableDevice
		(
			[in] GUID BootableDeviceId, 
			[in] LPCOLESTR pszBootableDeviceName,
			[out] IBootableDevice **ppiBootableDevice
		);
		HRESULT DeleteBootableDevice
		(
			[in] GUID BootableDeviceId
		);
		HRESULT AddServiceCategory
		(
			[in] GUID ServiceCategoryId, 
			[in] LPCOLESTR pszServiceCategoryName,
			[out] IServiceCategory **ppiServiceCategory
		);
		HRESULT DeleteServiceCategory
		(
			[in] GUID ServiceCategoryId
		);

	};



	// IBootableDeviceConfig to support
	// bootable devices
	[
		object,
		uuid(016ED627-9104-4fb6-8F82-E522755CC5AA),
		helpstring("IBootableDeviceConfig Interface"),
		pointer_default(unique)
	]
	interface IBootableDeviceConfig : IUnknown
	{
		HRESULT SetBootableDeviceName
		(
			[in] LPCOLESTR pszName
		);
		HRESULT AddService
		(
			[in] GUID ServiceCategoryId,
			[in] GUID ServiceCLSID
		);
		HRESULT DeleteService
		(
			[in] GUID ServiceCategoryId
		);
	};


	// IServiceCategoryConfig to support
	// bootable devices
	[
		object,
		uuid(C335A883-E95A-4ea4-9DDA-FBE83C55D519),
		helpstring("IServiceCategoryConfig Interface"),
		pointer_default(unique)
	]
	interface IServiceCategoryConfig : IUnknown
	{
		HRESULT SetServiceCategoryName
		(
			[in] LPCOLESTR pszServiceCategoryName
		);
		HRESULT AddServiceInfo
		(
			[in] GUID ServiceCLSID,
			[in] LPCOLESTR pszServiceName,
			[out] IServiceInfo **ppiServiceInfo
		);
		HRESULT DeleteServiceInfo
		(
			[in] GUID ServiceCLSID
		);


	};





	// IServiceInfoConfig to support
	// bootable devices
	[
		object,
		uuid(324AA352-F2F5-4c23-AD31-1088D7D8EA97),
		helpstring("IServiceInfoConfig Interface"),
		pointer_default(unique)
	]
	interface IServiceInfoConfig : IUnknown
	{
		HRESULT SetServiceInfoName
		(
			[in] LPCOLESTR pszServiceInfoName
		);

	};



	
	[
		object,
		uuid(DA438BC7-FA87-11D1-BB9E-00A0C9C9CCEE),
		helpstring("IPlatformConfig Interface"),
		pointer_default(unique)
	]
	interface IPlatformConfig : IUnknown
	{
		HRESULT AddPackage
		(
			[in] GUID PackageId,
			[in] LPCOLESTR pszPackageName,
			[out] IPackage **ppiPackage
		);
		HRESULT GetPackage
		(
			[in] GUID PackageId,
			[out] IPackage **ppiPackage
		);
		HRESULT DeletePackage
		(
			[in] GUID PackageId
		);
		HRESULT AddComponent
		(
			[in] COMPONENT_KIND ck,
			[in] GUID ComponentId,
			[in] BOOL fDefault
		);
		HRESULT SetPlatformName
		(
			[in] LPCOLESTR pszPlatformName
		);
		HRESULT AddDevice
		(
			[in] GUID DeviceId,
			[in] LPCOLESTR pszName,
			[in] DEVICE_TYPE dt, 
			[out] IRemoteDevice **ppiDevice
		);
		HRESULT DeleteDevice
		(
			[in] GUID DeviceId
		);
		HRESULT EnumComponent
		(
			[in] COMPONENT_KIND ck,
			[out] IEnumComponent **ppiEnumComponent
		);
		HRESULT GetComponentName
		(
			[in] COMPONENT_KIND ck,
			[in] GUID ComponentId,
			[out] LPOLESTR *pszName			
		);
		HRESULT GetComponentType
		(
			[in] COMPONENT_KIND ck,
			[in] GUID ComponentId,
			[out] DEVICE_TYPE *pdt
		);
		HRESULT AddSupportedCPU
		(
			[in] WORD wArchitecture,
			[in] DWORD dwCPUType,
			[in] LPCOLESTR pszName
		);
		HRESULT SetOSInfo
		(
			[in] WORD wMajorVersion,
			[in] WORD wMinorVersion
		);

	};

	[
		object,
		uuid(FA59C739-CFD3-4421-B7F0-AA22D48D864C),
		helpstring("IPlatformConfig2 Interface"),
		pointer_default(unique)
	]
	interface IPlatformConfig2 : IPlatformConfig
	{
		// AddPackage adds an IPackage2 interface
		HRESULT AddPackage2
		(
			[in] GUID PackageId,
			[in] LPCOLESTR pszPackageName,
			[out] IPackage2 **ppiPackage
		);
		// AddPackage now gets an IPackage2 interface
		HRESULT GetPackage2
		(
			[in] GUID PackageId,
			[out] IPackage2 **ppiPackage
		);
	};


	[
		object,
		uuid(DA438BCA-FA87-11D1-BB9E-00A0C9C9CCEE),
		helpstring("IRemoteDeviceConfig Interface"),
		pointer_default(unique)
	]
	interface IRemoteDeviceConfig : IUnknown
	{
		HRESULT SetDeviceName
		(
			[in] LPCOLESTR pszName
		);
		HRESULT SetComponent
		(
			[in] COMPONENT_KIND ck,
			[in] GUID ComponentId
		);
		HRESULT GetComponent
		(
			[in] COMPONENT_KIND ck,
			[out] GUID *pComponentId
		);
		HRESULT ConfigureComponent
		(
			[in] HWND hWnd,
			[in] COMPONENT_KIND ck,
			[in] GUID ComponentId
		);
	};

#ifdef DEVICE_SPECIFIC_TRANSPORTS
	[
		object,
		uuid(22ADBCCF-2007-451b-95D6-267E78B0EF98),
		helpstring("IRemoteDeviceConfig Interface"),
		pointer_default(unique)
	]
	interface IRemoteDeviceConfig2 : IRemoteDeviceConfig
	{
		//Allows you to Add a Device specific package.
		HRESULT AddPackage2
		(
			[in] GUID PackageId,
			[in] LPCOLESTR pszPackageName,
			[out] IPackage2 **ppiPackage
		);
		//Allows you to Get the specified Device specific package.
		HRESULT GetPackage2
		(
			[in] GUID PackageId,
			[out] IPackage2 **ppiPackage
		);

		//Allows you to Delete the specified Device specific package.
		HRESULT DeletePackage
		(
			[in] GUID PackageId
		);

		//Allows you to Add device specific Servers and Transports.
		HRESULT AddComponent
		(
			[in] COMPONENT_KIND ck,
			[in] GUID ComponentId,
			[in] BOOL fDefault
		);

		//Allows you to get an enumeration of device specific Servers and Transports.
		HRESULT EnumComponent
		(
			[in] COMPONENT_KIND ck,
			[out] IEnumComponent **ppiEnumComponent
		);
	}
#endif //DEVICE_SPECIFIC_TRANSPORTS

	[
		object,
		uuid(DA438BCD-FA87-11D1-BB9E-00A0C9C9CCEE),
		helpstring("IEnumComponent Interface"),
		pointer_default(unique)
	]
	interface IEnumComponent : IUnknown
	{
		HRESULT Next
		(
			[in] ULONG celt,
			[out, size_is(celt), length_is(*pceltFetched)] GUID *rgelt[],
			[out] ULONG *pceltFetched
		);

		HRESULT Skip
		(
			[in] ULONG celt
		);

		HRESULT Reset
		(
		);

		HRESULT Clone
		(
			[out] IEnumComponent **ppEnum
		);

		HRESULT GetCount
		(
			[out] ULONG *pcelt
		);

		HRESULT GetNext
		(
			[out] GUID *pComponentId
		);
	};
	
	[
		object,
		uuid(2A4F783A-014E-11D2-BBA0-00A0C9C9CCEE),
		helpstring("IPackage Interface"),
		pointer_default(unique)
	]
	interface IPackage : IUnknown
	{
		HRESULT AddFile
		(
			[in] LPCOLESTR pszFullPath,
			[in] LPCOLESTR pszName,
			[in] DEVICE_TYPE dt,
			[in] WORD wArchitecture,
			[in] DWORD dwCPUType,
			[in] WORD wProcessorLevel,
			[in] DWORD dwPageSize,
			[in] WORD wMajorVersion,
			[in] WORD wMinorVersion,
			[in] DWORD dwLocaleId,
			[in] DWORD dwFlags	
		);
		HRESULT AddPackageFile
		(
			[in] LPCOLESTR pszFullPath,
			[in] LPCOLESTR pszName,
			[in] PACKAGE_FILE_INFO pfi
		);
		HRESULT DeleteFile
		(
			[in] LPCOLESTR pszFullPath,
			[in] LPCOLESTR pszName
		);
		HRESULT EnumFiles
		(
			[in] LPCOLESTR pszName, 
			[in] PACKAGE_FILE_INFO pfi,
			[out] IEnumPackageFiles **ppiEnumFiles
		);
	};

// IPackage2 interface to support the PACKAGE_FILE_INFO2 structure which
// includes an OS specific GUID.
// 
	[
		object,
		uuid(64D0B782-47B7-4c30-8B5F-DDB7B248A91D),
		helpstring("IPackage2 Interface"),
		pointer_default(unique)
	]
	interface IPackage2 : IUnknown
	{
		HRESULT AddFile
		(
			[in] LPCOLESTR pszFullPath,
			[in] LPCOLESTR pszName,
			[in] DEVICE_TYPE dt,
			[in] WORD wArchitecture,
			[in] DWORD dwCPUType,
			[in] WORD wProcessorLevel,
			[in] DWORD dwPageSize,
			[in] WORD wMajorVersion,
			[in] WORD wMinorVersion,
			[in] DWORD dwLocaleId,
			[in] DWORD dwFlags,
			[in] GUID OSTypeId	
		);

		HRESULT AddPackageFile
		(
			[in] LPCOLESTR pszFullPath,
			[in] LPCOLESTR pszName,
			[in] PACKAGE_FILE_INFO2 pfi
		);       
			
		HRESULT DeleteFile
		(
			[in] LPCOLESTR pszFullPath,
			[in] LPCOLESTR pszName
		);

		HRESULT EnumFiles
		(
			[in] LPCOLESTR pszName, 
			[in] PACKAGE_FILE_INFO2 pfi,
			[out] IEnumPackageFiles2 **ppiEnumFiles
		);
	};

	[
		object,
		uuid(2A4F783D-014E-11D2-BBA0-00A0C9C9CCEE),
		helpstring("IEnumPackageFiles Interface"),
		pointer_default(unique)
	]
	interface IEnumPackageFiles : IUnknown
	{
		HRESULT Next
		(
			[in] ULONG celt,
			[out, size_is(celt), length_is(*pceltFetched)] LPOLESTR rgeltFullPath[],
			[out, size_is(celt), length_is(*pceltFetched)] LPOLESTR rgeltName[],
			[out, size_is(celt), length_is(*pceltFetched)] PACKAGE_FILE_INFO rgeltInfo[],
			[out] ULONG *pceltFetched
		);

		HRESULT Skip
		(
			[in] ULONG celt
		);

		HRESULT Reset
		(
		);

		HRESULT Clone
		(
			[out] IEnumPackageFiles **ppEnum
		);

		HRESULT GetCount
		(
			[out] ULONG *pcelt
		);

		HRESULT GetNext
		(
			[out] LPOLESTR *pszFullPath,
			[out] LPOLESTR *pszName,
			[out] PACKAGE_FILE_INFO *ppfi
		);
	};
	
	[
		object,
		uuid(BA5F16F6-F3A3-44E4-88F4-10E2B1E921F4),
		helpstring("IEnumPackageFiles2 Interface"),
		pointer_default(unique)
	]
	interface IEnumPackageFiles2 : IUnknown
	{
		HRESULT Next
		(
			[in] ULONG celt,
			[out, size_is(celt), length_is(*pceltFetched)] LPOLESTR rgeltFullPath[],
			[out, size_is(celt), length_is(*pceltFetched)] LPOLESTR rgeltName[],
			[out, size_is(celt), length_is(*pceltFetched)] PACKAGE_FILE_INFO2 rgeltInfo[],
			[out] ULONG *pceltFetched
		);

		HRESULT Skip
		(
			[in] ULONG celt
		);

		HRESULT Reset
		(
		);

		HRESULT Clone
		(
			[out] IEnumPackageFiles2 **ppEnum
		);

		HRESULT GetCount
		(
			[out] ULONG *pcelt
		);

		HRESULT GetNext
		(
			[out] LPOLESTR *pszFullPath,
			[out] LPOLESTR *pszName,
			[out] PACKAGE_FILE_INFO2 *ppfi
		);
	};
	

	[
		object,
		uuid(66B6C2DD-2590-11D2-BBA9-00A0C9C9CCEE),
		helpstring("IEnumCPU Interface"),
		pointer_default(unique)
	]
	interface IEnumCPU : IUnknown
	{
		HRESULT Next
		(
			[in] ULONG celt,
			[out, size_is(celt), length_is(*pceltFetched)] WORD rgeltArchitecture[],
			[out, size_is(celt), length_is(*pceltFetched)] DWORD rgeltCPUType[],
			[out, size_is(celt), length_is(*pceltFetched)] LPOLESTR rgetName[],
			[out] ULONG *pceltFetched
		);

		HRESULT Skip
		(
			[in] ULONG celt
		);

		HRESULT Reset
		(
		);

		HRESULT Clone
		(
			[out] IEnumCPU **ppEnum
		);

		HRESULT GetCount
		(
			[out] ULONG *pcelt
		);

		HRESULT GetNext
		(
			[out] LPWORD pwArchitecture,
			[out] LPDWORD pdwCPUType,
			[out] LPOLESTR *pszName
		);
	};


	//////////////////// NEW AUTOMATION INTERFACES/////////////////
	// The following interfaces were added to support automation in
	// platman 4.0.
	// 
	// All the objects which implement non-enumeration interfaces 
	// now implement these additional dual interfaces also.
	//	For example:
	//		CBootableDevice implements IBootableDevice and
	//		IBootableDeviceConfig
	//
	//		Now, CBootableDevice implements one additional dual
	//		interface IPMBootableDevice which is a wrapper for
	//		above two interfaces for automation clients (VB)
	//
	// All the objects which implement enumeration interfaces now
	// implement two additional interfaces. These two additional
	// interfaces are common to all enumeration objects as the
	// return types in these interfaces are all variants or array
	// of variants.
	//	For Example:
	//		CEnumBootableDevice implements IEnumBootableDevice
	//
	//		Now, CEnumBootableDevice also implements two new
	//		interfaces: IEnumVariant and IEnumVARIANT.
	//
	//		Both these interfaces are implemented by a new class
	//		CBaseCollection. Only one method in this class needs
	//		to be implemented (get_Item()) by any object which
	//		needs to provide enumeration and collections to the
	//		automation clients (VB).
	//
	//		With this change, now CEnumBootableDevice now inherits
	//		from CBaseCollection and implements (get_Item()) method.
	//
	//////////////////// NEW AUTOMATION INTERFACES/////////////////

	[
		object,
		uuid(EA720E9B-5C6D-4FBF-9352-A084866596A7),
		dual,
		helpstring("dual interface for IPlatformManager -- three IUnknown versions are combined into one dual interface"),
		pointer_default(unique)
	]
	interface IPMPlatformManager : IDispatch
	{		
		[id(1), helpstring("Enumeration of all platforms")]	
		HRESULT EnumPlatforms
		(
			[out, retval]  IEnumVariant **ppiEnumPlatform
		);

		[id(2), helpstring("Get a platform based on a GUID or a Name")]	
		HRESULT GetPlatform
		(
			[in] BSTR bstrPlatformIdOrName, 
			[out, retval] IPMPlatform **ppiPlatform
		);

		[id(3), helpstring("Add a new platform based on a optional GUID and a Name")]
		HRESULT AddPlatform
		(
			[in] BSTR bstrPlatformName,
			[in, defaultvalue("")] BSTR bstrPlatformId, 
			[out, retval] IPMPlatform **ppiPlatform
		);

		[id(4), helpstring("Delete a platform based on a GUID or a Name")]
		HRESULT DeletePlatform
		(
			[in] BSTR bstrPlatformIdOrName
		);

		[id(5), helpstring("Enumeration of all properties")]	
		HRESULT EnumProperties
		(
			[out, retval] IEnumVariant **ppiEnumProperty
		);

		[id(6), helpstring("Get a property based on a GUID")]	
		HRESULT GetProperty
		(
			[in] BSTR bstrPropId, 
			[out, retval] IPMProperty **ppiProperty
		);

		[id(7), helpstring("Add a new property based on a optional GUID and a LinkName")]	
		HRESULT AddProperty
		(
			[in] BSTR bstrLinkName,
			[in, defaultvalue("")] BSTR bstrPropId,
			[out, retval] IPMProperty **ppiProperty
		);

		[id(8), helpstring("Delete a property based on a GUID")]
		HRESULT DeleteProperty				   
		(
			[in] BSTR bstrPropId
		);
		
		[id(9), helpstring("Enumeration of all bootable devices")]	
		HRESULT EnumBootableDevices
		(
			[out, retval]  IEnumVariant **ppiEnumBootableDevice
		);

		[id(10), helpstring("Get a bootable device based on a GUID or a Name")]
		HRESULT GetBootableDevice
		(
			[in] BSTR bstrBootableDeviceIdOrName, 
			[out, retval] IPMBootableDevice **ppiBootableDevice
		);

		[id(11), helpstring("Add a new bootable device based on a optional GUID and a Name")]
		HRESULT AddBootableDevice
		(
			[in] BSTR bstrBootableDeviceName,
			[in, defaultvalue("")] BSTR bstrBootableDeviceId,
			[out, retval] IPMBootableDevice **ppiBootableDevice
		);

		[id(12), helpstring("Delete a bootable device based on a GUID or a Name")]
		HRESULT DeleteBootableDevice
		(
			[in] BSTR bstrBootableDeviceIdOrName
		);

		[id(13), helpstring("Enumeration of all service categories")]
		HRESULT EnumServiceCategories
		(
			[out, retval]  IEnumVariant **ppiEnumServiceCategory
		);

		[id(14), helpstring("Get a service category based on a GUID or a Name")]
		HRESULT GetServiceCategory
		(
			[in] BSTR bstrServiceCategoryIdOrName, 
			[out, retval] IPMServiceCategory **ppiServiceCategory
		);

		[id(15), helpstring("Add a service category based on a optional GUID and a Name")]
		HRESULT AddServiceCategory
		(
			[in] BSTR bstrServiceCategoryName,
			[in, defaultvalue("")] BSTR bstrServiceCategoryId,
			[out, retval] IPMServiceCategory **ppiServiceCategory
		);

		[id(16), helpstring("Delete a service category based on a GUID or a Name")]
		HRESULT DeleteServiceCategory
		(
			[in] BSTR bstrServiceCategoryIdOrName
		);

		[id(17), helpstring("Enumeration of all CPUs")]
		HRESULT EnumCPUs
		(
			[out, retval]  IEnumVariant **ppiEnumCPU
		);

		[id(18), helpstring("Get a CPU based on GUID or a Name")]
		HRESULT GetCPU
		(
			[in] BSTR bstrCPUIdOrName, 
			[out, retval] IPMCPU **ppiCPU
		);

		[id(19), helpstring("Add a new CPU")]
		HRESULT AddCPU
		(
			[in] BSTR bstrCPUName, 
			[in] long dwCpuNum,
			[in, defaultvalue(0)] int wArchitecture,
			[in, defaultvalue(0)] long dwCPUType,
			[in, defaultvalue("")] BSTR bstrCPUId,
			[in, optional] VARIANT vtPageSize,
			[in, optional] VARIANT vtLevel,
			[in, defaultvalue("")] BSTR bstrDefaultValue,
			[out, retval] IPMCPU **ppiCPU
		);

		[id(20), helpstring("Delete a CPU based on a GUID or a Name")]
		HRESULT DeleteCPU
		(
			[in] BSTR bstrCPUIdOrName
		);

		[id(21), helpstring("Enumeration of all OSs")]
		HRESULT EnumOSs
		(
			[out, retval]  IEnumVariant **ppiEnumOS
		);

		[id(22), helpstring("Get a OS based on a GUID or a Name")]
		HRESULT GetOS
		(
			[in] BSTR bstrOSIdOrName, 
			[out, retval] IPMOS **ppiOS
		);

		[id(23), helpstring("Add a new OS based on a optional GUID, name, major-minor versions and type GUID")]
		HRESULT AddOS
		(
			[in] BSTR bstrOSName,
			[in] int wMajorVersion,
			[in] int wMinorVersion,
			[in] BSTR bstrOSTypeId,
			[in, defaultvalue("")] BSTR bstrOSId,
			[out, retval] IPMOS **ppiOS
		);

		[id(24), helpstring("Delete a OS based on a GUID or a Name")]
		HRESULT DeleteOS
		(
			[in] BSTR bstrOSIdOrName
		);

		[id(25), helpstring("Enumeration of all Packages")]
		HRESULT EnumPackages
		(
			[out, retval]  IEnumVariant **ppiEnumPackage
		);

		[id(26), helpstring("Get a package based on a GUID or a Name")]
		HRESULT GetPackage
		(
			[in] BSTR bstrPackageIdOrName,
			[out, retval] IPMPackage **ppiPackage
		);

		[id(27), helpstring("Add a package based on a optional GUID and a Name")]
		HRESULT AddPackage
		(
			[in] BSTR bstrPackageName,
			[in, defaultvalue("")] BSTR bstrPackageId,
			[out, retval] IPMPackage **ppiPackage
		);

		[id(28), helpstring("Delete a package based on a GUID or a Name")]
		HRESULT DeletePackage
		(
			[in] BSTR bstrPackageIdOrName
		);

		[id(29), helpstring("Add a toolkit based on a optional GUID and a Name")]
		HRESULT AddToolkit
		(
			[in] BSTR bstrName,
			[in, defaultvalue("")] BSTR bstrToolkitId
		);

		[id(30), helpstring("Delete a toolkit based on a GUID or a Name")]
		HRESULT DeleteToolkit
		(
			[in] BSTR bstrToolkitIdOrName
		);

		[id(31), helpstring("Get the connection based on a GUID")]	
		HRESULT GetConnection
		(
			[in] BSTR bstrConnectId,
			[out, retval] IPMConnection **ppiConnection	
		);
		
		[id(32), helpstring("Get platman version")]
		HRESULT GetVersion
		(
			[out] VARIANT* pwMajorVersion,
			[out] VARIANT* pwMinorVersion,
			[out] VARIANT* pdwBuildNumber
		);

		[id(33), helpstring("Create and return a new GUID")]
		HRESULT CreateGUID
		(
			[out, retval] BSTR* pbstrNewGuid
		);

		[id(34), helpstring("Removes Platform Manager registry entries if there are no toolkits or platforms")]
		HRESULT CleanRegistry
		(
		);

		// A universal platform is a combination of a standard sdk and the TUSDK on which it
		// is based on; this enumeration returns a list of all platforms which support all
		// the installed TUSDKs. The platforms returned from this call use the headers and
		// libs from the TUSDK whereas rest of the platorm stuff is captured from the real
		// platform;
		[id(35), helpstring("Enumeration of all universal platforms")]	
		HRESULT EnumUniversalPlatforms
		(
			[out, retval]  IEnumVariant **ppiEnumUniversalPlatform
		);
	};

	// Automation version of IPlatformCE
	[
		object,
		uuid(5BA32507-0015-40A2-A0FE-AA81CB265FE1),
		dual,
		helpstring("IPMPlatform dual Interface"),
		pointer_default(unique)
	]
	interface IPMPlatform : IDispatch
	{
		[propget, id(1), helpstring("Get the Platform GUID")]
		HRESULT Id
		(
			[out, retval] BSTR *pbstrPlatformId
		);
		
		[propget, id(2), helpstring("Get the platform name")]
		HRESULT Name
		(
			[out, retval] BSTR *pbstrPlatformName
		);
		
		[propput, id(2), helpstring("Set the platform name")]
		HRESULT Name
		(
			[in] BSTR bstrPlatformName
		);

		[id(3), helpstring("Enumeration of properties")]
		HRESULT EnumProperties
		(
			[out, retval] IEnumVariant **ppiEnumProperty
		);

		[id(4), helpstring("Get a property based on a GUID")]
		HRESULT GetProperty
		(
			[in] BSTR bstrPropId,
			[out, retval] IPMProperty **ppiProperty
		);

		[id(5), helpstring("Add a property based on a optional GUID and a LinkName")]
		HRESULT AddProperty
		(
			[in] BSTR pszLinkName,
			[in, defaultvalue("")] BSTR bstrPropId,
			[out, retval] IPMProperty **ppiProperty
		);

		[id(6), helpstring("Delete a property based on a GUID")]
		HRESULT DeleteProperty
		(
			[in] BSTR bstrPropId
		);

		[id(7), helpstring("Enum all the devices within this platform")]
		HRESULT EnumDevices
		(
			[out, retval] IEnumVariant **ppiEnumDevice
		);
		
		[id(8), helpstring("Get a device based on a GUID or a Name")]
		HRESULT GetDevice
		(
			[in] BSTR bstrDeviceIdOrName,
			[out, retval] IPMRemoteDevice **ppiRemoteDevice
		);
		
		[id(9), helpstring("Add a device based on a optional GUID and a Name")]
		HRESULT AddDevice
		(
			[in] BSTR bstrName,
			[in, defaultvalue("")] BSTR bstrDeviceId,
			[out, retval] IPMRemoteDevice **ppiDevice
		);

		[id(10), helpstring("Delete a device based on a GUID or a Name")]
		HRESULT DeleteDevice
		(
			[in] BSTR bstrDeviceIdOrName
		);

		[id(11), helpstring("Enumeration of associated CPUs with this platform")]
		HRESULT EnumCPUs
		(
			[out, retval]  IEnumVariant **ppiEnumCPU
		);

		[id(12), helpstring("Get a CPU based on GUID or a Name")]
		HRESULT GetCPU
		(
			[in] BSTR bstrCPUIdOrName, 
			[out, retval] IPMCPU **ppiCPU
		);

		[id(13), helpstring("Associate an existing CPU with this platform")]
		HRESULT AddCPU
		(
			[in] BSTR bstrIdOrName,
			[out, retval] IPMCPU **ppiCPU
		);

		[id(14), helpstring("Delete an association of a CPU with this platform based on a GUID or a Name")]
		HRESULT DeleteCPU
		(
			[in] BSTR bstrCPUIdOrName
		);

		[id(15), helpstring("Get a OS based on a GUID or a Name")]
		HRESULT GetOS
		(
			[out, retval] IPMOS **ppiOS
		);

		[id(16), helpstring("Associate an existing OS with this platform")]
		HRESULT AddOS
		(
			[in] BSTR bstrIdOrName, 
			[out, retval] IPMOS **ppiOS
		);

		[id(17), helpstring("Delete an association of an OS with this platform")]
		HRESULT DeleteOS
		(
		);

		[id(18), helpstring("Enumeration of Packages")]
		HRESULT EnumPackages
		(
			[out, retval]  IEnumVariant **ppiEnumPackage
		);

		[id(19), helpstring("Get a package based on a GUID or a Name")]
		HRESULT GetPackage
		(
			[in] BSTR bstrPackageIdOrName,
			[out, retval] IPMPackage **ppiPackage
		);

		[id(20), helpstring("Add a new Package to this platform based on a optional GUID and a Name")]
		HRESULT AddPackage
		(
			[in] BSTR bstrPackageName,
			[in, defaultvalue("")] BSTR bstrPackageId,
			[out, retval] IPMPackage **ppiPackage
		);

		[id(21), helpstring("Delete a particular package based on a GUID or a Name")]
		HRESULT DeletePackage
		(
			[in] BSTR bstrPackageIdOrName
		);

		[id(22), helpstring("Enumeration of startup servers")]
		HRESULT EnumStartupServers
		(
			[out, retval] IEnumVariant **ppiEnumStartupServer
		);

		[id(23), helpstring("Get a startup server based on a GUID or a Name")]
		HRESULT GetStartupServer
		(
			[in] BSTR bstrStartupServerIdOrName,
			[out, retval] IPMStartupServerInfo **ppiStartupServer
		);

		[id(24), helpstring("Add a startup server to this platform based on a optional GUID, name, and default options")]
		HRESULT AddStartupServer
		(
			[in] BSTR bstrStartupServerId,
			[in, defaultvalue(TRUE)] VARIANT_BOOL bDefault,
			[out, retval] IPMStartupServerInfo** ppiStartupServer
		);

		[id(25), helpstring("Delete a particular startup server based on a GUID or a Name")]
		HRESULT DeleteStartupServer
		(
			[in] BSTR bstrStartupServerIdOrName
		);

		[id(26), helpstring("Enumeration of transports")]
		HRESULT EnumTransports
		(
			[out, retval] IEnumVariant **ppiEnumTransport
		);

		[id(27), helpstring("Get a transport for this platform based on a GUID or a Name")]
		HRESULT GetTransport
		(
			[in] BSTR bstrTransportIdOrName,
			[out, retval] IPMTransportInfo **ppiTransport
		);

		[id(28), helpstring("Add a Transport based on a optional GUID, name, and default options")]
		HRESULT AddTransport
		(
			[in] BSTR bstrTransportId,
			[in, defaultvalue(TRUE)] VARIANT_BOOL bDefault,
			[out, retval] IPMTransportInfo** ppiTransport
		);

		[id(29), helpstring("Delete a particular transport in this platform based on a GUID or a Name")]
		HRESULT DeleteTransport
		(
			[in] BSTR bstrTransportIdOrName
		);

		[id(30), helpstring("Get the major and minor version of the OS")]
		HRESULT GetOSInfo
		(
			[out] VARIANT* pwMajorVersion,
			[out] VARIANT* pwMinorVersion
		);

		[propget, id(31), helpstring("Get the corresponding universal sdk guid")]
		HRESULT UniversalSDK
		(
			[out, retval] BSTR *pbstrUniversalSDKGuid
		);
		
		[propput, id(31), helpstring("Set the corresponding universal sdk guid")]
		HRESULT UniversalSDK
		(
			[in] BSTR bstrUniversalSDKGuid
		);
		
		[propget, id(32), helpstring("Get the Remote Dbg Directory property value")]
		HRESULT RemoteDbgDirectory
		(
			[out, retval] BSTR *pbstrRemoteDbgDirectory
		);

	};

	// Automation version of IRemoteDevice
	[
		object,
		uuid(BCDAA3C8-E342-4DC0-A127-192780E4244B),
		dual,
		helpstring("IRemoteDevice dual Interface"),
		pointer_default(unique)
	]
	interface IPMRemoteDevice : IDispatch
	{
		[propget, id(1), helpstring("Get this device GUID")]
		HRESULT Id
		(
			[out, retval] BSTR *pbstrDeviceId
		);
				
		[propget, id(2), helpstring("Get this device name")]
		HRESULT Name
		(
			[out, retval] BSTR *pbstrDeviceName
		);
		
		[propput, id(2), helpstring("Set this device name")]		
		HRESULT Name
		(
			[in] BSTR bstrName
		);

		[propget, id(3), helpstring("Get startup server for this device")]
		HRESULT StartupServer
		(
			[out, retval] BSTR *pbstrStartupServerId
		);

		[propput, id(3), helpstring("Set startup server for this device")]
		HRESULT StartupServer
		(
			[in] BSTR bstrStartupServerId
		);

		[propget, id(4), helpstring("Get Transport for this device")]
		HRESULT Transport
		(
			[out, retval] BSTR *pbstrTransportId
		);

		[propput, id(4), helpstring("Set Transport for this device")]
		HRESULT Transport
		(
			[in] BSTR bstrTransportId
		);

		[id(5), helpstring("Enumeration of the properties")]
		HRESULT EnumProperties
		(
			[out, retval] IEnumVariant **ppiEnumProperty
		);

		[id(6), helpstring("Get a property based on a GUID")]
		HRESULT GetProperty
		(
			[in] BSTR bstrPropId,
			[out, retval] IPMProperty **ppiProperty
		);
		
		[id(7), helpstring("Add a property based on a optional GUID and a LinkName")]
		HRESULT AddProperty
		(
			[in] BSTR bstrLinkName,
			[in, defaultvalue("")] BSTR bstrPropId,
			[out, retval] IPMProperty **ppiProperty
		);
		
		[id(8), helpstring("Delete a property based on a GUID")]
		HRESULT DeleteProperty
		(
			[in] BSTR bstrPropId
		);
		
		[id(9), helpstring("Attach a connection to this device")]
		HRESULT Attach
		(
			[in] BSTR bstrProcessName,
			[in] long dwTimeOut,
			[in, optional] VARIANT vtProcessId,
			[out, retval] IPMConnection **ppiConnection
		);
		
		[id(10), helpstring("Get a connection for this device given a GUID")]
		HRESULT GetConnection
		(
			[in] BSTR bstrConnectId,
			[out, retval] IPMConnection **ppiConnection
		);

		[id(11), helpstring("Configure startup server")]
		HRESULT ConfigureStartupServer
		(
			[in, optional] VARIANT hWnd
		);

		[id(12), helpstring("Configure transport")]
		HRESULT ConfigureTransport
		(
			[in, optional] VARIANT hWnd
		);

		[propget, id(13), helpstring("Get Platform GUID corresponding to this device")]
		HRESULT Platform
		(
			[out, retval] IPMPlatform **ppiPlatform
		);

	};

	// Automation version of IProperty
	[
		object,
		uuid(D9956420-DF23-46E0-88E1-4E0D759E97DB),
		dual,
		helpstring("IProperty dual Interface"),
		pointer_default(unique)
	]
	interface IPMProperty : IDispatch
	{
		[propget, id(1), helpstring("Get a property id")]
		HRESULT Id
		(
			[out, retval] BSTR *pbstrPropId
		);

		[id(2), helpstring("Enumeration of the properties")]
		HRESULT EnumProperties
		(
			[out, retval] IEnumVariant **ppiEnumProperty
		);

		[id(3), helpstring("Get a property based on a GUID")]
		HRESULT GetProperty
		(
			[in] BSTR bstrPropId,
			[out, retval] IPMProperty **ppiProperty
		);
		
		[id(4), helpstring("Add a property based on a optional GUID and a LinkName")]
		HRESULT AddProperty
		(
			[in] BSTR bstrLinkName,
			[in, defaultvalue("")] BSTR bstrPropId,
			[out, retval] IPMProperty **ppiProperty
		);
		
		[id(5), helpstring("Delete a property based on a GUID")]
		HRESULT DeleteProperty
		(
			[in] BSTR bstrPropId
		);
		
		[id(6), helpstring("Enumeration of the properties info")]
		HRESULT EnumPropInfos
		(
			[out, retval] IEnumVariant **ppiEnumPropInfo
		);

		[id(7), helpstring("Get a property info object based on a Name")]
		HRESULT GetPropInfo
		(
			[in] BSTR bstrPropName,
			[out, retval] IPMPropInfo **ppiPropInfo
		);
		
		//
		//
		// dwPropInfoType can be one of the following values
		//
		/*
			(1) -- REG_SZ    // nul terminated string
			(4) -- REG_DWORD // 32-bit number
			Any other value translates to REG_BINARY
		*/

		[id(8), helpstring("Add a property info object based on a Name")]
		HRESULT AddPropInfo
		(
			[in] BSTR bstrPropInfoName,
			[in] long dwPropInfoType,
			[in] BSTR bstrPropInfoValue,
			[out, retval] IPMPropInfo **ppiPropInfo
		);
		
		[id(9), helpstring("Delete a property info object based on a Name")]
		HRESULT DeletePropInfo
		(
			[in] BSTR bstrPropInfoName
		);
	};

	// Automation version of IBootableDevice
	[
		object,
		uuid(6C8863F4-54B3-417E-83BF-2D63BFDDE437),
		dual,
		helpstring("IPMBootableDevice Interface"),
		pointer_default(unique)
	]
	interface IPMBootableDevice : IDispatch
	{
		[propget, id(1), helpstring("Get device GUID")]
		HRESULT Id
		(
			[out, retval] BSTR *pbstrBootableDeviceId
		);

		[propget, id(2), helpstring("Get device name")]
		HRESULT Name
		(
			[out, retval] BSTR *pbstrBootableDeviceName
		);
		
		[propput, id(2), helpstring("Set the bootable device name")]
		HRESULT Name
		(
			[in] BSTR bstrName
		);

		[id(3), helpstring("Get all device properties")]
		HRESULT EnumProperties
		(
			[out, retval] IEnumVariant **ppiEnumProperty
		);

		[id(4), helpstring("Get a property based on an GUID")]
		HRESULT GetProperty
		(
			[in] BSTR bstrPropId,
			[out, retval] IPMProperty **ppiProperty
		);

		[id(5), helpstring("Add a property based on a optional GUID and a Link Name")]
		HRESULT AddProperty
		(
			[in] BSTR bstrLinkName,
			[in, defaultvalue("")] BSTR bstrPropId,
			[out, retval] IPMProperty **ppiProperty
		);

		[id(6), helpstring("Delete a property based on a GUID")]
		HRESULT DeleteProperty
		(
			[in] BSTR bstrPropId
		);

		[id(7), helpstring("Get a service given a service category GUID or Name")]
		HRESULT GetService
		(
			[in] BSTR bstrServiceCategoryIdOrName,
			[out, retval] IPMService **ppiService
		);

		[id(8), helpstring("Add service info based on a service category GUID or a Name, and service class id")]
		HRESULT AddServiceInfo
		(
			[in] BSTR bstrServiceCategoryIdOrName,
			[in] BSTR bstrServiceCLSID
		);

		[id(9), helpstring("Delete a service based on a category GUID or a Name")]
		HRESULT DeleteService
		(
			[in] BSTR bstrServiceCategoryIdOrName
		);

		[id(10), helpstring("Delete all services associated with this device")]
		HRESULT Disconnect
		(
		);
	};

	// Automation version of IPackage & IPackage2
	[
		object,
		uuid(AF7FD18F-EC3E-4760-B1A7-EF9EC0B8D4D1),
		dual,
		helpstring("IPackage dual Interface"),
		pointer_default(unique)
	]
	interface IPMPackage : IDispatch
	{
		[propget, id(1), helpstring("Get package Id")]
		HRESULT Id
		(
			[out, retval] BSTR *pbstrPackageId
		);

		[propget, id(2), helpstring("Get package name")]
		HRESULT Name
		(
			[out, retval] BSTR* pbstrPackageName
		);

		[id(3), helpstring("Enumeration of files")]
		HRESULT EnumFiles
		(
			[out, retval] IEnumVariant **ppiEnumFiles
		);
		
		[id(4), helpstring("Get a file whose value is bstrFullPath and is listed under key bstrKeyName in registry")]
		HRESULT GetFile
		(
			[in] BSTR bstrFullPath,
			[in] BSTR bstrKeyName,
			[out, retval] IPMPackageFile** ppiPMPackageFile
		);

		[id(5), helpstring("Add a file to the package based on a full name of the file, name of the key, cpu info., os info., locale, and file flags")]
		HRESULT AddFile
		(
			[in] BSTR bstrFullPath,
			[in] BSTR bstrKeyName,
			[in] IPMCPU* piPMCPU,
			[in] IPMOS* piPMOS,
			[in] long dwLocaleId,
			[in] long dwFlags,
			[out, retval] IPMPackageFile** ppiPMPackageFile
		);

		[id(6), helpstring("Delete a file whose value if bstrFullPath and is listed under key bstrKeyName in registry")]
		HRESULT DeleteFile
		(
			[in] BSTR bstrFullPath,
			[in] BSTR bstrKeyName
		);

		[id(7), helpstring("Add multiple package files based on a path, filename")]
		HRESULT AddCPUFiles
		(
			[in] BSTR bstrFullPath,
			[in] BSTR bstrKeyName,
			[in, defaultvalue("")] BSTR bsOSIdOrName,
			[in, optional] VARIANT vtLocaleId,
			[in, optional] VARIANT vtFlags
		);
	};

	// Automation version of IService & IServiceConfig
	[
		object,
		uuid(CBC7337C-2A7C-4062-83A2-72C3E30C42BF),
		dual,
		helpstring("IPMService Interface"),
		pointer_default(unique)
	]
	interface IPMService : IDispatch
	{
		[propget, id(1), helpstring("Get service classid")]
		HRESULT Id
		(
			[out, retval] BSTR *pbstrServiceCLSID
		);
		
		[propget, id(2), helpstring("Get service name")]
		HRESULT Name
		(
			[out, retval] BSTR *pbstrName
		);
		
		[propput, id(2), helpstring("Set the service name")]
		HRESULT Name
		(
			[in] BSTR bstrName
		);

		[propget, id(3), helpstring("Get service category id")]
		HRESULT CategoryId
		(
			[out, retval] BSTR *pbstrServiceCategoryId
		);

		[id(4), helpstring("Initialize the service")]
		HRESULT InitService
		(
			[in] IPMBootableDevice *piBootableDevice,
			[in] IPMServiceInfo *piServiceInfo
		);
		
		[id(5), helpstring("Service can be released or not?")]
		HRESULT IsServiceReleaseable 
		(
			[out, retval] VARIANT_BOOL *pBool
		);
		
		[id(6), helpstring("Configure service UI")]
		HRESULT ConfigureServiceUI
		(
			[in] IPMBootableDevice *piDevice,
			[in] IPMServiceInfo *piServiceInfo, 
			[in, optional] VARIANT hWnd
		);
	};

	// Automation version of IServiceInfo & IserviceInfoConfig
	[
		object,
		uuid(184E566E-2134-4EA6-B298-F177DAC489DE),
		dual,
		helpstring("IPMServiceInfo Interface"),
		pointer_default(unique)
	]
	interface IPMServiceInfo : IDispatch
	{
		[propget, id(1), helpstring("Get service class id")]
		HRESULT Id
		(
			[out, retval] BSTR *pbstrServiceCLSID
		);

		[propget, id(2), helpstring("Get service info name")]
		HRESULT Name
		(
			[out, retval] BSTR *pbstrServiceInfoName
		);
		[propput, id(2), helpstring("Set service info name")]
		HRESULT Name
		(
			[in] BSTR bstrServiceInfoName
		);

		[id(3), helpstring("Get the enumeration of properties")]
		HRESULT EnumProperties
		(
			[out, retval] IEnumVariant **ppiEnumProperty
		);

		[id(4), helpstring("Get a property based on GUID")]
		HRESULT GetProperty
		(
			[in] BSTR bstrPropId,
			[out, retval] IPMProperty **ppiProperty
		);

		[id(5), helpstring("Add a property based on a optional GUID and a Link Name")]
		HRESULT AddProperty
		(
			[in] BSTR bstrLinkName,
			[in, defaultvalue("")] BSTR bstrPropId,
			[out, retval] IPMProperty **ppiProperty
		);

		[id(6), helpstring("Delete a property based on a GUID")]
		HRESULT DeleteProperty
		(
			[in] BSTR bstrPropId
		);

	};

	// Automation version of IServiceCategory & IServiceCategoryConfig
	[
		object,
		uuid(2E8C4F4D-BEFE-4FC0-81D5-E7311417843C),
		dual,
		helpstring("IServiceCategory dual Interface"),
		pointer_default(unique)
	]
	interface IPMServiceCategory : IDispatch
	{
		[propget, id(1), helpstring("Get service category GUID")]
		HRESULT Id
		(
			[out, retval] BSTR *pbstrServiceCategoryId
		);

		[propget, id(2), helpstring("Get service category name")]
		HRESULT Name
		(
			[out, retval] BSTR *pbstrServiceCategoryName
		);
		
		[propput, id(2), helpstring("Set service category name")]
		HRESULT Name
		(
			[in] BSTR bstrServiceCategoryName
		);

		[id(3), helpstring("Enumerate the service info objects")]
		HRESULT EnumServiceInfos
		(
			[out, retval] IEnumVariant **ppiEnumServiceInfo
		);

		[id(4), helpstring("Get service info based on a service GUID or a Name")]
		HRESULT GetServiceInfo
		(
			[in] BSTR bstrServiceIdOrName,
			[out, retval] IPMServiceInfo **ppiServiceInfo
		);

		[id(5), helpstring("Add service info based on a service GUID and a Name")]
		HRESULT AddServiceInfo
		(
			[in] BSTR bstrServiceCLSID,
			[in] BSTR bstrServiceName,
			[out, retval] IPMServiceInfo **ppiServiceInfo
		);

		[id(6), helpstring("Delete a service info based on a GUID or a Name")]
		HRESULT DeleteServiceInfo
		(
			[in] BSTR bstrServiceIdOrName
		);

		[id(7), helpstring("Enumerate of properties within service category")]
		HRESULT EnumProperties
		(
			[out, retval] IEnumVariant **ppiEnumProperty
		);

		[id(8), helpstring("Get a property based on a GUID")]
		HRESULT GetProperty
		(
			[in] BSTR bstrPropId,
			[out, retval] IPMProperty **ppiProperty
		);
		
		[id(9), helpstring("Add a property based on a optional GUID and a Link Name")]
		HRESULT AddProperty
		(
			[in] BSTR bstrLinkName,
			[in, defaultvalue("")] BSTR bstrPropId,
			[out, retval] IPMProperty **ppiProperty
		);

		[id(10), helpstring("Delete a property based on a GUID")]
		HRESULT DeleteProperty
		(
			[in] BSTR bstrPropId
		);
	};

	// Automation version of IConnectionStream
	[
		object,
		uuid(C41E4F72-6B73-4556-98EA-D86570745DDB),
		dual,
		helpstring("IConnectionStream dual Interface"),
		pointer_default(unique)
	]
	interface IPMConnectionStream : IDispatch
	{
		[id(1), helpstring("Send a byte array")]
		HRESULT Send
		(
			[in] long dwSize,
			[in] VARIANT vtArray, //BYTE *pBuffer is stored as VARIANT,
			[out, retval] long* pdwSizeSent
		);

		[id(2), helpstring("Receive from the stream and return the number of bytes received")]
		HRESULT Receive
		(
			[out, retval] long* pdwBytesReceived
		);

		[id(3), helpstring("Read bytes from the stream")]
		HRESULT ReadBytes
		(
			[in] long dwSize,
			[out] VARIANT* pvtArray, //BYTE *pBuffer is stored as VARIANT,
			[out, retval] long* pdwSizeRecv
		);

		[id(4), helpstring("Close the connection")]
		HRESULT Close
		(
		);
	};

	// Automation version of IConnection & IConnectionConfig
	[
		object,
		uuid(A887B5D6-A18E-41FB-BFC5-B6ABB419A3D3),
		dual,
		helpstring("IConnection dual Interface"),
		pointer_default(unique)
	]
	interface IPMConnection : IDispatch
	{
		[propget, id(1), helpstring("Get connection GUID")]
		HRESULT Id
		(
			[out, retval] BSTR *pbstrConnectId
		);

		[propget, id(2), helpstring("Get platform GUID")]
		HRESULT PlatformId
		(
			[out, retval] BSTR *pbstrPlatformId
		);

		[propget, id(3), helpstring("Get locale info")]
		HRESULT LocaleId
		(
			[out, retval] long* pdwLocaleId
		);

		[id(4), helpstring("Copy a file")]
		HRESULT FileCopy
		(
			[in] BSTR bstrSource,
			[in] BSTR bstrDest,
			[in] VARIANT_BOOL bOverWrite,
			[out, retval] long* pdwTotalSize
		);

		[id(5), helpstring("Get a single file size")]
		HRESULT GetFile
		(
			[in] BSTR bstrRemotePath,
			[in] BSTR bstrDest,
			[out, retval] long* pdwTotalSize
		);

		[id(6), helpstring("Get file info")]
		HRESULT FileGetInfo
		(
			[in] BSTR bstrRemotePath,
			[out] long* pdwFileAttributes,
			[out] long* pdwFileSize,
			[out] VARIANT* pvtCreationTime// for FILETIME structure
		);

		[id(7), helpstring("Delete a file")]
		HRESULT FileDelete
		(
			[in] BSTR bstrFullPath
		);

		[id(8), helpstring("Queue a file")]
		HRESULT QueueFile
		(
			[in] BSTR bstrSource,
			[in] BSTR bstrDest,
			[in] VARIANT_BOOL bOverWrite
		);

		[id(9), helpstring("Copy Queued files")]
		HRESULT CopyQueuedFiles
		(
			[out, retval] long* pdwTotalSize
		);

		[id(10), helpstring("Copy a Package based on a GUID")]
		HRESULT CopyPackage
		(
			[in] BSTR bstrPackageId,
			[in] BSTR bstrDestPath,
			[in] VARIANT_BOOL bOverWrite,
			[out, retval] long* pdwTotalSize
		);

		[id(11), helpstring("Queue a Package")]
		HRESULT QueuePackage
		(
			[in] BSTR bstrPackageId,
			[in] BSTR bstrDestPath,
			[in] VARIANT_BOOL bOverWrite
		);

		[id(12), helpstring("Get queue count")]
		HRESULT GetQueueCount
		(
			[out, retval] long* pdwCount
		);
		
		[id(13), helpstring("Reset queue")]
		HRESULT ResetQueue
		(
		);

		[id(14), helpstring("Create a stream")]
		HRESULT CreateStream
		(
			[in] BSTR bstrHostId,
			[in] long dwPortId,
			[out, retval] IPMConnectionStream **ppiConnectionStream
		);

		[id(15), helpstring("Close all streams")]
		HRESULT CloseAllStreams
		(
		);

		[id(16), helpstring("Launch")]
		HRESULT Launch
		(
			[in] BSTR bstrRemotePath,
			[in] BSTR bstrCmdLine
		);

		[id(17), helpstring("Get System info")]
		HRESULT SystemGetInfo
		(
			[out] VARIANT* pwArchitecture,
			[out] VARIANT* pdwCPUType,
			[out] VARIANT* pdwPageSize,
			[out] VARIANT* pwMajorVersion,
			[out] VARIANT* pwMinorVersion,
			[out] VARIANT* bstrOSTypeId
		);
        [id(18), helpstring("Get System info")]
        HRESULT GetSystemInfo
        (
            [out] IPMCPU ** piCpu,
            [out] IPMOS  ** piOs
        );
	};

	// Automation interface of CPU information
	[
		object,
		uuid(D32ACC9F-D772-41AA-9D5A-AC11AD5154B9),
		dual,
		helpstring("IPMCPU dual Interface"),
		pointer_default(unique)
	]
	interface IPMCPU : IDispatch
	{
		[propget, id(1), helpstring("CPU architecture")]
		HRESULT Id
		(
			[out, retval] BSTR *pbstrGuid
		);

		[propget, id(2), helpstring("CPU type")]
		HRESULT Name
		(
			[out, retval] BSTR *pbstrName
		);

		[propput, id(2), helpstring("CPU type")]
		HRESULT Name
		(
			[in] BSTR bstrName
		);

		[propget, id(3), helpstring("CPU architecture")]
		HRESULT Architecture
		(
			[out, retval] int *pwArchitecture
		);

		[propput, id(3), helpstring("CPU architecture")]
		HRESULT Architecture
		(
			[in] int wArchitecture
		);

		[propget, id(4), helpstring("CPU type")]
		HRESULT Type
		(
			[out, retval] long *pdwType
		);

		[propput, id(4), helpstring("CPU type")]
		HRESULT Type
		(
			[in] long dwType
		);

		[propget, id(5), helpstring("Default Page size")]
		HRESULT PageSize
		(
			[out, retval] long *pdwPageSize
		);

		[propput, id(5), helpstring("Default Page size")]
		HRESULT PageSize
		(
			[in] long dwPageSize
		);
		
		[propget, id(6), helpstring("Processor level")]
		HRESULT Level
		(
			[out, retval] long *pdwLevel
		);

		[propput, id(6), helpstring("Processor level")]
		HRESULT Level
		(
			[in] long dwLevel
		);

		[propget, id(7), helpstring("CPU Default unnamed value")]
		HRESULT DefaultValue
		(
			[out, retval] BSTR *pbstrName
		);

		[propput, id(7), helpstring("CPU Default unnamed value")]
		HRESULT DefaultValue
		(
			[in] BSTR bstrName
		);
        [propget, id(8), helpstring("CPU number")]
        HRESULT CpuNum
        (
            [out, retval] long *pdwNum
        );

        [propput, id(8), helpstring("CPU number")]
        HRESULT CpuNum
        (
            [in] long dwNum
        );
	};

	// Automation interface of OS information
	[
		object,
		uuid(57E91F66-D7C4-41BD-A4A9-C28060D00C57),
		dual,
		helpstring("IPMOS dual Interface"),
		pointer_default(unique)
	]
	interface IPMOS : IDispatch
	{
		[propget, id(1), helpstring("OS GUIId")]
		HRESULT Id
		(
			[out, retval] BSTR *pbstrGuid
		);

		[propget, id(2), helpstring("OS Name")]
		HRESULT Name
		(
			[out, retval] BSTR *pbstrName
		);

		[propput, id(2), helpstring("OS Name")]
		HRESULT Name
		(
			[in] BSTR bstrName
		);

		[propget, id(3), helpstring("OS Major version")]
		HRESULT MajorVersion
		(
			[out, retval] int *pwMajor
		);

		[propput, id(3), helpstring("OS Major version")]
		HRESULT MajorVersion
		(
			[in] int wMajor
		);

		[propget, id(4), helpstring("OS Minor version")]
		HRESULT MinorVersion
		(
			[out, retval] int *pwMinor
		);

		[propput, id(4), helpstring("OS Minor version")]
		HRESULT MinorVersion
		(
			[in] int wMinor
		);

		[propget, id(5), helpstring("OS Type GUID")]
		HRESULT TypeId
		(
			[out, retval] BSTR *pbstrTypeId
		);

		[propput, id(5), helpstring("OS Type GUID")]
		HRESULT TypeId
		(
			[in] BSTR bstrTypeId
		);
	};

	// Automation interface of Startup Server
	[
		object,
		uuid(A8FA6E12-2D8C-46B7-A25D-64C04FA69214),
		dual,
		helpstring("IPMStartupServerInfo dual Interface"),
		pointer_default(unique)
	]
	interface IPMStartupServerInfo : IDispatch
	{
		[propget, id(1), helpstring("StartupServer GUId")]
		HRESULT Id
		(
			[out, retval] BSTR *pbstrGuid
		);

		[propget, id(2), helpstring("StartupServer Value")]
		HRESULT Name
		(
			[out, retval] BSTR *pbstrValue
		);
	};

	// Automation interface of Transport
	[
		object,
		uuid(0761A737-372D-4020-800A-B52CCD06D25D),
		dual,
		helpstring("IPMTransportInfo dual Interface"),
		pointer_default(unique)
	]
	interface IPMTransportInfo : IDispatch
	{
		[propget, id(1), helpstring("Transport GUId")]
		HRESULT Id
		(
			[out, retval] BSTR *pbstrGuid
		);

		[propget, id(2), helpstring("Transport Value")]
		HRESULT Name
		(
			[out, retval] BSTR *pbstrValue
		);
	};

	// Automation interface of IPMPropInfo object(new)
	[
		object,
		uuid(F7B2D7E0-44B5-4715-A156-A5B3B42D7D5A),
		dual,
		helpstring("IPMPropInfo dual Interface"),
		pointer_default(unique)
	]
	interface IPMPropInfo : IDispatch
	{
		[propget, id(1), helpstring("PropInfo Name")]
		HRESULT Name
		(
			[out, retval] BSTR *pbstrName
		);

		[propput, id(1), helpstring("PropInfo Name")]
		HRESULT Name
		(
			[in] BSTR bstrName
		);

		[propget, id(2), helpstring("PropInfo type")]
		HRESULT Type
		(
			[out, retval] long *pdwType
		);

		[propput, id(2), helpstring("Propinfo type")]
		HRESULT Type
		(
			[in] long dwType
		);

		[propget, id(3), helpstring("PropInfo value")]
		HRESULT Value
		(
			[out, retval] VARIANT *pdwValue // could be string, dword, or BYTE* depending on type
		);

		[propput, id(3), helpstring("PropInfo value")]
		HRESULT Value
		(
			[in] BSTR bstrValue
		);
	};

	// Automation interface of IPMPackageFile object(new)
	[
		object,
		uuid(93BD6B7A-4340-45FF-B062-A4187BBB8D0B),
		dual,
		helpstring("IPMPackageFile dual Interface"),
		pointer_default(unique)
	]
	interface IPMPackageFile : IDispatch
	{
		[propget, id(1), helpstring("IPMPackageFile FileName")]
		HRESULT Name
		(
			[out, retval] BSTR *pbstrFileName
		);
	
		[propget, id(2), helpstring("IPMPackageFile Locale")]
		HRESULT Locale
		(
			[out, retval] long *pdwLocale
		);
	
		[propget, id(3), helpstring("IPMPackageFile Flags")]
		HRESULT Flags
		(
			[out, retval] long *pdwFlags
		);

		[propget, id(4), helpstring("IPMPackageFile registry key Name")]
		HRESULT KeyName
		(
			[out, retval] BSTR *pbstrName
		);
		[propget, id(5), helpstring("OS Major version")]
		HRESULT MajorVersion
		(
			[out, retval] int *pwMajor
		);

		[propget, id(6), helpstring("OS Minor version")]
		HRESULT MinorVersion
		(
			[out, retval] int *pwMinor
		);

		[propget, id(7), helpstring("OS Type GUID")]
		HRESULT TypeId
		(
			[out, retval] BSTR *pbstrTypeId
		);

		[propget, id(8), helpstring("CPU architecture")]
		HRESULT Architecture
		(
			[out, retval] int *pwArchitecture
		);

		[propget, id(9), helpstring("CPU type")]
		HRESULT Type
		(
			[out, retval] long *pdwType
		);

		[propget, id(10), helpstring("Default Page size")]
		HRESULT PageSize
		(
			[out, retval] long *pdwPageSize
		);
		
		[propget, id(11), helpstring("Processor level")]
		HRESULT Level
		(
			[out, retval] long *pdwLevel
		);
        [propget, id(12), helpstring("CPU number")]
        HRESULT CpuNum
        (
            [out, retval] long *pdwCpuNum
        );
	};

	// Automation version of all the enumeration interfaces
	[
		object,
		uuid(AF8278EC-A3C4-44B3-85B3-6B8CF9BC7237),
		dual,
		helpstring("IEnumVariant dual Interface"),
		pointer_default(unique)
	]
	interface IEnumVariant : IDispatch
	{
		[propget, restricted, id(DISPID_NEWENUM), helpstring("used in for each construct in vb")]
		HRESULT _NewEnum
		(
			[out, retval] IUnknown **pUnk
		);

		[propget, id(0), helpstring("default property of item")]
		HRESULT Item
		(
			[in] long Index,
			[out, retval] VARIANT *pVariant
		);

		[propget, id(1), helpstring("count of number of items")]
		HRESULT Count
		(
			[out, retval] long *pVal
		);
	};

	[
		object,
		uuid(B293E1A7-B804-498e-8597-B9105C58C371),
		helpstring("IClientInfo Interface"),
		pointer_default(unique)
	]
	interface IClientInfo : IUnknown
	{
		HRESULT SetClientProcessId([in] DWORD dwPid);
	};

