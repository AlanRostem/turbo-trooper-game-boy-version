#include "graphics/Graphics.h"
#include "game/GameWorld.h"
#include <time.h>
#include <stdio.h>

int main() {
    GameWorld_create();
    Graphics_show_sprites();
    while(1) {
        wait_vbl_done();
        GameWorld_process();

        switch (joypad()) {
            case J_START:
                return 0;
        }
    }
    return 0;
}