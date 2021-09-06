#pragma once

#include "../template.hpp"
#include "persistent_array.hpp"

template <int SHIFT> struct persistent_uf {
    int n;
    persistent_array<int, SHIFT> ps;
    persistent_uf(int n) : n(n), ps(n, -1) {}
    persistent_uf(int n, persistent_array<int, SHIFT> ps) : n(n), ps(ps) {}
    pair<int, int> find_with_size(int i) const {
        int psi = ps.get(i);
        return psi < 0 ? make_pair(i, -psi) : find_with_size(psi);
    }
    int find(int i) const { return find_with_size(i).first; }
    int size(int i) const { return find_with_size(i).second; }
    bool same(int i, int j) const { return find(i) == find(j); }
    persistent_uf unite(int i, int j) const {
        auto [ip, si] = find_with_size(i);
        auto [jp, sj] = find_with_size(j);
        if (ip == jp) return *this;
        if (si < sj) swap(ip, jp);
        return persistent_uf(n, ps.set(ip, -si - sj).set(jp, ip));
    }
    vector<vector<int>> groups() const {
        vector<vector<int>> ret(n);
        for (int i : rep(n)) ret[find(i)].push_back(i);
        ret.erase(remove_if(all(ret), [](const vector<int> &v) { return v.empty(); }), ret.end());
        return ret;
    }
};