#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"
#include "../../math/fps.hpp"

int main() {
    using mint = modint<998244353>;
    ll n;
    cin >> n;
    fps<mint> a(n);
    rep(i, n) cin >> a[i];
    fps<mint> b = a.log();
    rep(i, n) cout << b[i] << " ";
    cout << endl;
}