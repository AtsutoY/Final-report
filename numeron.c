#include <stdio.h>
#include <string.h>
#include <time.h>
#include <float.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "get-put-yourrecord.h"
#include "function.h"

#define NAME_mojisuu 64

char rank2(int count)
{
    if (count == 1)
    {
        return 'S';
    }
    else if (1 < count && count < 6)
    {
        return 'A';
    }
    else if (5 < count && count < 11)
    {
        return 'B';
    }
    else if (10 < count && count < 16)
    {
        return 'C';
    }
    else
    {
        return 'D';
    }
}

char rank4(int count)
{
    if (1 <= count && count < 6)
    {
        return 'S';
    }
    else if (5 < count && count < 11)
    {
        return 'A';
    }
    else if (10 < count && count < 16)
    {
        return 'B';
    }
    else if (15 < count && count < 36)
    {
        return 'C';
    }
    else
    {
        return 'D';
    }
}

typedef struct youare
{
    char name[NAME_mojisuu]; // 名前
    char rank;               // gameresult
} Youare;

int main(void)
{
    Youare you;
    puts("名前を入力してください");
    printf("名前:");
    scanf("%s", you.name);
    int coursenum;
    puts("コースを選択してください(1or2)");
    printf("コース:");
    scanf("%d", &coursenum);

    puts("あなたの過去の成績を表示します");
    switch (coursenum)
    {
    case 1:
        get_yourrecord1();
        break;
    case 2:
        get_yourrecord2();
        break;
    }

    puts("それではゲームスタート");

    // hit,blow数
    int hit, blow;

    // 正解
    char answer2[2];
    char answer4[4];

    // 文字列の配列
    const char moji[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    // 重複があるかないか
    int duplication;
    // 正解を作成(重複を許さない)
    if (coursenum == 1)
    {
        int j;
        for (int i = 0; i < 2; i++)
        {
            while (1)
            {
                duplication = 0;
                j = rand() % 10;
                for (int k = 0; k < i - 1; k++)
                {
                    // 重複があればduplicationの値を1にする
                    if (moji[j] == answer2[k])
                    {
                        duplication = 1;
                        break; // for文に対して
                    }
                }
                if (duplication == 1)
                {
                    continue;
                }
                else
                {
                    answer2[i] = moji[j]; // while文に対して
                    break;
                }
            }
        }
    }
    else
    {
        int j;
        for (int i = 0; i < 4; i++)
        {
            while (1)
            {
                duplication = 0;
                j = rand() % 10;
                for (int k = 0; k < i - 1; k++)
                {
                    // 重複があればduplicationの値を1にする
                    if (moji[j] == answer4[k])
                    {
                        duplication = 1;
                        break; // for文に対して
                    }
                }
                if (duplication == 1)
                {
                    continue;
                }
                else
                {
                    answer4[i] = moji[j];
                    break; // while文に対して
                }
            }
        }
    }

    int count = 0;

    if (coursenum == 1)
    {
        do
        {
            char input[2];
            while (1)
            {
                char yourinput[256];
                printf("2桁の数字を入力してください:");
                scanf("%s", yourinput);

                if (strlen(yourinput) != 2)
                {
                    printf("2桁ではないです\n");
                    continue;
                }

                if (!checkDigit(yourinput, 2))
                {
                    printf("数字以外があります");
                    continue;
                }

                for (int i = 0; i < 2; i++)
                {
                    input[i] = yourinput[i];
                }
                break;
            }

            // hit,blow数を表示
            hit = countHit(answer2, input, 2);
            blow = countBlow(answer2, input, 2);
            printf("%d HIT!! / %d BLOW!!\n", hit, blow);
            // 回数
            count++;
        } while (hit < 2);
        char yourrank2 = rank2(count);
        you.rank = yourrank2;
        // 記録の書き込み
        put_yourrecord1(yourrank2);
    }
    else
    {
        do
        {
            char input[4];
            while (1)
            {
                char yourinput[256];
                printf("4桁の数字を入力してください:");
                scanf("%s", yourinput);

                if (strlen(yourinput) != 4)
                {
                    printf("4桁ではないです\n");
                    continue;
                }

                if (!checkDigit(yourinput, 4))
                {
                    printf("数字以外があります");
                    continue;
                }

                for (int i = 0; i < 4; i++)
                {
                    input[i] = yourinput[i];
                }
                break;
            }

            // hit,blow数を表示
            hit = countHit(answer4, input, 4);
            blow = countBlow(answer4, input, 4);
            printf("%d HIT!! / %d BLOW!!\n", hit, blow);
            // 回数
            count++;
        } while (hit < 4);
        char yourrank4 = rank4(count);
        you.rank = yourrank4;
        // 記録の書き込み
        put_yourrecord2(yourrank4);
    }
}