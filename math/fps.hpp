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
        for (int i : rep(a.size())) (*this)[i] += a[i];
        return *this;
    }
    fps &operator-=(const fps &a) {
        if (a.size() > this->size()) this->resize(a.size());
        for (int i : rep(a.size())) (*this)[i] -= a[i];
        return *this;
    }
    fps &operator*=(const fps &a);
    fps &operator>>=(int d) {
        if (this->size() <= d) {
            *this = {};
        } else {
            this->erase(this->begin(), this->begin() + d);
        }
        return *this;
    }
    fps &operator<<=(int d) {
        this->insert(this->begin(), d, mint(0));
        return *this;
    }
    fps prefix(int d) const { return fps(this->begin(), this->begin() + min((int)this->size(), d)); }
    fps differential() const {
        int n = this->size();
        fps ret(max(0, n - 1));
        for (int i = 1; i < n; i++) { ret[i - 1] = i * (*this)[i]; }
        return ret;
    }
    fps integral() const {
        int n = this->size();
        fps ret(n + 1);
        ret[0] = mint(0);
        if (n > 0) ret[1] = mint(1);
        ll mod = mint::mod();
        for (int i = 2; i <= n; i++) ret[i] = (-ret[mod % i]) * (mod / i);
        for (int i : rep(n)) ret[i + 1] *= (*this)[i];
        return ret;
    }
    fps inv(int d = -1) const {
        if (d == -1) d = this->size();
        fps ret{(*this)[0].inv()};
        for (int m = 1; m < d; m <<= 1) ret = (mint(2) * ret - ret * ret * this->prefix(m << 1)).prefix(m << 1);
        return ret.prefix(d);
    };
    fps log(int d = -1) const {
        assert((*this)[0] == mint(1));
        if (d == -1) d = this->size();
        return (this->differential() * this->inv(d)).prefix(d - 1).integral();
    }
    fps exp(int d = -1) const {
        assert(this->size() == 0 || (*this)[0] == mint(0));
        if (d == -1) d = this->size();
        fps ret{1};
        for (int m = 1; m < d; m <<= 1) ret = (ret * (prefix(m << 1) + mint(1) - ret.log(m << 1))).prefix(m << 1);
        return ret.prefix(d);
    }
    friend fps operator-(const fps &a) { return fps() -= a; }
    friend fps operator+(const fps &a, const fps &b) { return fps(a) += b; }
    friend fps operator-(const fps &a, const fps &b) { return fps(a) -= b; }
    friend fps operator*(const fps &a, const fps &b) { return fps(a) *= b; }
    friend fps operator>>(const fps &a, int d) { return fps(a) >>= d; }
    friend fps operator<<(const fps &a, int d) { return fps(a) <<= d; }
};

using m9 = modint<998244353>;

template <> fps<m9> &fps<m9>::operator*=(const fps<m9> &a) {
    *this = convolution_friendly<m9>(*this, a);
    return *this;
}
template <> fps<m9> fps<m9>::inv(int d) const {
    if (d == -1) d = this->size();
    fps ret{(*this)[0].inv()};
    for (int m = 1; m < d; m <<= 1) {
        m9 wn = getw<m9>(m << 1);
        fps f = this->prefix(m << 1);
        fps g = ret;
        f.resize(m << 1), ntt(f, wn);
        g.resize(m << 1), ntt(g, wn);
        for (int i : rep(m << 1)) f[i] *= g[i];
        ntt(f, wn.inv());
        f = f >> m, f.resize(m << 1), ntt(f, wn);
        for (int i : rep(m << 1)) f[i] *= g[i];
        ntt(f, wn.inv());
        m9 iz = m9(m << 1).inv();
        iz *= -iz;
        for (int i : rep(m)) f[i] *= iz;
        ret.insert(ret.end(), f.begin(), f.begin() + m);
    }
    return ret.prefix(d);
}

#endif