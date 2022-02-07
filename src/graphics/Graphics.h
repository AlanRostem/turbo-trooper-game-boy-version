#pragma once
#include "../util/TypeDefs.h"
#include <gb/gb.h>

#define TILE_MAP_WIDTH 48 // This is a test value for now
#define TILE_MAP_HEIGHT 16
#define MAX_RENDERED_TILE_MAP_WIDTH 32
#define MAX_ON_SCREEN_TILE_MAP_WIDTH 20
#define OUT_OF_SCREEN_RENDERED_TILE_WIDTH_HALF 6
#define OUT_OF_SCREEN_RENDERED_TILE_WIDTH 12
#define TILE_SIZE 8

extern const uint8_t* Graphics_currently_shown_tile_map;
extern int16_t Graphics_current_camera_offset;

extern void Graphics_create();
extern void Graphics_show();

extern void Graphics_scroll_camera(int16_t pixel_offset_x);

extern void Graphics_show_start_of_tile_map(RomByte* tile_map);
extern void Graphics_show_end_of_tile_map(RomByte* tile_map);
