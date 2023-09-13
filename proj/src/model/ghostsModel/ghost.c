#include <lcom/lcf.h>
#include "ghost.h"

Ghost ghosts[4];

void (setRedGhostPosition)() {
    ghosts[0].pos.xMin = 500;
    ghosts[0].pos.xMax = 525;
    ghosts[0].pos.yMax = 305;
    ghosts[0].pos.yMin = 330;
}

void (setBlueGhostPosition)() {
    ghosts[1].pos.xMin = 440;
    ghosts[1].pos.xMax = 465;
    ghosts[1].pos.yMax = 345;
    ghosts[1].pos.yMin = 370;
}

void (setPinkGhostPosition)() {
    ghosts[2].pos.xMin = 500;
    ghosts[2].pos.xMax = 525;
    ghosts[2].pos.yMax = 345;
    ghosts[2].pos.yMin = 370;
}

void (setOrangeGhostPosition)() {
    ghosts[3].pos.xMin = 560;
    ghosts[3].pos.xMax = 585;
    ghosts[3].pos.yMax = 345;
    ghosts[3].pos.yMin = 370;
}

void (setGhostsPositions)() {
    setRedGhostPosition();
    setBlueGhostPosition();
    setPinkGhostPosition();
    setOrangeGhostPosition();
}
