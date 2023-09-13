#ifndef GHOSTS_MOVEMENT_CONTROLLER_H
#define GHOSTS_MOVEMENT_CONTROLLER_H

#include "../../model/position.h"

#define GHOST_STEP 5

/**
 * @brief Moves ghost to the left one step.
 * @param ghostIndex is the index of the ghost.
 */
void (moveLeft)(int ghostIndex);

/**
 * @brief Moves ghost to the right one step.
 * @param ghostIndex is the index of the ghost.
 */
void (moveRight)(int ghostIndex);

/**
 * @brief Moves ghost up one step.
 * @param ghostIndex is the index of the ghost.
 */
void (moveUp)(int ghostIndex);

/**
 * @brief Moves ghost down one step.
 * @param ghostIndex is the index of the ghost.
 */
void (moveDown)(int ghostIndex);

/**
 * @brief Tries to move ghost to a given position.
 * @param ghostIndex is the index of the ghost.
 * @param targetPosition is the position to move to.
*/
void tryMoving(int ghostIndex, Position targetPosition);

/**
 * @brief Strategy for first ghost: Move to a position ahead of Pacman.
 * @param ghostIndex is the index of the ghost.
 */
void ghostStrategy0(int ghostIndex);

/**
 * @brief Strategy for second ghost: Move to a position behind Pacman.
 * @param ghostIndex is the index of the ghost.
 */
void ghostStrategy1(int ghostIndex);

/**
 * @brief Strategy for third ghost: Move to a position ahead of Pacman in the opposite direction.
 * @param ghostIndex is the index of the ghost.
 */
void ghostStrategy2(int ghostIndex);

/**
 * @brief Strategy for fourth ghost: Move to a position behind Pacman in the opposite direction.
 * @param ghostIndex is the index of the ghost.
 */
void ghostStrategy3(int ghostIndex);

/**
 * @brief Moves ghosts according to their strategies.
 */
void (moveGhosts)();

#endif
