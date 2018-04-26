/*
1007 正整数分组
基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
将一堆正整数分为2组，要求2组的和相差最小。
例如：1 2 3 4 5，将1 2 4分为1组，3 5分为1组，两组和相差1，是所有方案中相差最少的。
Input
第1行：一个数N，N为正整数的数量。
第2 - N+1行，N个正整数。
(N <= 100, 所有正整数的和 <= 10000)
Output
输出这个最小差
Input示例
5
1
2
3
4
5
Output示例
1
*/

/**
 * 背包的容量为sum(N)/2,求能背的对大价值
 * dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i])
 */
#include <stdio.h>

#define MAX_X 108
#define MAX_Y 10008

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N, n[MAX_X], dp[MAX_X][MAX_Y] = {0}, sum = 0, half = 0, result;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &n[i]);
        sum += n[i];
    }
    //求 dp[N][sum/2]
    half = sum / 2;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= half; j++) {
            if (j < n[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - n[i]] + n[i]);
            }
        }
    }
    if (sum < 2 * dp[N][half]) {
        result = 2 * dp[N][half] - sum;
    } else {
        result = sum - 2 * dp[N][half];
    }
    printf("%d", result);
    return 0;
}