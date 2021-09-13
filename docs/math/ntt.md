---
title: 数論変換
documentation_of: //math/ntt.hpp
---
## 概要
- 数論変換を行う。
- 2 基底の Stockham FFT で実装している。

## 詳細
- `<typename mint> ntt(vector<mint> &a)`  
    $a$ 自身を NTT した結果に更新する。列長 $n$ は 2 冪である必要がある。 $O(n\log n)$ 時間。

- `<typename mint> intt(vector<mint> &a)`  
    $a$ 自身を逆 NTT した結果に更新する。列長 $n$ は 2 冪である必要がある。 $O(n\log n)$ 時間。

## 参考
- [Stockham FFT 入門](http://wwwa.pikara.ne.jp/okojisan/stockham/stockham1.html)