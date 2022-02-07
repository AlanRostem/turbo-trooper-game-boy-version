#include "graphics/Graphics.h"
#include "game/GameWorld.h"
#include "assets/tile_maps/TestTileMap.h"

int main() {

    Graphics_create();
    Graphics_show_start_of_tile_map(TestTileMap);

    GameWorld_create();

    Graphics_show();
    while(1) {
        wait_vbl_done();
        GameWorld_process();
    }

    return 0;
}