#pragma once
#include <gb/gb.h>

typedef struct {
    uint8_t* image_data;
    uint8_t tile_count;
    uint8_t tile_position_in_memory;
    uint8_t hardware_sprite_number;
} Sprite;

extern void Sprite_create(Sprite* sprite, uint8_t tile_count, uint8_t* image_data);
extern void Sprite_allocate_on_display(Sprite* sprite);
extern void Sprite_free_from_display(Sprite* sprite);
extern void Sprite_set_frame(Sprite* sprite, uint8_t frame);
extern uint8_t Sprite_get_frame(Sprite* sprite);
extern void Sprite_set_position(Sprite* sprite, uint8_t x, uint8_t y);