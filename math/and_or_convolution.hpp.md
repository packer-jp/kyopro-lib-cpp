---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/fzt_fmt.hpp
    title: "\u9AD8\u901F Zeta / Moebius \u5909\u63DB"
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/judge.u-aizu.ac.jp/Enumeration.0.test.cpp
    title: test/judge.u-aizu.ac.jp/Enumeration.0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Bitwise_And_Convolution.0.test.cpp
    title: test/judge.yosupo.jp/Bitwise_And_Convolution.0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Bitwise_And_Convolution.1.test.cpp
    title: test/judge.yosupo.jp/Bitwise_And_Convolution.1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/and_or_convolution.hpp\"\n\n#line 2 \"template.hpp\"\
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
    \        cerr << fixed << setprecision(PREC);\n    };\n} iOS;\n#line 2 \"math/fzt_fmt.hpp\"\
    \n\n#line 4 \"math/fzt_fmt.hpp\"\n\ntemplate <typename V> void fzt_super(vector<V>\
    \ &a) {\n    for (ll i : rep(flg(a.size()))) {\n        for (ll s : rep(a.size()))\
    \ {\n            if ((s >> i) & 1) a[s ^ pw(i)] += a[s];\n        }\n    }\n}\n\
    \ntemplate <typename V> void fzt_sub(vector<V> &a) {\n    for (ll i : rep(flg(a.size())))\
    \ {\n        for (ll s : rep(a.size())) {\n            if (!((s >> i) & 1)) a[s\
    \ ^ pw(i)] += a[s];\n        }\n    }\n}\n\ntemplate <typename V> void fmt_super(vector<V>\
    \ &a) {\n    for (ll i : rep(flg(a.size()))) {\n        for (ll s : rep(a.size()))\
    \ {\n            if ((s >> i) & 1) a[s ^ pw(i)] -= a[s];\n        }\n    }\n}\n\
    \ntemplate <typename V> void fmt_sub(vector<V> &a) {\n    for (ll i : rep(flg(a.size())))\
    \ {\n        for (ll s : rep(a.size())) {\n            if (!((s >> i) & 1)) a[s\
    \ ^ pw(i)] -= a[s];\n        }\n    }\n}\n#line 5 \"math/and_or_convolution.hpp\"\
    \n\ntemplate <typename V> vector<V> and_convolution(vector<V> a, vector<V> b)\
    \ {\n    ll _n = max(a.size(), b.size()), n;\n    for (n = 1; n < _n; n <<= 1)\
    \ {}\n    a.resize(n), b.resize(n);\n    fzt_super(a), fzt_super(b);\n    for\
    \ (ll i : rep(n)) a[i] *= b[i];\n    fmt_super(a);\n    return a;\n}\n\ntemplate\
    \ <typename V> vector<V> or_convolution(vector<V> a, vector<V> b) {\n    ll _n\
    \ = max(a.size(), b.size()), n;\n    for (n = 1; n < _n; n <<= 1) {}\n    a.resize(n),\
    \ b.resize(n);\n    fzt_sub(a), fzt_sub(b);\n    for (ll i : rep(n)) a[i] *= b[i];\n\
    \    fmt_sub(a);\n    return a;\n}\n"
  code: "#pragma once\n\n#include \"../template.hpp\"\n#include \"fzt_fmt.hpp\"\n\n\
    template <typename V> vector<V> and_convolution(vector<V> a, vector<V> b) {\n\
    \    ll _n = max(a.size(), b.size()), n;\n    for (n = 1; n < _n; n <<= 1) {}\n\
    \    a.resize(n), b.resize(n);\n    fzt_super(a), fzt_super(b);\n    for (ll i\
    \ : rep(n)) a[i] *= b[i];\n    fmt_super(a);\n    return a;\n}\n\ntemplate <typename\
    \ V> vector<V> or_convolution(vector<V> a, vector<V> b) {\n    ll _n = max(a.size(),\
    \ b.size()), n;\n    for (n = 1; n < _n; n <<= 1) {}\n    a.resize(n), b.resize(n);\n\
    \    fzt_sub(a), fzt_sub(b);\n    for (ll i : rep(n)) a[i] *= b[i];\n    fmt_sub(a);\n\
    \    return a;\n}"
  dependsOn:
  - template.hpp
  - math/fzt_fmt.hpp
  isVerificationFile: false
  path: math/and_or_convolution.hpp
  requiredBy: []
  timestamp: '2022-10-19 16:09:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/judge.yosupo.jp/Bitwise_And_Convolution.1.test.cpp
  - test/judge.yosupo.jp/Bitwise_And_Convolution.0.test.cpp
  - test/judge.u-aizu.ac.jp/Enumeration.0.test.cpp
documentation_of: math/and_or_convolution.hpp
layout: document
title: "and / or \u7573\u307F\u8FBC\u307F"
---

## 概要
- 高速ゼータ / メビウス変換を利用して and / orの 畳み込みを行う。

## 詳細
