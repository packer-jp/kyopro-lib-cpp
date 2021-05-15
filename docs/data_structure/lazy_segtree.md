---
title: 遅延評価 Segment Tree
documentation_of: //data_structure/lazy_segtree.hpp
---

- モノイド$V$と作用素モノイド$F$
- $mapping(op(v_0, v_1)) = op(mapping(v_0), mapping(v_1)))$
- $mapping(f_0, mapping(f_1, v)) = mapping(composition(f_0, f_1), v)$
- 長さ$n$の$V$の元の列に対する処理を行う
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

- $max\_right(l, g)$

- $min\_left(r, g)$