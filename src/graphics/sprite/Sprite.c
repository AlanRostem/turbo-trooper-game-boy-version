#include "Sprite.h"
#include "src/memory/Memory.h"

#include <gb/drawing.h>

void SpriteAnimation_create(SpriteAnimation *animation, uint8_t frame_count, uint8_t *frames_buffer) {
    animation->frame_count = frame_count;
    animation->frames_buffer_ref = frames_buffer;
}

void SpriteAnimation_loop(SpriteAnimation *animation) {
    animation->current_frame_index++;
    animation->current_frame_index %= animation->frame_count;
}

uint8_t SpriteAnimation_get_current_frame(SpriteAnimation* animation) {
    return animation->frames_buffer_ref[animation->current_frame_index];
}

void SpriteData_create(SpriteData* data, uint8_t tile_count, uint8_t* image_data) {
    data->image_data_ref = image_data;
    data->tile_count = tile_count;
    data->vram_tile_position = Memory_allocate_and_write_sprite_data(data->tile_count, data->image_data_ref);
}

void SingleSprite_create(SingleSprite *sprite, uint8_t tile_count, uint8_t *image_data) {
    SpriteData_create(&sprite->data, tile_count, image_data);
}

void SingleSprite_occupy_display(SingleSprite *sprite) {
    sprite->hardware_sprite_number = Memory_generate_hardware_sprite_number();
    set_sprite_tile(sprite->hardware_sprite_number, sprite->data.vram_tile_position);
}

void SingleSprite_free_from_display(SingleSprite *sprite) {
    Memory_free_hardware_sprite_number(sprite->hardware_sprite_number);
}

void SingleSprite_set_frame(SingleSprite *sprite, uint8_t frame) {
    set_sprite_tile(sprite->hardware_sprite_number, sprite->data.vram_tile_position + frame);
}

uint8_t SingleSprite_get_frame(SingleSprite *sprite) {
    return get_sprite_tile(sprite->hardware_sprite_number);
}

void SingleSprite_set_position(SingleSprite *sprite, uint8_t x, uint8_t y) {
    move_sprite(sprite->hardware_sprite_number, x, y);
}

