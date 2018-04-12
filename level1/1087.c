/*
1087 1 10 100 1000
题目来源： Ural 1209
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
1,10,100,1000...组成序列1101001000...，求这个序列的第N位是0还是1。
Input
第1行：一个数T，表示后面用作输入测试的数的数量。（1 <= T <= 10000)
第2 - T + 1行：每行1个数N。（1 <= N <= 10^9)
Output
共T行，如果该位是0，输出0，如果该位是1，输出1。
Input示例
3
1
2
3
Output示例
1
1
0
 */

#include <stdio.h>

#define MAX 10001

int main() {
    //a[0]=1,a[1]=2,a[2]=4,a[3]=7,a[n]=a[n-1]+n,
    int T, i, n[MAX] = {0}, max = 0, a[50001] = {0}, f;
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        scanf("%d", &n[i]);
    }
    a[0] = 1;
    for (i = 1; i <= 50000; i++) {
        a[i] = a[i - 1] + i;
    }

    for (i = 0; i < T; ++i) {
        f = 0;
        for (int j = 0; j <= 50001; ++j) {
            if (n[i] == a[j]) {
                printf("%d\n", 1);
                f = 1;
                break;
            } else if (n[i] < a[j]) {
                break;
            }
        }
        if (!f) {
            printf("%d\n", 0);
        }
    }
}