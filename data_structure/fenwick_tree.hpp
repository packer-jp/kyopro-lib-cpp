#pragma once

#include "../template.hpp"

template <typename T> struct fenwick_tree {
    vector<T> data;
    fenwick_tree(int n) : data(n + 1, T()) {}
    void add(int i, const T &x) {
        for (++i; i < data.size(); i += i & -i) data[i] += x;
    }
    T sum(int i) const {
        T ret = T();
        for (; i > 0; i -= i & -i) { ret += data[i]; }
        return ret;
    }
    T sum(int l, int r) const { return sum(r) - sum(l); }
};