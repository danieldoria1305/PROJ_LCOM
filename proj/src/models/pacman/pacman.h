#ifndef PACMAN_H
#define PACMAN_H

#include "../position.h"

typedef struct {
    Position position;
} Pacman;

void (set_pacman_position)();

#endif