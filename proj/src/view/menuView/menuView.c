#include <lcom/lcf.h>
#include <stdint.h>
#include "menuView.h"
#include "../../devices/graphics/graphics.h"
#include "../../devices/rtc/rtc.h"
#include "../pixmaps/pixmaps.h"
#include "../mouseView/mouseView.h"
#include "../finalScoreView/finalScoreView.h"

extern uint8_t* titlePM, *titleNightPM;
extern uint8_t* playPM, *quitGamePM, *gameDescriptionPM; 
extern uint8_t* goBackPM, *pauseGamePM;
extern uint8_t* winPM, *losePM, *finalScorePM; 

extern uint8_t* rules_description1_pixmap;
extern uint8_t* rules_description2_pixmap;
extern uint8_t* rules_description3_pixmap;
extern uint8_t* rules_description4_pixmap;
extern uint8_t* rules_description5_pixmap;
extern uint8_t* rules_description6_pixmap;


extern xpm_image_t titleImg, titleNightImg;
extern xpm_image_t playImg, quitGameImg, gameDescriptionImg;
extern xpm_image_t goBackImg, pauseGameImg;
extern xpm_image_t winImg, loseImg, finalScoreImg;

extern xpm_image_t rules_description1_info;
extern xpm_image_t rules_description2_info;
extern xpm_image_t rules_description3_info;
extern xpm_image_t rules_description4_info;
extern xpm_image_t rules_description5_info;
extern xpm_image_t rules_description6_info;


void (drawTitle)() {
    draw_xpm(titlePM, titleImg, PACMAN_TEXT_X, PACMAN_TEXT_Y);
}

void (drawTitleNight)() {
    draw_xpm(titleNightPM, titleNightImg, PACMAN_TEXT_X, PACMAN_TEXT_Y);
}

void (drawGameDescription)() {
    draw_xpm(gameDescriptionPM, gameDescriptionImg, RULES_TEXT_X, RULES_TEXT_Y);
}

void (drawPlay)() {
    draw_xpm(playPM, playImg, PLAY_TEXT_X, PLAY_TEXT_Y);
}

void (drawQuitGame)() {
    draw_xpm(quitGamePM, quitGameImg, EXIT_TEXT_X, EXIT_TEXT_Y);
}

void (drawWin)() {
    draw_xpm(winPM, winImg, WIN_TEXT_X, WIN_TEXT_Y);
}

void (drawLose)() {
    draw_xpm(losePM, loseImg, GAME_OVER_TEXT_X, GAME_OVER_TEXT_Y);
}

void (drawFinalScore)() {
    draw_xpm(finalScorePM, finalScoreImg, FINAL_SCORE_TEXT_X, FINAL_SCORE_TEXT_Y);
}

void (drawPauseGame)() {
    draw_xpm(pauseGamePM, pauseGameImg, PAUSE_TEXT_X, PAUSE_TEXT_Y);
}

void (drawMenu)() {
    drawMouse();

    uint8_t currentHour = rtc_get_hour();
    uint8_t nightStartHour = 20;
    uint8_t nightEndHour = 6;
    
    if (currentHour >= nightStartHour || currentHour < nightEndHour) {
        drawTitleNight();
    } else drawTitle();

    drawGameDescription();
    drawPlay();
    drawQuitGame();
}

void (eraseMenu)() {
    draw_rectangle(0, 0, 1024, 768, 0);
}

void (draw_rules_description)() {
    draw_xpm(rules_description1_pixmap, rules_description1_info, RULES_DESCRIPTION1_X, RULES_DESCRIPTION1_Y);
    draw_xpm(rules_description2_pixmap, rules_description2_info, RULES_DESCRIPTION2_X, RULES_DESCRIPTION2_Y);
    draw_xpm(rules_description3_pixmap, rules_description3_info, RULES_DESCRIPTION3_X, RULES_DESCRIPTION3_Y);
    draw_xpm(rules_description4_pixmap, rules_description4_info, RULES_DESCRIPTION4_X, RULES_DESCRIPTION4_Y);
    draw_xpm(rules_description5_pixmap, rules_description5_info, RULES_DESCRIPTION5_X, RULES_DESCRIPTION5_Y);
    draw_xpm(rules_description6_pixmap, rules_description6_info, RULES_DESCRIPTION6_X, RULES_DESCRIPTION6_Y);
    draw_xpm(goBackPM, goBackImg, BACK_TO_MENU_X, BACK_TO_MENU_Y);
}

void (drawYouWon)() {
    eraseMenu();
    drawWin();
    drawFinalScore();
    drawFinalScoreNums();
}

void (drawYouLost)() {
    eraseMenu();
    drawLose();
    drawFinalScore();
    drawFinalScoreNums();
}
