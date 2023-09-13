#ifndef _LCOM_GRAPHICS_H_
#define _LCOM_GRAPHICS_H_

#define AH 0x4f
#define VBE_FUNCTION 0x02
#define INT_NO 0x10

/**
 * @brief Maps the VRAM.
 * @param mode is the mode.
 * @return 0 if success, 1 otherwise.
 */
int (map_vram)(uint16_t mode);

/**
 * @brief Initializes the graphics mode.
 * @param mode is the mode.
 * @return 0 if success, 1 otherwise.
 */
int (initialize_graphics_mode)(uint16_t mode);

/**
 * @brief Initializes the graphics mode.
 * @param mode is the mode.
 * @return 0 if success, 1 otherwise.
*/
int (graphics_init)(uint16_t mode);

/**
 * @brief Draws a pixel.
 * @param x is the horizontal position.
 * @param y is the vertical position.
 * @param color is the color of the pixel.
 */
void (draw_pixel)(uint16_t x, uint16_t y, uint32_t color);

/**
 * @brief Draws a horizontal line.
 * @param x is the horizontal position.
 * @param y is the vertical position.
 * @param len is the length of the line.
 * @param color is the color of the line.
 */
void (draw_horizontal_line)(uint16_t x, uint16_t y, uint16_t len, uint32_t color);

/**
 * @brief Draws a rectangle.
 * @param x is the horizontal position.
 * @param y is the vertical position.
 * @param width is the width of the rectangle.
 * @param height is the height of the rectangle.
 * @param color is the color of the rectangle.
 */
void (draw_rectangle)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);

/**
 * @brief Draws a XPM.
 * @param pm is the XPM.
 * @param img_info is the XPM image info.
 * @param x is the horizontal position.
 * @param y is the vertical position.
 */
void (draw_xpm)(uint8_t* pm, xpm_image_t img_info, uint16_t x, uint16_t y);

#endif
