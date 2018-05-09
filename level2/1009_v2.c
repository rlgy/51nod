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

#define ll long long

ll resolve(int n, int b) {
    int current, before, after, ans = 0;
    current = (n / b) % 10;
    before = n / (b * 10);
    after = n - (n / b) * b;
    if (current == 0) {
        ans += before * b;
    } else if (current == 1) {
        ans += before * b + after + 1;
    } else if (current > 1) {
        ans += (before + 1) * b;
    }
    if (before)
        return resolve(n, b * 10) + ans;
    else
        return ans;
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%lld", resolve(N, 1));
    return 0;
}