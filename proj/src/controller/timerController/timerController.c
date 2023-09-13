#include <lcom/lcf.h>
#include <stdint.h>
#include "timerController.h"
#include "../../devices/timer/timer.h"
#include "../../view/ghostsView/ghostsView.h"
#include "../../view/pixmaps/pixmaps.h"
#include "../gameController/gameController.h"
#include "../ghostsController/ghostsController.h"

unsigned int gameDuration, mins, secs, timeBeforePause;

extern long timer_counter;
extern bool isGame, isPause;

void (setTimer)() {
    mins = gameDuration / 60;
    secs = gameDuration % 60;
}

void (timerInterruptHandler)() {
    timer_int_handler();
    
    if (timer_counter % 60 == 0){
        gameDuration--;
        setTimer();
        if (gameDuration == 0) isGame = false;
    }
    
    if (timer_counter % 10 == 0) {
        if(!isPause){
            eraseGhosts();
            moveGhosts();
            drawGameElements();
        }
        
    }
}
