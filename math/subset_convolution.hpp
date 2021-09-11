#pragma once

#include "../template.hpp"
#include "and_or_convolution.hpp"
#include "fps.hpp"

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
    int n_ = max(a.size(), b.size()), n;
    for (n = 1; n < n_; n <<= 1) {}
    a.resize(n), b.resize(n);
    vector<fps<T>> a_ = attach(a), b_ = attach(b);
    fzt_sub(a_), fzt_sub(b_);
    for (int i : rep(n)) a_[i] *= b_[i];
    fmt_sub(a_);
    return detach(a_);
}