#pragma once

#include "../template.hpp"

struct khan {
    vector<vector<int>> g;
    vector<int> indeg;
    khan(int n) : g(n), indeg(n) {}
    void add_edge(int from, int to) { g[from].push_back(to), ++indeg[to]; }
    vector<int> get() {
        vector<int> _indeg(indeg), ret;
        for (int i : rep(g.size())) {
            if (_indeg[i] == 0) ret.push_back(i);
        }
        for (int i : rep(g.size())) {
            if (i >= ret.size()) return {};
            for (int to : g[ret[i]]) {
                if (--_indeg[to] == 0) ret.push_back(to);
            }
        }
        return ret;
    }
};