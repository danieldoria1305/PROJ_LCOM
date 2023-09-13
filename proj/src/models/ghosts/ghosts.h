#ifndef GHOSTS_H
#define GHOSTS_H

#include "../position.h"

typedef struct {
    Position position;
    bool is_eaten;
} Ghost;

void (set_ghost_position)();

void (set_blueghost_position)();

void (set_redghost_position)();

void (set_pinkghost_position)();

void (set_orangeghost_position)();

#endif