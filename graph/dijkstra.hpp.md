---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Shortest_Path.0.test.cpp
    title: test/judge.yosupo.jp/Shortest_Path.0.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n\n#line 2 \"template.hpp\"\n\n#include\
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
    \        cerr << fixed << setprecision(PREC);\n    };\n} iOS;\n#line 4 \"graph/dijkstra.hpp\"\
    \n\ntemplate <typename S> struct dijkstra {\n    using D = typename S::D;\n  \
    \  using C = typename S::C;\n    struct edge {\n        ll to;\n        C cost;\n\
    \    };\n    vector<vector<edge>> g;\n    dijkstra(ll n) : g(n) {}\n    void add_edge(ll\
    \ from, ll to, const C &cost) { g[from].push_back({to, cost}); }\n    pair<vector<D>,\
    \ vector<ll>> get(ll s, const D &base = D()) const {\n        vector<D> dist(g.size(),\
    \ S::inf());\n        vector<ll> prev(g.size(), -1);\n        using P = pair<D,\
    \ ll>;\n        priority_queue_rev<P> pq;\n        dist[s] = base;\n        pq.emplace(base,\
    \ s);\n        while (!pq.empty()) {\n            auto [d, from] = pq.top();\n\
    \            pq.pop();\n            if (dist[from] < d) continue;\n          \
    \  for (auto [to, cost] : g[from]) {\n                D nd = d + cost;\n     \
    \           if (nd < dist[to]) {\n                    dist[to] = nd;\n       \
    \             prev[to] = from;\n                    pq.emplace(nd, to);\n    \
    \            }\n            }\n        }\n        return {dist, prev};\n    }\n\
    };\n\nstruct ll_dijkstra {\n    using D = ll;\n    using C = ll;\n    static D\
    \ inf() { return LLONG_MAX; }\n};\n"
  code: "#pragma once\n\n#include \"../template.hpp\"\n\ntemplate <typename S> struct\
    \ dijkstra {\n    using D = typename S::D;\n    using C = typename S::C;\n   \
    \ struct edge {\n        ll to;\n        C cost;\n    };\n    vector<vector<edge>>\
    \ g;\n    dijkstra(ll n) : g(n) {}\n    void add_edge(ll from, ll to, const C\
    \ &cost) { g[from].push_back({to, cost}); }\n    pair<vector<D>, vector<ll>> get(ll\
    \ s, const D &base = D()) const {\n        vector<D> dist(g.size(), S::inf());\n\
    \        vector<ll> prev(g.size(), -1);\n        using P = pair<D, ll>;\n    \
    \    priority_queue_rev<P> pq;\n        dist[s] = base;\n        pq.emplace(base,\
    \ s);\n        while (!pq.empty()) {\n            auto [d, from] = pq.top();\n\
    \            pq.pop();\n            if (dist[from] < d) continue;\n          \
    \  for (auto [to, cost] : g[from]) {\n                D nd = d + cost;\n     \
    \           if (nd < dist[to]) {\n                    dist[to] = nd;\n       \
    \             prev[to] = from;\n                    pq.emplace(nd, to);\n    \
    \            }\n            }\n        }\n        return {dist, prev};\n    }\n\
    };\n\nstruct ll_dijkstra {\n    using D = ll;\n    using C = ll;\n    static D\
    \ inf() { return LLONG_MAX; }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-10-20 00:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/judge.yosupo.jp/Shortest_Path.0.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
title: "Dijkstra \u6CD5"
---

## 概要
- Dijkstra 法を用いて、負辺のない有向グラフ上の単一始点最短路を求める。

## 詳細

- `<typename S> struct dijkstra`  
    Dijkstra 法を用いて単一始点最短路を求める構造体。

    - `typename S`  
        テンプレート引数として与える構造体。

        - `using dist_t`  
            各頂点の距離を表す型。

        - `using cost_t`  
            各辺のコストを表す型。

        - `static dist_t inf()`  
            `dist_t` の最大元を返す。

    - `(constructor)(int n)`  
        頂点数 $n$ で初期化。

    - `void add_edge(int from, int to, S::cost_t cost)`  
        頂点 $from$ から頂点 $to$ にコスト $cost$ の辺を張る。

    - `pair<vector<S::dist_t>, vector<int>> get(int s, S::dist_t base = S::dist_t())`  
        頂点 $s$ の距離を $base$ と定め、「「各頂点の距離の `vector`」 と「最短路の一つにおいて各頂点の直前に訪れる頂点番号の `vector`」 の `pair`」を取得する。 $O((n + m) \log n)$ 時間。


- `struct ll_dijkstra`  
    距離やコストが `ll` 型であるような「普通の」最短路問題を解くときに`dijkstra`にテンプレート引数 `S` として与える。