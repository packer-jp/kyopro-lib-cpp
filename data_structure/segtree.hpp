#pragma once

#include "../template.hpp"

template <typename P> struct segtree {
    using V = typename P::V;
    ll n, size;
    vector<V> val;
    segtree(ll n) : segtree(vector(n, P::e())) {}
    segtree(const vector<V> &src) : n(src.size()) {
        for (size = 1; size < n; size <<= 1) {}
        val.resize(size << 1);
        copy(all(src), val.begin() + size);
        for (ll i : per(1, size)) val[i] = P::op(val[i << 1 | 0], val[i << 1 | 1]);
    }
    void set(ll i, const V &a) {
        val[i += size] = a;
        while (i >>= 1) val[i] = P::op(val[i << 1 | 0], val[i << 1 | 1]);
    }
    V get(ll i) const { return val[i + size]; }
    V prod(ll l, ll r) const {
        V a = P::e(), b = P::e();
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) a = P::op(a, val[l++]);
            if (r & 1) b = P::op(val[--r], b);
        }
        return P::op(a, b);
    }
    template <typename F> ll max_right(ll l, F f) const {
        if (l == n) return n;
        V a = P::e();
        l += size;
        do {
            while (~l & 1) l >>= 1;
            if (!f(P::op(a, val[l]))) {
                while (l < size) {
                    l = l << 1;
                    if (f(P::op(a, val[l]))) a = P::op(a, val[l++]);
                }
                return l - size;
            }
            a = P::op(a, val[l++]);
        } while ((l & -l) != l);
        return n;
    }
    template <typename F> ll min_left(ll r, F f) const {
        if (r == 0) return 0;
        V a = P::e();
        r += size;
        do {
            r--;
            while (r > 1 && r & 1) r >>= 1;
            if (!f(P::op(val[r], a))) {
                while (r < size) {
                    r = r << 1 | 1;
                    if (f(P::op(val[r], a))) a = P::op(val[r--], a);
                }
                return r + 1 - size;
            }
            a = P::op(val[r], a);
        } while ((r & -r) != r);
        return 0;
    }
};

struct min_monoid {
    using V = ll;
    static V op(V a, V b) { return min(a, b); }
    static V e() { return LLONG_MAX; }
};

struct sum_monoid {
    using V = ll;
    static V op(V a, V b) { return a + b; }
    static V e() { return 0; }
};