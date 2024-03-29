#include <algorithm>
#include <vector>
#include <cassert>

struct heavy_light_decomposition {
    std::vector<std::vector<int>> adj;
    std::vector<int> par, sz, depth, in, out, head;
    heavy_light_decomposition(int n) : adj(n), par(n), sz(n), depth(n), in(n), out(n), head(n) {}
    void add_edge(int u, int v) { adj[u].emplace_back(v), adj[v].emplace_back(u); }
    void dfs_size(int v, int p) {
        sz[v] = 1;
        par[v] = p;
        if (p != -1) { depth[v] = depth[p] + 1; }
        for (int i = 0; i < adj[v].size(); i++) {
            int &u = adj[v][i];
            if (u == p) { continue; }
            dfs_size(u, v);
            sz[v] += sz[u];
            if (sz[u] > sz[adj[v][0]]) { std::swap(u, adj[v][0]); }
        }
    }
    int dfs_hld(int v, int &t) {
        in[v] = t++;
        for (int i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i];
            if (u == par[v]) { continue; }
            head[u] = (i == 0 ? head[v] : u);
            dfs_hld(u, t);
        }
        return out[v] = t;
    }
    std::vector<int> build(int root) {
        dfs_size(root, -1);
        head[root] = root;
        int t = 0;
        dfs_hld(root, t);
        return in;
    }
    int get_lca(int u, int v) {
        while (true) {
            if (in[u] > in[v]) { std::swap(u, v); }
            if (head[u] == head[v]) { return u; }
            v = par[head[v]];
        }
    }
    int get_dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[get_lca(u, v)]; }
    std::vector<std::pair<int, int>> get_path(int u, int v, bool edge) {
        std::vector<std::pair<int, int>> a, b;
        while (true) {
            if (head[u] == head[v]) {
                if (edge) {
                    if (in[u] > in[v]) { a.push_back({in[u], in[v] + 1}); }
                    if (in[u] < in[v]) { a.push_back({in[u] + 1, in[v]}); }
                } else { a.push_back({in[u], in[v]}); }
                break;
            }
            if (in[u] > in[v]) {
                a.push_back({in[u], in[head[u]]});
                u = par[head[u]];
            } else {
                b.push_back({in[head[v]], in[v]});
                v = par[head[v]];
            }
        }
        std::reverse(b.begin(), b.end());
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
    std::pair<int, int> get_subtree(int v, bool edge) { return {in[v] + edge, out[v] - 1}; }
};