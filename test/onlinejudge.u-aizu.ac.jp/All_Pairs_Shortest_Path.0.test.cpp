#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"
#include "../../graph/wf.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ll v, e;
    cin >> v >> e;
    vector adj(v, vll(v, LLONG_MAX));
    for (ll i : rep(v)) adj[i][i] = 0;
    while (e--) {
        ll s, t, d;
        cin >> s >> t >> d;
        adj[s][t] = d;
    }
    wf(adj);
    for (ll i : rep(v)) {
        if (adj[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for (ll i : rep(v)) {
        for (ll j : rep(v)) {
            if (adj[i][j] == LLONG_MAX) {
                cout << "INF";
            } else {
                cout << adj[i][j];
            }
            cout << (j == v - 1 ? "\n" : " ");
        }
    }
}