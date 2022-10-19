#pragma once

#include "../template.hpp"

template <typename V> void fzt_super(vector<V> &a) {
    for (ll i : rep(flg(a.size()))) {
        for (ll s : rep(a.size())) {
            if ((s >> i) & 1) a[s ^ pw(i)] += a[s];
        }
    }
}

template <typename V> void fzt_sub(vector<V> &a) {
    for (ll i : rep(flg(a.size()))) {
        for (ll s : rep(a.size())) {
            if (!((s >> i) & 1)) a[s ^ pw(i)] += a[s];
        }
    }
}

template <typename V> void fmt_super(vector<V> &a) {
    for (ll i : rep(flg(a.size()))) {
        for (ll s : rep(a.size())) {
            if ((s >> i) & 1) a[s ^ pw(i)] -= a[s];
        }
    }
}

template <typename V> void fmt_sub(vector<V> &a) {
    for (ll i : rep(flg(a.size()))) {
        for (ll s : rep(a.size())) {
            if (!((s >> i) & 1)) a[s ^ pw(i)] -= a[s];
        }
    }
}
