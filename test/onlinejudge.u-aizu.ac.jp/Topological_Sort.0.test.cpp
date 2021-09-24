#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B"
#include "../../graph/khan.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ll v, e;
    cin >> v >> e;
    khan khan(v);
    for (ll i : rep(e)) {
        ll s, t;
        cin >> s >> t;
        khan.add_edge(s, t);
    }
    auto ans = khan.get();
    for (ll a : ans) cout << a << endl;
}