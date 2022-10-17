#pragma once

#include "../template.hpp"

template <typename D, D INF = numeric_limits<D>::max()> void wf(vector<vector<D>> &g) {
    ll n = g.size();
    for (ll k : rep(n)) {
        for (ll i : rep(n)) {
            for (ll j : rep(n)) {
                if (g[i][k] != INF && g[k][j] != INF) chmin(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}