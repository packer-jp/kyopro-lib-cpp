#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"
#include "../../string/rolling_hash.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    string T, P;
    cin >> T >> P;
    rolling_hash Th(T), Ph(P);
    for (int i : rep((int)T.size() - (int)P.size() + 1)) {
        if (Th.get_hash(i, i + P.size()) == Ph.get_hash(0, P.size())) cout << i << endl;
    }
}