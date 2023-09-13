#ifndef POSITION_H
#define POSITION_H

#include <lcf.h>

typedef struct Position {
    int next_x;
    int prev_x;
    int up_y;
    int down_y;
} Position;

#endif