/*
1284 2 3 5 7的倍数
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
给出一个数N，求1至N中，有多少个数不是2 3 5 7的倍数。 例如N = 10，只有1不是2 3 5 7的倍数。
Input
输入1个数N(1 <= N <= 10^18)。
Output
输出不是2 3 5 7的倍数的数共有多少。
Input示例
10
Output示例
1

 N-(2,3,5,7)的倍数+(2,3)的倍数+(2,5)的倍数+(2,7)的倍数+(3,5)的倍数+(3,7)的倍数+
 (5,7)的倍数-(2,3,5)的倍数-(2,3,7)的倍数-(2,5,7)的倍数-(3,5,7)的倍数+(2,3,5,7)的倍数
 */
#include <stdio.h>

int main() {
    long long N, result;
    scanf("%lld", &N);
    result = N - N / 2 - N / 3 - N / 5 - N / 7 + N / 6 + N / 10 + N / 14 + N / 15 + N / 21 + N / 35 - N / 30 - N / 42 -
             N / 70 - N / 105 + N / 210;
    printf("%lld", result);
    return 0;
}