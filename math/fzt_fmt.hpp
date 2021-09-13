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
