#include <gb/gb.h>
#include <gb/drawing.h>

#include "assets/sprites/CrackedStoneTile.h"
#include "graphics/Sprite.h"

Sprite cracked_stone_sprite;

int main()
{
    Sprite_create(&cracked_stone_sprite);
    Sprite_load(&cracked_stone_sprite, 0, CrackedStoneTile);
    Sprite_set_tile(&cracked_stone_sprite, 0);
    Sprite_set_position(&cracked_stone_sprite, 100, 100);
    Graphics_show_sprites();
    return 0;
}