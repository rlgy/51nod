/*
1080 两个数的平方和
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
给出一个整数N，将N表示为2个整数i j的平方和（i <= j)，如果有多种表示，按照i的递增序输出。
例如：N = 130，130 = 3^2 + 11^2 = 7^2 + 9^2 （注：3 11同11 3算1种）
Input
一个数N(1 <= N <= 10^9)
Output
共K行：每行2个数，i j，表示N = i^2 + j^2（0 <= i <= j)。
如果无法分解为2个数的平方和，则输出No Solution
Input示例
130
Output示例
3 11
7 9
 */

#include <stdio.h>
#include <math.h>

int main() {
    int N, i, j, k, f = 0;
    scanf("%d", &N);
    k = (int) sqrt(N);
    for (i = 0; i <= k; ++i) {
        for (j = i; j <= k; ++j) {
            if (i * i + j * j == N) {
                f = 1;
                printf("%d %d\n", i, j);
            }
        }
    }
    if (!f) {
        printf("No Solution");
    }
    return 0;
}