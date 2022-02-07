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
    if (Graphics_current_tile_map_scroll_col != Graphics_current_camera_offset / TILE_SIZE) {
        Graphics_current_tile_map_scroll_col = Graphics_current_camera_offset / TILE_SIZE;
        if (Graphics_current_tile_map_scroll_col >= MAX_RENDERED_TILE_MAP_WIDTH) {
            set_bkg_submap(Graphics_current_tile_map_scroll_col, 0, TILE_MAP_INIT_OFFSET, TILE_MAP_HEIGHT,
                           Graphics_currently_shown_tile_map, TILE_MAP_WIDTH);
        }
    }
}

void Graphics_show_tile_map(uint8_t offset_x, RomByte* tile_map) {
    Graphics_currently_shown_tile_map = tile_map;
    Graphics_current_tile_map_scroll_col = MAX_ON_SCREEN_TILE_MAP_WIDTH + TILE_MAP_INIT_OFFSET + offset_x / TILE_SIZE;
    Graphics_current_camera_offset = Graphics_current_tile_map_scroll_col * TILE_SIZE;
    set_bkg_submap(offset_x, 0, 32, TILE_MAP_HEIGHT, Graphics_currently_shown_tile_map, TILE_MAP_WIDTH);
    move_bkg(TILE_MAP_INIT_OFFSET * TILE_SIZE, 0);
}

void Graphics_update_current_tile_map_col(uint8_t col, RomByte *tile_map) {

}

