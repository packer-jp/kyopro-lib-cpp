---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/onlinejudge.u-aizu.ac.jp/The_Smallest_Window_I.0.test.cpp
    title: test/onlinejudge.u-aizu.ac.jp/The_Smallest_Window_I.0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/onlinejudge.u-aizu.ac.jp/The_Smallest_Window_I.1.test.cpp
    title: test/onlinejudge.u-aizu.ac.jp/The_Smallest_Window_I.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/hld.test.cpp
    title: test/unit/hld.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/segtree.hpp\"\n\n#line 2 \"template.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define all(a) begin(a),\
    \ end(a)\n#define rall(a) rbegin(a), rend(a)\n#define uniq(a) (a).erase(unique(all(a)),\
    \ (a).end())\n#define t0 first\n#define t1 second\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing pll = pair<ll, ll>;\nusing vll = vector<ll>;\n\
    constexpr double pi = 3.14159265358979323846;\nconstexpr ll dy[9] = {0, 1, 0,\
    \ -1, 1, 1, -1, -1, 0};\nconstexpr ll dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};\n\
    constexpr ll sign(ll a) { return (a > 0) - (a < 0); }\nconstexpr ll fdiv(ll a,\
    \ ll b) { return a / b - ((a ^ b) < 0 && a % b); }\nconstexpr ll cdiv(ll a, ll\
    \ b) { return -fdiv(-a, b); }\nconstexpr ll pw(ll n) { return 1ll << n; }\nconstexpr\
    \ ll flg(ll n) { return 63 - __builtin_clzll(n); }\nconstexpr ll clg(ll n) { return\
    \ n == 1 ? 0 : flg(n - 1) + 1; }\nconstexpr ll safemod(ll x, ll mod) { return\
    \ (x % mod + mod) % mod; }\ntemplate <typename T> using priority_queue_rev = priority_queue<T,\
    \ vector<T>, greater<T>>;\ntemplate <typename T> constexpr T sq(const T &a) {\
    \ return a * a; }\ntemplate <typename T, typename U> constexpr bool chmax(T &a,\
    \ const U &b) { return a < b ? a = b, true : false; }\ntemplate <typename T, typename\
    \ U> constexpr bool chmin(T &a, const U &b) { return a > b ? a = b, true : false;\
    \ }\ntemplate <typename T, typename U> ostream &operator<<(ostream &os, const\
    \ pair<T, U> &a) {\n    os << \"(\" << a.first << \", \" << a.second << \")\"\
    ;\n    return os;\n}\ntemplate <typename T, typename U, typename V> ostream &operator<<(ostream\
    \ &os, const tuple<T, U, V> &a) {\n    os << \"(\" << get<0>(a) << \", \" << get<1>(a)\
    \ << \", \" << get<2>(a) << \")\";\n    return os;\n}\ntemplate <typename T> ostream\
    \ &operator<<(ostream &os, const vector<T> &a) {\n    os << \"(\";\n    for (auto\
    \ itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end()\
    \ ? \", \" : \"\");\n    os << \")\";\n    return os;\n}\ntemplate <typename T>\
    \ ostream &operator<<(ostream &os, const set<T> &a) {\n    os << \"(\";\n    for\
    \ (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end()\
    \ ? \", \" : \"\");\n    os << \")\";\n    return os;\n}\ntemplate <typename T>\
    \ ostream &operator<<(ostream &os, const multiset<T> &a) {\n    os << \"(\";\n\
    \    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr)\
    \ != a.end() ? \", \" : \"\");\n    os << \")\";\n    return os;\n}\ntemplate\
    \ <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &a)\
    \ {\n    os << \"(\";\n    for (auto itr = a.begin(); itr != a.end(); ++itr) os\
    \ << *itr << (next(itr) != a.end() ? \", \" : \"\");\n    os << \")\";\n    return\
    \ os;\n}\n#ifdef ONLINE_JUDGE\n#define dump(...) (void(0))\n#else\nvoid debug()\
    \ { cerr << endl; }\ntemplate <typename Head, typename... Tail> void debug(Head\
    \ &&head, Tail &&... tail) {\n    cerr << head;\n    if (sizeof...(Tail)) cerr\
    \ << \", \";\n    debug(tail...);\n}\n#define dump(...) cerr << __LINE__ << \"\
    : \" << #__VA_ARGS__ << \" = \", debug(__VA_ARGS__)\n#endif\nstruct rep {\n  \
    \  struct itr {\n        ll v;\n        itr(ll v) : v(v) {}\n        void operator++()\
    \ { ++v; }\n        ll operator*() const { return v; }\n        bool operator!=(itr\
    \ i) const { return v < *i; }\n    };\n    ll l, r;\n    rep(ll l, ll r) : l(l),\
    \ r(r) {}\n    rep(ll r) : rep(0, r) {}\n    itr begin() const { return l; };\n\
    \    itr end() const { return r; };\n};\nstruct per {\n    struct itr {\n    \
    \    ll v;\n        itr(ll v) : v(v) {}\n        void operator++() { --v; }\n\
    \        ll operator*() const { return v; }\n        bool operator!=(itr i) const\
    \ { return v > *i; }\n    };\n    ll l, r;\n    per(ll l, ll r) : l(l), r(r) {}\n\
    \    per(ll r) : per(0, r) {}\n    itr begin() const { return r - 1; };\n    itr\
    \ end() const { return l - 1; };\n};\nstruct io_setup {\n    static constexpr\
    \ int PREC = 20;\n    io_setup() {\n        cout << fixed << setprecision(PREC);\n\
    \        cerr << fixed << setprecision(PREC);\n    };\n} iOS;\n#line 4 \"data_structure/segtree.hpp\"\
    \n\ntemplate <typename P> struct segtree {\n    using V = typename P::V;\n   \
    \ ll n, size;\n    vector<V> val;\n    segtree(ll n) : segtree(vector(n, P::e()))\
    \ {}\n    segtree(const vector<V> &src) : n(src.size()) {\n        size = pw(clg(n));\n\
    \        val.resize(size << 1);\n        copy(all(src), val.begin() + size);\n\
    \        for (ll i : per(1, size)) val[i] = P::op(val[i << 1 | 0], val[i << 1\
    \ | 1]);\n    }\n    void set(ll i, const V &a) {\n        val[i += size] = a;\n\
    \        while (i >>= 1) val[i] = P::op(val[i << 1 | 0], val[i << 1 | 1]);\n \
    \   }\n    V get(ll i) const { return val[i + size]; }\n    V prod(ll l, ll r)\
    \ const {\n        V a = P::e(), b = P::e();\n        for (l += size, r += size;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (l & 1) a = P::op(a, val[l++]);\n\
    \            if (r & 1) b = P::op(val[--r], b);\n        }\n        return P::op(a,\
    \ b);\n    }\n    template <typename F> ll max_right(ll l, F f) const {\n    \
    \    if (l == n) return n;\n        V a = P::e();\n        l += size;\n      \
    \  do {\n            while (~l & 1) l >>= 1;\n            if (!f(P::op(a, val[l])))\
    \ {\n                while (l < size) {\n                    l = l << 1;\n   \
    \                 if (f(P::op(a, val[l]))) a = P::op(a, val[l++]);\n         \
    \       }\n                return l - size;\n            }\n            a = P::op(a,\
    \ val[l++]);\n        } while ((l & -l) != l);\n        return n;\n    }\n   \
    \ template <typename F> ll min_left(ll r, F f) const {\n        if (r == 0) return\
    \ 0;\n        V a = P::e();\n        r += size;\n        do {\n            r--;\n\
    \            while (r > 1 && r & 1) r >>= 1;\n            if (!f(P::op(val[r],\
    \ a))) {\n                while (r < size) {\n                    r = r << 1 |\
    \ 1;\n                    if (f(P::op(val[r], a))) a = P::op(val[r--], a);\n \
    \               }\n                return r + 1 - size;\n            }\n     \
    \       a = P::op(val[r], a);\n        } while ((r & -r) != r);\n        return\
    \ 0;\n    }\n};\n\nstruct min_monoid {\n    using V = ll;\n    static V op(V a,\
    \ V b) { return min(a, b); }\n    static V e() { return LLONG_MAX; }\n};\n\nstruct\
    \ sum_monoid {\n    using V = ll;\n    static V op(V a, V b) { return a + b; }\n\
    \    static V e() { return 0; }\n};\n"
  code: "#pragma once\n\n#include \"../template.hpp\"\n\ntemplate <typename P> struct\
    \ segtree {\n    using V = typename P::V;\n    ll n, size;\n    vector<V> val;\n\
    \    segtree(ll n) : segtree(vector(n, P::e())) {}\n    segtree(const vector<V>\
    \ &src) : n(src.size()) {\n        size = pw(clg(n));\n        val.resize(size\
    \ << 1);\n        copy(all(src), val.begin() + size);\n        for (ll i : per(1,\
    \ size)) val[i] = P::op(val[i << 1 | 0], val[i << 1 | 1]);\n    }\n    void set(ll\
    \ i, const V &a) {\n        val[i += size] = a;\n        while (i >>= 1) val[i]\
    \ = P::op(val[i << 1 | 0], val[i << 1 | 1]);\n    }\n    V get(ll i) const { return\
    \ val[i + size]; }\n    V prod(ll l, ll r) const {\n        V a = P::e(), b =\
    \ P::e();\n        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n   \
    \         if (l & 1) a = P::op(a, val[l++]);\n            if (r & 1) b = P::op(val[--r],\
    \ b);\n        }\n        return P::op(a, b);\n    }\n    template <typename F>\
    \ ll max_right(ll l, F f) const {\n        if (l == n) return n;\n        V a\
    \ = P::e();\n        l += size;\n        do {\n            while (~l & 1) l >>=\
    \ 1;\n            if (!f(P::op(a, val[l]))) {\n                while (l < size)\
    \ {\n                    l = l << 1;\n                    if (f(P::op(a, val[l])))\
    \ a = P::op(a, val[l++]);\n                }\n                return l - size;\n\
    \            }\n            a = P::op(a, val[l++]);\n        } while ((l & -l)\
    \ != l);\n        return n;\n    }\n    template <typename F> ll min_left(ll r,\
    \ F f) const {\n        if (r == 0) return 0;\n        V a = P::e();\n       \
    \ r += size;\n        do {\n            r--;\n            while (r > 1 && r &\
    \ 1) r >>= 1;\n            if (!f(P::op(val[r], a))) {\n                while\
    \ (r < size) {\n                    r = r << 1 | 1;\n                    if (f(P::op(val[r],\
    \ a))) a = P::op(val[r--], a);\n                }\n                return r +\
    \ 1 - size;\n            }\n            a = P::op(val[r], a);\n        } while\
    \ ((r & -r) != r);\n        return 0;\n    }\n};\n\nstruct min_monoid {\n    using\
    \ V = ll;\n    static V op(V a, V b) { return min(a, b); }\n    static V e() {\
    \ return LLONG_MAX; }\n};\n\nstruct sum_monoid {\n    using V = ll;\n    static\
    \ V op(V a, V b) { return a + b; }\n    static V e() { return 0; }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/segtree.hpp
  requiredBy: []
  timestamp: '2022-10-20 00:26:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/onlinejudge.u-aizu.ac.jp/The_Smallest_Window_I.1.test.cpp
  - test/onlinejudge.u-aizu.ac.jp/The_Smallest_Window_I.0.test.cpp
  - test/unit/hld.test.cpp
