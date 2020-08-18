/*

File:			FrameworkKing.h
Description:	FrameworkKing header file.

Copyright (c) GizzedINC Europe Ltd. All rights reserved.

*/

#ifndef _FRAMEWORKKING_H
#define _FRAMEWORKKING_H

#include <windows.h>
#include <GLES\GL.h>
#include <GLES\EGL.h>
//----------------------------------------------------------------------------------------------------------------------------
struct TGAFile
{
	unsigned char typeCode;
	short int width;
	short int height;
	unsigned char bpp;
	GLenum format;
	unsigned char *imageData;
};

bool LoadUncompressedTGA(char *filename, TGAFile *tgaFile);
unsigned char *LoadBitmap(char *filename, BITMAPINFOHEADER *bmpInfo);
bool LoadTexturesTGA(int NumberOfTextures, GLuint TextureHandle[], char *TextureFiles[]);
bool LoadTexturesBMP(int NumberOfTextures, GLuint TextureHandle[], char *TextureFiles[]);

//----------------------------------------------------------------------------------------------------------------------------

#endif // _FRAMEWORKKING_H