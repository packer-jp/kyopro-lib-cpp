#pragma once

#include "../template.hpp"

template <typename T> vector<T> divisors(T n) {
    vector<T> ret;
    T i;
    for (i = 1; i * i < n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            ret.push_back(n / i);
        }
    }
    if (i * i == n) ret.push_back(i);
    sort(all(ret));
    return ret;
}