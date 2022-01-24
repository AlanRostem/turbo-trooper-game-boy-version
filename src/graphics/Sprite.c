#include "Sprite.h"
#include "../Memory/Memory.h"

#include <gb/drawing.h>

/*
#ifndef NDEBUG
#include <stdio.h>
#endif
*/

void Sprite_create(Sprite* sprite, uint8_t tile_count, uint8_t* image_data)
{
    sprite->tile_count = tile_count;
    sprite->image_data = image_data;
}


void Sprite_load(Sprite* sprite)
{
    sprite->hardware_sprite_number = Memory_generate_hardware_sprite_number();
    sprite->memory_position = Memory_allocate_and_write_sprite_data(sprite->tile_count, sprite->image_data);
}

void Sprite_set_tile(Sprite* sprite, uint8_t tile)
{
    set_sprite_tile(sprite->hardware_sprite_number, tile);
}

void Sprite_set_position(Sprite* sprite, uint8_t x, uint8_t y) 
{
    move_sprite(sprite->hardware_sprite_number, x, y);
}
