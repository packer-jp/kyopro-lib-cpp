#ifndef PWMTREE_FPS_HPP
#define PWMTREE_FPS_HPP 1

#include "../template.hpp"
#include "convolution.hpp"
#include "modint.hpp"

template <typename mint> struct fps : vector<mint> {
    using vector<mint>::vector;
    using vector<mint>::operator=;
    fps(const fps &a) : vector<mint>(a) {}
    fps(const mint &a) : vector<mint>(1, a) {}
    fps &operator=(const fps &a) {
        *this = (vector<mint>)a;
        return *this;
    }
    fps &operator+=(const fps &a) {
        if (a.size() > this->size()) this->resize(a.size());
        rep(i, a.size())(*this)[i] += a[i];
        return *this;
    }
    fps &operator-=(const fps &a) {
        if (a.size() > this->size()) this->resize(a.size());
        rep(i, a.size())(*this)[i] -= a[i];
        return *this;
    }
    fps &operator*=(const fps &a);
    fps &operator>>=(ll d) {
        if (this->size() <= d) return {};
        this->erase(this->begin(), this->begin() + d);
        return *this;
    }
    fps &operator<<=(ll d) {
        this->insert(this->begin(), d, mint(0));
        return *this;
    }
    fps prefix(ll d) const { return fps(this->begin(), this->begin() + min((ll)this->size(), d)); }
    fps differential() const {
        ll n = this->size();
        fps ret(max(0LL, n - 1));
        for (int i = 1; i < n; i++) { ret[i - 1] = i * (*this)[i]; }
        return ret;
    }
    fps integral() const {
        ll n = this->size();
        fps ret(n + 1);
        ret[0] = mint(0);
        if (n > 0) ret[1] = mint(1);
        ll mod = mint::mod();
        for (int i = 2; i <= n; i++) ret[i] = (-ret[mod % i]) * (mod / i);
        rep(i, n) ret[i + 1] *= (*this)[i];
        return ret;
    }
    fps log(ll d = -1) const {
        assert((*this)[0] == mint(1));
        if (d == -1) d = this->size();
        return (this->differential() * this->inv(d)).prefix(d - 1).integral();
    }
    fps inv(ll d = -1) const;
    friend fps operator+(const fps &a, const fps &b) { return fps(a) += b; }
    friend fps operator-(const fps &a, const fps &b) { return fps(a) -= b; }
    friend fps operator*(const fps &a, const fps &b) { return fps(a) *= b; }
    friend fps operator>>(const fps &a, ll d) { return fps(a) >>= d; }
    friend fps operator<<(const fps &a, ll d) { return fps(a) <<= d; }
};

template <> fps<modint<998244353>> &fps<modint<998244353>>::operator*=(const fps<modint<998244353>> &a) {
    *this = convolution_friendly<modint<998244353>>(*this, a);
    return *this;
}

template <> fps<modint<998244353>> fps<modint<998244353>>::inv(ll d) const {
    if (d == -1) d = this->size();
    fps ret{(*this)[0].inv()};
    while (ret.size() < d) {
        ll m = ret.size();
        ret = modint<998244353>(2) * ret - *this * ret * ret;
        ret.resize(m << 1);
    }
    ret.resize(d);
    return ret;
}

#endif