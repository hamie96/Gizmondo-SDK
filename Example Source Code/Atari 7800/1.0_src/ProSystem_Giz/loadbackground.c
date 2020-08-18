
#include <stdlib.h>
#include <stdio.h>

#include "jpeglib.h"
#include "jpegbuffersrc.h"

unsigned short
psp_sdl_rgb(unsigned char R, unsigned char G, unsigned char B);

#define BACKGROUNDJPG_LEN 8107
extern unsigned char backgroundjpg[];

void * loadbackground()
{
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;
	JSAMPARRAY buffer;
	int row_stride;
	unsigned short * mem;
	unsigned short * memstart;

	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);
	//jpeg_stdio_src(&cinfo, infile);

	jpeg_buffer_src(&cinfo, backgroundjpg, BACKGROUNDJPG_LEN);
	jpeg_read_header(&cinfo, TRUE);
	jpeg_start_decompress(&cinfo);

	memstart = malloc(321*240*2);

	row_stride = cinfo.output_width * cinfo.output_components;
	buffer = (*cinfo.mem->alloc_sarray)((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

	mem = (unsigned short *)memstart;
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

			col = psp_sdl_rgb(r,g,b);

			*mem++ = col;
		}
		mem++;
	}

	jpeg_finish_decompress(&cinfo);

	return memstart;
}
