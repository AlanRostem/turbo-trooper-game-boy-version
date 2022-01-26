
#include "assets/sprites/CrackedStoneTile.h"
#include "assets/sprites/BricksSingleTile.h"

#include "graphics/Sprite.h"
#include "graphics/Graphics.h"
#include "memory/Memory.h"

const uint8_t FRAME_DELTA = 17;

SingleSprite cracked_stone_sprite;
SingleSprite bricks_single_sprite;

int main()
{
    SpriteData_create(&cracked_stone_sprite.data, 1, CrackedStoneTile);
    SingleSprite_allocate_on_display(&cracked_stone_sprite);
    SingleSprite_set_position(&cracked_stone_sprite, 10, 80);

    SpriteData_create(&bricks_single_sprite.data, 1, BricksSingleTile);
    SingleSprite_allocate_on_display(&bricks_single_sprite);
    SingleSprite_set_position(&bricks_single_sprite, 40, 80);

    Graphics_show_sprites();
    /*while(1) {
        // Sprite_animate(&cr)
        delay(FRAME_DELTA);
    }*/
    return 0;
}