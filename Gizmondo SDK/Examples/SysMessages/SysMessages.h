
#if !defined(AFX_SYSMESSAGES_H__06DCD838_F1C2_4022_BC4D_6DF4645B520B__INCLUDED_)
#define AFX_SYSMESSAGES_H__06DCD838_F1C2_4022_BC4D_6DF4645B520B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"

// GLOBAL MESSAGES
#define LOWBATERY_MSG		L"LOWBATERY_MSG"			// Sent when battery is low
#define CRITICALBATERY_MSG  L"CRITICALBATERY_MSG"		// Sent when battery is critical
#define SMS_MSG				L"SMS_MSG"					// Sent when a SMS/MMS is received
#define SWITCHTOSHELL_MSG   L"SWITCHTOSHELL_MSG"		// Sent when wanting to switch to the shell
#define GPRS_CONNECT_MSG	L"GPRS_CONNECT"				// Game requesting GRPS connection
#define GPRS_STATUS_MSG		L"GPRS_STATUS"				// GRPS connection status
#define GT_GETSTATUS_MSG	L"GT_GETSTATUS"				// Game asking for shell status
#define GT_STATUS_MSG		L"GT_STATUS"				// Shell status (flight mode etc)



#endif // !defined(AFX_SYSMESSAGES_H__06DCD838_F1C2_4022_BC4D_6DF4645B520B__INCLUDED_)
