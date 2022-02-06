#include "graphics/Graphics.h"
#include "game/GameWorld.h"

int main() {

    Graphics_create();
    Graphics_show_sprites();

    GameWorld_create();
    while(1) {
        wait_vbl_done();
        GameWorld_process();
    }
    return 0;
}