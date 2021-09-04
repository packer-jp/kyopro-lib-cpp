#pragma once

#include "../template.hpp"

template <typename F> ll bisect(ll ok, ll ng, F f) {
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}

template <typename F> double continuous_bisect(double ok, double ng, F f, int n) {
    while (n--) {
        double mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}