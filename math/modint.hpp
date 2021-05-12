#ifndef PWMTREE_MODINT_HPP
#define PWMTREE_MODINT_HPP 1

#include "../template.hpp"

template <ll MOD = 1000000007> struct modint {
    ll val;
    modint() {}
    modint(ll val) : val(val >= 0 ? val % MOD : (MOD - (-val) % MOD) % MOD) {}
    modint inv() const {
        ll a = val, b = MOD, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return modint(u);
    }
    modint &operator+=(const modint &a) {
        if ((val += a.val) >= MOD) val -= MOD;
        return *this;
    }
    modint &operator-=(const modint &a) {
        if ((val += MOD - a.val) >= MOD) val -= MOD;
        return *this;
    }
    modint &operator*=(const modint &a) {
        (val *= a.val) %= MOD;
        return *this;
    }
    modint &operator/=(const modint &a) { return *this *= a.inv(); }
    modint &operator^=(ll p) {
        modint res = 1;
        while (p) {
            if (p & 1) res *= *this;
            *this *= *this;
            p >>= 1;
        }
        val = res.val;
        return *this;
    }
    bool operator==(const modint &a) const { return val == a.val; }
    bool operator!=(const modint &a) const { return rel_ops::operator!=(*this, a); }
    modint operator+() const { return *this; }
    modint operator-() const { return modint(-val); }
    modint operator+(const modint &a) const { return modint(*this) += a; }
    modint operator-(const modint &a) const { return modint(*this) -= a; }
    modint operator*(const modint &a) const { return modint(*this) *= a; }
    modint operator/(const modint &a) const { return modint(*this) /= a; }
    friend istream &operator>>(istream &is, modint &a) {
        ll val;
        is >> val;
        a = modint(val);
        return is;
    }
    friend ostream &operator<<(ostream &os, const modint &a) { return os << a.val; }
};

#endif