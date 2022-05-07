#include <iostream>

#include "../src/sha256_utils.h"

using namespace std;

int main(int argc, char *argv[]) {

    uint32_t *state_in = new uint32_t[8];
    for (int i = 0; i < 8; ++i)
        state_in[i] = uint32_t(atoi(argv[i+1])); 
    uint8_t *block = new uint8_t[64];
    for (int i = 0; i < 64; ++i)
        block[i] = uint8_t(argv[9][i]);

    uint32_t *state_out = compress(state_in, block);

    for (int i = 0; i < 8; ++i)
        cout << state_out[i] << " ";

    return 0;
}
