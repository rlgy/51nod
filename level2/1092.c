/*
1092 回文字符串
基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
回文串是指aba、abba、cccbccc、aaaa这种左右对称的字符串。每个字符串都可以通过向中间添加一些字符，使之变为回文字符串。
例如：abbc 添加2个字符可以变为 acbbca，也可以添加3个变为 abbcbba。方案1只需要添加2个字符，是所有方案中添加字符数量最少的。
Input
输入一个字符串Str，Str的长度 <= 1000。
Output
输出最少添加多少个字符可以使之变为回文字串。
Input示例
abbc
Output示例
2
*/
#include <stdio.h>
#include <string.h>

#define MAX 1007
char s1[MAX], s2[MAX];

/**
 * s1的i位是否等于s2的j位
 * @param i 
 * @param j 
 * @return 
 */
int same(int i, int j) {
    return s1[i] == s2[j];
}

int max(int a, int b) {
    return a > b ? a : b;
}

/**
 * dp求LCS的长度
 * f[i][j]表示s1的i位与s2的j位之间的LCS的长度
 *
 * @return
 */
int main() {
    int f[MAX][MAX] = {0};
    int len;
    scanf("%s", s1);
    len = strlen(s1);
    for (int i = 0; i < len; i++) {
        s2[len - i - 1] = s1[i];
    }
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= len; ++j) {
            if (same(i - 1, j - 1)) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    printf("%d", len - f[len][len]);
    return 0;
}
