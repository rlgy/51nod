/*
1010 只包含因子2 3 5的数
基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
K的因子中只包含2 3 5。满足条件的前10个数是：2,3,4,5,6,8,9,10,12,15。
所有这样的K组成了一个序列S，现在给出一个数n，求S中 >= 给定数的最小的数。
例如：n = 13，S中 >= 13的最小的数是15，所以输出15。
Input
第1行：一个数T，表示后面用作输入测试的数的数量。（1 <= T <= 10000)
第2 - T + 1行：每行1个数N(1 <= N <= 10^18)
Output
共T行，每行1个数，输出>= n的最小的只包含因子2 3 5的数。
Input示例
5
1
8
13
35
77
Output示例
2
8
15
36
80
*/

#include <stdio.h>

#define MAX 10001
#define TMAX 1e18
long long M[15000];


void sort(int s, int e) {
    int i, j;
    long long k;
    if (s > e) {
        return;
    }
    i = s;
    j = e;
    k = M[i];
    while (i < j) {
        while (i < j && M[j] >= k) {
            j--;
        }
        M[i] = M[j];
        while (i < j && M[i] <= k) {
            i++;
        }
        M[j] = M[i];
    }
    M[i] = k;
    sort(s, i - 1);
    sort(i + 1, e);
}

int find(int s, int e, long long n) {
    int mid = 1;
    while (n > M[s] && n < M[e]) {
        mid = (s + e) / 2;
        if (mid == s) {
            return s == e ? s : e;
        }
        if (M[mid] > n) {
            e = mid;
        } else if (M[mid] < n) {
            s = mid;
        } else {
            return mid;
        }
    }
    return mid;
}

int main() {
    int T, m = 0;
    long long N[MAX];
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%lld", &N[i]);
    }

    //打表
    for (long long i = 1; i <= TMAX; i *= 2) {
        for (long long j = 1; i * j <= TMAX; j *= 3) {
            for (long long k = 1; i * j * k <= TMAX; k *= 5) {
                M[m++] = i * j * k;
            }
        }
    }
    //排序呢
    sort(0, m - 1);
    //二分查找
    for (int i = 0; i < T; ++i) {
        printf("%lld\n", M[find(1, m - 1, N[i])]);
    }
    return 0;
}