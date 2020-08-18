//	TetrisHighscoresDlg.h - Tetris for Pocket PC (highscores dialog)
//
//	Copyright (C) 2000-2004 Ramon de Klein (Ramon.de.Klein@ict.nl)
//
//	This program is free software; you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation; either version 2 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program; if not, write to the Free Software
//	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#ifndef __TETRIS_HIGHSCORES_DLG_H
#define __TETRIS_HIGHSCORES_DLG_H


#include "Resource.h"
#include "TetrisOptions.h"
#include "TetrisScore.h"
//#include "WaitCursor.h"
#include "Registry.h"

#ifdef IRDA_SUPPORT
#include "IrDASocket.h"
#endif


class CTetrisHighscoresDlg : public CDialogImpl<CTetrisHighscoresDlg>
{
public:
	enum { IDD = IDD_HIGHSCORES };

	CTetrisHighscoresDlg (bool fNewScore, DWORD dwScore)
		: m_fNewScore(fNewScore)
		, m_dwScore(dwScore)
		, m_dwIndex(CTetrisScore::MaxScores)
		, m_levelScore(CTetrisOptions::Unknown)
		, m_levelSelected(CTetrisOptions::Unknown)
	{
	}

private:
	BEGIN_MSG_MAP(CTetrisHighscoresDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		NOTIFY_HANDLER(IDC_SCORE_TAB, TCN_SELCHANGE,      OnScoreTabChange)
		NOTIFY_HANDLER(IDC_SCORELIST, LVN_BEGINLABELEDIT, OnBeginLabelEdit)
		NOTIFY_HANDLER(IDC_SCORELIST, LVN_ENDLABELEDIT,   OnEndLabelEdit  )
		NOTIFY_HANDLER(IDC_SCORELIST, NM_CUSTOMDRAW,      OnCustomDraw    )
		COMMAND_ID_HANDLER(IDOK,      OnOk)
		COMMAND_ID_HANDLER(IDCANCEL,  OnOk)
		COMMAND_ID_HANDLER(IDC_CLEAR_SCORES, OnClearScores)

#ifdef IRDA_SUPPORT
		COMMAND_ID_HANDLER(IDC_SEND,    OnSend)
		COMMAND_ID_HANDLER(IDC_RECEIVE, OnReceive)
#endif

	END_MSG_MAP()

private:
	LRESULT OnInitDialog (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Call base class
		DefWindowProc();

		// Create the menu bar
		SHMENUBARINFO mbi = {0};
		mbi.cbSize     = sizeof(SHMENUBARINFO);
		mbi.hwndParent = m_hWnd;
		mbi.dwFlags    = SHCMBF_EMPTYBAR;
		if (!::SHCreateMenuBar(&mbi)) 
			return -1;

		// Save the control bar
		m_hWndCB = mbi.hwndMB;

		// Create a bold font
		LOGFONT lf = {0};
		::GetObject(::GetStockObject(SYSTEM_FONT),sizeof(lf),&lf);
		lf.lfWeight = FW_BOLD;
		HFONT hfBold = ::CreateFontIndirect(&lf);

		// Set the bold font for all headers
		SendDlgItemMessage(IDC_GRP_HALLOFFAME,WM_SETFONT,WPARAM(hfBold),MAKELPARAM(TRUE,0));
		SendDlgItemMessage(IDC_SCORE,WM_SETFONT,WPARAM(hfBold),MAKELPARAM(TRUE,0));

		// Load the list control
		HWND hwndList = GetDlgItem(IDC_SCORELIST);
		ListView_SetExtendedListViewStyle(hwndList,LVS_EX_FULLROWSELECT);

		LVCOLUMN lvc = {0};
		lvc.mask = LVCF_FMT|LVCF_SUBITEM|LVCF_WIDTH;
		
		lvc.fmt      = LVCFMT_LEFT;
		lvc.iSubItem = 0;
		lvc.cx       = 126;
		ListView_InsertColumn(hwndList,0,&lvc);

		lvc.fmt      = LVCFMT_RIGHT;
		lvc.iSubItem = 1;
		lvc.cx       = 30;
		ListView_InsertColumn(hwndList,1,&lvc);

		lvc.fmt      = LVCFMT_RIGHT;
		lvc.iSubItem = 2;
		lvc.cx       = 55;
		ListView_InsertColumn(hwndList,2,&lvc);

		int aiOrder[] = {1,0,2};
		ListView_SetColumnOrderArray(hwndList,3,aiOrder);

		// Load the tab control
		HWND hwndTab = GetDlgItem(IDC_SCORE_TAB);

		// Setup the tab control
		TCITEM tci = {0};
		tci.mask = TCIF_TEXT;
		
		// Insert the tabs
		tci.pszText = _T("Easy");
		TabCtrl_InsertItem(hwndTab,0,&tci);

		tci.pszText = _T("Moderate");
		TabCtrl_InsertItem(hwndTab,1,&tci);

		tci.pszText = _T("Hard");
		TabCtrl_InsertItem(hwndTab,2,&tci);

		// Load the default options
		CTetrisOptions tetrisOptions;
		tetrisOptions.Load();

		// Set the score level
		m_levelScore = tetrisOptions.GetLevel();

		// Load default scores
		m_tetrisScore.Load(m_levelScore);

		// Check wether the score was a highscore
		if (m_fNewScore)
		{
			// Determine the index in the highscore list
			m_dwIndex = m_tetrisScore.GetScoreIndex(m_dwScore);
			if (m_dwIndex != CTetrisScore::MaxScores)
			{
				// Obtain the last known user
				TCHAR tszUsername[CTetrisScore::MaxNameLen+1] = _T("");

				CRegistry reg;
				if (reg.Open(HKEY_CURRENT_USER,REGKEY_SCORE,FALSE))
				{
					reg.Read(_T("Last user"),tszUsername,sizeof(tszUsername)/sizeof(TCHAR));
					reg.Close();
				}
					
				// Add the score to the list
				m_tetrisScore.AddScore(m_dwScore,tszUsername);
				m_tetrisScore.Save();
			}
		}

		TCHAR tszResource[100], tszMessage[100];

		// Set the last score
		::LoadString(_Module.GetResourceInstance(),IDS_SCORE,tszResource,sizeof(tszResource)/sizeof(TCHAR));
		wsprintf(tszMessage,_T("%s: %d"),tszResource, m_dwScore);
		::SetWindowText(GetDlgItem(IDC_SCORE),tszMessage);

		// Set focus to list control
		::SetFocus(hwndList);

		// Set the appropriate tab control
		m_levelSelected = m_levelScore;
		switch (m_levelSelected)
		{
		case CTetrisOptions::Easy:     TabCtrl_SetCurSel(hwndTab,0); break;
		case CTetrisOptions::Moderate: TabCtrl_SetCurSel(hwndTab,1); break;
		case CTetrisOptions::Hard:	   TabCtrl_SetCurSel(hwndTab,2); break;
		default:					   ATLASSERT(0);                 break;
		}

		// Refresh the list control
		Refresh();

		// Edit the high-score name
		if (m_dwIndex != CTetrisScore::MaxScores)
		{
			// We need to post the LVM_EDITLABEL instead of
			// using the ListView_EditLabel macro (this
			// macro sends the message). Posting the message
			// is better, because the SIP stays up.
			::PostMessage(hwndList,LVM_EDITLABEL,m_dwIndex,0);
		}

#ifdef IRDA_SUPPORT
		// Only enable send/receive when IrDA support is enabled
		::EnableWindow(GetDlgItem(IDC_SEND   ),TRUE);
		::EnableWindow(GetDlgItem(IDC_RECEIVE),TRUE);
#endif

		return FALSE;
	}

	LRESULT OnScoreTabChange (int idCtrl, LPNMHDR pnmh, BOOL& bHandled)
	{
		// Message will be handled
		bHandled = TRUE;

		// Determine the selected level
		switch (TabCtrl_GetCurSel(pnmh->hwndFrom))
		{
		case 0: m_levelSelected = CTetrisOptions::Easy;     break;
		case 1: m_levelSelected = CTetrisOptions::Moderate; break;
		case 2: m_levelSelected = CTetrisOptions::Hard;     break;
		default: ATLASSERT(0); break;
		}

		// Refresh the list control
		Refresh();

		return TRUE;
	}

	LRESULT OnBeginLabelEdit (int idCtrl, LPNMHDR pnmh, BOOL& bHandled)
	{
		// Message will be handled
		bHandled = TRUE;

		LV_DISPINFO* plvDispInfo = reinterpret_cast<LV_DISPINFO*>(pnmh);

		// We can only change if the levels correspond
		if (m_levelScore != m_levelSelected)
			return TRUE;

		// We don't allow change of other scores
		if (int(m_dwIndex) != plvDispInfo->item.iItem)
			return TRUE;

		// Allow change of score
		return FALSE;
	}

	LRESULT OnEndLabelEdit (int idCtrl, LPNMHDR pnmh, BOOL& bHandled)
	{
		// Message will be handled
		bHandled = TRUE;

		LV_DISPINFO* plvDispInfo = reinterpret_cast<LV_DISPINFO*>(pnmh);

		// Check wether the user cancelled
		if (plvDispInfo->item.pszText == 0)
			return FALSE;

		// Set the new score
		CTetrisScore::SCOREITEM& si = m_tetrisScore.GetScore(m_dwIndex);
		_tcscpy(si.tszName, plvDispInfo->item.pszText);

		// Save the score
		m_tetrisScore.Save();

		// Save the "last known user"
		CRegistry reg;
		if (reg.Open(HKEY_CURRENT_USER,REGKEY_SCORE,TRUE))
		{
			reg.Write(_T("Last user"),si.tszName);
			reg.Close();
		}
		return TRUE;
	}

	LRESULT OnCustomDraw (int idCtrl, LPNMHDR pnmh, BOOL& bHandled)
	{
		// Message will be handled
		bHandled = TRUE;

		NMLVCUSTOMDRAW* plvCustomDraw = reinterpret_cast<NMLVCUSTOMDRAW*>(pnmh);
		switch (plvCustomDraw->nmcd.dwDrawStage)
		{
		case CDDS_PREPAINT:
			return CDRF_NOTIFYITEMDRAW;

		case CDDS_ITEMPREPAINT:
			// Change the color for the current item
			if ((plvCustomDraw->nmcd.dwItemSpec == m_dwIndex) && (m_levelScore == m_levelSelected))
				plvCustomDraw->clrTextBk = RGB(128, 128, 128);

			// Don't perform special handling
			return CDRF_DODEFAULT;
		}

		return TRUE;
	}

	LRESULT OnOk (WORD wNotifyCode, WORD nID, HWND hwndCtl, BOOL& bHandled)
	{
		// Those %@!%$ developers in Redmond decided that the
		// listview's edit control should have identifer 1,
		// which is the same as IDOK. Whenever the edit control
		// sends a message, then it seems that the OK button
		// has been pressed. The only way to detect this is to
		// check the originator's parent. If it's the listview,
		// then we are fooled.
		if (::GetParent(hwndCtl) == GetDlgItem(IDC_SCORELIST))
			return 0;

		// End the dialog
		EndDialog(IDOK);
		bHandled = TRUE;
		return 0;
	}

	LRESULT OnClearScores (WORD wNotifyCode, WORD nID, HWND hwndCtl, BOOL& bHandled)
	{
		// Ask if the scores should really be cleared
		TCHAR tszMessageBody[100], tszMessageHdr[50];
		::LoadString(_Module.GetResourceInstance(),IDS_CLEAR_SCORES_BODY,tszMessageBody,sizeof(tszMessageBody)/sizeof(TCHAR));
		::LoadString(_Module.GetResourceInstance(),IDS_CLEAR_SCORES_HDR ,tszMessageHdr, sizeof(tszMessageHdr )/sizeof(TCHAR));
		if (MessageBox(tszMessageBody,tszMessageHdr,MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2) == IDYES)
		{
			// Set the new score
			m_tetrisScore.Clear();

			// Refresh the scores
			Refresh();
		}

		// Command handled
		bHandled = TRUE;
		return 0;
	}

	void Refresh ()
	{
		HWND hwndList = GetDlgItem(IDC_SCORELIST);

		// Remove all items from the list
		ListView_DeleteAllItems(hwndList);

		// Load default scores
		m_tetrisScore.Load(m_levelSelected);

		// Insert all items into the list
		LVITEM lvi = {0};
		lvi.mask = LVIF_TEXT;
		for (DWORD dwIndex=0; dwIndex<CTetrisScore::MaxScores; ++dwIndex)
		{
			const CTetrisScore::SCOREITEM& si = m_tetrisScore.GetScore(dwIndex);
			if (si.dwScore == 0)
				break;

			TCHAR tszPosition[5], tszScore[10];
			wsprintf(tszPosition,_T("%d."),dwIndex+1);
			wsprintf(tszScore,_T("%d"),si.dwScore);

			lvi.iItem = dwIndex;
			lvi.pszText = LPTSTR(si.tszName);

			ListView_InsertItem(hwndList,&lvi);
			ListView_SetItemText(hwndList,dwIndex,1,tszPosition);
			ListView_SetItemText(hwndList,dwIndex,2,tszScore);
		}
	}

private:
	CTetrisScore	m_tetrisScore;

	CTetrisOptions::Level	m_levelScore;
	CTetrisOptions::Level	m_levelSelected;

	bool			m_fNewScore;
	DWORD			m_dwScore;

	DWORD			m_dwIndex;

#ifdef IRDA_SUPPORT

private:
	// Infrared scheme version
	enum { Version = 1 };

	// Timeout values
	enum { ShortTimeout = 5000, LongTimeout = 15000 };

	LRESULT OnSend (WORD wNotifyCode, WORD nID, HWND hwndCtl, BOOL& bHandled)
	{
		// Send highscores using IrDA
		DWORD dwResult = Send();
		if (dwResult)
		{
			// Display a message that 
			TCHAR tszHeader[50], tszMessage[100];
			::LoadString(_Module.GetResourceInstance(),IDS_ERROR_HIGHSCORE_SEND,tszHeader,sizeof(tszHeader)/sizeof(TCHAR));
			::LoadString(_Module.GetResourceInstance(),dwResult,tszMessage,sizeof(tszMessage)/sizeof(TCHAR));
			MessageBox(tszMessage,tszHeader,MB_ICONEXCLAMATION|MB_OK);
		}
		
		// Command will be handled
		bHandled = TRUE;
		return 0;
	}

	LRESULT OnReceive (WORD wNotifyCode, WORD nID, HWND hwndCtl, BOOL& bHandled)
	{
		// Send highscores using IrDA
		DWORD dwResult = Receive();
		if (dwResult)
		{
			// Display a message that 
			TCHAR tszHeader[50], tszMessage[100];
			::LoadString(_Module.GetResourceInstance(),IDS_ERROR_HIGHSCORE_RECEIVE,tszHeader,sizeof(tszHeader)/sizeof(TCHAR));
			::LoadString(_Module.GetResourceInstance(),dwResult,tszMessage,sizeof(tszMessage)/sizeof(TCHAR));
			MessageBox(tszMessage,tszHeader,MB_ICONEXCLAMATION|MB_OK);
		}
		
		// Command will be handled
		bHandled = TRUE;
		return 0;
	}

	DWORD Send (void)
	{
		//CWaitCursor wc;

		USES_CONVERSION;

		// Make sure the socket layer is active
		CWinSock winSock;

		// Open an IrDA socket
		CIrDASocket sd;
		if (!sd.Open())
			return IDS_ERROR_IRDA_NO_SOCKET;

		// Try several times to find a device
		DEVICELIST deviceList = {0};
		for (int iTry=0; iTry<(LongTimeout/1000); ++iTry)
		{
			// Try to find a device
			if (!sd.EnumDevices(&deviceList,sizeof(DEVICELIST)))
				return IDS_ERROR_IRDA_CANNOT_ENUMDEVS;

			// Abort if we have found a device
			if (deviceList.numDevice > 0)
				break;

			// Wait a second
			::Sleep(1000);
		}

		// Check if all retries have been finished
		if (deviceList.numDevice == 0)
			return IDS_ERROR_NO_DEVICES_FOUND;

		// Obtain the devicename (ANSI)
		LPCTSTR lpszDeviceName = A2T(deviceList.Device[0].irdaDeviceName);

		// Disable wait cursor
		//wc.Disable();

		// Ask the user if recepient is okay
		TCHAR tszHeader[50], tszFormatString[100], tszMessage[100];
		::LoadString(_Module.GetResourceInstance(),IDS_HIGHSCORE_SEND,tszHeader,sizeof(tszHeader)/sizeof(TCHAR));
		::LoadString(_Module.GetResourceInstance(),IDS_HIGHSCORE_SENDTOHOST,tszFormatString,sizeof(tszFormatString)/sizeof(TCHAR));
		wsprintf(tszMessage,tszFormatString,lpszDeviceName);
		if (MessageBox(tszMessage,tszHeader,MB_ICONQUESTION|MB_YESNO) != IDYES)
			return 0;

		// Enable wait cursor
		//wc.Enable();

		// A device has been found
		if (!sd.Connect(IRDA_SERVICENAME,deviceList.Device[0].irdaDeviceID,LongTimeout))
			return IDS_ERROR_IRDA_CANNOT_CONNECT;

		// Setup header
		IR_HEADER irHeaderSend = {0};
		irHeaderSend.ulVersion = htonl(Version);
		irHeaderSend.usLevel   = htons(m_levelSelected);

		// Send the header
		if (!sd.Send(irHeaderSend,ShortTimeout))
			return IDS_ERROR_IRDA_CANNOT_SEND;

		// Receive the other end's header
		IR_HEADER irHeaderRecv = {0};
		if (!sd.Receive(irHeaderRecv,ShortTimeout))
			return IDS_ERROR_IRDA_CANNOT_RECEIVE;

		// Check if the version matches
		if (ntohl(irHeaderSend.ulVersion) != ntohl(irHeaderRecv.ulVersion))
			return IDS_ERROR_INCOMPATIBLE_VERSIONS;

		// Check if the levels match
		if (ntohs(irHeaderSend.usLevel) != ntohs(irHeaderRecv.usLevel))
			return IDS_ERROR_INCOMPATIBLE_LEVELS;

		// Send all scores
		for (int iIndex=0; iIndex<CTetrisScore::MaxScores; ++iIndex)
		{
			USES_CONVERSION;

			const CTetrisScore::SCOREITEM& si = m_tetrisScore.GetScore(iIndex);

			// Setup the send item
			IR_SENDRECORD irSendRec;
			irSendRec.ulScore     = htonl(si.dwScore);
			irSendRec.ulTimeStamp = htonl(si.dwTimeStamp);
			wcscpy(irSendRec.wszName,T2CW(si.tszName));

			// Send the item
			if (!sd.Send(irSendRec,ShortTimeout))
				return IDS_ERROR_IRDA_CANNOT_SEND;
		}

		// Receive the number of accepter scores
		IR_RESPONSE rcResponse;
		if (!sd.Receive(rcResponse,ShortTimeout))
			return IDS_ERROR_IRDA_CANNOT_RECEIVE;

		// Disable wait cursor
		//wc.Disable();

		// Display the number of scores transfered
		::LoadString(_Module.GetResourceInstance(),IDS_HIGHSCORE_SCORESMERGED,tszFormatString,sizeof(tszFormatString)/sizeof(TCHAR));
		wsprintf(tszMessage,tszFormatString,ntohs(rcResponse.usAccepted));
		MessageBox(tszMessage,tszHeader,MB_ICONINFORMATION|MB_OK);

		// Enable wait cursor
		//wc.Enable();

		// Return successful
		return 0;
	}

	DWORD Receive (void)
	{
		//CWaitCursor wc;

		// Make sure the socket layer is active
		CWinSock winSock;

		// Open an IrDA socket
		CIrDASocket sdServer;
		if (!sdServer.Open())
			return IDS_ERROR_IRDA_NO_SOCKET;

		// Bind socket
		if (!sdServer.Bind(IRDA_SERVICENAME))
			return IDS_ERROR_IRDA_CANNOT_BIND;

		// Listen on socket
		if (!sdServer.Listen())
			return IDS_ERROR_IRDA_CANNOT_LISTEN;

		// Wait for connection to be accepted
		CIrDASocket sd;
		if (!sdServer.Accept(&sd,LongTimeout))
			return IDS_ERROR_IRDA_CANNOT_ACCEPT;

		// Close the server
		sdServer.Close();

		// Setup header
		IR_HEADER irHeaderSend = {0};
		irHeaderSend.ulVersion = htonl(Version);
		irHeaderSend.usLevel   = htons(m_levelSelected);

		// Send the header
		if (!sd.Send(irHeaderSend,ShortTimeout))
			return IDS_ERROR_IRDA_CANNOT_SEND;

		// Receive the other end's header
		IR_HEADER irHeaderRecv = {0};
		if (!sd.Receive(irHeaderRecv,ShortTimeout))
			return IDS_ERROR_IRDA_CANNOT_RECEIVE;

		// Check if the version matches
		if (ntohl(irHeaderSend.ulVersion) != ntohl(irHeaderRecv.ulVersion))
			return IDS_ERROR_INCOMPATIBLE_VERSIONS;

		// Check if the levels match
		if (ntohs(irHeaderSend.usLevel) != ntohs(irHeaderRecv.usLevel))
			return IDS_ERROR_INCOMPATIBLE_LEVELS;

#if 0
		// TODO: Obtain the devicename
		LPCTSTR lpszDeviceName = A2T(sa.irdaDeviceName);
#else
		LPCTSTR lpszDeviceName = _T("<other side>");
#endif
	
		// Disable wait cursor
		//wc.Disable();

		// Ask the user if recepient is okay
		TCHAR tszHeader[50], tszFormatString[100], tszMessage[100];
		::LoadString(_Module.GetResourceInstance(),IDS_HIGHSCORE_RECEIVE,tszHeader,sizeof(tszHeader)/sizeof(TCHAR));
		::LoadString(_Module.GetResourceInstance(),IDS_HIGHSCORE_RECEIVEFROMHOST,tszFormatString,sizeof(tszFormatString)/sizeof(TCHAR));
		wsprintf(tszMessage,tszFormatString,lpszDeviceName);
		if (MessageBox(tszMessage,tszHeader,MB_ICONQUESTION|MB_YESNO) != IDYES)
			return 0;

		// Enable wait cursor
		//wc.Enable();

		// Send all scores
		int iScoresMerged = 0;
		for (int iIndex=0; iIndex<CTetrisScore::MaxScores; ++iIndex)
		{
			USES_CONVERSION;

			// Send the item
			IR_SENDRECORD irSendRec;
			if (!sd.Receive(irSendRec,ShortTimeout))
				return IDS_ERROR_IRDA_CANNOT_RECEIVE;

			// Process the results
			const DWORD dwScore = ntohl(irSendRec.ulScore);
			const DWORD dwTimestamp = ntohl(irSendRec.ulTimeStamp);
			LPCTSTR lptszName = W2T(irSendRec.wszName);

			// Add the score to the list
			if (dwScore>0)
			{
				if (m_tetrisScore.InsertScore(dwScore,lptszName,dwTimestamp,true))
					++iScoresMerged;
			}
		}

		// Receive the number of accepter scores
		IR_RESPONSE rcResponse;
		rcResponse.usAccepted = htons(iScoresMerged);
		if (!sd.Send(rcResponse,ShortTimeout))
			return IDS_ERROR_IRDA_CANNOT_SEND;

		// Save and refresh scores
		m_tetrisScore.Save();
		Refresh();

		// Disable wait cursor
		//wc.Disable();

		// Display the number of scores transfered
		::LoadString(_Module.GetResourceInstance(),IDS_HIGHSCORE_SCORESMERGED,tszFormatString,sizeof(tszFormatString)/sizeof(TCHAR));
		wsprintf(tszMessage,tszFormatString,ntohs(rcResponse.usAccepted));
		MessageBox(tszMessage,tszHeader,MB_ICONINFORMATION|MB_OK);

		// Enable wait cursor
		//wc.Enable();

		// Return successful
		return 0;
	}

private:
// The following structures are used when sending data using
// IrDA score synchronization. Structure alignment is disabled
// to avoid alignment problems between different platforms.
#pragma pack(push)
#pragma pack(1)

	// The IR_SENDHEADER is being sent upon connection to exchange
	// basic information. The version is most important. If the
	// versions don't match then synchronization cannot continue.
	typedef struct tagIR_HEADER
	{
		u_long  ulVersion;
		u_short usLevel;
	}
	IR_HEADER;

	// The IR_SENDRECORD structure contains the required data from a
	// single item in the scorelist.
	typedef struct tagIR_SENDRECORD
	{
		u_long	ulScore;
		u_long  ulTimeStamp;
		wchar_t wszName[CTetrisScore::MaxNameLen+1];
	} 
	IR_SENDRECORD;

	// The IR_RESPONSE structure contains the response from the
	// receiving side about the score information.
	typedef struct tagIR_RESPONSE
	{
		u_short usAccepted;
	}
	IR_RESPONSE;

// Restore the structure alignment to the default value
#pragma pack(pop)

#endif	// IRDA_SUPPORT
};


#endif // __TETRIS_HIGHSCORES_DLG_H
