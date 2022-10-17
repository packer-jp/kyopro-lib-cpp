#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include "../../math/fps.hpp"

int main() {
    using mint = modint998244353;
    ll n;
    cin >> n;
    fps<mint> a(n);
    for (ll i : rep(n)) cin >> a[i];
    fps<mint> b = a.exp(n);
    for (ll i : rep(n)) cout << b[i] << " ";
    cout << endl;
}