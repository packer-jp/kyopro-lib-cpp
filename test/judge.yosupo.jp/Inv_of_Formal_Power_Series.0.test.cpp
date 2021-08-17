#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
#include "../../math/fps.hpp"

int main() {
    using mint = modint<998244353>;
    ll n;
    cin >> n;
    fps<mint> a(n);
    for (ll i : range(n)) cin >> a[i];
    fps<mint> b = a.inv();
    for (ll i : range(n)) cout << b[i] << " ";
    cout << endl;
}