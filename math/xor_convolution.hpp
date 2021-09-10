#pragma once

#include "../template.hpp"

template <typename mint> void fwht(vector<mint> &a) {
    int n = a.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k : rep(i)) {
                mint p = a[0 + j + k], q = a[i + j + k];
                a[0 + j + k] = p + q;
                a[i + j + k] = p - q;
            }
        }
    }
}
template <typename mint> void ifwht(vector<mint> &a) {
    fwht(a);
    mint ninv = mint(a.size()).inv();
    for (mint &ai : a) ai *= ninv;
}
template <typename mint> vector<mint> xor_convolution(vector<mint> a, vector<mint> b) {
    int n_ = max(a.size(), b.size()), n;
    for (n = 1; n < n_; n <<= 1) {}
    a.resize(n), b.resize(n);
    fwht(a), fwht(b);
    for (int i : rep(n)) a[i] *= b[i];
    ifwht(a);
    return a;
}