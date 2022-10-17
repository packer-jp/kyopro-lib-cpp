#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"
#include "../../math/kth_of_lrs.hpp"

int main() {
    using mint = modint998244353;
    ll d, k;
    cin >> d >> k;
    vector<mint> a(d), c(d);
    for (ll i : rep(d)) cin >> a[i];
    for (ll i : rep(d)) cin >> c[i];
    cout << kth_of_lrs(a, c, k) << endl;
}