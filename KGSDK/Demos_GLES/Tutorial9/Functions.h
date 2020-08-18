//=======================================================================
//Tutorial 9: TGA / Bitmapped Text

//--------------------------------------------
//File:			Functions.h
//Description:	Contains all the non-relevant OpenGL|ES,
//				Drawing code for Tutorial 8
//
//Author: King (King@Gizmondoforums.com)
//Copyright (c) GizzedINC. All rights reserved.
//=======================================================================

#include <windows.h>
#include <GLES\gl.h>
#include <GLES\egl.h>
#include "KGSDK\framework.h"
#include "KGSDK\framework2D.h"
#include "KGSDK\frameworkGL.h"

#pragma comment(lib, "Framework.lib") 
#pragma comment(lib, "libGLES_CM.lib") 
#pragma comment(lib, "dxguid.lib") 
#pragma comment(lib, "ddraw.lib") 

static float rot[3];
static float loc[3];

float xrot = 0.0f;	
float yrot = 0.0f;	
		
#define NUMBER_OF_COLUMNS 16.0f;		//Number of columns in the Font Blue print
#define NUMBER_OF_ROWS 8.0f;			//Number of rows in the Font Blue print

const int NumberOfFonts = 2;			//NumberOfFonts
char *FontFiles[] =						//Filename of Fonts
{
	"KGSDK_Tahoma_Font.tga",
	"KGSDK_Twentieth_Century_Poster_1_Font.tga"
};

GLuint texture[NumberOfFonts];			//Storage for two textures (two fonts)

enum {Tahoma, TCP1} AvailableFonts;						//Enumeration of the Fonts we have loaded
enum {Use_GL_NEAREST, Use_GL_LINEAR} Texture_Filters;	//Enumeration of the Texture Filters

struct TGAFile							//Structure of a TGA File
{
	unsigned char typeCode;				//Format of the File
	short int width;					//Width of the File
	short int height;					//Height of the File
	unsigned char bpp;					//Bits per pixel
	GLenum format;						//Format of the File 
	unsigned char *imageData;			//Image Data
};

#include "BitmappedText.h"
//--------------------------------------------------------------------------------------------------------------------------------------
bool LoadUncompressedTGA(char *filename, TGAFile *tgaFile)
{
	FILE *file;							//TGA File we're loading

	unsigned char tmpRGB;				//Temporary variable used when converting from BGR -> RGB

	unsigned char ucNull;				//Recycle-Bin for 'unsigned char' elements of the TGA File
	unsigned short usNull;				//Recycle-Bin for 'unsigned short' elements of the TGA File

	TCHAR path[256];					//Path
	char fullPath[256];					//Path
	GetModuleFileName(NULL, path, 256);	//Get Current Working Directory

	TCHAR *pos = wcsrchr(path, '\\');	//Find last \\ so that we can remove the last part
	*(pos + 1) = '\0';					//Add NULL Character to position found, effectively removing last part
	
	wcstombs(fullPath, path, 256);		//Convert Wide characters to multi-byte
	
	strcat(fullPath, filename);			//Combine path with filename

	file = fopen(fullPath,"rb");		//Open File
	if (!file)							//Check validity of file
	{
		MessageBox(NULL, L"Can't Find TGA", L"Error", MB_OK);
		return false;
	}

	fread(&ucNull,sizeof(unsigned char),1,file);				//Discard idLength variable
	fread(&ucNull,sizeof(unsigned char),1,file);				//Discard colorMapType variable

	fread(&tgaFile->typeCode,sizeof(unsigned char),1,file);		//Save imageType variable to TGAFile structure

	if (tgaFile->typeCode != 2 && tgaFile->typeCode != 3)		//Make sure the File is an uncompressed TGA File
	{
		MessageBox(NULL, L"Incorrect texture type", L"Error", MB_OK);
		fclose(file);
		return false;
	}

	fread(&usNull,sizeof(unsigned short),1,file);				//Discard colorMapOrigin variable
	fread(&usNull,sizeof(unsigned short),1,file);				//Discard colorMapLength variable
	fread(&ucNull,sizeof(unsigned char),1,file);				//Discard colorMapEntrySize variable
	fread(&usNull,sizeof(unsigned short),1,file);				//Discard originX variable
	fread(&usNull,sizeof(unsigned short),1,file);				//Discard originY variable

	fread(&tgaFile->width, sizeof(unsigned short), 1, file);	//Save Width variable to TGAFile structure
	fread(&tgaFile->height, sizeof(unsigned short), 1, file);	//Save Height variable to TGAFile structure
	fread(&tgaFile->bpp, sizeof(unsigned char), 1, file);		//Save BPP(Bits Per Pixel) variable to TGAFile structure

	fread(&ucNull,sizeof(unsigned char),1,file);				//Discard descriptor variable

	int colorMode = tgaFile->bpp / 8;							//Convert Bits Per Pixel, to Bytes Per Pixel (Simply divide by 8)			

	if (colorMode == 3)											//If there isn't an Alpha Channel..			
		tgaFile->format = GL_RGB;								//	- Set to RGB Only..
	else														//	- Otherwise..
		tgaFile->format = GL_RGBA;								//	- Set RGBA

	long imageSize = tgaFile->width * tgaFile->height * colorMode;	//Work out total size of file

	tgaFile->imageData = new unsigned char[imageSize];			//Allocate enough memory for all of the image data

	if (!tgaFile->imageData)									//Check if Allocation is successful
	{
		MessageBox(NULL, L"Out of Memory", L"Error", MB_OK);
		delete[] tgaFile->imageData;
		fclose(file);
		return false;
	}

	fread(tgaFile->imageData,sizeof(unsigned char),imageSize,file);//Save image data to TGAFile structure

	if (!tgaFile->imageData)									//Check if the image data was loaded successfully
	{
		MessageBox(NULL, L"Error reading TGA", L"Error", MB_OK);
		fclose(file);
		return false;
	}

	for (int i = 0; i < imageSize; i += colorMode)				//Convert Image Data from BGR -> RGB (Swap last and first values around)
	{
		tmpRGB = tgaFile->imageData[i];
		tgaFile->imageData[i] = tgaFile->imageData[i+2];
		tgaFile->imageData[i+2] = tmpRGB;
	}

	fclose(file);												//Close File..

	return true;												//Function Completed Successfully .. Return..
}
//--------------------------------------------------------------------------------------------------------------------------------------
bool LoadTextures()
{
	TGAFile tgaFile;											//TGA File

	glGenTextures(NumberOfFonts, texture);						//Generate Unique Texture Identifiers

	for (int i = 0; i < NumberOfFonts; i++)						//Loop through each TGA File we are going to load
	{
		if (!LoadUncompressedTGA(FontFiles[i], &tgaFile))		//Load The File..
			return false;										//If Loading Fails, Exit Function

		glBindTexture(GL_TEXTURE_2D, texture[i]);				//Select the current texture

		glTexImage2D(GL_TEXTURE_2D, 0, tgaFile.format, tgaFile.width,	//Set Properties
			tgaFile.height, 0, tgaFile.format, GL_UNSIGNED_BYTE,
			tgaFile.imageData);

		glTexParameterf(GL_TEXTURE_2D,							//Set Min Filter of Texture
			GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D,							//Set Max Filter of Texture
			GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		delete[] tgaFile.imageData;								//Delete the Image Data
	}

	return true;												//Function Completed Successfully .. Return..
}
//--------------------------------------------------------------------------------------------------------------------------------------

