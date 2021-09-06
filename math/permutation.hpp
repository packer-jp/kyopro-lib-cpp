#pragma once

#include "../template.hpp"

struct permutation {
    vector<int> data;
    permutation(int n) : data(n) { iota(all(data), 0); }
    permutation(const vector<int> &src) : data(src) {}
    int size() const { return data.size(); }
    static permutation id(int n) {
        vector<int> ret(n);
        iota(all(ret), 0);
        return ret;
    }
    bool next() { return next_permutation(all(data)); }
    bool prev() { return prev_permutation(all(data)); }
    int operator[](int i) const { return data[i]; }
    permutation &operator*=(const permutation &a) {
        vector<int> tmp(data);
        for (int i : rep(size())) data[i] = tmp[a[i]];
        return *this;
    }
    permutation &operator/=(const permutation &a) { return *this *= a.inv(); }
    friend bool operator==(const permutation &a, const permutation &b) { return a.data == b.data; }
    friend bool operator!=(const permutation &a, const permutation &b) { return rel_ops::operator!=(a, b); }
    friend permutation operator*(permutation a, const permutation &b) { return a *= b; }
    friend permutation operator/(permutation a, const permutation &b) { return a /= b; }
    permutation inv() const {
        vector<int> ret(size());
        for (int i : rep(size())) ret[data[i]] = i;
        return ret;
    }
    permutation pow(ll k) const {
        vector<int> ret(size());
        vector<bool> used(size());
        for (int i : rep(size())) {
            if (used[i]) { continue; }
            vector<int> cyc;
            int cur = i;
            do {
                used[cur] = true;
                cyc.push_back(cur);
                cur = data[cur];
            } while (cur != i);
            for (int j : rep(cyc.size())) ret[cyc[j]] = cyc[(j + k) % cyc.size()];
        }
        return ret;
    }
    friend ostream &operator<<(std::ostream &os, const permutation &a) {
        os << "(";
        for (int i = 0; i < a.size(); i++) { os << a[i] << (i + 1 != a.size() ? ", " : ""); }
        os << ")";
        return os;
    }
};