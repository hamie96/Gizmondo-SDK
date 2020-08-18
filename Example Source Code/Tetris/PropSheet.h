#ifndef __PROPSHEET_H
#define __PROPSHEET_H

  #ifndef LongToHandle
#define LongToHandle( h) ((HANDLE)(LONG_PTR) (h))
  #endif

class _U_RECT
{
public:
	_U_RECT(LPRECT lpRect) : m_lpRect(lpRect)
	{ }
	_U_RECT(RECT& rc) : m_lpRect(&rc)
	{ }
	LPRECT m_lpRect;
};

class _U_MENUorID
{
public:
	_U_MENUorID(HMENU hMenu) : m_hMenu(hMenu)
	{ }
	_U_MENUorID(UINT nID) : m_hMenu((HMENU)LongToHandle(nID))
	{ }
	HMENU m_hMenu;
};

class _U_STRINGorID
{
public:
	_U_STRINGorID(LPCTSTR lpString) : m_lpstr(lpString)
	{ }
	_U_STRINGorID(UINT nID) : m_lpstr(MAKEINTRESOURCE(nID))
	{ }
	LPCTSTR m_lpstr;
};

class CPropertySheetWindow : public CWindow
{
public:
// Constructors
	CPropertySheetWindow(HWND hWnd = NULL) : CWindow(hWnd) { }

	CPropertySheetWindow& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

// Attributes
	int GetPageCount() const
	{
		ATLASSERT(::IsWindow(m_hWnd));
		HWND hWndTabCtrl = GetTabControl();
		ATLASSERT(hWndTabCtrl != NULL);
		return (int)::SendMessage(hWndTabCtrl, TCM_GETITEMCOUNT, 0, 0L);
	}
	HWND GetActivePage() const
	{
		ATLASSERT(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, PSM_GETCURRENTPAGEHWND, 0, 0L);
	}
	int GetActiveIndex() const
	{
		ATLASSERT(::IsWindow(m_hWnd));
		HWND hWndTabCtrl = GetTabControl();
		ATLASSERT(hWndTabCtrl != NULL);
		return (int)::SendMessage(hWndTabCtrl, TCM_GETCURSEL, 0, 0L);
	}
	BOOL SetActivePage(int nPageIndex)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, PSM_SETCURSEL, nPageIndex, 0L);
	}
	BOOL SetActivePage(HPROPSHEETPAGE hPage)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		ATLASSERT(hPage != NULL);
		return (BOOL)::SendMessage(m_hWnd, PSM_SETCURSEL, 0, (LPARAM)hPage);
	}
	BOOL SetActivePageByID(int nPageID)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, PSM_SETCURSELID, 0, nPageID);
	}
	void SetTitle(LPCTSTR lpszText, UINT nStyle = 0)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		ATLASSERT((nStyle & ~PSH_PROPTITLE) == 0); // only PSH_PROPTITLE is valid
		ATLASSERT(lpszText != NULL);
		::SendMessage(m_hWnd, PSM_SETTITLE, nStyle, (LPARAM)lpszText);
	}
	HWND GetTabControl() const
	{
		ATLASSERT(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, PSM_GETTABCONTROL, 0, 0L);
	}
	void SetFinishText(LPCTSTR lpszText)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, PSM_SETFINISHTEXT, 0, (LPARAM)lpszText);
	}
	void SetWizardButtons(DWORD dwFlags)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		::PostMessage(m_hWnd, PSM_SETWIZBUTTONS, 0, dwFlags);
	}

