#ifndef COLLISIONS_CONTROLLER_H
#define COLLISIONS_CONTROLLER_H

#include "../../model/position.h"

/**
 * @brief Checks if there was a collision between two objects.
 * @param obj1 is the first object.
 * @param obj2 is the second object.
 * @return true if there was a collision, false otherwise.
*/
bool (checkCollision)(Position obj1, Position obj2);

/**
 * @brief Checks if a given ghost collides with the pacman.
 * @param ghost_pos is the position of the ghost.
 * @return true if there was a collision, false otherwise.
*/
bool (ghostCollidesWithPacman)(Position ghost_pos);

/**
 * @brief Checks if there was a collision between pacman and a ghost.
 * @return true if there was a collision, false otherwise.
 */
bool (ghostCollision)();

/**
 * @brief Checks if there was a collision between pacman and a coin.
 * @return true if there was a collision, false otherwise.
 */
bool (coinCollision)();

/**
 * @brief Checks if there was a collision between pacman and an energizer.
 * @return true if there was a collision, false otherwise.
 */
bool (energizerCollision)();

/**
 * @brief Checks if there was a collision between pacman and a wall.
 * @param position is the position of pacman.
 * @return true if there was a collision, false otherwise.
 */
bool (wallCollision)(Position position);





/**
 * @brief Checks if the pacman captured any big coin.
 * 
 */
bool (twoGhostsCollision)(Position newPosition, int ghostIndex);

#endif
