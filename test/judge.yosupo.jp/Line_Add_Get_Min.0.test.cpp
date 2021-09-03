#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../../data_structure/cht.hpp"

int main() {
    ll n, q;
    cin >> n >> q;
    cht<ll_cht, true> cht;
    for (ll i : rep(n)) {
        ll a, b;
        cin >> a >> b;
        cht.add(a, b);
    }
    for (ll i : rep(q)) {
        ll t;
        cin >> t;
        if (t == 0) {
            ll a, b;
            cin >> a >> b;
            cht.add(a, b);
        }
        if (t == 1) {
            ll p;
            cin >> p;
            cout << cht.get(p) << endl;
        }
    }
}