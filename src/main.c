
#include "assets/sprites/CrackedStoneTile.h"
#include "assets/sprites/BricksSingleTile.h"

#include "graphics/Sprite.h"
#include "graphics/Graphics.h"

const uint8_t FRAME_DELTA = 17;

Sprite cracked_stone_sprite;
Sprite bricks_single_sprite;

int main()
{
    Sprite_create(&cracked_stone_sprite, 1, CrackedStoneTile);
    Sprite_setup_for_display(&cracked_stone_sprite);
    Sprite_set_position(&cracked_stone_sprite, 10, 80);

    Sprite_create(&bricks_single_sprite, 1, BricksSingleTile);
    Sprite_setup_for_display(&bricks_single_sprite);
    Sprite_set_position(&bricks_single_sprite, 40, 80);

    Graphics_show_sprites();
    /*while(1) {
        // Sprite_animate(&cr)
        delay(FRAME_DELTA);
    }*/
    return 0;
}