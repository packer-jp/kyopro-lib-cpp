---
title: 完全永続配列
documentation_of: //data_structure/persistent_array.hpp
---

## 概要
- コピー可能な配列。
- `using ptr` を `shared_ptr<persistent_array>` から `persistent_array *` に変更するといくらか性能が良くなる。しかし参照の切れたメモリが開放されないので、行う処理によっては危険である。

## 詳細
- `<typename T, int SHIFT> struct persistent_array`  
    永続配列本体。

    - `typename T`  
        テンプレート引数として与える、要素の型。

    - `int SHIFT`  
        テンプレート引数として与える値。 $2^{SHIFT}$ 分木として表現する。通常の使用では $2$ 程度にするとよい。

    - `(constructor)(int n = 1, T val = T())`  
        長さ $n$ 、全要素 $val$ で初期化。

    - `T get(int i)`  
        $i$ 番目の値を取得する。 $O(\log n)$ 時間。

    - `persistent_array set(int i, T val)`  
        $i$ 番目の値だけが $val$ に置き換えられた新たな完全永続配列を返す。$O(\log n)$ 時間および空間。

## 参考
- [37zigen さんの記事](https://37zigen.com/persistent-array/)