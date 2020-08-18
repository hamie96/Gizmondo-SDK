//=======================================================================
//Tutorial 2: Primitives & OpenGL Fundamentals
//--------------------------------------------
//File:			main.cpp
//Description:	Basic application which demonstartes what a primitive is
//				Also shows key points of OpenGL|ES Programming
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
}

//--------------------------------------------------------------------------------------------------------------------------------------
void DrawTriangle()				
{				
	GLfloat tri[] = 			
	{				
	-0.5f, -0.5f, -0.5f,			
	-0.5f,  0.5f, -0.5f,			
	 0.5f, -0.5f, -0.5f			
	};				
						
	GLfloat triColours[] = 		
	{				
	1.0f, 0.0f, 0.0f, 1.0f,	//Red		
	0.0f, 1.0f, 0.0f, 1.0f,	//Green		
	0.0f, 0.0f, 1.0f, 1.0f,	//Blue		
	};				
					
	glVertexPointer(3, GL_FLOAT, 0, tri);	
	glColorPointer(4, GL_FLOAT, 0, triColours);	
						
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);	
						
	glDrawArrays(GL_TRIANGLES, 0, 3);	
						
	glShadeModel(GL_SMOOTH);		
}					

//--------------------------------------------------------------------------------------------------------------------------------------

void Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	DrawTriangle();
	
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
