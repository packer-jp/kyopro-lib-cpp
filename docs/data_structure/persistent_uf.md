---
title: 完全永続 Union-Find Tree
documentation_of: //data_structure/persistent_uf.hpp
---

## 概要
- コピー可能な Union-Find Tree。

## 詳細
- `<int SHIFT> struct persistent_uf`  
    完全永続 Union-Find Tree 本体。

    - `int SHIFT`  
        テンプレート引数として与える値。 内部の永続配列を $2^{SHIFT}$ 分木として表現する。実験的には $2$ くらいにするのが良かったが、[熨斗袋さんのツイート](https://twitter.com/noshi91/status/1334461861127839746) によればもう少し大きくしたほうが良いらしい。実装の問題か？

    - `(constructor)(int n)`  
        $n$ 要素で初期化。

    - `int find(int i)`  
        要素 $i$ が属する集合の代表元を取得する。 $O((\log n)^2)$ 時間。

    - `int size(int i)`  
        要素 $i$ が属する集合のサイズを取得する。 $O((\log n)^2)$ 時間。

    - `bool same(int i, int j)`  
        要素 $i$ と要素 $j$ が同じ集合に含まれるかどうかを判定する。

    - `persistent_uf unite(int i, int j)`  
        要素 $i$ を含む集合と要素 $j$ を含む集合が併合された新たな完全永続 Union-Find Tree を返す。 $O((\log n)^2)$ 時間および $O(\log n)$ 空間。

    - `vector<vector<int>> groups()`  
        「「一つの集合に属する要素番号の`vector`」の`vector`」を取得する。 $O(n \log n)$ 時間。

## 参考
- [ACL](https://atcoder.github.io/ac-library/document_ja/dsu.html)
- [Nyaan さんのライブラリ](https://nyaannyaan.github.io/library/data-structure/persistent-union-find.hpp)