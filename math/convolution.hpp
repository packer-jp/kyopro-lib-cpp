#pragma once

#include "../template.hpp"
#include "ntt.hpp"

template <typename T> vector<T> convolution_naive(vector<T> a, vector<T> b) {
    int na = a.size(), nb = b.size();
    vector<T> c(na + nb - 1);
    if (na < nb) swap(a, b), swap(na, nb);
    for (int i : rep(na)) {
        for (int j : rep(nb)) c[i + j] += a[i] * b[j];
    }
    return c;
}

template <typename mint> vector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {
    int _n = a.size() + b.size() - 1, n;
    for (n = 1; n < _n; n <<= 1) {}
    a.resize(n), b.resize(n);
    ntt(a), ntt(b);
    for (int i : rep(n)) a[i] *= b[i];
    intt(a);
    a.resize(_n);
    return a;
}

template <typename mint> vector<mint> convolution(const vector<mint> &a, const vector<mint> &b) {
    if (min(a.size(), b.size()) <= 60) {
        return convolution_naive(a, b);
    } else {
        return convolution_ntt(a, b);
    }
}