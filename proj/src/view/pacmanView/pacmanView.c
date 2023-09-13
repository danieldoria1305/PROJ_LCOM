#include <lcom/lcf.h>
#include <stdint.h>
#include "pacmanView.h"
#include "../../devices/graphics/graphics.h"
#include "../../model/pacmanModel/pacman.h"
#include "../../controller/gameController/gameController.h"
#include "../pixmaps/pixmaps.h"

extern uint8_t* pacmanLeftPM, *pacmanRightPM, *pacmanUpPM, *pacmanDownPM;
extern xpm_image_t pacmanLeftImg, pacmanRightImg, pacmanUpImg, pacmanDownImg;
extern Pacman pacman;
extern bool start;

uint8_t* currentPacmanPM;
xpm_image_t currentPacmanImg;

void (drawPacman)() {
    if (start) {
        currentPacmanPM = pacmanRightPM;
        currentPacmanImg = pacmanRightImg;
    }
    draw_xpm(currentPacmanPM, currentPacmanImg, pacman.pos.xMin, pacman.pos.yMax);
}

void (erasePacman)() {
    draw_rectangle(pacman.pos.xMin, pacman.pos.yMax, pacmanRightImg.width, pacmanRightImg.height, 0);
}
