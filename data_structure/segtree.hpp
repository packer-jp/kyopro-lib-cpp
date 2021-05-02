#include "../template.hpp"

template <typename M> struct segtree {
    using T = typename M::type;
    int n, size;
    vector<T> vec;
    segtree(int n) : segtree(vector<T>(n, M::e())) {}
    segtree(vector<T> &src) : n(src.size()) {
        size = 1;
        while (size < n) size <<= 1;
        vec.resize(size << 1);
        copy(all(src), vec.begin() + size);
        for (int i = size - 1; i > 0; i--) vec[i] = M::op(vec[i << 1 | 0], vec[i << 1 | 1]);
    }
    void set(int i, T x) {
        vec[i += size] = x;
        while (i >>= 1) vec[i] = M::op(vec[i << 1 | 0], vec[i << 1 | 1]);
    }
    T get(int i) { return vec[i + size]; }
    T prod(int l, int r) {
        T a = M::e(), b = M::e();
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) a = M::op(a, vec[l++]);
            if (r & 1) b = M::op(vec[--r], b);
        }
        return M::op(a, b);
    }
    template <typename F> int max_right(int l, F f) {
        if (l == n) return n;
        T a = M::e();
        l += size;
        do {
            T na = M::op(a, vec[l]);
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
        T a = M::e();
        r += size;
        do {
            T na = M::op(vec[r - 1], a);
            if (f(na)) {
                a = na;
                r--;
                if (~r & 1) r >>= 1;
            } else {
                int nr = r << 1;
                if (nr > vec.size()) return r - size;
                r = nr;
            }
        } while ((r & -r) != r);
        return 0;
    }
};

struct min_monoid {
    using type = ll;
    static type op(type &a, type &b) { return min(a, b); }
    static type e() { return numeric_limits<type>::max(); }
};

struct plus_monoid {
    using type = ll;
    static type op(type &a, type &b) { return a + b; }
    static type e() { return 0; }
};