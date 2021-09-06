#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include "../../data_structure/persistent_uf.hpp"

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    vector<persistent_uf<2>> his;
    his.emplace_back(n);
    for (ll i : rep(q)) {
        ll c, k, u, v;
        cin >> c >> k >> u >> v, ++k;
        if (c == 0) { his.emplace_back(his[k].unite(u, v)); }
        if (c == 1) {
            cout << his[k].same(u, v) << '\n';
            his.emplace_back(1);
        }
    }
}