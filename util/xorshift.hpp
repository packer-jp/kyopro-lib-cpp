#pragma once

#include "../template.hpp"

template <typename V> V xor64(V lb, V ub) {
    static ull x = 88172645463325252ull;
    x ^= x << 7;
    return lb + (x ^= x >> 9) % (ub - lb);
}