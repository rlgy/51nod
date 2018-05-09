/*
1062 序列中最大的数
题目来源： Ural 1079
基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
有这样一个序列a：
a[0] = 0
a[1] = 1
a[2i] = a[i]
a[2i+1] = a[i] + a[i+1]

输入一个数N，求a[0] - a[n]中最大的数。
a[0] = 0, a[1] = 1, a[2] = 1, a[3] = 2, a[4] = 1, a[5] = 3, a[6] = 2, a[7] = 3, a[8] = 1, a[9] = 4, a[10] = 3。
例如：n = 5，最大值是3，n = 10，最大值是4。
Input
第1行：一个数T，表示后面用作输入测试的数的数量。（1 <= T <= 10)
第2 - T + 1行：T个数，表示需要计算的n。（1 <= n <= 10^5)
Output
共T行，每行1个最大值。
Input示例
2
5
10
Output示例
3
4
*/
#include <stdio.h>

#define MAX 100007

int a[MAX] = {0};//记录序列a[n]
int b[MAX]; //到地i位为止的最大值

void init(int n) {
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (i % 2 == 0) {
            a[i] = a[i / 2];
        } else {
            a[i] = a[(i - 1) / 2] + a[(i + 1) / 2];
        }
    }
}

void resolve(int n) {
    b[0] = a[0];
    for (int i = 1; i <= n; ++i) {
        b[i] = b[i - 1] > a[i] ? b[i - 1] : a[i];
    }
}

int main() {
    int T, n[10], max = 0;

    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        scanf("%d", &n[i]);
        max = (max < n[i]) ? n[i] : max;
    }
    init(max);
    resolve(max);
    for (int i = 0; i < T; ++i) {
        printf("%d\n", b[n[i]]);
    }
    return 0;
}