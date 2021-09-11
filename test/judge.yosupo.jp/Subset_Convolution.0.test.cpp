#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../../math/modint.hpp"
#include "../../math/subset_convolution.hpp"

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    using mint = modint<998244353>;
    ll n;
    cin >> n;
    vector<mint> a(bit(n)), b(bit(n));
    for (ll i : rep(bit(n))) cin >> a[i];
    for (ll i : rep(bit(n))) cin >> b[i];
    vector<mint> c = subset_convolution(a, b);
    for (mint ci : c) { cout << ci << " "; }
    cout << endl;
}