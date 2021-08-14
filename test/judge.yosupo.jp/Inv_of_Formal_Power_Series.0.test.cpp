#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
#include "../../math/fps_friendly.hpp"

int main() {
    using mint = modint<998244353>;
    using fps = fps_friendly<mint, 3>;
    ll n;
    cin >> n;
    fps a(n);
    rep(i, n) cin >> a[i];
    fps a_inv = a.inv(n);
    rep(i, n) cout << a_inv[i] << " ";
    cout << endl;
}