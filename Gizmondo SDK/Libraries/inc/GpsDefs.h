/******************************************************************************
 * Copyright (c) 2004 Plextek Limited, Great Chesterford, England.
 * All Rights Reserved
 ******************************************************************************
 * THIS FILE IS VERSION CONTROLLED USING VSS. DO NOT HAND EDIT THESE FIELDS
 * ----------------------------------------------------------------------------
 * $Archive: /Gizmondo/Apps/GTShell/GTShell/GpsDefs.h $
 * $Revision: 1 $
 * $Author: Graemew $
 * $Date: 11/08/04 14:46 $
 * ----------------------------------------------------------------------------
 *
 * This file contains public definitions for the GPS interface on the Gizmondo
 * platform
 *
 *****************************************************************************
 * $History: GpsDefs.h $
// 
// *****************  Version 1  *****************
// User: Graemew      Date: 11/08/04   Time: 14:46
// Created in $/Gizmondo/Apps/GTShell/GTShell
 * 
 * *****************  Version 6  *****************
 * User: Al           Date: 29/07/04   Time: 11:25
 * Updated in $/Veg/Swede/Src/EDS02
 * First formal release to Intrinsyc. Geofencing implemented and tested,
 * power management implemented but not yet fully tested/operational
 * 
 * *****************  Version 5  *****************
 * User: Al           Date: 23/07/04   Time: 11:41
 * Updated in $/Veg/Swede/Src/EDS02
 * Further testing on emulator.
 * Implemented power management.
 * Tidied up layout
 * 
 * *****************  Version 4  *****************
 * User: Al 		  Date: 20/07/04   Time: 17:40
 * Updated in $/Veg/Swede/Src/EDS02
 * Basic functionality (excluding Power management) implemented and
 * partially tested.
 * 
 * *****************  Version 3  *****************
 * User: Al 		  Date: 22/06/04   Time: 10:20
 * Updated in $/Veg/Swede/Src/EDS02
 * Position reporting now works on Target platform. Checked in for
 * delivery to Intrinsyc.
 * 
 * *****************  Version 2  *****************
 * User: Al 		  Date: 8/06/04    Time: 17:49
 * Updated in $/Veg/Swede/Src/EDS02
 * Check in preparatory to start of integration with Intrinsyc's BSP
 * 
 * *****************  Version 1  *****************
 * User: Al 		  Date: 28/05/04   Time: 16:55
 * Created in $/Veg/Swede/Src/EDS02
 * New files added since prototype version
 *****************************************************************************/

#ifndef __GPSDEFS_H__
#define __GPSDEFS_H__

// Constants

// Fix Mode 1 bitfield masks
#define PMODE_MASK		0x07
#define	TPMODE_MASK		0x08
#define	ALTMODE_MASK	0x30
#define	DOPMASK_MASK	0x40
#define	DGPS_MASK		0x80

// Values of the PMODE (fix type) field
#define PMODE_NONE		0
#define	PMODE_1SAT		1
#define	PMODE_2SAT		2
#define	PMODE_3SAT		3
#define	PMODE_nSAT		4
#define	PMODE_2DPOINT	5
#define	PMODE_3DPOINT	6
#define	PMODE_DEADRECK	7

// Values of the TPMODE field
#define TPMODE_FULL		0
#define	TPMODE_TRICKLE	1

// Values of the ALTMODE field
#define ALTMODE_NOHOLD	0
#define	ALTMODE_FILT	1
#define	ALTMODE_USER	2
#define	ALTMODE_FORCED	3

// Values of the DOPMASK field
#define DOPMASK_OK		0
#define	DOPMASK_EXCEED	1

// Values of the DGPS field
#define DGPS_NONE		0
#define	DGPS_POSITION	1

// The start of the UTC epoch 1/1/1972 00:00 in FILETIME units
#define UTC_EPOCH				0x019fef81c6cc0000L

// Fixed decimal data resolution values
#define LAT_LONG_RESOLUTION 10000000
#define UTC_SECONDS_RESOLUTION 1000

// Misc constants
#define MAX_GPS_CHANS				12
#define MIN_VALID_LAT				(-90 * LAT_LONG_RESOLUTION)
#define MAX_VALID_LAT				(90 * LAT_LONG_RESOLUTION)
#define MIN_VALID_LONG				(-180 * LAT_LONG_RESOLUTION)
#define MAX_VALID_LONG				(180 * LAT_LONG_RESOLUTION)
#define MIN_VALID_GEOFENCE_RADIUS	100
#define MAX_VALID_GEOFENCE_RADIUS	100000
#define	MIN_POWER_DUTY_CYCLE		5
#define	MAX_POWER_DUTY_CYCLE		95
#define	MIN_TIME_BETWEEN_FIXES		10
#define	MAX_TIME_BETWEEN_FIXES		180


// GPS IOCTLS
#ifndef CTL_CODE
// Duplicate definitions from WINDEV.H, to avoid missing definitions in user apps
#define CTL_CODE( DeviceType, Function, Method, Access )				  \
	( ((DeviceType) << 16) | ((Access) << 14) | ((Function) << 2) | (Method) ) \

#define METHOD_BUFFERED				0
#define FILE_ANY_ACCESS				0
#endif

// Assign a private device type and function codes for GPS
#define FILE_DEVICE_GPS		0x00008000

#define FUNCTION_GPS_CONFIGURE	0x801
#define FUNCTION_GPS_RESTART	0x802
#define	FUNCTION_GPS_VERSION	0x803

