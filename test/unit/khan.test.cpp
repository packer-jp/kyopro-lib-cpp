#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja"
#include "../../graph/khan.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    constexpr int n = 20, v = 100, e = 1000;
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> uid(0, v - 1);
    for (ll i : rep(n)) {
        khan khan(v);
        bool used[v][v] = {};
        int src[v];
        for (ll i : rep(v)) { src[i] = i; }
        shuffle(src, src + n, mt);
        for (ll j : rep(e)) {
            int u = uid(mt), v = uid(mt);
            if (used[u][v]) { continue; }
            if (src[u] < src[v]) {
                khan.add_edge(u, v);
                used[u][v] = true;
            }
        }
        vll sorted = khan.get();
        // shuffle(sorted.begin(), sorted.end(), mt);
        for (ll j : rep(v)) {
            for (ll k : rep(j + 1, v)) { assert(!used[sorted[k]][sorted[j]]); }
        }
    }

    cout << "Hello World" << endl;
}