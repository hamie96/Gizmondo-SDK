//	TetrisWindow.h - Tetris for Pocket PC (main window)
//  Converted To Gizmondo By TheReaper 2006
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

#ifndef __TETRIS_WINDOW_H
#define __TETRIS_WINDOW_H


#include "TetrisMatrix.h"
#include "TetrisAboutDlg.h"
#include "TetrisOptionsDlg.h"
#include "TetrisHighscoresDlg.h"


class CTetrisWindow : public CWindowImpl<CTetrisWindow>, 
                      private CTetrisMatrix::CTetrisEvents
{
private:
	enum { PieceWidth  =  15 };
	enum { PieceHeight =  15 };

	enum { WM_ENDOFGAME = WM_USER };

	typedef enum
	{ 
		ActionNone,
		ActionMoveLeft, 
		ActionMoveRight, 
		ActionSoftDrop,
		ActionHardDrop,
		ActionRotateLeft, 
		ActionRotateRight, 
		ActionPauseResume,
		ActionMax
	}
	Action;
	
	typedef enum 
	{ 
		IDGameTimer = 1, 
		IDKeyTimer  = 2
	}
	Timer;

public:
	// Constructor/Destructor
	CTetrisWindow()
		: m_pTetrisMatrix(0)
		, m_hbmpBackground(0)
		, m_hbmpTetris(0)
		, m_fSound(false)
		, m_iRepeat(0)
		, m_level(CTetrisOptions::Unknown)
		, m_iBaseDelay(0)
		, m_dwScore(0)
		, m_fPause(false)
		, m_action(ActionNone)
	{
	}

	~CTetrisWindow()
	{
		delete m_pTetrisMatrix;
	}

public:
	// Define the window class
	DECLARE_WND_CLASS(_T("TetrisWnd"))

private:
	// Message map
	BEGIN_MSG_MAP(CTetrisWindow)
		// Windows message handlers
		MESSAGE_HANDLER(WM_PAINT,         OnPaint)
		MESSAGE_HANDLER(WM_TIMER,         OnTimer)
		MESSAGE_HANDLER(WM_HOTKEY,        OnHotKey)
		MESSAGE_HANDLER(WM_LBUTTONDOWN,   OnLButtonDown)
		MESSAGE_HANDLER(WM_LBUTTONUP,     OnLButtonUp)
		MESSAGE_HANDLER(WM_ACTIVATE,      OnActivate)
		MESSAGE_HANDLER(WM_SETTINGCHANGE, OnSettingChange)
		MESSAGE_HANDLER(WM_CREATE,        OnCreate)
		MESSAGE_HANDLER(WM_DESTROY,       OnDestroy)

		// Command handlers
		COMMAND_ID_HANDLER(IDC_NEWGAME,    OnNewGame)
		//COMMAND_ID_HANDLER(IDC_ABOUT,      OnAbout)
		//COMMAND_ID_HANDLER(IDC_OPTIONS,    OnOptions)
		//COMMAND_ID_HANDLER(IDC_HIGHSCORES, OnHighscores)
		COMMAND_ID_HANDLER(IDC_EXIT,       OnExit)
		COMMAND_ID_HANDLER(IDC_PAUSE,	   OnPauseResume)

		// Private message handlers
		MESSAGE_HANDLER(WM_ENDOFGAME,   OnEndOfGame)
	END_MSG_MAP()

private:

	// Windows message handlers
	LRESULT OnCreate (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Create the menu bar
		//SHMENUBARINFO mbi = {0};
		//mbi.cbSize     = sizeof(SHMENUBARINFO);
		//mbi.hwndParent = m_hWnd;
		//mbi.dwFlags    = SHCMBF_HIDESIPBUTTON;
		//mbi.nToolBarId = IDM_MENU;
		//mbi.hInstRes   = _Module.GetResourceInstance(); 
		//if (!::SHCreateMenuBar(&mbi)) 
			//return -1;

		// Save the control bar
		//m_hWndCB = mbi.hwndMB;

		// Add tooltips
		//const static LPCTSTR aszTooltips[] = 
		//{
			//0,
			//_T("New game"),
			//_T("Pause/Resume"),
			//0,
			//_T("Options"),
			//_T("Highscores"),
			//0,
			//_T("About")
		//};
        //CommandBar_AddToolTips(m_hWndCB,sizeof(aszTooltips)/sizeof(*aszTooltips),aszTooltips);

		// Add bitmaps
		const static TBBUTTON atbbuttons[] =
		{
		    {0, 0,              TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0, -1},
			{0, IDC_NEWGAME,    TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
			{1, IDC_PAUSE,      TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
		    {0, 0,              TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0, -1},
			//{2, IDC_OPTIONS,    TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
			//{3, IDC_HIGHSCORES, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
		    {0, 0,              TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0, -1},
			{4, IDC_ABOUT,      TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1}
		};
        //CommandBar_AddBitmap(m_hWndCB, _Module.GetResourceInstance(), IDB_TOOLBAR, 15, 16, 16);
        //CommandBar_AddButtons(m_hWndCB, sizeof(atbbuttons)/sizeof(*atbbuttons), atbbuttons);

		// Recalculate the layout
		LoadSkin(_T(""));

		// Start a new game
		NewGame();

		// Reset shell activation structure
		memset(&m_sai, 0, sizeof(m_sai));
        m_sai.cbSize = sizeof(m_sai);

		// Finished
		bHandled = TRUE;
		return 0;
	}

	LRESULT OnDestroy (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Release the skin
		ReleaseSkin();

		// Unregister hotkeys
		UnregisterHotkeys();

		// Call base class
		DefWindowProc();

		// Post quit message
		::PostQuitMessage(0);

		// Finished
		bHandled = TRUE;
		return 0;
	}

	LRESULT OnPaint (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Don't do anything if we don't have a matrix yet
		if (!m_pTetrisMatrix)
			return 0;

		// Obtain the device context for painting
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(&ps);

		// Create a compatible device context for the memory
		// device context and use a compatible bitmap to draw on
		HDC hdcMem = ::CreateCompatibleDC(hdc);
		HBITMAP hbmpMem = ::CreateCompatibleBitmap(hdc,320,240);
		HGDIOBJ hbmpOldMem = ::SelectObject(hdcMem,hbmpMem);

		// Create a compatible device context to select bitmaps
		HDC hdcBitmap = ::CreateCompatibleDC(hdc);

		// Draw the background into the memory DC
		HGDIOBJ hbmpBitmapOld = ::SelectObject(hdcBitmap,m_hbmpBackground);
		::BitBlt(hdcMem,0,0,320,240,hdcBitmap,0,0,SRCCOPY);

		// Select the Tetris building blocks bitmap
		::SelectObject(hdcBitmap,m_hbmpTetris);

		// Draw all bubblets
		const CTetrisMatrix::Row    rows    = m_pTetrisMatrix->GetRows();
		const CTetrisMatrix::Column columns = m_pTetrisMatrix->GetColumns();
		for (CTetrisMatrix::Row row=0; row<rows; ++row)
		{
			for (CTetrisMatrix::Column column=0; column<columns; ++column)
			{
				CTetrisMatrix::Item item = m_pTetrisMatrix->At(row,column);
				if (item == CTetrisMatrix::InvalidItem)
				{
					item = m_pTetrisMatrix->PieceAt(row,column);
				}

				if (item != CTetrisMatrix::InvalidItem)
				{
					::BitBlt(hdcMem,m_rcGame.left+PieceWidth*column,m_rcGame.bottom-PieceHeight*row-PieceHeight,PieceWidth,PieceHeight,hdcBitmap,(item-1)*PieceWidth,0,SRCCOPY);
				}
			}
		}

		// Draw "next shape"
		const CTetrisMatrix::CTetrisShape& shapeNext = m_pTetrisMatrix->GetNextShape();

		// Determine width and height of the shape
		const int iShapeWidth  = shapeNext.GetWidth();
		const int iShapeHeight = shapeNext.GetHeight();

		// Determine the width of the "next shape" rectangle
		const int iShapeRectWidth  = m_rcNextShape.right-m_rcNextShape.left;
		const int iShapeRectHeight = m_rcNextShape.bottom-m_rcNextShape.top;

		const int iLeft   = m_rcNextShape.left+iShapeRectWidth/2-(iShapeWidth*PieceWidth)/2;
		const int iBottom = m_rcNextShape.top+iShapeRectHeight/2+(iShapeHeight*PieceHeight)/2;

		for (int iRow=0; iRow<iShapeHeight; ++iRow)
		{
			for (int iColumn=0; iColumn<iShapeWidth; ++iColumn)
			{
				const CTetrisMatrix::Item item = shapeNext.At(iRow,iColumn);
				::BitBlt(hdcMem,iLeft+(iColumn*PieceWidth),
						        iBottom-(iRow*PieceHeight)-PieceHeight,
								PieceWidth,
								PieceHeight,
								hdcBitmap,
								(item-1)*PieceWidth,
								0,
								SRCCOPY);
			}
		}

		// Delete the bitmap DC
		::SelectObject(hdcBitmap,hbmpBitmapOld);		::DeleteDC(hdcBitmap);

		// All texts are drawn transparent
		::SetBkMode(hdcMem,TRANSPARENT);

		// Draw the Level
		TCHAR tszLevel[20];
		::wsprintf(tszLevel,_T("%d"), m_pTetrisMatrix->GetSpeed());
		::DrawText(hdcMem,tszLevel,-1,&m_rcLevel,DT_CENTER|DT_NOCLIP|DT_NOPREFIX|DT_SINGLELINE|DT_VCENTER);

		// Draw the score
		TCHAR tszScore[20];
		::wsprintf(tszScore,_T("%d"), m_pTetrisMatrix->GetScore());
		::DrawText(hdcMem,tszScore,-1,&m_rcScore,DT_CENTER|DT_NOCLIP|DT_NOPREFIX|DT_SINGLELINE|DT_VCENTER);

		// Draw everything on screen
		::BitBlt(hdc,ps.rcPaint.left,ps.rcPaint.top,ps.rcPaint.right-ps.rcPaint.left,ps.rcPaint.bottom-ps.rcPaint.top,hdcMem,ps.rcPaint.left,ps.rcPaint.top,SRCCOPY);

		// Delete the memory DC
		::SelectObject(hdcMem,hbmpOldMem);
		::DeleteObject(hbmpMem);
		::DeleteDC(hdcMem);

		// We're finished painting
		EndPaint(&ps);
		bHandled = TRUE;
		return 0;
	}

	LRESULT OnTimer (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		switch (wParam)
		{
		case IDGameTimer:
			{
				// Move down one time
				MoveDown(false);

				//Message handled
				bHandled = TRUE;
			}
			break;

		case IDKeyTimer:
			{
				// Handle current action
				HandleAction();

				//Message handled
				bHandled = TRUE;
			}
			break;
		}

		return 0;
	}

	LRESULT OnActivate (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		if (LOWORD(wParam) == WA_INACTIVE)
		{
			// If the game wasn't paused already,
			// then we need to suspend the game.
			if (!m_fPause)
				StopTimer(IDGameTimer);

			// Unregister hotkeys
			UnregisterHotkeys();
		}
		else
		{
			// If the game is not in pause mode,
			// then we resume the game when it is
			// active again
			if (!m_fPause)
				StartTimer(IDGameTimer);

			// Register hotkeys
			RegisterHotkeys();
		}

		// Pass the message to the shell
		::SHHandleWMActivate(m_hWnd, wParam, lParam, &m_sai, FALSE);

		// Not handled completely
		bHandled = FALSE;
		return 0;
	}

	LRESULT OnSettingChange (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Pass the message to the shell
		::SHHandleWMSettingChange(m_hWnd, wParam, lParam, &m_sai);

		// Not handled completely
		bHandled = FALSE;
		return 0;
	}

private:
	LRESULT OnHotKey (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Check a key is pressed
		if (::GetAsyncKeyState(m_avkCodes[wParam]) & (1<<30))
		{
			// Key is pressed. Check wether it is repeating or not
			if (Action(wParam) != m_action)
				StartAction(Action(wParam));
		}
		else
		{
			StopAction();
		}

		// Finished
		bHandled = TRUE;
		return 0;
	}

	LRESULT OnLButtonDown (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		const int iPosX = LOWORD(lParam);
		const int iPosY = HIWORD(lParam);

		// Check if the user tapped above the game area
		if (iPosY <= m_rcGame.top)
		{
			StartAction(ActionRotateRight);
		}

		// Check if the user tapped below the game area
		else if (iPosY >= m_rcGame.bottom)
		{
			StartAction(ActionSoftDrop);
		}

		// Check if the user tapped left from the game area
		else if (iPosX <= m_rcGame.left)
		{
			StartAction(ActionMoveLeft); 
		}

		// Check if the user tapped right from the game area
		else if (iPosX >= m_rcGame.right)
		{
			StartAction(ActionMoveRight); 
		}

		// The user probably tapped somewhere in the game area
		else
		{
			const CTetrisMatrix::CTetrisShape& shapeNext = m_pTetrisMatrix->GetNextShape();

			// Determine width and height of the shape
			const int iShapeX = (m_pTetrisMatrix->GetShapeColumn()*PieceWidth) + (shapeNext.GetWidth()*PieceWidth/2) + m_rcGame.left;
			const int iShapeY = m_rcGame.bottom - m_pTetrisMatrix->GetShapeRow()*PieceHeight + (shapeNext.GetHeight()*PieceHeight/2);

			// Check differences between tap and shape
			const int iDiffX = iPosX - iShapeX;
			const int iDiffY = iPosY - iShapeY;

			// Check if the user tapped left of the piece
			if (abs(iDiffX) >= abs(iDiffY))
			{
				// It's a horizontal move
				StartAction((iDiffX<0)?ActionMoveLeft:ActionMoveRight); 
			}
			else
			{
				// It's a vertical move
				StartAction((iDiffY<0)?ActionRotateRight:ActionSoftDrop); 
			}
		}

		// Message is handled
		bHandled = TRUE;
		return 0;
	}

	LRESULT OnLButtonUp (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		StopAction();

		bHandled = TRUE;
		return 0;
	}

private:
	// Private message handlers
	LRESULT OnEndOfGame (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Disable key-repeat
		StopTimer(IDKeyTimer);

		// Stop action
		StopAction();

		// Load default scores
		//CTetrisScore bubblesScore;
		//bubblesScore.Load(m_level);

		// Remember last score
		//m_dwScore = m_pTetrisMatrix->GetScore();

		// Display high-score dialog
		//CTetrisHighscoresDlg dlgTetrisHighscores(m_dwScore>0,m_dwScore);
		//dlgTetrisHighscores.DoModal();
	
	
		// Restart the game
		NewGame(true);

		// Message handled successfully
		bHandled = TRUE;
		return 0;
	}

private:
	// Command handlers
	LRESULT OnNewGame (WORD wNotifyCode, WORD nID, HWND hwndCtl, BOOL& bHandled)
	{
		// Start a new game
		NewGame();

		// Message handled successfully
		bHandled = TRUE;
		return 0;
	}

	//LRESULT OnAbout (WORD wNotifyCode, WORD nID, HWND hwndCtl, BOOL& bHandled)
	//{
		// Display about window
		//About();

		// Message handled successfully
		//bHandled = TRUE;
		//return 0;
	//}

	LRESULT OnOptions (WORD wNotifyCode, WORD nID, HWND hwndCtl, BOOL& bHandled)
	{
		// Display options screen
		Options();

		// Message handled successfully
		bHandled = TRUE;
		return 0;
	}

	LRESULT OnHighscores (WORD wNotifyCode, WORD nID, HWND hwndCtl, BOOL& bHandled)
	{
		// Display the highscores
		Highscores();

		// Message handled successfully
		bHandled = TRUE;
		return 0;
	}

	LRESULT OnExit (WORD wNotifyCode, WORD nID, HWND hwndCtl, BOOL& bHandled)
	{
		// Exit the application
		Exit();

		// Message handled successfully
		bHandled = TRUE;
		return 0;
	}

	LRESULT OnPauseResume (WORD wNotifyCode, WORD nID, HWND hwndCtl, BOOL& bHandled)
	{
		// Pause/resume the application
		PauseResume();

		// Message handled successfully
		bHandled = TRUE;
		return 0;
	}

private:
	bool IsGameActive() const
	{
		// A game is active, when a game is loaded and
		// the user already made some moves, but
		// the game hasn't ended yet.
		return (m_pTetrisMatrix != 0);
	}

	bool LoadSkin (LPCTSTR lptszDirectory)
	{
		// Set game rectangle
		m_rcGame.left   = 10;
		m_rcGame.top    = 10;
		m_rcGame.right  = 160;
		m_rcGame.bottom = 250;

		// Set next shape rectangle
		m_rcNextShape.left   = 171;
		m_rcNextShape.right  = 231;
		m_rcNextShape.top    = 9;
		m_rcNextShape.bottom = 71;

		// Set level rectangle
		m_rcLevel.left   = 171;
		m_rcLevel.right  = 231;
		m_rcLevel.top    = 176;
		m_rcLevel.bottom = 199;

		// Set score rectangle
		m_rcScore.left   = 171;
		m_rcScore.right  = 231;
		m_rcScore.top    = 201;
		m_rcScore.bottom = 224;

		// Load the bitmaps
		m_hbmpBackground = ::LoadBitmap(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDB_BACKGROUND));
		m_hbmpTetris     = ::LoadBitmap(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDB_TETRIS));

		// Set the application's icon		
		SetIcon(::LoadIcon(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDI_TETRIS)));

		// Skin loaded successfully
		return true;
	}

	bool ReleaseSkin ()
	{
		// Delete bitmaps
		::DeleteObject(m_hbmpTetris);
		::DeleteObject(m_hbmpBackground);

		// Reset attributes
		m_hbmpTetris     = 0;
		m_hbmpBackground = 0;
	
		// Skin released successfully
		return true;
	}

	void StartTimer (const Timer timer)
	{
		switch (timer)
		{
		case IDGameTimer:
			SetTimer(IDGameTimer,m_iBaseDelay-(m_pTetrisMatrix->GetSpeed()-1)*(m_iBaseDelay/10));
			break;

		case IDKeyTimer:
			SetTimer(IDKeyTimer,1000/m_iRepeat);
			break;

		default:
			ATLASSERT(false);
			break;
		}
	}

	void StopTimer (const Timer timer)
	{
		KillTimer(timer);
	}

	void StartAction (Action action)
	{
		// Determine if the action needs to be repeated
		if (m_iRepeat)
		{
			bool fRepeat = false;
			switch (action)
			{
			case ActionMoveLeft:
			case ActionMoveRight:
			case ActionSoftDrop:
				// Key is pressed
				StartTimer(IDKeyTimer);
				break;

			case ActionRotateLeft:
			case ActionRotateRight:
			case ActionHardDrop:
			case ActionPauseResume:
				// No need to do anything
				break;

			default:
				ATLASSERT(false);
				break;
			}
		}

		// Set current action
		m_action = action;

		// Perform the action
		HandleAction();
	}

	void StopAction ()
	{
		// Stop timer (even if it wasn't running)
		StopTimer(IDKeyTimer);

		// Reset action attribute
		m_action = ActionNone;
	}

	void HandleAction ()
	{
		switch (m_action)
		{
		case ActionMoveLeft:     MoveLeft();       break;
		case ActionMoveRight:    MoveRight();      break;
		case ActionSoftDrop:     MoveDown(true);   break;
		case ActionHardDrop:     Drop();           break;
		case ActionRotateLeft:   RotateLeft();     break;
		case ActionRotateRight:  RotateRight();    break;
		case ActionPauseResume:  PauseResume();    break;
		default:                 ATLASSERT(false); break;
		}
	}

