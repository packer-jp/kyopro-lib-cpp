---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/and_or_convolution.hpp
    title: "and / or \u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: math/fzt_fmt.hpp
    title: "\u9AD8\u901F Zeta / Moebius \u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/judge.yosupo.jp/Bitwise_And_Convolution.0.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\
    #line 2 \"math/and_or_convolution.hpp\"\n\n#line 2 \"template.hpp\"\n\n#include\
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
    \        cerr << fixed << setprecision(PREC);\n    };\n} iOS;\n#line 2 \"math/fzt_fmt.hpp\"\
    \n\n#line 4 \"math/fzt_fmt.hpp\"\n\ntemplate <typename V> void fzt_super(vector<V>\
    \ &a) {\n    for (ll i : rep(flg(a.size()))) {\n        for (ll s : rep(a.size()))\
    \ {\n            if ((s >> i) & 1) a[s ^ pw(i)] += a[s];\n        }\n    }\n}\n\
    \ntemplate <typename V> void fzt_sub(vector<V> &a) {\n    for (ll i : rep(flg(a.size())))\
    \ {\n        for (ll s : rep(a.size())) {\n            if (!((s >> i) & 1)) a[s\
    \ ^ pw(i)] += a[s];\n        }\n    }\n}\n\ntemplate <typename V> void fmt_super(vector<V>\
    \ &a) {\n    for (ll i : rep(flg(a.size()))) {\n        for (ll s : rep(a.size()))\
    \ {\n            if ((s >> i) & 1) a[s ^ pw(i)] -= a[s];\n        }\n    }\n}\n\
    \ntemplate <typename V> void fmt_sub(vector<V> &a) {\n    for (ll i : rep(flg(a.size())))\
    \ {\n        for (ll s : rep(a.size())) {\n            if (!((s >> i) & 1)) a[s\
    \ ^ pw(i)] -= a[s];\n        }\n    }\n}\n#line 5 \"math/and_or_convolution.hpp\"\
    \n\ntemplate <typename V> vector<V> and_convolution(vector<V> a, vector<V> b)\
    \ {\n    ll _n = max(a.size(), b.size()), n;\n    for (n = 1; n < _n; n <<= 1)\
    \ {}\n    a.resize(n), b.resize(n);\n    fzt_super(a), fzt_super(b);\n    for\
    \ (ll i : rep(n)) a[i] *= b[i];\n    fmt_super(a);\n    return a;\n}\n\ntemplate\
    \ <typename V> vector<V> or_convolution(vector<V> a, vector<V> b) {\n    ll _n\
    \ = max(a.size(), b.size()), n;\n    for (n = 1; n < _n; n <<= 1) {}\n    a.resize(n),\
    \ b.resize(n);\n    fzt_sub(a), fzt_sub(b);\n    for (ll i : rep(n)) a[i] *= b[i];\n\
    \    fmt_sub(a);\n    return a;\n}\n#line 2 \"math/modint.hpp\"\n\n#line 4 \"\
    math/modint.hpp\"\n\ntemplate <typename M> struct modint {\n    ll val;\n    modint(ll\
    \ val = 0) : val(val >= 0 ? val % M::mod : (M::mod - (-val) % M::mod) % M::mod)\
    \ {}\n    static ll mod() { return M::mod; }\n    modint inv() const {\n     \
    \   ll a = val, b = M::mod, u = 1, v = 0, t;\n        while (b > 0) {\n      \
    \      t = a / b;\n            swap(a -= t * b, b);\n            swap(u -= t *\
    \ v, v);\n        }\n        return u;\n    }\n    modint pow(ll k) const {\n\
    \        modint ret = 1, mul = val;\n        while (k) {\n            if (k &\
    \ 1) ret *= mul;\n            mul *= mul;\n            k >>= 1;\n        }\n \
    \       return ret;\n    }\n    modint &operator+=(const modint &a) {\n      \
    \  if ((val += a.val) >= M::mod) val -= M::mod;\n        return *this;\n    }\n\
    \    modint &operator-=(const modint &a) {\n        if ((val += M::mod - a.val)\
    \ >= M::mod) val -= M::mod;\n        return *this;\n    }\n    modint &operator*=(const\
    \ modint &a) {\n        (val *= a.val) %= M::mod;\n        return *this;\n   \
    \ }\n    modint &operator/=(const modint &a) { return *this *= a.inv(); }\n  \
    \  modint operator+() const { return *this; }\n    modint operator-() const {\
    \ return modint(-val); }\n    friend bool operator==(const modint &a, const modint\
    \ &b) { return a.val == b.val; }\n    friend bool operator!=(const modint &a,\
    \ const modint &b) { return rel_ops::operator!=(a, b); }\n    friend modint operator+(const\
    \ modint &a, const modint &b) { return modint(a) += b; }\n    friend modint operator-(const\
    \ modint &a, const modint &b) { return modint(a) -= b; }\n    friend modint operator*(const\
    \ modint &a, const modint &b) { return modint(a) *= b; }\n    friend modint operator/(const\
    \ modint &a, const modint &b) { return modint(a) /= b; }\n    friend istream &operator>>(istream\
    \ &is, modint &a) {\n        ll val;\n        is >> val;\n        a = modint(val);\n\
    \        return is;\n    }\n    friend ostream &operator<<(ostream &os, const\
    \ modint &a) { return os << a.val; }\n};\n\nstruct _998244353 {\n    constexpr\
    \ static ll mod = 998244353;\n};\nstruct _1000000007 {\n    constexpr static ll\
    \ mod = 1000000007;\n};\nusing modint998244353 = modint<_998244353>;\nusing modint1000000007\
    \ = modint<_1000000007>;\n\nstruct arbitrary {\n    static ll mod;\n};\nll arbitrary::mod;\n\
    #line 4 \"test/judge.yosupo.jp/Bitwise_And_Convolution.0.test.cpp\"\n\nint main()\
    \ {\n    using mint = modint998244353;\n    ll n;\n    cin >> n;\n    vector<mint>\
    \ a(pw(n)), b(pw(n));\n    for (ll i : rep(pw(n))) cin >> a[i];\n    for (ll i\
    \ : rep(pw(n))) cin >> b[i];\n    vector<mint> c = and_convolution(a, b);\n  \
    \  for (mint ci : c) { cout << ci << \" \"; }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n#include \"../../math/and_or_convolution.hpp\"\n#include \"../../math/modint.hpp\"\
    \n\nint main() {\n    using mint = modint998244353;\n    ll n;\n    cin >> n;\n\
    \    vector<mint> a(pw(n)), b(pw(n));\n    for (ll i : rep(pw(n))) cin >> a[i];\n\
    \    for (ll i : rep(pw(n))) cin >> b[i];\n    vector<mint> c = and_convolution(a,\
    \ b);\n    for (mint ci : c) { cout << ci << \" \"; }\n    cout << endl;\n}"
  dependsOn:
  - math/and_or_convolution.hpp
  - template.hpp
  - math/fzt_fmt.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/judge.yosupo.jp/Bitwise_And_Convolution.0.test.cpp
  requiredBy: []
  timestamp: '2022-10-20 00:25:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/judge.yosupo.jp/Bitwise_And_Convolution.0.test.cpp
layout: document
redirect_from:
- /verify/test/judge.yosupo.jp/Bitwise_And_Convolution.0.test.cpp
- /verify/test/judge.yosupo.jp/Bitwise_And_Convolution.0.test.cpp.html
title: test/judge.yosupo.jp/Bitwise_And_Convolution.0.test.cpp
---
