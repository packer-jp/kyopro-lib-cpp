#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#include "../../data_structure/segtree.hpp"
#include "../../graph/hld.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;
    struct str {
        using val_t = string;
        static val_t op(val_t a, val_t b) { return a + b; }
        static val_t e() { return ""; }
    };
    segtree<str> st_fwd(n), st_rev(n);
    vector<string> weight = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    hld hld(n);
    hld.add_edge(7, 2);
    hld.add_edge(2, 6);
    hld.add_edge(4, 2);
    hld.add_edge(4, 3);
    hld.add_edge(5, 4);
    hld.add_edge(5, 1);
    hld.add_edge(1, 0);
    hld.add_edge(0, 9);
    hld.add_edge(5, 8);
    vector<int> in = hld.build(5);
    for (int i : rep(n)) {
        st_fwd.set(in[i], weight[i]);
        st_rev.set(n - in[i] - 1, weight[i]);
    }
    auto path = [&](int u, int v) {
        string ret = "";
        vector<pair<int, int>> path = hld.get_path(u, v, false);
        for (int i : rep(path.size())) {
            int l = path[i].first, r = path[i].second;
            if (l < r) {
                ret += st_fwd.prod(l, r + 1);
            } else {
                ret += st_rev.prod(n - l - 1, n - r);
            }
        }
        return ret;
    };
    auto subtree = [&](int v) {
        pair<int, int> subtree = hld.get_subtree(v, false);
        return st_fwd.prod(subtree.first, subtree.second + 1);
    };
    assert(path(2, 1) == "cefb");
    assert(path(5, 3) == "fed");
    assert(path(7, 4) == "hce");
    assert(path(4, 4) == "e");
    assert(subtree(2) == "chg");
    assert(subtree(5) == "fechgdbaji");
    assert(hld.dist(2, 0) == 4);
    assert(hld.dist(4, 1) == 2);

    cout << "Hello World" << endl;
}