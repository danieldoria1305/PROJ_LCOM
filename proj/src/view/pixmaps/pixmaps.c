#include <lcom/lcf.h>
#include <stdint.h>

#include "../wallsView/wallsView.h"
#include "../pacmanView/pacmanView.h"
#include "../ghostsView/ghostsView.h"
#include "../coinsView/coinsView.h"
#include "../timerView/timerView.h"
#include "../scoreView/scoreView.h"

#include "../assets/pacman/pacmanRight.xpm"
#include "../assets/pacman/pacmanLeft.xpm"
#include "../assets/pacman/pacmanUp.xpm"
#include "../assets/pacman/pacmanDown.xpm"

#include "../assets/ghosts/redGhost.xpm"
#include "../assets/ghosts/orangeGhost.xpm"
#include "../assets/ghosts/pinkGhost.xpm"
#include "../assets/ghosts/blueGhost.xpm"

#include "../assets/numbers/num0.xpm"
#include "../assets/numbers/num1.xpm"
#include "../assets/numbers/num2.xpm"
#include "../assets/numbers/num3.xpm"
#include "../assets/numbers/num4.xpm"
#include "../assets/numbers/num5.xpm"
#include "../assets/numbers/num6.xpm"
#include "../assets/numbers/num7.xpm"
#include "../assets/numbers/num8.xpm"
#include "../assets/numbers/num9.xpm"

#include "../assets/text/title.xpm"
#include "../assets/text/titleNight.xpm"
#include "../assets/text/play.xpm"
#include "../assets/text/gameDescription.xpm"
#include "../assets/text/quitGame.xpm"
#include "../assets/text/win.xpm"
#include "../assets/text/finalScore.xpm"
#include "../assets/text/lose.xpm"
#include "../assets/text/pauseGame.xpm"
#include "../assets/text/score.xpm"
#include "../assets/text/rules_description1.xpm"
#include "../assets/text/rules_description2.xpm"
#include "../assets/text/rules_description3.xpm"
#include "../assets/text/rules_description4.xpm"
#include "../assets/text/rules_description5.xpm"
#include "../assets/text/rules_description6.xpm"
#include "../assets/text/goBack.xpm"

#include "../assets/coin.xpm"
#include "../assets/energizer.xpm"

#include "../assets/timerDots.xpm"
#include "../assets/mouse.xpm"
#include "../assets/walls.xpm"

uint8_t* pacmanLeftPM, *pacmanRightPM, *pacmanUpPM, *pacmanDownPM;
uint8_t* redGhostPM, *orangeGhostPM, *pinkGhostPM, *blueGhostPM;
uint8_t* coinPM, *energizerPM;
uint8_t* num0PM, *num1PM, *num2PM, *num3PM, *num4PM, *num5PM, *num6PM, *num7PM, *num8PM, *num9PM;
uint8_t* wallsPM, *mousePM, *timerDotsPM, *scorePM;
uint8_t* titlePM, *titleNightPM, *descriptionPM, *goBackPM, *playPM, *gameDescriptionPM, *winPM, *losePM, *finalScorePM, *quitGamePM, *pauseGamePM;
uint8_t* rules_description1_pixmap;
uint8_t* rules_description2_pixmap;
uint8_t* rules_description3_pixmap;
uint8_t* rules_description4_pixmap;
uint8_t* rules_description5_pixmap;
uint8_t* rules_description6_pixmap;

xpm_image_t pacmanLeftImg, pacmanRightImg, pacmanUpImg, pacmanDownImg;
xpm_image_t redGhostImg, orangeGhostImg, pinkGhostImg, blueGhostImg;
xpm_image_t coinImg, energizerImg;
xpm_image_t num0Img, num1Img, num2Img, num3Img, num4Img, num5Img, num6Img, num7Img, num8Img, num9Img;
xpm_image_t wallsImg, mouseImg, timerDotsImg, scoreImg;
xpm_image_t titleImg, titleNightImg, goBackImg, playImg, gameDescriptionImg, winImg, loseImg, finalScoreImg, quitGameImg, pauseGameImg;
xpm_image_t rules_description1_info;
xpm_image_t rules_description2_info;
xpm_image_t rules_description3_info;
xpm_image_t rules_description4_info;
xpm_image_t rules_description5_info;
xpm_image_t rules_description6_info;

