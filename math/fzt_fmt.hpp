#pragma once

#include "../template.hpp"

template <typename V> void fzt_super(vector<V> &a) {
    for (ll i : rep(__builtin_ffs(a.size()) - 1)) {
        for (ll s : rep(a.size())) {
            if ((s >> i) & 1) a[s ^ bit(i)] += a[s];
        }
    }
}

template <typename V> void fzt_sub(vector<V> &a) {
    for (ll i : rep(__builtin_ffs(a.size()) - 1)) {
        for (ll s : rep(a.size())) {
            if (!((s >> i) & 1)) a[s ^ bit(i)] += a[s];
        }
    }
}

template <typename V> void fmt_super(vector<V> &a) {
    for (ll i : rep(__builtin_ffs(a.size()) - 1)) {
        for (ll s : rep(a.size())) {
            if ((s >> i) & 1) a[s ^ bit(i)] -= a[s];
        }
    }
}

template <typename V> void fmt_sub(vector<V> &a) {
    for (ll i : rep(__builtin_ffs(a.size()) - 1)) {
        for (ll s : rep(a.size())) {
            if (!((s >> i) & 1)) a[s ^ bit(i)] -= a[s];
        }
    }
}
