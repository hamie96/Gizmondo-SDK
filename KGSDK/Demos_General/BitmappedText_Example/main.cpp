#include <windows.h>
#include <GLES\gl.h>
#include <GLES\egl.h>
#include "KGSDK\framework.h"
#include "KGSDK\frameworkGL.h"
#include "KGSDK\FrameworkKing.h"	
#include "KGSDK\FrameworkKing_BitmappedText.h"	

#pragma comment(lib, "Framework.lib") 
#pragma comment(lib, "libGLES_CM.lib") 

static float rot[3];
static float loc[3];

float xrot = 0.0f;	
float yrot = 0.0f;	

//--------------------------------------------------------------------------------------------------------------------------------------
void Init()
{
	glEnable(GL_LIGHTING);		//Enable Lighting
	glEnable(GL_LIGHT0);		//Enable GL_LIGHT0
	glEnable(GL_COLOR_MATERIAL);//Enable Colour Material
	glEnable(GL_BLEND);			//Enable Blending
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_CULL_FACE);	//Disable Back face culling

	if (!LoadTexturesTGA(2, Font_Texture, FontFiles))	
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

void DrawMyText()
{
	glRotatef(xrot,1.0f,0.0f,0.0f);		//Rotate axis based on value of xrot
	glRotatef(yrot,0.0f,1.0f,0.0f);		//Rotate axis based on value of yrot

	FrameworkKing_BitmappedText Q("King Rules!!");	//Create a text object

	Q.RValue= 1.0f;						//Red value of colour
	Q.GValue= 1.0f;						//Green value of colour
	Q.BValue= 1.0f;						//Blue value of colour
	Q.AValue= 1.0f;						//Alpha value of colour
	Q.FontName = TCP1;					//Font to use: Tahoma
	Q.LocX = 0.0f;						//Don't Move on X-Axis	
	Q.LocY = 0.0f;						//Don't Move on Y-Axis	
	Q.LocZ = 0.0f;						//Don't Move on Z-Axis						
	Q.SizX = 0.35f;						//Don't Scale on X-Axis
	Q.SizY = 0.35f;						//Don't Scale on Y-Axis
	Q.SizZ = 0.35f;						//Don't Scale on Z-Axis
	Q.TextureFilter = Use_GL_NEAREST;	//Apply GL_NEAREST Texture filter to font

	Q.DrawBText();	//Draw it !/**/
}
//--------------------------------------------------------------------------------------------------------------------------------------

void Render()
{
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	DrawMyText();	//Draw Text to screen
	
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
	// If the Down button (DPAD) has been pressed: Rotate the Plane downards
	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_DPAD_UP	     )) 
		xrot += 1.0f;
	// If the Up button (DPAD) has been pressed: Rotate the Plane upwards
	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_DPAD_LEFT     )) 
		yrot -= 1.0f;
	// If the Left button (DPAD) has been pressed: Rotate the Plane towards the left
	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_DPAD_RIGHT	 )) 
		yrot += 1.0f;
	// If the Right button (DPAD) has been pressed: Rotate the Plane towards the Right
}

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