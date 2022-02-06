#pragma once
#include <stdint.h>

typedef struct {
    uint8_t* tile_map_data_ref;
    uint8_t width_in_tiles;
} PhysicsTileMap;

