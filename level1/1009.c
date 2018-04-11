/*
1009 数字1的数量
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
给定一个十进制正整数N，写下从1开始，到N的所有正数，计算出其中出现所有1的个数。
例如：n = 12，包含了5个1。1,10,12共包含3个1，11包含2个1，总共5个1。
Input
输入N(1 <= N <= 10^9)
Output
输出包含1的个数
Input示例
12
Output示例
5
 */

#include <stdio.h>

int main() {
    int N, result = 0, i = 1, current = 0, before = 0, after = 0;


    scanf("%d", &N);
    while ((N / i) != 0) {
        current = (N / i) % 10;
        before = N / (i * 10);
        after = N - (N / i) * i;
        if (current > 1) {
            result = result + (before + 1) * i;
        } else if (0 == current) {
            result += before * i;
        } else if (1 == current) {
            result = result + before * i + after + 1;
        }
        i *= 10;
    }

    printf("%d", result);
    return 0;
}