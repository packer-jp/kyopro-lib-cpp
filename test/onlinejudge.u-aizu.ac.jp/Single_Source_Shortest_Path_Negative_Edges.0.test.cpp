#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"
#include "../../graph/spfa.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ll v, e, r;
    cin >> v >> e >> r;
    spfa<ll_spfa> spfa(v);
    while (e--) {
        ll s, t, d;
        cin >> s >> t >> d;
        spfa.add_edge(s, t, d);
    }
    Vl res = spfa.get(r).first;
    if (res.empty()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (ll ans : res) {
        if (ans == ll_spfa::inf()) {
            cout << "INF" << endl;
        } else {
            cout << ans << endl;
        }
    }
}