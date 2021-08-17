#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_A"
#include "../../data_structure/segtree.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (ll i : rep(n)) cin >> a[i];
    segtree<sum_monoid> st(a);
    ll ans = LLONG_MAX;
    for (ll l : rep(n)) {
        ll r = st.max_right(l, [&](ll x) { return x < s; });
        if (r < n) chmin(ans, r - l + 1);
    }
    if (ans == LLONG_MAX) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }
}