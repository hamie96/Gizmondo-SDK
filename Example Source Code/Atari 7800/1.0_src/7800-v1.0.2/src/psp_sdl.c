/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <SDL/SDL.h>
//#include <SDL/SDL_mixer.h>
//#include <SDL/SDL_image.h>
//#include <SDL/SDL_ttf.h>
#include <png.h>

#include "global.h"
#include "psp_sdl.h"
//#include "psp_sound.h"
//#include "psp_danzeff.h"

void * giz_screen();

  extern unsigned char psp_font_8x8[];
  extern unsigned char psp_font_6x10[];

  unsigned char *psp_font;
  int            psp_font_width  = 8; 
  int            psp_font_height = 8; 

  //SDL_Surface *back_surface;
  //SDL_Surface *back2_surface;

  // single screen buffer for now...
  void * back_surface;
  void * back2_surface; 

unsigned short
psp_sdl_rgb(uchar R, uchar G, uchar B)
{
    unsigned short res = ((R&0x00F8)<<8)|((G&0x00FC)<<3)|((B&0x00F8)>>3);
    return res;
}

ushort *
psp_sdl_get_vram_addr(uint x, uint y)
{
  ushort *vram = (ushort *)back_surface;
  return vram + x + (y*PSP_LINE_SIZE);
}

void
loc_psp_debug(char *file, int line, char *message)
{
  static int current_line = 0;
  static int current_col  = 10;

  char buffer[128];
  current_line += 10;
  if (current_line > 220)
  {
    if (current_col == 200) {
      psp_sdl_clear_screen(psp_sdl_rgb(0, 0, 0xff));
      current_col = 10;
    } else {
      current_col = 200;
    }
    
    current_line = 10;
  }
  sprintf(buffer,"%s:%d %s", file, line, message);
  psp_sdl_print(current_col, current_line, buffer, psp_sdl_rgb(0xff,0xff,0xff) );
}

void 
psp_sdl_print(int x,int y, char *str, int color)
{
  int index;
  int x0 = x;

  for (index = 0; str[index] != '\0'; index++) {
    psp_sdl_put_char(x, y, color, 0, str[index], 1, 0);
    x += psp_font_width;
    if (x >= (PSP_SDL_SCREEN_WIDTH - psp_font_width)) {
      x = x0; y+= psp_font_height;
    }
    if (y >= (PSP_SDL_SCREEN_HEIGHT - psp_font_width)) break;
  }
}

void
psp_sdl_clear_screen(int color)
{
  int x; int y;
  ushort *vram = psp_sdl_get_vram_addr(0,0);
  
  for (y = 0; y < PSP_SDL_SCREEN_HEIGHT; y++) {
    for (x = 0; x < PSP_SDL_SCREEN_WIDTH; x++) {
      vram[x + (y*PSP_LINE_SIZE)] = color;
    }
  }
  psp_sdl_flush();
}


void 
psp_sdl_draw_rectangle(int x, int y, int w, int h, int border, int mode) 
{
  ushort *vram = (ushort *)psp_sdl_get_vram_addr(x, y);
  int xo, yo;
  if (mode == PSP_SDL_XOR) {
    for (xo = 0; xo < w; xo++) {
      vram[xo] ^=  border;
      vram[xo + h * PSP_LINE_SIZE] ^=  border;
    }
    for (yo = 0; yo < h; yo++) {
      vram[yo * PSP_LINE_SIZE] ^=  border;
      vram[w + yo * PSP_LINE_SIZE] ^=  border;
    }
  } else {
    for (xo = 0; xo < w; xo++) {
      vram[xo] =  border;
      vram[xo + h * PSP_LINE_SIZE] =  border;
    }
    for (yo = 0; yo < h; yo++) {
      vram[yo * PSP_LINE_SIZE] =  border;
      vram[w + yo * PSP_LINE_SIZE] =  border;
    }
  }
}

void 
psp_sdl_fill_rectangle(int x, int y, int w, int h, int color, int mode)
{
  ushort *vram  = (ushort *)psp_sdl_get_vram_addr(x, y);
  int xo, yo;
  if (mode == PSP_SDL_XOR) {
    for (xo = 0; xo <= w; xo++) {
      for (yo = 0; yo <= h; yo++) {
        if ( ((xo == 0) && ((yo == 0) || (yo == h))) ||
             ((xo == w) && ((yo == 0) || (yo == h))) ) {
          /* Skip corner */
        } else {
          vram[xo + yo * PSP_LINE_SIZE] ^=  color;
        }
      }
    }
  } else {
    for (xo = 0; xo <= w; xo++) {
      for (yo = 0; yo <= h; yo++) {
        vram[xo + yo * PSP_LINE_SIZE] =  color;
      }
    }
  }
}

