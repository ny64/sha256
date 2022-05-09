#ifndef HELPER_H
#define HELPER_H

#include <cstdint>

extern uint32_t *ROUND_CONSTANTS;

extern uint32_t *IV;

std::uint32_t rotl32(std::uint32_t x, std::int32_t n);

std::uint32_t rotr32(std::uint32_t x, std::int32_t n);

std::uint32_t little_sigma0(std::uint32_t x);

std::uint32_t little_sigma1(std::uint32_t x);

std::uint32_t big_sigma0(std::uint32_t x);

std::uint32_t big_sigma1(std::uint32_t x);

std::uint32_t choice(std::uint32_t x, std::uint32_t y, std::uint32_t z);

std::uint32_t majority(std::uint32_t x, std::uint32_t y, std::uint32_t z);

std::uint32_t* message_schedule(uint8_t *block);

std::uint32_t* round(std::uint32_t *state, std::uint32_t round_constant, std::uint32_t schedule_word);

std::uint32_t* compress(std::uint32_t input_state[8], std::uint8_t block[64]);

std::uint8_t* padding(std::uint64_t message_length);

std::uint8_t padding_length(uint64_t message_length);

std::uint8_t* sha(char *message);

#endif
