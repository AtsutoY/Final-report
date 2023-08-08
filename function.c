#include <stdio.h>
#include <string.h>
#include <time.h>
#include <float.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "function.h"

// 入力された文字が数字かどうか
int checkDigit(char yourinputstr[], int mojisuu)
{
    for (int i = 0; i < mojisuu; i++)
    {
        if (!isdigit(yourinputstr[i]))
        {
            return 0;
        }
    }
    return 1;
}

// hit数を数えるメソッド
int countHit(const char input[], const char answer[], int ketasuu)
{
    int hit = 0;

    for (int i = 0; i < ketasuu; i++)
    {
        for (int j = 0; j < ketasuu; j++)
        {
            if (answer[i] == input[j])
            {
                if (i == j)
                {
                    hit++;
                }
            }
        }
    }

    return hit;
}

// blowの数を数える
int countBlow(const char input[], const char answer[], int ketasuu)
{

    int blow = 0;

    for (int i = 0; i < ketasuu; i++)
    {
        for (int j = 0; j < ketasuu; j++)
        {
            if (answer[i] == input[j])
            {
                if (i != j)
                {
                    blow++;
                }
            }
        }
    }

    return blow;
}
