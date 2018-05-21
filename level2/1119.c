/*
1119 机器人走方格 V2
基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
M * N的方格，一个机器人从左上走到右下，只能向右或向下走。有多少种不同的走法？由于方法数量可能很大，只需要输出Mod 10^9 + 7的结果。
Input
第1行，2个数M,N，中间用空格隔开。（2 <= m,n <= 1000000)
Output
输出走法的数量 Mod 10^9 + 7。
Input示例
2 3
Output示例
3
*/
#include <stdio.h>

#define MAX 1000
#define MOD 1000000007 //素数

long long jc(long long n) {
    long long ans = 1;
    for (long long i = 1; i <= n; ++i) {
        ans = ans * i % MOD;
    }
    return ans;
}

long long pow1(long long n, long long i) {
    long long ans = 1;
    while (i) {
        if (i & 1) {
            ans = ans * n % MOD;
        }
        n = n * n % MOD;
        i >>= 1;
    }
    return ans;
}

long long C(long long n, long long m) {
    long long ans = 1;
    ans = ans * jc(n) % MOD;
    ans = ans * pow1(jc(m), MOD - 2) % MOD;
    ans = ans * pow1(jc(n - m), MOD - 2) % MOD;
    return ans;

}

int main() {
    long long M, N;
    scanf("%lld %lld", &M, &N);
    printf("%lld", C(N + M - 2, N - 1));
    return 0;
}
