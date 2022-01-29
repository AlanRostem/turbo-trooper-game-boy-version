#include "PlayerEntity.h"
#include "../../../graphics/sprite/MetaSprite.h"
#include "../../../assets/sprites/PlayerTestSprite.h"
#include "../../../util/Util.h"
#include "../../../system/memory/Memory.h"
#include "../../../system/System.h"
#include "../../physics/PhysicsBody.h"

const int16_t PLAYER_WALK_SPEED = 1;
const int16_t PLAYER_JUMP_SPEED = 6;

PhysicsBody player_body = { {{16, 16}, {32, 32}} };

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

void PlayerEntity_create() {
    for (global_for_loop_i = 0; global_for_loop_i < 4; global_for_loop_i++) {
        SpriteAnimation_create(&player_run_animations[global_for_loop_i], 4, player_run_animation_frames[global_for_loop_i]);
    }

    MetaSprite_create(&player_meta_sprite, META_SPRITE_TILE_DIMENSION_16x16, 22, PlayerTestSprite);
    MetaSprite_occupy_display(&player_meta_sprite, player_meta_sprite_numbers);

    MetaSprite_set_position(&player_meta_sprite, player_body.shape.pos.x, player_body.shape.pos.y);
}

void PlayerEntity_process() {
    uint8_t pad = joypad();
    if (pad & J_LEFT) player_body.velocity.x = -PLAYER_WALK_SPEED;
    if (pad & J_RIGHT) player_body.velocity.x = PLAYER_WALK_SPEED;
    if (pad & J_A && player_body.is_on_floor) {
        player_body.velocity.y = -PLAYER_JUMP_SPEED;
    }
    
    PhysicsBody_process_with_gravity(&player_body);
    MetaSprite_set_position(&player_meta_sprite, player_body.shape.pos.x, player_body.shape.pos.y);

    if (player_body.is_on_floor)
       player_body.velocity.x = 0;

    if (has_frame_timer_exceeded_wait_time(&player_test_animation_elapsed_frame_time, 100, PHYSICS_PROCESS_DELTA)) {
        for (global_for_loop_i = 0; global_for_loop_i < 4; global_for_loop_i++) {
            MetaSprite_set_frame(&player_meta_sprite, global_for_loop_i,
                                 SpriteAnimation_get_current_frame(&player_run_animations[global_for_loop_i]));
            SpriteAnimation_loop(&player_run_animations[global_for_loop_i]);
        }
    }
}