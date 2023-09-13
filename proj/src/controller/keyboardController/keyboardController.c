#include <lcom/lcf.h>
#include <stdint.h>
#include "keyboardController.h"
#include "../../devices/kbc/keyboard/keyboard.h"
#include "../../devices/kbc/i8042.h"
#include "../../devices/graphics/graphics.h"
#include "../../view/pacmanView/pacmanView.h"
#include "../../view/menuView/menuView.h"
#include "../../view/pixmaps/pixmaps.h"
#include "../../model/direction.h"
#include "../pacmanController/pacmanController.h"
#include "../timerController/timerController.h"

extern bool make_code, full_scancode;
extern int num_bytes;
extern uint8_t scan_bytes[2];

extern bool isGame, isPause;
extern unsigned int gameDuration, timeBeforePause;

Direction currentDirection;

void (setTimer)();
void (movePacman)();
void (keyHandler)() {
    if (num_bytes == 1) {
        if (scan_bytes[0] == Q_MCODE) isGame = false;
        else if (scan_bytes[0] == P_MCODE) {
            isPause = !isPause;
            if (isPause) {
                drawPauseGame();
                timeBeforePause = gameDuration;
            } else {
                gameDuration = timeBeforePause;
                setTimer();
                drawGameElements();
            }
        }
    } else if (num_bytes == 2 && scan_bytes[0] == SCAN_MSB && !isPause) {
        erasePacman();

        switch (scan_bytes[1]) {
        case ARROW_UP_MCODE:
            currentDirection = DIRECTION_UP;
            break;
        case ARROW_DOWN_MCODE:
            currentDirection = DIRECTION_DOWN;
            break;
        case ARROW_RIGHT_MCODE: 
            currentDirection = DIRECTION_RIGHT;
            break;
        case ARROW_LEFT_MCODE:
            currentDirection = DIRECTION_LEFT;
            break;
        default:
            break;
        }

        movePacman();
        drawPacman();
    }

    if (full_scancode) num_bytes = 0;
}
