#include <lcom/lcf.h>
#include <stdint.h>
#include "mouseView.h"
#include "../../devices/graphics/graphics.h"
#include "../../controller/mouseController/mouseController.h"
#include "../pixmaps/pixmaps.h"

extern int x,  y;

extern uint8_t* mousePM;
extern xpm_image_t mouseImg;

void (drawMouse)() {
    draw_xpm(mousePM, mouseImg, x, y);
}
