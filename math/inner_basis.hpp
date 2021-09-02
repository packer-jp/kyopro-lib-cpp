#pragma once

#include "../template.hpp"

vector<ull> inner_basis(vector<ull> a) {
    vector<ull> basis, ret;
    for (ull e : a) {
        ull e_ = e;
        for (ull b : basis) chmin(e, e ^ b);
        if (e) basis.push_back(e), ret.push_back(e_);
    }
    return ret;
}