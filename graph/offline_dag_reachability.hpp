#pragma once

#include "../template.hpp"
#include "../util/dynamic_bitset.hpp"
#include "khan.hpp"

struct offline_dag_reachability {
    khan ts;
    offline_dag_reachability(ll n) : ts(n) {}
    void add_edge(ll from, ll to) { ts.add_edge(from, to); }
    vector<bool> get(const vector<pair<ll, ll>> &q) {
        vector<bool> ret(q.size());
        vector<pll> edges;
        for (ll from : ts.get()) {
            for (ll to : ts.g[from]) edges.emplace_back(from, to);
        }
        for (ll i = 0; i < q.size(); i += 64) {
            ll m = min(64ll, (ll)q.size() - i);
            vector<ull> dp(ts.g.size());
            for (ll j : rep(m)) dp[q[i + j].first] |= bit(j);
            for (auto [from, to] : edges) dp[to] |= dp[from];
            for (ll j : rep(m)) ret[i + j] = (dp[q[i + j].second] >> j) & 1;
        }
        return ret;
    }
};