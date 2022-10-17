#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"
#include "../../data_structure/persistent_array.hpp"

int main() {
    ll q;
    cin >> q;
    ll il = q, ir = q + 1;
    vector<persistent_array<ll, 2>> his;
    his.emplace_back(q + 2, 0);
    for (ll i : rep(q)) {
        ll c, t;
        cin >> c >> t, ++t;
        if (c == 0) {
            ll x;
            cin >> x;
            ll r = his[t].get(ir);
            his.emplace_back(his[t].set(r, x).set(ir, r + 1));
        }
        if (c == 1) {
            ll l = his[t].get(il);
            cout << his[t].get(l) << '\n';
            his.emplace_back(his[t].set(il, l + 1));
        }
    }
}