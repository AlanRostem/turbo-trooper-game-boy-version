#include "Graphics.h"

static uint8_t sprites_used = 0;

uint8_t Graphics_generate_sprite_number() {
    // TODO: In debug mode, check if this exceeds the 40 limit
    return sprites_used++;
}

void Graphics_show_sprites() {
    SHOW_SPRITES;
}
