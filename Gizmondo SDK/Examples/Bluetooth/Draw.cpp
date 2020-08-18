//-------------------------------------------------------------------------------------------------

#include "Device.h"
#include "Draw.h"

//-------------------------------------------------------------------------------------------------

void Draw_Text(unsigned short *pString, int iXPos, int iYPos)
{
	Device_DrawText(pString, iXPos, iYPos);
}

//-------------------------------------------------------------------------------------------------

void Draw_Fill(int iOffset, unsigned short iCol, int iCount)
{
	unsigned short *pAddr = (unsigned short *)Device_BackBufferLock();
	pAddr += iOffset;

	while (iCount-- > 0)
	{
		*pAddr++ = iCol;
	}

	Device_BackBufferUnlock();
}

//-------------------------------------------------------------------------------------------------

void Draw_Ball(int iXPos, int iYPos)
{
	static unsigned short pBlob[8*8]=
	{
		0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000,
		0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000,
		0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000,
		0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
		0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
		0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000,
		0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000,
		0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000,
	};

	iXPos -= 4;
	iYPos -= 4;

	unsigned short *pAddr = (unsigned short *)Device_BackBufferLock();

	unsigned short *bBlobAddr = pBlob;
	unsigned short *pScreenAddr = pAddr + (iYPos*320) + iXPos;

	for (int y=0; y<8; y++)
	{
		for (int x=0; x<8; x++)
		{
			if (*bBlobAddr++ != 0)
			{
				*pScreenAddr = 0xffff;
			}
			pScreenAddr++;
		}

		pScreenAddr += 320-8;
	}

	Device_BackBufferUnlock();
}


//-------------------------------------------------------------------------------------------------
