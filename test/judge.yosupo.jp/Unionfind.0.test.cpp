#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../../data_structure/uf.hpp"

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    uf uf(n);
    while (q--) {
        ll t, u, v;
        cin >> t >> u >> v;
        if (t == 0) uf.unite(u, v);
        if (t == 1) cout << uf.same(u, v) << endl;
    }
}