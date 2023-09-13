#ifndef COIN_MODEL_H
#define COIN_MODEL_H

#include "../position.h"

/// @brief Coins that Pac-Man has to capture. They give him 10 points.
typedef struct {
    Position pos;
    bool isCaptured;
} Coin;

/// @brief Energizers that Pac-Man has to capture. They give him 50 points.
typedef struct {
    Position pos;
    bool isCaptured;
} Energizer;

/// @brief Set the coins' positions and mark them as not captured.
void (setCoinsPositions)();


/// @brief Set the energizers' positions and mark them as not captured.
void (setEnergizersPositions)();

#endif
