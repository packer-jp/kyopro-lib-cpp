#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include "../../math/modlog.hpp"

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll x, y, m;
        cin >> x >> y >> m;
        if (y == 1 || m == 1) {
            cout << 0 << endl;
        } else {
            cout << modlog(x, y, m) << endl;
        }
    }
}