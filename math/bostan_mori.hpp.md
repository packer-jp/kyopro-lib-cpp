---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution.hpp
    title: "\u7573\u307F\u8FBC\u307F"
  - icon: ':question:'
    path: math/fps.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: math/modint.hpp
    title: modint
  - icon: ':question:'
    path: math/ntt.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/kth_of_lrs.hpp
    title: math/kth_of_lrs.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/judge.yosupo.jp/Kth_Term_of_Linearly_Recurrent_Sequence.0.test.cpp
    title: test/judge.yosupo.jp/Kth_Term_of_Linearly_Recurrent_Sequence.0.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/bostan_mori.hpp\"\n\n#line 2 \"template.hpp\"\n\n#include\
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
    \        cerr << fixed << setprecision(PREC);\n    };\n} iOS;\n#line 2 \"math/fps.hpp\"\
    \n\n#line 2 \"math/convolution.hpp\"\n\n#line 2 \"math/ntt.hpp\"\n\n#line 4 \"\
    math/ntt.hpp\"\n\ntemplate <typename mint> void ntt(vector<mint> &a, bool inv\
    \ = false) {\n    ll n = a.size(), m = n >> 1;\n    mint root = 2;\n    while\
    \ (root.pow((mint::mod() - 1) >> 1) == 1) root += 1;\n    mint wn = root.pow((mint::mod()\
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
    #line 6 \"math/fps.hpp\"\n\ntemplate <typename mint> struct fps : vector<mint>\
    \ {\n    using vector<mint>::vector;\n    using vector<mint>::operator=;\n   \
    \ fps() : vector<mint>() {}\n    fps(const mint &a) : vector<mint>(1, a) {}\n\
    \    fps(const vector<mint> &a) : vector<mint>(a) {}\n    fps(const fps &a) :\
    \ vector<mint>(a) {}\n    fps &operator=(const fps &a) {\n        *this = (vector<mint>)a;\n\
    \        return *this;\n    }\n    fps &operator+=(const fps &a) {\n        if\
    \ (a.size() > this->size()) this->resize(a.size());\n        for (ll i : rep(a.size()))\
    \ (*this)[i] += a[i];\n        return *this;\n    }\n    fps &operator-=(const\
    \ fps &a) {\n        if (a.size() > this->size()) this->resize(a.size());\n  \
    \      for (ll i : rep(a.size())) (*this)[i] -= a[i];\n        return *this;\n\
    \    }\n    fps &operator*=(const fps &a);\n    fps &operator/=(const mint &a)\
    \ {\n        for (ll i : rep(this->size())) (*this)[i] /= a;\n        return *this;\n\
    \    };\n    fps &operator>>=(ll d) {\n        if ((ll)this->size() <= d) {\n\
    \            *this = {};\n        } else {\n            this->erase(this->begin(),\
    \ this->begin() + d);\n        }\n        return *this;\n    }\n    fps &operator<<=(ll\
    \ d) {\n        this->insert(this->begin(), d, 0);\n        return *this;\n  \
    \  }\n    fps &chdot(const fps &a) {\n        for (ll i : rep(this->size())) {\n\
    \            if (i < (ll)a.size()) {\n                (*this)[i] *= a[i];\n  \
    \          } else {\n                (*this)[i] = 0;\n            }\n        }\n\
    \        return *this;\n    }\n    fps prefix(ll d) const { return fps(this->begin(),\
    \ this->begin() + min((ll)this->size(), d)); }\n    fps differential() const {\n\
    \        ll n = this->size();\n        fps ret(max(0ll, n - 1));\n        for\
    \ (ll i : rep(1, n)) { ret[i - 1] = i * (*this)[i]; }\n        return ret;\n \
    \   }\n    fps integral() const {\n        ll n = this->size();\n        fps ret(n\
    \ + 1);\n        ret[0] = 0;\n        if (n > 0) ret[1] = 1;\n        for (ll\
    \ i : rep(2, n + 1)) ret[i] = (-ret[mint::mod() % i]) * (mint::mod() / i);\n \
    \       for (ll i : rep(n)) ret[i + 1] *= (*this)[i];\n        return ret;\n \
    \   }\n    fps inv(ll d) const {\n        fps ret{(*this)[0].inv()};\n       \
    \ for (ll m = 1; m < d; m <<= 1) ret = (ret + ret - ret * ret * this->prefix(m\
    \ << 1)).prefix(m << 1);\n        return ret.prefix(d);\n    }\n    fps log(ll\
    \ d) const {\n        assert((*this)[0] == 1);\n        return (this->differential()\
    \ * this->inv(d)).prefix(d - 1).integral();\n    }\n    fps exp(ll d) const {\n\
    \        assert(this->size() == 0 || (*this)[0] == 0);\n        fps ret{1};\n\
    \        for (ll m = 1; m < d; m <<= 1) ret = (ret * (this->prefix(m << 1) + 1\
    \ - ret.log(m << 1))).prefix(m << 1);\n        return ret.prefix(d);\n    }\n\
    \    fps pow(ll k, ll d) const {\n        if (k == 0) {\n            fps ret(d);\n\
    \            if (d) ret[0] = 1;\n            return ret;\n        }\n        for\
    \ (ll i : rep(this->size())) {\n            if ((*this)[i] != 0) {\n         \
    \       if (i > d / k) return fps(d);\n                fps ret = (((*this * (*this)[i].inv())\
    \ >> i).log(d) * mint(k)).exp(d) * (*this)[i].pow(k);\n                ret = (ret\
    \ << (i * k)).prefix(d);\n                ret.resize(d);\n                return\
    \ ret;\n            }\n        }\n        return fps(d);\n    }\n    friend fps\
    \ operator+(const fps &a) { return a; }\n    friend fps operator-(const fps &a)\
    \ { return fps() -= a; }\n    friend fps operator+(const fps &a, const fps &b)\
    \ { return fps(a) += b; }\n    friend fps operator-(const fps &a, const fps &b)\
    \ { return fps(a) -= b; }\n    friend fps operator*(const fps &a, const fps &b)\
    \ { return fps(a) *= b; }\n    friend fps operator>>(const fps &a, ll d) { return\
    \ fps(a) >>= d; }\n    friend fps operator<<(const fps &a, ll d) { return fps(a)\
    \ <<= d; }\n};\n\nusing m9 = modint998244353;\n\ntemplate <> fps<m9> &fps<m9>::operator*=(const\
    \ fps<m9> &a) {\n    *this = convolution(*this, a);\n    return *this;\n}\n\n\
    template <> fps<m9> fps<m9>::inv(ll d) const {\n    fps ret{(*this)[0].inv()};\n\
    \    for (ll m = 1; m < d; m <<= 1) {\n        fps f = this->prefix(m << 1);\n\
    \        fps g = ret;\n        f.resize(m << 1), ntt(f);\n        g.resize(m <<\
    \ 1), ntt(g);\n        f.chdot(g);\n        intt(f);\n        f >>= m, f.resize(m\
    \ << 1), ntt(f);\n        f.chdot(g);\n        intt(f);\n        f = -f;\n   \
    \     ret.insert(ret.end(), f.begin(), f.begin() + m);\n    }\n    return ret.prefix(d);\n\
    }\n\ntemplate <> fps<m9> fps<m9>::exp(ll d) const {\n    assert(this->size() ==\
    \ 0 || (*this)[0] == 0);\n    fps ret{1}, g{1}, g_freq{1};\n    for (ll m = 1;\
    \ m < d; m <<= 1) {\n        fps ret_freq = ret.prefix(m);\n        ret_freq.resize(m\
    \ << 1), ntt(ret_freq);\n\n        fps g_cont = g_freq;\n        for (ll i : rep(m))\
    \ g_cont[i] *= ret_freq[i << 1];\n        intt(g_cont);\n        g_cont >>= m\
    \ >> 1;\n        g_cont.resize(m), ntt(g_cont);\n        g_cont.chdot(g_freq);\n\
    \        intt(g_cont);\n        g_cont = -g_cont;\n        g.insert(g.end(), g_cont.begin(),\
    \ g_cont.begin() + (m >> 1));\n\n        fps r = this->differential().prefix(m\
    \ - 1);\n        r.resize(m), ntt(r);\n        for (ll i : rep(m)) r[i] *= ret_freq[i\
    \ << 1];\n        intt(r);\n\n        fps t = ret.differential() - r;\n      \
    \  t.insert(t.begin(), t.back()), t.pop_back();\n        t.resize(m << 1), ntt(t);\n\
    \        g_freq = g, g_freq.resize(m << 1), ntt(g_freq);\n        t.chdot(g_freq);\n\
    \        intt(t), t.resize(m);\n\n        fps u = (this->prefix(m << 1) - (t <<\
    \ m - 1).integral()) >> m;\n        u.resize(m << 1), ntt(u);\n        u.chdot(ret_freq);\n\
    \        intt(u);\n\n        ret += u.prefix(m) << m;\n    }\n    return ret.prefix(d);\n\
    }\n#line 5 \"math/bostan_mori.hpp\"\n\ntemplate <typename V> V bostan_mori(fps<V>\
    \ p, fps<V> q, ll k) {\n    while (k) {\n        fps<V> _q(q);\n        for (ll\
    \ i = 1; i < _q.size(); i += 2) _q[i] = -_q[i];\n        fps<V> u = p * _q, v\
    \ = q * _q;\n        p.resize((u.size() >> 1) + (u.size() & ~k & 1)), q.resize((v.size()\
    \ >> 1) + 1);\n        for (ll i : rep(p.size())) p[i] = u[i << 1 | (k & 1)];\n\
    \        for (ll i : rep(q.size())) q[i] = v[i << 1];\n        k >>= 1;\n    }\n\
    \    return p[0];\n}\n"
  code: "#pragma once\n\n#include \"../template.hpp\"\n#include \"fps.hpp\"\n\ntemplate\
    \ <typename V> V bostan_mori(fps<V> p, fps<V> q, ll k) {\n    while (k) {\n  \
    \      fps<V> _q(q);\n        for (ll i = 1; i < _q.size(); i += 2) _q[i] = -_q[i];\n\
    \        fps<V> u = p * _q, v = q * _q;\n        p.resize((u.size() >> 1) + (u.size()\
    \ & ~k & 1)), q.resize((v.size() >> 1) + 1);\n        for (ll i : rep(p.size()))\
    \ p[i] = u[i << 1 | (k & 1)];\n        for (ll i : rep(q.size())) q[i] = v[i <<\
    \ 1];\n        k >>= 1;\n    }\n    return p[0];\n}"
  dependsOn:
  - template.hpp
  - math/fps.hpp
  - math/convolution.hpp
  - math/ntt.hpp
  - math/modint.hpp
  isVerificationFile: false
  path: math/bostan_mori.hpp
  requiredBy:
  - math/kth_of_lrs.hpp
  timestamp: '2022-10-19 16:09:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/judge.yosupo.jp/Kth_Term_of_Linearly_Recurrent_Sequence.0.test.cpp
documentation_of: math/bostan_mori.hpp
layout: document
redirect_from:
- /library/math/bostan_mori.hpp
- /library/math/bostan_mori.hpp.html
title: math/bostan_mori.hpp
---
