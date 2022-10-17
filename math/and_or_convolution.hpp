#pragma once

#include "../template.hpp"
#include "fzt_fmt.hpp"

template <typename V> vector<V> and_convolution(vector<V> a, vector<V> b) {
    ll _n = max(a.size(), b.size()), n;
    for (n = 1; n < _n; n <<= 1) {}
    a.resize(n), b.resize(n);
    fzt_super(a), fzt_super(b);
    for (ll i : rep(n)) a[i] *= b[i];
    fmt_super(a);
    return a;
}

template <typename V> vector<V> or_convolution(vector<V> a, vector<V> b) {
    ll _n = max(a.size(), b.size()), n;
    for (n = 1; n < _n; n <<= 1) {}
    a.resize(n), b.resize(n);
    fzt_sub(a), fzt_sub(b);
    for (ll i : rep(n)) a[i] *= b[i];
    fmt_sub(a);
    return a;
}