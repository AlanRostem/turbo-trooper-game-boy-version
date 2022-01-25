#include "Util.h"

void set_bit_mask_uint8(uint8_t *integer, uint8_t bit_position, uint8_t flag) {
    int mask = 1 << bit_position;
    *integer = ((*integer & ~mask) | (flag << bit_position));
}
