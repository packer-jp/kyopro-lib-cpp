#pragma once

#include "../template.hpp"

template <typename P> struct unionfind {
    using V = typename P::V;
    ll n;
    vector<ll> ps;
    vector<V> val;
    unionfind(const vector<V> &val) : n(val.size()), ps(n, -1), val(val) {}
    unionfind(ll n, const V &a = {}) : unionfind(vector<V>(n, a)) {}
    ll find(ll i) {
        if (ps[i] < 0) return i;
        return ps[i] = find(ps[i]);
    }
    ll size(ll i) { return -ps[find(i)]; }
    void unite(ll i, ll j) {
        if ((i = find(i)) == (j = find(j))) return;
        if (-ps[i] < -ps[j]) swap(i, j);
        ps[i] += ps[j];
        P::merge(val[i], val[j]);
        ps[j] = i;
    }
    bool same(ll i, ll j) { return find(i) == find(j); }
    V &operator[](ll i) { return val[find(i)]; }
    vector<vector<ll>> groups() {
        vector<vector<ll>> ret(n);
        for (ll i : rep(n)) ret[find(i)].push_back(i);
        ret.erase(remove_if(all(ret), [](const vector<ll> &v) { return v.empty(); }), ret.end());
        return ret;
    }
};
struct normal_uf {
    using V = struct {};
    static void merge(V &a, const V &b) {}
};