#ifndef COLISSIONS_H
#define COLISSIONS_H

#include "../models/ghosts/ghosts.h"
#include "../models/coins/coins.h"
#include "../models/pacman/pacman.h"
#include "../models/position.h"

void (check_ghost_collision)();

void (check_smallcoin_collision)();

void (check_bigcoin_collision)();

void (pacman_ghost_collision)();

void (check_maze_collision)();

#endif