#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/1/ITP2_1_A"
#include "../../data_structure/splay_tree.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    splay_tree<ll> st;
    while (q--) {
        ll ord, x;
        cin >> ord;
        if (ord == 0) {
            cin >> x;
            st.insert(st.size(), x);
        }
        if (ord == 1) {
            cin >> x;
            cout << st.get(x) << endl;
        }
        if (ord == 2) st.erase(st.size() - 1);
    }
}