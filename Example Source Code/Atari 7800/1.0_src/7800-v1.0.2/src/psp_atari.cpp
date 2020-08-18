/*
   Ludovic Jacomme <Ludovic.Jacomme@gmail.com>
*/

#include <stdlib.h>
#include <stdio.h>

#include <zlib.h>
#include <string>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <unistd.h>
#include <string.h>

#include "global.h"
#include "psp_fmgr.h"
#include "psp_kbd.h"
//#include "psp_danzeff.h"
#include "psp_sdl.h"

#include "Cartridge.h"
#include "ProSystem.h"
#include "Database.h"
#include "Sound.h"

extern "C" {

//FILE * timelog = 0;

static word display_palette16[256] = {0};


//MWW
int Perf_GetTicks()
{
    //struct timeval t;
    //gettimeofday(&t,0);
    //double res = t.tv_sec*1e3 + t.tv_usec/1e3;^M
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

void
psp_atari_reset()
{
  prosystem_Reset();
}

int
psp_atari_load_state(char *filename)
{
  int error;

  std::string std_filename(filename);
  error = prosystem_Load(filename) ? 0 : 1;

  return error;
}

int
psp_atari_save_state(char *filename)
{
  int error;

  std::string std_filename(filename);
  error = prosystem_Save(filename, true) ? 0 : 1;
  //Test...
//  prosystem_Load(filename);

  return error;
}

int 
psp_atari_load_rom(char *filename) 
{
  std::string std_filename(filename);
  if(! cartridge_Load(std_filename)) return 1;

# if 0
    sound_Stop( );
    display_Clear( );
# endif
  database_Load(cartridge_digest);

  prosystem_Reset();

# if 0
    std::string title = std::string(CONSOLE_TITLE) + " - " + common_Trim(cartridge_title);
    SetWindowText(console_hWnd, title.c_str( ));
    console_AddRecent(filename);
    display_ResetPalette( );
    console_SetZoom(display_zoom);
    sound_Play( );
# endif
  return 0;
}

/* LUDO: */
/*void
atari_synchronize(void)
{
  static u32 nextclock = 1;

  static FILE * synclog = 0;
  if (!synclog)
  {
	  synclog = fopen("\\SD Card\\ProSystem_Giz_Opt\\sync,log","w");
  }

  fprintf(synclog, "PRE Now:%d Next:%d\n", Perf_GetTicks(), nextclock);
  if (nextclock) {
    u32 curclock;
    do {
     curclock = Perf_GetTicks();
    } while (curclock < nextclock);
    nextclock = curclock + (u32)( 1000 / ATARI.atari_speed_limiter);
  }

  fprintf(synclog,"DONE Now:%d Next:%d\n", Perf_GetTicks(), nextclock);
}*/

int timeDrawNextFrame = 0;
int autoFrameSkip = 1;

static double now()
{
       //struct timeval t;
       //gettimeofday(&t,0);
       //double res = t.tv_sec*1e3 + t.tv_usec/1e3;^M
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

void atari_synchronize(void)
{
        static double frameCount = 0;
        static double startTime = 0xbadf00d;
        double expectedTime;
        double diff;

        double tickDeltaTime = (1.0/prosystem_frequency)*1000.0;

        // Calulate where we are now
        double realTime = now() - startTime;

        frameCount+=1.0;

        // Deltatime is 1/50 for PAL, 1/60 for NTSC
        expectedTime = tickDeltaTime * frameCount;

        // resync if miles off!
        diff = fabs(realTime-expectedTime);
        if ((diff > (5*tickDeltaTime))) // More than 5 frames off
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
                        while ((now()-startTime+(0.6*tickDeltaTime)) < expectedTime);
                }
        }
        else
        {
                timeDrawNextFrame = !autoFrameSkip;
        }

        //fprintf(stderr,"timeDrawNextFrame:%d\n", timeDrawNextFrame);
}


void
atari_update_fps()
{
  static u32 next_sec_clock = 0;
  static u32 cur_num_frame = 0;
  cur_num_frame++;
  u32 curclock = Perf_GetTicks();
  if (curclock > next_sec_clock) {
    next_sec_clock = curclock + 1000;
    ATARI.atari_current_fps = cur_num_frame;
    cur_num_frame = 0;
  }
}

void
psp_atari_init_palette16()
{
  uint rsize  =  6;
  uint gsize  =  5;
  uint bsize  =  6;
      
  for(uint index = 0; index < 256; index++) {
    word r = palette_data[(index * 3) + 0];
    word g = palette_data[(index * 3) + 1];
    word b = palette_data[(index * 3) + 2];
    display_palette16[index] = psp_sdl_rgb(r, g, b);
  }
}

# if 0
//LUDO: HACK
static int loc_toggle_line = 0;

static inline void
psp_atari_put_image_normal()
{
  /* 320 x 223 */
  uint height = maria_visibleArea.GetHeight( );
  uint length = maria_visibleArea.GetLength( );

  const byte* buffer = maria_surface + 
      ((maria_visibleArea.top - maria_displayArea.top) * maria_visibleArea.GetLength( ));

  loc_toggle_line = (loc_toggle_line + 1) & 0x3;

  word* surface = (word*)psp_sdl_get_vram_addr(0, 8);
  uint pitch = PSP_LINE_SIZE;
  height = height >> 1;
  if (loc_toggle_line <= 1) {
    surface += pitch * height;
    buffer  += length * height;
  }
  for(uint indexY = 0; indexY < height; indexY++) {
    for(uint indexX = 0; indexX < length; indexX += 4) {
      surface[indexX + 0] = display_palette16[buffer[indexX + 0]];
      surface[indexX + 1] = display_palette16[buffer[indexX + 1]];
      surface[indexX + 2] = display_palette16[buffer[indexX + 2]];
      surface[indexX + 3] = display_palette16[buffer[indexX + 3]];
    }
    surface += pitch;
    buffer += length;
  }
}
# endif

static inline void
psp_atari_put_image_normal()
{
  /* 320 x 223 */
  uint height = maria_visibleArea.GetHeight( );
  uint length = maria_visibleArea.GetLength( );

  const byte* buffer = maria_surface + 
      ((maria_visibleArea.top - maria_displayArea.top) * maria_visibleArea.GetLength( ));

  uint* surface = (uint*)psp_sdl_get_vram_addr(0, 8);
  uint pitch = PSP_LINE_SIZE >> 1;
  uint maxX = length;

  height = height >> 1;
  //LUDO: HACK
  for(uint indexY = 0; indexY < height; indexY++) {

    for(uint indexX = 0; indexX < 320; indexX += 2) {
      *surface++ = (display_palette16[buffer[indexX+1]] << 16) | display_palette16[buffer[indexX]];
    }
    buffer += length;

    for(indexX = 0; indexX < 322; indexX += 2) {
      *surface++ = (display_palette16[buffer[indexX]] << 16) | display_palette16[buffer[indexX-1]];
    }
    //++surface;
    buffer += length;
  }
}

void
psp_atari_refresh_screen()
{
  //if (ATARI.psp_skip_cur_frame <= 0) {

if (timeDrawNextFrame)
{
    if (psp_screenshot_mode) {
      psp_screenshot_mode--;
      if (psp_screenshot_mode <= 0) {
		    const byte* buffer = maria_surface +  ((maria_visibleArea.top - maria_displayArea.top) * maria_visibleArea.GetLength( ));

        psp_sdl_save_screenshot(buffer, palette_data);
        psp_screenshot_mode = 0;
      }
    }

	//fprintf(timelog,"Blit:%d\n", Perf_GetTicks());
	psp_atari_put_image_normal(); 
	//psp_sdl_clear_screen(0);

    if (ATARI.atari_view_fps) {
		//fprintf(timelog,"FPS:%d\n", Perf_GetTicks());
      char buffer[32];
      sprintf(buffer, "FPS:%3d", (int)ATARI.atari_current_fps);
      psp_sdl_fill_print(15, 0, buffer, psp_sdl_rgb(0xff,0xff,0xff), 0 );
    }

/*    if (1) {
		int z = 0;
		//fprintf(timelog,"FPS:%d\n", Perf_GetTicks());
      char buffer[256];
      sprintf(buffer, "Keys:%1d %1d %1d %1d %1d, %1d %1d %1d %1d %1d, %1d %1d %1d %1d %1d, %1d %1d", 
		  (int)ATARI.keyboard_data[z++],
		  (int)ATARI.keyboard_data[z++],
		  (int)ATARI.keyboard_data[z++],
		  (int)ATARI.keyboard_data[z++],
		  (int)ATARI.keyboard_data[z++],

		  (int)ATARI.keyboard_data[z++],
		  (int)ATARI.keyboard_data[z++],
		  (int)ATARI.keyboard_data[z++],
		  (int)ATARI.keyboard_data[z++],
		  (int)ATARI.keyboard_data[z++],

		  (int)ATARI.keyboard_data[z++],
		  (int)ATARI.keyboard_data[z++],
		  (int)ATARI.keyboard_data[z++],
		  (int)ATARI.keyboard_data[z++],
		  (int)ATARI.keyboard_data[z++],

		  (int)ATARI.keyboard_data[z++],
		  (int)ATARI.keyboard_data[z++]
		 );
      psp_sdl_fill_print(0, 15, buffer, psp_sdl_rgb(0xff,0xff,0xff), 0 );
    }
*/
    //psp_kbd_display_active_mapping();
    //psp_sdl_flip();
}
  //} else if (ATARI.psp_skip_max_frame) {
    //ATARI.psp_skip_cur_frame--;
  //}


  //fprintf(timelog,"Syncing:%d\n", Perf_GetTicks());
  atari_synchronize();

  if (ATARI.atari_view_fps) {
    atari_update_fps();
  }

  	//fprintf(timelog,"Refreshed:%d\n", Perf_GetTicks());
}

extern "C" void sound_Store();

void
psp_atari_main_loop()
{
  if (bios_Load("7800.rom")) {
    bios_enabled = true;
  }
  /* Open default rom */
  if (psp_atari_load_rom("default.a78")) {
    psp_sdl_exit(1);
  }

  psp_atari_init_palette16();

  //if (!timelog)
  {
//	  timelog = fopen("\\SD Card\\Prosystem_Giz_Opt\\time.log","w");
  }

  while (1) {
    psp_update_keys();

    if(prosystem_active && !prosystem_paused) {
      //fprintf(timelog,"Prosystem:%d\n", Perf_GetTicks());
      prosystem_ExecuteFrame(ATARI.keyboard_data);
      //fprintf(timelog,"SoundStore:%d\n", Perf_GetTicks());
	  if (ATARI.atari_snd_enable)
		sound_Store();
      psp_atari_refresh_screen();
    }
  }
}

};
