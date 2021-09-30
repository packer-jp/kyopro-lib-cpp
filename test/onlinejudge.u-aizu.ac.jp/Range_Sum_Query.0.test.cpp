#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"
#include "../../data_structure/fenwick_tree.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n, q;
    cin >> n >> q;
    fenwick_tree<ll> ft(n);
    while (q--) {
        ll com, x, y;
        cin >> com >> x >> y, --x;
        if (com == 0) {
            ft.add(x, y);
        } else if (com == 1) {
            cout << ft.sum(x, y) << endl;
        }
    }
}