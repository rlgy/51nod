/*
1031 骨牌覆盖
基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
在2*N的一个长方形方格中，用一个1*2的骨牌排满方格。
问有多少种不同的排列方法。

例如：2 * 3的方格，共有3种不同的排法。（由于方案的数量巨大，只输出 Mod 10^9 + 7 的结果）

Input
输入N(N <= 1000)
Output
输出数量 Mod 10^9 + 7
Input示例
3
Output示例
3
*/

#include <stdio.h>

#define MOD 1000000007

struct mextri {
    long long m[2][2];
} ans, base;

//矩阵乘法
struct mextri multi(struct mextri a, struct mextri b) {
    struct mextri result = {0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                result.m[i][j] += (a.m[i][k] % MOD) * (b.m[k][j] % MOD);
                result.m[i][j] %= MOD;
            }
        }
    }
    return result;
}

long long fast_mod(int n) {
    while (n) {
        if (n & 1) {
            ans = multi(ans, base);
        }
        base = multi(base, base);
        n >>= 1;
    }
    return ans.m[0][1];
}

int main() {
    int N;
    scanf("%d", &N);
    //初始化base
    base.m[0][0] = base.m[0][1] = base.m[1][0] = 1;
    base.m[1][1] = 0;
    //ans为单位矩阵
    ans.m[0][0] = ans.m[1][1] = 1;
    ans.m[0][1] = ans.m[1][0] = 0;
    printf("%lld", fast_mod(N+1));
    return 0;
}