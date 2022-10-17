#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "../../math/convolution.hpp"
#include "../../math/modint.hpp"

int main() {
    using mint = modint998244353;
    ll n, m;
    cin >> n >> m;
    vector<mint> a(n), b(m);
    for (ll i : rep(n)) cin >> a[i];
    for (ll i : rep(m)) cin >> b[i];
    vector<mint> c = convolution(a, b);
    for (mint ci : c) { cout << ci << " "; }
    cout << endl;
}