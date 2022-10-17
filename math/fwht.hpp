#pragma once

#include "../template.hpp"

template <typename V> void fwht(vector<V> &a) {
    ll n = a.size();
    for (ll i = 1; i < n; i <<= 1) {
        for (ll j = 0; j < n; j += i << 1) {
            for (ll k : rep(i)) {
                V p = a[0 + j + k], q = a[i + j + k];
                a[0 + j + k] = p + q;
                a[i + j + k] = p - q;
            }
        }
    }
}

template <typename V> void ifwht(vector<V> &a) {
    fwht(a);
    V ninv = V(1) / a.size();
    for (V &ai : a) ai *= ninv;
}