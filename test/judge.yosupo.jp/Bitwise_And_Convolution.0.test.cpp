#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../../math/and_or_convolution.hpp"
#include "../../math/modint.hpp"

int main() {
    using mint = modint<998244353>;
    ll n;
    cin >> n;
    vector<mint> a(bit(n)), b(bit(n));
    for (ll i : rep(bit(n))) cin >> a[i];
    for (ll i : rep(bit(n))) cin >> b[i];
    vector<mint> c = and_convolution(a, b);
    for (mint ci : c) { cout << ci << " "; }
    cout << endl;
}