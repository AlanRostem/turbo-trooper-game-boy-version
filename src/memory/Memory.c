#include "Memory.h"

static uint8_t hardware_sprites_used = 0;


uint8_t Memory_allocate_and_write_sprite_data(uint8_t tile_count, uint8_t* image_data) {
    set_sprite_2bpp_data(hardware_sprites_used++, tile_count, image_data);
    return 0;
}

uint8_t Memory_generate_hardware_sprite_number() {
    // TODO: In debug mode, check if this exceeds the 40 limit
    return hardware_sprites_used++;
}
