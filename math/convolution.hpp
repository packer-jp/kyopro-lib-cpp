#ifndef PWMTREE_CONVOLUTION_HPP
#define PWMTREE_CONVOLUTION_HPP 1

#include "../template.hpp"
#include "modint.hpp"

template <typename mint> void ntt(vector<mint> &a, mint wn) {
    int n = a.size(), m = n >> 1;
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
}

template <typename mint> mint getw(ll n) {
    mint root = 2;
    while (root.pow((mint::mod() - 1) >> 1) == 1) root += 1;
    return root.pow((mint::mod() - 1) / n);
}

template <typename mint> vector<mint> convolution_friendly(vector<mint> a, vector<mint> b) {
    int n_ = a.size() + b.size() - 1, n;
    for (n = 1; n < n_; n <<= 1) {}
    a.resize(n), b.resize(n);
    mint wn = getw<mint>(n);
    ntt(a, wn), ntt(b, wn);
    for (int i : rep(n)) a[i] *= b[i];
    ntt(a, wn.inv());
    mint ninv = mint(n).inv();
    a.resize(n_);
    for (int i : rep(n_)) a[i] *= ninv;
    return a;
}

#endif