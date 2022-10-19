#pragma once

#include "../template.hpp"
#include "fps.hpp"

template <typename V> V bostan_mori(fps<V> p, fps<V> q, ll k) {
    while (k) {
        fps<V> _q(q);
        for (ll i = 1; i < _q.size(); i += 2) _q[i] = -_q[i];
        fps<V> u = p * _q, v = q * _q;
        p.resize((u.size() >> 1) + (u.size() & ~k & 1)), q.resize((v.size() >> 1) + 1);
        for (ll i : rep(p.size())) p[i] = u[i << 1 | (k & 1)];
        for (ll i : rep(q.size())) q[i] = v[i << 1];
        k >>= 1;
    }
    return p[0];
}