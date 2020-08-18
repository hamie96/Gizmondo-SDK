#include "shell.h"
#include "RingToneControl.h"
#include <nled.h>

/////////////////////////////////////////////////////////////////////////////////////
//RingToneControl constructor
//
RingToneControl::RingToneControl()
{
	m_audioThread = NULL;

	// create a mutex to the Playfile/Stop functions
	m_playMutex = CreateMutex(NULL, FALSE, NULL);

	// clear all pointers
	pMP = NULL;
	pMS = NULL;
	pGB = NULL;
	pBV = NULL;
	pME = NULL;
	pMC = NULL;
	pFG = NULL;

	// no vibrate unless found otherwise
	m_ringType = RING_ONLY;

	// don't quit audio thread
	m_quit = FALSE;
}

/////////////////////////////////////////////////////////////////////////////////////
//Destructor
//
RingToneControl::~RingToneControl()
{
	// clean up
	//
	
	m_quit = TRUE;
		 
	while(m_audioThread)
	{
		RETAILMSG(1, (TEXT("Waiting for Music worker thread to quit...\r\n")));
		Sleep(100);
	}

	// destroy any audio components running
	CleanupInterfaces();

	// delete mutexs
	CloseHandle(m_playMutex);
}

#define JIF(x) if (FAILED(hr=(x))) \
    {RETAILMSG(DBGMODE_HIGH, (TEXT("FAILED(0x%x) ") TEXT(#x) TEXT("\n"), hr)); goto CLEANUP;}

#define LIF(x) if (FAILED(hr=(x))) \
    {RETAILMSG(DBGMODE_HIGH, (TEXT("FAILED(0x%x) ") TEXT(#x) TEXT("\n"), hr)); }

#define RELEASE(i) {if (i) i->Release(); i = NULL;}

HRESULT RingToneControl::GetInterfaces(void)
{
    HRESULT hr = S_OK;

	JIF(CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC, IID_IGraphBuilder, (void **)&pGB));
	JIF(pGB->QueryInterface(IID_IMediaControl,  (void **)&pMC));
	JIF(pGB->QueryInterface(IID_IMediaSeeking,  (void **)&pMS));
	JIF(pGB->QueryInterface(IID_IMediaPosition, (void **)&pMP));
	JIF(pGB->QueryInterface(IID_IBasicVideo,    (void **)&pBV));
	JIF(pGB->QueryInterface(IID_IMediaEventEx,  (void **)&pME));
	JIF(pGB->QueryInterface(IID_IFilterGraph,  (void **)&pFG));
	
	return S_OK;

CLEANUP:
    CleanupInterfaces();
    return(hr);
}

void RingToneControl::CleanupInterfaces(BOOL forced)
{
	// wait for mutex
	if (WaitForSingleObject(m_stopMutex, 30000) == WAIT_OBJECT_0)
	{
		if (m_audioState != AS_UNINITIALISED)
		{
			if (pMC)
			{
				pMC->Stop();
			}

			// audio thread is still starting up, wait for it to quit...
			while(m_audioThread && !forced)
			{
				RETAILMSG(1, (TEXT("CleanupInterfaces..\r\n")));
				Sleep(100);
			}

			if (pGB)
				RELEASE(pGB);
			if (pMC)
				RELEASE(pMC);
			if (pMS)
				RELEASE(pMS);
			if (pMP)
				RELEASE(pMP);
			if (pBV)
				RELEASE(pBV);
			if (pME)
				RELEASE(pME);
			if (pFG)
				RELEASE(pFG);
			
			// clear all pointers
			pMP = NULL;
			pMS = NULL;
			pGB = NULL;
			pBV = NULL;
			pME = NULL;
			pMC = NULL;
			pFG = NULL;

			// uninitialised
			m_audioState = AS_UNINITIALISED;
		}

		// release the mutex now
		ReleaseMutex(m_stopMutex);
	}
}

// Start playing SMS/MMS tone in options 
//
BOOL RingToneControl::PlayTone()
{
	HRESULT hr = S_OK;
	
	// already busy?
	if (m_audioThread)
	{
		RETAILMSG(DBGMODE_HIGHEST, (TEXT("Already playing ring tone...\r\n")));
		return FALSE;
	}

	// check shell options
	if (gShell->GetShellOptions())
	{
		// Get default tone to play
		CString fileToPlay = *(gShell->GetShellOptions()->GetAttributeStr(SS_ToneName));
		
		// get vibrate setting
		DWORD ringType = *(gShell->GetShellOptions()->GetAttribute(SD_RingVibrate));

		RETAILMSG(1, (TEXT("m_fileToPlay = %s \r\n"), m_fileToPlay));

		// play the tone
		return PlayTone(fileToPlay,ringType);
	}

	return FALSE;
}

// Start playing SMS/MMS tone in options 
//
BOOL RingToneControl::PlayTone(CString fileToPlay, DWORD ringType)
{
	HRESULT hr = S_OK;
	
	// already busy?
	if (m_audioThread)
	{
		RETAILMSG(DBGMODE_HIGHEST, (TEXT("Already playing ring tone...\r\n")));
		return FALSE;
	}

	// Get default tone to play
	m_fileToPlay = fileToPlay;
		
	// get vibrate setting
	m_ringType = ringType;

	// wait for mutex
	if (WaitForSingleObject(m_playMutex, 30000) == WAIT_OBJECT_0)
	{
		// if playing or paused
		if (m_audioState != AS_UNINITIALISED)
		{
			// wait until completed before we stop the audio again!
			if (m_audioThread)
				while(m_audioThread)
					Sleep(100);

			// destroy the previous playback
			CleanupInterfaces();
		}

		// we're ready now..
		//
		m_audioState = AS_PLAYING;

		// Quick check to see if there is a thread already
		if (m_audioThread)
			RETAILMSG(DBGMODE_HIGHEST, (TEXT("Audio thread already running!\r\n")));

		// Get the movie interfaces
		if (GetInterfaces() == S_OK)
		{
			// don't quit the audio thread straight away
			m_quit = FALSE;

			// Create a video thream
			m_audioThread = CreateThread( NULL, 
										  0, 
										  (LPTHREAD_START_ROUTINE) AudioThread, 
										  (void*) this,
										  0,0);

			// release the mutex now
			ReleaseMutex(m_playMutex);

			return TRUE;
		}
	}

	// release the mutex now
	ReleaseMutex(m_playMutex);

	return FALSE;
}

// Mute on or off
//
HRESULT RingToneControl::Mute(BOOL on)
{
    HRESULT hr;
    IBasicAudio *pBA=NULL;

	if (!pGB)
		return S_OK;
		
	// Get audio interface pointer to control volume
	hr = pGB->QueryInterface(IID_IBasicAudio, (void **)&pBA);

	if (FAILED(hr) || (!pBA))
		return hr;

			if (FAILED(hr) || (!pBA))
			return hr;

	// Read current volume
	hr = pBA->get_Volume(&g_lVolume);
	
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

	if (on)
	{
		g_lVolume = VOLUME_SILENCE;
	}
	else
	{
		g_lVolume = VOLUME_FULL;
	}


	// Set new volume
	pBA->put_Volume(g_lVolume);
	pBA->Release();

    return hr;
}

// Are we currently playing?
BOOL RingToneControl::IsPlaying()
{
	return m_audioState == AS_PLAYING;
}

// Stop playing file
BOOL RingToneControl::StopPlayback()						
{
	RETAILMSG(1, (TEXT("RingToneControl::StopPlayback \r\n")));

	// wait until completed before we stop the audio again!
	if (m_audioThread)
		m_quit = TRUE;

	return TRUE;
}

// Actual worker function for thread (not static)
//
void RingToneControl::AudioThreadEntry()		
{
	HRESULT hr;

	// vibrate only?
	if (m_ringType != VIBRATE_ONLY)
	{
		CString file = TONES;
		file += m_fileToPlay;

		RETAILMSG(1, (TEXT("file = %s \r\n"), file));

		// Allow DirectShow to create the FilterGraph for this media file
		hr = pGB->RenderFile(file, NULL);

		if (FAILED(hr)) 
		{
			m_audioThread = NULL;
			RETAILMSG(DBGMODE_HIGHEST, (TEXT("RingToneControl::AudioThreadEntry Failed to render file")));
			m_audioState = AS_STOPPED;

			// just vibrator for 2 seconds to please our customers!
			VibrateForTime(2000);
			return;
		}

		
		// ensure full volume
		Mute(FALSE);

		// Start playback
		hr = pMC->Run();
		if (FAILED(hr)) 
		{
			hr = pMC->Run();
			if (FAILED(hr)) 
			{
				m_audioThread = NULL;
				RETAILMSG(DBGMODE_HIGHEST, (TEXT("RingToneControl::AudioThreadEntry Run failed\r\n")));
				m_audioState = AS_STOPPED;

				// just vibrator for 2 seconds to please our customers!
				VibrateForTime(2000);
				return;
			}
			else
			{
				RETAILMSG(DBGMODE_HIGHEST, (TEXT("RingToneControl::AudioThreadEntry Run working 2nd time\r\n")));
			}
		}
	}

	// turn on the vibrator
	if (Vibrate(TRUE))
	{
		// wait for 2 seoncd
		Sleep(2000);

		// turn off vibrator
		Vibrate(FALSE);
	}

	// vibrate only?
	if (m_ringType != VIBRATE_ONLY)
	{
		// wait for completion of music (this may already have happened!)
		ProcessEventLoopForMedia();

		Sleep(100);

		// destroy the previous playback
		CleanupInterfaces(TRUE);
	}

	RETAILMSG(1, (TEXT("RingToneControl::AudioThreadEntry - \r\n")));

	m_audioThread = NULL;
}

// Audio thread entry, this is static as otherwise we can't pass it to CreateThread, but as
// the argument to createThread is the *this pointer, we use this to call back into a 
// non static function
//
ULONG CALLBACK RingToneControl::AudioThread(void* ptr)
{
	RingToneControl* audioPtr = (RingToneControl*) ptr;

	// go to the worker function
	audioPtr->AudioThreadEntry();

	return 1;
}

// Get playback length
DWORD RingToneControl::GetPlaybackLength()
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
DWORD RingToneControl::GetPlaybackPosition()				
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

// Process media events directly
//
// Lifted from CEPlayit, these events should be incorporated into the main shell event loop
//
void RingToneControl::ProcessEventLoopForMedia()
{
	// is the track valid?
	while(GetPlaybackLength() != 0 && !m_quit)
	{
		// are we at the end of the track?
		if (GetPlaybackPosition() == GetPlaybackLength())
		{
			RETAILMSG(1, (TEXT("RingToneControl::ProcessEventLoopForMedia end of track\r\n")));
			m_audioState = AS_STOPPED;
			return;
		}
	}

	// wait for last second to play..
	if (!m_quit)
		Sleep(1000);

	// stop playback (if not stopped already..)
	if (pMC)
		pMC->Stop();
	
	m_audioState = AS_STOPPED;
}


// Turn on / off vibrator
BOOL RingToneControl::Vibrate(BOOL on)
{
	// vibrate disabled?
	if (m_ringType == RING_ONLY)
		return FALSE;

	NLED_SETTINGS_INFO ledSettingInfo;
	HANDLE hVib = CreateFile (L"VIB1:", GENERIC_READ | GENERIC_WRITE, 
										0, NULL, OPEN_EXISTING, 0, NULL);

	RETAILMSG(1, (TEXT("Vibrate %d \r\n"), on));

	// opened it?
	//
	if (hVib != INVALID_HANDLE_VALUE)
	{
		ledSettingInfo.LedNum = 0;
		
		if (on)
			ledSettingInfo.OffOnBlink = 2;		// 0 = off, 1 = on, 2 = blink
		else
			ledSettingInfo.OffOnBlink = 0;		// 0 = off, 1 = on, 2 = blink

		ledSettingInfo.OnTime = 1000000; 
		ledSettingInfo.OffTime = 750000;
		ledSettingInfo.TotalCycleTime = ledSettingInfo.OffTime + ledSettingInfo.OnTime;
		ledSettingInfo.MetaCycleOn = 0;
		ledSettingInfo.MetaCycleOff = 0;

		// Turn on or off the vibrator
		DeviceIoControl( hVib, 
						 NLED_SETTINGS_INFO_ID,
						 &ledSettingInfo, 
						 sizeof(ledSettingInfo),NULL, 
						 0, NULL, NULL );

		// close the driver
		CloseHandle(hVib);

		return TRUE;
	}

	return FALSE;
}

// Vibrate for a peroid of time, wait for completion!
BOOL RingToneControl::VibrateForTime(int msec)
{
	// vibrate disabled?
	if (m_ringType == RING_ONLY)
		return FALSE;

	Vibrate(TRUE);
	Sleep(msec);
	Vibrate(FALSE);

	return TRUE;
}