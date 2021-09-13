#pragma once

#include "../template.hpp"

template <typename T, T INF = numeric_limits<T>::max()> void wf(vector<vector<T>> &g) {
    int n = g.size();
    for (int k : rep(n)) {
        for (int i : rep(n)) {
            for (int j : rep(n)) {
                if (g[i][k] != INF && g[k][j] != INF) chmin(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}