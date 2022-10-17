#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../../data_structure/unionfind.hpp"

int main() {
    ll n, q;
    cin >> n >> q;
    unionfind uf(n);
    while (q--) {
        ll t, u, v;
        cin >> t >> u >> v;
        if (t == 0) uf.unite(u, v);
        if (t == 1) cout << uf.same(u, v) << endl;
    }
}