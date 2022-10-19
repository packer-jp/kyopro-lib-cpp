---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/unionfind.hpp
    title: data_structure/unionfind.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/judge.yosupo.jp/Unionfind.0.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n#line 2 \"data_structure/unionfind.hpp\"\
    \n\n#line 2 \"template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#define all(a) begin(a), end(a)\n#define rall(a) rbegin(a), rend(a)\n#define\
    \ uniq(a) (a).erase(unique(all(a)), (a).end())\n#define t0 first\n#define t1 second\n\
    using ll = long long;\nusing ull = unsigned long long;\nusing pll = pair<ll, ll>;\n\
    using vll = vector<ll>;\nconstexpr double pi = 3.14159265358979323846;\nconstexpr\
    \ ll dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};\nconstexpr ll dx[9] = {1, 0, -1,\
    \ 0, 1, -1, -1, 1, 0};\nconstexpr ll sign(ll a) { return (a > 0) - (a < 0); }\n\
    constexpr ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }\nconstexpr\
    \ ll cdiv(ll a, ll b) { return -fdiv(-a, b); }\nconstexpr ll pw(ll n) { return\
    \ 1ll << n; }\nconstexpr ll flg(ll n) { return 63 - __builtin_clzll(n); }\nconstexpr\
    \ ll clg(ll n) { return flg(n - 1) + 1; }\nconstexpr ll safemod(ll x, ll mod)\
    \ { return (x % mod + mod) % mod; }\ntemplate <typename T> using priority_queue_rev\
    \ = priority_queue<T, vector<T>, greater<T>>;\ntemplate <typename T> constexpr\
    \ T sq(const T &a) { return a * a; }\ntemplate <typename T, typename U> constexpr\
    \ bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }\ntemplate\
    \ <typename T, typename U> constexpr bool chmin(T &a, const U &b) { return a >\
    \ b ? a = b, true : false; }\ntemplate <typename T, typename U> ostream &operator<<(ostream\
    \ &os, const pair<T, U> &a) {\n    os << \"(\" << a.first << \", \" << a.second\
    \ << \")\";\n    return os;\n}\ntemplate <typename T, typename U, typename V>\
    \ ostream &operator<<(ostream &os, const tuple<T, U, V> &a) {\n    os << \"(\"\
    \ << get<0>(a) << \", \" << get<1>(a) << \", \" << get<2>(a) << \")\";\n    return\
    \ os;\n}\ntemplate <typename T> ostream &operator<<(ostream &os, const vector<T>\
    \ &a) {\n    os << \"(\";\n    for (auto itr = a.begin(); itr != a.end(); ++itr)\
    \ os << *itr << (next(itr) != a.end() ? \", \" : \"\");\n    os << \")\";\n  \
    \  return os;\n}\ntemplate <typename T> ostream &operator<<(ostream &os, const\
    \ set<T> &a) {\n    os << \"(\";\n    for (auto itr = a.begin(); itr != a.end();\
    \ ++itr) os << *itr << (next(itr) != a.end() ? \", \" : \"\");\n    os << \")\"\
    ;\n    return os;\n}\ntemplate <typename T> ostream &operator<<(ostream &os, const\
    \ multiset<T> &a) {\n    os << \"(\";\n    for (auto itr = a.begin(); itr != a.end();\
    \ ++itr) os << *itr << (next(itr) != a.end() ? \", \" : \"\");\n    os << \")\"\
    ;\n    return os;\n}\ntemplate <typename T, typename U> ostream &operator<<(ostream\
    \ &os, const map<T, U> &a) {\n    os << \"(\";\n    for (auto itr = a.begin();\
    \ itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? \", \" : \"\");\n\
    \    os << \")\";\n    return os;\n}\n#ifdef ONLINE_JUDGE\n#define dump(...) (void(0))\n\
    #else\nvoid debug() { cerr << endl; }\ntemplate <typename Head, typename... Tail>\
    \ void debug(Head &&head, Tail &&... tail) {\n    cerr << head;\n    if (sizeof...(Tail))\
    \ cerr << \", \";\n    debug(tail...);\n}\n#define dump(...) cerr << __LINE__\
    \ << \": \" << #__VA_ARGS__ << \" = \", debug(__VA_ARGS__)\n#endif\nstruct rep\
    \ {\n    struct itr {\n        ll v;\n        itr(ll v) : v(v) {}\n        void\
    \ operator++() { ++v; }\n        ll operator*() const { return v; }\n        bool\
    \ operator!=(itr i) const { return v < *i; }\n    };\n    ll l, r;\n    rep(ll\
    \ l, ll r) : l(l), r(r) {}\n    rep(ll r) : rep(0, r) {}\n    itr begin() const\
    \ { return l; };\n    itr end() const { return r; };\n};\nstruct per {\n    struct\
    \ itr {\n        ll v;\n        itr(ll v) : v(v) {}\n        void operator++()\
    \ { --v; }\n        ll operator*() const { return v; }\n        bool operator!=(itr\
    \ i) const { return v > *i; }\n    };\n    ll l, r;\n    per(ll l, ll r) : l(l),\
    \ r(r) {}\n    per(ll r) : per(0, r) {}\n    itr begin() const { return r - 1;\
    \ };\n    itr end() const { return l - 1; };\n};\nstruct io_setup {\n    static\
    \ constexpr int PREC = 20;\n    io_setup() {\n        cout << fixed << setprecision(PREC);\n\
    \        cerr << fixed << setprecision(PREC);\n    };\n} iOS;\n#line 4 \"data_structure/unionfind.hpp\"\
    \n\nstruct unionfind {\n    ll n;\n    vector<ll> ps;\n    unionfind(ll n) : n(n),\
    \ ps(n, -1) {}\n    ll find(ll i) {\n        if (ps[i] < 0) return i;\n      \
    \  return ps[i] = find(ps[i]);\n    }\n    ll size(ll i) { return -ps[find(i)];\
    \ }\n    void unite(ll i, ll j) {\n        if ((i = find(i)) == (j = find(j)))\
    \ return;\n        if (-ps[i] < -ps[j]) swap(i, j);\n        ps[i] += ps[j];\n\
    \        ps[j] = i;\n    }\n    bool same(ll i, ll j) { return find(i) == find(j);\
    \ }\n    vector<vector<ll>> groups() {\n        vector<vector<ll>> ret(n);\n \
    \       for (ll i : rep(n)) ret[find(i)].push_back(i);\n        ret.erase(remove_if(all(ret),\
    \ [](const vector<ll> &v) { return v.empty(); }), ret.end());\n        return\
    \ ret;\n    }\n};\n#line 3 \"test/judge.yosupo.jp/Unionfind.0.test.cpp\"\n\nint\
    \ main() {\n    ll n, q;\n    cin >> n >> q;\n    unionfind uf(n);\n    while\
    \ (q--) {\n        ll t, u, v;\n        cin >> t >> u >> v;\n        if (t ==\
    \ 0) uf.unite(u, v);\n        if (t == 1) cout << uf.same(u, v) << endl;\n   \
    \ }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    ../../data_structure/unionfind.hpp\"\n\nint main() {\n    ll n, q;\n    cin >>\
    \ n >> q;\n    unionfind uf(n);\n    while (q--) {\n        ll t, u, v;\n    \
    \    cin >> t >> u >> v;\n        if (t == 0) uf.unite(u, v);\n        if (t ==\
    \ 1) cout << uf.same(u, v) << endl;\n    }\n}"
  dependsOn:
  - data_structure/unionfind.hpp
  - template.hpp
  isVerificationFile: true
  path: test/judge.yosupo.jp/Unionfind.0.test.cpp
  requiredBy: []
  timestamp: '2022-10-19 16:09:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/judge.yosupo.jp/Unionfind.0.test.cpp
layout: document
redirect_from:
- /verify/test/judge.yosupo.jp/Unionfind.0.test.cpp
- /verify/test/judge.yosupo.jp/Unionfind.0.test.cpp.html
title: test/judge.yosupo.jp/Unionfind.0.test.cpp
---
