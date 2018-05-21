/*
1126 求递推序列的第N项
基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
有一个序列是这样定义的：f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
给出A，B和N，求f(n)的值。
Input
输入3个数：A,B,N。数字之间用空格分割。(-10000 <= A, B <= 10000, 1 <= N <= 10^9)
Output
输出f(n)的值。
Input示例
3 -1 5
Output示例
6
*/
#include <stdio.h>

struct matrix {
    int v[2][2];
} base, ans;

struct matrix mul(struct matrix a, struct matrix b) {
    struct matrix result = {0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                result.v[i][j] += a.v[i][k] * b.v[k][j] % 7;
            }
            result.v[i][j] = (result.v[i][j] + 7) % 7;
        }
    }
    return result;
}

void fast_mod(int n) {
    while (n) {
        if (n & 1) {
            ans = mul(ans, base);
        }
        base = mul(base, base);
        n >>= 1;
    }
}

int main() {
    int A, B, N;
    scanf("%d %d %d", &A, &B, &N);
    //初始化base矩阵
    base.v[0][0] = A;
    base.v[0][1] = B;
    base.v[1][0] = 1;
    base.v[1][1] = 0;
    //初始化ans矩阵
    ans.v[0][0] = ans.v[1][1] = 1;
    ans.v[0][1] = ans.v[1][0] = 0;

    struct matrix result;
    result.v[0][0] = result.v[1][0] = 1;
    fast_mod(N - 1);
    result = mul(ans, result);
    printf("%d", result.v[1][0] % 7);
    return 0;
}
