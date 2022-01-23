#include <gb/gb.h>
#include <gb/drawing.h>

#include "assets/sprites/CrackedStoneTile.h"
#include "graphics/Sprite.h"

Sprite cracked_stone_sprite;

void main()
{
    Sprite_create(&cracked_stone_sprite, CrackedStoneTile, 0);
    Sprite_load(&cracked_stone_sprite);
    Sprite_set_tile(&cracked_stone_sprite, 0);
    move_sprite(80, 72);
    Graphics_show_sprites();
}