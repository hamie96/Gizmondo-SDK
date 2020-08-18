#ifndef _COMPFILE_H_
#define _COMPFILE_H_

#include <stdio.h>  /* FILE */

int CompressedFile_ExtractGZ(const char *infilename, FILE *outfp);
int CompressedFile_ExtractGZF(FILE * infd, FILE * outfd);
int CompressedFile_DCMtoATR(FILE *infp, FILE *outfp);
int CompressedFile_ExtractFromZIP(const char *infilename, FILE *outfp); // /blah/foo/bar.zip/file.atr

#endif /* _COMPFILE_H_ */
