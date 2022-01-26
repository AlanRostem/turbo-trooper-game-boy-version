
#include "assets/sprites/CrackedStoneTile.h"
#include "assets/sprites/BricksSingleTile.h"
#include "assets/sprites/PlayerTestSprite.h"

#include "src/graphics/sprite/Sprite.h"
#include "src/graphics/sprite/MetaSprite.h"
#include "graphics/Graphics.h"

const uint8_t FRAME_DELTA = 17;

SingleSprite cracked_stone_sprite;
SingleSprite bricks_single_sprite;

MetaSprite player_meta_sprite;
uint8_t player_meta_sprite_numbers[4];

int main()
{
    SingleSprite_create(&cracked_stone_sprite, 1, CrackedStoneTile);
    SingleSprite_allocate_on_display(&cracked_stone_sprite);
    SingleSprite_set_position(&cracked_stone_sprite, 10, 80);

    SingleSprite_create(&bricks_single_sprite, 1, BricksSingleTile);
    SingleSprite_allocate_on_display(&bricks_single_sprite);
    SingleSprite_set_position(&bricks_single_sprite, 40, 80);

    MetaSprite_create(&player_meta_sprite, META_SPRITE_TILE_DIMENSION_16x16, 4, PlayerTestSprite);
    MetaSprite_allocate_on_display(&player_meta_sprite, player_meta_sprite_numbers);
    MetaSprite_set_position(&player_meta_sprite, 32, 20);

    Graphics_show_sprites();
    /*while(1) {
        // Sprite_animate(&cr)
        delay(FRAME_DELTA);
    }*/
    return 0;
}