#pragma once
#include <gb/gb.h>

extern uint8_t Memory_allocate_and_write_sprite_data(uint8_t tile_count, uint8_t* image_data);
extern uint8_t Memory_generate_hardware_sprite_number();
extern uint8_t Memory_free_hardware_sprite_number(uint8_t sprite_number);