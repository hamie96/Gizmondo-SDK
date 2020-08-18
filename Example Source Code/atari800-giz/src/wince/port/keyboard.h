#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

int prockb(void);
int initinput(void);
void uninitinput(void);

void hitbutton(short);
void releasebutton(short);

#endif /* _KEYBOARD_H_ */
