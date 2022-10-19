---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/hld.test.cpp
    title: test/unit/hld.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/hld.hpp\"\n\n#line 2 \"template.hpp\"\n\n#include\
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
    \        cerr << fixed << setprecision(PREC);\n    };\n} iOS;\n#line 4 \"graph/hld.hpp\"\
    \n\nstruct hld {\n    vector<vector<ll>> g;\n    vector<ll> par, sz, dep, in,\
    \ out, head;\n    hld(ll n) : g(n), par(n), sz(n), dep(n), in(n), out(n), head(n)\
    \ {}\n    void add_edge(ll u, ll v) { g[u].push_back(v), g[v].push_back(u); }\n\
    \    vector<ll> build(ll root) {\n        auto dfs_sz = [&](auto dfs_sz, ll v,\
    \ ll p) -> void {\n            sz[v] = 1;\n            par[v] = p;\n         \
    \   if (p != -1) dep[v] = dep[p] + 1;\n            for (ll &u : g[v]) {\n    \
    \            if (u == p) continue;\n                dfs_sz(dfs_sz, u, v);\n  \
    \              sz[v] += sz[u];\n                if (sz[u] > sz[g[v][0]]) swap(u,\
    \ g[v][0]);\n            }\n        };\n        ll t = 0;\n        auto dfs_hld\
    \ = [&](auto dfs_hld, ll v) -> ll {\n            in[v] = t++;\n            for\
    \ (ll i : rep(g[v].size())) {\n                ll u = g[v][i];\n             \
    \   if (u == par[v]) continue;\n                head[u] = (i == 0 ? head[v] :\
    \ u);\n                dfs_hld(dfs_hld, u);\n            }\n            return\
    \ out[v] = t;\n        };\n        dfs_sz(dfs_sz, root, -1);\n        head[root]\
    \ = root;\n        dfs_hld(dfs_hld, root);\n        return in;\n    }\n    ll\
    \ lca(ll u, ll v) const {\n        while (true) {\n            if (in[u] > in[v])\
    \ swap(u, v);\n            if (head[u] == head[v]) return u;\n            v =\
    \ par[head[v]];\n        }\n    }\n    ll dist(ll u, ll v) const { return dep[u]\
    \ + dep[v] - 2 * dep[lca(u, v)]; }\n    vector<pair<ll, ll>> get_path(ll u, ll\
    \ v, bool edge) const {\n        vector<pair<ll, ll>> a, b;\n        while (true)\
    \ {\n            if (head[u] == head[v]) {\n                if (edge) {\n    \
    \                if (in[u] > in[v]) a.emplace_back(in[u], in[v] + 1);\n      \
    \              if (in[u] < in[v]) a.emplace_back(in[u] + 1, in[v]);\n        \
    \        } else {\n                    a.emplace_back(in[u], in[v]);\n       \
    \         }\n                break;\n            }\n            if (in[u] > in[v])\
    \ {\n                a.emplace_back(in[u], in[head[u]]);\n                u =\
    \ par[head[u]];\n            } else {\n                b.emplace_back(in[head[v]],\
    \ in[v]);\n                v = par[head[v]];\n            }\n        }\n     \
    \   a.insert(a.end(), b.rbegin(), b.rend());\n        return a;\n    }\n    pair<ll,\
    \ ll> get_subtree(ll v, bool edge) const { return {in[v] + edge, out[v] - 1};\
    \ }\n};\n"
  code: "#pragma once\n\n#include \"../template.hpp\"\n\nstruct hld {\n    vector<vector<ll>>\
    \ g;\n    vector<ll> par, sz, dep, in, out, head;\n    hld(ll n) : g(n), par(n),\
    \ sz(n), dep(n), in(n), out(n), head(n) {}\n    void add_edge(ll u, ll v) { g[u].push_back(v),\
    \ g[v].push_back(u); }\n    vector<ll> build(ll root) {\n        auto dfs_sz =\
    \ [&](auto dfs_sz, ll v, ll p) -> void {\n            sz[v] = 1;\n           \
    \ par[v] = p;\n            if (p != -1) dep[v] = dep[p] + 1;\n            for\
    \ (ll &u : g[v]) {\n                if (u == p) continue;\n                dfs_sz(dfs_sz,\
    \ u, v);\n                sz[v] += sz[u];\n                if (sz[u] > sz[g[v][0]])\
    \ swap(u, g[v][0]);\n            }\n        };\n        ll t = 0;\n        auto\
    \ dfs_hld = [&](auto dfs_hld, ll v) -> ll {\n            in[v] = t++;\n      \
    \      for (ll i : rep(g[v].size())) {\n                ll u = g[v][i];\n    \
    \            if (u == par[v]) continue;\n                head[u] = (i == 0 ? head[v]\
    \ : u);\n                dfs_hld(dfs_hld, u);\n            }\n            return\
    \ out[v] = t;\n        };\n        dfs_sz(dfs_sz, root, -1);\n        head[root]\
    \ = root;\n        dfs_hld(dfs_hld, root);\n        return in;\n    }\n    ll\
    \ lca(ll u, ll v) const {\n        while (true) {\n            if (in[u] > in[v])\
    \ swap(u, v);\n            if (head[u] == head[v]) return u;\n            v =\
    \ par[head[v]];\n        }\n    }\n    ll dist(ll u, ll v) const { return dep[u]\
    \ + dep[v] - 2 * dep[lca(u, v)]; }\n    vector<pair<ll, ll>> get_path(ll u, ll\
    \ v, bool edge) const {\n        vector<pair<ll, ll>> a, b;\n        while (true)\
    \ {\n            if (head[u] == head[v]) {\n                if (edge) {\n    \
    \                if (in[u] > in[v]) a.emplace_back(in[u], in[v] + 1);\n      \
    \              if (in[u] < in[v]) a.emplace_back(in[u] + 1, in[v]);\n        \
    \        } else {\n                    a.emplace_back(in[u], in[v]);\n       \
    \         }\n                break;\n            }\n            if (in[u] > in[v])\
    \ {\n                a.emplace_back(in[u], in[head[u]]);\n                u =\
    \ par[head[u]];\n            } else {\n                b.emplace_back(in[head[v]],\
    \ in[v]);\n                v = par[head[v]];\n            }\n        }\n     \
    \   a.insert(a.end(), b.rbegin(), b.rend());\n        return a;\n    }\n    pair<ll,\
    \ ll> get_subtree(ll v, bool edge) const { return {in[v] + edge, out[v] - 1};\
    \ }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/hld.hpp
  requiredBy: []
  timestamp: '2022-10-20 00:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/hld.test.cpp
