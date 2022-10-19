#pragma once

#include "../template.hpp"

template <typename V> vector<V> prime_factorize(V n) {
    vector<V> ret;
    for (V i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ret.push_back(i);
            n /= i;
        }
    }
    if (n != 1) ret.push_back(n);
    return ret;
}