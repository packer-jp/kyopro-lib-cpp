#pragma once

#include "../template.hpp"

template <typename S> struct lazy_segtree {
    using V = typename S::val_t;
    using F = typename S::fn_t;
    int n, size, log;
    vector<V> val;
    vector<F> lazy;
    lazy_segtree(int n) : lazy_segtree(vector(n, S::e())) {}
    lazy_segtree(vector<V> src) : n(src.size()) {
        for (size = 1, log = 0; size < n; size <<= 1, log++) {}
        val.resize(size << 1);
        copy(all(src), val.begin() + size);
        lazy.resize(size << 1, S::id());
        for (int i : per(1, size)) val[i] = S::op(val[i << 1 | 0], val[i << 1 | 1]);
    }
    V reflect(int i) { return S::mapping(lazy[i], val[i]); }
    void push(int i) {
        val[i] = S::mapping(lazy[i], val[i]);
        lazy[i << 1 | 0] = S::composition(lazy[i], lazy[i << 1 | 0]);
        lazy[i << 1 | 1] = S::composition(lazy[i], lazy[i << 1 | 1]);
        lazy[i] = S::id();
    }
    void thrust(int i) {
        for (int j = log; j; j--) push(i >> j);
    }
    void recalc(int i) {
        while (i >>= 1) val[i] = S::op(reflect(i << 1 | 0), reflect(i << 1 | 1));
    }
    void set(int i, const V &a) {
        thrust(i += size);
        val[i] = a;
        lazy[i] = S::id();
        recalc(i);
    }
    void apply(int l, int r, F f) {
        thrust(l += size);
        thrust(r += size - 1);
        for (int i = l, j = r + 1; i < j; i >>= 1, j >>= 1) {
            if (i & 1) lazy[i] = S::composition(f, lazy[i]), ++i;
            if (j & 1) --j, lazy[j] = S::composition(f, lazy[j]);
        }
        recalc(l);
        recalc(r);
    }
    V get(int i) {
        thrust(i += size);
        return reflect(i);
    }
    V prod(int l, int r) {
        thrust(l += size);
        thrust(r += size - 1);
        V a = S::e(), b = S::e();
        for (r++; l < r; l >>= 1, r >>= 1) {
            if (l & 1) a = S::op(a, reflect(l++));
            if (r & 1) b = S::op(reflect(--r), b);
        }
        return S::op(a, b);
    }
    template <typename G> int max_right(int l, G g) {
        if (l == n) return n;
        thrust(l += size);
        V a = S::e();
        do {
            while (~l & 1) l >>= 1;
            if (!g(S::op(a, reflect(l)))) {
                while (l < size) {
                    push(l);
                    l = l << 1 | 0;
                    if (g(S::op(a, reflect(l)))) a = S::op(a, reflect(l++));
                }
                return l - size;
            }
            a = S::op(a, reflect(l++));
        } while ((l & -l) != l);
        return n;
    }
    template <typename G> int min_left(int r, G g) {
        if (r == 0) return 0;
        thrust((r += size) - 1);
        V a = S::e();
        do {
            r--;
            while (r > 1 && r & 1) r >>= 1;
            if (!g(S::op(reflect(r), a))) {
                while (r < size) {
                    push(r);
                    r = r << 1 | 1;
                    if (g(S::op(reflect(r), a))) a = S::op(reflect(r--), a);
                }
                return r + 1 - size;
            }
            a = S::op(reflect(r), a);
        } while ((r & -r) != r);
        return 0;
    }
};

struct min_monoid_with_addition {
    using val_t = ll;
    using fn_t = ll;
    static val_t op(val_t a, val_t b) { return min(a, b); }
    static val_t e() { return LLONG_MAX; }
    static val_t mapping(fn_t f, val_t a) { return a == e() ? a : f + a; }
    static fn_t composition(fn_t f, fn_t g) { return f + g; }
    static fn_t id() { return 0; }
};

struct min_monoid_with_update {
    using val_t = ll;
    using fn_t = ll;
    static val_t op(val_t a, val_t b) { return min(a, b); }
    static val_t e() { return LLONG_MAX; }
    static val_t mapping(fn_t f, val_t a) { return f == id() ? a : f; }
    static fn_t composition(fn_t f, fn_t g) { return f == id() ? g : f; }
    static fn_t id() { return -1; };
};

struct sum_monoid_with_addition {
    using val_t = pair<ll, ll>;
    using fn_t = ll;
    static val_t op(val_t a, val_t b) { return {a.first + b.first, a.second + b.second}; }
    static val_t e() { return {0, 0}; }
    static val_t mapping(fn_t f, val_t a) { return {a.first + f * a.second, a.second}; }
    static fn_t composition(fn_t f, fn_t g) { return f + g; }
    static fn_t id() { return 0; };
};

struct sum_monoid_with_update {
    using val_t = pair<ll, ll>;
    using fn_t = ll;
    static val_t op(val_t a, val_t b) { return {a.first + b.first, a.second + b.second}; }
    static val_t e() { return {0, 0}; }
    static val_t mapping(fn_t f, val_t a) { return f == id() ? a : make_pair(f * a.second, a.second); }
    static fn_t composition(fn_t f, fn_t g) { return f == id() ? g : f; }
    static fn_t id() { return LLONG_MIN; };
};