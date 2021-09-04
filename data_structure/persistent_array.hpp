#pragma once

#include "../template.hpp"

template <typename V, int SHIFT> struct persistent_array {
    struct node {
        V val;
        node *ch[bit(SHIFT)] = {};
    };
    static constexpr int MASK = bit(SHIFT) - 1;
    vector<node> pool, roots;
    persistent_array(int n) {
        int dep = 0;
        for (--n; n; n >>= SHIFT) ++dep;
    }
};