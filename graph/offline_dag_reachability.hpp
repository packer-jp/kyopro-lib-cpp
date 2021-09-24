#pragma once

#include "../template.hpp"
#include "../util/dynamic_bitset.hpp"
#include "khan.hpp"

struct offline_dag_reachability {
    khan ts;
    offline_dag_reachability(int n) : ts(n) {}
    void add_edge(int from, int to) { ts.add_edge(from, to); }
    vector<bool> get(const vector<pair<int, int>> &q) {
        vector<bool> ret(q.size());
        vector<pair<int, int>> edges;
        for (int from : ts.get()) {
            for (int to : ts.g[from]) edges.emplace_back(from, to);
        }
        for (int i = 0; i < q.size(); i += 64) {
            int m = min(64, (int)q.size() - i);
            vector<ull> dp(ts.g.size());
            for (int j : rep(m)) dp[q[i + j].first] |= bit(j);
            for (auto [from, to] : edges) dp[to] |= dp[from];
            for (int j : rep(m)) ret[i + j] = (dp[q[i + j].second] >> j) & 1;
        }
        return ret;
    }
};