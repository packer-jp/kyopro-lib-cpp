#pragma once

#include "../template.hpp"
#include "fps.hpp"
#include "fzt_fmt.hpp"

template <typename T> vector<fps<T>> attach(const vector<T> &a) {
    vector<fps<T>> ret(a.size());
    for (int i : rep(a.size())) {
        int j = __builtin_popcount(i);
        ret[i].resize(j + 1);
        ret[i][j] = a[i];
    }
    return ret;
}

template <typename T> vector<T> detach(const vector<fps<T>> &a) {
    vector<T> ret(a.size());
    for (int i : rep(a.size())) ret[i] = a[i][__builtin_popcount(i)];
    return ret;
}

template <typename T> vector<T> subset_convolution(vector<T> a, vector<T> b) {
    int _n = max(a.size(), b.size()), n;
    for (n = 1; n < _n; n <<= 1) {}
    a.resize(n), b.resize(n);
    vector<fps<T>> _a = attach(a), _b = attach(b);
    fzt_sub(_a), fzt_sub(_b);
    for (int i : rep(n)) _a[i] *= _b[i];
    fmt_sub(_a);
    return detach(_a);
}