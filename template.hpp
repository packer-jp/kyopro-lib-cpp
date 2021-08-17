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
struct range {
    int start, stop, step;
    struct iterator {
        int val, stop, step;
        iterator(int val, int stop, int step) : val(val), stop(stop), step(step) {}
        iterator &operator++() {
            val += step;
            if (step > 0) {
                chmin(val, stop);
            } else {
                chmax(val, stop);
            }
            return *this;
        }
        int operator*() const { return val; }
        bool operator!=(const iterator &i) const { return val != i.val; }
    };
    range(int end) : start(0), stop(end), step(1) {}
    range(int start, int stop) : start(0), stop(stop), step(1) {}
    range(int start, int stop, int step) : start(start), stop(stop), step(step) {}
    iterator begin() const { return {start, stop, step}; };
    iterator end() const { return {stop, stop, step}; };
};

#endif