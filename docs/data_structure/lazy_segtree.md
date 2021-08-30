---
title: 遅延評価 Segment Tree
documentation_of: //data_structure/lazy_segtree.hpp
---

# 概要
- モノイド$V$と作用素モノイド$F$
- $f(v_0 \times v_1) = f(v_0) \times f(v_1)$
- $f(g(v)) = f \circ g(v)$
- 長さ$n$の$V$の元の列$s$に対する処理を行う

# テンプレート引数
以下のメンバを持つ構造体を与える。

## `val_t`
$V$を表す型。

## `fn_t`
$F$を表す型。

## `val_t op(val_t a, val_t b)`
$a \times b$を返す。

## `val_t e()`
$V$の単位元$\mathrm{e}$を返す。

## `val_t mapping(fn_t f, val_t a)`
$f(a)$を返す。

## `fn_t composition(fn_t f, fn_t g)`
$f \circ g$を返す。

## `fn_t id()`
$F$の単位元$\mathrm{id}$を返す。

# メンバ
## `void set(int i, V a)`
要素$i$を$a$に置き換える。

### 制約
- $0 \leq i < n$

### 計算量
- $O(\log n)$  

## `void apply(int l, int r, F f)`
時間計算量: $O(log n)$
$s_l, \cdots s_{r-1}$に$f$を作用させる。

### 制約
- $0 \leq l \leq r \leq n$

### 計算量
- $O(\log n)$

## `V get(int i)`
$i$番目の要素を得る。

### 制約
- $0 \leq i < n$

### 計算量
- $O(\log n)$

## `prod(l, r)`
$\mathrm{e} \times s_l \times \cdots \times s_{r-1}$を計算する。

### 制約
- $0 \leq l \leq r \leq n$

### 計算量
- $O(\log n)$

## $max right(l, g)$

- $g(\mathrm{prod}(l, r))$
- $g(\mathrm{prod}(l, r + 1)) \lor r = n$

## $min_left(r, g)$