#include "graphics/Graphics.h"
#include "game/GameWorld.h"
#include "assets/tile_maps/TestTileMap.h"

int main() {

    Graphics_create();
    set_bkg_submap(0, 0, 20, 16, TestTileMap, 255);

    Graphics_show();

    GameWorld_create();
    while(1) {
        wait_vbl_done();
        GameWorld_process();
    }
    return 0;
}