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

void Graphics_scroll_camera(int8_t pixel_offset_x) {
    if (pixel_offset_x == 0) return;
    static uint8_t col_bounds_check;
    col_bounds_check = (Graphics_current_camera_offset + pixel_offset_x) / TILE_SIZE;
    if (col_bounds_check >= TILE_MAP_WIDTH || col_bounds_check == 0) return;
    Graphics_current_camera_offset += pixel_offset_x;
    scroll_bkg(pixel_offset_x, 0);
    if (Graphics_current_tile_map_scroll_col != col_bounds_check) {
        Graphics_current_tile_map_scroll_col = col_bounds_check;
        if (Graphics_current_tile_map_scroll_col >= MAX_RENDERED_TILE_MAP_WIDTH) {
            set_bkg_submap(Graphics_current_tile_map_scroll_col, 0, 1, TILE_MAP_HEIGHT,
                           Graphics_currently_shown_tile_map, TILE_MAP_WIDTH);
        }
    }
}

void Graphics_show_tile_map(uint8_t tile_offset_x, RomByte* tile_map) {
    Graphics_currently_shown_tile_map = tile_map;
    Graphics_current_tile_map_scroll_col = MAX_ON_SCREEN_TILE_MAP_WIDTH + tile_offset_x;
    Graphics_current_camera_offset = Graphics_current_tile_map_scroll_col * TILE_SIZE;
    set_bkg_submap(tile_offset_x, 0, 32, TILE_MAP_HEIGHT, Graphics_currently_shown_tile_map, TILE_MAP_WIDTH);
    move_bkg(tile_offset_x * TILE_SIZE, 0);
}
