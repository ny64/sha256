#include <iostream>
#include <cstdlib>
#include "../src/sha256_utils.h"

using namespace std;

int main(int argc, char *argv[]) {
    // Problem 1
    cout << uint32_t(atoi(argv[1])) + uint32_t(atoi(argv[2])) << " ";
    cout << uint32_t(atoi(argv[3])) + uint32_t(atoi(argv[4])) << " ";
    cout << uint32_t(atoi(argv[5])) + uint32_t(atoi(argv[6]));

    return 0;
}
