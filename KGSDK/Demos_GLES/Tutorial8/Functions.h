//=======================================================================
//Tutorial 8: Applying Mathematics (Sin/Cos/Pi)

//--------------------------------------------
//File:			Functions.h
//Description:	Contains all the non-relevant OpenGL|ES
//				Drawing code for Tutorial 8
//
//Author: King (King@Gizmondoforums.com)
//Copyright (c) GizzedINC. All rights reserved.
//=======================================================================

#include <windows.h>
#include <GLES\gl.h>
#include <GLES\egl.h>
#include "KGSDK\framework.h"
#include "KGSDK\frameworkGL.h"

#pragma comment(lib, "Framework.lib") 
#pragma comment(lib, "libGLES_CM.lib") 

static float rot[3];
static float loc[3];

float xrot = 0.0f;	
float yrot = 0.0f;	

float lightAmbient[] = { 0.7f, 0.8f, 0.9f, 1.0f }; 
float lightDiffuse[] = { 0.7f, 0.8f, 0.9f, 1.0f }; 

float matAmbient[] = { 0.6f, 0.6f, 0.6f, 1.0f };  
float matDiffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };  

#define PERIOD 20.0f				//How many waves
#define AMPLITUDE 2.0f				//Amplitude of Wave
#define PIOVER180 0.01745329252		//Simply PI divided by 180

GLuint texture[1];					//Storage for one texture
float flagPoints[10][36][3];		//Storage for Flag Colours
float flagCoords[10][36][2];		//Storage for Flag Vertexes
float wrapValue;					//Temporary storage for taking the last value, and placing it at the beginning

bool wireFrame = true;				//Indicates whether wireframe mode is selected

//--------------------------------------------------------------------------------------------------------------------------------------
unsigned char *LoadBitmap(char *filename, BITMAPINFOHEADER *bmpInfo)
{
	FILE *file;							//Actual File
	BITMAPFILEHEADER bmpFileHeader;		//Bitmap File Header
	unsigned char *bmpImage = NULL;		//Actual Bitmap Image
	unsigned char tmpRGB;				//Temporary storage for when converting from BGR to RGB

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
		MessageBox(NULL, L"Can't Find Bitmap", L"Error", MB_OK);
		return NULL;
	}

	fread(&bmpFileHeader,sizeof(BITMAPFILEHEADER),1,file); //Read header file into structure
	
	if (bmpFileHeader.bfType != 0x4D42)	//Check to see if the file is a bitmap
	{
		MessageBox(NULL, L"Incorrect texture type", L"Error", MB_OK);
		fclose(file);
		return NULL;
	}

	fread(bmpInfo,sizeof(BITMAPINFOHEADER),1,file);	//Read header info into structure

	fseek(file,bmpFileHeader.bfOffBits,SEEK_SET);	//Move to start of image data
	
	bmpImage = new unsigned char[bmpInfo->biSizeImage];

	if (!bmpImage)						//Memory allocated for image data
	{
		MessageBox(NULL, L"Out of Memory", L"Error", MB_OK);
		delete[] bmpImage;
		fclose(file);
		return NULL;
	}

	fread(bmpImage,1,bmpInfo->biSizeImage,file);	//Load image data

	if (!bmpImage)
	{
		MessageBox(NULL, L"Error reading bitmap", L"Error", MB_OK);
		fclose(file);
		return NULL;
	}

	for (unsigned int i = 0; i < bmpInfo->biSizeImage; i+=3)	//Convert BGR -> RGB													
	{
		tmpRGB = bmpImage[i];
		bmpImage[i] = bmpImage[i+2];
		bmpImage[i+2] = tmpRGB;
	}

	fclose(file);						//Close File

	return bmpImage;					//Return Bitmap Image
}

//--------------------------------------------------------------------------------------------------------------------------------------
bool LoadTextures()
{
	BITMAPINFOHEADER info;						//Structure to hold bitmap data
	unsigned char *bitmap = NULL;				//Pointer to point to image data

	bitmap = LoadBitmap("GFlag.bmp", &info);	//Load Bitmap

	if (!bitmap)
	return false;

	glGenTextures(1, texture);					//Generate Texture Identifiers

	glBindTexture(GL_TEXTURE_2D, texture[0]);	//Select texture[0]

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, info.biWidth,	//Set Texture Properties
		info.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE,
		bitmap);
	
	glTexParameterf(GL_TEXTURE_2D,				//Set further texture properties
		GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D,
		GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	delete[] bitmap;							//Clean Up

	return true;
}
//--------------------------------------------------------------------------------------------------------------------------------------

