#pragma once

#include "../template.hpp"
#include "modint.hpp"

template <typename mint> void ntt(vector<mint> &a, bool inv = false) {
    int n = a.size(), m = n >> 1;
    mint root = 2;
    while (root.pow((mint::mod() - 1) >> 1) == 1) root += 1;
    mint wn = root.pow((mint::mod() - 1) / n);
    if (inv) wn = wn.inv();
    vector<mint> b(n);
    for (int i = 1; i < n; i <<= 1, wn *= wn, swap(a, b)) {
        mint wj = 1;
        for (int j = 0; j < m; j += i, wj *= wn) {
            for (int k : rep(i)) {
                b[(j << 1) + k + 0] = (a[j + k] + a[j + k + m]);
                b[(j << 1) + k + i] = (a[j + k] - a[j + k + m]) * wj;
            }
        }
    }
    if (inv) {
        mint ninv = mint(n).inv();
        for (int i : rep(n)) a[i] *= ninv;
    }
}
template <typename mint> void intt(vector<mint> &a) { ntt(a, true); }

template <typename mint> vector<mint> convolution_naive(vector<mint> a, vector<mint> b) {
    int na = a.size(), nb = b.size();
    vector<mint> c(na + nb - 1);
    if (na < nb) swap(a, b), swap(na, nb);
    for (int i : rep(na)) {
        for (int j : rep(nb)) { c[i + j] += a[i] * b[j]; }
    }
    return c;
}

template <typename mint> vector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {
    int n_ = a.size() + b.size() - 1, n;
    for (n = 1; n < n_; n <<= 1) {}
    a.resize(n), b.resize(n);
    ntt(a), ntt(b);
    for (int i : rep(n)) a[i] *= b[i];
    intt(a);
    a.resize(n_);
    return a;
}

template <typename mint> vector<mint> convolution(const vector<mint> &a, const vector<mint> &b) {
    if (min(a.size(), b.size()) <= 60) {
        return convolution_naive(a, b);
    } else {
        return convolution_ntt(a, b);
    }
}