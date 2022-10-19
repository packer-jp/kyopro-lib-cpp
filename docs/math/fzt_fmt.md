---
title: 高速 Zeta / Moebius 変換
documentation_of: //math/fzt_fmt.hpp
---

## 概要
- 高速 Zeta / Moebius 変換を行う。両者は互いに逆変換の関係にある。

## 詳細
- `<typename T> fzt_super(vector<T> &a)`  
    $a$ 自身を Zeta 変換 (上位集合版) した結果に更新する。即ち、$a$ を集合上で定義される関数 $f$ と解釈したとき、
    $$g(S) := \sum_{T \supseteq S}{f(T)}$$
    で与えられる $g$ に更新する。

- `<typename T> fzt_sub(vector<T> &a)`  
    $a$ 自身を Zeta 変換 (下位集合版) した結果に更新する。即ち、$a$ を集合上で定義される関数 $f$ と解釈したとき、
    $$g(S) := \sum_{T \subseteq S}{f(T)}$$
    で与えられる $g$ に更新する。

- `<typename T> fmt_super(vector<T> &a)`  
    $a$ 自身を Moebius 変換 (上位集合版) した結果に更新する。即ち、$a$ を集合上で定義される関数 $g$ と解釈したとき、
    $$f(S) = \sum_{T \supseteq S}{(-1)^{|T| - |S|}g(T)}$$
    で与えられる $f$ に更新する。

- `<typename T> fzt_sub(vector<T> &a)`  
    $a$ 自身を Moebius 変換 (下位集合版) した結果に更新する。即ち、$a$ を集合上で定義される関数 $g$ と解釈したとき、
    $$f(S) = \sum_{T \subseteq S}{(-1)^{|T| - |S|}g(T)}$$
    で与えられる $f$ に更新する。