#ifndef SCORE_VIEW_H
#define SCORE_VIEW_H

#define SCORE_Y 50
#define SCORE_X 115

#define SCORE_TEXT_Y 20
#define SCORE_TEXT_X 30

#define NUM_WIDTH 25

/// @brief Gets the xpm of the number passed as argument.
/// @param num The number to be converted to xpm.
void (getNum)(int num);

/// @brief Draws the user's score.
void (drawScoreNums)();

/// @brief Draws the "Score:" image.
void (drawScore)();

#endif
