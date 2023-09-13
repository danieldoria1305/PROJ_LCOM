#include <lcom/lcf.h>
#include "ghosts.h"

Ghost ghosts[4];

void (set_blueghost_position)() {
    ghosts[0].position.prev_x = 440;
    ghosts[0].position.next_x = 465;
    ghosts[0].position.up_y = 360;
    ghosts[0].position.down_y = 335;
}

void (set_redghost_position)() {
    ghosts[1].position.prev_x = 500;
    ghosts[1].position.next_x = 525;
    ghosts[1].position.up_y = 310;
    ghosts[1].position.down_y = 330;
}

void (set_pinkghost_position)() {
    ghosts[2].position.prev_x = 500;
    ghosts[2].position.next_x = 525;
    ghosts[2].position.up_y = 360;
    ghosts[2].position.down_y = 335;
}

void (set_orangeghost_position)() {
    ghosts[3].position.prev_x = 560;
    ghosts[3].position.next_x = 285;
    ghosts[3].position.up_y = 360;
    ghosts[3].position.down_y = 335;
}

void (set_ghosts_positions)() {
    set_blueghost_position();
    set_redghost_position();
    set_pinkghost_position();
    set_orangeghost_position();
}