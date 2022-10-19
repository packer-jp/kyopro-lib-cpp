---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/dinic.hpp
    title: "Dinic \u6CD5"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"test/onlinejudge.u-aizu.ac.jp/Maximum_Flow.1.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n#line 2 \"graph/dinic.hpp\"\n\n#line 2 \"template.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define all(a) begin(a), end(a)\n#define rall(a) rbegin(a),\
    \ rend(a)\n#define uniq(a) (a).erase(unique(all(a)), (a).end())\n#define t0 first\n\
    #define t1 second\nusing ll = long long;\nusing ull = unsigned long long;\nusing\
    \ pll = pair<ll, ll>;\nusing vll = vector<ll>;\nconstexpr double pi = 3.14159265358979323846;\n\
    constexpr ll dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};\nconstexpr ll dx[9] = {1,\
    \ 0, -1, 0, 1, -1, -1, 1, 0};\nconstexpr ll sign(ll a) { return (a > 0) - (a <\
    \ 0); }\nconstexpr ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b);\
    \ }\nconstexpr ll cdiv(ll a, ll b) { return -fdiv(-a, b); }\nconstexpr ll pw(ll\
    \ n) { return 1ll << n; }\nconstexpr ll flg(ll n) { return 63 - __builtin_clzll(n);\
    \ }\nconstexpr ll clg(ll n) { return flg(n - 1) + 1; }\nconstexpr ll safemod(ll\
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
    \        cerr << fixed << setprecision(PREC);\n    };\n} iOS;\n#line 4 \"graph/dinic.hpp\"\
    \n\ntemplate <typename S> struct dinic {\n    using C = typename S::C;\n    struct\
    \ _edge {\n        ll to, rev;\n        C cap;\n    };\n    struct edge {\n  \
    \      ll from, to;\n        C cap, flow;\n        friend ostream &operator<<(ostream\
    \ &os, const edge &e) {\n            return os << \"(from: \" << e.from << \"\
    , to: \" << e.to << \", cap: \" << e.cap << \", flow: \" << e.flow << \")\";\n\
    \        }\n    };\n    vector<vector<_edge>> g;\n    vector<ll> level, iter;\n\
    \    vector<pair<ll, ll>> pos;\n    dinic(ll n) : g(n), level(n), iter(n) {}\n\
    \    ll add_edge(ll from, ll to, C cap) {\n        ll from_id = g[from].size();\n\
    \        ll to_id = g[to].size();\n        if (from == to) ++to_id;\n        g[from].push_back({to,\
    \ to_id, cap});\n        g[to].push_back({from, from_id, S::zero()});\n      \
    \  pos.emplace_back(from, from_id);\n        return pos.size() - 1;\n    }\n \
    \   void change_edge(ll i, C new_cap, C new_flow) {\n        _edge &e = g[pos[i].first][pos[i].second],\
    \ &re = g[e.to][e.rev];\n        e.cap = new_cap - new_flow;\n        re.cap =\
    \ new_flow;\n    }\n    C flow(ll s, ll t, C lim = S::inf()) {\n        auto bfs\
    \ = [&](ll s) -> void {\n            fill(level.begin(), level.end(), -1);\n \
    \           queue<ll> q;\n            level[s] = 0;\n            q.push(s);\n\
    \            while (!q.empty()) {\n                ll v = q.front();\n       \
    \         q.pop();\n                for (_edge &e : g[v]) {\n                \
    \    if (e.cap == S::zero() || level[e.to] >= 0) continue;\n                 \
    \   level[e.to] = level[v] + 1;\n                    q.push(e.to);\n         \
    \       }\n            }\n        };\n        auto dfs = [&](auto dfs, ll v, ll\
    \ t, C lim) -> C {\n            if (v == t) return lim;\n            for (ll &i\
    \ = iter[v]; i < (ll)g[v].size(); ++i) {\n                _edge &e = g[v][i];\n\
    \                if (level[v] >= level[e.to] || e.cap == S::zero()) continue;\n\
    \                C d = dfs(dfs, e.to, t, lim > e.cap ? e.cap : lim);\n       \
    \         if (d == S::zero()) continue;\n                e.cap -= d;\n       \
    \         g[e.to][e.rev].cap += d;\n                return d;\n            }\n\
    \            return S::zero();\n        };\n        C ret = S::zero();\n     \
    \   while (true) {\n            bfs(s);\n            if (level[t] < 0 || lim ==\
    \ S::zero()) return ret;\n            fill(iter.begin(), iter.end(), 0);\n   \
    \         C f;\n            while ((f = dfs(dfs, s, t, lim)) != S::zero()) {\n\
    \                ret += f;\n                lim -= f;\n            }\n       \
    \ }\n    }\n    edge get_edge(ll i) const {\n        _edge e = g[pos[i].first][pos[i].second],\
    \ re = g[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap + re.cap, re.cap};\n\
    \    }\n    vector<edge> edges() const {\n        vector<edge> ret(pos.size());\n\
    \        for (ll i : rep(pos.size())) ret[i] = get_edge(i);\n        return ret;\n\
    \    }\n    vector<bool> cut(ll s) const {\n        vector<bool> ret(g.size());\n\
    \        auto dfs = [&](auto dfs, ll v) -> void {\n            if (ret[v]) return;\n\
    \            ret[v] = true;\n            for (_edge e : g[v]) {\n            \
    \    if (e.cap) dfs(dfs, e.to);\n            }\n        };\n        dfs(dfs, s);\n\
    \        return ret;\n    }\n};\n\nstruct ll_dinic {\n    using C = ll;\n    static\
    \ C zero() { return 0; }\n    static C inf() { return numeric_limits<C>::max();\
    \ }\n};\n#line 3 \"test/onlinejudge.u-aizu.ac.jp/Maximum_Flow.1.test.cpp\"\n\n\
    #line 5 \"test/onlinejudge.u-aizu.ac.jp/Maximum_Flow.1.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n    ll v, e;\n    cin >> v >> e;\n    dinic<ll_dinic>\
    \ dinic(v);\n    while (e--) {\n        ll u, v, c;\n        cin >> u >> v >>\
    \ c;\n        dinic.add_edge(u, v, c);\n    }\n    dinic.flow(0, v - 1);\n   \
    \ auto flow = dinic.edges();\n    ll ans = 0;\n    for (auto e : flow) {\n   \
    \     if (e.from == 0) ans += e.flow;\n    }\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n#include \"../../graph/dinic.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ll v, e;\n    cin >> v >> e;\n    dinic<ll_dinic>\
    \ dinic(v);\n    while (e--) {\n        ll u, v, c;\n        cin >> u >> v >>\
    \ c;\n        dinic.add_edge(u, v, c);\n    }\n    dinic.flow(0, v - 1);\n   \
    \ auto flow = dinic.edges();\n    ll ans = 0;\n    for (auto e : flow) {\n   \
    \     if (e.from == 0) ans += e.flow;\n    }\n    cout << ans << endl;\n}"
  dependsOn:
  - graph/dinic.hpp
  - template.hpp
  isVerificationFile: true
  path: test/onlinejudge.u-aizu.ac.jp/Maximum_Flow.1.test.cpp
  requiredBy: []
  timestamp: '2022-10-19 19:47:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/onlinejudge.u-aizu.ac.jp/Maximum_Flow.1.test.cpp
layout: document
redirect_from:
- /verify/test/onlinejudge.u-aizu.ac.jp/Maximum_Flow.1.test.cpp
- /verify/test/onlinejudge.u-aizu.ac.jp/Maximum_Flow.1.test.cpp.html
title: test/onlinejudge.u-aizu.ac.jp/Maximum_Flow.1.test.cpp
---
