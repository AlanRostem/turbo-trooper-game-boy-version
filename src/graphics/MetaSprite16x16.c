#include "MetaSprite16x16.h"
#include "Graphics.h"

void MetaSprite16x16_create(MetaSprite16x16 *sprite) {
    sprite->sprite_numbers[0] = Graphics_generate_sprite_number();
    sprite->sprite_numbers[1] = Graphics_generate_sprite_number();
    sprite->sprite_numbers[2] = Graphics_generate_sprite_number();
    sprite->sprite_numbers[3] = Graphics_generate_sprite_number();
}
