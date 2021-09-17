#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/TUATPC/3198"
#include "../../graph/dinic.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    dinic<ll_dinic> dinic(n * 2 + 2);
    vector id(n, Vl(n, -1));
    ll s = n * 2, t = n * 2 + 1;
    for (ll i : rep(n)) {
        dinic.add_edge(s, i, 1);
        dinic.add_edge(i + n, t, 1);
    }
    for (ll i : rep(m)) {
        ll a, b;
        cin >> a >> b, --a, --b;
        id[a][b] = dinic.add_edge(a, b + n, 1);
    }
    ll q, f = dinic.flow(s, t);
    cin >> q;
    for (ll i : rep(q)) {
        ll x, y;
        cin >> x >> y, --x, --y;
        if (id[x][y] == -1) {
            id[x][y] = dinic.add_edge(x, y + n, 1);
        } else {
            auto e = dinic.get_edge(id[x][y]);
            if (e.flow > 0) {
                dinic.flow(x, s, 1);
                dinic.flow(t, y + n, 1);
                --f;
            }
            dinic.change_edge(id[x][y], 0, 0);
            id[x][y] = -1;
        }
        f += dinic.flow(s, t);
        if (f == n) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}