#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../../math/and_or_convolution.hpp"
#include "../../math/modint.hpp"

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    using mint = modint<998244353>;
    ll n;
    cin >> n;
    vector<mint> a(bit(n)), b(bit(n));
    for (ll i : rep(bit(n))) cin >> a[i];
    for (ll i : rep(bit(n))) cin >> b[i];
    for (ll i : rep(bit(n - 1))) {
        swap(a[i], a[i ^ ((bit(n) - 1))]);
        swap(b[i], b[i ^ ((bit(n) - 1))]);
    }
    vector<mint> c = or_convolution(a, b);
    for (ll i : rep(bit(n - 1))) swap(c[i], c[i ^ ((bit(n) - 1))]);
    for (mint ci : c) { cout << ci << " "; }
    cout << endl;
}