#ifndef PACMAN_MODEL_H
#define PACMAN_MODEL_H

#include "../position.h"

/// @brief Pac-Man, the player.
typedef struct {
    Position pos;
} Pacman;

/// @brief Set Pac-Man's initial position.
void (setPacmanPosition)();

#endif
