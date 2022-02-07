#include "graphics/Graphics.h"
#include "game/GameWorld.h"
#include "assets/tile_maps/TestTileMap.h"

const int16_t offset_x = 0; //(32 + 10) * 8;
const int16_t speed_x = 1;

int main() {

    Graphics_create();
    Graphics_show();
    Graphics_show_tile_map(0, TestTileMap);
    GameWorld_create();
    while(1) {
        wait_vbl_done();
        Graphics_scroll_camera(speed_x);
        GameWorld_process();
    }

    return 0;
}