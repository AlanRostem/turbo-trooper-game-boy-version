#pragma once
#include <gb/gb.h>

typedef struct {
    uint8_t* data;
    uint8_t sprite_number;
    uint8_t tile_count;
} Sprite;

extern void Graphics_show_sprites();

extern void Sprite_create(Sprite* sprite, uint8_t* image_data, uint8_t tile_count);
extern void Sprite_load(Sprite* sprite);
extern void Sprite_set_tile(Sprite* sprite, uint8_t tile);
extern void Sprite_set_position(Sprite* sprite, uint8_t x, uint8_t y);