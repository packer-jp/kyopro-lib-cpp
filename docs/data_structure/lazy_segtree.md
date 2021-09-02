---
title: 遅延評価 Segment Tree
documentation_of: //data_structure/lazy_segtree.hpp
---

# 概要
- $v, w \in V$ および $f, g \in F$ として、以下の条件を満たすモノイド $(V, \times)$ と作用素モノイド $(F, \circ)$ を考える。
    - $f(v \times w) = f(v) \times f(w)$
    - $f(g(v)) = f \circ g(v)$
- 長さ $n$ の $V$ の元の列 $s$ に対する処理を行う。

# 詳細
- `<typename S> struct lazy_segtree`  
    遅延評価 Segment Tree 本体。

    - `typename S`  
        テンプレート引数として与える構造体。

        - `using val_t`  
            $V$ を表す型。

        - `using fn_t`  
            $F$ を表す型。

        - `static val_t op(val_t a, val_t b)`  
            $a \times b$ を返す。
        
        - `static val_t e()`  
            $(V, \times)$ の単位元 $\mathrm{e}$ を返す。

        - `static val_t mapping(fn_t f, val_t a)`  
            $f(a)$ を返す。

        - `static fn_t composition(fn_t f, fn_t g)`  
            $f \circ g$ を返す。

        - `static fn_t id()`  
            $(F, \circ)$ の単位元 $\mathrm{id}$ を返す。

    - `using V`  
        $V$ を表す型。

    - `using F`  
        $F$ を表す型。

    - `(constructor)(int n)`  
        長さ $n$ 、全要素 $\mathrm{e}$ で初期化。

    - `(constructor)(vector<V> src)`  
        $s := src$ として初期化。

    - `void set(int i, V a)`  
        要素 $i$ を $a$ に置き換える。$O(\log n)$ 時間。

    - `void apply(int l, int r, F f)`  
        $s_l, \cdots s_{r-1}$ に $f$ を作用させる。 $O(\log n)$ 時間。

    - `V get(int i)`  
        $i$ 番目の要素を得る。 $O(\log n)$ 時間。
    
    - `V prod(int l, int r)`  
        $\mathrm{e} \times s_l \times \cdots \times s_{r-1}$ を計算する。 $O(\log n)$ 時間。

    - `<typename G> max_right(int l, G g)`  
        述語 $g$ について、
        - $g(\mathrm{prod}(l, r))$
        - $r = n \lor \lnot g(\mathrm{prod}(l, r + 1))$

        を共に満たす $r$ をいずれか一つ返す。 $O(\log n)$ 時間。 $g(\mathrm{e})$ を要請。


    - `<typename G> int min_left(int r, G g)`  
        述語 $g$ について、
        - $g(\mathrm{prod}(l, r))$
        - $l = 0 \lor \lnot g(\mathrm{prod}(l - 1, r))$

        を共に満たす $l$ をいずれか一つ返す。 $O(\log n)$ 時間。 $g(\mathrm{e})$ を要請。

- `struct min_monoid_with_addition`  
    区間最小/区間可算クエリを処理するときに`lazy_segtree`にテンプレート引数 `S` として与える。

- `struct min_monoid_with_update`  
    区間最小/区間更新クエリを処理するときに`lazy_segtree`にテンプレート引数 `S` として与える。

- `struct sum_monoid_with_addition`  
    区間和/区間可算クエリを処理するときに`lazy_segtree`にテンプレート引数 `S` として与える。

- `struct sum_monoid_with_update`  
    区間和/区間更新クエリを処理するときに`lazy_segtree`にテンプレート引数 `S` として与える。

# 参考
- [ACL](https://atcoder.github.io/ac-library/production/document_ja/lazysegtree.html)
- [Nyaan さんのライブラリ](https://nyaannyaan.github.io/library/segment-tree/lazy-segment-tree-utility.hpp)