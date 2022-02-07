#pragma once
#include "../util/TypeDefs.h"
#include <gb/gb.h>

#define TILE_MAP_WIDTH 48 // This is a test value for now
#define TILE_MAP_HEIGHT 16
#define MAX_RENDERED_TILE_MAP_WIDTH 32
#define MAX_ON_SCREEN_TILE_MAP_WIDTH 20
#define TILE_MAP_INIT_OFFSET 6
#define OUT_OF_SCREEN_RENDERED_TILE_WIDTH 12
#define TILE_SIZE 8

static int16_t Graphics_current_camera_offset = 0;
static uint16_t Graphics_current_tile_map_scroll_col = 0;
static uint8_t* Graphics_currently_shown_tile_map = 0;

extern void Graphics_create();
extern void Graphics_show();

extern void Graphics_scroll_camera(int8_t pixel_offset_x);

extern void Graphics_show_tile_map(uint8_t tile_offset_x, RomByte* tile_map);
