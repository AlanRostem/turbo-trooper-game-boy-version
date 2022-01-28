#include "graphics/Graphics.h"
#include "game/GameWorld.h"
#include "system/System.h"

int main() {
    GameWorld_create();
    Graphics_show_sprites();
    while(1) {
        GameWorld_process();

        switch (joypad()) {
            case J_START:
                return 0;
        }

        delay(PHYSICS_PROCESS_DELTA);
    }
    return 0;
}