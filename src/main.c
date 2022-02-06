#include "graphics/Graphics.h"
#include "game/GameWorld.h"
#include "assets/tile_maps/TestTileMap.h"

const int16_t offset_x = (32 + 6) * 8;

int main() {

    Graphics_create();
    Graphics_show();
    // Graphics_show_tile_map(6, TestTileMap);

    // show func:
    Graphics_currently_shown_tile_map = TestTileMap;
    set_bkg_submap(0, 0, 32, TILE_MAP_HEIGHT, Graphics_currently_shown_tile_map, TILE_MAP_WIDTH);
    move_bkg(TILE_MAP_INIT_OFFSET * TILE_SIZE, 0);

    // scroll func:
    scroll_bkg(offset_x, 0);
    Graphics_current_camera_offset += offset_x;
    Graphics_current_tile_map_scroll_col = Graphics_current_camera_offset / TILE_SIZE;
    set_bkg_submap(Graphics_current_tile_map_scroll_col, 0, TILE_MAP_INIT_OFFSET, TILE_MAP_HEIGHT, Graphics_currently_shown_tile_map, TILE_MAP_WIDTH);

    GameWorld_create();
    while(1) {
        wait_vbl_done();

        // Graphics_current_camera_offset += offset_x;
        // scroll_bkg(offset_x + TILE_MAP_INIT_OFFSET * TILE_SIZE, 0);
        // set_bkg_submap(Graphics_current_camera_offset / TILE_SIZE, 0, 1, TILE_MAP_HEIGHT, Graphics_currently_shown_tile_map, TILE_MAP_WIDTH);

        GameWorld_process();
    }
    return 0;
}