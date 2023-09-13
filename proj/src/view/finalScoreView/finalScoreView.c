#include <lcom/lcf.h>
#include <stdint.h>
#include "finalScoreView.h"
#include "../../devices/graphics/graphics.h"
#include "../pixmaps/pixmaps.h"

extern unsigned int score;
extern uint8_t* num0PM, *num1PM, *num2PM, *num3PM, *num4PM, *num5PM, *num6PM, *num7PM, *num8PM, *num9PM;
extern xpm_image_t num0Img, num1Img, num2Img, num3Img, num4Img, num5Img, num6Img, num7Img, num8Img, num9Img;

uint8_t* pm;
xpm_image_t img;

void (getNumbers)(int num) {
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

void drawFinalScoreNums() {
    int aux = score, numCounter = 0;

    int width = numCounter * NUM_WIDTH;
    int x = ((1024 - width)/2) + width;

    if (aux == 0) {
        getNumbers(0);
        draw_xpm(num0PM, num0Img, x, FINAL_SCORE_Y);
        return;
    }

    while (aux != 0) {
        int num = aux % 10;
        getNumbers(num);
        draw_xpm(pm, img, x - (numCounter * NUM_WIDTH), FINAL_SCORE_Y);
        aux /= 10;
        numCounter++;
    }
}
