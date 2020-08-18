//#include <SDL/SDL.h>

#define GPC_VK_HOME 1
#define GPC_VK_VOLUME 2
#define GPC_VK_FL 4
#define GPC_VK_FR 8
#define GPC_VK_FA 16
#define GPC_VK_FB 32
#define GPC_VK_FX 64
#define GPC_VK_FY 128
#define GPC_VK_UP 0x100
#define GPC_VK_DOWN 0x200
#define GPC_VK_LEFT 0x400
#define GPC_VK_RIGHT 0x800
#define GPC_VK_ASTERISK 0x1000
#define GPC_VK_TRIANGLE 0x2000
#define GPC_VK_POWER 0x4000

//#define GPDRAWSURFACE SDL_Surface 
#define GPDRAWSURFACE void

void GpTextOut(int* bad,GPDRAWSURFACE * surface, int x, int y, const char * text, int col);
void GpRectFill(int* bad, GPDRAWSURFACE * surface, int x,int y,int w,int h, int col);
int GpTickCountGet();

