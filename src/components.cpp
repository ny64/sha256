#include <cstdint>

#include "sha256_utils.h"

using std::uint32_t;

uint32_t* message_schedule(uint8_t block[64]) {
    uint32_t *W = new uint32_t[64];

    // convert characters into 4 byte integers (words)
    for (int i = 0; i < 16; ++i) {
        W[i] = 0;
        for (int j = 0; j < 4; ++j) {
            W[i] += block[4*i + j];
            if (j != 3) { W[i] = W[i] << 8; }
        }
    }

    for (int i = 16; i < 64; ++i) {
        W[i] = W[i - 16] + little_sigma0(W[i - 15]) + W[i - 7] + little_sigma1(W[i - 2]);
    }

    return W;
}

uint32_t* round(uint32_t state[8], uint32_t round_constant, uint32_t schedule_word) {
    uint32_t ch = choice(state[4], state[5], state[6]);
    uint32_t temp1 = state[7] + big_sigma1(state[4]) + ch + round_constant + schedule_word;
    uint32_t maj = majority(state[0], state[1], state[2]);
    uint32_t temp2 = big_sigma0(state[0]) + maj;

    uint32_t *new_state = new uint32_t[8];
    new_state[0] = temp1 + temp2; 
    new_state[1] = state[0]; 
    new_state[2] = state[1]; 
    new_state[3] = state[2]; 
    new_state[4] = state[3] + temp1;
    new_state[5] = state[4]; 
    new_state[6] = state[5]; 
    new_state[7] = state[6]; 

    return new_state;
}


uint32_t* compress(uint32_t input_state[8], uint8_t block[64]) {
    uint32_t *W = message_schedule(block);
    uint32_t *state = new uint32_t[8];

    for (int i = 0; i < 8; ++i) 
        state[i] = input_state[i];
    for (int i = 0; i < 64; ++i)
        state = round(state, ROUND_CONSTANTS[i], W[i]); 
    for (int i = 0; i < 8; ++i)
        state[i] = input_state[i] + state[i];

    return state;
}
