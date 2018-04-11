/*
1082 与7无关的数
题目来源： 有道难题
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
一个正整数，如果它能被7整除，或者它的十进制表示法中某个位数上的数字为7，则称其为与7相关的数。求所有小于等于N的与7无关的正整数的平方和。
例如：N = 8，<= 8与7无关的数包括：1 2 3 4 5 6 8，平方和为：155。
Input
第1行：一个数T，表示后面用作输入测试的数的数量。（1 <= T <= 1000)
第2 - T + 1行：每行1个数N。（1 <= N <= 10^6)
Output
共T行，每行一个数，对应T个测试的计算结果。
Input示例
5
4
5
6
7
8
Output示例
30
55
91
91
155
 */

#include <stdio.h>

#define MAX 1000007

int is(int n) {
    if (n % 7 == 0) {
        return 1;
    }
    while (n) {
        if (n % 10 == 7) {
            return 1;
        }
        n /= 10;
    }
    return 0;
}

int main() {
    int T, n;
    long long ans[MAX] = {0};
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        if (ans[n] != 0) {
            printf("%lld\n", ans[n]);
        } else {
            for (long long i = 1; i <= n; ++i) {
                if (!is(i)) {
                    ans[i] = i * i + ans[i - 1];
                } else {
                    ans[i] = ans[i - 1];
                }
            }
            printf("%lld\n", ans[n]);
        }
    }
    return 0;
}