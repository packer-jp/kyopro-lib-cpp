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
    vector<mint> c = and_convolution(a, b);
    for (mint ci : c) { cout << ci << " "; }
    cout << endl;
}