#include "assets/sprites/CrackedStoneTile.h"
#include "assets/sprites/BricksSingleTile.h"
#include "assets/sprites/PlayerTestSprite.h"

#include "src/graphics/sprite/Sprite.h"
#include "src/graphics/sprite/MetaSprite.h"
#include "graphics/Graphics.h"
#include "util/Util.h"
#include "game/physics/PhysicsWorld.h"

SingleSprite cracked_stone_sprite;
SingleSprite bricks_single_sprite;

MetaSprite player_meta_sprite;
uint8_t player_meta_sprite_numbers[4];

uint8_t player_run_animation_frames[4][4] = {
    {8, 8, 10, 8},
    {9, 9, 11, 9},
    {12, 14, 16, 18},
    { 13, 15, 17, 19},
};

SpriteAnimation player_run_animations[4];
uint16_t player_test_animation_elapsed_frame_time = 0;

int main() {
    SingleSprite_create(&cracked_stone_sprite, 1, CrackedStoneTile);
    SingleSprite_occupy_display(&cracked_stone_sprite);
    SingleSprite_set_position(&cracked_stone_sprite, 10, 80);

    SingleSprite_create(&bricks_single_sprite, 1, BricksSingleTile);
    SingleSprite_occupy_display(&bricks_single_sprite);
    SingleSprite_set_position(&bricks_single_sprite, 40, 80);

    static uint8_t i;
    for (i = 0; i < 4; i++) {
        SpriteAnimation_create(&player_run_animations[i], 4, player_run_animation_frames[i]);
    }

    MetaSprite_create(&player_meta_sprite, META_SPRITE_TILE_DIMENSION_16x16, 22, PlayerTestSprite);
    MetaSprite_occupy_display(&player_meta_sprite, player_meta_sprite_numbers);
    MetaSprite_set_flipped(&player_meta_sprite, TRUE);
    MetaSprite_set_position_flipped_h(&player_meta_sprite, 32, 20);

    Graphics_show_sprites();
    while(1) {
        if (has_frame_timer_exceeded_wait_time(&player_test_animation_elapsed_frame_time, 100, PHYSICS_FRAME_DELTA)) {
            for (i = 0; i < 4; i++) {
                MetaSprite_set_frame(&player_meta_sprite, i,
                                     SpriteAnimation_get_current_frame(&player_run_animations[i]));
                SpriteAnimation_loop(&player_run_animations[i]);
            }
        }

        switch (joypad()) {
            case J_START:
                return 0;
        }

        delay(PHYSICS_FRAME_DELTA);
    }
    return 0;
}