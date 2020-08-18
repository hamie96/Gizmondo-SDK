/*
   Ludovic Jacomme <Ludovic.Jacomme@gmail.com>
*/

#include <stdio.h>
#include <zlib.h>

#include <stdlib.h>
#include <stdio.h>

#include <zlib.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <unistd.h>
#include <string.h>

#include "global.h"
#include "psp_atari.h"
#include "psp_fmgr.h"
#include "psp_kbd.h"

#include "util.h"

  ATARI_t ATARI;

  int psp_screenshot_mode = 0;

char *getcwd(char *buffer, int maxlen);

void
psp_global_initialize()
{
  memset(&ATARI, 0, sizeof(ATARI_t));
  strcpy(ATARI.atari_home_dir, getcwd(0,0));

  atari_default_settings();
  atari_update_save_name("");
  atari_load_settings();
}

int 
main(int argc, char **argv)
{
  psp_global_initialize();
  psp_sdl_init();
  psp_atari_main_loop();

  psp_sdl_exit(0);

  return 0;
}

//LUDO:
void
atari_default_settings()
{
  //LUDO:
  ATARI.atari_snd_enable    = 1;
  ATARI.atari_render_mode   = ATARI_RENDER_NORMAL;
  ATARI.psp_screenshot_id   = 0;
  ATARI.atari_view_fps      = 0;
}

static int
loc_atari_save_settings(char *chFileName)
{
  FILE* FileDesc;
  int   error = 0;

  FileDesc = fopen(chFileName, "w");
  if (FileDesc != (FILE *)0 ) {

    fprintf(FileDesc, "atari_snd_enable=%d\n"   , ATARI.atari_snd_enable);
    fprintf(FileDesc, "atari_view_fps=%d\n"     , ATARI.atari_view_fps);

    fclose(FileDesc);

  } else {
    error = 1;
  }

  return error;
}

int
atari_save_settings(void)
{
  char  FileName[MAX_PATH+1];
  int   error;

  error = 1;

  snprintf(FileName, MAX_PATH, "%s\\set\\%s.set", ATARI.atari_home_dir, ATARI.atari_save_name);
  error = loc_atari_save_settings(FileName);

  return error;
}

static int
loc_atari_load_settings(char *chFileName)
{
  char  Buffer[512];
  char *Scan;
  unsigned int Value;
  FILE* FileDesc;

  FileDesc = fopen(chFileName, "r");
  if (FileDesc == (FILE *)0 ) return 0;

  while (fgets(Buffer,512, FileDesc) != (char *)0) {

    Scan = strchr(Buffer,'\n');
    if (Scan) *Scan = '\0';
    /* For this #@$% of windows ! */
    Scan = strchr(Buffer,'\r');
    if (Scan) *Scan = '\0';
    if (Buffer[0] == '#') continue;

    Scan = strchr(Buffer,'=');
    if (! Scan) continue;

    *Scan = '\0';
    Value = atoi(Scan+1);

    if (!strcasecmp(Buffer,"atari_snd_enable"))   ATARI.atari_snd_enable = Value;
    else
    if (!strcasecmp(Buffer,"atari_view_fps"))  ATARI.atari_view_fps = Value;
  }

  fclose(FileDesc);

  //gp2xPowerSetClockFrequency(ATARI.psp_cpu_clock);

  return 0;
}

int
atari_load_settings()
{
  char  FileName[MAX_PATH+1];
  int   error;

  error = 1;

  snprintf(FileName, MAX_PATH, "%s\\set\\%s.set", ATARI.atari_home_dir, ATARI.atari_save_name);
  error = loc_atari_load_settings(FileName);

  return error;
}

int
atari_load_file_settings(char *FileName)
{
  return loc_atari_load_settings(FileName);
}

static int 
loc_load_rom(char *TmpName)
{
  int error = psp_atari_load_rom(TmpName);
  return error;
}

void
atari_update_save_name(char *Name)
{
  char        TmpFileName[MAX_PATH];
  int         index;
  char       *SaveName;
  char       *Scan1;
  char       *Scan2;
	int len;
    char *cpy;

  SaveName = strrchr(Name,'/');
  if (SaveName != (char *)0) SaveName++;
  else                       SaveName = Name;

  len = strlen(SaveName);
  if (len>4)
  {
	  cpy = Util_strdup(SaveName);
	  cpy[4] = 0;
  }
  
  if (len >4 && strcasecmp(cpy, "sav_")) {
    Scan1 = SaveName + 4;
    Scan2 = strrchr(Scan1, '_');
    if (Scan2 && (Scan2[1] >= '0') && (Scan2[1] <= '5')) {
      strncpy(ATARI.atari_save_name, Scan1, MAX_PATH);
      ATARI.atari_save_name[Scan2 - Scan1] = '\0';
    } else {
      strncpy(ATARI.atari_save_name, SaveName, MAX_PATH);
    }
  } else {
    strncpy(ATARI.atari_save_name, SaveName, MAX_PATH);
  }
  free(cpy);

  memset(ATARI.atari_save_used,0,sizeof(ATARI.atari_save_used));

  if (ATARI.atari_save_name[0] == '\0') {
    strcpy(ATARI.atari_save_name,"default");
  }

  for (index = 0; index < ATARI_MAX_SAVE_STATE; index++) {
    snprintf(TmpFileName, MAX_PATH, "%s\\save\\sav_%s_%d.sta", ATARI.atari_home_dir, ATARI.atari_save_name, index);
    if (Util_fileexists(TmpFileName)) {
      ATARI.atari_save_used[index] = 1;
      ATARI.atari_save_date[index] = 0;//MWW
    }
  }
}

