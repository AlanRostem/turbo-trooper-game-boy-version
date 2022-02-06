#include <stdio.h>
#include "Graphics.h"
#include "../system/memory/Memory.h"
#include "../assets/sprites/TileSet.h"

static uint16_t current_tile_map_scroll_col = 0;
static uint8_t* Graphics_currently_shown_tile_map = 0;

void Graphics_create() {
    Memory_allocate_tile_set(TileSet, 38);
}

void Graphics_show() {
    SHOW_SPRITES;
    SHOW_BKG;
}

void Graphics_scroll_camera(int8_t offset_x) {
    if (Graphics_current_camera_offset == 0) return;
    Graphics_current_camera_offset += (uint16_t)offset_x;
    scroll_bkg(offset_x, 0);
    if (Graphics_current_camera_offset % TILE_SIZE != current_tile_map_scroll_col)
    {
        current_tile_map_scroll_col = Graphics_current_camera_offset % TILE_SIZE;
        Graphics_update_current_tile_map_col(current_tile_map_scroll_col, Graphics_currently_shown_tile_map);
    }
}

void Graphics_show_tile_map(uint8_t offset_x, RomByte* tile_map) {
    set_bkg_submap(offset_x + TILE_MAP_INIT_OFFSET, 0, 32, TILE_MAP_HEIGHT, tile_map, TILE_MAP_WIDTH);
    move_bkg(TILE_MAP_INIT_OFFSET * TILE_SIZE, 0);
    Graphics_currently_shown_tile_map = tile_map;
}

void Graphics_update_current_tile_map_col(uint8_t col, RomByte *tile_map) {
    set_bkg_submap(col, 0, 5, TILE_MAP_HEIGHT, tile_map, TILE_MAP_WIDTH);
}

