#include "shell.h"
#include "VideoItem.h"
#include "bitmapUtilities.h"
#include "MovieBrowser.h"
#include "pm.h"
#include "batterycontrol.h"

/////////////////////////////////////////////////////////////////////////////////////
//VideoItem constructor
//
VideoItem::VideoItem()
{
	// Initialise all variables
	m_type = VIDEO_ITEM;

	// clear all pointers
	pMP = NULL;
	pMS = NULL;
	pGB = NULL;
	pVW = NULL;
	pBV = NULL;
	pME = NULL;
	pMC = NULL;
	pBA = NULL;

	// no thread when starting
	m_videoThread = NULL;
	m_killedThread=TRUE;
	m_killThread=FALSE;

	// uninitialised
	m_videoState = VS_UNINITIALISED;

	// not full screen
	m_fullScreen = FALSE;

	// don't auto play
	m_playOnOpen = FALSE;

	// pause in background, else video is stopped when menu is quit
	m_backgroundPause = FALSE;
	
	// user isn't currently adjusting the volume
	m_continuePlayOnMenuExit = FALSE;

	// no movie browser to start with
	m_movieBrowser = NULL;

	// set theupdate rect to zero
	memset(&m_updateRect, 0, sizeof(m_updateRect));

	// no playback info window by default
	m_currentPlayPosWindow = NULL;

	// set last update time
	m_lastUpdateTime=0;
	m_updateInteval=500;	// twice a second

	m_busy = FALSE;

	// create a mutex for changing video state states
	m_videoStateMutex = CreateMutex(NULL, FALSE, NULL);

	// current play position
	m_lastPercentagePlayed = 0;
	*(gShell->GetShellOptions()->GetAttribute(SD_VideoPlayPosition))=0;

	m_repeat = FALSE;
}

/////////////////////////////////////////////////////////////////////////////////////
//Destructor
//
VideoItem::~VideoItem()
{
	// clean up
	//
	CleanupInterfaces();

	// Close mutex
	CloseHandle(m_videoStateMutex);
}

/////////////////////////////////////////////////////////////////////////////////////
//Paint Scrolling Text
//
void	VideoItem::Paint(HDC hDC, RECT& rt, int x, int y, ItemState menuState)
{
	// skip to maximize throughput if nothing to draw
//	if (m_updateRect.top == 0 && m_updateRect.bottom ==0)
//		return;

	if (m_fullScreen)
	{
		// do this once then set the update area to 0
		//
		BitBlt(hDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL, 0,0,BLACKNESS);
	}
	else
	{
		// blit the whole area black
		//
		BitBlt(hDC, m_posX, m_posY, m_sizeX, m_sizeY, NULL, 0,0,BLACKNESS);
	}

	// fill in the update rectangle, this is now nothing
	//
	m_updateRect.top = 0;
	m_updateRect.bottom = 0;
	m_updateRect.left = 0;
	m_updateRect.right = 0;

	if (m_fullScreen)
	{
		if (gShell->GetCurrentMenu() == (Menu*)this->pParent)
		{
			// full screen have timer only running at 1fps to get the most out of the system!
			gShell->StopTimer();
			gShell->StartTimer(1);
		}
	}
}

////////////////////////////////////////////////////////////////////////
// get area this control coveres
//
void VideoItem::GetUpdateRect(RECT* rt, DWORD currentTime)
{
	long evCode = 0;
		
	RETAILMSG(DBGMODE_MID, (TEXT("VideoItem::GetUpdateRect \r\n")));

	// update the video info
	UpdateTrackInfo();

	// copy in the update rect of the last draw
	memcpy(rt, &m_updateRect, sizeof(m_updateRect));
}

// Update the current play position and slider control for video positioning
//
void VideoItem::UpdateTrackInfo()
{
	WCHAR time[100];

	if (GetTickCount() > (m_lastUpdateTime + m_updateInteval))
	{
		// wait for any seek location, or take it as granted we're ok if 
		// paused!
		if (m_videoState == VS_PAUSED || WaitForReady() )
		{
			// are we currently playing, and not just in integrate mode only?
			//
			if (m_videoState == VS_PLAYING || m_videoState == VS_PAUSED)
			{
				DWORD pos = GetPlaybackPosition();
				DWORD len = GetPlaybackLength();

				// little alternating variable
				static BOOL bFlash=TRUE;
				bFlash=!bFlash;

				if (pos > 0 && len > 0)
				{
					// If playing OR cycle 0/1 of our flashing when paused then display the track info
					//
					if ((m_videoState == VS_PAUSED && bFlash) || m_videoState == VS_PLAYING)
					{
						// compose the string
						wsprintf(time, (TEXT("%d:%.2d/%d:%.2d")), pos/60,pos%60, len/60, len%60);
					}
					else
					{
						// compose the string of nothing!
						wsprintf(time, (TEXT("--/--")));				
					}

					int percentagePlayed = (pos * 100) / len;

					// update the play position in the shell attributes
					*(gShell->GetShellOptions()->GetAttribute(SD_VideoPlayPosition)) = percentagePlayed;

					// remember this!
					m_lastPercentagePlayed = percentagePlayed;
				}
				else
				{
					// compose the string of nothing!
					wsprintf(time, (TEXT("")));				
				}
			}
			else
			{
				// compose the string
				wsprintf(time, TEXT(""));
			}
		}
		else
		{
			// compose the string of nothing!
			wsprintf(time, (TEXT("")));				
		}
		
		// set the new controls text if available
		if (m_currentPlayPosWindow)
			m_currentPlayPosWindow->ProcessAction(TB_SETTEXT, CString(time));

		// set the time we've updated the control
		m_lastUpdateTime = GetTickCount();
	}


	if (m_videoState == VS_PLAYING)
	{
		// poll the backlight driver, this forces it on! (else after 15 seconds it will
		// turn off...)
		//gShell->NormalBacklight();
		//RETAILMSG(1, (TEXT("Pinging backlight...\r\n")));

		// keep power on inc the backlight
		gShell->GetBatteryControl()->ForcePowerOn(TRUE);
	}

	// is the track valid?
	if (GetPlaybackLength() != 0)
	{
		// are we at the end of the track?
		if (GetPlaybackPosition() == GetPlaybackLength())
			TrackFinished();
	}
}

