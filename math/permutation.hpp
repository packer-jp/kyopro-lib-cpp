#pragma once

#include "../template.hpp"

struct permutation {
    vector<ll> data;
    permutation(ll n) : data(n) { iota(all(data), 0); }
    permutation(const vector<ll> &src) : data(src) {}
    ll size() const { return data.size(); }
    static permutation id(ll n) {
        vector<ll> ret(n);
        iota(all(ret), 0);
        return ret;
    }
    bool next() { return next_permutation(all(data)); }
    bool prev() { return prev_permutation(all(data)); }
    ll operator[](ll i) const { return data[i]; }
    permutation &operator*=(const permutation &a) {
        vector<ll> tmp(data);
        for (ll i : rep(size())) data[i] = tmp[a[i]];
        return *this;
    }
    permutation &operator/=(const permutation &a) { return *this *= a.inv(); }
    friend bool operator==(const permutation &a, const permutation &b) { return a.data == b.data; }
    friend bool operator!=(const permutation &a, const permutation &b) { return rel_ops::operator!=(a, b); }
    friend permutation operator*(permutation a, const permutation &b) { return a *= b; }
    friend permutation operator/(permutation a, const permutation &b) { return a /= b; }
    permutation inv() const {
        vector<ll> ret(size());
        for (ll i : rep(size())) ret[data[i]] = i;
        return ret;
    }
    permutation pow(ll k) const {
        vector<ll> ret(size());
        vector<bool> used(size());
        for (ll i : rep(size())) {
            if (used[i]) { continue; }
            vector<ll> cyc;
            ll cur = i;
            do {
                used[cur] = true;
                cyc.push_back(cur);
                cur = data[cur];
            } while (cur != i);
            for (ll j : rep(cyc.size())) ret[cyc[j]] = cyc[(j + k) % cyc.size()];
        }
        return ret;
    }
    friend ostream &operator<<(std::ostream &os, const permutation &a) {
        os << "(";
        for (ll i : rep(a.size())) { os << a[i] << (i + 1 != a.size() ? ", " : ""); }
        os << ")";
        return os;
    }
};