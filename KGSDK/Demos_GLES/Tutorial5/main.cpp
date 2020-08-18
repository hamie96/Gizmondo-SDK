//=======================================================================
//Tutorial 5: Texture Filters
//--------------------------------------------
//File:			main.cpp
//Description:	Advanced Textures. Using texture filters to manipulate 
//				textures.
//
//Author: King (King@Gizmondoforums.com)
//Copyright (c) GizzedINC. All rights reserved.
//=======================================================================

#include <windows.h>
#include <GLES\gl.h>
#include <GLES\egl.h>
#include <KGSDK\framework.h>
#include <KGSDK\frameworkGL.h>

#pragma comment(lib, "Framework.lib") 
#pragma comment(lib, "libGLES_CM.lib") 

static float rot[3];
static float loc[3];

float xrot = 0.0f;	
float yrot = 0.0f;	

GLuint texture[4];

float lightAmbient[] = { 0.7f, 0.8f, 0.9f, 1.0f }; //Ambient Colour Array
float lightDiffuse[] = { 0.7f, 0.8f, 0.9f, 1.0f }; //Diffuse Colour Array

float matAmbient[] = { 0.6f, 0.6f, 0.6f, 1.0f };   //Material Properties for Ambient
float matDiffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };   //Material Properties for Diffuse

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

	bitmap = LoadBitmap("King.bmp", &info);		//Load Bitmap

	if (!bitmap)
	return false;

	glGenTextures(4, texture);					//Generate Texture Identifiers

	//Tex-1
	glBindTexture(GL_TEXTURE_2D, texture[0]);	//Select texture[0]

	glTexImage2D(
		GL_TEXTURE_2D, 0, GL_RGB, info.biWidth,	//Set Texture Properties
		info.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE,
		bitmap);

	//Set texture filter to GL_NEAREST when texture is small
	glTexParameterf(GL_TEXTURE_2D,				
		GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//Set texture filter to GL_NEAREST when texture is big
	glTexParameterf(GL_TEXTURE_2D,
		GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//Tex-2
	glBindTexture(GL_TEXTURE_2D, texture[1]);	//Select texture[1]

	glTexImage2D(								//Set Texture Properties
		GL_TEXTURE_2D, 0, GL_RGB, info.biWidth,	
		info.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE,
		bitmap);
	
	//Set texture filter to GL_LINEAR when texture is small
	glTexParameterf(GL_TEXTURE_2D,				
		GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//Set texture filter to GL_LINEAR when texture is big
	glTexParameterf(GL_TEXTURE_2D,
		GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	// Tex-3
	glBindTexture(GL_TEXTURE_2D, texture[2]);	//Select texture[2]

	glTexImage2D(								//Set Texture Properties
		GL_TEXTURE_2D, 0, GL_RGB, info.biWidth,
		info.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE,
		bitmap);

	//Set texture filter to GL_LINEAR when texture is small
	glTexParameterf(GL_TEXTURE_2D,				
		GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//Set texture filter to GL_LINEAR when texture is big
	glTexParameterf(GL_TEXTURE_2D,
		GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//Set texture to repeat itself horizontally
	glTexParameterf(GL_TEXTURE_2D,
		GL_TEXTURE_WRAP_S, GL_REPEAT);
	//Set texture to clamp to edges vertically
	glTexParameterf(GL_TEXTURE_2D,
		GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// Tex-4
	glBindTexture(GL_TEXTURE_2D, texture[3]);

	glTexParameterf(GL_TEXTURE_2D,
	GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, 
	GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D,
	GL_GENERATE_MIPMAP, GL_TRUE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, info.biWidth,
	info.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE,
	bitmap);

	delete[] bitmap;

	return true;
}
//--------------------------------------------------------------------------------------------------------------------------------------

void Init()
{
	glEnable(GL_LIGHTING);				//Enable Lighting
	glEnable(GL_LIGHT0);				//Enable GL_LIGHT0
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);	//Set Material Properties
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);	//Set Material Properties

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);	//Set Light Properties
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);	//Set Light Properties

	if (!LoadTextures())		//Load Textures, if fails display error message
	{
		MessageBox(NULL, L"Error loading textures", L"Error", MB_OK);
	}
	else
	{
		glEnable(GL_TEXTURE_2D);
	}

	glLoadIdentity();
		
	GLfixed mat[4][4];

	float nearz, farz;

	farz  = 300.0f;
	nearz = 0.01f;

	memset(mat, 0, sizeof(mat));
	mat[0][0] = (int) (65536.0f * 2.4f);
	mat[1][1] = (int) (65536.0f * 3.2f);
	mat[2][2] = (int) (65536.0f * (farz / (farz - nearz)));
	mat[2][3] = (int) (65536.0f * 1.0f);
	mat[3][2] = (int) (65536.0f * ((-farz * nearz) / (farz - nearz)));

	glMatrixMode(GL_PROJECTION);
	glLoadMatrixx(&mat[0][0]);

	rot[0] = 0;
	rot[1] = 0;
	rot[2] = 0;
	loc[0] = 0;
	loc[1] = 0;
	loc[2] = 3;
}


//--------------------------------------------------------------------------------------------------------------------------------------

void DrawCube()
{
	GLfloat cube[] = 
	{
	// FRONT
	-0.5f, -0.5f,  0.5f,
	 0.5f, -0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,
	 0.5f,  0.5f,  0.5f,
	// BACK
	-0.5f, -0.5f, -0.5f,
	-0.5f,  0.5f, -0.5f,
	 0.5f, -0.5f, -0.5f,
	 0.5f,  0.5f, -0.5f,
	// LEFT
	-0.5f, -0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,
	-0.5f, -0.5f, -0.5f,
	-0.5f,  0.5f, -0.5f,
	// RIGHT
	 0.5f, -0.5f, -0.5f,
	 0.5f,  0.5f, -0.5f,
	 0.5f, -0.5f,  0.5f,
	 0.5f,  0.5f,  0.5f,
	// TOP
	-0.5f,  0.5f,  0.5f,
	 0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f, -0.5f,
	 0.5f,  0.5f, -0.5f,
	// BOTTOM
	-0.5f, -0.5f,  0.5f,
	-0.5f, -0.5f, -0.5f,
	 0.5f, -0.5f,  0.5f,
	 0.5f, -0.5f, -0.5f,
	};

	GLfloat texCoords[] = {
	// FRONT
	 0.0f, 0.0f,
	 1.0f, 0.0f,
	 0.0f, 1.0f,
	 1.0f, 1.0f,
	// BACK
	 1.0f, 0.0f,
	 1.0f, 1.0f,
	 0.0f, 0.0f,
	 0.0f, 1.0f,
	// LEFT
	 2.0f, 0.0f,
	 2.0f, 2.0f,
	 0.0f, 0.0f,
	 0.0f, 2.0f,
	// RIGHT
	 3.0f, 0.0f,
	 3.0f, 3.0f,
	 0.0f, 0.0f,
	 0.0f, 3.0f,
	// TOP
	 0.0f, 0.0f,
	 1.0f, 0.0f,
	 0.0f, 1.0f,
	 1.0f, 1.0f,
	// BOTTOM
	 1.0f, 0.0f,
	 1.0f, 1.0f,
	 0.0f, 0.0f,
	 0.0f, 1.0f
	};
    glRotatef(xrot, 1.0f, .0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

	glVertexPointer(3, GL_FLOAT, 0, cube);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	// FRONT AND BACK
    glBindTexture(GL_TEXTURE_2D, texture[0]);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);		 //Color: RED
    glNormal3f(0.0f, 0.0f, 1.0f);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glNormal3f(0.0f, 0.0f,-1.0f);
    glDrawArrays(GL_TRIANGLE_STRIP, 4, 4);

    // LEFT AND RIGHT
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);		//Color: GREEN
    glNormal3f(-1.0f, 0.0f, 0.0f);
	glDrawArrays(GL_TRIANGLE_STRIP, 8, 4);
    glNormal3f(1.0f, 0.0f, 1.0f);
    glDrawArrays(GL_TRIANGLE_STRIP, 12, 4);

    // TOP AND BOTTOM
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);		//Color: BLUE
    glBindTexture(GL_TEXTURE_2D, texture[2]);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glDrawArrays(GL_TRIANGLE_STRIP, 16, 4);
    glBindTexture(GL_TEXTURE_2D, texture[3]);
	glNormal3f(0.0f,-1.0f, 1.0f);
    glDrawArrays(GL_TRIANGLE_STRIP, 20, 4);
}

