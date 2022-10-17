#pragma once

#include "../template.hpp"
#include "../util/xorshift.hpp"

struct rolling_hash {
    static constexpr ull MOD = bit(61) - 1;
    static vector<ull> pbase;
    vector<ull> hash;
    static void resize_pbase(ll n) {
        ll sz = pbase.size();
        if (sz > n) return;
        pbase.resize(n + 1);
        for (ll i : rep(sz - 1, n)) pbase[i + 1] = mul(pbase[i], pbase[1]);
    }
    template <typename T> static T calc_mod(T val) {
        val = (val & MOD) + (val >> 61);
        if (val >= MOD) val -= MOD;
        return val;
    }
    static ull mul(ull a, ull b) { return calc_mod((__uint128_t)a * b); }
    static ull concat(ull lhs, ull rhs, ll rn) {
        resize_pbase(rn);
        return calc_mod(mul(lhs, pbase[rn]) + rhs);
    }
    rolling_hash(const string &src) : hash(src.size() + 1) {
        for (ll i : rep(src.size())) hash[i + 1] = calc_mod(mul(hash[i], pbase[1]) + src[i]);
        resize_pbase(src.size());
    }
    template <typename T> rolling_hash(const vector<T> &src) : hash(src.size() + 1) {
        for (ll i : rep(src.size())) hash[i + 1] = calc_mod(mul(hash[i], pbase[1]) + src[i]);
        resize_pbase(src.size());
    }
    ull get_hash(ll l, ll r) const { return calc_mod(MOD - mul(hash[l], pbase[r - l]) + hash[r]); }
};
vector<ull> rolling_hash::pbase{1, xor64(MOD >> 1, MOD)};