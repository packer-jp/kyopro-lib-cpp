#pragma once

#include "../template.hpp"
#include "bostan_mori.hpp"

template <typename V> V kth_of_lrs(const vector<V> &a, const vector<V> &c, ll k) {
    fps<V> q = {1};
    q.insert(end(q), begin(c), end(c));
    for (ll i : rep(1, q.size())) q[i] = -q[i];
    fps<V> p = (q * a).prefix(a.size());
    return bostan_mori(p, q, k);
}