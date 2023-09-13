#include <lcom/lcf.h>
#include <stdint.h>
#include "coinsView.h"
#include "../../devices/graphics/graphics.h"
#include "../../model/coinsModel/coin.h"
#include "../pixmaps/pixmaps.h"

extern Coin coins[326];
extern Energizer energizers[5];
extern uint8_t* coinPM, *energizerPM;
extern xpm_image_t coinImg, energizerImg;

void (drawCoins)() {
    for (int i = 0; i < 326; i++)
        if (!coins[i].isCaptured)
            draw_xpm(coinPM, coinImg, coins[i].pos.xMin, coins[i].pos.yMax);
}

void (drawEnergizers)() {
    for (int i = 0; i < 5; i++)
        if (!energizers[i].isCaptured)
            draw_xpm(energizerPM, energizerImg, energizers[i].pos.xMin, energizers[i].pos.yMax);
}