void (loadPM)() {
    
    pacmanLeftPM = xpm_load(pacmanLeft, XPM_INDEXED, &pacmanLeftImg);
    pacmanRightPM = xpm_load(pacmanRight, XPM_INDEXED, &pacmanRightImg);
    pacmanUpPM = xpm_load(pacmanUp, XPM_INDEXED, &pacmanUpImg);
    pacmanDownPM = xpm_load(pacmanDown, XPM_INDEXED, &pacmanDownImg);

    redGhostPM = xpm_load(redGhost, XPM_INDEXED, &redGhostImg);
    orangeGhostPM = xpm_load(orangeGhost, XPM_INDEXED, &orangeGhostImg);
    pinkGhostPM = xpm_load(pinkGhost, XPM_INDEXED, &pinkGhostImg);
    blueGhostPM = xpm_load(blueGhost, XPM_INDEXED, &blueGhostImg);

    coinPM = xpm_load(coin, XPM_INDEXED, &coinImg);
    energizerPM = xpm_load(energizer, XPM_INDEXED, &energizerImg);

    num0PM = xpm_load(num0, XPM_INDEXED, &num0Img);
    num1PM = xpm_load(num1, XPM_INDEXED, &num1Img);
    num2PM = xpm_load(num2, XPM_INDEXED, &num2Img);
    num3PM = xpm_load(num3, XPM_INDEXED, &num3Img);
    num4PM = xpm_load(num4, XPM_INDEXED, &num4Img);
    num5PM = xpm_load(num5, XPM_INDEXED, &num5Img);
    num6PM = xpm_load(num6, XPM_INDEXED, &num6Img);
    num7PM = xpm_load(num7, XPM_INDEXED, &num7Img);
    num8PM = xpm_load(num8, XPM_INDEXED, &num8Img);
    num9PM = xpm_load(num9, XPM_INDEXED, &num9Img);

    wallsPM = xpm_load(walls, XPM_INDEXED, &wallsImg);
    mousePM = xpm_load(mouse, XPM_INDEXED, &mouseImg);
    timerDotsPM = xpm_load(timerDots, XPM_INDEXED, &timerDotsImg);
    scorePM = xpm_load(score, XPM_INDEXED, &scoreImg);

    titlePM = xpm_load(title, XPM_INDEXED, &titleImg);
    titleNightPM = xpm_load(titleNight, XPM_INDEXED, &titleNightImg);
    goBackPM = xpm_load(goBack, XPM_INDEXED, &goBackImg);
    playPM = xpm_load(play, XPM_INDEXED, &playImg);
    gameDescriptionPM = xpm_load(gameDescription, XPM_INDEXED, &gameDescriptionImg);
    quitGamePM = xpm_load(quitGame, XPM_INDEXED, &quitGameImg);
    winPM = xpm_load(win, XPM_INDEXED, &winImg);
    losePM = xpm_load(lose, XPM_INDEXED, &loseImg);
    finalScorePM = xpm_load(finalScore, XPM_INDEXED, &finalScoreImg);
    pauseGamePM = xpm_load(pauseGame, XPM_INDEXED, &pauseGameImg);

    rules_description1_pixmap = xpm_load(rules_description1, XPM_INDEXED, &rules_description1_info);
    rules_description2_pixmap = xpm_load(rules_description2, XPM_INDEXED, &rules_description2_info);    
    rules_description3_pixmap = xpm_load(rules_description3, XPM_INDEXED, &rules_description3_info);
    rules_description4_pixmap = xpm_load(rules_description4, XPM_INDEXED, &rules_description4_info);
    rules_description5_pixmap = xpm_load(rules_description5, XPM_INDEXED, &rules_description5_info);
    rules_description6_pixmap = xpm_load(rules_description6, XPM_INDEXED, &rules_description6_info);
}

void (drawGameElements)() {
    drawWalls();
    drawPacman();
    drawGhosts();
    drawScoreNums();
    drawScore();
    drawTimer();
    drawCoins();
    drawEnergizers();
}
