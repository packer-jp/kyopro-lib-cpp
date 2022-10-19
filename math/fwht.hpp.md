---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/xor_convolution.hpp
    title: "xor \u7573\u307F\u8FBC\u307F"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Bitwise_Xor_Convolution.0.test.cpp
    title: test/judge.yosupo.jp/Bitwise_Xor_Convolution.0.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/fwht.hpp\"\n\n#line 2 \"template.hpp\"\n\n#include\
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
    \        cerr << fixed << setprecision(PREC);\n    };\n} iOS;\n#line 4 \"math/fwht.hpp\"\
    \n\ntemplate <typename V> void fwht(vector<V> &a) {\n    ll n = a.size();\n  \
    \  for (ll i = 1; i < n; i <<= 1) {\n        for (ll j = 0; j < n; j += i << 1)\
    \ {\n            for (ll k : rep(i)) {\n                V p = a[0 + j + k], q\
    \ = a[i + j + k];\n                a[0 + j + k] = p + q;\n                a[i\
    \ + j + k] = p - q;\n            }\n        }\n    }\n}\n\ntemplate <typename\
    \ V> void ifwht(vector<V> &a) {\n    fwht(a);\n    V ninv = V(1) / a.size();\n\
    \    for (V &ai : a) ai *= ninv;\n}\n"
  code: "#pragma once\n\n#include \"../template.hpp\"\n\ntemplate <typename V> void\
    \ fwht(vector<V> &a) {\n    ll n = a.size();\n    for (ll i = 1; i < n; i <<=\
    \ 1) {\n        for (ll j = 0; j < n; j += i << 1) {\n            for (ll k :\
    \ rep(i)) {\n                V p = a[0 + j + k], q = a[i + j + k];\n         \
    \       a[0 + j + k] = p + q;\n                a[i + j + k] = p - q;\n       \
    \     }\n        }\n    }\n}\n\ntemplate <typename V> void ifwht(vector<V> &a)\
    \ {\n    fwht(a);\n    V ninv = V(1) / a.size();\n    for (V &ai : a) ai *= ninv;\n\
    }"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/fwht.hpp
  requiredBy:
  - math/xor_convolution.hpp
  timestamp: '2022-10-20 00:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/judge.yosupo.jp/Bitwise_Xor_Convolution.0.test.cpp
documentation_of: math/fwht.hpp
layout: document
title: "\u9AD8\u901F Walsh-Hadamard \u5909\u63DB"
---

## 概要
- 高速 Walsh-Hadamard 変換を行う。

- [cympfh さんの記事](https://cympfh.cc/aiura/hadamard-xor-convolution)