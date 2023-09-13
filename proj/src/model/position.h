#ifndef POSITION_H
#define POSITION_H

#include <lcom/lcf.h>

/// @brief Postion of a game element.
typedef struct {
    int xMin;
    int xMax;
    int yMax;
    int yMin;
} Position;

#endif
