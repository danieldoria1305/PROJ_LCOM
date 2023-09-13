#ifndef GHOST_MODEL_H
#define GHOST_MODEL_H

#include "../position.h"

/// @brief Ghosts that chase Pac-Man accross the maze.
typedef struct {
    Position pos; 
} Ghost;

/// @brief Set the initial position of the blue ghost.
void (setBlueGhostPosition)();

/// @brief Set the initial position of the orange ghost.
void (setOrangeGhostPosition)();

/// @brief Set the initial position of the pink ghost.
void (setPinkGhostPosition)();

/// @brief Set the initial position of the red ghost.
void (setRedGhostPosition)();

/// @brief Set the initial position of ghosts.
void (setGhostsPositions)();

#endif
