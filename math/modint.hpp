#pragma once

#include "../template.hpp"

template <typename M> struct modint {
    ll val;
    modint(ll val = 0) : val(val >= 0 ? val % M::mod : (M::mod - (-val) % M::mod) % M::mod) {}
    static ll mod() { return M::mod; }
    modint inv() const {
        ll a = val, b = M::mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return u;
    }
    modint pow(ll k) const {
        modint ret = 1, mul = val;
        while (k) {
            if (k & 1) ret *= mul;
            mul *= mul;
            k >>= 1;
        }
        return ret;
    }
    modint &operator+=(const modint &a) {
        if ((val += a.val) >= M::mod) val -= M::mod;
        return *this;
    }
    modint &operator-=(const modint &a) {
        if ((val += M::mod - a.val) >= M::mod) val -= M::mod;
        return *this;
    }
    modint &operator*=(const modint &a) {
        (val *= a.val) %= M::mod;
        return *this;
    }
    modint &operator/=(const modint &a) { return *this *= a.inv(); }
    modint operator+() const { return *this; }
    modint operator-() const { return modint(-val); }
    friend bool operator==(const modint &a, const modint &b) { return a.val == b.val; }
    friend bool operator!=(const modint &a, const modint &b) { return rel_ops::operator!=(a, b); }
    friend modint operator+(const modint &a, const modint &b) { return modint(a) += b; }
    friend modint operator-(const modint &a, const modint &b) { return modint(a) -= b; }
    friend modint operator*(const modint &a, const modint &b) { return modint(a) *= b; }
    friend modint operator/(const modint &a, const modint &b) { return modint(a) /= b; }
    friend istream &operator>>(istream &is, modint &a) {
        ll val;
        is >> val;
        a = modint(val);
        return is;
    }
    friend ostream &operator<<(ostream &os, const modint &a) { return os << a.val; }
};

struct _998244353 {
    constexpr static ll mod = 998244353;
};
struct _1000000007 {
    constexpr static ll mod = 1000000007;
};
using modint998244353 = modint<_998244353>;
using modint1000000007 = modint<_1000000007>;

struct arbitrary_mod {
    static ll mod;
};