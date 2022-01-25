#pragma once
#include <gb/gb.h>

typedef uint8_t bool_t;

uint8_t uint8_set_bit(uint8_t integer, uint8_t bit_position, bool_t flag);
uint8_t uint8_get_bit(uint8_t integer, uint8_t bit_position);
uint8_t uint8_get_rightmost_set_bit_position(uint8_t integer);
uint8_t uint8_get_rightmost_unset_bit_position(uint8_t integer);

uint8_t uint8_binary_log(uint8_t integer);