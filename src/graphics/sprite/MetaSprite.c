#include "MetaSprite.h"
#include "../../system/memory/Memory.h"
#include "src/util/TypeDefs.h"
#include "src/util/Util.h"

const uint8_t SPRITE_SIZE = 8;

void MetaSprite_create(MetaSprite *sprite, MetaSpriteTileDimensions tile_dimensions, uint8_t tile_count, uint8_t *image_data) {
    SpriteData_create(&sprite->data, tile_count, image_data);
    sprite->tile_dimensions = tile_dimensions;
}

void MetaSprite_occupy_display(MetaSprite *sprite, uint8_t *hardware_sprite_number_buffer) {
    sprite->hardware_sprite_number_buffer_ref = hardware_sprite_number_buffer;
    for (global_for_loop_i = 0; global_for_loop_i < sprite->tile_dimensions * sprite->tile_dimensions; global_for_loop_i++) {
        sprite->hardware_sprite_number_buffer_ref[global_for_loop_i] = Memory_generate_hardware_sprite_number();
        set_sprite_tile(sprite->hardware_sprite_number_buffer_ref[global_for_loop_i], sprite->data.vram_tile_position + global_for_loop_i);
    }
}

void MetaSprite_free_from_display(MetaSprite *sprite) {
    for (global_for_loop_i = 0; global_for_loop_i < sprite->tile_dimensions * sprite->tile_dimensions; global_for_loop_i++) {
        Memory_free_hardware_sprite_number(sprite->hardware_sprite_number_buffer_ref[global_for_loop_i]);
        sprite->hardware_sprite_number_buffer_ref[global_for_loop_i] = MAX_HARDWARE_SPRITES;
    }
}

void MetaSprite_set_position(MetaSprite *sprite, uint8_t x, uint8_t y) {
    for (global_for_loop_i = 0; global_for_loop_i < sprite->tile_dimensions * sprite->tile_dimensions; global_for_loop_i++) {
        move_sprite(sprite->hardware_sprite_number_buffer_ref[global_for_loop_i],
                    x + (global_for_loop_i % sprite->tile_dimensions) * SPRITE_SIZE,
                    y + (global_for_loop_i / sprite->tile_dimensions) * SPRITE_SIZE);
    }
}

void MetaSprite_set_position_flipped_h(MetaSprite *sprite, uint8_t x, uint8_t y) {
    for (global_for_loop_i = 0; global_for_loop_i < sprite->tile_dimensions * sprite->tile_dimensions; global_for_loop_i++) {
        move_sprite(sprite->hardware_sprite_number_buffer_ref[global_for_loop_i],
                    x + (sprite->tile_dimensions - 1 - (global_for_loop_i % sprite->tile_dimensions)) * SPRITE_SIZE,
                    y + (global_for_loop_i / sprite->tile_dimensions) * SPRITE_SIZE);
    }
}

void MetaSprite_set_frame(MetaSprite *sprite, uint8_t relative_sprite_number, uint8_t frame) {
    set_sprite_tile(sprite->hardware_sprite_number_buffer_ref[relative_sprite_number], sprite->data.vram_tile_position + frame);
}

void MetaSprite_set_flipped(MetaSprite *sprite, bool_t flag) {
    for (global_for_loop_i = 0; global_for_loop_i < sprite->tile_dimensions * sprite->tile_dimensions; global_for_loop_i++) {
        set_sprite_prop(
                sprite->data.vram_tile_position + global_for_loop_i,
                uint8_set_bit(
                        get_sprite_prop(sprite->data.vram_tile_position + global_for_loop_i), SPRITE_PROP_BIT_H_FLIP, flag));
    }
}

void MetaSprite_scroll(MetaSprite *sprite, int8_t dx, int8_t dy) {
    for (global_for_loop_i = 0; global_for_loop_i < sprite->tile_dimensions * sprite->tile_dimensions; global_for_loop_i++) {
        scroll_sprite(sprite->hardware_sprite_number_buffer_ref[global_for_loop_i],dx,dy);
    }
}