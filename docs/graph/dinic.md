---
title: Dinic 法
documentation_of: //graph/dinic.hpp
---

## 概要
- Dinic 法を用いて、最大フロー問題を解く。

## 詳細

- `<typename S> struct dinic`  
    Dinic 法を用いて最大フローを求める構造体。

    - `typename S`  
        テンプレート引数として与える構造体。

        - `using cap_t`  
            各頂点の距離を表す型。

        - `static cap_t zero()`  
            `cap_t` の零元を返す。

        - `static cap_t inf()`  
            `cap_t` の最大元を返す。

    - `(constructor)(int n)`  
        頂点数 $n$ で初期化。

    - `int add_edge(int from, int to, S::cap_t cap)`  
        頂点 $from$ から頂点 $to$ に容量 $cap$ の辺を張り、辺番号を返す。$0 \leq cap$ を要求。

    - `void change_edge(int i, S::cap_t new_cap, S::cap_t new_flow)`  
        辺 $i$ の容量を $new\,cap$ に、流量を $new\,flow$ に変更する。$0 \leq new\,flow \leq new\,cap$ を要求。

    - `S::cap_t flow(int s, int t, S::cap_t lim = S::inf())`  
        頂点 $s$ から $t$ へ、流量 $lim$ に達するまで流す。$O(n^2 m)$ 時間。辺の容量が高々 $k$ のとき、$O(km^{3/2})$ 時間。辺の容量が高々 $k$ で多重辺がないとき、$O(kn^{2/3}m)$ 時間。二部マッチングで用いる場合、$O(\sqrt{n}m)$ 時間。

    - `struct edge`
        - `int from, to`  
            始点と終点。
        
        - `S::cap_t cap, flow`  
            容量と流量。

    - `edge get_edge(int i)`  
        辺 `i` を返す。

    - `vector<edge> edges()`  
        番号順に並んだ辺の `vector` を返す。

    - `vector<bool> cut(int s)`  
        残余グラフ上で各頂点に到達できるかどうかの `bool` 値を要素とする `vector` を返す。

- `struct ll_dinic`  
    距離やコストが `ll` 型であるような最大フロー問題を解くときに`dinic`にテンプレート引数 `S` として与える。

## 参考
- [ACL](https://atcoder.github.io/ac-library/production/document_ja/maxflow.html)
- [みさわさんの記事](https://misawa.github.io/others/flow/dinic_time_complexity.html)