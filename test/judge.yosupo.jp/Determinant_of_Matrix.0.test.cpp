#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include "../../math/matrix.hpp"
#include "../../math/modint.hpp"

int main() {
    using mint = modint<998244353>;
    struct mint_field {
        using V = mint;
        static V zero() { return 0; }
        static V one() { return 1; }
    };
    ll n;
    cin >> n;
    matrix<mint_field> a(n, n);
    for (ll i : rep(n)) {
        for (ll j : rep(n)) { cin >> a[i][j]; }
    }
    cout << a.det() << endl;
}