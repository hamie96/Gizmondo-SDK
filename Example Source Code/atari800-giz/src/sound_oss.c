/*
 * sound_oss.c - Open Sound System driver
 *
 * Copyright (C) 1995-1998 David Firth
 * Copyright (C) 1998-2005 Atari800 development team (see DOC/CREDITS)
 *
 * This file is part of the Atari800 emulator project which emulates
 * the Atari 400, 800, 800XL, 130XE, and 5200 8-bit computers.
 *
 * Atari800 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Atari800 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Atari800; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "config.h"

#ifdef SOUND

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/soundcard.h>
/* XXX: #include <machine/soundcard.h> */

#include "atari.h"
#include "log.h"
#include "pokeysnd.h"
#include "util.h"

static const char * const dspname = "/dev/dsp";
static int dsprate = 22050;

static int sound_enabled = TRUE;
static int dsp_fd;
static int output_channels;
static int pokey_chips;

void Sound_Initialise(int *argc, char *argv[])
{
	int i, j;
	int help_only = FALSE;

	for (i = j = 1; i < *argc; i++) {
		if (strcmp(argv[i], "-sound") == 0)
			sound_enabled = TRUE;
		else if (strcmp(argv[i], "-nosound") == 0)
			sound_enabled = FALSE;
		else if (strcmp(argv[i], "-dsprate") == 0)
			dsprate = Util_sscandec(argv[++i]);
		else {
			if (strcmp(argv[i], "-help") == 0) {
				help_only = TRUE;
				Aprint("\t-sound           Enable sound\n"
				       "\t-nosound         Disable sound\n"
				       "\t-dsprate <rate>  Set sample rate in Hz"
				      );
			}
			argv[j++] = argv[i];
		}
	}
	*argc = j;

	if (help_only || !sound_enabled)
		return;

	dsp_fd = open(dspname, O_WRONLY);
	if (dsp_fd == -1) {
		perror(dspname);
		sound_enabled = FALSE;
		return;
	}
	i = AFMT_U8;
	if (ioctl(dsp_fd, SNDCTL_DSP_SETFMT, &i)) {
		Aprint("%s: cannot set 8-bit unsigned samples", dspname);
		close(dsp_fd);
		sound_enabled = FALSE;
		return;
	}

	/* try to set the OSS device into appropriate number of channels (1 for
	 * single pokey, 2 for dual Pokey).
	 * If the sound card does not support the mode we need it should not fail
	 * but just set the output_channels to value it's able to support.
	 */
#ifdef STEREO_SOUND
	output_channels = 2;
#else
	output_channels = 1;
#endif
	if (ioctl(dsp_fd, SNDCTL_DSP_CHANNELS, &output_channels)) {
		Aprint("%s: SNDCTL_DSP_CHANNELS(%1) failed", dspname, output_channels);
		close(dsp_fd);
		sound_enabled = FALSE;
		return;
	}

	if (ioctl(dsp_fd, SNDCTL_DSP_SPEED, &dsprate)) {
		Aprint("%s: cannot set %d sample rate", dspname, dsprate);
		close(dsp_fd);
		sound_enabled = FALSE;
		return;
	}
	if (dsprate < 1000 || dsprate > 65535) {
		Aprint("%s: %d sample rate is not supported", dspname, dsprate);
		close(dsp_fd);
		sound_enabled = FALSE;
		return;
	}

#ifdef STEREO_SOUND
	pokey_chips = 2; /* stereo sound generated by two Pokey chips */
#else
	pokey_chips = 1;
#endif
	Pokey_sound_init(FREQ_17_EXACT, dsprate, pokey_chips, 0);
}

void Sound_Pause(void)
{
	if (sound_enabled) {
		/* flush buffers */
		ioctl(dsp_fd, SNDCTL_DSP_POST, NULL);
	}
}

void Sound_Continue(void)
{
	/* do nothing */
}

void Sound_Exit(void)
{
	if (sound_enabled) {
		close(dsp_fd);
		sound_enabled = FALSE;
	}
}

void Sound_Update(void)
{
	/* 4096 bytes are enough for stereo 102400Hz
	   - pokeysnd currently supports only up to 65535Hz */
	static unsigned char buffer[4096];
	unsigned int len;
	if (!sound_enabled)
		return;
	/* compute number of samples for one Atari frame
	   (assuming 60Hz for NTSC and 50Hz for PAL) */
	len = dsprate / (tv_mode == TV_NTSC ? 60 : 50) * pokey_chips;

#if 0
	/* this code is not needed because buffer[] is big enough */
	while (len > sizeof(buffer)) {
		Pokey_process(buffer, sizeof(buffer));
		write(dsp_fd, buffer, sizeof(buffer));
		len -= sizeof(buffer);
	}
#endif

	Pokey_process(buffer, len);

#if 0
	/* For some unknown reason, this is needed
	   on Piotr's Red Hat 9, VT82C686 AC97 Audio Controller.
	   Not that the sound is just a bit silent without this,
	   it is totally broken. */
	{
		unsigned int i;
		for (i = 0; i < len; i++)
			buffer[i] <<= 1;
	}
#endif

	/* the following block of code deals with situation when Pokey output
	 * does not match OSS output.
	 * It would better be handled in the Pokey emulation itself
	 */
	if (output_channels == 2) {
		/* OSS device set to two channel mode */
		if (pokey_chips == 1) {
			/* upmix mono to stereo - for sound in both channels */
			int i;
			for (i = len-1; i >= 0; i--) {
				int pos = i * 2;
				buffer[pos] = buffer[pos+1] = buffer[i];
			}
		}
		else if (! stereo_enabled) {
			/* only single Pokey plays - copy left channel to right channel */
			int i;
			for (i = 0; i < len; i+=2) {
				buffer[i+1] = buffer[i];
			}
		}
	}
	else {
		/* OSS device set to single channel output */
		if (pokey_chips == 2) {
			/* downmix both channels into single output */
			int i;
			for (i = 0; i < len/2; i++) {
				int pos = i * 2;
				buffer[i] = (stereo_enabled ? buffer[pos]/2 + buffer[pos+1]/2 :
							 buffer[pos]);
			}
		}
	}

	write(dsp_fd, buffer, len);
}

#endif	/* SOUND */

/*
vim:ts=4:sw=4:
*/
