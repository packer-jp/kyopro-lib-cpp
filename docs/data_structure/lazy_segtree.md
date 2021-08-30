---
title: 遅延評価 Segment Tree
documentation_of: //data_structure/lazy_segtree.hpp
---

# 概要
- モノイド$V$と作用素モノイド$F$
- $f(v_0 \times v_1) = f(v_0) \times f(v_1)$
- $f(g(v)) = f \circ g(v)$
- 長さ$n$の$V$の元の列に対する処理を行う

## メンバ
- $set(i, a)$  
時間計算量: $O(log n)$  
要素$i$を$a$に置き換える。

- $apply(l, r, f)$
時間計算量: $O(log n)$
要素列$[l, r)$に$f$を$mapping$する。

- $get(i)$
$i$番目の要素を得る。

- $prod(l, r)$
要素列$[l, r)$について、順序を変えずに$op$したものを返す。

## `max_right`$(`l`, `g`)$

$\lor g(prod())$

## $min\_left(r, g)$