#ifndef PWMTREE_TEMPLATE_HPP
#define PWMTREE_TEMPLATE_HPP 1

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define bit(n) (1LL << (n))
using ll = long long;
template <typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
template <typename T> T sq(T a) { return a * a; }
template <typename T, typename U> bool chmax(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T, typename U> bool chmin(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template <typename T> ostream &operator<<(ostream &os, vector<T> a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); itr++) { os << *itr << (next(itr) != a.end() ? ", " : ""); }
    os << ")";
    return os;
}

#endif