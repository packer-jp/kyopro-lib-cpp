#pragma once

#include "../template.hpp"

template <typename D> pair<D, vll> kruskal(ll n, const vector<tuple<ll, ll, D>> &g) {
    unionfind uf(n);
    vll p(g.size());
    iota(all(p), 0ll);
    sort(all(p), [&](ll l, ll r) -> bool { return get<2>(g[l]) < get<2>(g[r]); });
    D sum = 0;
    vll used;
    for (ll i : rep(g.size())) {
        auto [u, v, d] = g[p[i]];
        if (!uf.same(u, v)) {
            uf.unite(u, v);
            sum += d;
            used.push_back(p[i]);
        }
    }
    return {sum, used};
}