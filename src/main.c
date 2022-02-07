#include "graphics/Graphics.h"
#include "game/GameWorld.h"
#include "assets/tile_maps/TestTileMap.h"

const int16_t offset_x = 0; //(32 + 10) * 8;
const int16_t speed_x = 1;

int main() {

    Graphics_create();
    Graphics_show();
    Graphics_show_tile_map(0, TestTileMap);

    // show func:
    /*
    Graphics_currently_shown_tile_map = TestTileMap;
    Graphics_current_tile_map_scroll_col = MAX_ON_SCREEN_TILE_MAP_WIDTH + TILE_MAP_INIT_OFFSET;
    Graphics_current_camera_offset = Graphics_current_tile_map_scroll_col * TILE_SIZE;
    set_bkg_submap(0, 0, 32, TILE_MAP_HEIGHT, Graphics_currently_shown_tile_map, TILE_MAP_WIDTH);
    move_bkg(TILE_MAP_INIT_OFFSET * TILE_SIZE, 0);
     */

    GameWorld_create();
    while(1) {
        wait_vbl_done();
        Graphics_scroll_camera(speed_x);
        /*
        if (Graphics_current_tile_map_scroll_col < TILE_MAP_WIDTH)
        {
            // scroll func:
            Graphics_current_camera_offset += speed_x;
            scroll_bkg(speed_x, 0);
            if (Graphics_current_tile_map_scroll_col != Graphics_current_camera_offset / TILE_SIZE) {
                Graphics_current_tile_map_scroll_col = Graphics_current_camera_offset / TILE_SIZE;
                if (Graphics_current_tile_map_scroll_col >= MAX_RENDERED_TILE_MAP_WIDTH) {
                    set_bkg_submap(Graphics_current_tile_map_scroll_col, 0, TILE_MAP_INIT_OFFSET, TILE_MAP_HEIGHT,
                                   Graphics_currently_shown_tile_map, TILE_MAP_WIDTH);
                }
            }
        }
         */

        GameWorld_process();
    }

    return 0;
}