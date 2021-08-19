#pragma once

#include "../template.hpp"

template <typename mint> struct combination {
    vector<mint> fact, finv, inv;
    combination(int n) : fact(n + 1), finv(n + 1), inv(n + 1) {
        fact[0] = fact[1] = finv[0] = finv[1] = inv[1] = 1;
        for (int i : rep(2, n + 1)) {
            fact[i] = fact[i - 1] * i;
            inv[i] = -inv[mint::mod() % i] * (mit::mod() / i);
            finv[i] = finv[i - 1] * inv[i];
        }
    }
    T P(int n, int r) { return r < 0 || n < r ? 0 : (fact[n] * finv[n - r]); }
    T C(int n, int r) { return P(n, r) * finv[r]; }
    T H(int n, int r) { return C(n + r - 1, r); }
    T catalan(int n) { return C(2 * n, n) / (n + 1); }
};