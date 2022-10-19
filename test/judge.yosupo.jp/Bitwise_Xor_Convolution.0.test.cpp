#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"
#include "../../math/modint.hpp"
#include "../../math/xor_convolution.hpp"

int main() {
    using mint = modint998244353;
    ll n;
    cin >> n;
    vector<mint> a(pw(n)), b(pw(n));
    for (ll i : rep(pw(n))) cin >> a[i];
    for (ll i : rep(pw(n))) cin >> b[i];
    vector<mint> c = xor_convolution(a, b);
    for (mint ci : c) { cout << ci << " "; }
    cout << endl;
}