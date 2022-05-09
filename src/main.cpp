#include <cstdio>

#include "sha256_utils.h"

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        uint8_t *hash = sha(argv[i]);
        for (int j = 0; j < 32; ++j)
            printf("%02x", hash[j]);
        printf("\n");
    }
   return 0;
}
