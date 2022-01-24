#pragma once
#include <gb/gb.h>

typedef struct {
    uint8_t start;
    uint8_t end;
} MemoryPosition;

extern uint8_t Memory_allocate_and_write_sprite_data(uint8_t tile_count, uint8_t* image_data);
extern uint8_t Memory_generate_hardware_sprite_number();