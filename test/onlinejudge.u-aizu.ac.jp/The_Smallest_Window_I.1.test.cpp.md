---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/segtree.hpp
    title: Segment Tree
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_A
  bundledCode: "#line 1 \"test/onlinejudge.u-aizu.ac.jp/The_Smallest_Window_I.1.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_A\"\
    \n#line 2 \"data_structure/segtree.hpp\"\n\n#line 2 \"template.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define all(a) begin(a), end(a)\n#define\
    \ rall(a) rbegin(a), rend(a)\n#define uniq(a) (a).erase(unique(all(a)), (a).end())\n\
    #define t0 first\n#define t1 second\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing pll = pair<ll, ll>;\nusing vll = vector<ll>;\nconstexpr double\
    \ pi = 3.14159265358979323846;\nconstexpr ll dy[9] = {0, 1, 0, -1, 1, 1, -1, -1,\
    \ 0};\nconstexpr ll dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};\nconstexpr ll sign(ll\
    \ a) { return (a > 0) - (a < 0); }\nconstexpr ll fdiv(ll a, ll b) { return a /\
    \ b - ((a ^ b) < 0 && a % b); }\nconstexpr ll cdiv(ll a, ll b) { return -fdiv(-a,\
    \ b); }\nconstexpr ll pw(ll n) { return 1ll << n; }\nconstexpr ll flg(ll n) {\
    \ return 63 - __builtin_clzll(n); }\nconstexpr ll clg(ll n) { return flg(n - 1)\
    \ + 1; }\nconstexpr ll safemod(ll x, ll mod) { return (x % mod + mod) % mod; }\n\
    template <typename T> using priority_queue_rev = priority_queue<T, vector<T>,\
    \ greater<T>>;\ntemplate <typename T> constexpr T sq(const T &a) { return a *\
    \ a; }\ntemplate <typename T, typename U> constexpr bool chmax(T &a, const U &b)\
    \ { return a < b ? a = b, true : false; }\ntemplate <typename T, typename U> constexpr\
    \ bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }\ntemplate\
    \ <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &a)\
    \ {\n    os << \"(\" << a.first << \", \" << a.second << \")\";\n    return os;\n\
    }\ntemplate <typename T, typename U, typename V> ostream &operator<<(ostream &os,\
    \ const tuple<T, U, V> &a) {\n    os << \"(\" << get<0>(a) << \", \" << get<1>(a)\
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
    \ {}\n    segtree(const vector<V> &src) : n(src.size()) {\n        for (size =\
    \ 1; size < n; size <<= 1) {}\n        val.resize(size << 1);\n        copy(all(src),\
    \ val.begin() + size);\n        for (ll i : per(1, size)) val[i] = P::op(val[i\
    \ << 1 | 0], val[i << 1 | 1]);\n    }\n    void set(ll i, const V &a) {\n    \
    \    val[i += size] = a;\n        while (i >>= 1) val[i] = P::op(val[i << 1 |\
    \ 0], val[i << 1 | 1]);\n    }\n    V get(ll i) const { return val[i + size];\
    \ }\n    V prod(ll l, ll r) const {\n        V a = P::e(), b = P::e();\n     \
    \   for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n            if (l &\
    \ 1) a = P::op(a, val[l++]);\n            if (r & 1) b = P::op(val[--r], b);\n\
    \        }\n        return P::op(a, b);\n    }\n    template <typename F> ll max_right(ll\
    \ l, F f) const {\n        if (l == n) return n;\n        V a = P::e();\n    \
    \    l += size;\n        do {\n            while (~l & 1) l >>= 1;\n         \
    \   if (!f(P::op(a, val[l]))) {\n                while (l < size) {\n        \
    \            l = l << 1;\n                    if (f(P::op(a, val[l]))) a = P::op(a,\
    \ val[l++]);\n                }\n                return l - size;\n          \
    \  }\n            a = P::op(a, val[l++]);\n        } while ((l & -l) != l);\n\
    \        return n;\n    }\n    template <typename F> ll min_left(ll r, F f) const\
    \ {\n        if (r == 0) return 0;\n        V a = P::e();\n        r += size;\n\
    \        do {\n            r--;\n            while (r > 1 && r & 1) r >>= 1;\n\
    \            if (!f(P::op(val[r], a))) {\n                while (r < size) {\n\
    \                    r = r << 1 | 1;\n                    if (f(P::op(val[r],\
    \ a))) a = P::op(val[r--], a);\n                }\n                return r +\
    \ 1 - size;\n            }\n            a = P::op(val[r], a);\n        } while\
    \ ((r & -r) != r);\n        return 0;\n    }\n};\n\nstruct min_monoid {\n    using\
    \ V = ll;\n    static V op(V a, V b) { return min(a, b); }\n    static V e() {\
    \ return LLONG_MAX; }\n};\n\nstruct sum_monoid {\n    using V = ll;\n    static\
    \ V op(V a, V b) { return a + b; }\n    static V e() { return 0; }\n};\n#line\
    \ 3 \"test/onlinejudge.u-aizu.ac.jp/The_Smallest_Window_I.1.test.cpp\"\n\n#line\
    \ 5 \"test/onlinejudge.u-aizu.ac.jp/The_Smallest_Window_I.1.test.cpp\"\nusing\
    \ namespace std;\n\nint main() {\n    ll n, s;\n    cin >> n >> s;\n    vector<ll>\
    \ a(n);\n    for (ll i : rep(n)) cin >> a[i];\n    segtree<sum_monoid> st(a);\n\
    \    ll ans = LLONG_MAX;\n    for (int r = 1; r <= n; r++) {\n        ll l = st.min_left(r,\
    \ [&](ll x) { return x < s; });\n        if (l > 0) chmin(ans, r - l + 1);\n \
    \   }\n    if (ans == LLONG_MAX) {\n        cout << 0 << endl;\n    } else {\n\
    \        cout << ans << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_A\"\
    \n#include \"../../data_structure/segtree.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ll n, s;\n    cin >> n >> s;\n    vector<ll>\
    \ a(n);\n    for (ll i : rep(n)) cin >> a[i];\n    segtree<sum_monoid> st(a);\n\
    \    ll ans = LLONG_MAX;\n    for (int r = 1; r <= n; r++) {\n        ll l = st.min_left(r,\
    \ [&](ll x) { return x < s; });\n        if (l > 0) chmin(ans, r - l + 1);\n \
    \   }\n    if (ans == LLONG_MAX) {\n        cout << 0 << endl;\n    } else {\n\
    \        cout << ans << endl;\n    }\n}"
  dependsOn:
  - data_structure/segtree.hpp
  - template.hpp
  isVerificationFile: true
  path: test/onlinejudge.u-aizu.ac.jp/The_Smallest_Window_I.1.test.cpp
  requiredBy: []
  timestamp: '2022-10-19 16:09:32+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/onlinejudge.u-aizu.ac.jp/The_Smallest_Window_I.1.test.cpp
layout: document
redirect_from:
- /verify/test/onlinejudge.u-aizu.ac.jp/The_Smallest_Window_I.1.test.cpp
- /verify/test/onlinejudge.u-aizu.ac.jp/The_Smallest_Window_I.1.test.cpp.html
title: test/onlinejudge.u-aizu.ac.jp/The_Smallest_Window_I.1.test.cpp
---
