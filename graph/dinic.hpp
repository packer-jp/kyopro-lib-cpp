#pragma once

#include "../template.hpp"

template <typename S> struct dinic {
    using C = typename S::C;
    struct _edge {
        ll to, rev;
        C cap;
    };
    struct edge {
        ll from, to;
        C cap, flow;
        friend ostream &operator<<(ostream &os, const edge &e) {
            return os << "(from: " << e.from << ", to: " << e.to << ", cap: " << e.cap << ", flow: " << e.flow << ")";
        }
    };
    vector<vector<_edge>> g;
    vector<ll> level, iter;
    vector<pair<ll, ll>> pos;
    dinic(ll n) : g(n), level(n), iter(n) {}
    ll add_edge(ll from, ll to, C cap) {
        ll from_id = g[from].size();
        ll to_id = g[to].size();
        if (from == to) ++to_id;
        g[from].push_back({to, to_id, cap});
        g[to].push_back({from, from_id, S::zero()});
        pos.emplace_back(from, from_id);
        return pos.size() - 1;
    }
    void change_edge(ll i, C new_cap, C new_flow) {
        _edge &e = g[pos[i].first][pos[i].second], &re = g[e.to][e.rev];
        e.cap = new_cap - new_flow;
        re.cap = new_flow;
    }
    C flow(ll s, ll t, C lim = S::inf()) {
        auto bfs = [&](ll s) -> void {
            fill(level.begin(), level.end(), -1);
            queue<ll> q;
            level[s] = 0;
            q.push(s);
            while (!q.empty()) {
                ll v = q.front();
                q.pop();
                for (_edge &e : g[v]) {
                    if (e.cap == S::zero() || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        };
        auto dfs = [&](auto dfs, ll v, ll t, C lim) -> C {
            if (v == t) return lim;
            for (ll &i = iter[v]; i < (ll)g[v].size(); ++i) {
                _edge &e = g[v][i];
                if (level[v] >= level[e.to] || e.cap == S::zero()) continue;
                C d = dfs(dfs, e.to, t, lim > e.cap ? e.cap : lim);
                if (d == S::zero()) continue;
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
            return S::zero();
        };
        C ret = S::zero();
        while (true) {
            bfs(s);
            if (level[t] < 0 || lim == S::zero()) return ret;
            fill(iter.begin(), iter.end(), 0);
            C f;
            while ((f = dfs(dfs, s, t, lim)) != S::zero()) {
                ret += f;
                lim -= f;
            }
        }
    }
    edge get_edge(ll i) const {
        _edge e = g[pos[i].first][pos[i].second], re = g[e.to][e.rev];
        return {pos[i].first, e.to, e.cap + re.cap, re.cap};
    }
    vector<edge> edges() const {
        vector<edge> ret(pos.size());
        for (ll i : rep(pos.size())) ret[i] = get_edge(i);
        return ret;
    }
    vector<bool> cut(ll s) const {
        vector<bool> ret(g.size());
        auto dfs = [&](auto dfs, ll v) -> void {
            if (ret[v]) return;
            ret[v] = true;
            for (_edge e : g[v]) {
                if (e.cap) dfs(dfs, e.to);
            }
        };
        dfs(dfs, s);
        return ret;
    }
};

struct ll_dinic {
    using C = ll;
    static C zero() { return 0; }
    static C inf() { return numeric_limits<C>::max(); }
};