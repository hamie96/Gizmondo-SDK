
#if !defined(AFX_CAMERA_H__55BFFB7F_9066_40B8_94F8_EF1E6E9158F2__INCLUDED_)
#define AFX_CAMERA_H__55BFFB7F_9066_40B8_94F8_EF1E6E9158F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"


#define NUM_BUFFERS 2

// Preview buffer structure
typedef struct {
	DWORD	nBuf;					// number of buffer sets
	DWORD	cx;						// buffer width
	DWORD	cy;						// buffer height
	DWORD	cbBuf;					// buffer size (bytes)
	HBITMAP	hBitmap[NUM_BUFFERS];	// DIB handle
	HDC		hImageCache;			// HDC
	PBYTE	pBitmap[NUM_BUFFERS];	// pointer to DIB bitmap data
	DWORD	dwCurBuf;				// index of current preview DIB
	DWORD	dwDispBuf;				// index of current display DIB
} DIBBUF, *PDIBBUF;



// Captured image buffer structure
typedef struct {
	DWORD	cx;						// buffer width
	DWORD	cy;						// buffer height
	DWORD	cbBuf;					// buffer size (bytes)
	PBYTE	pBuf;					// pointers to YUV image data
	DWORD	dwCurBuf;				// index of current image
	DWORD	dwDispBuf;				// index of current image
} YUVBUF, *PYUVBUF;



#endif // !defined(AFX_CAMERA_H__55BFFB7F_9066_40B8_94F8_EF1E6E9158F2__INCLUDED_)
