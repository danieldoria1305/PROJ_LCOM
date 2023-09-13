#include <lcom/lcf.h>
#include <stdint.h>
#include "gameController.h"
#include "../../devices/timer/timer.h"
#include "../../devices/kbc/keyboard/keyboard.h"
#include "../../devices/kbc/mouse/mouse.h"
#include "../../model/pacmanModel/pacman.h"
#include "../../model/ghostsModel/ghost.h"
#include "../../model/coinsModel/coin.h"
#include "../../view/pixmaps/pixmaps.h"
#include "../../view/coinsView/coinsView.h"
#include "../timerController/timerController.h"

extern unsigned int gameDuration;

bool isMenu = true, isGame = false, isPause = false, isRules = false, end = false, start = true;
unsigned int score = 0;

void setTimer();
void (initializeGame)() {
    setPacmanPosition();
    setGhostsPositions();
    setCoinsPositions();
    setEnergizersPositions();

    loadPM();
    
    gameDuration = 210;
    setTimer();
}
