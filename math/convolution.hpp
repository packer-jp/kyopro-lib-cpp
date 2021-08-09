#ifndef PWMTREE_CONVOLUTION_HPP
#define PWMTREE_CONVOLUTION_HPP 1

#include "../template.hpp"
#include "modint.hpp"

template <typename mint> void fft(vector<mint> &a, mint wn) {
    ll n = a.size(), m = n >> 1;
    vector<mint> b(n);
    for (ll i = 1; i < n; i <<= 1, wn *= wn, swap(a, b)) {
        mint wj = 1;
        for (ll j = 0; j < m; j += i, wj *= wn) {
            rep(k, i) {
                b[(j << 1) + k + 0] = (a[j + k] + a[j + k + m]);
                b[(j << 1) + k + i] = (a[j + k] - a[j + k + m]) * wj;
            }
        }
    }
}

template <typename mint, ll ROOT> vector<mint> convolution_friendly(vector<mint> a, vector<mint> b) {
    ll n_ = a.size() + b.size() - 1, n;
    for (n = 1; n < n_; n <<= 1) {}
    a.resize(n), b.resize(n);
    mint wn = mint(ROOT).pow((mint::mod() - 1) / n);
    fft(a, wn), fft(b, wn);
    rep(i, n) a[i] *= b[i];
    fft(a, wn.inv());
    mint ninv = mint(n).inv();
    a.resize(n_);
    rep(i, n_) a[i] *= ninv;
    return a;
}

#endif