documentation_of: graph/hld.hpp
layout: document
title: "HL \u5206\u89E3"
---

## 概要
- HL 分解を用いて木をパスに分解する。

## 詳細

- `struct hld`  
    HL 分解を行う構造体。

    - `(constructor)(int n)`  
        頂点数 $n$ で初期化。

    - `void add_edge(int u, int v)`  
        頂点 $u, v$ 間に辺を張る。

    - `vector<int> build(int root)`  
        頂点 $root$ を根として初期化し、各頂点の別の番号の `vector` を返す。 $O(n)$ 時間。

    - `int lca(int u, int v)`  
        頂点 $u, v$ の LCA の番号を返す。 $O(\log n)$ 時間。
    
    - `int get_path(int u, int v, bool edge)`  
        頂点属性のクエリの場合、頂点 $u, v$ 間のパスを $O(\log n)$ 個に分解し、「「新たな番号での始点、終点 (閉区間) を表す `pair`」 の `vector`」を返す。辺属性のクエリの場合もほぼ同様だが、こちらの場合は新たな頂点番号について、その頂点の親に繋がる辺という意味になる。

    - `pair<int, int> get_subtree(int v, bool edge)`  
        頂点 $v$ の部分木を $1$ 個の区間として返す。

## 備考
- 雑なのでまたちゃんと書く

## 参考
- [adamant さんの Codeforces blog](https://codeforces.com/blog/entry/53170)