// Operations
	void AddPage(HPROPSHEETPAGE hPage)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		ATLASSERT(hPage != NULL);
		::SendMessage(m_hWnd, PSM_ADDPAGE, 0, (LPARAM)hPage);
	}
	BOOL AddPage(LPCPROPSHEETPAGE pPage)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		ATLASSERT(pPage != NULL);
		HPROPSHEETPAGE hPage = ::CreatePropertySheetPage(pPage);
		if(hPage == NULL)
			return FALSE;
		::SendMessage(m_hWnd, PSM_ADDPAGE, 0, (LPARAM)hPage);
		return TRUE;
	}
	void RemovePage(int nPageIndex)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, PSM_REMOVEPAGE, nPageIndex, 0L);
	}
	void RemovePage(HPROPSHEETPAGE hPage)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		ATLASSERT(hPage != NULL);
		::SendMessage(m_hWnd, PSM_REMOVEPAGE, 0, (LPARAM)hPage);
	}
	BOOL PressButton(int nButton)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, PSM_PRESSBUTTON, nButton, 0L);
	}
	BOOL Apply()
	{
		ATLASSERT(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, PSM_APPLY, 0, 0L);
	}
	void CancelToClose()
	{
		ATLASSERT(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, PSM_CANCELTOCLOSE, 0, 0L);
	}
	void SetModified(HWND hWndPage, BOOL bChanged = TRUE)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		ATLASSERT(::IsWindow(hWndPage));
		UINT uMsg = bChanged ? PSM_CHANGED : PSM_UNCHANGED;
		::SendMessage(m_hWnd, uMsg, (WPARAM)hWndPage, 0L);
	}
	LRESULT QuerySiblings(WPARAM wParam, LPARAM lParam)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, PSM_QUERYSIBLINGS, wParam, lParam);
	}
	void RebootSystem()
	{
		ATLASSERT(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, PSM_REBOOTSYSTEM, 0, 0L);
	}
	void RestartWindows()
	{
		ATLASSERT(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, PSM_RESTARTWINDOWS, 0, 0L);
	}
	BOOL IsDialogMessage(LPMSG lpMsg)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, PSM_ISDIALOGMESSAGE, 0, (LPARAM)lpMsg);
	}

// Implementation - override to prevent usage
	HWND Create(LPCTSTR, HWND, _U_RECT = NULL, LPCTSTR = NULL, DWORD = 0, DWORD = 0, _U_MENUorID = 0U, LPVOID = NULL)
	{
		ATLASSERT(FALSE);
		return NULL;
	}
};

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetImpl - implements a property sheet

template <class T, class TBase = CPropertySheetWindow>
class ATL_NO_VTABLE CPropertySheetImpl : public CWindowImplBaseT< TBase >
{
public:
	PROPSHEETHEADER m_psh;
	CSimpleArray<HPROPSHEETPAGE> m_arrPages;

// Construction/Destruction
	CPropertySheetImpl(_U_STRINGorID title = (LPCTSTR)NULL, UINT uStartPage = 0, HWND hWndParent = NULL)
	{
		memset(&m_psh, 0, sizeof(PROPSHEETHEADER));
		m_psh.dwSize = sizeof(PROPSHEETHEADER);
		m_psh.dwFlags = PSH_USECALLBACK | PSH_MAXIMIZE;
		m_psh.hInstance = _Module.GetResourceInstance();
		m_psh.phpage = NULL;	// will be set later
		m_psh.nPages = 0;	// will be set later
		m_psh.pszCaption = title.m_lpstr;
		m_psh.nStartPage = uStartPage;
		m_psh.hwndParent = hWndParent;	// if NULL, will be set in DoModal/Create
		m_psh.pfnCallback = T::PropSheetCallback;
	}

	~CPropertySheetImpl()
	{
		if(m_arrPages.GetSize() > 0)	// sheet never created, destroy all pages
		{
			for(int i = 0; i < m_arrPages.GetSize(); i++)
				::DestroyPropertySheetPage((HPROPSHEETPAGE)m_arrPages[i]);
		}
	}

	static int CALLBACK PropSheetCallback(HWND hWnd, UINT uMsg, LPARAM)
	{
		switch (uMsg) 
		{
		case PSCB_INITIALIZED:
			{
				ATLASSERT(hWnd != NULL);
				CPropertySheetImpl< T, TBase >* pT = (CPropertySheetImpl< T, TBase >*)_Module.ExtractCreateWndData();
				// subclass the sheet window
				pT->SubclassWindow(hWnd);
				// remove page handles array
				pT->m_psh.nPages = 0;
				pT->m_psh.phpage = NULL;
				pT->m_arrPages.RemoveAll();

				HWND hWndTab = PropSheet_GetTabControl(hWnd);
				DWORD dwStyle = ::GetWindowLong(hWndTab, GWL_STYLE) | TCS_BOTTOM;
				::SetWindowLong(hWndTab, GWL_STYLE, dwStyle);

				// make the property sheet fullscreen (added by RdK)
				SHINITDLGINFO shidi = {0};
				shidi.dwMask  = SHIDIM_FLAGS;
				shidi.dwFlags = SHIDIF_DONEBUTTON | SHIDIF_SIPDOWN | SHIDIF_SIZEDLG;
				shidi.hDlg    = hWnd;
				if (!::SHInitDialog(&shidi))
				{
					DWORD dwError = GetLastError();
					ATLTRACE(_T("Warning: Making Fullscreen propertysheet failed during propertysheet init. Error # %d\n"),dwError);				
				}

				// Create the menu bar
				SHMENUBARINFO mbi = {0};
				mbi.cbSize     = sizeof(SHMENUBARINFO);
				mbi.hwndParent = pT->m_hWnd;
				mbi.dwFlags    = SHCMBF_EMPTYBAR | SHCMBF_HIDESIPBUTTON;
				if (!::SHCreateMenuBar(&mbi)) 
					return -1;

				// Save the control bar
				pT->m_hWndCB = mbi.hwndMB;
			}
			break;

		case PSCB_GETVERSION:
			return COMCTL32_VERSION;
		}
		
		return 0;
	}

