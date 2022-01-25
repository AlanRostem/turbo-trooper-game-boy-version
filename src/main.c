#include <gb/gb.h>
#include <gb/drawing.h>

#include "assets/sprites/CrackedStoneTile.h"
#include "graphics/Sprite.h"
#include "graphics/Graphics.h"

const uint8_t FRAME_DELTA = 17;

Sprite cracked_stone_sprite;

int main()
{
    Sprite_create(&cracked_stone_sprite, 0, CrackedStoneTile);
    Sprite_setup_for_display(&cracked_stone_sprite);
    Sprite_set_position(&cracked_stone_sprite, 80, 20);
    Graphics_show_sprites();
    /*while(1) {
        // Sprite_animate(&cr)
        delay(FRAME_DELTA);
    }*/
    return 0;
}