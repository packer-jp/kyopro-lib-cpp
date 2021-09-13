#pragma once

#include "../template.hpp"

template <typename T> void wf(vector<vector<T>> &g, T inf = numeric_limits<T>::max()) {
    int n = g.size();
    for (int k : rep(n)) {
        for (int i : rep(n)) {
            for (int j : rep(n)) {
                if (g[i][k] != inf && g[k][j] != inf) chmin(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}