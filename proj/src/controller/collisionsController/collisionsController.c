#include <lcom/lcf.h>
#include "collisionsController.h"
#include "../../model/position.h"
#include "../../model/coinsModel/coin.h"
#include "../../model/ghostsModel/ghost.h"
#include "../../model/pacmanModel/pacman.h"
#include "../../view/pixmaps/pixmaps.h"

extern Pacman pacman;
extern Ghost ghosts[4];
extern Energizer energizers[5];
extern Coin coins[326];
extern uint8_t* wallsPM;

bool (checkCollision)(Position obj1, Position obj2) {
    return (((obj1.yMax >= obj2.yMax && obj1.yMax <= obj2.yMin) || 
        (obj1.yMin <= obj2.yMin && obj1.yMin >= obj2.yMax)) &&
        ((obj1.xMin <= obj2.xMin && obj1.xMax >= obj2.xMin) || 
        (obj1.xMax >= obj2.xMax && obj1.xMin <= obj2.xMax)));
}

bool (ghostCollidesWithPacman)(Position ghost_pos) {
    return checkCollision(ghost_pos, pacman.pos);
}

bool (ghostCollision)() {
    for (int i = 0; i < 4; i++) {
        if (checkCollision(ghosts[i].pos, pacman.pos)) return true;
    }
    return false;
}

bool (coinCollision)() {
    for (int i = 0; i < 326; i++) {
        if (checkCollision(coins[i].pos, pacman.pos) && !coins[i].isCaptured) {
            coins[i].isCaptured = true;
            return true;
        }
    }
    return false;
}

bool (energizerCollision)() {
    for (int i = 0; i < 5; i++) {
        if (checkCollision(energizers[i].pos, pacman.pos) && !energizers[i].isCaptured) {
            energizers[i].isCaptured = true;
            return true;
        }
    }
    return false;
}

bool (wallCollision)(Position position) {
    position.xMin -= 148;
    position.xMax -= 148;
    position.yMax -= 20;
    position.yMin -= 20;

    int index = 0;
    for (int y = 0; y < 728; y++) {
        for (int x = 0; x < 728; x++) {
            if (y >= position.yMax && y <= position.yMin && x >= position.xMin && x <= position.xMax && *(wallsPM + index) == 1)
                return true;
            index++;
        }
    }
    return false;
}
