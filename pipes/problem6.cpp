#include <iostream>
#include <bitset>
#include <cstdint>
#include <cstdlib>

#include "../src/sha256_utils.h"

using namespace std;

int main(int argc, char *argv[]) {

    cout << big_sigma0(uint32_t(atoi(argv[1]))) << " ";

    return 0;
}