	HWND Create(HWND hWndParent = NULL)
	{
		ATLASSERT(m_hWnd == NULL);

		m_psh.dwFlags |= PSH_MODELESS;
		if(m_psh.hwndParent == NULL)
			m_psh.hwndParent = hWndParent;
		m_psh.phpage = (HPROPSHEETPAGE*)m_arrPages.GetData();
		m_psh.nPages = m_arrPages.GetSize();

		_Module.AddCreateWndData(&m_thunk.cd, (CPropertySheetImpl< T, TBase >*)this);

		HWND hWnd = (HWND)::PropertySheet(&m_psh);

		ATLASSERT(m_hWnd == hWnd);

		return hWnd;
	}

	INT_PTR DoModal(HWND hWndParent = ::GetActiveWindow())
	{
		ATLASSERT(m_hWnd == NULL);

		m_psh.dwFlags &= ~PSH_MODELESS;
		if(m_psh.hwndParent == NULL)
			m_psh.hwndParent = hWndParent;
		m_psh.phpage = (HPROPSHEETPAGE*)m_arrPages.GetData();
		m_psh.nPages = m_arrPages.GetSize();

		_Module.AddCreateWndData(&m_thunk.cd, (CPropertySheetImpl< T, TBase >*)this);

		return ::PropertySheet(&m_psh);
	}

// Attributes (extended overrides of client class methods)
// These now can be called before the sheet is created
// Note: Calling these after the sheet is created gives unpredictable results
	int GetPageCount() const
	{
		if(m_hWnd == NULL)	// not created yet
			return m_arrPages.GetSize();
		return TBase::GetPageCount();
	}
	int GetActiveIndex() const
	{
		if(m_hWnd == NULL)	// not created yet
			return m_psh.nStartPage;
		return TBase::GetActiveIndex();
	}
	HPROPSHEETPAGE GetPage(int nPageIndex) const
	{
		ATLASSERT(m_hWnd == NULL);	// can't do this after it's created
		return (HPROPSHEETPAGE)m_arrPages[nPageIndex];
	}
	int GetPageIndex(HPROPSHEETPAGE hPage) const
	{
		ATLASSERT(m_hWnd == NULL);	// can't do this after it's created
		return m_arrPages.Find((HPROPSHEETPAGE&)hPage);
	}
	BOOL SetActivePage(int nPageIndex)
	{
		if(m_hWnd == NULL)	// not created yet
		{
			ATLASSERT(nPageIndex >= 0 && nPageIndex < m_arrPages.GetSize());
			m_psh.nStartPage = nPageIndex;
			return TRUE;
		}
		return TBase::SetActivePage(nPageIndex);
	}
	BOOL SetActivePage(HPROPSHEETPAGE hPage)
	{
		ATLASSERT(hPage != NULL);
		if (m_hWnd == NULL)	// not created yet
		{
			int nPageIndex = GetPageIndex(hPage);
			if(nPageIndex == -1)
				return FALSE;

			return SetActivePage(nPageIndex);
		}
		return TBase::SetActivePage(hPage);

	}
	void SetTitle(LPCTSTR lpszText, UINT nStyle = 0)
	{
		ATLASSERT((nStyle & ~PSH_PROPTITLE) == 0); // only PSH_PROPTITLE is valid
		ATLASSERT(lpszText != NULL);

		if(m_hWnd == NULL)
		{
			// set internal state
			m_psh.pszCaption = lpszText;	// must exist until sheet is created
			m_psh.dwFlags &= ~PSH_PROPTITLE;
			m_psh.dwFlags |= nStyle;
		}
		else
		{
			// set external state
			TBase::SetTitle(lpszText, nStyle);
		}
	}
	void SetWizardMode()
	{
		m_psh.dwFlags |= PSH_WIZARD;
	}
	void EnableHelp()
	{
		m_psh.dwFlags |= PSH_HASHELP;
	}

// Operations
	BOOL AddPage(HPROPSHEETPAGE hPage)
	{
		ATLASSERT(hPage != NULL);
		BOOL bRet = TRUE;
		if(m_hWnd != NULL)
			TBase::AddPage(hPage);
		else	// sheet not created yet, use internal data
			bRet = m_arrPages.Add((HPROPSHEETPAGE&)hPage);
		return bRet;
	}
	BOOL AddPage(LPCPROPSHEETPAGE pPage)
	{
		ATLASSERT(pPage != NULL);
		HPROPSHEETPAGE hPage = ::CreatePropertySheetPage(pPage);
		if(hPage == NULL)
			return FALSE;
		BOOL bRet = AddPage(hPage);
		if(!bRet)
			::DestroyPropertySheetPage(hPage);
		return bRet;
	}
	BOOL RemovePage(HPROPSHEETPAGE hPage)
	{
		ATLASSERT(hPage != NULL);
		if (m_hWnd == NULL)		// not created yet
		{
			int nPage = GetPageIndex(hPage);
			if(nPage == -1)
				return FALSE;
			return RemovePage(nPage);
		}
		TBase::RemovePage(hPage);
		return TRUE;

	}
	BOOL RemovePage(int nPageIndex)
	{
		BOOL bRet = TRUE;
		if(m_hWnd != NULL)
			TBase::RemovePage(nPageIndex);
		else	// sheet not created yet, use internal data
			bRet = m_arrPages.RemoveAt(nPageIndex);
		return bRet;
	}

