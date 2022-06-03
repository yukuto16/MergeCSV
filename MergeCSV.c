// ToDo 例外処理の追加
//      定数・変数名のリファクタリング

#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define FILE_EXT "csv"
#define PATH_SIZE 300
#define BUF 260
#define CSV_COUNT 1
#define FIND_NUM 0
#define FIND_CPY_NUM 1

// csvファイルか判断
int FindExt(char *PathName, char *ext)
{
    int i;
    char buf[BUF];
    memset(buf, FIND_NUM, sizeof(char)*BUF);

    for (i = strlen(PathName); i > FIND_NUM; i--)
    {
        if (PathName[i] == '.') break;
    }

    if (i == FIND_NUM) return 0;
    strncpy(buf, PathName+i+FIND_CPY_NUM, strlen(PathName)-i);

    if (strcmp(buf, ext) == FIND_NUM) return 1;

    return 0;
}


// 1回目のcsv処理
int FastMerge(const char* fast_file)
{
    FILE *merge_fp = fopen("merge.csv", "w");
    FILE *file_fp = fopen(fast_file, "r");
    char str[PATH_SIZE];

    if (merge_fp == NULL)
    {
        perror("マージファイルを作成できませんでした");
        return 1;
    }

    if (file_fp == NULL)
    {
        perror("マージ対象のファイルを開けませんでした");
        return 1;
    }

    // 中身全てをコピー
    while (fgets(str, PATH_SIZE, file_fp) != NULL)
    {
        fprintf(merge_fp, "%s", str);
    }
    
    fclose(file_fp);
    fclose(merge_fp);

    return 0;
}


// 2回目以降のcsv処理
int Merge(const char* next_file)
{
    FILE *merge_fp = fopen("merge.csv", "a");
    FILE *next_fp = fopen(next_file, "r");
    char str[PATH_SIZE];

    if (merge_fp == NULL)
    {
        perror("マージファイルを作成できませんでした");
        return 1;
    }

    if (next_fp == NULL)
    {
        perror("マージ対象のファイルを開けませんでした");
        return 1;
    }

    // 1行目を抜かす
    while (fgetc(next_fp) != '\n' && !feof(next_fp));

    // 2行目以降をコピー
    while (fgets(str, PATH_SIZE, next_fp) != NULL)
    {
        fprintf(merge_fp, "%s", str);
    }
    
    fclose(next_fp);
    fclose(merge_fp);

    return 0;
}

// メイン処理
int main()
{
    DIR *dir;
    struct dirent *ds;
    char file_path[PATH_SIZE];
    char str_path[PATH_SIZE];
    int count;

    // csvファイルが配置されているパスをキーボート入力
    printf("パスを入力してください\n");
    scanf("%s", &file_path);

    dir=opendir(file_path);

    for(ds = readdir(dir), count = CSV_COUNT; ds != NULL; ds = readdir(dir)){
        snprintf(str_path, sizeof str_path, file_path);

        // 1回目のcsv
        if (FindExt(ds->d_name,FILE_EXT) == CSV_COUNT && count == CSV_COUNT)
        {
            count++;
            sprintf(str_path, "%s//%s", str_path, ds->d_name);
            printf("%s\n", ds->d_name);

            FastMerge(str_path);
        }
        // 2回目以降のcsv
        else if (FindExt(ds->d_name,FILE_EXT) == CSV_COUNT && count != CSV_COUNT)
        {
            sprintf(str_path, "%s//%s", str_path, ds->d_name);
            printf("%s\n", ds->d_name);
            
            Merge(str_path);
        }
    }

    closedir(dir);

    printf("正常終了\n");
    
    return 0;
}
