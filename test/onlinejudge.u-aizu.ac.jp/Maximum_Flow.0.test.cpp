#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"
#include "../../graph/dinic.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ll v, e;
    cin >> v >> e;
    dinic<ll_dinic> dinic(v);
    while (e--) {
        ll u, v, c;
        cin >> u >> v >> c;
        dinic.add_edge(u, v, c);
    }
    ll ans = dinic.flow(0, v - 1);
    cout << ans << endl;
}