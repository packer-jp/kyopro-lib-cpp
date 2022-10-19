#pragma once

#include "../template.hpp"

struct bfs01 {
    struct edge {
        ll to, cost;
    };
    vector<vector<edge>> g;
    bfs01(ll n) : g(n) {}
    void add_edge(ll from, ll to, ll cost) { g[from].push_back({to, cost}); }
    pair<vector<ll>, vector<ll>> get(ll s) const {
        vector<ll> dist(g.size(), LLONG_MAX), prev(g.size(), -1);
        using P = pair<ll, ll>;
        deque<P> deq;
        dist[s] = 0;
        deq.emplace_front(0, s);
        while (!deq.empty()) {
            auto [d, from] = deq.front();
            deq.pop_front();
            if (dist[from] < d) continue;
            for (auto [to, cost] : g[from]) {
                ll nd = dist[from] + cost;
                if (nd < dist[to]) {
                    dist[to] = nd;
                    prev[to] = from;
                    if (cost == 0) deq.emplace_front(nd, to);
                    if (cost == 1) deq.emplace_back(nd, to);
                }
            }
        }
        return {dist, prev};
    }
};