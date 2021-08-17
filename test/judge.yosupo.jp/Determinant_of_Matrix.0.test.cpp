#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include "../../math/matrix.hpp"
#include "../../math/modint.hpp"

int main() {
    using mint = modint<998244353>;
    struct mint_field {
        using val_t = mint;
        static val_t zero() { return mint(0); }
        static val_t one() { return mint(1); }
    };
    int n;
    cin >> n;
    matrix<mint_field> a(n, n);
    for (int i : range(n)) {
        for (int j : range(n)) { cin >> a[i][j]; }
    }
    cout << a.det() << endl;
}