# MergeCSV

## ツール説明
- C言語で作られたツールです
- 複数のcsvファイルを**1つの新たなcsvファイル**にマージするツールです
- 1つ目のcsvファイルを全てコピーし、2つ目以降のcsvファイルは**2行目以降**をコピーします
- ツール使用時のカレントディレクトリにマージされたcsvファイルが配置されます

## 実施環境
- Windows

## 使い方
1. コンパイル `gcc -fexec-charset=CP932 -o main_csv .\MergeCSV.c`
2. プログラムを実行　`.\MergeCSV.exe`
3. マージしたいcsvファイルがあるパスを指定 `C:\Users\xxxx\xxx\xxx`

- 定数 `FILE_EXT` を変更すれば、好きな拡張子でマージできます

## LICENSE
This software is released under the [MIT License](https://en.wikipedia.org/wiki/MIT_License), see LICENSE.