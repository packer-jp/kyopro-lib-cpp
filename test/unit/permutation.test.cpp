#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#include "../../math/permutation.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    vll e = {0, 1, 2, 3, 4};
    vll a = {3, 2, 1, 4, 0};
    vll b = {1, 2, 0, 3, 4};
    vll ab = {2, 1, 3, 4, 0};
    vll a9 = {0, 2, 1, 3, 4};
    vll b6 = {0, 1, 2, 3, 4};

    assert(permutation(5) == permutation(e));
    assert(permutation(a) * permutation(b) == permutation(ab));
    assert(permutation(ab) / permutation(b) == permutation(a));
    assert(permutation(a).pow(0) == permutation(e));
    assert(permutation(a).pow(9) == permutation(a9));
    assert(permutation(b).pow(6) == permutation(b6));

    cout << "Hello World" << endl;
}