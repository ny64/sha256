#include <iostream>
#include <cstdint>

#include "../src/sha256_utils.h"

using namespace std;

int main(int argc, char *argv[]) {

    uint8_t *block = new uint8_t[64];

    for (int i = 0; i < 64; ++i) {
        block[i] = uint32_t(argv[1][i]);
    }

    uint32_t *W = message_schedule(block);

    for (int i = 0; i < 64; ++i)
        cout << W[i] << " ";

    cout << endl;

    return 0;
}