	void SetHeader(LPCTSTR szbmHeader)
	{
		ATLASSERT(m_hWnd == NULL);	// can't do this after it's created

		m_psh.dwFlags &= ~PSH_WIZARD;
		m_psh.dwFlags |= (PSH_HEADER | PSH_WIZARD97);
		m_psh.pszbmHeader = szbmHeader;
	}

	void SetHeader(HBITMAP hbmHeader)
	{
		ATLASSERT(m_hWnd == NULL);	// can't do this after it's created

		m_psh.dwFlags &= ~PSH_WIZARD;
		m_psh.dwFlags |= (PSH_HEADER | PSH_USEHBMHEADER | PSH_WIZARD97);
		m_psh.hbmHeader = hbmHeader;
	}

	void SetWatermark(LPCTSTR szbmWatermark, HPALETTE hplWatermark = NULL)
	{
		ATLASSERT(m_hWnd == NULL);	// can't do this after it's created

		m_psh.dwFlags &= ~PSH_WIZARD;
		m_psh.dwFlags |= PSH_WATERMARK | PSH_WIZARD97;
		m_psh.pszbmWatermark = szbmWatermark;

		if (hplWatermark != NULL)
		{
			m_psh.dwFlags |= PSH_USEHPLWATERMARK;
			m_psh.hplWatermark = hplWatermark;
		}
	}

	void SetWatermark(HBITMAP hbmWatermark, HPALETTE hplWatermark = NULL)
	{
		ATLASSERT(m_hWnd == NULL);	// can't do this after it's created

		m_psh.dwFlags &= ~PSH_WIZARD;
		m_psh.dwFlags |= (PSH_WATERMARK | PSH_USEHBMWATERMARK | PSH_WIZARD97);
		m_psh.hbmWatermark = hbmWatermark;

		if (hplWatermark != NULL)
		{
			m_psh.dwFlags |= PSH_USEHPLWATERMARK;
			m_psh.hplWatermark = hplWatermark;
		}
	}

