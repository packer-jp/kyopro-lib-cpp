#pragma once

#include "../data_structure/fenwick_tree.hpp"
#include "../template.hpp"

ll inversion(const vll &v) {
    ll n = v.size();
    fenwick_tree<ll> ft(n);
    ll ret = 0;
    for (ll vi : v) {
        ret += ft.sum(vi, n);
        ft.add(vi, 1);
    }
    return ret;
}