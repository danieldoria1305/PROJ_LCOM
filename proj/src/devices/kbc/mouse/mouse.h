#ifndef _LCOM_MOUSE_H_
#define _LCOM_MOUSE_H_

/**
 * /// @brief Subscribes the mouse interruptions.
 * /// @param bit_no Address of memory to be initialized with the
 * ///         bit number to be set in the mask returned upon an interrupt
 * ///         notification.
 * /// @return Return 0 upon success and non-zero otherwise
*/
int (mouse_subscribe_int)(uint8_t *bit_no);

/**
 * /// @brief Unsubscribes the mouse interruptions.
 * /// @return Return 0 upon success and non-zero otherwise
*/
int (mouse_unsubscribe_int)();

/**
 * /// @brief Enables data reporting.
 * /// @return Return 0 upon success and non-zero otherwise
*/
int (enable_data_reporting)();

/**
 * /// @brief Disables data reporting.
 * /// @return Return 0 upon success and non-zero otherwise
*/
int (disable_data_reporting)();

/**
 * /// @brief Mouse interrupt handler.
*/
void (mouse_int_handler)();

/**
 * /// @brief Parses the mouse packet.
 * /// @param pp The packet to be parsed.
*/
void (parse_mouse_packet)(struct packet* pp);

#endif
