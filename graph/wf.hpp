#pragma once

#include "../template.hpp"

template <typename C> void wf(vector<vector<C>> &adj, C inf = numeric_limits<C>::max()) {
    int n = adj.size();
    for (int k : rep(n)) {
        for (int i : rep(n)) {
            for (int j : rep(n)) {
                if (adj[i][k] != inf && adj[k][j] != inf) chmin(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}