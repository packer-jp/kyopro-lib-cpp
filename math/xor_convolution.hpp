#pragma once

#include "../template.hpp"
#include "fwht.hpp"

template <typename T> vector<T> xor_convolution(vector<T> a, vector<T> b) {
    int _n = max(a.size(), b.size()), n;
    for (n = 1; n < _n; n <<= 1) {}
    a.resize(n), b.resize(n);
    fwht(a), fwht(b);
    for (int i : rep(n)) a[i] *= b[i];
    ifwht(a);
    return a;
}