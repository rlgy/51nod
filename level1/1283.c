/*
1283 最小周长
题目来源： Codility
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
一个矩形的面积为S，已知该矩形的边长都是整数，求所有满足条件的矩形中，周长的最小值。
例如：S = 24，那么有{1 24} {2 12} {3 8} {4 6}这4种矩形，其中{4 6}的周长最小，为20。
Input
输入1个数S(1 <= S <= 10^9)。
Output
输出最小周长。
Input示例
24
Output示例
20
 */

/*
 x*y=a;
 min(x+y)=k
 x+a/x=k 对勾函数
 */
#include <stdio.h>
#include <math.h>

int main() {
    int S, a, b;
    scanf("%d", &S);
    a = sqrt(S);
    if (a * a == S) {
        printf("%d", 4 * a);
    } else {
        do {
            b = S / a;
            if (a * b == S) {
                printf("%d", 2 * (a + b));
                break;
            }
            a--;
        } while (a > 0);
    }

    return 0;
}