	void StretchWatermark(bool bStretchWatermark)
	{
		ATLASSERT(m_hWnd == NULL);	// can't do this after it's created
		if (bStretchWatermark)
			m_psh.dwFlags |= PSH_STRETCHWATERMARK;
		else
			m_psh.dwFlags &= ~PSH_STRETCHWATERMARK;
	}

// Message map and handlers handlers
	typedef CPropertySheetImpl< T, TBase >	thisClass;
	BEGIN_MSG_MAP(thisClass)
		MESSAGE_HANDLER(WM_COMMAND, OnCommand)
	END_MSG_MAP()

	LRESULT OnCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
	{
		LRESULT lRet = DefWindowProc(uMsg, wParam, lParam);
		if(HIWORD(wParam) == BN_CLICKED && (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) &&
		   ((m_psh.dwFlags & PSH_MODELESS) != 0) && (GetActivePage() == NULL))
			DestroyWindow();
		return lRet;
	}
};

// for non-customized sheets
class CPropertySheet : public CPropertySheetImpl<CPropertySheet>
{
public:
	CPropertySheet(_U_STRINGorID title = (LPCTSTR)NULL, UINT uStartPage = 0, HWND hWndParent = NULL)
		: CPropertySheetImpl<CPropertySheet>(title, uStartPage, hWndParent)
	{ }

	BEGIN_MSG_MAP(thisClass)
		MESSAGE_HANDLER(WM_COMMAND, CPropertySheetImpl<CPropertySheet>::OnCommand)
	END_MSG_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// CPropertyPageWindow - client side for a property page

class CPropertyPageWindow : public CWindow
{
public:
// Constructors
	CPropertyPageWindow(HWND hWnd = NULL) : CWindow(hWnd) { }

	CPropertyPageWindow& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

// Attributes
	CPropertySheetWindow GetPropertySheet() const
	{
		ATLASSERT(::IsWindow(m_hWnd));
		return CPropertySheetWindow(GetParent());
	}

// Operations
	BOOL Apply()
	{
		ATLASSERT(::IsWindow(m_hWnd));
		ATLASSERT(GetParent() != NULL);
		return GetPropertySheet().Apply();
	}
	void CancelToClose()
	{
		ATLASSERT(::IsWindow(m_hWnd));
		ATLASSERT(GetParent() != NULL);
		GetPropertySheet().CancelToClose();
	}
	void SetModified(BOOL bChanged = TRUE)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		ATLASSERT(GetParent() != NULL);
		GetPropertySheet().SetModified(m_hWnd, bChanged);
	}
	LRESULT QuerySiblings(WPARAM wParam, LPARAM lParam)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		ATLASSERT(GetParent() != NULL);
		return GetPropertySheet().QuerySiblings(wParam, lParam);
	}
	void RebootSystem()
	{
		ATLASSERT(::IsWindow(m_hWnd));
		ATLASSERT(GetParent() != NULL);
		GetPropertySheet().RebootSystem();
	}
	void RestartWindows()
	{
		ATLASSERT(::IsWindow(m_hWnd));
		ATLASSERT(GetParent() != NULL);
		GetPropertySheet().RestartWindows();
	}
	void SetWizardButtons(DWORD dwFlags)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		ATLASSERT(GetParent() != NULL);
		GetPropertySheet().SetWizardButtons(dwFlags);
	}

// Implementation - overrides to prevent usage
	HWND Create(LPCTSTR, HWND, _U_RECT = NULL, LPCTSTR = NULL, DWORD = 0, DWORD = 0, _U_MENUorID = 0U, LPVOID = NULL)
	{
		ATLASSERT(FALSE);
		return NULL;
	}
};

/////////////////////////////////////////////////////////////////////////////
// CPropertyPageImpl - implements a property page

template <class T, class TBase = CPropertyPageWindow>
class ATL_NO_VTABLE CPropertyPageImpl : public CDialogImplBaseT< TBase >
{
public:
	PROPSHEETPAGE m_psp;

	operator PROPSHEETPAGE*() { return &m_psp; }

// Construction
	CPropertyPageImpl(_U_STRINGorID title = (LPCTSTR)NULL)
	{
		// initialize PROPSHEETPAGE struct
		memset(&m_psp, 0, sizeof(PROPSHEETPAGE));
		m_psp.dwSize = sizeof(PROPSHEETPAGE);
		m_psp.dwFlags = PSP_USECALLBACK;
		m_psp.hInstance = _Module.GetResourceInstance();
		T* pT = static_cast<T*>(this);
		pT;	// avoid level 4 warning
		m_psp.pszTemplate = MAKEINTRESOURCE(pT->IDD);
		m_psp.pfnDlgProc = (DLGPROC)T::StartDialogProc;
		m_psp.pfnCallback = T::PropPageCallback;
		m_psp.lParam = (LPARAM)this;

		if(title.m_lpstr != NULL)
			SetTitle(title);
	}

