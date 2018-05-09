/*
1042 数字0-9的数量
基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
给出一段区间a-b，统计这个区间内0-9出现的次数。
比如 10-19，1出现11次（10,11,12,13,14,15,16,17,18,19,其中11包括2个1)，其余数字各出现1次。
Input
两个数a,b（1 <= a <= b <= 10^18)
Output
输出共10行，分别是0-9出现的次数
Input示例
10 19
Output示例
1
11
1
1
1
1
1
1
1
1
*/
#include <stdio.h>

#define ll long long

ll x[20], y[20];//保存结果

void dfs(ll a, ll b, ll c[]) {
    ll n, m, t;
    n = a / 10;
    m = a % 10;
    t = n;
    //19
    //nm
    for (int i = 0; i <= m; ++i) {
        c[i] += b;
    }
    for (int i = 0; i < 10; ++i) {
        c[i] += b * n;
    }
    c[0] -= b;
    while (t) {
        c[t % 10] += b * (m + 1);
        t /= 10;
    }
    if (n)
        dfs(n - 1, b * 10, c);
}

int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    dfs(a - 1, 1, x);
    dfs(b, 1, y);
    for (int i = 0; i < 10; ++i) {
        printf("%lld\n", y[i] - x[i]);
    }
    return 0;
}