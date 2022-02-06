#include "Graphics.h"
#include "../system/memory/Memory.h"
#include "../assets/sprites/TileSet.h"

void Graphics_create() {
    Memory_allocate_tile_set(TileSet, 38);
}

void Graphics_show_sprites() {
    SHOW_SPRITES;
}