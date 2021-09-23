#pragma once

#include "../template.hpp"

template <typename F> auto fibsect(ll lb, ll ub, F f) {
    if (ub - lb == 1) return make_pair(lb, f(lb));
    --lb;
    ll a = 1, b = 2;
    while (a + b < ub - lb) b += a, a = b - a;
    ll l = lb + a, r = lb + b;
    auto fl = f(l), fr = f(r);
    while (true) {
        a = b - a;
        b -= a;
        if (r < ub && fl < fr) {
            if (b == 1) return make_pair(r, fr);
            l = r, fl = fr;
            if ((r += b - a) < ub) fr = f(r);
        } else {
            if (b == 1) return make_pair(l, fl);
            r = l, fr = fl;
            l += a - b, fl = f(l);
        }
    }
}