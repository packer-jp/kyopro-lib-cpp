#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "../../math/convolution.hpp"
#include "../../math/modint.hpp"

int main() {
    using mint = modint<998244353>;
    ll n, m;
    cin >> n >> m;
    vector<mint> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    vector<mint> c = convolution_friendly<mint>(a, b);
    for (mint ci : c) { cout << ci << '\n'; }
}