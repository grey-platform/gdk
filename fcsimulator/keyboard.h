#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#define KEY_A 0
#define KEY_B 1
#define KEY_SELECT 2
#define KEY_START 3
#define KEY_UP 4
#define KEY_DOWN 5
#define KEY_LEFT 6
#define KEY_RIGHT 7


void Keyboard_Keyboard();
int  Keyboard_setKey(int key, int value);
void Keyboard_keyDown(int evt);
void Keyboard_keyUp(int evt);
void Keyboard_keyPress(int evt);
    
extern int Keyboard_state1[8];
extern int Keyboard_state2[8];



#endif

