#pragma once

#include "../template.hpp"

template <typename T> void fzt_super(vector<T> &a) {
    int n = __builtin_ffs(a.size()) - 1;
    for (int i : rep(n)) {
        for (int s : rep(bit(n))) {
            if ((s >> i) & 1) a[s ^ bit(i)] += a[s];
        }
    }
}

template <typename T> void fzt_sub(vector<T> &a) {
    int n = __builtin_ffs(a.size()) - 1;
    for (int i : rep(n)) {
        for (int s : rep(bit(n))) {
            if (!((s >> i) & 1)) a[s ^ bit(i)] += a[s];
        }
    }
}

template <typename T> void fmt_super(vector<T> &a) {
    int n = __builtin_ffs(a.size()) - 1;
    for (int i : rep(n)) {
        for (int s : rep(bit(n))) {
            if ((s >> i) & 1) a[s ^ bit(i)] -= a[s];
        }
    }
}

template <typename T> void fmt_sub(vector<T> &a) {
    int n = __builtin_ffs(a.size()) - 1;
    for (int i : rep(n)) {
        for (int s : rep(bit(n))) {
            if (!((s >> i) & 1)) a[s ^ bit(i)] -= a[s];
        }
    }
}