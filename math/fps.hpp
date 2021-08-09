#ifndef PWMTREE_FPS_HPP
#define PWMTREE_FPS_HPP 1

#include "../template.hpp"
#include "convolution.hpp"
#include "modint.hpp"

template <typename mint> struct fps : vector<mint> {
    fps(mint a) {
        this->resize(1);
        *(this)[0] = a;
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
    fps &operator*=(const fps &a) {
        *this = convolution_friendly();
        return *this;
    }
};

#endif