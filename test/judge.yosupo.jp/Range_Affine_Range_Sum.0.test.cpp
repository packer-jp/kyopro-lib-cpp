#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../data_structure/lazy_segtree.hpp"
#include "../../math/modint.hpp"

int main() {
    using mint = modint<998244353>;
    ll n, q;
    cin >> n >> q;
    vector<pair<mint, int>> src(n, {0, 1});
    for (ll i : rep(n)) cin >> src[i].first;
    lazy_segtree<sum_monoid_with_affine<mint>> lst(src);
    while (q--) {
        ll t, l, r;
        cin >> t >> l >> r;
        if (t == 0) {
            ll b, c;
            cin >> b >> c;
            lst.apply(l, r, {b, c});
        }
        if (t == 1) { cout << lst.prod(l, r).first << endl; }
    }
}