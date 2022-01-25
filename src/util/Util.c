#include "Util.h"

uint8_t set_bit_mask_uint8(uint8_t integer, uint8_t bit_position, uint8_t flag) {
    int mask = 1 << bit_position;
    return ((integer & ~mask) | (flag << bit_position));
}
