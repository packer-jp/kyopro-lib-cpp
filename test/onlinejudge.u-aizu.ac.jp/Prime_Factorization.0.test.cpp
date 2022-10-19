#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"
#include "../../math/prime_factorize.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    cin >> n;
    cout << n << ":";
    auto v = prime_factorize(n);
    for (ll vi : v) cout << " " << vi;
    cout << endl;
}