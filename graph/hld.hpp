#pragma once

#include "../template.hpp"

struct hld {
    vector<vector<int>> g;
    vector<int> par, sz, dep, in, out, head;
    hld(int n) : g(n), par(n), sz(n), dep(n), in(n), out(n), head(n) {}
    void add_edge(int u, int v) { g[u].push_back(v), g[v].push_back(u); }
    vector<int> build(int root) {
        auto dfs_sz = [&](auto dfs_sz, int v, int p) -> void {
            sz[v] = 1;
            par[v] = p;
            if (p != -1) dep[v] = dep[p] + 1;
            for (int &u : g[v]) {
                if (u == p) continue;
                dfs_sz(dfs_sz, u, v);
                sz[v] += sz[u];
                if (sz[u] > sz[g[v][0]]) swap(u, g[v][0]);
            }
        };
        int t = 0;
        auto dfs_hld = [&](auto dfs_hld, int v) -> int {
            in[v] = t++;
            for (int i : rep(g[v].size())) {
                int u = g[v][i];
                if (u == par[v]) continue;
                head[u] = (i == 0 ? head[v] : u);
                dfs_hld(dfs_hld, u);
            }
            return out[v] = t;
        };
        dfs_sz(dfs_sz, root, -1);
        head[root] = root;
        dfs_hld(dfs_hld, root);
        return in;
    }
    int lca(int u, int v) const {
        while (true) {
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }
    int dist(int u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
    vector<pair<int, int>> get_path(int u, int v, bool edge) const {
        vector<pair<int, int>> a, b;
        while (true) {
            if (head[u] == head[v]) {
                if (edge) {
                    if (in[u] > in[v]) a.emplace_back(in[u], in[v] + 1);
                    if (in[u] < in[v]) a.emplace_back(in[u] + 1, in[v]);
                } else {
                    a.emplace_back(in[u], in[v]);
                }
                break;
            }
            if (in[u] > in[v]) {
                a.emplace_back(in[u], in[head[u]]);
                u = par[head[u]];
            } else {
                b.emplace_back(in[head[v]], in[v]);
                v = par[head[v]];
            }
        }
        a.insert(a.end(), b.rbegin(), b.rend());
        return a;
    }
    pair<int, int> get_subtree(int v, bool edge) const { return {in[v] + edge, out[v] - 1}; }
};