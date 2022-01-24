#include "Sprite.h"
#include "MetaSprite16x16.h"
#include "Graphics.h"

#include <gb/drawing.h>

/*
#ifndef NDEBUG
#include <stdio.h>
#endif
*/

void Sprite_create(Sprite* sprite, uint8_t tile_count)
{
    sprite->sprite_number = Graphics_generate_sprite_number();
    sprite->tile_count = tile_count;
}


void Sprite_load(Sprite* sprite, uint8_t* image_data)
{
    set_sprite_data(0, sprite->tile_count, image_data);
}

void Sprite_set_tile(Sprite* sprite, uint8_t tile)
{
    set_sprite_tile(sprite->sprite_number, tile);
}

void Sprite_set_position(Sprite* sprite, uint8_t x, uint8_t y) 
{
    move_sprite(sprite->sprite_number, x, y);
}
