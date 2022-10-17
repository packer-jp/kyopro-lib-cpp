#pragma once

#include "../template.hpp"
#include "fwht.hpp"

template <typename V> vector<V> xor_convolution(vector<V> a, vector<V> b) {
    ll _n = max(a.size(), b.size()), n;
    for (n = 1; n < _n; n <<= 1) {}
    a.resize(n), b.resize(n);
    fwht(a), fwht(b);
    for (ll i : rep(n)) a[i] *= b[i];
    ifwht(a);
    return a;
}