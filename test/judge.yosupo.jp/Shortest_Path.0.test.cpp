#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../../graph/dijkstra.hpp"

int main() {
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    dijkstra<ll_dij> dij(n);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        dij.add_edge(a, b, c);
    }
    auto [dist, prev] = dij.get(s, 0);
    if (prev[t] == -1) {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> vs{t};
    do {
        ll back = vs.back();
        vs.push_back(prev[back]);
    } while (vs.back() != s);
    reverse(all(vs));
    cout << dist[t] << " " << vs.size() - 1 << endl;
    rep(i, vs.size() - 1) cout << vs[i] << " " << vs[i + 1] << endl;
}