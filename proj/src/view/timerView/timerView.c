#include <lcom/lcf.h>
#include <stdint.h>
#include "timerView.h"
#include "../../devices/graphics/graphics.h"
#include "../../controller/timerController/timerController.h"
#include "../pixmaps/pixmaps.h"

extern unsigned int mins, secs;

extern uint8_t* num0PM, *num1PM, *num2PM, *num3PM, *num4PM, *num5PM, *num6PM, *num7PM, *num8PM, *num9PM;
extern uint8_t* timerDotsPM;

extern xpm_image_t num0Img, num1Img, num2Img, num3Img, num4Img, num5Img, num6Img, num7Img, num8Img, num9Img;
extern xpm_image_t timerDotsImg;

uint8_t* pm;
xpm_image_t img;

void (getNumPM)(int num) {
    switch (num) {
        case 0:
            pm = num0PM; 
            img = num0Img;
            break;
        case 1: 
            pm = num1PM; 
            img = num1Img;
            break;
        case 2: 
            pm = num2PM; 
            img = num2Img;
            break;
        case 3: 
            pm = num3PM; 
            img = num3Img;
            break;
        case 4:     
            pm = num4PM; 
            img = num4Img;
            break;
        case 5: 
            pm = num5PM; 
            img = num5Img;
            break;
        case 6: 
            pm = num6PM; 
            img = num6Img;
            break;
        case 7: 
            pm = num7PM; 
            img = num7Img;
            break;
        case 8: 
            pm = num8PM; 
            img = num8Img;
            break;
        case 9: 
            pm = num9PM; 
            img = num9Img;
            break;
        default:
            break;
    }
}

void (drawTimer)() {
    getNumPM(mins);
    draw_xpm(pm, img, TIMER_X, TIMER_Y);

    draw_xpm(timerDotsPM, timerDotsImg, TIMER_DIV_X, TIMER_Y);

    getNumPM(secs / 10);
    draw_xpm(pm, img, SECS_LEFT_X, TIMER_Y);

    getNumPM(secs % 10);
    draw_xpm(pm, img, SECS_RIGHT_X, TIMER_Y);
}
