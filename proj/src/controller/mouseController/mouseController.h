#ifndef MOUSE_CONTROLLER_H
#define MOUSE_CONTROLLER_H

/**
 * @brief Checks if there's a mouse click over the rules option and if so, display the corresponding result.
 * @param clicked True if the mouse is clicked, false otherwise.
*/
void clickRules(bool clicked);

/**
 * @brief Checks if there's a mouse click over the play option and if so, display the corresponding result.
 * @param clicked True if the mouse is clicked, false otherwise.
*/
void clickPlay(bool clicked);

/**
 * @brief Checks if there's a mouse click over the exit option and if so, display the corresponding result.
 * @param clicked True if the mouse is clicked, false otherwise.
*/
void clickExit(bool clicked);

/**
 * @brief Checks if there's a mouse click over the back to menu option and if so, display the corresponding result.
 * @param clicked True if the mouse is clicked, false otherwise.
*/
void clickBackToMenu(bool clicked);


/**
 * @brief Checks if there's a mouse clicked over any menu option and if so, display the corresponding result.
 * @param clicked True if the mouse is clicked, false otherwise.
 */
void (clickCheck)(bool clicked);

/**
 * @brief Checks if the mouse is over any menu option.
 * @param pp Mouse packet.
 */
void (mousePosition)(struct packet pp);

/**
 * @brief Mouse interrupt handler.
 */
void (mouseInterruptHandler)();

#endif
