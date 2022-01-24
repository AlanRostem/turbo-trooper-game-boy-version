#include "Sprite.h"
/*
#ifndef NDEBUG
#include <stdio.h>
#endif
*/

static uint8_t sprites_used = 0;

void Graphics_show_sprites()
{
    SHOW_SPRITES;
}

void Sprite_create(Sprite* sprite, uint8_t* image_data, uint8_t tile_count)
{
    sprite->data = image_data;
    sprite->sprite_number = sprites_used++;
    sprite->tile_count = tile_count;
    /*
#ifndef NDEBUG
    assert(sprite->sprite_number == MAX_HARDWARE_SPRITES);
#endif
    */
}


void Sprite_load(Sprite* sprite)
{
    set_sprite_data(0, sprite->tile_count, sprite->data);
}

void Sprite_set_tile(Sprite* sprite, uint8_t tile)
{
    set_sprite_tile(sprite->sprite_number, tile);
}

void Sprite_set_position(Sprite* sprite, uint8_t x, uint8_t y) 
{
    move_sprite(sprite->sprite_number, x, y);
}