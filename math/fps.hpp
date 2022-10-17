#pragma once

#include "../template.hpp"
#include "convolution.hpp"
#include "modint.hpp"

template <typename mint> struct fps : vector<mint> {
    using vector<mint>::vector;
    using vector<mint>::operator=;
    fps() : vector<mint>() {}
    fps(const mint &a) : vector<mint>(1, a) {}
    fps(const vector<mint> &a) : vector<mint>(a) {}
    fps(const fps &a) : vector<mint>(a) {}
    fps &operator=(const fps &a) {
        *this = (vector<mint>)a;
        return *this;
    }
    fps &operator+=(const fps &a) {
        if (a.size() > this->size()) this->resize(a.size());
        for (ll i : rep(a.size())) (*this)[i] += a[i];
        return *this;
    }
    fps &operator-=(const fps &a) {
        if (a.size() > this->size()) this->resize(a.size());
        for (ll i : rep(a.size())) (*this)[i] -= a[i];
        return *this;
    }
    fps &operator*=(const fps &a);
    fps &operator/=(const mint &a) {
        for (ll i : rep(this->size())) (*this)[i] /= a;
        return *this;
    };
    fps &operator>>=(ll d) {
        if ((ll)this->size() <= d) {
            *this = {};
        } else {
            this->erase(this->begin(), this->begin() + d);
        }
        return *this;
    }
    fps &operator<<=(ll d) {
        this->insert(this->begin(), d, 0);
        return *this;
    }
    fps &chdot(const fps &a) {
        for (ll i : rep(this->size())) {
            if (i < (ll)a.size()) {
                (*this)[i] *= a[i];
            } else {
                (*this)[i] = 0;
            }
        }
        return *this;
    }
    fps prefix(ll d) const { return fps(this->begin(), this->begin() + min((ll)this->size(), d)); }
    fps differential() const {
        ll n = this->size();
        fps ret(max(0ll, n - 1));
        for (ll i : rep(1, n)) { ret[i - 1] = i * (*this)[i]; }
        return ret;
    }
    fps integral() const {
        ll n = this->size();
        fps ret(n + 1);
        ret[0] = 0;
        if (n > 0) ret[1] = 1;
        for (ll i : rep(2, n + 1)) ret[i] = (-ret[mint::mod() % i]) * (mint::mod() / i);
        for (ll i : rep(n)) ret[i + 1] *= (*this)[i];
        return ret;
    }
    fps inv(ll d) const {
        fps ret{(*this)[0].inv()};
        for (ll m = 1; m < d; m <<= 1) ret = (ret + ret - ret * ret * this->prefix(m << 1)).prefix(m << 1);
        return ret.prefix(d);
    }
    fps log(ll d) const {
        assert((*this)[0] == 1);
        return (this->differential() * this->inv(d)).prefix(d - 1).integral();
    }
    fps exp(ll d) const {
        assert(this->size() == 0 || (*this)[0] == 0);
        fps ret{1};
        for (ll m = 1; m < d; m <<= 1) ret = (ret * (this->prefix(m << 1) + 1 - ret.log(m << 1))).prefix(m << 1);
        return ret.prefix(d);
    }
    fps pow(ll k, ll d) const {
        if (k == 0) {
            fps ret(d);
            if (d) ret[0] = 1;
            return ret;
        }
        for (ll i : rep(this->size())) {
            if ((*this)[i] != 0) {
                if (i > d / k) return fps(d);
                fps ret = (((*this * (*this)[i].inv()) >> i).log(d) * mint(k)).exp(d) * (*this)[i].pow(k);
                ret = (ret << (i * k)).prefix(d);
                ret.resize(d);
                return ret;
            }
        }
        return fps(d);
    }
    friend fps operator+(const fps &a) { return a; }
    friend fps operator-(const fps &a) { return fps() -= a; }
    friend fps operator+(const fps &a, const fps &b) { return fps(a) += b; }
    friend fps operator-(const fps &a, const fps &b) { return fps(a) -= b; }
    friend fps operator*(const fps &a, const fps &b) { return fps(a) *= b; }
    friend fps operator>>(const fps &a, ll d) { return fps(a) >>= d; }
    friend fps operator<<(const fps &a, ll d) { return fps(a) <<= d; }
};

using m9 = modint998244353;

template <> fps<m9> &fps<m9>::operator*=(const fps<m9> &a) {
    *this = convolution(*this, a);
    return *this;
}

template <> fps<m9> fps<m9>::inv(ll d) const {
    fps ret{(*this)[0].inv()};
    for (ll m = 1; m < d; m <<= 1) {
        fps f = this->prefix(m << 1);
        fps g = ret;
        f.resize(m << 1), ntt(f);
        g.resize(m << 1), ntt(g);
        f.chdot(g);
        intt(f);
        f >>= m, f.resize(m << 1), ntt(f);
        f.chdot(g);
        intt(f);
        f = -f;
        ret.insert(ret.end(), f.begin(), f.begin() + m);
    }
    return ret.prefix(d);
}

template <> fps<m9> fps<m9>::exp(ll d) const {
    assert(this->size() == 0 || (*this)[0] == 0);
    fps ret{1}, g{1}, g_freq{1};
    for (ll m = 1; m < d; m <<= 1) {
        fps ret_freq = ret.prefix(m);
        ret_freq.resize(m << 1), ntt(ret_freq);

        fps g_cont = g_freq;
        for (ll i : rep(m)) g_cont[i] *= ret_freq[i << 1];
        intt(g_cont);
        g_cont >>= m >> 1;
        g_cont.resize(m), ntt(g_cont);
        g_cont.chdot(g_freq);
        intt(g_cont);
        g_cont = -g_cont;
        g.insert(g.end(), g_cont.begin(), g_cont.begin() + (m >> 1));

        fps r = this->differential().prefix(m - 1);
        r.resize(m), ntt(r);
        for (ll i : rep(m)) r[i] *= ret_freq[i << 1];
        intt(r);

        fps t = ret.differential() - r;
        t.insert(t.begin(), t.back()), t.pop_back();
        t.resize(m << 1), ntt(t);
        g_freq = g, g_freq.resize(m << 1), ntt(g_freq);
        t.chdot(g_freq);
        intt(t), t.resize(m);

        fps u = (this->prefix(m << 1) - (t << m - 1).integral()) >> m;
        u.resize(m << 1), ntt(u);
        u.chdot(ret_freq);
        intt(u);

        ret += u.prefix(m) << m;
    }
    return ret.prefix(d);
}