void 
psp_sdl_back2_rectangle(int x, int y, int w, int h)
{
/*	ushort *vram;
  int xo, yo;

	if (! back2_surface) {
    psp_sdl_fill_rectangle(x, y, w, h, 0x0, 0);
    return;
  }

  vram  = (ushort *)psp_sdl_get_vram_addr(x, y);
  vram = (vram - psp_sdl_get_vram_addr(0,0)) + ((ushort *)back2_surface);

  for (xo = 0; xo <= w; xo++) {
    for (yo = 0; yo <= h; yo++) {
      vram[xo + yo * PSP_LINE_SIZE] = psp_sdl_get_back2_color(x + xo, y + yo);
    }
  }*/
}

void 
psp_sdl_put_char(int x, int y, int color, int bgcolor, char c, int drawfg, int drawbg)
{
  int cx;
  int cy;
  int b;
  int index;

  ushort *vram = (ushort *)psp_sdl_get_vram_addr(x, y);
  index = ((ushort)c) * psp_font_height;

  for (cy=0; cy< psp_font_height; cy++) {
    b = 1 << (psp_font_width - 1);
    for (cx=0; cx< psp_font_width; cx++) {
      if (psp_font[index] & b) {
        if (drawfg) vram[cx + cy * PSP_LINE_SIZE] = color;
      } else {
        if (drawbg) vram[cx + cy * PSP_LINE_SIZE] = bgcolor;
      }
      b = b >> 1;
    }
    index++;
  }
}

void 
psp_sdl_back2_put_char(int x, int y, int color, char c)
{
  int cx;
  int cy;
  int bmask;
  int index;
  u8 r;
  u8 g;
  u8 b;
ushort *vram;

  if (! back2_surface) {
    psp_sdl_put_char(x, y, color, 0x0, c, 1, 1);
    return;
  }

  vram  = (ushort *)psp_sdl_get_vram_addr(x, y);
  vram = (vram - psp_sdl_get_vram_addr(0,0)) + ((ushort *)back2_surface);

  index = ((ushort)c) * psp_font_height;

  for (cy=0; cy< psp_font_height; cy++) {
    bmask = 1 << (psp_font_width - 1);
    for (cx=0; cx< psp_font_width; cx++) {
      if (psp_font[index] & bmask) {
        vram[cx + cy * PSP_LINE_SIZE] = color;
      } else {
        //vram[cx + cy * PSP_LINE_SIZE] = psp_sdl_get_back2_color(x + cx, y + cy);
      }
      bmask = bmask >> 1;
    }
    index++;
  }
}

void 
psp_sdl_fill_print(int x,int y,const char *str, int color, int bgcolor)
{
  int index;
  int x0 = x;

  for (index = 0; str[index] != '\0'; index++) {
    psp_sdl_put_char(x, y, color, bgcolor, str[index], 1, 1);
    x += psp_font_width;
    if (x >= (PSP_SDL_SCREEN_WIDTH - psp_font_width)) {
      x = x0; y++;
    }
    if (y >= (PSP_SDL_SCREEN_HEIGHT - psp_font_width)) break;
  }
}

void
psp_sdl_back2_print(int x,int y,const char *str, int color)
{
  int index;
  int x0 = x;

  for (index = 0; str[index] != '\0'; index++) {
    psp_sdl_back2_put_char(x, y, color, str[index]);
    x += psp_font_width;
    if (x >= (PSP_SDL_SCREEN_WIDTH - psp_font_width)) {
      x = x0; y++;
    }
    if (y >= (PSP_SDL_SCREEN_HEIGHT - psp_font_width)) break;
  }
}

void
psp_sdl_wait_vn(uint count)
{
}

void
psp_sdl_wait_vblank(void)
{
}

void
psp_sdl_flush(void)
{
}

void
psp_sdl_lock(void)
{
//  SDL_LockSurface(back_surface);
}

//void
//psp_sdl_load_background()
//{
//  back2_surface = IMG_Load("./background.jpg");
//}

void
psp_sdl_blit_background()
{
  //psp_sdl_clear_screen(psp_sdl_rgb(0x00, 0x00, 0x00));
	static void * bg = 0;
	
	if (!bg)
		bg = loadbackground();
	memcpy(back2_surface, bg, 321*240*2);
	//memset(back2_surface, 0, 321*240*2);
}

