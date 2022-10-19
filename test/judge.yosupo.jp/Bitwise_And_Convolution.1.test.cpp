#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../../math/and_or_convolution.hpp"
#include "../../math/modint.hpp"

int main() {
    using mint = modint998244353;
    ll n;
    cin >> n;
    vector<mint> a(pw(n)), b(pw(n));
    for (ll i : rep(pw(n))) cin >> a[i];
    for (ll i : rep(pw(n))) cin >> b[i];
    if (n > 0) {
        for (ll i : rep(pw(n - 1))) {
            swap(a[i], a[i ^ (pw(n) - 1)]);
            swap(b[i], b[i ^ (pw(n) - 1)]);
        }
    }
    vector<mint> c = or_convolution(a, b);
    if (n > 0) {
        for (ll i : rep(pw(n - 1))) swap(c[i], c[i ^ (pw(n) - 1)]);
    }
    for (mint ci : c) { cout << ci << " "; }
    cout << endl;
}