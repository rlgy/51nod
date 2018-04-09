/*
1002 数塔取数问题
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
一个高度为N的由正整数组成的三角形，从上走到下，求经过的数字和的最大值。
每次只能走到下一层相邻的数上，例如从第3层的6向下走，只能走到第4层的2或9上。

   5
  8 4
 3 6 9
7 2 9 5

例子中的最优方案是：5 + 8 + 6 + 9 = 28
Input
第1行：N，N为数塔的高度。(2 <= N <= 500)
第2 - N + 1行：每行包括1层数塔的数字，第2行1个数，第3行2个数......第k+1行k个数。数与数之间用空格分隔（0 <= A[i] <= 10^5) 。
Output
输出最大值
Input示例
4
5
8 4
3 6 9
7 2 9 5
Output示例
28
 */

#include <stdio.h>

#define MAX 501

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    //f[i][j]表示从顶（1,1）到 点（i,j)的最大值
    //f[i][j]=max(f[i+1][j],f[i+1][j+1])+map[i][j]
    int N, dp[MAX][MAX] = {}, map[MAX][MAX] = {}, i = 0, j = 0;
    char c;
    scanf("%d", &N);

    while (j < N) {
        i = 1;
        j++;
        do {
            scanf("%d", &map[j][i++]);
        } while ((c = getchar()) != '\n');
    }

    for (i = 1; i <= N; i++) {
        dp[N][i] = map[N][i];
    }

    for (i = N - 1; i > 0; --i) {
        for (j = i; j > 0; --j) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + map[i][j];
        }
    }

    printf("%d", dp[1][1]);
    return 0;
}