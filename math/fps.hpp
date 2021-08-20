#pragma once

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
    fps &operator/=(const mint &a) {
        for (int i : rep(this->size())) (*this)[i] /= a;
        return *this;
    };
    fps &operator>>=(int d) {
        if ((int)this->size() <= d) {
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
        for (int i : rep(1, n)) { ret[i - 1] = i * (*this)[i]; }
        return ret;
    }
    fps integral() const {
        int n = this->size();
        fps ret(n + 1);
        ret[0] = mint(0);
        if (n > 0) ret[1] = mint(1);
        for (int i : rep(2, n + 1)) ret[i] = (-ret[mint::mod() % i]) * (mint::mod() / i);
        for (int i : rep(n)) ret[i + 1] *= (*this)[i];
        return ret;
    }
    fps inv(int d = -1) const {
        if (d == -1) d = this->size();
        fps ret{(*this)[0].inv()};
        for (int m = 1; m < d; m <<= 1) ret = (ret + ret - ret * ret * this->prefix(m << 1)).prefix(m << 1);
        return ret.prefix(d);
    }
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
    fps pow(ll k, int d = -1) const {
        if (d == -1) d = this->size();
        for (int i : rep(this->size())) {
            if ((*this)[i] != mint(0)) {
                if (i * k > d) return fps(d);
                fps ret = (((*this * (*this)[i].inv()) >> i).log(d) * mint(k)).exp(d) * ((*this)[i].pow(k));
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
    friend fps operator>>(const fps &a, int d) { return fps(a) >>= d; }
    friend fps operator<<(const fps &a, int d) { return fps(a) <<= d; }
};

using m9 = modint<998244353>;

template <> fps<m9> &fps<m9>::operator*=(const fps<m9> &a) {
    *this = convolution(*this, a);
    return *this;
}
template <> fps<m9> fps<m9>::inv(int d) const {
    using mint = m9;
    if (d == -1) d = this->size();
    fps ret{(*this)[0].inv()};
    for (int m = 1; m < d; m <<= 1) {
        fps f = this->prefix(m << 1);
        fps g = ret;
        f.resize(m << 1), ntt(f);
        g.resize(m << 1), ntt(g);
        for (int i : rep(m << 1)) f[i] *= g[i];
        intt(f);
        f >>= m, f.resize(m << 1), ntt(f);
        for (int i : rep(m << 1)) f[i] *= g[i];
        intt(f);
        f *= mint(-1);
        ret.insert(ret.end(), f.begin(), f.begin() + m);
    }
    return ret.prefix(d);
}

/*
template <> fps<m9> fps<m9>::exp(int d) const {
    using mint = m9;
    int n = this->size();
    assert(n > 0 && (*this)[0] == 0);
    if (d == -1) d = n;
    assert(d >= 0);
    fps g{1}, g_fft{1, 1};
    fps ret = *this;
    ret[0] = 1;
    ret.resize(d);
    fps h_drv(ret.differential());
    for (int m = 2; m < d; m *= 2) {
        // prepare
        fps f_fft(ret.begin(), ret.begin() + m);
        f_fft.resize(2 * m), ntt(f_fft);

        // Step 2.a'
        {
            fps _g(m);
            for (int i : rep(m)) _g[i] = f_fft[i] * g_fft[i];
            intt(_g), _g *= mint(_g.size());
            _g.erase(_g.begin(), _g.begin() + m / 2);
            _g.resize(m), ntt(_g);
            for (int i : rep(m)) _g[i] *= g_fft[i];
            intt(_g), _g *= mint(_g.size());
            _g.resize(m / 2);
            _g /= -m * m;
            g.insert(g.end(), _g.begin(), _g.begin() + m / 2);
        }

        // Step 2.b'--d'
        fps t(ret.begin(), ret.begin() + m);
        t = t.differential();
        {
            // Step 2.b'
            fps r{h_drv.begin(), h_drv.begin() + m - 1};
            // Step 2.c'
            r.resize(m);
            ntt(r);
            for (int i : rep(m)) r[i] *= f_fft[i];
            intt(r), r *= mint(r.size());
            r /= -m;
            // Step 2.d'
            t += r;
            t.insert(t.begin(), t.back());
            t.pop_back();
        }

        // Step 2.e'
        if (2 * m < d) {
            t.resize(2 * m);
            ntt(t);
            g_fft = g;
            g_fft.resize(2 * m);
            ntt(g_fft);
            for (int i : rep(2 * m)) t[i] *= g_fft[i];
            intt(t), t *= mint(t.size());
            t.resize(m);
            t /= 2 * m;
        } else { // この場合分けをしても数パーセントしか速くならない
            fps g1(g.begin() + m / 2, g.end());
            fps s1(t.begin() + m / 2, t.end());
            t.resize(m / 2);
            g1.resize(m), ntt(g1);
            t.resize(m), ntt(t);
            s1.resize(m), ntt(s1);
            for (int i : rep(m)) s1[i] = g_fft[i] * s1[i] + g1[i] * t[i];
            for (int i : rep(m)) t[i] *= g_fft[i];
            intt(t), t *= mint(t.size());
            intt(s1), s1 *= mint(s1.size());
            for (int i : rep(m / 2)) t[i + m / 2] += s1[i];
            t /= m;
        }

        // Step 2.f'
        fps v(ret.begin() + m, ret.begin() + min(d, 2 * m));
        v.resize(m);
        t.insert(t.begin(), m - 1, 0);
        t.push_back(0);
        t = t.integral();
        for (int i : rep(m)) v[i] -= t[m + i];

        // Step 2.g'
        v.resize(2 * m);
        ntt(v);
        for (int i : rep(2 * m)) v[i] *= f_fft[i];
        intt(v), v *= mint(v.size());
        v.resize(m);
        v /= 2 * m;

        // Step 2.h'
        for (int i : rep(min(d - m, m))) ret[m + i] = v[i];
    }
    return ret;
}
*/

template <> fps<m9> fps<m9>::exp(int deg) const {
    using mint = m9;
    assert((*this).size() == 0 || (*this)[0] == mint(0));
    if (deg == -1) deg = this->size();

    fps inv;
    inv.reserve(deg + 1);
    inv.push_back(mint(0));
    inv.push_back(mint(1));

    auto inplace_integral = [&](fps &F) -> void {
        const int n = (int)F.size();
        auto mod = mint::mod();
        while ((int)inv.size() <= n) {
            int i = inv.size();
            inv.push_back((-inv[mod % i]) * (mod / i));
        }
        F.insert(F.begin(), mint(0));
        for (int i = 1; i <= n; i++) F[i] *= inv[i];
    };

    auto inplace_diff = [](fps &F) -> void {
        if (F.empty()) return;
        F.erase(F.begin());
        mint coeff = 1, one = 1;
        for (int i = 0; i < (int)F.size(); i++) {
            F[i] *= coeff;
            coeff += one;
        }
    };

    fps b{1, 1 < (int)this->size() ? (*this)[1] : 0}, c{1}, z1, z2{1, 1};
    for (int m = 2; m < deg; m *= 2) {
        auto y = b;
        y.resize(2 * m);
        ntt(y);
        z1 = z2;
        fps z(m);
        for (int i = 0; i < m; ++i) z[i] = y[i] * z1[i];
        intt(z);
        fill(z.begin(), z.begin() + m / 2, mint(0));
        ntt(z);
        for (int i = 0; i < m; ++i) z[i] *= -z1[i];
        intt(z);
        c.insert(c.end(), z.begin() + m / 2, z.end());
        z2 = c;
        z2.resize(2 * m);
        ntt(z2);
        fps x(this->begin(), this->begin() + min<int>(this->size(), m));
        inplace_diff(x);
        x.push_back(mint(0));
        ntt(x);
        for (int i = 0; i < m; ++i) x[i] *= y[i];
        intt(x);
        x -= b.differential();
        x.resize(2 * m);
        for (int i = 0; i < m - 1; ++i) x[m + i] = x[i], x[i] = mint(0);
        ntt(x);
        for (int i = 0; i < 2 * m; ++i) x[i] *= z2[i];
        intt(x);
        x.pop_back();
        inplace_integral(x);
        for (int i = m; i < min<int>(this->size(), 2 * m); ++i) x[i] += (*this)[i];
        fill(x.begin(), x.begin() + m, mint(0));
        ntt(x);
        for (int i = 0; i < 2 * m; ++i) x[i] *= y[i];
        intt(x);
        b.insert(b.end(), x.begin() + m, x.end());
    }
    return b.prefix(deg);
}