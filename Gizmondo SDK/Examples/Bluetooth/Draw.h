
#ifndef _DRAW_H
#define _DRAW_H

//-------------------------------------------------------------------------------------------------

#define SETRGB(r,g,b) (((r)<<11) | ((g)<<5) | (b))

void Draw_Text(unsigned short *pString, int iXPos, int iYPos);
void Draw_Fill(int iOffset, unsigned short iCol, int iCount);
void Draw_Ball(int iXPos, int iYPos);

//-------------------------------------------------------------------------------------------------

#endif
