#include <gb/gb.h>
#include <stdio.h>

#include "include/assets/sprites/TestTile.h"

int main()
{
    set_sprite_data(0, 1, Assets_TestTile);
    set_sprite_tile(0, 0);
    move_sprite(0, 88, 78);
    SHOW_SPRITES;
    return 0;
}