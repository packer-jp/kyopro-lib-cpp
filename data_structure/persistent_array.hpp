#pragma once

#include "../template.hpp"

template <typename V, int SHIFT> struct persistent_array {
    using ptr = shared_ptr<persistent_array>;
    static constexpr int BASE = 1 << SHIFT;
    static constexpr int MASK = BASE - 1;
    V val;
    array<ptr, BASE> ch;
    persistent_array(int n = 1, V val = V()) : val(val) {
        for (int i : rep(BASE)) {
            int m = (n >> SHIFT) + ((n & MASK) > i);
            if (m > 1 || m > 0 && i > 0) ch[i] = ptr(new persistent_array(m, val));
        }
    }
    persistent_array(V val, const array<ptr, BASE> &ch) : val(val), ch(ch) {}
    persistent_array(V val, const array<ptr, BASE> &ch, int i, ptr chp) : val(val), ch(ch) { this->ch[i] = chp; }
    V get(int i) const { return i > 0 ? ch[i & MASK]->get(i >> SHIFT) : val; }
    ptr setp(int i, V val) const {
        return ptr(i > 0 ? new persistent_array(this->val, ch, i & MASK, ch[i & MASK]->setp(i >> SHIFT, val))
                         : new persistent_array(val, ch));
    }
    persistent_array set(int i, V val) const { return *setp(i, val); }
};