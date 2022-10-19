---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/offline_dag_reachability.hpp
    title: graph/offline_dag_reachability.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"util/dynamic_bitset.hpp\"\n\n#line 2 \"template.hpp\"\n\n\
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
    \        cerr << fixed << setprecision(PREC);\n    };\n} iOS;\n#line 4 \"util/dynamic_bitset.hpp\"\
    \n\nstruct dynamic_bitset {\n    using db = dynamic_bitset;\n    vector<ull> val;\n\
    \    struct ref {\n        ull &p;\n        ll i;\n        ref(ull &p, ll i) :\
    \ p(p), i(i) {}\n        ref &operator=(bool a) {\n            if (a) {\n    \
    \            p |= pw(i);\n            } else\n                p &= ~pw(i);\n \
    \           return *this;\n        }\n        ref &operator=(const ref &a) { return\
    \ *this = a; }\n        operator bool() const { return (p & pw(i)) != 0; }\n \
    \       bool operator~() const { return !*this; }\n        ref &flip() {\n   \
    \         p ^= pw(i);\n            return *this;\n        }\n    };\n    ref operator[](ll\
    \ i) {\n        if (val.size() <= i >> 4) val.resize((i >> 4) + 1);\n        return\
    \ {val[i >> 4], i & 63};\n    }\n    db &operator&=(const db &a) {\n        if\
    \ (a.val.size() < val.size()) val.resize(a.val.size());\n        for (ll i : rep(a.val.size()))\
    \ val[i] &= a.val[i];\n        return *this;\n    }\n    db &operator|=(const\
    \ db &a) {\n        if (a.val.size() > val.size()) val.resize(a.val.size());\n\
    \        for (ll i : rep(a.val.size())) val[i] |= a.val[i];\n        return *this;\n\
    \    }\n    db &operator^=(const db &a) {\n        if (a.val.size() > val.size())\
    \ val.resize(a.val.size());\n        for (ll i : rep(a.val.size())) val[i] ^=\
    \ a.val[i];\n        return *this;\n    }\n    ll count() const {\n        ll\
    \ ret = 0;\n        for (ull p : val) ret += __builtin_popcountll(p);\n      \
    \  return ret;\n    }\n    friend bool operator==(const db &a, const db &b) {\
    \ return (a ^ b).count() == 0; }\n    friend bool operator!=(const db &a, const\
    \ db &b) { return rel_ops::operator!=(a, b); }\n    friend bool operator<(const\
    \ db &a, const db &b) {\n        for (ll i : per(max(a.val.size(), b.val.size())))\
    \ {\n            ull pa = i < a.val.size() ? a.val[i] : 0;\n            ull pb\
    \ = i < b.val.size() ? b.val[i] : 0;\n            if (pa < pb) return true;\n\
    \            if (pa > pb) return false;\n        }\n        return false;\n  \
    \  }\n    friend bool operator>(const db &a, const db &b) { return rel_ops::operator>(a,\
    \ b); }\n    friend bool operator<=(const db &a, const db &b) { return rel_ops::operator<=(a,\
    \ b); }\n    friend bool operator>=(const db &a, const db &b) { return rel_ops::operator>=(a,\
    \ b); }\n    friend db operator&(const db &a, const db &b) { return db(a) &= b;\
    \ }\n    friend db operator|(const db &a, const db &b) { return db(a) |= b; }\n\
    \    friend db operator^(const db &a, const db &b) { return db(a) ^= b; }\n};\n"
  code: "#pragma once\n\n#include \"../template.hpp\"\n\nstruct dynamic_bitset {\n\
    \    using db = dynamic_bitset;\n    vector<ull> val;\n    struct ref {\n    \
    \    ull &p;\n        ll i;\n        ref(ull &p, ll i) : p(p), i(i) {}\n     \
    \   ref &operator=(bool a) {\n            if (a) {\n                p |= pw(i);\n\
    \            } else\n                p &= ~pw(i);\n            return *this;\n\
    \        }\n        ref &operator=(const ref &a) { return *this = a; }\n     \
    \   operator bool() const { return (p & pw(i)) != 0; }\n        bool operator~()\
    \ const { return !*this; }\n        ref &flip() {\n            p ^= pw(i);\n \
    \           return *this;\n        }\n    };\n    ref operator[](ll i) {\n   \
    \     if (val.size() <= i >> 4) val.resize((i >> 4) + 1);\n        return {val[i\
    \ >> 4], i & 63};\n    }\n    db &operator&=(const db &a) {\n        if (a.val.size()\
    \ < val.size()) val.resize(a.val.size());\n        for (ll i : rep(a.val.size()))\
    \ val[i] &= a.val[i];\n        return *this;\n    }\n    db &operator|=(const\
    \ db &a) {\n        if (a.val.size() > val.size()) val.resize(a.val.size());\n\
    \        for (ll i : rep(a.val.size())) val[i] |= a.val[i];\n        return *this;\n\
    \    }\n    db &operator^=(const db &a) {\n        if (a.val.size() > val.size())\
    \ val.resize(a.val.size());\n        for (ll i : rep(a.val.size())) val[i] ^=\
    \ a.val[i];\n        return *this;\n    }\n    ll count() const {\n        ll\
    \ ret = 0;\n        for (ull p : val) ret += __builtin_popcountll(p);\n      \
    \  return ret;\n    }\n    friend bool operator==(const db &a, const db &b) {\
    \ return (a ^ b).count() == 0; }\n    friend bool operator!=(const db &a, const\
    \ db &b) { return rel_ops::operator!=(a, b); }\n    friend bool operator<(const\
    \ db &a, const db &b) {\n        for (ll i : per(max(a.val.size(), b.val.size())))\
    \ {\n            ull pa = i < a.val.size() ? a.val[i] : 0;\n            ull pb\
    \ = i < b.val.size() ? b.val[i] : 0;\n            if (pa < pb) return true;\n\
    \            if (pa > pb) return false;\n        }\n        return false;\n  \
    \  }\n    friend bool operator>(const db &a, const db &b) { return rel_ops::operator>(a,\
    \ b); }\n    friend bool operator<=(const db &a, const db &b) { return rel_ops::operator<=(a,\
    \ b); }\n    friend bool operator>=(const db &a, const db &b) { return rel_ops::operator>=(a,\
    \ b); }\n    friend db operator&(const db &a, const db &b) { return db(a) &= b;\
    \ }\n    friend db operator|(const db &a, const db &b) { return db(a) |= b; }\n\
    \    friend db operator^(const db &a, const db &b) { return db(a) ^= b; }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: util/dynamic_bitset.hpp
  requiredBy:
  - graph/offline_dag_reachability.hpp
  timestamp: '2022-10-19 19:47:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/dynamic_bitset.hpp
layout: document
redirect_from:
- /library/util/dynamic_bitset.hpp
- /library/util/dynamic_bitset.hpp.html
title: util/dynamic_bitset.hpp
---
