---
title: 遅延評価 Segment Tree
documentation_of: //data_structure/lazy_segtree.hpp
---

# 概要
- モノイド$V$と作用素モノイド$F$
- $f(v_0 \times v_1) = f(v_0) \times f(v_1)$
- $f(g(v)) = f \circ g(v)$
- 長さ $n$ の $V$ の元の列 $s$ に対する処理を行う

# テンプレート引数
以下のメンバを持つ構造体を与える。

## $\mathrm{val\,t}$
$V$ を表す型。

## $\mathrm{fn\,t}$
$F$ を表す型。

## $\mathrm{op}(a, b)$
$a \times b$ を返す。

## $\mathrm{e}()$
$V$の単位元 $\mathrm{e}$ を返す。

## $\mathrm{mapping}(f, a)$
$f(a)$ を返す。

## $\mathrm{composition}(f, g)$
$f \circ g$ を返す。

## $\mathrm{id}()$
$F$ の単位元 $\mathrm{id}$ を返す。

# メンバ
## $\mathrm{set}(i, a)$
要素 $i$ を $a$ に置き換える。

### 制約
- $0 \leq i < n$

### 計算量
- $O(\log n)$  

## $\mathrm{apply}(l, r, f)$
時間計算量: $O(log n)$
$s_l, \cdots s_{r-1}$ に $f$ を作用させる。

### 制約
- $0 \leq l \leq r \leq n$

### 計算量
- $O(\log n)$

## $\mathrm{get}(i)$
$i$ 番目の要素を得る。

### 制約
- $0 \leq i < n$

### 計算量
- $O(\log n)$

## `prod(l, r)`
$\mathrm{e} \times s_l \times \cdots \times s_{r-1}$ を計算する。

### 制約
- $0 \leq l \leq r \leq n$

### 計算量
- $O(\log n)$

## $\mathrm{max\,right}(l, g)$
- $g(\mathrm{prod}(l, r))$
- $r = n \lor g(\mathrm{prod}(l, r + 1))$

を満たす $r$ をいずれか一つ返す。

### 制約
- $g(\mathrm{e})$
- $0 \leq l \leq n$

### 計算量
- $O(\log n)$

## $\mathrm{min\,left}(r, g)$
- $g(\mathrm{prod}(l, r))$
- $l = 0 \lor g(\mathrm{prod}(l - 1, r))$

を満たす $l$ をいずれか一つ返す。

### 制約
- $g(\mathrm{e})$
- $0 \leq r \leq n$

### 計算量
- $O(\log n)$