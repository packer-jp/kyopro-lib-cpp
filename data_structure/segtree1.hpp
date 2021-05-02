#include "../template.hpp"

template <typename T> struct segtree {
    int n, size;
    vector<T> vec;
    segtree(int n) : segtree(vector<T>(n, T::e())) {}
    segtree(vector<T> &src) : n(src.size()) {
        for (size = 1; size < n; size <<= 1) {}
        vec.resize(size << 1);
        copy(all(src), vec.begin() + size);
        for (int i = size - 1; i > 0; i--) vec[i] = T::op(vec[i << 1 | 0], vec[i << 1 | 1]);
    }
    void set(int i, T x) {
        vec[i += size] = x;
        while (i >>= 1) vec[i] = T::op(vec[i << 1 | 0], vec[i << 1 | 1]);
    }
    T get(int i) { return vec[i + size]; }
    T prod(int l, int r) {
        T a = T::e(), b = T::e();
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) a = T::op(a, vec[l++]);
            if (r & 1) b = T::op(vec[--r], b);
        }
        return T::op(a, b);
    }
    template <typename F> int max_right(int l, F f) {
        if (l == n) return n;
        T a = T::e();
        l += size;
        do {
            T na = T::op(a, vec[l]);
            if (f(na)) {
                a = na;
                l++;
                if (~l & 1) l >>= 1;
            } else {
                int nl = l << 1;
                if (nl >= vec.size()) return l - size;
                l = nl;
            }
        } while ((l & -l) != l);
        return n;
    }
    template <typename F> int min_left(int r, F f) {
        if (r == 0) return 0;
        T a = T::e();
        r += size;
        do {
            T na = T::op(vec[r - 1], a);
            if (f(na)) {
                a = na;
                r--;
                if (~r & 1) r >>= 1;
            } else {
                int nr = r << 1;
                if (nr >= vec.size()) return r - size;
                r = nr;
            }
        } while ((r & -r) != r);
        return 0;
    }
};

struct min_monoid {
    ll val;
    min_monoid(ll val) : val(val) {}
    static min_monoid op(min_monoid &a, min_monoid &b) { return min(a.val, b.val); }
    static min_monoid e() { return numeric_limits<ll>::max(); }
};

struct plus_monoid {
    ll val;
    plus_monoid(ll val) : val(val) {}
    static plus_monoid op(plus_monoid &a, plus_monoid &b) { return a.val + b.val; }
    static plus_monoid e() { return 0; }
};