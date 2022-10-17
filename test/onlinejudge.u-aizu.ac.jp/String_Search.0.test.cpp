#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"
#include "../../string/rolling_hash.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    string t, p;
    cin >> t >> p;
    rolling_hash th(t), ph(p);
    for (ll i : rep((ll)t.size() - (ll)p.size() + 1)) {
        if (th.get_hash(i, i + p.size()) == ph.get_hash(0, p.size())) cout << i << endl;
    }
}