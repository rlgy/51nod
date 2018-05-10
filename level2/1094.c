/*
1094 和为k的连续区间
基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
一整数数列a1, a2, ... , an（有正有负），以及另一个整数k，求一个区间[i, j]，(1 <= i <= j <= n)，使得a[i] + ... + a[j] = k。
Input
第1行：2个数N,K。N为数列的长度。K为需要求的和。(2 <= N <= 10000，-10^9 <= K <= 10^9)
第2 - N + 1行：A[i](-10^9 <= A[i] <= 10^9)。
Output
如果没有这样的序列输出No Solution。
输出2个数i, j，分别是区间的起始和结束位置。如果存在多个，输出i最小的。如果i相等，输出j最小的。
Input示例
6 10
1
2
3
4
5
6
Output示例
1 4
*/
#include <stdio.h>

#define MAX 10007
#define ll long long

/**
 *
 * @return
 */
int main() {
    ll sum[MAX] = {0};
    int N, K, n;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &n);
        sum[i] = sum[i - 1] + n;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            if (K == sum[j] - sum[i - 1]) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}
