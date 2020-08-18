#include "FrameworkKing.h"

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
bool LoadTexturesTGA(int NumberOfTextures, GLuint TextureHandle[], char *TextureFiles[])
{
	TGAFile tgaFile;											//TGA File

	glGenTextures(NumberOfTextures, TextureHandle);				//Generate Unique Texture Identifiers

	for (int i = 0; i < NumberOfTextures; i++)					//Loop through each TGA File we are going to load
	{
		if (!LoadUncompressedTGA(TextureFiles[i], &tgaFile))	//Load The File..
			return false;										//If Loading Fails, Exit Function

		glBindTexture(GL_TEXTURE_2D, TextureHandle[i]);			//Select the current texture

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
bool LoadTexturesBMP(int NumberOfTextures, GLuint TextureHandle[], char *TextureFiles[])
{
	BITMAPINFOHEADER info;							//Structure to hold bitmap data
	unsigned char *bitmap = NULL;					//Pointer to point to image data

	glGenTextures(NumberOfTextures, TextureHandle);	//Generate Texture Identifiers
	for (int i = 0; i < NumberOfTextures; i++)		//Loop through each TGA File we are going to load
	{
		bitmap = LoadBitmap(TextureFiles[i], &info);//Load Bitmap

		if (!bitmap)
		return false;


		glBindTexture(GL_TEXTURE_2D, TextureHandle[i]);	//Select texture[0]

		glTexImage2D(
			GL_TEXTURE_2D, 0, GL_RGB, info.biWidth,		//Set Texture Properties
			info.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE,
			bitmap);

		//Set texture filter to GL_NEAREST when texture is small
		glTexParameterf(GL_TEXTURE_2D,				
			GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		//Set texture filter to GL_NEAREST when texture is big
		glTexParameterf(GL_TEXTURE_2D,
			GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		delete[] bitmap;
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------------------------

