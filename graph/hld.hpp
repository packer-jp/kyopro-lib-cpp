#pragma once

#include "../template.hpp"

struct hld {
    vector<vector<ll>> g;
    vector<ll> par, sz, dep, in, out, head;
    hld(ll n) : g(n), par(n), sz(n), dep(n), in(n), out(n), head(n) {}
    void add_edge(ll u, ll v) { g[u].push_back(v), g[v].push_back(u); }
    vector<ll> build(ll root) {
        auto dfs_sz = [&](auto dfs_sz, ll v, ll p) -> void {
            sz[v] = 1;
            par[v] = p;
            if (p != -1) dep[v] = dep[p] + 1;
            for (ll &u : g[v]) {
                if (u == p) continue;
                dfs_sz(dfs_sz, u, v);
                sz[v] += sz[u];
                if (sz[u] > sz[g[v][0]]) swap(u, g[v][0]);
            }
        };
        ll t = 0;
        auto dfs_hld = [&](auto dfs_hld, ll v) -> ll {
            in[v] = t++;
            for (ll i : rep(g[v].size())) {
                ll u = g[v][i];
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
    ll lca(ll u, ll v) const {
        while (true) {
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }
    ll dist(ll u, ll v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
    vector<pair<ll, ll>> get_path(ll u, ll v, bool edge) const {
        vector<pair<ll, ll>> a, b;
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
    pair<ll, ll> get_subtree(ll v, bool edge) const { return {in[v] + edge, out[v] - 1}; }
};