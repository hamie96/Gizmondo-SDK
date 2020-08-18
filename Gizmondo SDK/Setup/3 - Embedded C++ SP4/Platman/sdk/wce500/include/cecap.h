//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//


// CECAP.H
// interface to remote call profiler APIs
//
// 1.  Start and stop, and suspend and resume profiling at global/process/thread level
// 2.  Add marks (labels) to timeline.
// 3.  Name a process or thread.


#ifndef __CECAP_H__
#define __CECAP_H__

#ifdef __cplusplus
extern "C" {
#endif

// Defines for Levels and Id's
#define PROFILE_GLOBALLEVEL		1
#define PROFILE_PROCESSLEVEL	2
#define PROFILE_THREADLEVEL		3
#define PROFILE_CURRENTID		((unsigned long)0xFFFFFFFF)

// Start/Stop Api's
int StopProfile(int nLevel, unsigned long dwId);
int StartProfile(int nLevel, unsigned long dwId);

// Suspend/Resume Api's
int SuspendProfile(int nLevel, unsigned long dwId);
int ResumeProfile(int nLevel, unsigned long dwId);

// Mark Api's
int MarkProfile(long lMarker);
int CommentMarkProfile(long lMarker, const char *szComment);
int CommentMarkAtProfile(__int64 dnTimestamp, long lMarker, const char *szComment);

// Named Profiling Elements Api's
int NameProfile(const char *pszName, int nLevel, unsigned long dwId);

// xxxProfile return codes
#define PROFILE_OK					0		// xxxProfile call successful
#define PROFILE_ERROR_NOT_YET_IMPLEMENTED 1 // api or level,id combination not supported yet
#define PROFILE_ERROR_MODE_NEVER	2		// mode was never when called
#define PROFILE_ERROR_LEVEL_NOEXIST 3		// level doesn't exist
#define PROFILE_ERROR_ID_NOEXIST	4		// id doesn't exist

// MarkProfile return codes 
#define MARK_OK						0	// Mark was taken successfully
#define MARK_ERROR_MODE_NEVER		1	// Profiling was never when MarkProfile called
#define MARK_ERROR_MODE_OFF			2	// Profiling was off when MarkProfile called
#define MARK_ERROR_MARKER_RESERVED	3	// Mark value passed is a reserved value
#define MARK_TEXTTOOLONG			4	// Comment text was truncated

// NameProfile return codes
#define NAME_OK						0	// Name was registered sucessfullly
#define NAME_ERROR_TEXTTRUNCATED	1	// The name text was too long and was therefore truncated
#define NAME_ERROR_REDEFINITION		2	// The given profile element has already been named
#define NAME_ERROR_LEVEL_NOEXIST	3	// level doesn't exist
#define NAME_ERROR_ID_NOEXIST 		4	// id doesn't exist
#define NAME_ERROR_INVALID_NAME		5	// name does not meet the specification's requirements

#define StartCAP() StartProfile(PROFILE_THREADLEVEL, PROFILE_CURRENTID)
#define StopCAP() StopProfile(PROFILE_THREADLEVEL, PROFILE_CURRENTID)
#define SuspendCAP() SuspendProfile(PROFILE_THREADLEVEL, PROFILE_CURRENTID)
#define ResumeCAP() ResumeProfile(PROFILE_THREADLEVEL, PROFILE_CURRENTID)

void  _CAP_Start_Profiling(VOID *pCurrentFunction, VOID *pTargetFunction);
void  _CAP_End_Profiling(VOID *pCurrentFunction);

#define StartCAPAll() StartProfile(PROFILE_PROCESSLEVEL, PROFILE_CURRENTID)
#define StopCAPAll() StopProfile(PROFILE_PROCESSLEVEL, PROFILE_CURRENTID)
#define SuspendCAPAll() SuspendProfile(PROFILE_PROCESSLEVEL, PROFILE_CURRENTID)
#define ResumeCAPAll() ResumeProfile(PROFILE_PROCESSLEVEL, PROFILE_CURRENTID)

#define MarkCAP(mark) MarkProfile(mark)

//
// USER DEFINED COUNTER HELPERS AND TYPES
//

// COUNTER_FUNCTION_PROLOGE and EPILOGE
//
// These functions are supplied to protect the state of registers
// that the collection probes rely on.  We did everything we
// could to eliminate instructions during collection.  Your mission,
// if you choose to accept it, is the same.
//
#define COUNTER_FUNCTION_PROLOGE	_asm push ecx _asm push ebx _asm push ebp
#define COUNTER_FUNCTION_EPILOGE	_asm pop ebp _asm pop ebx _asm pop ecx _asm ret

#ifndef USER_COUNTER_INFO_DEFINED
#define USER_COUNTER_INFO_DEFINED

// CONSTS AND ENUMS
//

// UserCounterType
//
// These enumerations describe how the counter works.
//
// MonotonicallyIncreasing	--	This describes a counter that will increment
//								by one each time some 'event' occurs.  An
//								example would be a counter that tracks the
//								number of memory allocations.  Each allocation
//								increments the number by one.
//
// MonotonicallyDecreasint	--	This describes a counter that will decrement
//								by one each time some 'event' occurs.  An
//								example would be a counter that tracks a limited
//								resource.  Each use of the resource decrements
//								the number by one.
//
// RandomIncreasing --			This describes a counter that will increase for
//								each 'event' that occurs, but by an undetermined
//								amount.  An example would be the total memory
//								allocated.  Each allocation would add it's size
//								to the counter, but each allocation being potentially
//								different, causes the counter to go up by a random
//								amount each time.
//
// RandomDecreasing --			This describes a coutner that will decrease for
//								each 'event' that occurs, but by an undetermined
//								amount.  An example would be a limited resource
//								that can be used in bunches.  Each use fo the
//								the resource would cause the number to descrease
//								by a random amount.
//
// Random --					This number can either go up, or go down.  An
//								example would be the total amount of available
//								memory, which can either go up (as memory is
//								free'd), or go down (as memory is allocated).
//
enum UserCounterType
{
	MonotonicallyIncreasing,
	MonotonicallyDecreasing,
	RandomIncreasing,
	RandomDecreasing,
	RandomI
};

// TYPEDEFS
//

typedef signed __int64	COUNTER, *PCOUNTER;

///////////////////////////////////////////////////////////////
// USERCOUNTERINFO
//
// This structure descibes a user defined counter so that
// can use it during profiling runs.
//
///////////////////////////////////////////////////////////////
typedef struct _USERCOUNTERINFO
{
	unsigned long dwSize;			// Size of this structure (for version control)
	char  szCounterFuncName[32];	// Name of the function
	enum UserCounterType	ct;		// Describes the type of number we will be collecting
	char szName[32];				// Name of user counter
	int bSynchronized;				// Is this counter synchronized

} USERCOUNTERINFO, *PUSERCOUNTERINFO;

#endif  // USER_COUNTER_INFO_DEFINED

#ifdef __cplusplus
}
#endif

#endif // __CECAP_H__
