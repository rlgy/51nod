/*
1083 矩阵取数问题
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
一个N*N矩阵中有不同的正整数，经过这个格子，就能获得相应价值的奖励，从左上走到右下，只能向下向右走，求能够获得的最大价值。
例如：3 * 3的方格。

1 3 3
2 1 3
2 2 1

能够获得的最大价值为：11。
Input
第1行：N，N为矩阵的大小。(2 <= N <= 500)
第2 - N + 1行：每行N个数，中间用空格隔开，对应格子中奖励的价值。（1 <= N[i] <= 10000)
Output
输出能够获得的最大价值。
Input示例
3
1 3 3
2 1 3
2 2 1
Output示例
11
 */

#include <stdio.h>

#define MAX 502

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N, i, j;
    int n[MAX][MAX] = {0};
    int dp[MAX][MAX] = {0};
    scanf("%d", &N);

    for (i = 1; i <= N; ++i) {
        for (j = 1; j <= N; ++j) {
            scanf("%d", &n[i][j]);
        }
    }
    for (i = N; i >= 1; --i) {
        for (j = N; j >= 1; --j) {
            dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) + n[i][j];
        }
    }
    printf("%d", dp[1][1]);
    return 0;
}