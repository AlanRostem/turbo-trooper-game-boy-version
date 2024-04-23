#pragma once
#include <gb/gb.h>
#include "../../util/Util.h"

// The coding guidelines is to use the least amount of memory and allocation of memory.
// This variable will be used for indexing in for loops. Set it to zero in every for loop and code will never break.
extern uint8_t global_for_loop_i;

extern uint8_t Memory_allocate_and_write_sprite_data(uint8_t tile_count, RomByte* image_data);
extern uint8_t Memory_generate_hardware_sprite_number();
extern uint8_t Memory_free_hardware_sprite_number(uint8_t sprite_number);

extern void Memory_allocate_tile_set(RomByte* tile_set, uint8_t tile_count);