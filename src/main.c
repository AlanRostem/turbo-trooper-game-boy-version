#include "graphics/Graphics.h"
#include "game/GameWorld.h"
#include "assets/tile_maps/TestTileMap.h"

int main() {

    Graphics_create();
    Graphics_show();
    Graphics_show_tile_map(0, TestTileMap);

    GameWorld_create();
    while(1) {
        wait_vbl_done();
        GameWorld_process();
    }
    return 0;
}