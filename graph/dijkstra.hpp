#pragma once

#include "../template.hpp"

template <typename S> struct dijkstra {
    using D = typename S::dist_t;
    using C = typename S::cost_t;
    struct edge {
        int to;
        C cost;
    };
    vector<vector<edge>> adj;
    dijkstra(int n) : adj(n) {}
    void add_edge(int from, int to, const C &cost) { adj[from].push_back({to, cost}); }
    pair<vector<D>, vector<int>> get(int s, const D &base = D()) const {
        vector<D> dist(adj.size(), S::inf());
        vector<int> prev(adj.size(), -1);
        using P = pair<D, int>;
        priority_queue_rev<P> pq;
        dist[s] = base;
        pq.emplace(base, s);
        while (!pq.empty()) {
            auto [d, from] = pq.top();
            pq.pop();
            if (dist[from] < d) continue;
            for (auto [to, cost] : adj[from]) {
                D nd = d + cost;
                if (nd < dist[to]) {
                    dist[to] = nd;
                    prev[to] = from;
                    pq.emplace(nd, to);
                }
            }
        }
        return {dist, prev};
    }
};

struct ll_dij {
    using dist_t = ll;
    using cost_t = ll;
    static dist_t inf() { return LLONG_MAX; }
};