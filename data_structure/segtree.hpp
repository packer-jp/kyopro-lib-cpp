#include "../template.hpp"

template <typename S> struct segtree {
    using V = typename S::val_t;
    int n, size;
    vector<V> val;
    segtree(int n) : segtree(vector(n, S::e())) {}
    segtree(vector<V> src) : n(src.size()) {
        for (size = 1; size < n; size <<= 1) {}
        val.resize(size << 1);
        copy(all(src), val.begin() + size);
        for (int i = size - 1; i > 0; i--) val[i] = S::op(val[i << 1 | 0], val[i << 1 | 1]);
    }
    void set(int i, V a) {
        val[i += size] = a;
        while (i >>= 1) val[i] = S::op(val[i << 1 | 0], val[i << 1 | 1]);
    }
    V get(int i) { return val[i + size]; }
    V prod(int l, int r) {
        T a = S::e(), b = S::e();
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) a = S::op(a, val[l++]);
            if (r & 1) b = S::op(val[--r], b);
        }
        return S::op(a, b);
    }
    template <typename F> int max_right(int l, F f) {
        if (l == n) return n;
        V a = S::e();
        l += size;
        do {
            V na = S::op(a, val[l]);
            if (f(na)) {
                a = na;
                l++;
                if (~l & 1) l >>= 1;
            } else {
                int nl = l << 1;
                if (nl >= val.size()) return l - size;
                l = nl;
            }
        } while ((l & -l) != l);
        return n;
    }
    template <typename F> int min_left(int r, F f) {
        if (r == 0) return 0;
        V a = S::e();
        r += size;
        do {
            V na = S::op(val[r - 1], a);
            if (f(na)) {
                a = na;
                r--;
                if (~r & 1) r >>= 1;
            } else {
                int nr = r << 1;
                if (nr >= val.size()) return r - size;
                r = nr;
            }
        } while ((r & -r) != r);
        return 0;
    }
};

struct min_monoid {
    using val_t = ll;
    static val_t op(val_t a, val_t b) { return min(a, b); }
    static val_t e() { return LLONG_MAX; }
};

struct plus_monoid {
    using val_t = ll;
    static val_t op(val_t a, val_t b) { return a + b; }
    static val_t e() { return 0; }
};