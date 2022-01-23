#include <gb/gb.h>
#include <gb/drawing.h>

#include "assets/sprites/CrackedStoneTile.h"

const uint8_t SCREEN_WIDTH = 160u;
const uint8_t SCREEN_HEIGHT = 144u;

void main(){
    set_sprite_data(0, 0, CrackedStoneTile);
    set_sprite_tile(0, 0);
    move_sprite(0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    SHOW_SPRITES;
}