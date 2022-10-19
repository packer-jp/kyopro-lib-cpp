---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: "\u884C\u5217"
  - icon: ':question:'
    path: math/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/judge.yosupo.jp/Determinant_of_Matrix.0.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n#line 2 \"math/matrix.hpp\"\
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
    \        cerr << fixed << setprecision(PREC);\n    };\n} iOS;\n#line 4 \"math/matrix.hpp\"\
    \n\ntemplate <typename S> struct matrix {\n    using V = typename S::V;\n    vector<vector<V>>\
    \ val;\n    matrix(int n, int m) : matrix(vector(n, vector(m, S::zero()))) {}\n\
    \    matrix(const vector<vector<V>> &src) : val(src) {}\n    vector<V> &operator[](int\
    \ i) { return val[i]; }\n    const vector<V> &operator[](int i) const { return\
    \ val[i]; }\n    int height() const { return val.size(); }\n    int width() const\
    \ { return val[0].size(); }\n    static matrix id(int n) {\n        matrix ret(n,\
    \ n);\n        for (int i : rep(n)) ret[i][i] = S::one();\n        return ret;\n\
    \    }\n    void row_add(int i, int j, V a) {\n        for (int k : rep(width()))\
    \ { val[i][k] += val[j][k] * a; }\n    }\n    bool place_nonzero(int i, int j)\
    \ {\n        for (int k : rep(i, height())) {\n            if (val[k][j] != S::zero())\
    \ {\n                if (k > i) row_add(i, k, S::one());\n                break;\n\
    \            }\n        }\n        return val[i][j] != S::zero();\n    }\n   \
    \ matrix upper_triangular() const {\n        matrix ret(*this);\n        for (int\
    \ i = 0, j = 0; i < height() && j < width(); j++) {\n            if (!ret.place_nonzero(i,\
    \ j)) continue;\n            for (int k : rep(i + 1, height())) ret.row_add(k,\
    \ i, -ret[k][j] / ret[i][j]);\n            i++;\n        }\n        return ret;\n\
    \    }\n    V det() const {\n        V ret = S::one();\n        matrix ut = upper_triangular();\n\
    \        for (int i : rep(height())) ret *= ut[i][i];\n        return ret;\n \
    \   }\n    matrix inv() const {\n        matrix ex(height(), width() << 1);\n\
    \        for (int i : rep(height())) {\n            for (int j : rep(width()))\
    \ { ex[i][j] = val[i][j]; }\n        }\n        for (int i : rep(height())) ex[i][width()\
    \ + i] = S::one();\n        matrix ut = ex.upper_triangular();\n        for (int\
    \ i : per(height())) {\n            ut.row_add(i, i, S::one() / ut[i][i] - S::one());\n\
    \            for (int j : rep(i)) ut.row_add(j, i, -ut[j][i] / ut[i][i]);\n  \
    \      }\n        matrix ret(height(), width());\n        for (int i : rep(height()))\
    \ {\n            for (int j : rep(width())) { ret[i][j] = ut[i][width() + j];\
    \ }\n        }\n        return ret;\n    }\n    matrix pow(ll k) const {\n   \
    \     matrix ret = matrix::id(height()), mul(*this);\n        while (k) {\n  \
    \          if (k & 1) ret *= mul;\n            mul *= mul;\n            k >>=\
    \ 1;\n        }\n        return ret;\n    }\n    matrix &operator+=(const matrix\
    \ &a) {\n        for (int i : rep(height())) {\n            for (int j : rep(width()))\
    \ { val[i][j] += a[i][j]; }\n        }\n        return *this;\n    }\n    matrix\
    \ &operator-=(const matrix &a) {\n        for (int i : rep(height())) {\n    \
    \        for (int j : rep(width())) { val[i][j] -= a[i][j]; }\n        }\n   \
    \     return *this;\n    }\n    matrix &operator*=(const matrix &a) {\n      \
    \  matrix res(height(), a.width());\n        for (int i : rep(height())) {\n \
    \           for (int j : rep(a.width())) {\n                for (int k : rep(width()))\
    \ { res[i][j] += val[i][k] * a[k][j]; }\n            }\n        }\n        val.swap(res.val);\n\
    \        return *this;\n    }\n    matrix &operator/=(const matrix &a) { return\
    \ *this *= a.inv(); }\n    bool operator==(const matrix &a) const { return val\
    \ == a.val; }\n    bool operator!=(const matrix &a) const { return rel_ops::operator!=(*this,\
    \ a); }\n    matrix operator+() const { return *this; }\n    matrix operator-()\
    \ const { return matrix(height(), width()) -= *this; }\n    matrix operator+(const\
    \ matrix &a) const { return matrix(*this) += a; }\n    matrix operator-(const\
    \ matrix &a) const { return matrix(*this) -= a; }\n    matrix operator*(const\
    \ matrix &a) const { return matrix(*this) *= a; }\n    matrix operator/(const\
    \ matrix &a) const { return matrix(*this) /= a; }\n};\n\nstruct double_field {\n\
    \    using V = double;\n    static V zero() { return 0.0; }\n    static V one()\
    \ { return 1.0; }\n};\n\ntemplate <> bool matrix<double_field>::place_nonzero(int\
    \ i, int j) {\n    static constexpr double EPS = 1e-12;\n    for (int k : rep(i\
    \ + 1, height())) {\n        if (abs(val[k][j]) > abs(val[i][j])) {\n        \
    \    swap(val[i], val[k]);\n            row_add(i, i, -2.0);\n        }\n    }\n\
    \    return abs(val[i][j]) > EPS;\n}\n#line 2 \"math/modint.hpp\"\n\n#line 4 \"\
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
    #line 4 \"test/judge.yosupo.jp/Determinant_of_Matrix.0.test.cpp\"\n\nint main()\
    \ {\n    using mint = modint998244353;\n    struct mint_field {\n        using\
    \ V = mint;\n        static V zero() { return 0; }\n        static V one() { return\
    \ 1; }\n    };\n    ll n;\n    cin >> n;\n    matrix<mint_field> a(n, n);\n  \
    \  for (ll i : rep(n)) {\n        for (ll j : rep(n)) { cin >> a[i][j]; }\n  \
    \  }\n    cout << a.det() << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n#include\
    \ \"../../math/matrix.hpp\"\n#include \"../../math/modint.hpp\"\n\nint main()\
    \ {\n    using mint = modint998244353;\n    struct mint_field {\n        using\
    \ V = mint;\n        static V zero() { return 0; }\n        static V one() { return\
    \ 1; }\n    };\n    ll n;\n    cin >> n;\n    matrix<mint_field> a(n, n);\n  \
    \  for (ll i : rep(n)) {\n        for (ll j : rep(n)) { cin >> a[i][j]; }\n  \
    \  }\n    cout << a.det() << endl;\n}"
  dependsOn:
  - math/matrix.hpp
  - template.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/judge.yosupo.jp/Determinant_of_Matrix.0.test.cpp
  requiredBy: []
  timestamp: '2022-10-20 00:25:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/judge.yosupo.jp/Determinant_of_Matrix.0.test.cpp
layout: document
redirect_from:
- /verify/test/judge.yosupo.jp/Determinant_of_Matrix.0.test.cpp
- /verify/test/judge.yosupo.jp/Determinant_of_Matrix.0.test.cpp.html
title: test/judge.yosupo.jp/Determinant_of_Matrix.0.test.cpp
---
