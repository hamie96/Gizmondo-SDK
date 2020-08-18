//-------------------------------------------------------------------------------------------------

#include "Util.h"

//-------------------------------------------------------------------------------------------------

void Util_CopyUnicodeToAscii(char *pAscii, const unsigned short *pUnicode)
{
	do
	{
		*pAscii = (char)(*pUnicode++);
	}
	while (*pAscii++ != 0);
}

//-------------------------------------------------------------------------------------------------

void Util_CopyAsciiToUnicode(unsigned short *pUnicode, const char *pAscii)
{
	do
	{
		*pUnicode = (short)(*pAscii++);
	}
	while (*pUnicode++ != 0);
}

//-------------------------------------------------------------------------------------------------
