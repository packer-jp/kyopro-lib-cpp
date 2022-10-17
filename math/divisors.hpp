#pragma once

#include "../template.hpp"

template <typename V> vector<V> divisors(V n) {
    vector<V> ret;
    V i;
    for (i = 1; i * i < n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            ret.push_back(n / i);
        }
    }
    if (i * i == n) ret.push_back(i);
    sort(all(ret));
    return ret;
}