// End of the movie track
//
void VideoItem::TrackFinished()
{
	RETAILMSG(1, (TEXT("Movie finished! \r\n")));

	if (m_repeat)
	{
		// just repeat
		PlayMovie();
	}
	else
	{
		// switch out of full screen if we're in it
		if (m_fullScreen)
		{
			ToggleFullScreen();
		}

		// close down video
		CleanupInterfaces();

		// If we're in smartAdd mode then go back a menu, this will take us
		// to the menu the user actually wanted to go to rather than the smartAdd !
		if (m_smartAddMode)
		{
			m_continuePlayOnMenuExit = TRUE;

			// try to find SmartAdd menu if available (to save/replay)
			//
			if (gShell->JumpToMenu(SMARTADD_MENU))
			{
				// ok we're now showing the SmartAdd menu.
				// it will handle things from here	
			}
			else
			{
				// stop on exit as there isn't a smart add menu
				m_continuePlayOnMenuExit = FALSE;

				// go back to the previous menu
				gShell->SelectPreviousMenu();
			}
		}
		
		EnableItems(VS_STOPPED);
		
		// enable the movie browser component if available
		//if (m_movieBrowser)
			//m_movieBrowser->Enable(TRUE);
	}
}

void VideoItem::EnableItems(VideoState state)
{
	switch(state)
	{
		case VS_STOPPED:
		case VS_UNINITIALISED:
			// Enable all controls with PLAY on them
			gShell->EnableItems(TRUE, NULL, VW_PLAY);
			gShell->EnableItems(TRUE, NULL, MB_PLAYMOVIE);
			gShell->EnableItems(FALSE, NULL, VW_PAUSE); 
			gShell->EnableItems(FALSE, NULL, VW_STOP); 
			gShell->EnableItems(FALSE, NULL, VW_FULLSCREEN); 
			gShell->EnableItems(FALSE, NULL, VW_PREVTRACK); 
			gShell->EnableItems(FALSE, NULL, VW_NEXTTRACK); 
			// enable the movie browser component if available
			//if (m_movieBrowser)
			//	m_movieBrowser->Enable(TRUE);

			m_busy = FALSE;

			m_lastPercentagePlayed = 0;
			*(gShell->GetShellOptions()->GetAttribute(SD_VideoPlayPosition)) = 0;


			break;
		case VS_PLAYING:
		case VS_INITIALISING:
			// Enable all controls related to video
			gShell->EnableItems(FALSE, NULL, VW_PLAY); 
			gShell->EnableItems(FALSE, NULL, MB_PLAYMOVIE);
			gShell->EnableItems(TRUE, NULL, VW_PAUSE); 
			gShell->EnableItems(TRUE, NULL, VW_STOP); 
			gShell->EnableItems(TRUE, NULL, VW_FULLSCREEN); 
			gShell->EnableItems(TRUE, NULL, VW_PREVTRACK); 
			gShell->EnableItems(TRUE, NULL, VW_NEXTTRACK); 

			// disable the movie browser component if available
			//if (m_movieBrowser)
			//	m_movieBrowser->Enable(FALSE);
			break;
		case VS_PAUSED:
			// Enable all controls related to video
			gShell->EnableItems(TRUE, NULL, VW_PLAY); 
			gShell->EnableItems(TRUE, NULL, MB_PLAYMOVIE);
			gShell->EnableItems(FALSE, NULL, VW_PAUSE); 
			gShell->EnableItems(TRUE, NULL, VW_STOP); 
			gShell->EnableItems(FALSE, NULL, VW_FULLSCREEN); 
			gShell->EnableItems(TRUE, NULL, VW_PREVTRACK); 
			gShell->EnableItems(TRUE, NULL, VW_NEXTTRACK); 

			m_busy = FALSE;

			// disable the movie browser component if available
			//if (m_movieBrowser)
			//	m_movieBrowser->Enable(FALSE);
			break;
		default:
			break;
	}

	// find any paused icon on the screen and show/hide it
	Item* pausedIcon = gShell->FindNamedItem(NULL, VIDEO_PAUSED);
	if (pausedIcon)
		pausedIcon->Show(IsPaused());
	// find any playing icon on the screen and show/hide it
	Item* playingIcon = gShell->FindNamedItem(NULL, VIDEO_PLAYING);
	if (playingIcon)
		playingIcon->Show(IsPlaying() || IsInitialising());
	// find any stopped icon on the screen and show/hide it
	Item* stoppedIcon = gShell->FindNamedItem(NULL, VIDEO_STOPPED);
	if (stoppedIcon)
		stoppedIcon->Show(!IsPaused() && !IsPlaying() && !IsInitialising());
	// find any seeking icon on the screen and show/hide it
	Item* seekingIcon = gShell->FindNamedItem(NULL, VIDEO_SEEKING);
	if (seekingIcon)
		seekingIcon->Show(m_busy);
	
	// allow suspend again if not playing!
/*	if (!IsPlaying())
	{
		// are we the current menu? Then unforce the power..
		if (gShell->GetCurrentMenu() == (Menu*) this->pParent)
			gShell->GetBatteryControl()->UnForcePowerOn();
	}
	else
		gShell->GetBatteryControl()->ForcePowerOn(TRUE);
*/

	// Select the first item if the state has changed
	//gShell->SelectFirstItem();

	m_updateRect.top = 0;
	m_updateRect.bottom = SCREEN_HEIGHT;
	m_updateRect.left = 0;
	m_updateRect.right = SCREEN_WIDTH;
	gShell->InvalidateArea(m_updateRect);
}

