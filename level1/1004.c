/*
1004 n^n的末位数字
题目来源： Author Ignatius.L (Hdu 1061)
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
给出一个整数N，输出N^N（N的N次方）的十进制表示的末位数字。
Input
一个数N（1 <= N <= 10^9）
Output
输出N^N的末位数字
Input示例
13
Output示例
3
 */

#include <stdio.h>

int main() {
    int N, result = 1;
    long long temp;
    scanf("%d", &N);
    temp = N;
    while (N) {
        if (N & 1) {
            result = result * temp % 10;
        }
        temp *= temp;
        temp %= 10;
        N >>= 1;
    }
    printf("%d", result);
    return 0;
}