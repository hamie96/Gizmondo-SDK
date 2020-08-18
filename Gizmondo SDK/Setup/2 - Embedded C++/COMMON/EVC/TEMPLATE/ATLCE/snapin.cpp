[!if=(FileExists, "FALSE")]
#include "stdafx.h"
#include "[!ProjectName].h"
#include "[!HeaderName]"
[!else]
[!AddIncludeFile(TargetFile, "stdafx.h")]
[!AddStringToSymbol(ProjectName.h, ProjectName, ".h")]
[!AddIncludeFile(TargetFile, ProjectName.h)]
[!AddIncludeFile(TargetFile, HeaderName)]
[!endif]

[!crlf]
/////////////////////////////////////////////////////////////////////////////
// [!ClassName]ComponentData


[!if=(IComponentData, "TRUE")]
static const GUID [!ClassName]GUID_NODETYPE = 
[!SnapInNodeType_GUIDFMT];

const GUID*  [!ClassName]Data::m_NODETYPE = &[!ClassName]GUID_NODETYPE;
const OLECHAR* [!ClassName]Data::m_SZNODETYPE = OLESTR("[!SnapInNodeType]");
const OLECHAR* [!ClassName]Data::m_SZDISPLAY_NAME = OLESTR("[!ShortName]");
const CLSID* [!ClassName]Data::m_SNAPIN_CLASSID = &CLSID_[!CoClassName];
[!crlf]
[!endif]
[!if=(EXTENSIONSNAPIN, "TRUE")]
static const GUID [!ClassName]ExtGUID_NODETYPE = 
[!EXTENDSNODE_GUIDFMT];

const GUID*  [!ClassName]ExtData::m_NODETYPE = &[!ClassName]ExtGUID_NODETYPE;
const OLECHAR* [!ClassName]ExtData::m_SZNODETYPE = OLESTR("[!EXTENDSNODE]");
const OLECHAR* [!ClassName]ExtData::m_SZDISPLAY_NAME = OLESTR("[!ShortName]");
const CLSID* [!ClassName]ExtData::m_SNAPIN_CLASSID = &CLSID_[!CoClassName];
[!endif]