//--------------------------------------------------------------------------------------------------------------------------------------

void Render()  
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	DrawCube();
	
	glFinish();
	eglSwapBuffers(FrameworkGL_GetDisplay(), FrameworkGL_GetSurface());
}

//--------------------------------------------------------------------------------------------------------------------------------------

void Update()
{
	GLfixed mat[4][4];

	memset(mat, 0, sizeof(mat));
	mat[0][0] = (int) (65536.0f *  cos(rot[0]));
	mat[0][2] = (int) (65536.0f *  sin(rot[0]));
	mat[1][1] = (int) (65536.0f *  cos(rot[1]));
	mat[1][2] = (int) (65536.0f *  sin(rot[1]));
	mat[2][0] = (int) (65536.0f * -sin(rot[0]) * cos(rot[1]));
	mat[2][2] = (int) (65536.0f *  cos(rot[0]) * cos(rot[1]));
	mat[3][2] = (int) (65536.0f * loc[2]);
	mat[3][3] = 65536;
	
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixx(&mat[0][0]);

	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_LEFT_SHOULDER )) 
		loc[2] += 0.3f; 
	// If the Left Shoulder Button has been pressed: Zoom out
	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_RIGHT_SHOULDER)) 
		loc[2] -= 0.3f;
	// If the Right Shoulder Button has been pressed: Zoom In
	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_DPAD_DOWN     )) 
		xrot -= 1.0f;
	// If the Down button (DPAD) has been pressed: Rotate the cube downards
	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_DPAD_UP	     )) 
		xrot += 1.0f;
	// If the Up button (DPAD) has been pressed: Rotate the cube upwards
	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_DPAD_LEFT     )) 
		yrot -= 1.0f;
	// If the Left button (DPAD) has been pressed: Rotate the cube towards the left
	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_DPAD_RIGHT	 )) 
		yrot += 1.0f;
	// If the Right button (DPAD) has been pressed: Rotate the cube towards the Right
	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_DPAD_RIGHT	 )) 
		yrot += 1.0f;
	// If the Right button (DPAD) has been pressed: Rotate the cube towards the Right
}


//--------------------------------------------------------------------------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow )
{
	if (!Framework_Init(hInstance, hPrevInstance))
	{
		return 0;
	}

	if (!FrameworkGL_Init())
	{
		Framework_Close();
		return 0;
	}

	Init();


	do
	{
		Render();
		Update();
		Framework_ProcessMessages();

		if (!Framework_IsAppActive())
		{
			while (!Framework_IsAppActive())
			{
				Framework_ProcessMessages();
				Sleep(50);
			}
		}

	} while (!Framework_IsButtonPressed(FRAMEWORK_BUTTON_HOME));

	FrameworkGL_Close();
	Framework_Close();

	return 0;
}
