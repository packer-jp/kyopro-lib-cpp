#pragma once

#include "../template.hpp"

struct zobfs {
    struct edge {
        ll to, cost;
        edge(ll to, ll cost) : to(to), cost(cost) {}
    };
    vector<vector<edge>> adj;
    zobfs(ll n) : adj(n) {}
    void add_edge(ll from, ll to, ll cost) { adj[from].emplace_back(to, cost); }
    pair<vector<ll>, vector<ll>> get(int s) const {
        vector<ll> dist(adj.size(), LLONG_MAX), prev(adj.size(), -1);
        using P = pair<ll, ll>;
        deque<P> deq;
        dist[s] = 0;
        deq.emplace_front(0, s);
        while (!deq.empty()) {
            auto [d, i] = deq.front();
            deq.pop_front();
            if (dist[i] < d) continue;
            for (auto [to, cost] : adj[i]) {
                ll nd = dist[i] + cost;
                if (nd < dist[to]) {
                    dist[to] = nd;
                    prev[to] = i;
                    if (cost == 0) deq.emplace_front(nd, to);
                    if (cost == 1) deq.emplace_back(nd, to);
                }
            }
        }
        return {dist, prev};
    }
};