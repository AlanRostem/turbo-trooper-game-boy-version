#include "MetaSprite.h"
#include "../memory/Memory.h"
#include <stdio.h>

void MetaSprite_create(MetaSprite *sprite, MetaSpriteTileDimensions tile_dimensions, uint8_t tile_count, uint8_t *image_data) {
    SpriteData_create(&sprite->data, tile_count, image_data);
    sprite->tile_dimensions = tile_dimensions;
}

void MetaSprite_allocate_on_display(MetaSprite *sprite, uint8_t *hardware_sprite_number_buffer) {
    sprite->hardware_sprite_number_buffer_ref = hardware_sprite_number_buffer;
    for (uint8_t i = 0; i < sprite->tile_dimensions * sprite->tile_dimensions; i++) {
        sprite->hardware_sprite_number_buffer_ref[i] = Memory_generate_hardware_sprite_number();
        set_sprite_tile(sprite->hardware_sprite_number_buffer_ref[i], sprite->data.vram_tile_position + i);
    }
}

void MetaSprite_free_from_display(MetaSprite *sprite) {
    for (uint8_t i = 0; i < sprite->tile_dimensions * sprite->tile_dimensions; i++) {
        Memory_free_hardware_sprite_number(sprite->hardware_sprite_number_buffer_ref[i]);
        sprite->hardware_sprite_number_buffer_ref[i] = MAX_HARDWARE_SPRITES;
    }
}

void MetaSprite_set_position(MetaSprite *sprite, uint8_t x, uint8_t y) {
    const uint8_t SPRITE_SIZE = 8; //TODO: Remove it and place it in a more global def. This is just temporary
    for (uint8_t i = 0; i < sprite->tile_dimensions * sprite->tile_dimensions; i++) {
        move_sprite(sprite->hardware_sprite_number_buffer_ref[i],
                    x + (i % sprite->tile_dimensions) * SPRITE_SIZE,
                    y + (i / sprite->tile_dimensions) * SPRITE_SIZE);
    }
}