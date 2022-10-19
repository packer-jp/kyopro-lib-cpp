#pragma once

#include "../template.hpp"

ll modlog(ll a, ll b, ll m) {
    a = safemod(a, m), b = safemod(b, m);
    ll t = 1, c;
    for (c = 1; pw(c) < m; ++c) {
        (t *= a) %= m;
        if (t == b) return c;
    }
    ll g = gcd(t, m);
    if (b % g != 0) return -1;
    t /= g, b /= g, m /= g;
    unordered_map<ll, ll> bs;
    ll r, gs = 1;
    for (r = 0; r * r < m; ++r) {
        bs[(gs * b) % m] = r;
        (gs *= a) %= m;
    }
    for (ll i : rep(1, r + 1)) {
        (t *= gs) %= m;
        if (bs.count(t)) return r * i - bs[t] + c - 1;
    }
    return -1;
}