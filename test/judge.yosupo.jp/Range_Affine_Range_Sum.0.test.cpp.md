---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segtree.hpp
    title: "\u9045\u5EF6\u8A55\u4FA1 Segment Tree"
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/judge.yosupo.jp/Range_Affine_Range_Sum.0.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    #line 2 \"data_structure/lazy_segtree.hpp\"\n\n#line 2 \"template.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define all(a) begin(a), end(a)\n#define\
    \ rall(a) rbegin(a), rend(a)\n#define uniq(a) (a).erase(unique(all(a)), (a).end())\n\
    #define t0 first\n#define t1 second\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing pll = pair<ll, ll>;\nusing vll = vector<ll>;\nconstexpr double\
    \ pi = 3.14159265358979323846;\nconstexpr ll dy[9] = {0, 1, 0, -1, 1, 1, -1, -1,\
    \ 0};\nconstexpr ll dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};\nconstexpr ll sign(ll\
    \ a) { return (a > 0) - (a < 0); }\nconstexpr ll fdiv(ll a, ll b) { return a /\
    \ b - ((a ^ b) < 0 && a % b); }\nconstexpr ll cdiv(ll a, ll b) { return -fdiv(-a,\
    \ b); }\nconstexpr ll pw(ll n) { return 1ll << n; }\nconstexpr ll flg(ll n) {\
    \ return 63 - __builtin_clzll(n); }\nconstexpr ll clg(ll n) { return n == 1 ?\
    \ 0 : flg(n - 1) + 1; }\nconstexpr ll safemod(ll x, ll mod) { return (x % mod\
    \ + mod) % mod; }\ntemplate <typename T> using priority_queue_rev = priority_queue<T,\
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
    \        cerr << fixed << setprecision(PREC);\n    };\n} iOS;\n#line 4 \"data_structure/lazy_segtree.hpp\"\
    \n\ntemplate <typename P> struct lazy_segtree {\n    using V = typename P::V;\n\
    \    using F = typename P::F;\n    ll n, size;\n    vector<V> val;\n    vector<F>\
    \ lazy;\n    lazy_segtree(ll n) : lazy_segtree(vector(n, P::e())) {}\n    lazy_segtree(const\
    \ vector<V> &src) : n(src.size()) {\n        size = pw(clg(n));\n        val.resize(size\
    \ << 1, P::e());\n        copy(all(src), val.begin() + size);\n        lazy.resize(size\
    \ << 1, P::id());\n        for (ll i : per(1, size)) val[i] = P::op(val[i << 1\
    \ | 0], val[i << 1 | 1]);\n    }\n    V reflect(ll i) { return P::mapping(lazy[i],\
    \ val[i]); }\n    void push(ll i) {\n        val[i] = P::mapping(lazy[i], val[i]);\n\
    \        lazy[i << 1 | 0] = P::composition(lazy[i], lazy[i << 1 | 0]);\n     \
    \   lazy[i << 1 | 1] = P::composition(lazy[i], lazy[i << 1 | 1]);\n        lazy[i]\
    \ = P::id();\n    }\n    void thrust(ll i) {\n        for (ll j = flg(n); j; j--)\
    \ push(i >> j);\n    }\n    void recalc(ll i) {\n        while (i >>= 1) val[i]\
    \ = P::op(reflect(i << 1 | 0), reflect(i << 1 | 1));\n    }\n    void set(ll i,\
    \ const V &a) {\n        thrust(i += size);\n        val[i] = a;\n        lazy[i]\
    \ = P::id();\n        recalc(i);\n    }\n    void apply(ll l, ll r, F f) {\n \
    \       if (l >= r) return;\n        thrust(l += size);\n        thrust(r += size\
    \ - 1);\n        for (ll i = l, j = r + 1; i < j; i >>= 1, j >>= 1) {\n      \
    \      if (i & 1) lazy[i] = P::composition(f, lazy[i]), ++i;\n            if (j\
    \ & 1) --j, lazy[j] = P::composition(f, lazy[j]);\n        }\n        recalc(l);\n\
    \        recalc(r);\n    }\n    V get(ll i) {\n        thrust(i += size);\n  \
    \      return reflect(i);\n    }\n    V prod(ll l, ll r) {\n        if (l >= r)\
    \ return P::e();\n        thrust(l += size);\n        thrust(r += size - 1);\n\
    \        V a = P::e(), b = P::e();\n        for (++r; l < r; l >>= 1, r >>= 1)\
    \ {\n            if (l & 1) a = P::op(a, reflect(l++));\n            if (r & 1)\
    \ b = P::op(reflect(--r), b);\n        }\n        return P::op(a, b);\n    }\n\
    \    template <typename G> ll max_right(ll l, G g) {\n        if (l == n) return\
    \ n;\n        thrust(l += size);\n        V a = P::e();\n        do {\n      \
    \      while (~l & 1) l >>= 1;\n            if (!g(P::op(a, reflect(l)))) {\n\
    \                while (l < size) {\n                    push(l);\n          \
    \          l = l << 1 | 0;\n                    if (g(P::op(a, reflect(l)))) a\
    \ = P::op(a, reflect(l++));\n                }\n                return l - size;\n\
    \            }\n            a = P::op(a, reflect(l++));\n        } while ((l &\
    \ -l) != l);\n        return n;\n    }\n    template <typename G> ll min_left(ll\
    \ r, G g) {\n        if (r == 0) return 0;\n        thrust((r += size) - 1);\n\
    \        V a = P::e();\n        do {\n            --r;\n            while (r >\
    \ 1 && r & 1) r >>= 1;\n            if (!g(P::op(reflect(r), a))) {\n        \
    \        while (r < size) {\n                    push(r);\n                  \
    \  r = r << 1 | 1;\n                    if (g(P::op(reflect(r), a))) a = P::op(reflect(r--),\
    \ a);\n                }\n                return r + 1 - size;\n            }\n\
    \            a = P::op(reflect(r), a);\n        } while ((r & -r) != r);\n   \
    \     return 0;\n    }\n};\n\nstruct min_monoid_with_addition {\n    using V =\
    \ ll;\n    using F = ll;\n    static V op(V a, V b) { return min(a, b); }\n  \
    \  static V e() { return LLONG_MAX; }\n    static V mapping(F f, V a) { return\
    \ a == e() ? a : f + a; }\n    static F composition(F f, F g) { return f + g;\
    \ }\n    static F id() { return 0; }\n};\n\nstruct min_monoid_with_update {\n\
    \    using V = ll;\n    using F = ll;\n    static V op(V a, V b) { return min(a,\
    \ b); }\n    static V e() { return LLONG_MAX; }\n    static V mapping(F f, V a)\
    \ { return f == id() ? a : f; }\n    static F composition(F f, F g) { return f\
    \ == id() ? g : f; }\n    static F id() { return -1; };\n};\n\nstruct sum_monoid_with_addition\
    \ {\n    using V = pair<ll, ll>;\n    using F = ll;\n    static V op(V a, V b)\
    \ { return {a.first + b.first, a.second + b.second}; }\n    static V e() { return\
    \ {0, 0}; }\n    static V mapping(F f, V a) { return {a.first + f * a.second,\
    \ a.second}; }\n    static F composition(F f, F g) { return f + g; }\n    static\
    \ F id() { return 0; };\n};\n\nstruct sum_monoid_with_update {\n    using V =\
    \ pair<ll, ll>;\n    using F = ll;\n    static V op(V a, V b) { return {a.first\
    \ + b.first, a.second + b.second}; }\n    static V e() { return {0, 0}; }\n  \
    \  static V mapping(F f, V a) { return f == id() ? a : make_pair(f * a.second,\
    \ a.second); }\n    static F composition(F f, F g) { return f == id() ? g : f;\
    \ }\n    static F id() { return LLONG_MIN; };\n};\n\ntemplate <typename T> struct\
    \ sum_monoid_with_affine {\n    using V = pair<T, ll>;\n    using F = pair<T,\
    \ T>;\n    static V op(V a, V b) { return {a.first + b.first, a.second + b.second};\
    \ }\n    static V e() { return {0, 0}; }\n    static V mapping(F f, V a) { return\
    \ {f.first * a.first + f.second * a.second, a.second}; }\n    static F composition(F\
    \ f, F g) { return {f.first * g.first, f.second + f.first * g.second}; }\n   \
    \ static F id() { return {1, 0}; };\n};\n#line 2 \"math/modint.hpp\"\n\n#line\
    \ 4 \"math/modint.hpp\"\n\ntemplate <typename M> struct modint {\n    ll val;\n\
    \    modint(ll val = 0) : val(val >= 0 ? val % M::mod : (M::mod - (-val) % M::mod)\
    \ % M::mod) {}\n    static ll mod() { return M::mod; }\n    modint inv() const\
    \ {\n        ll a = val, b = M::mod, u = 1, v = 0, t;\n        while (b > 0) {\n\
    \            t = a / b;\n            swap(a -= t * b, b);\n            swap(u\
    \ -= t * v, v);\n        }\n        return u;\n    }\n    modint pow(ll k) const\
    \ {\n        modint ret = 1, mul = val;\n        while (k) {\n            if (k\
    \ & 1) ret *= mul;\n            mul *= mul;\n            k >>= 1;\n        }\n\
    \        return ret;\n    }\n    modint &operator+=(const modint &a) {\n     \
    \   if ((val += a.val) >= M::mod) val -= M::mod;\n        return *this;\n    }\n\
    \    modint &operator-=(const modint &a) {\n        if ((val += M::mod - a.val)\
    \ >= M::mod) val -= M::mod;\n        return *this;\n    }\n    modint &operator*=(const\
    \ modint &a) {\n        (val *= a.val) %= M::mod;\n        return *this;\n   \
    \ }\n    modint &operator/=(const modint &a) { return *this *= a.inv(); }\n  \
    \  modint operator+() const { return *this; }\n    modint operator-() const {\
    \ return modint(-val); }\n    friend bool operator==(const modint &a, const modint\
    \ &b) { return a.val == b.val; }\n    friend bool operator!=(const modint &a,\
    \ const modint &b) { return rel_ops::operator!=(a, b); }\n    friend modint operator+(const\
    \ modint &a, const modint &b) { return modint(a) += b; }\n    friend modint operator-(const\
    \ modint &a, const modint &b) { return modint(a) -= b; }\n    friend modint operator*(const\
    \ modint &a, const modint &b) { return modint(a) *= b; }\n    friend modint operator/(const\
    \ modint &a, const modint &b) { return modint(a) /= b; }\n    friend istream &operator>>(istream\
    \ &is, modint &a) {\n        ll val;\n        is >> val;\n        a = modint(val);\n\
    \        return is;\n    }\n    friend ostream &operator<<(ostream &os, const\
    \ modint &a) { return os << a.val; }\n};\n\nstruct _998244353 {\n    constexpr\
    \ static ll mod = 998244353;\n};\nstruct _1000000007 {\n    constexpr static ll\
    \ mod = 1000000007;\n};\nusing modint998244353 = modint<_998244353>;\nusing modint1000000007\
    \ = modint<_1000000007>;\n\nstruct arbitrary {\n    static ll mod;\n};\nll arbitrary::mod;\n\
    #line 4 \"test/judge.yosupo.jp/Range_Affine_Range_Sum.0.test.cpp\"\n\nint main()\
    \ {\n    using mint = modint998244353;\n    ll n, q;\n    cin >> n >> q;\n   \
    \ vector<pair<mint, ll>> src(n, {0, 1});\n    for (ll i : rep(n)) cin >> src[i].first;\n\
    \    lazy_segtree<sum_monoid_with_affine<mint>> lst(src);\n    while (q--) {\n\
    \        ll t, l, r;\n        cin >> t >> l >> r;\n        if (t == 0) {\n   \
    \         ll b, c;\n            cin >> b >> c;\n            lst.apply(l, r, {b,\
    \ c});\n        }\n        if (t == 1) { cout << lst.prod(l, r).first << endl;\
    \ }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"../../data_structure/lazy_segtree.hpp\"\n#include \"../../math/modint.hpp\"\
    \n\nint main() {\n    using mint = modint998244353;\n    ll n, q;\n    cin >>\
    \ n >> q;\n    vector<pair<mint, ll>> src(n, {0, 1});\n    for (ll i : rep(n))\
    \ cin >> src[i].first;\n    lazy_segtree<sum_monoid_with_affine<mint>> lst(src);\n\
    \    while (q--) {\n        ll t, l, r;\n        cin >> t >> l >> r;\n       \
    \ if (t == 0) {\n            ll b, c;\n            cin >> b >> c;\n          \
    \  lst.apply(l, r, {b, c});\n        }\n        if (t == 1) { cout << lst.prod(l,\
    \ r).first << endl; }\n    }\n}"
  dependsOn:
  - data_structure/lazy_segtree.hpp
  - template.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/judge.yosupo.jp/Range_Affine_Range_Sum.0.test.cpp
  requiredBy: []
  timestamp: '2022-10-20 00:25:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/judge.yosupo.jp/Range_Affine_Range_Sum.0.test.cpp
layout: document
redirect_from:
- /verify/test/judge.yosupo.jp/Range_Affine_Range_Sum.0.test.cpp
- /verify/test/judge.yosupo.jp/Range_Affine_Range_Sum.0.test.cpp.html
title: test/judge.yosupo.jp/Range_Affine_Range_Sum.0.test.cpp
---
