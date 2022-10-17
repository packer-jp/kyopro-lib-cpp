#pragma once

#include "../template.hpp"

template <typename V> pair<vector<V>, vector<V>> xor_basis(const vector<V> &a) {
    vector<V> umsb, inner;
    for (V e : a) {
        V _e = e;
        for (V b : umsb) chmin(e, e ^ b);
        if (e != T()) umsb.push_back(e), inner.push_back(_e);
    }
    return {umsb, inner};
}