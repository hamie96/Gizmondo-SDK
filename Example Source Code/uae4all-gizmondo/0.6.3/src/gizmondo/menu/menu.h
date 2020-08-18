#include<stdio.h>
#include<SDL.h>

extern SDL_Surface *prSDLScreen;

#define MENU_FILE_SPLASH "\\SD Card\\uae4all\\data\\gizmondosplash.bmp"
#define MENU_FILE_BACKGROUND "\\SD Card\\uae4all\\data\\background.bmp"
#define MENU_FILE_WINDOW "\\SD Card\\uae4all\\data\\window.bmp"
#define MENU_FILE_TEXT "\\SD Card\\uae4all\\data\\text.bmp"
#ifdef DREAMCAST
#define MENU_DIR_DEFAULT "/cd/"
#else
#define MENU_DIR_DEFAULT "\\SD Card\\uae4all\\"
#endif

void text_draw_background();
void init_text(int splash);
void quit_text(void);
void write_text(int x, int y, char * str);
void write_text_inv(int x, int y, char * str);
void write_centered_text(int y, char * str);
void write_num(int x, int y, int v);
void write_num_inv(int x, int y, int v);
void text_draw_window(int x, int y, int w, int h, char *title);
// void text_draw_menu_msg();
void text_flip(void);

void drawPleaseWait(void);
void menu_raise(void);
void menu_unraise(void);

int run_mainMenu();
int run_menuLoad();
int run_menuGame();
int run_menuOverclock();
int run_menuControl();

enum { MAIN_MENU_CASE_REBOOT, MAIN_MENU_CASE_LOAD, MAIN_MENU_CASE_RUN, MAIN_MENU_CASE_RESET, MAIN_MENU_CASE_CANCEL, MAIN_MENU_CASE_OVERCLOCK, MAIN_MENU_CASE_EJECT };

