---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/bostan_mori.hpp
    title: math/bostan_mori.hpp
  - icon: ':heavy_check_mark:'
    path: math/fps.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':heavy_check_mark:'
    path: math/kth_of_lrs.hpp
    title: math/kth_of_lrs.hpp
  - icon: ':heavy_check_mark:'
    path: math/subset_convolution.hpp
    title: Subset Convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Bitwise_And_Convolution.0.test.cpp
    title: test/judge.yosupo.jp/Bitwise_And_Convolution.0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Bitwise_And_Convolution.1.test.cpp
    title: test/judge.yosupo.jp/Bitwise_And_Convolution.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Bitwise_Xor_Convolution.0.test.cpp
    title: test/judge.yosupo.jp/Bitwise_Xor_Convolution.0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Convolution.0.test.cpp
    title: test/judge.yosupo.jp/Convolution.0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Determinant_of_Matrix.0.test.cpp
    title: test/judge.yosupo.jp/Determinant_of_Matrix.0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Exp_of_Formal_Power_Series.0.test.cpp
    title: test/judge.yosupo.jp/Exp_of_Formal_Power_Series.0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Inv_of_Formal_Power_Series.0.test.cpp
    title: test/judge.yosupo.jp/Inv_of_Formal_Power_Series.0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Kth_Term_of_Linearly_Recurrent_Sequence.0.test.cpp
    title: test/judge.yosupo.jp/Kth_Term_of_Linearly_Recurrent_Sequence.0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Log_of_Formal_Power_Series.0.test.cpp
    title: test/judge.yosupo.jp/Log_of_Formal_Power_Series.0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Pow_of_Formal_Power_Series.0.test.cpp
    title: test/judge.yosupo.jp/Pow_of_Formal_Power_Series.0.test.cpp
  - icon: ':x:'
    path: test/judge.yosupo.jp/Range_Affine_Range_Sum.0.test.cpp
    title: test/judge.yosupo.jp/Range_Affine_Range_Sum.0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Subset_Convolution.0.test.cpp
    title: test/judge.yosupo.jp/Subset_Convolution.0.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/modint.hpp\"\n\n#line 2 \"template.hpp\"\n\n#include\
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
    \        cerr << fixed << setprecision(PREC);\n    };\n} iOS;\n#line 4 \"math/modint.hpp\"\
    \n\ntemplate <typename M> struct modint {\n    ll val;\n    modint(ll val = 0)\
    \ : val(val >= 0 ? val % M::mod : (M::mod - (-val) % M::mod) % M::mod) {}\n  \
    \  static ll mod() { return M::mod; }\n    modint inv() const {\n        ll a\
    \ = val, b = M::mod, u = 1, v = 0, t;\n        while (b > 0) {\n            t\
    \ = a / b;\n            swap(a -= t * b, b);\n            swap(u -= t * v, v);\n\
    \        }\n        return u;\n    }\n    modint pow(ll k) const {\n        modint\
    \ ret = 1, mul = val;\n        while (k) {\n            if (k & 1) ret *= mul;\n\
    \            mul *= mul;\n            k >>= 1;\n        }\n        return ret;\n\
    \    }\n    modint &operator+=(const modint &a) {\n        if ((val += a.val)\
    \ >= M::mod) val -= M::mod;\n        return *this;\n    }\n    modint &operator-=(const\
    \ modint &a) {\n        if ((val += M::mod - a.val) >= M::mod) val -= M::mod;\n\
    \        return *this;\n    }\n    modint &operator*=(const modint &a) {\n   \
    \     (val *= a.val) %= M::mod;\n        return *this;\n    }\n    modint &operator/=(const\
    \ modint &a) { return *this *= a.inv(); }\n    modint operator+() const { return\
    \ *this; }\n    modint operator-() const { return modint(-val); }\n    friend\
    \ bool operator==(const modint &a, const modint &b) { return a.val == b.val; }\n\
    \    friend bool operator!=(const modint &a, const modint &b) { return rel_ops::operator!=(a,\
    \ b); }\n    friend modint operator+(const modint &a, const modint &b) { return\
    \ modint(a) += b; }\n    friend modint operator-(const modint &a, const modint\
    \ &b) { return modint(a) -= b; }\n    friend modint operator*(const modint &a,\
    \ const modint &b) { return modint(a) *= b; }\n    friend modint operator/(const\
    \ modint &a, const modint &b) { return modint(a) /= b; }\n    friend istream &operator>>(istream\
    \ &is, modint &a) {\n        ll val;\n        is >> val;\n        a = modint(val);\n\
    \        return is;\n    }\n    friend ostream &operator<<(ostream &os, const\
    \ modint &a) { return os << a.val; }\n};\n\nstruct _998244353 {\n    constexpr\
    \ static ll mod = 998244353;\n};\nstruct _1000000007 {\n    constexpr static ll\
    \ mod = 1000000007;\n};\nusing modint998244353 = modint<_998244353>;\nusing modint1000000007\
    \ = modint<_1000000007>;\n\nstruct arbitrary {\n    static ll mod;\n};\nll arbitrary::mod;\n"
  code: "#pragma once\n\n#include \"../template.hpp\"\n\ntemplate <typename M> struct\
    \ modint {\n    ll val;\n    modint(ll val = 0) : val(val >= 0 ? val % M::mod\
    \ : (M::mod - (-val) % M::mod) % M::mod) {}\n    static ll mod() { return M::mod;\
    \ }\n    modint inv() const {\n        ll a = val, b = M::mod, u = 1, v = 0, t;\n\
    \        while (b > 0) {\n            t = a / b;\n            swap(a -= t * b,\
    \ b);\n            swap(u -= t * v, v);\n        }\n        return u;\n    }\n\
    \    modint pow(ll k) const {\n        modint ret = 1, mul = val;\n        while\
    \ (k) {\n            if (k & 1) ret *= mul;\n            mul *= mul;\n       \
    \     k >>= 1;\n        }\n        return ret;\n    }\n    modint &operator+=(const\
    \ modint &a) {\n        if ((val += a.val) >= M::mod) val -= M::mod;\n       \
    \ return *this;\n    }\n    modint &operator-=(const modint &a) {\n        if\
    \ ((val += M::mod - a.val) >= M::mod) val -= M::mod;\n        return *this;\n\
    \    }\n    modint &operator*=(const modint &a) {\n        (val *= a.val) %= M::mod;\n\
    \        return *this;\n    }\n    modint &operator/=(const modint &a) { return\
    \ *this *= a.inv(); }\n    modint operator+() const { return *this; }\n    modint\
    \ operator-() const { return modint(-val); }\n    friend bool operator==(const\
    \ modint &a, const modint &b) { return a.val == b.val; }\n    friend bool operator!=(const\
    \ modint &a, const modint &b) { return rel_ops::operator!=(a, b); }\n    friend\
    \ modint operator+(const modint &a, const modint &b) { return modint(a) += b;\
    \ }\n    friend modint operator-(const modint &a, const modint &b) { return modint(a)\
    \ -= b; }\n    friend modint operator*(const modint &a, const modint &b) { return\
    \ modint(a) *= b; }\n    friend modint operator/(const modint &a, const modint\
    \ &b) { return modint(a) /= b; }\n    friend istream &operator>>(istream &is,\
    \ modint &a) {\n        ll val;\n        is >> val;\n        a = modint(val);\n\
    \        return is;\n    }\n    friend ostream &operator<<(ostream &os, const\
    \ modint &a) { return os << a.val; }\n};\n\nstruct _998244353 {\n    constexpr\
    \ static ll mod = 998244353;\n};\nstruct _1000000007 {\n    constexpr static ll\
    \ mod = 1000000007;\n};\nusing modint998244353 = modint<_998244353>;\nusing modint1000000007\
    \ = modint<_1000000007>;\n\nstruct arbitrary {\n    static ll mod;\n};\nll arbitrary::mod;"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy:
  - math/kth_of_lrs.hpp
  - math/subset_convolution.hpp
  - math/bostan_mori.hpp
  - math/fps.hpp
  timestamp: '2022-10-19 16:09:32+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/judge.yosupo.jp/Determinant_of_Matrix.0.test.cpp
  - test/judge.yosupo.jp/Range_Affine_Range_Sum.0.test.cpp
  - test/judge.yosupo.jp/Log_of_Formal_Power_Series.0.test.cpp
  - test/judge.yosupo.jp/Inv_of_Formal_Power_Series.0.test.cpp
  - test/judge.yosupo.jp/Exp_of_Formal_Power_Series.0.test.cpp
  - test/judge.yosupo.jp/Bitwise_Xor_Convolution.0.test.cpp
  - test/judge.yosupo.jp/Convolution.0.test.cpp
  - test/judge.yosupo.jp/Subset_Convolution.0.test.cpp
  - test/judge.yosupo.jp/Kth_Term_of_Linearly_Recurrent_Sequence.0.test.cpp
  - test/judge.yosupo.jp/Bitwise_And_Convolution.1.test.cpp
  - test/judge.yosupo.jp/Pow_of_Formal_Power_Series.0.test.cpp
  - test/judge.yosupo.jp/Bitwise_And_Convolution.0.test.cpp
documentation_of: math/modint.hpp
layout: document
title: modint
---

## 概要
- $\bmod\,m$ で考えた整数について、各種演算をサポートする。

## 詳細
- `<ll MOD> struct modint`  
    modint 本体。

    - `ll MOD`  
        テンプレート引数として与える法 $m$。

    - `ll val`  
        $\bmod\,m$ で考えたときの値。

    - `static ll mod()`  
        $m$ を返す。

    - `modint inv()`  
        逆元を返す。 $m$ と互いに素である場合に逆元が存在する。 $O(\log m)$ 時間。

    - `modint pow(ll k)`  
        $k$ 乗した結果を返す。 $O(\log k)$ 時間。

    - 四則演算、比較、複合代入

    - `iostream` を用いた入出力


## 参考
- [うしさんのライブラリ](https://ei1333.github.io/library/math/combinatorics/mod-int.cpp)