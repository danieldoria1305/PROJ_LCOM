#ifndef _LCOM_KEYBOARD_H_
#define _LCOM_KEYBOARD_H_

/**
 * @brief Subscribes the keyboard interruptions.
 * @return Return 0 upon success and non-zero otherwise
 */
int (keyboard_subscribe_int)(uint8_t* bit_no);

/**
 * @brief Unsubscribes the keyboard interruptions.
 * @return Return 0 upon success and non-zero otherwise
 */
int (keyboard_unsubscribe_int)();

/**
 * @brief Keyboard interrupt handler.
 */
void (keyboard_int_handler)();

#endif
