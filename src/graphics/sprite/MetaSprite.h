#pragma once
#include <gb/gb.h>
#include "Sprite.h"
#include "src/util/TypeDefs.h"

typedef enum  {
    META_SPRITE_TILE_DIMENSION_16x16 = 2,
    META_SPRITE_TILE_DIMENSION_24x24 = 3,
    META_SPRITE_TILE_DIMENSION_32x32 = 4,
} MetaSpriteTileDimensions;

typedef struct {
    SpriteData data;
    uint8_t* hardware_sprite_number_buffer_ref;
    MetaSpriteTileDimensions tile_dimensions;
} MetaSprite;

extern void MetaSprite_create(MetaSprite *sprite, MetaSpriteTileDimensions tile_dimensions, uint8_t tile_count, uint8_t *image_data);
extern void MetaSprite_occupy_display(MetaSprite *sprite, uint8_t *hardware_sprite_number_buffer);
extern void MetaSprite_free_from_display(MetaSprite *sprite);
extern void MetaSprite_set_flipped(MetaSprite *sprite, bool_t flag);
extern void MetaSprite_set_position(MetaSprite *sprite, uint8_t x, uint8_t y);
extern void MetaSprite_scroll(MetaSprite *sprite, int8_t dx, int8_t dy);
extern void MetaSprite_set_position_flipped_h(MetaSprite *sprite, uint8_t x, uint8_t y);
extern void MetaSprite_set_frame(MetaSprite *sprite, uint8_t relative_sprite_number, uint8_t frame);