#include "assets/sprites/TileSet.h"
#include "assets/tile_maps/TestTileMap.h"

#define TILE_MAP_WIDTH 48 // This is a test value for now
#define TILE_MAP_HEIGHT 16
#define MAX_RENDERED_TILE_MAP_WIDTH 32
#define MAX_ON_SCREEN_TILE_MAP_WIDTH 20
#define OUT_OF_SCREEN_RENDERED_TILE_WIDTH_HALF 6
#define OUT_OF_SCREEN_RENDERED_TILE_WIDTH 12
#define TILE_SIZE 8


int main() {

    // WRAM variables
    static uint8_t joypad_input;
    static uint8_t tile_offset_x = 0;

    // Write tile set to VRAM
    set_bkg_2bpp_data(
        0, 
        38, 
        TileSet);

    // Set background tiles
    uint8_t tile_offset_x = OUT_OF_SCREEN_RENDERED_TILE_WIDTH_HALF;
    set_bkg_submap(tile_offset_x, 0, 
        MAX_RENDERED_TILE_MAP_WIDTH, 
        TILE_MAP_HEIGHT, 
        TestTileMap, 
        TILE_MAP_WIDTH);
    move_bkg(tile_offset_x * TILE_SIZE, 0);

    // Enable bg and sprites
    SHOW_SPRITES;
    SHOW_BKG;

    while(1) {
        wait_vbl_done();

        joypad_input = joypad();

    }

    return 0;
}