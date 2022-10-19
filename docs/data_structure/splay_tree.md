---
title: Splay Tree
documentation_of: //data_structure/splay_tree.hpp
---

## 概要
- 平衡二分木の一種で、挿入、削除、分割、連結などが高速に行える列として用いる。

## 詳細
- `<typename T> struct splay_tree`  
    Splay Tree 本体。

    - `typename T`  
        テンプレート引数として与える、要素の型。

    - `int size()`  
        要素数 $n$ を取得する。

    - `T &operator[](int i)`  
        $i$ 番目の要素を取得する。 ならし $O(\log n)$ 時間。

    - `<typename F> int lower_bound(F f)`  
        述語 $f$ について、
        - $f([i])$
        - $i = 0 \lor \lnot f([i - 1])$

        を共に満たす $i$ をいずれか一つ返す。 ならし $O(\log n)$ 時間。

    - `splay_tree split(int size_left)`  
        先頭 $size\,left$ 要素だけを残してそれ以降を切り離し、新たな `splay_tree` として取得する。 ならし $O(\log n)$ 時間。

    - `void merge(splay_tree right)`  
        $right$ を右側に連結する。 $right$ はそれ以降単体で使用してはならない。 ならし $O(\log n)$ 時間。

    - `void insert(int i, T val)`  
        先頭から $i$ 番目となるよう $val$ を挿入する。 ならし $O(\log n)$ 時間。

    - `void erase(int i)`  
        要素 $i$ を削除する。 ならし $O(\log n)$ 時間。

## 備考
- ちゃんとデストラクタを書きたい

## 参考
- [かつっぱさんの動画](https://www.youtube.com/watch?v=M6LcINhgXeM&t=0s)