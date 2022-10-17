#pragma once

#include "../template.hpp"

struct unionfind {
    ll n;
    vector<ll> ps;
    unionfind(ll n) : n(n), ps(n, -1) {}
    ll find(ll i) {
        if (ps[i] < 0) return i;
        return ps[i] = find(ps[i]);
    }
    ll size(ll i) { return -ps[find(i)]; }
    void unite(ll i, ll j) {
        if ((i = find(i)) == (j = find(j))) return;
        if (-ps[i] < -ps[j]) swap(i, j);
        ps[i] += ps[j];
        ps[j] = i;
    }
    bool same(ll i, ll j) { return find(i) == find(j); }
    vector<vector<ll>> groups() {
        vector<vector<ll>> ret(n);
        for (ll i : rep(n)) ret[find(i)].push_back(i);
        ret.erase(remove_if(all(ret), [](const vector<ll> &v) { return v.empty(); }), ret.end());
        return ret;
    }
};