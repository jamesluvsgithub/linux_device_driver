#include "mouse.h"
#include "mouse_lib.h"


bool mouse_reset(void)
{
    int mouse_present;

    _asm
    {
        mov ax, MOUSE_CHECK
        int MOUSE_HANDLER
        mov [mouse_present], ax
    }

    if (mouse_present != MOUSE_PRESENT)
    {
        return false;
    }

    // TODO: finish initializing mouse
    return true;
}

int mouse_get_button_presses(int16_t button)
{
    if (button > 2)
    {
        return -1;
    }

    int count;

    _asm
    {
        mov ax, GET_BUTTON_PRESSES
        mov bx, button
        int MOUSE_HANDLER
        mov [count], bx
    }

    return count;
}

int mouse_get_button_releases(int16_t button)
{
    if (button > 2)
    {
        return -1;
    }

    int count;

    _asm
    {
        mov ax, GET_BUTTON_RELEASES
        mov bx, button
        int MOUSE_HANDLER
        mov [count], bx
    }

    return count;
}

void mouse_get_mickeys(int16_t* mickeys_x, int16_t* mickeys_y)
{
    int16_t x;
    int16_t y;

    _asm
    {   
        mov ax, GET_MOVEMENT_CHANGES
        int MOUSE_HANDLER
        mov [x], cx
        mov [y], dx
    }

    *mickeys_x += x;
    *mickeys_y += y;
}

void mouse_calculate_pos(int16_t* value, int16_t* mickeys, int16_t rate)
{
    if (rate <= 0)
    {
        return;
    }

    *value += *mickeys / rate;
    *mickeys = *mickeys % rate;
}




//  BIOS STATE

void mouse_show_cursor(void)
{
    _asm
    {
        mov ax, SHOW_CURSOR
        int MOUSE_HANDLER
    }
}

void mouse_hide_cursor(void)
{
    _asm
    {
        mov ax, HIDE_CURSOR
        int MOUSE_HANDLER
    }
}

void mouse_set_limits_x(int16_t minimum, int16_t maximum)
{
    _asm
    {
        mov ax, SET_HORIZ_LIMIT
        mov cx, minimum
        mov dx, maximum
        int MOUSE_HANDLER
    }
}

void mouse_set_limits_y(int16_t minimum, int16_t maximum)
{
    _asm 
    {
        mov ax, SET_VERT_LIMIT
        mov cx, minimum
        mov dx, maximum
        int MOUSE_HANDLER
    }
}

void mouse_set_position(int16_t x, int16_t y)
{
    _asm 
    {
        mov ax, SET_CURSOR_POS
        mov cx, x
        mov dx, y
        int MOUSE_HANDLER
    }
}

void mouse_get_state(struct mouse_state* state)
{
    int16_t buttons;
    int16_t x, y;

    _asm 
    {
        mov ax, GET_CURSOR_STATE
        int MOUSE_HANDLER
        mov [buttons], bx
        mov [x], cx
        mov [y], dx
    }
    
    state->x = x;
    state->y = y;

    state->left   = (buttons & 0x01) != 0;
    state->right  = (buttons & 0x02) != 0;
    state->middle = (buttons & 0x04) != 0;
}

void mouse_set_movement_rate(int16_t rate_x, int16_t rate_y)
{

    _asm 
    {
        mov ax, SET_MICKEY_RATE
        mov cx, rate_x
        mov dx, rate_y
        int MOUSE_HANDLER
    }
}

void mouse_set_sensitivity(int16_t level_x, int16_t level_y)
{
    if (level_x > 100 || level_y > 100)
    {
        return;
    }

    _asm 
    {
        mov ax, SET_CURSOR_SENS
        mov bx, level_x
        mov cx, level_y
        mov dx, 100
        int MOUSE_HANDLER
    }
}

void mouse_get_sensitivity(int16_t *level_x, int16_t *level_y)
{
    int16_t x, y;

    _asm 
    {
        mov ax, GET_CURSOR_SENS
        int MOUSE_HANDLER
        mov [x], bx 
        mov [y], cx
    }

    *level_x = x;
    *level_y = y;
}