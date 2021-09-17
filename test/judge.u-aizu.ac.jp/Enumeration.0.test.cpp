#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446"
#define ERROR 1e-7
#include "../../math/and_or_convolution.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    Vl a(n), p(n);
    for (ll i : rep(n)) cin >> a[i];
    for (ll i : rep(n)) cin >> p[i];
    Vl x(bit(n));
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
    fzt_super(x);
    fmt_super(x);
    fzt_sub(x);
    fmt_sub(x);

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