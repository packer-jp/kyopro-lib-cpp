---
title: 行列
documentation_of: //math/matrix.hpp
---

# 概要
- 集合 $V$ について定めた代数的構造を載せた $n \times m$ 行列に関する各種演算をサポートする。

# 詳細
- `<typename S> struct matrix`  
    行列本体。

    - `typename S`  
        テンプレート引数として与える構造体。

        - `using val_t`  
            $V$ を表す型。各種演算、比較、複合代入をサポートする必要がある。

        - `val_t zero()`  
            加法単位元 $0$ を返す。
        
        - `val_t one()`  
            乗法単位元 $1$ を返す。

    - `using V`  
        $V$ を表す型。

    - `(constructor)(int n, int m)`  
        大きさ $n \times m$ 、全要素 $\mathrm{0}$ で初期化。

    - `(constructor)(vector<vector<V>> src)`  
        $src$ で初期化。

    - 要素アクセス  
        二次元配列のように、`[]`演算子を用いて行う。

    - `int height()`  
        高さ $n$ を返す。

    - `int width()`  
        幅 $m$ を返す。

    - `static matrix id(int n)`  
        $n \times n$ の単位行列を返す。

    - `V det()`  
        行列式を返す。定義に従った計算ではなく、上三角化を経由する関係上、`V` の除法を要請する。 $O(n^3)$ 時間。

    - `matrix inv()`  
        逆行列を返す。正則でない場合の動作は未定義。 $O(n^3)$ 時間。

    - `matrix pow(ll k)`  
        $k$ 乗した結果を返す。`V`が半環 (加法について可換モノイド、乗法についてモノイド、分配的、加法単位元は乗法吸収元) であることを要請する。 $O(n^3 \log k)$ 時間。

    - 四則演算、比較、複合代入

- `struct double_field`  
    実数体を載せるときに`matrix`にテンプレート引数 `S` として与える。誤差周りの事情から、特殊化を行っている。