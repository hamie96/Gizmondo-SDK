/*
 * compfile.c - File I/O and ZLIB compression
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef HAVE_LIBZ
#include <zlib.h>
#include "unzip.h"
#endif

#include "atari.h"
#include "log.h"
#include "util.h"

#include "compfile.h"

#define UNCOMPRESS_BUFFER_SIZE 131072

/* GZ decompression ------------------------------------------------------ */

/* Opens a GZIP compressed file and decompresses its contents to outfp.
   Returns TRUE on success. */
int CompressedFile_ExtractGZ(const char *infilename, FILE *outfp)
{
#ifndef HAVE_LIBZ
	Aprint("This executable cannot decompress ZLIB files");
	return FALSE;
#else
	/* TODO: replace gz* with low-level light-weight ZLIB functions. */
	gzFile gzf = gzopen(infilename, "rb");
	void *buf;
	int result;
	if (gzf == Z_NULL) {
		Aprint("ZLIB could not open file %s", infilename);
		return FALSE;
	}
	buf = Util_malloc(UNCOMPRESS_BUFFER_SIZE);
	do {
		result = gzread(gzf, buf, UNCOMPRESS_BUFFER_SIZE);
		if (result > 0) {
			if ((int) fwrite(buf, 1, result, outfp) != result)
				result = -1;
		}
	} while (result == UNCOMPRESS_BUFFER_SIZE);
	free(buf);
	gzclose(gzf);
	return result >= 0;
#endif	/* HAVE_LIBZ */
}

int CompressedFile_ExtractGZF(FILE * infp, FILE *outfp)
{
#ifndef HAVE_LIBZ
	Aprint("This executable cannot decompress ZLIB files");
	return FALSE;
#else
	/* TODO: replace gz* with low-level light-weight ZLIB functions. */

	// MWW: WTF does this fix it?! 
	// I reckon a glibc bug:-)
	FILE * tmp = fopen("\\Temp\\zlib.tmp","wb");
	char * buffer = malloc(131072);
	int size = 131072;
	int read = 0;
	void *buf;
	int result;
	int fd;
	gzFile gzf;

	fseek(infp, 0, SEEK_SET);
	do
	{
		read = fread(buffer, 1, size, infp);
		fwrite(buffer,read,1,tmp);
	}while (read==size);

	fclose(tmp);

	gzf = gzopen("\\Temp\\zlib.tmp", "rb");

	if (gzf == Z_NULL) {
		Aprint("ZLIB could not open file from fd %d", fileno(infp));
		return FALSE;
	}
	
	buf = Util_malloc(UNCOMPRESS_BUFFER_SIZE);
	do {
		result = gzread(gzf, buf, UNCOMPRESS_BUFFER_SIZE);
		if (result > 0) {
			if ((int) fwrite(buf, 1, result, outfp) != result)
				result = -1;
		}
	} while (result == UNCOMPRESS_BUFFER_SIZE);
	free(buf);
	gzclose(gzf);
	return result >= 0;
#endif	/* HAVE_LIBZ */
}

