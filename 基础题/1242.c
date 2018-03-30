//
// Created by rlgy on 18-3-30.
//

//1242 斐波那契数列的第N项
//斐波那契数列的定义如下：
//F(0) = 0
//F(1) = 1
//F(n) = F(n - 1) + F(n - 2) (n >= 2)

//(1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, ...)
//给出n，求F(n)，由于结果很大，输出F(n) % 1000000009的结果即可。

//Input
//输入1个数n(1 <= n <= 10^18)。
//Output
//输出F(n) % 1000000009的结果。

#include<stdio.h>

#define MOD 1000000009


struct matrix {
    long long m[2][2];
} ans, base;

//定义矩阵乘法
struct matrix mul(struct matrix a, struct matrix b) {
    struct matrix result = {0};
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

//快速幂
void fast_mod(long long n) {
    while (n) {
        if (n & 1) {
            ans = mul(ans, base);
        }
        base = mul(base, base);
        n >>= 1;
    }
    return;
}

int main() {
    //斐波那契数列当n很大时如何高效的求借第n项a(n) mod M的值? - 王希的回答 - 知乎
    //https://www.zhihu.com/question/23582123/answer/40464211

    long long n;
    scanf("%lld", &n);

    base.m[0][0] = base.m[0][1] = base.m[1][0] = 1;
    base.m[1][1] = 0;

    ans.m[0][0] = ans.m[1][1] = 1;
    ans.m[0][1] = ans.m[1][0] = 0;

    fast_mod(n);
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < 2; ++j) {
//            printf("%d ", ans.m[i][j]);
//        }
//        printf("\n");
//    }
    printf("%d", ans.m[0][1]);
    return 0;
}