---
title: 畳み込み
documentation_of: //math/convolution.hpp
---

## 概要
- 数論変換を用いた二数列の畳み込みを行う。
- 法 $m$ について、 $m - 1$ は結果の列長以上となる最小の 2 冪で割り切れる必要がある。 $998244353 = 2^{23} \times 119 + 1$ がよく用いられる。

## 詳細
- `<typename mint> vector<mint> convolution(vector<mint> a, vector<mint> b)`  
    $a, b$を畳み込んだ数列を返す。$a, b$それぞれの列長を $n, m$ とすると、結果の列長は $n + m - 1$ となる。$O((n + m)\log(n + m))$時間。