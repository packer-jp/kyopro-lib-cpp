#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/beta/room.html#HUPC2020Day2/problems/I"
#include "../../math/matrix.hpp"

int main() {
    int n;
    cin >> n;
    matrix<double_field> v(n, n), p(n, 1), l(n, n);
    rep(i, n) {
        rep(j, n) {
            cin >> v[j][i];
            l[i][i] += sq(v[j][i]);
        }
        l[i][i] = sqrt(l[i][i]);
    }
    rep(i, n) cin >> p[i][0];
    matrix<double_field> q = l / v * p;
    double ans = 0.0;
    rep(i, n) { ans += sq(q[i][0] - clamp(q[i][0], 0.0, l[i][i])); }
    ans = sqrt(ans);
    cout << ans << endl;
}