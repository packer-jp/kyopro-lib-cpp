#define PROBLEM "https://atcoder.jp/contests/typical90/tasks/typical90_ba"
#include "../../util/fibsect.hpp"

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll ans = fibsect(1, n + 1,
                         [](ll x) -> ll {
                             cout << "? " << x << endl;
                             ll ret;
                             cin >> ret;
                             return ret;
                         })
                     .second;
        cout << "! " << ans << endl;
    }
}