#pragma once

#include "../template.hpp"

struct uf {
    int n;
    vector<int> ps;
    uf(int n) : n(n), ps(n, -1) {}
    int find(int i) {
        if (ps[i] < 0) return i;
        return ps[i] = find(ps[i]);
    }
    int size(int i) { return -ps[find(i)]; }
    void unite(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return;
        if (-ps[i] < -ps[j]) swap(i, j);
        ps[i] += ps[j];
        ps[j] = i;
    }
    bool same(int i, int j) { return find(i) == find(j); }
    vector<vector<int>> groups() {
        vector<vector<int>> ret(n);
        for (int i : rep(n)) ret[find(i)].push_back(i);
        ret.erase(remove_if(all(ret), [](const vector<int> &v) { return v.empty(); }), ret.end());
        return ret;
    }
};