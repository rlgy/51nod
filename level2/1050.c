/*
1050 循环数组最大子段和
基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
N个整数组成的循环序列a[1],a[2],a[3],…,a[n]，求该序列如a[i]+a[i+1]+…+a[j]的连续的子段和的最大值（循环序列是指n个数围成一个圈，
 因此需要考虑a[n-1],a[n],a[1],a[2]这样的序列）。当所给的整数均为负数时和为0。
例如：-2,11,-4,13,-5,-2，和最大的子段为：11,-4,13。和为20。
Input
第1行：整数序列的长度N（2 <= N <= 50000)
第2 - N+1行：N个整数 (-10^9 <= S[i] <= 10^9)
Output
输出循环数组的最大子段和。
Input示例
6
-2
11
-4
13
-5
-2
Output示例
20
*/
#include <stdio.h>

#define MAX 100007

//最优解 = max(普通的最大子段和， 总和 – 普通的“最小子段和”)
int main() {
    int N, a[MAX];
    long long max = 0, min = 0, b[MAX], sum = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    b[0] = a[0];
    max = b[0];
    for (int i = 1; i < N; ++i) {
        if (b[i - 1] < 0) {
            b[i] = a[i];
        } else {
            b[i] = b[i - 1] + a[i];
        }
        if (max < b[i])
            max = b[i];
    }
    //求最小连续子段
    min = b[0];
    for (int i = 1; i < N; ++i) {
        if (b[i - 1] < 0) {
            b[i] = b[i - 1] + a[i];
        } else {
            b[i] = a[i];
        }
        if (min > b[i])
            min = b[i];
    }
    max = (max > sum - min) ? max : sum - min;
    if (max < 0)
        max = 0;
    printf("%lld", max);
    return 0;
}