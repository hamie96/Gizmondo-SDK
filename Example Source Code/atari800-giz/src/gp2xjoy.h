#define GP2X_ST 1;
#define GP2X_SE 2;
#define GP2X_L 4;
#define GP2X_R 8;
#define GP2X_A 16;
#define GP2X_B 32;
#define GP2X_X 64;
#define GP2X_Y 128;

void readJoy(int * x, int * y);
void readAllJoy(int * switches, int * x, int * y, int * buttons); // x and y are translated using DaveC number 2, switches are one bit per swich with LMB being 12.00 going anticlockwise

int getButtons();
int getX();
int getY();
int joyPressed();

