#include "Sprite.h"
#include "../memory/Memory.h"

#include <gb/drawing.h>
#include <stdio.h>

void Sprite_create(Sprite* sprite, uint8_t tile_count, uint8_t* image_data)
{
    sprite->image_data = image_data;
    sprite->tile_count = tile_count;
    sprite->tile_position_in_memory = Memory_allocate_and_write_sprite_data(sprite->tile_count, sprite->image_data);
}

void Sprite_setup_for_display(Sprite* sprite)
{
    sprite->hardware_sprite_number = Memory_generate_hardware_sprite_number();
    set_sprite_tile(sprite->hardware_sprite_number, sprite->tile_position_in_memory);
    printf("%u", sprite->hardware_sprite_number);

}

void Sprite_set_frame(Sprite* sprite, uint8_t frame)
{
    set_sprite_tile(sprite->hardware_sprite_number, sprite->tile_position_in_memory + frame);
}

uint8_t Sprite_get_frame(Sprite *sprite) {
    return get_sprite_tile(sprite->hardware_sprite_number);
}

void Sprite_set_position(Sprite* sprite, uint8_t x, uint8_t y)
{
    move_sprite(sprite->hardware_sprite_number, x, y);
}