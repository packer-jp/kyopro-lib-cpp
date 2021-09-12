#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"
#include "../../graph/dinic.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ll v, e;
    cin >> v >> e;
    dinic<ll_dinic> dinic(v);
    while (e--) {
        int u, v, c;
        cin >> u >> v >> c;
        dinic.add_edge(u, v, c);
    }
    dinic.calc_max_flow(0, v - 1);
    auto cut = dinic.get_min_cut(0);
    ll ans = 0;
    for (auto p : cut) ans += p.second;
    cout << ans << endl;
}