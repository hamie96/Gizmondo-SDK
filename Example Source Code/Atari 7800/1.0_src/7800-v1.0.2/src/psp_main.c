/*
   GP2X-ATARI: Porting of Atari800
   Ludovic Jacomme <Ludovic.Jacomme@gmail.com>
*/

#include <stdio.h>
#include <zlib.h>
#include "global.h"

#include <stdlib.h>
#include <stdio.h>
#include "cpulcd.h"
#include "gp2x_psp.h"

#define STDOUT_FILE  "stdout.txt"
#define STDERR_FILE  "stderr.txt"

//extern int SDL_main(int argc, char *argv[]);

static void cleanup_output(void);

#define NO_STDIO_REDIRECT

/* Remove the output files if there was no output written */
static void cleanup_output(void)
{
#ifndef NO_STDIO_REDIRECT
  FILE *file;
  int empty;
#endif

  /* Flush the output in case anything is queued */
  fclose(stdout);
  fclose(stderr);

#ifndef NO_STDIO_REDIRECT
  /* See if the files have any output in them */
  file = fopen(STDOUT_FILE, "rb");
  if ( file ) {
    empty = (fgetc(file) == EOF) ? 1 : 0;
    fclose(file);
    if ( empty ) {
      remove(STDOUT_FILE);
    }
  }
  file = fopen(STDERR_FILE, "rb");
  if ( file ) {
    empty = (fgetc(file) == EOF) ? 1 : 0;
    fclose(file);
    if ( empty ) {
      remove(STDERR_FILE);
    }
  }
#endif
#ifdef GP2X_MODE
  gp2xRmmodMMUhack();
  set_speed_clock(CPU_CLOCK_STD);
  cpulcd_deinit();
  sync();
  chdir("/usr/gp2x");
  execl("/usr/gp2x/gp2xmenu", "/usr/gp2x/gp2xmenu", NULL);
#endif
}

/*#undef main

int 
main(int argc, char *argv[])
{
#ifdef GP2X_MODE
  cpulcd_init();
#endif

  atexit(cleanup_output);

#ifdef GP2X_MODE
  gp2xInsmodMMUhack();
#endif

  SDL_main(argc,argv);

  return 0;
}
*/