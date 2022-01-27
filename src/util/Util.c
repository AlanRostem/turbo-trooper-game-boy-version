#include "Util.h"

uint8_t uint8_set_bit(uint8_t integer, uint8_t bit_position, uint8_t flag) {
    return ((integer & ~(1 << bit_position)) | (flag << bit_position));
}

uint8_t uint8_get_bit(uint8_t integer, uint8_t bit_position) {
    return (integer >> bit_position) & 1;
}

uint8_t uint8_get_rightmost_set_bit_position(uint8_t integer) {
    return uint8_binary_log((integer & (256 - integer))) + 1;
}

uint8_t uint8_binary_log(uint8_t integer) {
    static uint8_t n;
    static uint8_t power;

    n = integer;
    power = 0;
    while((n >>= 1) >= 1) power++;
    return power;
}

bool_t has_frame_timer_exceeded_wait_time(uint16_t *time_elapsed, uint16_t wait_time, uint16_t frame_delta) {
    if (*time_elapsed + frame_delta >= wait_time) {
        *time_elapsed = 0;
        return TRUE;
    }
    (*time_elapsed) += frame_delta;
    return FALSE;
}

