#pragma once
#include <gb/gb.h>

typedef enum {
    SPRITE_PROP_BIT_H_FLIP = 5,
    SPRITE_PROP_BIT_V_FLIP = 6,
    SPRITE_PROP_BIT_DRAW_BEHIND_BG = 7,
} SpritePropBit;

typedef struct {
    uint8_t* frames_buffer_ref;
    uint8_t frame_count;
    uint8_t current_frame_index;
} SpriteAnimation;

extern void SpriteAnimation_create(SpriteAnimation* animation, uint8_t frame_count, uint8_t* frames_buffer);
extern void SpriteAnimation_loop(SpriteAnimation* animation);
extern uint8_t SpriteAnimation_get_current_frame(SpriteAnimation* animation);

// Keep track of where a sprite is in vram
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
extern void SingleSprite_occupy_display(SingleSprite *sprite);
extern void SingleSprite_free_from_display(SingleSprite *sprite);
extern void SingleSprite_set_frame(SingleSprite *sprite, uint8_t frame);
extern uint8_t SingleSprite_get_frame(SingleSprite *sprite);
extern void SingleSprite_set_position(SingleSprite *sprite, uint8_t x, uint8_t y);