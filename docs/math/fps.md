---
title: 形式的冪級数
documentation_of: //math/fps.hpp
---

# 概要
- `modint`上の形式的冪級数に関する各種演算をサポートする。

# 詳細
- `<typename mint> struct fps`  
    形式的冪級数本体。

    - `typename mint`  
        テンプレート引数として与える`modint`。

# 参考
- [Nyaan さんのライブラリ](https://nyaannyaan.github.io/library/fps/formal-power-series.hpp)
- [opt さんの記事](https://opt-cp.com/fps-fast-algorithms/)
- [exp 高速化に関する論文](https://arxiv.org/pdf/1301.5804.pdf)