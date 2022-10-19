---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution.hpp
    title: "\u7573\u307F\u8FBC\u307F"
  - icon: ':question:'
    path: math/modint.hpp
    title: modint
  - icon: ':question:'
    path: math/ntt.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/judge.yosupo.jp/Convolution.0.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod\"\n#line 2 \"math/convolution.hpp\"\
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
    \        cerr << fixed << setprecision(PREC);\n    };\n} iOS;\n#line 2 \"math/ntt.hpp\"\
    \n\n#line 4 \"math/ntt.hpp\"\n\ntemplate <typename mint> void ntt(vector<mint>\
    \ &a, bool inv = false) {\n    ll n = a.size(), m = n >> 1;\n    mint root = 2;\n\
    \    while (root.pow((mint::mod() - 1) >> 1) == 1) root += 1;\n    mint wn = root.pow((mint::mod()\
    \ - 1) / n);\n    if (inv) wn = wn.inv();\n    vector<mint> b(n);\n    for (ll\
    \ i = 1; i < n; i <<= 1, wn *= wn, swap(a, b)) {\n        mint wj = 1;\n     \
    \   for (ll j = 0; j < m; j += i, wj *= wn) {\n            for (ll k : rep(i))\
    \ {\n                b[0 + (j << 1) + k] = (a[0 + j + k] + a[m + j + k]);\n  \
    \              b[i + (j << 1) + k] = (a[0 + j + k] - a[m + j + k]) * wj;\n   \
    \         }\n        }\n    }\n    if (inv) {\n        mint ninv = mint(n).inv();\n\
    \        for (mint &ai : a) ai *= ninv;\n    }\n}\ntemplate <typename mint> void\
    \ intt(vector<mint> &a) { ntt(a, true); }\n#line 5 \"math/convolution.hpp\"\n\n\
    template <typename V> vector<V> convolution_naive(vector<V> a, vector<V> b) {\n\
    \    ll na = a.size(), nb = b.size();\n    vector<V> c(na + nb - 1);\n    if (na\
    \ < nb) swap(a, b), swap(na, nb);\n    for (ll i : rep(na)) {\n        for (ll\
    \ j : rep(nb)) c[i + j] += a[i] * b[j];\n    }\n    return c;\n}\n\ntemplate <typename\
    \ mint> vector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\n    ll\
    \ _n = a.size() + b.size() - 1, n;\n    for (n = 1; n < _n; n <<= 1) {}\n    a.resize(n),\
    \ b.resize(n);\n    ntt(a), ntt(b);\n    for (ll i : rep(n)) a[i] *= b[i];\n \
    \   intt(a);\n    a.resize(_n);\n    return a;\n}\n\ntemplate <typename mint>\
    \ vector<mint> convolution(const vector<mint> &a, const vector<mint> &b) {\n \
    \   if (min(a.size(), b.size()) <= 60) {\n        return convolution_naive(a,\
    \ b);\n    } else {\n        return convolution_ntt(a, b);\n    }\n}\n#line 2\
    \ \"math/modint.hpp\"\n\n#line 4 \"math/modint.hpp\"\n\ntemplate <typename M>\
    \ struct modint {\n    ll val;\n    modint(ll val = 0) : val(val >= 0 ? val %\
    \ M::mod : (M::mod - (-val) % M::mod) % M::mod) {}\n    static ll mod() { return\
    \ M::mod; }\n    modint inv() const {\n        ll a = val, b = M::mod, u = 1,\
    \ v = 0, t;\n        while (b > 0) {\n            t = a / b;\n            swap(a\
    \ -= t * b, b);\n            swap(u -= t * v, v);\n        }\n        return u;\n\
    \    }\n    modint pow(ll k) const {\n        modint ret = 1, mul = val;\n   \
    \     while (k) {\n            if (k & 1) ret *= mul;\n            mul *= mul;\n\
    \            k >>= 1;\n        }\n        return ret;\n    }\n    modint &operator+=(const\
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
    \ = modint<_1000000007>;\n\nstruct arbitrary {\n    static ll mod;\n};\nll arbitrary::mod;\n\
    #line 4 \"test/judge.yosupo.jp/Convolution.0.test.cpp\"\n\nint main() {\n    using\
    \ mint = modint998244353;\n    ll n, m;\n    cin >> n >> m;\n    vector<mint>\
    \ a(n), b(m);\n    for (ll i : rep(n)) cin >> a[i];\n    for (ll i : rep(m)) cin\
    \ >> b[i];\n    vector<mint> c = convolution(a, b);\n    for (mint ci : c) { cout\
    \ << ci << \" \"; }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ \"../../math/convolution.hpp\"\n#include \"../../math/modint.hpp\"\n\nint main()\
    \ {\n    using mint = modint998244353;\n    ll n, m;\n    cin >> n >> m;\n   \
    \ vector<mint> a(n), b(m);\n    for (ll i : rep(n)) cin >> a[i];\n    for (ll\
    \ i : rep(m)) cin >> b[i];\n    vector<mint> c = convolution(a, b);\n    for (mint\
    \ ci : c) { cout << ci << \" \"; }\n    cout << endl;\n}"
  dependsOn:
  - math/convolution.hpp
  - template.hpp
  - math/ntt.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/judge.yosupo.jp/Convolution.0.test.cpp
  requiredBy: []
  timestamp: '2022-10-19 16:09:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/judge.yosupo.jp/Convolution.0.test.cpp
layout: document
redirect_from:
- /verify/test/judge.yosupo.jp/Convolution.0.test.cpp
- /verify/test/judge.yosupo.jp/Convolution.0.test.cpp.html
title: test/judge.yosupo.jp/Convolution.0.test.cpp
---
