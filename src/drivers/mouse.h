#ifndef MOUSE_H
#define MOUSE_H


struct mouse_state
{
    bool left, right, middle; // true if button is [ressed]
    int16_t x, y; // Current current position
};


//  HARDWARE POLLING

/**
 * @brief Initializes the mouse.
 *
 * @return true: Initialization successful.
 * @return false: Initialization failed.
 */
bool mouse_reset(void);

/**
 * @brief Get the number of presses of the specified button.
 * 
 * @param button 0: Left button
 *               1: Right button
 *               2: Middle button
 * 
 * @return The number of presses. -1 upon invalid button requested.
 */
int mouse_get_button_presses(int16_t button);

/**
 * @brief Get the number of releases of the specified button.
 * 
 * @param button 0: Left button.
 *               1: Right button.
 *               2: Middle button.
 * 
 * @return The number of releases. -1 upon invalid button requested.
 */
int mouse_get_button_releases(int16_t button);

/**
 * @brief Get the number of mickeys accumulated since the last call
 *        and add it to the values at the pointers provided.
 * 
 * @param mickeys_x Pointer to the number of horizontal mickeys.
 * @param mickeys_y Pointer to the number of vertical mickeys.
 * 
 * @return The number of mickeys in each direction.
 */
void mouse_get_mickeys(int16_t *mickeys_x, int16_t *mickeys_y);

/**
 * @brief Returns whether a button is currently pressed.
 * 
 * @param button 0: Left button.
 *               1: Right button.
 *               2: Middle button.
 * 
 * @return true: Button is currently pressed
 * @return false: Button is not currently pressed.
 */
bool mouse_is_pressed(int16_t button);

/**
 * @brief Calculate mouse position based on current values.
 * 
 * @param value Pointer to the value of the current position.
 * @param mickeys Number of mickeys accumulated.
 * @param rate Mouse sensitivity.
 * 
 * @return Updates the system with the new mouse position of value.
 *         Any remainder is re-stored in mickeys.
 */
void mouse_calculate_pos(int16_t* value, int16_t* mickeys, int16_t rate);



//  BIOS STATE

/**
 * @brief Shows the cursor.
 * 
 * @param None.
 * 
 * @return None.
 */
void mouse_show_cursor(void);

/**
 * @brief Hides the cursor.
 * 
 * @param None.
 * 
 * @return None.
 */
void mouse_hide_cursor(void);

/**
 * @brief Sets the horizontal cursor limits.
 * 
 * @param minimum Minimum x-coordinate.
 * @param maximum Maximum x-coordinate.
 * 
 * @return None.
 */
void mouse_set_limits_x(int16_t minimum, int16_t maximum);

/**
 * @brief Sets the vertical cursor limits.
 * 
 * @param minimum Minimum y-coordinate.
 * @param maximum Maximum y-coordinate.
 * 
 * @return None.
 */
void mouse_set_limits_y(int16_t minimum, int16_t maximum);

/**
 * @brief Sets the current mouse position.
 * 
 * @param x Current horizontal position.
 * @param y Current vertical position.
 * 
 * @return None.
 */
void mouse_set_position(int16_t x, int16_t y);

/**
 * @brief Obtains the mouse state from the BIOS.
 * 
 * @param state Pointer to the data structure that will contain the result.
 * 
 * @return Mouse state from the BIOS.
 */
void mouse_get_state(struct mouse_state* state);

/**
 * @brief Sets the mickeys-per-coordinate rate.
 * 
 * @param rate_x Number of mickeys per x-coordinate.
 * @param rate_x Number of mickeys per y-coordinate.
 * 
 * @return None.
 */
void mouse_set_movement_rate(int16_t rate_x, int16_t rate_y);

/**
 * @brief Sets the current mouse sensitivity level.
 * 
 * @param level_x Horizontal sensitivity level (1-100).
 * @param level_y Vertical sensitivity level (1-100).
 * 
 * @return None.
 */
void mouse_set_sensitivity(int16_t level_x, int16_t level_y);

/**
 * @brief Gets the current mouse sensitivity level (1-100).
 * 
 * @param level_x Pointer to the current horizontal sensitivity level.
 * @param level_y Pointer to the current vertical sensitivity level.
 * 
 * @return Mouse sensitivity levels will be stored in their respective pointers.
 */
void mouse_get_sensitivity(int16_t *level_x, int16_t *level_y);


#endif