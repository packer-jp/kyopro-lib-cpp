#pragma once

#include "../template.hpp"

template <typename S> struct dijkstra {
    using D = typename S::D;
    using C = typename S::C;
    struct edge {
        ll to;
        C cost;
    };
    vector<vector<edge>> g;
    dijkstra(ll n) : g(n) {}
    void add_edge(ll from, ll to, const C &cost) { g[from].push_back({to, cost}); }
    pair<vector<D>, vector<ll>> get(ll s, const D &base = D()) const {
        vector<D> dist(g.size(), S::inf());
        vector<ll> prev(g.size(), -1);
        using P = pair<D, ll>;
        priority_queue_rev<P> pq;
        dist[s] = base;
        pq.emplace(base, s);
        while (!pq.empty()) {
            auto [d, from] = pq.top();
            pq.pop();
            if (dist[from] < d) continue;
            for (auto [to, cost] : g[from]) {
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

struct ll_dijkstra {
    using D = ll;
    using C = ll;
    static D inf() { return LLONG_MAX; }
};