#pragma once
#include <stdint.h>
#include "../../util/Util.h"

typedef struct {
    RomByte* tile_map_data_ref;
    uint8_t width_in_tiles;
} PhysicsTileMap;

