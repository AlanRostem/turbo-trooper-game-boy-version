#include "graphics/Graphics.h"
#include "game/GameWorld.h"

int main() {
    GameWorld_create();
    Graphics_show_sprites();
    while(1) {
        wait_vbl_done();
        GameWorld_process();
    }
    return 0;
}