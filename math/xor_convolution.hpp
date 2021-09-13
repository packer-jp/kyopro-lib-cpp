#pragma once

#include "../template.hpp"

template <typename T> void fwht(vector<T> &a) {
    int n = a.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k : rep(i)) {
                T p = a[0 + j + k], q = a[i + j + k];
                a[0 + j + k] = p + q;
                a[i + j + k] = p - q;
            }
        }
    }
}

template <typename T> void ifwht(vector<T> &a) {
    fwht(a);
    T ninv = T(1) / a.size();
    for (T &ai : a) ai *= ninv;
}

template <typename T> vector<T> xor_convolution(vector<T> a, vector<T> b) {
    int _n = max(a.size(), b.size()), n;
    for (n = 1; n < _n; n <<= 1) {}
    a.resize(n), b.resize(n);
    fwht(a), fwht(b);
    for (int i : rep(n)) a[i] *= b[i];
    ifwht(a);
    return a;
}