#pragma once

#include <bits/stdc++.h>
using namespace std;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define uniq(a) (a).erase(unique(all(a)), (a).end())
#define SZ(x) int((x).size())
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define vsum(x) reduce(all(x))
#define vmax(a) *max_element(all(a))
#define vmin(a) *min_element(all(a))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define mp make_pair
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vi = vector<int>;
using Vl = vector<ll>;
using Vc = vector<char>;
using VVi = vector<vector<int>>;
using VVl = vector<vector<ll>>;
using VVc = vector<vector<char>>;
template <typename T, typename U> using P = pair<T, U>;
template <typename T> using V = vector<T>;
template <typename T> using VV = V<V<T>>;
constexpr ll inf = 1000000000ll;
constexpr ll INF = 4000000004000000000LL;
constexpr ld eps = 1e-15;
constexpr ld PI = 3.141592653589793;
constexpr int popcnt(ull x) { return __builtin_popcountll(x); }
template <typename T> using mat = vector<vector<T>>;
constexpr ll dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr ll dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr ll sign(ll a) { return (a > 0) - (a < 0); }
constexpr ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
constexpr ll cdiv(ll a, ll b) { return -fdiv(-a, b); }
constexpr ull bit(int n) { return 1ull << n; }
template <typename T> constexpr T mypow(T x, ll n) {
    T ret = 1;
    while (n) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}
constexpr ll modpow(ll x, ll n, ll mod) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
        x %= mod;
        ret %= mod;
    }
    return ret;
}
template <typename T> T xor64(T lb, T ub) {
    static ull x = 88172645463325252ull;
    x ^= x << 7;
    return lb + (x ^= x >> 9) % (ub - lb);
}
constexpr ll safemod(ll x, ll mod) { return (x % mod + mod) % mod; }
template <typename T> constexpr T sq(const T &a) { return a * a; }
template <typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
template <typename T, typename U> bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <typename T, typename U> bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &a) {
    os << "(" << a.first << ", " << a.second << ")";
    return os;
}
template <typename T, typename U, typename V> ostream &operator<<(ostream &os, const tuple<T, U, V> &a) {
    os << "(" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : "");
    os << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : "");
    os << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : "");
    os << ")";
    return os;
}
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : "");
    os << ")";
    return os;
}
template <typename T> void print(const T &a) { cout << a << endl; }
template <typename T> void print(const vector<T> &v) {
    for (auto &e : v) cout << e << " ";
    cout << endl;
}
template <typename T> void scan(vector<T> &a) {
    for (auto &i : a) cin >> i;
}
struct timer {
    clock_t start_time;
    void start() { start_time = clock(); }
    int lap() {
        // return x ms.
        return (clock() - start_time) * 1000 / CLOCKS_PER_SEC;
    }
};
template <typename T = int> struct Edge {
    int from, to;
    T cost;
    int idx;

    Edge() = default;

    Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

    operator int() const { return to; }
};
template <typename T = int> struct Graph {
    vector<vector<Edge<T>>> g;
    int es;

    Graph() = default;

    explicit Graph(int n) : g(n), es(0) {}

    size_t size() const { return g.size(); }

    void add_directed_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es++); }

    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a += padding;
            b += padding;
            T c = T(1);
            if (weighted) cin >> c;
            if (directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }
};
#ifdef ONLINE_JUDGE
#define dump(...) (void(0))
#else
void debug() { cerr << endl; }
template <typename Head, typename... Tail> void debug(Head &&head, Tail &&... tail) {
    cerr << head;
    if (sizeof...(Tail)) cerr << ", ";
    debug(tail...);
}
#define dump(...) cerr << __LINE__ << ": " << #__VA_ARGS__ << " = ", debug(__VA_ARGS__)
#endif
struct rep {
    struct itr {
        ll v;
        itr(ll v) : v(v) {}
        void operator++() { ++v; }
        ll operator*() const { return v; }
        bool operator!=(itr i) const { return v < *i; }
    };
    ll l, r;
    rep(ll l, ll r) : l(l), r(r) {}
    rep(ll r) : rep(0, r) {}
    itr begin() const { return l; };
    itr end() const { return r; };
};
struct per {
    struct itr {
        ll v;
        itr(ll v) : v(v) {}
        void operator++() { --v; }
        ll operator*() const { return v; }
        bool operator!=(itr i) const { return v > *i; }
    };
    ll l, r;
    per(ll l, ll r) : l(l), r(r) {}
    per(ll r) : per(0, r) {}
    itr begin() const { return r - 1; };
    itr end() const { return l - 1; };
};
struct io_setup {
    static constexpr int PREC = 20;
    io_setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} iOS;