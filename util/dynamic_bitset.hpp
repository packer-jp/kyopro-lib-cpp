#pragma once

#include "../template.hpp"

struct dynamic_bitset {
    using db = dynamic_bitset;
    vector<ull> val;
    struct ref {
        ull &p;
        int i;
        ref(ull &p, int i) : p(p), i(i) {}
        ref &operator=(bool a) {
            if (a) {
                p |= bit(i);
            } else
                p &= ~bit(i);
            return *this;
        }
        ref &operator=(const ref &a) { return *this = a; }
        operator bool() const { return (p & bit(i)) != 0; }
        bool operator~() const { return !*this; }
        ref &flip() {
            p ^= bit(i);
            return *this;
        }
    };
    ref operator[](int i) {
        if (val.size() <= i >> 4) val.resize((i >> 4) + 1);
        return {val[i >> 4], i & 63};
    }
    db &operator&=(const db &a) {
        if (a.val.size() < val.size()) val.resize(a.val.size());
        for (int i : rep(a.val.size())) val[i] &= a.val[i];
        return *this;
    }
    db &operator|=(const db &a) {
        if (a.val.size() > val.size()) val.resize(a.val.size());
        for (int i : rep(a.val.size())) val[i] |= a.val[i];
        return *this;
    }
    db &operator^=(const db &a) {
        if (a.val.size() > val.size()) val.resize(a.val.size());
        for (int i : rep(a.val.size())) val[i] ^= a.val[i];
        return *this;
    }
    int count() const {
        int ret = 0;
        for (ull p : val) ret += __builtin_popcountll(p);
        return ret;
    }
    friend bool operator==(const db &a, const db &b) { return (a ^ b).count() == 0; }
    friend bool operator!=(const db &a, const db &b) { return rel_ops::operator!=(a, b); }
    friend bool operator<(const db &a, const db &b) {
        for (int i : per(max(a.val.size(), b.val.size()))) {
            ull pa = i < a.val.size() ? a.val[i] : 0;
            ull pb = i < b.val.size() ? b.val[i] : 0;
            if (pa < pb) return true;
            if (pa > pb) return false;
        }
        return false;
    }
    friend bool operator>(const db &a, const db &b) { return rel_ops::operator>(a, b); }
    friend bool operator<=(const db &a, const db &b) { return rel_ops::operator<=(a, b); }
    friend bool operator>=(const db &a, const db &b) { return rel_ops::operator>=(a, b); }
    friend db operator&(const db &a, const db &b) { return db(a) &= b; }
    friend db operator|(const db &a, const db &b) { return db(a) |= b; }
    friend db operator^(const db &a, const db &b) { return db(a) ^= b; }
};