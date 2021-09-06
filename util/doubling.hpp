#pragma once

#include "../template.hpp"

struct doubling {
    vector<vector<int>> dst;
    doubling(vector<int> next, ll t_max) : dst(64 - __builtin_clzll(t_max), next) {
        for (int i : rep(dst.size() - 1)) {
            for (int j : rep(next.size())) {
                if (dst[i][j] == -1) {
                    dst[i + 1][j] = -1;
                } else {
                    dst[i + 1][j] = dst[i][dst[i][j]];
                }
            }
        }
    }
    int get(int i, ll t) {
        for (int j : per(dst.size())) {
            if ((t >> j) & 1) {
                if (i == -1) return -1;
                i = dst[j][i];
            }
        }
        return i;
    }
};