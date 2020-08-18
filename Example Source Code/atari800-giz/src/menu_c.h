//c interface to the menu
extern char currentMenu[];

void menuActivateUi();
void menuActivateMain();
int menuLoad(const char * filename);

void menuFrame(int x, int y, int keysPressed);
void menuClean();

int menuOper();
int menuKey();
int menuConsol();
int menuShift();
int menu5200Power();
void menuJoy(int joy[], int fire[]);
int menuAreKeysLocked();

void menuDump();
