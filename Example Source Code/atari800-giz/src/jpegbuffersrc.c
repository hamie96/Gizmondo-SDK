// jpeg_buffer_src routine by Rainer Johanni (released under GPL)
/*******************************************************************
 *                                                                 *
 *    The following routines define a JPEG Source manager which    *
 *    just reads from a given buffer (instead of a file as in      *
 *    the jpeg library)                                            *
 *                                                                 *
 *******************************************************************/

#include <stdlib.h>
#include <stdio.h>

#include "jpeglib.h"

/*
 * Initialize source --- called by jpeg_read_header
 * before any data is actually read.
 */

static void
init_source (j_decompress_ptr cinfo)
{
  /* no work necessary here */
}


/*
 * Fill the input buffer --- called whenever buffer is emptied.
 *
 * Should never be called since all data should be allready provided.
 * Is nevertheless sometimes called - sets the input buffer to data
 * which is the JPEG EOI marker;
 *
 */

static char EOI_data[2] = { 0xFF, 0xD9 };

static boolean
fill_input_buffer (j_decompress_ptr cinfo)
{
  cinfo->src->next_input_byte = EOI_data;
  cinfo->src->bytes_in_buffer = 2;
  return TRUE;
}


/*
 * Skip data --- used to skip over a potentially large amount of
 * uninteresting data (such as an APPn marker).
 *
 */

static void
skip_input_data (j_decompress_ptr cinfo, long num_bytes)
{
  if (num_bytes > 0) {
    if (num_bytes > (long) cinfo->src->bytes_in_buffer)
      num_bytes = (long) cinfo->src->bytes_in_buffer;
    cinfo->src->next_input_byte += (size_t) num_bytes;
    cinfo->src->bytes_in_buffer -= (size_t) num_bytes;
  }
}

/*
 * Terminate source --- called by jpeg_finish_decompress
 * after all data has been read.  Often a no-op.
 */

static void
term_source (j_decompress_ptr cinfo)
{
  /* no work necessary here */
}

void
jpeg_buffer_src (j_decompress_ptr cinfo, unsigned char *buffer, long num)
{
  /* The source object and input buffer are made permanent so that a series
   * of JPEG images can be read from the same buffer by calling jpeg_buffer_src
   * only before the first one.  (If we discarded the buffer at the end of
   * one image, we'd likely lose the start of the next one.)
   * This makes it unsafe to use this manager and a different source
   * manager serially with the same JPEG object.  Caveat programmer.
   */
  if (cinfo->src == NULL) {     /* first time for this JPEG object? */
    cinfo->src = (struct jpeg_source_mgr *)
      (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_PERMANENT,
                                  sizeof(struct jpeg_source_mgr));
  }

  cinfo->src->init_source = init_source;
  cinfo->src->fill_input_buffer = fill_input_buffer;
  cinfo->src->skip_input_data = skip_input_data;
  cinfo->src->resync_to_restart = jpeg_resync_to_restart; /* use default method */
  cinfo->src->term_source = term_source;
  cinfo->src->bytes_in_buffer = num;
  cinfo->src->next_input_byte = (JOCTET *) buffer;
}

