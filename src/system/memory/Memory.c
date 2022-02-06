#include "Memory.h"
#include "src/util/Util.h"

static uint8_t vram_tiles_occupied = 0;
uint8_t global_for_loop_i = 0;

// Allocate 40 bits
static uint8_t unused_hardware_sprite_bit_masks[5] = {255, 255, 255, 255,255};

uint8_t Memory_allocate_and_write_sprite_data(uint8_t tile_count, uint8_t* image_data) {
    uint8_t mem_pos = vram_tiles_occupied;
    set_sprite_2bpp_data(mem_pos, tile_count, image_data);
    vram_tiles_occupied += tile_count;
    return mem_pos;
}

// TODO: Determine if these static vars should be global
// gbdk specifies that static is faster, but also that stack variables are bad. not sure if this implementation
// necessarily follows that.
uint8_t Memory_generate_hardware_sprite_number() {
    static uint8_t bit_mask;
    static uint8_t bit_pos;
    for (global_for_loop_i = 0; global_for_loop_i < 5; global_for_loop_i++) {
        bit_mask = unused_hardware_sprite_bit_masks[global_for_loop_i];
        if (bit_mask) {
            bit_pos = uint8_get_rightmost_set_bit_position(bit_mask) - 1;
            unused_hardware_sprite_bit_masks[global_for_loop_i] = uint8_set_bit(bit_mask, bit_pos, FALSE);
            return global_for_loop_i * 8 + bit_pos;
        }
    }
    return MAX_HARDWARE_SPRITES;
}

uint8_t Memory_free_hardware_sprite_number(uint8_t sprite_number) {
    global_for_loop_i = sprite_number >> 1;
    unused_hardware_sprite_bit_masks[global_for_loop_i] = uint8_set_bit(unused_hardware_sprite_bit_masks[global_for_loop_i], sprite_number % 8, TRUE);
    return 0;
}

void Memory_allocate_tile_set(uint8_t *tile_set, uint8_t tile_count) {
    set_bkg_2bpp_data(vram_tiles_occupied, tile_count, tile_set);
    vram_tiles_occupied += tile_count;
}
