#include <lcom/lcf.h>
#include <stdint.h>
#include "ghostsView.h"
#include "../../devices/graphics/graphics.h"
#include "../../model/ghostsModel/ghost.h"
#include "../pixmaps/pixmaps.h"

extern Ghost ghosts[4];
extern uint8_t* redGhostPM, *orangeGhostPM, *pinkGhostPM, *blueGhostPM;
extern xpm_image_t redGhostImg, orangeGhostImg, pinkGhostImg, blueGhostImg;

void (drawGhosts)() {
    draw_xpm(redGhostPM, redGhostImg, ghosts[0].pos.xMin, ghosts[0].pos.yMax);
    draw_xpm(blueGhostPM, blueGhostImg, ghosts[1].pos.xMin, ghosts[1].pos.yMax);
    draw_xpm(pinkGhostPM, pinkGhostImg, ghosts[2].pos.xMin, ghosts[2].pos.yMax);
    draw_xpm(orangeGhostPM, orangeGhostImg, ghosts[3].pos.xMin, ghosts[3].pos.yMax);
}

void (eraseGhosts)() {
    draw_rectangle(ghosts[0].pos.xMin, ghosts[0].pos.yMax, redGhostImg.width, redGhostImg.height, 0);
    draw_rectangle(ghosts[1].pos.xMin, ghosts[1].pos.yMax, blueGhostImg.width, blueGhostImg.height, 0);
    draw_rectangle(ghosts[2].pos.xMin, ghosts[2].pos.yMax, pinkGhostImg.width, pinkGhostImg.height, 0);
    draw_rectangle(ghosts[3].pos.xMin, ghosts[3].pos.yMax, orangeGhostImg.width, orangeGhostImg.height, 0);
}
