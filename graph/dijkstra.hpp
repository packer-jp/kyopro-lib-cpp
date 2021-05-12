#ifndef PWMTREE_DIJKSTRA_HPP
#define PWMTREE_DIJKSTRA_HPP 1

#include "../template.hpp"

template <typename S> struct dijkstra {
    using D = typename S::dist_t;
    using C = typename S::cost_t;
    struct edge {
        int to;
        C cost;
        edge(int to, C cost) : to(to), cost(cost) {}
    };
    vector<vector<edge>> adj;
    dijkstra(int n) : adj(n) {}
    void add_edge(int from, int to, C cost) { adj[from].emplace_back(to, cost); }
    pair<vector<D>, vector<int>> get(int s, D base) {
        vector<D> dist(adj.size(), S::inf());
        vector<int> prev(adj.size(), -1);
        using P = pair<D, int>;
        priority_queue_rev<P> pq;
        dist[s] = base;
        pq.emplace(base, s);
        while (!pq.empty()) {
            auto [d, i] = pq.top();
            pq.pop();
            if (dist[i] < d) continue;
            for (auto [to, cost] : adj[i]) {
                D nd = d + cost;
                if (nd < dist[to]) {
                    dist[to] = nd;
                    prev[to] = i;
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

#endif