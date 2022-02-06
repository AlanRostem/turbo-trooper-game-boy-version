#include <stdio.h>
#include "Graphics.h"
#include "../system/memory/Memory.h"
#include "../assets/sprites/TileSet.h"


void Graphics_create() {
    Memory_allocate_tile_set(TileSet, 38);
}

void Graphics_show() {
    SHOW_SPRITES;
    SHOW_BKG;
}

void Graphics_scroll_camera(int8_t offset_x) {
    if (offset_x == 0) return;
    Graphics_current_camera_offset += offset_x;
    scroll_bkg(offset_x, 0);
    if (Graphics_current_camera_offset / TILE_SIZE != Graphics_current_tile_map_scroll_col)
    {
        Graphics_current_tile_map_scroll_col = Graphics_current_camera_offset % TILE_SIZE;
        Graphics_update_current_tile_map_col(Graphics_current_tile_map_scroll_col, Graphics_currently_shown_tile_map);
    }
}

void Graphics_show_tile_map(uint8_t offset_x, RomByte* tile_map) {
    set_bkg_submap(offset_x, 0, 31, TILE_MAP_HEIGHT, tile_map, TILE_MAP_WIDTH);
    move_bkg(0, 0);

    Graphics_currently_shown_tile_map = tile_map;
    Graphics_current_tile_map_scroll_col = 0;
    Graphics_current_camera_offset = 0;
}

void Graphics_update_current_tile_map_col(uint8_t col, RomByte *tile_map) {

}

