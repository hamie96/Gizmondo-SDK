#include "shell.h"

enum VideoState{VS_UNINITIALISED, VS_INITIALISING, VS_STOPPED, VS_PLAYING, VS_PAUSED};

class MovieBrowser;

////////////////////////////////////////////////////////////////////////////////
// Video is an item
//
class VideoItem : public Item
{
public:
	VideoItem();
	~VideoItem();

	// Parse any XML Atrributes assoicated with this object
	//
	virtual void		ParseXMLAttribute(LPCTSTR szAttributeTag, LPCTSTR szAttribute);

	// Paint this scrolling text
	virtual void	Paint(HDC hdc, RECT& rt, int x=0, int y=0, ItemState menuState=STATE_UNKNOWN);

	// get area this item covers
	virtual void	GetUpdateRect(RECT* rt, DWORD currentTime);

	// Set area this control coveres
	void			SetUpdateRect();

	// We can handle some actions
	virtual BOOL	ProcessAction(KeyAction action, CString& paramters, int recurseDepth=0);

	// ProcessKey - This item can handle keypresses 
	//
	virtual BOOL	ProcessKey(KeyEnum key, int repeatCount);

	// Clear any file information if not playing
	//
	BOOL			ClearFile();

	// Plays movie 
	void		PlayMovie();

	// Resize the video and center when not in full screen 
	void		ResizeAndCenter();

	// Is the control full screen?
	BOOL		IsFullScreen(){return m_fullScreen;};

	// Given a current movie calculate the size the video should be shown in the current
	// control to preserve the ratio 
	//
	SIZE		CalculateSize(BOOL fullScreen);

	// Playing or paused?
	BOOL		IsPlaying();			// playing
	BOOL		IsInitialising();		// Initialising ?
	BOOL		IsPaused();				// paused?
	BOOL		IsStopped();			// stopped


	// Functions used by the video thread
	//

private:

	// Video thread
	HANDLE				m_videoThread;		// Video thread available
	BOOL				m_killedThread;		// Video thread has terminated
	BOOL				m_killThread;		// Signal Video thread to terminated
	static DWORD WINAPI VideoThread(void *pArg);	// Thread entry (static)
	void				VideoThreadEntry();		// actual worker function for thread (not static)

	// Update the current play position and slider control for video positioning
	void				UpdateTrackInfo();

public:
	// Get playback position
	DWORD				GetPlaybackPosition();
private:

	// Get track length
	DWORD				GetPlaybackLength();

	// End of the movie track
	void				TrackFinished();

	// Enable or disable menu items depending on the current state
	void				EnableItems(VideoState state);

	// Wait for media control to be ready
	BOOL				WaitForReady();

	// Create Interfaces
	HRESULT GetInterfaces(void);

	// Cleanup Interfaces
	void CleanupInterfaces(BOOL force=FALSE);

	// Toggle full screen
	HRESULT ToggleFullScreen(void);
	BOOL	m_fullScreen;

	BOOL	m_hidden;		// item is hidden

	// Mute on or off
	HRESULT		Mute(BOOL on);

	// Process media events directly
	void		ProcessEventLoopForMedia();

	// Busy?
	BOOL		m_busy;

	// internal variables used for current paint positioning
	//	
	CString		m_videoFile;
	BOOL		m_playOnOpen;		// play the video file when menu is opened

	BOOL		m_backgroundPause;	// pause in background, else video is stopped
	BOOL		m_continuePlayOnMenuExit;	// continue to play video when menu is exitted

	// Pointer to any movie browser of the current menu
	MovieBrowser*		m_movieBrowser;

	// Are we in smartAd mode (i.e. restricted access and automatically go back 
	// to previous menu after playing?
	BOOL		m_smartAddMode;

	// size of playing video (if any)
	SIZE		m_videoSize;

	// track repeat
	BOOL		m_repeat;

	VideoState	m_videoState;

	// Used to pass information to the audio thread...
	Item* m_currentPlayPosWindow;
	
	// update time intervals
	DWORD m_lastUpdateTime;
	DWORD m_updateInteval;

	// video state mutex
	HANDLE		m_videoStateMutex;

	DWORD		m_lastPercentagePlayed;
	DWORD		m_justSeekedVideo;
	/////////////////////////////////////////////////////////////////////////////
	// Media playing
	IGraphBuilder  *pGB;
	IMediaControl  *pMC;
	IMediaSeeking  *pMS;
	IMediaPosition *pMP;
	IVideoWindow   *pVW;
	IBasicVideo    *pBV;
	IMediaEvent    *pME;
	IBasicAudio	   *pBA;
	LONG g_lVolume;
};

	