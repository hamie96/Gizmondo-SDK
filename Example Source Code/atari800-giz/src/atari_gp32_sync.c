#include "atari.h"
#include "config.h"
#include "monitor.h"
#include "colours.h"

#include <math.h>
#include <stdlib.h>
//#include <unistd.h>
//#include <time.h>
//#include <sys/time.h>
//#include <sched.h>

#include "atari_gp32.h"

// Variable may be used to see difference between GP32 clock and Atari clock
int timeDrawNextFrame = 0;

// Frame skip enabled?
static int autoFrameSkip = 1; //automatic enabled by default

static double now()
{
	//struct timeval t;
	//gettimeofday(&t,0);
	//double res = t.tv_sec*1e3 + t.tv_usec/1e3;
	double ticks;
	LARGE_INTEGER tick;
	static LARGE_INTEGER freq = {0,0};

	QueryPerformanceCounter(&tick);
	if (freq.QuadPart == 0)
		QueryPerformanceFrequency(&freq);

	ticks = tick.QuadPart;
	ticks/=freq.QuadPart;
	ticks*=1000.0;
	return ticks;
}

static void atariSync(int resync)
{
	static double frameCount = 0;
	static double startTime = 0xbadf00d;
	double expectedTime;
	double diff;

	//fprintf(stderr,"Frame\n");

	//if (frameCount>5.0)
	//	Atari_Exit(0);

	double tickDeltaTime = DELTATIME*1000.0;
	//fprintf(stderr, "tickDeltaTime:%f\n", tickDeltaTime);

	// Calulate where we are now
	double realTime = now() - startTime;

	frameCount+=1.0;

	// Deltatime is 1/50 for PAL, 1/60 for NTSC
	expectedTime = tickDeltaTime * frameCount;

	// Store diff
	//fprintf(stderr, "Expected:%f Real:%f Diff:%f\n", expectedTime, realTime, realTime-expectedTime);

	// resync if miles off!
	diff = fabs(realTime-expectedTime);
	if (resync || (diff > (5*tickDeltaTime))) // More than 5 frames off
	{
		realTime = expectedTime;
		startTime = now() - realTime;
		timeDrawNextFrame = 1;
		return;
	}

	//Are we ahead of where we should be?
	if (expectedTime>realTime)
	{
		double maxTime;
		timeDrawNextFrame = 1;

		maxTime = realTime+0.6*tickDeltaTime;
		if (expectedTime>maxTime) // Are we way too fast? Don't want to be too far ahead -> wait if so
		{
//			sprintf(debugTextBuffer,"Wait: real:%d req:%d diff:%d", now()-startTime, (int)requiredTime, (int)requiredTime-now()+startTime);
//			debugText = debugTextBuffer;

			while ((now()-startTime+(0.6*tickDeltaTime)) < expectedTime);
		}
	}
	else
	{
		timeDrawNextFrame = !autoFrameSkip;
	}

	//fprintf(stderr,"timeDrawNextFrame:%d\n", timeDrawNextFrame);
}

////////////////////////////////////////////////////////////////////////////
// Interface -> called externally
int Atari_Time()
{
	return GpTickCountGet();
//	return rtcTick*1000/64;
}

void Atari_Sync()
{
	atariSync(0);
}

void Atari_ReSync()
{
	atariSync(1);
}

void Atari_AutoFrameSkip(int enable)
{
	autoFrameSkip = enable;
}

int Atari_GetAutoFrameSkip()
{
	return autoFrameSkip;
}

void atari_sync() { Atari_Sync(); } 



