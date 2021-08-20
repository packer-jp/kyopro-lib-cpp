#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_A"
#include "../../data_structure/lazy_segtree.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n, s;
    cin >> n >> s;
    vector<pair<ll, ll>> a1(n);
    for (ll i : rep(n)) cin >> a1[i].first;
    lazy_segtree<sum_monoid_with_addition> lst(a1);
    ll ans = LLONG_MAX;
    for (ll l : rep(n)) {
        ll r = lst.max_right(l, [&](pair<ll, ll> x) { return x.first < s; });
        if (r < n) chmin(ans, r - l + 1);
    }
    if (ans == LLONG_MAX) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }
}