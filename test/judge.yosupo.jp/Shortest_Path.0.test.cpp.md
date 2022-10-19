---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/dijkstra.hpp
    title: "Dijkstra \u6CD5"
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/judge.yosupo.jp/Shortest_Path.0.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"graph/dijkstra.hpp\"\
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
    \ ll clg(ll n) { return n == 1 ? 0 : flg(n - 1) + 1; }\nconstexpr ll safemod(ll\
    \ x, ll mod) { return (x % mod + mod) % mod; }\ntemplate <typename T> using priority_queue_rev\
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
    \ inf() { return LLONG_MAX; }\n};\n#line 3 \"test/judge.yosupo.jp/Shortest_Path.0.test.cpp\"\
    \n\nint main() {\n    ll n, m, s, t;\n    cin >> n >> m >> s >> t;\n    dijkstra<ll_dijkstra>\
    \ dij(n);\n    while (m--) {\n        int a, b, c;\n        cin >> a >> b >> c;\n\
    \        dij.add_edge(a, b, c);\n    }\n    auto [dist, prev] = dij.get(s);\n\
    \    if (prev[t] == -1) {\n        cout << -1 << endl;\n        return 0;\n  \
    \  }\n    vll vs{t};\n    do {\n        ll back = vs.back();\n        vs.push_back(prev[back]);\n\
    \    } while (vs.back() != s);\n    reverse(all(vs));\n    cout << dist[t] <<\
    \ \" \" << vs.size() - 1 << endl;\n    for (ll i : rep(vs.size() - 1)) cout <<\
    \ vs[i] << \" \" << vs[i + 1] << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"../../graph/dijkstra.hpp\"\n\nint main() {\n    ll n, m, s, t;\n    cin >>\
    \ n >> m >> s >> t;\n    dijkstra<ll_dijkstra> dij(n);\n    while (m--) {\n  \
    \      int a, b, c;\n        cin >> a >> b >> c;\n        dij.add_edge(a, b, c);\n\
    \    }\n    auto [dist, prev] = dij.get(s);\n    if (prev[t] == -1) {\n      \
    \  cout << -1 << endl;\n        return 0;\n    }\n    vll vs{t};\n    do {\n \
    \       ll back = vs.back();\n        vs.push_back(prev[back]);\n    } while (vs.back()\
    \ != s);\n    reverse(all(vs));\n    cout << dist[t] << \" \" << vs.size() - 1\
    \ << endl;\n    for (ll i : rep(vs.size() - 1)) cout << vs[i] << \" \" << vs[i\
    \ + 1] << endl;\n}"
  dependsOn:
  - graph/dijkstra.hpp
  - template.hpp
  isVerificationFile: true
  path: test/judge.yosupo.jp/Shortest_Path.0.test.cpp
  requiredBy: []
  timestamp: '2022-10-20 00:25:59+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/judge.yosupo.jp/Shortest_Path.0.test.cpp
layout: document
redirect_from:
- /verify/test/judge.yosupo.jp/Shortest_Path.0.test.cpp
- /verify/test/judge.yosupo.jp/Shortest_Path.0.test.cpp.html
title: test/judge.yosupo.jp/Shortest_Path.0.test.cpp
---
