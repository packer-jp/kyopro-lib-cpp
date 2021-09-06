#pragma once

#include "../template.hpp"

template <typename V, int SHIFT> struct persistent_array {
    using ptr = shared_ptr<persistent_array>;
    static constexpr int BASE = 1 << SHIFT;
    static constexpr int MASK = BASE - 1;
    V val;
    array<ptr, BASE> ch;
    persistent_array(int n, V val = V(), bool ext = false) : val(val) {
        if (!ext) {
            int n_ = 1;
            while (n_ < n) n_ <<= SHIFT;
            n = n_;
        }
        if (n > 1) {
            for (int i : rep(BASE)) ch[i] = ptr(new persistent_array(n >> SHIFT, val, true));
        }
    }
    persistent_array(const persistent_array &pa) : val(pa.val), ch(pa.ch) {}
    persistent_array(V val, const array<ptr, BASE> &ch) : val(val), ch(ch) {}
    persistent_array(V val, const array<ptr, BASE> &ch, int i, ptr chp) : val(val), ch(ch) { this->ch[i] = chp; }
    V get(int i) const { return i == 0 ? val : ch[i & MASK]->get(i >> SHIFT); }
    ptr setp(int i, V val) const {
        return ptr(i == 0 ? new persistent_array(val, ch)
                          : new persistent_array(this->val, ch, i & MASK, ch[i & MASK]->setp(i >> SHIFT, val)));
    }
    persistent_array set(int i, V val) const { return *setp(i, val); }
};