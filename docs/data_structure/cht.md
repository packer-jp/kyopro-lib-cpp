---
title: Convex Hull Trick
documentation_of: //data_structure/cht.hpp
---

## 概要
以下の二種類のクエリを処理する。
- 座標平面 $V \times V$ 上の直線 $y=ax+b$ を集合 $L$ に追加する。
- $x=c$ において $L$ 内の直線がとる $y$ の最小値を答える。

## 詳細
- `<typename S, bool MIN> struct cht`  
    Convex Hull Trick を用いてクエリを処理するデータ構造本体。

    - `typename S`  
        テンプレート引数として与える構造体。

        - `using val_t`  
            $V$ を表す型。

        - `static val_t div(val_t num, val_t den)`  
            $V$ 内で $den \times x \leq num$ となる最大の $x$ を返す。整数なら切り捨て除算、実数なら単なる除算に相当する。

        - `static val_t inf()`  
            $V$ の最大元を返す。

    - `using V`  
        $V$ を表す型。

    - `void add(V a, V b)`  
        直線 $y=ax+b$ を集合 $L$ に追加する。

    - `V get(V c)`  
        $x=c$ において $L$ 内の直線がとる $y$ の最小値を答える。

## 参考
- [えびちゃんさんのスライド](https://hcpc-hokudai.github.io/archive/algorithm_convex_hull_trick_001.pdf)
- [kactl](https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h)