#pragma once

#include "../template.hpp"

template <typename mint> struct combination {
    vector<mint> fact, finv, inv;
    combination(ll n) : fact(n + 1), finv(n + 1), inv(n + 1) {
        fact[0] = fact[1] = finv[0] = finv[1] = inv[1] = 1;
        for (ll i : rep(2, n + 1)) {
            fact[i] = fact[i - 1] * i;
            inv[i] = -inv[mint::mod() % i] * (mint::mod() / i);
            finv[i] = finv[i - 1] * inv[i];
        }
    }
    mint P(ll n, ll r) { return r < 0 || n < r ? 0 : (fact[n] * finv[n - r]); }
    mint C(ll n, ll r) { return P(n, r) * finv[r]; }
    mint H(ll n, ll r) { return C(n + r - 1, r); }
    mint catalan(ll n) { return C(2 * n, n) / (n + 1); }
};