#pragma once

#include "../template.hpp"

template <typename S, bool MIN> struct cht {
    using V = typename S::val_t;
    struct line {
        mutable V a, b, l, r;
        bool operator<(const line &o) const { return a < o.a; };
        bool operator<(V x) const { return r < x; };
    };
    set<line, less<>> lines;
    void add(V a, V b) {
        if (MIN) a = -a, b = -b;
        line cur = {a, b, -S::inf(), S::inf()};
        auto p = lines.lower_bound(cur);
        if (p != lines.end() && p->a == a) {
            if (p->b > b) {
                return;
            } else {
                p = lines.erase(p);
            }
        }
        auto fi = [](const line &s, const line &t) -> V { return S::div(-s.b + t.b, s.a - t.a); };
        auto ci = [](const line &s, const line &t) -> V { return -S::div(s.b - t.b, s.a - t.a); };
        if (p != lines.begin() && ci(cur, *prev(p)) >= prev(p)->r && p != lines.end() && fi(cur, *p) <= p->l) return;
        while (p != lines.begin()) {
            auto pp = prev(p);
            if (ci(cur, *pp) <= pp->l) {
                lines.erase(pp);
                continue;
            }
            cur.l = ci(cur, *pp), pp->r = fi(cur, *pp);
            break;
        }
        while (p != lines.end()) {
            if (fi(cur, *p) >= p->r) {
                p = lines.erase(p);
                continue;
            }
            cur.r = fi(cur, *p), p->l = ci(cur, *p);
            break;
        }
        lines.insert(cur);
    }
    V get(V x) {
        line l = *lines.lower_bound(x);
        V ret = l.a * x + l.b;
        if (MIN) ret = -ret;
        return ret;
    }
};

struct ll_cht {
    using val_t = ll;
    static val_t div(val_t num, val_t den) { return fdiv(num, den); }
    static val_t inf() { return LLONG_MAX; }
};

struct double_cht {
    using val_t = double;
    static val_t div(val_t num, val_t den) { return num / den; }
    static val_t inf() { return numeric_limits<double>::infinity(); }
};