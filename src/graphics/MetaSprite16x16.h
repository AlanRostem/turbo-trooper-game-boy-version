#pragma once
#include <gb/gb.h>

typedef struct {
    uint8_t sprite_numbers[4];
} MetaSprite16x16;

extern void MetaSprite16x16_create(MetaSprite16x16* sprite);
extern void MetaSprite16x16_load(MetaSprite16x16* sprite, uint8_t* image_data);
// extern void MetaSprite16x16_set_tile(MetaSprite16x16* sprite, uint8_t tile);
// extern void MetaSprite16x16_set_position(MetaSprite16x16* sprite, uint8_t x, uint8_t y);