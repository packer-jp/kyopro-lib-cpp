#pragma once

#include "../template.hpp"

template <typename V> struct fenwick_tree {
    vector<V> data;
    fenwick_tree(ll n) : data(n + 1, V()) {}
    void add(ll i, const V &x) {
        for (++i; i < (ll)data.size(); i += i & -i) data[i] += x;
    }
    V sum(ll i) const {
        V ret = V();
        for (; i > 0; i -= i & -i) ret += data[i];
        return ret;
    }
    V sum(ll l, ll r) const { return sum(r) - sum(l); }
};

template <typename V> struct fenwick_tree_range {
    fenwick_tree<V> ft;
    fenwick_tree_range(ll n) : ft(n) {}
    void add(ll l, ll r, const V &x) { ft.add(l, x), ft.add(r, -x); }
    V get(ll i) const { return ft.sum(i + 1); }
};
