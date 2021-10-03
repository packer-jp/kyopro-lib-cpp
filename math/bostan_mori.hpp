#pragma once

#include "../template.hpp"
#include "fps.hpp"

template <typename T> T bostan_mori(fps<T> p, fps<T> q, ll k) {
    while (k) {
        fps<T> _q(q);
        for (int i = 1; i < _q.size(); i += 2) _q[i] = -_q[i];
        fps<T> u = p * _q, v = q * _q;
        p.resize((u.size() >> 1) + (u.size() & ~k & 1)), q.resize((v.size() >> 1) + 1);
        for (int i : rep(p.size())) p[i] = u[i << 1 | k & 1];
        for (int i : rep(q.size())) q[i] = v[i << 1];
        k >>= 1;
    }
    return p[0];
}