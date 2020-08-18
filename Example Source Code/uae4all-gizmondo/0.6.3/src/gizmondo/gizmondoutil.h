#ifndef _GP2X_UTIL_H
#define _GP2X_UTIL_H

void gp2x_init(void);
void gp2x_set_volume(int);
void inputmode_init();
void volumecontrol_init();
void setBatteryLED(int);
int is_overridden_button(int button);
void handle_remapped_button_down(int button);
void handle_remapped_button_up(int button);
int mmuhack(void);
#endif
