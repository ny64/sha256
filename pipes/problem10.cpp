#include <iostream>
#include <cstdint>
#include <cstdlib>

#include "../src/sha256_utils.h"

using namespace std;

int main(int argc, char *argv[]) {

    uint32_t *state_in = new uint32_t[8];
    for (int i = 0; i < 8; ++i) {
        state_in[i] = uint32_t(atoi(argv[i+1])); 
    }
    uint32_t *state_out = round(state_in, uint32_t(atoi(argv[9])), uint32_t(atoi(argv[10])));

    for (int i = 0; i < 8; ++i)
        cout << state_out[i] << " ";

    return 0;
}