public:
	bool Create ()
	{
		// Obtain the window size
		RECT rcDesktop = { 0 };
		::GetWindowRect(::GetDesktopWindow(),&rcDesktop);

		// Try to create the main window
		TCHAR tszTitle[100];
		::LoadString(_Module.GetResourceInstance(),IDS_TETRIS_TITLE,tszTitle,sizeof(tszTitle)/sizeof(TCHAR));
		if (!CWindowImpl<CTetrisWindow>::Create(0,rcDesktop,tszTitle,WS_VISIBLE))
			return false;

		// Return successful
		return true;
	}

	bool MoveLeft ()
	{
		// Cannot move when paused
		if (m_fPause)
			return false;

		// Move left (if possible)
		if (!m_pTetrisMatrix->MoveSideways(CTetrisMatrix::Left))
		{
			// Stop the key-repeat
			StopTimer(IDKeyTimer);
			return false;
		}

		// Invalidate game rectangle
		InvalidateRect(&m_rcGame,FALSE);
		return true;
	}

	bool MoveRight ()
	{
		// Cannot move when paused
		if (m_fPause)
			return false;

		// Move left (if possible)
		if (!m_pTetrisMatrix->MoveSideways(CTetrisMatrix::Right))
		{
			// Stop the key-repeat
			StopTimer(IDKeyTimer);
			return false;
		}

		// Invalidate game rectangle
		InvalidateRect(&m_rcGame,FALSE);
		return true;
	}

	bool RotateLeft ()
	{
		// Rotate left (if possible)
		if (m_fPause || !m_pTetrisMatrix->Rotate(CTetrisMatrix::Left))
			return false;

		// Play sound
		if (m_fSound)
			::PlaySound(MAKEINTRESOURCE(IDR_WAVE_ROTATE),_Module.GetResourceInstance(),SND_RESOURCE|SND_ASYNC);

		// Invalidate game rectangle
		InvalidateRect(&m_rcGame,FALSE);
		return true;
	}

	bool RotateRight ()
	{
		// Rotate left (if possible)
		if (m_fPause || !m_pTetrisMatrix->Rotate(CTetrisMatrix::Right))
			return false;

		// Play sound
		if (m_fSound)
			::PlaySound(MAKEINTRESOURCE(IDR_WAVE_ROTATE),_Module.GetResourceInstance(),SND_RESOURCE|SND_ASYNC);

		// Invalidate game rectangle
		InvalidateRect(&m_rcGame,FALSE);
		return true;
	}

	bool MoveDown (const bool fManual)
	{
		// We cannot move when in Pause mode
		if (m_fPause)
			return false;

		// Move the piece
		if (m_pTetrisMatrix->MoveDown(fManual))
		{
			// Check wether the shape has hit the bottom
			if (!m_pTetrisMatrix->CanDrop())
			{
				// Stop the key-repeat
				StopTimer(IDKeyTimer);

				// Play sound
				if (m_fSound)
					::PlaySound(MAKEINTRESOURCE(IDR_WAVE_HITBOTTOM),_Module.GetResourceInstance(),SND_RESOURCE|SND_ASYNC);
			}
		}

		// Check if game has ended
		if (m_pTetrisMatrix->IsGameOver())
		{
			KillTimer(IDGameTimer);
			PostMessage(WM_ENDOFGAME);
		}

		// Invalidate rectangle
		InvalidateRect(&m_rcGame,FALSE);
		return true;
	}

	bool Drop ()
	{
		// We cannot move when in Pause mode
		do
		{
			// Try to move down
			if (!MoveDown(true))
				return false;
		}
		while (m_pTetrisMatrix->CanDrop());
		
		// Succes
		return true;
	}

	bool PauseResume ()
	{
		if (m_fPause)
		{
			// Start timer
			StartTimer(IDGameTimer);

			// Set title bar text
			::SHSetNavBarText(m_hWnd,_T("Tetris"));

			// Disable pause mode
			m_fPause = false;
		}
		else
		{
			// Stop timer
			StopTimer(IDGameTimer);

			// Set title
			::SHSetNavBarText(m_hWnd,_T("Tetris (Paused)"));

			// Enable pause mode
			m_fPause = true;
		}

		return true;
	}

	bool NewGame (const bool fForceRestart = false)
	{
		// Check whether the user is already busy playing
		if (!fForceRestart && IsGameActive())
		{
			// Ask if the user really wants to restart the game
			if (MessageBox(_T("The current game isn't finished yet. Do you really want to start a new game?"),_T("New game"),MB_YESNO) == IDNO)
				return false;
		}

		// Delete the current game
		delete m_pTetrisMatrix;

		// Load the game options
		LoadOptions(true);

		// Create a new bubblet matrix
		m_pTetrisMatrix = new CTetrisMatrix(16,10);
		m_pTetrisMatrix->Subscribe(this);

		// If game is in pause, then we need to resume the game
		if (m_fPause)
			PauseResume();

		// Start the game timer
		StartTimer(IDGameTimer);

		// Update the entire client area
		Invalidate();
		return true;
	}

	bool About ()
	{
		// Display the about box
		CTetrisAboutDlg dlgTetrisAbout;
		dlgTetrisAbout.DoModal(m_hWnd);
		return true;
	}

	bool Options ()
	{
		{
			// Display the options dialog. This should be
			// done within it's own context, otherwise the
			// dialog's save routine hasn't been called yet.
			// TODO: Change save options mechanism
			CTetrisOptionsDlg dlgTetrisOptions;
			if (!dlgTetrisOptions.DoModal(m_hWnd))
				return false;
		}

		// If the game hasn't started yet, then we
		// start a new game. Otherwise, we only
		// update the dynamic options.
		if (!IsGameActive())
		{
			// Restart the game
			NewGame();
		}
		else
		{
			// Unregister the current keys
			UnregisterHotkeys();

			// Update the dynamic options
			LoadOptions(false);

			// Register the new loaded keys
			RegisterHotkeys();
		}

		return true;
	}

	void Highscores ()
	{
		// Display the options dialog
		CTetrisHighscoresDlg dlgTetrisHighscores(false,0);
		dlgTetrisHighscores.DoModal(m_hWnd);
	}

	bool Exit ()
	{
		// Destroy the window
		DestroyWindow();
		return true;
	}

