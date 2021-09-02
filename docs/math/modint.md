---
title: modint
documentation_of: //math/modint.hpp
---

# 概要
- $\bmod\,m$ で考えた整数について、各種演算をサポートする。

# 詳細
- `<ll MOD> struct modint`  
    modint 本体。

    - `ll MOD`  
        テンプレート引数として与える法 $m$。

    - `ll val`  
        $\bmod\,m$ で考えたときの値。

    - `static ll mod()`  
        $m$ を返す。

    - `modint inv()`  
        逆元を返す。 $m$ と互いに素である場合に逆元が存在する。 $O(\log m)$ 時間。

    - `modint pow(ll k)`  
        $k$ 乗した結果を返す。 $O(\log k)$ 時間。

    - 四則演算、比較、複合代入

    - `iostream` を用いた入出力


# 参考
- [うしさんのライブラリ](https://ei1333.github.io/library/math/combinatorics/mod-int.cpp)