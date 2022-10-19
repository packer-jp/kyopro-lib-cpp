---
title: HL 分解
documentation_of: //graph/hld.hpp
---

## 概要
- HL 分解を用いて木をパスに分解する。

## 詳細

- `struct hld`  
    HL 分解を行う構造体。

    - `(constructor)(int n)`  
        頂点数 $n$ で初期化。

    - `void add_edge(int u, int v)`  
        頂点 $u, v$ 間に辺を張る。

    - `vector<int> build(int root)`  
        頂点 $root$ を根として初期化し、各頂点の別の番号の `vector` を返す。 $O(n)$ 時間。

    - `int lca(int u, int v)`  
        頂点 $u, v$ の LCA の番号を返す。 $O(\log n)$ 時間。
    
    - `int get_path(int u, int v, bool edge)`  
        頂点属性のクエリの場合、頂点 $u, v$ 間のパスを $O(\log n)$ 個に分解し、「「新たな番号での始点、終点 (閉区間) を表す `pair`」 の `vector`」を返す。辺属性のクエリの場合もほぼ同様だが、こちらの場合は新たな頂点番号について、その頂点の親に繋がる辺という意味になる。

    - `pair<int, int> get_subtree(int v, bool edge)`  
        頂点 $v$ の部分木を $1$ 個の区間として返す。

## 備考
- 雑なのでまたちゃんと書く

## 参考
- [adamant さんの Codeforces blog](https://codeforces.com/blog/entry/53170)