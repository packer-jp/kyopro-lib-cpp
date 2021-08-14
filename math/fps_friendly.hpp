#ifndef PWMTREE_FPS_FRIENDLY_HPP
#define PWMTREE_FPS_FRIENDLY_HPP 1

#include "../template.hpp"
#include "convolution.hpp"
#include "fps.hpp"
#include "modint.hpp"

template <typename mint, ll ROOT> struct fps_friendly : fps<mint> {
    using fps<mint>::fps;
    using fps<mint>::operator=;
    fps_friendly &operator*=(const fps_friendly &a) {
        *this = convolution_friendly<mint, ROOT>(*this, a);
        return *this;
    }
    friend fps_friendly operator*(const fps_friendly &a, const fps_friendly &b) { return fps_friendly(a) *= b; }
    fps_friendly inv(ll d) {
        fps_friendly ret{(*this)[0].inv()};
        while (ret.size() < d) {
            ll m = ret.size();
            ret = 2 * ret - *this * ret * ret;
            ret.resize(2 * m);
        }
        ret.resize(d);
        return ret;
    }
};

#endif