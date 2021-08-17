#ifndef PWMTREE_TEMPLATE_HPP
#define PWMTREE_TEMPLATE_HPP 1

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define bit(n) (1ull << (n))
using ll = long long;
template <typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
template <typename T> T sq(const T &a) { return a * a; }
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
template <typename T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); itr++) { os << *itr << (next(itr) != a.end() ? ", " : ""); }
    os << ")";
    return os;
}
struct rep {
    struct itr {
        int v;
        itr(int v) : v(v) {}
        void operator++() { v++; }
        int operator*() const { return v; }
        bool operator!=(const itr &i) const { return v != i.v; }
    };
    int l, r;
    rep(int r) : l(0), r(r) {}
    rep(int l, int r) : l(l), r(r) {}
    itr begin() const { return l; };
    itr end() const { return r; };
};
struct per {
    struct itr {
        int v;
        itr(int v) : v(v) {}
        void operator++() { v--; }
        int operator*() const { return v; }
        bool operator!=(const itr &i) const { return v != i.v; }
    };
    int l, r;
    per(int r) : l(0), r(r) {}
    per(int l, int r) : l(l), r(r) {}
    itr begin() const { return r - 1; };
    itr end() const { return l - 1; };
};

#endif