public:
	static bool Reactivate ()
	{
		// Determine window name
		TCHAR tszTitle[100];
		::LoadString(_Module.GetResourceInstance(),IDS_TETRIS_TITLE,tszTitle,sizeof(tszTitle)/sizeof(TCHAR));

		// Find the existing window
		HWND hwnd = ::FindWindow(GetWndClassInfo().m_wc.lpszClassName,tszTitle);
		if (!hwnd)
			return false;

		// Activate the actual application current window. Thanks to
		// "kbarnett@ozemail.com.au" for pointing out how to activate
		// the application's current window. This nasty method should
		// be used, because with an ordinary SetForegroundWindow(hwnd)
		// the main window is activated, which is wrong when there is
		// an active dialog.
		::SetForegroundWindow(HWND(DWORD(hwnd)|1));
		return true;
	}

	void RowDeleted (const CTetrisMatrix::Row row)
	{
		// NOP
	}

	void SpeedChange (const CTetrisMatrix::Speed speedNew)
	{
		// We cannot be in pause at this moment
		ATLASSERT(!m_fPause);

		// Reset the timer
		StartTimer(IDGameTimer);

		// Update the level rectangle
		InvalidateRect(&m_rcLevel,FALSE);
	}

	void ScoreChange (const int iScore)
	{
		// We cannot be in pause at this moment
		ATLASSERT(!m_fPause);

		// Update the score rectangle
		InvalidateRect(&m_rcScore,FALSE);
	}

	void NextShapeChange (const CTetrisMatrix::CTetrisShape& shapeNext)
	{
		// We cannot be in pause at this moment
		ATLASSERT(!m_fPause);

		// Update the level rectangle
		InvalidateRect(&m_rcNextShape,FALSE);
	}

	void RegisterHotkeys ()
	{
		// Register the hotkeys
		for (int action=1; action<ActionMax; ++action)
		{
			const UINT vkCode = m_avkCodes[action];
			if (vkCode)
			{
				if (vkCode>=0xC1 && vkCode<=0xC5)
					::RegisterHotKey(m_hWnd,action,MOD_KEYUP|MOD_WIN,vkCode);
				else
					::RegisterHotKey(m_hWnd,action,MOD_KEYUP,vkCode);
			}
		}
	}

	void UnregisterHotkeys ()
	{
		// Unregister the hotkeys
		for (int action=1; action<ActionMax; ++action)
		{
			const UINT vkCode = m_avkCodes[action];
			if (vkCode)
			{
				::UnregisterHotKey(m_hWnd,action);
			}
		}
	}

	void LoadOptions (const bool fAllOptions)
	{
		// Obtain the options
		CTetrisOptions tetrisOptions;
		m_fSound  = tetrisOptions.GetSound();
		m_iRepeat = tetrisOptions.GetRepeat();

		// Obtain the key-mapping
		m_avkCodes[ActionMoveLeft   ] = tetrisOptions.GetKeyCode(CTetrisOptions::ActionMoveLeft   );
		m_avkCodes[ActionMoveRight  ] = tetrisOptions.GetKeyCode(CTetrisOptions::ActionMoveRight  );
		m_avkCodes[ActionRotateLeft ] = tetrisOptions.GetKeyCode(CTetrisOptions::ActionRotateLeft );
		m_avkCodes[ActionRotateRight] = tetrisOptions.GetKeyCode(CTetrisOptions::ActionRotateRight);
		m_avkCodes[ActionSoftDrop   ] = tetrisOptions.GetKeyCode(CTetrisOptions::ActionSoftDrop   );
		m_avkCodes[ActionHardDrop   ] = tetrisOptions.GetKeyCode(CTetrisOptions::ActionHardDrop   );
		m_avkCodes[ActionPauseResume] = tetrisOptions.GetKeyCode(CTetrisOptions::ActionPauseResume);
        
		// Obtain the non-dynamic options as well
		if (fAllOptions)
		{
			m_level      = tetrisOptions.GetLevel();
			m_iBaseDelay = tetrisOptions.GetDelay();
		}
	}

private:
	// Shell activation info
	SHACTIVATEINFO m_sai;

	// The actual game object
	CTetrisMatrix* m_pTetrisMatrix;

	// Cached bubbled bitmap
	HBITMAP m_hbmpTetris;
	HBITMAP m_hbmpBackground;

	// Rectangles within our window
	RECT	m_rcGame;
	RECT	m_rcNextShape;
	RECT	m_rcScore;
	RECT	m_rcLevel;

	// Game options
	CTetrisOptions::Level	m_level;
	bool					m_fSound;
	int						m_iRepeat;
	int						m_iBaseDelay;
	bool					m_fPause;
	UINT					m_avkCodes[ActionMax];

	// Current action
	Action m_action;

	// Last known score
	DWORD m_dwScore;
};

#endif // __TETRIS_WINDOW_H
