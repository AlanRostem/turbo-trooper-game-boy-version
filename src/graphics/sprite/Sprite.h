#pragma once
#include <gb/gb.h>

typedef struct {
    uint8_t start_frame;
    uint8_t end_frame;
    uint16_t frame_time_ms;
} SpriteAnimation;

// This is mainly for re-usability among other types of sprites
typedef struct {
    uint8_t* image_data_ref;
    uint8_t tile_count;
    uint8_t vram_tile_position;
} SpriteData;

extern void SpriteData_create(SpriteData* data, uint8_t tile_count, uint8_t* image_data);

typedef struct {
    SpriteData data;
    uint8_t hardware_sprite_number;
} SingleSprite;

extern void SingleSprite_create(SingleSprite * sprite, uint8_t tile_count, uint8_t* image_data);
extern void SingleSprite_allocate_on_display(SingleSprite *sprite);
extern void SingleSprite_free_from_display(SingleSprite *sprite);
extern void SingleSprite_set_frame(SingleSprite *sprite, uint8_t frame);
extern uint8_t SingleSprite_get_frame(SingleSprite *sprite);
extern void SingleSprite_set_position(SingleSprite *sprite, uint8_t x, uint8_t y);