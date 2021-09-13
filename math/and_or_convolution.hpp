#pragma once

#include "../template.hpp"

template <typename T> void fzt_super(vector<T> &a) {
    for (int i : rep(__builtin_ffs(a.size()) - 1)) {
        for (int s : rep(a.size())) {
            if ((s >> i) & 1) a[s ^ bit(i)] += a[s];
        }
    }
}

template <typename T> void fzt_sub(vector<T> &a) {
    for (int i : rep(__builtin_ffs(a.size()) - 1)) {
        for (int s : rep(a.size())) {
            if (!((s >> i) & 1)) a[s ^ bit(i)] += a[s];
        }
    }
}

template <typename T> void fmt_super(vector<T> &a) {
    for (int i : rep(__builtin_ffs(a.size()) - 1)) {
        for (int s : rep(a.size())) {
            if ((s >> i) & 1) a[s ^ bit(i)] -= a[s];
        }
    }
}

template <typename T> void fmt_sub(vector<T> &a) {
    for (int i : rep(__builtin_ffs(a.size()) - 1)) {
        for (int s : rep(a.size())) {
            if (!((s >> i) & 1)) a[s ^ bit(i)] -= a[s];
        }
    }
}

template <typename T> vector<T> and_convolution(vector<T> a, vector<T> b) {
    int _n = max(a.size(), b.size()), n;
    for (n = 1; n < _n; n <<= 1) {}
    a.resize(n), b.resize(n);
    fzt_super(a), fzt_super(b);
    for (int i : rep(n)) a[i] *= b[i];
    fmt_super(a);
    return a;
}

template <typename T> vector<T> or_convolution(vector<T> a, vector<T> b) {
    int _n = max(a.size(), b.size()), n;
    for (n = 1; n < _n; n <<= 1) {}
    a.resize(n), b.resize(n);
    fzt_sub(a), fzt_sub(b);
    for (int i : rep(n)) a[i] *= b[i];
    fmt_sub(a);
    return a;
}