void
psp_sdl_unlock(void)
{
  //SDL_UnlockSurface(back_surface);
}

void
psp_sdl_flip(void)
{
  //SDL_Flip(back_surface);
	memcpy(back_surface, back2_surface, 321*240*2);
	psp_sdl_blit_background();
}

#define  systemRedShift      (back_surface->format->Rshift)
#define  systemGreenShift    (back_surface->format->Gshift)
#define  systemBlueShift     (back_surface->format->Bshift)
#define  systemRedMask       (back_surface->format->Rmask)
#define  systemGreenMask     (back_surface->format->Gmask)
#define  systemBlueMask      (back_surface->format->Bmask)

void
psp_sdl_save_png(char *filename, char * ptr1, unsigned char * display_palette)
{
        png_structp png_ptr;
        png_infop info_ptr;
        png_bytep rows[223];


  FILE *fp = fopen(filename,"wb");
    int i;
    png_color palette[256];


  if(!fp) return;

        png_ptr = png_create_write_struct(
                PNG_LIBPNG_VER_STRING,
                NULL, NULL, NULL
        );
        if (png_ptr == NULL)
                return;
        info_ptr = png_create_info_struct(png_ptr);
        if (info_ptr == NULL)
                return;
        png_init_io(png_ptr, fp);
        png_set_IHDR(
                png_ptr, info_ptr, 320, 223,
                8, PNG_COLOR_TYPE_PALETTE,
                PNG_INTERLACE_NONE,
                PNG_COMPRESSION_TYPE_DEFAULT,
                PNG_FILTER_TYPE_DEFAULT
        );
                for (i = 0; i < 256; i++) {
                        palette[i].red = display_palette[i*3+0];
                        palette[i].green = display_palette[i*3+1];
                        palette[i].blue = display_palette[i*3+2];
                }
                png_set_PLTE(png_ptr, info_ptr, palette, 256);
                for (i = 0; i < 223; i++) {
                        rows[i] = ptr1;
                        ptr1 += 320;
                }

        png_set_rows(png_ptr, info_ptr, rows);
        png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
        png_destroy_write_struct(&png_ptr, &info_ptr);

		fclose(fp);
}


void
psp_sdl_save_screenshot(char * buffer, unsigned char * palette)
{
  char TmpFileName[MAX_PATH];

  sprintf(TmpFileName,"%s\\scr\\screenshot_%d.png", ATARI.atari_home_dir, ATARI.psp_screenshot_id++);
  if (ATARI.psp_screenshot_id >= 10) ATARI.psp_screenshot_id = 0;
  psp_sdl_save_png(TmpFileName, buffer, palette);
}

int
psp_sdl_init(void)
{
  //if (SDL_Init(SDL_INIT_AUDIO) < 0) {
  //   return 0;
  //}
//  SDL_JoystickEventState(SDL_ENABLE);
//  SDL_JoystickOpen(0);

//  if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
//    return 0;
//  }

  psp_sdl_select_font_6x10();

//  back_surface=SDL_SetVideoMode(PSP_SDL_SCREEN_WIDTH,PSP_SDL_SCREEN_HEIGHT, 16 , 
//                                SDL_DOUBLEBUF|SDL_HWSURFACE);


  back_surface = giz_screen();

  if ( !back_surface) {
    return 0;
  }

  back2_surface = malloc(321*240*2);

  //SDL_FillRect(back_surface,NULL,SDL_MapRGB(back_surface->format,0x0,0x0,0x0));
  //SDL_Flip(back_surface);
  //SDL_FillRect(back_surface,NULL,SDL_MapRGB(back_surface->format,0x0,0x0,0x0));
  //SDL_Flip(back_surface);

  //SDL_ShowCursor(SDL_DISABLE);

//  Danzeff Keyboard
//  danzeff_load();
//  danzeff_set_screen(back_surface);

  psp_sound_init();

  //SDL_Delay(1000);        // Give sound some time to init
  //SDL_PauseAudio(0);
  return 1;
}

void
psp_sdl_exit(int status)
{
  //SDL_Quit();
  exit(status);
}

void
psp_sdl_select_font_8x8()
{
  psp_font = psp_font_8x8;
  psp_font_height = 8;
  psp_font_width  = 8;
}

void
psp_sdl_select_font_6x10()
{
  psp_font = psp_font_6x10;
  psp_font_height = 10;
  psp_font_width  = 6;
}

