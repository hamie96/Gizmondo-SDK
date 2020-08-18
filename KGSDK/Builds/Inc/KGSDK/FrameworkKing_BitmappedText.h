/*

File:			FrameworkKing.h
Description:	FrameworkKing header file.

Copyright (c) GizzedINC Europe Ltd. All rights reserved.

*/

#ifndef _FRAMEWORKKING_BITMAPPEDTEXT_H
#define _FRAMEWORKKING_BITMAPPEDTEXT_H

#include <windows.h>
#include <GLES\GL.h>
#include <GLES\EGL.h>
//----------------------------------------------------------------------------------------------------------------------------
//BitmappedText Related:
//----------------------
#define NUMBER_OF_COLUMNS 16.0f;		//Number of columns in the Font Blue print
#define NUMBER_OF_ROWS 8.0f;			//Number of rows in the Font Blue print

const int NumberOfFonts = 2;
GLuint Font_Texture[NumberOfFonts];		//Storage for two textures (two fonts)

enum {Tahoma, TCP1} AvailableFonts;						//Enumeration of the Fonts we have loaded
enum {Use_GL_NEAREST, Use_GL_LINEAR} Texture_Filters;	//Enumeration of the Texture Filters
char *FontFiles[] =						//Filename of Fonts
{
	"KGSDK_Tahoma_Font.tga",
	"KGSDK_Twentieth_Century_Poster_1_Font.tga"
};
//----------------------------------------------------------------------------------------------------------------------------
//BitmappedText Class:
//----------------------

class FrameworkKing_BitmappedText		//The Bitmapped Font Text Class Implementation..
{
	public:
		FrameworkKing_BitmappedText(char String[]);	//Constructor
		DrawBText();					//Function to draw character to screen
		int FontName;					//What Font to use ?
		float LocX;						//X Location of character in 3D Space
		float LocY;						//Y Location of character in 3D Space
		float LocZ;						//Z Location of character in 3D Space
		float SizX;						//Scale Factor on X-axis
		float SizY;						//Scale Factor on Y-axis
		float SizZ;						//Scale Factor on Z-axis
		float RValue;					//Red Value of the Colour of the Font
		float GValue;					//Green Value of the Colour of the Font
		float BValue;					//Blue Value of the Colour of the Font
		float AValue;					//Alpha Value of the Colour of the Font
		int TextureFilter;				//What texture filter to use to render the font ?
		char Text[512];					//Text to draw to screen
	private:
		int NumberOfCharacters;			//The Width of one character
		float OneCWUnit;				//The Width of one character
		float OneCHUnit;				//The Height of one character
		float XOffsetOfC;				//Which column to select our character from
		float YOffsetOfC;				//Which row to select our character from
};

//----------------------------------------------------------------------------------------------------------------------------
FrameworkKing_BitmappedText::FrameworkKing_BitmappedText(char String[])
{	
	//Store Text in member variable..
	memcpy (Text,String,strlen(String)+1);

	//Set NumberOfCharacters to Number Of Characters in Text..
	NumberOfCharacters = strlen(Text);

	OneCWUnit = 1.0f/NUMBER_OF_COLUMNS;	//Set One Character Width Unit
	OneCHUnit = 1.0f/NUMBER_OF_ROWS;	//Set One Character Height Unit
}

