#include <windows.h>
#include <GLES\gl.h>
#include <GLES\egl.h>
#include <KGSDK\framework.h>
#include <KGSDK\frameworkGL.h>
#include <KGSDK\framework2D.h>	//Header file for 2D operations

#pragma comment(lib, "Framework.lib") 
#pragma comment(lib, "libGLES_CM.lib") 
#pragma comment(lib, "dxguid.lib")	//Library required to draw text
#pragma comment(lib, "ddraw.lib")	//Library required to draw text

static float rot[3];
static float loc[3];

//Blending Factor Source
GLenum blendSrc[] = 
{
	GL_ONE,
	GL_SRC_ALPHA
};

//Blending Factor Destination
GLenum blendDst[] = 
{
	GL_ZERO,
	GL_ONE,
	GL_DST_ALPHA,
	GL_ONE_MINUS_SRC_ALPHA
};

int BlendSrcNumber = 0;		//The Current Blending Factor Source
int BlendDstNumber = 0;		//The Current Blending Factor Destination
bool TextDisplayed = false;	//Is there text on the screen?

bool RButton = false;		//Is Right Shoulder Button being held down?
bool LButton = false;		//Is Left  Shoulder Button being held down?
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
	
	glEnable(GL_BLEND);	//Enable Blending
}

//--------------------------------------------------------------------------------------------------------------------------------------

void DrawStrips()
{
	GLfloat TemplateStrip[] = 
	{
	-0.1f, -0.3f, 0.0f,
	-0.1f,  0.3f, 0.0f,
	 0.1f, -0.3f, 0.0f,
	 0.1f,  0.3f, 0.0f
	};

	glVertexPointer(3, GL_FLOAT, 0, TemplateStrip);
	glEnableClientState(GL_VERTEX_ARRAY);
	
	glBlendFunc(blendSrc[BlendSrcNumber], blendDst[BlendDstNumber]);
	//Set Blending Factors (Properties)

	//Top Left Cross
	glPushMatrix();
		glTranslatef(-0.6f, 0.5f, 0.0f);
		glColor4f(1.0f, 0.0f, 0.0f, 0.25f);		//Red
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-0.6f, 0.5f, 0.0f);
		glRotatef(90, 0.0f, 0.0f, 1.0f);		
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);		//Green
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glPopMatrix();
	//Top Right Cross
	glPushMatrix();
		glTranslatef(0.6f, 0.5f, 0.0f);
		glColor4f(0.0f, 1.0f, 0.0f, 0.5f);		//Green
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.6f, 0.5f, 0.0f);
		glRotatef(90, 0.0f, 0.0f, 1.0f);		
		glColor4f(0.0f, 0.0f, 1.0f, 0.5f);		//Blue
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glPopMatrix();
	//Bottom Left Cross
	glPushMatrix();
		glTranslatef(-0.6f, -0.5f, 0.0f);
		glColor4f(0.0f, 0.0f, 1.0f, 0.5f);		//Blue
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-0.6f, -0.5f, 0.0f);
		glRotatef(90, 0.0f, 0.0f, 1.0f);
		glColor4f(1.0f, 1.0f, 0.0f, 0.5f);		//Yellow
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glPopMatrix();
	//Bottom Right Cross
	glPushMatrix();
		glTranslatef(0.6f, -0.5f, 0.0f);
		glColor4f(1.0f, 1.0f, 0.0f, 0.5f);		//Yellow
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.6f, -0.5f, 0.0f);
		glRotatef(90, 0.0f, 0.0f, 1.0f);		//Green
		glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glPopMatrix();
	//Center Cross
	glPushMatrix();
		glColor4f(1.0f, 0.0f, 0.0f, 0.25f);		//Red
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glPopMatrix();
	glPushMatrix();
		glRotatef(90, 0.0f, 0.0f, 1.0f);		//Blue
		glColor4f(0.0f, 0.0f, 1.0f, 0.75f);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glPopMatrix();
}

//--------------------------------------------------------------------------------------------------------------------------------------

void Render()  
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	DrawStrips();	//Draw Strips onto screen

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

	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_LEFT_SHOULDER ) && !LButton) 
	{
		Framework2D_Begin();	//Begin the 2D Framework
		BlendSrcNumber++;		//Increment the current Blending Source Factor
		
		if (BlendSrcNumber > 1)	//If Blending Source Factor is above 1, reset it
			BlendSrcNumber = 0;

		switch (BlendSrcNumber)	//Write Blend Source Factor to Screen
		{
			case 0:
			Framework2D_DrawText(L"Source: GL_ONE", 110, 115, (RGB(255, 255, 255)));
			break;
			case 1:
			Framework2D_DrawText(L"Source: GL_SRC_ALPHA", 100, 115, (RGB(255, 255, 255)));
			break;
		}
		Framework2D_End();		//End the 2D Framework
		LButton = true;			//LButton being held down
		TextDisplayed = true;	//There is text displayed on screen
	}
	// If the Left Shoulder Button has been pressed: Toggle the Blending Source Factor
	// And write it onto the screen

	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_RIGHT_SHOULDER ) && !RButton) 
	{
		Framework2D_Begin();	//Begin the 2D Framework
		BlendDstNumber++;		//Increment the current Blending Destination Factor
		
		if (BlendDstNumber > 3)	//If Blending Destination Factor is above 3, reset it
			BlendDstNumber = 0;

		switch (BlendDstNumber)	//Write Blend Destination Factor to Screen
		{
			case 0:
			Framework2D_DrawText(L"Destination: GL_ZERO", 108, 115, (RGB(255, 255, 255)));
			break;
			case 1:
			Framework2D_DrawText(L"Destination: GL_ONE", 110, 115, (RGB(255, 255, 255)));
			break;
			case 2:
			Framework2D_DrawText(L"Destination: GL_ONE_DST_ALPHA", 50, 115, (RGB(255, 255, 255)));
			break;
			case 3:
			Framework2D_DrawText(L"Destination: GL_ONE_MINUS_SRC_ALPHA", 50, 115, (RGB(255, 255, 255)));
			break;
		}
		Framework2D_End();		//End the 2D Framework
		RButton = true;			//LButton being held down
		TextDisplayed = true;	//There is text displayed on screen
	}
	// If the Right Shoulder Button has been pressed: Toggle the Blending Destination Factor
	// And write it onto the screen


	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_FORWARD			)) 
		TextDisplayed = false;
	// If the Forward Button has been pressed: Clear the text off the screen
	// And return to strips

	if (!Framework_IsButtonPressed(FRAMEWORK_BUTTON_RIGHT_SHOULDER	)) 
		RButton = false;
	// If the Right Shoulder Button is NOT being pressed, reset RButton

	if (!Framework_IsButtonPressed(FRAMEWORK_BUTTON_LEFT_SHOULDER	)) 
		LButton = false;
	// If the Left Shoulder Button is NOT being pressed, reset LButton
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
	
	//Initialise the 2D Framework.
	if (!Framework2D_Init())
	{
		Framework_Close();
		return 0;
	}

	Init();

	do
	{
		//If text is displayed on the screen, dont draw the strips
		if (!TextDisplayed)	
		{
		Render();
		} 

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

	//Clean Up
	FrameworkGL_Close();
	Framework2D_Close();
	Framework_Close();

	return 0;
}
