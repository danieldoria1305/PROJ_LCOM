#include <lcom/lcf.h>
#include <stdint.h>
#include "wallsView.h"
#include "../../devices/graphics/graphics.h"
#include "../pixmaps/pixmaps.h"

extern uint8_t* wallsPM;
extern xpm_image_t wallsImg;

void (drawWalls)() {
    draw_xpm(wallsPM, wallsImg, 148, 20);
}

void (eraseWalls)() {
    draw_rectangle(148, 20, wallsImg.width, wallsImg.height, 0);
}
