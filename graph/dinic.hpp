#pragma once

#include "../template.hpp"

template <typename S> struct dinic {
    using C = typename S::cost_t;
    struct _edge {
        int to, rev;
        C cap;
    };
    struct edge {
        int from, to;
        C cap, flow;
    };
    vector<vector<_edge>> g;
    vector<int> level, iter;
    vector<pair<int, int>> pos;
    dinic(int n) : g(n), level(n), iter(n) {}
    int add_edge(int from, int to, C cap) {
        int from_id = g[from].size();
        int to_id = g[to].size();
        if (from == to) ++to_id;
        g[from].push_back({to, to_id, cap});
        g[to].push_back({from, from_id, S::zero()});
        pos.emplace_back(from, from_id);
        return pos.size() - 1;
    }
    void change_edge(int i, C new_cap, C new_flow) {
        _edge &e = g[pos[i].first][pos[i].second], &re = g[e.to][e.rev];
        e.cap = new_cap - new_flow;
        re.cap = new_flow;
    }
    C flow(int s, int t, C lim = S::inf()) {
        auto bfs = [&](int s) -> void {
            fill(level.begin(), level.end(), -1);
            queue<int> q;
            level[s] = 0;
            q.push(s);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (_edge &e : g[v]) {
                    if (e.cap == S::zero() || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        };
        auto dfs = [&](auto dfs, int v, int t, C lim) -> C {
            if (v == t) return lim;
            for (int &i = iter[v]; i < g[v].size(); ++i) {
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
    edge get_edge(int i) const {
        _edge e = g[pos[i].first][pos[i].second], re = g[e.to][e.rev];
        return {pos[i].first, e.to, e.cap + re.cap, re.cap};
    }
    vector<edge> edges() const {
        vector<edge> ret(pos.size());
        for (int i : rep(pos.size())) ret[i] = get_edge(i);
        return ret;
    }
    vector<bool> min_cut(int s) const {
        vector<bool> ret(g.size());
        auto dfs = [&](auto dfs, int v) -> void {
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
    using cost_t = ll;
    static cost_t zero() { return 0; }
    static cost_t inf() { return numeric_limits<cost_t>::max(); }
};