/* Pulling files out of ZIPs --------------------------------------------- */
int CompressedFile_ExtractFromZIP(const char *infilename, FILE *outfile)
{
	unzFile zipSource;

	// Get the pointer to the actual file we want
	const char * realFile = infilename;
	do
	{
		if ((strncmp(realFile, ".ZIP", 4) == 0) || (strncmp(realFile, ".zip", 4) == 0))
		{
			realFile+=5;
			*(char *)(realFile-1) = 0;
			break;
		}
	} while (realFile++);

	// Open the input file
	zipSource = unzOpen( infilename );
	if( !zipSource )
	{
		//fprintf(stderr, "ZLIB minizip could not open file %s", infilename);
		Aprint( "ZLIB minizip could not open file %s", infilename );
		return FALSE;
	}
	else	/* Convert the zip file to the temporary file */
	{
		int	result=-1, temp;
		Aprint( "Converting %s(%s)", infilename, realFile);
		if (UNZ_OK == unzLocateFile(zipSource, realFile,1))
		{
			//fprintf(stderr, "Found %s in zip %s\n", realFile, infilename);
			unzOpenCurrentFile(zipSource);

			do
			{
				char buffer[1024];
				result = unzReadCurrentFile( zipSource, buffer, 1024 );
				if( result > 0 )
				{
					if( fwrite(buffer, 1, result, outfile) != result )
					{
						Aprint( "Error writing to temporary file, disk may be full");
						result = -1;
					}
				}
			} while( result == 1024 );

			unzCloseCurrentFile(zipSource);
		}
		else
		{
			Aprint("File %s not in zip %s\n", realFile, infilename);
		}
		temp = unzClose( zipSource );
		if( result < 0 )
		{
			Aprint( "Error while parsing zip file" );
			return FALSE;
		}
	}

#ifdef BACK_SLASH
       *(char *)(realFile-1) = '\\';
#else
       *(char *)(realFile-1) = '/';
#endif

       // FIXME
       fseek(outfile,0,SEEK_SET);
      // FILE * x = tmpfile();
     //  CompressedFile_ExtractGZF(outfile, x);

	return TRUE;
}

/* DCM decompression ----------------------------------------------------- */

static int fgetw(FILE *fp)
{ 
	int low;
	int high;
	low = fgetc(fp);
	if (low == EOF)
		return -1;
	high = fgetc(fp);
	if (high == EOF)
		return -1;
	return low + (high << 8);
}

static int fload(void *buf, int size, FILE *fp)
{
	return (int) fread(buf, 1, size, fp) == size;
}

static int fsave(void *buf, int size, FILE *fp)
{
	return (int) fwrite(buf, 1, size, fp) == size;
}

static int write_atr_header(FILE *fp, int sectorcount, int sectorsize)
{
	struct ATR_Header header;
	ULONG paras = (sectorsize != 256 || sectorcount <= 3)
		? (sectorcount << 3) /* single density or only boot sectors: sectorcount * 128 / 16 */
		: (sectorcount << 4) - 0x18; /* double density with 128-byte boot sectors: (sectorcount * 256 - 3 * 128) / 16 */
	memset(&header, 0, sizeof(header));
	header.magic1 = MAGIC1;
	header.magic2 = MAGIC2;
	header.secsizelo = (UBYTE) sectorsize;
	header.secsizehi = (UBYTE) (sectorsize >> 8);
	header.seccountlo = (UBYTE) paras;
	header.seccounthi = (UBYTE) (paras >> 8);
	header.hiseccountlo = (UBYTE) (paras >> 16);
	header.hiseccounthi = (UBYTE) (paras >> 24);
	return fsave(&header, sizeof(header), fp);
}

