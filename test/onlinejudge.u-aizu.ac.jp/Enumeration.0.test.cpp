#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/search/titles/2446"
#include "../../math/fzt_and_fmt.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    vll a(n), p(n);
    for (ll i : rep(n)) cin >> a[i];
    for (ll i : rep(n)) cin >> p[i];
    vector<ll> x(bit(n));
    for (ll i : rep(bit(n))) {
        ll l = 1;
        for (ll j : rep(n)) {
            if ((i >> j) & 1) {
                if (l) {
                    ll d = l / gcd(l, a[j]);
                    l = (__int128_t)d * a[j] > m ? 0 : d * a[j];
                }
            }
        }
        if (l) x[i] = m / l;
    }
    fmt_sub(x);
    double ans = 0;
    for (ll i : rep(bit(n))) {
        double q = 1;
        for (ll j : rep(n)) {
            if ((i >> j) & 1) {
                q *= p[j] / 100.0;
            } else {
                q *= (1 - p[j] / 100.0);
            }
        }
        x[i] = m - abs(x[i]);
        ans += x[i] * q;
    };
    cout << ans << endl;
}