//
// Created by rlgyzhcn on 2019/11/3 19:54.
//

//1396 还是01串
//
//给定一个0-1串s，长度为n，下标从0开始，求一个位置k，满足0<=k<=n, 并且子串s[0..k - 1]中的0的个数与子串s[k..n - 1]中1的个数相等。 注意：
//
//（1） 如果k = 0, s[0..k - 1]视为空串
//
//（2） 如果k = n, s[k..n - 1]视为空串
//
//（3） 如果存在多个k值，输处任何一个都可以
//
//（4） 如果不存在这样的k值，请输出-1
//
//输入
//就一行，包含一个0-1串S，长度不超过1000000。
//输出
//题目要求的k值
//输入样例
//01
//输出样例
//1


#include <stdio.h>
#include <string.h>

#define APP_ENV_TEST
#define MAX_INPUT 1000000

int main() {
    FILE *input;
    int N0 = 0;
    int N1 = 0;
    char S[MAX_INPUT] = {0};
    int Len = 0;

#ifdef APP_ENV_TEST
    // 打开文件读取数据
    input = fopen("/mnt/hgfs/code/c/first/input.txt", "r");
    if (input == NULL) {
        return 0;
    }
#else
    input = stdin;
#endif
    fscanf(input, "%s", S);
    Len = strlen(S);
    for (int i = 0; i < Len; ++i) {
        if ('1' == S[i]) {
            N1++;
        }
    }

    for (int i = 0; i <= Len; ++i) {
        if (N0 == N1) {
            printf("%d", i);
            return 0;
        }
        if ('1' == S[i]) {
            N1--;
        } else {
            N0++;
        }
    }

    printf("-1");
    return 0;
}

