/*
1347 旋转字符串
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
S[0...n-1]是一个长度为n的字符串，定义旋转函数Left(S)=S[1…n-1]+S[0].比如S=”abcd”,Left(S)=”bcda”.
一个串是对串当且仅当这个串长度为偶数，前半段和后半段一样。比如”abcabc”是对串,”aabbcc”则不是。

现在问题是给定一个字符串，判断他是否可以由一个对串旋转任意次得到。


Input
第1行：给出一个字符串（字符串非空串，只包含小写字母，长度不超过1000000）
Output
对于每个测试用例，输出结果占一行，如果能，输出YES，否则输出NO。
Input示例
aa
ab
Output示例
YES
NO
 */
#include <stdio.h>
#include <string.h>

#define MAX 1000007

int main() {
    char S[MAX];

    int len;
    scanf("%s", S);
    len = strlen(S);
    if (len % 2 != 0) {
        printf("NO");
        return 0;
    }
    for (int i = 0; i < len / 2; i++) {
        if (S[i] != S[i + len / 2]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}