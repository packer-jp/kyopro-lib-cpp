---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/lazy_segtree.hpp
    title: "\u9045\u5EF6\u8A55\u4FA1 Segment Tree"
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
  bundledCode: "#line 1 \"test/onlinejudge.u-aizu.ac.jp/RSQ_and_RUQ.0.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\"\
    \n#line 2 \"data_structure/lazy_segtree.hpp\"\n\n#line 2 \"template.hpp\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#define all(a) begin(a), end(a)\n\
    #define rall(a) rbegin(a), rend(a)\n#define uniq(a) (a).erase(unique(all(a)),\
    \ (a).end())\n#define t0 first\n#define t1 second\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing pll = pair<ll, ll>;\nusing vll = vector<ll>;\n\
    constexpr double pi = 3.14159265358979323846;\nconstexpr ll dy[9] = {0, 1, 0,\
    \ -1, 1, 1, -1, -1, 0};\nconstexpr ll dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};\n\
    constexpr ll sign(ll a) { return (a > 0) - (a < 0); }\nconstexpr ll fdiv(ll a,\
    \ ll b) { return a / b - ((a ^ b) < 0 && a % b); }\nconstexpr ll cdiv(ll a, ll\
    \ b) { return -fdiv(-a, b); }\nconstexpr ll pw(ll n) { return 1ll << n; }\nconstexpr\
    \ ll flg(ll n) { return 63 - __builtin_clzll(n); }\nconstexpr ll clg(ll n) { return\
    \ flg(n - 1) + 1; }\nconstexpr ll safemod(ll x, ll mod) { return (x % mod + mod)\
    \ % mod; }\ntemplate <typename T> using priority_queue_rev = priority_queue<T,\
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
    \    using F = typename P::F;\n    ll n, size, log;\n    vector<V> val;\n    vector<F>\
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
    \ static F id() { return {1, 0}; };\n};\n#line 3 \"test/onlinejudge.u-aizu.ac.jp/RSQ_and_RUQ.0.test.cpp\"\
    \n\n#line 5 \"test/onlinejudge.u-aizu.ac.jp/RSQ_and_RUQ.0.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n    ll n, q;\n    cin >> n >> q;\n    vector<pair<ll,\
    \ ll>> src(n, {0, 1});\n    lazy_segtree<sum_monoid_with_update> lst(src);\n \
    \   while (q--) {\n        ll com;\n        cin >> com;\n        if (com == 0)\
    \ {\n            ll s, t, x;\n            cin >> s >> t >> x;\n            lst.apply(s,\
    \ t + 1, x);\n        } else if (com == 1) {\n            ll s, t;\n         \
    \   cin >> s >> t;\n            cout << lst.prod(s, t + 1).first << endl;\n  \
    \      }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\"\
    \n#include \"../../data_structure/lazy_segtree.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ll n, q;\n    cin >> n >> q;\n    vector<pair<ll,\
    \ ll>> src(n, {0, 1});\n    lazy_segtree<sum_monoid_with_update> lst(src);\n \
    \   while (q--) {\n        ll com;\n        cin >> com;\n        if (com == 0)\
    \ {\n            ll s, t, x;\n            cin >> s >> t >> x;\n            lst.apply(s,\
    \ t + 1, x);\n        } else if (com == 1) {\n            ll s, t;\n         \
    \   cin >> s >> t;\n            cout << lst.prod(s, t + 1).first << endl;\n  \
    \      }\n    }\n}"
  dependsOn:
  - data_structure/lazy_segtree.hpp
  - template.hpp
  isVerificationFile: true
  path: test/onlinejudge.u-aizu.ac.jp/RSQ_and_RUQ.0.test.cpp
  requiredBy: []
  timestamp: '2022-10-19 16:09:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/onlinejudge.u-aizu.ac.jp/RSQ_and_RUQ.0.test.cpp
layout: document
redirect_from:
- /verify/test/onlinejudge.u-aizu.ac.jp/RSQ_and_RUQ.0.test.cpp
- /verify/test/onlinejudge.u-aizu.ac.jp/RSQ_and_RUQ.0.test.cpp.html
title: test/onlinejudge.u-aizu.ac.jp/RSQ_and_RUQ.0.test.cpp
---
