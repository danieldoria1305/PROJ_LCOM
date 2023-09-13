#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#define MENU_WIDTH 1023
#define MENU_HEIGHT 767

#define PACMAN_TEXT_X 244
#define PACMAN_TEXT_Y 100
#define PACMAN_TEXT_WIDTH 536
#define PACMAN_TEXT_HEIGHT 100

#define RULES_TEXT_X 366
#define RULES_TEXT_Y 276
#define RULES_TEXT_WIDTH 292
#define RULES_TEXT_HEIGHT 80

#define PLAY_TEXT_X 389
#define PLAY_TEXT_Y 432
#define PLAY_TEXT_WIDTH 246
#define PLAY_TEXT_HEIGHT 80

#define EXIT_TEXT_X 392
#define EXIT_TEXT_Y 588
#define EXIT_TEXT_WIDTH 240
#define EXIT_TEXT_HEIGHT 80

#define WIN_TEXT_X 401
#define WIN_TEXT_Y 100

#define GAME_OVER_TEXT_X 191
#define GAME_OVER_TEXT_Y 100

#define FINAL_SCORE_TEXT_X 339
#define FINAL_SCORE_TEXT_Y 300

#define PAUSE_TEXT_X 355
#define PAUSE_TEXT_Y 344

#define RULES_DESCRIPTION1_X 65
#define RULES_DESCRIPTION1_Y 65
#define RULES_DESCRIPTION2_X 65
#define RULES_DESCRIPTION2_Y 165
#define RULES_DESCRIPTION3_X 65
#define RULES_DESCRIPTION3_Y 265
#define RULES_DESCRIPTION4_X 65
#define RULES_DESCRIPTION4_Y 365
#define RULES_DESCRIPTION5_X 65
#define RULES_DESCRIPTION5_Y 465
#define RULES_DESCRIPTION6_X 65
#define RULES_DESCRIPTION6_Y 565

#define RULES_DESCRIPTION1_WIDTH 700
#define RULES_DESCRIPTION1_HEIGHT 21
#define RULES_DESCRIPTION2_WIDTH 700
#define RULES_DESCRIPTION2_HEIGHT 29
#define RULES_DESCRIPTION3_WIDTH 700
#define RULES_DESCRIPTION3_HEIGHT 23
#define RULES_DESCRIPTION4_WIDTH 326
#define RULES_DESCRIPTION4_HEIGHT 20
#define RULES_DESCRIPTION5_WIDTH 600
#define RULES_DESCRIPTION5_HEIGHT 23
#define RULES_DESCRIPTION6_WIDTH 230
#define RULES_DESCRIPTION6_HEIGHT 22

#define BACK_TO_MENU_X 65
#define BACK_TO_MENU_Y 665
#define BACK_TO_MENU_WIDTH 180
#define BACK_TO_MENU_HEIGHT 22

/// @brief Draws "PACMAN" in the main menu.
void (drawTitle)();


/// @brief Draws "PACMAN" title in the main menu, in "dark mode".
void (drawTitleNight)();

/// @brief Draws "RULES" in the main menu.
void (drawGameDescription)();

/// @brief Draws "PLAY" in the main menu.
void (drawPlay)();

/// @brief Draws "QUIT" in the main menu.
void (drawQuitGame)();

/// @brief Draws "YOU WIN" when the game ends.
void (drawWin)();

/// @brief Draws "YOU LOSE" when the game ends.
void (drawLose)();

/// @brief Draws "FINAL SCORE" when the game ends.
void (drawFinalScore)();

/// @brief Draws "PAUSE" when the game is paused.
void (drawPauseGame)();

/// @brief Draws all the main menu's elements.
void (drawMenu)();

/// @brief Draws a black rectangle over the main menu.
void (eraseMenu)();

/// @brief Draws the game instructions.
void (draw_rules_description)();

/// @brief Draws the win screen.
void (drawYouWon)();

/// @brief Draws the lose screen.
void (drawYouLost)();

#endif
