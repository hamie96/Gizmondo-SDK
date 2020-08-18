#ifndef _CELOGGER_H
#define _CELOGGER_H

#ifdef CELOGGER_EXPORTS
#define CELOGGER_API __declspec(dllexport)
#else
#define CELOGGER_API __declspec(dllimport)
#endif

#define CELOGGER_MAXMSG_SIZE    1000

enum CELOGLEVEL
{
	CELOG_OFF = 0,
	CELOG_ERRORS,
	CELOG_DETAILS,
	CELOG_VERBOSE,
};

class CCeLogEngineImpl;

CELOGGER_API CCeLogEngineImpl * CreateLogEngine();

const WCHAR EVENT_REGKEY[]= {L"SYSTEM\\CurrentControlSet\\Services\\EventLog\\"};
const WCHAR EVENT_SUBKEY[]= {L"WinCe Log"};
const WCHAR LOG_ROOT[]={L"SOFTWARE\\Microsoft\\Windows CE Tools\\Logging"};
const WCHAR DLLPATH[]={L"DLLPath"};
const WCHAR FILEPATH[]={L"FilePath"};

// This class is for resolving linker problems
class CELOGGER_API CCeLogEngine
{
public:
	CCeLogEngine(void){}
	virtual ~CCeLogEngine(){}

	//methods
	virtual HRESULT Open(WCHAR *filename) = 0;
	virtual HRESULT Close() = 0;
	virtual HRESULT LoadFromRegistry(DWORD hkey, const WCHAR *subkey) = 0;
	virtual HRESULT Write(enum CELOGLEVEL level,const WCHAR *text) = 0;
	virtual HRESULT WriteEx(const WCHAR *source, enum CELOGLEVEL level, const WCHAR *text) = 0;

	//properties
	virtual HRESULT get_level(CELOGLEVEL *pVal) = 0;
	virtual HRESULT put_level(CELOGLEVEL newVal) = 0;
};

// This class is exported from the celogger.dll
class CELOGGER_API CCeLogEngineImpl : public CCeLogEngine
{
public:
	CCeLogEngineImpl(void);
	virtual ~CCeLogEngineImpl();

	//methods
	virtual HRESULT Open(WCHAR *filename);
	virtual HRESULT Close();
	virtual HRESULT LoadFromRegistry(DWORD hkey, const WCHAR *subkey);
	virtual HRESULT Write(enum CELOGLEVEL level,const WCHAR *text);
	virtual HRESULT WriteEx(const WCHAR *source, enum CELOGLEVEL level, const WCHAR *text);

	//properties
	virtual HRESULT get_level(CELOGLEVEL *pVal);
	virtual HRESULT put_level(CELOGLEVEL newVal);

private:
	CELOGLEVEL m_loggingLevel;
	HANDLE m_eventSource;
	HANDLE m_mutex;
	CRITICAL_SECTION m_cs;
	BOOL m_bLogToFile;
	WCHAR m_szLogFile[MAX_PATH];
	WCHAR m_szFileName[MAX_PATH];

	void Lock();		// single process
	void Unlock();
	BOOL HeavyLock();	// cross process
	void HeavyUnlock();

	HRESULT RegisterLog(WCHAR * subkey, WCHAR * dllpath);
	HRESULT Unregister();
	HRESULT RegisterEventSource(WCHAR * subkey);
	HRESULT LogStringEvent(DWORD eventID,const WCHAR ** msg, WORD type);
	HRESULT CreateEventSource(WCHAR * subkey);
	HRESULT GetDLLPath(WCHAR *path, DWORD length);
	HRESULT GetFilePath(WCHAR *path, DWORD length);

	HRESULT OpenLogFile();
	void CloseLogFile();
	HRESULT WriteToFile(const WCHAR *text);
};

#endif