#define IOCTL_GPS_CONFIGURE \
	CTL_CODE(FILE_DEVICE_GPS, FUNCTION_GPS_CONFIGURE, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_GPS_RESTART \
	CTL_CODE(FILE_DEVICE_GPS, FUNCTION_GPS_RESTART, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_GPS_VERSION \
	CTL_CODE(FILE_DEVICE_GPS, FUNCTION_GPS_VERSION, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Reset type definitions for use with IOCTL_GPS_RESTART
#define GPS_FACTORY_RESTART		(0)
#define GPS_COLD_RESTART		(1)
#define	GPS_WARM_RESTART		(2)
#define GPS_HOT_RESTART			(3)
#define GPS_MAX_RESTART_TYPE	GPS_HOT_RESTART

// Geofence requests

#define	GEOFENCE_SET_REQUEST	(0)
#define	GEOFENCE_CANCEL_REQUEST (1)
#define	GEOFENCE_STATUS_REQUEST (2)

// Geofence notification types
#define	GEOFENCE_ALARM_NOTIFICATION		(0)
#define	GEOFENCE_STATUS_NOTIFICATION	(1)

// Configuration type
#define	APM_CONFIGURATION	(0)

//=========================================
// Simple data type definitions

// UTC timestamp (seconds since 00:00 on 1/1/1972)
typedef	UINT32 UTCTIME;

//=========================================
// Data structure definitions

// All data structures are packed
#pragma pack(1)

// Data structures

// Satellite constellation data
typedef struct
{
	UINT8 SatVehicleID;
	UINT16 Azimuth;
	UINT8 Elevation;
	UINT16 State;
	UINT8 C_NO;	// Current signal strength
	BOOL InFix;	// Satellite is actually being used in a fix
} GPS_VISIBLE_SATS, * PGPS_VISIBLE_SATS;

// Position data
typedef struct
{
	UINT8 DriverVersion;	// Indicates the version number of the GPS driver
	BOOL FixSincePowerUp;	// Indicates that a fix has been made since power up
	UINT16 GpsExtendedWeek;	// GPS week number (doesn't wrap!)
	UINT32 GpsTimeOfWeek;	// Milliseconds since 0:00 on Sunday morning
	UTCTIME Timestamp;		// Timestamp for last valid position fix
	BOOL FixValidated;		// Flag indicating whether the fix has been validated
	UINT16 FixType;			// Diagnostic data about how fix was derived
	INT32 Latitude;			// Latitude in decimal degrees (7 dec places)
	INT32 Longitude;		// Longitude in decimal degrees (7 dec places)
	INT32 AltitudeMSL;		// Altitude above mean sea level
	UINT16 EstSpeed;		// Speed estimated by SiRF firmware
	UINT16 EstCourse;		// Course estimated by SiRF firmware
	UINT32 EstHorizError;	// Horizontal position error estimated by SiRF firmware
	UINT32 EstVertError;	// Vertical position error estimated by SiRF firmware
	UINT8 SatsUsed;			// Number of satellites used in latest valid fix
	UINT8 HorizDilution;	// Horizontal dilution of precision
	UINT8 NumSatsVisible;	// How many satellites are currently visible
	GPS_VISIBLE_SATS VisibleSats[MAX_GPS_CHANS]; // Satellite data
} LATEST_GPS_DATA, * PLATEST_GPS_DATA;

// Geofence request
typedef struct
{
	UINT8 RequestType;		// Geofence request type
	INT32 CentreLatitude;	// Latitude in decimal degrees (7 dec places)
	INT32 CentreLongitude;	// Longitude in decimal degrees (7 dec places)
	INT32 Radius;			// Radius in metres
	UTCTIME StartTimeUTC;	// Geofence start time (0 = now)
	UTCTIME StopTimeUTC;	// Geofence stop time (0 = forever)
} GEOFENCE_PARAMETERS, * PGEOFENCE_PARAMETERS;

// Geofence notification
typedef struct
{
	UINT8 NotificationType;	// Alarm or status
	INT32 CentreLatitude;	// Latitude of Geofence centre
	INT32 CentreLongitude;	// Longitude of Geofence centre
	INT32 Radius;			// Geofence radius in metres
	UTCTIME StartTimeUTC;	// Geofence start time (0 = now)
	UTCTIME StopTimeUTC;	// Geofence stop time (0 = forever)
	INT32 CurrentLatitude;	// Current latitude in decimal degrees (7 dec places)
	INT32 CurrentLongitude;	// Current longitude in decimal degrees (7 dec places)
	UINT16 SpeedOverGround;	// Estimated speed (m/s)
	UINT16 CourseOverGround;// Estimated heading (degrees from True North)
	UINT32 EstHorizError;	// Estimated error radius of current position
} GEOFENCE_NOTIFICATION, * PGEOFENCE_NOTIFICATION;

// SiRF Advanced Power Management (APM) parameters

typedef struct
{
	BOOL ApmEnabled;		// FALSE = full power operation, TRUE = power saving
	UINT8 TimeBetweenFixes;	// 10-180 seconds
	UINT8 PowerDutyCycle;	// percentage (5%-95%) in multiples of 5%
	BOOL PowerSavePriority;	// TRUE = Power duty cycle takes priority, FALSE= Time between fixes takes priority
} APM_PARAMETERS, * PAPM_PARAMETERS;

typedef struct
{
	UINT8 ConfigType;
	union
	{
		APM_PARAMETERS ApmParameters[4];
	} ConfigParameters;
} GPS_CONFIG_PARAMETERS, * PGPS_CONFIG_PARAMETERS;

#pragma pack()
#endif __GPSDEFS_H__