	static UINT CALLBACK PropPageCallback(HWND hWnd, UINT uMsg, LPPROPSHEETPAGE ppsp)
	{
		hWnd;	// avoid level 4 warning
		if(uMsg == PSPCB_CREATE)
		{
			ATLASSERT(hWnd == NULL);
			CDialogImplBaseT< TBase >* pPage = (CDialogImplBaseT< TBase >*)ppsp->lParam;
			_Module.AddCreateWndData(&pPage->m_thunk.cd, pPage);
		}

		return 1;
	}

	HPROPSHEETPAGE Create()
	{
		return ::CreatePropertySheetPage(&m_psp);
	}

// Attributes
	void SetTitle(_U_STRINGorID title)
	{
		m_psp.pszTitle = title.m_lpstr;
		m_psp.dwFlags |= PSP_USETITLE;
	}

// Operations
	void EnableHelp()
	{
		m_psp.dwFlags |= PSP_HASHELP;
	}

// Message map and handlers
	typedef CPropertyPageImpl< T, TBase >	thisClass;
	BEGIN_MSG_MAP(thisClass)
		MESSAGE_HANDLER(WM_NOTIFY, OnNotify)
	END_MSG_MAP()

	LRESULT OnNotify(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM lParam, BOOL& bHandled)
	{
		ATLASSERT(::IsWindow(m_hWnd));
		NMHDR* pNMHDR = (NMHDR*)lParam;

		// don't handle messages not from the page/sheet itself
		if(pNMHDR->hwndFrom != m_hWnd && pNMHDR->hwndFrom != ::GetParent(m_hWnd))
		{
			bHandled = FALSE;
			return 1;
		}

		T* pT = static_cast<T*>(this);
		LRESULT lResult = 0;
		switch(pNMHDR->code)
		{
		case PSN_SETACTIVE:
			lResult = pT->OnSetActive() ? 0 : -1;
			break;
		case PSN_KILLACTIVE:
			lResult = !pT->OnKillActive();
			break;
		case PSN_APPLY:
			lResult = pT->OnApply() ? PSNRET_NOERROR : PSNRET_INVALID_NOCHANGEPAGE;
			break;
		case PSN_RESET:
			pT->OnReset();
			break;
		case PSN_QUERYCANCEL:
			lResult = !pT->OnQueryCancel();
			break;
		case PSN_WIZNEXT:
			lResult = pT->OnWizardNext();
			break;
		case PSN_WIZBACK:
			lResult = pT->OnWizardBack();
			break;
		case PSN_WIZFINISH:
			lResult = !pT->OnWizardFinish();
			break;
		case PSN_HELP:
			pT->OnHelp();
			break;
		default:
			bHandled = FALSE;	// not handled
		}

		return lResult;
	}

// Overridables
	BOOL OnSetActive()
	{
		return TRUE;
	}
	BOOL OnKillActive()
	{
		return TRUE;
	}
	BOOL OnApply()
	{
		return TRUE;
	}
	void OnReset()
	{
	}
	BOOL OnQueryCancel()
	{
		return TRUE;    // ok to cancel
	}
	int OnWizardBack()
	{
		// 0  = goto next page
		// -1 = prevent page change
		// >0 = jump to page by dlg ID
		return 0;
	}
	int OnWizardNext()
	{
		// 0  = goto next page
		// -1 = prevent page change
		// >0 = jump to page by dlg ID
		return 0;
	}
	BOOL OnWizardFinish()
	{
		return TRUE;
	}
	void OnHelp()
	{
	}
};

// for non-customized pages
template <WORD t_wDlgTemplateID>
class CPropertyPage : public CPropertyPageImpl<CPropertyPage<t_wDlgTemplateID> >
{
public:
	enum { IDD = t_wDlgTemplateID };

	CPropertyPage(_U_STRINGorID title = (LPCTSTR)NULL) : CPropertyPageImpl<CPropertyPage>(title)
	{ }

	DECLARE_EMPTY_MSG_MAP()
};


#endif // __PROPSHEET_H
