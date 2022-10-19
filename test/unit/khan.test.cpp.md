---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/khan.hpp
    title: "Khan \u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
  bundledCode: "#line 1 \"test/unit/khan.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#line 2 \"graph/khan.hpp\"\n\n#line 2 \"template.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define all(a) begin(a), end(a)\n#define rall(a) rbegin(a),\
    \ rend(a)\n#define uniq(a) (a).erase(unique(all(a)), (a).end())\n#define t0 first\n\
    #define t1 second\nusing ll = long long;\nusing ull = unsigned long long;\nusing\
    \ pll = pair<ll, ll>;\nusing vll = vector<ll>;\nconstexpr double pi = 3.14159265358979323846;\n\
    constexpr ll dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};\nconstexpr ll dx[9] = {1,\
    \ 0, -1, 0, 1, -1, -1, 1, 0};\nconstexpr ll sign(ll a) { return (a > 0) - (a <\
    \ 0); }\nconstexpr ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b);\
    \ }\nconstexpr ll cdiv(ll a, ll b) { return -fdiv(-a, b); }\nconstexpr ll pw(ll\
    \ n) { return 1ll << n; }\nconstexpr ll flg(ll n) { return 63 - __builtin_clzll(n);\
    \ }\nconstexpr ll clg(ll n) { return n == 1 ? 0 : flg(n - 1) + 1; }\nconstexpr\
    \ ll safemod(ll x, ll mod) { return (x % mod + mod) % mod; }\ntemplate <typename\
    \ T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;\ntemplate\
    \ <typename T> constexpr T sq(const T &a) { return a * a; }\ntemplate <typename\
    \ T, typename U> constexpr bool chmax(T &a, const U &b) { return a < b ? a = b,\
    \ true : false; }\ntemplate <typename T, typename U> constexpr bool chmin(T &a,\
    \ const U &b) { return a > b ? a = b, true : false; }\ntemplate <typename T, typename\
    \ U> ostream &operator<<(ostream &os, const pair<T, U> &a) {\n    os << \"(\"\
    \ << a.first << \", \" << a.second << \")\";\n    return os;\n}\ntemplate <typename\
    \ T, typename U, typename V> ostream &operator<<(ostream &os, const tuple<T, U,\
    \ V> &a) {\n    os << \"(\" << get<0>(a) << \", \" << get<1>(a) << \", \" << get<2>(a)\
    \ << \")\";\n    return os;\n}\ntemplate <typename T> ostream &operator<<(ostream\
    \ &os, const vector<T> &a) {\n    os << \"(\";\n    for (auto itr = a.begin();\
    \ itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? \", \" : \"\");\n\
    \    os << \")\";\n    return os;\n}\ntemplate <typename T> ostream &operator<<(ostream\
    \ &os, const set<T> &a) {\n    os << \"(\";\n    for (auto itr = a.begin(); itr\
    \ != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? \", \" : \"\");\n \
    \   os << \")\";\n    return os;\n}\ntemplate <typename T> ostream &operator<<(ostream\
    \ &os, const multiset<T> &a) {\n    os << \"(\";\n    for (auto itr = a.begin();\
    \ itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? \", \" : \"\");\n\
    \    os << \")\";\n    return os;\n}\ntemplate <typename T, typename U> ostream\
    \ &operator<<(ostream &os, const map<T, U> &a) {\n    os << \"(\";\n    for (auto\
    \ itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end()\
    \ ? \", \" : \"\");\n    os << \")\";\n    return os;\n}\n#ifdef ONLINE_JUDGE\n\
    #define dump(...) (void(0))\n#else\nvoid debug() { cerr << endl; }\ntemplate <typename\
    \ Head, typename... Tail> void debug(Head &&head, Tail &&... tail) {\n    cerr\
    \ << head;\n    if (sizeof...(Tail)) cerr << \", \";\n    debug(tail...);\n}\n\
    #define dump(...) cerr << __LINE__ << \": \" << #__VA_ARGS__ << \" = \", debug(__VA_ARGS__)\n\
    #endif\nstruct rep {\n    struct itr {\n        ll v;\n        itr(ll v) : v(v)\
    \ {}\n        void operator++() { ++v; }\n        ll operator*() const { return\
    \ v; }\n        bool operator!=(itr i) const { return v < *i; }\n    };\n    ll\
    \ l, r;\n    rep(ll l, ll r) : l(l), r(r) {}\n    rep(ll r) : rep(0, r) {}\n \
    \   itr begin() const { return l; };\n    itr end() const { return r; };\n};\n\
    struct per {\n    struct itr {\n        ll v;\n        itr(ll v) : v(v) {}\n \
    \       void operator++() { --v; }\n        ll operator*() const { return v; }\n\
    \        bool operator!=(itr i) const { return v > *i; }\n    };\n    ll l, r;\n\
    \    per(ll l, ll r) : l(l), r(r) {}\n    per(ll r) : per(0, r) {}\n    itr begin()\
    \ const { return r - 1; };\n    itr end() const { return l - 1; };\n};\nstruct\
    \ io_setup {\n    static constexpr int PREC = 20;\n    io_setup() {\n        cout\
    \ << fixed << setprecision(PREC);\n        cerr << fixed << setprecision(PREC);\n\
    \    };\n} iOS;\n#line 4 \"graph/khan.hpp\"\n\nstruct khan {\n    vector<vector<ll>>\
    \ g;\n    vector<ll> indeg;\n    khan(ll n) : g(n), indeg(n) {}\n    void add_edge(ll\
    \ from, ll to) { g[from].push_back(to), ++indeg[to]; }\n    vector<ll> get() {\n\
    \        vector<ll> _indeg(indeg), ret;\n        for (ll i : rep(g.size())) {\n\
    \            if (_indeg[i] == 0) ret.push_back(i);\n        }\n        for (ll\
    \ i : rep(g.size())) {\n            if (i >= ret.size()) return {};\n        \
    \    for (ll to : g[ret[i]]) {\n                if (--_indeg[to] == 0) ret.push_back(to);\n\
    \            }\n        }\n        return ret;\n    }\n};\n#line 3 \"test/unit/khan.test.cpp\"\
    \n\n#line 5 \"test/unit/khan.test.cpp\"\nusing namespace std;\n\nint main() {\n\
    \    constexpr int n = 20, v = 100, e = 1000;\n    random_device rnd;\n    mt19937\
    \ mt(rnd());\n    uniform_int_distribution<> uid(0, v - 1);\n    for (ll i : rep(n))\
    \ {\n        khan khan(v);\n        bool used[v][v] = {};\n        int src[v];\n\
    \        for (ll i : rep(v)) { src[i] = i; }\n        shuffle(src, src + n, mt);\n\
    \        for (ll j : rep(e)) {\n            int u = uid(mt), v = uid(mt);\n  \
    \          if (used[u][v]) { continue; }\n            if (src[u] < src[v]) {\n\
    \                khan.add_edge(u, v);\n                used[u][v] = true;\n  \
    \          }\n        }\n        vll sorted = khan.get();\n        // shuffle(sorted.begin(),\
    \ sorted.end(), mt);\n        for (ll j : rep(v)) {\n            for (ll k : rep(j\
    \ + 1, v)) { assert(!used[sorted[k]][sorted[j]]); }\n        }\n    }\n\n    cout\
    \ << \"Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#include \"../../graph/khan.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    constexpr int n = 20, v = 100, e = 1000;\n    random_device\
    \ rnd;\n    mt19937 mt(rnd());\n    uniform_int_distribution<> uid(0, v - 1);\n\
    \    for (ll i : rep(n)) {\n        khan khan(v);\n        bool used[v][v] = {};\n\
    \        int src[v];\n        for (ll i : rep(v)) { src[i] = i; }\n        shuffle(src,\
    \ src + n, mt);\n        for (ll j : rep(e)) {\n            int u = uid(mt), v\
    \ = uid(mt);\n            if (used[u][v]) { continue; }\n            if (src[u]\
    \ < src[v]) {\n                khan.add_edge(u, v);\n                used[u][v]\
    \ = true;\n            }\n        }\n        vll sorted = khan.get();\n      \
    \  // shuffle(sorted.begin(), sorted.end(), mt);\n        for (ll j : rep(v))\
    \ {\n            for (ll k : rep(j + 1, v)) { assert(!used[sorted[k]][sorted[j]]);\
    \ }\n        }\n    }\n\n    cout << \"Hello World\" << endl;\n}"
  dependsOn:
  - graph/khan.hpp
  - template.hpp
  isVerificationFile: true
  path: test/unit/khan.test.cpp
  requiredBy: []
  timestamp: '2022-10-20 00:25:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/khan.test.cpp
layout: document
redirect_from:
- /verify/test/unit/khan.test.cpp
- /verify/test/unit/khan.test.cpp.html
title: test/unit/khan.test.cpp
---