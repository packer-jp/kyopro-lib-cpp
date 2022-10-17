#pragma once

#include "../template.hpp"
#include "fps.hpp"
#include "fzt_fmt.hpp"

template <typename V> vector<fps<V>> attach(const vector<V> &a) {
    vector<fps<V>> ret(a.size());
    for (ll i : rep(a.size())) {
        ll j = __builtin_popcount(i);
        ret[i].resize(j + 1);
        ret[i][j] = a[i];
    }
    return ret;
}

template <typename V> vector<V> detach(const vector<fps<V>> &a) {
    vector<V> ret(a.size());
    for (ll i : rep(a.size())) ret[i] = a[i][__builtin_popcount(i)];
    return ret;
}

template <typename V> vector<V> subset_convolution(vector<V> a, vector<V> b) {
    ll _n = max(a.size(), b.size()), n;
    for (n = 1; n < _n; n <<= 1) {}
    a.resize(n), b.resize(n);
    vector<fps<V>> _a = attach(a), _b = attach(b);
    fzt_sub(_a), fzt_sub(_b);
    for (ll i : rep(n)) _a[i] *= _b[i];
    fmt_sub(_a);
    return detach(_a);
}