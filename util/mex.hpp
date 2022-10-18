#pragma once

#include "../template.hpp"

ll mex(const vll &v) {
    ll n = v.size();
    vll cnt(n);
    for (ll vi : v) {
        if (vi < n) ++cnt[vi];
    }
    for (ll i : rep(n)) {
        if (cnt[i] == 0) return i;
    }
    return n;
}