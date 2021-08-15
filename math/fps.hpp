#ifndef PWMTREE_FPS_HPP
#define PWMTREE_FPS_HPP 1

#include "../template.hpp"
#include "convolution.hpp"
#include "modint.hpp"

template <typename mint> struct fps : vector<mint> {
    using vector<mint>::vector;
    using vector<mint>::operator=;
    fps() : vector<mint>() {}
    fps(const mint &a) : vector<mint>(1, a) {}
    fps(const fps &a) : vector<mint>(a) {}
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
        if (this->size() <= d) {
            *this = {};
        } else {
            this->erase(this->begin(), this->begin() + d);
        }
        return *this;
    }
    fps &operator<<=(ll d) {
        this->insert(this->begin(), d, mint(0));
        return *this;
    }
    fps prefix(ll d) const { return fps(this->begin(), this->begin() + min((ll)this->size(), d)); }
    fps differential() const {
        ll n = this->size();
        fps ret(max(0ll, n - 1));
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
    fps inv(ll d = -1) const {
        if (d == -1) d = this->size();
        fps ret{(*this)[0].inv()};
        for (ll i = 1; i < d; i <<= 1) ret = (mint(2) * ret - ret * ret * this->prefix(i << 1)).prefix(i << 1);
        return ret.prefix(d);
    };
    friend fps operator-(const fps &a) { return fps() -= a; }
    friend fps operator+(const fps &a, const fps &b) { return fps(a) += b; }
    friend fps operator-(const fps &a, const fps &b) { return fps(a) -= b; }
    friend fps operator*(const fps &a, const fps &b) { return fps(a) *= b; }
    friend fps operator>>(const fps &a, ll d) { return fps(a) >>= d; }
    friend fps operator<<(const fps &a, ll d) { return fps(a) <<= d; }
};

using m9 = modint<998244353>;

template <> fps<m9> &fps<m9>::operator*=(const fps<m9> &a) {
    *this = convolution_friendly<m9>(*this, a);
    return *this;
}
template <> fps<m9> fps<m9>::inv(ll d) const {
    if (d == -1) d = this->size();
    fps ret{(*this)[0].inv()};
    for (ll m = 1; m < d; m <<= 1) {
        m9 wn = get_w<m9>(m << 1);
        fps f = this->prefix(m << 1);
        fps g = ret;
        f.resize(m << 1), ntt(f, wn);
        g.resize(m << 1), ntt(g, wn);
        rep(i, m << 1) f[i] *= g[i];
        ntt(f, wn.inv());
        f = f >> m, f.resize(m << 1), ntt(f, wn);
        rep(i, m << 1) f[i] *= g[i];
        ntt(f, wn.inv());
        m9 iz = m9(m << 1).inv();
        iz *= -iz;
        rep(i, m) f[i] *= iz;
        ret.insert(ret.end(), f.begin(), f.begin() + m);
    }
    return ret.prefix(d);
}

#endif