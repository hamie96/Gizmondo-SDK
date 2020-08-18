//=======================================================================
//Tutorial 6: Fog
//--------------------------------------------
//File:			main.cpp
//Description:	Demonstrates the fog principle, and properties of.
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

float LightGray[] = { 0.6f, 0.6f, 0.6f, 0.0f };	//Light Gray Colour (RGBA)
float DarkGray[] = { 0.1f, 0.1f, 0.1f, 0.0f };	//Dark Gray Colour (RGBA)

bool ColourLight = true;		//Fog Colour Light Gray?
bool EnableLighting = true;		//Lighting Enabled?

float xrot = 0.0f;
float yrot = 0.0f;

float lightAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };

float matAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };

//--------------------------------------------------------------------------------------------------------------------------------------

void Init()
{
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

	glFogf(GL_FOG_MODE, GL_LINEAR);		//Set Fog Mode
	glFogfv(GL_FOG_COLOR, LightGray);	//Set Fog Colour to Light Gray
	glFogf(GL_FOG_DENSITY, 0.4f);		//Set Fog Density
	glHint(GL_FOG_HINT, GL_NICEST);		//Set Fog Quality
	glFogf(GL_FOG_START, 1.0f);			//Set Fog "nearz" value
	glFogf(GL_FOG_END, 5.0f);			//Set Fog "farz" value
	glEnable(GL_FOG);					//Enable Fog Capability

	glEnable(GL_LIGHTING);				//Enable Lighting
	glEnable(GL_LIGHT0);				//Enable Light 0
	glEnable(GL_TEXTURE_2D);			//Enable Textures

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);

	glShadeModel(GL_SMOOTH);
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
	 1.0f, 0.0f,
	 1.0f, 1.0f,
	 0.0f, 0.0f,
	 0.0f, 1.0f,
	// RIGHT
	 1.0f, 0.0f,
	 1.0f, 1.0f,
	 0.0f, 0.0f,
	 0.0f, 1.0f,
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

	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);

	glVertexPointer(3, GL_FLOAT, 0, cube);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	// FRONT AND BACK
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);		 //Color: RED
    glNormal3f(0.0f, 0.0f, 1.0f);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glNormal3f(0.0f, 0.0f,-1.0f);
    glDrawArrays(GL_TRIANGLE_STRIP, 4, 4);

    // LEFT AND RIGHT
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);		//Color: GREEN
    glNormal3f(-1.0f, 0.0f, 0.0f);
	glDrawArrays(GL_TRIANGLE_STRIP, 8, 4);
    glNormal3f(1.0f, 0.0f, 1.0f);
    glDrawArrays(GL_TRIANGLE_STRIP, 12, 4);

    // TOP AND BOTTOM
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);		//Color: BLUE
	glNormal3f(0.0f, 1.0f, 0.0f);
	glDrawArrays(GL_TRIANGLE_STRIP, 16, 4);
	glNormal3f(0.0f,-1.0f, 1.0f);
    glDrawArrays(GL_TRIANGLE_STRIP, 20, 4);
}

//--------------------------------------------------------------------------------------------------------------------------------------

void Render()
{
	glClearColor(0.6f, 0.6f, 0.6f, 1.0f);	//Background: Light Gray
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
	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_FORWARD		 )) 
	{
		EnableLighting =! EnableLighting;
		(EnableLighting ? glEnable(GL_LIGHTING) : glDisable(GL_LIGHTING));
	}
	// If the Forward has been pressed: Toggle Lighting
	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_REWIND 		 )) 
	{
		ColourLight =! ColourLight;
		(ColourLight ? glFogfv(GL_FOG_COLOR, LightGray) : glFogfv(GL_FOG_COLOR, DarkGray));
	}
	// If the Rewind has been pressed: Toggle Colour
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
