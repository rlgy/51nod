/*
1003 阶乘后面0的数量
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
n的阶乘后面有多少个0？
6的阶乘 = 1*2*3*4*5*6 = 720，720后面有1个0。
Input
一个数N(1 <= N <= 10^9)
Output
输出0的数量
Input示例
5
Output示例
1
 */

#include <stdio.h>

int main() {
    int N;
    long long temp = 5;
    long long result = 0;
    scanf("%d", &N);

    while (N >= temp) {
        result += N / temp;
        temp *= 5;
    }

    printf("%lld", result);
    return 0;
}