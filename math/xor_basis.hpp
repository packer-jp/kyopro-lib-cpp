#pragma once

#include "../template.hpp"

template <typename T> pair<vector<T>, vector<T>> xor_basis(const vector<T> &a) {
    vector<T> umsb, inner;
    for (T e : a) {
        T _e = e;
        for (T b : umsb) chmin(e, e ^ b);
        if (e != T()) umsb.push_back(e), inner.push_back(_e);
    }
    return {umsb, inner};
}