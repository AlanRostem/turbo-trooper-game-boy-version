#pragma once
#include <stdint.h>

#define TILE_MAP_HEIGHT 16
#define TILE_SIZE 8

typedef struct {
    uint8_t* tile_map_data_ref;
    uint8_t width_in_tiles;
} PhysicsTileMap;