// Get track length
//
DWORD VideoItem::GetPlaybackLength()
{
	if (pMP)
	{
		HRESULT hr;
		double duration = 0.0;

		hr = pMP->get_Duration(&duration);

		if (!FAILED(hr)) 
		{
			return (DWORD) duration;	
		}
	}
	return 0;
}

// Get playback position
DWORD VideoItem::GetPlaybackPosition()				
{
	if (pMP)
	{
		HRESULT hr;
		double current = 0.0;

		hr = pMP->get_CurrentPosition(&current);

		if (!FAILED(hr)) 
		{
			return (DWORD) current;	
		}
	}

	return 0;
}


////////////////////////////////////////////////////////////////////////
// Set area this control coveres
//
void VideoItem::SetUpdateRect()
{
	if (!m_fullScreen)
	{
		m_updateRect.top = m_posY;
		m_updateRect.bottom = m_posY+m_sizeY;
		m_updateRect.left = m_posX;
		m_updateRect.right = m_posX+m_sizeX;
	}
	else
	{
		m_updateRect.top = 0;
		m_updateRect.bottom = SCREEN_HEIGHT;
		m_updateRect.left = 0;
		m_updateRect.right = SCREEN_WIDTH;
	}
}

//////////////////////////////////////////////////////////////////////
// Parse the XML for this item
//
void VideoItem::ParseXMLAttribute(LPCTSTR szAttributeTag, LPCTSTR szAttribute)
{
	if (_wcsicmp(szAttributeTag, TEXT("videoFile")) == 0)
	{
		m_videoFile = szAttribute;
		m_playOnOpen = TRUE;	// start playing automatically
	}
	else if (_wcsicmp(szAttributeTag, TEXT("backgroundPause")) == 0)
	{
		if (_wcsicmp(szAttribute, TEXT("true"))== 0)
			m_backgroundPause = TRUE;
		else if (_wcsicmp(szAttribute, TEXT("yes"))== 0)
			m_backgroundPause = TRUE;
		else if (_wcsicmp(szAttribute, TEXT("y"))== 0)
			m_backgroundPause = TRUE;
	}
	else if (_wcsicmp(szAttributeTag, TEXT("repeat")) == 0)
	{
		if (_wcsicmp(szAttribute, TEXT("true"))== 0)
			m_repeat = TRUE;
		else if (_wcsicmp(szAttribute, TEXT("yes"))== 0)
			m_repeat = TRUE;
	}
	else
	{
		// Pass onto base class
		Item::ParseXMLAttribute(szAttributeTag,szAttribute);
	}
}