[!if=(IComponentData, "TRUE")]
[!if=(IExtendPropertySheet, "TRUE)]
HRESULT [!ClassName]Data::CreatePropertyPages(LPPROPERTYSHEETCALLBACK lpProvider,
    long handle, 
	IUnknown* pUnk,
	DATA_OBJECT_TYPES type)
{
	if (type == CCT_SCOPE || type == CCT_RESULT)
	{
		[!ClassName]Page* pPage = new [!ClassName]Page(handle, true, _T("[!ShortName]"));
		lpProvider->AddPage(pPage->Create());
		// The second parameter  to the property page class constructor
		// should be true for only one page.
[!crlf]
		// TODO : Add code here to add additional pages
		return S_OK;
	}
	return E_UNEXPECTED;
}
[!crlf]
[!endif]
HRESULT [!ClassName]Data::GetScopePaneInfo(SCOPEDATAITEM *pScopeDataItem)
{
	if (pScopeDataItem->mask & SDI_STR)
		pScopeDataItem->displayname = m_bstrDisplayName;

	if (pScopeDataItem->mask & SDI_IMAGE)
		pScopeDataItem->nImage = m_scopeDataItem.nImage;

	if (pScopeDataItem->mask & SDI_OPENIMAGE)
		pScopeDataItem->nOpenImage = m_scopeDataItem.nOpenImage;

	if (pScopeDataItem->mask & SDI_PARAM)
		pScopeDataItem->lParam = m_scopeDataItem.lParam;

	if (pScopeDataItem->mask & SDI_STATE )
		pScopeDataItem->nState = m_scopeDataItem.nState;
[!crlf]
	// TODO : Add code for SDI_CHILDREN 
	return S_OK;
}
[!crlf]
HRESULT [!ClassName]Data::GetResultPaneInfo(RESULTDATAITEM *pResultDataItem)
{
	if (pResultDataItem->bScopeItem)
	{
		if (pResultDataItem->mask & RDI_STR)
		{
			pResultDataItem->str = GetResultPaneColInfo(pResultDataItem->nCol);
		}
		if (pResultDataItem->mask & RDI_IMAGE)
		{
			pResultDataItem->nImage = m_scopeDataItem.nImage;
		}
		if (pResultDataItem->mask & RDI_PARAM)
		{
			pResultDataItem->lParam = m_scopeDataItem.lParam;
		}
[!crlf]
		return S_OK;
	}
[!crlf]
	if (pResultDataItem->mask & RDI_STR)
	{
		pResultDataItem->str = GetResultPaneColInfo(pResultDataItem->nCol);
	}
	if (pResultDataItem->mask & RDI_IMAGE)
	{
		pResultDataItem->nImage = m_resultDataItem.nImage;
	}
	if (pResultDataItem->mask & RDI_PARAM)
	{
		pResultDataItem->lParam = m_resultDataItem.lParam;
	}
	if (pResultDataItem->mask & RDI_INDEX)
	{
		pResultDataItem->nIndex = m_resultDataItem.nIndex;
	}
[!crlf]
	return S_OK;
}
[!crlf]
HRESULT [!ClassName]Data::Notify( MMC_NOTIFY_TYPE event,
    long arg,
    long param,
	IComponentData* pComponentData,
	IComponent* pComponent,
	DATA_OBJECT_TYPES type)
{
	// Add code to handle the different notifications.
	// Handle MMCN_SHOW and MMCN_EXPAND to enumerate children items.
	// In response to MMCN_SHOW you have to enumerate both the scope
	// and result pane items.
	// For MMCN_EXPAND you only need to enumerate the scope items
	// Use IConsoleNameSpace::InsertItem to insert scope pane items
	// Use IResultData::InsertItem to insert result pane item.
	HRESULT hr = E_NOTIMPL;
[!crlf]	
	_ASSERTE(pComponentData != NULL || pComponent != NULL);
[!crlf]
	CComPtr<IConsole> spConsole;
	CComQIPtr<IHeaderCtrl, &IID_IHeaderCtrl> spHeader;
	if (pComponentData != NULL)
		spConsole = (([!ClassName]*)pComponentData)->m_spConsole;
	else
	{
		spConsole = (([!ClassName]Component*)pComponent)->m_spConsole;
		spHeader = spConsole;
	}
[!crlf]
	switch (event)
	{
	case MMCN_SHOW:
		{

			CComQIPtr<IResultData, &IID_IResultData> spResultData(spConsole);
			// TODO : Enumerate the result pane items
			hr = S_OK;
			break;
		}
	case MMCN_EXPAND:
		{
			CComQIPtr<IConsoleNameSpace, &IID_IConsoleNameSpace> spConsoleNameSpace(spConsole);
			// TODO : Enumerate scope pane items
			hr = S_OK;
			break;
		}
	case MMCN_ADD_IMAGES:
		{
			// Add Images
			IImageList* pImageList = (IImageList*) arg;
			hr = E_FAIL;
			// Load bitmaps associated with the scope pane
			// and add them to the image list
			// Loads the default bitmaps generated by the wizard
			// Change as required
			HBITMAP hBitmap16 = LoadBitmap(_Module.GetResourceInstance(), MAKEINTRESOURCE([!IDB_SNAPIN16]));
			if (hBitmap16 != NULL)
			{
				HBITMAP hBitmap32 = LoadBitmap(_Module.GetResourceInstance(), MAKEINTRESOURCE([!IDB_SNAPIN32]));
				if (hBitmap32 != NULL)
				{
					hr = pImageList->ImageListSetStrip((long*)hBitmap16, 
					(long*)hBitmap32, 0, RGB(0, 128, 128));
					if (FAILED(hr))
						ATLTRACE(_T("IImageList::ImageListSetStrip failed\n"));
				}
			}
			break;
		}
	}
	return hr;
}
[!crlf]
LPOLESTR [!ClassName]Data::GetResultPaneColInfo(int nCol)
{
	if (nCol == 0)
		return m_bstrDisplayName;

	// TODO : Return the text for other columns

	return OLESTR("Override GetResultPaneColInfo");
}
[!crlf]
[!endif]
[!if=(EXTENSIONSNAPIN, "TRUE")]
[!if=(IExtendPropertySheet, "TRUE)]
HRESULT [!ClassName]ExtData::CreatePropertyPages(LPPROPERTYSHEETCALLBACK lpProvider,
    long handle, 
	IUnknown* pUnk,
	DATA_OBJECT_TYPES type)
{
	if (type == CCT_SCOPE || type == CCT_RESULT)
	{
		[!ClassName]Page* pPage = new [!ClassName]Page(handle, true, _T("[!ShortName]"));
		lpProvider->AddPage(pPage->Create());
		// The second parameter  to the property page class constructor
		// should be true for only one page.
[!crlf]
		// TODO : Add code here to add additional pages
		return S_OK;
	}
	return E_UNEXPECTED;
}
[!crlf]
[!endif]
[!endif]
[!if=(IComponentData, "TRUE")]
HRESULT [!ClassName]::Initialize(LPUNKNOWN pUnknown)
{
	HRESULT hr = IComponentDataImpl<[!ClassName], [!ClassName]Component >::Initialize(pUnknown);
	if (FAILED(hr))
		return hr;
[!crlf]
	CComPtr<IImageList> spImageList;
[!crlf]
	if (m_spConsole->QueryScopeImageList(&spImageList) != S_OK)
	{
		ATLTRACE(_T("IConsole::QueryScopeImageList failed\n"));
		return E_UNEXPECTED;
	}
[!crlf]
	// Load bitmaps associated with the scope pane
	// and add them to the image list
	// Loads the default bitmaps generated by the wizard
	// Change as required
	HBITMAP hBitmap16 = LoadBitmap(_Module.GetResourceInstance(), MAKEINTRESOURCE([!IDB_SNAPIN16]));
	if (hBitmap16 == NULL)
		return S_OK;
[!crlf]
	HBITMAP hBitmap32 = LoadBitmap(_Module.GetResourceInstance(), MAKEINTRESOURCE([!IDB_SNAPIN32]));
	if (hBitmap32 == NULL)
		return S_OK;
[!crlf]
	if (spImageList->ImageListSetStrip((long*)hBitmap16, 
		(long*)hBitmap32, 0, RGB(0, 128, 128)) != S_OK)
	{
		ATLTRACE(_T("IImageList::ImageListSetStrip failed\n"));
		return E_UNEXPECTED;
	}
	return S_OK;
}
[!endif]
