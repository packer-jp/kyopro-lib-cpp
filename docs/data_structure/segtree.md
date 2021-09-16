---
title: Segment Tree
documentation_of: //data_structure/segtree.hpp
---

## 概要
- モノイド $(V, \times)$ を考える。
- 長さ $n$ の $V$ の元の列 $s$ に対する処理を行う。

## 詳細

- `<typename S> struct segtree`  
    Segment Tree 本体。

    - `typename S`  
        テンプレート引数として与える構造体。

        - `using val_t`  
            $V$ を表す型。

        - `static val_t op(val_t a, val_t b)`  
            $a \times b$ を返す。
        
        - `static val_t e()`  
            $(V, \times)$ の単位元 $e$ を返す。

    - `using V`  
        $V$ を表す型。

    - `(constructor)(int n)`  
        長さ $n$ 、全要素 $e$ で初期化。

    - `(constructor)(vector<V> src)`  
        $s := src$ として初期化。

    - `void set(int i, V a)`  
        要素 $i$ を $a$ に置き換える。$O(\log n)$ 時間。

    - `V get(int i)`  
        $i$ 番目の要素を得る。 $O(\log n)$ 時間。
    
    - `V prod(int l, int r)`  
        $e \times s_l \times \cdots \times s_{r-1}$ を計算する。 $O(\log n)$ 時間。

    - `<typename G> max_right(int l, G g)`  
        述語 $g$ について、
        - $g(prod(l, r))$
        - $r = n \lor \lnot g(prod(l, r + 1))$

        を共に満たす $r$ をいずれか一つ返す。 $O(\log n)$ 時間。 $g(e)$ を要請。


    - `<typename G> int min_left(int r, G g)`  
        述語 $g$ について、
        - $g(prod(l, r))$
        - $l = 0 \lor \lnot g(prod(l - 1, r))$

        を共に満たす $l$ をいずれか一つ返す。 $O(\log n)$ 時間。 $g(e)$ を要請。

- `struct min_monoid_with_addition`  
    区間最小/一点更新クエリを処理するときに`segtree`にテンプレート引数 `S` として与える。

- `struct sum_monoid_with_update`  
    区間和/一点更新クエリを処理するときに`segtree`にテンプレート引数 `S` として与える。

## 参考
- [ACL](https://atcoder.github.io/ac-library/production/document_ja/segtree.html)
- [えびちゃんさんのスライド](https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf)