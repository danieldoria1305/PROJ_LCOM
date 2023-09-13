#include <lcom/lcf.h>
#include "ghostsController.h"
#include "../../model/ghostsModel/ghost.h"
#include "../../model/pacmanModel/pacman.h"
#include "../../model/direction.h"
#include "../../model/position.h"
#include "../../view/pixmaps/pixmaps.h"
#include "../collisionsController/collisionsController.h"
#include "../gameController/gameController.h"
#include "../keyboardController/keyboardController.h"

extern Pacman pacman;
extern Direction currentDirection;
extern Ghost ghosts[4];
extern bool isGame;

bool (ghostCollidesWithPacman)(Position ghostPosition);
void moveLeft(int ghostIndex) {
    ghosts[ghostIndex].pos.xMin -= GHOST_STEP;
    ghosts[ghostIndex].pos.xMax -= GHOST_STEP;
}

void moveRight(int ghostIndex) {
    ghosts[ghostIndex].pos.xMin += GHOST_STEP;
    ghosts[ghostIndex].pos.xMax += GHOST_STEP;
}

void moveUp(int ghostIndex) {
    ghosts[ghostIndex].pos.yMin -= GHOST_STEP;
    ghosts[ghostIndex].pos.yMax -= GHOST_STEP;
}

void moveDown(int ghostIndex) {
    ghosts[ghostIndex].pos.yMin += GHOST_STEP;
    ghosts[ghostIndex].pos.yMax += GHOST_STEP;
}

void tryMoving(int ghostIndex, Position targetPosition) {
    Position aux = ghosts[ghostIndex].pos;

    if(ghosts[ghostIndex].pos.xMax >= (148 + 728) || ghosts[ghostIndex].pos.xMin <= 148)
        ghosts[ghostIndex].pos = aux;
    else if (ghosts[ghostIndex].pos.xMin < targetPosition.xMin)
        moveRight(ghostIndex);
    else if (ghosts[ghostIndex].pos.xMin > targetPosition.xMin)
        moveLeft(ghostIndex);
    else if (ghosts[ghostIndex].pos.yMin < targetPosition.yMin)
        moveDown(ghostIndex);
    else if (ghosts[ghostIndex].pos.yMin > targetPosition.yMin)
        moveUp(ghostIndex);
    if (ghostCollidesWithPacman(ghosts[ghostIndex].pos))
        isGame = false;
}

// Strategy for Ghost 0: Move to a position ahead of Pacman
void ghostStrategy0(int ghostIndex) {
    int numPositionsAhead = 4;
    Position pacmanPosition = pacman.pos;
    Position targetPosition = pacmanPosition;

    switch (currentDirection) {
        case DIRECTION_UP:
            targetPosition.yMin -= GHOST_STEP * numPositionsAhead;
            targetPosition.yMax -= GHOST_STEP * numPositionsAhead;
            break;
        case DIRECTION_DOWN:
            targetPosition.yMin += GHOST_STEP * numPositionsAhead;
            targetPosition.yMax += GHOST_STEP * numPositionsAhead;
            break;
        case DIRECTION_RIGHT:
            targetPosition.xMin += GHOST_STEP * numPositionsAhead;
            targetPosition.xMax += GHOST_STEP * numPositionsAhead;
            break;
        case DIRECTION_LEFT:
            targetPosition.xMin -= GHOST_STEP * numPositionsAhead;
            targetPosition.xMax -= GHOST_STEP * numPositionsAhead;
            break;
    }

    tryMoving(ghostIndex, targetPosition);
}

// Strategy for Ghost 1: Move to a position ahead of Pacman in the opposite direction
void ghostStrategy1(int ghostIndex) {
    int numPositionsAhead = 6;
    Position pacmanPosition = pacman.pos;
    Position targetPosition = pacmanPosition;

    switch (currentDirection) {
        case DIRECTION_UP:
            targetPosition.yMin += GHOST_STEP * numPositionsAhead;
            targetPosition.yMax += GHOST_STEP * numPositionsAhead;
            break;
        case DIRECTION_DOWN:
            targetPosition.yMin -= GHOST_STEP * numPositionsAhead;
            targetPosition.yMax -= GHOST_STEP * numPositionsAhead;
            break;
        case DIRECTION_RIGHT:
            targetPosition.xMin -= GHOST_STEP * numPositionsAhead;
            targetPosition.xMax -= GHOST_STEP * numPositionsAhead;
            break;
        case DIRECTION_LEFT:
            targetPosition.xMin += GHOST_STEP * numPositionsAhead;
            targetPosition.xMax += GHOST_STEP * numPositionsAhead;
            break;
    }

    tryMoving(ghostIndex, targetPosition);
}

// Strategy for Ghost 2: Move to a position ahead and to the side of Pacman
void ghostStrategy2(int ghostIndex) {
    int numPositionsAhead = 6;
    Position pacmanPosition = pacman.pos;
    Position targetPosition = pacmanPosition;

    switch (currentDirection) {
        case DIRECTION_UP:
            targetPosition.yMin -= GHOST_STEP * numPositionsAhead;
            targetPosition.yMax -= GHOST_STEP * numPositionsAhead;
            targetPosition.xMin += GHOST_STEP * numPositionsAhead;
            targetPosition.xMax += GHOST_STEP * numPositionsAhead;
            break;
        case DIRECTION_DOWN:
            targetPosition.yMin += GHOST_STEP * numPositionsAhead;
            targetPosition.yMax += GHOST_STEP * numPositionsAhead;
            targetPosition.xMin -= GHOST_STEP * numPositionsAhead;
            targetPosition.xMax -= GHOST_STEP * numPositionsAhead;
            break;
        case DIRECTION_RIGHT:
            targetPosition.xMin -= GHOST_STEP * numPositionsAhead;
            targetPosition.xMax -= GHOST_STEP * numPositionsAhead;
            targetPosition.yMin -= GHOST_STEP * numPositionsAhead;
            targetPosition.yMax -= GHOST_STEP * numPositionsAhead;
            break;
        case DIRECTION_LEFT:
            targetPosition.xMin += GHOST_STEP * numPositionsAhead;
            targetPosition.xMax += GHOST_STEP * numPositionsAhead;
            targetPosition.yMin += GHOST_STEP * numPositionsAhead;
            targetPosition.yMax += GHOST_STEP * numPositionsAhead;
            break;
    }

    tryMoving(ghostIndex, targetPosition);
}

// Strategy for Ghost 3: Move to a random position ahead of Pacman
void ghostStrategy3(int ghostIndex) {
    int numPositionsAhead = 2;
    Position pacmanPosition = pacman.pos;
    Position targetPosition = pacmanPosition;

    int offsetX = (rand() % (2 * numPositionsAhead + 1)) - numPositionsAhead;
    int offsetY = (rand() % (2 * numPositionsAhead + 1)) - numPositionsAhead;

    targetPosition.xMin += offsetX * GHOST_STEP;
    targetPosition.xMax += offsetX * GHOST_STEP;
    targetPosition.yMin += offsetY * GHOST_STEP;
    targetPosition.yMax += offsetY * GHOST_STEP;

    tryMoving(ghostIndex, targetPosition);
}

void moveGhosts() {
    for (int i = 0; i < 4; i++) {
        if(i == 0) ghostStrategy0(i);
        else if(i == 1) ghostStrategy1(i);
        else if(i == 2) ghostStrategy2(i);
        else if(i == 3) ghostStrategy3(i);
    }
}
