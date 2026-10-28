#include "vga.h"
#include "vga_lib.h"

#include <conio.h> // For I/O port stuff
#include <i86.h>



void vga_set_mode(uint8_t mode)
{
    _asm
    {
        mov ah, SET_MODE
        mov al, mode
        int SET_VIDEO_MODE_HANDLER
    }
}

void vga_vertical_sync()
{
    // Block until next vertical retrace begins.

    while (inp(INPUT_STATUS_REG1) & VERT_RETRACE_ACTIVE_BITMASK);
    while (!(inp(INPUT_STATUS_REG1) & VERT_RETRACE_ACTIVE_BITMASK));
}

void vga_set_palette_mask(uint8_t mask)
{
    _asm 
    {
        mov dx, PALETTE_MASK
        mov al, mask
        out dx, al
    }
}

void vga_set_color(uint8_t index, uint8_t r, uint8_t g, uint8_t b)
{
    _asm 
    {
        mov dx, WRITE_COLOR_INDEX
        mov al, index
        out dx, al


        mov dx, RGB_DATA

        mov al, r
        out dx, al

        mov al, g
        out dx, al

        mov al, b
        out dx, al
    }
}




//  ADAPTER QUERY

void vga_get_color(uint8_t index, uint8_t *r, uint8_t *g, uint8_t *b)
{
    uint8_t red, green, blue;

    _asm 
    {
        mov dx, READ_COLOR_INDEX
        mov al, index
        out dx, al

        mov dx, RGB_DATA

        in  al, dx
        mov [red], al

        in  al, dx
        mov [green], al

        in  al, dx
        mov [blue], al
    }

    *r = red;
    *g = green;
    *b = blue;
}

uint8_t *vga_get_address()
{
    return (char *) 0xA0000000
}