---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/kruskal.hpp\"\n\n#line 2 \"template.hpp\"\n\n#include\
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
    \        cerr << fixed << setprecision(PREC);\n    };\n} iOS;\n#line 4 \"graph/kruskal.hpp\"\
    \n\ntemplate <typename D> pair<D, vll> kruskal(ll n, const vector<tuple<ll, ll,\
    \ D>> &g) {\n    unionfind uf(n);\n    vll p(g.size());\n    iota(all(p), 0ll);\n\
    \    sort(all(p), [&](ll l, ll r) -> bool { return get<2>(g[l]) < get<2>(g[r]);\
    \ });\n    D sum = 0;\n    vll used;\n    for (ll i : rep(g.size())) {\n     \
    \   auto [u, v, d] = g[p[i]];\n        if (!uf.same(u, v)) {\n            uf.unite(u,\
    \ v);\n            sum += d;\n            used.push_back(p[i]);\n        }\n \
    \   }\n    return {sum, used};\n}\n"
  code: "#pragma once\n\n#include \"../template.hpp\"\n\ntemplate <typename D> pair<D,\
    \ vll> kruskal(ll n, const vector<tuple<ll, ll, D>> &g) {\n    unionfind uf(n);\n\
    \    vll p(g.size());\n    iota(all(p), 0ll);\n    sort(all(p), [&](ll l, ll r)\
    \ -> bool { return get<2>(g[l]) < get<2>(g[r]); });\n    D sum = 0;\n    vll used;\n\
    \    for (ll i : rep(g.size())) {\n        auto [u, v, d] = g[p[i]];\n       \
    \ if (!uf.same(u, v)) {\n            uf.unite(u, v);\n            sum += d;\n\
    \            used.push_back(p[i]);\n        }\n    }\n    return {sum, used};\n\
    }"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/kruskal.hpp
  requiredBy: []
  timestamp: '2022-10-19 16:09:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/kruskal.hpp
layout: document
redirect_from:
- /library/graph/kruskal.hpp
- /library/graph/kruskal.hpp.html
title: graph/kruskal.hpp
---
