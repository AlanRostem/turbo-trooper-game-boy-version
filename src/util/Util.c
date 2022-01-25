#include "Util.h"

uint8_t uint8_set_bit(uint8_t integer, uint8_t bit_position, uint8_t flag) {
    int mask = 1 << bit_position;
    return ((integer & ~mask) | (flag << bit_position));
}

uint8_t uint8_get_bit(uint8_t integer, uint8_t bit_position) {
    return (integer >> bit_position) & 1;
}

uint8_t uint8_get_rightmost_set_bit_position(uint8_t integer) {
    return uint8_binary_log((integer & (256 - integer))) + 1;
}

uint8_t uint8_binary_log(uint8_t integer) {
    uint8_t n = integer;
    uint8_t power = 0;
    while((n >>= 1) >= 1) power++;
    return power;
}

