#pragma once

#include "../template.hpp"

template <typename T> struct fenwick_tree {
    vector<T> data;
    fenwick_tree(int n) : data(n + 1, T()) {}
    void add(int i, const T &x) {
        for (++i; i < (int)data.size(); i += i & -i) data[i] += x;
    }
    T sum(int i) const {
        T ret = T();
        for (; i > 0; i -= i & -i) ret += data[i];
        return ret;
    }
    T sum(int l, int r) const { return sum(r) - sum(l); }
};

template <typename T> struct fenwick_tree_range {
    fenwick_tree<T> ft;
    fenwick_tree_range(int n) : ft(n) {}
    void add(int l, int r, const T &x) { ft.add(l, x), ft.add(r, -x); }
    T get(int i) const { return ft.sum(i + 1); }
};
