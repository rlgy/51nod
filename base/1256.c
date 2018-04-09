//
// Created by rlgy on 18-3-30.
//

//1256 乘法逆元
//给出2个数M和N(M < N)，且M与N互质，找出一个数K满足0 < K < N且K * M % N = 1，如果有多个满足条件的，输出最小的。
//Input
//输入2个数M, N中间用空格分隔（1 <= M < N <= 10^9)
//Output
//输出一个数K，满足0 < K < N且K * M % N = 1，如果有多个满足条件的，输出最小的。
//Input示例
//2 3
//Output示例
//2

#include <stdio.h>

int get_primes_count(int n) {
    int result;
    result = n;
    for (int i = 2; i * i < n; ++i) {
        if (n % i == 0) {
            result = result / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1)
        result = result / n * (n - 1);
    return result;
}

int fast_mod(int m, int p, int n) {
    long long result, base;
    result = 1;
    base = m % n;

    while (p) {
        if (p & 1) {
            result = result * base % n;
        }
        p >>= 1;
        base = base * base % n;
    }
    return result;
}

int main() {
    //欧拉定理
    //K*M = M^u(N)
    //K = M^(u(N)-1) % N
    //求u(N)
    //欧拉函数

    int M, N, c, result;

    scanf("%d %d", &M, &N);

    c = get_primes_count(N) - 1;
    result = fast_mod(M, c, N);
    printf("%d", result);

    return 0;
}