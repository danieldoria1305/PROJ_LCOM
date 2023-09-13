#ifndef PACMAN_MOVEMENT_CONTROLLER_H
#define PACMAN_MOVEMENT_CONTROLLER_H

#define PACMAN_STEP 10

/**
 * @brief Moves pacman to the left one step.
 */
void (moveL)();

/**
 * @brief Moves pacman to the right one step.
 */
void (moveR)();

/**
 * @brief Moves pacman up one step.
 */
void (moveU)();

/**
 * @brief Moves pacman down one step.
 */
void (moveD)();

/**
 * @brief Moves pacman in the direction it's facing, while checking for collisions.
 */
void (movePacman)();

#endif
