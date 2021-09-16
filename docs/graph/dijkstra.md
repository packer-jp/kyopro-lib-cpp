---
title: Dijkstra 法
documentation_of: //graph/dijkstra.hpp
---

## 概要
Dijkstra 法を用いて、負辺のない有向グラフ上の単一始点最短路を求める。

## 詳細

- `<typename S> struct dijkstra`  
    Dijkstra 法を用いて単一始点最短路を求める構造体。

    - `typename S`  
        テンプレート引数として与える構造体。

        - `using dist_t`  
            各頂点の距離を表す型。

        - `using cost_t`
            各辺のコストを表す型。

        - `static dist_t inf()`  
            `dist_t` の最大元を返す。

    - `(constructor)(int n)`  
        頂点数 $n$ で初期化。

    - `void add_edge(int from, int to, S::cost_t cost)`  
        頂点 `from` から頂点 `to` にコスト `cost` の辺を張る。

    - `pair<vector<S::dist_t>, vector<int>> get(int s, S::dist_t base = S::dist_t())`  
        頂点 `s` の距離を `base` と定め、「「各頂点の距離の `vector`」 と「最短路の一つにおいて各頂点の直前に訪れる頂点番号の `vector`」 の `pair`」を取得する。 $O((n + m) \log n)$ 時間。


- `struct ll_dijkstra`  
    距離やコストが `ll` 型であるような「普通の」最短路問題を解くときに`dijkstra`にテンプレート引数 `S` として与える。