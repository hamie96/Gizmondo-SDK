// Crap loads of new check:

/* Include Windows CE workarounds for each files of the emulator core */
#include "missing.h"

/* Include Windows CE workarounds for each files of the emulator core */
#include "missing.h"

// Define HAVE_CHMOD to set files as read-only with chmod
#undef HAVE_CHMOD

// Think this is win32 directory access (guess not since this is wince and its not defined...)
#undef HAVE_DIRECT_H

// Standard unix dir access
#undef HAVE_DIRENT_H

// Standard unix err no
#undef HAVE_ERRNO_H

// Standard unix file access thingy
#undef HAVE_FCNTL_H

// Temp file thing
#undef HAVE_FDOPEN

// File system flushing
#undef HAVE_FFLUSH

// Can get working dir
#define HAVE_GETCWD 1

// Image library - replaces pcx crap
#define HAVE_LIBPNG 1

// duh
#define HAVE_LIBZ 1

// part of time stuff 
#undef HAVE_LOCALTIME

// Can make dir!
#undef HAVE_MKDIR

//temp files
#undef HAVE_MKSTEMP
#undef HAVE_MKTEMP

// more of dirent?
#undef HAVE_OPENDIR

// yep, can rename
#undef HAVE_RENAME

// more of stdio FFS 
#undef HAVE_REWIND

// ditto
#undef HAVE_RMDIR

// Don't want signal - well not on gp32 or generally really
#undef HAVE_SIGNAL
#undef HAVE_SIGNAL_H

// More libc
#undef HAVE_SNPRINTF
#define HAVE_STRCHR 1
#define HAVE_STRDUP 1

// Use system to run commands? nope...
#undef HAVE_SYSTEM

// system specific?

// time

// more temp stuff
#define HAVE_TMPFILE 1
#define HAVE_TMPNAM 1

#define HAVE_UNLINK 1

/* config.h.  Generated automatically by configure.  */
/* config.h.in.  Generated automatically from configure.in by autoheader.  */

/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define as __inline if that's what the C compiler calls it.  */
/* #undef inline */

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */

/* Define if your <sys/time.h> declares struct tm.  */
/* #undef TM_IN_SYS_TIME */

/* Define if your processor stores words with the most significant
   byte first (like Motorola and SPARC, unlike Intel and VAX).  */
/* #undef WORDS_BIGENDIAN */

/* The number of bytes in a long.  */
#define SIZEOF_LONG 4

/* Define if you have the strdup function.  */
#define HAVE_STRDUP 1

/* Define if you have the strerror function.  */

/* Define if you have the <dirent.h> header file.  */

/* Define if you have the <fcntl.h> header file.  */

/* Define if you have the <sys/dir.h> header file.  */
/* #undef HAVE_SYS_DIR_H */

/* Define if you have the <sys/ioctl.h> header file.  */
#define HAVE_SYS_IOCTL_H 1

/* Define if you have the <sys/ndir.h> header file.  */
/* #undef HAVE_SYS_NDIR_H */

/* Define if you have the <sys/time.h> header file.  */

/* Define if you have the <unistd.h> header file.  */

/* Define if you have the m library (-lm).  */
#define HAVE_LIBM 1

/* Define if you have the ncurses library (-lncurses).  */
/* #undef HAVE_LIBNCURSES */

/* Define if you have the olgx library (-lolgx).  */
/* #undef HAVE_LIBOLGX */

/* Define if you have the winmm library (-lwinmm).  */
/* #undef HAVE_LIBWINMM */

/* Define if you have the xview library (-lxview).  */
/* #undef HAVE_LIBXVIEW */

/* Define if you have the z library (-lz).  */
#define HAVE_LIBZ 1

/* #undef BASIC */

/* #undef CURSES */

/* #undef NCURSES */

/* #undef WIN32 */

#define DIRECTX

//#define X11 0

/* #undef XVIEW */

/* #undef MOTIF */

//#define SHM 0

/* define to enable dos style drives support */
/* #undef DOS_DRIVES */

/* define to use back slash */
#define BACK_SLASH

/* define if unaligned long access is ok */
//#define UNALIGNED_LONG_OK 1

/* Is your computer very slow (disables generating screen completely) */
/* #undef VERY_SLOW */

/*  Show crash menu after CIM instruction */
#define CRASH_MENU 1

/* Enable BREAK command in monitor (slows CPU a little bit) */
/* #undef MONITOR_BREAK */

/* Enable hints in disassembler (addresses get human readable labels) */
#define MONITOR_HINTS 1

/* Enable assembler in monitor (you can enter ASM insns directly) */
#define MONITOR_ASSEMBLER 1

/* Compile internal palettes */
/* #undef COMPILED_PALETTE */

/* Use cursor keys/Ctrl for keyboard joystick */
/* #undef USE_CURSORBLOCK */

/* Run atari800 as Linux realtime process */
//#define REALTIME 0

/* Enable LINUX Joystick */
//#define LINUX_JOYSTICK 0

/* define to enable sound */
#define SOUND 1

/* define to disable console sound (keyboard clicks) */
/* #undef NO_CONSOL_SOUND */

/* define to enable serial in/out sound */
/* #undef SERIO_SOUND */

/* define to disable sound interpolation */
//#define NOSNDINTER 

/* define to enable sound clipping */
#define CLIP
#define CLIP_SOUND

/* define to enable stereo sound */
#define STEREO
#define STEREO_SOUND

/* extra sounds!
 */
#define CONSOLE_SOUND
#define SERIO_SOUND
#define VOL_ONLY_SOUND

/* Buffer debug output (until the graphics mode switches back to text mode) */
/* #undef BUFFERED_LOG */

/* Emulate disk LED diode */
/* #undef SET_LED */

/* Display LED on screen */
/* #undef NO_LED_ON_SCREEN */

//#define DIRTYRECT
//#define NODIRTYCOMP
//#define PAGED_MEM
#define PAGED_ATTRIB
#define NEW_CYCLE_EXACT
#define DAVEC

#define GP2X

/* Alternate config filename due to 8 + 3 limit (huh? Sure I've seen longer on giz)*/
#define DEFAULT_CFG_NAME "atari800.cfg"

