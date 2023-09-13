#include <lcom/lcf.h>
#include "pacmanController.h"
#include "../../model/pacmanModel/pacman.h"
#include "../../model/direction.h"
#include "../../view/menuView/menuView.h"
#include "../gameController/gameController.h"
#include "../collisionsController/collisionsController.h"
#include "../timerController/timerController.h"

extern Pacman pacman;
extern Direction currentDirection;

extern bool isGame;
extern unsigned int score;

extern uint8_t* pacmanLeftPM, *pacmanRightPM, *pacmanUpPM, *pacmanDownPM, *currentPacmanPM;
extern xpm_image_t pacmanLeftImg, pacmanRightImg, pacmanUpImg, pacmanDownImg, currentPacmanImg;

void (moveL)() {
    pacman.pos.xMin -= PACMAN_STEP;
    pacman.pos.xMax -= PACMAN_STEP;
    currentPacmanPM = pacmanLeftPM;
    currentPacmanImg = pacmanLeftImg;
}

void (moveR)() {
    pacman.pos.xMin += PACMAN_STEP;
    pacman.pos.xMax += PACMAN_STEP;
    currentPacmanPM = pacmanRightPM;
    currentPacmanImg = pacmanRightImg;
}

void (moveU)() {
    pacman.pos.yMax -= PACMAN_STEP;
    pacman.pos.yMin -= PACMAN_STEP;
    currentPacmanPM = pacmanUpPM;
    currentPacmanImg = pacmanUpImg;
}

void (moveD)() {
    pacman.pos.yMax += PACMAN_STEP;
    pacman.pos.yMin += PACMAN_STEP;
    currentPacmanPM = pacmanDownPM;
    currentPacmanImg = pacmanDownImg;
}

void setTimer();
void movePacman() {
    Position aux = pacman.pos;
    switch (currentDirection) {
        case DIRECTION_UP:
            moveU();
            break;
        case DIRECTION_DOWN:
            moveD();
            break;
        case DIRECTION_LEFT:
            moveL();
            break;
        case DIRECTION_RIGHT:
            moveR();
            break;
    }

    if(pacman.pos.xMax >= (148 + 728)) {
        pacman.pos.xMin = 148;
        pacman.pos.xMax = 148 + 25;
    }
    else if(pacman.pos.xMin <= 148) {
        pacman.pos.xMin = 148 + 728 - 25;
        pacman.pos.xMax = 148 + 728;
    }
    if (wallCollision(pacman.pos)) pacman.pos = aux;
    else if (ghostCollision()) {
        pacman.pos = aux;
        isGame = false;
    }
    else if (coinCollision()) score += 10;
    else if (energizerCollision()) score += 50;
}
