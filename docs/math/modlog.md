---
title: 離散対数問題
documentation_of: //math/modlog.hpp
---

## 概要
- 離散対数問題を解く。

## 詳細
- `ll modlog(ll a, ll b, ll m)`  
    $a^x \equiv b \pmod m$ なる最小の正整数 $x$ を返す。 期待 $O(\sqrt m)$ 時間。

## 参考
- [habara-k さんの記事](https://habara-k.hatenadiary.jp/entry/2021/10/14/230035)