int CompressedFile_DCMtoATR(FILE *infp, FILE *outfp)
{
	int archive_type;
	int archive_flags;
	int sectorcount;
	int sectorsize;
	UBYTE zero_buf[256];
	int pass_flags;
	int sector;
	archive_type = fgetc(infp);
	if (archive_type != 0xf9 && archive_type != 0xfa) {
		Aprint("This is not a DCM image");
		return FALSE;
	}
	archive_flags = fgetc(infp);
	if ((archive_flags & 0x1f) != 1) {
		Aprint("Expected pass one first");
		if (archive_type == 0xf9)
			Aprint("It seems that multi-file archive has been concatenated in wrong order");
		return FALSE;
	}
	switch ((archive_flags >> 5) & 3) {
	case 0:
		sectorcount = 720;
		sectorsize = 128;
		break;
	case 1:
		sectorcount = 720;
		sectorsize = 256;
		break;
	case 2:
		sectorcount = 1040;
		sectorsize = 128;
		break;
	default:
		Aprint("Unrecognized density");
		return FALSE;
	}
	if (!write_atr_header(outfp, sectorcount, sectorsize))
		return FALSE;
	memset(zero_buf, 0, sizeof(zero_buf));
	pass_flags = archive_flags;
	sector = 1;
	for (;;) {
		/* pass */
		UBYTE sector_buf[256];
		int blocktype;
		memset(sector_buf, 0, sizeof(sector_buf));
		do {
			/* sector group */
			int next_sector = fgetw(infp);
			if (next_sector < sector)
				return TRUE; // FIXME
			while (sector < next_sector) {
				if (!fsave(zero_buf, sector <= 3 ? 128 : sectorsize, outfp))
					return FALSE;
				sector++;
			}
			do {
				/* sector */
				int i;
				blocktype = fgetc(infp);
				if (blocktype == 0x45)
					break;
				switch (blocktype & 0x7f) {
				case 0x41:
					i = fgetc(infp);
					if (i == EOF)
						return FALSE;
					do {
						int b = fgetc(infp);
						if (b == EOF)
							return FALSE;
						sector_buf[i] = (UBYTE) b;
					} while (i-- != 0);
					break;
				case 0x42:
					if (!fload(sector_buf + 123, 5, infp))
						return FALSE;
					memset(sector_buf, sector_buf[123], 123);
					break;
				case 0x43:
					i = 0;
					do {
						int j;
						int c;
						j = fgetc(infp);
						if (j < i) {
							if (j != 0)
								return FALSE;
							j = 256;
						}
						if (i < j && !fload(sector_buf + i, j - i, infp))
							return FALSE;
						if (j >= sectorsize)
							break;
						i = fgetc(infp);
						if (i < j) {
							if (i != 0)
								return FALSE;
							i = 256;
						}
						c = fgetc(infp);
						if (c == EOF)
							return FALSE;
						memset(sector_buf + j, c, i - j);
					} while (i < sectorsize);
					break;
				case 0x44:
					i = fgetc(infp);
					if (i == EOF || i >= sectorsize)
						return FALSE;
					if (!fload(sector_buf + i, sectorsize - i, infp))
						return FALSE;
					break;
				case 0x46:
					break;
				case 0x47:
					if (!fload(sector_buf, sectorsize, infp))
						return FALSE;
					break;
				default:
					Aprint("Unrecognized block type 0x%02X", blocktype);
					return FALSE;
				}
				if (!fsave(sector_buf, sector <= 3 ? 128 : sectorsize, outfp))
					return FALSE;
				sector++;
			} while (blocktype & 0x80);
		} while (blocktype != 0x45);
		if (pass_flags & 0x80)
			break;
		blocktype = fgetc(infp);
		if (blocktype != archive_type) {
			if (blocktype == EOF && archive_type == 0xf9) {
				Aprint("Multi-part archive error.");
				Aprint("To process these files, you must first combine the files into a single file.");
#if defined(WIN32) || defined(DJGPP)
				Aprint("COPY /B file1.dcm+file2.dcm+file3.dcm newfile.dcm from the DOS prompt");
#elif defined(linux) || defined(unix)
				Aprint("cat file1.dcm file2.dcm file3.dcm >newfile.dcm from the shell");
#endif
			}
			return FALSE;
		}
		pass_flags = fgetc(infp);
		if ((pass_flags ^ archive_flags) & 0x60) {
			Aprint("Density changed inside DCM archive?");
			return FALSE;
		}
		/* TODO: check pass number, this is tricky for >31 */
	}
	/* note: last written sector is (sector - 1) */
	if (sector - 1 == sectorcount)
		return TRUE;
	if (sector - 1 < sectorcount) {
		/* write remaining sectors */
		do {
			if (!fsave(zero_buf, sector <= 3 ? 128 : sectorsize, outfp))
				return FALSE;
		} while (sector++ < sectorcount);
		return TRUE;
	}
	/* more sectors written: update ATR header */
	Util_rewind(outfp);
	return write_atr_header(outfp, sector - 1, sectorsize);
}
