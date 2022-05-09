#include <cstdint>
#include <iostream> // TODO: REMOVE
#include <cstdio> // TODO: REMOVE

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

uint8_t padding_length(uint64_t message_length) {
    return 64 - ((message_length + 8) % 64) + 8;
}

/* Retrieve padding for given message length */
uint8_t* padding(uint64_t message_length) {
    uint8_t filler_byte_length = 64 - ((message_length + 8) % 64) - 1;
    uint8_t padding_length = 1 + filler_byte_length + 8;
    uint8_t *padding = new uint8_t[padding_length];

    padding[0] = 0x80;
    for (int i = 1; i < filler_byte_length + 1; ++i) {
        padding[i] = 0x00;
    }
    message_length *= 8;
    for (int i = filler_byte_length + 1; i < padding_length; ++i) {
        padding[i] = uint8_t(message_length >> (64 - 8));
        message_length = message_length << 8;
    }

    return padding;
}

uint8_t* sha(char *message) {
    // Retrieve message length
    uint32_t m_len = 0;
    while (message[m_len] != '\0') ++m_len;
    uint32_t p_len = padding_length(m_len);
    
    // Append padding to message
    uint8_t *pad = padding(m_len);
    uint8_t *padmsg = new uint8_t[m_len + p_len];
    for (int i = 0; i < m_len + p_len; ++i)
        padmsg[i] = (i < m_len) ? message[i] : pad[i - m_len];
    
    // Deep copy IV into state
    uint32_t *state = new uint32_t[8];
    for (int i = 0; i < 8; ++i) state[i] = IV[i];
    
    // Split padded message into 64B blocks
    uint32_t block_num = (m_len + p_len)/64;
    uint8_t blocks[block_num][64];
    uint32_t k = 0;
    for (int i = 0; i < block_num; ++i)
        for (int j = 0; j < 64; ++j)
            blocks[i][j] = padmsg[k++];
    
    // Generate hash value
    for (int i = 0; i < block_num; ++i)
        state = compress(state, blocks[i]);
    uint8_t *hash = new uint8_t[32];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 4; ++j) {
            hash[4*i + j] = uint8_t(state[i] >> (32 - 8));
            state[i] = state[i] << 8;
        }
    }

    return hash;
}

