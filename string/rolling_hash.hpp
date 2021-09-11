#pragma once

#include "../template.hpp"
#include "../util/xorshift.hpp"

struct rolling_hash {
    static constexpr ull MOD = bit(61) - 1;
    static vector<ull> pb;
    vector<ull> hash;
    static void resize_pb(int n) {
        int sz = pb.size();
        if (sz > n) return;
        pb.resize(n + 1);
        for (int i : rep(sz - 1, n)) pb[i + 1] = mul(pb[i], pb[1]);
    }
    template <typename T> static T calc_mod(T val) {
        val = (val & MOD) + (val >> 61);
        if (val >= MOD) val -= MOD;
        return val;
    }
    static ull mul(ull a, ull b) { return calc_mod((__uint128_t)a * b); }
    static ull concat(ull lhs, ull rhs, int rn) {
        resize_pb(rn);
        return calc_mod(mul(lhs, pb[rn]) + rhs);
    }
    rolling_hash(const string &src) : hash(src.size() + 1) {
        for (int i : rep(src.size())) hash[i + 1] = calc_mod(mul(hash[i], pb[1]) + src[i]);
        resize_pb(src.size());
    }
    template <typename T> rolling_hash(const vector<T> &src) : hash(src.size() + 1) {
        for (int i : rep(src.size())) hash[i + 1] = calc_mod(mul(hash[i], pb[1]) + src[i]);
        resize_pb(src.size());
    }
    ull get_hash(int l, int r) const { return calc_mod((MOD << 2) - mul(hash[l], pb[r - l]) + hash[r]); }
};
vector<ull> rolling_hash::pb{1, xor64(MOD >> 1, MOD)};