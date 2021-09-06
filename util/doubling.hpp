#pragma once

#include "../template.hpp"

struct doubling {
    int n;
    vector<int> next;
    vector<vector<int>> dst;
    doubling(int n) : n(n), next(n + 1, n) {}
    void set(int i, int j) { next[i] = ((j == -1) ? n : j); }
    void build(ll t_max) {
        dst.assign(64 - __builtin_clzll(t_max), next);
        for (int i : rep(dst.size() - 1)) {
            for (int j : rep(n + 1)) dst[i + 1][j] = dst[i][dst[i][j]];
        }
    }
    int get(int i, ll t) const {
        if (i == -1) return -1;
        for (int j : per(dst.size())) {
            if ((t >> j) & 1) i = dst[j][i];
        }
        return i == n ? -1 : i;
    }
};