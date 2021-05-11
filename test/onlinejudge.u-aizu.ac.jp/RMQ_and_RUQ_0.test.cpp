#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"
#include "../../data_structure/lazy_segtree.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> src(n, INT_MAX);
    lazy_segtree<min_monoid_with_update> lst(src);
    while (q--) {
        ll com;
        cin >> com;
        if (com == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            lst.apply(s, t + 1, x);
        } else if (com == 1) {
            ll s, t;
            cin >> s >> t;
            cout << lst.prod(s, t + 1) << endl;
        }
    }
}