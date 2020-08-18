#include "stdafx.h"
#include "windows.h"
#include <exception>

#define MAX_SIZE 32768						//Maximum Size of any line
#define INPUT_FILE argv[1]					//Path of Input File
#define OUTPUT_FILE	argv[2]					//Path of Output File

//Expressions depending on what Information we're loading..

//Vertex Info:
//If First Character is a "v", and second is a space..
#define VERTICES_EXP string[0] == 118 && string[1] == 32
//Normal Info:
//If First Character is a "v", second is a "n", and third is a space..
#define NORMALS_EXP string[0] == 118 && string[1] == 110 && string[2] == 32
//TexCoord Info:
//If First Character is a "v", second is a "t", and third is a space..
#define TEX_COORDS_EXP string[0] == 118 && string[1] == 116 && string[2] == 32

enum InfoToLoad {Vertices, Normals, TexCoords};		//Enumeration of available info to load
FILE *OutputFile;									//Output File
FILE *InputFile;									//Input File
long SizeOfInputFile;								//Size Of Input File

//-------------------------------------------------------------
//Function: LoadObjInfo
//-------------------------------------------------------------
//Description:	This is our main function. It reads each line of the OBJ File,
//				and Identifies it accordingly to which type of info we're loading.
//
//Parameters:	ArrayHeader		: The Header that will be used in the Output File
//				WhatInfoToLoad	: What Info to Load ? Self-Explanatory ...

void LoadObjInfo(char * ArrayHeader, InfoToLoad WhatInfoToLoad)
{
	char string [MAX_SIZE];				//Temp storage for line

	//Write beginning of vertex array (header)..
	fputs(ArrayHeader, OutputFile);

	do	// Read Each line until end of file..
	{
		fgets (string , MAX_SIZE , InputFile);	//Read Line into "string"

		//If first character of line is "v", second is "t", and third is a space..
		if((WhatInfoToLoad < 1 ? VERTICES_EXP  : (WhatInfoToLoad < 2 ? NORMALS_EXP : TEX_COORDS_EXP ) )) 
		{								//Then this line contains Vertex pos info..
			fputc (9, OutputFile);		//Add a tab before eachline

			int i;						//Where to start reading from..
			switch (WhatInfoToLoad)
			{
				case Vertices:			//Loading Vertex Info
					i = 2;				//Start reading from the second character of the line..
					break;
				default:				//Loading TexCoord/Normal Info
					i = 3;				//Start reading from the third character of the line..
					break;
			}

			//For each character in the line..
			for (i; i < strlen(string); i++)
			{	
				//If it is a space, replace with a comma..
				switch (string[i])
				{
					case 32:	//If character is a space ..
						fputs(", ", OutputFile);		//Replace with a comma, and a space
						break;
					case 10:	//If character is a newline (Reached end of line) ..
						fputs(",\n", OutputFile);		//Replace with a comma, and a newline
						break;
					default:	//If character is anything else ..
						fputc(string[i], OutputFile);	//Print it out as normal
						break;
				}					//End Checking through each character of the line..
			}						//End Looping through each character of the line..
		}							//End Check for line containing vertex info..
	} while (feof(InputFile) == 0);	//If EOF has occured, stop reading lines..
	
	//Write end of vertex array ..
	fputs("}\n\n", OutputFile);
}


int main(int argc, char* argv[])
{
	//If there are the right number of params..
	if (argc == 3)
	{
		//-----------------------------------------------------------
		InputFile = fopen (INPUT_FILE , "r");	//Open Input File
		if (!InputFile)							//Check validity of file
		{
			MessageBox(NULL, L"Can't Open Input File", L"Error", MB_OK);
			return NULL;
		}
		//-----------------------------------------------------------
		OutputFile = fopen (OUTPUT_FILE , "w");	//Open Output File
		if (!OutputFile)						//Check validity of file
		{
			MessageBox(NULL, L"Can't Create Output File", L"Error", MB_OK);
			return NULL;
		}
		//-----------------------------------------------------------
		//Tag Output File..
		fputs("//This file was exported by the KingWFOL Tool, as part of the KGSDK.\n", OutputFile);
		fputs("//KGSDK can be found from the GizzedINC Website: http://www.gizzedinc.com\n\n", OutputFile);
		//-----------------------------------------------------------
		
		//-----------------------------------------------------------
		freopen(INPUT_FILE, "r", InputFile);
		LoadObjInfo("GLfloat OBJ1_VerticesInfo[] = \n{\n"  , Vertices);	//Load Vertices from Wavefront OBJ File
		//-----------------------------------------------------------
		freopen(INPUT_FILE, "r", InputFile);
		LoadObjInfo("GLfloat OBJ1_NormalsInfo[] = \n{\n"   , Normals);	//Load Normals from Wavefront OBJ File
		//-----------------------------------------------------------
		freopen(INPUT_FILE, "r", InputFile);
		LoadObjInfo("GLfloat OBJ1_TexCoordsInfo[] = \n{\n" , TexCoords);//Load Tex-Coords from Wavefront OBJ File		
		//-----------------------------------------------------------

		fclose (OutputFile);						//Close Output File
		fclose (InputFile);							//Close Input File
		
		fprintf(stdout,"Completed Succesfully");	//Notify user Operation completed successfully
		return 0;									//End
	}
	else	//If wrong number of params..
	{
		//Print out Program Info..
		fprintf(stdout,"------------------------------------\n");
		fprintf(stdout,"KingWFOBL: King WaveFront Object Loader\n");
		fprintf(stdout,"------------------------------------\n");
		fprintf(stdout,"Description: Convert Wavefront OBJ Files (.obj) \n");
		fprintf(stdout,"             into usuable C++ Header Files (.h)\n");
		fprintf(stdout,"Usage: - KingWFOBL <input> <output> \n");
		fprintf(stdout,"       - Both Parameters are required.. \n");
		fprintf(stdout," \n");
		fprintf(stdout,"Author: King \n");
		fprintf(stdout,"GizzedINC: http://www.gizzedinc.com\n");

	}
}