void
reset_save_name()
{
  atari_update_save_name("");
}

void
atari_kbd_load(void)
{
  char        TmpFileName[MAX_PATH + 1];

  snprintf(TmpFileName, MAX_PATH, "%s\\kbd\\%s.kbd", ATARI.atari_home_dir, ATARI.atari_save_name );
  if (Util_fileexists(TmpFileName)) {
    psp_kbd_load_mapping(TmpFileName);
  }
}

int
atari_kbd_save(void)
{
  char TmpFileName[MAX_PATH + 1];
  snprintf(TmpFileName, MAX_PATH, "%s\\kbd\\%s.kbd", ATARI.atari_home_dir, ATARI.atari_save_name );
  return( psp_kbd_save_mapping(TmpFileName) );
}


void
emulator_reset(void)
{
  psp_atari_reset();
}

//Load Functions

typedef unsigned int dword;
typedef unsigned char byte;
typedef unsigned short word;

#define ERR_FILE_NOT_FOUND       13
#define ERR_FILE_BAD_ZIP         14
#define ERR_FILE_EMPTY_ZIP       15
#define ERR_FILE_UNZIP_FAILED    16

FILE *pfileObject;
char *pbGPBuffer = NULL;

static dword
loc_get_dword(byte *buff)
{
  return ( (((dword)buff[3]) << 24) |
           (((dword)buff[2]) << 16) |
           (((dword)buff[1]) <<  8) |
           (((dword)buff[0]) <<  0) );
}

static void
loc_set_dword(byte *buff, dword value)
{
  buff[3] = (value >> 24) & 0xff;
  buff[2] = (value >> 16) & 0xff;
  buff[1] = (value >>  8) & 0xff;
  buff[0] = (value >>  0) & 0xff;
}

static word
loc_get_word(byte *buff)
{
  return( (((word)buff[1]) <<  8) |
          (((word)buff[0]) <<  0) );
}

int
atari_load_rom(char *FileName, int zip_format)
{
  char *pchPtr;
  char *scan;
  char  SaveName[MAX_PATH+1];
  char  TmpFileName[MAX_PATH + 1];
  dword n;
  int   format;
  int   error;

  error = 1;

    strncpy(SaveName,FileName,MAX_PATH);
	scan = strrchr(SaveName,'.');
	if (scan) *scan = '\0';
	atari_update_save_name(SaveName);
	error = loc_load_rom(FileName);

  if (! error ) {
    atari_kbd_load();
    atari_load_settings();
  }

  return error;
}

static int
loc_load_state(char *filename)
{
  int error;
  error = psp_atari_load_state(filename);
  return error;
}

int
atari_load_state(char *FileName)
{
  char *pchPtr;
  char *scan;
  char  SaveName[MAX_PATH+1];
  char  TmpFileName[MAX_PATH + 1];
  dword n;
  int   format;
  int   error;

  error = 1;

  strncpy(SaveName,FileName,MAX_PATH);
  scan = strrchr(SaveName,'.');
  if (scan) *scan = '\0';
  atari_update_save_name(SaveName);
  error = loc_load_state(FileName);

  if (! error ) {
    atari_kbd_load();
    atari_load_settings();
  }

  return error;
}

static int
atari_save_state(char *filename)
{
  int error; 
  error = psp_atari_save_state(filename);
  return error;
}

int
atari_snapshot_save_slot(int save_id)
{
  char        FileName[MAX_PATH+1];
  int         error;

  error = 1;

  if (save_id < ATARI_MAX_SAVE_STATE) {
    snprintf(FileName, MAX_PATH, "%s\\save\\sav_%s_%d.sta", ATARI.atari_home_dir, ATARI.atari_save_name, save_id);
    error = atari_save_state(FileName);
    if (! error) {
      if (Util_fileexists(FileName)) {
        ATARI.atari_save_used[save_id] = 1;
        ATARI.atari_save_date[save_id] = 0; //MWW
      }
    }
  }

  return error;
}

int
atari_snapshot_load_slot(int load_id)
{
  char  FileName[MAX_PATH+1];
  int   error;

  error = 1;

  if (load_id < ATARI_MAX_SAVE_STATE) {
    snprintf(FileName, MAX_PATH, "%s\\save\\sav_%s_%d.sta", ATARI.atari_home_dir, ATARI.atari_save_name, load_id);
    error = loc_load_state(FileName);
  }
  return error;
}

int
atari_snapshot_del_slot(int save_id)
{
  char  FileName[MAX_PATH+1];
  int   error;

  error = 1;

  if (save_id < ATARI_MAX_SAVE_STATE) {
    snprintf(FileName, MAX_PATH, "%s\\save\\sav_%s_%d.sta", ATARI.atari_home_dir, ATARI.atari_save_name, save_id);
    error = Util_unlink(FileName);
    if (! error) {
      ATARI.atari_save_used[save_id] = 0;
      memset(&ATARI.atari_save_date[save_id], 0, sizeof(ATARI.atari_save_date[save_id]));
    }
  }

  return error;
}