FrameworkKing_BitmappedText::DrawBText()
{
	glPushMatrix();
	glTranslatef(LocX, LocY, LocZ);		//Move to specified area..
	glScalef(SizX, SizY, SizZ);			//Scale font to desired size..

	int i;
	for (i = 0; i < NumberOfCharacters; i ++)	//Loop through each character of the text..
	{

		switch (Text[i])
		{
			case	32	:
					
				XOffsetOfC = 1.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	33	:
					
				XOffsetOfC = 2.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	34	:
					
				XOffsetOfC = 3.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	35	:
					
				XOffsetOfC = 4.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	36	:
					
				XOffsetOfC = 5.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	37	:
					
				XOffsetOfC = 6.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	38	:
					
				XOffsetOfC = 7.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	39	:
					
				XOffsetOfC = 8.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	40	:
					
				XOffsetOfC = 9.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	41	:
					
				XOffsetOfC = 10.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	42	:
					
				XOffsetOfC = 11.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	43	:
					
				XOffsetOfC = 12.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	44	:
					
				XOffsetOfC = 13.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	45	:
					
				XOffsetOfC = 14.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	46	:
					
				XOffsetOfC = 15.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	47	:
					
				XOffsetOfC = 16.0f;	
				YOffsetOfC = 8.0f;	
				break;	
					
			case	48	:
					
				XOffsetOfC = 1.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	49	:
					
				XOffsetOfC = 2.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	50	:
					
				XOffsetOfC = 3.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	51	:
					
				XOffsetOfC = 4.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	52	:
					
				XOffsetOfC = 5.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	53	:
					
				XOffsetOfC = 6.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	54	:
					
				XOffsetOfC = 7.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	55	:
					
				XOffsetOfC = 8.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	56	:
					
				XOffsetOfC = 9.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	57	:
					
				XOffsetOfC = 10.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	58	:
					
				XOffsetOfC = 11.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	59	:
					
				XOffsetOfC = 12.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	60	:
					
				XOffsetOfC = 13.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	61	:
					
				XOffsetOfC = 14.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	62	:
					
				XOffsetOfC = 15.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	63	:
					
				XOffsetOfC = 16.0f;	
				YOffsetOfC = 7.0f;	
				break;	
					
			case	64	:
					
				XOffsetOfC = 1.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case	65	:
					
				XOffsetOfC = 2.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case	66	:
					
				XOffsetOfC = 3.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case	67	:
					
				XOffsetOfC = 4.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case 68:
					
				XOffsetOfC = 5.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case	69	:
					
				XOffsetOfC = 6.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case	70	:
					
				XOffsetOfC = 7.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case	71	:
					
				XOffsetOfC = 8.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case	72	:
					
				XOffsetOfC = 9.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case	73	:
					
				XOffsetOfC = 10.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case	74	:
					
				XOffsetOfC = 11.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case	75	:
					
				XOffsetOfC = 12.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case	76	:
					
				XOffsetOfC = 13.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case	77	:
					
				XOffsetOfC = 14.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case	78	:
					
				XOffsetOfC = 15.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case	79	:
					
				XOffsetOfC = 16.0f;	
				YOffsetOfC = 6.0f;	
				break;	
					
			case	80	:
					
				XOffsetOfC = 1.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	81	:
					
				XOffsetOfC = 2.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	82	:
					
				XOffsetOfC = 3.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	83	:
					
				XOffsetOfC = 4.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	84	:
					
				XOffsetOfC = 5.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	85	:
					
				XOffsetOfC = 6.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	86	:
					
				XOffsetOfC = 7.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	87	:
					
				XOffsetOfC = 8.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	88	:
					
				XOffsetOfC = 9.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	89	:
					
				XOffsetOfC = 10.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	90	:
					
				XOffsetOfC = 11.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	91	:
					
				XOffsetOfC = 12.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	92	:
					
				XOffsetOfC = 13.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	93	:
					
				XOffsetOfC = 14.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	94	:
					
				XOffsetOfC = 15.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	95	:
					
				XOffsetOfC = 16.0f;	
				YOffsetOfC = 5.0f;	
				break;	
					
			case	96	:
					
				XOffsetOfC = 1.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	97	:
					
				XOffsetOfC = 2.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	98	:
					
				XOffsetOfC = 3.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	99	:
					
				XOffsetOfC = 4.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	100	:
					
				XOffsetOfC = 5.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	101	:
					
				XOffsetOfC = 6.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	102	:
					
				XOffsetOfC = 7.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	103	:
					
				XOffsetOfC = 8.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	104	:
					
				XOffsetOfC = 9.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	105	:
					
				XOffsetOfC = 10.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	106	:
					
				XOffsetOfC = 11.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	107	:
					
				XOffsetOfC = 12.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	108	:
					
				XOffsetOfC = 13.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	109	:
					
				XOffsetOfC = 14.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	110	:
					
				XOffsetOfC = 15.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	111	:
					
				XOffsetOfC = 16.0f;	
				YOffsetOfC = 4.0f;	
				break;	
					
			case	112	:
					
				XOffsetOfC = 1.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	113	:
					
				XOffsetOfC = 2.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	114	:
					
				XOffsetOfC = 3.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	115	:
					
				XOffsetOfC = 4.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	116	:
					
				XOffsetOfC = 5.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	117	:
					
				XOffsetOfC = 6.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	118	:
					
				XOffsetOfC = 7.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	119	:
					
				XOffsetOfC = 8.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	120	:
					
				XOffsetOfC = 9.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	121	:
					
				XOffsetOfC = 10.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	122	:
					
				XOffsetOfC = 11.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	123	:
					
				XOffsetOfC = 12.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	124	:
					
				XOffsetOfC = 13.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	125	:
					
				XOffsetOfC = 14.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	126	:
					
				XOffsetOfC = 15.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	127	:
					
				XOffsetOfC = 16.0f;	
				YOffsetOfC = 3.0f;	
				break;	
					
			case	128	:
					
				XOffsetOfC = 1.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	129	:
					
				XOffsetOfC = 2.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	130	:
					
				XOffsetOfC = 3.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	131	:
					
				XOffsetOfC = 4.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	132	:
					
				XOffsetOfC = 5.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	133	:
					
				XOffsetOfC = 6.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	134	:
					
				XOffsetOfC = 7.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	135	:
					
				XOffsetOfC = 8.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	136	:
					
				XOffsetOfC = 9.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	137	:
					
				XOffsetOfC = 10.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	138	:
					
				XOffsetOfC = 11.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	139	:
					
				XOffsetOfC = 12.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	140	:
					
				XOffsetOfC = 13.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	141	:
					
				XOffsetOfC = 14.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	142	:
					
				XOffsetOfC = 15.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	143	:
					
				XOffsetOfC = 16.0f;	
				YOffsetOfC = 2.0f;	
				break;	
					
			case	144	:
					
				XOffsetOfC = 1.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			case	145	:
					
				XOffsetOfC = 2.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			case	146	:
					
				XOffsetOfC = 3.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			case	147	:
					
				XOffsetOfC = 4.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			case	148	:
					
				XOffsetOfC = 5.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			case	149	:
					
				XOffsetOfC = 6.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			case	150	:
					
				XOffsetOfC = 7.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			case	151	:
					
				XOffsetOfC = 8.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			case	152	:
					
				XOffsetOfC = 9.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			case	153	:
					
				XOffsetOfC = 10.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			case	154	:
					
				XOffsetOfC = 11.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			case	155	:
					
				XOffsetOfC = 12.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			case	156	:
					
				XOffsetOfC = 13.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			case	157	:
					
				XOffsetOfC = 14.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			case	158	:
					
				XOffsetOfC = 15.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			case	159	:
					
				XOffsetOfC = 16.0f;	
				YOffsetOfC = 1.0f;	
				break;	
					
			default:
				XOffsetOfC = 0.0f;	
				YOffsetOfC = 0.0f;	
				break;	
		}
	
		GLfloat TexCoords[]=											//Array which determines which character to load
		{
			OneCWUnit * (XOffsetOfC - 1), OneCHUnit * (YOffsetOfC - 1),	//Bottom-Left of Character 
			OneCWUnit *  XOffsetOfC		, OneCHUnit * (YOffsetOfC - 1),	//Bottom-Right of Character
			OneCWUnit * (XOffsetOfC - 1), OneCHUnit *  YOffsetOfC,		//Top-Left of Character
			OneCWUnit *  XOffsetOfC		, OneCHUnit *  YOffsetOfC		//Top-Right of Character
		};	
		
		GLfloat Plane[] =									//A simple rectangle. Moves one unit (0.5) to the right for each character
		{
			-0.5f + (0.5 * i), -1.0f,  0.0f,				//Bottom-Left
			 0.5f + (0.5 * i), -1.0f,  0.0f,				//Bottom-Right
			-0.5f + (0.5 * i),  1.0f,  0.0f,				//Top-Left
			 0.5f + (0.5 * i),  1.0f,  0.0f					//Top-Right
		};

		glEnableClientState(GL_VERTEX_ARRAY);				
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		
		glTexCoordPointer(2, GL_FLOAT, 0, TexCoords);		//Point Texture Pointer to Tex Coords..
		glVertexPointer(3, GL_FLOAT, 0, Plane);				//Point Vertex Pointer to the plane..

		glBindTexture(GL_TEXTURE_2D, Font_Texture[FontName]);	//Select Font..
		
		glTexParameterf(GL_TEXTURE_2D, 
			GL_TEXTURE_MIN_FILTER, ((TextureFilter == Use_GL_NEAREST) ? GL_NEAREST : GL_LINEAR));
		glTexParameterf(GL_TEXTURE_2D,
			GL_TEXTURE_MAG_FILTER, ((TextureFilter == Use_GL_NEAREST) ? GL_NEAREST : GL_LINEAR));
		
		glColor4f(RValue, GValue, BValue, AValue);			//Set Colour from Colour Member Variables ..

		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);				//Draw it!
	}

	glPopMatrix();
}
//----------------------------------------------------------------------------------------------------------------------------

#endif // _FRAMEWORKKING_BITMAPPEDTEXT_H