documentation_of: data_structure/segtree.hpp
layout: document
title: Segment Tree
---

## 概要
- モノイド $(V, \times)$ を考える。
- 長さ $n$ の $V$ の元の列 $s$ に対する処理を行う。

## 詳細

- `<typename S> struct segtree`  
    Segment Tree 本体。

    - `typename S`  
        テンプレート引数として与える構造体。

        - `using val_t`  
            $V$ を表す型。

        - `static val_t op(val_t a, val_t b)`  
            $a \times b$ を返す。
        
        - `static val_t e()`  
            $(V, \times)$ の単位元 $e$ を返す。

    - `(constructor)(int n)`  
        長さ $n$ 、全要素 $e$ で初期化。

    - `(constructor)(vector<S::val_t> src)`  
        $s := src$ として初期化。

    - `void set(int i, S::val_t a)`  
        要素 $i$ を $a$ に置き換える。$O(\log n)$ 時間。

    - `S::val_t get(int i)`  
        $i$ 番目の要素を得る。 $O(\log n)$ 時間。
    
    - `S::val_t prod(int l, int r)`  
        $e \times s_l \times \cdots \times s_{r-1}$ を計算する。 $O(\log n)$ 時間。

    - `<typename G> max_right(int l, G g)`  
        述語 $g$ について、
        - $g(prod(l, r))$
        - $r = n \lor \lnot g(prod(l, r + 1))$

        を共に満たす $r$ をいずれか一つ返す。 $O(\log n)$ 時間。 $g(e)$ を要請。


    - `<typename G> int min_left(int r, G g)`  
        述語 $g$ について、
        - $g(prod(l, r))$
        - $l = 0 \lor \lnot g(prod(l - 1, r))$

        を共に満たす $l$ をいずれか一つ返す。 $O(\log n)$ 時間。 $g(e)$ を要請。

- `struct min_monoid_with_addition`  
    区間最小/一点更新クエリを処理するときに`segtree`にテンプレート引数 `S` として与える。

- `struct sum_monoid_with_update`  
    区間和/一点更新クエリを処理するときに`segtree`にテンプレート引数 `S` として与える。

## 参考
- [ACL](https://atcoder.github.io/ac-library/production/document_ja/segtree.html)
- [えびちゃんさんのスライド](https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf)