#pragma once

#include "../template.hpp"

struct doubling {
    ll n;
    vector<ll> next;
    vector<vector<ll>> dst;
    doubling(ll n) : n(n), next(n + 1, n) {}
    void set(ll i, ll j) { next[i] = ((j == -1) ? n : j); }
    void build(ll t_max) {
        dst.assign(64 - __builtin_clzll(t_max), next);
        for (ll i : rep(dst.size() - 1)) {
            for (ll j : rep(n + 1)) dst[i + 1][j] = dst[i][dst[i][j]];
        }
    }
    ll get(ll i, ll t) const {
        if (i == -1) return -1;
        for (ll j : per(dst.size())) {
            if ((t >> j) & 1) i = dst[j][i];
        }
        return i == n ? -1 : i;
    }
};