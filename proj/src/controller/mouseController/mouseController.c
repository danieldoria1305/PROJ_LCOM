#include <lcom/lcf.h>
#include <stdint.h>
#include "mouseController.h"
#include "../../devices/kbc/mouse/mouse.h"
#include "../../devices/graphics/graphics.h"
#include "../../view/mouseView/mouseView.h"
#include "../../view/menuView/menuView.h"
#include "../gameController/gameController.h"

int x = 0, y = 0;

extern int packet_index;
extern uint8_t mouse_bytes[3];
extern xpm_image_t mouseImg;

extern bool isMenu, isGame, isRules, end;

void clickRules(bool clicked) {
    if (x >= RULES_TEXT_X && x < RULES_TEXT_X + RULES_TEXT_WIDTH && y >= RULES_TEXT_Y && y < RULES_TEXT_Y + RULES_TEXT_HEIGHT) {
        if (clicked) {
            isRules = true;
            draw_rectangle(0, 0, 1024, 768, 0);
            draw_rules_description();
        }
        else drawGameDescription();
    }
}

void clickPlay(bool clicked) {
    if (x >= PLAY_TEXT_X && x < PLAY_TEXT_X + PLAY_TEXT_WIDTH && y >= PLAY_TEXT_Y && y < PLAY_TEXT_Y + PLAY_TEXT_HEIGHT) {
        if (clicked) {
            isMenu = false;
            isGame = true;
        }
        else drawPlay();
    }
}

void clickExit(bool clicked) {
    if (x >= EXIT_TEXT_X && x < EXIT_TEXT_X + EXIT_TEXT_WIDTH && y >= EXIT_TEXT_Y && y < EXIT_TEXT_Y + EXIT_TEXT_HEIGHT) {
        if (clicked) {
            end = true;
            isMenu = false;
            isGame = false;
        }
        else drawQuitGame();
    }
}

void clickBackToMenu(bool clicked) {
    if (x >= BACK_TO_MENU_X && x < BACK_TO_MENU_X + BACK_TO_MENU_WIDTH && y >= BACK_TO_MENU_Y && y < BACK_TO_MENU_Y + BACK_TO_MENU_HEIGHT) {
        if (clicked) {
            isRules = false;
            draw_rectangle(0, 0, 1024, 768, 0);
            drawMenu();
        }
        else draw_rules_description();
    }
}

void (clickCheck)(bool clicked) {
    if(!isRules){
        drawTitle();
        clickRules(clicked);
        clickPlay(clicked);
        clickExit(clicked);
    }
    else {
        draw_rules_description();
        clickBackToMenu(clicked);
    }
}

void (mousePosition)(struct packet pp) {
    draw_rectangle(x, y, mouseImg.width, mouseImg.height, 0);

    if ((x + pp.delta_x) < 0) x = 0;
    else if ((x + mouseImg.width + pp.delta_x) > MENU_WIDTH) x = MENU_WIDTH - mouseImg.width;
    else x += pp.delta_x;

    if ((y - pp.delta_y) < 0) y = 0;
    else if ((y + mouseImg.height - pp.delta_y) > MENU_HEIGHT) y = MENU_HEIGHT - mouseImg.height;
    else y -= pp.delta_y;

    clickCheck(pp.lb);
    drawMouse();
}

void (mouseInterruptHandler)() {
    mouse_int_handler();
    if (packet_index == 3) {
        struct packet pp;
        parse_mouse_packet(&pp);
        mousePosition(pp);
        packet_index = 0;
    }        
}
