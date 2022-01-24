#include "Sprite.h"
#include <gb/drawing.h>

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

void Sprite_create(Sprite* sprite)
{
    sprite->sprite_number = sprites_used++;
    /*
#ifndef NDEBUG
    assert(sprite->sprite_number == MAX_HARDWARE_SPRITES);
#endif
    */
}


void Sprite_load(Sprite* sprite, uint8_t tile_count, uint8_t* image_data)
{
    set_sprite_data(0, tile_count, image_data);
}

void Sprite_set_tile(Sprite* sprite, uint8_t tile)
{
    set_sprite_tile(sprite->sprite_number, tile);
}

void Sprite_set_position(Sprite* sprite, uint8_t x, uint8_t y) 
{
    move_sprite(sprite->sprite_number, x, y);
}