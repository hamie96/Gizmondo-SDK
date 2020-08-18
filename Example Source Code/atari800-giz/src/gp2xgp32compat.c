#include "gp2xgp32compat.h"

//#include "gp2xminlib.h"

#include "config.h"
#include "atari.h"
#include "memory.h"
#include "atari_gp32.h"

static int init=0;
static char ch[1024];

void GpPlotChar(GPDRAWSURFACE * surface, int x, int y, char atariChar, int col)
{
	int ac = atariChar;

	int yo=0;
	for (yo=0; yo<8; ++yo)
	{
		unsigned char xd = ch[(ac<<3) + yo];
		int xpos=0;
		int xo=0;
		for (xo=128;xo>0;xo>>=1, xpos++)
		{
			if (xd&xo)
			{
				gp2x_video_plot(x+xpos,y+yo, col);
			}
		}
	}
}

void GpTextOut(int* bad,GPDRAWSURFACE * surface, int x, int y, const char * text, int col)
{
	int len;
	int i;
	if (!init)
	{
		get_charset(ch);
	}	

	// Plot the 8x8 grid per character
	len = strlen(text);
	i=0;
	for (i=0; i<len; ++i)
	{
		GpPlotChar(surface,x,y+3,text[i]&0x7f, mapPal(col));
		x+=8;
	}
}

void GpRectFill(int* bad,GPDRAWSURFACE * surface, int x,int y,int w,int h, int col)
{
	gp2x_fill_rect(x,y,w,h, mapPal(col));
}

int GpTickCountGet()
{
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

