#pragma once

#include "../template.hpp"

template <typename S> struct spfa {
    using D = typename S::D;
    using C = typename S::C;
    struct edge {
        ll to;
        C cost;
    };
    vector<vector<edge>> g;
    spfa(ll n) : g(n) {}
    void add_edge(ll from, ll to, const C &cost) { g[from].push_back({to, cost}); }
    pair<vector<D>, vector<ll>> get(ll s, const D &base = D()) const {
        ll n = g.size();
        vector<D> dist(n, S::inf());
        vector<ll> prev(n, -1), time(n);
        vector<bool> inq(n);
        queue<ll> q;
        q.push(s);
        dist[s] = base;
        ++time[s];
        while (!q.empty()) {
            ll from = q.front();
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
    using D = ll;
    using C = ll;
    static D inf() { return LLONG_MAX; }
};