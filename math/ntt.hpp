#pragma once

#include "../template.hpp"

template <typename mint> void ntt(vector<mint> &a, bool inv = false) {
    ll n = a.size(), m = n >> 1;
    mint root = 2;
    while (root.pow((mint::mod() - 1) >> 1) == 1) root += 1;
    mint wn = root.pow((mint::mod() - 1) / n);
    if (inv) wn = wn.inv();
    vector<mint> b(n);
    for (ll i = 1; i < n; i <<= 1, wn *= wn, swap(a, b)) {
        mint wj = 1;
        for (ll j = 0; j < m; j += i, wj *= wn) {
            for (ll k : rep(i)) {
                b[0 + (j << 1) + k] = (a[0 + j + k] + a[m + j + k]);
                b[i + (j << 1) + k] = (a[0 + j + k] - a[m + j + k]) * wj;
            }
        }
    }
    if (inv) {
        mint ninv = mint(n).inv();
        for (mint &ai : a) ai *= ninv;
    }
}
template <typename mint> void intt(vector<mint> &a) { ntt(a, true); }