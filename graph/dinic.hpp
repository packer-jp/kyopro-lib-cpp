#pragma once

#include "../template.hpp"

template <typename S> struct dinic {
    using C = typename S::cost_t;
    struct edge {
        int to, rev;
        C cap;
        bool is_rev;
    };
    vector<vector<edge>> graph;
    vector<int> level, iter;
    void add_edge(int from, int to, C cap) {
        graph[from].push_back({to, (int)graph[to].size(), cap, false});
        graph[to].push_back({from, (int)graph[from].size() - 1, S::zero(), true});
    }
    dinic(int n) : graph(n), level(n), iter(n) {}
    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (edge &e : graph[v]) {
                if (e.cap == S::zero() || level[e.to] >= 0) continue;
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
    C dfs(int v, int t, C f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < graph[v].size(); ++i) {
            edge &e = graph[v][i];
            if (level[v] >= level[e.to] || e.cap == S::zero()) continue;
            C d = dfs(e.to, t, f > e.cap ? e.cap : f);
            if (d == S::zero()) continue;
            e.cap -= d;
            graph[e.to][e.rev].cap += d;
            return d;
        }
        return S::zero();
    }
    C calc_max_flow(int s, int t, C lim) {
        C ret = S::zero();
        while (true) {
            bfs(s);
            if (level[t] < 0 || lim == S::zero()) { return ret; }
            fill(iter.begin(), iter.end(), 0);
            C f;
            while ((f = dfs(s, t, lim)) != S::zero()) {
                ret += f;
                lim -= f;
            }
        }
    }
    C calc_max_flow(int s, int t) { return calc_max_flow(s, t, S::inf()); }
    map<pair<int, int>, C> get_max_flow() {
        map<pair<int, int>, C> ret;
        for (int i : rep(graph.size())) {
            for (edge &e : graph[i]) {
                if (e.is_rev) ret[{e.to, i}] = e.cap;
            }
        }
        return ret;
    }
    map<pair<int, int>, C> get_min_cut(int s) {
        map<pair<int, int>, C> ret;
        vector<int> visited(graph.size());
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            if (visited[v]) continue;
            visited[v] = true;
            for (edge &e : graph[v]) {
                if (e.cap != S::zero()) que.push(e.to);
            }
        }
        for (int i : rep(graph.size())) {
            if (visited[i]) continue;
            for (edge &e : graph[i]) {
                if (e.is_rev && visited[e.to]) ret[{e.to, i}] = e.cap;
            }
        }
        return ret;
    }
};

struct ll_dinic {
    using cost_t = ll;
    static cost_t zero() { return 0; }
    static cost_t inf() { return numeric_limits<cost_t>::max(); }
};