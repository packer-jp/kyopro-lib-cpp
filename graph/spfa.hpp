#pragma once

#include "../template.hpp"

template <typename S> struct spfa {
    using D = typename S::dist_t;
    using C = typename S::cost_t;
    struct edge {
        int to;
        C cost;
    };
    vector<vector<edge>> g;
    spfa(int n) : g(n) {}
    void add_edge(int from, int to, const C &cost) { g[from].push_back({to, cost}); }
    pair<vector<D>, vector<int>> get(int s, const D &base = D()) const {
        int n = g.size();
        vector<D> dist(n, S::inf());
        vector<int> prev(n, -1), time(n);
        vector<bool> inq(n);
        queue<int> q;
        q.push(s);
        dist[s] = base;
        ++time[s];
        while (!q.empty()) {
            int from = q.front();
            q.pop();
            inq[from] = false;
            for (auto [to, cost] : g[from]) {
                if (chmin(dist[to], dist[from] + cost)) {
                    prev[to] = from;
                    if (!inq[to]) {
                        if (++time[to] >= n) return {{}, {}};
                        q.push(to);
                        inq[to] = true;
                    }
                }
            }
        }
        return {dist, prev};
    }
};

struct ll_spfa {
    using dist_t = ll;
    using cost_t = ll;
    static dist_t inf() { return LLONG_MAX; }
};