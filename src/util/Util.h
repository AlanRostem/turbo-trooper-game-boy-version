#pragma once
#include "TypeDefs.h"


uint8_t uint8_set_bit(uint8_t integer, uint8_t bit_position, bool_t flag);
uint8_t uint8_get_bit(uint8_t integer, uint8_t bit_position);
uint8_t uint8_get_rightmost_set_bit_position(uint8_t integer);

uint8_t uint8_binary_log(uint8_t integer);

bool_t has_frame_timer_exceeded_wait_time(uint16_t* time_elapsed, uint16_t wait_time, uint16_t frame_delta);