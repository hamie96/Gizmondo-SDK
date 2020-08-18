#include "menu_amenu.h"

extern "C"
{
	#include "atari_gp32.h"
}

bool AMenu::shouldDraw(bool displayChanged)
{
	bool needToDraw = false;

	if (displayChanged)
	{
		d_doubleBufferA = 0;
		d_doubleBufferB = 0;
	}

	GPDRAWSURFACE * surface = Atari_DisplayActiveBuffer();
	while (true)
	{
		int surfaceI = (int) surface;
		if (surfaceI == d_doubleBufferA) // Already drawn
			break;

		if (surfaceI == d_doubleBufferB) // Already drawn
			break;

		// Not drawn -> mark as drawn
		needToDraw = true;
		if (d_doubleBufferA == 0)
			d_doubleBufferA = surfaceI;
		else
			d_doubleBufferB = surfaceI;
		
		break;	
	}

	return needToDraw;
}
