# MergeCSV

## ツール説明
- 複数のcsvファイルを**1つの新たなcsvファイル**にマージするツールです
- 1つ目のcsvファイルを全てコピーし、2つ目以降のcsvファイルは**2行目以降**をコピーします
- ツール使用時のカレントディレクトリにマージされたcsvファイルが配置されます

----

## 実施環境
- Windows

----

## 使い方
1. コンパイル `gcc -fexec-charset=CP932 -o main_csv .\main_csv.c`
2. プログラムを実行　`.\main_csv.exe`
3. マージしたいcsvファイルがあるパスを指定 `C:\Users\xxxx\xxx\xxx`