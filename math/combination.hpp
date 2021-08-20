#pragma once

#include "../template.hpp"

template <typename mint> struct combination {
    vector<mint> fact, finv, inv;
    combination(int n) : fact(n + 1), finv(n + 1), inv(n + 1) {
        fact[0] = fact[1] = finv[0] = finv[1] = inv[1] = 1;
        for (int i : rep(2, n + 1)) {
            fact[i] = fact[i - 1] * i;
            inv[i] = -inv[mint::mod() % i] * (mint::mod() / i);
            finv[i] = finv[i - 1] * inv[i];
        }
    }
    mint P(int n, int r) { return r < 0 || n < r ? 0 : (fact[n] * finv[n - r]); }
    mint C(int n, int r) { return P(n, r) * finv[r]; }
    mint H(int n, int r) { return C(n + r - 1, r); }
    mint catalan(int n) { return C(2 * n, n) / (n + 1); }
};