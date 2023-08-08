#include <stdio.h>
#include <string.h>
#include <time.h>
#include <float.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "get-put-yourrecord.h"
#include "_get-put-yourrecord.h"

// 記録を書き込むためのファイル
char yourrecord1[] = "yourrecord1.dat";
char yourrecord2[] = "yourrecord2.dat";

// あなたのcourse1の過去の記録を読み取り
void get_yourrecord1()
{
    FILE *fp;
    char rank[50];

    if ((fp = fopen(yourrecord1, "rb")) == NULL)
    {
        printf("ファイルを作成します。\n");
    }
    else
    {
        int i;
        struct tm local;
        double line[256];

        printf("\n過去の成績\n-------------------------- \n");

        while ((i = fread(&local, sizeof(struct tm), 1, fp)) > 0)
        {
            printf("%d年 %d月 %d日 %d時 %d分 %d秒\n",
                   local.tm_year + 1900, local.tm_mon + 1,
                   local.tm_mday, local.tm_hour, local.tm_min, local.tm_sec);
            fread(rank, sizeof(char), 1, fp);
            rank[1] = '\0'; // ヌル文字の追加
            printf("成績は%s \n", rank);
        }
        fclose(fp);
    }
};

// あなたの今回のcourse1の記録の書き込み
void put_yourrecord1(char rank)
{
    FILE *fp;
    time_t t = time(NULL);
    struct tm *local = localtime(&t);

    if ((fp = fopen(yourrecord1, "ab")) == NULL)
    {
        printf("ファイルがありません");
        fflush(stdout);
    }
    else
    {
        fwrite(local, sizeof(struct tm), 1, fp);
        fwrite(&rank, sizeof(char), 1, fp);
        fclose(fp);
    }
};

// あなたのcourse2の過去の記録を読み取り
void get_yourrecord2()
{
    FILE *fp;
    char rank[50];

    if ((fp = fopen(yourrecord2, "rb")) == NULL)
    {
        printf("ファイルを作成します。\n");
    }
    else
    {
        int i;
        struct tm local;
        double line[256];

        printf("\n過去の成績\n-------------------------- \n");

        while ((i = fread(&local, sizeof(struct tm), 1, fp)) > 0)
        {
            printf("%d年 %d月 %d日 %d時 %d分 %d秒\n",
                   local.tm_year + 1900, local.tm_mon + 1,
                   local.tm_mday, local.tm_hour, local.tm_min, local.tm_sec);
            fread(rank, sizeof(char), 1, fp);
            rank[1] = '\0'; // ヌル文字の追加
            printf("成績は%s \n", rank);
        }
        fclose(fp);
    }
};

// あなたの今回のcourse2の記録の書き込み
void put_yourrecord2(char rank)
{
    FILE *fp;
    time_t t = time(NULL);
    struct tm *local = localtime(&t);

    if ((fp = fopen(yourrecord2, "ab")) == NULL)
    {
        printf("ファイルがありません");
        fflush(stdout);
    }
    else
    {
        fwrite(local, sizeof(struct tm), 1, fp);
        fwrite(&rank, sizeof(char), 1, fp);
        fclose(fp);
    }
};