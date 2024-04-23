#include "GameWorld.h"
#include "entity/player/PlayerEntity.h"

void GameWorld_create() {
    PlayerEntity_create();
}

void GameWorld_process() {
    PlayerEntity_process();
}
