/*
1014 X^2 Mod P
基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
X*X mod P = A，其中P为质数。给出P和A，求<=P的所有X。
Input
两个数P A，中间用空格隔开。(1 <= A < P <= 1000000, P为质数)
Output
输出符合条件的X，且0 <= X <= P，如果有多个，按照升序排列，中间用空格隔开。
如果没有符合条件的X，输出：No Solution
Input示例
13 3
Output示例
4 9
*/

#include <stdio.h>

int main() {
    int P, A, f = 0;
    scanf("%d %d", &P, &A);
    for (long long i = 0; i <= P; i++) {
        if (i * i % P == A) {
            f = 1;
            printf("%lld ", i);
        }
    }
    if (!f) {
        printf("No Solution\n");
    }
    return 0;
}