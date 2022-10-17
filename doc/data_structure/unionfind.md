---
title: Union-Find Tree
documentation_of: //data_structure/uf.hpp
---

## 概要
- $n$ 個の要素をいくつかの素集合に分割したものを考える。はじめは全ての要素がその要素ただ一つを含む集合に属している。以下の二種類のクエリを処理する。
    - 要素 $i$ を含む集合と要素 $j$ を含む集合を併合する。
    - 要素 $i$ を含む集合の代表元を得る。

## 詳細
- `struct uf`  
    Union-Find Tree 本体。

    - `(constructor)(int n)`  
        $n$ 要素で初期化。

    - `int find(int i)`  
        要素 $i$ が属する集合の代表元を取得する。ならし $O(\alpha(n))$ 時間。

    - `int size(int i)`  
        要素 $i$ が属する集合のサイズを取得する。ならし $O(\alpha(n))$ 時間。

    - `bool same(int i, int j)`  
        要素 $i$ と要素 $j$ が同じ集合に含まれるかどうかを判定する。ならし $O(\alpha(n))$ 時間。

    - `void unite(int i, int j)`  
        要素 $i$ を含む集合と要素 $j$ を含む集合を併合する。ならし $O(\alpha(n))$ 時間。

    - `vector<vector<int>> groups()`  
        「「一つの集合に属する要素番号の`vector`」の`vector`」を取得する。 $O(n)$ 時間。

## 参考
- [ACL](https://atcoder.github.io/ac-library/document_ja/dsu.html)