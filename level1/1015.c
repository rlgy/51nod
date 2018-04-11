/*
1015 水仙花数
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
水仙花数是指一个 n 位数 ( n >= 3 )，它的每个位上的数字的 n 次幂之和等于它本身。（例如：1^3 + 5^3 + 3^3 = 153）
给出一个整数M，求 >= M的最小的水仙花数。
Input
一个整数M（10 <= M <= 1000）
Output
输出>= M的最小的水仙花数
Input示例
99
Output示例
153
 */

#include <stdio.h>
#include <math.h>

int main() {
    int M, n, temp, ans;
    scanf("%d", &M);

    while (1) {
        ans = 0;
        n = 1;
        temp = M;
        while (temp / 10) {
            n++;
            temp /= 10;
        }
        temp = M;
        while (temp) {
            ans += pow(temp % 10, n);
            temp /= 10;
        }
        if (ans == M) {
            printf("%d", M);
            break;
        }
        M++;
    }
    return 0;
}