#include "vga.h"
#include "vga_lib.h"



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

}

void vga_set_pallete_mask(uint8_t mask)
{

}

void vga_set_color(uint8_t index, uint8_t r, uint8_t g, uint8_t b)
{

}




//  ADAPTER QUERY

void vga_get_color(uint8_t index, uint8_t *r, uint8_t *g, uint8_t *b)
{

}

uint8_t *vga_get_address()
{

}