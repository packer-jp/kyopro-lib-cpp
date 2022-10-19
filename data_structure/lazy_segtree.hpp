#pragma once

#include "../template.hpp"

template <typename P> struct lazy_segtree {
    using V = typename P::V;
    using F = typename P::F;
    ll n, size;
    vector<V> val;
    vector<F> lazy;
    lazy_segtree(ll n) : lazy_segtree(vector(n, P::e())) {}
    lazy_segtree(const vector<V> &src) : n(src.size()) {
        size = pw(clg(n));
        val.resize(size << 1, P::e());
        copy(all(src), val.begin() + size);
        lazy.resize(size << 1, P::id());
        for (ll i : per(1, size)) val[i] = P::op(val[i << 1 | 0], val[i << 1 | 1]);
    }
    V reflect(ll i) { return P::mapping(lazy[i], val[i]); }
    void push(ll i) {
        val[i] = P::mapping(lazy[i], val[i]);
        lazy[i << 1 | 0] = P::composition(lazy[i], lazy[i << 1 | 0]);
        lazy[i << 1 | 1] = P::composition(lazy[i], lazy[i << 1 | 1]);
        lazy[i] = P::id();
    }
    void thrust(ll i) {
        for (ll j = flg(n); j; j--) push(i >> j);
    }
    void recalc(ll i) {
        while (i >>= 1) val[i] = P::op(reflect(i << 1 | 0), reflect(i << 1 | 1));
    }
    void set(ll i, const V &a) {
        thrust(i += size);
        val[i] = a;
        lazy[i] = P::id();
        recalc(i);
    }
    void apply(ll l, ll r, F f) {
        if (l >= r) return;
        thrust(l += size);
        thrust(r += size - 1);
        for (ll i = l, j = r + 1; i < j; i >>= 1, j >>= 1) {
            if (i & 1) lazy[i] = P::composition(f, lazy[i]), ++i;
            if (j & 1) --j, lazy[j] = P::composition(f, lazy[j]);
        }
        recalc(l);
        recalc(r);
    }
    V get(ll i) {
        thrust(i += size);
        return reflect(i);
    }
    V prod(ll l, ll r) {
        if (l >= r) return P::e();
        thrust(l += size);
        thrust(r += size - 1);
        V a = P::e(), b = P::e();
        for (++r; l < r; l >>= 1, r >>= 1) {
            if (l & 1) a = P::op(a, reflect(l++));
            if (r & 1) b = P::op(reflect(--r), b);
        }
        return P::op(a, b);
    }
    template <typename G> ll max_right(ll l, G g) {
        if (l == n) return n;
        thrust(l += size);
        V a = P::e();
        do {
            while (~l & 1) l >>= 1;
            if (!g(P::op(a, reflect(l)))) {
                while (l < size) {
                    push(l);
                    l = l << 1 | 0;
                    if (g(P::op(a, reflect(l)))) a = P::op(a, reflect(l++));
                }
                return l - size;
            }
            a = P::op(a, reflect(l++));
        } while ((l & -l) != l);
        return n;
    }
    template <typename G> ll min_left(ll r, G g) {
        if (r == 0) return 0;
        thrust((r += size) - 1);
        V a = P::e();
        do {
            --r;
            while (r > 1 && r & 1) r >>= 1;
            if (!g(P::op(reflect(r), a))) {
                while (r < size) {
                    push(r);
                    r = r << 1 | 1;
                    if (g(P::op(reflect(r), a))) a = P::op(reflect(r--), a);
                }
                return r + 1 - size;
            }
            a = P::op(reflect(r), a);
        } while ((r & -r) != r);
        return 0;
    }
};

struct min_monoid_with_addition {
    using V = ll;
    using F = ll;
    static V op(V a, V b) { return min(a, b); }
    static V e() { return LLONG_MAX; }
    static V mapping(F f, V a) { return a == e() ? a : f + a; }
    static F composition(F f, F g) { return f + g; }
    static F id() { return 0; }
};

struct min_monoid_with_update {
    using V = ll;
    using F = ll;
    static V op(V a, V b) { return min(a, b); }
    static V e() { return LLONG_MAX; }
    static V mapping(F f, V a) { return f == id() ? a : f; }
    static F composition(F f, F g) { return f == id() ? g : f; }
    static F id() { return -1; };
};

struct sum_monoid_with_addition {
    using V = pair<ll, ll>;
    using F = ll;
    static V op(V a, V b) { return {a.first + b.first, a.second + b.second}; }
    static V e() { return {0, 0}; }
    static V mapping(F f, V a) { return {a.first + f * a.second, a.second}; }
    static F composition(F f, F g) { return f + g; }
    static F id() { return 0; };
};

struct sum_monoid_with_update {
    using V = pair<ll, ll>;
    using F = ll;
    static V op(V a, V b) { return {a.first + b.first, a.second + b.second}; }
    static V e() { return {0, 0}; }
    static V mapping(F f, V a) { return f == id() ? a : make_pair(f * a.second, a.second); }
    static F composition(F f, F g) { return f == id() ? g : f; }
    static F id() { return LLONG_MIN; };
};

template <typename T> struct sum_monoid_with_affine {
    using V = pair<T, ll>;
    using F = pair<T, T>;
    static V op(V a, V b) { return {a.first + b.first, a.second + b.second}; }
    static V e() { return {0, 0}; }
    static V mapping(F f, V a) { return {f.first * a.first + f.second * a.second, a.second}; }
    static F composition(F f, F g) { return {f.first * g.first, f.second + f.first * g.second}; }
    static F id() { return {1, 0}; };
};