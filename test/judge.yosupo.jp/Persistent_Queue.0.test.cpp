#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"
#define IGNORE
#include "../../data_structure/persistent_array.hpp"

int main() {
    persistent_array<ll, 1> pa(1);
    ll n;
    cin >> n;
    cout << sq(n) << endl;
}