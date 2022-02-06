#pragma once
#include "../util/TypeDefs.h"
#include <gb/gb.h>

#define TILE_MAP_WIDTH 255 // This is a test value for now
#define TILE_MAP_HEIGHT 16
#define TILE_MAP_INIT_OFFSET 6
#define TILE_SIZE 8

static uint16_t Graphics_current_camera_offset = 0;

extern void Graphics_create();
extern void Graphics_show();

extern void Graphics_scroll_camera(int8_t offset_x);

extern void Graphics_show_tile_map(uint8_t offset_x, RomByte* tile_map);
extern void Graphics_update_current_tile_map_col(uint8_t col, RomByte* tile_map);
