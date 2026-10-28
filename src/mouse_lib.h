#ifndef MOUSE_LIB_H
#define MOUSE_LIB_H

#define MOUSE_HANDLER   0x33
#define MOUSE_CHECK     0x00
#define SHOW_CURSOR     0x01
#define HIDE_CURSOR     0x02
#define GET_CURSOR_STATE     0x03
#define SET_CURSOR_POS       0x04
#define GET_BUTTON_PRESSES   0x05
#define GET_BUTTON_RELEASES  0x06
#define SET_HORIZ_LIMIT      0x07
#define SET_VERT_LIMIT       0x08
#define GET_MOVEMENT_CHANGES 0x0B
#define SET_MICKEY_RATE      0x0F
#define SET_CURSOR_SENS      0x1A
#define GET_SURSOR_SENS      0x1B

#define MOUSE_LEFT   0
#define MOUSE_RIGHT  1
#define MOUSE_MIDDLE 2

#define MOUSE_NOT_PRESENT 0x0000
#define MOUSE_PRESENT     0xFFFF


#endif