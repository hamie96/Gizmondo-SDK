#include "shell.h"
#include <qnetwork.h>
#include <musicbrowser.h>

#ifndef _RingToneControl 
#define _RingToneControl 

// 0 = ring only, 1 = vibrate and ring, 2 = vibrate only
#define RING_ONLY		0
#define RING_VIBRATE	1
#define VIBRATE_ONLY	2

////////////////////////////////////////////////////////////////////////////////
// RingToneControl controls MP3/MIDI/WAV incomming ring tones..
//
class RingToneControl 
{
public:
	RingToneControl();
	~RingToneControl();

	// Start playing SMS/MMS tone in options 
	//
	BOOL	PlayTone();			

	// Start playing a specifc tone / vibrate
	//
	BOOL	PlayTone(CString fileToPlay, DWORD ringType);

	// Are we currently playing?
	BOOL	IsPlaying();						
	
	// Stop playing file
	BOOL	StopPlayback();						
	
private:

	// Turn on / off vibrator
	BOOL	Vibrate(BOOL on);

	// Vibrate for a peroid of time, wait for completion!
	BOOL	VibrateForTime(int msec);

	// cached setting for users options of vibrate or not
	DWORD	m_ringType;		// 0 = ring only, 1 = vibrate and ring, 2 = vibrate only

	// Process medie events
	void		ProcessEventLoopForMedia();

	// Get playback position
	DWORD		GetPlaybackPosition();

	// Get playback length
	DWORD		GetPlaybackLength();

	// Mute on or off
	//
	HRESULT		Mute(BOOL on);

	void	TrackFinished();					// The end of the track has been reached
	
	// Private Media tools
	//
	void CleanupInterfaces(BOOL forced=FALSE);		// shut down audio
	HRESULT GetInterfaces(void);	// start up components
	
	CString m_fileToPlay;	// file to play

	// current audio state
	AudioState	m_audioState;

	// Thread stuff
	//
	static DWORD WINAPI AudioThread(void *pArg);	// Thread entry (static)
	void				AudioThreadEntry();		// actual worker function for thread (not static)
	HANDLE				m_audioThread;

	/////////////////////////////////////////////////////////////////////////////
	// Media playing controls
	IGraphBuilder  *pGB;
	IMediaControl  *pMC;
	IMediaSeeking  *pMS;
	IMediaPosition *pMP;
	IBasicVideo    *pBV;
	IMediaEvent    *pME;
	IFilterGraph   *pFG;

	LONG g_lVolume;
	HANDLE			m_playMutex;
	HANDLE			m_stopMutex;

	// quit whlist playing a song
	BOOL			m_quit;
};

#endif