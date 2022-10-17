#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja"
#include "../../data_structure/segtree.hpp"
#include "../../graph/hld.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n = 10;
    struct str_monoid {
        using V = string;
        static V op(V a, V b) { return a + b; }
        static V e() { return ""; }
    };
    segtree<str_monoid> st_fwd(n), st_rev(n);
    vector<string> weight = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    hld hld(n);
    hld.add_edge(7, 2);
    hld.add_edge(2, 6);
    hld.add_edge(4, 2);
    hld.add_edge(4, 3);
    hld.add_edge(5, 4);
    hld.add_edge(5, 1);
    hld.add_edge(1, 0);
    hld.add_edge(0, 9);
    hld.add_edge(5, 8);
    vector<ll> in = hld.build(5);
    for (ll i : rep(n)) {
        st_fwd.set(in[i], weight[i]);
        st_rev.set(n - in[i] - 1, weight[i]);
    }
    auto path = [&](ll u, ll v) {
        string ret = "";
        vector<pair<ll, ll>> path = hld.get_path(u, v, false);
        for (ll i : rep(path.size())) {
            ll l = path[i].first, r = path[i].second;
            if (l < r) {
                ret += st_fwd.prod(l, r + 1);
            } else {
                ret += st_rev.prod(n - l - 1, n - r);
            }
        }
        return ret;
    };
    auto subtree = [&](ll v) {
        pair<ll, ll> subtree = hld.get_subtree(v, false);
        return st_fwd.prod(subtree.first, subtree.second + 1);
    };
    assert(path(2, 1) == "cefb");
    assert(path(5, 3) == "fed");
    assert(path(7, 4) == "hce");
    assert(path(4, 4) == "e");
    assert(subtree(2) == "chg");
    assert(subtree(5) == "fechgdbaji");
    assert(hld.dist(2, 0) == 4);
    assert(hld.dist(4, 1) == 2);

    cout << "Hello World" << endl;
}