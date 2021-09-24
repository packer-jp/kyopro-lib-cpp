#pragma once

#include "../template.hpp"

template <typename T> vector<T> inner_basis(const vector<T> &a) {
    vector<T> basis, ret;
    for (T e : a) {
        T _e = e;
        for (T b : basis) chmin(e, e ^ b);
        if (e != T()) basis.push_back(e), ret.push_back(_e);
    }
    return ret;
}