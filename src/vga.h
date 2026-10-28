#ifndef VGA_H
#define VGA_H

//  VIDEO CONFIGURATION

/**
 * @brief Sets the video mode
 * 
 * @param mode Number of the desired mode.
 * 
 * @return None.
 */
void vga_set_mode(uint8_t mode);

/**
 * @brief Blocks until the vertical refresh cycle has been completed.
 *        This prevents tearing on CRTs.
 * 
 * @param None.
 * 
 * @return None.
 */
void vga_vertical_sync();

/**
 * @brief Sets the palette mask for the video graphics adapter.
 *        This prevents the modification of colors.
 * 
 * @param mask The color palette mask.
 * 
 * @return None.
 */
void vga_set_pallete_mask(uint8_t mask);

/**
 * @brief Sets palette entry at index to the inputted RGB values.
 *        Colors must fall within [0:63].
 * 
 * @param index Index in the color palette to be written to.
 * @param r Pointer to red value.
 * @param g Pointer to green value.
 * @param b Pointer to blue value.
 */
void vga_set_color(uint8_t index, uint8_t r, uint8_t g, uint8_t b);



//  ADAPTER QUERY

/**
 * @brief Retrieves palette entry at index and stores the values
 *        in the respective pointers.
 * 
 * @param index Index in the color palette to be retreived.
 * @param r Pointer to red value.
 * @param g Pointer to green value.
 * @param b Pointer to blue value.
 */
void vga_get_color(uint8_t index, uint8_t *r, uint8_t *g, uint8_t *b);

/**
 * @brief Gets address of video memory for the adapter.
 * 
 * @param None.
 * 
 * @return Address of video memory.
 */
uint8_t *vga_get_address();



#endif