#define JIF(x) if (FAILED(hr=(x))) \
    {RETAILMSG(1, (TEXT("FAILED(0x%x) ") TEXT(#x) TEXT("\n"), hr)); goto CLEANUP;}

#define LIF(x) if (FAILED(hr=(x))) \
    {RETAILMSG(1, (TEXT("FAILED(0x%x) ") TEXT(#x) TEXT("\n"), hr)); }

#define RELEASE(i) {if (i) i->Release(); i = NULL;}

HRESULT VideoItem::GetInterfaces(void)
{
    HRESULT hr = S_OK;

	JIF(CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC, IID_IGraphBuilder, (void **)&pGB));
	JIF(pGB->QueryInterface(IID_IMediaControl,  (void **)&pMC));
	JIF(pGB->QueryInterface(IID_IMediaSeeking,  (void **)&pMS));
	JIF(pGB->QueryInterface(IID_IMediaPosition, (void **)&pMP));
	JIF(pGB->QueryInterface(IID_IVideoWindow,   (void **)&pVW));
	JIF(pGB->QueryInterface(IID_IBasicVideo,    (void **)&pBV));
	JIF(pGB->QueryInterface(IID_IMediaEventEx,  (void **)&pME));
	JIF(pGB->QueryInterface(IID_IBasicAudio,	(void **)&pBA));
	
    return S_OK;

CLEANUP:
    CleanupInterfaces();
    return(hr);
}

// Destroy any video interfaces we have
//
void VideoItem::CleanupInterfaces(BOOL force)
{
	if (m_videoState != VS_UNINITIALISED)
	{
		int tries=30;

		// Wait until the video thread has terminated itself
		while(m_videoThread && !force && tries--)
		{
			m_killThread = TRUE;
			RETAILMSG(1, (TEXT("Waiting for video worker thread to quit...\r\n")));
			Sleep(50);
		}

		// wait for the mutex
		if (WaitForSingleObject(m_videoStateMutex, 30000) == WAIT_OBJECT_0)
		{
			if (pGB)
				RELEASE(pGB);
			if (pMC)
				RELEASE(pMC);
			if (pMS)
				RELEASE(pMS);
			if (pMP)
				RELEASE(pMP);
			if (pVW)
				RELEASE(pVW);
			if (pBV)
				RELEASE(pBV);
			if (pME)
				RELEASE(pME);	
			if (pBA)
				RELEASE(pBA);	

			// clear all pointers
			pMP = NULL;
			pMS = NULL;
			pGB = NULL;
			pVW = NULL;
			pBV = NULL;
			pME = NULL;
			pMC = NULL;
			pBA = NULL;

			// uninitialised
			m_videoState = VS_UNINITIALISED;

			// release the mutex again
			ReleaseMutex(m_videoStateMutex);
		}
	}
}

// Toggle full screen
//
HRESULT VideoItem::ToggleFullScreen(void)
{
    HRESULT hr=S_OK;
    static HWND hDrain=0;
    BOOL bPausedForTransition=FALSE;

	// if some video is loaded
	if (m_videoState != VS_UNINITIALISED)
	{
		// Don't bother with full-screen for audio-only files
		if (!pVW)
			return S_OK;

		// invert current selection
		m_fullScreen=!m_fullScreen;
		
		// update
		ResizeAndCenter();

		// ensure shell has focus
		SetFocus(gShell->GetMainWindow());

		// non full screen allow a 1/10 sec timer (1/3 full speed)
		// (the stop is after the paint otherwise)
		if (!m_fullScreen)
		{
			gShell->StartTimer(10);
		}
		else
			gShell->StartTimer(1);
	}

    return hr;
}

// Mute on or off
//
HRESULT VideoItem::Mute(BOOL on)
{
    HRESULT hr;
    

	// if playing or paused
	if (m_videoState != VS_UNINITIALISED)
	{
		if (!pBA)
			return S_OK;
		
		if (on)
		{
			g_lVolume = VOLUME_SILENCE;
		}
		else
		{
			g_lVolume = VOLUME_FULL;
		}

		// Set new volume
		hr = pBA->put_Volume(g_lVolume);

		if (hr == E_NOTIMPL)
		{
			// Fail quietly if this is a video-only media file
			return hr;
		}
		else if (FAILED(hr))
		{
			RETAILMSG(1, (TEXT("Failed in pBA->get_Volume!  hr=0x%x\r\n"), hr));
			return hr;
		}
	}

    return hr;
}

// Plays movie (full screen)
//
void VideoItem::PlayMovie()
{
	HRESULT hr = S_OK;
	
	// Ensure Audio playback is stopped!
	gShell->Broadcast(NULL, MB_PAUSE, CString(""));

	// if playing or paused
	if (m_videoState != VS_UNINITIALISED)
	{
		// destroy the window
		CleanupInterfaces();
	}

	// Quick check to see if there is a thread already
	if (m_videoThread)
		RETAILMSG(1, (TEXT("Video thread already running!\r\n")));

	// Get the movie interfaces
	if (GetInterfaces() == S_OK)
	{
		// we're playing now! (or will be, we may get another paint in as it takes so long to set up the video
		//
		m_videoState = VS_INITIALISING;

		// Create a video thream
		m_videoThread = CreateThread( NULL, 
									  0, 
									  (LPTHREAD_START_ROUTINE) VideoThread, 
									  (void*) this,
									  0,0);
	}

	// disable the movie browser component if available
//	if (m_movieBrowser)
//		m_movieBrowser->Enable(FALSE);
}

// Resize the video and center when not in full screen 
//
void VideoItem::ResizeAndCenter()
{
	DWORD offsetX=0;
	DWORD offsetY=0;

	// work out the controls size 
	m_videoSize = CalculateSize(m_fullScreen);
	
	if (m_hidden)
	{
		// Set the video playback off the screen
		pVW->SetWindowPosition(640, 0,
							   16, 16);
	}
	else if (!m_fullScreen)
	{
		// do we need centering?
		if (m_videoSize.cx != m_sizeX)
			offsetX = (m_sizeX-m_videoSize.cx) / 2;

		// do we need centering?
		if (m_videoSize.cy != m_sizeY)
			offsetY = (m_sizeY-m_videoSize.cy) / 2;
		
		// make the correct size first, then the correct position..
		pVW->SetWindowPosition(640, 0,
							   m_videoSize.cx, m_videoSize.cy);

		// Set the video playback to our window
		pVW->SetWindowPosition(m_posX + offsetX, m_posY + offsetY,
							   m_videoSize.cx, m_videoSize.cy);
	}
	else
	{
		// make the correct size first, then the correct position..
		pVW->SetWindowPosition(640, 0,
							   m_videoSize.cx, m_videoSize.cy+2);

		// Set the video playback to our window
		pVW->SetWindowPosition((SCREEN_WIDTH-m_videoSize.cx)/2,
							   (SCREEN_HEIGHT-m_videoSize.cy)/2, 
							   m_videoSize.cx, m_videoSize.cy+2);		// TODO shouldn't be +2
																		// but otherwise it doesn't
																		// draw in demonstrator, maybe
																		// because of DDRAW isn't 
																		// supported?
	}

	// set the update area for the whole screen, doesn't matter if we're
	// toggling between fullscreen and a window we need to update everything
	m_updateRect.top = 0;
	m_updateRect.bottom = SCREEN_HEIGHT;
	m_updateRect.left = 0;
	m_updateRect.right = SCREEN_WIDTH;

	// force an update
	gShell->InvalidateArea(m_updateRect);
}

// Process media events directly
//
// Lifted from CEPlayit, these events should be incorporated into the main shell event loop
//
void VideoItem::ProcessEventLoopForMedia()
{
    HRESULT hr;
    BOOL bSleep=TRUE;
    
	m_killedThread=FALSE;
	m_killThread=FALSE;

	

	// Continue
    while (!m_killThread)
    {
//        MSG msg;
        LONGLONG pos=0;
        long lEventCode, lParam1, lParam2;

        // Reset sleep flag
        bSleep = TRUE;

        // Has there been a media event?  Look for end of stream condition.
        if(E_ABORT != pME->GetEvent(&lEventCode, &lParam1, &lParam2, 0))
        {
            // Free the media event resources.
            hr = pME->FreeEventParams(lEventCode, lParam1, lParam2);
            if (FAILED(hr))
            {
				RETAILMSG(1, (TEXT("...\r\n")));
			    return;
            }

			// first frame shown?
			if (lEventCode == EC_VIDEOFRAMEREADY)
			{
				m_busy = FALSE;

				// Make sure play icons are updated 
				EnableItems(m_videoState);
			}

            // Is this the end of the movie?
            if (lEventCode == EC_COMPLETE)
            {
				// start the timer again, this will spot the end of the track
				gShell->StartTimer(10);
			    return;
            }
        }

        // Give system threads time to run (and don't sample user input madly)
        if (bSleep)
            Sleep(100);

        // Check and process window messages (like our keystrokes)
        /*while (PeekMessage (&msg, gShell->GetWindow(), 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }*/
    }

	m_killThread=FALSE;
	m_killedThread=TRUE;
}

// control to preserve the ratio 
//
SIZE VideoItem::CalculateSize(BOOL fullScreen)
{
	SIZE result;
	long width, height;
	int ratio;
	HRESULT hr;
	
	// Get Window Ideal Image size, which is the normal playback size
	//
	hr = pVW->GetMaxIdealImageSize(&width, &height);

	// failed?
	if (FAILED(hr))
	{
		result.cx = SCREEN_WIDTH;
		result.cy = SCREEN_HEIGHT;	
		return result;
	}

	
	//RETAILMSG(1, (TEXT("Video image size, x=%d, y = %d \r\n"), width, height));

	// failed?
	if (width == 0 || height == 0)
		height = width = 1;
	
	// Work out a ratio of width to height
	ratio = (width*100) / height;

	// Is our video more than 1:1
	if (ratio >= 100)
	{
		// Size to specifed controls width and work out the maximum height to show
		if (!fullScreen)
			result.cx = m_sizeX;	
		else
			result.cx = SCREEN_WIDTH;	

		result.cy = (result.cx*100) / ratio;
	}
	else
	{
		// Size to specifed controls height and work out the maximum width to show
		if (!fullScreen)
			result.cy = m_sizeY;	
		else
			result.cy = SCREEN_HEIGHT;	

		result.cx = (result.cy*100) / ratio;
	}

	//RETAILMSG(1, (TEXT("Calcualted control size, x=%d, y = %d \r\n"), result.cx, result.cy));

	return result;
}


////////////////////////////////////////////////////////////////////////
//
// ProcessKey - This item can handle keypresses 
//
BOOL VideoItem::ProcessKey(KeyEnum key, int repeatCount)
{
	BOOL handled = FALSE;

	// Volume or brightnes is highest priority
	if (key==KEY_APP2 || key==KEY_APP3)
	{
		// remember we are adjusting the volume
		m_continuePlayOnMenuExit = TRUE;

		// we have not handled this (the shell will)
		handled = FALSE;
	}
	else if (m_smartAddMode)
	{
		// handle all key presses in SmartAdd mode! (apart form vol/brightness)
		handled = TRUE;
	}
	else 
	{
		// ignore
	}

	// set the update rect for the full screen
	SetUpdateRect();

	return handled;
}


// Wait for media control to be ready
BOOL VideoItem::WaitForReady()
{
	BOOL ready=FALSE;

	RETAILMSG(1, (TEXT("WaitForReady \r\n")));

	int tries=30;
	// check to make sure the control isn't inbetween states...
	do
	{
		OAFilterState state;
		HRESULT result;
	
		// wait for the mutex
		if (WaitForSingleObject(m_videoStateMutex, 30000) == WAIT_OBJECT_0)
		{
			// check to see if this is ok to proceed
			if (m_videoState == VS_UNINITIALISED || IsInitialising())
			{
				RETAILMSG(1, (TEXT("WaitForReady- \r\n")));
				ReleaseMutex(m_videoStateMutex);
				return ready;
			}

			if (pMC)
				result = pMC->GetState(1000, &state);

			if (result == S_OK)
			{
				ready=TRUE;
			}
			else
			{
//				RETAILMSG(1, (TEXT("GetState not, state = %d\r\n"), result));	
			}

			ReleaseMutex(m_videoStateMutex);
		}
	}
	while(!ready && tries--);
	
	RETAILMSG(1, (TEXT("WaitForReady-- \r\n")));

	return ready;
}

// We can handle some actions
BOOL VideoItem::ProcessAction(KeyAction action, CString& parameters, int recurseDepth)
{
	switch(action)
	{
		case VW_PAUSE:
		{
			// if playing or paused
			if (m_videoState == VS_PLAYING)
			{
				// stop playback
				if (pMC)
					pMC->Pause();

				m_videoState = VS_PAUSED;
			}

			// update menu items
			EnableItems(m_videoState);
			break;
		}
		case VW_PLAY:
		{
			if (IsPaused())
			{
				// Ensure Audio playback is stopped!
				gShell->Broadcast(NULL, MB_PAUSE, CString(""));

				// start playback
				if (pMC)
					pMC->Run();

				m_videoState = VS_PLAYING; 
			}
			else if (IsStopped())	// not running at all?
			{
				if (m_videoFile != "")
				{
					// reset the movie 
					PlayMovie();
				}
			}
			// update menu items
			EnableItems(m_videoState);
			break;
		}
		case VW_STOP:
		{
			if (IsPaused() || IsPlaying())
			{
				LONGLONG pos = 0;

				// switch out of full screen if we're in it
				if (m_fullScreen)
				{
					ToggleFullScreen();
				}

				CleanupInterfaces();

				// set the status to blank
				if (m_currentPlayPosWindow)
					m_currentPlayPosWindow->ProcessAction(TB_SETTEXT, CString(""));
			}
			// update menu items
			EnableItems(m_videoState);
			break;
		}
		
		case VW_NEXTTRACK:
			if (m_movieBrowser)
				m_movieBrowser->NextTrack();
			break;
		case VW_PREVTRACK:
			if (m_movieBrowser)
				m_movieBrowser->PrevTrack();
			break;

		case VW_FULLSCREEN:
		{ 
			// if the current menu is disappearing and we're currently opening a video then
			// wait for a conclusion before moving to the next menu
			//
			if (IsInitialising())
			{
				// wait
				while(IsInitialising())
				{
					m_killThread = TRUE;
					RETAILMSG(1, (TEXT("MENUCLOSE waiting for video thread\r\n")));
					Sleep(50);
				}
			}

			if (IsPaused() || IsPlaying())
			{
				// Check we have a video window
				if (pVW)
				{
					// toggle full screen
					ToggleFullScreen();
				}
			}
			break;
		}
		case VW_SMARTADDMODE:
		{
			// Set into smartAdd mode
			//
			m_smartAddMode = TRUE;
			break;
		}
		case VW_SMARTADDSAVE:
		{
			if (!CopyFile(m_videoFile, USER_MOVIE_INTERNAL, FALSE))
			{
				// failed to save smartAdd menu (note we have to do this as a menu as the 
				// save/replay menu items are not on the SmartAdd menu itself...
				gShell->JumpToMenu(SMARTADD_FAILEDSAVE_MENU);
			}
			else
			{
				// go back to the original screen now, saving was successful
				gShell->SelectPreviousMenu();
			}
			break;
		}
		case VW_OPENFILE:
		{
			VideoState oldState = m_videoState;

			// store the new file to be played
			m_videoFile = parameters;

			// play the movie, this will clean up as well
			//
			PlayMovie();
			
			// update menu items if changed
			if (oldState != m_videoState)
				EnableItems(m_videoState);
			break;
		}
		case MENU_OPEN:
		{
			// set the update rect for the full screen
			SetUpdateRect();

			// Make sure play icons are updated 
			EnableItems(m_videoState);

			// enable//disable menu items to our current state
			EnableItems(m_videoState);

			// reset the movie on open
			if (m_playOnOpen)
				PlayMovie();

			// Show the video window if hidden
			if (m_videoState != VS_UNINITIALISED && !IsInitialising())
			{
				m_hidden=FALSE;
				ResizeAndCenter();			
			}

			// Reduce the animations timer from 30fps to 1fps when showing video
			gShell->StopTimer();
			gShell->StartTimer(10);

			break;
		}
		case MENU_CLOSE:

			// if the current menu is disappearing and we're currently opening a video then
			// wait for a conclusion before moving to the next menu
			//
			if (IsInitialising())
			{
				// wait
				while(IsInitialising())
				{
					m_killThread = TRUE;
					RETAILMSG(1, (TEXT("MENUCLOSE waiting for video thread\r\n")));
					Sleep(50);
				}
			}

			if (m_continuePlayOnMenuExit)
			{
				// just hide the window so we carry on playing
				m_continuePlayOnMenuExit = FALSE;
			}
			else if (m_backgroundPause)
			{
				// if initialising wait!
				if (IsInitialising())
				{
					int trys=30;
					// wait for it to finish initialising..
					while(IsInitialising() && trys--)
						Sleep(100);
				}

				// if playing then paused
				if (IsPlaying())
				{
					// wait for the media control to be ready if busy
					WaitForReady();

					// stop playback
					if (pMC)
					{
						RETAILMSG(1, (TEXT("MENUCLOSE Pausing video\r\n")));
						pMC->Pause();
					}

					m_videoState = VS_PAUSED;
				}
				
				// Hide the video window
				if (m_videoState != VS_UNINITIALISED)
				{
					RETAILMSG(1, (TEXT("MENUCLOSE Hiding video window\r\n")));
					pVW->put_Visible(FALSE);
				}
			}
			else
			{
				// were we in smartAdd playback mode?
				if (m_smartAddMode)
				{
					// indicate smart ad has finished to the shell
					gShell->SmartAdFinished();

					// cancel smartAdd mode now
					m_smartAddMode = FALSE;
				}

				// clean up
				//	
				CleanupInterfaces();
			}

			// allow suspend again..
			//gShell->GetBatteryControl()->UnForcePowerOn();

			// Start animations again at full speed now that video is not being displayed
			gShell->StopTimer();
			gShell->StartTimer(30);

			break;

		case ATTRIBUTES_UPDATED:
		{
			// update the play position in the shell attributes
			DWORD newPos = *(gShell->GetShellOptions()->GetAttribute(SD_VideoPlayPosition));

			// was play position altered whilst we're playing?
			if (newPos != m_lastPercentagePlayed && IsPlaying())
			{
				DWORD len = GetPlaybackLength();

				len *= newPos;  // get amount of time from percentage to seconds
				len /= 100;

				LONGLONG position = len;
				LONGLONG multipler = 10000000;
				position *= multipler;

				pMC->Pause();
				pMS->SetPositions(&position, AM_SEEKING_AbsolutePositioning | AM_SEEKING_SeekToKeyFrame, 
									NULL , AM_SEEKING_NoPositioning);
				pMC->Run();

				// update menu items
				EnableItems(m_videoState);

				// remember this so we don't do any moving twice
				m_lastPercentagePlayed = newPos;
			}
			break;
		}

		case VW_PLAYPOSITION:
			// don't stop play
			m_continuePlayOnMenuExit = TRUE;

			// update the video info
			UpdateTrackInfo();

			// try to find a position menu
			gShell->JumpToMenu(VIDEOPOSITION_MENU);
			break;

		case INITIALISE:
			// find named item on this menu for play position
			//
			m_movieBrowser = (MovieBrowser*)gShell->FindTypeItem((Menu*) this->pParent, MOVIEBROWSER_ITEM);

			// find named item on this menu for play position
			//
			m_currentPlayPosWindow = gShell->FindNamedItem((Menu*) this->pParent, 
															MOVIEBROWSER_PLAYPOSITION);
			break;

		default:
			break;
	}

	return TRUE;
}


/*
// IVideoWindow has the following functions
//
	get_AutoShow				Queries whether the video renderer automatically shows the video window when it receives video data. 
	get_BackgroundPalette		Queries whether the video window realizes its palette in the background.  
	get_BorderColor				Retrieves the color that appears around the edges of the destination rectangle. 
	get_Caption					Retrieves the video window caption.  
	get_FullScreenMode			Queries whether the video renderer is in full-screen mode.  
	get_Height					Retrieves the height of the video window.  
	get_Left					Retrieves the video window's x-coordinate.  
	get_MessageDrain			Retrieves the window that receives mouse and keyboard messages from the video window, if any.  
	get_Owner					Retrieves the video window's parent window, if any.  
	get_Top						Retrieves the video window's y-coordinate.  
	get_Visible					Queries whether the video window is visible.  
	get_Width					Retrieves the width of the video window.  
	get_WindowState				Queries whether the video window is visible, hidden, minimized, or maximized.  
	get_WindowStyle				Retrieves the window style on the video window.  
	get_WindowStyleEx			Retrieves the extended window style on the video window.  
	GetMaxIdealImageSize		Retrieves the maximum ideal size for the video image.  
	GetMinIdealImageSize		Retrieves the minimum ideal size for the video image.  
	GetRestorePosition			Retrieves the restored window position.  
	GetWindowPosition			Retrieves the position of the video window.  
	HideCursor					Hides the cursor.  
	IsCursorHidden				Queries whether the cursor is hidden.  
	NotifyOwnerMessage			Forwards a message to the video window.  
	put_AutoShow				Specifies whether the video renderer automatically shows the video window when it receives video data. 
	put_BackgroundPalette		Specifies whether the video window realizes its palette in the background.  
	put_BorderColor				Sets the color that appears around the edges of the destination rectangle. 
	put_Caption					Sets the video window caption.  
	put_FullScreenMode			Enables or disables full-screen mode.  
	put_Height					Sets the height of the video window.  
	put_Left					Sets the video window's x-coordinate.  
	put_MessageDrain			Specifies a window to receive mouse and keyboard messages from the video window.  
	put_Owner					Specifies a parent window for the video window.  
	put_Top						Sets the video window's y-coordinate.  
	put_Visible					Shows or hides the video window.  
	put_Width					Sets the width of the video window.  
	put_WindowState				Shows, hides, minimizes, or maximizes the video window.  
	put_WindowStyle				Sets the window style on the video window.  
	put_WindowStyleEx			Sets the extended window style on the video window.  
	SetWindowForeground			Places the video window at the top of the Z order.  
	SetWindowPosition			Sets the position of the video window.  
*/

// Actual worker function for thread (not static)
//
void VideoItem::VideoThreadEntry()		
{
	HRESULT hr;
	SIZE videoSize;
	long style;

	m_busy = TRUE;
	
	// Make sure play icons are updated 
	EnableItems(m_videoState);

	// Allow DirectShow to create the FilterGraph for this media file
	hr = pGB->RenderFile(m_videoFile, NULL);

	if (hr == VFW_S_AUDIO_NOT_RENDERED)
	{
		// clean up a little
		CleanupInterfaces(TRUE);
		
		// thread is quiting
		m_videoThread=NULL;
		m_busy = FALSE;
		
	    RETAILMSG(DBGMODE_HIGHEST, (TEXT("VideoItem::VideoThreadEntry Unable to render audio!%s\r\n"),m_videoFile));
		return;
	}

	if (FAILED(hr)) 
	{
		// clean up a little
		CleanupInterfaces(TRUE);

		// thread is quiting
		m_videoThread=NULL;
		m_busy = FALSE;
		
	    RETAILMSG(DBGMODE_HIGHEST, (TEXT("VideoItem::VideoThreadEntry Unable to render file %s\r\n"),m_videoFile));
		return;
	}

	// set to minimum 
	videoSize.cx = 1;
	videoSize.cy = 1;
	
	// Set the video playback to our window (off screen!)
	pVW->SetWindowPosition(SCREEN_WIDTH+10, 0, videoSize.cx, videoSize.cy);

	// make video window topmost
	pVW->get_WindowStyleEx(&style);
	style |= WS_EX_TOPMOST | WS_EX_NOANIMATION | WS_EX_NOACTIVATE;
	pVW->put_WindowStyleEx(style);

	// Start playback on first frame, then we can resize
	hr = pMC->Pause();
	if (FAILED(hr)) 
	{
		// clean up a little
		CleanupInterfaces(TRUE);

		// thread is quiting
		m_videoThread=NULL;
		m_busy = FALSE;
		RETAILMSG(DBGMODE_HIGHEST, (TEXT("VideoItem::VideoThreadEntry  Pause() failed!\r\n")));
		return;
	}

	// Resize the video and center
	ResizeAndCenter();

	// Start playback
	hr = pMC->Run();
	if (FAILED(hr)) 
	{
		// clean up a little
		CleanupInterfaces(TRUE);

		// thread is quiting
		m_videoThread=NULL;
		m_busy = FALSE;
		RETAILMSG(DBGMODE_HIGHEST, (TEXT("VideoItem::VideoThreadEntry  Run() failed!\r\n")));
		return;
	}

	// allow a little time for the video thread to get started then ensure we still have focus and 
	// the volume is correct
	Sleep(250);

	// ensure full volume
	Mute(FALSE);

	// ensure shell has focus
	SetFocus(gShell->GetMainWindow());

	// wait for completion
	//
	m_busy = FALSE; 
	// Make sure play icons are updated 
	EnableItems(m_videoState);

	//ProcessEventLoopForMedia();

	// and we're playing...
	m_videoState = VS_PLAYING;

	// thread is quiting
	m_videoThread=NULL;
}

// Video thread entry, this is static as otherwise we can't pass it to CreateThread, but as
// the argument to createThread is the *this pointer, we use this to call back into a 
// non static function
//
ULONG CALLBACK VideoItem::VideoThread(void* ptr)
{
	VideoItem* videoPtr = (VideoItem*) ptr;

	// go to the worker function
	videoPtr->VideoThreadEntry();

	return 1;
}

// Playing ?
BOOL VideoItem::IsPlaying()
{
	return m_videoState == VS_PLAYING;
}

// Initialising ?
BOOL VideoItem::IsInitialising()
{
	return m_videoState == VS_INITIALISING;
}

// stopped ?
BOOL VideoItem::IsStopped()
{
	return (m_videoState == VS_UNINITIALISED || m_videoState == VS_STOPPED);
}

// Paused ?
BOOL VideoItem::IsPaused()
{
	return m_videoState == VS_PAUSED;
}

// Clear any file information if not playing
//
BOOL VideoItem::ClearFile()
{
	// Make sure the video is stopped
	if (m_videoState == VS_STOPPED || m_videoState == VS_UNINITIALISED)
	{
		// clear the file information
		m_videoFile = "";	
	
		// update menu items
		EnableItems(m_videoState);

		return TRUE;
	}

	return FALSE;
}