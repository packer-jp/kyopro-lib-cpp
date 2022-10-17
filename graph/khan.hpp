#pragma once

#include "../template.hpp"

struct khan {
    vector<vector<ll>> g;
    vector<ll> indeg;
    khan(ll n) : g(n), indeg(n) {}
    void add_edge(ll from, ll to) { g[from].push_back(to), ++indeg[to]; }
    vector<ll> get() {
        vector<ll> _indeg(indeg), ret;
        for (ll i : rep(g.size())) {
            if (_indeg[i] == 0) ret.push_back(i);
        }
        for (ll i : rep(g.size())) {
            if (i >= ret.size()) return {};
            for (ll to : g[ret[i]]) {
                if (--_indeg[to] == 0) ret.push_back(to);
            }
        }
        return ret;
    }
};