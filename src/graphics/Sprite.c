#include "Sprite.h"

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
#if 0
    assert(sprite->sprite_number == MAX_HARDWARE_SPRITES);
#endif
}


extern void Sprite_load(Sprite* sprite)
{
    set_sprite_data(0, sprite->tile_count, sprite->data);
}

extern void Sprite_set_tile(Sprite* sprite, uint8_t tile)
{
    set_sprite_tile(sprite->sprite_number, tile);
}