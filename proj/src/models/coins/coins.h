#ifndef COINS_H
#define COINS_H

#include "../position.h"

typedef struct {
    Position position;
    bool is_collected;
} Small_Coin;

typedef struct {
    Position position;
    bool is_collected;
} Big_Coin;

void (set_smallcoin_position)();

void (set_bigcoin_position)();

#endif