#pragma once

#include "../template.hpp"
#include "bostan_mori.hpp"

template <typename T> T kth_of_lrs(const vector<T> &a, const vector<T> &c, ll k) {
    fps<T> q = {1};
    q.insert(end(q), begin(c), end(c));
    for (int i : rep(1, q.size())) q[i] = -q[i];
    fps<T> p = (q * a).prefix(a.size());
    return bostan_mori(p, q, k);
}