#include <iostream>
#include <bitset>
#include <cstdint>
#include <cstdlib>

#include "../src/sha256_utils.h"

using namespace std;

int main(int argc, char *argv[]) {

    cout << rotr32(uint32_t(atoi(argv[1])), uint32_t(atoi(argv[2]))) << " ";
    cout << rotr32(uint32_t(atoi(argv[3])), uint32_t(atoi(argv[4]))) << " ";
    cout << rotr32(uint32_t(atoi(argv[5])), uint32_t(atoi(argv[6]))) << " ";

    return 0;
}
