---
title: 二分探索
documentation_of: //util/bisect.hpp
---

# 概要
二分探索を用いて、述語の成立 / 不成立の境界値を計算する。

# 詳細
- `<typename F> bisect(ll ok, ll ng, F f)`  
    $f(ok)\land \lnot f(ng)$ とする。 $f$ が成立し、 $ng$ 側に $1$ 動かすと成立しなくなるような整数を一つ返す。 $O(\log |ok - ng|)$ 時間。

- `<typename F> continuous_bisect(double ok, double ng, F f, int n)`  
    $f(ok), \lnot f(ng)$ とする。 $f$ が成立し、 $ng$ 側に微小量動かすと成立しなくなるような実数を一つ返す。精度は $\frac{|ok - ng|}{2^n}$ 。 $O(n)$ 時間。

# 参考
- [因幡めぐるさんのツイート](https://twitter.com/meguru_comp/status/697008509376835584)