#include <cstdint>

using std::uint32_t;

// Rotate left n times
uint32_t rotl32(uint32_t x, int32_t n) {
    int32_t s =  n>=0? n%32 : -((-n)%32);
    return (x<<s) | (x>>(32-s));
}

// Rotate right n times
uint32_t rotr32(uint32_t x, int32_t n) {
    int32_t s =  n>=0? n%32 : -((-n)%32);
    return (x>>s) | (x<<(32-s));
}

