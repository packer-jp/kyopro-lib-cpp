#ifndef PWMTREE_FPS_HPP
#define PWMTREE_FPS_HPP 1

#include "../template.hpp"
#include "convolution.hpp"
#include "modint.hpp"

template <typename mint> struct fps : vector<mint> {
    using vector<mint>::vector;
    using vector<mint>::operator=;
    fps &operator+=(const fps &a) {
        if (a.size() > this->size()) this->resize(a.size());
        rep(i, a.size())(*this)[i] += a[i];
        return *this;
    }
    fps &operator+=(const mint &a) {
        if (this->empty()) this->resize(1);
        (*this)[0] += a;
        return *this;
    }
    fps &operator-=(const fps &a) {
        if (a.size() > this->size()) this->resize(a.size());
        rep(i, a.size())(*this)[i] -= a[i];
        return *this;
    }
    fps &operator-=(const mint &a) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= a;
        return *this;
    }
    fps &operator*=(const mint &a) {
        rep(i, this->size())(*this)[i] *= a;
        return *this;
    }
    friend fps operator+(const fps &a, const fps &b) { return fps(a) += b; }
    friend fps operator+(const fps &a, const mint &b) { return fps(a) += b; }
    friend fps operator+(const mint &a, const fps &b) { return fps(b) += a; }
    friend fps operator-(const fps &a, const fps &b) { return fps(a) -= b; }
    friend fps operator-(const fps &a, const mint &b) { return fps(a) -= b; }
    friend fps operator-(const mint &a, const fps &b) { return fps(b) -= a; }
    friend fps operator*(const fps &a, const mint &b) { return fps(a) *= b; }
    friend fps operator*(const mint &a, const fps &b) { return fps(b) *= a; }
};

#endif