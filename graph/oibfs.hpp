#pragma once

#include "../template.hpp"

struct oibfs {
    struct edge {
        int to, cost;
    };
    vector<vector<edge>> adj;
    oibfs(int n) : adj(n) {}
    void add_edge(int from, int to, int cost) { adj[from].push_back({to, cost}); }
    pair<vector<int>, vector<int>> get(int s) const {
        vector<int> dist(adj.size(), INT_MAX), prev(adj.size(), -1);
        using P = pair<int, int>;
        deque<P> deq;
        dist[s] = 0;
        deq.emplace_front(0, s);
        while (!deq.empty()) {
            auto [d, from] = deq.front();
            deq.pop_front();
            if (dist[from] < d) continue;
            for (auto [to, cost] : adj[from]) {
                int nd = dist[from] + cost;
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