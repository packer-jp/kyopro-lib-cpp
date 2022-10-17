#pragma once

#include "../template.hpp"
#include "persistent_array.hpp"

template <ll SHIFT> struct persistent_unionfind {
    ll n;
    persistent_array<ll, SHIFT> ps;
    persistent_unionfind(ll n) : n(n), ps(n, -1) {}
    persistent_unionfind(ll n, persistent_array<ll, SHIFT> ps) : n(n), ps(ps) {}
    pair<ll, ll> find_with_size(ll i) const {
        ll psi = ps.get(i);
        return psi < 0 ? make_pair(i, -psi) : find_with_size(psi);
    }
    ll find(ll i) const { return find_with_size(i).first; }
    ll size(ll i) const { return find_with_size(i).second; }
    bool same(ll i, ll j) const { return find(i) == find(j); }
    persistent_unionfind unite(ll i, ll j) const {
        auto [ip, si] = find_with_size(i);
        auto [jp, sj] = find_with_size(j);
        if (ip == jp) return *this;
        if (si < sj) swap(ip, jp);
        return persistent_unionfind(n, ps.set(ip, -si - sj).set(jp, ip));
    }
    vector<vector<ll>> groups() const {
        vector<vector<ll>> ret(n);
        for (ll i : rep(n)) ret[find(i)].push_back(i);
        ret.erase(remove_if(all(ret), [](const vector<ll> &v) { return v.empty(); }), ret.end());
        return ret;
    }
};