#include "atari_gp32.h"

#include <stdlib.h>
#include <stdio.h>
//#include <unistd.h>

#include "jpeglib.h"
#include "jpegbuffersrc.h"
#include "gp2xjoy.h"
//#include "gp2xminlib.h"
void gp2x_fill_rect(int x, int y, int width, int height, int col);

#include "splash_data.h"

#include "windows.h"

//SDL_Surface * testSurface;

// Copy a 16-bit screen to the GP's screen, adjusting brightness in the process
static void fade(unsigned int * dest, unsigned int * src, int factor)
{
	int count = 321*240*2/4;
	int i;
	unsigned int r,g,b,r2,g2,b2;
	for (i=0; i<count; ++i)
	{
		unsigned int reg = *src++;

		b = (((reg&0x3e)*factor)>>7)&0x3e;
		g = (((reg&0x7c0)*factor)>>7)&0x7c0;
		r = (((reg&0xf800)*factor)>>7)&0xf800;

		b2 = (((reg&0x3e0000)>>7)*factor)&0x3e0000;
		g2 = (((reg&0x7c00000)>>7)*factor)&0x7c00000;
		r2 = (((reg&0xf8000000)>>7)*factor)&0xf8000000;

		*dest++ = (unsigned int)r2 | (unsigned int)g2 | (unsigned int)b2| (unsigned int)r | (unsigned int)g | (unsigned int)b;
	}
}

static char * splashmem = 0;
static int splashfade = 0;
static int splashToggle = 0;
//static SDL_TimerID splashTimer;
static HANDLE splashTimer;
static int splashKey = 0;

DWORD displaySplash(LPVOID);
unsigned short gp2x_video_color15(unsigned char R, unsigned char G, unsigned char B, unsigned char A);

void initSplash()
{
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;
	JSAMPARRAY buffer;
	int row_stride;
	unsigned short * mem;

	/*testSurface = SDL_SetVideoMode(320,240,16,SDL_HWSURFACE);
	SDL_Rect rect;
	rect.x=0;rect.y=0;rect.w=320;rect.h=240;
	SDL_FillRect(testSurface,&rect,0);
*/
	gron();
	//gp2x_video_init(16);
	gp2x_fill_rect(0,0,320,240,0);
	
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);
	//jpeg_stdio_src(&cinfo, infile);
	jpeg_buffer_src(&cinfo, splash, splash_length);
	jpeg_read_header(&cinfo, TRUE);
	jpeg_start_decompress(&cinfo);

	splashmem = malloc(321*240*2);

	row_stride = cinfo.output_width * cinfo.output_components;
	buffer = (*cinfo.mem->alloc_sarray)((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

	mem = (unsigned short *)splashmem;
	while (cinfo.output_scanline < cinfo.output_height) {
		int i=0;
		unsigned char r,g,b;
		unsigned char * src;
		jpeg_read_scanlines(&cinfo, buffer, 1);	

		src = buffer[0];
		for (i=0; i<960; i+=3)
		{
			unsigned short col;
			r = (src[i]&0xf8);
			g = (src[i+1]&0xf8);
			b = (src[i+2]&0xf8);

			col = gp2x_video_color15(r,g,b, 0);

			*mem++ = col;
		}
		mem++;
	}

	jpeg_finish_decompress(&cinfo);

	displaySplash(NULL);

	//splashTimer =  SDL_AddTimer(40, displaySplash,NULL);
	splashTimer = CreateThread(NULL,0,displaySplash, 0,0,NULL);
}

DWORD displaySplash(LPVOID blah)
{
	for (;;)
	{
		if (joyPressed())
		{
			splashfade = 128;
			splashKey = 1;
		}

		Sleep(40);

		fade((unsigned int *)Atari_DisplayActiveBuffer(), (unsigned int *)splashmem, splashfade);
		splashToggle ^=1;

		splashfade+=4;
		gp2x_video_flip();

		if (splashfade>128)	
			break;
	}
	return 0;
}

void cleanupSplash()
{
	if (!splashKey)
		while (!joyPressed()) Sleep(0);
	//SDL_RemoveTimer(splashTimer);
	TerminateThread(splashTimer,0);

	free(splashmem);
	gp2x_fill_rect(0,0,320,240,0);
	gp2x_video_flip();
	gp2x_fill_rect(0,0,320,240,0);
	gp2x_video_flip();
}



