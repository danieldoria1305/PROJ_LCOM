#ifndef TIMER_VIEW_H
#define TIMER_VIEW_H

#define TIMER_WIDTH 88
#define TIMER_HEIGHT 25

#define TIMER_Y 20
#define TIMER_X 890
#define TIMER_DIV_X 912
#define SECS_LEFT_X 934
#define SECS_RIGHT_X 956

/// @brief Gets the xpm of the number passed as argument.
/// @param num The number to be converted to xpm.
void (getNumPM)(int num);

/// @brief Draws the timer.
void (drawTimer)();

#endif
