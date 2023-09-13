#include <lcom/lcf.h>
#include "pacman.h"

Pacman pacman;

void (set_pacman_position)() {
    pacman.position.prev_x = 500;
    pacman.position.next_x = 525;
    pacman.position.up_y = 544;
    pacman.position.down_y = 570;
}