#include <stdio.h>
#include "Graphics.h"
#include "../system/memory/Memory.h"
#include "../assets/sprites/TileSet.h"

int16_t Graphics_current_camera_offset = 0;
const uint8_t* Graphics_currently_shown_tile_map = 0;

void Graphics_create() {
    Memory_allocate_tile_set(TileSet, 38);
}

void Graphics_show() {
    SHOW_SPRITES;
    SHOW_BKG;
}

void Graphics_scroll_camera(int16_t pixel_offset_x) {
    if (pixel_offset_x == 0) return;

    static int16_t col_bounds_check;
    col_bounds_check = (Graphics_current_camera_offset + pixel_offset_x) / TILE_SIZE + MAX_ON_SCREEN_TILE_MAP_WIDTH;
    if (col_bounds_check >= TILE_MAP_WIDTH || col_bounds_check <= MAX_ON_SCREEN_TILE_MAP_WIDTH) return;

    Graphics_current_camera_offset += pixel_offset_x;
    scroll_bkg(pixel_offset_x, 0);

    set_bkg_submap(Graphics_current_camera_offset / TILE_SIZE + (pixel_offset_x > 0) * MAX_ON_SCREEN_TILE_MAP_WIDTH,
                   0, 1, TILE_MAP_HEIGHT,Graphics_currently_shown_tile_map, TILE_MAP_WIDTH);
}

void Graphics_show_tile_map(uint8_t tile_offset_x, RomByte* tile_map) {
    Graphics_currently_shown_tile_map = tile_map;
    Graphics_current_camera_offset = tile_offset_x * TILE_SIZE;
    set_bkg_submap(tile_offset_x, 0, MAX_RENDERED_TILE_MAP_WIDTH, TILE_MAP_HEIGHT, Graphics_currently_shown_tile_map, TILE_MAP_WIDTH);
    move_bkg(tile_offset_x * TILE_SIZE, 0);
}

void Graphics_show_start_of_tile_map(RomByte *tile_map) {
    Graphics_show_tile_map(OUT_OF_SCREEN_RENDERED_TILE_WIDTH_HALF, tile_map);
}

void Graphics_show_end_of_tile_map(RomByte *tile_map) {
    Graphics_show_tile_map(TILE_MAP_WIDTH - MAX_ON_SCREEN_TILE_MAP_WIDTH - 1, tile_map);
}